#!/usr/bin/env bash
# Execution-point wrapper for the corpus health gate.
#
# Runs between MERGE and GRID. A nonzero exit propagates to DAGMan, which stops
# the workflow, so a degenerate corpus never reaches the experiment grid.
#
# Placing the gate here rather than at the end is the whole point. The grid is
# the expensive stage, and a corpus whose classes have no within-class variation
# produces saturated metrics that look like a strong result. Catching that after
# the grid means a retraction; catching it here means a rebuild.
set -euo pipefail

tar xzf obfuscope_src.tar.gz
export PYTHONPATH="${PWD}/src:${PYTHONPATH:-}"

MIN_DISTINCT="${1:-0.80}"
MAX_SINGLE_F1="${2:-0.70}"

echo "[ep] host=$(hostname) gate on $(wc -l < features.csv) lines"

STATUS=0
python3 scripts/diversity_gate.py \
    --features features.csv \
    --label technique \
    --group sample_id \
    --min-distinct-ratio "${MIN_DISTINCT}" \
    --max-single-feature-f1 "${MAX_SINGLE_F1}" \
    --report gate_technique.json || STATUS=$?

# The fine-grained axis is the harder one and is reported for the record even
# when the coarse axis has already failed, so one run gives the full picture.
python3 scripts/diversity_gate.py \
    --features features.csv \
    --label sub_technique \
    --group sample_id \
    --min-distinct-ratio "${MIN_DISTINCT}" \
    --max-single-feature-f1 "${MAX_SINGLE_F1}" \
    --report gate_sub_technique.json || true

exit "${STATUS}"
