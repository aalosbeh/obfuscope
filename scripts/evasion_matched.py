"""Evasion rates compared at a matched class count.

Version 1 of this work reported a greedy evasion success rate on each of two
corpora and read the difference as a property of the corpora. The two label sets
had different widths, eleven classes against four, and that alone moves the
number. A greedy attacker only has to push an artifact across the nearest
decision boundary, and the more classes there are the closer the nearest
boundary tends to be, so a wide label set makes evasion look easy for a reason
that has nothing to do with how the corpus was built. The comparison was
confounded and the conclusion drawn from it was not supported.

This script removes the confound by subsampling the wider label set down to the
narrower one and repeating the draw. For every replicate it chooses k classes at
random from the wide corpus, refits, and reruns the same greedy search, so the
only remaining difference between the two corpora is the corpora themselves.
Results are reported as a distribution over replicates rather than a single
figure, because which k classes are drawn matters and a single draw would
reintroduce an arbitrary choice.

Two further corrections are applied to the search itself.

The step size in the original search was ten percent of each feature's corpus
wide standard deviation, with no limit on the total displacement. An attacker
allowed unlimited displacement will always succeed eventually, so an unbounded
search measures how long the optimiser runs rather than how robust the model is.
A budget is therefore imposed and swept: the total move is constrained in units
of standard deviations, measured as a Euclidean norm over the standardised
feature vector, and the success rate is reported at each budget. A robustness
claim is only meaningful against a stated budget.

The original search also allowed every feature to move. Many features cannot be
moved independently by someone editing source code, and several cannot be moved
at all without changing behaviour. The sweep is therefore repeated with the
attack restricted to features an attacker plausibly controls directly, which
gives a second and much more conservative bound. Neither bound establishes that
an attacker editing C source can realise the change; both are feature space
bounds, and that limit is stated here rather than left to a reader to infer.

Usage
    python3 scripts/evasion_matched.py \
        --wide data/features.csv --narrow data/features_pilot.csv \
        --replicates 10 --report results/evasion_matched.json
"""

from __future__ import annotations

import argparse
import json
import os
import sys
from typing import Dict, List, Optional, Sequence

import numpy as np
import pandas as pd

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "src"))

LABEL_COLS = ["path", "cohort", "sample_id", "technique", "sub_technique",
              "malware_family"]

# Features an attacker editing C source can move more or less directly, as
# opposed to ones that follow from the transformation or from compilation. This
# list is a judgement and is stated so it can be disputed; the unrestricted
# sweep is reported beside it so no conclusion rests on the judgement alone.
ATTACKER_CONTROLLED_PREFIXES = (
    "n_comment", "comment_", "identifier_", "n_blank", "indent_",
    "whitespace_", "n_lines", "size_bytes", "avg_line",
)


def shared_features(a: pd.DataFrame, b: pd.DataFrame) -> List[str]:
    """Numeric columns present in both corpora, so the attack space matches."""
    def numeric(df):
        return {c for c in df.columns
                if c not in LABEL_COLS and pd.api.types.is_numeric_dtype(df[c])}
    cols = sorted(numeric(a) & numeric(b))
    if not cols:
        raise ValueError("the two corpora share no numeric feature columns")
    return cols


def greedy_evade(
    X: np.ndarray,
    y: np.ndarray,
    groups: np.ndarray,
    feats: Sequence[str],
    seed: int,
    budgets: Sequence[float],
    n_trials: int,
    max_steps: int,
    restrict_to: Optional[Sequence[int]] = None,
) -> Dict:
    """Greedy coordinate ascent evasion with an explicit displacement budget.

    Displacement is measured in the standardised feature space, so a budget of
    one means the artifact has been moved by one standard deviation in total
    Euclidean distance. Success is recorded at the first step at which the
    prediction changes, and attributed to every budget at least as large as the
    displacement used, so one search populates the whole sweep.
    """
    from sklearn.ensemble import RandomForestClassifier
    from sklearn.model_selection import StratifiedGroupKFold

    sgkf = StratifiedGroupKFold(n_splits=5, shuffle=True, random_state=seed)
    tr, te = next(iter(sgkf.split(X, y, groups)))

    clf = RandomForestClassifier(n_estimators=400,
                                 class_weight="balanced_subsample",
                                 random_state=seed, n_jobs=-1)
    clf.fit(X[tr], y[tr])

    sd = X[tr].std(axis=0)
    sd[sd == 0] = 1.0
    step = 0.10 * sd

    movable = (np.arange(X.shape[1]) if restrict_to is None
               else np.asarray(sorted(restrict_to), dtype=int))
    if movable.size == 0:
        return {"skipped": "no movable features"}

    Xte, yte = X[te], y[te]
    correct = np.where(clf.predict(Xte) == yte)[0]
    if correct.size == 0:
        return {"skipped": "no correctly classified held out artifacts"}

    rng = np.random.default_rng(seed)
    sample = rng.choice(correct, size=min(n_trials, correct.size), replace=False)
    classes = list(clf.classes_)

    displacements: List[float] = []
    steps_used: List[int] = []
    for i in sample:
        x0 = Xte[i:i + 1].copy()
        x = x0.copy()
        true_idx = classes.index(yte[i])
        succeeded = False
        for s in range(max_steps):
            proba = clf.predict_proba(x)[0]
            if int(np.argmax(proba)) != true_idx:
                displacements.append(
                    float(np.linalg.norm((x - x0)[0] / sd)))
                steps_used.append(s)
                succeeded = True
                break
            batch = np.repeat(x, 2 * movable.size, axis=0)
            for k, j in enumerate(movable):
                batch[2 * k, j] = max(batch[2 * k, j] + step[j], 0.0)
                batch[2 * k + 1, j] = max(batch[2 * k + 1, j] - step[j], 0.0)
            scores = clf.predict_proba(batch)[:, true_idx]
            best = int(np.argmin(scores))
            if proba[true_idx] - scores[best] <= 0:
                break
            x = batch[best:best + 1]
        if not succeeded:
            displacements.append(float("inf"))
            steps_used.append(max_steps)

    disp = np.asarray(displacements, dtype=float)
    out = {
        "n_classes": int(len(classes)),
        "n_attacked": int(disp.size),
        "closed_accuracy_heldout": float((clf.predict(Xte) == yte).mean()),
        "unbounded_success_rate": round(float(np.isfinite(disp).mean()), 4),
        "median_displacement_when_successful": (
            round(float(np.median(disp[np.isfinite(disp)])), 4)
            if np.isfinite(disp).any() else None),
        "mean_steps_when_successful": (
            round(float(np.mean([s for s, d in zip(steps_used, disp)
                                 if np.isfinite(d)])), 2)
            if np.isfinite(disp).any() else None),
        "success_by_budget": {
            f"{b:g}": round(float((disp <= b).mean()), 4) for b in budgets
        },
        "n_movable_features": int(movable.size),
    }
    return out


def run(args) -> int:
    wide = pd.read_csv(args.wide)
    narrow = pd.read_csv(args.narrow)
    feats = shared_features(wide, narrow)
    budgets = [float(b) for b in args.budgets]

    movable_idx = [i for i, f in enumerate(feats)
                   if f.startswith(ATTACKER_CONTROLLED_PREFIXES)]

    print("Evasion comparison at a matched class count")
    print(f"  wide corpus    {args.wide}  rows {len(wide)}  "
          f"classes {wide['technique'].nunique()}")
    print(f"  narrow corpus  {args.narrow}  rows {len(narrow)}  "
          f"classes {narrow['technique'].nunique()}")
    print(f"  shared numeric features {len(feats)}")
    print(f"  attacker controlled subset {len(movable_idx)} "
          f"({', '.join(feats[i] for i in movable_idx) if movable_idx else 'none'})")
    print(f"  displacement budgets, in standard deviations: {budgets}")
    print()
    print("  Displacement is the Euclidean norm of the change in standardised")
    print("  feature space. An unbounded search always succeeds given enough")
    print("  steps, so the budgeted rates are the ones that carry a claim.")
    print()

    k = int(narrow["technique"].nunique())
    report: Dict = {"wide": args.wide, "narrow": args.narrow,
                    "n_shared_features": len(feats),
                    "matched_class_count": k,
                    "budgets": budgets,
                    "attacker_controlled_features":
                        [feats[i] for i in movable_idx]}

    def prep(df: pd.DataFrame, keep: Optional[Sequence[str]] = None):
        d = df if keep is None else df[df["technique"].isin(keep)]
        X = np.nan_to_num(d[feats].to_numpy(dtype=float),
                          nan=0.0, posinf=0.0, neginf=0.0)
        return X, d["technique"].to_numpy(), d["sample_id"].to_numpy()

    for restricted, tag in ((None, "all features movable"),
                            (movable_idx, "attacker controlled features only")):
        if restricted is not None and not restricted:
            print(f"  {tag}: skipped, no shared feature matched the subset")
            print()
            continue
        print(f"=== {tag} ===")
        print()

        Xn, yn, gn = prep(narrow)
        narrow_res = greedy_evade(Xn, yn, gn, feats, args.seed, budgets,
                                  args.n_trials, args.max_steps, restricted)
        print(f"  narrow corpus, {k} classes, as built")
        _show(narrow_res, budgets)

        wide_classes = sorted(wide["technique"].unique())
        reps = []
        rng = np.random.default_rng(args.seed)
        print(f"  wide corpus subsampled to {k} classes, "
              f"{args.replicates} replicates")
        for r in range(args.replicates):
            keep = list(rng.choice(wide_classes, size=k, replace=False))
            Xw, yw, gw = prep(wide, keep)
            res = greedy_evade(Xw, yw, gw, feats, args.seed + r, budgets,
                               args.n_trials, args.max_steps, restricted)
            if "skipped" in res:
                continue
            res["classes"] = [str(c) for c in keep]
            reps.append(res)

        if reps:
            print(f"    pooled over {len(reps)} replicates")
            print(f"      unbounded success rate   "
                  f"{np.mean([x['unbounded_success_rate'] for x in reps]):.4f}"
                  f" +/- {np.std([x['unbounded_success_rate'] for x in reps], ddof=1):.4f}")
            for b in budgets:
                vals = [x["success_by_budget"][f"{b:g}"] for x in reps]
                print(f"      budget {b:>5g} sd           "
                      f"{np.mean(vals):.4f} +/- {np.std(vals, ddof=1):.4f}")
            print(f"      held out closed accuracy "
                  f"{np.mean([x['closed_accuracy_heldout'] for x in reps]):.4f}")
            print()

            # The comparison the version 1 text attempted, now at matched width.
            for b in budgets:
                nv = narrow_res["success_by_budget"][f"{b:g}"]
                wv = np.mean([x["success_by_budget"][f"{b:g}"] for x in reps])
                wsd = np.std([x["success_by_budget"][f"{b:g}"] for x in reps], ddof=1)
                verdict = ("narrow easier" if nv > wv + wsd else
                           "wide easier" if wv > nv + wsd else
                           "not separated")
                print(f"    budget {b:>5g}: narrow {nv:.4f} against wide "
                      f"{wv:.4f} +/- {wsd:.4f}  -> {verdict}")
            print()

        report[f"{'unrestricted' if restricted is None else 'restricted'}"] = {
            "narrow": narrow_res,
            "wide_matched_replicates": reps,
        }

    if args.report:
        os.makedirs(os.path.dirname(args.report) or ".", exist_ok=True)
        with open(args.report, "w") as fh:
            json.dump(report, fh, indent=2)
        print(f"report written to {args.report}")
    return 0


def _show(res: Dict, budgets: Sequence[float]) -> None:
    if "skipped" in res:
        print(f"    skipped: {res['skipped']}")
        print()
        return
    print(f"    classes {res['n_classes']}  attacked {res['n_attacked']}  "
          f"movable features {res['n_movable_features']}")
    print(f"    held out closed accuracy   {res['closed_accuracy_heldout']:.4f}")
    print(f"    unbounded success rate     {res['unbounded_success_rate']:.4f}")
    print(f"    median displacement        "
          f"{res['median_displacement_when_successful']}")
    for b in budgets:
        print(f"    budget {b:>5g} sd             "
              f"{res['success_by_budget'][f'{b:g}']:.4f}")
    print()


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(
        description="Compare greedy evasion rates between two corpora at a "
                    "matched class count and under an explicit displacement "
                    "budget.")
    ap.add_argument("--wide", default="data/features.csv")
    ap.add_argument("--narrow", default="data/features_pilot.csv")
    ap.add_argument("--replicates", type=int, default=10)
    ap.add_argument("--budgets", nargs="+", default=[0.5, 1.0, 2.0, 5.0])
    ap.add_argument("--n-trials", type=int, default=150)
    ap.add_argument("--max-steps", type=int, default=30)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--report", default=None)
    args = ap.parse_args(argv)
    return run(args)


if __name__ == "__main__":
    raise SystemExit(main())
