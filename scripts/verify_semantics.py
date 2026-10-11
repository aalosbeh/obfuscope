"""
Semantic preservation check for generated artifacts.

An obfuscating transformation is only valid if it preserves behaviour. A corpus
of artifacts that compile but compute something different is not a corpus of
obfuscated programs, and a provenance classifier trained on it would partly be
learning which transformations are broken.

The check is direct: compile the original program, run it, keep its standard
output; then for every artifact, compile, run, and compare. The input programs
are deterministic and print to standard output, which is what makes the
comparison a usable oracle.

This is reported as a rate, not asserted as a property. A transformation with a
low preservation rate is a finding about that transformation, and the rate
belongs in the corpus table alongside the artifact counts.

Usage
-----
    python3 scripts/verify_semantics.py --programs corpus_inputs/programs.tsv \\
        --backend reference --replicates 2 --report results/semantics.json

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


def compile_and_run(src_path: str, cc: str, timeout: int) -> Tuple[bool, str, str]:
    """Compile one translation unit and capture its standard output."""
    with tempfile.TemporaryDirectory() as td:
        exe = os.path.join(td, "a.out")
        c = subprocess.run([cc, "-w", "-O0", "-o", exe, src_path],
                           capture_output=True, text=True, timeout=timeout)
        if c.returncode != 0:
            first = (c.stderr or "").strip().splitlines()
            return False, "", (first[0][:160] if first else "compile failed")
        try:
            r = subprocess.run([exe], capture_output=True, text=True, timeout=timeout)
        except subprocess.TimeoutExpired:
            return False, "", "execution timed out"
        return True, r.stdout, ""


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


def _baseline(programs: Sequence[Tuple[str, str]], cc: str,
              timeout: int) -> Tuple[Dict[str, str], List[Dict]]:
    baseline: Dict[str, str] = {}
    unusable = []
    for path, _suite in programs:
        ok, out, err = compile_and_run(path, cc, timeout)
        if not ok:
            unusable.append({"program": path, "error": err})
            continue
        if not out.strip():
            unusable.append({"program": path, "error": "no standard output to compare"})
            continue
        baseline[path] = out

    print(f"usable input programs: {len(baseline)}/{len(programs)}")
    for u in unusable:
        print(f"  excluded {os.path.basename(u['program'])}: {u['error']}")
    print()
    return baseline, unusable


def run_corpus(corpus: str, programs: Sequence[Tuple[str, str]], cc: str,
               timeout: int) -> Dict:
    """Check the artifacts that are actually on disk.

    This is the mode whose number belongs in the paper. Regenerating artifacts
    in order to test them measures the generator as invoked by this script, not
    the corpus that was released, and the two can differ in seeding. Here each
    file under the corpus root is compiled and run as it will be shipped.
    """
    baseline, unusable = _baseline(programs, cc, timeout)

    # sample_id is "<suite>_<stem>" by construction in build_corpus_tigress.
    by_sample = {
        f"{suite}_{os.path.splitext(os.path.basename(path))[0]}": path
        for path, suite in programs
    }

    artifacts: List[Tuple[str, str, str]] = []
    for root, _dirs, files in os.walk(corpus):
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

    per_param: Dict[str, Dict[str, int]] = defaultdict(
        lambda: {"attempted": 0, "preserved": 0, "compile_failed": 0, "output_differs": 0}
    )
    failures: List[Dict] = []
    unmapped: List[str] = []

    for i, (full, sample, label) in enumerate(artifacts, 1):
        src = by_sample.get(sample)
        if src is None or src not in baseline:
            unmapped.append(full)
            continue
        rec = per_param[label]
        rec["attempted"] += 1
        ok, got, err = compile_and_run(full, cc, timeout)
        if not ok:
            rec["compile_failed"] += 1
            failures.append({"program": sample, "param": label, "reason": err})
        elif got != baseline[src]:
            rec["output_differs"] += 1
            failures.append({"program": sample, "param": label,
                             "reason": "standard output differs"})
        else:
            rec["preserved"] += 1
        if i % 200 == 0 or i == len(artifacts):
            print(f"  [{i}/{len(artifacts)}]", flush=True)

    if unmapped:
        print(f"\n{len(unmapped)} artifacts could not be matched to a usable input "
              f"program and were not checked, first: {unmapped[0]}")

    return {
        "mode": "corpus",
        "corpus": corpus,
        "artifacts_found": len(artifacts),
        "artifacts_unmatched": len(unmapped),
        "usable_programs": len(baseline),
        "excluded_programs": unusable,
        "per_parameterisation": {k: dict(v) for k, v in per_param.items()},
        "failures": failures,
    }


def run(programs: Sequence[Tuple[str, str]], replicates: int, cc: str,
        timeout: int) -> Dict:
    """Regenerate artifacts with fresh seeds and check those.

    Complements the corpus mode: it answers whether the transformation preserves
    behaviour in general, over seeds the released corpus does not contain, rather
    than whether the released files happen to be correct.
    """
    baseline, unusable = _baseline(programs, cc, timeout)

    per_param: Dict[str, Dict[str, int]] = defaultdict(
        lambda: {"attempted": 0, "preserved": 0, "compile_failed": 0, "output_differs": 0}
    )
    failures: List[Dict] = []

    with tempfile.TemporaryDirectory() as td:
        for t in REF_CATALOGUE:
            for p in t.params:
                for path, _suite in programs:
                    if path not in baseline:
                        continue
                    original = open(path).read()
                    for rep in range(replicates):
                        # hashlib rather than hash(): hash() salts strings per
                        # process, so this script would draw different seeds on
                        # every run and could not reproduce a reported rate. The
                        # "verify" prefix keeps this seed stream disjoint from
                        # the one build_corpus_tigress uses, so the regenerate
                        # mode genuinely exercises unseen seeds.
                        key = f"verify|{path}|{t.name}|{p.label}|{rep}"
                        seed = int(hashlib.sha256(key.encode()).hexdigest()[:8], 16)
                        rec = per_param[p.label]
                        rec["attempted"] += 1
                        try:
                            out_src = apply_transform(
                                original, t.name, dict(p.options), seed
                            )
                        except Exception as exc:  # noqa: BLE001
                            rec["compile_failed"] += 1
                            failures.append({"program": os.path.basename(path),
                                             "param": p.label, "reason": str(exc)[:160]})
                            continue
                        art = os.path.join(td, "artifact.c")
                        with open(art, "w") as fh:
                            fh.write(out_src)
                        ok, got, err = compile_and_run(art, cc, timeout)
                        if not ok:
                            rec["compile_failed"] += 1
                            failures.append({"program": os.path.basename(path),
                                             "param": p.label, "reason": err})
                        elif got != baseline[path]:
                            rec["output_differs"] += 1
                            failures.append({"program": os.path.basename(path),
                                             "param": p.label,
                                             "reason": "standard output differs"})
                        else:
                            rec["preserved"] += 1

    return {
        "mode": "regenerate",
        "replicates": replicates,
        "usable_programs": len(baseline),
        "excluded_programs": unusable,
        "per_parameterisation": {k: dict(v) for k, v in per_param.items()},
        "failures": failures,
    }


def report(result: Dict) -> int:
    rows = result["per_parameterisation"]
    width = max(len(k) for k in rows) if rows else 10
    print(f"{'parameterisation'.ljust(width)}  attempted  preserved  compile_fail  "
          f"output_diff  rate")
    print("-" * (width + 52))
    total_a = total_p = 0
    worst = 1.0
    for label in sorted(rows):
        r = rows[label]
        rate = r["preserved"] / r["attempted"] if r["attempted"] else 0.0
        worst = min(worst, rate)
        total_a += r["attempted"]
        total_p += r["preserved"]
        print(f"{label.ljust(width)}  {r['attempted']:9d}  {r['preserved']:9d}  "
              f"{r['compile_failed']:12d}  {r['output_differs']:11d}  {rate:5.1%}")
    overall = total_p / total_a if total_a else 0.0
    print("-" * (width + 52))
    print(f"{'overall'.ljust(width)}  {total_a:9d}  {total_p:9d}  "
          f"{'':12s}  {'':11s}  {overall:5.1%}")
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
        description="Measure semantic preservation of generated artifacts."
    )
    ap.add_argument("--programs", required=True, help="TSV program manifest")
    ap.add_argument("--corpus", default=None,
                    help="check the artifacts already written under this root "
                         "instead of regenerating them; this is the mode whose "
                         "rate describes the released corpus")
    ap.add_argument("--replicates", type=int, default=2,
                    help="regenerate mode only: fresh seeds per parameterisation")
    ap.add_argument("--cc", default="cc")
    ap.add_argument("--timeout", type=int, default=60)
    ap.add_argument("--report", default=None, help="write a JSON report here")
    args = ap.parse_args(argv)

    progs = read_programs(args.programs)
    if args.corpus:
        result = run_corpus(args.corpus, progs, args.cc, args.timeout)
    else:
        result = run(progs, args.replicates, args.cc, args.timeout)
    code = report(result)

    if args.report:
        os.makedirs(os.path.dirname(os.path.abspath(args.report)), exist_ok=True)
        with open(args.report, "w") as fh:
            json.dump(result, fh, indent=2)
        print(f"report written to {args.report}")
    return code


if __name__ == "__main__":
    sys.exit(main())
