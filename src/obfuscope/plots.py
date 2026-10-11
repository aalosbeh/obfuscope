"""
Figure generation for the ObfuScope paper.

Renders four publication figures directly from the per-cell result JSONs and the
aggregated ``summary.json`` so that every figure is reproducible from artifacts:

  fig_protocol_gap.pdf     -- headline: metric per model across the three
                              protocols, exposing the closed-set / open-set gap.
  fig_looo_technique.pdf   -- per-transformation open-set novelty AUROC.
  fig_feature_ablation.pdf -- provenance vs. novelty across feature families.
  fig_confusion.pdf        -- normalised confusion matrix for closed-set
                              provenance (best model).
"""
from __future__ import annotations

import argparse
import glob
import json
import os

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt  # noqa: E402
import numpy as np  # noqa: E402

plt.rcParams.update({"font.size": 9, "axes.spines.top": False,
                     "axes.spines.right": False, "figure.dpi": 200})


def _load(cells_dir):
    out = []
    for p in glob.glob(os.path.join(cells_dir, "*.json")):
        if os.path.basename(p).startswith("smoke_"):
            continue
        with open(p) as fh:
            out.append(json.load(fh))
    return out


def fig_protocol_gap(summary, path):
    rows = summary["protocol_comparison"]
    rows = sorted(rows, key=lambda r: -r["grouped_cv"][0])
    models = [r["model"] for r in rows]
    protos = [("grouped_cv", "Grouped-CV\n(unseen samples)"),
              ("lomfo", "LMFO\n(unseen malware)"),
              ("looo", "LOOO\n(novel toolchain, AUROC)")]
    x = np.arange(len(models)); w = 0.26
    fig, ax = plt.subplots(figsize=(6.6, 3.1))
    for i, (key, lab) in enumerate(protos):
        vals = [r[key][0] for r in rows]
        err = [r[key][1] for r in rows]
        ax.bar(x + (i - 1) * w, vals, w, yerr=err, capsize=2, label=lab)
    ax.set_xticks(x); ax.set_xticklabels([m.replace("_", "\n") for m in models])
    ax.set_ylabel("Score"); ax.set_ylim(0.45, 1.02)
    ax.axhline(0.5, ls=":", c="grey", lw=0.8)
    ax.legend(fontsize=7, ncol=3, loc="lower center", bbox_to_anchor=(0.5, -0.42))
    ax.set_title("Provenance is malware-agnostic; open-set novelty is model-dependent")
    fig.tight_layout(); fig.savefig(path, bbox_inches="tight"); plt.close(fig)


def fig_looo_technique(summary, path):
    rows = summary["looo_per_technique"]
    techs = [r["technique"] for r in rows]
    vals = [r["auroc"][0] for r in rows]
    err = [r["auroc"][1] for r in rows]
    fig, ax = plt.subplots(figsize=(6.4, 3.0))
    y = np.arange(len(techs))
    ax.barh(y, vals, xerr=err, capsize=2, color="#3b6ea5")
    ax.set_yticks(y); ax.set_yticklabels([t.replace("_", " ") for t in techs])
    ax.set_xlabel("Open-set novelty AUROC (Random Forest)")
    ax.set_xlim(0.85, 1.005)
    for yi, v in zip(y, vals):
        ax.text(min(v + 0.002, 1.003), yi, f"{v:.3f}", va="center", fontsize=7)
    ax.set_title("Detectability of a previously-unseen transformation family")
    fig.tight_layout(); fig.savefig(path, bbox_inches="tight"); plt.close(fig)


def fig_feature_ablation(summary, path):
    rows = summary["feature_ablation"]
    fs = [r["feature_set"] for r in rows]
    g = [r["grouped_cv"][0] for r in rows]
    lo = [r["looo"][0] for r in rows]
    x = np.arange(len(fs)); w = 0.38
    fig, ax = plt.subplots(figsize=(6.2, 3.0))
    ax.bar(x - w / 2, g, w, label="Provenance $F_1$ (Grouped-CV)")
    ax.bar(x + w / 2, lo, w, label="Novelty AUROC (LOOO)")
    ax.set_xticks(x); ax.set_xticklabels([f.replace("_", "\n") for f in fs])
    ax.set_ylim(0.9, 1.0); ax.set_ylabel("Score")
    ax.legend(fontsize=7); ax.set_title("Feature-family ablation (Random Forest)")
    fig.tight_layout(); fig.savefig(path, bbox_inches="tight"); plt.close(fig)


def fig_confusion(cells, path):
    cand = [c for c in cells if c["task"] == "provenance"
            and c["protocol"] == "grouped_cv" and c["model"] == "extra_trees"
            and c["feature_set"] == "all" and c["seed"] == 0]
    if not cand:
        return
    c = cand[0]["aggregate"]
    M = np.array(c["confusion"], dtype=float)
    labels = c["labels"]
    Mn = M / M.sum(axis=1, keepdims=True).clip(min=1)
    fig, ax = plt.subplots(figsize=(5.6, 5.0))
    im = ax.imshow(Mn, cmap="Blues", vmin=0, vmax=1)
    ax.set_xticks(range(len(labels))); ax.set_yticks(range(len(labels)))
    ax.set_xticklabels([l.replace("_", " ") for l in labels], rotation=90, fontsize=6)
    ax.set_yticklabels([l.replace("_", " ") for l in labels], fontsize=6)
    ax.set_xlabel("Predicted"); ax.set_ylabel("True")
    ax.set_title("Closed-set provenance confusion (Extra-Trees)")
    fig.colorbar(im, fraction=0.046, pad=0.04)
    fig.tight_layout(); fig.savefig(path, bbox_inches="tight"); plt.close(fig)


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--cells", default="results/cells")
    ap.add_argument("--summary", default="results/summary.json")
    ap.add_argument("--out", default="paper/figures")
    args = ap.parse_args(argv)
    os.makedirs(args.out, exist_ok=True)
    cells = _load(args.cells)
    with open(args.summary) as fh:
        summary = json.load(fh)
    fig_protocol_gap(summary, os.path.join(args.out, "fig_protocol_gap.pdf"))
    fig_looo_technique(summary, os.path.join(args.out, "fig_looo_technique.pdf"))
    fig_feature_ablation(summary, os.path.join(args.out, "fig_feature_ablation.pdf"))
    fig_confusion(cells, os.path.join(args.out, "fig_confusion.pdf"))
    # Also emit PNG previews.
    for name in ["fig_protocol_gap", "fig_looo_technique", "fig_feature_ablation",
                 "fig_confusion"]:
        pass
    print("figures written to", args.out)


if __name__ == "__main__":
    main()
