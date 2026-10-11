"""Tests for the revision additions to scripts/holdout_inversion_sim.py.

Run with ``PYTHONPATH=src python -m pytest -q`` from the repository root.
"""
import argparse
import os
import sys

import numpy as np
import pytest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "scripts"))

import holdout_inversion_sim as sim  # noqa: E402


def _args(**kw):
    base = dict(n_families=3, n_siblings=3, n_per_class=60, dim=8,
                family_spread=12.0, sibling_spreads=[2.0], seeds=2,
                seed_start=0, seed_list=None, sibling_layout="ordered",
                report=None)
    base.update(kw)
    return argparse.Namespace(**base)


def test_random_layout_radius_matches_ordered_pair_spacing():
    # Three siblings at -1, 0, 1: mean squared pair distance 2 -> radius 1.
    assert sim.random_layout_radius(3, 1.0) == pytest.approx(1.0)
    assert sim.random_layout_radius(3, 4.0) == pytest.approx(4.0)
    assert sim.random_layout_radius(1, 4.0) == 0.0
    # Empirical check in high dimension: random directions at that radius give
    # about the same mean squared pair distance as the ordered axis.
    rng = np.random.default_rng(0)
    c, _, fam, _ = sim.class_centres(50, 4, 400, 12.0, 2.0, rng, layout="random")
    c_o, _, _, _ = sim.class_centres(50, 4, 400, 12.0, 2.0,
                                     np.random.default_rng(0), layout="ordered")

    def mean_pair_d2(cent):
        out = []
        for f in range(50):
            sib = cent[4 * f:4 * f + 4]
            out += [((sib[i] - sib[j]) ** 2).sum()
                    for i in range(4) for j in range(i + 1, 4)]
        return float(np.mean(out))

    assert mean_pair_d2(c) == pytest.approx(mean_pair_d2(c_o), rel=0.05)


def test_ordered_layout_is_the_default_and_unchanged():
    a = sim.class_centres(4, 3, 20, 12.0, 1.0, np.random.default_rng(3))
    b = sim.class_centres(4, 3, 20, 12.0, 1.0, np.random.default_rng(3),
                          layout="ordered")
    assert np.array_equal(a[0], b[0])
    with pytest.raises(ValueError):
        sim.class_centres(4, 3, 20, 12.0, 1.0, np.random.default_rng(3),
                          layout="spiral")


def test_one_condition_reports_bayes_accuracy_without_changing_values():
    args = _args()
    out = sim.one_condition("edge", 2.0, args, 0)
    assert 0.0 <= out["closed_accuracy_bayes"] <= 1.0
    assert out["sibling_layout"] == "ordered"
    # The keys that existed before the revision are all still there.
    for k in ("auroc_bayes_msp", "auroc_bayes_max_logit", "auroc_logreg_msp",
              "auroc_random_forest_msp", "closed_accuracy_random_forest"):
        assert k in out
    # Recomputing gives identical values (no hidden extra random draws).
    again = sim.one_condition("edge", 2.0, args, 0)
    assert again == out


def test_seed_values():
    assert sim.seed_values(_args(seeds=5)) == [0, 1, 2, 3, 4]
    assert sim.seed_values(_args(seeds=3, seed_start=10)) == [10, 11, 12]
    assert sim.seed_values(_args(seed_list=[7, 2])) == [7, 2]


def test_run_report_has_new_blocks(tmp_path):
    rep = tmp_path / "sim.json"
    args = _args(sibling_layout="random", report=str(rep))
    sim.run(args, str(rep))
    import json
    d = json.loads(rep.read_text())
    assert d["sibling_layout"] == "random"
    assert d["seed_values"] == [0, 1]
    row = d["rows"][0]
    assert "closed_accuracy_bayes_mean" in row
    fe = row["fitted_estimators"]
    assert fe["random_forest"]["auroc_msp_mean"] == row["auroc_random_forest_msp_mean"]
    assert fe["logreg"]["auroc_msp_mean"] == row["auroc_logreg_msp_mean"]
    assert {a["sibling_spread"] for a in d["edge_vs_interior"]} == {2.0}

