#!/usr/bin/env bash
# Execution-point wrapper for ONE feature-extraction shard.
#
# Each job extracts static features for the artifacts assigned to its shard
# (CRC32(path) % NUM_SHARDS == SHARD_INDEX) and returns a partial CSV. The corpus
# is staged from the OSDF so that hundreds of shards can read it from the
# distributed cache rather than the access point.
set -euo pipefail

SHARD_INDEX="$1"; NUM_SHARDS="$2"

echo "[ep] host=$(hostname) shard ${SHARD_INDEX}/${NUM_SHARDS}"

tar xzf obfuscope_src.tar.gz
export PYTHONPATH="${PWD}/src:${PYTHONPATH:-}"

# The corpus tarball is delivered via OSDF (see features.sub) and unpacked here.
mkdir -p corpus
tar xzf corpus.tar.gz -C corpus

python3 -m obfuscope.build_dataset \
    --corpus corpus \
    --out "features_shard_${SHARD_INDEX}.csv" \
    --jobs "$(nproc)" \
    --shard-index "${SHARD_INDEX}" --num-shards "${NUM_SHARDS}" \
    --no-header

echo "[ep] rows: $(wc -l < "features_shard_${SHARD_INDEX}.csv")"
