"""
Corpus health gate: six diagnostics run on a feature table before the
experiment grid.

Why this exists
---------------
A provenance corpus can look large and still carry almost no information. If a
generator emits identical output for every input in a class, that class collapses
to a single feature vector. Every classifier then separates it perfectly, every
metric saturates, and the reported accuracy measures the generator rather than
the attribution method. The failure is silent: row counts, class balance, and
grouped cross validation all look correct while the result is vacuous.

This gate turns that silent failure into a named, blocking one. It reads the
feature table produced by feature extraction and is meant to run before the
model grid, so a degenerate corpus stops the pipeline instead of producing a
number that has to be retracted later.

What the gate is not
--------------------
It is not model free. Diagnostics 4 and 5 fit decision trees and random
forests of their own, on the gate's own splits (below), which are not the
splits of the headline protocol in src/obfuscope/protocols.py. When
``--full-macro-f1`` is given, the headroom ratio R of diagnostic 4 combines a
headline score measured elsewhere, under another protocol and another model,
with a best single feature score measured here; the JSON report records which
reference was used (``single_feature.headroom_reference``) so that mismatch is
visible.

The diagnostics
---------------
1. Distinct vector ratio per class. The number of distinct feature vectors in
   a class divided by the number of artifacts in it. A class of 100 artifacts
   with 1 distinct vector scores 0.01 and tells the model nothing about within
   class variation.

1b. Input dependence per class. The share of within class feature variance that
   lies between input programs (eta squared, and its bias corrected form omega
   squared), tested against a permutation null in which the program labels are
   shuffled among the rows of the class (an unrestricted shuffle that ignores any
   parameterisation or seed structure inside the class). 200 permutations, drawn
   from a generator seeded with 0 whatever ``--seed`` is. A class fails only when
   ``--min-input-dependence`` is above zero and the permutation p value exceeds
   ``--input-dependence-alpha``; the threshold value itself is not used as a cut.

2. Constant features per class. A feature with zero variance across an entire
   class is not describing that class, it is naming it. The count includes
   features that are constant across the whole corpus, not only features that
   take a class specific constant.

3. Cross group duplicate clusters. Grouped cross validation only prevents
   leakage when the grouping variable actually separates the data. If one feature
   vector appears under two different group keys, the grouping constraint is
   satisfied while a feature identical row sits in both train and test.

4. Best k feature ceiling and chance corrected headroom. One decision tree per
   feature (not a stump: maximum depth ``min(8, n_classes + 2)``), scored by
   mean macro F1 over ``GroupShuffleSplit(n_splits=3, test_size=0.3,
   random_state=seed)`` grouped by ``--group``. k = 1 is exhaustive; k = 2 and
   3 use greedy forward selection from the 24 strongest single features. Greedy
   search can only understate the ceiling an exhaustive search would find, but
   features are selected on the same test splits they are scored on (there is
   no nested selection), which overstates it. The headroom is

       R = (F1_full - F1_best_single) / (F1_full - F1_chance),  F1_chance = 1/n_classes

   where F1_full is ``--full-macro-f1`` when supplied and otherwise a tree of
   the same depth on all features, on the same splits. The JSON always also
   reports R against that probe reference. When F1_full - F1_chance is zero or
   negative R is undefined, and ``headroom_status`` is ``"inconclusive"``: the
   headroom sub-check then neither passes nor fails, the report says so, and
   the exit status is decided by the other checks. ``--repeats N`` re-runs this
   diagnostic with split seeds ``seed .. seed + N - 1`` and reports the mean,
   minimum and maximum of the best single feature score, the best k scores and
   R. The verdict always uses the first seed only.

5. Permuted label control. A 200 tree random forest on the same three splits,
   with labels permuted inside each training split only and scored against the
   true test labels. Macro F1 must fall to chance within ``--permutation-tolerance``.
   It tests the gate's own fitting code, not the headline pipeline.

6. Cross class duplicate clusters. Identical feature vectors carrying more than
   one class label, the irreducible error they force, and the accuracy ceiling
   that follows.

Implementation choices that change results
------------------------------------------
* Feature vectors are rounded to 9 decimal places before hashing in diagnostics
  1, 3 and 6, so vectors differing only below that precision count as equal.
* Missing values are filled with zero for diagnostics 1b, 4 and 5.
* Feature columns are every numeric column not in ``LABEL_COLS``.
* The defaults of ``run()`` (0.0) disable diagnostic 1b, the headroom sub-check
  and diagnostic 6 when the gate is called as a library; the command line
  defaults (0.20, 0.50, 0.005) enable them.

Thresholds are arguments, not constants, because the defensible value depends on
the transformation family.

Usage
-----
    python3 scripts/diversity_gate.py --features data/features.csv
    python3 scripts/diversity_gate.py --features data/features.csv \
        --label technique --min-distinct-ratio 0.80 --max-single-feature-f1 0.70
    python3 scripts/diversity_gate.py --features data/features_pilot.csv \
        --label technique --full-macro-f1 0.9542 \
        --full-macro-f1-protocol "<how the headline score was measured>" \
        --repeats 10 --report gate.json

Exit status is 0 when every enabled check passes and 1 when any check fails, so
the HTCondor DAG node holds the rest of the pipeline back on failure. An
inconclusive headroom does not change the exit status; it is reported in the
JSON (``single_feature.headroom_status`` and the top level ``inconclusive``
list) and on the console.
"""
from __future__ import annotations

import argparse
import json
import sys
from typing import Dict, List, Optional, Sequence, Tuple

import numpy as np
import pandas as pd

LABEL_COLS = ["path", "cohort", "sample_id", "technique", "sub_technique", "malware_family"]

# Implementation constants that change results. They are named here so the
# report can record them; changing any of them changes committed gate reports.
VECTOR_ROUND_DECIMALS = 9      # diagnostics 1, 3 and 6 hash rounded vectors
INPUT_DEPENDENCE_PERMUTATIONS = 200  # diagnostic 1b permutation count
INPUT_DEPENDENCE_SEED = 0      # diagnostic 1b permutation seed (not --seed)
PROBE_MAX_DEPTH_CAP = 8        # diagnostic 4 depth = min(8, n_classes + 2)
GREEDY_POOL_SIZE = 24          # diagnostic 4 candidates for k above one
PROBE_N_SPLITS = 3             # diagnostics 4 and 5 GroupShuffleSplit splits
PROBE_TEST_SIZE = 0.3          # diagnostics 4 and 5 test share per split
HEADROOM_GAP_EPS = 1e-9        # R is undefined when F1_full - chance <= this


def feature_columns(df: pd.DataFrame) -> List[str]:
    cols = [c for c in df.columns if c not in LABEL_COLS]
    numeric = [c for c in cols if pd.api.types.is_numeric_dtype(df[c])]
    if not numeric:
        raise ValueError("no numeric feature columns found")
    return numeric


def _vector_keys(frame: pd.DataFrame, feats: Sequence[str]) -> pd.Series:
    """Hashable key per row so identical vectors compare equal.

    Rounded before hashing because two artifacts that differ only in floating
    point noise are not meaningfully distinct, and an unrounded hash would hide
    a degenerate class behind a trailing digit.
    """
    rounded = frame[list(feats)].astype("float64").round(VECTOR_ROUND_DECIMALS)
    return pd.Series(
        [hash(tuple(row)) for row in rounded.to_numpy()], index=frame.index
    )


# ---------------------------------------------------------------- check 1 and 2

def check_class_diversity(
    df: pd.DataFrame,
    feats: Sequence[str],
    label: str,
    min_distinct_ratio: float,
    max_constant_fraction: float,
    group: Optional[str] = None,
    min_input_dependence: float = 0.0,
    input_dependence_alpha: float = 0.05,
) -> Tuple[bool, List[Dict], List[str]]:
    """Per class distinctness, zero variance features, and input dependence.

    The distinct vector ratio on its own is a weak diagnostic and version 1 of
    this gate over claimed what it measures. If a generator is run with a fresh
    random seed per artifact then almost every output vector differs from every
    other, the ratio sits near one, and the gate passes. Nothing about that
    establishes that the corpus varies with the input program, which is the
    property an attribution claim actually needs. A corpus built by transforming
    one single program a thousand times with a thousand seeds would clear the
    ratio comfortably and still teach a classifier nothing except the identity
    of that program.

    The ratio is therefore kept but demoted to a necessary condition, and a
    second quantity is reported beside it that the seed jitter attack cannot
    fake. Input dependence is the share of total feature variance inside a class
    that lies between input programs rather than within them:

        D = SS_between_groups / SS_total        computed per feature,
                                                then averaged over features

    Seed jitter moves artifacts around within a group, which raises SS_within
    and lowers D. Only genuine sensitivity to the input program raises it. The
    two numbers answer different questions and a corpus needs both: distinctness
    says the generator is not emitting literal copies, input dependence says the
    features are describing a transformation applied to varied material rather
    than a constant signature plus noise.

    Features with no variance at all inside the class are excluded from the
    average, since their D is undefined rather than zero, and they are already
    counted by the constant feature diagnostic.
    """
    rows: List[Dict] = []
    failures: List[str] = []

    for cls, grp in df.groupby(label, sort=True):
        n = len(grp)
        keys = _vector_keys(grp, feats)
        n_distinct = int(keys.nunique())
        ratio = n_distinct / n if n else 0.0

        nunique_per_feat = grp[list(feats)].nunique(dropna=False)
        n_constant = int((nunique_per_feat <= 1).sum())
        const_fraction = n_constant / len(feats)

        row = {
            "class": str(cls),
            "n": n,
            "distinct_vectors": n_distinct,
            "distinct_ratio": round(ratio, 4),
            "constant_features": n_constant,
            "constant_fraction": round(const_fraction, 4),
        }

        dependence = _input_dependence(grp, feats, group) if group else None
        if dependence is not None:
            row["input_dependence"] = round(dependence["mean"], 4)
            row["dependence_omega2"] = round(dependence["omega_squared"], 4)
            row["n_groups"] = dependence["n_groups"]
            row["seed_sensitivity"] = round(1.0 - dependence["mean"], 4)
            perm = dependence.get("permutation") or {}
            row["dependence_null_mean"] = perm.get("null_mean")
            row["dependence_z"] = perm.get("z_score")
            row["dependence_p"] = perm.get("p_value")

        rows.append(row)

        if ratio < min_distinct_ratio:
            failures.append(
                f"class '{cls}': {n_distinct} distinct vectors in {n} artifacts "
                f"(ratio {ratio:.3f} below {min_distinct_ratio:.2f}). The generator "
                "is producing near identical output within this class, so the "
                "class is separable without any attribution signal."
            )
        if const_fraction > max_constant_fraction:
            failures.append(
                f"class '{cls}': {n_constant} of {len(feats)} features have zero "
                f"variance (fraction {const_fraction:.3f} above "
                f"{max_constant_fraction:.2f}). Those features identify the class "
                "rather than describe it."
            )
        if (dependence is not None and min_input_dependence > 0.0
                and dependence["n_groups"] >= 2
                and (dependence.get("permutation") or {}).get("p_value") is not None
                and dependence["permutation"]["p_value"] > input_dependence_alpha):
            perm = dependence["permutation"]
            failures.append(
                f"class '{cls}': the between program share of feature variance is "
                f"{dependence['omega_squared']:.3f} after bias correction, against "
                f"{perm['null_mean']:.3f} when the program labels are shuffled "
                f"(p = {perm['p_value']:.3f} over {perm['n_permutations']} "
                "permutations). The variation within this class does not track the "
                f"input programs, so the distinct vector ratio of {ratio:.3f} is "
                "being produced by generator randomness rather than by sensitivity "
                "to the material being transformed."
            )

    return (not failures), rows, failures


def _eta_squared(x: pd.DataFrame, codes: np.ndarray, n_groups: int) -> Dict:
    """Per feature between group variance share and its bias corrected form.

    The raw share, eta squared, is ``ss_between / ss_total``. It is not centred
    on zero when there is no group effect: with ``k`` groups and ``n`` rows of
    pure noise its expectation is about ``(k - 1) / (n - 1)``, so a table with
    many small groups scores above zero for no reason. Omega squared removes
    that bias by subtracting the within group mean square that ``k - 1``
    degrees of freedom would absorb by chance, which makes the number
    comparable across tables with different group counts.
    """
    n = len(x)
    grand = x.mean(axis=0)
    ss_total = ((x - grand) ** 2).sum(axis=0)

    means = x.groupby(codes).mean()
    sizes = pd.Series(np.bincount(codes, minlength=n_groups), dtype="float64")
    sizes = sizes.reindex(means.index)
    ss_between = ((means - grand) ** 2).mul(sizes, axis=0).sum(axis=0)

    n_present = int(len(means))
    ss_within = (ss_total - ss_between).clip(lower=0.0)
    df_within = max(n - n_present, 1)
    ms_within = ss_within / df_within

    varying = ss_total > 1e-12
    if not bool(varying.any()):
        return {"eta_squared": 0.0, "omega_squared": 0.0, "n_varying_features": 0,
                "per_feature": {}}

    eta = (ss_between[varying] / ss_total[varying]).clip(0.0, 1.0)
    k_minus_1 = max(n_present - 1, 1)
    omega_num = ss_between[varying] - k_minus_1 * ms_within[varying]
    omega_den = ss_total[varying] + ms_within[varying]
    omega = (omega_num / omega_den.replace(0.0, np.nan)).fillna(0.0).clip(-1.0, 1.0)

    return {
        "eta_squared": float(eta.mean()),
        "omega_squared": float(omega.mean()),
        "n_varying_features": int(varying.sum()),
        "per_feature": {k: round(float(v), 4) for k, v in omega.items()},
    }


def _input_dependence(
    frame: pd.DataFrame,
    feats: Sequence[str],
    group: str,
    n_permutations: int = INPUT_DEPENDENCE_PERMUTATIONS,
    seed: int = INPUT_DEPENDENCE_SEED,
) -> Optional[Dict]:
    """Does the within class feature variation track the input programs?

    Version 1 of this diagnostic reported one number, the between group
    variance share, and compared it against a fixed threshold. Testing the gate
    against tables whose correct verdict was known in advance showed that the
    fixed threshold was the weak part: it was chosen so that the authors' own
    corpus cleared it, which is not a calibration. Two changes follow.

    First the statistic is bias corrected, because the raw share rises with the
    group count even under no group effect at all.

    Second the decision is made against a permutation null rather than against a
    constant. Group labels are shuffled among the rows of the class, which
    destroys any association between a row and the program it came from while
    leaving every marginal distribution intact, and the statistic is recomputed.
    A corpus whose variation really does come from the input programs scores far
    above that null. A corpus whose variation is generator randomness scores
    inside it, because for such a corpus the group label carries no information
    and shuffling it changes nothing. The threshold is then a property of the
    table being examined rather than a number carried over from another corpus.

    Returns ``None`` when the grouping column is absent.
    """
    if group not in frame.columns:
        return None
    groups = frame[group].astype(str)
    n_groups = int(groups.nunique())
    if n_groups < 2:
        return {"mean": 0.0, "omega_squared": 0.0, "n_groups": n_groups,
                "per_feature": {}, "permutation": None}

    x = frame[list(feats)].astype("float64").fillna(0.0).reset_index(drop=True)
    codes = pd.Categorical(groups).codes.astype(int)

    observed = _eta_squared(x, codes, n_groups)

    rng = np.random.default_rng(seed)
    null = np.empty(n_permutations, dtype=float)
    for i in range(n_permutations):
        null[i] = _eta_squared(x, rng.permutation(codes), n_groups)["omega_squared"]

    null_mean, null_sd = float(null.mean()), float(null.std(ddof=1))
    obs = observed["omega_squared"]
    exceed = int((null >= obs).sum())
    return {
        # "mean" keeps the version 1 field name so existing callers and reports
        # still read, and still holds the raw share.
        "mean": observed["eta_squared"],
        "omega_squared": obs,
        "n_groups": n_groups,
        "n_varying_features": observed["n_varying_features"],
        "per_feature": observed["per_feature"],
        "permutation": {
            "n_permutations": n_permutations,
            "null_mean": round(null_mean, 6),
            "null_sd": round(null_sd, 6),
            "null_p95": round(float(np.quantile(null, 0.95)), 6),
            "z_score": (round(float((obs - null_mean) / null_sd), 3)
                        if null_sd > 1e-12 else None),
            "p_value": round((exceed + 1) / (n_permutations + 1), 5),
        },
    }


# ---------------------------------------------------------------------- check 3

def check_cross_group_duplicates(
    df: pd.DataFrame,
    feats: Sequence[str],
    group: str,
    max_affected_fraction: float,
) -> Tuple[bool, Dict, List[str]]:
    keys = _vector_keys(df, feats)
    work = pd.DataFrame({"key": keys, "group": df[group].astype(str)})

    per_key = work.groupby("key")["group"].agg(["nunique", "size"])
    spanning = per_key[(per_key["nunique"] > 1) & (per_key["size"] > 1)]

    affected_rows = int(spanning["size"].sum())
    fraction = affected_rows / len(df) if len(df) else 0.0

    stats = {
        "group_column": group,
        "duplicate_clusters_spanning_groups": int(len(spanning)),
        "rows_in_those_clusters": affected_rows,
        "fraction_of_corpus": round(fraction, 4),
        "total_rows": int(len(df)),
        "distinct_vectors_overall": int(keys.nunique()),
    }

    failures: List[str] = []
    if fraction > max_affected_fraction:
        failures.append(
            f"{len(spanning)} duplicate feature vector clusters span more than one "
            f"'{group}', covering {affected_rows} rows ({fraction:.1%} of the "
            f"corpus, above {max_affected_fraction:.1%}). Grouping by '{group}' "
            "therefore does not stop feature identical rows appearing in both "
            "train and test, so the held out score is optimistic."
        )
    return (not failures), stats, failures


# ---------------------------------------------------------------------- check 6

def check_cross_class_duplicates(
    df: pd.DataFrame,
    feats: Sequence[str],
    label: str,
    max_affected_fraction: float,
) -> Tuple[bool, Dict, List[str]]:
    """Identical feature vectors carrying more than one class label.

    Version 1 of this gate had a blind spot that the gate itself could not have
    reported. Check 3 groups duplicate vectors by the split key and never by the
    label, so a vector appearing under two different classes passes unnoticed as
    long as it also appears under two different split keys. Those rows are not
    merely leakage, they are an irreducible error floor: no function of the
    features can assign both labels, so at least the smaller side of every such
    cluster is guaranteed wrong, and the ceiling on any classifier is below one
    by a known amount before any model is fitted.

    Reported quantities:

      clusters              duplicate vector clusters spanning two or more labels
      rows_in_those_clusters  how much of the corpus sits in them
      irreducible_errors    rows that must be misclassified, summed over
                            clusters as (cluster size minus its majority count)
      accuracy_ceiling      one minus the irreducible error rate

    The ceiling is the honest upper bound to compare a reported accuracy
    against. A paper reporting accuracy above the ceiling has either leaked or
    mismeasured, and a paper reporting accuracy at the ceiling has saturated the
    corpus rather than solved the problem.
    """
    keys = _vector_keys(df, feats)
    work = pd.DataFrame({"key": keys, "label": df[label].astype(str)})

    per_key = work.groupby("key")["label"].agg(["nunique", "size"])
    spanning = per_key[per_key["nunique"] > 1]

    affected_rows = int(spanning["size"].sum())
    fraction = affected_rows / len(df) if len(df) else 0.0

    irreducible = 0
    detail: List[Dict] = []
    if len(spanning):
        members = work[work["key"].isin(spanning.index)]
        for key, grp in members.groupby("key"):
            counts = grp["label"].value_counts()
            irreducible += int(len(grp) - counts.iloc[0])
            detail.append({
                "rows": int(len(grp)),
                "labels": {str(k): int(v) for k, v in counts.items()},
                "forced_errors": int(len(grp) - counts.iloc[0]),
            })
        detail.sort(key=lambda d: d["forced_errors"], reverse=True)

    stats = {
        "label_column": label,
        "duplicate_clusters_spanning_labels": int(len(spanning)),
        "rows_in_those_clusters": affected_rows,
        "fraction_of_corpus": round(fraction, 4),
        "irreducible_errors": irreducible,
        "irreducible_error_rate": round(irreducible / len(df), 6) if len(df) else 0.0,
        "accuracy_ceiling": round(1.0 - irreducible / len(df), 6) if len(df) else 1.0,
        "worst_clusters": detail[:10],
    }

    failures: List[str] = []
    if fraction > max_affected_fraction:
        failures.append(
            f"{len(spanning)} duplicate feature vector clusters carry more than one "
            f"'{label}' label, covering {affected_rows} rows ({fraction:.2%} of the "
            f"corpus, above {max_affected_fraction:.2%}). {irreducible} of those "
            "rows cannot be classified correctly by any model, so the accuracy "
            f"ceiling for this label is {1.0 - irreducible / len(df):.4f} and the "
            "feature set does not separate the classes it is being asked to name."
        )
    return (not failures), stats, failures


# ---------------------------------------------------------------------- check 4

def check_single_feature_ceiling(
    df: pd.DataFrame,
    feats: Sequence[str],
    label: str,
    group: str,
    max_f1: float,
    seed: int,
    max_headroom: float = 0.0,
    k_values: Sequence[int] = (1, 2, 3),
    full_macro_f1: Optional[float] = None,
    full_macro_f1_protocol: Optional[str] = None,
) -> Tuple[bool, Dict, List[str]]:
    """Macro F1 reachable from the best k features, and the headroom above it.

    Returned statistics added in the revision, beside the version 2 fields:

      headroom_status    "pass", "fail", "inconclusive" (R undefined because
                         F1_full - F1_chance <= 0), or "not_checked" (R
                         defined but ``max_headroom`` is zero)
      headroom_gap       F1_full - F1_chance, the denominator of R
      headroom_reference which value F1_full is, the protocol it was measured
                         under, and the protocol of the best k scores
      full_set_probe_macro_f1, headroom_R_probe_reference
                         the same R computed against the gate's own probe tree
                         on all features, so the two references can be compared
      probe_settings     depth, depth rule, splitter, candidate pool

    Two things were wrong with the version 1 form of this diagnostic.

    First, the threshold was an absolute macro F1 and absolute macro F1 is not
    comparable across corpora. Chance macro F1 is near 1/n_classes, so a score
    of 0.70 from one feature is close to worthless on a two class problem and
    remarkable on a twenty class problem. A fixed 0.70 bar is therefore strict
    on wide label sets and vacuous on narrow ones, which is the opposite of what
    is wanted. The repair is to report chance corrected headroom

        R = (F1_full - F1_best_k) / (F1_full - F1_chance)

    which is the share of the achievable gap above chance that the full feature
    set adds on top of the best k features alone. R near one means the full set
    is doing the work. R near zero means k features already had the answer and
    the remaining features are decoration. Numerator and denominator are
    measured from the same chance baseline, but R is not invariant to the class
    count: how high R can go still depends on 1/n_classes and on F1_full. When
    F1_full is at or below chance, R is undefined and the status is reported as
    inconclusive rather than passed.

    Second, probing one feature at a time misses shortcuts that live in a pair.
    Two features that are individually weak can be jointly sufficient, and a
    corpus whose classes are separated by a two feature rule has a shortcut just
    as surely as one separated by a single threshold. Subsets up to size k are
    therefore searched, with a depth limited tree per subset (depth
    ``min(8, n_classes + 2)``, so depth 6 for four classes and 8 for ten).

    Enumeration is exhaustive for k equal to one, and greedy forward selection
    for larger k, because the full subset count grows too quickly to enumerate
    and greedy selection is the conservative direction: it can only understate
    the reachable ceiling, so a failure it reports is real.
    """
    from sklearn.model_selection import GroupShuffleSplit
    from sklearn.metrics import f1_score
    from sklearn.tree import DecisionTreeClassifier

    y = df[label].astype(str).to_numpy()
    groups = df[group].astype(str).to_numpy()

    classes = np.unique(y)
    n_classes = len(classes)
    if n_classes < 2:
        return True, {"skipped": "fewer than two classes"}, []
    if len(np.unique(groups)) < 2:
        return True, {"skipped": f"fewer than two '{group}' values"}, []

    splitter = GroupShuffleSplit(n_splits=PROBE_N_SPLITS, test_size=PROBE_TEST_SIZE,
                                 random_state=seed)
    splits = list(splitter.split(np.zeros(len(df)), y, groups))
    depth = min(PROBE_MAX_DEPTH_CAP, n_classes + 2)

    values = df[list(feats)].astype("float64").fillna(0.0).to_numpy()
    col = {f: i for i, f in enumerate(feats)}

    def score_subset(subset: Sequence[str], tree_depth: int) -> Optional[float]:
        idx = [col[f] for f in subset]
        x = values[:, idx]
        fold_scores = []
        for tr, te in splits:
            if len(np.unique(y[tr])) < 2:
                continue
            clf = DecisionTreeClassifier(max_depth=tree_depth, random_state=seed)
            clf.fit(x[tr], y[tr])
            fold_scores.append(
                f1_score(y[te], clf.predict(x[te]), average="macro",
                         zero_division=0)
            )
        return float(np.mean(fold_scores)) if fold_scores else None

    singles: Dict[str, float] = {}
    for feat in feats:
        s = score_subset([feat], depth)
        if s is not None:
            singles[feat] = s
    if not singles:
        return True, {"skipped": "no evaluable splits"}, []

    ranked = sorted(singles.items(), key=lambda kv: kv[1], reverse=True)
    best_feat, best_single = ranked[0]

    # Greedy forward selection for k above one, seeded with the best single
    # feature. Candidates are limited to the strongest singles so the cost stays
    # bounded on wide feature tables; a shortcut built from two features that
    # are both individually near chance is possible in principle but has not
    # been observed here, and the limit is recorded so the omission is visible.
    pool = [f for f, _ in ranked[: min(len(ranked), GREEDY_POOL_SIZE)]]
    chosen = [best_feat]
    per_k = {1: round(best_single, 4)}
    k_trace = [{"k": 1, "features": list(chosen), "macro_f1": round(best_single, 4)}]
    current = best_single
    for k in sorted(set(int(v) for v in k_values) - {1}):
        while len(chosen) < k:
            gains = []
            for feat in pool:
                if feat in chosen:
                    continue
                s = score_subset(chosen + [feat], depth)
                if s is not None:
                    gains.append((s, feat))
            if not gains:
                break
            s, feat = max(gains)
            chosen.append(feat)
            current = s
        if len(chosen) == k:
            per_k[k] = round(current, 4)
            k_trace.append({"k": k, "features": list(chosen),
                            "macro_f1": round(current, 4)})

    # A shallow tree on the whole feature table. The gap between this and the
    # headline model separates "the corpus is easy" from "the model is good".
    full_shallow = score_subset(list(feats), 3)
    full_unrestricted = score_subset(list(feats), depth)

    chance = 1.0 / n_classes
    reference = (full_macro_f1 if full_macro_f1 is not None
                 else full_unrestricted)
    headroom = None
    if reference is not None and reference - chance > HEADROOM_GAP_EPS:
        headroom = (reference - best_single) / (reference - chance)

    # The same ratio against the gate's own probe tree, reported whatever the
    # reference above is, so a supplied headline score measured under another
    # protocol can be compared with a reference measured on these splits.
    headroom_probe = None
    if (full_unrestricted is not None
            and full_unrestricted - chance > HEADROOM_GAP_EPS):
        headroom_probe = ((full_unrestricted - best_single)
                          / (full_unrestricted - chance))

    gap = (reference - chance) if reference is not None else None
    if headroom is None:
        headroom_status = "inconclusive"
        if reference is None:
            headroom_note = ("no full feature set score could be computed, so "
                             "R is undefined; the headroom sub-check was not "
                             "applied")
        else:
            headroom_note = (
                f"F1_full ({reference:.4f}) - F1_chance ({chance:.4f}) = "
                f"{gap:.4f} is not above zero, so R is undefined; the headroom "
                "sub-check neither passes nor fails on this table")
    elif max_headroom <= 0.0:
        headroom_status = "not_checked"
        headroom_note = "R is defined but no minimum headroom was set"
    elif headroom < max_headroom:
        headroom_status = "fail"
        headroom_note = f"R {headroom:.4f} below {max_headroom:.2f}"
    else:
        headroom_status = "pass"
        headroom_note = f"R {headroom:.4f} at or above {max_headroom:.2f}"

    splitter_desc = (f"GroupShuffleSplit(n_splits={PROBE_N_SPLITS}, "
                     f"test_size={PROBE_TEST_SIZE}, random_state={seed}) "
                     f"grouped by '{group}'")
    best_k_protocol = (f"DecisionTreeClassifier(max_depth={depth}, "
                       f"random_state={seed}) on the feature subset, mean macro "
                       f"F1 over {splitter_desc}")
    if full_macro_f1 is not None:
        reference_protocol = (full_macro_f1_protocol
                              or "supplied by the caller with --full-macro-f1; "
                                 "protocol not stated")
        same_protocol = False
    else:
        reference_protocol = (f"DecisionTreeClassifier(max_depth={depth}, "
                              f"random_state={seed}) on all {len(feats)} "
                              f"features, mean macro F1 over {splitter_desc}")
        same_protocol = True

    stats = {
        "n_classes": n_classes,
        "chance_macro_f1": round(chance, 4),
        "best_feature": best_feat,
        "best_macro_f1": round(best_single, 4),
        "macro_f1_by_k": per_k,
        "greedy_trace": k_trace,
        "candidate_pool_size": len(pool),
        "full_set_shallow_depth3": round(full_shallow, 4)
        if full_shallow is not None else None,
        "full_set_macro_f1": round(reference, 4) if reference is not None else None,
        "full_set_source": "supplied" if full_macro_f1 is not None
        else "probe tree on all features",
        "headroom_R": round(headroom, 4) if headroom is not None else None,
        "top_five": [{"feature": f, "macro_f1": round(s, 4)} for f, s in ranked[:5]],
        "threshold_absolute_f1": max_f1,
        "threshold_min_headroom": max_headroom,
        # Fields below were added in the revision; the ones above are unchanged.
        "headroom_status": headroom_status,
        "headroom_note": headroom_note,
        "headroom_gap": round(gap, 4) if gap is not None else None,
        "headroom_reference": {
            "full_set_source": "supplied" if full_macro_f1 is not None
            else "probe tree on all features",
            "full_set_value": round(reference, 4) if reference is not None else None,
            "full_set_protocol": reference_protocol,
            "best_k_protocol": best_k_protocol,
            "same_protocol_as_best_k": same_protocol,
        },
        "full_set_probe_macro_f1": round(full_unrestricted, 4)
        if full_unrestricted is not None else None,
        "headroom_R_probe_reference": round(headroom_probe, 4)
        if headroom_probe is not None else None,
        "probe_settings": {
            "tree_depth": depth,
            "depth_rule": f"min({PROBE_MAX_DEPTH_CAP}, n_classes + 2)",
            "splitter": splitter_desc,
            "seed": seed,
            "k_values": sorted(set(int(v) for v in k_values)),
            "k1_search": "exhaustive over all features",
            "k_above_1_search": (f"greedy forward selection from the "
                                 f"{GREEDY_POOL_SIZE} strongest single features"),
            "selection_and_scoring_on_same_splits": True,
        },
    }

    failures: List[str] = []
    if best_single > max_f1:
        failures.append(
            f"single feature '{best_feat}' reaches macro F1 {best_single:.3f} on its "
            f"own (above {max_f1:.2f}) against a chance level of {chance:.3f}. One "
            "scalar is carrying the attribution result, so the corpus has an "
            "artifact dependent shortcut rather than a transformation signature."
        )
    if (max_headroom > 0.0 and headroom is not None
            and headroom < max_headroom):
        failures.append(
            f"chance corrected headroom R is {headroom:.3f} (below {max_headroom:.2f}). "
            f"The best single feature '{best_feat}' recovers "
            f"{1.0 - headroom:.1%} of the gap between chance and the full feature "
            "set, so the remaining features add little and the reported result is "
            "close to a one feature rule dressed up as a learned model."
        )
    for k, v in per_k.items():
        if k > 1 and v > max_f1:
            failures.append(
                f"the best {k} features together reach macro F1 {v:.3f} (above "
                f"{max_f1:.2f}) with a depth {depth} tree. A {k} feature rule "
                "settles the label, so the corpus is separable without the "
                "representation the paper is arguing for."
            )
            break
    return (not failures), stats, failures


# ---------------------------------------------------------------------- check 5

def check_permuted_labels(
    df: pd.DataFrame,
    feats: Sequence[str],
    label: str,
    group: str,
    tolerance: float,
    seed: int,
) -> Tuple[bool, Dict, List[str]]:
    """Fit the real model on permuted labels and require chance performance.

    The permutation is applied to the label column only. Features, group keys and
    splits are left alone, so the only thing removed is the association between
    an artifact and its class. A model that still scores above chance is reading
    the labels through some channel other than the features, which means the
    evaluation is broken rather than the corpus being good.

    Reported against 1/n_classes because macro F1 under a permuted multiclass
    label lands near that value for any sensible classifier.
    """
    from sklearn.ensemble import RandomForestClassifier
    from sklearn.metrics import f1_score
    from sklearn.model_selection import GroupShuffleSplit

    x = df[list(feats)].astype("float64").fillna(0.0).to_numpy()
    y = df[label].astype(str).to_numpy()
    groups = df[group].astype(str).to_numpy()

    classes = np.unique(y)
    if len(classes) < 2 or len(np.unique(groups)) < 2:
        return True, {"skipped": "needs two classes and two groups"}, []

    chance = 1.0 / len(classes)
    rng = np.random.default_rng(seed)
    splitter = GroupShuffleSplit(n_splits=PROBE_N_SPLITS, test_size=PROBE_TEST_SIZE,
                                 random_state=seed)
    splits = list(splitter.split(x, y, groups))

    real, permuted = [], []
    for tr, te in splits:
        clf = RandomForestClassifier(n_estimators=200, random_state=seed, n_jobs=-1)
        clf.fit(x[tr], y[tr])
        real.append(f1_score(y[te], clf.predict(x[te]), average="macro",
                             zero_division=0))

        # Permute within the training set only. Permuting the whole column would
        # also scramble the test labels, which makes the comparison trivially
        # low for the wrong reason.
        y_perm = y.copy()
        y_perm[tr] = rng.permutation(y[tr])
        clf_p = RandomForestClassifier(n_estimators=200, random_state=seed, n_jobs=-1)
        clf_p.fit(x[tr], y_perm[tr])
        permuted.append(f1_score(y[te], clf_p.predict(x[te]), average="macro",
                                 zero_division=0))

    m_real = float(np.mean(real))
    m_perm = float(np.mean(permuted))
    stats = {
        "real_macro_f1": round(m_real, 4),
        "permuted_macro_f1": round(m_perm, 4),
        "chance_macro_f1": round(chance, 4),
        "excess_over_chance": round(m_perm - chance, 4),
        "tolerance": tolerance,
    }

    failures: List[str] = []
    if m_perm - chance > tolerance:
        failures.append(
            f"with labels permuted the model still reaches macro F1 {m_perm:.3f} "
            f"against a chance level of {chance:.3f}, an excess of "
            f"{m_perm - chance:.3f} above the {tolerance:.2f} tolerance. Nothing "
            "is learnable from permuted labels, so the evaluation is reading the "
            "label through a channel other than the features and every score it "
            "produces is suspect."
        )
    return (not failures), stats, failures


# ----------------------------------------------------------------------- report

def _table(rows: Sequence[Dict], cols: Sequence[str]) -> str:
    header = [c for c in cols]
    body = [[str(r.get(c, "")) for c in cols] for r in rows]
    widths = [max(len(header[i]), *(len(b[i]) for b in body)) if body else len(header[i])
              for i in range(len(header))]
    out = ["  ".join(h.ljust(widths[i]) for i, h in enumerate(header)),
           "  ".join("-" * w for w in widths)]
    for b in body:
        out.append("  ".join(b[i].ljust(widths[i]) for i in range(len(header))))
    return "\n".join(out)


def run(
    features_path: str,
    label: str,
    group: str,
    min_distinct_ratio: float,
    max_constant_fraction: float,
    max_affected_fraction: float,
    max_single_feature_f1: float,
    permutation_tolerance: float,
    seed: int,
    report_path: Optional[str],
    skip_single_feature: bool,
    max_cross_class_fraction: float = 0.0,
    min_headroom: float = 0.0,
    min_input_dependence: float = 0.0,
    input_dependence_alpha: float = 0.05,
    full_macro_f1: Optional[float] = None,
    full_macro_f1_protocol: Optional[str] = None,
    repeats: int = 1,
) -> int:
    if repeats < 1:
        raise ValueError("repeats must be at least 1")
    df = pd.read_csv(features_path)
    for col in (label, group):
        if col not in df.columns:
            raise ValueError(f"column '{col}' not in {features_path}")
    feats = feature_columns(df)

    print(f"corpus    {features_path}")
    print(f"rows      {len(df)}")
    print(f"features  {len(feats)}")
    print(f"label     {label}  ({df[label].nunique()} classes)")
    print(f"group     {group}  ({df[group].nunique()} groups)")
    print()

    all_failures: List[str] = []
    inconclusive: List[str] = []
    report: Dict = {"features_path": features_path, "label": label, "group": group}

    ok1, class_rows, f1_fail = check_class_diversity(
        df, feats, label, min_distinct_ratio, max_constant_fraction,
        group=group, min_input_dependence=min_input_dependence,
        input_dependence_alpha=input_dependence_alpha,
    )
    print("CHECK 1 and 2  per class distinctness, constant features, input "
          "dependence")
    cols = ["class", "n", "distinct_vectors", "distinct_ratio",
            "constant_features", "constant_fraction"]
    if class_rows and "input_dependence" in class_rows[0]:
        cols += ["n_groups", "input_dependence", "dependence_omega2",
                 "dependence_null_mean", "dependence_z", "dependence_p"]
    print(_table(class_rows, cols))
    print("  distinct_ratio is a necessary condition only. input_dependence is "
          "the raw share of within")
    print("  class feature variance lying between input programs; "
          "dependence_omega2 is the same quantity")
    print("  with the upward bias from the group count removed, and "
          "dependence_null_mean is its value when")
    print("  the program labels are shuffled. The verdict uses dependence_p, "
          "not a fixed cut, so a high")
    print("  distinct ratio with variation that does not track the input "
          "programs is caught whatever the")
    print("  group count happens to be.")
    print()
    report["per_class"] = class_rows
    all_failures += f1_fail

    ok3, dup_stats, f3_fail = check_cross_group_duplicates(
        df, feats, group, max_affected_fraction
    )
    print("CHECK 3  duplicate feature vectors spanning groups")
    for k, v in dup_stats.items():
        print(f"  {k:38s} {v}")
    print()
    report["cross_group_duplicates"] = dup_stats
    all_failures += f3_fail

    ok6, cc_stats, f6_fail = check_cross_class_duplicates(
        df, feats, label, max_cross_class_fraction
    )
    print("CHECK 6  duplicate feature vectors spanning class labels")
    for k, v in cc_stats.items():
        if k == "worst_clusters":
            if v:
                print("  worst_clusters")
                for item in v:
                    print(f"    rows={item['rows']:4d} forced_errors="
                          f"{item['forced_errors']:4d}  {item['labels']}")
            continue
        print(f"  {k:38s} {v}")
    print("  accuracy_ceiling is the highest accuracy any model can reach on "
          "this feature table and")
    print("  label. Compare every reported accuracy against it.")
    print()
    report["cross_class_duplicates"] = cc_stats
    all_failures += f6_fail

    if skip_single_feature:
        print("CHECK 4  skipped by request")
        print()
        report["single_feature"] = {"skipped": "by request"}
    else:
        ok4, sf_stats, f4_fail = check_single_feature_ceiling(
            df, feats, label, group, max_single_feature_f1, seed,
            max_headroom=min_headroom, full_macro_f1=full_macro_f1,
            full_macro_f1_protocol=full_macro_f1_protocol,
        )
        print("CHECK 4  best k feature ceiling and chance corrected headroom")
        for k, v in sf_stats.items():
            if k == "top_five":
                print("  top_five")
                for item in v:
                    print(f"    {item['feature']:30s} {item['macro_f1']}")
            elif k == "greedy_trace":
                print("  greedy_trace")
                for item in v:
                    print(f"    k={item['k']}  {item['macro_f1']}  "
                          f"{', '.join(item['features'])}")
            elif k in ("headroom_reference", "probe_settings"):
                print(f"  {k}")
                for kk, vv in v.items():
                    print(f"    {str(kk):36s} {vv}")
            else:
                print(f"  {k:38s} {v}")
        print("  headroom_R = (full - best_single) / (full - chance). Near zero "
              "means one feature")
        print("  already recovers the achievable gap above chance.")
        if sf_stats.get("headroom_status") == "inconclusive":
            msg = ("diagnostic 4 headroom INCONCLUSIVE: "
                   + sf_stats.get("headroom_note", "R is undefined"))
            inconclusive.append(msg)
            print(f"  {msg}")
        print()
        report["single_feature"] = sf_stats
        all_failures += f4_fail

        if repeats > 1:
            report["single_feature_repeats"] = _repeat_single_feature(
                df, feats, label, group, max_single_feature_f1, seed, repeats,
                min_headroom, full_macro_f1, full_macro_f1_protocol, sf_stats)
            _print_repeats(report["single_feature_repeats"])

    ok5, perm_stats, f5_fail = check_permuted_labels(
        df, feats, label, group, permutation_tolerance, seed
    )
    print("CHECK 5  permuted label control")
    for k, v in perm_stats.items():
        print(f"  {k:38s} {v}")
    print()
    report["permuted_labels"] = perm_stats
    all_failures += f5_fail

    report["failures"] = all_failures
    report["passed"] = not all_failures
    # Added in the revision. "inconclusive" lists sub-checks that could not be
    # decided on this table; they do not change "passed" or the exit status.
    report["inconclusive"] = inconclusive
    report["gate_settings"] = {
        "seed": seed,
        "repeats": repeats,
        "min_distinct_ratio": min_distinct_ratio,
        "max_constant_fraction": max_constant_fraction,
        "max_cross_group_fraction": max_affected_fraction,
        "max_single_feature_f1": max_single_feature_f1,
        "permutation_tolerance": permutation_tolerance,
        "max_cross_class_fraction": max_cross_class_fraction,
        "min_headroom": min_headroom,
        "min_input_dependence": min_input_dependence,
        "input_dependence_alpha": input_dependence_alpha,
        "input_dependence_permutations": INPUT_DEPENDENCE_PERMUTATIONS,
        "input_dependence_seed": INPUT_DEPENDENCE_SEED,
        "vector_round_decimals": VECTOR_ROUND_DECIMALS,
        "probe_depth_rule": f"min({PROBE_MAX_DEPTH_CAP}, n_classes + 2)",
        "greedy_pool_size": GREEDY_POOL_SIZE,
        "probe_splits": (f"GroupShuffleSplit(n_splits={PROBE_N_SPLITS}, "
                         f"test_size={PROBE_TEST_SIZE}, random_state=seed)"),
        "full_macro_f1": full_macro_f1,
        "full_macro_f1_protocol": full_macro_f1_protocol,
        "skip_single_feature": skip_single_feature,
    }

    if report_path:
        with open(report_path, "w") as fh:
            json.dump(report, fh, indent=2)
        print(f"report written to {report_path}")
        print()

    if all_failures:
        print("GATE FAILED")
        for i, msg in enumerate(all_failures, 1):
            print(f"  {i}. {msg}")
        print()
        if inconclusive:
            print("Inconclusive, neither passed nor failed:")
            for msg in inconclusive:
                print(f"    - {msg}")
            print()
        print("The corpus does not support an attribution claim in its current "
              "state. Increase generator variation, widen the input programs, or "
              "drop the degenerate classes, then rebuild.")
        return 1

    if skip_single_feature:
        ceiling_text = ("the best k feature ceiling and headroom were not "
                        "checked (skipped by request)")
    else:
        status = report["single_feature"].get("headroom_status")
        ceiling_text = "no small feature subset reaches the threshold, "
        if status == "pass":
            ceiling_text += "headroom above the best single feature is adequate"
        elif status == "inconclusive":
            ceiling_text += ("headroom is INCONCLUSIVE because the full feature "
                             "set does not score above chance, so R is "
                             "undefined")
        elif status == "not_checked":
            ceiling_text += "headroom was not checked (no minimum set)"
        else:
            ceiling_text += "headroom could not be evaluated"
    print("GATE PASSED  every class carries within class variation that tracks "
          "the input programs, no duplicate vector spans a group or a class "
          f"label, {ceiling_text}, and permuted labels fall to chance")
    if inconclusive:
        print("  Inconclusive, not passed:")
        for msg in inconclusive:
            print(f"    - {msg}")
    return 0


def _summary(values: Sequence[Optional[float]]) -> Dict:
    """Mean, minimum and maximum over the values that are defined."""
    defined = [float(v) for v in values if v is not None]
    if not defined:
        return {"mean": None, "min": None, "max": None, "n_defined": 0,
                "values": list(values)}
    return {
        "mean": round(float(np.mean(defined)), 4),
        "min": round(float(np.min(defined)), 4),
        "max": round(float(np.max(defined)), 4),
        "n_defined": len(defined),
        "values": list(values),
    }


def _repeat_single_feature(df, feats, label, group, max_f1, seed, repeats,
                           min_headroom, full_macro_f1, full_macro_f1_protocol,
                           first: Dict) -> Dict:
    """Re-run diagnostic 4 over split seeds ``seed .. seed + repeats - 1``.

    The first seed's statistics are passed in rather than recomputed. Only the
    spread is reported here; the verdict stays on the first seed.
    """
    runs = [first]
    for s in range(seed + 1, seed + repeats):
        _ok, st, _fail = check_single_feature_ceiling(
            df, feats, label, group, max_f1, s, max_headroom=min_headroom,
            full_macro_f1=full_macro_f1,
            full_macro_f1_protocol=full_macro_f1_protocol)
        runs.append(st)
    seeds = list(range(seed, seed + repeats))
    usable = [r for r in runs if "skipped" not in r]
    ks = sorted({int(k) for r in usable for k in r.get("macro_f1_by_k", {})} - {1})
    return {
        "seeds": seeds,
        "verdict_seed": seed,
        "note": ("The verdict, the failure messages and every field under "
                 "single_feature use the first seed only. This block reports "
                 "how diagnostic 4 moves with the split seed."),
        "best_feature_by_seed": [r.get("best_feature") for r in runs],
        "best_1_macro_f1": _summary([r.get("best_macro_f1") for r in runs]),
        "best_k_macro_f1": {
            str(k): _summary([r.get("macro_f1_by_k", {}).get(k) for r in runs])
            for k in ks
        },
        "headroom_R": _summary([r.get("headroom_R") for r in runs]),
        "headroom_R_probe_reference": _summary(
            [r.get("headroom_R_probe_reference") for r in runs]),
        "full_set_probe_macro_f1": _summary(
            [r.get("full_set_probe_macro_f1") for r in runs]),
        "headroom_status_by_seed": [r.get("headroom_status") for r in runs],
    }


def _print_repeats(rep: Dict) -> None:
    print(f"CHECK 4  repeated over split seeds {rep['seeds'][0]}.."
          f"{rep['seeds'][-1]} (verdict uses seed {rep['verdict_seed']} only)")
    rows = [("best_1_macro_f1", rep["best_1_macro_f1"])]
    rows += [(f"best_{k}_macro_f1", v) for k, v in rep["best_k_macro_f1"].items()]
    rows += [("headroom_R", rep["headroom_R"]),
             ("headroom_R_probe_reference", rep["headroom_R_probe_reference"])]
    for name, summ in rows:
        print(f"  {name:30s} mean {summ['mean']}  min {summ['min']}  "
              f"max {summ['max']}  (defined in {summ['n_defined']} of "
              f"{len(rep['seeds'])})")
    print(f"  best_feature_by_seed           {rep['best_feature_by_seed']}")
    print(f"  headroom_status_by_seed        {rep['headroom_status_by_seed']}")
    print()


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(
        description="Fail a corpus that cannot support an attribution claim."
    )
    ap.add_argument("--features", required=True, help="feature table CSV")
    ap.add_argument("--label", default="technique",
                    help="label column under test (default technique)")
    ap.add_argument("--group", default="sample_id",
                    help="grouping column whose leakage is checked (default sample_id)")
    ap.add_argument("--min-distinct-ratio", type=float, default=0.80,
                    help="minimum distinct feature vectors per class artifact")
    ap.add_argument("--max-constant-fraction", type=float, default=0.50,
                    help="maximum fraction of features allowed zero variance in a class")
    ap.add_argument("--max-cross-group-fraction", type=float, default=0.05,
                    help="maximum corpus fraction in duplicate clusters spanning groups")
    ap.add_argument("--max-single-feature-f1", type=float, default=0.70,
                    help="maximum macro F1 any one feature may reach alone")
    ap.add_argument("--permutation-tolerance", type=float, default=0.08,
                    help="how far above chance a permuted label fit may score")
    ap.add_argument("--max-cross-class-fraction", type=float, default=0.005,
                    help="maximum corpus fraction in duplicate clusters that "
                         "carry more than one class label (check 6)")
    ap.add_argument("--min-headroom", type=float, default=0.50,
                    help="minimum chance corrected headroom R above the best "
                         "single feature (check 4)")
    ap.add_argument("--min-input-dependence", type=float, default=0.20,
                    help="set above zero to enable the input dependence check. "
                         "The value no longer acts as a cut on the variance "
                         "share, because a fixed cut is not comparable across "
                         "tables with different group counts; the decision is "
                         "made by the permutation test governed by "
                         "--input-dependence-alpha (check 1b)")
    ap.add_argument("--input-dependence-alpha", type=float, default=0.05,
                    help="a class fails check 1b when the bias corrected "
                         "between program variance share is not above its own "
                         "label shuffled null at this level")
    ap.add_argument("--full-macro-f1", type=float, default=None,
                    help="headline macro F1 to use as the reference in the "
                         "headroom calculation. Defaults to a probe tree on the "
                         "full feature table, which understates a strong model "
                         "and therefore understates R")
    ap.add_argument("--full-macro-f1-protocol", default=None,
                    help="free text describing how the --full-macro-f1 value "
                         "was measured (protocol, model, seeds); recorded in "
                         "the JSON next to the gate's own probe protocol")
    ap.add_argument("--repeats", type=int, default=1,
                    help="repeat check 4 over split seeds seed..seed+N-1 and "
                         "report mean, min and max of the best single, best k "
                         "and R; the verdict still uses the first seed")
    ap.add_argument("--skip-single-feature", action="store_true",
                    help="skip check 4, which is the slowest")
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--report", default=None, help="write a JSON report here")
    args = ap.parse_args(argv)

    return run(
        features_path=args.features,
        label=args.label,
        group=args.group,
        min_distinct_ratio=args.min_distinct_ratio,
        max_constant_fraction=args.max_constant_fraction,
        max_affected_fraction=args.max_cross_group_fraction,
        max_single_feature_f1=args.max_single_feature_f1,
        permutation_tolerance=args.permutation_tolerance,
        seed=args.seed,
        report_path=args.report,
        skip_single_feature=args.skip_single_feature,
        max_cross_class_fraction=args.max_cross_class_fraction,
        min_headroom=args.min_headroom,
        min_input_dependence=args.min_input_dependence,
        input_dependence_alpha=args.input_dependence_alpha,
        full_macro_f1=args.full_macro_f1,
        full_macro_f1_protocol=args.full_macro_f1_protocol,
        repeats=args.repeats,
    )


if __name__ == "__main__":
    sys.exit(main())
