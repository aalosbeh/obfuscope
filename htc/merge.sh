#!/usr/bin/env bash
# Concatenate shard CSVs into a single feature table with one header, then stage
# it to the OSDF for the experiment grid to consume.
set -euo pipefail
tar xzf obfuscope_src.tar.gz
export PYTHONPATH="${PWD}/src:${PYTHONPATH:-}"
python3 - <<'PY'
import glob, csv, os
from obfuscope.build_dataset import _LABEL_COLS
from obfuscope.features import feature_names
header = _LABEL_COLS + feature_names()
shards = sorted(glob.glob("shards/features_shard_*.csv"))
with open("features.csv","w",newline="") as out:
    w=csv.writer(out); w.writerow(header)
    for s in shards:
        with open(s) as fh:
            for line in fh:
                out.write(line)
print("merged", len(shards), "shards ->", sum(1 for _ in open("features.csv"))-1, "rows")
PY
