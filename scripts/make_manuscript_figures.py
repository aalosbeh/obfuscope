"""Generate the manuscript figures from the manuscript's own tables.

Design constraint, and the reason this script is shaped the way it is: no number
is typed into this file. Every plotted value is parsed out of a pipe table in
``docs/ObfuScope_manuscript_revised_2.md``, identified by its table number, and
recorded in a JSON sidecar next to the figures together with the table, row and
column it came from. ``scripts/figcheck.py`` then re-parses the manuscript
independently and asserts that every value in the sidecar still matches the cell
it claims to come from. A figure can therefore disagree with the manuscript only
if the manuscript changed, and the check will say which cell moved.

The one figure that is not data driven is Figure 1, the pipeline schematic. Its
box labels are still derived from the tables (artifact counts, feature counts,
protocol counts) rather than written in, for the same reason.

Usage
-----
    python3 scripts/make_manuscript_figures.py

Writes ``docs/figures/figN_*.pdf``, ``docs/figures/figN_*.png`` and
``docs/figures/plotted_values.json``.
"""
from __future__ import annotations

import hashlib
import json
import os
import re
import sys

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt
import matplotlib.lines as mlines
import matplotlib.patches as mpatches
from matplotlib.legend_handler import HandlerTuple
from matplotlib.transforms import Bbox
from matplotlib.lines import Line2D
from matplotlib.patches import FancyArrowPatch, FancyBboxPatch

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
MD = os.path.join(ROOT, "docs", "ObfuScope_manuscript_revised_2.md")
OUT = os.path.join(ROOT, "docs", "figures")

# 6.0 in is the usable text width of the manuscript page and of acmart's
# `manuscript` class option (432 pt against a 428 pt \textwidth, so LaTeX
# scales by 0.99). Smallest text in the data figures is FS_ANNOT at 6.8 pt,
# printing at 6.73 pt; smallest anywhere is 6.2 pt inside the Figure 1 boxes,
# printing at 6.14 pt. Both clear the ACM 6 pt floor, but only just, so these
# figures must be regenerated rather than scaled down if the class option
# changes to one with a narrower \textwidth.
WIDTH = 6.0
FS_TICK = 7.0
FS_LABEL = 8.0
FS_TITLE = 8.5
FS_ANNOT = 6.8

INK = "#1a1a1a"
GRID = "#d9d9d9"
# Colour is never the only channel: every encoding below is also carried by
# position, hatch or marker, so the figures survive greyscale printing.
C_FAR = "#2f6f9f"
C_NEAR = "#c2452d"
C_THIRD = "#5a9367"
C_MUTED = "#8c8c8c"
C_BAND = "#f2dede"

plt.rcParams.update({
    "font.family": "DejaVu Sans",
    "font.size": FS_TICK,
    "axes.edgecolor": INK,
    "axes.labelcolor": INK,
    "text.color": INK,
    "xtick.color": INK,
    "ytick.color": INK,
    "axes.linewidth": 0.6,
    "xtick.major.width": 0.6,
    "ytick.major.width": 0.6,
    "figure.facecolor": "white",
    "axes.facecolor": "white",
    "savefig.facecolor": "white",
    "pdf.fonttype": 42,
})

# --------------------------------------------------------------------------
# manuscript table parsing
# --------------------------------------------------------------------------

_CAPTION = re.compile(r"^\*\*Table (\d+)\.\s*(.*?)\*\*\s*$")


def _cells(line: str) -> list[str]:
    s = line.strip()
    if s.startswith("|"):
        s = s[1:]
    if s.endswith("|"):
        s = s[:-1]
    return [c.strip() for c in s.split("|")]


def _is_rule(line: str) -> bool:
    cs = _cells(line)
    return bool(cs) and all(re.fullmatch(r":?-{2,}:?", c or "") for c in cs)


def load_tables(path: str) -> dict:
    """Return {number: {"caption", "header", "rows"}} for every pipe table."""
    lines = open(path, encoding="utf-8").read().split("\n")
    out: dict[int, dict] = {}
    i = 0
    while i < len(lines):
        m = _CAPTION.match(lines[i])
        if not m:
            i += 1
            continue
        num, caption = int(m.group(1)), m.group(2)
        j = i + 1
        while j < len(lines) and not lines[j].lstrip().startswith("|"):
            if lines[j].strip():          # prose intervened: not this table's
                break
            j += 1
        if j >= len(lines) or not lines[j].lstrip().startswith("|"):
            i += 1
            continue
        block = []
        while j < len(lines) and lines[j].lstrip().startswith("|"):
            if not _is_rule(lines[j]):
                block.append(_cells(lines[j]))
            j += 1
        if num in out:
            sys.exit("duplicate Table %d caption in %s" % (num, path))
        out[num] = {"caption": caption, "header": block[0], "rows": block[1:]}
        i = j
    return out


TABLES = load_tables(MD)

# Every value handed to matplotlib passes through record(), which is what makes
# the sidecar complete by construction rather than by my remembering to log.
PROV: list[dict] = []


def _strip(s: str) -> str:
    return s.replace("`", "").replace("**", "").strip()


def col(table: int, name: str) -> int:
    """Resolve a column name to an index, refusing to guess.

    A duplicated column name is a hard error rather than a silent first match.
    The provenance sidecar records the column by name, so a name that matches
    two columns records a value that cannot afterwards be traced to the cell it
    came from: that is how Table 19's two protocols, which both once carried a
    bare ``fold sd``, escaped verification until figcheck.py compared them.
    """
    hdr = [_strip(h) for h in TABLES[table]["header"]]
    want = _strip(name)
    if want not in hdr:
        sys.exit("Table %d has no column %r; has %r" % (table, want, hdr))
    if hdr.count(want) > 1:
        sys.exit("Table %d has %d columns named %r, so a value recorded "
                 "against that name could not be traced back to one cell; "
                 "give the columns distinct names in the manuscript"
                 % (table, hdr.count(want), want))
    return hdr.index(want)


def cell(table: int, row: int, column: str) -> str:
    return TABLES[table]["rows"][row][col(table, column)]


def rowkey(table: int, row: int) -> str:
    return _strip(TABLES[table]["rows"][row][0])


def num(table: int, row: int, column: str, *, pick: int = 0) -> float:
    """Parse the pick-th number out of a cell and record its provenance.

    Cells in these tables are not always bare numbers: ``0.3780 +/- 0.3661``
    carries two, ``0.9181, 1.0000`` carries a min and a max, and ``3.0836 below
    centre`` carries a magnitude plus a direction word that fixes its sign.
    """
    raw = cell(table, row, column)
    found = re.findall(r"-?\d+(?:\.\d+)?", raw.replace("%", ""))
    if len(found) <= pick:
        sys.exit("Table %d row %r col %r: no number #%d in %r"
                 % (table, rowkey(table, row), column, pick, raw))
    v = float(found[pick])
    if "below centre" in raw:
        v = -v
    PROV.append({"table": table, "row": rowkey(table, row), "column": column,
                 "pick": pick, "raw": raw, "value": v})
    return v


def nrows(table: int) -> int:
    return len(TABLES[table]["rows"])


def table_digest(table: int) -> str:
    """Digest a whole source table, so a change anywhere in it is detectable.

    Comparing each plotted value against its cell catches an edited number, but
    not a row added to a table, which leaves every recorded value correct while
    making the figure an incomplete picture of it. The digest covers the header
    and every row, so that case is caught too.

    The canonical form is deliberately simple, cells stripped of markdown
    emphasis and joined with a pipe, rows joined with a newline, because
    figcheck.py reimplements it against its own parse. Two parsers that
    disagree about what a table contains will produce different digests, which
    is the independence check doing its job rather than a false alarm.
    """
    t = TABLES[table]
    canon = "\n".join("|".join(_strip(c) for c in row)
                       for row in [t["header"]] + t["rows"])
    return hashlib.sha256(canon.encode("utf-8")).hexdigest()[:16]


def save(fig, stem: str) -> None:
    os.makedirs(OUT, exist_ok=True)
    for ext, dpi in (("pdf", None), ("png", 400)):
        kw = {"dpi": dpi} if dpi else {}
        fig.savefig(os.path.join(OUT, "%s.%s" % (stem, ext)),
                    bbox_inches="tight", pad_inches=0.02, **kw)
    plt.close(fig)
    print("  wrote figures/%s.pdf and .png" % stem)


def tidy(ax, *, grid_axis="y") -> None:
    ax.spines["top"].set_visible(False)
    ax.spines["right"].set_visible(False)
    ax.grid(True, axis=grid_axis, color=GRID, linewidth=0.5, zorder=0)
    ax.set_axisbelow(True)
    ax.tick_params(labelsize=FS_TICK, length=2.5)


# Candidate label offsets in points, tried in order. The first six keep the
# label close to its marker; the rest step further out for crowded regions.
_OFFSETS = [(0, 7), (0, -11), (9, 3), (-9, 3), (9, -5), (-9, -5),
            (0, 15), (0, -19), (14, 10), (-14, 10), (14, -12), (-14, -12),
            (0, 23), (0, -27), (20, 17), (-20, 17)]


def declutter(fig, ax, annots, points, *, marker_pt=7.5, hlines=()) -> None:
    """Move each annotation to the first offset that collides with nothing.

    Matplotlib has no label placement pass, so a scatter with ten named points
    overprints itself wherever two points are close. This measures the real
    rendered extent of every label through the renderer and greedily assigns
    each one the nearest candidate offset that overlaps neither an already
    placed label, nor a data marker, nor a reference line. It is
    deterministic: the same input always yields the same layout.

    ``points`` are the data space marker centres. They are passed explicitly
    because ``PathCollection.get_window_extent`` returns a null bbox, so the
    markers cannot be recovered from the axes after the fact.

    ``hlines`` takes data space y values of reference lines, such as a chance
    line, which are reserved as thin bands so no label is printed across one.
    """
    fig.canvas.draw()
    rend = fig.canvas.get_renderer()
    half = marker_pt / 2.0 * fig.dpi / 72.0
    taken = []
    for x, y in points:
        px, py = ax.transData.transform((x, y))
        taken.append(Bbox.from_extents(px - half, py - half,
                                       px + half, py + half))
    axbb = ax.get_window_extent(rend)
    for y in hlines:
        ypx = ax.transData.transform((0.0, y))[1]
        taken.append(Bbox.from_extents(axbb.x0, ypx - 3.5,
                                       axbb.x1, ypx + 3.5))
    inside = axbb.expanded(0.995, 0.995)
    placed = []
    for a, (x, y) in zip(annots, points):
        best = None
        for dx, dy in _OFFSETS:
            a.set_position((dx, dy))
            bb = a.get_window_extent(rend).expanded(1.06, 1.30)
            if bb.x0 < inside.x0 or bb.x1 > inside.x1:
                continue                     # would run off the panel
            if bb.y0 < inside.y0 or bb.y1 > inside.y1:
                continue
            if not any(bb.overlaps(t) for t in taken):
                best = (dx, dy, bb)
                break
        if best is None:                     # nothing clear; keep the default
            a.set_position(_OFFSETS[0])
            bb = a.get_window_extent(rend)
        else:
            a.set_position(best[:2])
            bb = best[2]
        taken.append(bb)
        placed.append((a, bb, ax.transData.transform((x, y))))

    # A label pushed clear of the crowd is no longer obviously attached to its
    # marker, so draw a hairline from the marker to the nearest edge of the
    # label. Short hops are left bare; a leader there would be noise.
    inv = ax.transData.inverted()
    for a, bb, (mx, my) in placed:
        tx = min(max(mx, bb.x0), bb.x1)
        ty = min(max(my, bb.y0), bb.y1)
        d = ((tx - mx) ** 2 + (ty - my) ** 2) ** 0.5
        if d <= half + 2.0:
            continue
        ux, uy = (tx - mx) / d, (ty - my) / d
        p0 = inv.transform((mx + ux * (half - 0.5), my + uy * (half - 0.5)))
        p1 = inv.transform((tx - ux * 1.0, ty - uy * 1.0))
        ax.plot([p0[0], p1[0]], [p0[1], p1[1]], color=C_MUTED,
                linewidth=0.45, zorder=2, solid_capstyle="butt")


# --------------------------------------------------------------------------
# Figure 1: the gate as a build stage
# --------------------------------------------------------------------------

def fig1_pipeline() -> None:
    """Schematic of the build and evaluation pipeline.

    Counts in the labels come from Tables 5, 6, 8, 9, 11, 12 and 13 so that the
    figure cannot drift from the text. The stage ordering is the claim: the gate
    sits between feature extraction and model fitting, and a disqualifying
    failure stops the build (Section 4.6).
    """
    n_suites = nrows(5)
    n_programs = sum(int(num(5, r, "Programs")) for r in range(n_suites))
    n_param = nrows(6)
    n_family = len({_strip(TABLES[6]["rows"][r][col(6, "Family")])
                    for r in range(n_param)})
    n_artifacts = int(num(8, 0, "Artifacts"))
    preservation = cell(8, 0, "Preservation")
    total = nrows(9) - 1                       # last row of Table 9 is the total
    n_declared = int(num(9, total, "Declared"))
    n_live = int(num(9, total, "Live"))
    n_protocols = sum(1 for r in range(nrows(11))
                      if _strip(cell(11, r, "Run here")).startswith("yes"))
    n_config = nrows(12)
    n_scorers = nrows(13)

    n_est_closed = nrows(19)
    n_est_open = nrows(14)

    fig, ax = plt.subplots(figsize=(WIDTH, 4.0))
    ax.set_xlim(0, 100)
    ax.set_ylim(-2, 100)
    ax.axis("off")

    FS_BOX = 6.2
    FS_BOXTITLE = 6.3

    # Every label is checked against its own box at the end of the function.
    # Hand checking a schematic by looking at it is how the first draft of this
    # figure shipped with two labels overhanging their borders.
    boxed: list[tuple] = []

    def box(x, y, w, h, title, body, face="#ffffff", edge=INK, lw=0.8,
            tsize=FS_BOXTITLE):
        ax.add_patch(FancyBboxPatch(
            (x, y), w, h, boxstyle="round,pad=0.0,rounding_size=1.4",
            linewidth=lw, edgecolor=edge, facecolor=face, zorder=2))
        t = ax.text(x + w / 2, y + h - 2.4, title, ha="center", va="top",
                    fontsize=tsize, fontweight="bold", zorder=3)
        b = ax.text(x + w / 2, y + h - 7.4, body, ha="center", va="top",
                    fontsize=FS_BOX, linespacing=1.5, zorder=3)
        boxed.append((title, (x, y, w, h), t, b))

    def arrow(x0, y0, x1, y1, style="-|>", color=INK, lw=0.8, ls="-"):
        ax.add_patch(FancyArrowPatch(
            (x0, y0), (x1, y1), arrowstyle=style, mutation_scale=7,
            linewidth=lw, color=color, linestyle=ls,
            shrinkA=0, shrinkB=0, zorder=4))

    # ---- row 1: corpus build. Four stages, equal width, 2.5 unit gaps.
    W1, G = 23.5, 2.0
    xs = [0.0, W1 + G, 2 * (W1 + G), 3 * (W1 + G)]
    Y1, H1 = 66, 30
    box(xs[0], Y1, W1, H1, "1  Input programs",
        "%d benign C programs,\n%d suites of %d\n(Table 5)"
        % (n_programs, n_suites, n_programs // n_suites))
    box(xs[1], Y1, W1, H1, "2  Reference backend",
        "%d families at\n%d parameterisations,\nper artifact seeding\n(Table 6)"
        % (n_family, n_param))
    box(xs[2], Y1, W1, H1, "3  Semantics check",
        "all %d artifacts\ncompiled and run\nagainst the original\n%s preserved\n(Table 8)"
        % (n_artifacts, preservation))
    box(xs[3], Y1, W1, H1, "4  Feature extraction",
        "%d declared static\nfeatures, of which\n%d are alive\n(Table 9)"
        % (n_declared, n_live))
    for k in range(3):
        arrow(xs[k] + W1 + 0.2, Y1 + H1 / 2, xs[k + 1] - 0.2, Y1 + H1 / 2)

    # ---- row 2: the gate. Drawn wide and shaded because the claim of
    # Section 4.6 is positional: it sits here, before any model is fitted.
    Y2, H2, X2, W2 = 32, 28, 16, 68
    box(X2, Y2, W2, H2,
        "5  Corpus validity gate, run before any model is fitted",
        "six diagnostics over one feature table and one label (Table 1)\n"
        "machine readable verdict naming the cause of each failure\n"
        "a disqualifying failure stops the build, leaving no feature table\n"
        "an advisory failure is recorded as an accepted exception in the\n"
        "report of record, and no threshold is moved to make it pass",
        face="#eef2f7", lw=1.2, tsize=FS_BOXTITLE)
    arrow(xs[3] + W1 / 2, Y1 - 0.2, X2 + W2 - 6, Y2 + H2 + 0.2,
          ls=(0, (2.5, 1.5)))
    ax.text(X2 + W2 + 1.5, (Y1 + Y2 + H2) / 2 + 1, "feature\ntable",
            fontsize=FS_BOX, va="center", ha="left")

    # the refusal edge is what separates a build stage from an analysis script
    arrow(X2 - 0.2, Y2 + H2 / 2, 13.5, Y2 + H2 / 2, color=C_NEAR)
    ax.text(13.0, Y2 + H2 / 2, "build\nstops", fontsize=FS_BOX, ha="right",
            va="center", color=C_NEAR, fontweight="bold")
    # ---- row 3: evaluation
    Y3, H3 = 2, 22
    box(2, Y3, 45, H3, "6  Closed set attribution",
        "%d grouped protocols (Table 11)\n"
        "two label granularities, %d estimators, 5 seeds\n"
        "fold and estimator spread reported separately"
        % (n_protocols, n_est_closed))
    box(53, Y3, 45, H3, "7  Open set recognition",
        "%d configurations differing only in holdout unit\n"
        "and label granularity (Table 12)\n%d novelty scorers (Table 13), %d estimators"
        % (n_config, n_scorers, n_est_open))
    arrow(45, Y2 - 7.5, 24.5, Y3 + H3 + 0.2)
    arrow(55, Y2 - 7.5, 75.5, Y3 + H3 + 0.2)
    ax.plot([45, 55], [Y2 - 7.5, Y2 - 7.5], color=INK, linewidth=0.8, zorder=4)
    arrow(50, Y2 - 0.2, 50, Y2 - 7.5, style="-")

    # ---- does every label actually fit inside the box it belongs to?
    fig.canvas.draw()
    rend = fig.canvas.get_renderer()
    bad = []
    for title, (x, y, w, h), t, b in boxed:
        x0, y0 = ax.transData.transform((x, y))
        x1, y1 = ax.transData.transform((x + w, y + h))
        frame = Bbox.from_extents(x0, y0, x1, y1)
        for what, art in (("title", t), ("body", b)):
            bb = art.get_window_extent(rend)
            over = max(frame.x0 - bb.x0, bb.x1 - frame.x1,
                       frame.y0 - bb.y0, bb.y1 - frame.y1)
            if over > -1.0:                 # want at least 1 px of clearance
                bad.append("%s: %s overhangs by %.1f px"
                           % (title.split("  ")[-1], what, over))
    if bad:
        sys.exit("Figure 1 text does not fit its boxes:\n  "
                 + "\n  ".join(bad))

    save(fig, "fig1_pipeline")


# --------------------------------------------------------------------------
# Figure 2: does the gate discriminate?
# --------------------------------------------------------------------------

def fig2_gate_specificity() -> None:
    """Table 2 as a per-family picture of agreement with a constructed verdict.

    The objection this answers is that a gate which fails everything is a
    difficulty detector, not a validity check. So the two families built to be
    hard but sound are the ones a reader should look at, and they are drawn in
    the same panel as the degenerate ones rather than in a footnote.
    """
    fams, correct, got, nright, fired = [], [], [], [], []
    for r in range(nrows(2)):
        fams.append(rowkey(2, r))
        correct.append(_strip(cell(2, r, "Correct verdict")))
        got.append(_strip(cell(2, r, "Gate verdict")))
        nright.append(int(num(2, r, "Correct seeds")))
        fired.append(_strip(cell(2, r, "Checks that fired")))
    n_seeds = int(num(2, 0, "Correct seeds", pick=1))

    order = sorted(range(len(fams)), key=lambda r: (correct[r] != "pass", fams[r]))
    fig, ax = plt.subplots(figsize=(WIDTH, 2.5))
    y = list(range(len(order)))[::-1]

    for yi, r in zip(y, order):
        want_pass = correct[r] == "pass"
        for s in range(n_seeds):
            agreed = s < nright[r]
            ax.scatter([s], [yi], s=46,
                       marker="o" if want_pass else "s",
                       facecolor=(C_FAR if want_pass else C_NEAR) if agreed
                                 else "white",
                       edgecolor=C_FAR if want_pass else C_NEAR,
                       linewidth=1.0, zorder=3)
        ax.text(n_seeds - 0.55, yi, "%d/%d" % (nright[r], n_seeds),
                fontsize=FS_ANNOT, va="center", ha="left")
        ax.text(n_seeds + 0.45, yi,
                "fired: %s" % (fired[r] if fired[r] != "none" else "nothing"),
                fontsize=FS_ANNOT, va="center", ha="left", color=C_MUTED)

    ax.axhline(len(order) - nright.count(0) - 3.5, color=GRID, linewidth=0.5)
    ax.set_yticks(y)
    ax.set_yticklabels(
        ["%s\n(should %s)" % (fams[r], correct[r]) for r in order],
        fontsize=FS_ANNOT)
    ax.set_xticks(range(n_seeds))
    ax.set_xticklabels(["seed %d" % (s + 1) for s in range(n_seeds)],
                       fontsize=FS_TICK)
    ax.set_xlim(-0.6, n_seeds + 3.6)
    ax.set_ylim(-0.8, len(order) - 0.2)
    ax.set_xlabel("one constructed instance per seed", fontsize=FS_LABEL)
    ax.spines["top"].set_visible(False)
    ax.spines["right"].set_visible(False)
    ax.tick_params(length=2.5)

    n_pass = sum(nright[r] for r in range(len(fams)) if correct[r] == "pass")
    n_pass_tot = n_seeds * sum(1 for c in correct if c == "pass")
    n_fail = sum(nright[r] for r in range(len(fams)) if correct[r] == "fail")
    n_fail_tot = n_seeds * sum(1 for c in correct if c == "fail")
    ax.set_title(
        "agreement with the constructed verdict %d of %d   |   "
        "sensitivity %d/%d on degenerate instances   |   "
        "specificity %d/%d on sound instances"
        % (n_pass + n_fail, n_pass_tot + n_fail_tot,
           n_fail, n_fail_tot, n_pass, n_pass_tot),
        fontsize=FS_ANNOT, loc="left", pad=6)

    ax.legend(handles=[
        Line2D([], [], marker="o", color=C_FAR, linestyle="", markersize=6,
               label="sound by construction, filled = gate agreed"),
        Line2D([], [], marker="s", color=C_NEAR, linestyle="", markersize=6,
               label="degenerate by construction, filled = gate agreed"),
        Line2D([], [], marker="o", color=C_FAR, linestyle="", markersize=6,
               markerfacecolor="white", label="open = gate disagreed"),
    ], fontsize=FS_ANNOT, frameon=False, loc="lower right",
        bbox_to_anchor=(1.0, -0.42), ncol=1, handletextpad=0.4)

    save(fig, "fig2_gate_specificity")


# --------------------------------------------------------------------------
# Figure 3: the holdout unit decides the open set result
# --------------------------------------------------------------------------

def fig3_holdout_unit() -> None:
    """Table 14, the article's main empirical finding.

    Panel (b) exists to close off the obvious alternative explanation. If
    configuration B inverted because its models were weak, the inverted points
    would sit at low closed accuracy. They do not: B spans the same closed
    accuracy range as C and inverts anyway, so the inversion tracks the holdout
    unit and not model quality.
    """
    cfg = [h for h in TABLES[14]["header"][1:4]]
    labels = ["A: family held out\n4 classes (far)",
              "B: parameterisation held out\n10 classes (near)",
              "C: family held out\n10 classes (far)"]
    ests = [rowkey(14, r) for r in range(nrows(14))]
    auroc = [[num(14, r, cfg[c]) for r in range(nrows(14))] for c in range(3)]
    closed = [[num(14, r, TABLES[14]["header"][4], pick=c)
               for r in range(nrows(14))] for c in range(3)]

    fig, (ax, bx) = plt.subplots(
        1, 2, figsize=(WIDTH, 3.0), gridspec_kw={"width_ratios": [1.5, 1]})

    # ---- panel a: grouped bars
    h, colours = 0.26, [C_FAR, C_NEAR, C_THIRD]
    hatches = ["", "///", "..."]
    marks = ["o", "s", "^"]
    ypos = list(range(len(ests)))[::-1]
    ax.axvspan(0, 0.5, color=C_BAND, zorder=0)
    for c in range(3):
        ax.barh([y + (1 - c) * h for y in ypos], auroc[c], height=h,
                color=colours[c], edgecolor="white", linewidth=0.4,
                hatch=hatches[c], zorder=3)
    ax.axvline(0.5, color=INK, linewidth=0.8, linestyle="--", zorder=4)
    ax.text(0.485, len(ests) - 0.42, "chance", fontsize=FS_ANNOT,
            ha="right", va="center", style="italic")
    ax.text(0.015, -0.95, "shaded: inverted, novel artifacts score as more\n"
                          "familiar than known ones",
            fontsize=FS_ANNOT, va="center", color=C_NEAR)
    ax.set_yticks(ypos)
    ax.set_yticklabels(ests, fontsize=FS_ANNOT)
    ax.set_xlim(0, 1.0)
    ax.set_xlabel("novelty AUROC", fontsize=FS_LABEL)
    ax.set_ylim(-1.35, len(ests) - 0.35)
    tidy(ax, grid_axis="x")
    ax.set_title("(a) one corpus, three holdout definitions",
                 fontsize=FS_TITLE, loc="left", pad=4)

    # ---- panel b: AUROC against closed accuracy
    bx.axhspan(0, 0.5, color=C_BAND, zorder=0)
    for c in range(3):
        bx.scatter(closed[c], auroc[c], s=24, marker=marks[c],
                   facecolor=colours[c], edgecolor="white", linewidth=0.4,
                   zorder=3)
    bx.axhline(0.5, color=INK, linewidth=0.8, linestyle="--", zorder=4)
    bx.set_xlabel("closed set accuracy, retained classes", fontsize=FS_LABEL)
    bx.set_ylabel("novelty AUROC", fontsize=FS_LABEL)
    bx.set_ylim(0, 1.0)
    tidy(bx, grid_axis="both")
    bx.set_title("(b) inversion is not weak models", fontsize=FS_TITLE,
                 loc="left", pad=4)

    # ---- one figure level key, so neither panel carries a legend on its data.
    # Each entry pairs the panel (a) bar with the panel (b) marker, so the two
    # panels are read with a single key and colour is never the only channel.
    handles = [(mpatches.Patch(facecolor=colours[c], hatch=hatches[c],
                               edgecolor="white", linewidth=0.4),
                mlines.Line2D([], [], color=colours[c], marker=marks[c],
                              linestyle="none", markersize=4,
                              markeredgecolor="white", markeredgewidth=0.4))
               for c in range(3)]
    fig.legend(handles, labels, handler_map={tuple: HandlerTuple(ndivide=None)},
               fontsize=FS_ANNOT, frameon=False, ncol=3, loc="lower center",
               bbox_to_anchor=(0.5, -0.02), handlelength=2.2,
               handletextpad=0.5, columnspacing=1.6)
    fig.subplots_adjust(bottom=0.30, wspace=0.32)

    save(fig, "fig3_holdout_unit")


# --------------------------------------------------------------------------
# Figure 4: the ordered sibling axis
# --------------------------------------------------------------------------

def fig4_sibling_axis() -> None:
    """Tables 15 and 16, the prediction that could have failed.

    Panel (a) plots each parameterisation at its measured position on its
    family's principal axis, so the reader can see that the three position
    classes separate along the axis rather than being assigned to fit the
    AUROCs. Table 15's projections are signed here: a cell reading "below
    centre" is negative.
    """
    names = [rowkey(15, r) for r in range(nrows(15))]
    fam = [_strip(cell(15, r, "Family")) for r in range(nrows(15))]
    proj = [num(15, r, "Axis projection") for r in range(nrows(15))]
    posn = [_strip(cell(15, r, "Position")) for r in range(nrows(15))]
    au = [num(15, r, "AUROC") for r in range(nrows(15))]

    groups = [rowkey(16, r) for r in range(nrows(16))]
    gmean = [num(16, r, "Mean AUROC") for r in range(nrows(16))]
    gsd = [num(16, r, "Standard deviation") for r in range(nrows(16))]
    gfolds = [int(num(16, r, "Folds")) for r in range(nrows(16))]
    gbelow = [num(16, r, "Fraction of folds below 0.5") for r in range(nrows(16))]

    style = {"end": (C_NEAR, "s"), "end of a pair": (C_THIRD, "D"),
             "interior": (C_FAR, "o")}

    fig, (ax, bx) = plt.subplots(
        1, 2, figsize=(WIDTH, 3.0), gridspec_kw={"width_ratios": [1.6, 1]})

    # ---- panel a
    ax.axhspan(0, 0.5, color=C_BAND, zorder=0)
    seen, annots = set(), []
    for i in range(len(names)):
        c, m = style[posn[i]]
        ax.scatter([proj[i]], [au[i]], s=30, marker=m, facecolor=c,
                   edgecolor="white", linewidth=0.5, zorder=3,
                   label=posn[i] if posn[i] not in seen else None)
        seen.add(posn[i])
        annots.append(ax.annotate(
            names[i], (proj[i], au[i]), fontsize=FS_ANNOT, xytext=(0, 7),
            textcoords="offset points", ha="center", va="center",
            color=C_MUTED, zorder=5))
    ax.axhline(0.5, color=INK, linewidth=0.8, linestyle="--", zorder=4)
    ax.axvline(0, color=GRID, linewidth=0.8, zorder=1)
    ax.set_xlabel("signed position on the family's principal axis",
                  fontsize=FS_LABEL)
    ax.set_ylabel("novelty AUROC, configuration B", fontsize=FS_LABEL)
    ax.set_ylim(0, 0.78)
    ax.set_xlim(-4.4, 4.4)
    tidy(ax, grid_axis="both")
    ax.set_title("(a) measured axis position", fontsize=FS_TITLE,
                 loc="left", pad=4)

    # ---- panel b
    yp = list(range(len(groups)))[::-1]
    bx.axvspan(0, 0.5, color=C_BAND, zorder=0)
    for y, g in zip(yp, range(len(groups))):
        c, m = style[groups[g]]
        bx.errorbar([gmean[g]], [y], xerr=[gsd[g]], fmt=m, color=c,
                    markersize=5.5, capsize=2.5, elinewidth=0.9, zorder=3)
        # Two short lines, left aligned at the axis, so a low mean cannot
        # push a centred label off the left edge.
        bx.text(0.015, y + 0.22,
                "mean %.4f\n%d folds, %.0f%% below 0.5"
                % (gmean[g], gfolds[g], gbelow[g] * 100),
                fontsize=FS_ANNOT, ha="left", va="bottom", linespacing=1.25)
    bx.axvline(0.5, color=INK, linewidth=0.8, linestyle="--", zorder=4)
    bx.set_yticks(yp)
    bx.set_yticklabels(groups, fontsize=FS_ANNOT)
    bx.set_ylim(-0.5, len(groups) - 0.05)
    bx.set_xlim(0, 0.78)
    bx.set_xlabel("mean AUROC", fontsize=FS_LABEL)
    tidy(bx, grid_axis="x")
    bx.set_title("(b) grouped by position", fontsize=FS_TITLE, loc="left",
                 pad=4)

    # One key for both panels: the marker and colour of a position class are
    # the same in each, so a per panel legend would only repeat itself.
    order = ["end", "end of a pair", "interior"]
    fig.legend([mlines.Line2D([], [], color=style[k][0], marker=style[k][1],
                              linestyle="none", markersize=4.5,
                              markeredgecolor="white", markeredgewidth=0.4)
                for k in order],
               order, fontsize=FS_ANNOT, frameon=False, ncol=3,
               loc="lower center", bbox_to_anchor=(0.5, -0.02),
               handletextpad=0.3, columnspacing=1.8)

    declutter(fig, ax, annots, list(zip(proj, au)), hlines=[0.5])
    fig.subplots_adjust(bottom=0.26, wspace=0.30)
    save(fig, "fig4_sibling_axis")


# --------------------------------------------------------------------------
# Figure 6: the controlled simulation
# --------------------------------------------------------------------------

def fig6_simulation() -> None:
    """Table 18, where the geometry is known by construction.

    Panel (b) is not decoration. The family holdout curve in panel (a) also
    inverts at small separation, which looks like a contradiction of Figure 3
    until the retained class accuracy is read beside it: below a spread of about
    4 the simulated model cannot separate its own training classes, so its
    posterior is uninformative for every input. The dashed marker is where the
    real configuration C sits, which is in the non inverting regime.
    """
    hdr = TABLES[18]["header"]
    spread = [num(18, r, hdr[0]) for r in range(nrows(18))]
    series = [
        (hdr[1], C_NEAR, "s", "-", "posterior, end sibling held out"),
        (hdr[3], C_FAR, "o", "-", "posterior, interior sibling held out"),
        (hdr[4], C_THIRD, "^", "-", "posterior, whole family held out"),
        (hdr[2], C_NEAR, "s", "--", "maximum unnormalised score, end sibling"),
        (hdr[5], C_THIRD, "^", "--", "maximum unnormalised score, family"),
    ]
    closed_col = hdr[6]
    closed = [num(18, r, closed_col) for r in range(nrows(18))]

    fig, (ax, bx) = plt.subplots(2, 1, figsize=(WIDTH, 4.0), sharex=True,
                                 gridspec_kw={"height_ratios": [2.1, 1]})

    ax.axhspan(0, 0.5, color=C_BAND, zorder=0)
    for column, c, m, ls, lab in series:
        ys = [num(18, r, column) for r in range(nrows(18))]
        ax.plot(spread, ys, ls, color=c, marker=m, markersize=3.4,
                linewidth=1.1, label=lab, zorder=3)
    ax.axhline(0.5, color=INK, linewidth=0.8, linestyle=":", zorder=4)
    ax.set_xscale("log")
    ax.set_ylim(-0.03, 1.06)
    ax.set_ylabel("novelty AUROC", fontsize=FS_LABEL)
    tidy(ax, grid_axis="both")
    ax.set_title("(a) novelty detection against sibling separation",
                 fontsize=FS_TITLE, loc="left", pad=4)

    bx.plot(spread, closed, "-", color=C_MUTED, marker="o", markersize=3.4,
            linewidth=1.1, zorder=3)
    bx.set_xscale("log")
    bx.set_xticks(spread)
    bx.set_xticklabels(["%g" % s for s in spread], fontsize=FS_TICK)
    bx.minorticks_off()
    bx.set_ylim(0.2, 1.06)
    bx.set_xlabel("sibling separation, as a spread in the simulated "
                  "feature space", fontsize=FS_LABEL)
    bx.set_ylabel("retained class\nclosed accuracy", fontsize=FS_LABEL)
    tidy(bx, grid_axis="both")
    bx.set_title("(b) the same model's closed set task", fontsize=FS_TITLE,
                 loc="left", pad=4)

    # Five series will not fit beside the curves without covering them, so the
    # key goes under the figure where it competes with nothing.
    h, l = ax.get_legend_handles_labels()
    fig.legend(h, l, fontsize=FS_ANNOT, frameon=False, ncol=2,
               loc="lower center", bbox_to_anchor=(0.5, -0.025),
               handlelength=2.2, handletextpad=0.4, columnspacing=1.4)
    fig.subplots_adjust(bottom=0.26, hspace=0.30)
    save(fig, "fig6_simulation")


# --------------------------------------------------------------------------
# Figure 7: closed set attribution and the variance decomposition
# --------------------------------------------------------------------------

def fig7_closed_set() -> None:
    """Tables 19 and 20.

    The whiskers are the observed minimum and maximum fold, not a confidence
    interval, and the axis label says so. Panel (c) is the variance
    decomposition: the seed component is the one that would have to be large for
    a single quoted spread to have meant what it was taken to mean, and it is
    not, including three estimators where it is exactly zero because they are
    deterministic.
    """
    # Table 19 carries two protocols side by side, so every column name is
    # prefixed with its protocol. That is a manuscript property, not a
    # convenience here: the table previously repeated the bare names "fold sd",
    # "seed sd" and "min, max fold", which left the provenance sidecar unable to
    # say which of the two protocols a recorded value came from, and left a
    # reader counting columns to find out. figcheck.py now rejects any table it
    # is asked to verify whose column names are not unique.
    ests19 = [rowkey(19, r) for r in range(nrows(19))]
    g_mean = [num(19, r, "grouped_cv mean") for r in range(nrows(19))]
    g_fsd = [num(19, r, "grouped_cv fold sd") for r in range(nrows(19))]
    g_ssd = [num(19, r, "grouped_cv seed sd") for r in range(nrows(19))]
    g_lo = [num(19, r, "grouped_cv min, max fold") for r in range(nrows(19))]
    g_hi = [num(19, r, "grouped_cv min, max fold", pick=1) for r in range(nrows(19))]
    d_mean = [num(19, r, "domain holdout mean") for r in range(nrows(19))]
    d_lo = [num(19, r, "domain holdout min, max fold") for r in range(nrows(19))]
    d_hi = [num(19, r, "domain holdout min, max fold", pick=1)
            for r in range(nrows(19))]

    ests20 = [rowkey(20, r) for r in range(nrows(20))]
    p_mean = [num(20, r, "Mean") for r in range(nrows(20))]
    p_lo = [num(20, r, "min, max fold") for r in range(nrows(20))]
    p_hi = [num(20, r, "min, max fold", pick=1) for r in range(nrows(20))]

    chance_fam = float(re.search(r"chance (\d*\.\d+)",
                                 TABLES[19]["caption"]).group(1))
    chance_par = float(re.search(r"chance (\d*\.\d+)",
                                 TABLES[20]["caption"]).group(1))

    # Three range plots will not fit across one 6 in row: each needs a column
    # of estimator names, and Tables 19 and 20 order their rows differently, so
    # the names cannot be shared. The two granularities take the top row and
    # the variance decomposition takes a full width row of its own.
    fig = plt.figure(figsize=(WIDTH, 4.5))
    gs = fig.add_gridspec(2, 2, height_ratios=[1.45, 1], hspace=0.95,
                          wspace=0.42)
    ax = fig.add_subplot(gs[0, 0])
    bx = fig.add_subplot(gs[0, 1])
    cx = fig.add_subplot(gs[1, :])

    def rangeplot(a, ests, pairs, chance, title):
        yp = list(range(len(ests)))[::-1]
        for k, (mean, lo, hi, c, m, lab) in enumerate(pairs):
            off = (len(pairs) - 1 - 2 * k) * 0.17
            for y, i in zip(yp, range(len(ests))):
                a.plot([lo[i], hi[i]], [y + off, y + off], color=c,
                       linewidth=1.1, solid_capstyle="butt", zorder=3)
                a.plot([lo[i], hi[i]], [y + off, y + off], "|", color=c,
                       markersize=3.2, zorder=3)
            a.scatter(mean, [y + off for y in yp], s=20, marker=m,
                      facecolor=c, edgecolor="white", linewidth=0.4,
                      zorder=4, label=lab)
        a.axvline(chance, color=C_MUTED, linewidth=0.8, linestyle=":", zorder=2)
        a.text(chance, len(ests) - 0.42, " chance %.2f" % chance,
               fontsize=FS_ANNOT, va="center", color=C_MUTED)
        a.set_yticks(yp)
        a.set_yticklabels(ests, fontsize=FS_ANNOT)
        a.set_xlim(0, 1.04)
        a.set_ylim(-0.6, len(ests) - 0.25)
        a.set_xlabel("macro F1", fontsize=FS_LABEL)
        tidy(a, grid_axis="x")
        a.set_title(title, fontsize=FS_TITLE, loc="left", pad=4)

    rangeplot(ax, ests19,
              [(g_mean, g_lo, g_hi, C_FAR, "o", "grouped_cv"),
               (d_mean, d_lo, d_hi, C_NEAR, "s", "domain holdout")],
              chance_fam, "(a) family granularity, 4 classes")
    ax.legend(fontsize=FS_ANNOT, frameon=False, loc="upper center", ncol=2,
              bbox_to_anchor=(0.5, -0.30), handletextpad=0.3,
              columnspacing=1.4)

    rangeplot(bx, ests20,
              [(p_mean, p_lo, p_hi, C_THIRD, "D", "domain holdout")],
              chance_par, "(b) parameterisation granularity, 10 classes")
    bx.legend(fontsize=FS_ANNOT, frameon=False, loc="upper center",
              bbox_to_anchor=(0.5, -0.30), handletextpad=0.3)

    # ---- panel c: fold spread against estimator spread, as paired columns.
    # Vertical bars rather than a third dot column: this panel has the full
    # width, and the point is the ratio of two heights at each estimator.
    xp = list(range(len(ests19)))
    w = 0.36
    cx.bar([x - w / 2 for x in xp], g_fsd, width=w, color=C_FAR,
           edgecolor="white", linewidth=0.4, zorder=3,
           label="fold spread, within one seed")
    cx.bar([x + w / 2 for x in xp], g_ssd, width=w, color=C_NEAR,
           edgecolor="white", linewidth=0.4, hatch="///", zorder=3,
           label="estimator spread, between seeds")
    top = max(g_fsd) * 1.38
    for i, x in enumerate(xp):
        if g_ssd[i] == 0.0:
            cx.annotate("0", (x + w / 2, 0), fontsize=FS_ANNOT,
                        xytext=(0, 2.5), textcoords="offset points",
                        ha="center", va="bottom", color=C_NEAR)
    det = [ests19[i] for i in range(len(ests19)) if g_ssd[i] == 0.0]
    cx.text(0.995, 0.95, "0 = no seed dependence at all: " + ", ".join(det),
            transform=cx.transAxes, fontsize=FS_ANNOT, ha="right",
            va="top", color=C_NEAR)
    cx.set_xticks(xp)
    cx.set_xticklabels(ests19, fontsize=FS_ANNOT, rotation=15,
                       rotation_mode="anchor", ha="right")
    cx.set_xlim(-0.65, len(ests19) - 0.35)
    cx.set_ylim(0, top)
    cx.set_ylabel("sd of macro F1", fontsize=FS_LABEL)
    tidy(cx, grid_axis="y")
    cx.legend(fontsize=FS_ANNOT, frameon=False, loc="upper left",
              handlelength=1.6, handletextpad=0.4)
    cx.set_title("(c) the two spread components, family granularity, "
                 "grouped_cv", fontsize=FS_TITLE, loc="left", pad=4)

    save(fig, "fig7_closed_set")


# --------------------------------------------------------------------------
# Figure 5: what the softmax discards
# --------------------------------------------------------------------------

def fig5_scorers() -> None:
    """Table 17, the three estimators that expose unnormalised class scores.

    A slope chart rather than bars, because the claim is about the ordering
    holding within every estimator and not about the absolute values.
    """
    ests = [rowkey(17, r) for r in range(nrows(17))]
    hdr = TABLES[17]["header"]
    steps = [(hdr[1], "msp"), (hdr[2], "energy"), (hdr[3], "openmax")]
    colours = [C_FAR, C_NEAR, C_THIRD]
    markers = ["o", "s", "^"]

    fig, (ax, bx) = plt.subplots(
        1, 2, figsize=(WIDTH, 2.7), gridspec_kw={"width_ratios": [1.3, 1]})

    ax.axhspan(0, 0.5, color=C_BAND, zorder=0)
    xs = list(range(len(steps)))
    annots, pts = [], []
    for i, e in enumerate(ests):
        ys = [num(17, i, column) for column, _ in steps]
        ax.plot(xs, ys, "-", color=colours[i], marker=markers[i],
                markersize=4.5, linewidth=1.2, label=e, zorder=3)
        for x, y in zip(xs, ys):
            annots.append(ax.annotate(
                "%.4f" % y, (x, y), fontsize=FS_ANNOT, xytext=(0, 6),
                textcoords="offset points", ha="center", va="center",
                color=colours[i], zorder=5))
            pts.append((x, y))
    ax.axhline(0.5, color=INK, linewidth=0.8, linestyle="--", zorder=4)
    ax.set_xticks(xs)
    ax.set_xticklabels([lab for _, lab in steps], fontsize=FS_TICK)
    ax.set_xlim(-0.42, len(steps) - 0.58)
    ax.set_ylim(0.15, 0.86)
    ax.set_ylabel("novelty AUROC, configuration B", fontsize=FS_LABEL)
    ax.set_xlabel("open set scorer", fontsize=FS_LABEL)
    tidy(ax, grid_axis="y")
    ax.legend(fontsize=FS_ANNOT, frameon=False, loc="lower right", ncol=3,
              handlelength=1.6, handletextpad=0.3, columnspacing=1.0,
              borderpad=0.1)
    ax.set_title("(a) the ordering holds for every estimator",
                 fontsize=FS_TITLE, loc="left", pad=4)

    # ---- panel b: the operating point, which the AUROC hides
    fpr = [num(17, r, hdr[4]) for r in range(nrows(17))]
    yp = list(range(len(ests)))[::-1]
    bx.barh(yp, fpr, height=0.5, color=C_MUTED, edgecolor="white",
            linewidth=0.4, zorder=3)
    for y, v in zip(yp, fpr):
        bx.text(v - 0.02, y, "%.2f%%" % (v * 100), fontsize=FS_ANNOT,
                va="center", ha="right", color="white")
    bx.set_yticks(yp)
    bx.set_yticklabels(ests, fontsize=FS_ANNOT)
    bx.set_xlim(0, 1.0)
    bx.set_ylim(-0.6, len(ests) - 0.4)
    bx.set_xlabel("novel artifacts accepted as known,\nopenmax at 95% known "
                  "retention", fontsize=FS_LABEL)
    tidy(bx, grid_axis="x")
    bx.set_title("(b) above chance is not solved", fontsize=FS_TITLE,
                 loc="left", pad=4)

    declutter(fig, ax, annots, pts, marker_pt=6.5, hlines=[0.5])
    fig.subplots_adjust(wspace=0.34)
    save(fig, "fig5_scorers")


# --------------------------------------------------------------------------

# Numbered and ordered to match where each figure is placed in the manuscript,
# so a reader meets Figure n after Figure n-1. The file stem carries the same
# number as the caption, which is what keeps a renumbering honest: a stem that
# disagreed with its caption would be a silent trap for the next edit.
FIGURES = [
    ("Figure 1, pipeline and the gate as a build stage (Section 4)",
     fig1_pipeline),
    ("Figure 2, gate specificity (Section 4.3, Table 2)",
     fig2_gate_specificity),
    ("Figure 3, the holdout unit result (Section 7.2, Table 14)",
     fig3_holdout_unit),
    ("Figure 4, the ordered sibling axis (Section 7.3, Tables 15, 16)",
     fig4_sibling_axis),
    ("Figure 5, what the softmax discards (Section 7.4, Table 17)",
     fig5_scorers),
    ("Figure 6, the controlled simulation (Section 7.5, Table 18)",
     fig6_simulation),
    ("Figure 7, closed set attribution (Section 7.6, Tables 19, 20)",
     fig7_closed_set),
]


def main() -> int:
    print("parsed %d tables from %s" % (len(TABLES), os.path.basename(MD)))
    for title, fn in FIGURES:
        print(title)
        fn()
    os.makedirs(OUT, exist_ok=True)
    side = os.path.join(OUT, "plotted_values.json")
    with open(side, "w", encoding="utf-8") as fh:
        json.dump({"source": os.path.relpath(MD, ROOT),
                   "tables": {str(n): table_digest(n)
                              for n in sorted({r["table"] for r in PROV})},
                   "values": PROV}, fh, indent=1)
    print("recorded %d plotted values in figures/plotted_values.json"
          % len(PROV))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
