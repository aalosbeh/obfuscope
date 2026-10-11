#!/usr/bin/env bash
# DAGMan PRE script for the GRID node: (re)generate the cell manifest.
set -euo pipefail
python3 make_manifest.py --out grid.txt
echo "grid.txt has $(wc -l < grid.txt) cells"
