"""Tests for scripts/eta_bias_example.py.

Run with ``PYTHONPATH=src python -m pytest -q`` from the repository root.
"""
import os
import sys

import pytest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "scripts"))


def test_eta_bias_example_matches_analytic():
    import eta_bias_example as eta

    res = eta.example(k=30, rows_per_program=10, n_features=5,
                      n_permutations=50, seed=0)
    e = res["raw_eta_squared"]
    assert e["analytic_null_expectation"] == pytest.approx(29 / 299, abs=1e-6)
    # The shuffled null of the raw statistic sits on the analytic value, and
    # omega squared's null sits on zero.
    assert e["permutation_null_mean"] == pytest.approx(29 / 299, abs=0.01)
    assert res["omega_squared"]["permutation_null_mean"] == pytest.approx(0.0, abs=0.01)
    # Deterministic for a fixed seed.
    assert eta.example(30, 10, 5, 50, 0) == res
