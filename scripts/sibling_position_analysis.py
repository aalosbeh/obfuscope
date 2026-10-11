"""Does the measured inversion depend on which sibling is held out?

The Gaussian mixture model in ``holdout_inversion_sim.py`` makes a falsifiable
prediction about the measured corpus. Its claim is that a parameterisation
holdout inverts the posterior when the removed class sits at an end of an
ordered sibling axis, because the removed artifacts then project onto a single
nearest retained sibling with nothing competing on the far side, while retained
classes keep splitting posterior mass with neighbours on both sides. When the
removed class sits between two retained siblings, the prediction is no
inversion.

That prediction can be tested here rather than assumed, and it is worth testing
precisely because it could fail. The test does not rely on knowing the true
geometry. Each sibling's position is measured from the data: the class centroid
is computed in standardised feature space, the family centroid is subtracted,
and the siblings of a family are projected onto the first principal direction of
their own centroids. A class whose projection is the largest or smallest within
its family is an end of the axis. A class strictly between two others is
interior. Families with only two siblings have no interior member and both are
ends, so they are reported separately and excluded from the contrast.

The per fold AUROC values are then grouped by that position and compared. The
comparison is unpaired, because a fold is defined by which class was removed and
no fold exists in both groups, so a paired test is not available. Instead the
difference is reported with a Welch statistic, which does not assume equal
variances, together with the full per class table so a reader can see the
spread rather than only the summary.

A failure of the prediction would mean the mixture model explains something
other than what the corpus does, and the structural argument would have to be
withdrawn. That is the point of running it.

Usage
    python3 scripts/sibling_position_analysis.py \
        --openset results/openset_v2_subtechnique.json \
        --features data/features_pilot.csv \
        --report results/sibling_position.json
"""

from __future__ import annotations

import argparse
import json
import os
from typing import Dict, List, Optional, Sequence

import numpy as np
import pandas as pd


def sibling_positions(features_path: str) -> Dict[str, Dict]:
    """Classify every sub technique as an end or an interior member of its family.

    Positions are measured, not assumed. Features are standardised so no single
    wide ranging column dominates the geometry, class centroids are taken, the
    family centroid is removed, and the siblings are projected onto the leading
    principal direction of their own centroid cloud. That direction is the axis
    the parameterisations vary along, if they vary along one at all.
    """
    df = pd.read_csv(features_path)
    label_cols = ["path", "cohort", "sample_id", "technique", "sub_technique",
                  "malware_family"]
    feats = [c for c in df.columns
             if c not in label_cols and pd.api.types.is_numeric_dtype(df[c])]

    x = df[feats].astype("float64").fillna(0.0)
    sd = x.std(axis=0).replace(0.0, 1.0)
    z = (x - x.mean(axis=0)) / sd

    out: Dict[str, Dict] = {}
    for fam, grp in df.groupby("technique"):
        subs = sorted(grp["sub_technique"].unique())
        centroids = np.stack([z.loc[grp.index[grp["sub_technique"] == s]].mean(axis=0)
                              .to_numpy() for s in subs])
        centred = centroids - centroids.mean(axis=0)

        if len(subs) < 2:
            continue
        # Leading principal direction of the sibling centroids.
        u, s_vals, vt = np.linalg.svd(centred, full_matrices=False)
        axis = vt[0]
        proj = centred @ axis
        # Share of sibling centroid variance captured by that one direction.
        explained = (float(s_vals[0] ** 2 / (s_vals ** 2).sum())
                     if (s_vals ** 2).sum() > 0 else 0.0)

        order = np.argsort(proj)
        for rank, i in enumerate(order):
            if len(subs) == 2:
                position = "end_of_pair"
            elif rank == 0 or rank == len(subs) - 1:
                position = "end"
            else:
                position = "interior"
            out[subs[i]] = {
                "family": str(fam),
                "position": position,
                "rank_in_family": rank,
                "n_siblings": len(subs),
                "projection": round(float(proj[i]), 4),
                "axis_variance_explained": round(explained, 4),
            }
    return out


def welch(a: Sequence[float], b: Sequence[float]) -> Dict:
    """Welch statistic for two groups with possibly unequal variances."""
    a, b = np.asarray(a, dtype=float), np.asarray(b, dtype=float)
    if len(a) < 2 or len(b) < 2:
        return {"skipped": "need at least two observations per group"}
    va, vb = a.var(ddof=1), b.var(ddof=1)
    se = np.sqrt(va / len(a) + vb / len(b))
    if se == 0:
        return {"skipped": "zero standard error"}
    t = (a.mean() - b.mean()) / se
    # Welch Satterthwaite degrees of freedom.
    num = (va / len(a) + vb / len(b)) ** 2
    den = (va / len(a)) ** 2 / (len(a) - 1) + (vb / len(b)) ** 2 / (len(b) - 1)
    return {
        "mean_a": round(float(a.mean()), 4),
        "mean_b": round(float(b.mean()), 4),
        "difference": round(float(a.mean() - b.mean()), 4),
        "n_a": int(len(a)), "n_b": int(len(b)),
        "t_statistic": round(float(t), 3),
        "welch_df": round(float(num / den), 1) if den > 0 else None,
    }


def run(openset_path: str, features_path: str, scorer: str,
        report_path: Optional[str]) -> int:
    with open(openset_path) as fh:
        res = json.load(fh)
    positions = sibling_positions(features_path)

    print(f"open set report   {openset_path}")
    print(f"holdout unit      {res.get('holdout_unit')}")
    print(f"label             {res.get('label')}")
    print(f"scorer            {scorer}")
    print(f"folds             {len(res['per_fold'])}")
    print()

    print("measured sibling positions")
    print(f"  {'sub technique':18s} {'family':20s} {'position':12s} "
          f"{'rank':>5s} {'proj':>9s} {'axis var':>9s}")
    for name in sorted(positions, key=lambda n: (positions[n]["family"],
                                                 positions[n]["rank_in_family"])):
        p = positions[name]
        print(f"  {name:18s} {p['family']:20s} {p['position']:12s} "
              f"{p['rank_in_family']:5d} {p['projection']:9.3f} "
              f"{p['axis_variance_explained']:9.3f}")
    print("  axis var is the share of sibling centroid variance on the leading "
          "direction; a low")
    print("  value means the siblings are not well described by a single axis "
          "and the end versus")
    print("  interior distinction is correspondingly weaker.")
    print()

    # Collect per fold AUROC by held out class.
    by_class: Dict[str, List[float]] = {}
    for fold in res["per_fold"]:
        sc = fold["scorers"].get(scorer, {})
        if "auroc" not in sc:
            continue
        by_class.setdefault(fold["novel_class"], []).append(float(sc["auroc"]))

    print(f"per held out class AUROC, {scorer}, pooled over models and seeds")
    print(f"  {'sub technique':18s} {'position':12s} {'n':>4s} {'mean':>8s} "
          f"{'sd':>8s} {'min':>8s} {'max':>8s}")
    rows = []
    for name in sorted(by_class, key=lambda n: positions.get(n, {}).get("family", "")):
        v = np.asarray(by_class[name], dtype=float)
        pos = positions.get(name, {}).get("position", "unknown")
        rows.append({"sub_technique": name, "position": pos,
                     "family": positions.get(name, {}).get("family"),
                     "n_folds": int(v.size),
                     "auroc_mean": round(float(v.mean()), 4),
                     "auroc_sd": round(float(v.std(ddof=1)), 4) if v.size > 1 else 0.0,
                     "auroc_min": round(float(v.min()), 4),
                     "auroc_max": round(float(v.max()), 4)})
        print(f"  {name:18s} {pos:12s} {v.size:4d} {v.mean():8.4f} "
              f"{(v.std(ddof=1) if v.size > 1 else 0.0):8.4f} "
              f"{v.min():8.4f} {v.max():8.4f}")
    print()

    groups: Dict[str, List[float]] = {}
    for name, v in by_class.items():
        groups.setdefault(positions.get(name, {}).get("position", "unknown"),
                          []).extend(v)

    print("grouped by measured position")
    for pos in sorted(groups):
        v = np.asarray(groups[pos], dtype=float)
        print(f"  {pos:12s} n={v.size:4d}  mean AUROC {v.mean():.4f}  "
              f"sd {v.std(ddof=1):.4f}  share of folds below 0.5 "
              f"{float((v < 0.5).mean()):.3f}")
    print()

    verdict = None
    contrast = None
    if "end" in groups and "interior" in groups:
        contrast = welch(groups["end"], groups["interior"])
        print("contrast, ends against interior members, families of three only")
        for k, v in contrast.items():
            print(f"  {k:20s} {v}")
        if "difference" in contrast:
            if contrast["difference"] < 0:
                verdict = ("consistent with the model: ends invert further than "
                           "interior members")
            else:
                verdict = ("inconsistent with the model: ends do not invert "
                           "further than interior members, so the ordered axis "
                           "explanation does not account for the measured "
                           "inversion and must be withdrawn or revised")
        print()
    else:
        verdict = ("not testable on this corpus: the contrast needs at least "
                   "one family with three or more siblings and a measurable "
                   "interior member")

    print("verdict")
    print(f"  {verdict}")

    report = {
        "openset_report": openset_path,
        "scorer": scorer,
        "positions": positions,
        "per_class": rows,
        "grouped": {k: {"n": len(v),
                        "mean": round(float(np.mean(v)), 4),
                        "sd": round(float(np.std(v, ddof=1)), 4) if len(v) > 1 else 0.0,
                        "fraction_below_half": round(float(np.mean(np.asarray(v) < 0.5)), 4)}
                    for k, v in groups.items()},
        "contrast_end_vs_interior": contrast,
        "verdict": verdict,
    }
    if report_path:
        os.makedirs(os.path.dirname(report_path) or ".", exist_ok=True)
        with open(report_path, "w") as fh:
            json.dump(report, fh, indent=2)
        print()
        print(f"report written to {report_path}")
    return 0


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(
        description="Test whether the measured parameterisation holdout "
                    "inversion depends on the position of the held out sibling "
                    "along its family's axis.")
    ap.add_argument("--openset", default="results/openset_v2_subtechnique.json")
    ap.add_argument("--features", default="data/features_pilot.csv")
    ap.add_argument("--scorer", default="msp")
    ap.add_argument("--report", default=None)
    args = ap.parse_args(argv)
    return run(args.openset, args.features, args.scorer, args.report)


if __name__ == "__main__":
    raise SystemExit(main())
