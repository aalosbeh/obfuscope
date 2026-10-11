"""Tests for the open set metrics and splits in scripts/openset_baselines.py.

Run with ``PYTHONPATH=src python -m pytest -q`` from the repository root.
"""
import os
import sys

import numpy as np
import pytest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "src"))
sys.path.insert(0, os.path.join(ROOT, "scripts"))

import openset_baselines as ob  # noqa: E402

PILOT = os.path.join(ROOT, "data", "features_pilot.csv")


# --------------------------------------------------------------------------- #
# FPR at 95% TPR, both conventions
# --------------------------------------------------------------------------- #

def _hand_example():
    # Inlier scores, larger = more known. Chosen so the two conventions differ.
    s_known = np.arange(20, dtype=float)              # 0, 1, ..., 19
    s_novel = 0.5 * np.arange(20, dtype=float) - 2.0  # -2, -1.5, ..., 7.5
    return s_known, s_novel


def test_fpr95_known_positive_hand_example():
    s_known, s_novel = _hand_example()
    # Threshold = 5% quantile of known inlier scores = 0.95. Known retained:
    # 1..19 = 19/20. Novel accepted (>= 0.95): -2 + 0.5 i >= 0.95 -> i >= 6,
    # i.e. 14 of 20.
    fpr, tpr = ob.fpr_at_tpr(s_known, s_novel, 0.95)
    assert fpr == pytest.approx(14 / 20)
    assert tpr == pytest.approx(19 / 20)


def test_fpr95_novel_positive_hand_example_and_legacy():
    s_known, s_novel = _hand_example()
    # Novelty = -inlier. Threshold = 5% quantile of novel novelty scores
    # = -7.5 + 0.95 * 0.5 = -7.025. Novel detected: 19/20. Known flagged
    # (-k >= -7.025 -> k <= 7): 8 of 20.
    fpr, tpr = ob.fpr_at_tpr(-s_novel, -s_known, 0.95)
    assert fpr == pytest.approx(8 / 20)
    assert tpr == pytest.approx(19 / 20)
    # The legacy helper computes the same novel positive quantity.
    assert ob._fpr_at_tpr(-s_known, -s_novel, 0.95) == pytest.approx(fpr)


def test_fpr95_conventions_match_roc_curve_definition():
    from sklearn.metrics import roc_curve
    s_known, s_novel = _hand_example()
    truth = np.r_[np.zeros(len(s_known)), np.ones(len(s_novel))]
    # Novel positive: smallest FPR at which TPR >= 0.95.
    f, t, _ = roc_curve(truth, -np.r_[s_known, s_novel])
    assert ob.fpr_at_tpr(-s_novel, -s_known)[0] == pytest.approx(f[t >= 0.95][0])
    # Known positive.
    f, t, _ = roc_curve(1 - truth, np.r_[s_known, s_novel])
    assert ob.fpr_at_tpr(s_known, s_novel)[0] == pytest.approx(f[t >= 0.95][0])


def test_fpr95_ties_push_achieved_tpr_to_one():
    s_known = np.ones(10)
    s_novel = np.r_[np.zeros(5), np.ones(5)]
    fpr, tpr = ob.fpr_at_tpr(s_known, s_novel, 0.95)
    assert tpr == 1.0 and fpr == 0.5
    fpr, tpr = ob.fpr_at_tpr(-s_novel, -s_known, 0.95)
    assert tpr == 1.0 and fpr == 1.0


def test_fpr95_achieved_tpr_can_fall_below_target():
    # 48 distinct positive scores: the 5% quantile interpolates between the
    # 3rd and 4th order statistics, so only 45 of 48 rows reach it.
    pos = np.arange(48, dtype=float)
    fpr, tpr = ob.fpr_at_tpr(pos, np.array([-1.0]), 0.95)
    assert tpr == pytest.approx(45 / 48)
    assert tpr == pytest.approx((48 - np.ceil(0.05 * 47)) / 48)


def test_scorer_metrics_record_both_conventions():
    s_known, s_novel = _hand_example()
    correct = np.ones(len(s_known), dtype=bool)
    m = ob._scorer_metrics(s_known, s_novel, correct, correct)
    assert m["fpr95_known_pos"] == pytest.approx(14 / 20)
    assert m["fpr95_novel_pos"] == pytest.approx(8 / 20)
    assert m["fpr_at_95tpr"] == m["fpr95_novel_pos"]
    assert m["tpr95_achieved_known_pos"] == pytest.approx(0.95)
    assert m["tpr95_achieved_novel_pos"] == pytest.approx(0.95)


# --------------------------------------------------------------------------- #
# OSCR and ECE
# --------------------------------------------------------------------------- #

def test_oscr_hand_example():
    s_known = np.array([3.0, 2.0, 1.0])
    correct = np.array([True, False, True])
    s_novel = np.array([2.0, 0.0])
    # Correct known 3 beats both novel rows, correct known 1 beats only 0:
    # 3 of 3 * 2 pairs.
    assert ob._oscr(s_known, correct, s_novel) == pytest.approx(0.5)
    assert ob.oscr_mann_whitney(s_known, correct, s_novel) == pytest.approx(0.5)
    # A tie counts half.
    assert ob._oscr(np.array([2.0]), np.array([True]),
                    np.array([2.0])) == pytest.approx(0.5)


@pytest.mark.parametrize("seed", range(5))
def test_oscr_equals_mann_whitney_with_ties(seed):
    rng = np.random.RandomState(seed)
    s_known = np.round(rng.normal(size=60), 1)       # rounding creates ties
    s_novel = np.round(rng.normal(-0.3, size=40), 1)
    correct = rng.rand(60) < 0.7
    assert ob._oscr(s_known, correct, s_novel) == pytest.approx(
        ob.oscr_mann_whitney(s_known, correct, s_novel), abs=1e-12)


def test_ece_toy_example():
    proba = np.array([[0.95, 0.05], [0.95, 0.05], [0.65, 0.35], [0.65, 0.35]])
    correct = np.array([True, False, True, True])
    # Bin of 0.95: accuracy 0.5, confidence 0.95, mass 0.5.
    # Bin of 0.65: accuracy 1.0, confidence 0.65, mass 0.5.
    expected = 0.5 * abs(0.5 - 0.95) + 0.5 * abs(1.0 - 0.65)
    assert ob._ece(proba, correct) == pytest.approx(expected)
    # Perfect calibration gives zero.
    assert ob._ece(np.array([[1.0, 0.0]]), np.array([True])) == pytest.approx(0.0)


# --------------------------------------------------------------------------- #
# Splits: novel programs held out
# --------------------------------------------------------------------------- #

def _pilot_columns():
    pd = pytest.importorskip("pandas")
    if not os.path.exists(PILOT):
        pytest.skip("data/features_pilot.csv not present")
    df = pd.read_csv(PILOT, usecols=["sample_id", "technique", "sub_technique"])
    return (df["sample_id"].to_numpy(), df["technique"].to_numpy(),
            df["sub_technique"].to_numpy())


@pytest.mark.parametrize("split", ["gss", "program_kfold"])
@pytest.mark.parametrize("config", ["A", "B", "C"])
def test_heldout_novel_programs_are_unseen(split, config):
    groups, tech, sub = _pilot_columns()
    y, hold_on = {"A": (tech, tech), "B": (sub, sub), "C": (sub, tech)}[config]
    n_folds = 0
    for seed in (0, 1):
        for sp in ob.iter_openset_splits(hold_on, y, groups, seed, split,
                                         "heldout"):
            fit_p = set(groups[sp["fit_idx"]].tolist())
            eval_p = set(groups[sp["eval_idx"]].tolist())
            nov_p = set(groups[sp["novel_idx"]].tolist())
            assert len(sp["novel_idx"]) > 0
            assert fit_p.isdisjoint(eval_p)
            assert nov_p <= eval_p
            assert nov_p.isdisjoint(fit_p)
            assert set(sp["eval_programs"].tolist()) == eval_p
            # Novel rows are rows of the held out unit only.
            assert set(hold_on[sp["novel_idx"]].tolist()) == {sp["novel_class"]}
            assert not np.isin(sp["novel_class"], hold_on[sp["fit_idx"]])
            n_folds += 1
    assert n_folds > 0


def test_program_kfold_scores_every_novel_row_once_per_seed():
    groups, tech, sub = _pilot_columns()
    for seed in (0, 3):
        seen = {}
        for sp in ob.iter_openset_splits(sub, sub, groups, seed,
                                         "program_kfold", "heldout"):
            seen.setdefault(sp["novel_class"], []).append(sp["novel_idx"])
        for cls, parts in seen.items():
            allidx = np.concatenate(parts)
            assert len(allidx) == len(set(allidx.tolist()))
            assert set(allidx.tolist()) == set(np.where(sub == cls)[0].tolist())


def test_program_kfold_blocks_depend_on_seed():
    groups, tech, sub = _pilot_columns()

    def blocks(seed):
        return [tuple(sp["eval_programs"].tolist())
                for sp in ob.iter_openset_splits(tech, tech, groups, seed,
                                                 "program_kfold", "heldout")
                if sp["novel_class"] == sorted(set(tech.tolist()))[0]]
    assert blocks(0) != blocks(1)
    assert blocks(0) == blocks(0)


def test_novel_programs_all_and_gss_reproduce_original_split():
    from sklearn.model_selection import GroupShuffleSplit
    groups, tech, sub = _pilot_columns()
    for sp in ob.iter_openset_splits(sub, sub, groups, 2, "gss", "all"):
        known = np.where(sub != sp["novel_class"])[0]
        novel = np.where(sub == sp["novel_class"])[0]
        a, b = next(GroupShuffleSplit(n_splits=1, test_size=0.2,
                                      random_state=2)
                    .split(known, groups=groups[known]))
        np.testing.assert_array_equal(sp["fit_idx"], known[a])
        np.testing.assert_array_equal(sp["eval_idx"], known[b])
        np.testing.assert_array_equal(sp["novel_idx"], novel)


def test_invalid_options_raise():
    groups, tech, sub = _pilot_columns()
    with pytest.raises(ValueError):
        next(ob.iter_openset_splits(tech, tech, groups, 0, "bogus", "heldout"))
    with pytest.raises(ValueError):
        next(ob.iter_openset_splits(tech, tech, groups, 0, "gss", "bogus"))


# --------------------------------------------------------------------------- #
# End to end on a small slice of the pilot table
# --------------------------------------------------------------------------- #

def test_run_end_to_end_records_new_fields(tmp_path):
    pd = pytest.importorskip("pandas")
    if not os.path.exists(PILOT):
        pytest.skip("data/features_pilot.csv not present")
    df = pd.read_csv(PILOT)
    progs = sorted(df["sample_id"].unique())[:10]
    small = tmp_path / "small.csv"
    df[df["sample_id"].isin(progs)].to_csv(small, index=False)
    res = ob.run(str(small), ["logreg"], [0], "all", "technique", 5, 20, 3,
                 novel_programs="heldout", split="gss")
    assert res["split"] == "gss" and res["novel_programs"] == "heldout"
    assert res["per_fold"]
    for f in res["per_fold"]:
        assert f["n_novel_from_fit_programs"] == 0
        assert f["novel_prevalence"] == pytest.approx(
            f["n_novel"] / (f["n_novel"] + f["n_known_eval"]))
        # Lower bound of the achieved TPR under linear quantile interpolation.
        lo_k = (f["n_known_eval"] - np.ceil(0.05 * (f["n_known_eval"] - 1))) \
            / f["n_known_eval"]
        lo_n = (f["n_novel"] - np.ceil(0.05 * (f["n_novel"] - 1))) / f["n_novel"]
        for name, m in f["scorers"].items():
            if "auroc" in m:
                assert m["fpr_at_95tpr"] == m["fpr95_novel_pos"]
                assert lo_k - 1e-12 <= m["tpr95_achieved_known_pos"] <= 1.0
                assert lo_n - 1e-12 <= m["tpr95_achieved_novel_pos"] <= 1.0
    s = res["summary"]["logreg"]
    assert "novel_prevalence_mean" in s and "closed_accuracy_argmax_mean" in s
    assert "fpr95_known_pos_mean" in s["scorers"]["msp"]
    assert "fpr95_novel_pos_std" in s["scorers"]["msp"]
