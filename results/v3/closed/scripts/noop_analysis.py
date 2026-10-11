"""AUDIT-GENERATED (run:closedset-v3). No-op sensitivity of the domain holdout results (Tables 19 and 20).

Part A compares the no-op-free cells (closed/noop/cells, produced by
obfuscope.experiment on closed/noop/features_pilot_no_noop.csv) with the
committed full-table cells: mean, fold sd, seed sd, min/max (aggregate_seeds
decomposition), per held out domain differences (folds paired on the held out
domain, recomputed from obfuscope.protocols.lomfo for each table), and per
class F1 of the renaming classes.

Part B separates where the change comes from. For every (task, model, seed,
fold) it fits the registry model on (i) the full training fold and (ii) the
training fold without no-op rows, and scores each on (a) the full test fold and
(b) the test fold without no-op rows. Cell (i,a) must equal the committed cell
and (ii,b) the no-op-free cell; (i,b) isolates the test-side effect.
"""
from __future__ import annotations

import os
for _k in ("OMP_NUM_THREADS", "OPENBLAS_NUM_THREADS", "VECLIB_MAXIMUM_THREADS", "MKL_NUM_THREADS",
           "LOKY_MAX_CPU_COUNT"):
    os.environ[_k] = "1"

import json  # noqa: E402
import sys  # noqa: E402
from multiprocessing import Pool  # noqa: E402

import numpy as np  # noqa: E402

HERE = os.path.dirname(os.path.abspath(__file__))
CLOSED = os.path.dirname(HERE)
REPO = os.path.abspath(os.path.join(CLOSED, "..", "..", ".."))
sys.path.insert(0, os.path.join(REPO, "scripts"))
sys.path.insert(0, os.path.join(REPO, "src"))
import aggregate_seeds as AS  # noqa: E402

TASKS = (("provenance", "family", "pilot5", "renameidentifiers"),
         ("sub_provenance", "parameterisation", "pilot5sub", None))
MODELS = ("random_forest", "hist_gbdt")
# MS lines: Table 19 domain holdout columns (L663, L664), Table 20 (L675, L676)
MS = {("provenance", "hist_gbdt"): (0.9480, 0.0339, 0.0031, 0.8797, 1.0000, "MS L663"),
      ("provenance", "random_forest"): (0.9542, 0.0356, 0.0053, 0.9058, 1.0000, "MS L664"),
      ("sub_provenance", "hist_gbdt"): (0.8124, 0.0816, 0.0073, 0.7112, 0.9366, "MS L675"),
      ("sub_provenance", "random_forest"): (0.8045, 0.0731, 0.0042, 0.7372, 0.9436, "MS L676")}


def lomfo_domains(csv_path, task):
    import pandas as pd
    from obfuscope.config import TASK_LABEL
    from obfuscope.protocols import iter_splits
    df = pd.read_csv(csv_path)
    y = df[TASK_LABEL[task]].to_numpy(); fam = df["malware_family"].to_numpy()
    out = {}
    for s in range(5):
        sp = iter_splits("lomfo", groups=df["sample_id"].to_numpy(), y=y, families=fam,
                         n_splits=5, seed=s)
        out[s] = [sorted(set(fam[x.test_idx].tolist()))[0] for x in sp]
    return out


def part_a(orig):
    full_csv = os.path.join(REPO, "data", "features_pilot.csv")
    nn_csv = os.path.join(CLOSED, "noop", "features_pilot_no_noop.csv")
    res = []
    for task, gran, sub, _ in TASKS:
        dom_full = lomfo_domains(full_csv, task); dom_nn = lomfo_domains(nn_csv, task)
        for m in MODELS:
            full = [json.load(open(os.path.join(orig, sub, f"{task}_lomfo_{m}_all_s{s}.json")))
                    for s in range(5)]
            nn = [json.load(open(os.path.join(CLOSED, "noop", "cells", f"{task}_lomfo_{m}_all_s{s}.json")))
                  for s in range(5)]
            dfull, dnn = AS.decompose(full), AS.decompose(nn)
            # per domain, seed averaged
            per_dom = {}
            for s in range(5):
                for i, f in enumerate(full[s]["per_fold"]):
                    per_dom.setdefault(dom_full[s][i], {"full": [], "noop_free": []})["full"].append(f["macro_f1"])
                for i, f in enumerate(nn[s]["per_fold"]):
                    per_dom[dom_nn[s][i]]["noop_free"].append(f["macro_f1"])
            dom_rows = {d: {"full": round(float(np.mean(v["full"])), 4),
                            "noop_free": round(float(np.mean(v["noop_free"])), 4),
                            "diff": round(float(np.mean(v["noop_free"]) - np.mean(v["full"])), 4)}
                        for d, v in sorted(per_dom.items())}
            # per class F1 of renaming classes, pooled over folds per seed then averaged over seeds
            cls = [c for c in full[0]["aggregate"]["labels"] if "ren" in c]
            pcf = {c: {"full": round(float(np.mean([x["aggregate"]["per_class_f1"][c] for x in full])), 4),
                       "noop_free": round(float(np.mean([x["aggregate"]["per_class_f1"][c] for x in nn])), 4)}
                   for c in cls}
            ms = MS[(task, m)]
            res.append({
                "granularity": gran, "task": task, "protocol": "lomfo (domain holdout)", "model": m,
                "ms_ref": ms[5], "ms_mean": ms[0], "ms_fold_sd": ms[1], "ms_seed_sd": ms[2],
                "ms_min": ms[3], "ms_max": ms[4],
                "committed_full": {k: dfull[k] for k in ("mean", "sd_fold", "sd_seed", "min_fold",
                                                          "max_fold", "per_seed_mean")},
                "ms_matches_committed": all(abs(a - b) < 5e-5 for a, b in zip(
                    ms[:5], (dfull["mean"], dfull["sd_fold"], dfull["sd_seed"], dfull["min_fold"], dfull["max_fold"]))),
                "noop_free": {k: dnn[k] for k in ("mean", "sd_fold", "sd_seed", "min_fold", "max_fold",
                                                   "per_seed_mean")},
                "mean_diff_noop_free_minus_full": round(dnn["mean"] - dfull["mean"], 4),
                "per_domain_seed_avg": dom_rows,
                "per_class_f1_renaming": pcf,
                "fold_to_domain_full_seed0": dom_full[0], "fold_to_domain_noop_free_seed0": dom_nn[0],
            })
    return res


def _job(args):
    task, m, seed = args
    import pandas as pd
    from sklearn.metrics import f1_score
    from obfuscope.config import TASK_LABEL
    from obfuscope.experiment import _load
    from obfuscope.models import build_model
    from obfuscope.protocols import iter_splits
    df, X, _ = _load(os.path.join(REPO, "data", "features_pilot.csv"), "all")
    rep = json.load(open(os.path.join(CLOSED, "noop", "noop_rows.json")))
    noop = df["path"].isin(set(rep["noop_paths"])).to_numpy()
    assert noop.sum() == 32
    y = df[TASK_LABEL[task]].to_numpy(); labels = sorted(set(y.tolist()))
    fam = df["malware_family"].to_numpy()
    sp_full = iter_splits("lomfo", groups=df["sample_id"].to_numpy(), y=y, families=fam, n_splits=5, seed=seed)
    # the no-op-free experiment re-splits the filtered table; pair folds on the held out domain
    out = []
    for sp in sp_full:
        dom = sorted(set(fam[sp.test_idx].tolist()))[0]
        tr_all, te_all = sp.train_idx, sp.test_idx
        tr_nn, te_nn = tr_all[~noop[tr_all]], te_all[~noop[te_all]]
        rec = {"task": task, "model": m, "seed": seed, "domain": dom,
               "n_noop_train": int(noop[tr_all].sum()), "n_noop_test": int(noop[te_all].sum())}
        for tname, tr in (("train_full", tr_all), ("train_noopfree", tr_nn)):
            clf = build_model(m, seed); clf.fit(X[tr], y[tr])
            for ename, te in (("test_full", te_all), ("test_noopfree", te_nn)):
                p = clf.predict(X[te])
                rec[f"{tname}|{ename}"] = float(f1_score(y[te], p, average="macro", labels=labels,
                                                         zero_division=0))
        out.append(rec)
    return out


def part_b():
    jobs = [(t, m, s) for t, *_ in TASKS for m in MODELS for s in range(5)]
    with Pool(4) as pool:
        recs = [r for rs in pool.map(_job, jobs) for r in rs]
    summary = {}
    for t, gran, *_ in TASKS:
        for m in MODELS:
            rr = [r for r in recs if r["task"] == t and r["model"] == m]
            summary[f"{gran}|{m}"] = {k: round(float(np.mean([r[k] for r in rr])), 4)
                                      for k in ("train_full|test_full", "train_full|test_noopfree",
                                                "train_noopfree|test_full", "train_noopfree|test_noopfree")}
    return recs, summary


def main():
    orig = sys.argv[1]
    a = part_a(orig)
    recs, summ = part_b()
    # consistency checks against the two cell grids
    checks = []
    for r in a:
        t, m = r["task"], r["model"]
        key = f"{r['granularity']}|{m}"
        checks.append({"config": key,
                       "partB_full_full_vs_committed_mean": [summ[key]["train_full|test_full"], r["committed_full"]["mean"]],
                       "partB_nn_nn_vs_noop_cells_mean": [summ[key]["train_noopfree|test_noopfree"], r["noop_free"]["mean"]]})
    out = {"label": "AUDIT-GENERATED run:closedset-v3",
           "noop_definition": "closed/noop/noop_rows.json (32 rows: ref_ren_hex and ref_ren_long of "
                              "bitops_popcount and textproc_trim, byte identical to the input program)",
           "partA_cells_comparison": a, "partB_2x2_mean_macro_f1": summ, "partB_consistency": checks,
           "partB_per_fold": recs}
    with open(os.path.join(CLOSED, "noop", "noop_sensitivity.json"), "w") as fh:
        json.dump(out, fh, indent=2)
    for r in a:
        print(f"{r['granularity']:16s} {r['model']:13s} MS {r['ms_mean']:.4f} committed {r['committed_full']['mean']:.4f} "
              f"(match {r['ms_matches_committed']}) noop-free {r['noop_free']['mean']:.4f} "
              f"sd_fold {r['noop_free']['sd_fold']:.4f} sd_seed {r['noop_free']['sd_seed']:.4f} "
              f"[{r['noop_free']['min_fold']:.4f},{r['noop_free']['max_fold']:.4f}] diff {r['mean_diff_noop_free_minus_full']:+.4f}")
        print("   per-domain", r["per_domain_seed_avg"])
        print("   renaming F1", r["per_class_f1_renaming"])
    print(json.dumps(summ, indent=1)); print(json.dumps(checks, indent=1))


if __name__ == "__main__":
    main()
