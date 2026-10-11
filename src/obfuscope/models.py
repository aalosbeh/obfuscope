"""
Model registry for the ObfuScope experiments.

Each entry returns a scikit-learn :class:`~sklearn.pipeline.Pipeline` that
standardises features and fits a classifier. Keeping the registry small and
declarative lets the HTC driver enumerate ``model x feature_set x protocol``
cells without any model-specific code paths.
"""
from __future__ import annotations

from typing import Callable, Dict

from sklearn.ensemble import (ExtraTreesClassifier, HistGradientBoostingClassifier,
                              RandomForestClassifier)
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC


def _pipe(clf, scale: bool = True) -> Pipeline:
    steps = []
    if scale:
        steps.append(("scaler", StandardScaler()))
    steps.append(("clf", clf))
    return Pipeline(steps)


MODEL_REGISTRY: Dict[str, Callable[[int], Pipeline]] = {
    # NOTE: no explicit ``multi_class`` kwarg -- newer scikit-learn (>=1.8)
    # removed it entirely (multinomial handling is automatic); the pinned
    # 1.7.2 already defaults to the same behaviour, so omitting it keeps the
    # registry working across the version range instead of hard-failing.
    "logreg": lambda seed: _pipe(
        LogisticRegression(max_iter=2000, C=1.0,
                           class_weight="balanced", random_state=seed)),
    "random_forest": lambda seed: _pipe(
        RandomForestClassifier(n_estimators=400, max_depth=None, n_jobs=-1,
                               class_weight="balanced_subsample", random_state=seed),
        scale=False),
    "extra_trees": lambda seed: _pipe(
        ExtraTreesClassifier(n_estimators=400, n_jobs=-1,
                             class_weight="balanced_subsample", random_state=seed),
        scale=False),
    "hist_gbdt": lambda seed: _pipe(
        HistGradientBoostingClassifier(max_iter=200, learning_rate=0.1,
                                       l2_regularization=1.0, early_stopping=True,
                                       random_state=seed),
        scale=False),
    "svm_rbf": lambda seed: _pipe(
        SVC(C=4.0, gamma="scale", probability=True,
            class_weight="balanced", random_state=seed)),
    "knn": lambda seed: _pipe(KNeighborsClassifier(n_neighbors=7, weights="distance")),
    # NOTE: ``early_stopping`` is disabled deliberately. Under scikit-learn 1.7
    # its internal validation-scoring path raises on string class labels; the
    # model instead relies on ``max_iter`` and the ``tol`` convergence check.
    "mlp": lambda seed: _pipe(
        MLPClassifier(hidden_layer_sizes=(96,), alpha=1e-3, max_iter=200,
                      early_stopping=False, n_iter_no_change=8, tol=1e-4,
                      random_state=seed)),
}


def build_model(name: str, seed: int = 0) -> Pipeline:
    if name not in MODEL_REGISTRY:
        raise KeyError(f"unknown model '{name}'; choices: {sorted(MODEL_REGISTRY)}")
    return MODEL_REGISTRY[name](seed)


from .config import MODEL_NAMES  # noqa: E402  (canonical, sklearn-free list)

# Guard against the registry and the light config drifting apart.
assert set(MODEL_REGISTRY) == set(MODEL_NAMES), \
    "MODEL_REGISTRY and config.MODEL_NAMES disagree"
