"""AUDIT-GENERATED (run:closedset-v3). Compare re-run seed 0 cells with the committed grid (per fold macro F1 and confusion)."""
import glob, json, os, sys
CLOSED = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ORIG = sys.argv[1]  # obfuscope-main/results
rows = []
for p in sorted(glob.glob(os.path.join(CLOSED, "repro_check", "*.json"))):
    b = os.path.basename(p)
    sub = "pilot5sub" if b.startswith("sub_") else "pilot5"
    a = json.load(open(p)); c = json.load(open(os.path.join(ORIG, sub, b)))
    fa = [f["macro_f1"] for f in a["per_fold"]]; fc = [f["macro_f1"] for f in c["per_fold"]]
    same_conf = all(x["confusion"] == y["confusion"] for x, y in zip(a["per_fold"], c["per_fold"]))
    rows.append({"cell": b, "max_abs_fold_diff": max(abs(x - y) for x, y in zip(fa, fc)),
                 "identical_confusions": same_conf, "rerun_mean": a["macro_f1_mean"],
                 "committed_mean": c["macro_f1_mean"]})
json.dump({"label": "AUDIT-GENERATED run:closedset-v3", "rows": rows},
          open(os.path.join(CLOSED, "repro_check", "_compare.json"), "w"), indent=2)
for r in rows: print(r)
