"""Pool the closed set grid over seeds and split the spread into its sources.

Version 1 reported a single standard deviation next to every macro F1 and
described it as the spread over folds and seeds. The grid behind those numbers
was run at one seed, so the figure was fold spread alone. This script reads the
five seed grid and reports three quantities per cell instead of one:

  mean            macro F1 averaged over every fold of every seed
  sd_fold         spread between folds, averaged within a seed then over seeds
  sd_seed         spread between the per seed means

Separating them matters because they answer different questions. Fold spread
says how much the estimate moves when the held out programs change. Seed spread
says how much it moves when only the random initialisation changes, with the
data fixed. A result whose seed spread approaches its fold spread is not a
stable measurement of the corpus, it is a measurement of the optimiser.

A paired comparison between two models is also reported. Pairing is done on the
fold identity, so each difference holds the held out programs constant and the
only thing that changes is the model. A count of overlapping standard
deviations, which is what version 1 used, ignores that pairing and throws away
the within fold correlation that makes the comparison sensitive.

The 25 differences of a five fold, five seed grid are not 25 independent
observations. Under the committed grids every seed uses the same five folds
(see obfuscope.protocols.grouped_cv), so a deterministic estimator contributes
five copies of each fold. Each comparison therefore also carries a
``fold_level`` summary: the difference is averaged over seeds within each
distinct fold, and wins, ties and losses, an exact two sided sign test and an
exact Wilcoxon signed rank test are computed on those per fold means. A
distinct fold is identified by its held out programs (``test_groups``) when
every cell records them (``obfuscope.experiment --permute-groups``), and by
the fold index otherwise, which assumes the partition is identical across
seeds, as it is for the committed grids.

Two cells with the same (task, protocol, model, feature_set, seed) are an
error: the earlier behaviour silently kept the last one read.

Usage
    python3 scripts/aggregate_seeds.py --results results/pilot5 \
        --report results/closed_set_five_seed.json
"""

from __future__ import annotations

import argparse
import glob
import json
import math
import os
from typing import Dict, List, Optional, Sequence, Tuple

import numpy as np


def load(results_dir: str) -> List[Dict]:
    cells = []
    seen: Dict[Tuple, str] = {}
    for path in sorted(glob.glob(os.path.join(results_dir, "*.json"))):
        with open(path) as fh:
            cell = json.load(fh)
        k = _key(cell) + (int(cell["seed"]),)
        if k in seen:
            raise ValueError(
                f"duplicate (config, seed) {k}: {seen[k]} and {path}")
        seen[k] = path
        cells.append(cell)
    if not cells:
        raise ValueError(f"no result cells found in {results_dir}")
    return cells


def _check_unique_seeds(cells: Sequence[Dict]) -> None:
    """Raise if two cells share (task, protocol, model, feature_set, seed)."""
    seen = set()
    for cell in cells:
        k = _key(cell) + (int(cell["seed"]),)
        if k in seen:
            raise ValueError(f"duplicate (config, seed) entry {k}")
        seen.add(k)


def _key(cell: Dict) -> Tuple[str, str, str, str]:
    return (cell["task"], cell["protocol"], cell["model"], cell["feature_set"])


def decompose(cells: Sequence[Dict]) -> Dict:
    """Mean macro F1 with the fold and seed components of its spread."""
    _check_unique_seeds(cells)
    by_seed: Dict[int, List[float]] = {}
    for cell in cells:
        folds = [f["macro_f1"] for f in cell["per_fold"]]
        by_seed[int(cell["seed"])] = folds

    seeds = sorted(by_seed)
    per_seed_mean = np.array([float(np.mean(by_seed[s])) for s in seeds])
    # Fold spread is computed inside a seed and then averaged, so the seed to
    # seed offset does not inflate it.
    per_seed_sd = np.array(
        [float(np.std(by_seed[s], ddof=1)) if len(by_seed[s]) > 1 else 0.0
         for s in seeds]
    )
    pooled = np.concatenate([np.asarray(by_seed[s], dtype=float) for s in seeds])

    return {
        "n_seeds": len(seeds),
        "n_folds_per_seed": int(np.mean([len(by_seed[s]) for s in seeds])),
        "n_measurements": int(pooled.size),
        "mean": round(float(pooled.mean()), 4),
        "sd_total": round(float(pooled.std(ddof=1)), 4),
        "sd_fold": round(float(per_seed_sd.mean()), 4),
        "sd_seed": round(float(per_seed_mean.std(ddof=1)), 4)
        if len(seeds) > 1 else 0.0,
        "per_seed_mean": [round(v, 4) for v in per_seed_mean.tolist()],
        "min_fold": round(float(pooled.min()), 4),
        "max_fold": round(float(pooled.max()), 4),
    }


def paired_fold_test(a: Sequence[Dict], b: Sequence[Dict]) -> Dict:
    """Paired difference between two cells, matched on seed and fold index.

    The alternative used in version 1 was to check whether two means sat within
    one standard deviation of each other. That treats the two sets of fold
    scores as independent samples when in fact fold i of one model and fold i of
    the other were scored on the same held out programs. Pairing removes the
    between fold variance, which is the dominant term, and leaves the model
    difference.

    Reports the mean difference, its standard error, a t statistic on the
    differences, and the fraction of folds in which the first cell wins. These
    treat every (seed, fold) pair as an observation. When the partition is the
    same at every seed the pairs are not independent (a deterministic
    estimator repeats each fold exactly), so neither the t statistic nor the
    win count is a valid test; see :func:`paired_fold_level` for the summary
    over distinct folds.
    """
    _check_unique_seeds(a)
    _check_unique_seeds(b)
    index_a = {(int(c["seed"]), i): f["macro_f1"]
               for c in a for i, f in enumerate(c["per_fold"])}
    index_b = {(int(c["seed"]), i): f["macro_f1"]
               for c in b for i, f in enumerate(c["per_fold"])}
    shared = sorted(set(index_a) & set(index_b))
    if len(shared) < 3:
        return {"skipped": "fewer than three paired folds"}

    d = np.array([index_a[k] - index_b[k] for k in shared], dtype=float)
    n = d.size
    sd = float(d.std(ddof=1))
    se = sd / np.sqrt(n) if sd > 0 else 0.0
    t = float(d.mean() / se) if se > 0 else float("inf") if d.mean() else 0.0
    wins = int((d > 0).sum())
    ties = int((d == 0).sum())

    return {
        "n_pairs": n,
        "mean_difference": round(float(d.mean()), 4),
        "sd_of_differences": round(sd, 4),
        "standard_error": round(se, 4),
        "t_statistic": round(t, 3),
        "folds_won": wins,
        "folds_tied": ties,
        "folds_lost": n - wins - ties,
        "win_fraction": round(wins / n, 4),
        # Cohen's d on the paired differences. Reported because a mean
        # difference of 0.01 can be decisive or meaningless depending on how
        # consistent it is across folds, and the t statistic alone confounds
        # that consistency with the number of folds.
        "paired_effect_size": round(float(d.mean() / sd), 3) if sd > 0 else None,
    }


def _sign_test_p(wins: int, losses: int) -> float:
    """Exact two sided binomial sign test, ties already removed."""
    n = wins + losses
    if n == 0:
        return 1.0
    k = min(wins, losses)
    tail = sum(math.comb(n, i) for i in range(k + 1)) / 2.0 ** n
    return float(min(1.0, 2.0 * tail))


def _wilcoxon_exact_p(d: Sequence[float], tol: float = 1e-12) -> Tuple[float, float, int]:
    """Exact two sided Wilcoxon signed rank test.

    Zero differences (``|d| <= tol``) are dropped (Wilcoxon's convention).
    Absolute differences are rounded to 12 decimals before ranking so that
    differences that are equal up to floating point noise count as ties.
    Ties among the remaining ``|d|`` get average ranks, and the null
    distribution of the positive rank sum W+ is enumerated exactly over all
    2**n sign assignments of those ranks (the permutation distribution
    conditional on the ties), so the p value stays exact with ties. Returns
    ``(W+, p, n_nonzero)``; p is 1.0 when nothing is left.
    """
    from scipy.stats import rankdata
    d = np.asarray([x for x in d if abs(x) > tol], dtype=float)
    n = int(d.size)
    if n == 0:
        return 0.0, 1.0, 0
    ranks2 = np.rint(2.0 * rankdata(np.round(np.abs(d), 12))).astype(int)  # midranks x 2
    w_obs2 = int(ranks2[d > 0].sum())
    total2 = int(ranks2.sum())
    # dist[s] = number of sign assignments whose doubled positive sum is s.
    dist = np.zeros(total2 + 1, dtype=object)
    dist[0] = 1
    for r in ranks2.tolist():
        nxt = dist.copy()
        nxt[r:] = nxt[r:] + dist[:total2 + 1 - r]
        dist = nxt
    centre2 = total2 / 2.0
    dev_obs = abs(w_obs2 - centre2)
    extreme = sum(int(c) for s2, c in enumerate(dist.tolist())
                  if abs(s2 - centre2) >= dev_obs - 1e-9)
    p = extreme / float(2 ** n)
    return w_obs2 / 2.0, float(min(1.0, p)), n


def _fold_identity(cells: Sequence[Dict]) -> str:
    """'test_groups' when every fold of every cell records them, else index."""
    if cells and all("test_groups" in f for c in cells for f in c["per_fold"]):
        return "test_groups"
    return "fold_index"


def paired_fold_level(a: Sequence[Dict], b: Sequence[Dict]) -> Dict:
    """Paired comparison on distinct folds, each averaged over seeds.

    For each seed present in both configurations and each fold present in
    both, the difference a - b in macro F1 is formed; differences are then
    averaged over seeds within each distinct fold. Wins, ties and losses,
    an exact two sided sign test and an exact Wilcoxon signed rank test are
    computed over those per fold means, so each held out fold counts once.
    """
    _check_unique_seeds(a)
    _check_unique_seeds(b)
    basis = ("test_groups" if _fold_identity(a) == "test_groups"
             and _fold_identity(b) == "test_groups" else "fold_index")

    def index(cells):
        out = {}
        for c in cells:
            for i, f in enumerate(c["per_fold"]):
                fid = (tuple(sorted(f["test_groups"])) if basis == "test_groups"
                       else i)
                out[(int(c["seed"]), fid)] = float(f["macro_f1"])
        return out

    ia, ib = index(a), index(b)
    shared = sorted(set(ia) & set(ib), key=lambda k: (k[0], str(k[1])))
    per_fold: Dict = {}
    for seed, fid in shared:
        per_fold.setdefault(fid, []).append(ia[(seed, fid)] - ib[(seed, fid)])
    fids = sorted(per_fold, key=str)
    if len(fids) < 2:
        return {"skipped": "fewer than two distinct paired folds",
                "fold_identity": basis}
    dm = np.array([float(np.mean(per_fold[f])) for f in fids])
    tol = 1e-12
    wins = int((dm > tol).sum())
    losses = int((dm < -tol).sum())
    ties = int(len(dm) - wins - losses)
    w_plus, p_w, n_nz = _wilcoxon_exact_p(dm.tolist(), tol)
    return {
        "fold_identity": basis,
        "n_distinct_folds": int(len(fids)),
        "n_seeds_per_fold": sorted({len(per_fold[f]) for f in fids}),
        "seed_averaged_differences": [round(float(v), 4) for v in dm],
        "mean_difference": round(float(dm.mean()), 4),
        "folds_won": wins,
        "folds_tied": ties,
        "folds_lost": losses,
        "sign_test_p_two_sided": round(_sign_test_p(wins, losses), 6),
        "wilcoxon_w_plus": w_plus,
        "wilcoxon_n_nonzero": n_nz,
        "wilcoxon_p_two_sided_exact": round(p_w, 6),
    }


def run(results_dir: str, report_path: Optional[str]) -> int:
    cells = load(results_dir)
    groups: Dict[Tuple[str, str, str, str], List[Dict]] = {}
    for cell in cells:
        groups.setdefault(_key(cell), []).append(cell)

    report: Dict = {"results_dir": results_dir, "cells": []}
    print(f"grid      {results_dir}")
    print(f"cells     {len(cells)}")
    print(f"configs   {len(groups)}")
    print()

    header = (f"{'task':12s} {'protocol':10s} {'model':14s} {'featureset':14s} "
              f"{'mean':>7s} {'sd_fold':>8s} {'sd_seed':>8s} {'seeds':>6s}")
    print(header)
    print("-" * len(header))

    for key in sorted(groups):
        task, protocol, model, fset = key
        stats = decompose(groups[key])
        report["cells"].append({
            "task": task, "protocol": protocol, "model": model,
            "feature_set": fset, **stats,
        })
        print(f"{task:12s} {protocol:10s} {model:14s} {fset:14s} "
              f"{stats['mean']:7.4f} {stats['sd_fold']:8.4f} "
              f"{stats['sd_seed']:8.4f} {stats['n_seeds']:6d}")
    print()
    print("sd_fold is the spread between held out folds within a seed. sd_seed "
          "is the spread between per seed means. A result is only reproducible "
          "in the sense version 1 claimed if sd_seed is small next to sd_fold.")
    print()

    # Paired model comparisons inside each task and protocol, against the best
    # mean. This replaces the standard deviation overlap argument.
    print("paired fold level comparisons against the best model in each cell")
    print()
    comparisons = []
    by_tp: Dict[Tuple[str, str, str], List[Tuple[str, List[Dict]]]] = {}
    for key, cs in groups.items():
        task, protocol, model, fset = key
        if fset != "all":
            continue
        by_tp.setdefault((task, protocol, fset), []).append((model, cs))

    for (task, protocol, fset), entries in sorted(by_tp.items()):
        if len(entries) < 2:
            continue
        ranked = sorted(entries, key=lambda e: decompose(e[1])["mean"],
                        reverse=True)
        best_model, best_cells = ranked[0]
        print(f"  {task} / {protocol} / {fset}: reference {best_model} "
              f"({decompose(best_cells)['mean']:.4f})")
        for model, cs in ranked[1:]:
            test = paired_fold_test(best_cells, cs)
            if "skipped" in test:
                continue
            fold_level = paired_fold_level(best_cells, cs)
            comparisons.append({
                "task": task, "protocol": protocol, "feature_set": fset,
                "reference": best_model, "other": model, **test,
                "fold_level": fold_level,
            })
            print(f"    vs {model:14s} diff {test['mean_difference']:+.4f} "
                  f"t {test['t_statistic']:+7.2f} "
                  f"wins {test['folds_won']}/{test['n_pairs']} "
                  f"effect {test['paired_effect_size']}")
            if "skipped" not in fold_level:
                print(f"       per distinct fold ({fold_level['fold_identity']}): "
                      f"won {fold_level['folds_won']} tied "
                      f"{fold_level['folds_tied']} lost "
                      f"{fold_level['folds_lost']} of "
                      f"{fold_level['n_distinct_folds']}  sign p "
                      f"{fold_level['sign_test_p_two_sided']:.4f}  Wilcoxon p "
                      f"{fold_level['wilcoxon_p_two_sided_exact']:.4f}")
        print()
    report["paired_comparisons"] = comparisons

    if report_path:
        os.makedirs(os.path.dirname(report_path) or ".", exist_ok=True)
        with open(report_path, "w") as fh:
            json.dump(report, fh, indent=2)
        print(f"report written to {report_path}")
    return 0


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(
        description="Pool the closed set grid over seeds and separate the fold "
                    "and seed components of the spread.")
    ap.add_argument("--results", default="results/pilot5")
    ap.add_argument("--report", default=None)
    args = ap.parse_args(argv)
    return run(args.results, args.report)


if __name__ == "__main__":
    raise SystemExit(main())
