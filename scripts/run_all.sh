#!/usr/bin/env bash
# One-command local reproduction of the ObfuScope study.
#   scripts/run_all.sh /path/to/extracted_corpus
set -euo pipefail
CORPUS="${1:?usage: run_all.sh /path/to/extracted_corpus}"
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
export PYTHONPATH="${ROOT}/src:${PYTHONPATH:-}"
cd "${ROOT}"

echo "== 1/4 feature extraction =="
python3 -m obfuscope.build_dataset --corpus "${CORPUS}" --out data/features.csv --jobs "$(nproc)"

echo "== 2/4 experiment grid (resumable) =="
python3 -m obfuscope.run_grid --data data/features.csv --out-dir results/cells --wall 1000000

echo "== 3/4 aggregate =="
python3 -m obfuscope.aggregate --cells results/cells --out results

echo "== 4/4 figures =="
python3 -m obfuscope.plots --cells results/cells --summary results/summary.json --out paper/figures

echo "Done. See results/tables/, results/summary.json, and paper/figures/."
