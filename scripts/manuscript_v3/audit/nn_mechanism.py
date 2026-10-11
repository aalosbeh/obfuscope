"""AUDIT-GENERATED mechanism diagnostic (not an author result).

For configuration B (and A, C), using the script's own split and the same
StandardScaler-on-fit-rows used by _fit_context, record for every evaluation
row whether its nearest fitting row comes from the SAME input program, and the
mean 5-NN distance, for: known evaluation rows, novel_unseen rows, novel_seen
rows. Also report the share of feature variance explained by program identity
versus sub_technique (one-way R^2 per standardised feature, averaged).
"""
import json
import os
import sys

import numpy as np
import pandas as pd
from sklearn.model_selection import GroupShuffleSplit
from sklearn.neighbors import NearestNeighbors
from sklearn.preprocessing import StandardScaler

HERE = os.path.dirname(os.path.abspath(__file__))
# Repository root: three levels above this file (scripts/manuscript_v3/audit/), or $OBFUSCOPE_REPO.
REPO = os.environ.get("OBFUSCOPE_REPO", os.path.abspath(os.path.join(HERE, "..", "..", "..")))
sys.path.insert(0, os.path.join(REPO, "src"))
from obfuscope.config import FEATURE_SETS      # noqa: E402
from obfuscope.features import feature_names   # noqa: E402

df = pd.read_csv(os.path.join(REPO, "data/features_pilot.csv"))
cols = feature_names(FEATURE_SETS["all"])
X = np.nan_to_num(df[cols].to_numpy(dtype=float), nan=0.0, posinf=0.0, neginf=0.0)
groups = df["sample_id"].to_numpy()
out = {"label": "AUDIT-GENERATED"}

# One-way R^2 of each standardised feature on program vs sub_technique vs technique.
Z = StandardScaler().fit_transform(X)
live = Z.std(axis=0) > 0


def r2(col):
    lab = df[col].to_numpy()
    tot = ((Z[:, live] - Z[:, live].mean(0)) ** 2).sum(0)
    between = np.zeros(live.sum())
    for v in np.unique(lab):
        m = lab == v
        between += m.sum() * (Z[m][:, live].mean(0) - Z[:, live].mean(0)) ** 2
    r = between / tot
    return {"mean_r2": float(r.mean()), "median_r2": float(np.median(r)),
            "n_live_features": int(live.sum())}


out["oneway_r2"] = {c: r2(c) for c in ["sample_id", "sub_technique", "technique"]}

for cfg, (label_col, hold_col) in {"A": ("technique", "technique"),
                                   "B": ("sub_technique", "sub_technique"),
                                   "C": ("sub_technique", "technique")}.items():
    hold_on = df[hold_col].to_numpy()
    acc = {"known_eval": [], "novel_unseen": [], "novel_seen": []}
    dist = {"known_eval": [], "novel_unseen": [], "novel_seen": []}
    for seed in range(5):
        for h in sorted(set(hold_on)):
            known = np.where(hold_on != h)[0]
            novel = np.where(hold_on == h)[0]
            a, b = next(GroupShuffleSplit(n_splits=1, test_size=0.2, random_state=seed)
                        .split(known, groups=groups[known]))
            fit_idx, eval_idx = known[a], known[b]
            fp = set(groups[fit_idx])
            nu = novel[~np.isin(groups[novel], list(fp))]
            ns = novel[np.isin(groups[novel], list(fp))]
            sc = StandardScaler().fit(X[fit_idx])
            nn = NearestNeighbors(n_neighbors=5).fit(sc.transform(X[fit_idx]))
            for name, idx in [("known_eval", eval_idx), ("novel_unseen", nu), ("novel_seen", ns)]:
                d, j = nn.kneighbors(sc.transform(X[idx]))
                acc[name].append(float(np.mean(groups[fit_idx][j[:, 0]] == groups[idx])))
                dist[name].append(float(np.mean(d.mean(1))))
    out[cfg] = {"nearest_fit_row_same_program_frac": {k: float(np.mean(v)) for k, v in acc.items()},
                "mean_5nn_distance": {k: float(np.mean(v)) for k, v in dist.items()}}

OUT = sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, "results", "v3", "openset_mechanism", "nn_mechanism.json")
with open(OUT, "w") as fh:
    json.dump(out, fh, indent=1)
print(json.dumps(out, indent=1))
