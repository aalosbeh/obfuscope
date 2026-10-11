#!/usr/bin/env bash
# Execution-point wrapper for ONE experiment cell.
#
# HTCondor delivers: the obfuscope source tarball, the feature table, and five
# positional arguments describing the cell. The script unpacks the code, runs the
# single-cell experiment, and leaves a result JSON in the working directory for
# HTCondor to transfer back. All paths are relative to the job scratch dir, as
# required on the OSPool.
set -euo pipefail

TASK="$1"; PROTOCOL="$2"; MODEL="$3"; FEATURE_SET="$4"; SEED="$5"
DATA="${6:-features.csv}"

echo "[ep] host=$(hostname) task=${TASK} protocol=${PROTOCOL} model=${MODEL} " \
     "fset=${FEATURE_SET} seed=${SEED}"

# Code arrives as obfuscope_src.tar.gz (see experiment.sub).
tar xzf obfuscope_src.tar.gz
export PYTHONPATH="${PWD}/src:${PYTHONPATH:-}"

CELL_ID="${TASK}__${PROTOCOL}__${MODEL}__${FEATURE_SET}__s${SEED}"
OUT="${CELL_ID}.json"

python3 -m obfuscope.experiment \
    --data "${DATA}" \
    --task "${TASK}" --protocol "${PROTOCOL}" --model "${MODEL}" \
    --feature-set "${FEATURE_SET}" --seed "${SEED}" \
    --out "${OUT}"

echo "[ep] wrote ${OUT}"
ls -la "${OUT}"
