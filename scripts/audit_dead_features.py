"""Report which declared features carry no variation on a corpus.

A feature that takes one value across every artifact cannot contribute to any
model, and a feature set defined by name rather than by content can therefore
declare far more capacity than it delivers. Version 1 of this work defined an
ablation over named feature sets and read a small accuracy change as evidence
that the result did not depend on obfuscation specific markers. The set it
removed declared 14 features and removed 4 live ones, so the comparison could
not have shown what it was read as showing.

This script makes that visible before any ablation is interpreted. It reports:

  dead                features constant across the whole corpus
  dead_by_family      the same list grouped by declared feature family
  live_by_family      the complement, which is what each family actually offers
  per set counts      declared, present in the table, and alive, for every
                      named feature set including the deprecated aliases

A feature is counted dead when its number of distinct values in the table is
one. That is a deliberately weak test: a feature with two distinct values in
2400 rows is alive by this definition and still close to useless. The intent is
to catch the unambiguous case, because the unambiguous case is the one that was
missed.

Usage
    python3 scripts/audit_dead_features.py --features data/features_pilot.csv \
        --report results/dead_features.json \
        --set-report results/feature_set_live_counts.json
"""

from __future__ import annotations

import argparse
import json
import os
import sys
from typing import Dict, List, Optional, Sequence

import pandas as pd

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "src"))

from obfuscope.config import FEATURE_SETS  # noqa: E402
from obfuscope.features import FEATURE_FAMILIES, feature_names  # noqa: E402


def dead_columns(df: pd.DataFrame, cols: Sequence[str]) -> List[str]:
    """Columns present in the table whose value never changes."""
    return sorted(c for c in cols
                  if c in df.columns and df[c].nunique(dropna=False) <= 1)


def run(features_path: str, report_path: Optional[str],
        set_report_path: Optional[str]) -> int:
    df = pd.read_csv(features_path)
    declared = feature_names()
    dead = set(dead_columns(df, declared))

    dead_by_family: Dict[str, List[str]] = {}
    live_by_family: Dict[str, List[str]] = {}
    for family, cols in FEATURE_FAMILIES.items():
        d = sorted(c for c in cols if c in dead)
        live = sorted(c for c in cols if c in df.columns and c not in dead)
        if d:
            dead_by_family[family] = d
        if live:
            live_by_family[family] = live

    print(f"features table      {features_path}")
    print(f"rows                {len(df)}")
    print(f"declared features   {len(declared)}")
    print(f"constant features   {len(dead)}")
    print()
    print("by declared family")
    header = f"  {'family':14s} {'declared':>9s} {'alive':>6s} {'constant':>9s}"
    print(header)
    print("  " + "-" * (len(header) - 2))
    for family, cols in FEATURE_FAMILIES.items():
        n_dead = len(dead_by_family.get(family, []))
        print(f"  {family:14s} {len(cols):9d} {len(cols) - n_dead:6d} "
              f"{n_dead:9d}")
    print()

    # The point of the per set table. A set is a promise about how much of the
    # representation is being withheld, and the declared count is the promise
    # while the live count is what is actually withheld.
    set_counts: Dict[str, Dict[str, int]] = {}
    print("by named feature set")
    header = (f"  {'set':22s} {'declared':>9s} {'present':>8s} {'alive':>6s}")
    print(header)
    print("  " + "-" * (len(header) - 2))
    for name, families in FEATURE_SETS.items():
        cols = feature_names(families)
        present = [c for c in cols if c in df.columns]
        live = [c for c in present if c not in dead]
        set_counts[name] = {
            "declared": len(cols),
            "present": len(present),
            "live": len(live),
        }
        print(f"  {name:22s} {len(cols):9d} {len(present):8d} {len(live):6d}")
    print()
    print("A set whose declared count exceeds its live count by a wide margin "
          "cannot support a claim about what removing it does, because most of "
          "what it removes was never contributing.")
    print()

    if report_path:
        os.makedirs(os.path.dirname(report_path) or ".", exist_ok=True)
        with open(report_path, "w") as fh:
            json.dump({
                "n_features": len(declared),
                "dead": sorted(dead),
                "dead_by_family": dead_by_family,
                "live_by_family": live_by_family,
            }, fh, indent=2)
        print(f"report written to {report_path}")

    if set_report_path:
        os.makedirs(os.path.dirname(set_report_path) or ".", exist_ok=True)
        with open(set_report_path, "w") as fh:
            json.dump(set_counts, fh, indent=2)
        print(f"report written to {set_report_path}")
    return 0


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(
        description="Report constant features and the live size of every "
                    "named feature set.")
    ap.add_argument("--features", required=True)
    ap.add_argument("--report", default=None)
    ap.add_argument("--set-report", default=None)
    args = ap.parse_args(argv)
    return run(args.features, args.report, args.set_report)


if __name__ == "__main__":
    raise SystemExit(main())
