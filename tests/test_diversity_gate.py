"""Tests for the headroom status, reference record and repeats in
scripts/diversity_gate.py.

Run with ``PYTHONPATH=src python -m pytest -q`` from the repository root.
"""
import json
import os
import sys

import numpy as np
import pandas as pd
import pytest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "scripts"))

import diversity_gate as gate  # noqa: E402


def _table(seed: int = 0, signal: float = 3.0) -> pd.DataFrame:
    """Four classes, ten programs per class, five rows per program.

    Feature ``f0`` carries the class; the others are noise. Small enough that
    diagnostic 4 runs in well under a second.
    """
    rng = np.random.default_rng(seed)
    rows = []
    for c in range(4):
        for g in range(10):
            for r in range(5):
                rows.append({
                    "sample_id": f"c{c}_p{g}",
                    "technique": f"t{c}",
                    "f0": c * signal + rng.normal(),
                    "f1": rng.normal(),
                    "f2": rng.normal(),
                    "f3": rng.normal(),
                })
    return pd.DataFrame(rows)


FEATS = ["f0", "f1", "f2", "f3"]


def test_headroom_inconclusive_when_full_not_above_chance():
    df = _table()
    # Supplied F1_full equal to chance (1/4): the gap is zero, so R is undefined.
    ok, stats, failures = gate.check_single_feature_ceiling(
        df, FEATS, "technique", "sample_id", max_f1=1.01, seed=0,
        max_headroom=0.5, full_macro_f1=0.25)
    assert stats["headroom_R"] is None
    assert stats["headroom_status"] == "inconclusive"
    assert stats["headroom_gap"] == pytest.approx(0.0)
    assert "R is undefined" in stats["headroom_note"]
    # Inconclusive is not a failure and does not produce a headroom message.
    assert not any("headroom" in f for f in failures)
    assert ok


def test_headroom_inconclusive_below_chance():
    df = _table()
    _ok, stats, _f = gate.check_single_feature_ceiling(
        df, FEATS, "technique", "sample_id", max_f1=1.01, seed=0,
        max_headroom=0.5, full_macro_f1=0.10)
    assert stats["headroom_status"] == "inconclusive"
    assert stats["headroom_gap"] < 0


def test_headroom_fail_pass_and_not_checked():
    df = _table()
    # f0 alone separates the classes, so with a supplied F1_full of 1.0 the
    # best single feature recovers nearly all of the gap: R is small -> fail.
    _ok, st_fail, fails = gate.check_single_feature_ceiling(
        df, FEATS, "technique", "sample_id", max_f1=1.01, seed=0,
        max_headroom=0.99, full_macro_f1=1.0)
    assert st_fail["headroom_status"] == "fail"
    assert any("headroom" in f for f in fails)

    _ok, st_pass, _f = gate.check_single_feature_ceiling(
        df, FEATS, "technique", "sample_id", max_f1=1.01, seed=0,
        max_headroom=1e-6, full_macro_f1=1.0)
    if st_pass["headroom_R"] >= 1e-6:
        assert st_pass["headroom_status"] == "pass"

    _ok, st_nc, _f = gate.check_single_feature_ceiling(
        df, FEATS, "technique", "sample_id", max_f1=1.01, seed=0,
        max_headroom=0.0, full_macro_f1=1.0)
    assert st_nc["headroom_status"] == "not_checked"


def test_headroom_reference_records_source_and_protocol():
    df = _table()
    _ok, sup, _f = gate.check_single_feature_ceiling(
        df, FEATS, "technique", "sample_id", max_f1=1.01, seed=0,
        full_macro_f1=0.9, full_macro_f1_protocol="example protocol")
    ref = sup["headroom_reference"]
    assert ref["full_set_source"] == "supplied" == sup["full_set_source"]
    assert ref["full_set_protocol"] == "example protocol"
    assert ref["same_protocol_as_best_k"] is False
    assert "GroupShuffleSplit" in ref["best_k_protocol"]
    # The probe reference R is reported whatever the reference is.
    assert sup["full_set_probe_macro_f1"] is not None

    _ok, probe, _f = gate.check_single_feature_ceiling(
        df, FEATS, "technique", "sample_id", max_f1=1.01, seed=0)
    assert probe["headroom_reference"]["full_set_source"] == \
        "probe tree on all features"
    assert probe["headroom_reference"]["same_protocol_as_best_k"] is True
    # With no supplied value, R and the probe reference R coincide.
    assert probe["headroom_R"] == probe["headroom_R_probe_reference"]
    assert probe["probe_settings"]["tree_depth"] == min(8, 4 + 2)


def test_run_reports_inconclusive_without_changing_exit_status(tmp_path, capsys):
    df = _table()
    path = tmp_path / "features.csv"
    df.to_csv(path, index=False)

    common = dict(
        features_path=str(path), label="technique", group="sample_id",
        min_distinct_ratio=0.0, max_constant_fraction=1.0,
        max_affected_fraction=1.0, max_single_feature_f1=1.01,
        permutation_tolerance=1.0, seed=0, skip_single_feature=False,
        min_headroom=0.5,
    )
    rep_inc = tmp_path / "inc.json"
    code_inc = gate.run(report_path=str(rep_inc), full_macro_f1=0.25, **common)
    out = capsys.readouterr().out
    rep = json.loads(rep_inc.read_text())
    assert code_inc == 0
    assert rep["passed"] is True
    assert rep["single_feature"]["headroom_status"] == "inconclusive"
    assert len(rep["inconclusive"]) == 1
    assert "INCONCLUSIVE" in out
    # The pass message no longer claims adequate headroom.
    assert "headroom above the best single feature is adequate" not in out

    # Same table with the headroom check disabled: same exit status.
    common_off = dict(common, min_headroom=0.0)
    code_off = gate.run(report_path=None, full_macro_f1=0.25, **common_off)
    assert code_off == code_inc


def test_repeats_summary_keeps_first_seed_verdict(tmp_path):
    df = _table()
    path = tmp_path / "features.csv"
    df.to_csv(path, index=False)
    kw = dict(
        features_path=str(path), label="technique", group="sample_id",
        min_distinct_ratio=0.0, max_constant_fraction=1.0,
        max_affected_fraction=1.0, max_single_feature_f1=1.01,
        permutation_tolerance=1.0, seed=3, skip_single_feature=False,
        min_headroom=0.0, full_macro_f1=0.95,
    )
    one = tmp_path / "one.json"
    three = tmp_path / "three.json"
    gate.run(report_path=str(one), repeats=1, **kw)
    gate.run(report_path=str(three), repeats=3, **kw)
    r1 = json.loads(one.read_text())
    r3 = json.loads(three.read_text())
    assert "single_feature_repeats" not in r1
    rep = r3["single_feature_repeats"]
    assert rep["seeds"] == [3, 4, 5]
    assert rep["verdict_seed"] == 3
    # The first seed's single_feature block and verdict are unchanged.
    assert r3["single_feature"] == r1["single_feature"]
    assert r3["passed"] == r1["passed"] and r3["failures"] == r1["failures"]
    b1 = rep["best_1_macro_f1"]
    assert b1["values"][0] == r1["single_feature"]["best_macro_f1"]
    assert b1["min"] <= b1["mean"] <= b1["max"]
    assert set(rep["best_k_macro_f1"]) == {"2", "3"}
    assert rep["headroom_R"]["n_defined"] == 3
