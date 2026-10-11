"""AUDIT-GENERATED diagnostics for scripts/evasion_matched.py (MS Section 7.8).

Replicates the exact split, model, sample selection and greedy search of
evasion_matched.greedy_evade (scripts/evasion_matched.py:82-176) on the narrow
corpus, and records *why* each attacked artifact's search ended:
  success   prediction flipped
  plateau   no single +/-0.1 sd coordinate move lowered the true-class proba
            (evasion_matched.py:151-152 break)
  max_steps 30 steps used without flip

Then runs a simple stronger attack under the SAME constraints (same movable
features, same non-negativity clip, same displacement metric ||dx/sd||_2) and
the SAME budgets: (i) single-coordinate line search over magnitudes up to the
budget, (ii) random directions in the movable subspace scaled to the budget
radius grid. Success = argmax != true label, identical to the original.

Also reports feature importances of the 6 'attacker controlled' features and
the grouped closed-set accuracy of a forest restricted to those features.

Usage: python evasion_diagnostics.py <repo_root> <out_json>
"""
import json
import sys

import numpy as np
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import StratifiedGroupKFold

repo, out_path = sys.argv[1], sys.argv[2]
sys.path.insert(0, repo + "/scripts")
import evasion_matched as em  # noqa: E402

wide = pd.read_csv(repo + "/data/features.csv")
narrow = pd.read_csv(repo + "/data/features_pilot.csv")
feats = em.shared_features(wide, narrow)
movable_idx = [i for i, f in enumerate(feats)
               if f.startswith(em.ATTACKER_CONTROLLED_PREFIXES)]
BUDGETS = [0.5, 1.0, 2.0, 5.0]
SEED = 0


def prep(df):
    X = np.nan_to_num(df[feats].to_numpy(dtype=float), nan=0.0, posinf=0.0, neginf=0.0)
    return X, df["technique"].to_numpy(), df["sample_id"].to_numpy()


def setup(X, y, g, seed):
    sgkf = StratifiedGroupKFold(n_splits=5, shuffle=True, random_state=seed)
    tr, te = next(iter(sgkf.split(X, y, g)))
    clf = RandomForestClassifier(n_estimators=400, class_weight="balanced_subsample",
                                 random_state=seed, n_jobs=1)
    clf.fit(X[tr], y[tr])
    sd = X[tr].std(axis=0)
    sd[sd == 0] = 1.0
    Xte, yte = X[te], y[te]
    correct = np.where(clf.predict(Xte) == yte)[0]
    rng = np.random.default_rng(seed)
    sample = rng.choice(correct, size=min(150, correct.size), replace=False)
    return clf, sd, Xte, yte, sample, tr


def greedy_instrumented(clf, sd, Xte, yte, sample, movable, max_steps=30):
    step = 0.10 * sd
    classes = list(clf.classes_)
    recs = []
    for i in sample:
        x0 = Xte[i:i + 1].copy(); x = x0.copy()
        t = classes.index(yte[i])
        reason, steps, disp = None, None, None
        for s in range(max_steps):
            proba = clf.predict_proba(x)[0]
            if int(np.argmax(proba)) != t:
                reason, steps = "success", s
                disp = float(np.linalg.norm((x - x0)[0] / sd)); break
            batch = np.repeat(x, 2 * movable.size, axis=0)
            for k, j in enumerate(movable):
                batch[2 * k, j] = max(batch[2 * k, j] + step[j], 0.0)
                batch[2 * k + 1, j] = max(batch[2 * k + 1, j] - step[j], 0.0)
            scores = clf.predict_proba(batch)[:, t]
            best = int(np.argmin(scores))
            if proba[t] - scores[best] <= 0:
                reason, steps = "plateau", s
                disp = float(np.linalg.norm((x - x0)[0] / sd)); break
            x = batch[best:best + 1]
        if reason is None:
            reason, steps = "max_steps", max_steps
            disp = float(np.linalg.norm((x - x0)[0] / sd))
        recs.append({"reason": reason, "steps": steps, "disp": disp})
    return recs


def stronger(clf, sd, Xte, yte, sample, movable, budgets, n_dirs=400, seed=0):
    """Line search + random direction search; returns min successful norm per sample."""
    rng = np.random.default_rng(1000 + seed)
    classes = list(clf.classes_)
    bmax = max(budgets)
    mags = np.concatenate([np.linspace(0.05, 1.0, 20), np.linspace(1.1, bmax, 40)])
    radii = np.array([0.25, 0.5, 0.75, 1.0, 1.5, 2.0, 3.0, 4.0, 5.0])
    best_norm = []
    for i in sample:
        x0 = Xte[i]
        t = classes.index(yte[i])
        cands = []
        for j in movable:
            for sgn in (1.0, -1.0):
                for m in mags:
                    d = np.zeros_like(x0); d[j] = sgn * m * sd[j]; cands.append(d)
        D = rng.normal(size=(n_dirs, movable.size))
        D /= np.linalg.norm(D, axis=1, keepdims=True)
        for r in radii:
            for row in D:
                d = np.zeros_like(x0); d[movable] = r * row * sd[movable]; cands.append(d)
        C = np.maximum(x0[None, :] + np.asarray(cands), 0.0)
        norms = np.linalg.norm((C - x0[None, :]) / sd[None, :], axis=1)
        pred = clf.predict_proba(C).argmax(axis=1)
        ok = pred != t
        best_norm.append(float(norms[ok].min()) if ok.any() else float("inf"))
    bn = np.asarray(best_norm)
    return {"success_by_budget": {f"{b:g}": round(float((bn <= b).mean()), 4) for b in budgets},
            "n_attacked": int(bn.size),
            "median_min_norm_when_successful": (round(float(np.median(bn[np.isfinite(bn)])), 4)
                                                if np.isfinite(bn).any() else None)}


def summarise(recs, budgets):
    reasons = pd.Series([r["reason"] for r in recs]).value_counts().to_dict()
    disp = np.array([r["disp"] if r["reason"] == "success" else np.inf for r in recs])
    plateau_at0 = sum(1 for r in recs if r["reason"] == "plateau" and r["steps"] == 0)
    succ_steps = [r["steps"] for r in recs if r["reason"] == "success"]
    return {"stop_reasons": {k: int(v) for k, v in reasons.items()},
            "plateau_at_step0": int(plateau_at0),
            "success_by_budget_reproduced": {f"{b:g}": round(float((disp <= b).mean()), 4) for b in budgets},
            "unbounded_success_rate_reproduced": round(float(np.isfinite(disp).mean()), 4),
            "mean_steps_when_successful": round(float(np.mean(succ_steps)), 2) if succ_steps else None,
            "max_displacement_any_trial": round(float(max(r["disp"] for r in recs)), 4),
            "max_possible_displacement_30_steps": 3.0}


out = {"note": "AUDIT-GENERATED; replicates scripts/evasion_matched.py greedy_evade split/model/sample",
       "shared_features": len(feats),
       "attacker_controlled": [feats[i] for i in movable_idx]}
X, y, g = prep(narrow)
clf, sd, Xte, yte, sample, tr = setup(X, y, g, SEED)
imp = clf.feature_importances_
order = np.argsort(-imp)
out["narrow_importance"] = {
    "controlled_features": {feats[i]: {"importance": round(float(imp[i]), 5),
                                       "rank_of_61": int(np.where(order == i)[0][0]) + 1,
                                       "train_sd": float(X[tr][:, i].std())}
                            for i in movable_idx},
    "controlled_importance_share": round(float(imp[movable_idx].sum()), 4),
    "top10": [(feats[i], round(float(imp[i]), 4)) for i in order[:10]]}
for tag, mov in (("unrestricted", np.arange(len(feats))),
                 ("restricted", np.asarray(sorted(movable_idx)))):
    recs = greedy_instrumented(clf, sd, Xte, yte, sample, mov)
    out[f"narrow_{tag}_greedy"] = summarise(recs, BUDGETS)
    out[f"narrow_{tag}_stronger_attack"] = stronger(clf, sd, Xte, yte, sample, mov, BUDGETS)
    print(tag, out[f"narrow_{tag}_greedy"], out[f"narrow_{tag}_stronger_attack"], flush=True)

# Closed-set signal in the controlled features alone (grouped 5-fold, seed 0).
Xc = X[:, movable_idx]
accs = []
for trf, tef in StratifiedGroupKFold(n_splits=5, shuffle=True, random_state=0).split(Xc, y, g):
    m = RandomForestClassifier(n_estimators=400, class_weight="balanced_subsample",
                               random_state=0, n_jobs=1).fit(Xc[trf], y[trf])
    accs.append(float((m.predict(Xc[tef]) == y[tef]).mean()))
out["narrow_closed_accuracy_controlled_features_only_grouped5fold"] = {
    "mean": round(float(np.mean(accs)), 4), "per_fold": [round(a, 4) for a in accs],
    "chance_4_classes": 0.25}
print(out["narrow_closed_accuracy_controlled_features_only_grouped5fold"], flush=True)

with open(out_path, "w") as fh:
    json.dump(out, fh, indent=2)
print("written", out_path)
