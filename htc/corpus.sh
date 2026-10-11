#!/usr/bin/env bash
# Execution-point wrapper for ONE shard of Tigress corpus generation.
#
# Each job generates the artifacts whose relative path hashes to its shard
# (CRC32(rel_path) % NUM_SHARDS == SHARD_INDEX), which is the same partition
# function build_dataset uses, and returns them as one tarball plus a JSONL
# manifest of every attempt.
#
# Tigress must be present inside the container image. The driver verifies that
# every flag in scripts/tigress_spec.py is recognised by the installed binary
# before generating anything, so a container built against a different Tigress
# release fails here with the list of flags to fix rather than producing a
# corpus that is quietly missing whole classes.
set -euo pipefail

SHARD_INDEX="$1"; NUM_SHARDS="$2"
REPLICATES="${3:-8}"

echo "[ep] host=$(hostname) corpus shard ${SHARD_INDEX}/${NUM_SHARDS}"

tar xzf obfuscope_src.tar.gz
export PYTHONPATH="${PWD}/src:${PYTHONPATH:-}"

# Benign C program sources, delivered via OSDF (see corpus.sub).
mkdir -p programs
tar xzf programs.tar.gz -C programs

# programs.tsv ships alongside and holds lines of
#   <path relative to programs/><TAB><suite><TAB><functions>
# Rewrite the first column to the unpacked location.
awk -F'\t' 'BEGIN{OFS="\t"} /^#/ || NF==0 {print; next} {$1="programs/"$1; print}' \
    programs.tsv > programs_resolved.tsv

mkdir -p out

python3 scripts/build_corpus_tigress.py \
    --programs programs_resolved.tsv \
    --out out \
    --replicates "${REPLICATES}" \
    --shard-index "${SHARD_INDEX}" --num-shards "${NUM_SHARDS}" \
    --manifest "corpus_manifest_${SHARD_INDEX}.jsonl" \
    --compile-check cc

# Empty shards are legitimate: a shard can hold only cells whose transformation
# failed on every program. Pack regardless so the assemble step sees a tarball
# from every shard and a missing one is a real error.
tar czf "corpus_shard_${SHARD_INDEX}.tar.gz" -C out .

echo "[ep] artifacts: $(find out -name '*.c' | wc -l)"
