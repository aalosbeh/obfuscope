"""
List corpus artifacts whose text is identical to the program they were made from.

An artifact that is byte for byte the input program carries no trace of the
transformation it is labelled with. It still compiles, still preserves
behaviour, and still passes every check that looks at the artifact alone, but
its label is unrecoverable from its text by construction: no feature extractor
can attribute a transformation that did nothing. Such artifacts inflate the
class they sit in with copies of the input programs and set an error floor on
attribution for that class.

Two comparisons are made against the input program named by the artifact's
``sample_id`` directory (``<suite>_<stem>``, as build_corpus_tigress lays the
corpus out):

  byte_identical        the artifact's bytes equal the input program's bytes
  whitespace_identical  equal after every run of whitespace is collapsed to one
                        space and leading and trailing whitespace is removed;
                        includes the byte identical artifacts

``whitespace_only_difference`` is the second set minus the first.

Counts are reported per parameterisation, per program, and per (program,
parameterisation) cell, and every matching artifact is listed by its path
relative to the corpus root.

Usage
-----
    python3 scripts/audit_noop_artifacts.py --corpus data/pilot_corpus \\
        --programs corpus_inputs/programs.tsv --report noop_artifacts.json
"""
from __future__ import annotations

import argparse
import json
import os
import re
import sys
from collections import defaultdict
from typing import Dict, List, Optional, Sequence, Tuple

_HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, _HERE)

from verify_semantics import read_programs, sample_id_for  # noqa: E402

_WS = re.compile(r"\s+")


def normalise_whitespace(text: str) -> str:
    """Collapse every whitespace run to one space and strip both ends."""
    return _WS.sub(" ", text).strip()


def find_artifacts(corpus: str) -> List[Dict]:
    """Every ``.c`` file under a ``*_variants`` directory of the corpus.

    Layout: ``<root>/<cohort>/<sample_id>/<technique>_variants/<label>_<rep>.c``.
    """
    found: List[Dict] = []
    for root, dirs, files in os.walk(corpus):
        dirs.sort()
        for fn in sorted(files):
            if not fn.endswith(".c"):
                continue
            full = os.path.join(root, fn)
            rel = os.path.relpath(full, corpus).replace("\\", "/")
            parts = rel.split("/")
            tech = next((p for p in parts if p.endswith("_variants")), None)
            if tech is None or parts.index(tech) == 0:
                continue
            stem = os.path.splitext(fn)[0]
            m = re.match(r"^(.*)_(\d+)$", stem)
            label, rep = (m.group(1), int(m.group(2))) if m else (stem, None)
            found.append({
                "path": full,
                "relpath": rel,
                "sample_id": parts[parts.index(tech) - 1],
                "technique_dir": tech,
                "param": label,
                "replicate": rep,
            })
    return found


def audit(corpus: str, programs: Sequence[Tuple[str, str]]) -> Dict:
    by_sample = {sample_id_for(path, suite): path for path, suite in programs}
    originals: Dict[str, bytes] = {}
    for sid, path in by_sample.items():
        with open(path, "rb") as fh:
            originals[sid] = fh.read()
    originals_ws = {sid: normalise_whitespace(b.decode("utf-8", "replace"))
                    for sid, b in originals.items()}

    artifacts = find_artifacts(corpus)
    if not artifacts:
        raise ValueError(f"no artifacts with a '*_variants' parent under {corpus}")

    def counter() -> Dict[str, int]:
        return {"artifacts": 0, "byte_identical": 0, "whitespace_identical": 0,
                "whitespace_only_difference": 0}

    per_param: Dict[str, Dict[str, int]] = defaultdict(counter)
    per_program: Dict[str, Dict[str, int]] = defaultdict(counter)
    per_cell: Dict[Tuple[str, str], Dict[str, int]] = defaultdict(counter)
    listed: List[Dict] = []
    unmatched: List[str] = []

    for a in artifacts:
        sid = a["sample_id"]
        if sid not in originals:
            unmatched.append(a["relpath"])
            continue
        with open(a["path"], "rb") as fh:
            data = fh.read()
        byte_same = data == originals[sid]
        ws_same = (byte_same or normalise_whitespace(
            data.decode("utf-8", "replace")) == originals_ws[sid])
        for rec in (per_param[a["param"]], per_program[sid],
                    per_cell[(sid, a["param"])]):
            rec["artifacts"] += 1
            rec["byte_identical"] += int(byte_same)
            rec["whitespace_identical"] += int(ws_same)
            rec["whitespace_only_difference"] += int(ws_same and not byte_same)
        if ws_same:
            listed.append({
                "artifact": a["relpath"], "sample_id": sid,
                "technique_dir": a["technique_dir"], "param": a["param"],
                "replicate": a["replicate"],
                "byte_identical": byte_same, "whitespace_identical": True,
            })

    checked = len(artifacts) - len(unmatched)
    n_byte = sum(1 for r in listed if r["byte_identical"])
    n_ws = len(listed)
    return {
        "corpus": corpus,
        "definitions": {
            "byte_identical": "artifact bytes equal the input program's bytes",
            "whitespace_identical": "equal after collapsing every whitespace run "
                                    "to one space and stripping both ends; "
                                    "includes byte_identical",
            "whitespace_only_difference": "whitespace_identical and not "
                                          "byte_identical",
        },
        "artifacts_found": len(artifacts),
        "artifacts_checked": checked,
        "artifacts_unmatched": len(unmatched),
        "unmatched_examples": unmatched[:10],
        "input_programs": len(originals),
        "totals": {
            "byte_identical": n_byte,
            "whitespace_identical": n_ws,
            "whitespace_only_difference": n_ws - n_byte,
            "byte_identical_fraction": round(n_byte / checked, 6) if checked else None,
            "whitespace_identical_fraction": round(n_ws / checked, 6) if checked else None,
        },
        "per_parameterisation": {k: per_param[k] for k in sorted(per_param)},
        "per_program": {k: per_program[k] for k in sorted(per_program)
                        if per_program[k]["whitespace_identical"]},
        "programs_with_no_identical_artifact": sorted(
            k for k, v in per_program.items() if not v["whitespace_identical"]),
        "per_program_parameterisation": [
            {"sample_id": sid, "param": prm, **rec}
            for (sid, prm), rec in sorted(per_cell.items())
            if rec["whitespace_identical"]
        ],
        "artifacts": listed,
    }


def report(res: Dict) -> None:
    t = res["totals"]
    print(f"corpus {res['corpus']}: {res['artifacts_checked']} artifacts checked "
          f"against {res['input_programs']} input programs "
          f"({res['artifacts_unmatched']} unmatched)")
    print(f"  byte identical to the input program        {t['byte_identical']}")
    print(f"  identical after whitespace normalisation   {t['whitespace_identical']}")
    print()
    rows = res["per_parameterisation"]
    w = max([len(k) for k in rows] + [16])
    print(f"{'parameterisation'.ljust(w)}  artifacts  byte_identical  "
          "whitespace_identical")
    for k, r in rows.items():
        print(f"{k.ljust(w)}  {r['artifacts']:9d}  {r['byte_identical']:14d}  "
              f"{r['whitespace_identical']:20d}")
    print()
    if res["per_program_parameterisation"]:
        print("cells with at least one identical artifact")
        for c in res["per_program_parameterisation"]:
            print(f"  {c['sample_id']:28s} {c['param']:16s} "
                  f"{c['byte_identical']}/{c['artifacts']} byte identical, "
                  f"{c['whitespace_identical']}/{c['artifacts']} after whitespace")
        print()


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(
        description="List artifacts identical to their input program.")
    ap.add_argument("--corpus", required=True, help="corpus root directory")
    ap.add_argument("--programs", required=True, help="TSV program manifest")
    ap.add_argument("--report", default=None, help="write a JSON report here")
    args = ap.parse_args(argv)

    res = audit(args.corpus, read_programs(args.programs))
    report(res)
    if args.report:
        os.makedirs(os.path.dirname(os.path.abspath(args.report)), exist_ok=True)
        with open(args.report, "w") as fh:
            json.dump(res, fh, indent=2)
        print(f"report written to {args.report}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
