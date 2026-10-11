"""
Single-cell experiment runner -- the atomic unit of every closed set result.

One invocation evaluates exactly one ``(task, protocol, model, feature_set, seed)``
cell and writes a self-describing JSON result. Every cell is independent, so
cells can be run locally in a loop (Appendix A.2 of the manuscript drives this
module directly with explicit seed loops) or dispatched as HTCondor jobs. The
grid enumeration in ``make_grid.py`` / ``run_grid.py`` is version 1 legacy and
does not describe the reported grid.

Tasks
-----
``provenance``      : transformation family classification (``technique``
                      column; 4 classes on the pilot corpus: addopaque,
                      encodeliterals, encodestrings, renameidentifiers).
``sub_provenance``  : parameterisation classification (``sub_technique``
                      column; 10 classes on the pilot corpus).

Protocols: ``grouped_cv`` | ``lomfo`` (program domain holdout; legacy code
name) | ``looo`` (see :mod:`obfuscope.protocols`). ``--permute-groups`` is an
opt-in for ``grouped_cv`` that makes the partition depend on the seed.

Usage
-----
    python -m obfuscope.experiment --data data/features.csv \
        --task provenance --protocol grouped_cv --model random_forest \
        --feature-set all --seed 0 --out results/cell.json
"""
from __future__ import annotations

import argparse
import json
import os
import time
from typing import Dict, List

import numpy as np

from .config import FEATURE_SETS, TASK_LABEL  # re-exported for backward compatibility
from .features import FEATURE_FAMILIES, feature_names
from .models import build_model
from .protocols import iter_splits


def _load(data_path: str, feature_set: str):
    import pandas as pd
    df = pd.read_parquet(data_path) if data_path.endswith(".parquet") \
        else pd.read_csv(data_path)
    cols = feature_names(FEATURE_SETS[feature_set])
    X = df[cols].to_numpy(dtype=float)
    X = np.nan_to_num(X, nan=0.0, posinf=0.0, neginf=0.0)
    return df, X, cols


def _closed_set_metrics(y_true, y_pred, labels) -> Dict:
    from sklearn.metrics import (accuracy_score, balanced_accuracy_score,
                                 f1_score, confusion_matrix)
    return {
        "accuracy": float(accuracy_score(y_true, y_pred)),
        "balanced_accuracy": float(balanced_accuracy_score(y_true, y_pred)),
        "macro_f1": float(f1_score(y_true, y_pred, average="macro", labels=labels,
                                   zero_division=0)),
        "weighted_f1": float(f1_score(y_true, y_pred, average="weighted", labels=labels,
                                      zero_division=0)),
        "per_class_f1": {str(l): float(v) for l, v in zip(
            labels, f1_score(y_true, y_pred, average=None, labels=labels,
                             zero_division=0))},
        "confusion": confusion_matrix(y_true, y_pred, labels=labels).tolist(),
        "labels": [str(l) for l in labels],
        "n_test": int(len(y_true)),
    }


def _run_closed(df, X, task, protocol, model_name, seed, n_splits,
                permute_groups: bool = False) -> Dict:
    y = df[TASK_LABEL[task]].to_numpy()
    groups = df["sample_id"].to_numpy()
    families = df["malware_family"].to_numpy()
    splits = iter_splits(protocol, groups=groups, y=y, families=families,
                         n_splits=n_splits, seed=seed,
                         permute_groups=permute_groups)
    labels = sorted(set(y.tolist()))
    per_fold, y_all, p_all = [], [], []
    for sp in splits:
        clf = build_model(model_name, seed)
        clf.fit(X[sp.train_idx], y[sp.train_idx])
        pred = clf.predict(X[sp.test_idx])
        m = _closed_set_metrics(y[sp.test_idx], pred, labels)
        m["fold_id"] = sp.fold_id
        if permute_groups:
            # Partitions differ between seeds under --permute-groups, so the
            # fold index no longer identifies the same held out programs
            # across seeds. Record them so that a fold level comparison
            # (scripts/aggregate_seeds.py) can pair on program identity.
            m["test_groups"] = sorted(str(g) for g in set(groups[sp.test_idx].tolist()))
        per_fold.append(m)
        y_all.extend(y[sp.test_idx].tolist()); p_all.extend(pred.tolist())
    agg = _closed_set_metrics(np.array(y_all), np.array(p_all), labels)
    return {"per_fold": per_fold, "aggregate": agg,
            "macro_f1_mean": float(np.mean([f["macro_f1"] for f in per_fold])),
            "macro_f1_std": float(np.std([f["macro_f1"] for f in per_fold]))}


def _run_looo(df, X, model_name, seed) -> Dict:
    """Open-set novelty detection: hold out each technique as an unknown class.

    Version 1 legacy, kept unchanged. It scores the maximum class posterior
    only and, like earlier versions of ``scripts/openset_baselines.py``, takes
    the novel rows from every input program while the known evaluation rows
    come from programs held out of fitting. The revised manuscript's open set
    results come from ``scripts/openset_baselines.py``, not from this function.
    """
    from sklearn.model_selection import GroupShuffleSplit
    from sklearn.metrics import roc_auc_score, average_precision_score
    tech = df["technique"].to_numpy()
    groups = df["sample_id"].to_numpy()
    rows = []
    for holdout in sorted(set(tech.tolist())):
        known = np.where(tech != holdout)[0]
        novel = np.where(tech == holdout)[0]
        # Grouped 80/20 split of the KNOWN rows so negatives at test time are
        # never seen during fitting.
        gss = GroupShuffleSplit(n_splits=1, test_size=0.2, random_state=seed)
        k_fit, k_eval = next(gss.split(known, groups=groups[known]))
        fit_idx = known[k_fit]
        eval_known = known[k_eval]
        clf = build_model(model_name, seed)
        clf.fit(X[fit_idx], tech[fit_idx])
        # Inlier score = max class posterior; novelty score = 1 - inlier.
        def novelty(idx):
            if hasattr(clf, "predict_proba"):
                return 1.0 - clf.predict_proba(X[idx]).max(axis=1)
            d = clf.decision_function(X[idx])
            d = d.max(axis=1) if d.ndim > 1 else d
            return -d
        s_known = novelty(eval_known)
        s_novel = novelty(novel)
        scores = np.concatenate([s_known, s_novel])
        labels = np.concatenate([np.zeros(len(s_known)), np.ones(len(s_novel))])
        rows.append({
            "novel_technique": holdout,
            "auroc": float(roc_auc_score(labels, scores)),
            "auprc": float(average_precision_score(labels, scores)),
            "n_novel": int(len(novel)), "n_known_eval": int(len(eval_known)),
            "mean_novelty_novel": float(np.mean(s_novel)),
            "mean_novelty_known": float(np.mean(s_known)),
        })
    return {"per_technique": rows,
            "auroc_mean": float(np.mean([r["auroc"] for r in rows])),
            "auroc_std": float(np.std([r["auroc"] for r in rows]))}


def run_cell(data_path, task, protocol, model_name, feature_set, seed=0,
             n_splits=5, permute_groups: bool = False) -> Dict:
    t0 = time.time()
    df, X, cols = _load(data_path, feature_set)
    if protocol == "looo":
        body = _run_looo(df, X, model_name, seed)
    else:
        body = _run_closed(df, X, task, protocol, model_name, seed, n_splits,
                           permute_groups=permute_groups)
    # The flag is recorded only when set, so a default cell is unchanged.
    extra = {"permute_groups": True} if permute_groups else {}
    return {
        "task": task, "protocol": protocol, "model": model_name,
        "feature_set": feature_set, "seed": seed, "n_features": len(cols),
        "n_rows": int(len(df)), "runtime_s": round(time.time() - t0, 2),
        **extra,
        **body,
    }


def main(argv=None):
    ap = argparse.ArgumentParser(description="Run one ObfuScope experiment cell.")
    ap.add_argument("--data", required=True)
    ap.add_argument("--task", default="provenance", choices=list(TASK_LABEL))
    ap.add_argument("--protocol", default="grouped_cv",
                    choices=["grouped_cv", "lomfo", "looo"])
    ap.add_argument("--model", default="random_forest")
    ap.add_argument("--feature-set", default="all", choices=list(FEATURE_SETS))
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--n-splits", type=int, default=5)
    ap.add_argument("--permute-groups", action="store_true",
                    help="grouped_cv only: relabel sample_id with a seed "
                         "dependent permutation before StratifiedGroupKFold, "
                         "so different seeds give different partitions (in "
                         "scikit-learn 1.6.1 shuffle=True alone has no effect "
                         "when every group has the same label counts). Off by "
                         "default, which reproduces the committed results.")
    ap.add_argument("--out", default="")
    args = ap.parse_args(argv)
    res = run_cell(args.data, args.task, args.protocol, args.model,
                   args.feature_set, args.seed, args.n_splits,
                   permute_groups=args.permute_groups)
    text = json.dumps(res, indent=2)
    if args.out:
        os.makedirs(os.path.dirname(os.path.abspath(args.out)) or ".", exist_ok=True)
        with open(args.out, "w") as fh:
            fh.write(text)
    # Always echo a compact summary to stdout (HTC job logs or a local loop).
    key = res.get("macro_f1_mean", res.get("auroc_mean"))
    print(f"[cell] {args.task}/{args.protocol}/{args.model}/{args.feature_set} "
          f"seed={args.seed} -> {key:.4f} ({res['runtime_s']}s)")


if __name__ == "__main__":
    main()
