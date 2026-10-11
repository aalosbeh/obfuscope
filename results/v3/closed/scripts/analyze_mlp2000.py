"""AUDIT-GENERATED (run:closedset-v3). MLP max_iter=2000 against the committed max_iter=200 cells (Table 20, Table 19)."""
from __future__ import annotations

import json
import os
import sys

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
CLOSED = os.path.dirname(HERE)
REPO = os.path.abspath(os.path.join(CLOSED, "..", "..", ".."))
sys.path.insert(0, os.path.join(REPO, "scripts"))
import aggregate_seeds as AS  # noqa: E402

ORIG = sys.argv[1]
MS = {"sub_provenance": {"ref": "MS L679 (Table 20)", "mean": 0.6834, "sd_fold": 0.0960, "sd_seed": 0.0131,
                         "min": 0.4920, "max": 0.7973},
      "provenance": {"ref": "MS L668 (Table 19, domain holdout)", "mean": 0.8233, "sd_fold": 0.0629,
                     "sd_seed": 0.0178, "min": 0.7259, "max": 0.8975}}
NEIGHBOURS = {"sub_provenance": ("pilot5sub", ["logreg", "svm_rbf", "knn"]),
              "provenance": ("pilot5", ["logreg", "svm_rbf", "knn"])}


def main():
    out = {"label": "AUDIT-GENERATED run:closedset-v3",
           "wrapper": "results/v3/closed/scripts/mlp_maxiter_wrapper.py (models.py unchanged; only max_iter differs)",
           "results": {}}
    for task in ("sub_provenance", "provenance"):
        sub, neigh = NEIGHBOURS[task]
        new = [json.load(open(os.path.join(CLOSED, "mlp2000", f"{task}_lomfo_mlp_maxiter2000_all_s{s}.json")))
               for s in range(5)]
        old = [json.load(open(os.path.join(ORIG, sub, f"{task}_lomfo_mlp_all_s{s}.json"))) for s in range(5)]
        dn, do = AS.decompose(new), AS.decompose(old)
        fits = [f for c in new for f in c["audit_wrapper"]["per_fold_fit"]]
        diffs = np.array([[fn["macro_f1"] - fo["macro_f1"] for fn, fo in zip(cn["per_fold"], co["per_fold"])]
                          for cn, co in zip(new, old)])
        fold_mean = diffs.mean(axis=0)
        others = {m: AS.decompose([json.load(open(os.path.join(ORIG, sub, f"{task}_lomfo_{m}_all_s{s}.json")))
                                   for s in range(5)])["mean"] for m in neigh}
        out["results"][task] = {
            "ms": MS[task],
            "committed_max_iter_200": {k: do[k] for k in ("mean", "sd_fold", "sd_seed", "min_fold", "max_fold", "per_seed_mean")},
            "max_iter_2000": {k: dn[k] for k in ("mean", "sd_fold", "sd_seed", "min_fold", "max_fold", "per_seed_mean")},
            "mean_diff_2000_minus_200": round(dn["mean"] - do["mean"], 4),
            "paired_per_fold_seed_avg_diff": [round(float(v), 4) for v in fold_mean],
            "paired_diff_all_25": {"mean": round(float(diffs.mean()), 4), "sd": round(float(diffs.std(ddof=1)), 4),
                                   "n_pos": int((diffs > 1e-12).sum()), "n_zero": int((np.abs(diffs) <= 1e-12).sum()),
                                   "n_neg": int((diffs < -1e-12).sum())},
            "fold_level_test": AS.paired_fold_level(new, old),
            "n_iter_2000": {"min": min(f["n_iter_"] for f in fits), "max": max(f["n_iter_"] for f in fits),
                            "median": float(np.median([f["n_iter_"] for f in fits])),
                            "n_hit_max_iter": sum(f["hit_max_iter"] for f in fits),
                            "n_convergence_warning": sum(f["convergence_warning"] for f in fits),
                            "n_fits": len(fits)},
            "neighbour_means_committed": others,
        }
        r = out["results"][task]
        print(task, "200:", do["mean"], do["sd_fold"], do["sd_seed"], "| 2000:", dn["mean"], dn["sd_fold"], dn["sd_seed"],
              dn["min_fold"], dn["max_fold"], "| diff", r["mean_diff_2000_minus_200"], "| fold diffs",
              r["paired_per_fold_seed_avg_diff"], r["paired_diff_all_25"], "| n_iter", r["n_iter_2000"],
              "| neighbours", others, "| fold-level", {k: r["fold_level_test"][k] for k in
              ("folds_won", "folds_tied", "folds_lost", "wilcoxon_p_two_sided_exact")} if "skipped" not in r["fold_level_test"] else r["fold_level_test"])
    with open(os.path.join(CLOSED, "mlp2000", "mlp_maxiter_sensitivity.json"), "w") as fh:
        json.dump(out, fh, indent=2)


if __name__ == "__main__":
    main()
