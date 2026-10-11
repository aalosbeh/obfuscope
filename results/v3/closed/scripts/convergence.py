"""AUDIT-GENERATED (run:closedset-v3). Per fold iteration counts / convergence of mlp, hist_gbdt (and logreg).

Re-fits exactly what obfuscope.experiment._run_closed fits (same splits from
obfuscope.protocols.iter_splits, same build_model(name, seed), same X built by
obfuscope.experiment._load) under lomfo at both granularities, and records
n_iter_ and convergence per fold. Each fold's macro F1 is compared with the
committed cell to show the fits are the committed ones.

Primary block: seed 0 (as requested). Supplementary block: seeds 0-4 summary.
"""
from __future__ import annotations

import argparse
import json
import os
import sys
import warnings

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
CLOSED = os.path.dirname(HERE)
REPO = os.path.abspath(os.path.join(CLOSED, "..", "..", ".."))
sys.path.insert(0, os.path.join(REPO, "src"))
from sklearn.exceptions import ConvergenceWarning  # noqa: E402
from sklearn.metrics import f1_score  # noqa: E402

from obfuscope.config import TASK_LABEL  # noqa: E402
from obfuscope.experiment import _load  # noqa: E402
from obfuscope.models import build_model  # noqa: E402
from obfuscope.protocols import iter_splits  # noqa: E402


def fit_record(model, X, y, sp, labels, seed):
    clf = build_model(model, seed)
    with warnings.catch_warnings(record=True) as w:
        warnings.simplefilter("always", ConvergenceWarning)
        clf.fit(X[sp.train_idx], y[sp.train_idx])
    est = clf.named_steps["clf"]
    pred = clf.predict(X[sp.test_idx])
    rec = {"fold_id": sp.fold_id,
           "macro_f1": float(f1_score(y[sp.test_idx], pred, average="macro", labels=labels,
                                      zero_division=0)),
           "convergence_warning": any(issubclass(x.category, ConvergenceWarning) for x in w)}
    if model == "mlp":
        rec.update({"n_iter_": int(est.n_iter_), "max_iter": int(est.max_iter),
                    "hit_max_iter": bool(est.n_iter_ >= est.max_iter),
                    "stopped_by_tol_rule": bool(est.n_iter_ < est.max_iter),
                    "final_loss": round(float(est.loss_), 6),
                    "best_loss": round(float(est.best_loss_), 6),
                    "no_improvement_count_at_stop": int(est._no_improvement_count)})
    elif model == "hist_gbdt":
        vs = getattr(est, "validation_score_", None)
        rec.update({"n_iter_": int(est.n_iter_), "max_iter": int(est.max_iter),
                    "early_stopped": bool(est.n_iter_ < est.max_iter),
                    "n_trees_per_iteration": int(est.n_trees_per_iteration_),
                    "validation_fraction": est.validation_fraction,
                    "best_validation_score": None if vs is None else round(float(np.max(vs)), 6),
                    "final_validation_score": None if vs is None else round(float(vs[-1]), 6)})
    elif model == "logreg":
        rec.update({"n_iter_": [int(v) for v in np.ravel(est.n_iter_)], "max_iter": int(est.max_iter)})
    return rec


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--orig-results", required=True)
    ap.add_argument("--data", default=os.path.join(REPO, "data", "features_pilot.csv"))
    a = ap.parse_args()
    df, X, _ = _load(a.data, "all")
    groups = df["sample_id"].to_numpy(); fam = df["malware_family"].to_numpy()
    out = {"label": "AUDIT-GENERATED run:closedset-v3", "protocol": "lomfo (domain holdout)",
           "data": os.path.relpath(a.data, REPO), "seed0": {}, "seeds0_4_summary": {}}
    for task, gran, sub in (("provenance", "family", "pilot5"),
                            ("sub_provenance", "parameterisation", "pilot5sub")):
        y = df[TASK_LABEL[task]].to_numpy(); labels = sorted(set(y.tolist()))
        for seed in range(5):
            splits = iter_splits("lomfo", groups=groups, y=y, families=fam, n_splits=5, seed=seed)
            for model in ("mlp", "hist_gbdt", "logreg"):
                if seed > 0 and model == "logreg":
                    continue
                with open(os.path.join(a.orig_results, sub,
                                       f"{task}_lomfo_{model}_all_s{seed}.json")) as fh:
                    committed = json.load(fh)
                recs = []
                for sp, cf in zip(splits, committed["per_fold"]):
                    r = fit_record(model, X, y, sp, labels, seed)
                    r["held_out_domain"] = sorted(set(fam[sp.test_idx].tolist()))
                    r["committed_macro_f1"] = cf["macro_f1"]
                    r["matches_committed"] = abs(r["macro_f1"] - cf["macro_f1"]) < 1e-12
                    recs.append(r)
                key = f"{gran}|{model}"
                if seed == 0:
                    out["seed0"][key] = recs
                summ = out["seeds0_4_summary"].setdefault(key, {"n_fits": 0, "n_iter_": [],
                                                                "n_hit_max_iter_or_warning": 0,
                                                                "all_match_committed": True})
                summ["n_fits"] += len(recs)
                summ["n_iter_"].extend([r.get("n_iter_") for r in recs])
                summ["n_hit_max_iter_or_warning"] += sum(
                    bool(r.get("hit_max_iter") or r["convergence_warning"]) for r in recs)
                summ["all_match_committed"] &= all(r["matches_committed"] for r in recs)
                print(task, model, seed, [r.get("n_iter_") for r in recs],
                      [r["convergence_warning"] for r in recs],
                      all(r["matches_committed"] for r in recs), flush=True)
    for k, s in out["seeds0_4_summary"].items():
        if k.endswith("hist_gbdt"):
            s["n_early_stopped"] = int(sum(v < 200 for v in s["n_iter_"]))
    with open(os.path.join(CLOSED, "convergence.json"), "w") as fh:
        json.dump(out, fh, indent=2)


if __name__ == "__main__":
    main()
