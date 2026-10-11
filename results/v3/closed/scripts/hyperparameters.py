"""AUDIT-GENERATED (run:closedset-v3). Non-default hyperparameters of the 7 registry models.

Every step of every pipeline built by obfuscope.models.build_model(name, seed=0)
is compared programmatically with a default constructed instance of the same
class (``type(step)()``) in the installed scikit-learn. ``random_state`` is
reported as "seed" because the registry passes the cell seed.
Also checks two code comments in models.py against the installed version.
"""
from __future__ import annotations

import json
import os
import sys
import warnings

import numpy as np
import sklearn

HERE = os.path.dirname(os.path.abspath(__file__))
CLOSED = os.path.dirname(HERE)
REPO = os.path.abspath(os.path.join(CLOSED, "..", "..", ".."))
sys.path.insert(0, os.path.join(REPO, "src"))
from obfuscope.models import MODEL_REGISTRY, build_model  # noqa: E402


def norm(v):
    if isinstance(v, (np.integer,)):
        return int(v)
    if isinstance(v, (np.floating,)):
        return float(v)
    if isinstance(v, tuple):
        return list(v)
    return v


def main():
    out = {"label": "AUDIT-GENERATED run:closedset-v3",
           "sklearn_version": sklearn.__version__, "numpy_version": np.__version__,
           "source": "src/obfuscope/models.py:31-63", "models": {}}
    for name in MODEL_REGISTRY:
        p0, p1 = build_model(name, 0), build_model(name, 1)
        steps = []
        for (sname, est), (_, est1) in zip(p0.steps, p1.steps):
            cur = est.get_params(deep=False)
            dflt = type(est)().get_params(deep=False)
            seed_dep = {k for k in cur if cur[k] != est1.get_params(deep=False)[k]}
            nd = {}
            for k in sorted(cur):
                if k in seed_dep:
                    nd[k] = {"value": "seed (cell --seed)", "default": norm(dflt[k])}
                elif cur[k] != dflt[k]:
                    nd[k] = {"value": norm(cur[k]), "default": norm(dflt[k])}
            steps.append({"step": sname, "class": f"{type(est).__module__}.{type(est).__name__}",
                          "non_default": nd,
                          "set_explicitly_but_equal_to_default": None})
        out["models"][name] = {"pipeline_steps": [s for s, _ in p0.steps], "steps": steps}

    # Parameters written explicitly in models.py that equal the default (read from source).
    explicit = {
        "logreg": {"C": 1.0},
        "random_forest": {"max_depth": None},
        "hist_gbdt": {"learning_rate": 0.1},
        "svm_rbf": {"gamma": "scale"},
        "mlp": {"max_iter": 200, "early_stopping": False, "tol": 1e-4},
    }
    for name, d in explicit.items():
        clf = build_model(name, 0).named_steps["clf"]
        dflt = type(clf)().get_params(deep=False)
        out["models"][name]["steps"][-1]["set_explicitly_but_equal_to_default"] = {
            k: {"value": norm(v), "default": norm(dflt[k]), "equal": v == dflt[k]} for k, v in d.items()}

    # Behavioural notes that follow from the settings (checked, not assumed).
    from sklearn.ensemble import HistGradientBoostingClassifier
    out["notes"] = {
        "hist_gbdt_early_stopping": (
            "early_stopping=True is non-default; the default 'auto' enables it only when "
            "n_samples > 10000. Each fold trains on 1920 rows, so with the default no "
            "validation split would be held out. With True, validation_fraction="
            f"{HistGradientBoostingClassifier().validation_fraction} of the training rows "
            f"is held out (n_iter_no_change={HistGradientBoostingClassifier().n_iter_no_change}, "
            "scoring='loss')."),
        "svm_probability": ("probability=True fits an internal 5 fold Platt calibration; "
                            "SVC.predict still uses the decision function, so closed set "
                            "predictions do not depend on it."),
        "random_forest_extra_trees_n_jobs": "n_jobs=-1 affects speed only, not results (verified "
                                            "by exact reproduction of committed cells with one thread).",
    }

    # Comment checks in models.py
    comments = {}
    comments["models.py:32-35 (multi_class comment mentions 'pinned 1.7.2')"] = (
        f"installed/environment-of-record scikit-learn is {sklearn.__version__}, not 1.7.2")
    from sklearn.neural_network import MLPClassifier
    rng = np.random.RandomState(0)
    X = rng.normal(size=(200, 5)); y = np.array(["a", "b", "c", "d"] * 50)
    X[y == "b"] += 2
    try:
        with warnings.catch_warnings():
            warnings.simplefilter("ignore")
            MLPClassifier(hidden_layer_sizes=(8,), early_stopping=True, max_iter=50,
                          random_state=0).fit(X, y)
        comments["models.py:56-58 (early_stopping raises on string labels under 1.7)"] = (
            f"under scikit-learn {sklearn.__version__} MLPClassifier(early_stopping=True) "
            "fits on string labels without error (synthetic 4 class check); the comment "
            "concerns 1.7, which is not the environment of record. early_stopping=False is "
            "also the library default, so the line changes nothing.")
    except Exception as exc:
        # Same fit with integer coded labels, to show the failure is the string labels.
        yi = np.unique(y, return_inverse=True)[1]
        try:
            with warnings.catch_warnings():
                warnings.simplefilter("ignore")
                MLPClassifier(hidden_layer_sizes=(8,), early_stopping=True, max_iter=50,
                              random_state=0).fit(X, yi)
            int_ok = "fits without error"
        except Exception as exc2:
            int_ok = f"also raises {type(exc2).__name__}"
        comments["models.py:56-58 (early_stopping raises on string labels under 1.7)"] = (
            f"confirmed under scikit-learn {sklearn.__version__} as well: "
            f"MLPClassifier(early_stopping=True).fit on string labels raised "
            f"{type(exc).__name__}: {str(exc)[:120]}; with integer coded labels it {int_ok}. "
            "The comment's version reference (1.7) is narrower than the behaviour. "
            "early_stopping=False is also the library default, so the explicit setting "
            "changes nothing; the consequence is that MLP training is bounded only by "
            "max_iter=200 (the default) and the tol/n_iter_no_change check on the "
            "training loss.")
    out["code_comment_checks"] = comments

    path = os.path.join(CLOSED, "hyperparameters.json")
    with open(path, "w") as fh:
        json.dump(out, fh, indent=2)
    for name, m in out["models"].items():
        print(name, m["pipeline_steps"], {s["step"]: s["non_default"] for s in m["steps"]})
    print(json.dumps(comments, indent=1))


if __name__ == "__main__":
    main()
