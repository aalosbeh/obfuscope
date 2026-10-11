"""
Source level obfuscated corpus generation with Tigress.

Builds a corpus of obfuscated C artifacts from benign C programs, laid out so
that the existing ObfuScope pipeline (``obfuscope.labels`` then
``obfuscope.build_dataset``) consumes it with no changes:

    <out>/tigress_c/<suite>_<program>/<transform>_variants/<param_label>_<seed>.c
           cohort     sample_id        technique              sub_technique

Three label axes fall out of that path for free:

- ``technique``      the coarse transformation, the provenance target
- ``sub_technique``  the parameterisation, the fine grained target
- ``malware_family`` ``labels.parse_family`` cuts the sample id at the first
                     underscore, so naming a program ``coreutils_ls`` yields the
                     group ``coreutils``. That is the benign analogue of the
                     leave malware families out protocol: leave whole program
                     suites out, and the held out programs are genuinely
                     unrelated to the ones trained on.

Why per artifact seeding matters
--------------------------------
``--Seed`` is passed a value derived from (program, transform, parameterisation,
replicate), so two artifacts of the same class differ in their randomised
choices. This is the property the previous corpus lacked: without it a generator
can emit byte identical output for every input, which makes class membership
trivially recoverable and inflates every downstream metric. The diversity gate in
``scripts/diversity_gate.py`` exists to prove per artifact seeding actually
produced variation rather than to assume it.

Yield accounting
----------------
Tigress does not succeed on every program. Virtualize in particular fails or
explodes on large functions. Failures are recorded, never silently dropped, and
the per transform success rate is reported at the end. Differential yield is a
selection bias: if Virtualize only succeeds on small programs, then program size
becomes a proxy for the class label and the attribution result is confounded.
The summary prints the yield spread so that bias is visible before it reaches
the feature table.

Usage
-----
    # smallest useful run
    python3 scripts/build_corpus_tigress.py \
        --programs programs.txt --out data/corpus --replicates 3

    # one HTC shard of many
    python3 scripts/build_corpus_tigress.py \
        --programs programs.txt --out data/corpus --replicates 3 \
        --shard-index 7 --num-shards 64

``programs.txt`` is one entry per line, either ``/path/to/prog.c`` or
``/path/to/prog.c<TAB>suite_name<TAB>functions``. Blank lines and ``#`` comments
are ignored. ``functions`` defaults to ``main`` and is passed to ``--Functions``.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys
import time
import zlib
from collections import Counter, defaultdict
from dataclasses import asdict, dataclass
from typing import Dict, Iterator, List, Optional, Sequence, Tuple

_HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, _HERE)
sys.path.insert(0, os.path.join(_HERE, "..", "src"))

from tigress_spec import (  # noqa: E402
    CATALOGUE,
    DEFAULT_ENVIRONMENT,
    SETUP_TRANSFORMS,
    Transform,
    Parameterisation,
    validate,
    verify_against_installed_tigress,
)
import reference_backend  # noqa: E402

# The cohort is the first path component and is carried into the feature table
# as a column, so writing reference artifacts under a different cohort makes the
# generator of every row recoverable after the fact. Numbers from the two
# backends are not comparable and must not be pooled.
COHORTS = {"tigress": "tigress_c", "reference": "reference_c"}


@dataclass
class Program:
    path: str
    suite: str
    functions: str = "main"

    @property
    def stem(self) -> str:
        return os.path.splitext(os.path.basename(self.path))[0]

    @property
    def sample_id(self) -> str:
        """Directory name. parse_family cuts at the first underscore, so the
        suite becomes the grouping family and the program stays distinct."""
        return f"{self.suite}_{self.stem}"


@dataclass
class Cell:
    """One artifact to generate."""

    program: Program
    transform: Transform
    param: Parameterisation
    replicate: int
    cohort: str = "tigress_c"

    @property
    def seed(self) -> int:
        """Deterministic, collision resistant seed for this exact artifact.

        Derived from the cell coordinates rather than drawn from a global counter
        so that regenerating one shard reproduces byte identical output without
        regenerating the whole corpus.
        """
        key = f"{self.program.sample_id}|{self.transform.name}|{self.param.label}|{self.replicate}"
        return int(hashlib.sha256(key.encode()).hexdigest()[:8], 16)

    @property
    def rel_path(self) -> str:
        return os.path.join(
            self.cohort,
            self.program.sample_id,
            self.transform.technique_dir,
            f"{self.param.label}_{self.replicate}.c",
        )


@dataclass
class Result:
    rel_path: str
    program: str
    suite: str
    transform: str
    param: str
    replicate: int
    seed: int
    ok: bool
    bytes_out: int
    seconds: float
    error: str = ""
    backend: str = "tigress"
    bytes_in: int = 0


def read_programs(path: str) -> List[Program]:
    # Relative entries resolve against the directory holding the manifest, not
    # the current working directory, so the manifest travels with the sources it
    # names. On an execution point the manifest and the unpacked programs land
    # in the same scratch directory, which is the case this serves.
    base = os.path.dirname(os.path.abspath(path))
    progs: List[Program] = []
    with open(path) as fh:
        for raw in fh:
            line = raw.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split("\t")
            src = parts[0].strip()
            if not os.path.isabs(src):
                src = os.path.join(base, src)
            suite = parts[1].strip() if len(parts) > 1 and parts[1].strip() else "misc"
            funcs = parts[2].strip() if len(parts) > 2 and parts[2].strip() else "main"
            if "_" in suite:
                raise ValueError(
                    f"suite '{suite}' contains an underscore, which would split the "
                    "grouping label; use a single token such as 'coreutils'"
                )
            if not os.path.isfile(src):
                raise FileNotFoundError(f"program not found: {src}")
            progs.append(Program(path=os.path.abspath(src), suite=suite, functions=funcs))
    if not progs:
        raise ValueError(f"no programs read from {path}")
    return progs


def enumerate_cells(programs: Sequence[Program], replicates: int,
                    catalogue: Sequence[Transform], cohort: str) -> List[Cell]:
    cells = []
    for p in programs:
        for t in catalogue:
            for param in t.params:
                for r in range(replicates):
                    cells.append(Cell(p, t, param, r, cohort))
    return cells


def in_shard(rel_path: str, shard_index: int, num_shards: int) -> bool:
    """CRC32 over the artifact path, matching build_dataset._in_shard so that
    corpus generation and feature extraction partition identically."""
    if num_shards <= 1:
        return True
    return (zlib.crc32(rel_path.encode("utf-8")) % num_shards) == shard_index


def build_command(cell: Cell, out_path: str, environment: str, binary: str) -> List[str]:
    """Assemble one Tigress invocation.

    Tigress reads options positionally: each --Transform=X is followed by the
    options that belong to it, so prerequisites are emitted first and the target
    transformation last.
    """
    cmd = [binary, f"--Environment={environment}", f"--Seed={cell.seed}"]

    for dep in cell.transform.requires:
        cmd.append(f"--Transform={dep}")
        for k, v in SETUP_TRANSFORMS[dep].items():
            cmd.append(f"--{k}={v}")
        cmd.append(f"--Functions={cell.program.functions}")

    cmd.append(f"--Transform={cell.transform.name}")
    for k, v in cell.param.options.items():
        cmd.append(f"--{k}={v}")
    cmd.append(f"--Functions={cell.program.functions}")

    cmd.append(f"--out={out_path}")
    cmd.append(cell.program.path)
    return cmd


def compile_check(c_path: str, cc: str) -> Tuple[bool, str]:
    """Syntax level validity check on a generated artifact.

    Not a semantics check. It only confirms Tigress emitted compilable C, which
    catches the failure mode where a transformation produces truncated output and
    the feature extractor happily reads it as a short file.
    """
    try:
        proc = subprocess.run(
            [cc, "-fsyntax-only", "-w", c_path],
            capture_output=True, text=True, timeout=180,
        )
    except (subprocess.TimeoutExpired, FileNotFoundError) as exc:
        return False, f"compile check unavailable: {exc}"
    if proc.returncode != 0:
        return False, (proc.stderr or "").strip().splitlines()[:1][0] if proc.stderr else "cc failed"
    return True, ""


def _generate_tigress(cell: Cell, dest: str, environment: str, binary: str,
                      timeout: int) -> str:
    """Invoke Tigress. Returns an empty string on success, else the error."""
    cmd = build_command(cell, dest, environment, binary)
    try:
        proc = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)
    except subprocess.TimeoutExpired:
        return f"timeout after {timeout}s"
    except Exception as exc:  # noqa: BLE001
        return f"{type(exc).__name__}: {exc}"[:300]
    if proc.returncode != 0:
        err = (proc.stderr or proc.stdout or "").strip()
        return err.splitlines()[-1][:300] if err else "nonzero exit"
    if not os.path.isfile(dest) or os.path.getsize(dest) == 0:
        return "tigress reported success but produced no output"
    return ""


def _generate_reference(cell: Cell, dest: str) -> str:
    """Apply the in process reference transformation. In process rather than a
    subprocess because there is no binary to call, which also means a defect in
    the backend surfaces as a Python exception with a traceback rather than as an
    opaque nonzero exit."""
    try:
        with open(cell.program.path) as fh:
            src = fh.read()
        out = reference_backend.apply_transform(
            src, cell.transform.name, dict(cell.param.options), cell.seed
        )
    except Exception as exc:  # noqa: BLE001
        return f"{type(exc).__name__}: {exc}"[:300]
    if not out.strip():
        return "reference backend produced no output"
    with open(dest, "w") as fh:
        fh.write(out)
    return ""


def run_cell(cell: Cell, out_root: str, environment: str, binary: str,
             timeout: int, cc: Optional[str], backend: str) -> Result:
    rel = cell.rel_path
    dest = os.path.join(out_root, rel)
    os.makedirs(os.path.dirname(dest), exist_ok=True)

    t0 = time.time()
    if backend == "reference":
        err = _generate_reference(cell, dest)
    else:
        err = _generate_tigress(cell, dest, environment, binary, timeout)
    ok = not err

    if ok and cc:
        good, msg = compile_check(dest, cc)
        if not good:
            ok = False
            err = f"compile check failed: {msg}"[:300]

    if not ok and os.path.isfile(dest):
        os.remove(dest)

    return Result(
        rel_path=rel,
        program=cell.program.sample_id,
        suite=cell.program.suite,
        transform=cell.transform.name,
        param=cell.param.label,
        replicate=cell.replicate,
        seed=cell.seed,
        ok=ok,
        bytes_out=os.path.getsize(dest) if ok else 0,
        seconds=round(time.time() - t0, 3),
        error=err,
        backend=backend,
        bytes_in=os.path.getsize(cell.program.path),
    )


def report(results: Sequence[Result]) -> Dict[str, object]:
    by_transform: Dict[str, List[Result]] = defaultdict(list)
    for r in results:
        by_transform[r.transform].append(r)

    lines = ["", "per transform yield", "-------------------"]
    yields = {}
    for name in sorted(by_transform):
        rs = by_transform[name]
        n_ok = sum(1 for r in rs if r.ok)
        rate = n_ok / len(rs) if rs else 0.0
        yields[name] = rate
        progs_ok = len({r.program for r in rs if r.ok})
        ratios = [r.bytes_out / r.bytes_in for r in rs if r.ok and r.bytes_in]
        exp = f"  mean size x{sum(ratios) / len(ratios):.2f}" if ratios else ""
        lines.append(
            f"  {name:18s} {n_ok:5d}/{len(rs):<5d} ({rate:6.1%})  "
            f"programs covered: {progs_ok}{exp}"
        )

    n_ok_total = sum(1 for r in results if r.ok)
    lines.append("")
    lines.append(f"  total {n_ok_total}/{len(results)} artifacts written")

    if yields:
        spread = max(yields.values()) - min(yields.values())
        lines.append(f"  yield spread across transforms: {spread:.1%}")
        if spread > 0.20:
            lines.append(
                "  WARNING: yield differs by more than 20 points across transforms. "
                "If failures correlate with program size, program size becomes a "
                "proxy for the class label. Inspect failures before using this corpus."
            )

    errs = Counter(r.error.split(":")[0] for r in results if not r.ok and r.error)
    if errs:
        lines.append("")
        lines.append("  failure modes:")
        for kind, n in errs.most_common(8):
            lines.append(f"    {n:5d}  {kind[:70]}")

    print("\n".join(lines))
    return {"yields": yields, "n_ok": n_ok_total, "n_total": len(results)}


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[1],
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--programs", required=True, help="program manifest, one per line")
    ap.add_argument("--out", required=True, help="corpus root to write under")
    ap.add_argument("--backend", choices=sorted(COHORTS), default="tigress",
                    help="tigress calls the installed binary; reference uses the "
                         "token level stand in in scripts/reference_backend.py, "
                         "which exercises the chain without Tigress but is not "
                         "Tigress and whose numbers are not Tigress numbers")
    ap.add_argument("--replicates", type=int, default=3,
                    help="distinct seeds per (program, transform, parameterisation)")
    ap.add_argument("--environment", default=DEFAULT_ENVIRONMENT)
    ap.add_argument("--tigress", default="tigress", help="path to the tigress binary")
    ap.add_argument("--timeout", type=int, default=600, help="per artifact seconds")
    ap.add_argument("--compile-check", dest="cc", default=None, metavar="CC",
                    help="verify each artifact compiles, e.g. --compile-check gcc")
    ap.add_argument("--shard-index", type=int, default=0)
    ap.add_argument("--num-shards", type=int, default=1)
    ap.add_argument("--manifest", default=None,
                    help="where to write the JSONL generation log "
                         "(default <out>/generation_<shard>.jsonl)")
    ap.add_argument("--dry-run", action="store_true",
                    help="print the cell count and one sample command, generate nothing")
    ap.add_argument("--skip-verify", action="store_true",
                    help="do not check catalogue flags against the installed Tigress")
    args = ap.parse_args(argv)

    if args.backend == "reference":
        reference_backend.validate()
        catalogue: Sequence[Transform] = reference_backend.REF_CATALOGUE
    else:
        validate()
        catalogue = CATALOGUE
    cohort = COHORTS[args.backend]

    programs = read_programs(args.programs)
    cells = enumerate_cells(programs, args.replicates, catalogue, cohort)
    mine = [c for c in cells if in_shard(c.rel_path, args.shard_index, args.num_shards)]

    print(f"backend            {args.backend}")
    print(f"cohort             {cohort}")
    print(f"programs           {len(programs)}")
    print(f"suites             {len({p.suite for p in programs})}")
    print(f"classes            {len(catalogue)}")
    print(f"parameterisations  {sum(len(t.params) for t in catalogue)}")
    print(f"replicates         {args.replicates}")
    print(f"cells total        {len(cells)}")
    print(f"cells this shard   {len(mine)}  (shard {args.shard_index}/{args.num_shards})")
    if args.backend == "reference":
        print("\nNOTE: the reference backend is a stand in, not Tigress. Results "
              "obtained with it validate the harness and the gate. They are not "
              "measurements of Tigress and must be reported as such.")

    if args.dry_run:
        if mine and args.backend == "tigress":
            c = mine[0]
            print("\nexample command:")
            print("  " + " ".join(build_command(c, os.path.join(args.out, c.rel_path),
                                                args.environment, args.tigress)))
        elif mine:
            c = mine[0]
            print(f"\nexample cell:\n  {c.rel_path}  "
                  f"transform={c.transform.name} options={dict(c.param.options)} "
                  f"seed={c.seed}")
        return 0

    if args.backend == "tigress" and not args.skip_verify:
        missing = verify_against_installed_tigress(args.tigress)
        if missing:
            print("\nERROR: these catalogue flags are not recognised by the installed "
                  "Tigress:", file=sys.stderr)
            for f in missing:
                print(f"  {f}", file=sys.stderr)
            print("Edit scripts/tigress_spec.py to match your version, or rerun with "
                  "--skip-verify to proceed anyway.", file=sys.stderr)
            return 2

    os.makedirs(args.out, exist_ok=True)
    manifest = args.manifest or os.path.join(
        args.out, f"generation_{args.shard_index:04d}.jsonl")
    os.makedirs(os.path.dirname(os.path.abspath(manifest)), exist_ok=True)

    results: List[Result] = []
    t0 = time.time()
    with open(manifest, "w") as mh:
        for i, cell in enumerate(mine, 1):
            res = run_cell(cell, args.out, args.environment, args.tigress,
                           args.timeout, args.cc, args.backend)
            results.append(res)
            mh.write(json.dumps(asdict(res)) + "\n")
            mh.flush()
            if i % 50 == 0 or i == len(mine):
                rate = sum(1 for r in results if r.ok) / len(results)
                print(f"  [{i}/{len(mine)}] ok={rate:.1%} "
                      f"elapsed={time.time() - t0:.0f}s", flush=True)

    stats = report(results)
    print(f"\nmanifest: {manifest}")
    print("next: python3 -m obfuscope.build_dataset --corpus %s --out data/features.csv"
          % args.out)
    print("then:  python3 scripts/diversity_gate.py --features data/features.csv")
    return 0 if stats["n_ok"] else 1


if __name__ == "__main__":
    sys.exit(main())
