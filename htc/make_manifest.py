"""
Generate the HTCondor manifests for the ObfuScope grid.

Writes ``grid.txt`` -- one line per experiment cell in the exact column order
expected by ``experiment.sub`` (``queue task, protocol, model, feature_set, seed
from grid.txt``). Because it calls the same :func:`enumerate_cells` used by the
local runner, the cluster executes an identical set of cells to the laptop.

    python make_manifest.py --out grid.txt

Optionally emits a ``full`` grid (all models x all feature sets x all protocols x
more seeds) for the large-scale OSPool run reported in the paper.
"""
from __future__ import annotations

import argparse
import itertools
import os
import sys

# Allow running from the htc/ directory without installing the package.
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "src"))
# Only the light, dependency-free modules are imported here, so make_manifest.py
# runs on a bare HTCondor access point that has no numpy/scikit-learn.
from obfuscope.make_grid import enumerate_cells, Cell  # noqa: E402
from obfuscope.config import FEATURE_SETS, MODEL_NAMES  # noqa: E402


def full_grid(seeds):
    keys = ["task", "protocol", "model", "feature_set", "seed"]
    g = {"task": ["provenance", "sub_provenance"],
         "protocol": ["grouped_cv", "lomfo", "looo"],
         "model": MODEL_NAMES,
         "feature_set": list(FEATURE_SETS.keys()),
         "seed": list(range(seeds))}
    from obfuscope.make_grid import Cell
    seen, cells = set(), []
    for vals in itertools.product(*(g[k] for k in keys)):
        c = Cell(*vals)
        if c.cell_id not in seen:
            seen.add(c.cell_id); cells.append(c)
    return cells


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="grid.txt")
    ap.add_argument("--full", action="store_true",
                    help="emit the full paper-scale grid instead of the curated one")
    ap.add_argument("--seeds", type=int, default=10,
                    help="number of seeds when --full is set")
    args = ap.parse_args()
    cells = full_grid(args.seeds) if args.full else enumerate_cells()
    with open(args.out, "w") as fh:
        for c in cells:
            fh.write(f"{c.task}, {c.protocol}, {c.model}, {c.feature_set}, {c.seed}\n")
    print(f"wrote {len(cells)} cells to {args.out}")


if __name__ == "__main__":
    main()
