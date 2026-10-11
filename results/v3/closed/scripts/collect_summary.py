"""AUDIT-GENERATED (run:closedset-v3). Collect the key numbers of closed/ into closed/summary_v3_closed.json."""
import csv
import hashlib
import json
import os

HERE = os.path.dirname(os.path.abspath(__file__))
C = os.path.dirname(HERE)


def j(p):
    with open(os.path.join(C, p)) as fh:
        return json.load(fh)


def main():
    pg = j("pg_partition_variance.json")
    noop = j("noop/noop_sensitivity.json")
    nr = j("noop/noop_rows.json")
    mlp = j("mlp2000/mlp_maxiter_sensitivity.json")
    conv = j("convergence.json")
    hp = j("hyperparameters.json")
    rep = j("repro_check/_compare.json")
    with open(os.path.join(C, "paired_foldlevel.csv")) as fh:
        pf = list(csv.DictReader(fh))
    with open(os.path.join(C, "pg_paired_corrected.csv")) as fh:
        pgp = list(csv.DictReader(fh))

    def count(rows, key, thr=0.05):
        return sum(float(r[key]) < thr for r in rows if r[key] not in ("nan", ""))

    by_setting = {}
    for r in pf:
        k = f"{r['granularity']}|{r['protocol']}"
        s = by_setting.setdefault(k, {"n_pairs": 0, "n_5_of_5": 0, "n_sign_p_lt_0.05": 0,
                                      "n_wilcoxon_p_lt_0.05": 0, "n_nb_p_lt_0.05": 0,
                                      "n_nb_holm_lt_0.05": 0, "nb_holm_significant": []})
        s["n_pairs"] += 1
        s["n_5_of_5"] += int(r["wins"]) == 5
        s["n_sign_p_lt_0.05"] += float(r["sign_p_exact"]) < 0.05
        s["n_wilcoxon_p_lt_0.05"] += float(r["wilcoxon_p_exact"]) < 0.05
        s["n_nb_p_lt_0.05"] += float(r["nb_p"]) < 0.05
        if float(r["nb_p_holm21"]) < 0.05:
            s["n_nb_holm_lt_0.05"] += 1
            s["nb_holm_significant"].append(f"{r['model_a']}>{r['model_b']} (p_holm={r['nb_p_holm21']})")
    out = {
        "label": "AUDIT-GENERATED run:closedset-v3",
        "repro_check_all_exact": all(r["max_abs_fold_diff"] == 0 and r["identical_confusions"] for r in rep["rows"]),
        "repro_check_n_cells": len(rep["rows"]),
        "task1_partition_variance": {
            "n_distinct_partitions": pg["partitions"]["n_distinct_partitions"],
            "n_distinct_test_folds": pg["partitions"]["n_distinct_test_folds_over_25"],
            "seeds_equal_to_default_partition": pg["partitions"]["any_equals_default_partition"],
            "per_model": [{k: r[k] for k in ("model", "table19_mean", "table19_fold_sd", "table19_seed_sd",
                                             "table19_matches_committed", "pg_mean", "pg_fold_sd",
                                             "pg_seed_partition_sd", "pg_min", "pg_max",
                                             "pg_minus_table19_mean")} for r in pg["per_model"]],
            "rank_table19": pg["rank_table19"], "rank_permuted": pg["rank_permuted"],
            "corrected_rcv_holm_significant": [f"{r['model_a']}>{r['model_b']} p_holm={r['corrected_rcv_p_holm21']}"
                                               for r in pgp if float(r["corrected_rcv_p_holm21"]) < 0.05],
        },
        "task2_noop": {
            "n_noop": nr["n_noop"], "by_sub_technique": nr["noop_by_sub_technique"],
            "by_sample_id": nr["noop_by_sample_id"],
            "duplicate_clusters_before": nr["duplicates_full_table"]["n_duplicate_clusters"],
            "duplicate_clusters_after": nr["duplicates_after_removal"]["n_duplicate_clusters"],
            "cells": [{"granularity": r["granularity"], "model": r["model"], "ms_ref": r["ms_ref"],
                       "ms_mean": r["ms_mean"], "ms_matches_committed": r["ms_matches_committed"],
                       "noop_free": r["noop_free"], "diff": r["mean_diff_noop_free_minus_full"],
                       "renaming_f1": r["per_class_f1_renaming"]} for r in noop["partA_cells_comparison"]],
            "decomposition_2x2": noop["partB_2x2_mean_macro_f1"],
        },
        "task3_paired_foldlevel_by_setting": by_setting,
        "task4_convergence": conv["seeds0_4_summary"],
        "task4_hyperparameters_non_default": {m: v["steps"][-1]["non_default"] for m, v in hp["models"].items()},
        "task5_mlp_maxiter2000": {t: {k: v[k] for k in ("ms", "committed_max_iter_200", "max_iter_2000",
                                                         "mean_diff_2000_minus_200", "paired_per_fold_seed_avg_diff",
                                                         "n_iter_2000", "neighbour_means_committed")}
                                  for t, v in mlp["results"].items()},
    }
    with open(os.path.join(C, "summary_v3_closed.json"), "w") as fh:
        json.dump(out, fh, indent=2)
    # checksums of every output file under closed/
    lines = []
    for root, _, files in os.walk(C):
        for f in sorted(files):
            if f == "SHA256SUMS.txt":
                continue
            p = os.path.join(root, f)
            with open(p, "rb") as fh:
                lines.append(f"{hashlib.sha256(fh.read()).hexdigest()}  {os.path.relpath(p, C)}")
    with open(os.path.join(C, "SHA256SUMS.txt"), "w") as fh:
        fh.write("\n".join(sorted(lines, key=lambda s: s.split("  ")[1])) + "\n")
    print(json.dumps(out["task3_paired_foldlevel_by_setting"], indent=1))
    print(json.dumps(out["task1_partition_variance"]["corrected_rcv_holm_significant"]))


if __name__ == "__main__":
    main()
