"""
Aggregate per-cell result JSONs into tables, a summary, and LaTeX snippets.

Reads every ``*.json`` produced by :mod:`obfuscope.experiment`, collapses seed
replicates into mean +/- standard deviation, and emits: CSV tables, ready-to-
\\input LaTeX tables, and a machine-readable ``summary.json`` that the paper and
the verification step both consume. Producing every reported number from this
single script guarantees the manuscript never drifts from the artifacts.
"""
from __future__ import annotations

import argparse
import csv
import glob
import json
import os
from collections import defaultdict
from statistics import mean, pstdev
from typing import Dict, List


def _load_cells(cells_dir: str) -> List[Dict]:
    out = []
    for p in glob.glob(os.path.join(cells_dir, "*.json")):
        if os.path.basename(p).startswith("smoke_"):
            continue
        try:
            with open(p) as fh:
                out.append(json.load(fh))
        except Exception:  # noqa: BLE001
            continue
    return out


def _ms(vals):
    vals = [v for v in vals if v is not None]
    if not vals:
        return (float("nan"), 0.0)
    return (mean(vals), pstdev(vals) if len(vals) > 1 else 0.0)


def _headline(cell: Dict) -> float:
    if cell["protocol"] == "looo":
        return cell.get("auroc_mean")
    return cell.get("macro_f1_mean")


def build_tables(cells_dir: str, out_dir: str) -> Dict:
    cells = _load_cells(cells_dir)
    os.makedirs(out_dir, exist_ok=True)
    tabdir = os.path.join(out_dir, "tables")
    os.makedirs(tabdir, exist_ok=True)
    summary: Dict = {"n_cells": len(cells)}

    def group(pred):
        g = defaultdict(list)
        for c in cells:
            if pred(c):
                g[c["model"]].append(c)
        return g

    # ---- Table 1: model comparison, closed-set provenance (grouped_cv, all) ----
    rows = []
    g = group(lambda c: c["task"] == "provenance" and c["protocol"] == "grouped_cv"
              and c["feature_set"] == "all")
    for model, cs in sorted(g.items()):
        acc = _ms([c["aggregate"]["accuracy"] for c in cs])
        bacc = _ms([c["aggregate"]["balanced_accuracy"] for c in cs])
        mf1 = _ms([c["macro_f1_mean"] for c in cs])
        rows.append({"model": model, "accuracy": acc, "balanced_accuracy": bacc,
                     "macro_f1": mf1, "n_seeds": len(cs)})
    _write_csv(os.path.join(tabdir, "model_comparison.csv"),
               ["model", "accuracy", "balanced_accuracy", "macro_f1", "n_seeds"], rows)
    summary["model_comparison"] = _jsonify(rows)

    # ---- Table 2: protocol comparison per model (feature_set=all) ----
    prow = []
    models = sorted({c["model"] for c in cells
                     if c["task"] == "provenance" and c["feature_set"] == "all"})
    for model in models:
        rec = {"model": model}
        have_all = True
        for proto in ["grouped_cv", "lomfo", "looo"]:
            cs = [c for c in cells if c["task"] == "provenance"
                  and c["feature_set"] == "all" and c["protocol"] == proto
                  and c["model"] == model]
            if not cs:
                have_all = False
            rec[proto] = _ms([_headline(c) for c in cs]) if cs else (float("nan"), 0.0)
        # Only models evaluated under all three protocols enter the comparison
        # (the kernel SVM is a single-cell closed-set reference point).
        if have_all:
            prow.append(rec)
    _write_csv(os.path.join(tabdir, "protocol_comparison.csv"),
               ["model", "grouped_cv", "lomfo", "looo"], prow)
    summary["protocol_comparison"] = _jsonify(prow)

    # ---- Table 3: feature-family ablation (random_forest) ----
    arow = []
    fsets = ["all", "no_obfuscation", "structural", "semantic", "lexical_only"]
    for fs in fsets:
        rec = {"feature_set": fs}
        for proto in ["grouped_cv", "looo"]:
            cs = [c for c in cells if c["task"] == "provenance"
                  and c["model"] == "random_forest" and c["feature_set"] == fs
                  and c["protocol"] == proto]
            rec[proto] = _ms([_headline(c) for c in cs]) if cs else (float("nan"), 0.0)
        arow.append(rec)
    _write_csv(os.path.join(tabdir, "feature_ablation.csv"),
               ["feature_set", "grouped_cv", "looo"], arow)
    summary["feature_ablation"] = _jsonify(arow)

    # ---- Table 4: LOOO per-technique novelty (random_forest, all) ----
    per_tech = defaultdict(list)
    for c in cells:
        if (c["task"] == "provenance" and c["protocol"] == "looo"
                and c["model"] == "random_forest" and c["feature_set"] == "all"):
            for r in c["per_technique"]:
                per_tech[r["novel_technique"]].append(r["auroc"])
    trow = [{"technique": t, "auroc": _ms(v), "n_seeds": len(v)}
            for t, v in sorted(per_tech.items(), key=lambda kv: mean(kv[1]))]
    _write_csv(os.path.join(tabdir, "looo_per_technique.csv"),
               ["technique", "auroc", "n_seeds"], trow)
    summary["looo_per_technique"] = _jsonify(trow)

    # ---- Sub-transformation provenance (fine grained) ----
    sub = [c for c in cells if c["task"] == "sub_provenance"
           and c["protocol"] == "grouped_cv"]
    subrow = []
    for model in sorted({c["model"] for c in sub}):
        cs = [c for c in sub if c["model"] == model]
        subrow.append({"model": model,
                       "accuracy": _ms([c["aggregate"]["accuracy"] for c in cs]),
                       "macro_f1": _ms([c["macro_f1_mean"] for c in cs]),
                       "n_classes": cs[0]["aggregate"]["labels"].__len__() if cs else 0})
    _write_csv(os.path.join(tabdir, "sub_provenance.csv"),
               ["model", "accuracy", "macro_f1", "n_classes"], subrow)
    summary["sub_provenance"] = _jsonify(subrow)

    # ---- Headline numbers ----
    best_gcv = max(summary["model_comparison"], key=lambda r: r["macro_f1"][0])
    summary["headline"] = {
        "best_provenance_model": best_gcv["model"],
        "best_provenance_macro_f1": best_gcv["macro_f1"],
        "best_provenance_accuracy": best_gcv["accuracy"],
        "looo_mean_auroc_rf": _ms([a for v in per_tech.values() for a in v]),
        "hardest_novel_technique": trow[0]["technique"] if trow else None,
        "hardest_novel_auroc": trow[0]["auroc"] if trow else None,
    }
    with open(os.path.join(out_dir, "summary.json"), "w") as fh:
        json.dump(summary, fh, indent=2)
    _write_latex(summary, os.path.join(out_dir, "tables"))
    return summary


def _jsonify(rows):
    return json.loads(json.dumps(rows))


def _fmt(cell):
    if isinstance(cell, (list, tuple)) and len(cell) == 2:
        m, s = cell
        return f"{m:.3f}±{s:.3f}"
    return str(cell)


def _write_csv(path, cols, rows):
    with open(path, "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(cols)
        for r in rows:
            w.writerow([_fmt(r.get(c)) for c in cols])


def _lx(cell, pct=False):
    if isinstance(cell, (list, tuple)) and len(cell) == 2:
        m, s = cell
        if pct:
            return f"{100*m:.1f}\\,$\\pm$\\,{100*s:.1f}"
        return f"{m:.3f}\\,$\\pm$\\,{s:.3f}"
    return str(cell)


def _esc(s):
    return str(s).replace("_", r"\_")


def _write_latex(summary, tabdir):
    EOL = r" \\"
    # Table 1
    lines = [r"% auto-generated by obfuscope.aggregate",
             r"\begin{tabular}{lccc}", r"\toprule",
             r"Model & Accuracy & Balanced Acc. & Macro-$F_1$ \\", r"\midrule"]
    for r in sorted(summary["model_comparison"], key=lambda x: -x["macro_f1"][0]):
        name = _esc(r["model"])
        lines.append(f"\\texttt{{{name}}} & {_lx(r['accuracy'])} & "
                     f"{_lx(r['balanced_accuracy'])} & {_lx(r['macro_f1'])}" + EOL)
    lines += [r"\bottomrule", r"\end{tabular}"]
    open(os.path.join(tabdir, "tab_model_comparison.tex"), "w").write("\n".join(lines))

    # Table 2 protocol
    lines = [r"\begin{tabular}{lccc}", r"\toprule",
             r"Model & Grouped-CV ($F_1$) & LMFO ($F_1$) & LOOO (AUROC) \\",
             r"\midrule"]
    for r in sorted(summary["protocol_comparison"], key=lambda x: -x["grouped_cv"][0]):
        name = _esc(r["model"])
        lines.append(f"\\texttt{{{name}}} & {_lx(r['grouped_cv'])} & "
                     f"{_lx(r['lomfo'])} & {_lx(r['looo'])}" + EOL)
    lines += [r"\bottomrule", r"\end{tabular}"]
    open(os.path.join(tabdir, "tab_protocol.tex"), "w").write("\n".join(lines))

    # Table 3 ablation
    lines = [r"\begin{tabular}{lcc}", r"\toprule",
             r"Feature set & Provenance $F_1$ & Novelty AUROC \\", r"\midrule"]
    for r in summary["feature_ablation"]:
        name = _esc(r["feature_set"])
        lines.append(f"\\texttt{{{name}}} & {_lx(r['grouped_cv'])} & "
                     f"{_lx(r['looo'])}" + EOL)
    lines += [r"\bottomrule", r"\end{tabular}"]
    open(os.path.join(tabdir, "tab_ablation.tex"), "w").write("\n".join(lines))

    # Table 4 per technique
    lines = [r"\begin{tabular}{lc}", r"\toprule",
             r"Held-out (novel) transformation & Novelty AUROC \\", r"\midrule"]
    for r in summary["looo_per_technique"]:
        name = _esc(r["technique"])
        lines.append(f"\\texttt{{{name}}} & {_lx(r['auroc'])}" + EOL)
    lines += [r"\bottomrule", r"\end{tabular}"]
    open(os.path.join(tabdir, "tab_looo_technique.tex"), "w").write("\n".join(lines))


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--cells", default="results/cells")
    ap.add_argument("--out", default="results")
    args = ap.parse_args(argv)
    s = build_tables(args.cells, args.out)
    h = s["headline"]
    print(json.dumps(h, indent=2))


if __name__ == "__main__":
    main()
