#!/usr/bin/env bash
# Reduce per-cell result JSONs into tables and figures.
set -euo pipefail
tar xzf obfuscope_src.tar.gz
export PYTHONPATH="${PWD}/src:${PYTHONPATH:-}"
mkdir -p results
tar xzf cells.tar.gz -C results
python3 -m obfuscope.aggregate --cells results/cells --out results
python3 -m obfuscope.plots --cells results/cells --summary results/summary.json --out figures
tar czf outputs.tar.gz results/tables results/summary.json figures
