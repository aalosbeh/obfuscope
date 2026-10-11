#!/usr/bin/env python3
"""Article figures for the revised ObfuScope manuscript (ACM TOPS, acmsmall).

Every plotted value is read from a result file under ``results/`` or
``results/v3/`` of this repository; nothing is typed in and nothing is read
from the manuscript.  Each value handed to matplotlib (or written into the TikZ
source of Figure 1) is recorded in ``figures_provenance.json`` with the file it
came from (path relative to the repository root, plus its SHA-256) and a JSON
path or CSV row/column.  Means that are recomputed from per-fold records are
cross-checked against the summary written by the analysis code, and the script
stops if they disagree.

Outputs (default directory ``../../latex/figures`` relative to the repository,
i.e. ``submission_package/latex/figures``):

    fig1-pipeline.tex          TikZ source, \\input inside a figure environment
    fig1-pipeline.pdf          the same picture compiled standalone (tectonic)
    fig2-gate-specificity.{pdf,png}
    fig3-openset.{pdf,png}
    fig4-sibling-axis.{pdf,png}
    fig5-simulation.{pdf,png}
    fig6-closed-set.{pdf,png}
    figures_provenance.json    every plotted value with source file and path
    MANIFEST.txt               sizes, minimum font sizes, sources, conventions

Print conventions: width 5.47 in (acmsmall \\textwidth is 395.82 pt =
5.477 in), saved with constrained layout and without bbox_inches='tight' so
the page width is exact; every text >= 7 pt at final size; TrueType (Type 42)
fonts embedded; no titles inside figures (captions carry them); estimator
order and colours fixed across figures (Okabe-Ito hues, validated for
colour-vision deficiency, each estimator also carries a marker shape or a
direct label so the figures survive greyscale printing).

Usage (Python 3.9.6 environment of record, matplotlib 3.9.4):

    python scripts/manuscript_v3/make_figures.py [--out DIR] [--no-tectonic]
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import io
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path
from typing import Dict, List, Optional, Sequence, Tuple

import numpy as np
import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt  # noqa: E402
from matplotlib import font_manager  # noqa: E402
from matplotlib.lines import Line2D  # noqa: E402
from matplotlib.patches import Rectangle  # noqa: E402
from matplotlib.text import Text  # noqa: E402

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]                      # obfuscope-corrected
RES = ROOT / "results"
DEFAULT_OUT = ROOT.parents[1] / "latex" / "figures"

# ----------------------------------------------------------------- page geometry
# Defaults are the ACM acmsmall geometry. For other templates set, e.g. for the
# Springer Nature sn-jnl text width (372 pt = 5.15 in) and 8 pt lettering:
#   OBF_FIG_WIDTH=5.15 OBF_FIG_MIN_PT=8 python scripts/manuscript_v3/make_figures.py --out DIR
FULL_W = float(os.environ.get("OBF_FIG_WIDTH", "5.47"))   # in; acmsmall text width (395.82 pt = 5.477 in)
HALF_W = 2.65          # in
MIN_PT = float(os.environ.get("OBF_FIG_MIN_PT", "7.0"))   # smallest permitted text size at final print size
FS = MIN_PT            # tick labels, legends, annotations
FS_LABEL = MIN_PT + 0.5  # axis labels
FS_PANEL = MIN_PT + 1.0  # panel letters

INK = "#222222"
INK2 = "#555555"       # secondary text, 7.5:1 on white
GRID = "#E4E4E4"
REF = "#7F7F7F"        # reference lines (chance)
ACCENT = "#D55E00"     # verdict that disagrees with the known status (Fig. 2)

# Estimator order and colours: fixed for every figure.  Okabe-Ito hues except
# mlp (wine), because black fails the categorical lightness/chroma checks of the
# dataviz validator.  validate_palette.js (light): lightness, chroma, adjacent
# CVD (worst dE 11.0) and normal-vision (worst dE 15.6) all PASS; contrast WARN
# for the three light hues is relieved by direct labels on every axis.
EST_ORDER = ["random_forest", "extra_trees", "hist_gbdt", "logreg",
             "svm_rbf", "knn", "mlp"]
EST_COLOR = {
    "random_forest": "#0072B2", "extra_trees": "#56B4E9",
    "hist_gbdt": "#009E73", "logreg": "#D55E00", "svm_rbf": "#E69F00",
    "knn": "#CC79A7", "mlp": "#882255",
}
EST_MARKER = {
    "random_forest": "o", "extra_trees": "s", "hist_gbdt": "D",
    "logreg": "^", "svm_rbf": "v", "knn": "P", "mlp": "X",
}
OPEN_EST = [m for m in EST_ORDER if m != "hist_gbdt"]
# display labels: the abbreviations of the article's tables (Table 8 and Table 7)
LABEL = {"random_forest": "RF", "extra_trees": "ET", "hist_gbdt": "HGB", "logreg": "LR",
         "svm_rbf": "SVM", "knn": "kNN", "mlp": "MLP",
         "knn_dist": "kNN dist.", "mahalanobis": "Mahalanobis", "iforest": "iForest"}
MODEL_FREE_COLOR = "#4D4D4D"

# Simulation hold-out conditions (validated all-pairs: CVD dE 11.0, normal
# 25.8, contrast >= 3:1).  Fitted random forest keeps the estimator colour.
SIM_COLOR = {"edge": "#D55E00", "interior": "#009E73", "family": "#5D3A9B"}
SIM_MARKER = {"edge": "o", "interior": "s", "family": "^"}
BAYES_COLOR = "#000000"

JITTER_SEED = 20261010  # horizontal jitter of strip points only (not data)

SOURCES: Dict[str, str] = {}
_CACHE: Dict[str, object] = {}


# ------------------------------------------------------------------ provenance
class Provenance:
    def __init__(self) -> None:
        self.figs: Dict[str, Dict] = {}

    def add(self, fig: str, panel: str, series: str, key, value, source: str,
            path: str, derivation: Optional[str] = None) -> None:
        rec = {"panel": panel, "series": series, "key": key,
               "value": value, "source": source, "path": path}
        if derivation:
            rec["derivation"] = derivation
        self.figs.setdefault(fig, {"values": []})["values"].append(rec)

    def meta(self, fig: str, **kw) -> None:
        self.figs.setdefault(fig, {"values": []}).update(kw)


PROV = Provenance()


def _check_inside_results(p: Path) -> None:
    rp = p.resolve()
    if not str(rp).startswith(str(RES.resolve()) + os.sep):
        raise SystemExit(f"refusing to read outside results/: {p}")


def load_json(rel: str):
    if rel not in _CACHE:
        p = ROOT / rel
        _check_inside_results(p)
        raw = p.read_bytes()
        SOURCES[rel] = hashlib.sha256(raw).hexdigest()
        _CACHE[rel] = json.loads(raw)
    return _CACHE[rel]


def load_csv(rel: str) -> List[Dict[str, str]]:
    if rel not in _CACHE:
        p = ROOT / rel
        _check_inside_results(p)
        raw = p.read_bytes()
        SOURCES[rel] = hashlib.sha256(raw).hexdigest()
        _CACHE[rel] = list(csv.DictReader(io.StringIO(raw.decode("utf-8"))))
    return _CACHE[rel]


def csv_row(rel: str, **match) -> Tuple[int, Dict[str, str]]:
    rows = load_csv(rel)
    hits = [(i, r) for i, r in enumerate(rows)
            if all(r[k] == v for k, v in match.items())]
    if len(hits) != 1:
        raise SystemExit(f"{rel}: {len(hits)} rows match {match}")
    return hits[0]


def close(a: float, b: float, tol: float, what: str) -> None:
    if not (abs(a - b) <= tol):
        raise SystemExit(f"cross-check failed for {what}: {a!r} vs {b!r} (tol {tol})")


# --------------------------------------------------------------------- styling
def pick_font() -> str:
    names = {f.name for f in font_manager.fontManager.ttflist}
    for cand in ("Arial", "Liberation Sans", "DejaVu Sans"):
        if cand in names:
            return cand
    return "DejaVu Sans"


FONT = pick_font()
plt.rcParams.update({
    "font.family": FONT,
    "font.size": FS,
    "axes.labelsize": FS_LABEL,
    "axes.titlesize": FS_LABEL,
    "xtick.labelsize": FS,
    "ytick.labelsize": FS,
    "legend.fontsize": FS,
    "legend.title_fontsize": FS,
    "legend.frameon": False,
    "legend.handletextpad": 0.4,
    "legend.columnspacing": 1.2,
    "legend.borderaxespad": 0.2,
    "text.color": INK,
    "axes.labelcolor": INK,
    "axes.edgecolor": INK,
    "xtick.color": INK,
    "ytick.color": INK,
    "axes.linewidth": 0.6,
    "xtick.major.width": 0.6,
    "ytick.major.width": 0.6,
    "xtick.minor.width": 0.4,
    "ytick.minor.width": 0.4,
    "xtick.major.size": 2.5,
    "ytick.major.size": 2.5,
    "xtick.major.pad": 2.0,
    "ytick.major.pad": 2.0,
    "axes.labelpad": 2.5,
    "axes.spines.top": False,
    "axes.spines.right": False,
    "lines.linewidth": 1.2,
    "lines.markeredgewidth": 0.8,
    "pdf.fonttype": 42,
    "ps.fonttype": 42,
    "svg.fonttype": "none",
    "savefig.dpi": 300,
    "figure.dpi": 100,
    "figure.facecolor": "white",
    "axes.facecolor": "white",
    "figure.constrained_layout.h_pad": 0.02,
    "figure.constrained_layout.w_pad": 0.02,
    "figure.constrained_layout.hspace": 0.04,
    "figure.constrained_layout.wspace": 0.04,
})


def panel_letter(ax, letter: str, x: float = -0.0, y: float = 1.0, dx_pt: float = -8.0,
                 dy_pt: float = 5.0) -> None:
    """Panel letter just above the top-left corner of the axes (offset in points,
    so it clears the top y tick label)."""
    ax.annotate(f"({letter})", xy=(x, y), xycoords="axes fraction", xytext=(dx_pt, dy_pt),
                textcoords="offset points", fontsize=FS_PANEL, fontweight="bold",
                ha="right", va="bottom")


def hgrid(ax) -> None:
    ax.grid(axis="y", color=GRID, linewidth=0.5)
    ax.set_axisbelow(True)


def vgrid(ax) -> None:
    ax.grid(axis="x", color=GRID, linewidth=0.5)
    ax.set_axisbelow(True)


# ------------------------------------------------------------- quality checks
def visible_texts(fig) -> List[Text]:
    out = []
    for t in fig.findobj(Text):
        if not t.get_visible() or not t.get_text().strip():
            continue
        # skip texts whose ancestors are hidden (e.g. hidden axes)
        a = getattr(t, "axes", None)
        if a is not None and not a.get_visible():
            continue
        out.append(t)
    return out


def check_figure(fig, name: str, target_w: float) -> Dict:
    """Font-size, width, overlap and clipping checks before saving."""
    w, h = fig.get_size_inches()
    if abs(w - target_w) > 1e-9:
        raise SystemExit(f"{name}: width {w} != target {target_w}")
    fig.canvas.draw()
    rend = fig.canvas.get_renderer()
    texts = visible_texts(fig)
    sizes = [t.get_fontsize() for t in texts]
    small = [(t.get_text(), t.get_fontsize()) for t in texts
             if t.get_fontsize() < MIN_PT - 1e-9]
    if small:
        raise SystemExit(f"{name}: text below {MIN_PT} pt: {small[:10]}")
    W, H = fig.bbox.width, fig.bbox.height
    boxes = []
    clipped = []
    for t in texts:
        bb = t.get_window_extent(rend)
        if bb.width == 0 or bb.height == 0:
            continue
        if bb.x0 < -0.5 or bb.y0 < -0.5 or bb.x1 > W + 0.5 or bb.y1 > H + 0.5:
            clipped.append(t.get_text())
        boxes.append((t, bb))
    overlaps = []
    for i in range(len(boxes)):
        for j in range(i + 1, len(boxes)):
            a, b = boxes[i][1], boxes[j][1]
            ix = min(a.x1, b.x1) - max(a.x0, b.x0)
            iy = min(a.y1, b.y1) - max(a.y0, b.y0)
            if ix > 0.5 and iy > 0.5:
                overlaps.append((boxes[i][0].get_text(), boxes[j][0].get_text()))
    # legends must not cover data: no plotted point may fall inside a legend box
    covered = []
    for a in fig.axes:
        leg = a.get_legend()
        if leg is None:
            continue
        lb = leg.get_window_extent(rend)
        for ln in a.lines:
            xy = np.column_stack(ln.get_data()).astype(float)
            if xy.size == 0:
                continue
            d = ln.get_transform().transform(xy)
            inside = ((d[:, 0] >= lb.x0) & (d[:, 0] <= lb.x1) &
                      (d[:, 1] >= lb.y0) & (d[:, 1] <= lb.y1))
            if inside.any():
                covered.append(ln.get_label())
        for col in a.collections:
            offs = col.get_offsets()
            if len(offs) == 0:
                continue
            d = col.get_offset_transform().transform(offs)
            inside = ((d[:, 0] >= lb.x0) & (d[:, 0] <= lb.x1) &
                      (d[:, 1] >= lb.y0) & (d[:, 1] <= lb.y1))
            if inside.any():
                covered.append("collection")
    problems = []
    if covered:
        problems.append(f"{name}: legend covers data: {covered[:5]}")
    if clipped:
        problems.append(f"{name}: text outside the canvas: {clipped}")
    if overlaps:
        problems.append(f"{name}: overlapping texts: {overlaps[:10]}")
    if problems:
        if os.environ.get("FIGDEBUG"):
            fig.savefig(Path(os.environ["FIGDEBUG"]) / f"{name}_debug.png", dpi=150)
        raise SystemExit("; ".join(problems))
    return {"width_in": round(w, 4), "height_in": round(h, 4),
            "min_font_pt": min(sizes), "max_font_pt": max(sizes),
            "n_texts": len(texts)}


_MB = re.compile(rb"/MediaBox\s*\[\s*([-\d.]+)\s+([-\d.]+)\s+([-\d.]+)\s+([-\d.]+)\s*\]")


def pdf_search(raw: bytes, rx):
    """Search a PDF's bytes and, failing that, its inflated streams (object
    streams written by xdvipdfmx)."""
    m = rx.search(raw)
    if m:
        return m
    import zlib
    for sm in re.finditer(rb"stream\r?\n", raw):
        start = sm.end()
        end = raw.find(b"endstream", start)
        try:
            data = zlib.decompress(raw[start:end])
        except Exception:
            continue
        m = rx.search(data)
        if m:
            return m
    return None


def verify_pdf(path: Path, target_w: float) -> Dict:
    raw = path.read_bytes()
    m = pdf_search(raw, _MB)
    if not m:
        raise SystemExit(f"{path.name}: no MediaBox")
    x0, y0, x1, y1 = (float(v) for v in m.groups())
    width_in = (x1 - x0) / 72.0
    height_in = (y1 - y0) / 72.0
    if abs(width_in - target_w) > 0.005:
        raise SystemExit(f"{path.name}: PDF width {width_in:.4f} in != {target_w}")
    type3 = b"/Type3" in raw
    fontfiles = raw.count(b"/FontFile2") + raw.count(b"/FontFile3") + raw.count(b"/FontFile ")
    basefonts = sorted({b.decode() for b in re.findall(rb"/BaseFont\s*/([A-Za-z0-9+\-_,]+)", raw)})
    if type3:
        raise SystemExit(f"{path.name}: contains Type 3 fonts")
    if fontfiles == 0:
        raise SystemExit(f"{path.name}: no embedded font program")
    return {"pdf_width_in": round(width_in, 4), "pdf_height_in": round(height_in, 4),
            "embedded_font_programs": fontfiles, "base_fonts": basefonts,
            "type3_fonts": type3}


def save(fig, out: Path, name: str, target_w: float) -> Dict:
    info = check_figure(fig, name, target_w)
    pdf = out / f"{name}.pdf"
    png = out / f"{name}.png"
    meta_pdf = {"Creator": "scripts/manuscript_v3/make_figures.py",
                "Producer": None, "CreationDate": None}
    fig.savefig(pdf, format="pdf", metadata=meta_pdf)
    fig.savefig(png, format="png", dpi=300,
                metadata={"Software": "scripts/manuscript_v3/make_figures.py"})
    plt.close(fig)
    info.update(verify_pdf(pdf, target_w))
    info["files"] = [pdf.name, png.name]
    PROV.meta(name, check=info)
    return info


# ========================================================================= Fig 2
CHECKS = [
    ("1_distinctness", "1"), ("1b_input_dependence", "1b"),
    ("2_constant_features", "2"), ("3_cross_group_duplicates", "3"),
    ("4_feature_ceiling", "4a"), ("4b_headroom", "4b"),
    ("5_permuted_labels", "5"), ("6_cross_class_duplicates", "6"),
]
DIAG4 = {"4_feature_ceiling", "4b_headroom"}
SOUND = ["clean", "hard_but_honest", "near_chance"]
DEGENERATE = ["leaked_id", "seed_jitter_only", "duplicated_rows", "ambiguous_labels"]


def fig2(out: Path) -> Dict:
    name = "fig2-gate-specificity"
    src = "results/gate_specificity.json"
    pol_src = "results/v3/gate/specificity_policies.json"
    gs = load_json(src)
    pol = load_json(pol_src)
    runs = gs["per_run"]
    seeds = sorted({r["seed"] for r in runs})
    if seeds != [0, 1, 2]:
        raise SystemExit(f"unexpected seed indices {seeds}")
    fams = SOUND + DEGENERATE
    if sorted({r["family"] for r in runs}) != sorted(fams):
        raise SystemExit("unexpected families in gate_specificity.json")

    # verdicts under both policies, recomputed from checks_fired and checked
    # against the re-scoring file
    verdict = {}
    for i, r in enumerate(runs):
        fired = set(r["checks_fired"])
        unknown = fired - {c for c, _ in CHECKS}
        if unknown:
            raise SystemExit(f"unlabelled checks {unknown}")
        fail_i = not r["passed"]
        if fail_i != bool(fired):
            raise SystemExit(f"passed flag inconsistent with checks_fired, run {i}")
        fail_ii = bool(fired - DIAG4)
        verdict[(r["family"], r["seed"])] = (i, fail_i, fail_ii, r["should_pass"])
    for key, pkey in (("policy_i", 1), ("policy_ii", 2)):
        for fam, d in pol[key]["per_family"].items():
            want = sorted(d["failed_seeds"])
            got = sorted(s for (f, s), v in verdict.items() if f == fam and v[pkey])
            if want != got:
                raise SystemExit(f"{key} {fam}: failed seeds {got} != {want}")
    # instance-level cross-check against the v3 re-scoring
    for k, inst in enumerate(pol["per_instance"]):
        v = verdict[(inst["family"], inst["seed"])]
        if inst["passed_policy_i"] == v[1] or sorted(inst["checks_fired"]) != sorted(runs[v[0]]["checks_fired"]):
            raise SystemExit(f"per_instance {k} disagrees with gate_specificity.json")

    W, H = FULL_W, 2.86
    fig = plt.figure(figsize=(W, H))
    ax = fig.add_axes([0, 0, 1, 1])
    ax.set_xlim(0, W)
    ax.set_ylim(H, 0)
    ax.axis("off")

    left = 0.06
    c0, cw = 1.02, 0.355                      # check columns
    vx = [c0 + 8 * cw + 0.17, c0 + 8 * cw + 0.17 + 0.62 + 0.13]  # verdict col left edges
    vw = 0.62
    neq_x = vx[0] + vw + 0.065
    sd = 0.105                                 # seed offset inside a check cell
    sdv = 0.16                                 # seed offset inside a verdict cell
    col_centres = [c0 + (j + 0.5) * cw for j in range(8)]
    ver_centres = [vx[0] + vw / 2, vx[1] + vw / 2]

    y_head1, y_head2, y_head3 = 0.12, 0.28, 0.43
    rule_y = 0.51
    rows_y = {}
    y = 0.66
    group_y = {}
    for gname, members in (("Sound tables (should pass)", SOUND),
                           ("Degenerate tables (should fail)", DEGENERATE)):
        group_y[gname] = y
        y += 0.155
        for f in members:
            rows_y[f] = y
            y += 0.155
        y += 0.04

    # column shading and headers
    for j, xc in enumerate(col_centres):
        if j % 2 == 0:
            ax.add_patch(Rectangle((c0 + j * cw, rule_y + 0.02), cw, y - rule_y - 0.10,
                                   facecolor="#F3F3F3", edgecolor="none", zorder=0))
    for k in range(2):
        ax.add_patch(Rectangle((vx[k], rule_y + 0.02), vw, y - rule_y - 0.10,
                               facecolor="#F3F3F3", edgecolor="none", zorder=0))
    ax.text(c0 + 4 * cw, y_head1, "Diagnostic check", ha="center", va="center",
            fontsize=FS, fontweight="bold")
    ax.text((vx[0] + vx[1] + vw) / 2, y_head1, "Gate verdict", ha="center",
            va="center", fontsize=FS, fontweight="bold")
    for (cid, lab), xc in zip(CHECKS, col_centres):
        ax.text(xc, y_head2, lab, ha="center", va="center", fontsize=FS)
    ax.text(ver_centres[0], y_head2, "policy (i)", ha="center", va="center", fontsize=FS)
    ax.text(ver_centres[1], y_head2, "policy (ii)", ha="center", va="center", fontsize=FS)
    for xc, off in [(c, sd) for c in col_centres] + [(c, sdv) for c in ver_centres]:
        for s in seeds:
            ax.text(xc + (s - 1) * off, y_head3, str(s), ha="center", va="center",
                    fontsize=FS, color=INK2)
    ax.text(left, y_head3, "seed index", ha="left", va="center", fontsize=FS, color=INK2)
    ax.plot([left, vx[1] + vw], [rule_y, rule_y], color=INK, lw=0.5)

    for gname, gy in group_y.items():
        ax.text(left, gy, gname, ha="left", va="center", fontsize=FS, fontweight="bold")
    for f, ry in rows_y.items():
        ax.text(left + 0.07, ry, f, ha="left", va="center", fontsize=FS)
        for s in seeds:
            i, fail_i, fail_ii, should_pass = verdict[(f, s)]
            fired = set(runs[i]["checks_fired"])
            for (cid, lab), xc in zip(CHECKS, col_centres):
                hit = cid in fired
                if hit:
                    ax.plot(xc + (s - 1) * sd, ry, marker="s", ms=4.6, color=INK,
                            mec=INK, ls="none", zorder=3)
                else:
                    ax.plot(xc + (s - 1) * sd, ry, marker="o", ms=1.6, color="#B5B5B5",
                            mec="none", ls="none", zorder=2)
                PROV.add(name, "matrix", f"check {lab}", {"family": f, "seed_index": s},
                         bool(hit), src, f"per_run[{i}].checks_fired",
                         "True if the check id is in checks_fired")
            for k, fail in enumerate((fail_i, fail_ii)):
                xc = ver_centres[k] + (s - 1) * sdv
                correct = (not fail) == should_pass
                col = INK if correct else ACCENT
                ax.plot(xc, ry, marker="o", ms=5.0, ls="none", zorder=3,
                        color=col if fail else "white", mec=col, mew=0.9)
                if not correct:
                    ax.plot(xc, ry, marker="s", ms=8.6, ls="none", zorder=4,
                            mfc="none", mec=ACCENT, mew=0.8)
                path = (f"per_run[{i}].passed" if k == 0 else
                        f"per_run[{i}].checks_fired (fails unless only 4_feature_ceiling/4b_headroom fired)")
                PROV.add(name, "verdict", f"policy ({'i' if k == 0 else 'ii'})",
                         {"family": f, "seed_index": s},
                         {"gate_fails": bool(fail), "should_pass": bool(should_pass),
                          "agrees_with_known_status": bool(correct)}, src, path,
                         f"cross-checked against {pol_src} policy_{'i' if k == 0 else 'ii'}.per_family.{f}.failed_seeds")
        if any(verdict[(f, s)][1] != verdict[(f, s)][2] for s in seeds):
            ax.text(neq_x, ry, "\u2260", ha="center", va="center", fontsize=8.0,
                    color=INK)

    # legend (drawn by hand so that markers match exactly)
    ly1 = y + 0.04
    ly2 = ly1 + 0.155
    items1 = [("fired", dict(marker="s", ms=4.6, color=INK, mec=INK), "check fired"),
              ("not", dict(marker="o", ms=1.6, color="#B5B5B5", mec="none"), "did not fire"),
              ("fail", dict(marker="o", ms=5.0, color=INK, mec=INK, mew=0.9), "gate fails the table"),
              ("pass", dict(marker="o", ms=5.0, color="white", mec=INK, mew=0.9), "gate passes the table")]
    x = left
    for key, st, lab in items1:
        ax.plot(x + 0.04, ly1, ls="none", **st)
        t = ax.text(x + 0.11, ly1, lab, ha="left", va="center", fontsize=FS)
        x += 0.11 + text_width_in(fig, t) + 0.20
    x = left
    ax.plot(x + 0.04, ly2, marker="o", ms=5.0, ls="none", color=ACCENT, mec=ACCENT, mew=0.9)
    ax.plot(x + 0.04, ly2, marker="s", ms=8.6, ls="none", mfc="none", mec=ACCENT, mew=0.8)
    t = ax.text(x + 0.13, ly2, "verdict contradicts the known status of the table", ha="left",
                va="center", fontsize=FS)
    x += 0.13 + text_width_in(fig, t) + 0.20
    ax.text(x + 0.03, ly2, "\u2260", ha="center", va="center", fontsize=8.0)
    ax.text(x + 0.11, ly2, "policies (i) and (ii) disagree", ha="left", va="center", fontsize=FS)
    ly3 = ly2 + 0.16
    key_lines = [
        "Checks: 1 distinct vectors; 1b input dependence; 2 constant features; "
        "3 cross-group duplicates;",
        "4 best-k ceiling; 4b chance-corrected headroom; 5 permuted-label control; "
        "6 cross-class duplicates.",
        "Policy (i): every failure disqualifies. Policy (ii): diagnostic 4 (4 and 4b) is advisory.",
    ]
    for k, line in enumerate(key_lines):
        ax.text(left, ly3 + k * 0.135, line, ha="left", va="center", fontsize=FS, color=INK2)
    bottom = ly3 + (len(key_lines) - 1) * 0.135 + 0.08
    if bottom > H:
        raise SystemExit(f"{name}: canvas too short ({bottom:.3f} > {H})")
    PROV.meta(name, sources=[src, pol_src],
              note="markers per family x seed index from results/gate_specificity.json per_run; "
                   "policy (ii) verdict = fail iff a check other than 4_feature_ceiling/4b_headroom fired")
    return save(fig, out, name, FULL_W)


def text_width_in(fig, t: Text) -> float:
    fig.canvas.draw()
    bb = t.get_window_extent(fig.canvas.get_renderer())
    return bb.width / fig.dpi


# ========================================================================= Fig 3
CONFIGS = ["A", "B", "C"]


def openset(config: str, variant: str):
    rel = f"results/v3/openset_{config}_{variant}.json"
    return rel, load_json(rel)


def fig3(out: Path) -> Dict:
    name = "fig3-openset"
    fig = plt.figure(figsize=(FULL_W, 5.05), layout="constrained")
    gsp = fig.add_gridspec(2, 1, height_ratios=[2.05, 2.75])
    axa = fig.add_subplot(gsp[0])
    axb = fig.add_subplot(gsp[1])

    # ---------------- (a) per-fold MSP AUROC, matched protocol, A/B/C
    rng = np.random.default_rng(JITTER_SEED)
    off = {"A": -0.29, "B": 0.0, "C": 0.29}
    xt, xl = [], []
    for gi, m in enumerate(OPEN_EST):
        for c in CONFIGS:
            rel, d = openset(c, "heldout")
            if d["novel_programs"] != "heldout" or d["split"] != "gss":
                raise SystemExit(f"{rel}: not the program-matched protocol")
            vals, paths = [], []
            for i, f in enumerate(d["per_fold"]):
                if f["model"] != m:
                    continue
                if f.get("n_novel_from_fit_programs", 0) != 0:
                    raise SystemExit(f"{rel}: novel rows from fitting programs")
                vals.append(f["scorers"]["msp"]["auroc"])
                paths.append(f"per_fold[{i}].scorers.msp.auroc")
            vals = np.asarray(vals, dtype=float)
            mean = float(vals.mean())
            close(mean, d["summary"][m]["scorers"]["msp"]["auroc_mean"], 1e-12,
                  f"{rel} {m} msp mean")
            _, row = csv_row("results/v3/summary/table14.csv", variant="heldout",
                             config=c, model=m)
            close(mean, float(row["msp_auroc_mean"]), 5e-7, f"table14 {c} {m}")
            if int(row["n_folds"]) != len(vals):
                raise SystemExit(f"fold count mismatch {c} {m}")
            x0 = gi + off[c]
            jit = rng.uniform(-0.085, 0.085, size=len(vals))
            axa.scatter(x0 + jit, vals, s=5.5, color=EST_COLOR[m], alpha=0.55,
                        linewidths=0, zorder=2, rasterized=False)
            axa.plot([x0 - 0.12, x0 + 0.12], [mean, mean], color=INK, lw=1.4,
                     solid_capstyle="butt", zorder=3)
            for v, p in zip(vals, paths):
                PROV.add(name, "a", f"{m} config {c}", "fold", float(v), rel, p)
            PROV.add(name, "a", f"{m} config {c}", "mean (bar)", mean, rel,
                     f"summary.{m}.scorers.msp.auroc_mean",
                     f"mean of {len(vals)} per-fold values; equals summary")
            xt.append(x0)
            xl.append(c)
    axa.axhline(0.5, color=REF, lw=0.7, ls=(0, (3, 2)), zorder=1)
    axa.set_xticks(xt)
    axa.set_xticklabels(xl)
    axa.tick_params(axis="x", length=0, pad=2)
    for gi in range(1, len(OPEN_EST)):
        axa.axvline(gi - 0.5, color=GRID, lw=0.6, zorder=0)
    axa.set_xlim(-0.5, len(OPEN_EST) - 0.5)
    axa.set_ylim(-0.025, 1.025)
    axa.spines["left"].set_bounds(0, 1)
    axa.set_yticks([0, 0.25, 0.5, 0.75, 1.0])
    axa.set_yticklabels(["0", "0.25", "0.5", "0.75", "1"])
    axa.set_ylabel("MSP AUROC per fold")
    sec = axa.secondary_xaxis(-0.105)
    sec.set_xticks(range(len(OPEN_EST)))
    sec.set_xticklabels([LABEL[m] for m in OPEN_EST])
    sec.tick_params(axis="x", length=0, pad=1)
    sec.spines["bottom"].set_visible(False)
    hgrid(axa)
    axa.grid(axis="y", color=GRID, linewidth=0.5)
    panel_letter(axa, "a", x=-0.035, y=1.0)
    # legend for the mean bar and chance line, placed above the axes
    hs = [Line2D([], [], color=INK, lw=1.4),
          Line2D([], [], color=REF, lw=0.7, ls=(0, (3, 2)))]
    axa.legend(hs, ["mean over folds", "chance (0.5)"], loc="lower right",
               bbox_to_anchor=(1.0, 1.0), ncol=2, borderaxespad=0.1)

    # ---------------- (b) configuration B, six scorers, three protocols
    rows: List[Tuple[str, str, str, Optional[str]]] = []
    for m in OPEN_EST:
        rows.append(("MSP", m, "msp", m))
    for sc, lab in (("energy", "Energy"), ("openmax", "OpenMax")):
        for m in ["logreg", "svm_rbf", "mlp"]:
            rows.append((lab, m, sc, m))
    for s in ("knn_dist", "mahalanobis", "iforest"):
        rows.append(("Model-free", s, s, None))
    variants = [("all", "program-overlapping"),
                ("heldout", "program-matched" if FULL_W < 5.4 else "program-matched (primary)"),
                ("kfold", "program k-fold")]
    ypos, y = [], 0.0
    prev = None
    for r in rows:
        if prev is not None and r[0] != prev:
            y += 0.55
        ypos.append(y)
        prev = r[0]
        y += 1.0
    ymax = y - 1.0
    group_span: Dict[str, List[float]] = {}
    for (grp, lab, sc, m), yy in zip(rows, ypos):
        vals = {}
        for v, _ in variants:
            rel, d = openset("B", v)
            if m is not None:
                val = d["summary"][m]["scorers"][sc]["auroc_mean"]
                path = f"summary.{m}.scorers.{sc}.auroc_mean"
                deriv = None
            else:
                per_model = [d["summary"][mm]["scorers"][sc]["auroc_mean"] for mm in OPEN_EST]
                if max(per_model) - min(per_model) > 1e-12:
                    raise SystemExit(f"{rel}: model-free {sc} differs across estimators")
                val = per_model[0]
                path = f"summary.random_forest.scorers.{sc}.auroc_mean"
                deriv = "model-free scorer; identical in every estimator's summary (checked)"
            _, grow = csv_row("results/v3/summary/grid.csv", variant=v, config="B",
                              model=m if m is not None else "random_forest", scorer=sc)
            close(val, float(grow["auroc_mean"]), 5e-7, f"grid.csv B {v} {lab} {sc}")
            vals[v] = val
            PROV.add(name, "b", f"{grp} {lab}", v, float(val), rel, path, deriv)
        col = EST_COLOR[m] if m is not None else MODEL_FREE_COLOR
        lo, hi = min(vals.values()), max(vals.values())
        axb.plot([lo, hi], [yy, yy], color=col, lw=1.0, alpha=0.55, zorder=1,
                 solid_capstyle="butt")
        axb.plot(vals["all"], yy, marker="o", ms=5.2, mfc="white", mec=col, mew=1.0,
                 ls="none", zorder=3)
        axb.plot(vals["heldout"], yy, marker="o", ms=5.2, color=col, mec=col,
                 ls="none", zorder=4)
        axb.plot(vals["kfold"], yy, marker="|", ms=7.0, mew=1.1, color=INK,
                 ls="none", zorder=5)
        group_span.setdefault(grp, []).append(yy)
    axb.axvline(0.5, color=REF, lw=0.7, ls=(0, (3, 2)), zorder=1)
    axb.set_yticks(ypos)
    axb.set_yticklabels([LABEL[r[1]] for r in rows])
    axb.set_ylim(ymax + 0.7, -0.7)
    axb.set_xlim(0, 0.75)
    axb.set_xticks([0, 0.25, 0.5, 0.75])
    axb.set_xticklabels(["0", "0.25", "0.5", "0.75"])
    axb.set_xlabel("Configuration B AUROC (mean over folds)")
    axb.tick_params(axis="y", length=0, pad=3)
    vgrid(axb)
    for grp, ys in group_span.items():
        axb.annotate(grp, xy=(0, (min(ys) + max(ys)) / 2), xycoords=("axes fraction", "data"),
                     xytext=(-62, 0), textcoords="offset points", ha="right", va="center",
                     fontsize=FS, fontweight="bold")
    seps = sorted({(ypos[i] + ypos[i - 1]) / 2 for i in range(1, len(rows))
                   if rows[i][0] != rows[i - 1][0]})
    for s in seps:
        axb.axhline(s, color="#CFCFCF", lw=0.5, zorder=0)
    hs = [Line2D([], [], marker="o", ms=5.2, mfc="white", mec=INK, mew=1.0, ls="none"),
          Line2D([], [], marker="o", ms=5.2, color=INK, ls="none"),
          Line2D([], [], marker="|", ms=7.0, mew=1.1, color=INK, ls="none")]
    narrow = FULL_W < 5.4   # e.g. Springer sn-jnl width: tighten the one-row legend
    axb.legend(hs, [lab for _, lab in variants], loc="lower left",
               bbox_to_anchor=(-0.02 if narrow else 0.0, 1.0), ncol=3, borderaxespad=0.1,
               columnspacing=0.8 if narrow else 2.0, handletextpad=0.3 if narrow else 0.8)
    panel_letter(axb, "b", x=-0.035, y=1.0)
    PROV.meta(name, sources=[f"results/v3/openset_{c}_heldout.json" for c in CONFIGS]
              + ["results/v3/openset_B_all.json", "results/v3/openset_B_kfold.json",
                 "results/v3/summary/table14.csv", "results/v3/summary/grid.csv"],
              note="(a) program-matched protocol (--novel-programs heldout, gss); bars are "
                         "means over folds (A, C: 4 families x 5 seeds; B: 10 parameterisations x 5 "
                         "seeds); horizontal jitter only. (b) configuration B; evt_posterior excluded; "
                         "energy/OpenMax only where the estimator exposes class scores.")
    return save(fig, out, name, FULL_W)


# ========================================================================= Fig 4
POS_ORDER = [("end", "end\n(3-member families)"), ("interior", "interior\n(3-member)"),
             ("end_of_pair", "end of pair\n(2-member families)")]


def fig4(out: Path) -> Dict:
    name = "fig4-sibling-axis"
    pos_src = "results/v3/sibling_position_heldout.json"
    tst_src = "results/v3/summary/sibling_tests.json"
    t16 = "results/v3/summary/table16.csv"
    t15 = "results/v3/summary/table15.csv"
    pos = load_json(pos_src)["positions"]
    tests = load_json(tst_src)
    # numbering: family order, then rank on the axis
    fam_order = []
    for p, d in pos.items():
        if d["family"] not in fam_order:
            fam_order.append(d["family"])
    params = sorted(pos, key=lambda p: (fam_order.index(pos[p]["family"]),
                                        pos[p]["rank_in_family"]))
    number = {p: i + 1 for i, p in enumerate(params)}
    # positions must agree across the three variant reports
    for v in ("all", "kfold"):
        other = load_json(f"results/v3/sibling_position_{v}.json")["positions"]
        for p in params:
            if other[p]["position"] != pos[p]["position"]:
                raise SystemExit(f"position of {p} differs in variant {v}")

    narrow = FULL_W < 5.4   # e.g. Springer sn-jnl width with 8 pt lettering
    fig = plt.figure(figsize=(FULL_W, 2.9 if narrow else 2.6), layout="constrained")
    gsp = fig.add_gridspec(1, 2, width_ratios=[2.9, 1.75] if narrow else [3.45, 1.5])
    ax = fig.add_subplot(gsp[0])
    axk = fig.add_subplot(gsp[1])
    axk.axis("off")

    x = 0.0
    xt, xl, grp_centres = [], [], []
    seps = []
    for gi, (pk, plab) in enumerate(POS_ORDER):
        members = [p for p in params if pos[p]["position"] == pk]
        gx0 = x
        for p in members:
            vals = {}
            for v in ("heldout", "all"):
                val = tests[v]["param_level_means"][p]
                _, r15 = csv_row(t15, variant=v, sub_technique=p)
                close(val, float(r15["msp_auroc_mean"]), 5e-7, f"table15 {v} {p}")
                vals[v] = val
                PROV.add(name, "main", f"{number[p]} {p}", v, float(val), tst_src,
                         f"{v}.param_level_means.{p}",
                         "MSP AUROC, configuration B, mean over 30 folds (6 estimators x 5 seeds)")
            ax.plot([x, x], [vals["all"], vals["heldout"]], color="#9A9A9A", lw=0.8, zorder=1)
            ax.plot(x, vals["all"], marker="o", ms=5.4, mfc="white", mec=INK, mew=0.9,
                    ls="none", zorder=3)
            ax.plot(x, vals["heldout"], marker="o", ms=5.4, color=INK, ls="none", zorder=4)
            xt.append(x)
            xl.append(str(number[p]))
            x += 1.0
        # group mean +/- 1 sd over folds
        mx = x + 0.15
        for v, dx, filled in (("heldout", -0.17, True), ("all", 0.17, False)):
            i16, r16 = csv_row(t16, variant=v, position=pk)
            mean, sdv = float(r16["mean"]), float(r16["sd"])
            unit_means = [tests[v]["param_level_means"][p] for p in members]
            close(mean, float(np.mean(unit_means)), 5e-6, f"table16 mean {v} {pk}")
            close(mean, float(r16["param_level_mean_of_means"]), 5e-7, f"table16 {v} {pk}")
            ax.errorbar(mx + dx, mean, yerr=sdv, fmt="D", ms=4.6, color=INK,
                        mfc=INK if filled else "white", mec=INK, mew=0.9, elinewidth=0.9,
                        capsize=2.0, capthick=0.9, zorder=4)
            for key, val in (("group mean", mean), ("group sd (folds)", sdv)):
                PROV.add(name, "main", f"group {pk}", f"{v} {key}", val, t16,
                         f"row {i16} (variant={v}, position={pk}) column "
                         f"{'mean' if key == 'group mean' else 'sd'}",
                         f"n_folds={r16['n_folds']}, n_parameterisations={r16['n_parameterisations']}")
        xt.append(mx)
        xl.append("mean")
        grp_centres.append(((gx0 + mx) / 2, plab))
        x = mx + 1.05
        if gi < len(POS_ORDER) - 1:
            seps.append(x - 0.55)
    for s in seps:
        ax.axvline(s, color=GRID, lw=0.6, zorder=0)
    ax.axhline(0.5, color=REF, lw=0.7, ls=(0, (3, 2)), zorder=1)
    ax.set_xticks(xt)
    ax.set_xticklabels(xl)
    ax.tick_params(axis="x", length=0, pad=2)
    ax.set_xlim(-0.6, x - 0.45)
    ax.set_ylim(0, 1.0)
    ax.set_yticks([0, 0.25, 0.5, 0.75, 1.0])
    ax.set_yticklabels(["0", "0.25", "0.5", "0.75", "1"])
    ax.set_ylabel("MSP AUROC, configuration B")
    hgrid(ax)
    sec = ax.secondary_xaxis(-0.1)
    sec.set_xticks([c for c, _ in grp_centres])
    sec.set_xticklabels([lab for _, lab in grp_centres])
    sec.tick_params(axis="x", length=0, pad=1)
    sec.spines["bottom"].set_visible(False)
    hs = [Line2D([], [], marker="o", ms=5.4, color=INK, ls="none"),
          Line2D([], [], marker="o", ms=5.4, mfc="white", mec=INK, mew=0.9, ls="none"),
          Line2D([], [], marker="D", ms=4.6, color=INK, ls="none")]
    fig.legend(hs, ["program-matched" if FULL_W < 5.4 else "program-matched (primary)", "program-overlapping",
                    "position-class mean \u00b1 1 sd over folds"],
               loc="outside upper left", ncol=3, borderaxespad=0.1,
               handletextpad=0.3, columnspacing=1.2)

    # key: number, parameterisation, |PC1 projection|; line pitch fixed in points.
    # Key texts are excluded from constrained layout (they are placed in axes
    # fraction of an empty axes whose size the gridspec fixes).
    fig.canvas.draw()
    hk_pt = axk.get_window_extent().height / fig.dpi * 72.0
    lh = 8.9 / hk_pt
    n_before = len(axk.texts)
    yk = 1.0
    axk.text(0.0, yk, "No.", transform=axk.transAxes, ha="left", va="top",
             fontsize=FS, fontweight="bold")
    axk.text(0.17, yk, "parameterisation", transform=axk.transAxes, ha="left", va="top",
             fontsize=FS, fontweight="bold")
    axk.text(1.0, yk, "|proj.|", transform=axk.transAxes, ha="right", va="top",
             fontsize=FS, fontweight="bold")
    yk -= lh * 1.15
    for fam in fam_order:
        axk.text(0.0, yk, fam, transform=axk.transAxes, ha="left", va="top",
                 fontsize=FS, color=INK2, style="italic")
        yk -= lh
        for p in [q for q in params if pos[q]["family"] == fam]:
            proj = tests["pc1_recomputed_unrounded"][fam]["projections"][p]
            close(proj, pos[p]["projection"], 5e-5, f"projection {p}")
            axk.text(0.10, yk, str(number[p]), transform=axk.transAxes, ha="right",
                     va="top", fontsize=FS)
            axk.text(0.17, yk, p, transform=axk.transAxes, ha="left", va="top", fontsize=FS)
            axk.text(1.0, yk, f"{abs(proj):.2f}", transform=axk.transAxes, ha="right",
                     va="top", fontsize=FS)
            PROV.add(name, "key", f"{number[p]} {p}", "|PC1 projection|", abs(proj), tst_src,
                     f"pc1_recomputed_unrounded.{fam}.projections.{p}",
                     "absolute value; printed to 2 decimals")
            PROV.add(name, "key", f"{number[p]} {p}", "position", pos[p]["position"], pos_src,
                     f"positions.{p}.position")
            yk -= lh
    for t in axk.texts[n_before:]:
        t.set_in_layout(False)
    if yk < -0.02:
        raise SystemExit(f"{name}: key does not fit ({yk:.3f})")
    PROV.meta(name, sources=[pos_src, tst_src, t15, t16],
              note="per-parameterisation MSP AUROC pooled over 6 estimators x 5 seeds (30 folds); "
                   "group markers are the fold-level mean +/- 1 sd (ddof=1) of each position class "
                   "(end: 120 folds/4 units; interior: 60/2; end of pair: 120/4)")
    return save(fig, out, name, FULL_W)


# ========================================================================= Fig 5
SPREADS = [0.25, 0.5, 1.0, 2.0, 4.0]   # 8.0 omitted (float64 saturation)


def sim_cell(layout: str, spread: float, holdout: str):
    rel = f"results/v3/sim/inversion_sim_{layout}_20seeds.json"
    d = load_json(rel)
    if d["settings"]["sibling_layout"] != layout or d["settings"]["seeds"] != 20:
        raise SystemExit(f"{rel}: unexpected settings")
    hits = [(i, c) for i, c in enumerate(d["audit_monte_carlo"]["cells"])
            if c["sibling_spread"] == spread and c["holdout"] == holdout]
    if len(hits) != 1:
        raise SystemExit(f"{rel}: {len(hits)} cells for {spread} {holdout}")
    return rel, hits[0][0], hits[0][1]


def fig5(out: Path) -> Dict:
    name = "fig5-simulation"
    t18 = "results/v3/sim/table18_v3.csv"
    fig = plt.figure(figsize=(FULL_W, 2.45), layout="constrained")
    gsp = fig.add_gridspec(1, 2, width_ratios=[1, 1])
    axa = fig.add_subplot(gsp[0])
    axb = fig.add_subplot(gsp[1], sharex=axa)
    ls_of = {"ordered": "-", "random": (0, (3.2, 1.8))}
    hold_lab = {"edge": "end", "interior": "interior", "family": "family"}
    wide_a = {"edge": "bayes_posterior_auroc_end", "interior": "bayes_posterior_auroc_interior",
              "family": "bayes_posterior_auroc_family"}

    def series(ax, layout, holdout, metric, color, marker, panel, label, wide):
        means, lo, hi = [], [], []
        for s in SPREADS:
            rel, ci, cell = sim_cell(layout, s, holdout)
            mm = cell["metrics"][metric]
            if mm["n"] != 20:
                raise SystemExit("expected 20 seeds")
            _, row = csv_row(t18, layout=layout, n_seeds="20", sibling_spread=str(s))
            close(mm["mean"], float(row[f"{wide}_mean"]), 5e-5, f"table18 {layout} {s} {wide}")
            close(mm["ci95_mean_lo"], float(row[f"{wide}_ci95_lo"]), 5e-5, "ci lo")
            close(mm["ci95_mean_hi"], float(row[f"{wide}_ci95_hi"]), 5e-5, "ci hi")
            means.append(mm["mean"])
            lo.append(mm["ci95_mean_lo"])
            hi.append(mm["ci95_mean_hi"])
            for k in ("mean", "ci95_mean_lo", "ci95_mean_hi"):
                PROV.add(name, panel, f"{label} {layout}", {"sibling_spread": s, "stat": k},
                         float(mm[k]), rel, f"audit_monte_carlo.cells[{ci}].metrics.{metric}.{k}",
                         "20 seeds; t-based 95% interval of the mean")
        ax.fill_between(SPREADS, lo, hi, color=color, alpha=0.16, linewidth=0, zorder=1)
        filled = layout == "ordered"
        ax.plot(SPREADS, means, color=color, ls=ls_of[layout], lw=1.2, zorder=3,
                marker=marker, ms=4.2, mfc=color if filled else "white", mec=color, mew=0.9)

    for layout in ("ordered", "random"):
        # interior first so that the end curve (which coincides with it under the
        # random layout) is drawn on top and stays visible
        for h in ("interior", "edge", "family"):
            series(axa, layout, h, "auroc_bayes_msp", SIM_COLOR[h], SIM_MARKER[h], "a",
                   f"Bayes posterior AUROC, {hold_lab[h]} held out", wide_a[h])
        series(axb, layout, "family", "closed_accuracy_bayes", BAYES_COLOR, "D", "b",
               "exact Bayes retained-class accuracy, family holdout", "bayes_retained_acc_family")
        series(axb, layout, "family", "closed_accuracy_random_forest",
               EST_COLOR["random_forest"], "o", "b",
               "fitted random forest retained-class accuracy, family holdout",
               "rf_retained_acc_family")
    for ax in (axa, axb):
        ax.set_xscale("log", base=2)
        ax.set_xticks(SPREADS)
        ax.set_xticklabels(["0.25", "0.5", "1", "2", "4"])
        ax.minorticks_off()
        ax.set_xlim(0.25 / 1.18, 4.0 * 1.18)
        ax.set_ylim(-0.03, 1.03)
        ax.spines["left"].set_bounds(0, 1)
        ax.set_yticks([0, 0.25, 0.5, 0.75, 1.0])
        ax.set_yticklabels(["0", "0.25", "0.5", "0.75", "1"])
        ax.set_xlabel("Sibling spread")
        hgrid(ax)
    axa.axhline(0.5, color=REF, lw=0.7, ls=(0, (3, 2)), zorder=1)
    axa.set_ylabel("Exact-posterior MSP AUROC")
    axb.set_ylabel("Retained-class accuracy")
    panel_letter(axa, "a", x=-0.05)
    panel_letter(axb, "b", x=-0.05)
    ha = [Line2D([], [], color=SIM_COLOR[h], marker=SIM_MARKER[h], ms=4.2, lw=1.2)
          for h in ("edge", "interior", "family")]
    hl = [Line2D([], [], color=INK, lw=1.2, ls=ls_of["ordered"], marker="o", ms=4.2,
                 mfc=INK, mec=INK, mew=0.9),
          Line2D([], [], color=INK, lw=1.2, ls=ls_of["random"], marker="o", ms=4.2,
                 mfc="white", mec=INK, mew=0.9)]
    fig.legend(ha + hl, ["end held out", "interior held out", "family held out",
                         "ordered layout", "random layout"],
               loc="outside upper center", ncol=3 if FULL_W < 5.4 else 5, borderaxespad=0.1,
               handlelength=2.0, columnspacing=1.0, handletextpad=0.35)
    hb = [Line2D([], [], color=BAYES_COLOR, marker="D", ms=4.2, lw=1.2),
          Line2D([], [], color=EST_COLOR["random_forest"], marker="o", ms=4.2, lw=1.2)]
    axb.legend(hb, ["exact Bayes classifier", "fitted random forest"], loc="lower right",
               borderaxespad=0.3, handlelength=2.2)
    PROV.meta(name, sources=["results/v3/sim/inversion_sim_ordered_20seeds.json",
                             "results/v3/sim/inversion_sim_random_20seeds.json", t18],
              note="spread 8.0 omitted (1 - max posterior saturates in float64); bands are "
                   "t-based 95% intervals of the mean over 20 seeds; filled markers/solid = "
                   "ordered layout, hollow/dashed = random layout; panel (b) is the family holdout; "
                   "each condition removes one sibling per family (four novel classes) at once")
    return save(fig, out, name, FULL_W)


# ========================================================================= Fig 6
def closed_cells(kind: str, m: str):
    """Per-fold macro F1 for one estimator.  kind: grouped_cv (repeated grouped
    CV, family), lomfo (domain holdout, family), lomfo_sub (domain holdout,
    parameterisation)."""
    vals, recs = [], []
    for s in range(5):
        if kind == "grouped_cv":
            rel = f"results/v3/closed/pg/provenance_grouped_cv_{m}_all_s{s}.json"
        elif kind == "lomfo":
            rel = f"results/pilot5/provenance_lomfo_{m}_all_s{s}.json"
        else:
            rel = f"results/pilot5sub/sub_provenance_lomfo_{m}_all_s{s}.json"
        d = load_json(rel)
        if d["model"] != m or d["seed"] != s or d["feature_set"] != "all":
            raise SystemExit(f"{rel}: unexpected cell")
        if kind == "grouped_cv" and not d.get("permute_groups"):
            raise SystemExit(f"{rel}: not a permuted-partition run")
        if len(d["per_fold"]) != 5:
            raise SystemExit(f"{rel}: expected 5 folds")
        for i, f in enumerate(d["per_fold"]):
            vals.append(float(f["macro_f1"]))
            recs.append((rel, f"per_fold[{i}].macro_f1", s, f["fold_id"]))
    return np.asarray(vals), recs


def fig6(out: Path) -> Dict:
    name = "fig6-closed-set"
    agg = {"grouped_cv": ("results/v3/closed/pg_aggregate.json", "provenance", "grouped_cv"),
           "lomfo": ("results/v3/closed/agg_committed_pilot5.json", "provenance", "lomfo"),
           "lomfo_sub": ("results/v3/closed/agg_committed_pilot5sub.json", "sub_provenance", "lomfo")}
    chance_src = {"family": "results/v3/gate/gate_selfcontained_technique.json",
                  "param": "results/v3/gate/gate_selfcontained_subtechnique.json"}
    chance = {}
    for k, rel in chance_src.items():
        g = load_json(rel)
        chance[k] = float(g["single_feature"]["chance_macro_f1"])
        PROV.add(name, "a" if k == "family" else "b", "chance line", "macro F1", chance[k], rel,
                 "single_feature.chance_macro_f1",
                 f"{g['single_feature']['n_classes']} balanced classes")

    fig = plt.figure(figsize=(FULL_W, 2.2), layout="constrained")
    gsp = fig.add_gridspec(1, 2, width_ratios=[1, 1])
    axa = fig.add_subplot(gsp[0])
    axb = fig.add_subplot(gsp[1], sharey=axa)
    settings = [("a", axa, "grouped_cv", -0.17, "o", "repeated grouped CV"),
                ("a", axa, "lomfo", 0.17, "s", "domain holdout"),
                ("b", axb, "lomfo_sub", 0.0, "s", "domain holdout")]
    for panel, ax, kind, dy, mk, lab in settings:
        arel, task, proto = agg[kind]
        a = load_json(arel)
        for yi, m in enumerate(EST_ORDER):
            vals, recs = closed_cells(kind, m)
            cell = [c for c in a["cells"] if c["task"] == task and c["protocol"] == proto
                    and c["model"] == m and c["feature_set"] == "all"]
            if len(cell) != 1:
                raise SystemExit(f"{arel}: no unique cell for {m}")
            cell = cell[0]
            mean, lo, hi = float(vals.mean()), float(vals.min()), float(vals.max())
            close(mean, cell["mean"], 5e-5, f"{arel} {m} mean")
            close(lo, cell["min_fold"], 5e-5, f"{arel} {m} min")
            close(hi, cell["max_fold"], 5e-5, f"{arel} {m} max")
            if cell["n_measurements"] != len(vals):
                raise SystemExit("measurement count mismatch")
            y = yi + dy
            col = EST_COLOR[m]
            ax.plot([lo, hi], [y, y], color=col, lw=1.6, solid_capstyle="butt", zorder=2)
            ax.plot(mean, y, marker=mk, ms=4.8, color=col, mec="white", mew=0.6, ls="none",
                    zorder=3)
            ax.plot([lo, lo], [y - 0.09, y + 0.09], color=col, lw=0.9, zorder=2)
            ax.plot([hi, hi], [y - 0.09, y + 0.09], color=col, lw=0.9, zorder=2)
            series = f"{m} {lab} ({'family' if panel == 'a' else 'parameterisation'})"
            for v, (rel, path, s, fid) in zip(vals, recs):
                PROV.add(name, panel, series, {"seed": s, "fold_id": fid}, float(v), rel, path,
                         "per-fold value; range and mean are computed over these 25")
            PROV.add(name, panel, series, "mean (marker)", mean, arel,
                     f"cells[task={task},protocol={proto},model={m},feature_set=all].mean",
                     "mean of the 25 per-fold values (5 folds x 5 seeds); summary rounded to 4 d.p.")
            cpath = f"cells[task={task},protocol={proto},model={m},feature_set=all]"
            PROV.add(name, panel, series, "min (range end)", lo, arel, cpath + ".min_fold",
                     "min of the 25 per-fold values; summary rounded to 4 d.p.")
            PROV.add(name, panel, series, "max (range end)", hi, arel, cpath + ".max_fold",
                     "max of the 25 per-fold values; summary rounded to 4 d.p.")
    for ax, k in ((axa, "family"), (axb, "param")):
        ax.axvline(chance[k], color=REF, lw=0.7, ls=(0, (3, 2)), zorder=1)
        ax.text(chance[k] + 0.012, -0.95, "chance", ha="left", va="center", fontsize=FS,
                color=INK2)
        ax.set_xlim(0, 1.025)
        ax.spines["bottom"].set_bounds(0, 1)
        ax.set_xticks([0, 0.25, 0.5, 0.75, 1.0])
        ax.set_xticklabels(["0", "0.25", "0.5", "0.75", "1"])
        vgrid(ax)
        ax.tick_params(axis="y", length=0, pad=3)
    axa.set_ylim(len(EST_ORDER) - 0.5, -1.3)
    axa.set_yticks(range(len(EST_ORDER)))
    axa.set_yticklabels([LABEL[m] for m in EST_ORDER])
    plt.setp(axb.get_yticklabels(), visible=False)
    axa.set_xlabel("Macro F1, family label (4 classes)")
    axb.set_xlabel("Macro F1, parameterisation label (10 classes)")
    hs = [Line2D([], [], marker="o", ms=4.8, color=INK, mec="white", mew=0.6, ls="-", lw=1.6),
          Line2D([], [], marker="s", ms=4.8, color=INK, mec="white", mew=0.6, ls="-", lw=1.6)]
    fig.legend(hs, ["repeated grouped CV, 5 permuted program partitions (family only)",
                    "domain holdout, 5 suites"],
               loc="outside upper right", ncol=2, borderaxespad=0.1,
               handlelength=1.8, columnspacing=1.4)
    panel_letter(axa, "a", x=-0.02)
    panel_letter(axb, "b", x=-0.02)
    PROV.meta(name, sources=[v[0] for v in agg.values()] + list(chance_src.values()),
              note="marker = mean of 25 per-fold macro F1 values (5 folds x 5 seeds); line = "
                   "min-max over the same 25 values; repeated grouped CV uses 5 permuted program "
                   "partitions (results/v3/closed/pg); domain holdout = lomfo, one partition of 5 suites")
    return save(fig, out, name, FULL_W)


# ========================================================================= Fig 1
# Figure 1 is drawn with plain TikZ (no libraries, explicit coordinates in cm)
# so that it needs nothing beyond \usepackage{tikz} and cannot be broken by
# library loading inside the figure group.
FIG1_BOXES = [
    # name, x (cm), width (cm), top (cm), height (cm), dashed, title, body lines
    ("in", 0.00, 1.75, 0.00, 2.60, False, "Inputs",
     ["@NPROG@ benign C", "programs in", "@NSUITE@ suites of @PERSUITE@"]),
    ("be", 2.20, 2.50, 0.00, 2.60, False, "Reference backend",
     ["@NFAM@ families,", "@NPARAM@ parameterisations;", "@NREP@ replicates, one", "seed per artifact"]),
    ("co", 5.15, 1.40, 0.00, 2.60, False, "Corpus",
     ["@NART@", "artifacts"]),
    ("fe", 7.00, 1.90, 0.00, 2.60, False, "Feature table",
     ["@NDECL@ declared", "features,", "@NLIVE@ live"]),
    ("cs", 9.45, 4.30, 0.00, 1.10, False, "Closed-set evaluation",
     ["family and parameterisation labels;", "repeated grouped CV, domain holdout"]),
    ("os", 9.45, 4.30, -1.20, 1.40, False, "Open-set evaluation",
     ["configurations A, B, C; novel set:", "program-matched, program-overlapping", "or program $k$-fold"]),
    ("sc", 2.20, 4.35, -3.05, 1.00, True, "Semantic check",
     ["@NPRES@/@NART@ preserved (stdout and", "exit status; -O0 and -O2)"]),
    ("gt", 7.00, 6.75, -3.05, 1.00, True, "Validity gate (standalone check)",
     ["reads the feature table and writes a JSON report;",
      "checks 1, 1b, 2, 3, 6 model-free; 4, 5 fit probe models"]),
]
FIG1_EDGES = [
    # solid data flow
    r"\draw[flow] (in.east) -- (be.west);",
    r"\draw[flow] (be.east) -- (co.west);",
    r"\draw[flow] (co.east) -- (fe.west);",
    r"\draw[flow] (fe.east) -- ++(0.25,0) |- (cs.west);",
    r"\draw[flow] (fe.east) -- ++(0.25,0) |- (os.west);",
    # dashed side checks
    r"\draw[aux] (co.south) -- (co.south |- sc.north);",
    r"\draw[aux] (fe.south) -- (fe.south |- gt.north);",
]


def fig1_tex(nums: Dict[str, int]) -> str:
    def fmt(n: int) -> str:
        return str(n)

    out = [
        "% fig1-pipeline.tex -- written by scripts/manuscript_v3/make_figures.py; do not edit by hand.",
        "% Every count is read from result files and recorded in figures_provenance.json.",
        "% Use inside a figure environment: \\input{figures/fig1-pipeline}",
        "% Needs only \\usepackage{tikz} (no TikZ libraries). Width about 13.8 cm, below 5.47 in and the acmsmall \\linewidth (13.92 cm).",
        "\\begin{tikzpicture}[x=1cm,y=1cm,>=stealth,",
        "  stage/.style={draw=black!85,line width=0.45pt,rounded corners=1.2pt,align=center,",
        "                inner xsep=2pt,inner ysep=2pt,anchor=north west,font=\\scriptsize,",
        "                execute at begin node={\\hyphenpenalty=10000\\relax}},",
        "  check/.style={stage,dashed},",
        "  flow/.style={->,line width=0.55pt,black!85},",
        "  aux/.style={->,line width=0.45pt,dashed,black!85}]",
    ]
    for (nm, x, w, top, h, dashed, title, body) in FIG1_BOXES:
        tw = w - 4 * 0.0352778 - 0.02   # minus inner xsep (2 x 2 pt) and line width
        text = "{\\footnotesize\\bfseries " + title + "}\\\\" + "\\\\".join(body)
        out.append(f"\\node[{'check' if dashed else 'stage'},minimum width={w:.2f}cm,"
                   f"text width={tw:.3f}cm,minimum height={h:.2f}cm] ({nm}) at ({x:.2f},{top:.2f})")
        out.append("  {" + text + "};")
    out.extend(FIG1_EDGES)
    out.append("\\end{tikzpicture}%")
    tex = "\n".join(out) + "\n"
    for k, v in nums.items():
        tex = tex.replace(f"@{k}@", fmt(int(v)))
    left = re.findall(r"@[A-Z]+@", tex)
    if left:
        raise SystemExit(f"unfilled placeholders {left}")
    return tex


def fig1(out: Path, build_pdf: bool) -> Dict:
    name = "fig1-pipeline"
    sem0 = "results/v3/semantics/semantics_corpus_O0.json"
    sem2 = "results/v3/semantics/semantics_corpus_O2.json"
    live = "results/feature_set_live_counts.json"
    pos_src = "results/v3/sibling_position_heldout.json"
    os_src = "results/v3/openset_B_heldout.json"
    man = "results/v3/summary/manifest.json"
    nums = {}
    s0, s2 = load_json(sem0), load_json(sem2)
    for rel, s, flag in ((sem0, s0, "-O0"), (sem2, s2, "-O2")):
        if flag not in s["compiler"]["flags"] or "-std=c99" not in s["compiler"]["flags"]:
            raise SystemExit(f"{rel}: unexpected compiler flags")
        att = sum(v["attempted"] for v in s["per_parameterisation"].values())
        pres = sum(v["preserved"] for v in s["per_parameterisation"].values())
        nfail = len(s.get("failures", []))
        if att != pres or s["artifacts_found"] != att or nfail:
            raise SystemExit(f"{rel}: not every artifact preserved")
        PROV.add(name, "box: semantic check", f"preserved {flag}", "count", pres, rel,
                 "sum over per_parameterisation[*].preserved")
        PROV.add(name, "box: semantic check", f"attempted {flag}", "count", att, rel,
                 "sum over per_parameterisation[*].attempted")
        nums.setdefault("NPRES", pres)
        if nums["NPRES"] != pres:
            raise SystemExit("O0 and O2 preserved counts differ")
    nums["NART"] = s0["artifacts_found"]
    PROV.add(name, "box: corpus", "artifacts", "count", nums["NART"], sem0, "artifacts_found")
    nums["NPROG"] = s0["usable_programs"]
    PROV.add(name, "box: inputs", "programs", "count", nums["NPROG"], sem0, "usable_programs")
    osd = load_json(os_src)
    if osd["n_groups"] != nums["NPROG"] or osd["n_rows"] != nums["NART"]:
        raise SystemExit("program/artifact counts disagree with the open-set report")
    # suites: program-name prefixes of the 30 test groups of a repeated grouped-CV cell
    pg = "results/v3/closed/pg/provenance_grouped_cv_random_forest_all_s0.json"
    groups = sorted({g for f in load_json(pg)["per_fold"] for g in f["test_groups"]})
    if len(groups) != nums["NPROG"]:
        raise SystemExit("grouped-CV test groups do not cover the programs")
    suites: Dict[str, int] = {}
    for g in groups:
        suites[g.split("_")[0]] = suites.get(g.split("_")[0], 0) + 1
    if len(set(suites.values())) != 1:
        raise SystemExit(f"suites are unequal: {suites}")
    nums["NSUITE"] = len(suites)
    nums["PERSUITE"] = list(suites.values())[0]
    PROV.add(name, "box: inputs", "suites", "count", nums["NSUITE"], pg,
             "per_fold[*].test_groups", f"distinct program-name prefixes: {sorted(suites)}")
    PROV.add(name, "box: inputs", "programs per suite", "count", nums["PERSUITE"], pg,
             "per_fold[*].test_groups", "programs per prefix")
    lomfo = load_json("results/pilot5/provenance_lomfo_random_forest_all_s0.json")
    if len(lomfo["per_fold"]) != nums["NSUITE"]:
        raise SystemExit("domain-holdout fold count differs from suite count")
    pos = load_json(pos_src)["positions"]
    nums["NPARAM"] = len(pos)
    nums["NFAM"] = len({d["family"] for d in pos.values()})
    if set(pos) != set(s0["per_parameterisation"]):
        raise SystemExit("parameterisations differ between reports")
    PROV.add(name, "box: backend", "parameterisations", "count", nums["NPARAM"], pos_src,
             "positions (keys)")
    PROV.add(name, "box: backend", "families", "count", nums["NFAM"], pos_src,
             "positions[*].family (distinct)")
    per_param = {v["attempted"] for v in s0["per_parameterisation"].values()}
    if len(per_param) != 1:
        raise SystemExit("unequal artifacts per parameterisation")
    rep = list(per_param)[0] / nums["NPROG"]
    if rep != int(rep):
        raise SystemExit("non-integer replicate count")
    nums["NREP"] = int(rep)
    PROV.add(name, "box: backend", "replicates per program and parameterisation", "count",
             nums["NREP"], sem0, "per_parameterisation[*].attempted / usable_programs",
             f"{list(per_param)[0]} / {nums['NPROG']}")
    lc = load_json(live)["all"]
    nums["NDECL"], nums["NLIVE"] = lc["declared"], lc["live"]
    PROV.add(name, "box: features", "declared", "count", nums["NDECL"], live, "all.declared")
    PROV.add(name, "box: features", "live", "count", nums["NLIVE"], live, "all.live")
    mf = load_json(man)
    if sorted(mf["configs"]) != ["A", "B", "C"] or sorted(mf["variants"]) != ["all", "heldout", "kfold"]:
        raise SystemExit("open-set configurations/variants differ from the figure")
    PROV.add(name, "box: open-set", "configurations", "labels", sorted(mf["configs"]), man, "configs")
    PROV.add(name, "box: open-set", "novel-set protocols", "labels",
             {"heldout": "matched", "all": "overlapping", "kfold": "program k-fold"}, man, "variants")
    pga = load_json("results/v3/closed/pg_aggregate.json")
    if {c["n_seeds"] for c in pga["cells"]} != {5}:
        raise SystemExit("repeated grouped CV does not have 5 partitions")

    tex = fig1_tex(nums)
    (out / f"{name}.tex").write_text(tex, encoding="utf-8")
    info = {"files": [f"{name}.tex"], "numbers": nums}
    if build_pdf:
        info.update(build_fig1_pdf(out, name))
        for ext in ("pdf", "png"):
            if (out / f"{name}.{ext}").exists():
                info["files"].append(f"{name}.{ext}")
    PROV.meta(name, check=info, sources=[sem0, sem2, live, pos_src, os_src, man, pg])
    return info


SWIFT_RENDER = r"""import Foundation
import CoreGraphics
import ImageIO
import UniformTypeIdentifiers

let args = CommandLine.arguments
let inURL = URL(fileURLWithPath: args[1]) as CFURL
let outURL = URL(fileURLWithPath: args[2]) as CFURL
let dpi = Double(args[3]) ?? 300.0
guard let doc = CGPDFDocument(inURL), let page = doc.page(at: 1) else { exit(2) }
let box = page.getBoxRect(.mediaBox)
let scale = dpi / 72.0
let w = Int((box.width * scale).rounded()), h = Int((box.height * scale).rounded())
let cs = CGColorSpaceCreateDeviceRGB()
guard let ctx = CGContext(data: nil, width: w, height: h, bitsPerComponent: 8, bytesPerRow: 0,
                          space: cs, bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue) else { exit(3) }
ctx.setFillColor(CGColor(red: 1, green: 1, blue: 1, alpha: 1))
ctx.fill(CGRect(x: 0, y: 0, width: w, height: h))
ctx.scaleBy(x: CGFloat(scale), y: CGFloat(scale))
ctx.translateBy(x: -box.origin.x, y: -box.origin.y)
ctx.drawPDFPage(page)
guard let img = ctx.makeImage(),
      let dest = CGImageDestinationCreateWithURL(outURL, UTType.png.identifier as CFString, 1, nil) else { exit(4) }
let props = [kCGImagePropertyDPIWidth: dpi, kCGImagePropertyDPIHeight: dpi] as CFDictionary
CGImageDestinationAddImage(dest, img, props)
if !CGImageDestinationFinalize(dest) { exit(5) }
print("\(w)x\(h)")
"""


def build_fig1_pdf(out: Path, name: str) -> Dict:
    tectonic = shutil.which("tectonic") or "/opt/homebrew/bin/tectonic"
    if not Path(tectonic).exists():
        return {"pdf": "not built (tectonic not found)"}
    res = {}
    with tempfile.TemporaryDirectory() as td:
        tdp = Path(td)
        shutil.copy(out / f"{name}.tex", tdp / f"{name}.tex")
        # 1) inside acmart (acmsmall): must fit \linewidth without overfull boxes
        (tdp / "acm.tex").write_text(
            "\\documentclass[acmsmall,screen,review,anonymous]{acmart}\n"
            "\\usepackage{tikz}\n\\begin{document}\n"
            "\\begin{figure}\\centering\n"
            "\\sbox0{\\input{" + name + "}}\\typeout{FIGWIDTH=\\the\\wd0}"
            "\\typeout{FIGHEIGHT=\\the\\ht0}\\typeout{LINEWIDTH=\\the\\linewidth}\n"
            "\\input{" + name + "}\\caption{Test}\\Description{Test}\\end{figure}\n"
            "\\makeatletter{\\scriptsize\\typeout{SCRIPTSIZE=\\f@size pt}}"
            "{\\footnotesize\\typeout{FOOTNOTESIZE=\\f@size pt}}\\makeatother\n"
            "\\end{document}\n", encoding="utf-8")
        p = subprocess.run([tectonic, "--print", "acm.tex"], cwd=td,
                           capture_output=True, text=True)
        log = p.stdout + "\n" + p.stderr
        if p.returncode != 0:
            raise SystemExit("fig1 does not compile in acmart:\n" + p.stderr[-3000:])
        fw = re.search(r"FIGWIDTH=([\d.]+)pt", log)
        lw = re.search(r"LINEWIDTH=([\d.]+)pt", log)
        fh = re.search(r"FIGHEIGHT=([\d.]+)pt", log)
        if not (fw and lw):
            raise SystemExit("could not measure fig1 width")
        res["acmart_figure_width_pt"] = float(fw.group(1))
        res["acmart_figure_height_pt"] = float(fh.group(1)) if fh else None
        res["acmart_linewidth_pt"] = float(lw.group(1))
        res["acmart_overfull_hbox"] = "Overfull \\hbox" in log
        if res["acmart_overfull_hbox"]:
            raise SystemExit("fig1: overfull \\hbox (text does not fit a box)")
        if res["acmart_figure_width_pt"] > FULL_W * 72.0:
            raise SystemExit(f"fig1 wider than {FULL_W} in: {res}")
        sz = re.search(r"SCRIPTSIZE=([\d.]+)pt", log)
        fz = re.search(r"FOOTNOTESIZE=([\d.]+)pt", log)
        res["acmart_scriptsize_pt"] = float(sz.group(1)) if sz else None
        res["acmart_footnotesize_pt"] = float(fz.group(1)) if fz else None
        if not sz or float(sz.group(1)) < MIN_PT:
            raise SystemExit(f"fig1: \\scriptsize is not >= {MIN_PT} pt in acmart: {res}")
        # 2) standalone PDF at exactly 5.47 in, Libertine as in acmart
        (tdp / "sa.tex").write_text(
            "\\documentclass[10pt,border=0pt]{standalone}\n"
            "\\usepackage{libertine}\n\\usepackage{tikz}\n\\begin{document}\n"
            "\\makebox[" + f"{FULL_W}in" + "][c]{\\input{" + name + "}}\n"
            "\\end{document}\n", encoding="utf-8")
        env = dict(os.environ, SOURCE_DATE_EPOCH="1700000000")
        p = subprocess.run([tectonic, "-Z", "deterministic-mode", "sa.tex"], cwd=td,
                           capture_output=True, text=True, env=env)
        if p.returncode != 0:
            raise SystemExit("fig1 standalone build failed:\n" + p.stderr[-3000:])
        shutil.copy(tdp / "sa.pdf", out / f"{name}.pdf")
        # 300-dpi PNG preview, rendered with CoreGraphics through a small Swift
        # program (macOS); skipped where swift is not available.
        sw = shutil.which("swift")
        if sw:
            (tdp / "render.swift").write_text(SWIFT_RENDER, encoding="utf-8")
            q = subprocess.run([sw, str(tdp / "render.swift"), str(tdp / "sa.pdf"),
                                str(tdp / "sa.png"), "300"], capture_output=True, text=True)
            if q.returncode == 0 and (tdp / "sa.png").exists():
                shutil.copy(tdp / "sa.png", out / f"{name}.png")
                res["png"] = f"{name}.png ({q.stdout.strip()} px, 300 dpi, CoreGraphics via swift)"
            else:
                res["png"] = "not rendered (swift failed: " + q.stderr[-300:] + ")"
    raw = (out / f"{name}.pdf").read_bytes()
    m = pdf_search(raw, _MB)
    if m:
        x0, y0, x1, y1 = (float(v) for v in m.groups())
        res["pdf_width_in"] = round((x1 - x0) / 72.0, 4)
        res["pdf_height_in"] = round((y1 - y0) / 72.0, 4)
    res["min_font_pt"] = 7.0
    res["font_note"] = ("\\scriptsize (7 pt) for detail lines and \\footnotesize (8 pt) bold for "
                        "stage names, in a 10 pt class (acmsmall and standalone)")
    return res


# ======================================================================= driver
def write_outputs(out: Path, infos: Dict[str, Dict]) -> None:
    prov = {
        "generated_by": "scripts/manuscript_v3/make_figures.py",
        "environment": {"python": sys.version.split()[0], "matplotlib": matplotlib.__version__,
                        "numpy": np.__version__, "font": FONT},
        "conventions": {
            "paths": "source paths are relative to the repository root (obfuscope-corrected)",
            "json_path": "dotted keys and [index]; for CSV sources: row index (0-based, header excluded) and column",
            "estimator_colours": EST_COLOR, "estimator_markers": EST_MARKER,
            "estimator_order": EST_ORDER,
        },
        "source_sha256": dict(sorted(SOURCES.items())),
        "figures": PROV.figs,
    }
    (out / "figures_provenance.json").write_text(json.dumps(prov, indent=1, default=float) + "\n",
                                                encoding="utf-8")
    lines = []
    lines.append("Article figures (generated; do not edit by hand)")
    lines.append("=" * 48)
    lines.append("Generator : code/obfuscope-corrected/scripts/manuscript_v3/make_figures.py")
    lines.append(f"Run with  : Python {sys.version.split()[0]}, matplotlib {matplotlib.__version__}, "
                 f"numpy {np.__version__}; font {FONT} (TrueType, embedded as Type 42)")
    lines.append("Inputs    : only result files under results/ and results/v3/ (see "
                 "figures_provenance.json for every value, its file, JSON path and the file SHA-256)")
    lines.append("Width     : 5.47 in (acmsmall \\textwidth = 395.82 pt = 5.477 in); include with "
                 "\\includegraphics[width=\\linewidth]{figures/<name>.pdf} (scale 1.001) or at natural size")
    lines.append("Text      : every text object >= 7.0 pt at the stated width (checked before saving); "
                 "no titles inside figures; panel letters (a), (b) at 8 pt bold")
    lines.append("Colour    : estimator colours/markers fixed across figures (Okabe-Ito; mlp = #882255):")
    for m in EST_ORDER:
        lines.append(f"            {m:14s} {EST_COLOR[m]}  marker '{EST_MARKER[m]}'")
    lines.append("            matched = filled marker, overlapping = hollow marker (Fig. 3b, Fig. 4); "
                 "chance/0.5 reference = grey dashed line")
    lines.append("")
    desc = {
        "fig1-pipeline": (
            "Pipeline. Inputs -> reference backend -> corpus -> features -> closed-set and open-set "
            "evaluation; the semantic check and the validity gate are drawn as dashed side checks: the "
            "gate is a standalone program that reads the feature table and writes a JSON report (it is "
            "not a build stage and does not stop anything). \\input{figures/fig1-pipeline} needs "
            "\\usepackage{tikz}; fig1-pipeline.pdf is the same picture compiled standalone (Libertine)."),
        "fig2-gate-specificity": (
            "Gate on 21 constructed feature tables (7 families x seed index 0-2). Squares: checks that "
            "fired (results/gate_specificity.json per_run[*].checks_fired). Circles: verdict under policy "
            "(i) every failure disqualifies and (ii) diagnostic 4 (4 and 4b) advisory; filled = gate fails, "
            "hollow = passes; vermillion with a square frame = verdict contradicts the table's known status "
            "(hard_but_honest seed index 0 under (i); leaked_id seeds 0-2 under (ii)); '\u2260' marks rows "
            "where the policies disagree. Checks 1, 2 and 5 never fired."),
        "fig3-openset": (
            "(a) MSP AUROC per fold under the program-matched protocol for configurations A (family label, "
            "family held out), B (parameterisation label, parameterisation held out) and C "
            "(parameterisation label, family held out); bar = mean over folds (A, C: 20 folds; B: 50); "
            "dashed line = 0.5; horizontal jitter only (seed fixed). (b) Configuration B AUROC (mean "
            "over folds) of the six scorers under program-overlapping (hollow), program-matched (filled) "
            "and program k-fold (vertical tick); energy and OpenMax only for estimators with class "
            "scores; evt_posterior excluded; model-free scorers do not depend on the estimator."),
        "fig4-sibling-axis": (
            "Configuration B MSP AUROC of each held-out parameterisation (numbered; key on the right with "
            "|PC1 projection| on its family's sibling axis) under the program-matched (filled) and "
            "program-overlapping (hollow) protocols, grouped by position class; diamonds = position-class "
            "mean +/- 1 sd over folds (filled matched, hollow overlapping). Each point pools 6 estimators "
            "x 5 seeds (30 folds). Interior parameterisations are per-site mixtures of their end siblings "
            "by construction."),
        "fig5-simulation": (
            "Simulation, 20 seeds, sibling spread 0.25-4 (8.0 omitted: 1 - max posterior saturates in "
            "float64). (a) Exact-posterior MSP AUROC when the end, the interior or the whole family is "
            "held out (each condition removes one sibling per family, four novel classes, at once); "
            "solid/filled = ordered sibling layout, dashed/hollow = random-offset layout; bands = t-based "
            "95% intervals of the mean. (b) Retained-class accuracy under family holdout of the exact "
            "Bayes classifier and of a fitted random forest."),
        "fig6-closed-set": (
            "Closed-set macro F1 per estimator: (a) family label, repeated grouped CV over 5 permuted "
            "program partitions (circle) and domain holdout over 5 suites (square); (b) parameterisation "
            "label, domain holdout. Marker = mean of 25 per-fold values (5 folds x 5 seeds); line = "
            "min-max of the same 25 values; dashed line = chance macro F1 (0.25, 0.10) from the gate "
            "reports. No ranking is implied."),
    }
    alt = {
        "fig1-pipeline": (
            "Flow diagram of five boxes from left to right: input programs, reference backend, "
            "corpus, feature table, and a pair of evaluation boxes (closed set above, open set below). "
            "Two dashed boxes hang below: a semantic check fed by the corpus and a standalone validity "
            "gate that reads the feature table and writes a report."),
        "fig2-gate-specificity": (
            "Grid with seven constructed table families as rows and eight gate checks as columns, "
            "three markers per cell for seed indices 0 to 2. Each degenerate family triggers one "
            "diagnostic (leaked_id: 4 and 4b; seed_jitter_only: 1b; duplicated_rows: 3; "
            "ambiguous_labels: 6); the sound families trigger nothing except a headroom (4b) failure "
            "for hard_but_honest at seed index 0. Two verdict columns show that this instance is "
            "wrongly failed under the every-failure policy, and that the leaked_id tables are wrongly "
            "passed when diagnostic 4 is advisory."),
        "fig3-openset": (
            "Top: strip plots of per-fold MSP AUROC for six estimators under configurations A, B "
            "and C; the configuration B mean lies below the 0.5 line for every estimator, and the A "
            "and C means lie above the B mean for every estimator. Bottom: dot plot of configuration "
            "B AUROC for fifteen scorer and estimator combinations under three protocols; the "
            "program-overlapping value lies left of the program-matched value in 14 of the 15 rows "
            "(not energy with logreg), with the largest shifts for the kNN-distance and Mahalanobis "
            "scorers."),
        "fig4-sibling-axis": (
            "Dot plot of MSP AUROC for ten numbered held-out parameterisations grouped into end, "
            "interior and end-of-pair positions, with matched (filled) and overlapping (hollow) "
            "markers joined by lines and a mean with an error bar per group. The end group has the "
            "lowest mean under both protocols; a key lists each number's parameterisation and its "
            "absolute projection."),
        "fig5-simulation": (
            "Two line charts against sibling spread on a logarithmic axis. Left: under the ordered "
            "layout the exact-posterior AUROC falls towards zero when an end is held out and rises "
            "when the interior is held out; under the random layout the end and interior curves "
            "coincide and rise; with the whole family held out the AUROC stays below 0.5 up to "
            "spread 2 in both layouts. Right: retained-class accuracy of the exact Bayes classifier "
            "and of a fitted random forest rises with spread in both layouts."),
        "fig6-closed-set": (
            "Two range plots of macro F1 for seven estimators. Left, family label: two ranges per "
            "estimator (repeated grouped CV and domain holdout), all far above the chance line. "
            "Right, parameterisation label: one domain-holdout range per estimator, with means below "
            "the family means and all values above chance. The ranges of the strongest estimators "
            "overlap."),
    }
    lines.append("Checks run by the generator (it stops on any failure)")
    lines.append("  - figure width equals 5.47 in before saving and the PDF MediaBox width equals 5.47 in after")
    lines.append("  - every visible matplotlib Text object >= 7.0 pt (inspected before saving)")
    lines.append("  - no two text bounding boxes overlap; no text outside the canvas")
    lines.append("  - no plotted point lies inside a legend box")
    lines.append("  - PDFs embed TrueType font programs and contain no Type 3 fonts")
    lines.append("  - recomputed means/ranges equal the summaries written by the analysis code "
                 "(summary JSON, table14/15/16, grid.csv, table18_v3.csv, pg_aggregate, agg_committed_*)")
    lines.append("  - fig1: compiles inside acmart (acmsmall, review, anonymous) with tectonic, no overfull "
                 "box, width <= 5.47 in, \\scriptsize = 7 pt there")
    lines.append("  - regeneration is byte-identical (PDF CreationDate removed; tectonic deterministic mode)")
    lines.append("")
    for name in ["fig1-pipeline", "fig2-gate-specificity", "fig3-openset", "fig4-sibling-axis",
                 "fig5-simulation", "fig6-closed-set"]:
        info = infos.get(name, {})
        lines.append(name)
        lines.append("-" * len(name))
        files = info.get("files", [])
        lines.append("  files     : " + ", ".join(files))
        if name == "fig1-pipeline":
            if "acmart_figure_width_pt" in info:
                lines.append(f"  size      : {info['acmart_figure_width_pt']:.2f} pt wide x "
                             f"{info['acmart_figure_height_pt']:.2f} pt high inside acmart "
                             f"(\\linewidth {info['acmart_linewidth_pt']:.2f} pt); standalone PDF "
                             f"{info.get('pdf_width_in')} x {info.get('pdf_height_in')} in")
            lines.append("  min font  : 7 pt (\\scriptsize in a 10 pt class); stage names 8 pt bold")
            lines.append("  numbers   : " + ", ".join(f"{k}={v}" for k, v in info.get("numbers", {}).items()))
        else:
            lines.append(f"  size      : {info['width_in']} x {info['height_in']} in "
                         f"(PDF MediaBox {info['pdf_width_in']} x {info['pdf_height_in']} in)")
            lines.append(f"  min font  : {info['min_font_pt']:.1f} pt (max {info['max_font_pt']:.1f} pt, "
                         f"{info['n_texts']} text objects)")
            lines.append(f"  fonts     : {', '.join(info['base_fonts'])} (embedded, no Type 3)")
        lines.append(f"  values    : {len(PROV.figs.get(name, {}).get('values', []))} recorded in "
                     "figures_provenance.json")
        srcs = PROV.figs.get(name, {}).get("sources")
        if srcs:
            lines.append("  sources   : " + "; ".join(srcs))
        lines.append("  content   : " + desc[name])
        lines.append("  alt text  : " + alt[name] + " (suggested \\Description; verify against the final caption)")
        lines.append("")
    (out / "MANIFEST.txt").write_text("\n".join(lines) + "\n", encoding="utf-8")


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--out", type=Path, default=DEFAULT_OUT)
    ap.add_argument("--no-tectonic", action="store_true",
                    help="write fig1-pipeline.tex but do not compile it")
    ap.add_argument("--only", nargs="*", default=None)
    args = ap.parse_args(argv)
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    infos: Dict[str, Dict] = {}
    todo = {"fig1-pipeline": lambda: fig1(out, not args.no_tectonic),
            "fig2-gate-specificity": lambda: fig2(out),
            "fig3-openset": lambda: fig3(out),
            "fig4-sibling-axis": lambda: fig4(out),
            "fig5-simulation": lambda: fig5(out),
            "fig6-closed-set": lambda: fig6(out)}
    for name, fn in todo.items():
        if args.only and name not in args.only:
            continue
        infos[name] = fn()
        i = infos[name]
        if name == "fig1-pipeline":
            print(f"{name}: {i.get('acmart_figure_width_pt', '?')} pt in acmart "
                  f"(linewidth {i.get('acmart_linewidth_pt', '?')}), PDF {i.get('pdf_width_in', '?')} in")
        else:
            print(f"{name}: {i['width_in']} x {i['height_in']} in, min font {i['min_font_pt']} pt, "
                  f"PDF {i['pdf_width_in']} in, fonts {i['base_fonts']}")
    if not args.only:
        write_outputs(out, infos)
    return 0


if __name__ == "__main__":
    sys.exit(main())
