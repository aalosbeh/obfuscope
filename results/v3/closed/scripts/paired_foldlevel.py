"""AUDIT-GENERATED (run:closedset-v3). All pairwise fold level comparisons among the 7 estimators.

Reads committed cells (feature set ``all``) and, for every unordered model pair
in each setting, calls ``scripts/aggregate_seeds.paired_fold_level`` (the
updated fold level summary: per distinct fold the a - b macro F1 difference
averaged over seeds; wins/ties/losses; exact sign test; exact Wilcoxon). It
adds the Nadeau and Bengio (2003) corrected resampled t test on the same
per fold means:

    t = mean(d) / sqrt((1/J + n_test/n_train) * var(d, ddof=1)),  df = J - 1

with J = number of distinct folds (5) and n_test/n_train = 1/4 (480/1920 per
fold; checked from the cells). Holm adjusted p values over the 21 pairs of a
setting are given for the Wilcoxon and the corrected t test.

Orientation: model_a is the model with the higher pooled mean in that setting,
so mean_diff >= 0 except for ties in the pooled mean.

The fold identity is the fold index (committed cells carry no test_groups); the
script re-derives the default partitions at seeds 0-4 and checks they are
identical, which is what makes index pairing valid.
"""
from __future__ import annotations

import argparse
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
sys.path.insert(0, os.path.join(REPO, "src"))
import aggregate_seeds as AS  # noqa: E402

MODELS = ["hist_gbdt", "random_forest", "extra_trees", "svm_rbf", "logreg", "mlp", "knn"]
SETTINGS = [("family", "provenance", "grouped_cv", "pilot5"),
            ("family", "provenance", "lomfo", "pilot5"),
            ("parameterisation", "sub_provenance", "lomfo", "pilot5sub")]


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


def partitions_identical(task, protocol, data):
    import pandas as pd
    from obfuscope.config import TASK_LABEL
    from obfuscope.protocols import iter_splits
    df = pd.read_csv(data)
    y = df[TASK_LABEL[task]].to_numpy()
    groups = df["sample_id"].to_numpy()
    fam = df["malware_family"].to_numpy()
    parts = []
    for s in range(5):
        sp = iter_splits(protocol, groups=groups, y=y, families=fam, n_splits=5, seed=s)
        parts.append([tuple(sorted(set((groups if protocol == "grouped_cv" else fam)[x.test_idx].tolist())))
                      for x in sp])
    return all(p == parts[0] for p in parts), parts[0]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--orig-results", required=True)
    ap.add_argument("--data", default=os.path.join(REPO, "data", "features_pilot.csv"))
    a = ap.parse_args()

    rows, meta = [], {"label": "AUDIT-GENERATED run:closedset-v3", "settings": {}}
    for gran, task, proto, sub in SETTINGS:
        cells = {}
        for m in MODELS:
            cs = []
            for s in range(5):
                p = os.path.join(a.orig_results, sub, f"{task}_{proto}_{m}_all_s{s}.json")
                with open(p) as fh:
                    cs.append(json.load(fh))
            cells[m] = cs
        means = {m: AS.decompose(cells[m])["mean"] for m in MODELS}
        n_test = sorted({f["n_test"] for c in cells["hist_gbdt"] for f in c["per_fold"]})
        n_rows = cells["hist_gbdt"][0]["n_rows"]
        ratios = sorted({round(t / (n_rows - t), 6) for t in n_test})
        assert ratios == [0.25], ratios
        ident, part0 = partitions_identical(task, proto, a.data)
        meta["settings"][f"{gran}|{proto}"] = {
            "n_test_per_fold": n_test, "n_rows": n_rows, "test_train_ratio": ratios,
            "default_partition_identical_seeds_0_4": ident,
            "held_out_groups_by_fold_index": [list(t) for t in part0],
            "pooled_means": means}
        block = []
        for m1, m2 in itertools.combinations(MODELS, 2):
            ma, mb = (m1, m2) if means[m1] >= means[m2] else (m2, m1)
            fl = AS.paired_fold_level(cells[ma], cells[mb])
            d = np.asarray(fl["seed_averaged_differences"], dtype=float)
            # recompute the per fold means at full precision for the t test
            per = {}
            for ca in cells[ma]:
                cb = [c for c in cells[mb] if c["seed"] == ca["seed"]][0]
                for i, (fa, fb) in enumerate(zip(ca["per_fold"], cb["per_fold"])):
                    per.setdefault(i, []).append(fa["macro_f1"] - fb["macro_f1"])
            dm = np.array([np.mean(per[i]) for i in sorted(per)])
            assert np.allclose(np.round(dm, 4), d)
            J = len(dm)
            var = float(np.var(dm, ddof=1))
            corr = (1.0 / J + 0.25)
            if var > 0:
                t_nb = float(dm.mean() / np.sqrt(corr * var))
                p_nb = float(2 * stats.t.sf(abs(t_nb), J - 1))
                t_naive = float(dm.mean() / np.sqrt(var / J))
                p_naive = float(2 * stats.t.sf(abs(t_naive), J - 1))
            else:
                t_nb = p_nb = t_naive = p_naive = float("nan")
            block.append({
                "granularity": gran, "task": task, "protocol": proto,
                "protocol_name_ms": "grouped_cv" if proto == "grouped_cv" else "domain holdout",
                "model_a": ma, "model_b": mb,
                "mean_a": means[ma], "mean_b": means[mb],
                "n_distinct_folds": fl["n_distinct_folds"],
                "n_seeds_per_fold": fl["n_seeds_per_fold"][0],
                "fold_identity": fl["fold_identity"],
                "per_fold_seed_avg_diff": ";".join(f"{v:.4f}" for v in dm),
                "mean_diff": round(float(dm.mean()), 4),
                "sd_fold_diff": round(float(np.sqrt(var)), 4),
                "wins": fl["folds_won"], "ties": fl["folds_tied"], "losses": fl["folds_lost"],
                "sign_p_exact": fl["sign_test_p_two_sided"],
                "wilcoxon_w_plus": fl["wilcoxon_w_plus"],
                "wilcoxon_n_nonzero": fl["wilcoxon_n_nonzero"],
                "wilcoxon_p_exact": fl["wilcoxon_p_two_sided_exact"],
                "nb_t": round(t_nb, 4), "nb_df": J - 1, "nb_p": round(p_nb, 6),
                "uncorrected_t_5folds": round(t_naive, 4), "uncorrected_p_5folds": round(p_naive, 6),
            })
        for key, col in (("wilcoxon_p_exact", "wilcoxon_p_holm21"), ("nb_p", "nb_p_holm21")):
            adj = holm([r[key] if r[key] == r[key] else 1.0 for r in block])
            for r, v in zip(block, adj):
                r[col] = round(float(v), 6)
        rows.extend(block)

    out_csv = os.path.join(CLOSED, "paired_foldlevel.csv")
    with open(out_csv, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    meta["n_rows"] = len(rows)
    meta["nadeau_bengio"] = ("t = mean(d)/sqrt((1/J + 1/4) var(d)), J = 5 distinct folds, d = seed "
                             "averaged per fold differences, df = 4, two sided")
    meta["minimum_attainable_exact_p_with_5_folds"] = {"sign": 0.0625, "wilcoxon": 0.0625}
    with open(os.path.join(CLOSED, "paired_foldlevel_meta.json"), "w") as fh:
        json.dump(meta, fh, indent=2)
    print(f"wrote {out_csv} ({len(rows)} rows)")
    for r in rows:
        print(f"{r['granularity'][:5]} {r['protocol']:10s} {r['model_a']:13s} {r['model_b']:13s} "
              f"d={r['mean_diff']:+.4f} {r['wins']}/{r['ties']}/{r['losses']} sign={r['sign_p_exact']:.4f} "
              f"wil={r['wilcoxon_p_exact']:.4f} nb_t={r['nb_t']:.3f} nb_p={r['nb_p']:.4f} "
              f"holm={r['nb_p_holm21']:.4f}")


if __name__ == "__main__":
    main()
