"""AUDIT-GENERATED (run:closedset-v3). Identify no-op artifacts and write a filtered feature table.

An artifact is a no-op when its bytes are identical to the unmodified input
program it was derived from (corpus_inputs/<suite>/<name>.c). Also reports the
duplicate feature-vector clusters before and after removal.

Usage (from the repository root):
  python results/v3/closed/scripts/noop_identify.py \
      --features data/features_pilot.csv --corpus data/pilot_corpus \
      --inputs corpus_inputs --out-dir results/v3/closed/noop
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
from collections import Counter

import pandas as pd


def sha(path: str) -> str:
    with open(path, "rb") as fh:
        return hashlib.sha256(fh.read()).hexdigest()


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--features", required=True)
    ap.add_argument("--corpus", required=True)
    ap.add_argument("--inputs", required=True)
    ap.add_argument("--out-dir", required=True)
    a = ap.parse_args()

    # programs.tsv: path<TAB>suite<TAB>functions; sample_id = <suite>_<stem>
    prog_path = {}
    with open(os.path.join(a.inputs, "programs.tsv")) as fh:
        for line in fh:
            if not line.strip() or line.startswith("#"):
                continue
            rel, suite = line.split("\t")[:2]
            stem = os.path.splitext(os.path.basename(rel))[0]
            prog_path[f"{suite}_{stem}"] = os.path.join(a.inputs, rel)

    df = pd.read_csv(a.features)
    input_hash = {sid: sha(p) for sid, p in prog_path.items()}
    missing = sorted(set(df.sample_id) - set(input_hash))
    is_noop = []
    for _, r in df.iterrows():
        art = os.path.join(a.corpus, r["path"])
        is_noop.append(sha(art) == input_hash[r["sample_id"]])
    df["_noop"] = is_noop
    noop = df[df._noop]

    feat_cols = [c for c in df.columns if c not in
                 ("path", "cohort", "sample_id", "technique", "sub_technique",
                  "malware_family", "_noop")]

    def dup_clusters(d: pd.DataFrame):
        key = d[feat_cols].round(12).astype(str).agg("|".join, axis=1)
        counts = key.value_counts()
        dups = counts[counts > 1]
        out = []
        for k, n in dups.items():
            rows = d[key == k]
            out.append({"size": int(n),
                        "sub_techniques": dict(Counter(rows.sub_technique)),
                        "sample_ids": sorted(set(rows.sample_id))})
        return {"n_rows": int(len(d)), "n_distinct_vectors": int(key.nunique()),
                "n_duplicate_clusters": int(len(dups)),
                "rows_in_duplicate_clusters": int(dups.sum()) if len(dups) else 0,
                "clusters": out}

    filtered = df[~df._noop].drop(columns=["_noop"])
    os.makedirs(a.out_dir, exist_ok=True)
    out_csv = os.path.join(a.out_dir, "features_pilot_no_noop.csv")
    filtered.to_csv(out_csv, index=False)

    report = {
        "label": "AUDIT-GENERATED run:closedset-v3",
        "definition": "artifact SHA-256 equals SHA-256 of its unmodified input program",
        "features": a.features, "n_rows_in": int(len(df)),
        "sample_ids_without_input": missing,
        "n_noop": int(len(noop)),
        "noop_by_sub_technique": dict(Counter(noop.sub_technique)),
        "noop_by_sample_id": dict(Counter(noop.sample_id)),
        "noop_by_technique": dict(Counter(noop.technique)),
        "noop_by_domain": dict(Counter(noop.malware_family)),
        "noop_paths": sorted(noop.path.tolist()),
        "duplicates_full_table": dup_clusters(df.drop(columns=["_noop"])),
        "duplicates_after_removal": dup_clusters(filtered),
        "n_rows_out": int(len(filtered)),
        "filtered_csv": out_csv,
        "filtered_csv_sha256": sha(out_csv),
        "class_counts_after_removal": {
            "technique": dict(Counter(filtered.technique)),
            "sub_technique": dict(Counter(filtered.sub_technique)),
            "domain": dict(Counter(filtered.malware_family)),
        },
    }
    with open(os.path.join(a.out_dir, "noop_rows.json"), "w") as fh:
        json.dump(report, fh, indent=2)
    print(json.dumps({k: v for k, v in report.items() if k != "noop_paths"
                      and not k.startswith("duplicates")}, indent=1))
    for k in ("duplicates_full_table", "duplicates_after_removal"):
        d = report[k]
        print(k, d["n_rows"], d["n_distinct_vectors"], d["n_duplicate_clusters"],
              d["rows_in_duplicate_clusters"], [c["sub_techniques"] for c in d["clusters"]])


if __name__ == "__main__":
    main()
