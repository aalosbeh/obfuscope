#!/usr/bin/env python3
"""Number ledger for the revised ObfuScope manuscript (ACM TOPS).

AUDIT-GENERATED (label build:ledger-tables). Every number that the revised
article, its supplement or its tables print is collected here, once, from the
result files of this repository, so that prose and tables copy a single
``display`` string instead of retyping numbers.

Inputs (read only)
------------------
* committed results: results/*.json (gate_v2_*, gate_original_technique,
  gate_specificity, closed_set_five_seed*.json, sibling_position.json,
  inversion_sim.json, dead_features.json, feature_set_live_counts.json,
  semantics_*.json, openset_v2_*.json, evasion_matched.json) and the committed
  per-cell closed-set grids results/pilot5/ and results/pilot5sub/ (used only
  for the fold-level paired feature-set ablation, which no result file holds);
* revision results: results/v3/** (open set, sibling axis, summaries, gate,
  closed set, simulation, semantics, checksums);
* results/v3/openset_mechanism/nn_mechanism.json and
  results/v3/evasion/evasion_diagnostics.json: copies of two AUDIT-GENERATED
  analyses made outside the repository (copied here by this script when the
  copy is missing; the copy is what is read);
* data/features_pilot.csv, data/features.csv (row and class counts) and
  corpus_inputs/ (line counts of the 30 input programs);
* a few code constants that no result file records (ECE bins, Isolation
  Forest size, GroupShuffleSplit test size, the Tigress catalogue size); each
  such entry names the source file in ``source`` and says so in ``note``.

Outputs
-------
_work/ledger/ledger.json  {key: {value, display, source, path, note}}
_work/ledger/ledger.txt   one line per key: key = display  [source: file::path]
_work/ledger/ledger.csv   key, value, display, source, path, note

Display conventions
-------------------
``display`` is the exact LaTeX string to print. AUROC, AUPR, F1, accuracy,
ECE, OSCR, FPR, TPR, R, omega squared, simulation values and differences of
these: 4 decimals. Counts: integers. Percentages: as stated per key, with
``\\%``. Negative numbers are wrapped in math mode (``$-0.4591$``) so that the
minus sign is typeset correctly. p values: 4 decimals (``$<0.0001$`` below).
Keys ending in ``_2dp`` are 2-decimal roundings of the key without the suffix,
for the few sentences that the revision plan words with two decimals.

Standard deviations are sample standard deviations (ddof = 1) over folds
unless the key or note says otherwise (``sd_fold``/``sd_seed`` of the closed
set grids follow scripts/aggregate_seeds.py: the mean of the within-seed fold
sds, and the sd of the per-seed means).

Derived quantities computed here (not stored in any result file) say so in
``note`` (LEDGER-COMPUTED): the class-level crossed bootstrap intervals for
configuration B, the minima/maxima over estimators, C minus B orientation of
the B minus C contrast, the paired feature-set ablation, and a few differences.

Usage:
    python scripts/manuscript_v3/make_ledger.py
"""
from __future__ import annotations

import csv
import glob
import hashlib
import itertools
import json
import math
import os
import re
import shutil
import sys
from typing import Dict, List, Optional

import numpy as np
from scipy import stats as sstats

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", ".."))
RES = os.path.join(REPO, "results")
V3 = os.path.join(RES, "v3")
WORK = os.environ.get(
    "OBFUSCOPE_WORK", os.path.abspath(os.path.join(REPO, "..", "..", "_work")))
OUT = os.path.join(WORK, "ledger")
SCRATCH = os.environ.get(
    "OBFUSCOPE_AUDIT_SCRATCH",
    os.path.join(REPO, "..", "audit_scratch"))
COPIES = [
    (os.path.join(SCRATCH, "audit", "experiment_program-overlap-control", "nn_mechanism.json"),
     os.path.join(V3, "openset_mechanism", "nn_mechanism.json")),
    (os.path.join(SCRATCH, "audit2", "code_analyses+evasion", "out", "evasion_diagnostics.json"),
     os.path.join(V3, "evasion", "evasion_diagnostics.json")),
]

sys.path.insert(0, os.path.join(REPO, "scripts"))
sys.path.insert(0, os.path.join(REPO, "src"))

MODELS_OS = ["random_forest", "extra_trees", "logreg", "svm_rbf", "knn", "mlp"]
MODELS_CS = ["hist_gbdt", "random_forest", "extra_trees", "svm_rbf", "logreg", "mlp", "knn"]
SCORERS = ["msp", "energy", "knn_dist", "mahalanobis", "iforest", "openmax", "evt_posterior"]
MODEL_FREE = ["knn_dist", "mahalanobis", "iforest"]
LOGIT_MODELS = ["logreg", "mlp", "svm_rbf"]
VARIANTS = {"heldout": "matched", "all": "overlap", "kfold": "kfold"}
CONFIGS = ["A", "B", "C"]
PARAMS = ["ref_opq_junk", "ref_opq_both", "ref_opq_true", "ref_lit_xor", "ref_lit_mixed",
          "ref_lit_sum", "ref_str_add", "ref_str_xor", "ref_ren_hex", "ref_ren_long"]
FAMILIES = ["addopaque", "encodeliterals", "encodestrings", "renameidentifiers"]
SPREADS = [0.25, 0.5, 1.0, 2.0, 4.0, 8.0]

BOOT_R = 10000
BOOT_SEED = 20261009  # the seed of results/v3/summarise_openset.py


# --------------------------------------------------------------------------- #
# formatting

def _neg(s: str, x: float) -> str:
    if x < 0 and float(s) != 0.0:
        return f"$-{s}$"
    return s


def f4(x) -> str:
    if x is None:
        return "n/a"
    x = float(x)
    if not math.isfinite(x):
        return "n/a"
    return _neg(f"{abs(x):.4f}", x)


def fnd(x, nd: int) -> str:
    x = float(x)
    return _neg(f"{abs(x):.{nd}f}", x)


def pct(x, nd: int = 1) -> str:
    return fnd(100.0 * float(x), nd) + r"\%"


def cnt(x) -> str:
    return str(int(round(float(x))))


def pval(x) -> str:
    x = float(x)
    if x < 0.0001:
        return "$<0.0001$"
    return f"{x:.4f}"


def sspread(s: float) -> str:
    return "s" + (f"{s:g}".replace(".", "_"))


def tex_escape(s: str) -> str:
    return s.replace("_", r"\_")


# --------------------------------------------------------------------------- #

def _plain(v):
    """Convert numpy scalars (also inside lists) to plain Python values."""
    if isinstance(v, np.bool_):
        return bool(v)
    if isinstance(v, np.integer):
        return int(v)
    if isinstance(v, np.floating):
        return float(v)
    if isinstance(v, (list, tuple)):
        return [_plain(x) for x in v]
    return v


class Ledger:
    def __init__(self) -> None:
        self.d: Dict[str, Dict] = {}
        self.warnings: List[str] = []

    def add(self, key: str, value, display: str, source: str, path: str = "",
            note: str = "") -> None:
        if key in self.d:
            raise KeyError(f"duplicate ledger key {key}")
        value = _plain(value)
        self.d[key] = {"value": value, "display": display, "source": source,
                       "path": path, "note": note}

    def num(self, key, value, source, path="", note="", nd=4, two=False):
        disp = f4(value) if nd == 4 else fnd(value, nd)
        self.add(key, value, disp, source, path, note)
        if two:
            self.add(key + "_2dp", value, fnd(value, 2), source, path,
                     (note + "; " if note else "") + "2-decimal rounding")

    def count(self, key, value, source, path="", note=""):
        self.add(key, int(value), cnt(value), source, path, note)

    def text(self, key, value, source, path="", note="", display=None):
        self.add(key, value, display if display is not None else tex_escape(str(value)),
                 source, path, note)

    def warn(self, msg: str) -> None:
        self.warnings.append(msg)


def rel(p: str) -> str:
    return os.path.relpath(p, REPO)


def load(p: str):
    with open(p) as fh:
        return json.load(fh)


def read_csv(p: str) -> List[Dict]:
    with open(p, newline="") as fh:
        return list(csv.DictReader(fh))


def sha256(p: str) -> str:
    h = hashlib.sha256()
    with open(p, "rb") as fh:
        for chunk in iter(lambda: fh.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def holm(ps):
    ps = np.asarray(ps, dtype=float)
    order = np.argsort(ps)
    m = len(ps)
    adj = np.empty(m)
    running = 0.0
    for rank, i in enumerate(order):
        running = max(running, min(1.0, (m - rank) * ps[i]))
        adj[i] = running
    return adj


# --------------------------------------------------------------------------- #
# 0. copies of the two external AUDIT-GENERATED analyses

def ensure_copies(L: Ledger) -> None:
    for src, dst in COPIES:
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        if not os.path.exists(dst):
            if os.path.exists(src):
                shutil.copy2(src, dst)
            else:
                L.warn(f"external file missing and no copy present: {src}")
                continue
        if os.path.exists(src) and sha256(src) != sha256(dst):
            L.warn(f"copy differs from its external source: {dst}")
        L.text(f"provenance.copy.{os.path.basename(dst).replace('.json', '')}.sha256",
               sha256(dst), rel(dst), "", "sha256 of the in-repository copy",
               display=r"\texttt{" + sha256(dst) + "}")


# --------------------------------------------------------------------------- #
# 1. environment, corpus, features

def environment(L: Ledger) -> None:
    p = os.path.join(V3, "sim", "checksums_sim_v3.txt")
    txt = open(p).read()
    m = re.search(r"python (\S+) numpy (\S+) scipy (\S+) scikit-learn (\S+) pandas (\S+)", txt)
    if not m:
        raise RuntimeError("environment line not found in checksums_sim_v3.txt")
    for k, v in zip(["python", "numpy", "scipy", "sklearn", "pandas"], m.groups()):
        L.text(f"env.{k}", v, rel(p), "header line '# python ... pandas ...'")
    hp = load(os.path.join(V3, "closed", "hyperparameters.json"))
    if hp["sklearn_version"] != L.d["env.sklearn"]["value"] or \
            hp["numpy_version"] != L.d["env.numpy"]["value"]:
        L.warn("environment versions differ between sim checksums and hyperparameters.json")


def corpus(L: Ledger) -> None:
    import pandas as pd
    p = os.path.join(REPO, "data", "features_pilot.csv")
    df = pd.read_csv(p)
    src = rel(p)
    L.count("corpus.n_artifacts", len(df), src, "rows")
    L.count("corpus.n_programs", df["sample_id"].nunique(), src, "unique sample_id")
    L.count("corpus.n_suites", df["malware_family"].nunique(), src,
            "unique malware_family (= input suite)")
    L.count("corpus.n_families", df["technique"].nunique(), src, "unique technique")
    L.count("corpus.n_params", df["sub_technique"].nunique(), src, "unique sub_technique")
    meta_cols = {"path", "cohort", "sample_id", "technique", "sub_technique", "malware_family"}
    L.count("corpus.n_feature_columns", len([c for c in df.columns if c not in meta_cols]), src,
            "columns other than path, cohort, sample_id, technique, sub_technique, malware_family")
    for fam, n in df["technique"].value_counts().sort_index().items():
        L.count(f"corpus.family.{fam}.n", n, src, f"technique == {fam}")
        L.count(f"corpus.family.{fam}.n_params", df.loc[df.technique == fam, "sub_technique"].nunique(),
                src, f"sub_technique values within technique {fam}")
    for par, n in df["sub_technique"].value_counts().sort_index().items():
        L.count(f"corpus.param.{par}.n", n, src, f"sub_technique == {par}")
    reps = len(df) / (df["sample_id"].nunique() * df["sub_technique"].nunique())
    L.count("corpus.replicates", reps, src,
            note="rows / (programs x parameterisations); LEDGER-COMPUTED")
    cells = df.groupby(["sample_id", "sub_technique"]).size()
    if cells.nunique() != 1:
        L.warn("replicate count is not constant over program x parameterisation cells")
    for s, n in df.groupby("malware_family")["sample_id"].nunique().items():
        L.count(f"corpus.suite.{s}.n_programs", n, src, f"programs in suite {s}")

    p1 = os.path.join(REPO, "data", "features.csv")
    v1 = pd.read_csv(p1)
    L.count("corpus.v1.n_artifacts", len(v1), rel(p1), "rows",
            "template-generated corpus from an earlier pipeline (negative control)")
    L.count("corpus.v1.n_classes", v1["technique"].nunique(), rel(p1), "unique technique")
    L.count("corpus.v1.n_groups", v1["sample_id"].nunique(), rel(p1), "unique sample_id")

    # input programs: line counts (wc -l semantics: newline characters)
    tsv = os.path.join(REPO, "corpus_inputs", "programs.tsv")
    progs = []
    for line in open(tsv):
        if line.startswith("#") or not line.strip():
            continue
        rp, suite = line.rstrip("\n").split("\t")[:2]
        with open(os.path.join(REPO, "corpus_inputs", rp), "rb") as fh:
            nl = fh.read().count(b"\n")
        progs.append((rp, suite, nl))
    lines = np.array([p[2] for p in progs])
    srcp = "corpus_inputs/" + "{programs.tsv,*/*.c}"
    L.count("corpus.lines.n_programs", len(progs), srcp, "programs listed in programs.tsv")
    L.count("corpus.lines.min", lines.min(), srcp, "min newline count (wc -l)")
    L.count("corpus.lines.max", lines.max(), srcp, "max newline count (wc -l)")
    L.count("corpus.lines.total", lines.sum(), srcp, "sum of newline counts (wc -l)")
    L.num("corpus.lines.mean", float(lines.mean()), srcp, "mean newline count", nd=1)
    L.num("corpus.lines.median", float(np.median(lines)), srcp, "median newline count", nd=1)
    L.text("corpus.lines.min_program", [p[0] for p in progs if p[2] == lines.min()][0], srcp)
    L.text("corpus.lines.max_program", [p[0] for p in progs if p[2] == lines.max()][0], srcp)
    for rp, suite, nl in progs:
        name = rp.replace("/", "_").replace(".c", "")
        L.count(f"corpus.lines.program.{name}", nl, srcp, f"wc -l of corpus_inputs/{rp}")
    for suite in sorted({p[1] for p in progs}):
        sl = [p[2] for p in progs if p[1] == suite]
        L.count(f"corpus.lines.suite.{suite}.min", min(sl), srcp)
        L.count(f"corpus.lines.suite.{suite}.max", max(sl), srcp)
        L.count(f"corpus.lines.suite.{suite}.total", sum(sl), srcp)

    # checksums
    p = os.path.join(V3, "checksums.txt")
    for line in open(p):
        m = re.match(r"([0-9a-f]{64})\s+(\S+)", line)
        if m:
            name = os.path.basename(m.group(2)).replace(".csv", "")
            L.text(f"checksum.{name}", m.group(1), rel(p), m.group(2),
                   display=r"\texttt{" + m.group(1) + "}")
            actual = sha256(os.path.join(REPO, m.group(2)))
            if actual != m.group(1):
                L.warn(f"checksum mismatch for {m.group(2)}")

    # Tigress catalogue (specified, not run): counts from the specification file
    import tigress_spec as ts  # scripts/ is on sys.path; pure data module
    n_fam = len(ts.CATALOGUE)
    n_par = sum(len(t.params) for t in ts.CATALOGUE)
    L.count("tigress.n_families", n_fam, "scripts/tigress_spec.py", "len(CATALOGUE)",
            "code constant: the Tigress cohort is specified, not run")
    L.count("tigress.n_params", n_par, "scripts/tigress_spec.py", "sum of len(params)",
            "code constant: the Tigress cohort is specified, not run")
    L.count("tigress.n_artifacts", n_par * L.d["corpus.n_programs"]["value"] * L.d["corpus.replicates"]["value"],
            "scripts/tigress_spec.py + data/features_pilot.csv",
            "parameterisations x programs x replicates",
            "LEDGER-COMPUTED: 21 x 30 x 8 under the replicate count of the measured corpus")


def features(L: Ledger) -> None:
    p = os.path.join(RES, "dead_features.json")
    d = load(p)
    src = rel(p)
    L.count("features.declared", d["n_features"], src, "n_features")
    L.count("features.dead", len(d["dead"]), src, "len(dead)")
    live_total = sum(len(v) for v in d["live_by_family"].values())
    L.count("features.live", live_total, src, "sum len(live_by_family[*])")
    fams = ["lexical", "entropy", "control_flow", "literal", "operator", "api", "obfuscation"]
    for f in fams:
        live = d["live_by_family"].get(f, [])
        dead = d["dead_by_family"].get(f, [])
        L.count(f"features.family.{f}.declared", len(live) + len(dead), src,
                f"len(live_by_family.{f}) + len(dead_by_family.{f})")
        L.count(f"features.family.{f}.live", len(live), src, f"len(live_by_family.{f})")
        L.count(f"features.family.{f}.dead", len(dead), src, f"len(dead_by_family.{f})")
        L.text(f"features.family.{f}.dead_names", dead, src, f"dead_by_family.{f}",
               display=", ".join(r"\code{" + tex_escape(x) + "}" for x in dead) or "none")
        L.text(f"features.family.{f}.live_names", live, src, f"live_by_family.{f}",
               display=", ".join(r"\code{" + tex_escape(x) + "}" for x in live) or "none")
    p2 = os.path.join(RES, "feature_set_live_counts.json")
    fs = load(p2)
    for name, v in fs.items():
        L.count(f"fs.{name}.declared", v["declared"], rel(p2), f"{name}.declared")
        L.count(f"fs.{name}.live", v["live"], rel(p2), f"{name}.live")


# --------------------------------------------------------------------------- #
# 2. gate

def classify_failure(msg: str) -> str:
    if "distinct vectors in" in msg:
        return "1"
    if "between program share" in msg:
        return "1b"
    if "features have zero variance" in msg:
        return "2"
    if "span more than one" in msg:
        return "3"
    if "single feature" in msg or "headroom" in msg or "features together reach" in msg:
        return "4"
    if "permut" in msg and "chance" in msg:
        return "5"
    if "carry more than one" in msg:
        return "6"
    return "other"


def gate_report(L: Ledger, prefix: str, rep: Dict, src: str, with_supplied: bool) -> None:
    pc = rep["per_class"]
    L.count(f"{prefix}.n_classes", len(pc), src, "len(per_class)")
    for r in pc:
        cb = f"{prefix}.class.{r['class']}"
        sel = f"per_class[class={r['class']}]"
        L.count(f"{cb}.n", r["n"], src, f"{sel}.n")
        L.count(f"{cb}.distinct", r["distinct_vectors"], src, f"{sel}.distinct_vectors")
        L.num(f"{cb}.distinct_ratio", r["distinct_ratio"], src, f"{sel}.distinct_ratio")
        L.count(f"{cb}.constant", r["constant_features"], src, f"{sel}.constant_features")
        L.num(f"{cb}.constant_fraction", r["constant_fraction"], src, f"{sel}.constant_fraction")
        L.num(f"{cb}.omega2", r["dependence_omega2"], src, f"{sel}.dependence_omega2")
        L.num(f"{cb}.p", r["dependence_p"], src, f"{sel}.dependence_p")
        L.count(f"{cb}.n_groups", r["n_groups"], src, f"{sel}.n_groups")
    dr = [r["distinct_ratio"] for r in pc]
    L.num(f"{prefix}.distinct_ratio.min", min(dr), src, "min per_class[*].distinct_ratio")
    L.num(f"{prefix}.distinct_ratio.max", max(dr), src, "max per_class[*].distinct_ratio")
    om = [r["dependence_omega2"] for r in pc]
    L.num(f"{prefix}.omega2.min", min(om), src, "min per_class[*].dependence_omega2")
    L.num(f"{prefix}.omega2.max", max(om), src, "max per_class[*].dependence_omega2")
    pv = [r["dependence_p"] for r in pc]
    L.num(f"{prefix}.dependence_p.max", max(pv), src, "max per_class[*].dependence_p")
    L.num(f"{prefix}.dependence_p.min", min(pv), src, "min per_class[*].dependence_p")
    cf = [r["constant_fraction"] for r in pc]
    L.num(f"{prefix}.constant_fraction.max", max(cf), src, "max per_class[*].constant_fraction")
    L.num(f"{prefix}.constant_fraction.min", min(cf), src, "min per_class[*].constant_fraction")
    st = rep["gate_settings"] if "gate_settings" in rep else None
    thr_d = st["min_distinct_ratio"] if st else 0.8
    thr_c = st["max_constant_fraction"] if st else 0.5
    alpha = st["input_dependence_alpha"] if st else 0.05
    L.count(f"{prefix}.n_classes_fail_distinct", sum(x < thr_d for x in dr), src,
            "per_class with distinct_ratio < min_distinct_ratio")
    L.count(f"{prefix}.n_classes_fail_constant", sum(x > thr_c for x in cf), src,
            "per_class with constant_fraction > max_constant_fraction")
    L.count(f"{prefix}.n_classes_fail_dependence", sum(x > alpha for x in pv), src,
            "per_class with dependence_p > input_dependence_alpha")
    L.count(f"{prefix}.n_classes_single_vector", sum(r["distinct_vectors"] == 1 for r in pc), src,
            "per_class with distinct_vectors == 1")
    cg = rep["cross_group_duplicates"]
    L.count(f"{prefix}.diag3.clusters", cg["duplicate_clusters_spanning_groups"], src,
            "cross_group_duplicates.duplicate_clusters_spanning_groups")
    L.count(f"{prefix}.diag3.rows", cg["rows_in_those_clusters"], src,
            "cross_group_duplicates.rows_in_those_clusters")
    L.count(f"{prefix}.diag3.total_rows", cg["total_rows"], src, "cross_group_duplicates.total_rows")
    L.num(f"{prefix}.diag3.fraction", cg["fraction_of_corpus"], src,
          "cross_group_duplicates.fraction_of_corpus")
    L.add(f"{prefix}.diag3.fraction_pct", cg["fraction_of_corpus"], pct(cg["fraction_of_corpus"], 2),
          src, "cross_group_duplicates.fraction_of_corpus", "percentage, 2 decimals")
    L.count(f"{prefix}.distinct_vectors_overall", cg["distinct_vectors_overall"], src,
            "cross_group_duplicates.distinct_vectors_overall")
    cc = rep["cross_class_duplicates"]
    L.count(f"{prefix}.diag6.clusters", cc["duplicate_clusters_spanning_labels"], src,
            "cross_class_duplicates.duplicate_clusters_spanning_labels")
    L.count(f"{prefix}.diag6.rows", cc["rows_in_those_clusters"], src,
            "cross_class_duplicates.rows_in_those_clusters")
    L.num(f"{prefix}.diag6.fraction", cc["fraction_of_corpus"], src, "cross_class_duplicates.fraction_of_corpus")
    L.add(f"{prefix}.diag6.fraction_pct", cc["fraction_of_corpus"], pct(cc["fraction_of_corpus"], 2),
          src, "cross_class_duplicates.fraction_of_corpus", "percentage, 2 decimals")
    L.count(f"{prefix}.diag6.forced_errors", cc["irreducible_errors"], src,
            "cross_class_duplicates.irreducible_errors")
    L.num(f"{prefix}.diag6.ceiling", cc["accuracy_ceiling"], src, "cross_class_duplicates.accuracy_ceiling")
    sf = rep["single_feature"]
    L.num(f"{prefix}.chance", sf["chance_macro_f1"], src, "single_feature.chance_macro_f1")
    L.text(f"{prefix}.best_feature", sf["best_feature"], src, "single_feature.best_feature",
           display=r"\code{" + tex_escape(sf["best_feature"]) + "}")
    for k in ("1", "2", "3"):
        L.num(f"{prefix}.best{k}", sf["macro_f1_by_k"][k], src, f"single_feature.macro_f1_by_k.{k}")
        feats = [t["features"] for t in sf["greedy_trace"] if str(t["k"]) == k][0]
        L.text(f"{prefix}.best{k}_features", feats, src, f"single_feature.greedy_trace[k={k}].features",
               display=", ".join(r"\code{" + tex_escape(x) + "}" for x in feats))
    L.num(f"{prefix}.depth3_full", sf["full_set_shallow_depth3"], src, "single_feature.full_set_shallow_depth3")
    for i, t in enumerate(sf["top_five"]):
        L.text(f"{prefix}.top{i + 1}.feature", t["feature"], src, f"single_feature.top_five[{i}].feature",
               display=r"\code{" + tex_escape(t["feature"]) + "}")
        L.num(f"{prefix}.top{i + 1}.f1", t["macro_f1"], src, f"single_feature.top_five[{i}].macro_f1")
    if "full_set_probe_macro_f1" in sf:
        L.num(f"{prefix}.probe_full", sf["full_set_probe_macro_f1"], src, "single_feature.full_set_probe_macro_f1")
        L.num(f"{prefix}.R_self", sf["headroom_R_probe_reference"], src,
              "single_feature.headroom_R_probe_reference",
              "R with the gate's own probe tree on all features as the reference (self-contained)")
    if with_supplied:
        L.num(f"{prefix}.F1_supplied", sf["full_set_macro_f1"], src, "single_feature.full_set_macro_f1",
              "reference F1 supplied with --full-macro-f1 (headline model, different protocol)")
        L.num(f"{prefix}.R_supplied", sf["headroom_R"], src, "single_feature.headroom_R")
    if "headroom_status" in sf:
        L.text(f"{prefix}.headroom_status", sf["headroom_status"], src, "single_feature.headroom_status")
    pl = rep["permuted_labels"]
    L.num(f"{prefix}.diag5.real", pl["real_macro_f1"], src, "permuted_labels.real_macro_f1")
    L.num(f"{prefix}.diag5.permuted", pl["permuted_macro_f1"], src, "permuted_labels.permuted_macro_f1")
    L.num(f"{prefix}.diag5.excess", pl["excess_over_chance"], src, "permuted_labels.excess_over_chance")
    fails = rep["failures"]
    L.count(f"{prefix}.n_failures", len(fails), src, "len(failures)")
    by = {}
    for m in fails:
        c = classify_failure(m)
        by[c] = by.get(c, 0) + 1
    if "other" in by:
        L.warn(f"{prefix}: unclassified failure messages: {by['other']}")
    for c in ["1", "1b", "2", "3", "4", "5", "6"]:
        L.count(f"{prefix}.failures.diag{c}", by.get(c, 0), src,
                "failures[*] classified by message text", "LEDGER-COMPUTED classification")
    L.text(f"{prefix}.passed", bool(rep["passed"]), src, "passed",
           display="pass" if rep["passed"] else "fail")


def code_constants(L: Ledger) -> None:
    """Constants of the generator and the gate that no result file records."""
    p = os.path.join(REPO, "scripts", "reference_backend.py")
    code = open(p).read()
    note = "code constant read from the source file"
    checks = [
        ("backend.lit.max_value", r"if val > (0x[0-9A-Fa-f]+):", "int16", "EncodeLiterals leaves literals above this value unchanged"),
        ("backend.lit.xor_mask_hi", r"mask = rng\.randrange\(1, (0x[0-9A-Fa-f]+)\)", "int16", "XOR mask drawn from [1, value-1]"),
        ("backend.lit.sum_offset_hi", r"off = rng\.randrange\(1, (\d+)\)", "int", "offset drawn from [1, value-1]"),
        ("backend.str.key_hi", r"key = rng\.randrange\(1, (\d+)\)", "int", "string key drawn from [1, value-1]"),
        ("backend.str.max_len", r"len\(body\) > (\d+)", "int", "string literals longer than this many bytes are left unchanged"),
        ("backend.opq.share", r"round\(len\(candidates\) \* ([0-9.]+)\)", "float", "share of eligible statement boundaries that receive an opaque construct"),
        ("backend.opq.min_sites", r"take_n = max\((\d+),", "int", "minimum number of insertion sites"),
        ("backend.ren.min_len", r"len\(n\) < (\d+)", "int", "identifiers shorter than this are not renamed"),
        ("backend.ren.long_min", r"rng\.randint\((\d+), \d+\)\)\)", "int", "ref_ren_long name length lower bound"),
        ("backend.ren.long_max", r"rng\.randint\(\d+, (\d+)\)\)\)", "int", "ref_ren_long name length upper bound"),
        ("backend.ren.hex_lo", r"f\"v_\{rng\.randrange\((0x[0-9A-Fa-f]+), 0x[0-9A-Fa-f]+\):x\}", "int16", "ref_ren_hex suffix lower bound"),
        ("backend.ren.hex_hi", r"f\"v_\{rng\.randrange\(0x[0-9A-Fa-f]+, (0x[0-9A-Fa-f]+)\):x\}", "int16", "ref_ren_hex suffix upper bound (exclusive)"),
    ]
    for key, rx, kind, desc in checks:
        m = re.search(rx, code)
        if not m:
            L.warn(f"code constant {key} not found in {rel(p)}")
            continue
        raw = m.group(1)
        if kind == "int16":
            v = int(raw, 16)
            L.add(key, v, str(v), rel(p), rx, f"{note}; {desc}; source literal {raw}")
        elif kind == "float":
            v = float(raw)
            L.add(key, v, raw, rel(p), rx, f"{note}; {desc}")
            L.add(key + "_pct", v, f"{100 * v:.0f}" + r"\%", rel(p), rx, f"{note}; {desc}; percentage")
        else:
            v = int(raw)
            L.add(key, v, str(v), rel(p), rx, f"{note}; {desc}")
    hl = L.d.get("backend.ren.hex_lo", {}).get("value")
    hh = L.d.get("backend.ren.hex_hi", {}).get("value")
    if hl is not None and hh is not None:
        nd = len(f"{hl:x}")
        if nd == len(f"{hh - 1:x}"):
            L.add("backend.ren.hex_digits", nd, str(nd), rel(p), "len(hex(lo)) == len(hex(hi-1))",
                  "LEDGER-COMPUTED: number of hexadecimal digits after v_")
    p = os.path.join(REPO, "scripts", "diversity_gate.py")
    code = open(p).read()
    for key, rx in [("gate.const.probe_depth_cap", r"PROBE_MAX_DEPTH_CAP = (\d+)"),
                    ("gate.const.pool_size", r"GREEDY_POOL_SIZE = (\d+)"),
                    ("gate.const.probe_splits", r"PROBE_N_SPLITS = (\d+)"),
                    ("gate.const.permutations", r"INPUT_DEPENDENCE_PERMUTATIONS = (\d+)"),
                    ("gate.const.round_decimals", r"VECTOR_ROUND_DECIMALS = (\d+)")]:
        m = re.search(rx, code)
        L.count(key, int(m.group(1)), rel(p), rx, note)
    m = re.search(r"PROBE_TEST_SIZE = ([0-9.]+)", code)
    L.num("gate.const.probe_test_size", float(m.group(1)), rel(p), "PROBE_TEST_SIZE", note, nd=1)
    seg = code[code.index("def check_permuted_labels"):]
    m = re.search(r"RandomForestClassifier\(n_estimators=(\d+)", seg)
    L.count("gate.const.diag5_trees", int(m.group(1)), rel(p), "check_permuted_labels: RandomForestClassifier(n_estimators)", note)
    p = os.path.join(REPO, "scripts", "build_corpus_tigress.py")
    code = open(p).read()
    m = re.search(r"hexdigest\(\)\[:(\d+)\]", code)
    L.count("corpus.seed_hex_digits", int(m.group(1)), rel(p), "hashlib.sha256(key).hexdigest()[:n]",
            note + "; per-artifact seed = first n hex digits of sha256(sample_id|transform|param|replicate)")


def gate(L: Ledger) -> None:
    G = os.path.join(V3, "gate")
    # settings (identical in every v3 gate report)
    p = os.path.join(G, "gate_supplied_technique.json")
    st = load(p)["gate_settings"]
    for k in ["min_distinct_ratio", "max_constant_fraction", "max_cross_group_fraction",
              "max_single_feature_f1", "permutation_tolerance", "max_cross_class_fraction",
              "min_headroom", "min_input_dependence", "input_dependence_alpha"]:
        L.num(f"gate.settings.{k}", st[k], rel(p), f"gate_settings.{k}",
              nd=3 if k == "max_cross_class_fraction" else 2)
    L.count("gate.settings.permutations", st["input_dependence_permutations"], rel(p),
            "gate_settings.input_dependence_permutations")
    L.count("gate.settings.round_decimals", st["vector_round_decimals"], rel(p),
            "gate_settings.vector_round_decimals")
    L.count("gate.settings.pool_size", st["greedy_pool_size"], rel(p), "gate_settings.greedy_pool_size")
    L.text("gate.settings.depth_rule", st["probe_depth_rule"], rel(p), "gate_settings.probe_depth_rule",
           display=r"$\min(8, k+2)$")
    L.text("gate.settings.probe_splits", st["probe_splits"], rel(p), "gate_settings.probe_splits",
           display=r"\code{GroupShuffleSplit(n\_splits=3, test\_size=0.3)}")
    L.add("gate.settings.permutation_p_floor", 1.0 / (1 + st["input_dependence_permutations"]),
          pval(1.0 / (1 + st["input_dependence_permutations"])), rel(p),
          "1/(1+input_dependence_permutations)", "LEDGER-COMPUTED; equals the dependence_p of every class with no null exceedance")

    for name, fn, sup in [("gate.v2.technique", "gate_supplied_technique.json", True),
                          ("gate.v2.param", "gate_supplied_subtechnique.json", True),
                          ("gate.v1", "gate_supplied_v1.json", True),
                          ("gate.noopfree.param", "gate_noop_free_selfcontained_subtechnique.json", False),
                          ("gate.noopfree.technique", "gate_noop_free_selfcontained_technique.json", False)]:
        p = os.path.join(G, fn)
        gate_report(L, name, load(p), rel(p), sup)
    # self-contained runs: verdicts (R_self is also inside the supplied runs, check equality)
    for name, fn, sup in [("gate.self.technique", "gate_selfcontained_technique.json", False),
                          ("gate.self.param", "gate_selfcontained_subtechnique.json", False),
                          ("gate.self.v1", "gate_selfcontained_v1.json", False)]:
        p = os.path.join(G, fn)
        r = load(p)
        L.count(f"{name}.n_failures", len(r["failures"]), rel(p), "len(failures)")
        L.text(f"{name}.passed", bool(r["passed"]), rel(p), "passed", display="pass" if r["passed"] else "fail")
        L.num(f"{name}.R", r["single_feature"]["headroom_R"], rel(p), "single_feature.headroom_R")
    for g in ["technique", "param", "v1"]:
        a = L.d[f"gate.v2.{g}.R_self" if g != "v1" else "gate.v1.R_self"]["value"]
        b = L.d[f"gate.self.{g}.R"]["value"]
        if abs(a - b) > 1e-9:
            L.warn(f"self-contained R differs between supplied and self-contained runs for {g}")
    # supplied-protocol noop-free with the RF value of the no-op-free table
    p = os.path.join(G, "gate_noop_free_supplied_noopRF_subtechnique.json")
    r = load(p)
    L.num("gate.noopfree.param.R_supplied_noopRF", r["single_feature"]["headroom_R"], rel(p),
          "single_feature.headroom_R", "reference F1 0.8165 = RF lomfo on the no-op-free table")
    L.num("gate.noopfree.param.F1_supplied_noopRF", r["single_feature"]["full_set_macro_f1"], rel(p),
          "single_feature.full_set_macro_f1")

    # committed reports, cross-check (gate_v2 = v3 supplied on all committed keys)
    p = os.path.join(G, "compare_supplied_vs_committed.json")
    cmp_ = load(p)
    L.text("gate.xcheck.supplied_vs_committed", json.dumps(cmp_)[:200], rel(p), "",
           "differences between the v3 supplied runs and the committed gate_v2/gate_original reports")
    for fn, key in [("gate_v2_technique.json", "gate.committed.technique.R"),
                    ("gate_v2_subtechnique.json", "gate.committed.param.R"),
                    ("gate_original_technique.json", "gate.committed.v1.R")]:
        pc = os.path.join(RES, fn)
        L.num(key, load(pc)["single_feature"]["headroom_R"], rel(pc), "single_feature.headroom_R",
              "committed report (identical to the v3 supplied run)")

    # seed repeats (split seeds 0-9)
    p = os.path.join(G, "gate_v3_summary.json")
    rep = load(p)["task2_repeats"]
    for rk, name in [("selfcontained_technique", "technique.self"), ("supplied_technique", "technique.supplied"),
                     ("selfcontained_subtechnique", "param.self"), ("supplied_subtechnique", "param.supplied")]:
        r = rep[rk]
        base = f"gate.seeds.{name}"
        for q in ["best_1_macro_f1", "best_2_macro_f1", "best_3_macro_f1", "headroom_R",
                  "headroom_R_probe_reference", "full_set_probe_macro_f1"]:
            short = {"best_1_macro_f1": "best1", "best_2_macro_f1": "best2", "best_3_macro_f1": "best3",
                     "headroom_R": "R", "headroom_R_probe_reference": "R_self",
                     "full_set_probe_macro_f1": "probe_full"}[q]
            for stat in ["mean", "min", "max"]:
                L.num(f"{base}.{short}.{stat}", r[q][stat], rel(p), f"task2_repeats.{rk}.{q}.{stat}")
            for s, v in zip(r["seeds"], r[q]["values"]):
                L.num(f"{base}.{short}.seed{s}", v, rel(p), f"task2_repeats.{rk}.{q}.values[{s}]")
            L.count(f"{base}.{short}.n_defined", r[q]["n_defined"], rel(p), f"task2_repeats.{rk}.{q}.n_defined")
        for s, (bf, hs) in enumerate(zip(r["best_feature_by_seed"], r["headroom_status_by_seed"])):
            L.text(f"{base}.best_feature.seed{s}", bf, rel(p), f"task2_repeats.{rk}.best_feature_by_seed[{s}]",
                   display=r"\code{" + tex_escape(bf) + "}")
            L.text(f"{base}.status.seed{s}", hs, rel(p), f"task2_repeats.{rk}.headroom_status_by_seed[{s}]")
        L.count(f"{base}.n_headroom_fail", sum(h == "fail" for h in r["headroom_status_by_seed"]), rel(p),
                f"task2_repeats.{rk}.headroom_status_by_seed")
        L.count(f"{base}.n_seeds", len(r["seeds"]), rel(p), f"task2_repeats.{rk}.seeds")

    # consistent-protocol headroom
    p = os.path.join(G, "consistent_protocol_R.json")
    cp = load(p)["results"]
    for lab, g in [("technique", "technique"), ("sub_technique", "param")]:
        r = cp[lab]
        b = f"gate.consistent.{g}"
        L.num(f"{b}.R", r["R_consistent_protocol"], rel(p), f"results.{lab}.R_consistent_protocol")
        L.num(f"{b}.R_vs_probe", r["R_vs_probe_full_same_protocol"], rel(p),
              f"results.{lab}.R_vs_probe_full_same_protocol")
        L.num(f"{b}.F1_ref", r["F1_full_supplied"], rel(p), f"results.{lab}.F1_full_supplied")
        L.num(f"{b}.probe_full", r["full_set_probe_macro_f1"], rel(p), f"results.{lab}.full_set_probe_macro_f1")
        L.count(f"{b}.probe_depth", r["probe_depth"], rel(p), f"results.{lab}.probe_depth")
        L.text(f"{b}.best_feature", r["best_feature"], rel(p), f"results.{lab}.best_feature",
               display=r"\code{" + tex_escape(r["best_feature"]) + "}")
        L.num(f"{b}.best1_fold_sd", r["best_1_fold_sd"], rel(p), f"results.{lab}.best_1_fold_sd")
        for t in r["greedy_trace"]:
            L.num(f"{b}.best{t['k']}", t["macro_f1"], rel(p), f"results.{lab}.greedy_trace[k={t['k']}].macro_f1")
            L.text(f"{b}.best{t['k']}_features", t["features"], rel(p),
                   f"results.{lab}.greedy_trace[k={t['k']}].features",
                   display=", ".join(r"\code{" + tex_escape(x) + "}" for x in t["features"]))
        for i, t in enumerate(r["top_five"]):
            L.text(f"{b}.top{i + 1}.feature", t["feature"], rel(p), f"results.{lab}.top_five[{i}].feature",
                   display=r"\code{" + tex_escape(t["feature"]) + "}")
            L.num(f"{b}.top{i + 1}.f1", t["macro_f1"], rel(p), f"results.{lab}.top_five[{i}].macro_f1")

    # eta bias example
    p = os.path.join(G, "eta_bias_example.json")
    e = load(p)
    s = e["settings"]
    L.count("gate.eta.k", s["programs_k"], rel(p), "settings.programs_k")
    L.count("gate.eta.n", s["rows_n"], rel(p), "settings.rows_n")
    L.count("gate.eta.rows_per_program", s["rows_per_program"], rel(p), "settings.rows_per_program")
    L.count("gate.eta.features", s["features"], rel(p), "settings.features")
    L.count("gate.eta.permutations", s["permutations"], rel(p), "settings.permutations")
    L.num("gate.eta.raw", e["raw_eta_squared"]["observed"], rel(p), "raw_eta_squared.observed")
    L.num("gate.eta.raw_null_mean", e["raw_eta_squared"]["permutation_null_mean"], rel(p),
          "raw_eta_squared.permutation_null_mean")
    L.num("gate.eta.raw_analytic", e["raw_eta_squared"]["analytic_null_expectation"], rel(p),
          "raw_eta_squared.analytic_null_expectation", "(k-1)/(n-1)")
    L.num("gate.eta.omega2", e["omega_squared"]["observed"], rel(p), "omega_squared.observed")
    L.num("gate.eta.omega2_null_mean", e["omega_squared"]["permutation_null_mean"], rel(p),
          "omega_squared.permutation_null_mean")
    L.num("gate.eta.omega2_p", e["omega_squared"]["permutation_p_value"], rel(p),
          "omega_squared.permutation_p_value")
    L.add("gate.eta.omega2_p_3dp", e["omega_squared"]["permutation_p_value"],
          f"{e['omega_squared']['permutation_p_value']:.3f}", rel(p), "omega_squared.permutation_p_value",
          "3-decimal rounding as worded in the revision plan")
    L.num("gate.eta.gate_p", e["gate_diagnostic_1b"]["permutation"]["p_value"], rel(p),
          "gate_diagnostic_1b.permutation.p_value", "the gate's own permutation stream on the same table")

    # specificity
    p = os.path.join(G, "specificity_policies.json")
    sp = load(p)
    for pk, name in [("policy_i", "policy_i"), ("policy_ii", "policy_ii"), ("policy_ii_b_variant", "policy_iib")]:
        r = sp[pk]
        for q in ["agreement", "sensitivity", "specificity"]:
            k, n = [int(x) for x in r[q].split("/")]
            b = f"gate.spec.{name}.{q}"
            L.add(b, r[f"{q}_rate"], f"{k}/{n}", rel(p), f"{pk}.{q}")
            L.count(f"{b}_k", k, rel(p), f"{pk}.{q}")
            L.count(f"{b}_n", n, rel(p), f"{pk}.{q}")
            L.num(f"{b}_rate", r[f"{q}_rate"], rel(p), f"{pk}.{q}_rate")
            L.num(f"{b}_cp_lo", r[f"{q}_cp95"][0], rel(p), f"{pk}.{q}_cp95[0]", "Clopper-Pearson 95%")
            L.num(f"{b}_cp_hi", r[f"{q}_cp95"][1], rel(p), f"{pk}.{q}_cp95[1]", "Clopper-Pearson 95%")
            L.add(f"{b}_cp", r[f"{q}_cp95"], f"[{r[q + '_cp95'][0]:.4f}, {r[q + '_cp95'][1]:.4f}]",
                  rel(p), f"{pk}.{q}_cp95", "Clopper-Pearson 95% interval")
        for fam, v in r["per_family"].items():
            L.count(f"gate.spec.{name}.family.{fam}.correct", v["correct_seeds"], rel(p),
                    f"{pk}.per_family.{fam}.correct_seeds")
            L.count(f"gate.spec.{name}.family.{fam}.n", v["n_seeds"], rel(p), f"{pk}.per_family.{fam}.n_seeds")
            L.text(f"gate.spec.{name}.family.{fam}.expected", v["expected"], rel(p), f"{pk}.per_family.{fam}.expected")
    ru = sp["R_undefined"]
    L.count("gate.spec.R_undefined.count", ru["count"], rel(p), "R_undefined.count")
    L.count("gate.spec.R_undefined.of", ru["of"], rel(p), "R_undefined.of")
    hs = sp["headroom_status_counts"]
    for k, v in hs.items():
        L.count(f"gate.spec.headroom_status.{k}", v, rel(p), f"headroom_status_counts.{k}")
    inst = sp["per_instance"]
    fired5 = 0
    fam_checks: Dict[str, set] = {}
    for r in inst:
        b = f"gate.spec.inst.{r['family']}.seed{r['seed']}"
        L.text(f"{b}.checks", r["checks_fired"], rel(p), f"per_instance[{r['family']},{r['seed']}].checks_fired",
               display=", ".join(tex_escape(c.split('_')[0]) for c in r["checks_fired"]) or "none")
        L.num(f"{b}.best1", r["best_1"], rel(p), "per_instance.best_1")
        for kk in ("2", "3"):
            L.num(f"{b}.best{kk}", r["best_k"][kk], rel(p), f"per_instance.best_k.{kk}")
        L.num(f"{b}.probe_full", r["full_set_probe_macro_f1"], rel(p), "per_instance.full_set_probe_macro_f1")
        L.num(f"{b}.chance", r["chance"], rel(p), "per_instance.chance")
        L.num(f"{b}.gap", r["headroom_gap"], rel(p), "per_instance.headroom_gap")
        if r["headroom_R"] is None:
            L.add(f"{b}.R", None, "undefined", rel(p), "per_instance.headroom_R")
        else:
            L.num(f"{b}.R", r["headroom_R"], rel(p), "per_instance.headroom_R")
        L.text(f"{b}.status", r["headroom_status"], rel(p), "per_instance.headroom_status")
        L.num(f"{b}.permuted", r["permuted_macro_f1"], rel(p), "per_instance.permuted_macro_f1")
        L.count(f"{b}.n_rows", r["n_rows"], rel(p), "per_instance.n_rows")
        L.count(f"{b}.n_classes", r["n_classes"], rel(p), "per_instance.n_classes")
        L.text(f"{b}.passed_i", r["passed_policy_i"], rel(p), "per_instance.passed_policy_i",
               display="pass" if r["passed_policy_i"] else "fail")
        adv = [c for c in r["checks_fired"] if not c.startswith("4")]
        L.text(f"{b}.passed_ii", not adv, rel(p), "per_instance.checks_fired without 4_*",
               display="pass" if not adv else "fail", note="LEDGER-COMPUTED: policy (ii) ignores 4_feature_ceiling and 4b_headroom")
        L.text(f"{b}.should_pass", r["should_pass"], rel(p), "per_instance.should_pass",
               display="pass" if r["should_pass"] else "fail")
        if any(c.startswith("5") for c in r["checks_fired"]):
            fired5 += 1
        fam_checks.setdefault(r["family"], set()).update(r["checks_fired"])
    L.count("gate.spec.diag5_fired", fired5, rel(p), "per_instance[*].checks_fired starting with 5",
            "LEDGER-COMPUTED")
    for fam, cs in fam_checks.items():
        L.text(f"gate.spec.family.{fam}.checks", sorted(cs), rel(p), "union of per_instance.checks_fired",
               display=", ".join(tex_escape(c) for c in sorted(cs)) or "none", note="LEDGER-COMPUTED union over seeds")
    fa = [r for r in inst if r["should_pass"] and not r["passed_policy_i"]]
    if len(fa) == 1:
        r = fa[0]
        L.text("gate.spec.false_alarm.family", r["family"], rel(p), "per_instance (should_pass and not passed_policy_i)")
        L.count("gate.spec.false_alarm.seed", r["seed"], rel(p), "per_instance.seed")
        L.num("gate.spec.false_alarm.R", r["headroom_R"], rel(p), "per_instance.headroom_R")
        L.add("gate.spec.false_alarm.R_3dp", r["headroom_R"], f"{r['headroom_R']:.3f}", rel(p),
              "per_instance.headroom_R", "3-decimal rounding as worded in the revision plan")
        L.num("gate.spec.false_alarm.gap", r["headroom_gap"], rel(p), "per_instance.headroom_gap")
    else:
        L.warn(f"expected one false alarm under policy (i), found {len(fa)}")
    L.count("gate.spec.n_instances", len(inst), rel(p), "len(per_instance)")
    L.count("gate.spec.n_families", len({r['family'] for r in inst}), rel(p), "families in per_instance")
    pc = os.path.join(RES, "gate_specificity.json")
    c = load(pc)
    L.num("gate.spec.committed.agreement", c["agreement"], rel(pc), "agreement", "committed report")

    # no-op artifacts
    p = os.path.join(G, "noop_artifacts.json")
    na = load(p)
    tot = na["totals"] if "totals" in na else na.get("audit_totals", {})
    p2 = os.path.join(G, "noop_filter.json")
    nf = load(p2)
    L.count("gate.noop.n", nf["rows_removed"], rel(p2), "rows_removed")
    L.count("gate.noop.rows_after", nf["rows_out"], rel(p2), "rows_out")
    L.add("gate.noop.fraction_pct", nf["rows_removed"] / nf["rows_in"],
          pct(nf["rows_removed"] / nf["rows_in"], 2), rel(p2), "rows_removed / rows_in", "LEDGER-COMPUTED percentage")
    for r in nf["removed_by"]:
        L.count(f"gate.noop.by.{r['sample_id']}.{r['sub_technique']}", r["n"], rel(p2),
                f"removed_by[{r['sample_id']},{r['sub_technique']}].n")
    L.count("gate.noop.n_programs", len({r["sample_id"] for r in nf["removed_by"]}), rel(p2), "removed_by[*].sample_id")
    L.count("gate.noop.diag6_rows_full", nf["diag6_rows_on_full_table"], rel(p2), "diag6_rows_on_full_table")
    L.text("gate.noop.diag6_clusters_all_noop", nf["diag6_clusters_all_noop"], rel(p2), "diag6_clusters_all_noop")
    if isinstance(tot, dict) and "byte_identical" in tot:
        L.count("gate.noop.byte_identical", tot["byte_identical"], rel(p), "totals.byte_identical")


# --------------------------------------------------------------------------- #
# 3. open set

def fold_vals(folds, scorer, key):
    out = []
    for f in folds:
        s = f["scorers"].get(scorer, {})
        if "not_applicable" in s or key not in s or s[key] is None:
            continue
        out.append(float(s[key]))
    return out


def openset(L: Ledger) -> None:
    import pandas as pd
    grid = pd.read_csv(os.path.join(V3, "summary", "grid.csv"))
    reps = {}
    for c in CONFIGS:
        for v in VARIANTS:
            p = os.path.join(V3, f"openset_{c}_{v}.json")
            reps[(c, v)] = (load(p), rel(p))
    metric_keys = [("auroc", "auroc"), ("aupr_novel", "aupr_novel"), ("aupr_known", "aupr_known"),
                   ("fpr95_known_pos", "fpr95_known"), ("tpr95_achieved_known_pos", "tpr95_known"),
                   ("fpr95_novel_pos", "fpr95_novel"), ("tpr95_achieved_novel_pos", "tpr95_novel"),
                   ("oscr", "oscr")]
    for (c, v), (rep, src) in reps.items():
        V = VARIANTS[v]
        pf = rep["per_fold"]
        # configuration-level descriptors from the random forest folds
        rf = [f for f in pf if f["model"] == "random_forest"]
        base = f"open.{V}.{c}"
        L.count(f"{base}.n_folds_per_estimator", len(rf), src, "per_fold[model=random_forest]")
        L.count(f"{base}.n_units", len({f['novel_class'] for f in rf}), src, "unique per_fold.novel_class")
        L.count(f"{base}.n_seeds", len(rep["seeds"]), src, "seeds")
        if rep.get("n_blocks"):
            L.count(f"{base}.n_blocks", rep["n_blocks"], src, "n_blocks")
        prev = np.array([f["novel_prevalence"] for f in rf])
        L.num(f"{base}.novel_prevalence", prev.mean(), src, "mean per_fold.novel_prevalence")
        L.num(f"{base}.novel_prevalence_min", prev.min(), src, "min per_fold.novel_prevalence")
        L.num(f"{base}.novel_prevalence_max", prev.max(), src, "max per_fold.novel_prevalence")
        for k in ["n_novel", "n_known_eval", "n_fit", "n_novel_from_fit_programs", "n_eval_programs",
                  "n_fit_programs"]:
            a = np.array([f[k] for f in rf], float)
            L.num(f"{base}.{k}", a.mean(), src, f"mean per_fold.{k}", nd=1)
            L.count(f"{base}.{k}_min", a.min(), src, f"min per_fold.{k}")
            L.count(f"{base}.{k}_max", a.max(), src, f"max per_fold.{k}")
        fr = np.array([f["n_novel_from_fit_programs"] / f["n_novel"] for f in rf])
        L.num(f"{base}.frac_novel_from_fit", fr.mean(), src,
              "mean per_fold.n_novel_from_fit_programs / n_novel", "LEDGER-COMPUTED")
        L.add(f"{base}.frac_novel_from_fit_pct", fr.mean(), pct(fr.mean(), 0), src,
              "mean per_fold.n_novel_from_fit_programs / n_novel", "LEDGER-COMPUTED percentage")
        kc = sorted({f["n_known_classes"] for f in rf})
        L.text(f"{base}.n_known_classes", kc, src, "unique per_fold.n_known_classes",
               display=" or ".join(str(x) for x in kc))
        L.text(f"{base}.label", rep["label"], src, "label")
        L.text(f"{base}.holdout_unit", rep["holdout_unit"], src, "holdout_unit")
        L.text(f"{base}.split", rep["split"], src, "split")
        L.text(f"{base}.novel_programs", rep["novel_programs"], src, "novel_programs")
        if c == "A" and v == "heldout":
            L.count("open.settings.knn_k", rep["knn_k"], src, "knn_k")
            L.count("open.settings.weibull_tail", rep["weibull_tail"], src, "weibull_tail")
            L.count("open.settings.openmax_alpha", rep["openmax_alpha"], src, "openmax_alpha")
            L.count("open.settings.n_seeds", len(rep["seeds"]), src, "seeds")
            L.count("open.settings.n_estimators", len(rep["models"]), src, "models")
        for m in MODELS_OS:
            fm = [f for f in pf if f["model"] == m]
            mb = f"{base}.{m}"
            ca = np.array([f["closed_accuracy"] for f in fm])
            caa = np.array([f["closed_accuracy_argmax"] for f in fm])
            ece = np.array([f["ece"] for f in fm])
            L.num(f"{mb}.closed_acc", ca.mean(), src, f"mean per_fold[model={m}].closed_accuracy",
                  "predict(); differs from argmax(predict_proba) only for svm_rbf")
            L.num(f"{mb}.closed_acc_sd", ca.std(ddof=1), src, f"sd(ddof=1) per_fold[model={m}].closed_accuracy")
            L.num(f"{mb}.closed_acc_argmax", caa.mean(), src, f"mean per_fold[model={m}].closed_accuracy_argmax")
            L.num(f"{mb}.ece", ece.mean(), src, f"mean per_fold[model={m}].ece",
                  "15 equal-width bins, argmax-consistent correctness")
            L.num(f"{mb}.ece_sd", ece.std(ddof=1), src, f"sd(ddof=1) per_fold[model={m}].ece")
            L.count(f"{mb}.n_folds", len(fm), src, f"per_fold[model={m}]")
            for s in SCORERS:
                sb = f"{mb}.{s}"
                vals = {}
                for key, short in metric_keys:
                    vals[short] = fold_vals(fm, s, key)
                if not vals["auroc"]:
                    na = [f["scorers"][s].get("not_applicable") for f in fm if "not_applicable" in f["scorers"].get(s, {})]
                    L.add(f"{sb}.status", "not_applicable", "n/a", src,
                          f"per_fold[model={m}].scorers.{s}.not_applicable", na[0] if na else "")
                    continue
                a = np.array(vals["auroc"])
                L.num(f"{sb}.auroc", a.mean(), src, f"mean per_fold[model={m}].scorers.{s}.auroc")
                L.num(f"{sb}.auroc_sd", a.std(ddof=1), src, f"sd(ddof=1) per_fold[model={m}].scorers.{s}.auroc")
                L.num(f"{sb}.auroc_sd_pop", a.std(), src, f"sd(ddof=0) per_fold[model={m}].scorers.{s}.auroc",
                      "population sd as in summary/grid.csv")
                L.num(f"{sb}.auroc_min", a.min(), src, f"min per_fold[model={m}].scorers.{s}.auroc")
                L.num(f"{sb}.auroc_max", a.max(), src, f"max per_fold[model={m}].scorers.{s}.auroc")
                L.num(f"{sb}.frac_below_half", float((a < 0.5).mean()), src,
                      f"fraction of per_fold[model={m}].scorers.{s}.auroc < 0.5")
                L.count(f"{sb}.n_below_half", int((a < 0.5).sum()), src,
                        f"count of per_fold[model={m}].scorers.{s}.auroc < 0.5")
                L.count(f"{sb}.n_above_half", int((a > 0.5).sum()), src,
                        f"count of per_fold[model={m}].scorers.{s}.auroc > 0.5")
                L.count(f"{sb}.n_folds", a.size, src, f"per_fold[model={m}].scorers.{s}")
                for short in ["aupr_novel", "aupr_known", "fpr95_known", "tpr95_known", "fpr95_novel",
                              "tpr95_novel", "oscr"]:
                    x = np.array(vals[short])
                    L.num(f"{sb}.{short}", x.mean(), src, f"mean per_fold[model={m}].scorers.{s}.{short}")
                    L.num(f"{sb}.{short}_sd", x.std(ddof=1), src, f"sd(ddof=1) per_fold[model={m}].scorers.{s}.{short}")
                # cross-check against summary/grid.csv
                g = grid[(grid.variant == v) & (grid.config == c) & (grid.model == m) & (grid.scorer == s)]
                if len(g) == 1 and g.iloc[0]["status"] == "ok":
                    if abs(float(g.iloc[0]["auroc_mean"]) - a.mean()) > 5e-6:
                        L.warn(f"grid.csv AUROC mismatch {v} {c} {m} {s}")
                    if abs(float(g.iloc[0]["fpr95_known_pos_mean"]) - np.mean(vals["fpr95_known"])) > 5e-6:
                        L.warn(f"grid.csv FPR95 mismatch {v} {c} {m} {s}")
        # model-free scorers: identical over estimators; keep one copy
        for s in MODEL_FREE:
            ref = None
            for m in MODELS_OS:
                fm = sorted([f for f in pf if f["model"] == m],
                            key=lambda f: (f["seed"], f["novel_class"], str(f.get("block"))))
                a = [f["scorers"][s]["auroc"] for f in fm]
                if ref is None:
                    ref = a
                elif max(abs(x - y) for x, y in zip(a, ref)) > 1e-12:
                    L.warn(f"model-free scorer {s} differs across estimators in {c} {v}")
            for suffix in ["auroc", "auroc_sd", "auroc_sd_pop", "auroc_min", "auroc_max", "frac_below_half",
                           "n_below_half", "n_above_half", "n_folds", "aupr_novel", "aupr_known", "fpr95_known",
                           "tpr95_known", "fpr95_novel", "tpr95_novel", "aupr_novel_sd",
                           "aupr_known_sd", "fpr95_known_sd", "tpr95_known_sd", "fpr95_novel_sd",
                           "tpr95_novel_sd"]:
                # OSCR is not copied: it counts the estimator's correctly classified known rows,
                # so it differs between estimators even for a model-free score.
                e = L.d[f"{base}.random_forest.{s}.{suffix}"]
                L.add(f"{base}.{s}.{suffix}", e["value"], e["display"], e["source"], e["path"],
                      "model-free scorer: identical for every estimator (checked); copied from the random_forest folds")
        # minima / maxima over estimators of MSP AUROC
        if c == "B":
            ms = [L.d[f"{base}.{m}.msp.auroc"]["value"] for m in MODELS_OS]
            L.num(f"{base}.msp.min_over_estimators", min(ms), src, "min over estimators of mean MSP AUROC",
                  "LEDGER-COMPUTED", two=True)
            L.num(f"{base}.msp.max_over_estimators", max(ms), src, "max over estimators of mean MSP AUROC",
                  "LEDGER-COMPUTED", two=True)
            for s in ["msp", "energy", "openmax"]:
                vv = [L.d[f"{base}.{m}.{s}.auroc"]["value"] for m in LOGIT_MODELS]
                L.num(f"{base}.logit3.{s}.min", min(vv), src,
                      f"min over logreg, mlp, svm_rbf of mean {s} AUROC", "LEDGER-COMPUTED", two=True)
                L.num(f"{base}.logit3.{s}.max", max(vv), src,
                      f"max over logreg, mlp, svm_rbf of mean {s} AUROC", "LEDGER-COMPUTED", two=True)
    # two-decimal headline roundings
    for k in ["open.matched.B.random_forest.msp.auroc", "open.overlap.B.random_forest.msp.auroc",
              "open.matched.C.random_forest.msp.auroc", "open.matched.B.knn_dist.auroc",
              "open.overlap.B.knn_dist.auroc", "open.matched.B.mahalanobis.auroc",
              "open.overlap.B.mahalanobis.auroc"]:
        e = L.d[k]
        L.add(k + "_2dp", e["value"], fnd(e["value"], 2), e["source"], e["path"], "2-decimal rounding")

    # cross-check: overlapping protocol reproduces the committed reports
    for c, fn in [("A", "openset_v2_technique.json"), ("B", "openset_v2_subtechnique.json"),
                  ("C", "openset_v2_family.json")]:
        pc = os.path.join(RES, fn)
        com = load(pc)
        for m in MODELS_OS:
            a = com["summary"][m]["scorers"]["msp"]["auroc_mean"]
            b = L.d[f"open.overlap.{c}.{m}.msp.auroc"]["value"]
            if abs(a - b) > 1e-9:
                L.warn(f"overlap {c} {m} MSP differs from committed {fn}")
        L.num(f"open.committed.{c}.random_forest.msp.auroc", com["summary"]["random_forest"]["scorers"]["msp"]["auroc_mean"],
              rel(pc), "summary.random_forest.scorers.msp.auroc_mean",
              "committed report; equals open.overlap.<C>.random_forest.msp.auroc")

    # B minus C contrast (crossed bootstrap, summary/bc_contrast.csv)
    p = os.path.join(V3, "summary", "bc_contrast.csv")
    for r in read_csv(p):
        V = VARIANTS[r["variant"]]
        m = r["model"]
        b = f"open.{V}.bc.{m}"
        sel = f"rows[variant={r['variant']},model={m}]"
        L.num(f"{b}.B", float(r["B_msp_auroc_mean"]), rel(p), f"{sel}.B_msp_auroc_mean")
        L.num(f"{b}.C", float(r["C_msp_auroc_mean"]), rel(p), f"{sel}.C_msp_auroc_mean")
        L.num(f"{b}.diff", float(r["B_minus_C"]), rel(p), f"{sel}.B_minus_C", "B minus C")
        L.num(f"{b}.ci_lo", float(r["boot_ci95_lo"]), rel(p), f"{sel}.boot_ci95_lo",
              "crossed bootstrap (units x seeds), 10000 replicates, percentile 95%")
        L.num(f"{b}.ci_hi", float(r["boot_ci95_hi"]), rel(p), f"{sel}.boot_ci95_hi")
        L.num(f"{b}.frac_ge_0", float(r["boot_frac_ge_0"]), rel(p), f"{sel}.boot_frac_ge_0")
        L.num(f"{b}.fam_diff", float(r["family_paired_mean_diff"]), rel(p), f"{sel}.family_paired_mean_diff")
        L.num(f"{b}.fam_ci_lo", float(r["family_paired_ci95_lo"]), rel(p), f"{sel}.family_paired_ci95_lo")
        L.num(f"{b}.fam_ci_hi", float(r["family_paired_ci95_hi"]), rel(p), f"{sel}.family_paired_ci95_hi")
        excl = float(r["boot_ci95_hi"]) < 0 or float(r["boot_ci95_lo"]) > 0
        L.text(f"{b}.ci_excludes_0", excl, rel(p), f"{sel}.boot_ci95_lo/hi", "LEDGER-COMPUTED",
               display="yes" if excl else "no")
        cb = f"open.{V}.cb.{m}"
        L.num(f"{cb}.diff", -float(r["B_minus_C"]), rel(p), f"{sel}.B_minus_C",
              "C minus B (sign flipped); LEDGER-COMPUTED", two=(m == "random_forest"))
        L.num(f"{cb}.ci_lo", -float(r["boot_ci95_hi"]), rel(p), f"{sel}.boot_ci95_hi",
              "C minus B: lower bound = -(B minus C upper bound); LEDGER-COMPUTED", two=(m == "random_forest"))
        L.num(f"{cb}.ci_hi", -float(r["boot_ci95_lo"]), rel(p), f"{sel}.boot_ci95_lo",
              "C minus B: upper bound = -(B minus C lower bound); LEDGER-COMPUTED", two=(m == "random_forest"))

    # class-level crossed bootstrap of configuration B MSP AUROC (LEDGER-COMPUTED)
    for vi, v in enumerate(VARIANTS):
        rep, src = reps[("B", v)]
        V = VARIANTS[v]
        for mi, m in enumerate(MODELS_OS):
            cells: Dict = {}
            for f in rep["per_fold"]:
                if f["model"] != m:
                    continue
                cells.setdefault((f["novel_class"], f["seed"]), []).append(f["scorers"]["msp"]["auroc"])
            units = sorted({u for u, _ in cells})
            seeds = sorted({s for _, s in cells})
            M = np.array([[np.mean(cells[(u, s)]) for s in seeds] for u in units])
            rng = np.random.default_rng([BOOT_SEED, vi, mi])
            nu, ns = M.shape
            wu = rng.multinomial(nu, np.full(nu, 1.0 / nu), size=BOOT_R)
            ws = rng.multinomial(ns, np.full(ns, 1.0 / ns), size=BOOT_R)
            boots = np.einsum("ru,us,rs->r", wu, M, ws) / (nu * ns)
            lo, hi = np.percentile(boots, [2.5, 97.5])
            b = f"open.{V}.B.{m}.msp"
            note = ("LEDGER-COMPUTED: crossed bootstrap over the 10 held-out parameterisations and the 5 seeds "
                    "(scheme of summarise_openset.boot_crossed, 10000 replicates, numpy default_rng([20261009, "
                    f"{vi}, {mi}])), percentile 95%")
            L.num(f"{b}.class_ci_lo", lo, src, f"per_fold[model={m}].scorers.msp.auroc", note)
            L.num(f"{b}.class_ci_hi", hi, src, f"per_fold[model={m}].scorers.msp.auroc", note)
            ub = hi < 0.5
            L.text(f"{b}.class_ci_below_half", ub, src, "class_ci_hi < 0.5", "LEDGER-COMPUTED",
                   display="yes" if ub else "no")
            cm = M.mean(axis=1)
            nb = int((cm < 0.5).sum())
            L.count(f"{b}.n_classes_below_half", nb, src,
                    f"held-out parameterisations whose seed-averaged MSP AUROC < 0.5 (model={m})", "LEDGER-COMPUTED")
            L.count(f"{b}.n_classes", len(units), src, "held-out parameterisations")
            sp = sstats.binomtest(nb, len(units), 0.5).pvalue
            L.add(f"{b}.class_sign_p", float(sp), pval(sp), src, "exact two-sided binomial sign test on class means",
                  "LEDGER-COMPUTED")
        below = [m for m in MODELS_OS if L.d[f"open.{V}.B.{m}.msp.class_ci_below_half"]["value"]]
        L.text(f"open.{V}.B.msp.class_ci_below_half_models", below, src, "", "LEDGER-COMPUTED",
               display=", ".join(r"\code{" + tex_escape(x) + "}" for x in below) or "none")

    # scorer per-fold counts (summary/table17.csv)
    p = os.path.join(V3, "summary", "table17.csv")
    for r in read_csv(p):
        V = VARIANTS[r["variant"]]
        b = f"open.{V}.{r['config']}.{r['model']}.count"
        sel = f"rows[variant={r['variant']},config={r['config']},model={r['model']}]"
        for col, short in [("n_msp<energy", "msp_lt_energy"), ("n_energy<openmax", "energy_lt_openmax"),
                           ("n_msp<energy<openmax", "msp_lt_energy_lt_openmax"), ("n_openmax>0.5", "openmax_gt_half"),
                           ("n_energy>0.5", "energy_gt_half"), ("n_msp>0.5", "msp_gt_half"), ("n_folds", "n_folds")]:
            L.count(f"{b}.{short}", int(r[col]), rel(p), f"{sel}.{col}")

    # mechanism (nearest neighbours), AUDIT-GENERATED copy
    p = os.path.join(V3, "openset_mechanism", "nn_mechanism.json")
    if os.path.exists(p):
        nn = load(p)
        for c in CONFIGS:
            for grp, name in [("known_eval", "known_eval"), ("novel_unseen", "novel_matched"),
                              ("novel_seen", "novel_overlap")]:
                b = f"open.mech.{c}.{name}"
                fr = nn[c]["nearest_fit_row_same_program_frac"][grp]
                L.num(f"{b}.nn_same_program_frac", fr, rel(p), f"{c}.nearest_fit_row_same_program_frac.{grp}",
                      "AUDIT-GENERATED analysis copied into the repository")
                L.add(f"{b}.nn_same_program_pct", fr, pct(fr, 1), rel(p),
                      f"{c}.nearest_fit_row_same_program_frac.{grp}", "percentage, 1 decimal")
                d5 = nn[c]["mean_5nn_distance"][grp]
                L.add(f"{b}.mean_5nn_distance", d5, fnd(d5, 2), rel(p), f"{c}.mean_5nn_distance.{grp}",
                      "mean Euclidean distance to the 5 nearest fitting rows (standardised); 2 decimals")
                L.num(f"{b}.mean_5nn_distance_4dp", d5, rel(p), f"{c}.mean_5nn_distance.{grp}")
        for lab in ["sample_id", "sub_technique", "technique"]:
            L.num(f"open.mech.oneway_r2.{lab}.mean", nn["oneway_r2"][lab]["mean_r2"], rel(p),
                  f"oneway_r2.{lab}.mean_r2", "mean over the live features of the one-way R^2")
            L.num(f"open.mech.oneway_r2.{lab}.median", nn["oneway_r2"][lab]["median_r2"], rel(p),
                  f"oneway_r2.{lab}.median_r2")
            L.count(f"open.mech.oneway_r2.{lab}.n_features", nn["oneway_r2"][lab]["n_live_features"], rel(p),
                    f"oneway_r2.{lab}.n_live_features")
    else:
        L.warn("nn_mechanism.json copy missing")

    # run diagnostics (MLP convergence, Weibull fallbacks)
    p = os.path.join(V3, "summary", "diagnostics_summary.json")
    dg = load(p)
    for c in CONFIGS:
        for v in VARIANTS:
            k = f"openset_{c}_{v}"
            if k not in dg:
                continue
            r = dg[k]
            b = f"open.diag.{VARIANTS[v]}.{c}"
            L.count(f"{b}.mlp_fits", r["fits"]["mlp"], rel(p), f"{k}.fits.mlp")
            L.count(f"{b}.mlp_max_iter", r["mlp_fits_reaching_max_iter"]["mlp"], rel(p),
                    f"{k}.mlp_fits_reaching_max_iter.mlp")
            for m in ["extra_trees", "knn"]:
                w = r["weibull"][f"{m}|posterior"]
                L.count(f"{b}.weibull.{m}.fits", w["fits"], rel(p), f"{k}.weibull.{m}|posterior.fits")
                L.count(f"{b}.weibull.{m}.degenerate", w.get("fallback_degenerate", 0), rel(p),
                        f"{k}.weibull.{m}|posterior.fallback_degenerate")
            L.count(f"{b}.scorer_errors", len(r["scorer_errors"]), rel(p), f"{k}.scorer_errors")
    # code constants used in the protocol description
    p = os.path.join(REPO, "scripts", "openset_baselines.py")
    code = open(p).read()
    m = re.search(r"def _ece\(.*?n_bins: int = (\d+)", code, re.S)
    L.count("open.settings.ece_bins", int(m.group(1)), rel(p), "_ece(n_bins default)", "code constant")
    m = re.search(r"IsolationForest\(n_estimators=(\d+)", code)
    L.count("open.settings.iforest_trees", int(m.group(1)), rel(p), "IsolationForest(n_estimators)", "code constant")
    m = re.search(r"GroupShuffleSplit\(n_splits=1, test_size=([0-9.]+)", code)
    L.num("open.settings.gss_test_size", float(m.group(1)), rel(p), "GroupShuffleSplit(test_size)",
          "code constant", nd=1)
    L.count("open.settings.boot_replicates", BOOT_R, "scripts/manuscript_v3/make_ledger.py", "BOOT_R",
            "LEDGER-COMPUTED: replicates of the crossed (unit x seed) bootstrap")
    # largest |k-fold - matched| fold-mean AUROC over the 15 scorer/estimator rows of each configuration
    rows15 = ([(f"{m}.msp", m) for m in ["random_forest", "extra_trees", "logreg", "svm_rbf", "knn", "mlp"]]
              + [(f"{m}.{s}", m) for s in ["energy", "openmax"] for m in ["logreg", "mlp", "svm_rbf"]]
              + [(s, None) for s in ["knn_dist", "mahalanobis", "iforest"]])
    for c in "ABC":
        diffs = []
        for r, _m in rows15:
            km, kk = f"open.matched.{c}.{r}.auroc", f"open.kfold.{c}.{r}.auroc"
            if km in L.d and kk in L.d:
                diffs.append((abs(L.d[kk]["value"] - L.d[km]["value"]), r))
        if len(diffs) == len(rows15):
            dmax, rmax = max(diffs)
            L.num(f"open.kfold_vs_matched.{c}.max_abs_auroc_diff", dmax, "LEDGER-COMPUTED",
                  f"max over the 15 configuration-{c} rows of |open.kfold.{c}.*.auroc - open.matched.{c}.*.auroc|",
                  "LEDGER-COMPUTED from fold-mean AUROC values")
            L.text(f"open.kfold_vs_matched.{c}.max_abs_auroc_diff_row", rmax, "LEDGER-COMPUTED",
                   "row attaining the maximum", "LEDGER-COMPUTED")


# --------------------------------------------------------------------------- #
# 4. sibling axis

def sibling(L: Ledger) -> None:
    pst = os.path.join(V3, "summary", "sibling_tests.json")
    st = load(pst)
    proj = {}
    for fam, v in st["pc1_recomputed_unrounded"].items():
        L.num(f"sib.pc1.{fam}.share", v["pc1_variance_share"], rel(pst),
              f"pc1_recomputed_unrounded.{fam}.pc1_variance_share")
        for par, x in v["projections"].items():
            proj[par] = (fam, x)
    for v in VARIANTS:
        V = VARIANTS[v]
        p = os.path.join(V3, f"openset_B_{v}.json")
        rep = load(p)
        ps = os.path.join(V3, f"sibling_position_{v}.json")
        sp = load(ps)
        pos = {k: x["position"] for k, x in sp["positions"].items()}
        for par in PARAMS:
            a = np.array([f["scorers"]["msp"]["auroc"] for f in rep["per_fold"] if f["novel_class"] == par])
            b = f"sib.{V}.{par}"
            L.num(f"{b}.auroc", a.mean(), rel(p), f"mean per_fold[novel_class={par}].scorers.msp.auroc (6 estimators)")
            L.num(f"{b}.sd", a.std(ddof=1), rel(p), f"sd(ddof=1) per_fold[novel_class={par}].scorers.msp.auroc")
            L.num(f"{b}.frac_below_half", float((a < 0.5).mean()), rel(p), "fraction of folds with AUROC < 0.5")
            L.count(f"{b}.n_folds", a.size, rel(p), f"per_fold[novel_class={par}]")
            L.text(f"{b}.position", pos[par], rel(ps), f"positions.{par}.position",
                   display={"end": "end", "end_of_pair": "end of pair", "interior": "interior"}[pos[par]])
            exp = st[v]["param_level_means"][par]
            if abs(exp - a.mean()) > 1e-9:
                L.warn(f"sibling mean mismatch {v} {par}")
        for g in ["end", "end_of_pair", "interior"]:
            members = [par for par in PARAMS if pos[par] == g]
            a = np.array([f["scorers"]["msp"]["auroc"] for f in rep["per_fold"] if f["novel_class"] in members])
            b = f"sib.{V}.{g}"
            L.num(f"{b}.mean", a.mean(), rel(p), f"mean per_fold[novel_class in {g}].scorers.msp.auroc",
                  two=True)
            L.num(f"{b}.sd", a.std(ddof=1), rel(p), "sd(ddof=1) over folds")
            L.num(f"{b}.frac_below_half", float((a < 0.5).mean()), rel(p), "fraction of folds with AUROC < 0.5")
            L.count(f"{b}.n_folds", a.size, rel(p), f"per_fold[novel_class in {g}]")
            L.count(f"{b}.n_params", len(members), rel(ps), f"positions[*].position == {g}")
        t = st[v]
        for tk, short in [("param_level_perm_ends_lt_interiors", "ends_vs_interiors"),
                          ("param_level_perm_ends_lt_pairs_and_interiors", "ends_vs_others")]:
            L.num(f"sib.{V}.perm_p.{short}", t[tk]["p_one_sided"], rel(pst), f"{v}.{tk}.p_one_sided",
                  "exact one-sided permutation test at the parameterisation level")
            L.num(f"sib.{V}.perm_p.{short}_min", t[tk]["min_attainable_p"], rel(pst), f"{v}.{tk}.min_attainable_p")
            L.count(f"sib.{V}.perm_p.{short}_arrangements", t[tk]["n_arrangements"], rel(pst), f"{v}.{tk}.n_arrangements")
            L.count(f"sib.{V}.perm_p.{short}_extreme", t[tk]["n_as_or_more_extreme"], rel(pst),
                    f"{v}.{tk}.n_as_or_more_extreme")
            L.num(f"sib.{V}.perm_p.{short}_diff", t[tk]["t_obs_mean_diff"], rel(pst), f"{v}.{tk}.t_obs_mean_diff")
    vals = {L.d[f"sib.{VARIANTS[v]}.perm_p.ends_vs_interiors"]["value"] for v in VARIANTS}
    if len(vals) == 1:
        x = vals.pop()
        L.num("sib.perm_p.ends_vs_interiors", x, rel(pst), "<variant>.param_level_perm_ends_lt_interiors.p_one_sided",
              "identical in the matched, overlapping and k-fold variants (= 1/15, the minimum attainable)")
        L.text("sib.perm_p.ends_vs_interiors_fraction", "1/15", rel(pst), "n_as_or_more_extreme/n_arrangements",
               display="1/15")
    else:
        L.warn("ends-vs-interiors permutation p differs between variants")
    for par, (fam, x) in proj.items():
        L.num(f"sib.proj.{par}", x, rel(pst), f"pc1_recomputed_unrounded.{fam}.projections.{par}")
        L.num(f"sib.proj.{par}.abs", abs(x), rel(pst), f"|pc1_recomputed_unrounded.{fam}.projections.{par}|")
        L.text(f"sib.family.{par}", fam, rel(pst), f"pc1_recomputed_unrounded.{fam}")
    # committed report cross-check
    pc = os.path.join(RES, "sibling_position.json")
    if os.path.exists(pc):
        com = load(pc)
        L.text("sib.committed.source", rel(pc), rel(pc), "", "committed sibling report (overlapping protocol)")


# --------------------------------------------------------------------------- #
# 5. simulation

def simulation(L: Ledger) -> None:
    p = os.path.join(V3, "sim", "table18_v3.csv")
    rows = read_csv(p)
    stems = {"bayes_posterior_auroc_end": "end", "bayes_posterior_auroc_interior": "interior",
             "bayes_posterior_auroc_family": "family", "bayes_maxscore_auroc_end": "maxscore_end",
             "bayes_maxscore_auroc_interior": "maxscore_interior", "bayes_maxscore_auroc_family": "maxscore_family",
             "bayes_retained_acc_family": "bayes_acc_family", "rf_retained_acc_family": "rf_acc_family",
             "bayes_retained_acc_end": "bayes_acc_end", "rf_retained_acc_end": "rf_acc_end",
             "fitted_lr_auroc_end": "lr_end", "fitted_lr_auroc_interior": "lr_interior",
             "fitted_lr_auroc_family": "lr_family", "fitted_rf_auroc_end": "rf_end",
             "fitted_rf_auroc_interior": "rf_interior", "fitted_rf_auroc_family": "rf_family"}
    for r in rows:
        lay, ns, sp = r["layout"], int(r["n_seeds"]), float(r["sibling_spread"])
        b = f"sim.{lay}.{ns}.{sspread(sp)}"
        sel = f"rows[layout={lay},n_seeds={ns},sibling_spread={sp:g}]"
        for stem, short in stems.items():
            for st, suf in [("mean", "mean"), ("ci95_lo", "ci_lo"), ("ci95_hi", "ci_hi")]:
                L.num(f"{b}.{short}.{suf}", float(r[f"{stem}_{st}"]), rel(p), f"{sel}.{stem}_{st}",
                      "mean over seeds; 95% t interval of the mean" if suf != "mean" else "mean over seeds")
    # derived: max |end - interior| under the random layout, 20 seeds, spreads 0.25-4
    d = []
    for sp in SPREADS[:-1]:
        b = f"sim.random.20.{sspread(sp)}"
        d.append(abs(L.d[f"{b}.end.mean"]["value"] - L.d[f"{b}.interior.mean"]["value"]))
    L.num("sim.random.20.max_abs_end_minus_interior", max(d), rel(p),
          "max over spreads 0.25-4 of |end.mean - interior.mean|", "LEDGER-COMPUTED difference of ledger values")
    raw = load(os.path.join(V3, "sim", "inversion_sim_ordered_20seeds.json"))["settings"]
    src = "results/v3/sim/inversion_sim_ordered_20seeds.json"
    for k in ["n_families", "n_siblings", "n_per_class", "dim"]:
        L.count(f"sim.settings.{k}", raw[k], src, f"settings.{k}")
    L.num("sim.settings.family_spread", raw["family_spread"], src, "settings.family_spread", nd=1)
    L.count("sim.settings.seeds", raw["seeds"], src, "settings.seeds")
    # long table: number of seeds below 0.5 (Bayes posterior)
    pl = os.path.join(V3, "sim", "table18_v3_long.csv")
    metric_map = {"auroc_bayes_msp": "", "auroc_bayes_max_logit": "maxscore_", "auroc_logreg_msp": "lr_",
                  "auroc_random_forest_msp": "rf_", "closed_accuracy_bayes": "bayes_acc_",
                  "closed_accuracy_random_forest": "rf_acc_", "closed_accuracy_logreg": "lr_acc_"}
    for r in read_csv(pl):
        if r["metric"] not in metric_map:
            continue
        hold = {"edge": "end", "interior": "interior", "family": "family"}[r["holdout"]]
        short = metric_map[r["metric"]] + hold
        b = f"sim.{r['layout']}.{r['n_seeds']}.{sspread(float(r['sibling_spread']))}.{short}"
        sel = (f"rows[layout={r['layout']},n_seeds={r['n_seeds']},sibling_spread={r['sibling_spread']},"
               f"holdout={r['holdout']},metric={r['metric']}]")
        L.count(f"{b}.n_below_half", int(r["n_below_0_5"]), rel(pl), f"{sel}.n_below_0_5",
                "number of seeds with a value below 0.5")
        for col, suf in [("min", "min"), ("max", "max"), ("pct2_5", "pct_lo"), ("pct97_5", "pct_hi"), ("sd", "sd")]:
            L.num(f"{b}.{suf}", float(r[col]), rel(pl), f"{sel}.{col}",
                  "over the per-seed values" + ("; sd with ddof = 1" if suf == "sd" else ""))
    sm = load(os.path.join(V3, "sim", "sim_v3_summary.json"))
    rc = sm["reproduction_check"]
    L.count("sim.repro.cells_compared", rc["table18_cells_compared"], "results/v3/sim/sim_v3_summary.json",
            "reproduction_check.table18_cells_compared")
    L.count("sim.repro.cells_matching", rc["table18_cells_matching_ms_committed_and_rerun"],
            "results/v3/sim/sim_v3_summary.json", "reproduction_check.table18_cells_matching_ms_committed_and_rerun")


# --------------------------------------------------------------------------- #
# 6. closed set

def closed(L: Ledger) -> None:
    C = os.path.join(V3, "closed")
    p = os.path.join(C, "pg_aggregate.json")
    for c in load(p)["cells"]:
        b = f"closed.pg.family.{c['model']}"
        L.num(f"{b}.mean", c["mean"], rel(p), f"cells[model={c['model']}].mean",
              "repeated grouped CV, 5 permuted program partitions x 5 folds")
        L.num(f"{b}.fold_sd", c["sd_fold"], rel(p), f"cells[model={c['model']}].sd_fold")
        L.num(f"{b}.partition_sd", c["sd_seed"], rel(p), f"cells[model={c['model']}].sd_seed",
              "sd of the 5 per-partition means (seed = partition)")
        L.num(f"{b}.min", c["min_fold"], rel(p), f"cells[model={c['model']}].min_fold")
        L.num(f"{b}.max", c["max_fold"], rel(p), f"cells[model={c['model']}].max_fold")
    for fn, gran in [("closed_set_five_seed.json", "family"), ("closed_set_five_seed_sub.json", "param")]:
        p = os.path.join(RES, fn)
        cells_ = load(p)["cells"]
        ns = {c["n_seeds"] for c in cells_}
        nf = {c["n_folds_per_seed"] for c in cells_}
        if len(ns) == 1 and len(nf) == 1:
            L.count(f"closed.{gran}.n_seeds", ns.pop(), rel(p), "cells[*].n_seeds")
            L.count(f"closed.{gran}.n_folds_per_seed", nf.pop(), rel(p), "cells[*].n_folds_per_seed")
        else:
            L.warn(f"{fn}: seeds or folds differ between cells")
        for c in cells_:
            proto = {"grouped_cv": "fixed", "lomfo": "lomfo"}[c["protocol"]]
            sel = f"cells[protocol={c['protocol']},model={c['model']},feature_set={c['feature_set']}]"
            if c["feature_set"] == "all":
                b = f"closed.{proto}.{gran}.{c['model']}"
            else:
                b = f"closed.{proto}.{gran}.{c['model']}.fs.{c['feature_set']}"
            L.num(f"{b}.mean", c["mean"], rel(p), f"{sel}.mean")
            L.num(f"{b}.fold_sd", c["sd_fold"], rel(p), f"{sel}.sd_fold")
            L.num(f"{b}.seed_sd", c["sd_seed"], rel(p), f"{sel}.sd_seed")
            L.num(f"{b}.min", c["min_fold"], rel(p), f"{sel}.min_fold")
            L.num(f"{b}.max", c["max_fold"], rel(p), f"{sel}.max_fold")
    for k in ["closed.lomfo.family.random_forest.mean", "closed.lomfo.param.random_forest.mean"]:
        e = L.d[k]
        L.add(k + "_2dp", e["value"], fnd(e["value"], 2), e["source"], e["path"], "2-decimal rounding")
    # differences repeated minus fixed partition
    p = os.path.join(C, "pg_vs_table19.csv")
    for r in read_csv(p):
        L.num(f"closed.pg.family.{r['model']}.minus_fixed", float(r["pg_minus_table19_mean"]), rel(p),
              f"rows[model={r['model']}].pg_minus_table19_mean")
    # fold-level paired comparisons (committed cells, n = 5 distinct folds)
    p = os.path.join(C, "paired_foldlevel.csv")
    for r in read_csv(p):
        setting = {"grouped_cv": "fixedcv", "lomfo": "family"}[r["protocol"]] if r["granularity"] == "family" else "param"
        b = f"paired.fold.{setting}.{r['model_a']}_vs_{r['model_b']}"
        sel = f"rows[granularity={r['granularity']},protocol={r['protocol']},model_a={r['model_a']},model_b={r['model_b']}]"
        L.count(f"{b}.wins", int(r["wins"]), rel(p), f"{sel}.wins")
        L.count(f"{b}.ties", int(r["ties"]), rel(p), f"{sel}.ties")
        L.count(f"{b}.losses", int(r["losses"]), rel(p), f"{sel}.losses")
        L.add(f"{b}.wtl", f"{r['wins']}/{r['ties']}/{r['losses']}", f"{r['wins']}/{r['ties']}/{r['losses']}",
              rel(p), f"{sel}.wins/ties/losses")
        L.num(f"{b}.mean_diff", float(r["mean_diff"]), rel(p), f"{sel}.mean_diff", "model_a minus model_b")
        L.num(f"{b}.sd_fold_diff", float(r["sd_fold_diff"]), rel(p), f"{sel}.sd_fold_diff")
        L.add(f"{b}.nb_p", float(r["nb_p"]), pval(r["nb_p"]), rel(p), f"{sel}.nb_p",
              "Nadeau-Bengio corrected t, df 4")
        L.add(f"{b}.nb_p_holm", float(r["nb_p_holm21"]), pval(r["nb_p_holm21"]), rel(p), f"{sel}.nb_p_holm21",
              "Holm over the 21 pairs of the setting")
        L.add(f"{b}.sign_p", float(r["sign_p_exact"]), pval(r["sign_p_exact"]), rel(p), f"{sel}.sign_p_exact")
        L.add(f"{b}.wilcoxon_p", float(r["wilcoxon_p_exact"]), pval(r["wilcoxon_p_exact"]), rel(p),
              f"{sel}.wilcoxon_p_exact")
        L.num(f"{b}.mean_a", float(r["mean_a"]), rel(p), f"{sel}.mean_a")
        L.num(f"{b}.mean_b", float(r["mean_b"]), rel(p), f"{sel}.mean_b")
    # reversed-orientation record for a pair the text reports from the other side (HGB minus RF, family)
    k = "paired.fold.family.random_forest_vs_hist_gbdt.wtl"
    w_, t_, l_ = L.d[k]["display"].split("/")
    L.add("paired.fold.family.hist_gbdt_vs_random_forest.wtl", f"{l_}/{t_}/{w_}", f"{l_}/{t_}/{w_}",
          L.d[k]["source"], L.d[k]["path"] + " (reversed)",
          "LEDGER-COMPUTED: wins/ties/losses of random_forest_vs_hist_gbdt read from the hist_gbdt side")
    p = os.path.join(C, "pg_paired_corrected.csv")
    for r in read_csv(p):
        b = f"paired.pg.family.{r['model_a']}_vs_{r['model_b']}"
        sel = f"rows[model_a={r['model_a']},model_b={r['model_b']}]"
        L.count(f"{b}.wins", int(r["wins"]), rel(p), f"{sel}.wins")
        L.count(f"{b}.ties", int(r["ties"]), rel(p), f"{sel}.ties")
        L.count(f"{b}.losses", int(r["losses"]), rel(p), f"{sel}.losses")
        L.add(f"{b}.wtl", f"{r['wins']}/{r['ties']}/{r['losses']}", f"{r['wins']}/{r['ties']}/{r['losses']}",
              rel(p), f"{sel}.wins/ties/losses")
        L.num(f"{b}.mean_diff", float(r["mean_diff"]), rel(p), f"{sel}.mean_diff")
        L.add(f"{b}.p", float(r["corrected_rcv_p"]), pval(r["corrected_rcv_p"]), rel(p), f"{sel}.corrected_rcv_p",
              "corrected repeated CV t (r = 5, k = 5, df 24)")
        L.add(f"{b}.p_holm", float(r["corrected_rcv_p_holm21"]), pval(r["corrected_rcv_p_holm21"]), rel(p),
              f"{sel}.corrected_rcv_p_holm21", "Holm over 21 pairs")
    p = os.path.join(C, "summary_v3_closed.json")
    sm = load(p)
    for k, v in sm["task3_paired_foldlevel_by_setting"].items():
        gran, proto = k.split("|")
        setting = ("fixedcv" if proto == "grouped_cv" else "family") if gran == "family" else "param"
        for q in ["n_pairs", "n_5_of_5", "n_sign_p_lt_0.05", "n_wilcoxon_p_lt_0.05", "n_nb_p_lt_0.05",
                  "n_nb_holm_lt_0.05"]:
            L.count(f"paired.summary.{setting}.{q.replace('.', '')}", v[q], rel(p),
                    f"task3_paired_foldlevel_by_setting.{k}.{q}")
    L.count("closed.pg.n_partitions", sm["task1_partition_variance"]["n_distinct_partitions"], rel(p),
            "task1_partition_variance.n_distinct_partitions")
    L.count("closed.pg.n_test_folds", sm["task1_partition_variance"]["n_distinct_test_folds"], rel(p),
            "task1_partition_variance.n_distinct_test_folds")
    pm = os.path.join(C, "paired_foldlevel_meta.json")
    meta = load(pm)
    L.num("paired.min_exact_p", meta["minimum_attainable_exact_p_with_5_folds"]["sign"], rel(pm),
          "minimum_attainable_exact_p_with_5_folds.sign")
    L.count("closed.repro.n_cells", sm["repro_check_n_cells"], rel(p), "repro_check_n_cells")
    L.text("closed.repro.all_exact", sm["repro_check_all_exact"], rel(p), "repro_check_all_exact")

    # no-op sensitivity
    p = os.path.join(C, "noop", "noop_sensitivity.json")
    ns = load(p)
    diffs = []
    for c in ns["partA_cells_comparison"]:
        gran = "family" if c["granularity"] == "family" else "param"
        b = f"closed.noop.{gran}.{c['model']}"
        sel = f"partA_cells_comparison[granularity={c['granularity']},model={c['model']}]"
        L.num(f"{b}.full", c["committed_full"]["mean"], rel(p), f"{sel}.committed_full.mean")
        L.num(f"{b}.full_fold_sd", c["committed_full"]["sd_fold"], rel(p), f"{sel}.committed_full.sd_fold")
        L.num(f"{b}.noopfree", c["noop_free"]["mean"], rel(p), f"{sel}.noop_free.mean")
        L.num(f"{b}.noopfree_fold_sd", c["noop_free"]["sd_fold"], rel(p), f"{sel}.noop_free.sd_fold")
        L.num(f"{b}.noopfree_seed_sd", c["noop_free"]["sd_seed"], rel(p), f"{sel}.noop_free.sd_seed")
        L.num(f"{b}.diff", c["mean_diff_noop_free_minus_full"], rel(p), f"{sel}.mean_diff_noop_free_minus_full")
        diffs.append(abs(c["mean_diff_noop_free_minus_full"]))
        within = abs(c["mean_diff_noop_free_minus_full"]) < c["committed_full"]["sd_fold"]
        L.text(f"{b}.within_fold_sd", within, rel(p), f"|{sel}.mean_diff| < committed_full.sd_fold",
               "LEDGER-COMPUTED", display="yes" if within else "no")
        for cls, v in c["per_class_f1_renaming"].items():
            L.num(f"{b}.renaming_f1.{cls}.full", v["full"], rel(p), f"{sel}.per_class_f1_renaming.{cls}.full")
            L.num(f"{b}.renaming_f1.{cls}.noopfree", v["noop_free"], rel(p),
                  f"{sel}.per_class_f1_renaming.{cls}.noop_free")
    L.num("closed.noop.max_abs_diff", max(diffs), rel(p), "max |partA_cells_comparison[*].mean_diff_noop_free_minus_full|",
          "LEDGER-COMPUTED")
    for k, v in ns["partB_2x2_mean_macro_f1"].items():
        gran, m = k.split("|")
        g = "family" if gran == "family" else "param"
        for kk, x in v.items():
            L.num(f"closed.noop.{g}.{m}.x2.{kk.replace('|', '__')}", x, rel(p), f"partB_2x2_mean_macro_f1.{k}.{kk}")

    # MLP max_iter sensitivity and convergence
    p = os.path.join(C, "mlp2000", "mlp_maxiter_sensitivity.json")
    ms = load(p)["results"]
    for task, g in [("sub_provenance", "param"), ("provenance", "family")]:
        r = ms[task]
        b = f"closed.mlp2000.{g}"
        L.num(f"{b}.mean_200", r["committed_max_iter_200"]["mean"], rel(p), f"results.{task}.committed_max_iter_200.mean")
        L.num(f"{b}.mean_2000", r["max_iter_2000"]["mean"], rel(p), f"results.{task}.max_iter_2000.mean")
        L.num(f"{b}.fold_sd_2000", r["max_iter_2000"]["sd_fold"], rel(p), f"results.{task}.max_iter_2000.sd_fold")
        L.num(f"{b}.seed_sd_2000", r["max_iter_2000"]["sd_seed"], rel(p), f"results.{task}.max_iter_2000.sd_seed")
        L.num(f"{b}.diff", r["mean_diff_2000_minus_200"], rel(p), f"results.{task}.mean_diff_2000_minus_200")
        fl = r["fold_level_test"]
        L.add(f"{b}.wtl", f"{fl['folds_won']}/{fl['folds_tied']}/{fl['folds_lost']}",
              f"{fl['folds_won']}/{fl['folds_tied']}/{fl['folds_lost']}", rel(p), f"results.{task}.fold_level_test")
        L.add(f"{b}.wilcoxon_p", fl["wilcoxon_p_two_sided_exact"], pval(fl["wilcoxon_p_two_sided_exact"]), rel(p),
              f"results.{task}.fold_level_test.wilcoxon_p_two_sided_exact")
        for q in ["min", "max", "median"]:
            L.count(f"{b}.n_iter_{q}", r["n_iter_2000"][q], rel(p), f"results.{task}.n_iter_2000.{q}")
        L.count(f"{b}.n_hit_max_iter", r["n_iter_2000"]["n_hit_max_iter"], rel(p), f"results.{task}.n_iter_2000.n_hit_max_iter")
        L.count(f"{b}.n_fits", r["n_iter_2000"]["n_fits"], rel(p), f"results.{task}.n_iter_2000.n_fits")
    p = os.path.join(C, "convergence.json")
    cv = load(p)["seeds0_4_summary"]
    for k, v in cv.items():
        gran, m = k.split("|")
        b = f"closed.conv.{'family' if gran == 'family' else 'param'}.{m}"
        it = [x[0] if isinstance(x, list) else x for x in v["n_iter_"]]
        L.count(f"{b}.n_fits", v["n_fits"], rel(p), f"seeds0_4_summary.{k}.n_fits")
        L.count(f"{b}.n_iter_min", min(it), rel(p), f"min seeds0_4_summary.{k}.n_iter_")
        L.count(f"{b}.n_iter_max", max(it), rel(p), f"max seeds0_4_summary.{k}.n_iter_")
        L.count(f"{b}.n_hit_max_iter", v["n_hit_max_iter_or_warning"], rel(p),
                f"seeds0_4_summary.{k}.n_hit_max_iter_or_warning")
        if "n_early_stopped" in v:
            L.count(f"{b}.n_early_stopped", v["n_early_stopped"], rel(p), f"seeds0_4_summary.{k}.n_early_stopped")

    # hyperparameters
    p = os.path.join(C, "hyperparameters.json")
    hp = load(p)
    hn = hp["notes"]["hist_gbdt_early_stopping"]
    m_ = re.search(r"validation_fraction=([0-9.]+)", hn)
    L.num("hyper.hist_gbdt.validation_fraction", float(m_.group(1)), rel(p), "notes.hist_gbdt_early_stopping",
          "validation share held out by early stopping (not grouped by program)", nd=1)
    m_ = re.search(r"n_iter_no_change=(\d+)", hn)
    L.count("hyper.hist_gbdt.n_iter_no_change", int(m_.group(1)), rel(p), "notes.hist_gbdt_early_stopping")
    m_ = re.search(r"trains on (\d+) rows", hn)
    L.count("hyper.hist_gbdt.train_rows_per_fold", int(m_.group(1)), rel(p), "notes.hist_gbdt_early_stopping")
    for m, spec in hp["models"].items():
        L.text(f"hyper.{m}.steps", spec["pipeline_steps"], rel(p), f"models.{m}.pipeline_steps")
        for step in spec["steps"]:
            if step["step"] != "clf":
                continue
            L.text(f"hyper.{m}.class", step["class"].split(".")[-1], rel(p), f"models.{m}.steps[clf].class")
            for k, v in (step["non_default"] or {}).items():
                L.text(f"hyper.{m}.{k}", v["value"], rel(p), f"models.{m}.steps[clf].non_default.{k}.value",
                       note=f"scikit-learn default {v['default']}")
            for k, v in (step["set_explicitly_but_equal_to_default"] or {}).items():
                L.text(f"hyper.{m}.{k}", v["value"], rel(p),
                       f"models.{m}.steps[clf].set_explicitly_but_equal_to_default.{k}.value",
                       note="set explicitly, equal to the scikit-learn default")


def ablation(L: Ledger) -> None:
    """Fold-level paired feature-set ablation from the committed per-cell grids (LEDGER-COMPUTED)."""
    import aggregate_seeds as AS
    sets = ["no_obfuscation", "lexical_only", "structural", "semantic"]
    for gran, task, sub, models in [("family", "provenance", "pilot5", ["random_forest", "hist_gbdt", "logreg"]),
                                    ("param", "sub_provenance", "pilot5sub", ["random_forest", "hist_gbdt"])]:
        rows = []
        for m in models:
            def cells(fs):
                out = []
                for s in range(5):
                    pth = os.path.join(RES, sub, f"{task}_lomfo_{m}_{fs}_s{s}.json")
                    out.append(load(pth))
                return out
            base = cells("all")
            ratio = sorted({round(f["n_test"] / (c["n_rows"] - f["n_test"]), 6) for c in base for f in c["per_fold"]})
            if len(ratio) != 1:
                L.warn(f"ablation {gran} {m}: n_test/n_train not constant {ratio}")
            for fs in sets:
                other = cells(fs)
                fl = AS.paired_fold_level(base, other)
                per = {}
                for ca in base:
                    cb = [c for c in other if c["seed"] == ca["seed"]][0]
                    for i, (fa, fb) in enumerate(zip(ca["per_fold"], cb["per_fold"])):
                        per.setdefault(i, []).append(fa["macro_f1"] - fb["macro_f1"])
                dm = np.array([np.mean(per[i]) for i in sorted(per)])
                J = len(dm)
                var = float(np.var(dm, ddof=1))
                t = float(dm.mean() / math.sqrt((1.0 / J + ratio[0]) * var)) if var > 0 else float("nan")
                pnb = float(2 * sstats.t.sf(abs(t), J - 1)) if var > 0 else 1.0
                rows.append((m, fs, fl, dm, pnb))
        adj = holm([r[4] for r in rows])
        for (m, fs, fl, dm, pnb), ph in zip(rows, adj):
            b = f"ablation.{gran}.{m}.all_vs_{fs}"
            src = f"results/{sub}/{task}_lomfo_{m}_{{all,{fs}}}_s{{0..4}}.json"
            note = ("LEDGER-COMPUTED with scripts/aggregate_seeds.paired_fold_level and the Nadeau-Bengio "
                    "corrected t of results/v3/closed/scripts/paired_foldlevel.py (J = 5 domains, df 4); "
                    f"Holm over the {len(rows)} comparisons of this granularity")
            L.num(f"{b}.mean_diff", float(dm.mean()), src, "mean of seed-averaged per-fold differences (all minus set)", note)
            L.num(f"{b}.sd_diff", float(np.std(dm, ddof=1)), src, "sd(ddof=1) of the 5 per-fold differences", note)
            L.add(f"{b}.wtl", f"{fl['folds_won']}/{fl['folds_tied']}/{fl['folds_lost']}",
                  f"{fl['folds_won']}/{fl['folds_tied']}/{fl['folds_lost']}", src, "paired_fold_level", note)
            L.add(f"{b}.nb_p", pnb, pval(pnb), src, "Nadeau-Bengio corrected t", note)
            L.add(f"{b}.nb_p_holm", float(ph), pval(ph), src, "Holm-adjusted", note)
            L.add(f"{b}.wilcoxon_p", fl["wilcoxon_p_two_sided_exact"], pval(fl["wilcoxon_p_two_sided_exact"]), src,
                  "paired_fold_level.wilcoxon_p_two_sided_exact", note)


# --------------------------------------------------------------------------- #
# 7. semantics, evasion

def semantics(L: Ledger) -> None:
    S = os.path.join(V3, "semantics")
    p = os.path.join(S, "semantics_v3_summary.json")
    sm = load(p)
    for run, key in [("corpus_O0", "corpus_O0"), ("corpus_O2", "corpus_O2"), ("regen_repo", "regen"),
                     ("regen_copyA", "regen_copyA"), ("regen_copyB", "regen_copyB")]:
        r = sm["runs"][run]
        t = r["totals"]
        b = f"sem.{key}"
        for q in ["attempted", "preserved", "compile_failed", "behaviour_differs", "output_differs",
                  "exit_status_differs", "run_timeout", "transform_failed"]:
            L.count(f"{b}.{q}", t[q], rel(p), f"runs.{run}.totals.{q}")
        L.add(f"{b}.preserved_frac", t["preserved"], f"{t['preserved']}/{t['attempted']}", rel(p),
              f"runs.{run}.totals.preserved/attempted")
        L.text(f"{b}.flags", " ".join(r["compiler"]["flags"]), rel(p), f"runs.{run}.compiler.flags",
               display=r"\code{" + " ".join(r["compiler"]["flags"]) + "}")
        L.text(f"{b}.compiler", r["compiler"]["version"], rel(p), f"runs.{run}.compiler.version")
        if r.get("replicate_indices"):
            L.text(f"{b}.replicates", r["replicate_indices"], rel(p), f"runs.{run}.replicate_indices",
                   display=" and ".join(str(x) for x in r["replicate_indices"]))
        pp = os.path.join(S, r["file"])
        per = load(pp)["per_parameterisation"]
        for par, v in per.items():
            L.count(f"{b}.param.{par}.attempted", v["attempted"], rel(pp), f"per_parameterisation.{par}.attempted")
            L.count(f"{b}.param.{par}.preserved", v["preserved"], rel(pp), f"per_parameterisation.{par}.preserved")
        L.count(f"{b}.usable_programs", r["usable_programs"], rel(p), f"runs.{run}.usable_programs")
    na = sm["noop_artifacts"]
    L.count("sem.noop.byte_identical", na["totals"]["byte_identical"], rel(p), "noop_artifacts.totals.byte_identical")
    L.count("sem.noop.whitespace_identical", na["totals"]["whitespace_identical"], rel(p),
            "noop_artifacts.totals.whitespace_identical")
    for par, v in na["per_parameterisation"].items():
        L.count(f"sem.noop.param.{par}", v["byte_identical"], rel(p), f"noop_artifacts.per_parameterisation.{par}.byte_identical")
    for par, v in sm["regenerated_r8_r9_hashes"]["identical_to_input_per_param"].items():
        L.count(f"sem.regen.noop.param.{par}", v, rel(p), f"regenerated_r8_r9_hashes.identical_to_input_per_param.{par}")
    for k in ["regen_r0to7_vs_pilot_corpus_copyA", "regen_r0to7_vs_pilot_corpus_copyB"]:
        L.count(f"sem.{k}.identical", sm[k]["identical"], rel(p), f"{k}.identical")
        L.count(f"sem.{k}.compared", sm[k]["compared"], rel(p), f"{k}.compared")
    L.text("sem.regen_identical_across_locations", sm["regenerate_reports_identical_across_locations"], rel(p),
           "regenerate_reports_identical_across_locations")
    # committed v2 checks (standard output only)
    for fn, key in [("semantics_pilot_corpus.json", "sem.v2_corpus"), ("semantics_reference.json", "sem.v2_reference")]:
        pc = os.path.join(RES, fn)
        d = load(pc)
        att = sum(v["attempted"] for v in d["per_parameterisation"].values())
        pre = sum(v["preserved"] for v in d["per_parameterisation"].values())
        L.count(f"{key}.attempted", att, rel(pc), "sum per_parameterisation[*].attempted",
                "committed check; compared standard output only")
        L.count(f"{key}.preserved", pre, rel(pc), "sum per_parameterisation[*].preserved",
                "committed check; compared standard output only")
        for par, v in d["per_parameterisation"].items():
            L.count(f"{key}.param.{par}.attempted", v["attempted"], rel(pc), f"per_parameterisation.{par}.attempted",
                    "committed check; compared standard output only")
            L.count(f"{key}.param.{par}.preserved", v["preserved"], rel(pc), f"per_parameterisation.{par}.preserved",
                    "committed check; compared standard output only")


def evasion(L: Ledger) -> None:
    p = os.path.join(V3, "evasion", "evasion_diagnostics.json")
    if not os.path.exists(p):
        L.warn("evasion_diagnostics.json copy missing; no evasion entries")
        return
    e = load(p)
    src = rel(p)
    note = "AUDIT-GENERATED re-analysis copied into the repository"
    L.count("evasion.n_controlled", len(e["attacker_controlled"]), src, "attacker_controlled", note)
    L.count("evasion.n_features", e["shared_features"], src, "shared_features", note)
    L.text("evasion.controlled", e["attacker_controlled"], src, "attacker_controlled", note,
           display=", ".join(r"\code{" + tex_escape(x) + "}" for x in e["attacker_controlled"]))
    L.num("evasion.controlled_importance_share", e["narrow_importance"]["controlled_importance_share"], src,
          "narrow_importance.controlled_importance_share", note)
    for f, v in e["narrow_importance"]["controlled_features"].items():
        L.num(f"evasion.importance.{f}", v["importance"], src, f"narrow_importance.controlled_features.{f}.importance", note)
        L.count(f"evasion.importance.{f}.rank", v["rank_of_61"], src, f"narrow_importance.controlled_features.{f}.rank_of_61", note)
    for scope in ["unrestricted", "restricted"]:
        g = e[f"narrow_{scope}_greedy"]
        s = e[f"narrow_{scope}_stronger_attack"]
        for bud, v in g["success_by_budget_reproduced"].items():
            L.num(f"evasion.{scope}.greedy.success.{bud.replace('.', '_')}", v, src,
                  f"narrow_{scope}_greedy.success_by_budget_reproduced.{bud}", note)
        for bud, v in s["success_by_budget"].items():
            L.num(f"evasion.{scope}.stronger.success.{bud.replace('.', '_')}", v, src,
                  f"narrow_{scope}_stronger_attack.success_by_budget.{bud}", note)
        for r, n in g["stop_reasons"].items():
            L.count(f"evasion.{scope}.greedy.stop.{r}", n, src, f"narrow_{scope}_greedy.stop_reasons.{r}", note)
        L.count(f"evasion.{scope}.greedy.plateau_at_step0", g["plateau_at_step0"], src,
                f"narrow_{scope}_greedy.plateau_at_step0", note)
        L.num(f"evasion.{scope}.greedy.max_displacement", g["max_displacement_any_trial"], src,
              f"narrow_{scope}_greedy.max_displacement_any_trial", note)
        L.num(f"evasion.{scope}.greedy.max_possible", g["max_possible_displacement_30_steps"], src,
              f"narrow_{scope}_greedy.max_possible_displacement_30_steps", note, nd=1)
        L.count(f"evasion.{scope}.n_attacked", s["n_attacked"], src, f"narrow_{scope}_stronger_attack.n_attacked", note)
        L.num(f"evasion.{scope}.stronger.median_min_norm", s["median_min_norm_when_successful"], src,
              f"narrow_{scope}_stronger_attack.median_min_norm_when_successful", note)
    ca = e["narrow_closed_accuracy_controlled_features_only_grouped5fold"]
    L.num("evasion.controlled_only_accuracy", ca["mean"], src,
          "narrow_closed_accuracy_controlled_features_only_grouped5fold.mean", note)
    L.num("evasion.controlled_only_chance", ca["chance_4_classes"], src,
          "narrow_closed_accuracy_controlled_features_only_grouped5fold.chance_4_classes", note, nd=2)
    pc = os.path.join(RES, "evasion_matched.json")
    c = load(pc)
    L.num("evasion.committed.narrow.closed_acc", c["unrestricted"]["narrow"]["closed_accuracy_heldout"], rel(pc),
          "unrestricted.narrow.closed_accuracy_heldout", "committed report")
    for scope in ["unrestricted", "restricted"]:
        for bud, v in c[scope]["narrow"]["success_by_budget"].items():
            L.num(f"evasion.committed.{scope}.success.{bud.replace('.', '_')}", v, rel(pc),
                  f"{scope}.narrow.success_by_budget.{bud}", "committed report")
        if abs(c[scope]["narrow"]["success_by_budget"]["5"] -
               e[f"narrow_{scope}_greedy"]["success_by_budget_reproduced"]["5"]) > 1e-9:
            L.warn(f"evasion re-analysis does not reproduce the committed {scope} greedy success")


# --------------------------------------------------------------------------- #

def write(L: Ledger) -> None:
    os.makedirs(OUT, exist_ok=True)
    keys = sorted(L.d)
    with open(os.path.join(OUT, "ledger.json"), "w") as fh:
        json.dump({k: L.d[k] for k in keys}, fh, indent=1, sort_keys=True)
    with open(os.path.join(OUT, "ledger.txt"), "w") as fh:
        fh.write("# ObfuScope manuscript number ledger (AUDIT-GENERATED by scripts/manuscript_v3/make_ledger.py)\n")
        fh.write("# key = display  [source: file::path]   (display is LaTeX-ready; paths are relative to the\n")
        fh.write("# repository root code/obfuscope-corrected; 'LEDGER-COMPUTED' entries are derived here)\n")
        fh.write(f"# {len(keys)} keys; {len(L.warnings)} consistency warnings"
                 + (":" if L.warnings else "") + "\n")
        for wmsg in L.warnings:
            fh.write(f"# WARNING: {wmsg}\n")
        for k in keys:
            e = L.d[k]
            fh.write(f"{k} = {e['display']}  [source: {e['source']}::{e['path']}]"
                     + (f"  # {e['note']}" if e["note"] else "") + "\n")
    with open(os.path.join(OUT, "ledger.csv"), "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["key", "value", "display", "source", "path", "note"])
        for k in keys:
            e = L.d[k]
            v = e["value"]
            w.writerow([k, json.dumps(v) if isinstance(v, (list, dict, bool)) or v is None else v,
                        e["display"], e["source"], e["path"], e["note"]])


def main() -> int:
    L = Ledger()
    ensure_copies(L)
    environment(L)
    corpus(L)
    features(L)
    code_constants(L)
    gate(L)
    openset(L)
    sibling(L)
    simulation(L)
    closed(L)
    ablation(L)
    semantics(L)
    evasion(L)
    write(L)
    print(f"ledger: {len(L.d)} keys -> {OUT}")
    for w in L.warnings:
        print("WARNING:", w)
    return 0


if __name__ == "__main__":
    sys.exit(main())
