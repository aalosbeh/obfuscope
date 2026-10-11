"""
Reproducible example of the upward bias of raw eta squared (Section 4.2).

Diagnostic 1b of scripts/diversity_gate.py asks whether the within class
feature variation tracks the input programs. Its raw statistic, eta squared,
is the between program share of the variance, ``SS_between / SS_total``. With
``k`` programs and ``n`` rows that statistic is not centred on zero when there
is no program effect at all: under the null its expectation is about
``(k - 1) / (n - 1)``. Omega squared subtracts that chance share and is centred
near zero.

This script builds one synthetic class with that null true by construction and
reports, for the same table:

  observed raw eta squared             mean over features
  raw eta squared permutation null     program labels shuffled among the rows,
                                       200 permutations, mean of the statistic
  analytic null expectation            (k - 1) / (n - 1)
  observed omega squared               mean over features
  omega squared permutation null       mean over the same permutations

and, for reference, the gate's own diagnostic 1b output on the table
(``diversity_gate._input_dependence``), which decides on the omega squared
permutation p value. Both statistics come from ``diversity_gate._eta_squared``,
so the numbers are exactly what the gate computes.

The expected reading: the raw eta squared permutation null mean and the
analytic value agree (about 0.097 for k = 30 and n = 300), and the observed raw
value lies within sampling error of them (the permutation null standard
deviation is reported), because the raw statistic measures the chance share and
nothing else here. Omega squared and its null mean are both near zero. A raw
value is therefore only interpretable against a null computed for the same k
and n, never against zero or a fixed cut.

Usage
-----
    python3 scripts/eta_bias_example.py --report eta_bias_example.json
    python3 scripts/eta_bias_example.py --programs 30 --rows-per-program 10 \\
        --features 5 --permutations 200 --seed 0
"""
from __future__ import annotations

import argparse
import json
import os
import sys
from typing import Dict, Optional, Sequence

import numpy as np
import pandas as pd

_HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, _HERE)

import diversity_gate as gate  # noqa: E402


def make_null_class(k: int, rows_per_program: int, n_features: int,
                    rng: np.random.Generator) -> pd.DataFrame:
    """One class, ``k`` programs, iid standard normal features: no program effect."""
    n = k * rows_per_program
    data = {f"f{j}": rng.normal(size=n) for j in range(n_features)}
    data["sample_id"] = np.repeat([f"p{i:02d}" for i in range(k)], rows_per_program)
    return pd.DataFrame(data)


def example(k: int = 30, rows_per_program: int = 10, n_features: int = 5,
            n_permutations: int = 200, seed: int = 0) -> Dict:
    rng = np.random.default_rng(seed)
    df = make_null_class(k, rows_per_program, n_features, rng)
    feats = [f"f{j}" for j in range(n_features)]
    n = len(df)

    x = df[feats].astype("float64").reset_index(drop=True)
    codes = pd.Categorical(df["sample_id"]).codes.astype(int)
    observed = gate._eta_squared(x, codes, k)

    null_eta = np.empty(n_permutations)
    null_omega = np.empty(n_permutations)
    for i in range(n_permutations):
        r = gate._eta_squared(x, rng.permutation(codes), k)
        null_eta[i] = r["eta_squared"]
        null_omega[i] = r["omega_squared"]

    gate_1b = gate._input_dependence(df, feats, "sample_id")

    return {
        "description": ("One synthetic class with no program effect: k programs, "
                        "rows_per_program rows each, iid N(0, 1) features. "
                        "Statistics from diversity_gate._eta_squared, averaged "
                        "over features."),
        "settings": {
            "programs_k": k, "rows_per_program": rows_per_program, "rows_n": n,
            "features": n_features, "permutations": n_permutations,
            "seed": seed,
            "permutation": "program labels shuffled among all rows of the class",
        },
        "raw_eta_squared": {
            "observed": round(float(observed["eta_squared"]), 6),
            "permutation_null_mean": round(float(null_eta.mean()), 6),
            "permutation_null_sd": round(float(null_eta.std(ddof=1)), 6),
            "analytic_null_expectation": round((k - 1) / (n - 1), 6),
            "analytic_formula": "(k - 1) / (n - 1)",
        },
        "omega_squared": {
            "observed": round(float(observed["omega_squared"]), 6),
            "permutation_null_mean": round(float(null_omega.mean()), 6),
            "permutation_null_sd": round(float(null_omega.std(ddof=1)), 6),
            "permutation_p_value": round(
                (int((null_omega >= observed["omega_squared"]).sum()) + 1)
                / (n_permutations + 1), 5),
        },
        "per_feature_eta_squared_observed": {
            f: round(float(v), 6) for f, v in _per_feature_eta(x, codes).items()
        },
        "gate_diagnostic_1b": {
            "note": ("diversity_gate._input_dependence on the same table: its "
                     "own permutation stream (seed "
                     f"{gate.INPUT_DEPENDENCE_SEED}, "
                     f"{gate.INPUT_DEPENDENCE_PERMUTATIONS} permutations) and "
                     "omega squared null only"),
            "raw_eta_squared": round(float(gate_1b["mean"]), 6),
            "omega_squared": round(float(gate_1b["omega_squared"]), 6),
            "permutation": gate_1b["permutation"],
        },
    }


def _per_feature_eta(x: pd.DataFrame, codes: np.ndarray) -> Dict[str, float]:
    grand = x.mean(axis=0)
    ss_total = ((x - grand) ** 2).sum(axis=0)
    means = x.groupby(codes).mean()
    sizes = pd.Series(np.bincount(codes), dtype="float64").reindex(means.index)
    ss_between = ((means - grand) ** 2).mul(sizes, axis=0).sum(axis=0)
    return (ss_between / ss_total).to_dict()


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(
        description="Raw eta squared against its permutation null and the "
                    "analytic (k - 1)/(n - 1) on a class with no program effect.")
    ap.add_argument("--programs", type=int, default=30, help="k (default 30)")
    ap.add_argument("--rows-per-program", type=int, default=10,
                    help="rows per program (default 10, so n = 300)")
    ap.add_argument("--features", type=int, default=5)
    ap.add_argument("--permutations", type=int, default=200)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--report", default=None, help="write a JSON report here")
    args = ap.parse_args(argv)

    res = example(args.programs, args.rows_per_program, args.features,
                  args.permutations, args.seed)
    s, e, o = res["settings"], res["raw_eta_squared"], res["omega_squared"]
    print(f"synthetic class: k = {s['programs_k']} programs, n = {s['rows_n']} "
          f"rows, {s['features']} features, no program effect, seed {s['seed']}")
    print(f"  raw eta squared, observed                  {e['observed']:.4f}")
    print(f"  raw eta squared, permutation null mean     "
          f"{e['permutation_null_mean']:.4f}  ({s['permutations']} permutations)")
    print(f"  raw eta squared, analytic (k-1)/(n-1)      "
          f"{e['analytic_null_expectation']:.4f}")
    print(f"  omega squared, observed                    {o['observed']:.4f}")
    print(f"  omega squared, permutation null mean       "
          f"{o['permutation_null_mean']:.4f}")
    print(f"  omega squared, permutation p               {o['permutation_p_value']}")
    if args.report:
        os.makedirs(os.path.dirname(os.path.abspath(args.report)), exist_ok=True)
        with open(args.report, "w") as fh:
            json.dump(res, fh, indent=2)
        print(f"report written to {args.report}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
