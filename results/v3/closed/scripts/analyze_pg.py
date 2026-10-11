"""AUDIT-GENERATED (run:closedset-v3). Partition variance under grouped_cv --permute-groups.

Inputs: closed/pg/*.json (35 cells), closed/pg_aggregate.json (aggregate_seeds.py),
committed cells (obfuscope-main/results/pilot5) for the fixed partition grid.
Outputs: closed/pg_partition_variance.json, closed/pg_vs_table19.csv,
closed/pg_paired_corrected.csv.

Partition check: every seed's 5 test folds must cover the 30 programs exactly
once; partitions are compared across seeds, across models at one seed, and
against the default (seed invariant) partition.

Corrected repeated k-fold t test (Nadeau and Bengio 2003; Bouckaert and Frank
2004): with r = 5 partitions x k = 5 folds, d = a - b paired on (seed, fold),
t = mean(d) / sqrt((1/(r k) + n_test/n_train) var(d)), df = r k - 1 = 24.
"""
from __future__ import annotations

import csv
import itertools
import json
import os
import sys

import numpy as np
from scipy import stats

HERE = os.path.dirname(os.path.abspath(__file__))
CLOSED = os.path.dirname(HERE)
REPO = os.path.abspath(os.path.join(CLOSED, "..", "..", ".."))
sys.path.insert(0, os.path.join(REPO, "scripts"))
import aggregate_seeds as AS  # noqa: E402

ORIG = sys.argv[1] if len(sys.argv) > 1 else None
MODELS = ["hist_gbdt", "random_forest", "extra_trees", "svm_rbf", "logreg", "mlp", "knn"]
# Table 19 grouped_cv columns, MS L663-669: mean, fold sd, seed sd, min, max
TABLE19_GCV = {
    "hist_gbdt": (0.9601, 0.0357, 0.0009, 0.9181, 1.0000, 663),
    "random_forest": (0.9583, 0.0318, 0.0030, 0.9187, 1.0000, 664),
    "extra_trees": (0.9440, 0.0368, 0.0048, 0.8883, 0.9913, 665),
    "svm_rbf": (0.9013, 0.0443, 0.0000, 0.8526, 0.9569, 666),
    "logreg": (0.8859, 0.0919, 0.0000, 0.7333, 0.9548, 667),
    "mlp": (0.8641, 0.0870, 0.0159, 0.7086, 0.9611, 668),
    "knn": (0.8356, 0.0713, 0.0000, 0.7729, 0.9548, 669),
}


def load(dirpath, prefix):
    cells = {}
    for m in MODELS:
        cells[m] = []
        for s in range(5):
            with open(os.path.join(dirpath, f"{prefix}_{m}_all_s{s}.json")) as fh:
                cells[m].append(json.load(fh))
    return cells


def main():
    pg = load(os.path.join(CLOSED, "pg"), "provenance_grouped_cv")
    fixed = load(os.path.join(ORIG, "pilot5"), "provenance_grouped_cv")
    with open(os.path.join(CLOSED, "paired_foldlevel_meta.json")) as fh:
        default_part = [tuple(x) for x in json.load(fh)["settings"]["family|grouped_cv"]
                        ["held_out_groups_by_fold_index"]]

    # ---- partitions
    part = {}
    for s in range(5):
        per_model = {m: tuple(tuple(f["test_groups"]) for f in pg[m][s]["per_fold"]) for m in MODELS}
        assert len(set(per_model.values())) == 1, f"models disagree on partition at seed {s}"
        p = per_model["hist_gbdt"]
        allg = [g for fold in p for g in fold]
        assert len(allg) == 30 and len(set(allg)) == 30
        part[s] = p
    as_sets = {s: frozenset(frozenset(f) for f in part[s]) for s in part}
    default_set = frozenset(frozenset(f) for f in default_part)
    distinct_folds = {frozenset(f) for s in part for f in part[s]}

    def coassign(p):
        lab = {g: i for i, f in enumerate(p) for g in f}
        gs = sorted(lab)
        return {(a, b) for a, b in itertools.combinations(gs, 2) if lab[a] == lab[b]}

    pair_agree = {}
    for s1, s2 in itertools.combinations(range(5), 2):
        c1, c2 = coassign(part[s1]), coassign(part[s2])
        pair_agree[f"{s1}-{s2}"] = {"shared_fold_count": len(set(as_sets[s1]) & set(as_sets[s2])),
                                    "coassigned_pairs_jaccard": round(len(c1 & c2) / len(c1 | c2), 4)}
    # stratification: per fold test label counts identical?
    strat = sorted({tuple(tuple(row) for row in np.array(f["confusion"]).sum(axis=1, keepdims=True).tolist())
                    for s in range(5) for f in pg["hist_gbdt"][s]["per_fold"]})
    partitions = {
        "n_seeds": 5,
        "n_distinct_partitions": len(set(as_sets.values())),
        "any_equals_default_partition": [s for s in part if as_sets[s] == default_set],
        "n_distinct_test_folds_over_25": len(distinct_folds),
        "partition_by_seed": {s: [list(f) for f in part[s]] for s in part},
        "default_partition_seed_invariant": [list(f) for f in default_part],
        "pairwise_partition_similarity": pair_agree,
        "models_share_partition_within_seed": True,
        "per_fold_test_class_counts_observed": [list(x) for x in strat],
    }

    # ---- decomposition vs Table 19
    rows = []
    for m in MODELS:
        d_pg = AS.decompose(pg[m]); d_fx = AS.decompose(fixed[m])
        t = TABLE19_GCV[m]
        rows.append({
            "model": m, "ms_line": f"MS L{t[5]}",
            "table19_mean": t[0], "table19_fold_sd": t[1], "table19_seed_sd": t[2],
            "table19_min": t[3], "table19_max": t[4],
            "committed_fixed_mean": d_fx["mean"], "committed_fixed_fold_sd": d_fx["sd_fold"],
            "committed_fixed_seed_sd": d_fx["sd_seed"],
            "table19_matches_committed": (abs(d_fx["mean"] - t[0]) < 5e-5 and abs(d_fx["sd_fold"] - t[1]) < 5e-5
                                          and abs(d_fx["sd_seed"] - t[2]) < 5e-5
                                          and abs(d_fx["min_fold"] - t[3]) < 5e-5
                                          and abs(d_fx["max_fold"] - t[4]) < 5e-5),
            "pg_mean": d_pg["mean"], "pg_fold_sd": d_pg["sd_fold"],
            "pg_seed_partition_sd": d_pg["sd_seed"], "pg_sd_total_25": d_pg["sd_total"],
            "pg_min": d_pg["min_fold"], "pg_max": d_pg["max_fold"],
            "pg_per_seed_mean": ";".join(f"{v:.4f}" for v in d_pg["per_seed_mean"]),
            "pg_minus_table19_mean": round(d_pg["mean"] - t[0], 4),
            "seed_sd_over_fold_sd_pg": round(d_pg["sd_seed"] / d_pg["sd_fold"], 3),
        })
    rank_t19 = [r["model"] for r in sorted(rows, key=lambda r: -r["table19_mean"])]
    rank_pg = [r["model"] for r in sorted(rows, key=lambda r: -r["pg_mean"])]
    with open(os.path.join(CLOSED, "pg_vs_table19.csv"), "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0])); w.writeheader(); w.writerows(rows)

    # ---- pairwise corrected repeated CV t (all 21 pairs) + fold level from aggregate_seeds
    means = {r["model"]: r["pg_mean"] for r in rows}
    prow = []
    for m1, m2 in itertools.combinations(MODELS, 2):
        a, b = (m1, m2) if means[m1] >= means[m2] else (m2, m1)
        d = []
        for s in range(5):
            for fa, fb in zip(pg[a][s]["per_fold"], pg[b][s]["per_fold"]):
                assert fa["test_groups"] == fb["test_groups"]
                d.append(fa["macro_f1"] - fb["macro_f1"])
        d = np.array(d); n = d.size; v = float(np.var(d, ddof=1))
        t_c = float(d.mean() / np.sqrt((1 / n + 0.25) * v)) if v > 0 else float("nan")
        p_c = float(2 * stats.t.sf(abs(t_c), n - 1)) if v > 0 else float("nan")
        fl = AS.paired_fold_level(pg[a], pg[b])
        prow.append({"model_a": a, "model_b": b, "mean_a": means[a], "mean_b": means[b],
                     "n_pairs": n, "mean_diff": round(float(d.mean()), 4),
                     "sd_diff": round(float(np.sqrt(v)), 4),
                     "wins": fl["folds_won"], "ties": fl["folds_tied"], "losses": fl["folds_lost"],
                     "fold_identity": fl["fold_identity"],
                     "sign_p_naive_25": fl["sign_test_p_two_sided"],
                     "wilcoxon_p_naive_25": fl["wilcoxon_p_two_sided_exact"],
                     "corrected_rcv_t": round(t_c, 4), "corrected_rcv_df": n - 1,
                     "corrected_rcv_p": round(p_c, 6)})
    ps = np.array([r["corrected_rcv_p"] for r in prow]); order = np.argsort(ps); run = 0.0
    adj = np.empty(len(ps))
    for rank, i in enumerate(order):
        run = max(run, min(1.0, (len(ps) - rank) * ps[i])); adj[i] = run
    for r, v in zip(prow, adj):
        r["corrected_rcv_p_holm21"] = round(float(v), 6)
    with open(os.path.join(CLOSED, "pg_paired_corrected.csv"), "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=list(prow[0])); w.writeheader(); w.writerows(prow)

    out = {"label": "AUDIT-GENERATED run:closedset-v3",
           "command": "python -m obfuscope.experiment --data data/features_pilot.csv --task provenance "
                      "--protocol grouped_cv --model <m> --feature-set all --seed <s> --n-splits 5 "
                      "--permute-groups (s = 0..4)",
           "partitions": partitions, "per_model": rows,
           "rank_table19": rank_t19, "rank_permuted": rank_pg,
           "paired_corrected_rcv": prow,
           "note": ("sd_seed under --permute-groups mixes partition and estimator randomness; for "
                    "the deterministic svm_rbf, logreg and knn it is partition variance alone. "
                    "Sign/Wilcoxon over the 25 distinct folds treat folds from overlapping "
                    "partitions as independent and are anti-conservative; the corrected repeated "
                    "CV t is the primary test.")}
    with open(os.path.join(CLOSED, "pg_partition_variance.json"), "w") as fh:
        json.dump(out, fh, indent=2)
    print("distinct partitions", partitions["n_distinct_partitions"], "equal default:",
          partitions["any_equals_default_partition"], "distinct folds", len(distinct_folds))
    print(json.dumps(pair_agree)); print("class counts per test fold", partitions["per_fold_test_class_counts_observed"])
    for r in rows:
        print(f"{r['model']:13s} T19 {r['table19_mean']:.4f}/{r['table19_fold_sd']:.4f}/{r['table19_seed_sd']:.4f} "
              f"match={r['table19_matches_committed']}  PG {r['pg_mean']:.4f}/{r['pg_fold_sd']:.4f}/"
              f"{r['pg_seed_partition_sd']:.4f} [{r['pg_min']:.4f},{r['pg_max']:.4f}] diff {r['pg_minus_table19_mean']:+.4f} "
              f"per-seed {r['pg_per_seed_mean']}")
    print("rank T19", rank_t19); print("rank PG ", rank_pg)
    for r in prow:
        print(f"{r['model_a']:13s} {r['model_b']:13s} d={r['mean_diff']:+.4f} {r['wins']}/{r['ties']}/{r['losses']} "
              f"t={r['corrected_rcv_t']:.3f} p={r['corrected_rcv_p']:.4f} holm={r['corrected_rcv_p_holm21']:.4f}")


if __name__ == "__main__":
    main()
