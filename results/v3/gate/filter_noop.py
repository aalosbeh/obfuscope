import os
"""AUDIT-GENERATED (run:gate-v3). Remove the no-op artifacts listed in
results/v3/gate/noop_artifacts.json (byte identical to their input program)
from data/features_pilot.csv, matching on the feature table's 'path' column,
and write results/v3/gate/features_pilot_no_noop.csv. Row order and columns
are preserved. Also checks the cross-class duplicate clusters of diagnostic 6
on the full table against the removed rows."""
import hashlib, json, os
import pandas as pd
ROOT = os.environ.get("OBFUSCOPE_REPO", os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "..")))
OUT = os.path.join(ROOT, "results/v3/gate")
noop = json.load(open(os.path.join(OUT, "noop_artifacts.json")))
paths = {a["artifact"] for a in noop["artifacts"] if a["byte_identical"]}
df = pd.read_csv(os.path.join(ROOT, "data/features_pilot.csv"))
mask = df["path"].isin(paths)
assert mask.sum() == len(paths) == 32, (mask.sum(), len(paths))
kept = df.loc[~mask]
out_csv = os.path.join(OUT, "features_pilot_no_noop.csv")
kept.to_csv(out_csv, index=False)

# diagnostic 6 clusters on the full table: identical rounded vectors with >1 sub_technique
import sys; sys.path.insert(0, os.path.join(ROOT, "scripts"))
import diversity_gate as gate
feats = gate.feature_columns(df)
keys = gate._vector_keys(df, feats)
g = df.assign(_k=keys).groupby("_k")
clusters = []
for k, sub in g:
    if sub["sub_technique"].nunique() > 1:
        clusters.append({"rows": int(len(sub)),
                         "sub_technique": sorted(sub["sub_technique"].unique().tolist()),
                         "technique": sorted(sub["technique"].unique().tolist()),
                         "sample_id": sorted(sub["sample_id"].unique().tolist()),
                         "all_rows_are_noop": bool(sub["path"].isin(paths).all())})
cc_rows = sum(c["rows"] for c in clusters)
# do the no-op rows equal the untransformed program's feature vector? (all 16 per program identical?)
noop_df = df.loc[mask]
per_prog = {sid: int(gate._vector_keys(s, feats).nunique()) for sid, s in noop_df.groupby("sample_id")}
other_ren = df[(df["technique"] == "renameidentifiers") & (~mask)]
other_ren_cc = {}
for sid in per_prog:
    s = other_ren[other_ren.sample_id == sid]
    other_ren_cc[sid] = int(len(s))
res = {
    "label": "AUDIT-GENERATED no-op filter (run:gate-v3)",
    "source": "data/features_pilot.csv", "rows_in": int(len(df)),
    "rows_removed": int(mask.sum()), "rows_out": int(len(kept)),
    "removed_by": noop_df.groupby(["sample_id", "sub_technique"]).size().rename("n").reset_index().to_dict("records"),
    "output_csv": out_csv,
    "output_sha256": hashlib.sha256(open(out_csv, "rb").read()).hexdigest(),
    "class_counts_after": {"technique": kept["technique"].value_counts().to_dict(),
                           "sub_technique": kept["sub_technique"].value_counts().to_dict()},
    "distinct_vectors_among_noop_rows_per_program": per_prog,
    "diag6_clusters_on_full_table": clusters,
    "diag6_rows_on_full_table": cc_rows,
    "diag6_clusters_all_noop": all(c["all_rows_are_noop"] for c in clusters),
}
json.dump(res, open(os.path.join(OUT, "noop_filter.json"), "w"), indent=2)
print(json.dumps({k: v for k, v in res.items() if k not in ("class_counts_after",)}, indent=1))
