"""Tests for the opt-in --permute-groups behaviour of grouped_cv."""
import json
import os
import sys

import numpy as np
import pytest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "src"))

from obfuscope.protocols import grouped_cv, iter_splits, permuted_group_codes  # noqa: E402

PILOT = os.path.join(ROOT, "data", "features_pilot.csv")


def _balanced_design(n_groups=30):
    """Every group has identical label counts, as in the pilot corpus."""
    groups, y = [], []
    for g in range(n_groups):
        for label, count in (("a", 3), ("b", 3), ("c", 2), ("d", 2)):
            groups += [f"prog{g:02d}"] * count
            y += [label] * count
    return np.array(groups), np.array(y)


def _partition(groups, y, seed, permute):
    return [frozenset(groups[sp.test_idx].tolist())
            for sp in grouped_cv(groups, y, n_splits=5, seed=seed,
                                 permute_groups=permute)]


def test_default_partitions_identical_across_seeds():
    groups, y = _balanced_design()
    assert _partition(groups, y, 0, False) == _partition(groups, y, 1, False)


def test_permuted_partitions_differ_across_seeds():
    groups, y = _balanced_design()
    p0 = _partition(groups, y, 0, True)
    p1 = _partition(groups, y, 1, True)
    assert set(p0) != set(p1)
    # Still deterministic for a fixed seed.
    assert p0 == _partition(groups, y, 0, True)


def test_permuted_partition_is_still_a_grouped_partition():
    groups, y = _balanced_design()
    for seed in range(3):
        splits = list(grouped_cv(groups, y, n_splits=5, seed=seed,
                                 permute_groups=True))
        test_rows = np.concatenate([sp.test_idx for sp in splits])
        assert sorted(test_rows.tolist()) == list(range(len(y)))
        for sp in splits:
            assert set(groups[sp.train_idx]).isdisjoint(set(groups[sp.test_idx]))


def test_permuted_group_codes_preserve_grouping():
    groups, _ = _balanced_design(6)
    codes = permuted_group_codes(groups, 3)
    for g in set(groups.tolist()):
        assert len(set(codes[groups == g].tolist())) == 1
    assert len(set(codes.tolist())) == len(set(groups.tolist()))


def test_iter_splits_passes_flag_and_ignores_it_elsewhere():
    groups, y = _balanced_design()
    a = iter_splits("grouped_cv", groups=groups, y=y, seed=1, permute_groups=True)
    b = iter_splits("grouped_cv", groups=groups, y=y, seed=1)
    assert [frozenset(groups[s.test_idx]) for s in a] != \
        [frozenset(groups[s.test_idx]) for s in b]
    fam = np.array([g[:5] for g in groups])  # 6 groups of 5 programs
    c = iter_splits("lomfo", groups=groups, y=y, families=fam, seed=1,
                    permute_groups=True)
    d = iter_splits("lomfo", groups=groups, y=y, families=fam, seed=1)
    assert [s.test_idx.tolist() for s in c] == [s.test_idx.tolist() for s in d]


def test_pilot_partitions_seed0_vs_seed1():
    pd = pytest.importorskip("pandas")
    if not os.path.exists(PILOT):
        pytest.skip("data/features_pilot.csv not present")
    df = pd.read_csv(PILOT, usecols=["sample_id", "technique"])
    g, y = df["sample_id"].to_numpy(), df["technique"].to_numpy()
    assert _partition(g, y, 0, False) == _partition(g, y, 1, False)
    assert set(_partition(g, y, 0, True)) != set(_partition(g, y, 1, True))


def test_default_cell_reproduces_committed_result():
    """Without the flag a grouped_cv cell equals the committed one."""
    pytest.importorskip("pandas")
    committed = os.path.join(ROOT, "results", "pilot5",
                             "provenance_grouped_cv_logreg_all_s0.json")
    if not (os.path.exists(PILOT) and os.path.exists(committed)):
        pytest.skip("pilot table or committed cell not present")
    from obfuscope.experiment import run_cell
    res = run_cell(PILOT, "provenance", "grouped_cv", "logreg", "all", seed=0)
    with open(committed) as fh:
        ref = json.load(fh)
    assert "permute_groups" not in res
    assert [f["macro_f1"] for f in res["per_fold"]] == \
        [f["macro_f1"] for f in ref["per_fold"]]
    assert all("test_groups" not in f for f in res["per_fold"])
    perm = run_cell(PILOT, "provenance", "grouped_cv", "logreg", "all", seed=0,
                    permute_groups=True)
    assert perm["permute_groups"] is True
    assert all(len(f["test_groups"]) == 6 for f in perm["per_fold"])
