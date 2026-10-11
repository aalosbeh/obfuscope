"""AUDIT-GENERATED (run:gate-v3). Consistent-protocol headroom for diagnostic 4.

The committed gate computes the best single feature macro F1 under its own
probe protocol (GroupShuffleSplit(3, 0.3) grouped by sample_id) and divides
by F1_full taken from the headline closed set protocol (lomfo, random forest,
5 folds x 5 seeds). This script re-measures the best-k probe scores under the
headline protocol itself so numerator and denominator share one protocol:

  splits   obfuscope.protocols.iter_splits("lomfo", families=malware_family,
           y=label, n_splits=5, seed=s) for s in 0..4  (as experiment._run_closed)
  features obfuscope.experiment._load(..., "all")  (61 columns, NaN/inf -> 0)
  probe    DecisionTreeClassifier(max_depth=min(8, n_classes + 2),
           random_state=s), one per feature (the gate's depth rule)
  metric   f1_score(average="macro", labels=sorted classes, zero_division=0)
           per fold, mean over the 25 (seed, fold) measurements, as the
           headline cells are aggregated
  k = 1    exhaustive; k = 2, 3 greedy forward selection from the 24 strongest
           singles (the gate's rule). Selection and scoring use the same folds,
           exactly as in the gate, so best-k is optimistic.

R = (F1_full - F1_best1) / (F1_full - 1/n_classes) with F1_full = 0.9542
(technique) / 0.8045 (sub_technique), the manuscript's random forest lomfo
values (MS L664, L676; results/closed_set_five_seed*.json).

Also reported: the probe tree on all 61 features under the same protocol and
R against it, and per seed best-1 values.
"""
from __future__ import annotations

import json
import os
import sys

import numpy as np

ROOT = os.environ.get("OBFUSCOPE_REPO", os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "..")))
sys.path.insert(0, os.path.join(ROOT, "src"))
from obfuscope.experiment import _load  # noqa: E402
from obfuscope.protocols import iter_splits  # noqa: E402
from sklearn.metrics import f1_score  # noqa: E402
from sklearn.tree import DecisionTreeClassifier  # noqa: E402

SEEDS = [0, 1, 2, 3, 4]
F1_FULL = {"technique": 0.9542, "sub_technique": 0.8045}
POOL = 24


def run(data_path: str, label: str, f1_full: float) -> dict:
    df, X, cols = _load(data_path, "all")
    y = df[label].astype(str).to_numpy()
    fam = df["malware_family"].to_numpy()
    classes = sorted(set(y.tolist()))
    n_classes = len(classes)
    depth = min(8, n_classes + 2)
    split_sets = {s: iter_splits("lomfo", y=y, families=fam, n_splits=5, seed=s)
                  for s in SEEDS}
    held_out = {s: [sorted(set(fam[sp.test_idx].tolist())) for sp in split_sets[s]]
                for s in SEEDS}

    def score(idx):
        per_seed = {}
        allv = []
        for s in SEEDS:
            vals = []
            for sp in split_sets[s]:
                clf = DecisionTreeClassifier(max_depth=depth, random_state=s)
                clf.fit(X[sp.train_idx][:, idx], y[sp.train_idx])
                pred = clf.predict(X[sp.test_idx][:, idx])
                vals.append(float(f1_score(y[sp.test_idx], pred, average="macro",
                                           labels=classes, zero_division=0)))
            per_seed[s] = float(np.mean(vals))
            allv += vals
        return float(np.mean(allv)), per_seed, allv

    singles = {}
    single_seed = {}
    single_folds = {}
    for j, c in enumerate(cols):
        m, ps, allv = score([j])
        singles[c] = m
        single_seed[c] = ps
        single_folds[c] = allv
    ranked = sorted(singles.items(), key=lambda kv: kv[1], reverse=True)
    best_feat, best1 = ranked[0]
    pool = [f for f, _ in ranked[:POOL]]
    col = {c: i for i, c in enumerate(cols)}
    chosen = [best_feat]
    trace = [{"k": 1, "features": list(chosen), "macro_f1": round(best1, 4)}]
    for k in (2, 3):
        gains = []
        for f in pool:
            if f in chosen:
                continue
            m, _, _ = score([col[c] for c in chosen + [f]])
            gains.append((m, f))
        m, f = max(gains)
        chosen.append(f)
        trace.append({"k": k, "features": list(chosen), "macro_f1": round(m, 4)})
    full_m, full_ps, full_folds = score(list(range(len(cols))))
    chance = 1.0 / n_classes
    R = (f1_full - best1) / (f1_full - chance)
    R_probe = (full_m - best1) / (full_m - chance) if full_m - chance > 1e-9 else None

    # Best-1 if the best feature were chosen per seed (it is not; reported for
    # stability only).
    per_seed_best = {}
    for s in SEEDS:
        fs, v = max(((c, single_seed[c][s]) for c in cols), key=lambda t: t[1])
        per_seed_best[str(s)] = {"feature": fs, "macro_f1": round(v, 4),
                                 "R": round((f1_full - v) / (f1_full - chance), 4)}
    bf = np.array(single_folds[best_feat])
    return {
        "label": label,
        "n_rows": int(len(df)),
        "n_features": len(cols),
        "n_classes": n_classes,
        "chance_macro_f1": round(chance, 4),
        "probe_depth": depth,
        "lomfo_held_out_domains_by_seed": {str(s): held_out[s] for s in SEEDS},
        "best_feature": best_feat,
        "best_1_macro_f1": round(best1, 4),
        "best_1_fold_sd": round(float(bf.std(ddof=1)), 4),
        "best_1_min_fold": round(float(bf.min()), 4),
        "best_1_max_fold": round(float(bf.max()), 4),
        "best_1_per_seed_mean": {str(s): round(single_seed[best_feat][s], 4) for s in SEEDS},
        "per_seed_best_single": per_seed_best,
        "top_five": [{"feature": f, "macro_f1": round(v, 4)} for f, v in ranked[:5]],
        "greedy_trace": trace,
        "full_set_probe_macro_f1": round(full_m, 4),
        "full_set_probe_per_seed": {str(s): round(v, 4) for s, v in full_ps.items()},
        "F1_full_supplied": f1_full,
        "F1_full_source": "manuscript random_forest lomfo mean of 25 (MS L664 / L676)",
        "R_consistent_protocol": round(R, 4),
        "R_vs_probe_full_same_protocol": round(R_probe, 4) if R_probe is not None else None,
        "all_singles": {f: round(v, 4) for f, v in ranked},
    }


def main():
    data = os.path.join(ROOT, "data/features_pilot.csv")
    out = {
        "label": "AUDIT-GENERATED consistent-protocol headroom (run:gate-v3)",
        "protocol": ("lomfo = StratifiedGroupKFold(n_splits=5, shuffle=True, "
                     "random_state=seed) over malware_family, seeds 0-4; probe "
                     "DecisionTreeClassifier(max_depth=min(8, n_classes+2), "
                     "random_state=seed); macro F1 per fold with all labels, "
                     "zero_division=0; mean over 25 measurements"),
        "results": {},
    }
    for lab in ("technique", "sub_technique"):
        out["results"][lab] = run(data, lab, F1_FULL[lab])
        r = out["results"][lab]
        print(lab, r["best_feature"], r["best_1_macro_f1"], "R", r["R_consistent_protocol"],
              "trace", [(t["k"], t["macro_f1"]) for t in r["greedy_trace"]],
              "probe full", r["full_set_probe_macro_f1"])
    path = os.path.join(ROOT, "results/v3/gate/consistent_protocol_R.json")
    with open(path, "w") as fh:
        json.dump(out, fh, indent=2)
    print("written", path)


if __name__ == "__main__":
    main()
