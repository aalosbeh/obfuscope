#!/usr/bin/env python3
"""
Four diagnostic checks run against the limitations raised in the paper's
Threats to Validity / Limitations sections. All four use only released,
already-extracted features (data/features.csv) -- no raw corpus text is
required or available.

1. behavioral_only ablation -- retrain with every naming/size-sensitive
   feature removed (the whole ``lexical`` and ``entropy`` families, plus
   ``obfuscation``), keeping only control_flow/literal/operator/api (32 of
   61 features): the features least plausibly explained by a generator's
   deterministic naming or output-size choices. Probes the external-validity
   concern harder than the existing ``no_obfuscation`` preset.

2. lmfo_no_unknown_hash -- re-run leave-malware-families-out excluding the
   ``unknown_hash`` placeholder bucket (4 unrelated samples with no
   recoverable family name, pooled under one label; see Section 4 of the
   paper). Tests whether malware-agnosticism survives removing that one
   known confound in the malware-family axis.

3. perturbation_robustness -- perturb the top-5 most important features of a
   fitted Random Forest by +/-10/25/50% (random sign per artifact) and
   measure how often the predicted class flips. This is a naive, random
   perturbation, NOT an optimization-based adversarial-example search, and
   operates in feature space rather than on actual C source; it is reported
   as a narrow robustness probe, not a full adaptive-adversary evaluation.

4. adversarial_search -- a REAL, optimization-based (greedy coordinate-ascent)
   evasion search, in direct contrast to check 3's naive random perturbation.
   At each step, scores every single-feature +/-10%-of-std move in one batched
   predict_proba call and keeps whichever most reduces the true-class
   posterior. Still a feature-space attack, not a source-code one -- it
   bounds evasion difficulty in feature space, not whether that evasion is
   realizable by an attacker who can only edit code.

Usage: python3 scripts/robustness_checks.py --data data/features.csv
"""
from __future__ import annotations

import argparse
import os
import sys

import numpy as np
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import f1_score
from sklearn.model_selection import StratifiedGroupKFold

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "src"))
from obfuscope.features import feature_names  # noqa: E402

BEHAVIORAL_FAMILIES = ["control_flow", "literal", "operator", "api"]


def behavioral_only(df: pd.DataFrame, seed: int) -> None:
    cols = feature_names(BEHAVIORAL_FAMILIES)
    X = np.nan_to_num(df[cols].to_numpy(dtype=float), nan=0.0, posinf=0.0, neginf=0.0)
    y = df["technique"].to_numpy()
    groups = df["sample_id"].to_numpy()
    sgkf = StratifiedGroupKFold(n_splits=5, shuffle=True, random_state=seed)
    f1s = []
    for tr, te in sgkf.split(X, y, groups):
        clf = RandomForestClassifier(n_estimators=400, class_weight="balanced_subsample",
                                     random_state=seed, n_jobs=-1)
        clf.fit(X[tr], y[tr])
        f1s.append(f1_score(y[te], clf.predict(X[te]), average="macro"))
    print(f"[1] behavioral_only ({len(cols)}/61 features, naming/size/boilerplate "
          f"removed): grouped_cv macro-F1 = {np.mean(f1s):.4f} +/- {np.std(f1s):.4f}")


def lmfo_no_unknown_hash(df: pd.DataFrame, seed: int) -> None:
    cols = feature_names()
    sub = df[df["malware_family"] != "unknown_hash"].reset_index(drop=True)
    X = np.nan_to_num(sub[cols].to_numpy(dtype=float), nan=0.0, posinf=0.0, neginf=0.0)
    y = sub["technique"].to_numpy()
    fam = sub["malware_family"].to_numpy()
    k = max(2, min(5, len(set(fam.tolist()))))
    sgkf = StratifiedGroupKFold(n_splits=k, shuffle=True, random_state=seed)
    f1s = []
    for tr, te in sgkf.split(X, y, fam):
        clf = RandomForestClassifier(n_estimators=400, class_weight="balanced_subsample",
                                     random_state=seed, n_jobs=-1)
        clf.fit(X[tr], y[tr])
        f1s.append(f1_score(y[te], clf.predict(X[te]), average="macro"))
    print(f"[2] LMFO excluding unknown_hash ({len(sub)}/{len(df)} rows, "
          f"{len(set(fam.tolist()))} families): macro-F1 = "
          f"{np.mean(f1s):.4f} +/- {np.std(f1s):.4f}")


def perturbation_robustness(df: pd.DataFrame, seed: int) -> None:
    cols = feature_names()
    X = np.nan_to_num(df[cols].to_numpy(dtype=float), nan=0.0, posinf=0.0, neginf=0.0)
    y = df["technique"].to_numpy()
    groups = df["sample_id"].to_numpy()
    sgkf = StratifiedGroupKFold(n_splits=5, shuffle=True, random_state=seed)
    tr, te = next(iter(sgkf.split(X, y, groups)))
    clf = RandomForestClassifier(n_estimators=400, class_weight="balanced_subsample",
                                 random_state=seed, n_jobs=-1)
    clf.fit(X[tr], y[tr])
    base_pred = clf.predict(X[te])
    top5 = np.argsort(-clf.feature_importances_)[:5]
    print(f"[3] perturbing top-5 features: {[cols[i] for i in top5]}")
    rng = np.random.default_rng(seed)
    for frac in (0.10, 0.25, 0.50):
        Xp = X[te].copy()
        for i in top5:
            signs = rng.choice([-1.0, 1.0], size=Xp.shape[0])
            Xp[:, i] = Xp[:, i] * (1.0 + signs * frac)
        pred_p = clf.predict(Xp)
        flip_rate = (pred_p != base_pred).mean()
        print(f"    +/-{int(frac*100):>2d}% random perturbation: flip_rate={flip_rate:.3f}")


def adversarial_search(df: pd.DataFrame, seed: int, n_trials: int = 150,
                       max_steps: int = 30) -> None:
    """Real, optimization-based (greedy coordinate-ascent) evasion search, in
    contrast to perturbation_robustness's naive random perturbation. At each
    step, tries moving every feature by 10% of its corpus-wide std in either
    direction (all candidates scored in one batched predict_proba call) and
    keeps whichever single move most reduces the true-class posterior.

    This still perturbs already-extracted numeric features, not actual C
    source under a functionality-preserving constraint -- it bounds how easy
    evasion is in feature space, not whether that evasion is realizable by an
    attacker who can only edit code. See Limitations L3."""
    cols = feature_names()
    X = np.nan_to_num(df[cols].to_numpy(dtype=float), nan=0.0, posinf=0.0, neginf=0.0)
    y = df["technique"].to_numpy()
    groups = df["sample_id"].to_numpy()
    sgkf = StratifiedGroupKFold(n_splits=5, shuffle=True, random_state=seed)
    tr, te = next(iter(sgkf.split(X, y, groups)))
    clf = RandomForestClassifier(n_estimators=400, class_weight="balanced_subsample",
                                 random_state=seed, n_jobs=-1)
    clf.fit(X[tr], y[tr])

    base_pred = clf.predict(X[te])
    correct_mask = base_pred == y[te]
    n_feat = X.shape[1]
    step = 0.10 * X.std(axis=0)
    step[step == 0] = 1e-6

    rng = np.random.default_rng(seed)
    idx_correct = np.where(correct_mask)[0]
    sample_idx = rng.choice(idx_correct, size=min(n_trials, len(idx_correct)), replace=False)
    classes = list(clf.classes_)

    successes, steps_needed = 0, []
    for i in sample_idx:
        x = X[te][i:i + 1].copy()
        true_idx = classes.index(y[te][i])
        for s in range(max_steps):
            proba = clf.predict_proba(x)[0]
            if np.argmax(proba) != true_idx:
                successes += 1
                steps_needed.append(s)
                break
            batch = np.repeat(x, 2 * n_feat, axis=0)
            for j in range(n_feat):
                batch[2 * j, j] = max(batch[2 * j, j] + step[j], 0.0)
                batch[2 * j + 1, j] = max(batch[2 * j + 1, j] - step[j], 0.0)
            batch_proba = clf.predict_proba(batch)[:, true_idx]
            best_row = np.argmin(batch_proba)
            if proba[true_idx] - batch_proba[best_row] <= 0:
                break
            x = batch[best_row:best_row + 1]

    print(f"[4] greedy coordinate-ascent adversarial search (max {max_steps} steps, "
          f"n={len(sample_idx)} correctly-classified held-out artifacts):")
    print(f"    evasion success rate: {successes}/{len(sample_idx)} "
          f"= {successes/len(sample_idx)*100:.1f}%")
    if steps_needed:
        print(f"    mean steps to evade (when successful): {np.mean(steps_needed):.1f}")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--data", default="data/features.csv")
    ap.add_argument("--seed", type=int, default=0)
    args = ap.parse_args(argv)
    df = pd.read_csv(args.data)
    behavioral_only(df, args.seed)
    lmfo_no_unknown_hash(df, args.seed)
    perturbation_robustness(df, args.seed)
    adversarial_search(df, args.seed)


if __name__ == "__main__":
    main()
