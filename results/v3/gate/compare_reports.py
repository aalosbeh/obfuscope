import os
"""AUDIT-GENERATED (run:gate-v3). Leaf-by-leaf comparison of regenerated gate
reports with the committed ones, on the committed (pre-existing) keys only."""
import json, sys, os
ROOT = os.environ.get("OBFUSCOPE_REPO", os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "..")))
PAIRS = [("results/gate_v2_technique.json", "results/v3/gate/gate_supplied_technique.json"),
         ("results/gate_v2_subtechnique.json", "results/v3/gate/gate_supplied_subtechnique.json"),
         ("results/gate_original_technique.json", "results/v3/gate/gate_supplied_v1.json"),
         ("results/gate_v2_technique.json", "results/v3/gate/gate_repeats_supplied_technique.json"),
         ("results/gate_v2_subtechnique.json", "results/v3/gate/gate_repeats_supplied_subtechnique.json")]

def leaves(o, p=""):
    if isinstance(o, dict):
        for k, v in o.items():
            yield from leaves(v, f"{p}/{k}")
    elif isinstance(o, list):
        for i, v in enumerate(o):
            yield from leaves(v, f"{p}[{i}]")
    else:
        yield p, o

def new_keys(a, b, p=""):
    out = []
    if isinstance(a, dict) and isinstance(b, dict):
        for k in b:
            if k not in a:
                out.append(f"{p}/{k}")
            else:
                out += new_keys(a[k], b[k], f"{p}/{k}")
    elif isinstance(a, list) and isinstance(b, list):
        for i, (x, y) in enumerate(zip(a, b)):
            out += new_keys(x, y, f"{p}[{i}]")
    return out

res = {}
for old, new in PAIRS:
    a = json.load(open(os.path.join(ROOT, old))); b = json.load(open(os.path.join(ROOT, new)))
    la = dict(leaves(a)); lb = dict(leaves(b))
    diffs = [{"path": k, "committed": la[k], "regenerated": lb.get(k, "<missing>")}
             for k in la if lb.get(k, "<missing>") != la[k]]
    res[os.path.basename(new)] = {"committed": old, "committed_leaves": len(la),
        "differences": diffs, "n_differences": len(diffs),
        "new_keys": new_keys(a, b)}
    print(new, "leaves", len(la), "diffs", len(diffs), "new keys", new_keys(a, b))
json.dump(res, open(os.path.join(ROOT, "results/v3/gate/compare_supplied_vs_committed.json"), "w"), indent=2)
