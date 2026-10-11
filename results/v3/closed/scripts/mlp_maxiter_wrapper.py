"""AUDIT-GENERATED (run:closedset-v3). Run one closed set cell with the registry MLP at a different max_iter.

src/obfuscope/models.py is NOT modified. A new registry key
``mlp_maxiter<N>`` is added at runtime whose pipeline is identical to the
registry ``mlp`` (StandardScaler + MLPClassifier(hidden_layer_sizes=(96,),
alpha=1e-3, early_stopping=False, n_iter_no_change=8, tol=1e-4,
random_state=seed)) except for ``max_iter``. The classifier is a trivial
subclass that records n_iter_, the final loss and whether a
ConvergenceWarning was raised at each fit; these are written into the cell.
The cell is otherwise produced by obfuscope.experiment.run_cell, unchanged.
"""
from __future__ import annotations

import argparse
import json
import os
import warnings

from sklearn.exceptions import ConvergenceWarning
from sklearn.neural_network import MLPClassifier

from obfuscope import models as M
from obfuscope.experiment import run_cell

RECORD = []


class RecordingMLP(MLPClassifier):
    def fit(self, X, y):
        with warnings.catch_warnings(record=True) as w:
            warnings.simplefilter("always", ConvergenceWarning)
            out = super().fit(X, y)
        RECORD.append({
            "n_iter_": int(self.n_iter_), "max_iter": int(self.max_iter),
            "hit_max_iter": bool(self.n_iter_ >= self.max_iter),
            "convergence_warning": any(issubclass(x.category, ConvergenceWarning) for x in w),
            "final_loss": float(self.loss_),
            "no_improvement_count_at_stop": int(self._no_improvement_count),
        })
        return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--data", required=True)
    ap.add_argument("--task", required=True)
    ap.add_argument("--protocol", default="lomfo")
    ap.add_argument("--seed", type=int, required=True)
    ap.add_argument("--max-iter", type=int, default=2000)
    ap.add_argument("--out", required=True)
    a = ap.parse_args()

    name = f"mlp_maxiter{a.max_iter}"
    M.MODEL_REGISTRY[name] = lambda seed: M._pipe(
        RecordingMLP(hidden_layer_sizes=(96,), alpha=1e-3, max_iter=a.max_iter,
                     early_stopping=False, n_iter_no_change=8, tol=1e-4,
                     random_state=seed))
    # Same estimator as the registry mlp apart from max_iter (checked here).
    ref = M.build_model("mlp", a.seed).named_steps["clf"].get_params()
    new = M.build_model(name, a.seed).named_steps["clf"].get_params()
    diff = {k: (ref[k], new[k]) for k in ref if ref[k] != new[k]}
    assert set(diff) <= {"max_iter"}, diff

    res = run_cell(a.data, a.task, a.protocol, name, "all", a.seed, 5)
    res["audit_wrapper"] = {
        "label": "AUDIT-GENERATED run:closedset-v3",
        "base_model": "mlp", "changed_params": {"max_iter": [ref["max_iter"], a.max_iter]},
        "per_fold_fit": RECORD,
    }
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, "w") as fh:
        json.dump(res, fh, indent=2)
    print(f"[cell] {a.task}/{a.protocol}/{name} seed={a.seed} -> "
          f"{res['macro_f1_mean']:.4f} n_iter={[r['n_iter_'] for r in RECORD]}")


if __name__ == "__main__":
    main()
