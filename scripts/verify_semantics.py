"""
Semantic preservation check for generated artifacts.

An obfuscating transformation is only valid if it preserves behaviour. A corpus
of artifacts that compile but compute something different is not a corpus of
obfuscated programs, and a provenance classifier trained on it would partly be
learning which transformations are broken.

The check is direct: compile the original program, run it, keep its standard
output and its exit status; then for every artifact, compile, run, and compare
both. The input programs are deterministic and print to standard output, which
is what makes the comparison a usable oracle. Standard output and exit status
are compared and reported separately (``output_differs``,
``exit_status_differs``); an artifact counts as preserved only when both match.
Compile and run timeouts are caught and counted, not raised.

Every compile uses ``-std=c99 -w -O0`` by default (``--std``, ``--opt``), so the
result does not depend on the compiler's default dialect; the compiler, its
version and the flags are recorded in the JSON report.

Two modes
---------
corpus      (``--corpus``) compiles and runs the artifacts on disk. This is the
            number that describes the released corpus.
regenerate  (default) regenerates artifacts with the reference backend at
            replicate indices the corpus does not hold (8 and 9 by default; the
            pilot corpus holds 0..7), seeded exactly as build_corpus_tigress
            seeds the corpus, from ``<sample_id>|<transformation>|
            <parameterisation>|<replicate>``. The stream depends on the
            sample_id, not on any file path, so it is the same on every machine.

This is reported as a rate, not asserted as a property. A transformation with a
low preservation rate is a finding about that transformation, and the rate
belongs in the corpus table alongside the artifact counts.

Usage
-----
    # regenerate replicates 8 and 9 of every cell and check them
    python3 scripts/verify_semantics.py --programs corpus_inputs/programs.tsv \\
        --replicates 2 --report results/semantics.json

    # check artifacts already on disk against their source programs
    python3 scripts/verify_semantics.py --corpus data/pilot_corpus \\
        --programs corpus_inputs/programs.tsv --report results/semantics.json
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import subprocess
import sys
import tempfile
from collections import defaultdict
from typing import Dict, List, Optional, Sequence, Tuple

_HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, _HERE)

from reference_backend import REF_CATALOGUE, apply_transform  # noqa: E402


# Compiler settings. -std=c99 pins the language dialect so the check does not
# depend on a compiler's default (gnu17 on current clang, gnu11 or gnu17 on
# gcc); -O0 keeps the compiler from folding away behaviour the transformation
# introduced. Both are recorded in the JSON report.
DEFAULT_STD = "c99"
DEFAULT_OPT = "0"

# The released pilot corpus holds replicates 0..7 of every (program,
# transformation, parameterisation) cell. The regenerate mode defaults to
# replicates 8 and 9, which the corpus does not contain.
CORPUS_REPLICATES = 8
DEFAULT_FIRST_REPLICATE = 8

# Counter names, in report order. They are documented in the JSON report.
COUNTER_KEYS = (
    "attempted", "preserved", "compile_failed", "compile_timeout",
    "run_timeout", "transform_failed", "behaviour_differs", "output_differs",
    "exit_status_differs", "output_and_exit_status_differ",
)
COUNTER_DEFINITIONS = {
    "attempted": "artifacts checked against a usable baseline",
    "preserved": "compiled, ran to completion, and both standard output and "
                 "exit status equal the original program's",
    "compile_failed": "did not compile, including compile timeouts",
    "compile_timeout": "subset of compile_failed: the compiler timed out",
    "run_timeout": "compiled but did not finish within the timeout",
    "transform_failed": "regenerate mode only: the transformation raised",
    "behaviour_differs": "ran to completion but standard output or exit status "
                         "differs; attempted = preserved + compile_failed + "
                         "run_timeout + transform_failed + behaviour_differs",
    "output_differs": "standard output differs (whatever the exit status)",
    "exit_status_differs": "exit status differs (whatever the standard output)",
    "output_and_exit_status_differ": "both differ; behaviour_differs = "
                                     "output_differs + exit_status_differs - "
                                     "output_and_exit_status_differ",
}


def _new_counter() -> Dict[str, int]:
    return {k: 0 for k in COUNTER_KEYS}


def compile_flags(std: str = DEFAULT_STD, opt: str = DEFAULT_OPT) -> List[str]:
    flags = ["-w", f"-O{opt}"]
    if std:
        flags.insert(0, f"-std={std}")
    return flags


def compile_and_run(src_path: str, cc: str, timeout: int,
                    std: str = DEFAULT_STD, opt: str = DEFAULT_OPT) -> Dict:
    """Compile one translation unit, run it, and capture stdout and exit status.

    Returns a dict with ``ok`` (compiled and ran to completion), ``stage``
    (``None``, ``"compile"``, ``"compile_timeout"`` or ``"run_timeout"``),
    ``stdout``, ``exit_status`` (the return code; negative when a signal ended
    the process) and ``error``. Compile and run timeouts are caught and
    reported rather than raised.
    """
    with tempfile.TemporaryDirectory() as td:
        exe = os.path.join(td, "a.out")
        cmd = [cc, *compile_flags(std, opt), "-o", exe, src_path]
        try:
            c = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)
        except subprocess.TimeoutExpired:
            return {"ok": False, "stage": "compile_timeout", "stdout": "",
                    "exit_status": None, "error": "compilation timed out"}
        if c.returncode != 0:
            first = (c.stderr or "").strip().splitlines()
            return {"ok": False, "stage": "compile", "stdout": "",
                    "exit_status": None,
                    "error": (first[0][:160] if first else "compile failed")}
        try:
            r = subprocess.run([exe], capture_output=True, text=True,
                               timeout=timeout)
        except subprocess.TimeoutExpired:
            return {"ok": False, "stage": "run_timeout", "stdout": "",
                    "exit_status": None, "error": "execution timed out"}
        return {"ok": True, "stage": None, "stdout": r.stdout,
                "exit_status": int(r.returncode), "error": ""}


def classify(base: Dict, got: Dict) -> Tuple[str, List[str], str]:
    """Compare one artifact run against the original program's run.

    Returns ``(outcome, counters, reason)`` where ``outcome`` is
    ``"preserved"`` or ``"failed"``, ``counters`` lists every counter in
    ``COUNTER_KEYS`` (other than ``attempted``) to increment, and ``reason`` is
    a short human readable cause ("" when preserved).
    """
    if not got["ok"]:
        if got["stage"] == "compile_timeout":
            return "failed", ["compile_failed", "compile_timeout"], got["error"]
        if got["stage"] == "run_timeout":
            return "failed", ["run_timeout"], got["error"]
        return "failed", ["compile_failed"], got["error"]
    out_diff = got["stdout"] != base["stdout"]
    exit_diff = got["exit_status"] != base["exit_status"]
    if not out_diff and not exit_diff:
        return "preserved", ["preserved"], ""
    counters = ["behaviour_differs"]
    if out_diff:
        counters.append("output_differs")
    if exit_diff:
        counters.append("exit_status_differs")
    if out_diff and exit_diff:
        counters.append("output_and_exit_status_differ")
        reason = (f"standard output and exit status differ (exit "
                  f"{base['exit_status']} expected, {got['exit_status']} got)")
    elif out_diff:
        reason = "standard output differs"
    else:
        reason = (f"exit status differs ({base['exit_status']} expected, "
                  f"{got['exit_status']} got)")
    return "failed", counters, reason


def artifact_seed(sample_id: str, transform: str, label: str, replicate: int) -> int:
    """The per artifact seed, keyed exactly as build_corpus_tigress.Cell.seed.

    Keyed on ``sample_id`` (``<suite>_<stem>``), never on a file path, so the
    stream is the same on every machine and checkout. hashlib rather than
    hash(), which is salted per process.
    """
    key = f"{sample_id}|{transform}|{label}|{replicate}"
    return int(hashlib.sha256(key.encode()).hexdigest()[:8], 16)


def sample_id_for(path: str, suite: str) -> str:
    """``<suite>_<stem>``, the corpus directory name of an input program."""
    return f"{suite}_{os.path.splitext(os.path.basename(path))[0]}"


def compiler_info(cc: str, std: str, opt: str, timeout: int) -> Dict:
    version = ""
    try:
        v = subprocess.run([cc, "--version"], capture_output=True, text=True,
                           timeout=30)
        lines = (v.stdout or v.stderr or "").strip().splitlines()
        version = lines[0] if lines else ""
    except (OSError, subprocess.TimeoutExpired):
        version = "unknown"
    return {"cc": cc, "version": version, "flags": compile_flags(std, opt),
            "timeout_seconds": timeout}


def read_programs(path: str) -> List[Tuple[str, str]]:
    base = os.path.dirname(os.path.abspath(path))
    progs = []
    with open(path) as fh:
        for raw in fh:
            line = raw.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split("\t")
            p = parts[0].strip()
            if not os.path.isabs(p):
                p = os.path.join(base, p)
            suite = parts[1].strip() if len(parts) > 1 and parts[1].strip() else "misc"
            if not os.path.isfile(p):
                raise FileNotFoundError(p)
            progs.append((os.path.abspath(p), suite))
    return progs


def _baseline(programs: Sequence[Tuple[str, str]], cc: str, timeout: int,
              std: str = DEFAULT_STD, opt: str = DEFAULT_OPT,
              ) -> Tuple[Dict[str, Dict], List[Dict]]:
    """Run every original program once; keep stdout and exit status."""
    baseline: Dict[str, Dict] = {}
    unusable = []
    for path, _suite in programs:
        res = compile_and_run(path, cc, timeout, std, opt)
        if not res["ok"]:
            unusable.append({"program": path, "error": res["error"]})
            continue
        if not res["stdout"].strip():
            unusable.append({"program": path, "error": "no standard output to compare"})
            continue
        baseline[path] = {"stdout": res["stdout"],
                          "exit_status": res["exit_status"]}

    print(f"usable input programs: {len(baseline)}/{len(programs)}")
    for u in unusable:
        print(f"  excluded {os.path.basename(u['program'])}: {u['error']}")
    nonzero = {os.path.basename(p): b["exit_status"]
               for p, b in baseline.items() if b["exit_status"] != 0}
    if nonzero:
        print(f"  original programs with a nonzero exit status: {nonzero}")
    print()
    return baseline, unusable


def _baseline_summary(baseline: Dict[str, Dict]) -> Dict:
    return {
        "exit_status_counts": {
            str(k): v for k, v in sorted(
                _count(b["exit_status"] for b in baseline.values()).items())
        },
    }


def _count(values) -> Dict:
    out: Dict = defaultdict(int)
    for v in values:
        out[v] += 1
    return dict(out)


def run_corpus(corpus: str, programs: Sequence[Tuple[str, str]], cc: str,
               timeout: int, std: str = DEFAULT_STD,
               opt: str = DEFAULT_OPT) -> Dict:
    """Check the artifacts that are actually on disk.

    This is the mode whose number belongs in the paper. Regenerating artifacts
    in order to test them measures the generator as invoked by this script, not
    the corpus that was released, and the two can differ in seeding. Here each
    file under the corpus root is compiled and run as it will be shipped, and
    both its standard output and its exit status are compared with the
    original program's.
    """
    baseline, unusable = _baseline(programs, cc, timeout, std, opt)

    # sample_id is "<suite>_<stem>" by construction in build_corpus_tigress.
    by_sample = {sample_id_for(path, suite): path for path, suite in programs}

    artifacts: List[Tuple[str, str, str]] = []
    for root, dirs, files in os.walk(corpus):
        dirs.sort()
        for fn in sorted(files):
            if not fn.endswith(".c"):
                continue
            full = os.path.join(root, fn)
            parts = os.path.relpath(full, corpus).replace("\\", "/").split("/")
            tech = next((p for p in parts if p.endswith("_variants")), None)
            if tech is None:
                continue
            sample = parts[parts.index(tech) - 1]
            label = re.sub(r"_\d+$", "", os.path.splitext(fn)[0])
            artifacts.append((full, sample, label))

    if not artifacts:
        raise ValueError(f"no artifacts with a '*_variants' parent found under {corpus}")

    per_param: Dict[str, Dict[str, int]] = defaultdict(_new_counter)
    failures: List[Dict] = []
    unmapped: List[str] = []

    for i, (full, sample, label) in enumerate(artifacts, 1):
        src = by_sample.get(sample)
        if src is None or src not in baseline:
            unmapped.append(full)
            continue
        rec = per_param[label]
        rec["attempted"] += 1
        got = compile_and_run(full, cc, timeout, std, opt)
        outcome, counters, reason = classify(baseline[src], got)
        for c in counters:
            rec[c] += 1
        if outcome != "preserved":
            failures.append({"program": sample, "param": label,
                             "artifact": os.path.relpath(full, corpus),
                             "reason": reason,
                             "expected_exit_status": baseline[src]["exit_status"],
                             "exit_status": got["exit_status"]})
        if i % 200 == 0 or i == len(artifacts):
            print(f"  [{i}/{len(artifacts)}]", flush=True)

    if unmapped:
        print(f"\n{len(unmapped)} artifacts could not be matched to a usable input "
              f"program and were not checked, first: {unmapped[0]}")

    return {
        "mode": "corpus",
        "corpus": corpus,
        "compiler": compiler_info(cc, std, opt, timeout),
        "artifacts_found": len(artifacts),
        "artifacts_unmatched": len(unmapped),
        "usable_programs": len(baseline),
        "excluded_programs": unusable,
        "baseline": _baseline_summary(baseline),
        "comparison": "standard output and exit status, reported separately",
        "counter_definitions": COUNTER_DEFINITIONS,
        "per_parameterisation": {k: dict(v) for k, v in per_param.items()},
        "failures": failures,
    }


def run(programs: Sequence[Tuple[str, str]], replicates: int, cc: str,
        timeout: int, std: str = DEFAULT_STD, opt: str = DEFAULT_OPT,
        first_replicate: int = DEFAULT_FIRST_REPLICATE,
        corpus_replicates: int = CORPUS_REPLICATES) -> Dict:
    """Regenerate artifacts at replicate indices the corpus does not hold.

    Complements the corpus mode: it answers whether the transformation preserves
    behaviour in general, over seeds the released corpus does not contain, rather
    than whether the released files happen to be correct.

    Seeds are keyed exactly as build_corpus_tigress keys the corpus,
    ``<sample_id>|<transformation>|<parameterisation>|<replicate>``, with
    replicate indices ``first_replicate .. first_replicate + replicates - 1``
    (8 and 9 by default). The released pilot corpus holds replicates 0..7, so
    the default indices are disjoint from it and the artifacts checked here are
    the ones the corpus builder would emit as replicates 8 and 9. Keying on
    ``sample_id`` rather than on the absolute path makes the stream, and hence
    the reported rate, the same on every machine.
    """
    if replicates < 1:
        raise ValueError("replicates must be at least 1")
    indices = list(range(first_replicate, first_replicate + replicates))
    overlap = sorted(set(indices) & set(range(corpus_replicates)))
    if overlap:
        print(f"WARNING: replicate indices {overlap} are also in the released "
              f"corpus (replicates 0..{corpus_replicates - 1}); those artifacts "
              "are not unseen seeds.")

    baseline, unusable = _baseline(programs, cc, timeout, std, opt)

    per_param: Dict[str, Dict[str, int]] = defaultdict(_new_counter)
    failures: List[Dict] = []

    with tempfile.TemporaryDirectory() as td:
        for t in REF_CATALOGUE:
            for p in t.params:
                for path, suite in programs:
                    if path not in baseline:
                        continue
                    sid = sample_id_for(path, suite)
                    with open(path) as fh:
                        original = fh.read()
                    for rep in indices:
                        seed = artifact_seed(sid, t.name, p.label, rep)
                        rec = per_param[p.label]
                        rec["attempted"] += 1
                        try:
                            out_src = apply_transform(
                                original, t.name, dict(p.options), seed
                            )
                        except Exception as exc:  # noqa: BLE001
                            rec["transform_failed"] += 1
                            failures.append({"program": sid, "param": p.label,
                                             "replicate": rep, "seed": seed,
                                             "reason": str(exc)[:160]})
                            continue
                        art = os.path.join(td, "artifact.c")
                        with open(art, "w") as fh:
                            fh.write(out_src)
                        got = compile_and_run(art, cc, timeout, std, opt)
                        outcome, counters, reason = classify(baseline[path], got)
                        for c in counters:
                            rec[c] += 1
                        if outcome != "preserved":
                            failures.append({
                                "program": sid, "param": p.label,
                                "replicate": rep, "seed": seed,
                                "reason": reason,
                                "expected_exit_status": baseline[path]["exit_status"],
                                "exit_status": got["exit_status"]})

    return {
        "mode": "regenerate",
        "replicates": replicates,
        "replicate_indices": indices,
        "corpus_replicates": corpus_replicates,
        "replicates_overlap_corpus": bool(overlap),
        "seed_key": "sha256('<sample_id>|<transformation>|<parameterisation>|"
                    "<replicate>')[:8] as an integer, as build_corpus_tigress",
        "compiler": compiler_info(cc, std, opt, timeout),
        "usable_programs": len(baseline),
        "excluded_programs": unusable,
        "baseline": _baseline_summary(baseline),
        "comparison": "standard output and exit status, reported separately",
        "counter_definitions": COUNTER_DEFINITIONS,
        "per_parameterisation": {k: dict(v) for k, v in per_param.items()},
        "failures": failures,
    }


def report(result: Dict) -> int:
    rows = result["per_parameterisation"]
    width = max(len(k) for k in rows) if rows else 10
    cols = [("attempted", 9), ("preserved", 9), ("compile_failed", 14),
            ("run_timeout", 11), ("transform_failed", 16),
            ("output_differs", 14), ("exit_status_differs", 19)]
    header = "  ".join([f"{'parameterisation'.ljust(width)}"]
                       + [name.rjust(w) for name, w in cols] + ["  rate"])
    print(header)
    print("-" * len(header))
    totals = _new_counter()
    worst = 1.0
    for label in sorted(rows):
        r = rows[label]
        rate = r["preserved"] / r["attempted"] if r["attempted"] else 0.0
        worst = min(worst, rate)
        for k in COUNTER_KEYS:
            totals[k] += r.get(k, 0)
        print("  ".join([label.ljust(width)]
                        + [f"{r.get(name, 0):{w}d}" for name, w in cols]
                        + [f"{rate:6.1%}"]))
    overall = totals["preserved"] / totals["attempted"] if totals["attempted"] else 0.0
    print("-" * len(header))
    print("  ".join(["overall".ljust(width)]
                    + [f"{totals[name]:{w}d}" for name, w in cols]
                    + [f"{overall:6.1%}"]))
    print("  output_differs and exit_status_differs are reported separately and "
          "can overlap;")
    print(f"  {totals['output_and_exit_status_differ']} artifacts differ in both.")
    print()

    if result["failures"]:
        by_reason: Dict[str, int] = defaultdict(int)
        for f in result["failures"]:
            by_reason[f["reason"]] += 1
        print(f"{len(result['failures'])} failures, grouped by cause:")
        for reason, n in sorted(by_reason.items(), key=lambda kv: -kv[1])[:10]:
            print(f"  {n:5d}  {reason}")
        print()

    # A transformation that preserves behaviour on only part of the input set is
    # a selection effect as well as a correctness problem: the artifacts that
    # survive are not a random sample of the inputs.
    if worst < 0.95:
        print(f"NOTE: the weakest parameterisation preserves behaviour on only "
              f"{worst:.1%} of attempts. The surviving artifacts for that class "
              f"are a filtered subset of the inputs, so input properties partly "
              f"encode the class label.")
    return 0


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(
        description="Measure semantic preservation of generated artifacts by "
                    "comparing standard output and exit status with the "
                    "original program."
    )
    ap.add_argument("--programs", required=True, help="TSV program manifest")
    ap.add_argument("--corpus", default=None,
                    help="check the artifacts already written under this root "
                         "instead of regenerating them; this is the mode whose "
                         "rate describes the released corpus")
    ap.add_argument("--replicates", type=int, default=2,
                    help="regenerate mode only: number of replicate indices to "
                         "generate per (program, parameterisation)")
    ap.add_argument("--first-replicate", type=int, default=DEFAULT_FIRST_REPLICATE,
                    help="regenerate mode only: first replicate index (default "
                         f"{DEFAULT_FIRST_REPLICATE}, so the default indices 8 "
                         "and 9 are disjoint from the corpus replicates 0..7)")
    ap.add_argument("--corpus-replicates", type=int, default=CORPUS_REPLICATES,
                    help="replicates per cell in the released corpus; used only "
                         "to warn when regenerated indices overlap it")
    ap.add_argument("--cc", default="cc")
    ap.add_argument("--std", default=DEFAULT_STD,
                    help="C dialect passed as -std= (default c99; empty string "
                         "for the compiler default)")
    ap.add_argument("--opt", default=DEFAULT_OPT,
                    help="optimisation level passed as -O<opt> (default 0)")
    ap.add_argument("--timeout", type=int, default=60,
                    help="seconds allowed for each compile and for each run")
    ap.add_argument("--report", default=None, help="write a JSON report here")
    args = ap.parse_args(argv)

    progs = read_programs(args.programs)
    if args.corpus:
        result = run_corpus(args.corpus, progs, args.cc, args.timeout,
                            args.std, args.opt)
    else:
        result = run(progs, args.replicates, args.cc, args.timeout,
                     args.std, args.opt, args.first_replicate,
                     args.corpus_replicates)
    code = report(result)

    if args.report:
        os.makedirs(os.path.dirname(os.path.abspath(args.report)), exist_ok=True)
        with open(args.report, "w") as fh:
            json.dump(result, fh, indent=2)
        print(f"report written to {args.report}")
    return code

if __name__ == "__main__":
    sys.exit(main())
