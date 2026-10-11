"""
Convert the project notes to Word documents.

Two kinds of table appear in these notes and they need opposite treatment. The
revision notes hold space aligned tables inside fenced blocks, and Word reflows
proportional text, which would destroy the column alignment, so fenced blocks
are emitted in a monospace font with paragraph spacing suppressed. The review
notes hold pipe delimited tables, which carry no alignment of their own, so
those are emitted as real Word tables where Word is free to size the columns.

Inline markup handled: bold, italic, and backticked code. Hyphens inside
backticks are left alone because they are command line flags and identifiers
rather than punctuation.

A line that is nothing but ``![alt](path)`` becomes an embedded picture, with
the alt text carried into the shape's description so it survives into the
accessibility pane. A path that does not resolve is a hard error rather than a
skipped line: a converter that quietly drops an image produces a document that
discusses figures it does not contain, which is the one failure mode worth
crashing over.

Usage
-----
    python3 scripts/md_to_docx.py docs/paper_revision_v2.md \\
        docs/paper_revision_v2.docx
"""
from __future__ import annotations

import os
import re
import sys

from docx import Document
from docx.enum.text import WD_ALIGN_PARAGRAPH
from docx.shared import Inches, Pt, RGBColor

# The figures are drawn at exactly this width by make_manuscript_figures.py,
# and their in-figure type is sized against it with only ~0.7 pt of headroom
# over the 6 pt floor. So they are placed at their native width and never
# scaled: a Word default page is 8.5 in with 1 in margins, leaving 6.5 in of
# text, so 6.0 in fits without reflowing anything.
FIG_WIDTH_IN = 6.0


def _code(doc: Document, lines: list[str]) -> None:
    for line in lines:
        p = doc.add_paragraph()
        p.paragraph_format.space_before = Pt(0)
        p.paragraph_format.space_after = Pt(0)
        p.paragraph_format.line_spacing = 1.0
        p.alignment = WD_ALIGN_PARAGRAPH.LEFT
        run = p.add_run(line if line else " ")
        run.font.name = "Menlo"
        run.font.size = Pt(8.5)
        run.font.color.rgb = RGBColor(0x1A, 0x1A, 0x1A)


# Bold is tested before italic so that a doubled star is not consumed as an
# italic opener. Code is tested before both so that stars inside a backticked
# span stay literal. The bold body is lazy rather than star free because bold
# routinely wraps italic or code in these notes, and a star free body would
# leave the markers in the output as literal text.
_INLINE = re.compile(
    r"`(?P<code>[^`]+)`"
    r"|\*\*(?P<bold>.+?)\*\*"
    r"|(?<![\w*])\*(?P<ital>[^*\n]+)\*(?![\w*])"
)


def _plain(p, text: str, base: Pt, bold: bool, italic: bool) -> None:
    r = p.add_run(text)
    r.font.size = base
    if bold:
        r.bold = True
    if italic:
        r.italic = True


def _runs(p, text: str, base: Pt, mono: Pt,
          bold: bool = False, italic: bool = False) -> None:
    """Add the runs for one paragraph of inline markup.

    Recursive, because the markup nests: a bold span can contain a backticked
    identifier and an emphasised clause, and each needs to keep the enclosing
    weight as well as its own. Flat parsing drops the outer markers into the
    document as literal stars.
    """
    pos = 0
    for m in _INLINE.finditer(text):
        if m.start() > pos:
            _plain(p, text[pos:m.start()], base, bold, italic)
        if m.group("code") is not None:
            r = p.add_run(m.group("code"))
            r.font.name = "Menlo"
            r.font.size = mono
            if bold:
                r.bold = True
            if italic:
                r.italic = True
        elif m.group("bold") is not None:
            _runs(p, m.group("bold"), base, mono, True, italic)
        else:
            _runs(p, m.group("ital"), base, mono, bold, True)
        pos = m.end()
    if pos < len(text):
        _plain(p, text[pos:], base, bold, italic)


def _body(doc: Document, text: str) -> None:
    p = doc.add_paragraph()
    p.paragraph_format.space_after = Pt(6)
    # A line that is entirely bold is a run in head, the numbered concern
    # labels in the review notes being the case this serves. Giving it space
    # above makes it read as a heading without putting it in the Word outline,
    # which would clutter the navigation pane with twenty entries.
    s = text.strip()
    if s.startswith("**") and s.endswith("**") and "**" not in s[2:-2]:
        p.paragraph_format.space_before = Pt(12)
    _runs(p, text, base=Pt(11), mono=Pt(9.5))


_SEP_CELL = re.compile(r"^:?-{2,}:?$")


def _row_cells(line: str) -> list[str]:
    s = line.strip()
    if s.startswith("|"):
        s = s[1:]
    if s.endswith("|"):
        s = s[:-1]
    return [c.strip() for c in s.split("|")]


def _is_separator(line: str) -> bool:
    cells = _row_cells(line)
    return bool(cells) and all(_SEP_CELL.match(c or "") for c in cells)


def _table(doc: Document, rows: list[list[str]]) -> None:
    ncols = max(len(r) for r in rows)
    t = doc.add_table(rows=len(rows), cols=ncols)
    t.style = "Table Grid"
    for i, row in enumerate(rows):
        for j in range(ncols):
            p = t.cell(i, j).paragraphs[0]
            p.paragraph_format.space_before = Pt(2)
            p.paragraph_format.space_after = Pt(2)
            _runs(p, row[j] if j < len(row) else "", base=Pt(9), mono=Pt(8.5))
            if i == 0:
                for r in p.runs:
                    r.bold = True


_RULE = re.compile(r"^\s*(?:-{3,}|\*{3,}|_{3,})\s*$")
_IMAGE = re.compile(r"^!\[(?P<alt>[^\]]*)\]\((?P<path>[^)]+)\)\s*$")
_FIGCAP = re.compile(r"^\*\*Figure \d+\.")


def _picture(doc: Document, src: str, alt: str, rel: str) -> None:
    """Embed one figure, sized to its native width and centred."""
    path = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(src)),
                                         rel))
    if not os.path.exists(path):
        raise SystemExit("%s references the image %s, which does not exist at "
                         "%s" % (src, rel, path))
    p = doc.add_paragraph()
    p.alignment = WD_ALIGN_PARAGRAPH.CENTER
    p.paragraph_format.space_before = Pt(10)
    p.paragraph_format.space_after = Pt(4)
    p.add_run().add_picture(path, width=Inches(FIG_WIDTH_IN))
    if alt:
        # python-docx has no alt text API, so reach the drawing property the
        # accessibility pane actually reads.
        doc.inline_shapes[-1]._inline.docPr.set("descr", alt)


def _caption(doc: Document, text: str) -> None:
    p = doc.add_paragraph()
    p.paragraph_format.space_after = Pt(12)
    p.paragraph_format.line_spacing = 1.0
    _runs(p, text, base=Pt(9.5), mono=Pt(8.5))


def convert(src: str, dest: str) -> None:
    doc = Document()
    style = doc.styles["Normal"]
    style.font.name = "Calibri"
    style.font.size = Pt(11)

    with open(src) as fh:
        lines = fh.read().split("\n")

    i = 0
    buffer: list[str] = []

    def flush() -> None:
        nonlocal buffer
        if buffer:
            _body(doc, " ".join(buffer).strip())
            buffer = []

    while i < len(lines):
        line = lines[i]

        if line.startswith("```"):
            flush()
            i += 1
            block: list[str] = []
            while i < len(lines) and not lines[i].startswith("```"):
                block.append(lines[i])
                i += 1
            _code(doc, block)
            doc.add_paragraph().paragraph_format.space_after = Pt(4)
            i += 1
            continue

        # A pipe table. The separator row carries only alignment, which Word
        # decides for itself, so it is dropped rather than rendered.
        if line.lstrip().startswith("|"):
            flush()
            rows: list[list[str]] = []
            while i < len(lines) and lines[i].lstrip().startswith("|"):
                if not _is_separator(lines[i]):
                    rows.append(_row_cells(lines[i]))
                i += 1
            if rows:
                _table(doc, rows)
                doc.add_paragraph().paragraph_format.space_after = Pt(4)
            continue

        m = _IMAGE.match(line.strip())
        if m:
            flush()
            _picture(doc, src, m.group("alt"), m.group("path"))
            i += 1
            continue

        # A figure caption is set smaller and kept tight under its picture, so
        # it reads as a caption rather than as the next paragraph of the body.
        if _FIGCAP.match(line.strip()):
            flush()
            text = line.strip()
            while i + 1 < len(lines) and lines[i + 1].strip():
                i += 1
                text += " " + lines[i].strip()
            _caption(doc, text)
            i += 1
            continue

        # A horizontal rule. Headings already separate the sections, so drawing
        # a second divider under every one of them only adds noise.
        if _RULE.match(line):
            flush()
            i += 1
            continue

        m = re.match(r"^(#{1,4})\s+(.*)$", line)
        if m:
            flush()
            doc.add_heading(m.group(2).strip(), level=len(m.group(1)))
            i += 1
            continue

        if re.match(r"^\s*(?:\d+\.|[*+-])\s+", line):
            flush()
            text = re.sub(r"^\s*(?:\d+\.|[*+-])\s+", "", line)
            # Continuation lines of a list item are indented; fold them in so
            # the item reads as one paragraph rather than one line per source
            # line.
            while i + 1 < len(lines) and re.match(r"^\s{3,}\S", lines[i + 1]) \
                    and not lines[i + 1].startswith("```"):
                i += 1
                text += " " + lines[i].strip()
            p = doc.add_paragraph(style="List Bullet")
            p.paragraph_format.space_after = Pt(4)
            _runs(p, text, base=Pt(11), mono=Pt(9.5))
            i += 1
            continue

        if not line.strip():
            flush()
            i += 1
            continue

        buffer.append(line.strip())
        i += 1

    flush()
    doc.save(dest)
    print(f"wrote {dest}")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(__doc__)
        raise SystemExit(2)
    convert(sys.argv[1], sys.argv[2])
