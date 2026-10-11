#!/usr/bin/env bash
# Package the obfuscope Python source for shipping to HTCondor execution
# points via transfer_input_files. Produces htc/obfuscope_src.tar.gz such that
# `tar xzf obfuscope_src.tar.gz` on an execution point yields ./src and ./scripts trees,
# matching the PYTHONPATH setup in features.sh / experiment.sh / merge.sh /
# aggregate.sh.
#
# Used automatically as the DAGMan PRE script for the CORPUS node (see
# obfuscope.dag) so `condor_submit_dag obfuscope.dag` always ships current
# code. Also safe to run by hand after any source change, before submitting
# an individual stage (condor_submit features.sub / experiment.sub / ...).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="${ROOT}/htc/obfuscope_src.tar.gz"

# scripts/ ships alongside src/ because the CORPUS and GATE stages invoke
# scripts/build_corpus_tigress.py and scripts/diversity_gate.py directly.
tar czf "${OUT}" -C "${ROOT}" src scripts

echo ">> wrote ${OUT} ($(du -h "${OUT}" | cut -f1))"
