"""
Reference source-to-source backend. A stand-in for Tigress, not a replacement.

What this is for
----------------
The generation harness, the labelling contract, the sharding, the diversity gate
and the DAG wiring all need to be exercised end to end before a Tigress run is
worth submitting. Tigress is a licensed external binary; this module lets the
whole chain run and be measured without it.

What it is not
--------------
It is not Tigress and it does not reproduce Tigress output. It implements four
transformation families at the token level, which is a weaker construction than
Tigress applies over a parsed AST. Two of the Tigress families in
``tigress_spec.CATALOGUE``, Flatten and Virtualize, are deliberately absent:
both rewrite the control flow graph, which cannot be done correctly without
parsing C, and a token level approximation would produce a fingerprint of this
module rather than of control flow flattening.

Any number measured on this backend is therefore a property of this backend.
It bounds what the pipeline does, it does not stand in for a Tigress result.
Results from the two must never be pooled or compared as though equivalent.

Correctness is checked, not assumed
-----------------------------------
Every artifact is compiled and executed, and its standard output is compared
against the unmodified program's. An artifact that fails to compile or whose
output differs is discarded and recorded as a failure. Semantic preservation is
therefore measured per artifact rather than argued for in prose.

Collberg coverage
-----------------
    EncodeLiterals     data     integer literals rewritten as opaque expressions
    EncodeStrings      data     string literals stored encoded, decoded on use
    AddOpaque          control  dead branches guarded by opaque predicates
    RenameIdentifiers  layout   local and static identifiers renamed

All three categories of Collberg, Thomborson and Low (1997) are represented, so
the label axis spans the same taxonomy as the Tigress catalogue even though the
specific transformations differ.
"""
from __future__ import annotations

import random
import re
from dataclasses import dataclass, field
from typing import Dict, List, Sequence, Tuple

# Identifiers that must never be renamed or shadowed. Renaming any of these
# produces code that still compiles but calls the wrong thing, which the output
# comparison would catch as a failure rather than as the bug it is.
RESERVED = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline",
    "int", "long", "register", "restrict", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while", "_Bool", "main",
    "printf", "sprintf", "snprintf", "puts", "putchar", "malloc", "calloc",
    "realloc", "free", "memcpy", "memmove", "memset", "strlen", "strcmp",
    "strncmp", "strcpy", "strncpy", "strchr", "strstr", "size_t", "NULL",
    "stdout", "stderr", "stdin", "FILE", "abs", "labs", "exit",
}

# Matches a C string literal, a char literal, a line comment, a block comment,
# or a preprocessor line. Rewrites must skip all of these: a literal inside a
# string is data, and a literal on an #include line is a path.
_PROTECTED = re.compile(
    r'("(?:[^"\\\n]|\\.)*")'      # string literal
    r"|('(?:[^'\\\n]|\\.)*')"     # char literal
    r"|(//[^\n]*)"                # line comment
    r"|(/\*.*?\*/)"               # block comment
    r"|(^[ \t]*#[^\n]*)",         # preprocessor line
    re.S | re.M,
)


@dataclass(frozen=True)
class RefParam:
    label: str
    options: Dict[str, str] = field(default_factory=dict)


@dataclass(frozen=True)
class RefTransform:
    name: str
    collberg: str
    params: Sequence[RefParam]
    notes: str = ""

    @property
    def technique_dir(self) -> str:
        return f"{self.name.lower()}_variants"


REF_CATALOGUE: List[RefTransform] = [
    RefTransform(
        name="EncodeLiterals",
        collberg="data",
        params=[
            RefParam("ref_lit_xor", {"scheme": "xor"}),
            RefParam("ref_lit_sum", {"scheme": "sum"}),
            RefParam("ref_lit_mixed", {"scheme": "mixed"}),
        ],
        notes="Integer literals replaced by expressions that evaluate to them.",
    ),
    RefTransform(
        name="EncodeStrings",
        collberg="data",
        params=[
            RefParam("ref_str_xor", {"scheme": "xor"}),
            RefParam("ref_str_add", {"scheme": "add"}),
        ],
        notes="String literals stored encoded and decoded through a helper.",
    ),
    RefTransform(
        name="AddOpaque",
        collberg="control",
        params=[
            RefParam("ref_opq_true", {"kinds": "true"}),
            RefParam("ref_opq_junk", {"kinds": "junk"}),
            RefParam("ref_opq_both", {"kinds": "both"}),
        ],
        notes="Dead branches guarded by predicates whose value is fixed but not "
              "locally evident, built on a volatile so the compiler cannot fold "
              "them away.",
    ),
    RefTransform(
        name="RenameIdentifiers",
        collberg="layout",
        params=[
            RefParam("ref_ren_hex", {"style": "hex"}),
            RefParam("ref_ren_long", {"style": "long"}),
        ],
        notes="Local and file static identifiers renamed. Layout level, included "
              "so the label axis spans all three Collberg categories.",
    ),
]


def _mask_protected(src: str) -> Tuple[str, List[str]]:
    """Replace strings, chars, comments and preprocessor lines with placeholders.

    Rewrites then operate on code only, and the placeholders are restored
    afterwards. Doing this with a mask rather than with lookarounds keeps the
    rewrite rules readable and keeps literal data out of their reach.
    """
    stash: List[str] = []

    def take(m: re.Match) -> str:
        stash.append(m.group(0))
        return f"\x00{_encode_index(len(stash) - 1)}\x00"

    return _PROTECTED.sub(take, src), stash


# The placeholder index is written in letters, not digits. A digit here would be
# matched by the integer-literal rewrite and the placeholder would be mangled
# into an arithmetic expression, so the restore step would find nothing.
def _encode_index(i: int) -> str:
    return "".join(chr(ord("A") + int(d)) for d in str(i))


def _decode_index(s: str) -> int:
    return int("".join(str(ord(c) - ord("A")) for c in s))


def _restore(src: str, stash: Sequence[str]) -> str:
    return re.sub(r"\x00([A-J]+)\x00",
                  lambda m: stash[_decode_index(m.group(1))], src)


# --------------------------------------------------------------- EncodeLiterals

# A floating point literal is matched first and passed through unchanged. Left
# to the integer branch, "2.0" would be seen as the two integers 2 and 0 and
# rewritten into "(0xA ^ 0xB).(0xC ^ 0xD)", which is not an expression at all.
_LIT = re.compile(
    r"(?P<flt>(?:\d+\.\d*|\.\d+)(?:[eE][+-]?\d+)?[fFlL]?|\d+[eE][+-]?\d+[fFlL]?)"
    r"|\b(?P<int>0[xX][0-9a-fA-F]+|\d+)(?P<sfx>[uU]?[lL]{0,2})\b"
)


def encode_literals(src: str, rng: random.Random, scheme: str) -> str:
    code, stash = _mask_protected(src)

    def rewrite(m: re.Match) -> str:
        if m.group("flt") is not None:
            return m.group(0)
        raw, suffix = m.group("int"), m.group("sfx")
        try:
            val = int(raw, 0)
        except ValueError:
            return m.group(0)
        # Values above 2^31 are left alone: splitting them risks overflowing the
        # type the literal was written for, which changes the program's meaning.
        if val > 0x7FFFFFFF:
            return m.group(0)
        # The suffix goes on each operand, never on the parenthesised result:
        # "(0xA ^ 0xB)u" is not valid C, while "(0xAu ^ 0xBu)" is, and carries
        # the same type the original literal did.
        pick = scheme if scheme != "mixed" else rng.choice(["xor", "sum"])
        if pick == "xor":
            mask = rng.randrange(1, 0x7FFFFFFF)
            return f"(0x{mask:X}{suffix} ^ 0x{(val ^ mask):X}{suffix})"
        off = rng.randrange(1, 4096)
        return f"(0x{(val + off):X}{suffix} - 0x{off:X}{suffix})"

    return _restore(_LIT.sub(rewrite, code), stash)


# ---------------------------------------------------------------- EncodeStrings

_DECODER = """
static char {fn}_buf[{cap}][256];
static int {fn}_slot = 0;
static const char *{fn}(const unsigned char *enc, int n, int key) {{
    int s = {fn}_slot++ % {cap};
    char *out = {fn}_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)({expr});
    out[n < 255 ? n : 255] = '\\0';
    return out;
}}
"""


def encode_strings(src: str, rng: random.Random, scheme: str) -> str:
    """Move string literals into encoded byte arrays decoded at the use site.

    Only literals used as values are rewritten. A literal in an initialiser such
    as ``char buf[] = "text";`` is left alone, because a function call is not a
    valid initialiser there and rewriting it would not compile.
    """
    fn = f"dec_{rng.randrange(0x1000, 0xFFFF):x}"
    key = rng.randrange(1, 250)
    expr = "enc[i] ^ key" if scheme == "xor" else "enc[i] - key"
    enc_byte = (lambda b: b ^ key) if scheme == "xor" else (lambda b: (b + key) & 0xFF)

    lits: List[Tuple[str, bytes]] = []

    def take(m: re.Match) -> str:
        text = m.group(0)
        # Skip the initialiser case and anything a call cannot stand in for.
        body = text[1:-1].encode().decode("unicode_escape").encode("latin-1")
        if not body or len(body) > 200:
            return text
        lits.append((text, body))
        arr = ", ".join(f"0x{enc_byte(b):02X}" for b in body)
        return f"{fn}((const unsigned char[]){{{arr}}}, {len(body)}, {key})"

    out_lines: List[str] = []
    for line in src.split("\n"):
        stripped = line.lstrip()
        # Initialisers and declarations need compile time constants, and
        # preprocessor lines are not C expressions.
        if (stripped.startswith("#")
                or re.search(r"\[\s*\]\s*=", line)
                or re.match(r"\s*(static\s+)?(const\s+)?char\s+\w+\s*\[", line)):
            out_lines.append(line)
            continue
        out_lines.append(re.sub(r'"(?:[^"\\\n]|\\.)*"', take, line))

    if not lits:
        return src

    body = "\n".join(out_lines)
    decoder = _DECODER.format(fn=fn, cap=max(4, len(lits) + 2), expr=expr)
    # The decoder goes after the last #include so it can see size_t and friends.
    includes = [i for i, l in enumerate(body.split("\n")) if l.lstrip().startswith("#include")]
    parts = body.split("\n")
    at = (includes[-1] + 1) if includes else 0
    return "\n".join(parts[:at] + [decoder] + parts[at:])


# ------------------------------------------------------------------- AddOpaque

def _opaque_globals(tag: str) -> str:
    """Opaque state used by the inserted predicates.

    ``volatile`` is what makes the predicate opaque to the compiler rather than
    only to a reader: without it the optimiser folds ``k*k+k`` and deletes the
    dead branch, and the transformation leaves no trace in the output.
    """
    return (f"static volatile int opq_{tag} = 7;\n"
            f"static volatile int opq_{tag}_b = 3;\n")


def add_opaque(src: str, rng: random.Random, kinds: str) -> str:
    tag = f"{rng.randrange(0x1000, 0xFFFF):x}"

    def true_pred() -> str:
        k = f"opq_{tag}"
        # k*k+k is even for every integer k, so the guard always holds, but the
        # fact is not evident from the expression alone.
        return rng.choice([
            f"((({k} * {k} + {k}) % 2) == 0)",
            f"((({k} * ({k} + 1)) % 2) == 0)",
            f"(({k} * {k} - {k}) % 2 == 0)",
        ])

    def false_pred() -> str:
        k = f"opq_{tag}"
        b = f"opq_{tag}_b"
        # A square is never congruent to 2 modulo 4, so this never holds.
        return rng.choice([
            f"((({k} * {k}) % 4) == 2)",
            f"((({k} * {k} + {b} * {b}) % 4) == 3)",
        ])

    def junk(depth: int) -> str:
        v = f"jv_{rng.randrange(0x10000, 0xFFFFF):x}"
        ind = "    " * depth
        ops = [
            f"{ind}    {v} ^= ({v} << 3) | 0x{rng.randrange(1, 0xFFFF):X};",
            f"{ind}    {v} += ({v} >> 2) + 0x{rng.randrange(1, 0xFF):X};",
            f"{ind}    {v} = ({v} * 0x{rng.randrange(3, 0x3F):X}) % 0x7FFFFFFF;",
        ]
        rng.shuffle(ops)
        return (f"{ind}{{ int {v} = opq_{tag} ^ 0x{rng.randrange(1, 0xFFFF):X};\n"
                + "\n".join(ops[:rng.randint(1, 3)])
                + f"\n{ind}  (void){v}; }}")

    lines = src.split("\n")

    # Collect legal insertion points first, then sample from them. Sampling each
    # line independently starves small functions: a program with four candidate
    # lines would often receive nothing, and a class whose artifacts are
    # sometimes unmodified is a class the gate will reject for the wrong reason.
    candidates: List[Tuple[int, int]] = []
    depth = 0
    for idx, line in enumerate(lines):
        prev_depth = depth
        depth += line.count("{") - line.count("}")
        stripped = line.strip()
        # Insert only at a statement boundary inside a function body. Inserting
        # at file scope would place a statement where only declarations are legal.
        if prev_depth < 1 and depth < 1:
            continue
        if not (stripped.endswith(";") or stripped.endswith("{")):
            continue
        if stripped.startswith(("#", "//", "return", "case", "default",
                                "break", "continue", "goto", "else")):
            continue
        # An insertion here would sit between an unbraced if body and its else,
        # and the else would then bind to the inserted if. That compiles and
        # changes what the program computes, which is the worst kind of
        # failure: silent. The same applies to the while of a do-while.
        nxt = next((l.strip() for l in lines[idx + 1:] if l.strip()), "")
        if nxt.startswith(("else", "while")):
            continue
        candidates.append((idx, max(depth, 1)))

    if not candidates:
        return src

    take_n = max(2, min(len(candidates), round(len(candidates) * 0.45)))
    chosen = dict(rng.sample(candidates, take_n))

    out: List[str] = []
    for idx, line in enumerate(lines):
        out.append(line)
        if idx not in chosen:
            continue
        ind = chosen[idx]
        pad = "    " * ind
        pick = kinds if kinds != "both" else rng.choice(["true", "junk"])
        if pick == "junk":
            # Guarded by a predicate that never holds, so the junk is dead code
            # that still has to be represented in the translation unit.
            out.append(f"{pad}if ({false_pred()}) {{")
            out.append(junk(ind + 1))
            out.append(f"{pad}}}")
        else:
            # Guarded by a predicate that always holds, so the branch executes
            # and the body must be free of observable effect.
            out.append(f"{pad}if ({true_pred()}) {{ opq_{tag}_b ^= 0; }}")

    body = "\n".join(out)
    parts = body.split("\n")
    includes = [i for i, l in enumerate(parts) if l.lstrip().startswith("#include")]
    at = (includes[-1] + 1) if includes else 0
    return "\n".join(parts[:at] + [_opaque_globals(tag)] + parts[at:])


# ------------------------------------------------------------ RenameIdentifiers

_DECL = re.compile(
    r"\b(?:static\s+)?(?:const\s+)?(?:unsigned\s+|signed\s+)?"
    r"(?:int|long|short|char|float|double|size_t|unsigned|void)"
    r"(?:\s*\*+)?\s+([A-Za-z_]\w*)\s*(?=[=;,\[\)])"
)
_STRUCT_DECL = re.compile(r"\bstruct\s+\w+\s*\*?\s*([A-Za-z_]\w*)\s*(?=[=;,\[\)])")


def rename_identifiers(src: str, rng: random.Random, style: str) -> str:
    code, stash = _mask_protected(src)

    names = set()
    for pat in (_DECL, _STRUCT_DECL):
        for m in pat.finditer(code):
            n = m.group(1)
            if n in RESERVED or len(n) < 2:
                continue
            names.add(n)

    if not names:
        return src

    used: set = set()
    mapping: Dict[str, str] = {}
    for n in sorted(names):
        while True:
            if style == "hex":
                cand = f"v_{rng.randrange(0x100000, 0xFFFFFF):x}"
            else:
                cand = "".join(rng.choice("abcdefghijklmnopqrstuvwxyz")
                               for _ in range(rng.randint(14, 22)))
            if cand not in used and cand not in names:
                used.add(cand)
                mapping[n] = cand
                break

    pattern = re.compile(r"\b(" + "|".join(re.escape(n) for n in sorted(
        mapping, key=len, reverse=True)) + r")\b")
    code = pattern.sub(lambda m: mapping[m.group(1)], code)
    return _restore(code, stash)


# ------------------------------------------------------------------- dispatch

_APPLY = {
    "EncodeLiterals": lambda s, r, o: encode_literals(s, r, o.get("scheme", "xor")),
    "EncodeStrings": lambda s, r, o: encode_strings(s, r, o.get("scheme", "xor")),
    "AddOpaque": lambda s, r, o: add_opaque(s, r, o.get("kinds", "both")),
    "RenameIdentifiers": lambda s, r, o: rename_identifiers(s, r, o.get("style", "hex")),
}


def apply_transform(src: str, transform: str, options: Dict[str, str], seed: int) -> str:
    """Apply one transformation to one translation unit.

    The RNG is seeded from the caller's per artifact seed, so two artifacts of
    the same class on the same program differ in every randomised choice while
    regenerating either one reproduces it exactly.
    """
    if transform not in _APPLY:
        raise KeyError(
            f"{transform} has no reference implementation. Flatten and "
            "Virtualize rewrite the control flow graph and need Tigress."
        )
    return _APPLY[transform](src, random.Random(seed), options)


def validate() -> None:
    seen = set()
    labels = set()
    for t in REF_CATALOGUE:
        if t.name not in _APPLY:
            raise ValueError(f"{t.name} is in REF_CATALOGUE but has no implementation")
        if t.technique_dir in seen:
            raise ValueError(f"duplicate technique dir {t.technique_dir}")
        seen.add(t.technique_dir)
        if t.collberg not in {"layout", "data", "control"}:
            raise ValueError(f"{t.name}: bad collberg category")
        for p in t.params:
            if p.label in labels:
                raise ValueError(f"duplicate label {p.label}")
            if re.search(r"\d$", p.label):
                raise ValueError(f"{p.label}: labels must not end in a digit")
            if not re.fullmatch(r"[a-z][a-z0-9_]*", p.label):
                raise ValueError(f"{p.label}: labels must be lower snake case")
            labels.add(p.label)


if __name__ == "__main__":
    validate()
    n = sum(len(t.params) for t in REF_CATALOGUE)
    print(f"{len(REF_CATALOGUE)} reference classes, {n} parameterisations")
    for t in REF_CATALOGUE:
        print(f"  {t.name:18s} {t.collberg:8s} {[p.label for p in t.params]}")
