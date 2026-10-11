"""AUDIT-GENERATED thin runner around scripts/openset_baselines.py (v3 runs).

It calls ``openset_baselines.main(argv)`` unchanged, so the report JSON written
with ``--report`` is exactly what the script itself writes. Around it, the
runner records diagnostics the script does not keep, into a sidecar JSON given
with ``--diagnostics``:

* per model: number of classifier fits, warnings raised inside ``fit`` by
  category (ConvergenceWarning etc.), and for the MLP the number of fits whose
  ``n_iter_`` reached ``max_iter``;
* per model and tail type (``posterior`` = log posterior tails used by
  evt_posterior; ``logit`` = unnormalised score tails used by openmax, only for
  estimators that expose them): Weibull fits attempted, degenerate-tail
  fallbacks (fewer than two finite distances or all equal) and fit-failure
  fallbacks (non finite or exception), both of which return shape 1.0 and
  scale mean(d);
* per model: class tails that fell back to all class rows because fewer than
  three fitting rows of that class were classified correctly by predict();
* wall clock runtime.

The wrappers return the original values, add no randomness (one extra
deterministic ``predict`` on the fitting rows per fold) and do not change any
reported number. Usage:

    python results/v3/run_openset_instrumented.py --diagnostics D.json -- \
        <openset_baselines.py arguments>
"""
from __future__ import annotations

import importlib.util
import json
import os
import sys
import time
import warnings
from collections import Counter, defaultdict

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
SCRIPT = os.path.normpath(os.path.join(HERE, "..", "..", "scripts",
                                       "openset_baselines.py"))


def _load():
    spec = importlib.util.spec_from_file_location("openset_baselines", SCRIPT)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def main() -> int:
    argv = sys.argv[1:]
    if "--diagnostics" not in argv or "--" not in argv:
        print(__doc__)
        return 2
    i = argv.index("--diagnostics")
    diag_path = argv[i + 1]
    script_argv = argv[argv.index("--") + 1:]

    osb = _load()
    state = {"model": None, "weib": None}
    fits = Counter()
    warn_cat = defaultdict(Counter)
    warn_msg = defaultdict(Counter)
    fits_with_cat = defaultdict(Counter)
    nonfinite_params = Counter()
    mlp_iter = defaultdict(list)
    weib = defaultdict(lambda: Counter())
    lt3 = Counter()
    tails_total = Counter()

    orig_build = osb.build_model

    def build_model(name, seed=0):
        clf = orig_build(name, seed)
        state["model"] = name
        orig_fit = clf.fit

        def fit(X, y, **kw):
            from sklearn.exceptions import ConvergenceWarning
            with warnings.catch_warnings(record=True) as w:
                # "default": each distinct (message, location) once per fit;
                # ConvergenceWarning: every occurrence.
                warnings.simplefilter("default")
                warnings.simplefilter("always", ConvergenceWarning)
                out = orig_fit(X, y, **kw)
            fits[name] += 1
            cats = set()
            for ww in w:
                warn_cat[name][ww.category.__name__] += 1
                warn_msg[name][str(ww.message)[:90]] += 1
                cats.add(ww.category.__name__)
            for c in cats:
                fits_with_cat[name][c] += 1
            inner = clf[-1]
            if type(inner).__name__ == "MLPClassifier":
                mlp_iter[name].append(int(inner.n_iter_))
                if not all(np.isfinite(c).all() for c in
                           list(inner.coefs_) + list(inner.intercepts_)):
                    nonfinite_params[name] += 1
            return out

        clf.fit = fit
        return clf

    osb.build_model = build_model

    orig_weibull = osb._fit_weibull

    def _fit_weibull(d):
        res = orig_weibull(d)
        dd = np.asarray(d, dtype=float)
        dd = dd[np.isfinite(dd)]
        degenerate = len(dd) < 2 or np.allclose(dd, dd[0])
        fb_val = [1.0, float(max(dd.mean() if len(dd) else 1.0, 1e-6))]
        is_fallback = (res[0] == fb_val[0] and res[1] == fb_val[1])
        if state["weib"] is not None:
            state["weib"].append((bool(degenerate), bool(is_fallback)))
        return res

    osb._fit_weibull = _fit_weibull

    orig_ctx = osb._fit_context

    def _fit_context(clf, X_fit, y_fit, seed, k, tail, alpha):
        state["weib"] = []
        ctx = orig_ctx(clf, X_fit, y_fit, seed, k, tail, alpha)
        rec = state["weib"]
        state["weib"] = None
        name = state["model"]
        classes = np.unique(y_fit)
        nc = len(classes)
        kinds = ["posterior"] * nc + ["logit"] * (len(rec) - nc)
        for kind, (deg, fb) in zip(kinds, rec):
            c = weib[f"{name}|{kind}"]
            c["fits"] += 1
            if fb and deg:
                c["fallback_degenerate"] += 1
            elif fb:
                c["fallback_fit_failure"] += 1
        pred = clf.predict(X_fit)
        for cl in classes:
            tails_total[name] += 1
            if int(((y_fit == cl) & (pred == cl)).sum()) < 3:
                lt3[name] += 1
        return ctx

    osb._fit_context = _fit_context

    t0 = time.time()
    rc = osb.main(script_argv)
    dt = time.time() - t0

    mlp_max_iter = 200
    diag = {
        "runner": "AUDIT-GENERATED results/v3/run_openset_instrumented.py",
        "script": SCRIPT,
        "argv": script_argv,
        "runtime_seconds": round(dt, 1),
        "python": sys.version.split()[0],
        "env": {k: os.environ.get(k) for k in
                ("LOKY_MAX_CPU_COUNT", "OMP_NUM_THREADS", "PYTHONPATH")},
        "fits": dict(fits),
        "fit_warnings_by_category": {m: dict(c) for m, c in warn_cat.items()},
        "fit_warnings_note": "ConvergenceWarning counted at every "
                             "occurrence; other categories once per distinct "
                             "(message, location) per fit",
        "fits_with_warning_category": {m: dict(c) for m, c in
                                       fits_with_cat.items()},
        "fit_warning_messages": {m: dict(c.most_common(8))
                                 for m, c in warn_msg.items()},
        "mlp_fits_with_nonfinite_parameters": dict(nonfinite_params),
        "mlp_fits_reaching_max_iter": {
            m: int(sum(1 for n in v if n >= mlp_max_iter))
            for m, v in mlp_iter.items()},
        "mlp_n_iter_summary": {
            m: {"n": len(v), "min": int(min(v)), "median": float(np.median(v)),
                "max": int(max(v))} for m, v in mlp_iter.items() if v},
        "weibull": {k: dict(c) for k, c in sorted(weib.items())},
        "tail_fallback_lt3_correct_classes": dict(lt3),
        "tail_classes_total": dict(tails_total),
    }
    os.makedirs(os.path.dirname(diag_path) or ".", exist_ok=True)
    with open(diag_path, "w") as fh:
        json.dump(diag, fh, indent=2)
    print(f"wrote {diag_path}  runtime {dt:.1f}s")
    return rc


if __name__ == "__main__":
    raise SystemExit(main())
