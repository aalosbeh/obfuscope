#!/usr/bin/env bash
# Stage the extracted corpus (the directory holding the *_variants/ trees) to
# the OSDF so every FEATURES shard can read it from the distributed cache
# instead of the access point.
#
# Usage: bash stage_corpus.sh /path/to/extracted_corpus
#
# Safety note: the corpus is derived from live malware (see
# ../../dataset/README.md). Keep it inside your own OSDF namespace, never on
# shared scratch, and follow your institution's handling policy. Feature
# extraction itself is execution-free (text statistics only, see
# src/obfuscope/features.py) but the raw artifacts remain sensitive.
set -euo pipefail
CORPUS="${1:?usage: stage_corpus.sh /path/to/extracted_corpus}"
USER_NS="${OSDF_USER_NS:-/ospool/ap40/data/${USER}}"
DEST="${USER_NS}/obfuscope"

if [ ! -d "${CORPUS}" ]; then
    echo "error: ${CORPUS} is not a directory" >&2
    exit 1
fi

echo ">> Packing ${CORPUS}"
TMP_TGZ="$(mktemp -t obfuscope_corpus.XXXXXX).tar.gz"
tar czf "${TMP_TGZ}" -C "${CORPUS}" .

echo ">> Staging to ${DEST}/corpus.tar.gz"
mkdir -p "${DEST}"
cp -f "${TMP_TGZ}" "${DEST}/corpus.tar.gz"
rm -f "${TMP_TGZ}"

echo ">> Done. features.sub reads it from:"
echo "   osdf://${DEST}/corpus.tar.gz"
