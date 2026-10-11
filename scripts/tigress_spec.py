"""
Tigress transformation catalogue for the source-level ObfuScope corpus.

This module is pure data plus a flag verifier. It holds no generation logic, so
that the transformation grid can be reviewed, edited, and cited without reading
the driver in ``build_corpus_tigress.py``.

Scope
-----
Source to source C only. Every transformation below is applied by Tigress to a
C translation unit and produces a C translation unit, which is the representation
the ObfuScope feature extractor (``obfuscope.features``) already operates on. No
compilation, no decompilation, no binary level tooling.

Why a data table
----------------
Tigress option names vary across releases. Rather than hardcode flags into the
driver, each transformation declares its options here and the driver asks
:func:`verify_against_installed_tigress` to confirm that every flag this file
names is actually recognised by the installed binary. A version mismatch then
surfaces as an explicit, named failure before any generation work begins, rather
than as a corpus full of silently skipped transformations.

Run the check directly:

    python3 scripts/tigress_spec.py --verify

Collberg mapping
----------------
Each entry carries a ``collberg`` field placing it in the layout / data / control
taxonomy of Collberg, Thomborson and Low (1997). This is what lets the corpus
table in the manuscript state the taxonomy position of every class rather than
asserting coverage.

Parameterisation labels
-----------------------
``obfuscope.labels.sub_technique_of`` derives the fine grained label from the
file stem by stripping a trailing integer. The driver therefore writes artifacts
as ``<param_label>_<seed>.c``, and every ``param_label`` below must not itself
end in a digit or the seed strip would eat part of the label. :func:`validate`
enforces this.
"""
from __future__ import annotations

import argparse
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass, field
from typing import Dict, List, Optional, Sequence

# Tigress target environment string. Override with --environment if the local
# install targets a different triple.
DEFAULT_ENVIRONMENT = "x86_64:Linux:Gcc:4.6"


@dataclass(frozen=True)
class Parameterisation:
    """One concrete option setting for a transformation.

    ``label`` becomes the ``sub_technique`` ground-truth label, so it must be
    stable across seeds and must not end in a digit.
    """

    label: str
    options: Dict[str, str] = field(default_factory=dict)


@dataclass(frozen=True)
class Transform:
    """One coarse transformation family, the provenance target class.

    ``requires`` names transformations that Tigress needs to have run earlier in
    the same invocation. Opaque predicate machinery in particular has to be
    initialised before a transformation can draw on it.
    """

    name: str
    collberg: str
    params: Sequence[Parameterisation]
    requires: Sequence[str] = ()
    notes: str = ""

    @property
    def technique_dir(self) -> str:
        """Directory name carrying the coarse label, matching the repo layout."""
        return f"{self.name.lower()}_variants"


# Transformations that only set up state for later ones. They are never a
# prediction target and never get their own output directory.
SETUP_TRANSFORMS: Dict[str, Dict[str, str]] = {
    "InitEntropy": {"InitEntropyKinds": "vars"},
    "InitOpaque": {"InitOpaqueStructs": "list,array,input"},
}


CATALOGUE: List[Transform] = [
    Transform(
        name="Flatten",
        collberg="control",
        params=[
            Parameterisation("flat_switch", {"FlattenDispatch": "switch"}),
            Parameterisation("flat_goto", {"FlattenDispatch": "goto"}),
            Parameterisation("flat_indirect", {"FlattenDispatch": "indirect"}),
            Parameterisation(
                "flat_cond_compute",
                {"FlattenDispatch": "switch", "FlattenConditionalKinds": "compute"},
            ),
            Parameterisation(
                "flat_cond_flag",
                {"FlattenDispatch": "switch", "FlattenConditionalKinds": "flag"},
            ),
        ],
        notes="Control flow flattening. The dispatch variants are structurally "
              "distinct enough to serve as a fine grained provenance target.",
    ),
    Transform(
        name="Virtualize",
        collberg="control",
        params=[
            Parameterisation("virt_switch", {"VirtualizeDispatch": "switch"}),
            Parameterisation("virt_direct", {"VirtualizeDispatch": "direct"}),
            Parameterisation("virt_indirect", {"VirtualizeDispatch": "indirect"}),
            Parameterisation("virt_ifnest", {"VirtualizeDispatch": "ifnest"}),
            Parameterisation(
                "virt_operands_stack",
                {"VirtualizeDispatch": "switch", "VirtualizeOperands": "stack"},
            ),
        ],
        notes="Bytecode interpreter synthesis. Output size grows quickly with "
              "function size, so very large inputs should be excluded or scoped "
              "with --Functions.",
    ),
    Transform(
        name="EncodeArithmetic",
        collberg="data",
        params=[
            Parameterisation("arith_default", {}),
            Parameterisation("arith_integer", {"EncodeArithmeticKinds": "integer"}),
        ],
        notes="Mixed boolean arithmetic rewriting of integer expressions.",
    ),
    Transform(
        name="EncodeLiterals",
        collberg="data",
        params=[
            Parameterisation("lit_string", {"EncodeLiteralsKinds": "string"}),
            Parameterisation("lit_integer", {"EncodeLiteralsKinds": "integer"}),
            Parameterisation("lit_both", {"EncodeLiteralsKinds": "string,integer"}),
        ],
        notes="String and integer literal encoding.",
    ),
    Transform(
        name="AddOpaque",
        collberg="control",
        params=[
            Parameterisation(
                "opaque_true",
                {"AddOpaqueStructs": "list", "AddOpaqueKinds": "true"},
            ),
            Parameterisation(
                "opaque_junk",
                {"AddOpaqueStructs": "list", "AddOpaqueKinds": "junk"},
            ),
            Parameterisation(
                "opaque_call",
                {"AddOpaqueStructs": "array", "AddOpaqueKinds": "call"},
            ),
        ],
        requires=("InitEntropy", "InitOpaque"),
        notes="Opaque predicate insertion. Needs the opaque structure pool to be "
              "initialised first, hence the requires chain.",
    ),
    Transform(
        name="Split",
        collberg="layout",
        params=[
            Parameterisation("split_block", {"SplitKinds": "block"}),
            Parameterisation("split_deep", {"SplitKinds": "deep"}),
            Parameterisation("split_recursive", {"SplitKinds": "recursive"}),
        ],
        notes="Function splitting. Layout level, included so the corpus spans all "
              "three Collberg categories rather than only data and control.",
    ),
]


def validate() -> None:
    """Fail loudly on catalogue mistakes that would corrupt the label axis."""
    seen_dirs = set()
    # Parameterisation labels become sub_technique values, and sub_technique is
    # read from the file stem alone with no reference to the parent directory.
    # Two transformations sharing a label would merge into one sub_technique
    # class spanning two coarse classes, a label error nothing downstream catches.
    global_labels: Dict[str, str] = {}
    for t in CATALOGUE:
        if t.technique_dir in seen_dirs:
            raise ValueError(f"duplicate technique dir: {t.technique_dir}")
        seen_dirs.add(t.technique_dir)
        if t.collberg not in {"layout", "data", "control"}:
            raise ValueError(f"{t.name}: collberg must be layout, data or control")
        if not t.params:
            raise ValueError(f"{t.name}: needs at least one parameterisation")
        labels = [p.label for p in t.params]
        if len(set(labels)) != len(labels):
            raise ValueError(f"{t.name}: duplicate parameterisation labels")
        for p in t.params:
            # A trailing digit would be consumed by sub_technique_of's seed strip.
            if re.search(r"\d$", p.label):
                raise ValueError(
                    f"{t.name}/{p.label}: param labels must not end in a digit, "
                    "because labels.sub_technique_of strips a trailing integer"
                )
            if not re.fullmatch(r"[a-z][a-z0-9_]*", p.label):
                raise ValueError(f"{t.name}/{p.label}: label must be lower snake case")
            if p.label in global_labels:
                raise ValueError(
                    f"{t.name}/{p.label}: label already used by "
                    f"{global_labels[p.label]}. Parameterisation labels must be "
                    "unique across the whole catalogue, because sub_technique is "
                    "derived from the file stem without the parent directory."
                )
            global_labels[p.label] = t.name
        for dep in t.requires:
            if dep not in SETUP_TRANSFORMS:
                raise ValueError(f"{t.name}: unknown prerequisite {dep}")


def all_flag_names() -> List[str]:
    """Every Tigress option name this catalogue depends on."""
    flags = {"Environment", "Seed", "out", "Transform", "Functions"}
    for opts in SETUP_TRANSFORMS.values():
        flags.update(opts)
    for t in CATALOGUE:
        flags.add(t.name)
        for p in t.params:
            flags.update(p.options)
    return sorted(flags)


def verify_against_installed_tigress(binary: str = "tigress") -> List[str]:
    """Return the flags this catalogue names that the installed Tigress does not.

    An empty list means the catalogue matches the installed version. A non empty
    list is the precise edit required, which is the whole point of keeping the
    options in a data table.
    """
    if shutil.which(binary) is None:
        raise FileNotFoundError(
            f"'{binary}' not on PATH. Install Tigress and set TIGRESS_HOME, or pass "
            "--tigress /path/to/tigress."
        )
    try:
        proc = subprocess.run(
            [binary, "--help"], capture_output=True, text=True, timeout=120
        )
    except subprocess.TimeoutExpired:
        raise RuntimeError("tigress --help timed out")
    help_text = (proc.stdout or "") + (proc.stderr or "")
    if not help_text.strip():
        raise RuntimeError("tigress --help produced no output; cannot verify flags")
    # Transform *names* appear as --Transform=Name, option names as --Name=.
    missing = []
    for flag in all_flag_names():
        if flag in {"Transform", "Environment", "Seed", "out", "Functions"}:
            needle = f"--{flag}"
        else:
            needle = flag
        if needle not in help_text:
            missing.append(flag)
    return missing


def verify_against_labels_module() -> List[str]:
    """Return the mismatches between this catalogue and ``labels.TECHNIQUE_DIRS``.

    ``labels.label_path`` returns ``None`` for any directory it does not
    recognise and ``build_dataset`` drops those rows without comment. A
    catalogue entry missing from ``labels.py`` therefore produces a feature
    table that is quietly short of a whole class, which is exactly the kind of
    defect that is easier to catch here than in the results.
    """
    import os as _os

    src = _os.path.join(_os.path.dirname(_os.path.abspath(__file__)), "..", "src")
    if src not in sys.path:
        sys.path.insert(0, src)
    from obfuscope.labels import TECHNIQUE_DIRS, TIGRESS_TECHNIQUE_DIRS

    problems = []
    for t in CATALOGUE:
        if t.technique_dir not in TECHNIQUE_DIRS:
            problems.append(
                f"{t.technique_dir} is in the catalogue but not in "
                "labels.TECHNIQUE_DIRS, so its artifacts would be dropped"
            )
    catalogue_dirs = {t.technique_dir for t in CATALOGUE}
    for d in TIGRESS_TECHNIQUE_DIRS:
        if d not in catalogue_dirs:
            problems.append(
                f"{d} is in labels.TIGRESS_TECHNIQUE_DIRS but no catalogue entry "
                "generates it, so the list is stale"
            )
    return problems


def summary_table() -> str:
    """Text summary suitable for pasting into the manuscript corpus section."""
    rows = [("transformation", "collberg", "parameterisations", "requires")]
    for t in CATALOGUE:
        rows.append(
            (t.name, t.collberg, str(len(t.params)), ",".join(t.requires) or "none")
        )
    widths = [max(len(r[i]) for r in rows) for i in range(4)]
    out = []
    for i, r in enumerate(rows):
        out.append("  ".join(c.ljust(widths[j]) for j, c in enumerate(r)))
        if i == 0:
            out.append("  ".join("-" * w for w in widths))
    n_cells = sum(len(t.params) for t in CATALOGUE)
    out.append("")
    out.append(f"{len(CATALOGUE)} coarse classes, {n_cells} parameterisations total")
    return "\n".join(out)


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(description="Inspect or verify the Tigress catalogue.")
    ap.add_argument("--verify", action="store_true",
                    help="check every catalogue flag against the installed Tigress")
    ap.add_argument("--tigress", default="tigress", help="path to the tigress binary")
    ap.add_argument("--verify-labels", action="store_true",
                    help="check the catalogue against obfuscope.labels.TECHNIQUE_DIRS")
    args = ap.parse_args(argv)

    validate()
    print(summary_table())

    if args.verify_labels:
        problems = verify_against_labels_module()
        print()
        if problems:
            print("CATALOGUE AND labels.py DISAGREE:")
            for p in problems:
                print(f"  {p}")
            return 1
        print("catalogue and labels.TECHNIQUE_DIRS agree")

    if args.verify:
        missing = verify_against_installed_tigress(args.tigress)
        print()
        if missing:
            print("FLAGS NOT FOUND IN INSTALLED TIGRESS:")
            for f in missing:
                print(f"  {f}")
            print("\nEdit CATALOGUE or SETUP_TRANSFORMS to match your version.")
            return 1
        print("all catalogue flags recognised by the installed Tigress")
    return 0


if __name__ == "__main__":
    sys.exit(main())
