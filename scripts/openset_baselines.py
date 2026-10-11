"""
Open set recognition baselines for transformation attribution.

Version 1 of the paper scored novelty with one quantity, the maximum class
posterior, and reported one metric, AUROC. That is the weakest published
baseline measured by the most forgiving metric, so a reader cannot tell whether
the reported number says something about the features or only about the scorer.
This script replaces that single measurement with six scorers and five metrics
evaluated under one protocol.

Scorers
-------
msp          Maximum class posterior. Hendrycks and Gimpel, ICLR 2017.
energy       Negative free energy of the logits. Liu et al., NeurIPS 2020.
knn_dist     Negative mean distance to the k nearest training rows. The scorer
             Vaze et al., ICLR 2022 showed is competitive with far more
             elaborate methods.
mahalanobis  Negative smallest class conditional Mahalanobis distance under a
             tied covariance. Lee et al., NeurIPS 2018.
iforest      Isolation Forest path length. Liu et al., ICDM 2008.
openmax      Extreme value recalibration of the activation vector against a
             Weibull fitted to the tail of the correctly classified training
             distances. Bendale and Boult, CVPR 2016.

Every scorer returns an inlier score where larger means more likely to belong
to a transformation the model was trained on, so the metrics below read the
same way for all six.

Metrics
-------
auroc        Area under the receiver operating characteristic, novel positive.
aupr_novel   Average precision with the novel class positive. Unlike AUROC this
             moves when the novel class is rare, which is the realistic case.
aupr_known   Average precision with the known class positive.
fpr_at_95tpr Fraction of known rows wrongly flagged novel at the threshold that
             detects 95 percent of novel rows. This is the number an analyst
             feels, because it sets how much known traffic lands in the review
             queue.
oscr         Area under the open set classification rate curve, which charges
             the model for closed set mistakes as well as for accepting novel
             rows. Dhamija et al., NeurIPS 2018.

A calibration error is also reported for the closed set posteriors on the known
evaluation rows, because msp and energy both inherit whatever miscalibration
the classifier has. Guo et al., ICML 2017.

Protocol
--------
Leave one transformation out. Each transformation in turn is removed from
training and its artifacts become the novel class at evaluation time. The
remaining transformations are split 80 to 20 by input program with
GroupShuffleSplit, so no input program contributes rows to both the fitting set
and the known evaluation set. Without the grouping constraint a known
evaluation row can be a sibling variant of a fitting row and the known side of
the comparison becomes trivially easy.

The whole protocol repeats over several seeds and the spread across seeds is
reported, because a four fold protocol over four transformations has enough
sampling noise that a single run is not informative.

Usage
-----
    python3 scripts/openset_baselines.py \\
        --data data/features_pilot.csv \\
        --models random_forest logreg knn \\
        --seeds 0 1 2 3 4 \\
        --report results/openset_baselines.json
"""
from __future__ import annotations

import argparse
import json
import os
import sys
from typing import Dict, List

import numpy as np

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "src"))

from obfuscope.config import FEATURE_SETS          # noqa: E402
from obfuscope.features import feature_names        # noqa: E402
from obfuscope.models import build_model            # noqa: E402


class NotApplicable(Exception):
    """A scorer cannot be defined for this estimator.

    Kept distinct from a failure so the report can say that a method does not
    apply, which is informative, rather than that it broke, which is not.
    """


# --------------------------------------------------------------------------- #
# Metrics
# --------------------------------------------------------------------------- #

def _fpr_at_tpr(novelty_known: np.ndarray, novelty_novel: np.ndarray,
                target_tpr: float = 0.95) -> float:
    """Known rows flagged novel at the threshold detecting target_tpr of novels.

    Computed from the empirical quantile of the novel scores rather than by
    interpolating a sampled curve, so the answer does not depend on how finely
    the curve was sampled.
    """
    if len(novelty_novel) == 0 or len(novelty_known) == 0:
        return float("nan")
    thr = float(np.quantile(novelty_novel, 1.0 - target_tpr))
    return float(np.mean(novelty_known >= thr))


def _oscr(inlier_known: np.ndarray, correct_known: np.ndarray,
          inlier_novel: np.ndarray) -> float:
    """Area under the open set classification rate curve.

    Sweeping the acceptance threshold over every observed score, the curve
    plots the fraction of known rows that are both accepted and classified
    correctly against the fraction of novel rows wrongly accepted. A model that
    rejects novel rows by refusing to classify anything scores zero, which is
    the property AUROC lacks.
    """
    if len(inlier_known) == 0 or len(inlier_novel) == 0:
        return float("nan")
    thresholds = np.unique(np.concatenate([inlier_known, inlier_novel]))
    # Descending so the curve is traced from strict to permissive.
    thresholds = np.concatenate([[np.inf], thresholds[::-1], [-np.inf]])
    ccr, fpr = [], []
    for t in thresholds:
        acc_known = inlier_known >= t
        ccr.append(float(np.mean(acc_known & correct_known)))
        fpr.append(float(np.mean(inlier_novel >= t)))
    fpr = np.asarray(fpr)
    ccr = np.asarray(ccr)
    order = np.argsort(fpr, kind="stable")
    return float(np.trapezoid(ccr[order], fpr[order]))


def _ece(proba: np.ndarray, correct: np.ndarray, n_bins: int = 15) -> float:
    """Expected calibration error of the top class posterior."""
    if len(proba) == 0:
        return float("nan")
    conf = proba.max(axis=1)
    edges = np.linspace(0.0, 1.0, n_bins + 1)
    total = 0.0
    for lo, hi in zip(edges[:-1], edges[1:]):
        m = (conf > lo) & (conf <= hi)
        if not m.any():
            continue
        total += (m.mean() * abs(float(correct[m].mean()) - float(conf[m].mean())))
    return float(total)


# --------------------------------------------------------------------------- #
# Inlier scorers
# --------------------------------------------------------------------------- #

def _inner(clf):
    """The estimator at the end of a pipeline, or the estimator itself."""
    return clf[-1] if hasattr(clf, "__getitem__") and hasattr(clf, "steps") else clf


def _is_mlp(clf) -> bool:
    return type(_inner(clf)).__name__ == "MLPClassifier"


def _pre_output(clf, X: np.ndarray):
    """Hidden activations and output layer logits of a fitted MLP.

    scikit learn's ``MLPClassifier`` exposes ``predict_proba`` and no
    ``decision_function``, so the logits it computes internally are not
    reachable through the public interface. They are recovered here by
    replaying the forward pass from ``coefs_`` and ``intercepts_``. Two
    quantities come out of it. The second is the pre softmax output layer,
    which is what the free energy score is defined on. The first is the final
    hidden layer activation vector, which is what OpenMax is defined on, and
    which is non negative under the default rectified linear activation, the
    property the method's Weibull tail fit assumes.

    Returns ``(penultimate, logits)``.
    """
    mlp = _inner(clf)
    Z = clf[:-1].transform(X) if hasattr(clf, "steps") else X
    h = np.asarray(Z, dtype=float)
    acts = {"relu": lambda v: np.maximum(v, 0.0),
            "tanh": np.tanh,
            "logistic": lambda v: 1.0 / (1.0 + np.exp(-v)),
            "identity": lambda v: v}
    f = acts.get(mlp.activation, acts["relu"])
    n_layers = len(mlp.coefs_)
    for i in range(n_layers - 1):
        h = f(h @ mlp.coefs_[i] + mlp.intercepts_[i])
    logits = h @ mlp.coefs_[-1] + mlp.intercepts_[-1]
    if logits.ndim == 1:
        logits = np.column_stack([-logits, logits])
    return h, np.asarray(logits, dtype=float)


def _has_logits(clf) -> bool:
    """Whether the estimator exposes unnormalised per class scores.

    This distinction decides whether the energy score can be computed at all.
    Free energy is the log of the summed exponentiated logits, so it only
    carries information when the per class scores are unnormalised. Substituting
    log posteriors makes the sum equal to one by construction and the score
    collapses to a constant, which would be reported as an AUROC near one half
    and read as a finding when it is an artefact. Tree ensembles and the nearest
    neighbour classifier are therefore recorded as not applicable rather than
    given a meaningless number.

    The multilayer perceptron is a third case. It has no ``decision_function``
    but it does compute logits, which ``_pre_output`` recovers, so it counts as
    exposing them.
    """
    if _is_mlp(clf):
        return True
    return hasattr(_inner(clf), "decision_function")


def _has_penultimate(clf) -> bool:
    """Whether a hidden representation exists for OpenMax to be faithful on."""
    return _is_mlp(clf)


def _decision(clf, X: np.ndarray) -> np.ndarray:
    """Per class activation scores, logits where the estimator has them."""
    if _is_mlp(clf):
        return _pre_output(clf, X)[1]
    if hasattr(_inner(clf), "decision_function"):
        d = clf.decision_function(X)
        if d.ndim == 1:                     # binary case, lift to two columns
            d = np.column_stack([-d, d])
        return np.asarray(d, dtype=float)
    p = np.clip(np.asarray(clf.predict_proba(X), dtype=float), 1e-12, 1.0)
    return np.log(p)                        # log posteriors as activations


def _log_posteriors(clf, X: np.ndarray) -> np.ndarray:
    """Log posteriors, the activation substitute for normalised estimators."""
    p = np.clip(np.asarray(clf.predict_proba(X), dtype=float), 1e-12, 1.0)
    return np.log(p)


def _msp(ctx: Dict, X: np.ndarray) -> np.ndarray:
    return ctx["clf"].predict_proba(X).max(axis=1)


def _energy(ctx: Dict, X: np.ndarray) -> np.ndarray:
    from scipy.special import logsumexp
    if not _has_logits(ctx["clf"]):
        raise NotApplicable("estimator exposes no unnormalised class scores")
    return np.asarray(logsumexp(_decision(ctx["clf"], X), axis=1), dtype=float)


def _knn_dist(ctx: Dict, X: np.ndarray) -> np.ndarray:
    d, _ = ctx["nn"].kneighbors(ctx["scaler"].transform(X))
    return -d.mean(axis=1)


def _mahalanobis(ctx: Dict, X: np.ndarray) -> np.ndarray:
    Z = ctx["scaler"].transform(X)
    P = ctx["precision"]
    best = None
    for mu in ctx["class_means"]:
        delta = Z - mu
        d = np.einsum("ij,jk,ik->i", delta, P, delta)
        best = d if best is None else np.minimum(best, d)
    return -np.sqrt(np.maximum(best, 0.0))


def _iforest(ctx: Dict, X: np.ndarray) -> np.ndarray:
    return np.asarray(ctx["iforest"].score_samples(ctx["scaler"].transform(X)),
                      dtype=float)


def _openmax_core(A: np.ndarray, mav: np.ndarray, weib: np.ndarray,
                  alpha: int) -> np.ndarray:
    """One minus the recalibrated probability that the row is unknown.

    The activation vector is the per class score layer, which is what Bendale
    and Boult recalibrate. For each class a Weibull is fitted to the tail of
    the distances between the class mean activation vector and the correctly
    classified training rows of that class. The fitted cumulative distribution
    converts a query distance into the probability that the query is further
    from the class than its own training rows ever were, and the mass removed
    from the classes by that rescaling is collected into an unknown pseudo
    class.

    The method assumes activations on which removed mass is positive. Feeding
    it log posteriors, which are bounded above by zero, makes the unknown
    accumulator negative and inverts the score. That is why this core is called
    only with genuine logits, and why the log posterior variant is reported
    separately under its own name.
    """
    alpha = min(len(mav), alpha)
    dist = np.stack([np.linalg.norm(A - m, axis=1) for m in mav], axis=1)
    # Rank the classes per row; only the top alpha are rescaled, as in the
    # original formulation, because the tail fit is only meaningful for the
    # classes the row actually resembles.
    order = np.argsort(-A, axis=1)
    w = np.ones_like(A)
    for j in range(alpha):
        cls = order[:, j]
        shape, scale = weib[cls, 0], weib[cls, 1]
        d = dist[np.arange(len(A)), cls]
        # Weibull CDF in log space. Evaluating (d / scale) ** shape directly
        # overflows to infinity whenever a held out artifact sits far outside
        # the fitted tail, which is exactly the case this scorer exists to
        # handle. The exponent is formed as shape * log(d / scale) and clipped
        # before exponentiation, so a far outlier saturates the CDF at one,
        # which is its correct limit, instead of raising an overflow and
        # relying on the resulting infinity to behave.
        ratio = np.maximum(d, 0.0) / np.maximum(scale, 1e-12)
        log_ratio = np.log(np.maximum(ratio, 1e-300))
        exponent = np.clip(np.maximum(shape, 1e-12) * log_ratio, -700.0, 700.0)
        cdf = -np.expm1(-np.exp(exponent))
        modifier = 1.0 - cdf * (float(alpha - j) / float(alpha))
        w[np.arange(len(A)), cls] = modifier
    A_hat = A * w
    unknown = np.sum(A * (1.0 - w), axis=1)
    from scipy.special import softmax
    P = softmax(np.column_stack([A_hat, unknown]), axis=1)
    return 1.0 - P[:, -1]


def _openmax(ctx: Dict, X: np.ndarray) -> np.ndarray:
    """OpenMax as published, on genuine logits only."""
    clf = ctx["clf"]
    if not _has_logits(clf):
        raise NotApplicable(
            "OpenMax recalibrates unnormalised activations; this estimator "
            "exposes none, and substituting log posteriors inverts the score")
    return _openmax_core(_decision(clf, X), ctx["mav"], ctx["weibull"],
                         ctx["alpha"])


def _evt_posterior(ctx: Dict, X: np.ndarray) -> np.ndarray:
    """The log posterior adaptation of the OpenMax recalibration.

    Reported for every model so that the extreme value recalibration can be
    compared across the suite, and named separately because it is not the
    published method. On estimators whose activations are log posteriors the
    unknown accumulator is negative and the score is anti correlated with
    novelty, which is a property of this adaptation and not of OpenMax.
    """
    return _openmax_core(_log_posteriors(ctx["clf"], X), ctx["mav_post"],
                         ctx["weibull_post"], ctx["alpha"])


SCORERS = {
    "msp": _msp,
    "energy": _energy,
    "knn_dist": _knn_dist,
    "mahalanobis": _mahalanobis,
    "iforest": _iforest,
    "openmax": _openmax,
    "evt_posterior": _evt_posterior,
}


def _fit_context(clf, X_fit: np.ndarray, y_fit: np.ndarray, seed: int,
                 k: int, tail: int, alpha: int) -> Dict:
    """Fit everything the scorers need, once per fold."""
    from sklearn.covariance import LedoitWolf
    from sklearn.ensemble import IsolationForest
    from sklearn.neighbors import NearestNeighbors
    from sklearn.preprocessing import StandardScaler

    scaler = StandardScaler().fit(X_fit)
    Z = scaler.transform(X_fit)

    nn = NearestNeighbors(n_neighbors=min(k, len(Z))).fit(Z)

    classes = np.unique(y_fit)
    means = np.stack([Z[y_fit == c].mean(axis=0) for c in classes])
    # A tied covariance with Ledoit Wolf shrinkage. The feature count is close
    # to the per class row count, so the plain empirical covariance is singular
    # often enough that shrinkage is not optional.
    centred = np.concatenate([Z[y_fit == c] - means[i]
                              for i, c in enumerate(classes)])
    precision = LedoitWolf(assume_centered=True).fit(centred).precision_

    iforest = IsolationForest(n_estimators=300, random_state=seed).fit(Z)

    # Weibull tails for the extreme value recalibration, fitted on the
    # training rows the model gets right, which is what the method prescribes.
    # Two sets are fitted: one on genuine logits where the estimator has them,
    # which is what OpenMax uses, and one on log posteriors, which is what the
    # separately named adaptation uses.
    pred = clf.predict(X_fit)

    def _tails(A):
        mav, weibull = [], []
        for c in classes:
            m = (y_fit == c) & (pred == c)
            if m.sum() < 3:
                m = (y_fit == c)
            a = A[m]
            mu = a.mean(axis=0)
            d = np.linalg.norm(a - mu, axis=1)
            d = np.sort(d)[-min(tail, len(d)):]
            mav.append(mu)
            weibull.append(_fit_weibull(d))
        return np.stack(mav), np.asarray(weibull)

    mav_post, weibull_post = _tails(_log_posteriors(clf, X_fit))
    if _has_logits(clf):
        mav, weibull = _tails(_decision(clf, X_fit))
    else:
        mav, weibull = mav_post, weibull_post
    return {"clf": clf, "scaler": scaler, "nn": nn, "class_means": means,
            "precision": precision, "iforest": iforest,
            "mav": mav, "weibull": weibull,
            "mav_post": mav_post, "weibull_post": weibull_post,
            "alpha": alpha}


def _fit_weibull(d: np.ndarray) -> List[float]:
    """Shape and scale of a two parameter Weibull fitted to the tail.

    scipy is asked for a zero location fit, which is the right constraint for a
    distance, and a degenerate tail falls back to a shape of one so the
    recalibration stays finite rather than raising.
    """
    from scipy.stats import weibull_min
    d = np.asarray(d, dtype=float)
    d = d[np.isfinite(d)]
    if len(d) < 2 or np.allclose(d, d[0]):
        return [1.0, float(max(d.mean() if len(d) else 1.0, 1e-6))]
    try:
        shape, _, scale = weibull_min.fit(d, floc=0.0)
        if not (np.isfinite(shape) and np.isfinite(scale)) or scale <= 0:
            raise ValueError
        return [float(shape), float(scale)]
    except Exception:
        return [1.0, float(max(d.mean(), 1e-6))]


# --------------------------------------------------------------------------- #
# Protocol
# --------------------------------------------------------------------------- #

def run(data: str, models: List[str], seeds: List[int], feature_set: str,
        label_col: str, k: int, tail: int, alpha: int,
        holdout_col: str = "") -> Dict:
    """Leave one out open set evaluation.

    ``holdout_col`` decides what a novel class means, and it is the knob that
    separates two questions the literature usually runs together. When it is
    empty the unit held out is one value of ``label_col``, so holding out one
    parameterisation leaves its sibling parameterisations in training. When it
    names a coarser column, every label sharing that coarser value is held out
    together, so nothing from the same transformation family remains. The
    classification problem is identical in both cases. Only the definition of
    novel changes, which is what makes the comparison between the two
    interpretable.
    """
    import pandas as pd
    from sklearn.metrics import average_precision_score, roc_auc_score
    from sklearn.model_selection import GroupShuffleSplit

    df = pd.read_csv(data)
    cols = feature_names(FEATURE_SETS[feature_set])
    X = np.nan_to_num(df[cols].to_numpy(dtype=float),
                      nan=0.0, posinf=0.0, neginf=0.0)
    y = df[label_col].to_numpy()
    groups = df["sample_id"].to_numpy()
    hold_on = df[holdout_col].to_numpy() if holdout_col else y
    held = sorted(set(hold_on.tolist()))

    folds: List[Dict] = []
    for model_name in models:
        for seed in seeds:
            for holdout in held:
                known = np.where(hold_on != holdout)[0]
                novel = np.where(hold_on == holdout)[0]
                if len(set(y[known].tolist())) < 2 or len(novel) == 0:
                    continue
                gss = GroupShuffleSplit(n_splits=1, test_size=0.2,
                                        random_state=seed)
                a, b = next(gss.split(known, groups=groups[known]))
                fit_idx, eval_idx = known[a], known[b]
                if len(set(y[fit_idx].tolist())) < 2 or len(eval_idx) == 0:
                    continue

                clf = build_model(model_name, seed)
                clf.fit(X[fit_idx], y[fit_idx])
                ctx = _fit_context(clf, X[fit_idx], y[fit_idx], seed, k, tail,
                                   alpha)

                correct = (clf.predict(X[eval_idx]) == y[eval_idx])
                proba = clf.predict_proba(X[eval_idx])
                row = {
                    "model": model_name, "seed": int(seed),
                    "novel_class": str(holdout),
                    "n_fit": int(len(fit_idx)),
                    "n_known_eval": int(len(eval_idx)),
                    "n_novel": int(len(novel)),
                    "n_known_classes": int(len(set(y[fit_idx].tolist()))),
                    "closed_accuracy": float(correct.mean()),
                    "ece": _ece(proba, correct),
                    "scorers": {},
                }
                for name, fn in SCORERS.items():
                    try:
                        s_known = np.asarray(fn(ctx, X[eval_idx]), dtype=float)
                        s_novel = np.asarray(fn(ctx, X[novel]), dtype=float)
                    except NotApplicable as exc:
                        row["scorers"][name] = {"not_applicable": str(exc)}
                        continue
                    except Exception as exc:               # record, do not hide
                        row["scorers"][name] = {"error": repr(exc)}
                        continue
                    nk, nn_ = -s_known, -s_novel           # novelty direction
                    truth = np.concatenate([np.zeros(len(nk)), np.ones(len(nn_))])
                    score = np.concatenate([nk, nn_])
                    if not np.all(np.isfinite(score)):
                        row["scorers"][name] = {"error": "non finite scores"}
                        continue
                    row["scorers"][name] = {
                        "auroc": float(roc_auc_score(truth, score)),
                        "aupr_novel": float(average_precision_score(truth, score)),
                        "aupr_known": float(average_precision_score(1 - truth,
                                                                    -score)),
                        "fpr_at_95tpr": _fpr_at_tpr(nk, nn_, 0.95),
                        "oscr": _oscr(s_known, correct, s_novel),
                        "mean_inlier_known": float(np.mean(s_known)),
                        "mean_inlier_novel": float(np.mean(s_novel)),
                    }
                folds.append(row)

    return {"data": data, "feature_set": feature_set, "label": label_col,
            "holdout_unit": holdout_col or label_col,
            "n_rows": int(len(df)), "n_features": len(cols),
            "n_groups": int(len(set(groups.tolist()))),
            "models": models, "seeds": [int(s) for s in seeds],
            "knn_k": k, "weibull_tail": tail, "openmax_alpha": alpha,
            "per_fold": folds,
            "summary": _summarise(folds)}


def _summarise(folds: List[Dict]) -> Dict:
    """Mean and spread per model and scorer, pooled over folds and seeds."""
    out: Dict = {}
    keys = ["auroc", "aupr_novel", "aupr_known", "fpr_at_95tpr", "oscr"]
    for model in sorted({f["model"] for f in folds}):
        sel = [f for f in folds if f["model"] == model]
        entry = {
            "closed_accuracy_mean": float(np.mean([f["closed_accuracy"]
                                                   for f in sel])),
            "ece_mean": float(np.mean([f["ece"] for f in sel])),
            "n_folds": len(sel),
            "scorers": {},
        }
        for name in SCORERS:
            vals = {k: [f["scorers"][name][k] for f in sel
                        if k in f["scorers"].get(name, {})] for k in keys}
            if not vals["auroc"]:
                na = sorted({f["scorers"][name]["not_applicable"] for f in sel
                             if "not_applicable" in f["scorers"].get(name, {})})
                if na:
                    entry["scorers"][name] = {"not_applicable": "; ".join(na)}
                    continue
                errs = sorted({f["scorers"][name].get("error", "")
                               for f in sel if "error" in f["scorers"].get(name, {})})
                entry["scorers"][name] = {"error": "; ".join(e for e in errs if e)}
                continue
            entry["scorers"][name] = {
                f"{k}_{stat}": float(getattr(np, stat)(vals[k]))
                for k in keys for stat in ("mean", "std")
                if vals[k]
            }
        out[model] = entry
    return out


# --------------------------------------------------------------------------- #
# Reporting
# --------------------------------------------------------------------------- #

def report(res: Dict) -> None:
    print(f"rows {res['n_rows']}  features {res['n_features']}  "
          f"groups {res['n_groups']}  label {res['label']}  "
          f"novel unit {res['holdout_unit']}")
    print(f"folds {len(res['per_fold'])}  seeds {res['seeds']}")
    for model, m in res["summary"].items():
        print()
        print(f"{model}   closed accuracy {m['closed_accuracy_mean']:.4f}   "
              f"calibration error {m['ece_mean']:.4f}   folds {m['n_folds']}")
        print(f"  {'scorer':<13}{'AUROC':>16}{'AUPR novel':>16}"
              f"{'FPR@95TPR':>16}{'OSCR':>16}")
        for name in SCORERS:
            s = m["scorers"].get(name, {})
            if "not_applicable" in s:
                print(f"  {name:<13}{'not applicable':>16}")
                continue
            if "error" in s:
                print(f"  {name:<13}{s['error']:>16}")
                continue
            print(f"  {name:<13}"
                  f"{s['auroc_mean']:>9.4f} {s['auroc_std']:.4f} "
                  f"{s['aupr_novel_mean']:>9.4f} {s['aupr_novel_std']:.4f} "
                  f"{s['fpr_at_95tpr_mean']:>9.4f} {s['fpr_at_95tpr_std']:.4f} "
                  f"{s['oscr_mean']:>9.4f} {s['oscr_std']:.4f}")
    print()
    print("AUROC and OSCR larger is better. FPR@95TPR smaller is better.")
    print("Values printed as mean then standard deviation over folds and seeds.")


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(
        description="Open set recognition baselines under leave one "
                    "transformation out.")
    ap.add_argument("--data", default="data/features_pilot.csv")
    ap.add_argument("--models", nargs="+",
                    default=["random_forest", "logreg", "knn"])
    ap.add_argument("--seeds", nargs="+", type=int, default=[0, 1, 2, 3, 4])
    ap.add_argument("--feature-set", default="all", choices=list(FEATURE_SETS))
    ap.add_argument("--label", default="technique",
                    choices=["technique", "sub_technique"])
    ap.add_argument("--holdout-col", default="",
                    help="Column defining a novel class. Defaults to --label. "
                         "Set to technique while --label is sub_technique to "
                         "hold out whole transformation families and leave no "
                         "sibling parameterisation in training.")
    ap.add_argument("--knn-k", type=int, default=5)
    ap.add_argument("--weibull-tail", type=int, default=20)
    ap.add_argument("--openmax-alpha", type=int, default=3)
    ap.add_argument("--report", default="")
    args = ap.parse_args(argv)

    res = run(args.data, args.models, args.seeds, args.feature_set, args.label,
              args.knn_k, args.weibull_tail, args.openmax_alpha,
              args.holdout_col)
    report(res)
    if args.report:
        os.makedirs(os.path.dirname(args.report) or ".", exist_ok=True)
        with open(args.report, "w") as fh:
            json.dump(res, fh, indent=2)
        print(f"wrote {args.report}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
