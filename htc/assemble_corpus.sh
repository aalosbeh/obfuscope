#!/usr/bin/env bash
# DAGMan POST script for the CORPUS node.
#
# Merges the per-shard tarballs into one corpus tree, stages it to the OSDF at
# the path features.sub reads, and prints the generation yield from the merged
# manifests.
#
# Why the yield matters enough to print here: Tigress does not succeed on every
# program, and the failures are not spread evenly across transformations.
# Virtualize fails or times out on large functions far more often than Split
# does. If one class only survives on small inputs, program size becomes a
# proxy for the class label and the attribution result is confounded by
# selection rather than driven by transformation signatures. The spread is
# reported at the point where it can still be corrected, by widening the input
# set or scoping the transformation with --Functions.
set -euo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
SHARDS="${HERE}/data/corpus_shards"
USER_NS="${OSDF_USER_NS:-/ospool/ap40/data/${USER}}"
DEST="${USER_NS}/obfuscope"

if [ ! -d "${SHARDS}" ]; then
    echo "error: ${SHARDS} does not exist; did the CORPUS stage run?" >&2
    exit 1
fi

TARS=$(find "${SHARDS}" -name 'corpus_shard_*.tar.gz' | wc -l | tr -d ' ')
if [ "${TARS}" -eq 0 ]; then
    echo "error: no shard tarballs in ${SHARDS}" >&2
    exit 1
fi
echo ">> merging ${TARS} shard tarballs"

WORK="$(mktemp -d -t obfuscope_corpus.XXXXXX)"
trap 'rm -rf "${WORK}"' EXIT
mkdir -p "${WORK}/corpus"

for t in "${SHARDS}"/corpus_shard_*.tar.gz; do
    tar xzf "${t}" -C "${WORK}/corpus"
done

N_C=$(find "${WORK}/corpus" -name '*.c' | wc -l | tr -d ' ')
echo ">> merged corpus holds ${N_C} artifacts"
if [ "${N_C}" -eq 0 ]; then
    echo "error: merged corpus is empty; check logs/corpus_*.err" >&2
    exit 1
fi

echo ">> artifacts per transformation"
find "${WORK}/corpus" -name '*.c' \
    | sed -E 's#.*/([^/]+_variants)/.*#\1#' \
    | sort | uniq -c | sort -rn

cat "${SHARDS}"/corpus_manifest_*.jsonl > "${HERE}/data/corpus_manifest.jsonl" 2>/dev/null || true
if [ -s "${HERE}/data/corpus_manifest.jsonl" ]; then
    echo ">> generation yield per transformation"
    python3 - "${HERE}/data/corpus_manifest.jsonl" <<'PY'
import json, sys
from collections import defaultdict
tot = defaultdict(int); ok = defaultdict(int)
with open(sys.argv[1]) as fh:
    for line in fh:
        line = line.strip()
        if not line:
            continue
        r = json.loads(line)
        tot[r["transform"]] += 1
        ok[r["transform"]] += 1 if r.get("ok") else 0
rates = {}
for t in sorted(tot):
    rate = ok[t] / tot[t]
    rates[t] = rate
    print(f"   {t:20s} {ok[t]:6d}/{tot[t]:<6d} {rate:6.1%}")
if rates:
    spread = max(rates.values()) - min(rates.values())
    print(f"   yield spread {spread:.1%}")
    if spread > 0.20:
        print("   WARNING: yield differs by more than 20 points across "
              "transformations. Differential dropout is a selection bias: the "
              "surviving inputs are not the same set for every class, so input "
              "properties partly encode the label. Widen the program set or "
              "scope the failing transformations before trusting the result.")
PY
fi

echo ">> staging to ${DEST}/corpus.tar.gz"
mkdir -p "${DEST}"
tar czf "${DEST}/corpus.tar.gz" -C "${WORK}/corpus" .
echo ">> done. features.sub reads osdf://${DEST}/corpus.tar.gz"
