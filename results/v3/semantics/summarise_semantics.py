"""AUDIT-GENERATED (run:semantics-v3): combine the semantic-preservation reports
in this directory into semantics_v3_summary.json. Reads only files written by
this run (verify_semantics.py reports, regen_hashes.py dumps,
audit_noop_artifacts.py report, logs with /usr/bin/time -p output)."""
from __future__ import annotations

import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))


def load(name):
    p = os.path.join(HERE, name)
    return json.load(open(p)) if os.path.isfile(p) else None


def real_seconds(tag):
    p = os.path.join(HERE, "logs", f"{tag}.log")
    if not os.path.isfile(p):
        return None
    m = re.findall(r"^real\s+([0-9.]+)", open(p).read(), re.M)
    return float(m[-1]) if m else None


def totals(rep):
    keys = ["attempted", "preserved", "compile_failed", "compile_timeout",
            "run_timeout", "transform_failed", "behaviour_differs",
            "output_differs", "exit_status_differs",
            "output_and_exit_status_differ"]
    t = {k: 0 for k in keys}
    for r in rep["per_parameterisation"].values():
        for k in keys:
            t[k] += r.get(k, 0)
    t["preservation_rate"] = t["preserved"] / t["attempted"] if t["attempted"] else None
    return t


def strip_volatile(rep):
    r = json.loads(json.dumps(rep))
    r.pop("corpus", None)
    return r


def main():
    out = {"label": "AUDIT-GENERATED (run:semantics-v3)", "runs": {}}
    for tag, fn in [("corpus_O0", "semantics_corpus_O0.json"),
                    ("corpus_O2", "semantics_corpus_O2.json"),
                    ("regen_repo", "semantics_regenerate.json"),
                    ("regen_copyA", "semantics_regenerate_copyA.json"),
                    ("regen_copyB", "semantics_regenerate_copyB.json")]:
        rep = load(fn)
        if rep is None:
            out["runs"][tag] = "missing"
            continue
        out["runs"][tag] = {
            "file": fn,
            "mode": rep.get("mode"),
            "compiler": rep.get("compiler"),
            "artifacts_found": rep.get("artifacts_found"),
            "artifacts_unmatched": rep.get("artifacts_unmatched"),
            "replicate_indices": rep.get("replicate_indices"),
            "replicates_overlap_corpus": rep.get("replicates_overlap_corpus"),
            "usable_programs": rep.get("usable_programs"),
            "excluded_programs": rep.get("excluded_programs"),
            "baseline": rep.get("baseline"),
            "per_parameterisation": rep.get("per_parameterisation"),
            "totals": totals(rep),
            "n_failures": len(rep.get("failures", [])),
            "wall_seconds": real_seconds(tag),
        }
    a, b, c = (load("semantics_regenerate.json"),
               load("semantics_regenerate_copyA.json"),
               load("semantics_regenerate_copyB.json"))
    if a and b and c:
        out["regenerate_reports_identical_across_locations"] = (
            strip_volatile(a) == strip_volatile(b) == strip_volatile(c))
    ha, hb = load("regen_hashes_r89_copyA.json"), load("regen_hashes_r89_copyB.json")
    if ha and hb:
        out["regenerated_r8_r9_hashes"] = {
            "n_artifacts_copyA": ha["n_artifacts"],
            "n_artifacts_copyB": hb["n_artifacts"],
            "combined_sha256_copyA": ha["combined_sha256"],
            "combined_sha256_copyB": hb["combined_sha256"],
            "per_artifact_identical": ha["artifacts"] == hb["artifacts"],
            "cwd_copyA": ha["cwd"], "cwd_copyB": hb["cwd"],
            "identical_to_input_per_param": ha["identical_to_input_per_param"],
        }
    for tag in ("copyA", "copyB"):
        h = load(f"regen_hashes_r0to7_vs_corpus_{tag}.json")
        if h:
            cc = dict(h["corpus_compare"])
            cc.pop("differs_list", None)
            cc.pop("missing_list", None)
            out[f"regen_r0to7_vs_pilot_corpus_{tag}"] = cc
    n = load("noop_artifacts.json")
    if n:
        out["noop_artifacts"] = {k: n[k] for k in n
                                 if k not in ("artifacts", "byte_identical_artifacts",
                                              "whitespace_identical_artifacts")
                                 and not isinstance(n[k], list)}
    json.dump(out, open(os.path.join(HERE, "semantics_v3_summary.json"), "w"),
              indent=2, sort_keys=True)
    print(json.dumps({k: (v["totals"] if isinstance(v, dict) else v)
                      for k, v in out["runs"].items()}, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
