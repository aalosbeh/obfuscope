"""
Open set recognition baselines for transformation attribution.

Version 1 of the paper scored novelty with one quantity, the maximum class
posterior, and reported one metric, AUROC. That is the weakest published
baseline measured by the most forgiving metric, so a reader cannot tell whether
the reported number says something about the features or only about the scorer.
This script replaces that single measurement with seven scorers and several
metrics evaluated under one protocol.

Scorers
-------
msp           Maximum class posterior. Hendrycks and Gimpel, ICLR 2017.
energy        Log sum exp of the per class scores (the negative free energy).
              Liu et al., NeurIPS 2020. Only defined where the estimator
              exposes unnormalised per class scores; see "Per class scores"
              below for what those are for each estimator.
knn_dist      Negative MEAN Euclidean distance to the k nearest fitting rows,
              in the StandardScaler space fitted on the fitting rows. This is
              the mean over the k neighbours, not the distance to the k-th
              neighbour that the deep nearest neighbour baseline benchmarked in
              OpenOOD uses; the two orderings can differ.
mahalanobis   Negative smallest class conditional Mahalanobis distance under a
              tied Ledoit Wolf covariance. Lee et al., NeurIPS 2018.
iforest       Isolation Forest score_samples (negative anomaly score).
              Liu et al., ICDM 2008.
openmax       Extreme value recalibration of the per class score vector against
              a Weibull fitted to the tail of the correctly classified fitting
              distances. Bendale and Boult, CVPR 2016. Deviations from the
              reference implementation: Euclidean rather than eucos distance,
              scipy weibull_min with zero location rather than libMR, and a
              fallback to all class rows when fewer than three are correct.
evt_posterior The OpenMax core applied to LOG POSTERIORS. It is not the
              published method and it is INVERTED BY CONSTRUCTION for every
              estimator: log posteriors are <= 0, so the unknown accumulator
              sum(A * (1 - w)) is <= 0 and, holding the activations fixed, a
              larger Weibull CDF (a row further from every class) RAISES the
              inlier score. It is still computed so that existing reports can be
              regenerated, but its AUROC is not evidence about extreme value
              recalibration and must not be read as such.

Every scorer returns an inlier score where larger means more likely to belong
to a transformation the model was trained on, so the metrics below read the
same way for all seven.

Per class scores
----------------
energy and openmax need unnormalised per class scores. For logreg these are
the decision function (linear logits). For mlp they are the pre softmax output
layer recovered by replaying the forward pass. For svm_rbf they are scikit
learn's ``decision_function`` with the default ``decision_function_shape='ovr'``,
which is NOT a set of one-vs-rest margins: it is the one-vs-rest aggregation of
the one-vs-one classifiers, i.e. each class's one-vs-one VOTE COUNT plus a
bounded confidence term (strictly inside (-1/3, 1/3)) derived from the
one-vs-one decision values. Energy and openmax on svm_rbf therefore operate on
vote counts plus bounded confidences, and ``SVC.predict`` (which uses the same
votes) can disagree with ``argmax(predict_proba)`` (Platt scaled). Tree
ensembles and knn expose no such scores and are reported as not applicable.

Metrics
-------
auroc            Area under the receiver operating characteristic, novel
                 positive.
aupr_novel       Average precision with the novel class positive. Unlike AUROC
                 this moves when the novel class is rare, which is the realistic
                 case; read it next to ``novel_prevalence``.
aupr_known       Average precision with the known class positive.
fpr95_known_pos  OpenOOD convention, and the quantity the manuscript text
                 describes: the fraction of NOVEL rows accepted as known at the
                 threshold that retains 95 percent of KNOWN rows (known is the
                 positive class). ``tpr95_achieved_known_pos`` records the
                 fraction of known rows actually retained at that threshold.
                 It is not exactly 0.95: interpolating between order
                 statistics can leave it slightly below (for n rows, down to
                 (n - ceil(0.05 (n - 1))) / n), and ties can push it above,
                 up to 1.0.
fpr95_novel_pos  The quantity earlier versions computed: the fraction of KNOWN
                 rows flagged novel at the threshold that detects 95 percent of
                 NOVEL rows (novel is the positive class). It sets how much
                 known traffic lands in the review queue.
                 ``tpr95_achieved_novel_pos`` records the fraction of novel rows
                 actually detected at that threshold.
fpr_at_95tpr     Legacy key, kept for backward compatibility and always equal
                 to ``fpr95_novel_pos``.
oscr             Area under the open set classification rate curve, which
                 charges the model for closed set mistakes as well as for
                 accepting novel rows. Dhamija et al., NeurIPS 2018. Equal to
                 the Mann Whitney form: the probability that a correctly
                 classified known row outscores a novel row, ties counted half,
                 normalised by ALL known rows.

A calibration error (15 equal width bins) is also reported for the closed set
posteriors on the known evaluation rows, because msp and energy both inherit
whatever miscalibration the classifier has. Guo et al., ICML 2017.

Correctness for ``ece`` and ``oscr`` is argmax(predict_proba) == true label, so
that it refers to the same posterior whose maximum is the confidence.
``closed_accuracy`` is still computed from ``predict()`` for backward
compatibility, and ``closed_accuracy_argmax`` from argmax(predict_proba). The
two differ only for svm_rbf, whose ``predict`` uses one-vs-one votes.

Protocol
--------
Leave one transformation out. Each transformation in turn (each value of
``--holdout-col``, by default of ``--label``) is removed from training and its
artifacts become the novel class at evaluation time. The known rows are split
by input program (``sample_id``) so that no input program contributes rows to
both the fitting set and the known evaluation set. Without the grouping
constraint a known evaluation row can be a sibling variant of a fitting row and
the known side of the comparison becomes trivially easy.

``--split gss`` (default) is the original single GroupShuffleSplit with
test_size 0.2 and random_state equal to the seed, applied to the known rows.
``--split program_kfold`` permutes the sorted unique programs with
``np.random.RandomState(seed).permutation``, cuts them into ``--n-blocks``
blocks with ``np.array_split``, and for each block and each held out unit fits
on the known rows of the programs outside the block and evaluates the known
and novel rows of the programs inside it, so that every novel row is scored
once per seed by a model that never saw its input program.

The same sibling argument applies to the novel side. ``--novel-programs
heldout`` (default) restricts the novel rows to the input programs of the known
evaluation split (for program_kfold, the programs of the block), so the known
and novel evaluation rows come from the same programs and none of those
programs contributed rows to fitting. ``--novel-programs all`` reproduces the
behaviour of earlier versions, in which the novel set was every artifact of the
held out unit from every program, so that most novel rows came from programs
whose other artifacts were in the fitting set, while every known evaluation row
came from an unseen program. Each fold records ``n_novel`` and
``novel_prevalence`` = n_novel / (n_novel + n_known_eval).

The whole protocol repeats over several seeds and the spread across folds and
seeds is reported, because a protocol over four to ten held out units has
enough sampling noise that a single run is not informative.

Usage
-----
    python3 scripts/openset_baselines.py \\
        --data data/features_pilot.csv \\
        --models random_forest logreg knn \\
        --seeds 0 1 2 3 4 \\
        --split program_kfold --novel-programs heldout \\
        --report results/openset_baselines.json

To regenerate the earlier reports (novel rows from every program, one
GroupShuffleSplit per seed) pass ``--split gss --novel-programs all``.
"""
from __future__ import annotations

import argparse
import json
import os
import sys
from typing import Dict, Iterator, List, Tuple

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

    This is the NOVEL-POSITIVE convention (``fpr95_novel_pos``, legacy key
    ``fpr_at_95tpr``). Computed from the empirical quantile of the novel scores
    rather than by interpolating a sampled curve, so the answer does not depend
    on how finely the curve was sampled. Kept with its original signature and
    behaviour; :func:`fpr_at_tpr` is the general form that also returns the
    achieved TPR.
    """
    if len(novelty_novel) == 0 or len(novelty_known) == 0:
        return float("nan")
    thr = float(np.quantile(novelty_novel, 1.0 - target_tpr))
    return float(np.mean(novelty_known >= thr))


def fpr_at_tpr(pos_scores: np.ndarray, neg_scores: np.ndarray,
               target_tpr: float = 0.95) -> Tuple[float, float]:
    """False positive rate at a target true positive rate, and the TPR achieved.

    ``pos_scores`` and ``neg_scores`` are scores of the positive and negative
    class, larger meaning more positive. The threshold is the empirical
    ``1 - target_tpr`` quantile of the positive scores (numpy's default linear
    interpolation) and a row is called positive when its score is ``>=`` the
    threshold. Returns ``(fpr, achieved_tpr)``, where ``fpr`` is the fraction of
    negative rows called positive and ``achieved_tpr`` the fraction of positive
    rows called positive. The achieved TPR is not exactly the target: the
    interpolated threshold can sit above the order statistic it was
    interpolated from, which leaves it as low as
    ``(n - ceil((1 - target_tpr) * (n - 1))) / n`` for n positive rows, and
    ties at the threshold can push it above the target, up to 1.0. It is
    therefore reported next to the FPR.

    The two conventions used in this script are
      novel positive: ``fpr_at_tpr(-s_novel, -s_known)`` = fraction of known rows
                      flagged novel at 95 percent novel detection, identical to
                      ``_fpr_at_tpr(-s_known, -s_novel)``;
      known positive: ``fpr_at_tpr(s_known, s_novel)`` = fraction of novel rows
                      accepted as known at 95 percent known retention (OpenOOD).
    where ``s_known`` and ``s_novel`` are inlier scores.
    """
    pos = np.asarray(pos_scores, dtype=float)
    neg = np.asarray(neg_scores, dtype=float)
    if len(pos) == 0 or len(neg) == 0:
        return float("nan"), float("nan")
    thr = float(np.quantile(pos, 1.0 - target_tpr))
    return float(np.mean(neg >= thr)), float(np.mean(pos >= thr))


def _oscr(inlier_known: np.ndarray, correct_known: np.ndarray,
          inlier_novel: np.ndarray) -> float:
    """Area under the open set classification rate curve.

    Sweeping the acceptance threshold over every observed score, the curve
    plots the fraction of known rows that are both accepted and classified
    correctly against the fraction of novel rows wrongly accepted. A model that
    rejects novel rows by refusing to classify anything scores zero, which is
    the property AUROC lacks.

    The trapezoidal area equals the Mann Whitney form
    ``sum_{i correct known} sum_{j novel} [s_i > s_j] + 0.5 [s_i == s_j]``
    divided by ``n_known * n_novel`` (see :func:`oscr_mann_whitney`).
    ``correct_known`` should be argmax(predict_proba) == label so that the
    correctness refers to the same posterior as the msp confidence.
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


def oscr_mann_whitney(inlier_known: np.ndarray, correct_known: np.ndarray,
                      inlier_novel: np.ndarray) -> float:
    """Closed form of :func:`_oscr`, used as a cross check in the tests.

    The probability that a known row is classified correctly AND outscores a
    random novel row, ties counted half, normalised by all known rows.
    """
    sk = np.asarray(inlier_known, dtype=float)
    sn = np.asarray(inlier_novel, dtype=float)
    ck = np.asarray(correct_known, dtype=bool)
    if len(sk) == 0 or len(sn) == 0:
        return float("nan")
    sc = sk[ck]
    gt = (sc[:, None] > sn[None, :]).sum()
    eq = (sc[:, None] == sn[None, :]).sum()
    return float((gt + 0.5 * eq) / (len(sk) * len(sn)))


def _ece(proba: np.ndarray, correct: np.ndarray, n_bins: int = 15) -> float:
    """Expected calibration error of the top class posterior.

    Rows are binned by ``max(proba)`` into ``n_bins`` equal width bins over
    (0, 1] (a row with confidence exactly 0 falls in no bin), and the error is
    the bin mass weighted mean of |accuracy - mean confidence|. ``correct``
    must be argmax(proba) == label for the accuracy to refer to the class whose
    probability is the confidence.
    """
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
    which is what both the free energy score and OpenMax consume in this
    script (``_decision`` returns it; OpenMax's activation vector is the per
    class score layer, as in Bendale and Boult). The first is the final hidden
    layer activation vector; it is returned but not used by any scorer, and
    ``_has_penultimate`` is likewise unused. Note that MLP logits can be
    negative, so the non negativity OpenMax assumes is not guaranteed for the
    MLP either.

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

    The kernel SVM counts as exposing them because ``SVC`` has a
    ``decision_function``, but with the default ``decision_function_shape``
    of ``'ovr'`` those values are NOT one-vs-rest margins: scikit learn
    aggregates the one-vs-one classifiers into one-vs-one VOTE COUNTS per class
    plus a bounded confidence term in (-1/3, 1/3). They are unnormalised, but
    they are votes, not logits.
    """
    if _is_mlp(clf):
        return True
    return hasattr(_inner(clf), "decision_function")


def _has_penultimate(clf) -> bool:
    """Whether a hidden representation exists for OpenMax to be faithful on."""
    return _is_mlp(clf)


def _decision(clf, X: np.ndarray) -> np.ndarray:
    """Per class activation scores.

    logreg: linear decision function. mlp: replayed pre softmax logits.
    svm_rbf: one-vs-rest aggregation of one-vs-one votes plus bounded
    confidences (see ``_has_logits``), not margins. Estimators with neither
    fall back to log posteriors, which energy and openmax refuse to use.
    """
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
    """Negative MEAN Euclidean distance to the k nearest fitting rows.

    Distances are measured in the StandardScaler space fitted on the fitting
    rows only. This is the mean over the k neighbours, not the distance to the
    k-th neighbour.
    """
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
    accumulator negative and inverts the score. That is why ``openmax`` calls
    this core only with unnormalised per class scores, and why the log
    posterior variant is reported separately under its own name
    (``evt_posterior``), which is inverted by construction. Even the
    unnormalised scores are not guaranteed non negative: MLP logits can be
    negative, and the svm_rbf ovr values (votes plus a confidence in
    (-1/3, 1/3)) can be slightly negative for a class with no votes.
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

    INVERTED BY CONSTRUCTION. This applies the OpenMax core to log posteriors
    for every estimator. Log posteriors are <= 0, so the unknown accumulator
    ``sum(A * (1 - w))`` is <= 0 for every row, and, holding the activation
    vector fixed, a larger Weibull CDF (a row further from the class means)
    RAISES the returned inlier score instead of lowering it. Its AUROC is
    therefore not evidence about extreme value recalibration and not
    evidence about the estimator; it is kept only so that earlier reports can
    be regenerated, and is named separately because it is not the published
    method.
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

SPLITS = ("gss", "program_kfold")
NOVEL_PROGRAMS = ("heldout", "all")

FPR95_CONVENTIONS = {
    "fpr95_known_pos": "fraction of NOVEL rows accepted as known at the "
                       "threshold retaining 95% of KNOWN rows (known positive, "
                       "OpenOOD convention; the quantity the manuscript text "
                       "describes)",
    "fpr95_novel_pos": "fraction of KNOWN rows flagged novel at the threshold "
                       "detecting 95% of NOVEL rows (novel positive; the "
                       "quantity earlier versions reported)",
    "fpr_at_95tpr": "legacy key, equal to fpr95_novel_pos",
    "tpr95_achieved_*": "TPR actually achieved at the 95% threshold of the "
                        "matching convention; interpolation can leave it "
                        "slightly below 0.95 and ties can push it above, up "
                        "to 1.0",
}


def iter_openset_splits(hold_on: np.ndarray, y: np.ndarray, groups: np.ndarray,
                        seed: int, split: str = "gss",
                        novel_programs: str = "heldout",
                        n_blocks: int = 5) -> Iterator[Dict]:
    """Index sets of every open set fold for one seed, without fitting anything.

    Yields one dict per fold with keys ``novel_class``, ``block`` (``None``
    under gss), ``fit_idx``, ``eval_idx`` (known evaluation rows),
    ``novel_idx``, ``novel_all_idx`` (every row of the held out unit) and
    ``eval_programs`` (sorted program ids of the evaluation side).

    split
        ``gss``: GroupShuffleSplit(n_splits=1, test_size=0.2,
        random_state=seed) over the known rows grouped by program, exactly as
        in earlier versions. ``program_kfold``: the sorted unique programs are
        permuted with ``np.random.RandomState(seed).permutation`` and cut into
        ``n_blocks`` blocks with ``np.array_split``; for each held out unit and
        each block the fit rows are the known rows of programs outside the
        block, and the evaluation rows are the known rows of programs inside
        it.
    novel_programs
        ``heldout``: novel rows are restricted to the evaluation programs (the
        programs of the known evaluation rows under gss; the programs of the
        block under program_kfold), so no novel row comes from a program that
        contributed rows to fitting. ``all``: every row of the held out unit,
        from every program, as in earlier versions.

    Folds whose fitting side has fewer than two classes, or whose known or
    novel evaluation side is empty, are skipped, as before.
    """
    from sklearn.model_selection import GroupShuffleSplit

    if split not in SPLITS:
        raise ValueError(f"unknown split {split!r}; choices {SPLITS}")
    if novel_programs not in NOVEL_PROGRAMS:
        raise ValueError(f"unknown novel_programs {novel_programs!r}; "
                         f"choices {NOVEL_PROGRAMS}")
    hold_on = np.asarray(hold_on)
    y = np.asarray(y)
    groups = np.asarray(groups)
    held = sorted(set(hold_on.tolist()))

    blocks = None
    if split == "program_kfold":
        progs = np.array(sorted(set(groups.tolist())))
        if not 2 <= n_blocks <= len(progs):
            raise ValueError(f"n_blocks must be in [2, {len(progs)}]")
        perm = progs[np.random.RandomState(seed).permutation(len(progs))]
        blocks = np.array_split(perm, n_blocks)

    for holdout in held:
        known = np.where(hold_on != holdout)[0]
        novel = np.where(hold_on == holdout)[0]
        if len(set(y[known].tolist())) < 2 or len(novel) == 0:
            continue
        if split == "gss":
            gss = GroupShuffleSplit(n_splits=1, test_size=0.2,
                                    random_state=seed)
            a, b = next(gss.split(known, groups=groups[known]))
            units = [(None, known[a], known[b],
                      np.array(sorted(set(groups[known[b]].tolist()))))]
        else:
            units = []
            for j, blk in enumerate(blocks):
                in_blk = np.isin(groups[known], blk)
                units.append((j, known[~in_blk], known[in_blk],
                              np.array(sorted(blk.tolist()))))
        for block, fit_idx, eval_idx, eval_progs in units:
            if len(set(y[fit_idx].tolist())) < 2 or len(eval_idx) == 0:
                continue
            if novel_programs == "heldout":
                novel_idx = novel[np.isin(groups[novel], eval_progs)]
            else:
                novel_idx = novel
            if len(novel_idx) == 0:
                continue
            yield {"novel_class": holdout, "block": block,
                   "fit_idx": fit_idx, "eval_idx": eval_idx,
                   "novel_idx": novel_idx, "novel_all_idx": novel,
                   "eval_programs": eval_progs}


def _scorer_metrics(s_known: np.ndarray, s_novel: np.ndarray,
                    correct: np.ndarray, correct_predict: np.ndarray) -> Dict:
    """Every per scorer metric from inlier scores on known and novel rows."""
    from sklearn.metrics import average_precision_score, roc_auc_score
    nk, nn_ = -s_known, -s_novel                   # novelty direction
    truth = np.concatenate([np.zeros(len(nk)), np.ones(len(nn_))])
    score = np.concatenate([nk, nn_])
    if not np.all(np.isfinite(score)):
        return {"error": "non finite scores"}
    fpr_np, tpr_np = fpr_at_tpr(nn_, nk, 0.95)      # novel positive
    fpr_kp, tpr_kp = fpr_at_tpr(s_known, s_novel, 0.95)   # known positive
    return {
        "auroc": float(roc_auc_score(truth, score)),
        "aupr_novel": float(average_precision_score(truth, score)),
        "aupr_known": float(average_precision_score(1 - truth, -score)),
        "fpr_at_95tpr": fpr_np,                    # legacy key
        "fpr95_novel_pos": fpr_np,
        "tpr95_achieved_novel_pos": tpr_np,
        "fpr95_known_pos": fpr_kp,
        "tpr95_achieved_known_pos": tpr_kp,
        "oscr": _oscr(s_known, correct, s_novel),
        # OSCR with predict() correctness, as computed by earlier versions.
        # Differs from ``oscr`` only where predict() != argmax(predict_proba).
        "oscr_legacy_predict": _oscr(s_known, correct_predict, s_novel),
        "mean_inlier_known": float(np.mean(s_known)),
        "mean_inlier_novel": float(np.mean(s_novel)),
    }


def run(data: str, models: List[str], seeds: List[int], feature_set: str,
        label_col: str, k: int, tail: int, alpha: int,
        holdout_col: str = "", novel_programs: str = "heldout",
        split: str = "gss", n_blocks: int = 5) -> Dict:
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

    ``split`` and ``novel_programs`` are described in
    :func:`iter_openset_splits`. ``split='gss', novel_programs='all'``
    reproduces earlier versions of this script.
    """
    import pandas as pd

    df = pd.read_csv(data)
    cols = feature_names(FEATURE_SETS[feature_set])
    X = np.nan_to_num(df[cols].to_numpy(dtype=float),
                      nan=0.0, posinf=0.0, neginf=0.0)
    y = df[label_col].to_numpy()
    groups = df["sample_id"].to_numpy()
    hold_on = df[holdout_col].to_numpy() if holdout_col else y

    folds: List[Dict] = []
    for model_name in models:
        for seed in seeds:
            for sp in iter_openset_splits(hold_on, y, groups, seed, split,
                                          novel_programs, n_blocks):
                fit_idx, eval_idx = sp["fit_idx"], sp["eval_idx"]
                novel = sp["novel_idx"]

                clf = build_model(model_name, seed)
                clf.fit(X[fit_idx], y[fit_idx])
                ctx = _fit_context(clf, X[fit_idx], y[fit_idx], seed, k, tail,
                                   alpha)

                correct_predict = (clf.predict(X[eval_idx]) == y[eval_idx])
                proba = clf.predict_proba(X[eval_idx])
                pred_argmax = np.asarray(clf.classes_)[np.argmax(proba, axis=1)]
                # Correctness of the class whose posterior is the confidence.
                correct = (pred_argmax == y[eval_idx])
                n_known_eval, n_novel = int(len(eval_idx)), int(len(novel))
                fit_progs = set(groups[fit_idx].tolist())
                row = {
                    "model": model_name, "seed": int(seed),
                    "novel_class": str(sp["novel_class"]),
                    "n_fit": int(len(fit_idx)),
                    "n_known_eval": n_known_eval,
                    "n_novel": n_novel,
                    "n_known_classes": int(len(set(y[fit_idx].tolist()))),
                    "closed_accuracy": float(correct_predict.mean()),
                    "closed_accuracy_argmax": float(correct.mean()),
                    "ece": _ece(proba, correct),
                    "ece_legacy_predict": _ece(proba, correct_predict),
                    "split": split,
                    "block": sp["block"],
                    "novel_programs": novel_programs,
                    "novel_prevalence": float(n_novel / (n_novel + n_known_eval)),
                    "n_novel_all_programs": int(len(sp["novel_all_idx"])),
                    "n_fit_programs": int(len(fit_progs)),
                    "n_eval_programs": int(len(sp["eval_programs"])),
                    "n_novel_programs": int(len(set(groups[novel].tolist()))),
                    "n_novel_from_fit_programs": int(np.isin(
                        groups[novel], list(fit_progs)).sum()),
                    "eval_programs": [str(p) for p in sp["eval_programs"]],
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
                    row["scorers"][name] = _scorer_metrics(
                        s_known, s_novel, correct, correct_predict)
                folds.append(row)

    return {"data": data, "feature_set": feature_set, "label": label_col,
            "holdout_unit": holdout_col or label_col,
            "n_rows": int(len(df)), "n_features": len(cols),
            "n_groups": int(len(set(groups.tolist()))),
            "models": models, "seeds": [int(s) for s in seeds],
            "knn_k": k, "weibull_tail": tail, "openmax_alpha": alpha,
            "split": split,
            "n_blocks": int(n_blocks) if split == "program_kfold" else None,
            "novel_programs": novel_programs,
            "correctness": "ece and oscr use argmax(predict_proba) == label; "
                           "closed_accuracy uses predict(); "
                           "closed_accuracy_argmax uses argmax(predict_proba)",
            "fpr95_conventions": FPR95_CONVENTIONS,
            "per_fold": folds,
            "summary": _summarise(folds)}


SUMMARY_KEYS = ["auroc", "aupr_novel", "aupr_known", "fpr_at_95tpr",
                "fpr95_novel_pos", "tpr95_achieved_novel_pos",
                "fpr95_known_pos", "tpr95_achieved_known_pos", "oscr"]


def _summarise(folds: List[Dict]) -> Dict:
    """Mean and spread per model and scorer, pooled over folds and seeds.

    Spreads are population standard deviations (numpy's default ddof=0) over
    every fold of every seed, as in earlier versions.
    """
    out: Dict = {}
    keys = SUMMARY_KEYS
    for model in sorted({f["model"] for f in folds}):
        sel = [f for f in folds if f["model"] == model]
        prev = [f["novel_prevalence"] for f in sel]
        n_nov = [f["n_novel"] for f in sel]
        entry = {
            "closed_accuracy_mean": float(np.mean([f["closed_accuracy"]
                                                   for f in sel])),
            "closed_accuracy_argmax_mean": float(np.mean(
                [f["closed_accuracy_argmax"] for f in sel])),
            "ece_mean": float(np.mean([f["ece"] for f in sel])),
            "n_folds": len(sel),
            "novel_prevalence_mean": float(np.mean(prev)),
            "novel_prevalence_std": float(np.std(prev)),
            "n_novel_mean": float(np.mean(n_nov)),
            "n_novel_min": int(np.min(n_nov)),
            "n_novel_max": int(np.max(n_nov)),
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
    print(f"split {res['split']}"
          + (f" ({res['n_blocks']} blocks)" if res.get("n_blocks") else "")
          + f"  novel programs {res['novel_programs']}")
    print(f"folds {len(res['per_fold'])}  seeds {res['seeds']}")
    for model, m in res["summary"].items():
        print()
        print(f"{model}   closed accuracy {m['closed_accuracy_mean']:.4f} "
              f"(argmax {m['closed_accuracy_argmax_mean']:.4f})   "
              f"calibration error {m['ece_mean']:.4f}   folds {m['n_folds']}   "
              f"novel prevalence {m['novel_prevalence_mean']:.4f}")
        print(f"  {'scorer':<13}{'AUROC':>16}{'AUPR novel':>16}"
              f"{'FPR95 known+':>16}{'FPR95 novel+':>16}{'OSCR':>16}")
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
                  f"{s['fpr95_known_pos_mean']:>9.4f} {s['fpr95_known_pos_std']:.4f} "
                  f"{s['fpr95_novel_pos_mean']:>9.4f} {s['fpr95_novel_pos_std']:.4f} "
                  f"{s['oscr_mean']:>9.4f} {s['oscr_std']:.4f}")
    print()
    print("AUROC and OSCR larger is better. Both FPR95 columns smaller is better.")
    print("FPR95 known+ : novel rows accepted at 95% known retention (OpenOOD).")
    print("FPR95 novel+ : known rows flagged at 95% novel detection "
          "(legacy fpr_at_95tpr).")
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
    ap.add_argument("--novel-programs", default="heldout",
                    choices=list(NOVEL_PROGRAMS),
                    help="heldout (default): novel rows only from the input "
                         "programs of the known evaluation split, none of "
                         "which contributed rows to fitting. all: novel rows "
                         "from every program, as in earlier versions.")
    ap.add_argument("--split", default="gss", choices=list(SPLITS),
                    help="gss (default): one GroupShuffleSplit(test_size=0.2, "
                         "random_state=seed) of the known rows by program, as "
                         "in earlier versions. program_kfold: programs "
                         "permuted per seed and cut into --n-blocks blocks; "
                         "each block is evaluated by a model fitted on the "
                         "other blocks' known rows.")
    ap.add_argument("--n-blocks", type=int, default=5,
                    help="number of program blocks for --split program_kfold")
    ap.add_argument("--knn-k", type=int, default=5)
    ap.add_argument("--weibull-tail", type=int, default=20)
    ap.add_argument("--openmax-alpha", type=int, default=3)
    ap.add_argument("--report", default="")
    args = ap.parse_args(argv)

    res = run(args.data, args.models, args.seeds, args.feature_set, args.label,
              args.knn_k, args.weibull_tail, args.openmax_alpha,
              args.holdout_col, novel_programs=args.novel_programs,
              split=args.split, n_blocks=args.n_blocks)
    report(res)
    if args.report:
        os.makedirs(os.path.dirname(args.report) or ".", exist_ok=True)
        with open(args.report, "w") as fh:
            json.dump(res, fh, indent=2)
        print(f"wrote {args.report}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
