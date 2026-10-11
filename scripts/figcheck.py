"""Verify that every number drawn in a figure still matches the manuscript.

``make_manuscript_figures.py`` writes ``docs/figures/plotted_values.json``, one
record per value it handed to matplotlib, naming the table, row and column the
value came from and the raw cell text it was parsed out of. This script reads
that sidecar, re-parses the manuscript, and checks each record against the cell
it claims to come from.

The markdown parser here is written independently of the one in the generator,
on purpose. A shared parser would make the check circular: a table the
generator misreads it would also misread here, and the comparison would pass.
These two read the file differently (this one indexes rows by their first cell
rather than by position) so a misparse has to occur twice, in two different
ways, to go unnoticed.

Checks performed
----------------
0. every table a record points at addresses cells uniquely, that is its column
   names are distinct and so are its row keys. A record names its cell by table,
   row and column, so a table with two columns of the same name cannot be
   verified: either answer is defensible and the disagreement stays hidden. This
   check exists because Table 19 was in exactly that state, carrying a bare
   ``fold sd`` for each of its two protocols.
1. every sidecar record resolves to a real table, row and column
2. the recorded raw cell text equals the cell's current text
3. the recorded value is the pick-th number in that text, with the sign
   convention the manuscript uses for signed projections
4. every figure exists as both .pdf and .png, and none predates the generator
   that draws it
5. no source table has changed since the figures were drawn, checked by a
   digest over the whole table so that an added or deleted row is caught and a
   prose edit elsewhere in the manuscript is not
6. every figure file in docs/figures is referenced by the manuscript, and
   every figure the manuscript references exists
7. every figure is both captioned and discussed in the body text, the caption
   and the discussion being different jobs: a caption has to stand alone for a
   reader who is skimming, and the body has to say why the figure is there. A
   figure that is inserted and never mentioned is the defect this check exists
   to prevent

Usage
-----
    python3 scripts/figcheck.py

Exit status is 0 if every check passes and 1 otherwise, so this can be run in
CI or as a pre-submission gate.
"""
from __future__ import annotations

import hashlib
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
MD = os.path.join(ROOT, "docs", "ObfuScope_manuscript_revised_2.md")
FIGDIR = os.path.join(ROOT, "docs", "figures")
SIDECAR = os.path.join(FIGDIR, "plotted_values.json")


def clean(s: str) -> str:
    """Drop the markdown emphasis that is presentation, not content."""
    return s.replace("`", "").replace("**", "").strip()


def parse_tables(text: str) -> dict:
    """Index every captioned pipe table as {number: {column: {row: cell}}}.

    Deliberately a different shape from the generator's positional parse: rows
    and columns are keyed by name here, so a row that moved would be found at
    its name rather than silently read at the wrong index.
    """
    tables: dict[int, dict] = {}
    lines = text.split("\n")
    num = None
    pending: list[list[str]] = []

    def flush(n, block):
        if n is None or len(block) < 2:
            return
        header = [clean(h) for h in block[0]]
        body = block[1:]
        byname: dict[str, dict] = {}
        for c, name in enumerate(header):
            col: dict[str, str] = {}
            for row in body:
                if c < len(row):
                    col[clean(row[0])] = row[c]
            byname[name] = col
        order = [clean(r[0]) for r in body]
        # Keyed indexes silently collapse repeats: a second column or row of the
        # same name overwrites the first, and the check then compares against
        # whichever happened to land last. Record the repeats so check 0 can
        # refuse the table outright instead.
        tables[n] = {"columns": byname, "header": header, "order": order,
                     "rows": body,
                     "dup_columns": sorted({h for h in header
                                            if header.count(h) > 1}),
                     "dup_rows": sorted({r for r in order
                                         if order.count(r) > 1})}

    for line in lines:
        cap = re.match(r"^\*\*Table (\d+)\.", line)
        if cap:
            flush(num, pending)
            num, pending = int(cap.group(1)), []
            continue
        if line.lstrip().startswith("|"):
            s = line.strip().strip("|")
            cells = [c.strip() for c in s.split("|")]
            if all(re.fullmatch(r":?-{2,}:?", c or "") for c in cells):
                continue                       # the ---|--- rule row
            pending.append(cells)
            continue
        if line.strip() and pending:
            flush(num, pending)
            num, pending = None, []
    flush(num, pending)
    return tables


def digest(table: dict) -> str:
    """Recompute the generator's table digest from this file's own parse.

    The canonical form has to match make_manuscript_figures.table_digest: cells
    stripped of markdown emphasis, joined with a pipe, rows joined with a
    newline, header first. It is reimplemented here rather than imported, so a
    disagreement between the two parsers shows up as a digest mismatch.
    """
    canon = "\n".join("|".join(clean(c) for c in row)
                       for row in [table["header"]] + table["rows"])
    return hashlib.sha256(canon.encode("utf-8")).hexdigest()[:16]


def numbers(raw: str) -> list[float]:
    return [float(x) for x in re.findall(r"-?\d+(?:\.\d+)?", raw.replace("%", ""))]


def main() -> int:
    if not os.path.exists(SIDECAR):
        print("no sidecar at %s; run make_manuscript_figures.py first"
              % os.path.relpath(SIDECAR, ROOT))
        return 1

    side = json.load(open(SIDECAR, encoding="utf-8"))
    records = side["values"]
    text = open(MD, encoding="utf-8").read()
    tables = parse_tables(text)
    fail: list[str] = []

    # ---- 0: refuse tables whose cells cannot be addressed by name
    ambiguous = set()
    for t in sorted({r["table"] for r in records}):
        if t not in tables:
            continue
        for what, key in (("column", "dup_columns"), ("row", "dup_rows")):
            if tables[t][key]:
                ambiguous.add(t)
                fail.append("Table %d has repeated %s names %r, so a value "
                            "recorded against one of them cannot be traced to "
                            "a single cell; give them distinct names in the "
                            "manuscript"
                            % (t, what, tables[t][key]))

    # ---- 1 to 3: every plotted value against its cell
    for i, rec in enumerate(records):
        if rec["table"] in ambiguous:
            continue                           # already reported, once, above
        t, row, column = rec["table"], rec["row"], rec["column"]
        where = "record %d (Table %d, row %r, column %r)" % (i, t, row, column)
        if t not in tables:
            fail.append("%s: Table %d is not in the manuscript" % (where, t))
            continue
        cols = tables[t]["columns"]
        key = clean(column)
        if key not in cols:
            fail.append("%s: no such column; have %r"
                        % (where, tables[t]["header"]))
            continue
        if row not in cols[key]:
            fail.append("%s: no such row; have %r" % (where, tables[t]["order"]))
            continue
        now = cols[key][row]
        if now != rec["raw"]:
            fail.append("%s: cell text changed from %r to %r"
                        % (where, rec["raw"], now))
            continue
        found = numbers(now)
        if len(found) <= rec["pick"]:
            fail.append("%s: no number #%d in %r" % (where, rec["pick"], now))
            continue
        want = found[rec["pick"]]
        if "below centre" in now:
            want = -want                      # signed about the family centre
        if abs(want - rec["value"]) > 1e-12:
            fail.append("%s: plotted %s but the cell gives %s"
                        % (where, rec["value"], want))

    # ---- 4: the figure files themselves, and whether the generator moved
    # under them. Deliberately not compared against the manuscript's mtime: a
    # prose edit touches the file without touching any table, and a check that
    # fires on every prose edit is a check that gets ignored. Table content is
    # covered precisely by check 5 below.
    gen_mtime = os.path.getmtime(os.path.join(HERE,
                                              "make_manuscript_figures.py"))
    stems = sorted({f[:-4] for f in os.listdir(FIGDIR)
                    if f.endswith(".pdf") or f.endswith(".png")})
    for stem in stems:
        for ext in ("pdf", "png"):
            path = os.path.join(FIGDIR, "%s.%s" % (stem, ext))
            if not os.path.exists(path):
                fail.append("%s.%s is missing" % (stem, ext))
            elif os.path.getmtime(path) < gen_mtime:
                fail.append("%s.%s is older than the generator that draws it; "
                            "re-run make_manuscript_figures.py" % (stem, ext))

    # ---- 5: has any source table changed since the figures were drawn? This
    # catches the edit that the per value comparison cannot, a row added to or
    # removed from a table, which leaves every recorded value correct while
    # making the figure an incomplete picture of its source.
    stored = side.get("tables")
    if not stored:
        fail.append("the sidecar carries no table digests; it predates this "
                    "check, so re-run make_manuscript_figures.py")
    else:
        for key in sorted(stored, key=int):
            t = int(key)
            if t not in tables:
                continue                       # already reported by check 1
            now = digest(tables[t])
            if now != stored[key]:
                fail.append("Table %d has changed since the figures were "
                            "drawn (digest %s, now %s); re-run "
                            "make_manuscript_figures.py"
                            % (t, stored[key], now))

    # ---- 6: references in the manuscript point at files that exist
    refs = re.findall(r"!\[[^\]]*\]\(([^)]+)\)", text)
    for r in refs:
        path = os.path.normpath(os.path.join(ROOT, "docs", r))
        if not os.path.exists(path):
            fail.append("manuscript references %s, which does not exist" % r)
    referenced = {os.path.splitext(os.path.basename(r))[0] for r in refs}
    for stem in stems:
        if stem.startswith("_"):
            continue                          # scratch crops, not deliverables
        if stem not in referenced:
            fail.append("%s is generated but never referenced by the "
                        "manuscript" % stem)

    # ---- 7: each figure captioned once and discussed at least once, with the
    # discussion counted outside the caption line and outside the alt text.
    body = [ln.strip() for ln in text.split("\n")]
    for n in range(1, len(refs) + 1):
        cap = [ln for ln in body if ln.startswith("**Figure %d." % n)]
        disc = [ln for ln in body
                if re.search(r"\bFigure %d\b" % n, ln)
                and not ln.startswith("**Figure %d." % n)
                and not ln.startswith("![")]
        if len(cap) != 1:
            fail.append("Figure %d has %d captions; expected exactly one "
                        "line beginning '**Figure %d.'" % (n, len(cap), n))
        if not disc:
            fail.append("Figure %d is captioned but never referred to in the "
                        "body text, so a reader is never told why it is there"
                        % n)

    tabs = sorted({r["table"] for r in records})
    print("%d plotted values checked against %d tables (%s)"
          % (len(records), len(tabs),
             ", ".join("T%d" % t for t in tabs)))
    print("%d figure stems, %d manuscript references" % (len(stems), len(refs)))
    if fail:
        print("\nFAILED, %d problem(s):" % len(fail))
        for f in fail:
            print("  " + f)
        return 1
    print("all checks passed")
    return 0


if __name__ == "__main__":
    sys.exit(main())
