"""Tests for scripts/aggregate_seeds.py: duplicate detection and the fold
level paired summary."""
import itertools
import json
import os
import sys

import numpy as np
import pytest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "scripts"))

import aggregate_seeds as ag  # noqa: E402


def _cell(model, seed, f1s, test_groups=None, task="provenance",
          protocol="grouped_cv", fset="all"):
    folds = []
    for i, v in enumerate(f1s):
        f = {"macro_f1": float(v), "fold_id": f"fold{i}"}
        if test_groups is not None:
            f["test_groups"] = list(test_groups[i])
        folds.append(f)
    return {"task": task, "protocol": protocol, "model": model,
            "feature_set": fset, "seed": seed, "per_fold": folds}


def test_duplicate_seed_raises_in_decompose_and_paired_tests():
    cells = [_cell("rf", 0, [0.9] * 5), _cell("rf", 0, [0.8] * 5)]
    with pytest.raises(ValueError, match="duplicate"):
        ag.decompose(cells)
    other = [_cell("et", 0, [0.7] * 5)]
    with pytest.raises(ValueError, match="duplicate"):
        ag.paired_fold_test(cells, other)
    with pytest.raises(ValueError, match="duplicate"):
        ag.paired_fold_level(cells, other)


def test_duplicate_seed_raises_when_loading_a_directory(tmp_path):
    for name in ("a.json", "b.json"):
        with open(tmp_path / name, "w") as fh:
            json.dump(_cell("rf", 3, [0.9] * 5), fh)
    with pytest.raises(ValueError, match="duplicate"):
        ag.load(str(tmp_path))
    with pytest.raises(ValueError, match="duplicate"):
        ag.run(str(tmp_path), None)


def test_fold_level_counts_each_fold_once():
    # Five folds repeated identically at five seeds, as for a deterministic
    # estimator under the committed grids.
    a_f1 = [0.90, 0.80, 0.85, 0.97, 0.70]
    b_f1 = [0.85, 0.82, 0.85, 0.90, 0.60]
    a = [_cell("a", s, a_f1) for s in range(5)]
    b = [_cell("b", s, b_f1) for s in range(5)]
    old = ag.paired_fold_test(a, b)
    assert old["n_pairs"] == 25 and old["folds_won"] == 15
    fl = ag.paired_fold_level(a, b)
    assert fl["fold_identity"] == "fold_index"
    assert fl["n_distinct_folds"] == 5
    assert fl["n_seeds_per_fold"] == [5]
    assert (fl["folds_won"], fl["folds_tied"], fl["folds_lost"]) == (3, 1, 1)
    # Sign test on 3 wins vs 1 loss: 2 * (1 + 4) / 16.
    assert fl["sign_test_p_two_sided"] == pytest.approx(10 / 16)
    from scipy.stats import wilcoxon
    d = [x for x in np.subtract(a_f1, b_f1) if abs(x) > 1e-12]
    ref = wilcoxon(d, method="exact").pvalue
    assert fl["wilcoxon_p_two_sided_exact"] == pytest.approx(ref, abs=1e-6)


def test_sign_test_exact_values():
    assert ag._sign_test_p(5, 0) == pytest.approx(2 / 32)
    assert ag._sign_test_p(0, 0) == 1.0
    assert ag._sign_test_p(3, 3) == pytest.approx(1.0)


@pytest.mark.parametrize("d", [
    [0.3, -0.1, 0.2, 0.5, 0.4],
    [0.1, 0.1, -0.1, 0.2, 0.3, -0.05],     # tied absolute values
    [0.2, -0.2, 0.2, 0.0, 0.4],            # zero dropped, ties
    [0.90 - 0.85, 0.95 - 0.90, -0.02],     # equal only up to float noise
])
def test_wilcoxon_exact_matches_brute_force(d):
    from scipy.stats import rankdata
    w, p, n = ag._wilcoxon_exact_p(d)
    nz = np.array([x for x in d if abs(x) > 1e-12])
    r = rankdata(np.round(np.abs(nz), 12))
    w_obs = r[nz > 0].sum()
    centre = r.sum() / 2
    hits = 0
    for signs in itertools.product([0, 1], repeat=len(nz)):
        wp = r[np.array(signs, dtype=bool)].sum()
        hits += abs(wp - centre) >= abs(w_obs - centre) - 1e-9
    assert n == len(nz)
    assert w == pytest.approx(w_obs)
    assert p == pytest.approx(hits / 2 ** len(nz))


def test_fold_level_uses_test_groups_when_recorded():
    # Different partitions per seed: every (seed, fold) is a distinct fold.
    def groups(seed):
        progs = [f"p{i}" for i in range(10)]
        rng = np.random.RandomState(seed)
        perm = [progs[i] for i in rng.permutation(10)]
        return [sorted(perm[2 * k:2 * k + 2]) for k in range(5)]
    a = [_cell("a", s, [0.9] * 5, groups(s)) for s in range(2)]
    b = [_cell("b", s, [0.8] * 5, groups(s)) for s in range(2)]
    fl = ag.paired_fold_level(a, b)
    assert fl["fold_identity"] == "test_groups"
    n_distinct = len({tuple(g) for s in range(2) for g in groups(s)})
    assert fl["n_distinct_folds"] == n_distinct
    assert fl["folds_won"] == n_distinct


def test_committed_reports_reproduced_with_existing_keys():
    for rdir, ref in (("pilot5", "closed_set_five_seed.json"),
                      ("pilot5sub", "closed_set_five_seed_sub.json")):
        rpath = os.path.join(ROOT, "results", rdir)
        refpath = os.path.join(ROOT, "results", ref)
        if not (os.path.isdir(rpath) and os.path.exists(refpath)):
            pytest.skip("committed grids not present")
        cells = ag.load(rpath)
        with open(refpath) as fh:
            committed = json.load(fh)
        groups = {}
        for c in cells:
            groups.setdefault(ag._key(c), []).append(c)
        got = [{"task": k[0], "protocol": k[1], "model": k[2],
                "feature_set": k[3], **ag.decompose(groups[k])}
               for k in sorted(groups)]
        assert got == committed["cells"]
