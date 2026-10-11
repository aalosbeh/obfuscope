"""AUDIT-GENERATED helper (run:semantics-v3). Not part of the released pipeline.

Regenerates reference-backend artifacts exactly as scripts/verify_semantics.py
does in regenerate mode (same functions: read_programs, sample_id_for,
artifact_seed, REF_CATALOGUE, apply_transform, imported from --scripts-dir),
and records the sha256 of every regenerated artifact keyed on
"<sample_id>|<transform>|<param>|<replicate>". Used to show that the
regenerated artifacts are byte identical when the code is run from two
different directory copies, and (optionally, --compare-corpus) that
regenerating replicates 0..7 reproduces the pilot corpus files byte for byte.

Usage
    python regen_hashes.py --scripts-dir <copy>/scripts \
        --programs <copy>/corpus_inputs/programs.tsv \
        --first-replicate 8 --replicates 2 --report out.json \
        [--write-dir <dir>] [--compare-corpus <copy>/data/pilot_corpus/reference_c]
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import sys


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--scripts-dir", required=True)
    ap.add_argument("--programs", required=True)
    ap.add_argument("--first-replicate", type=int, default=8)
    ap.add_argument("--replicates", type=int, default=2)
    ap.add_argument("--report", required=True)
    ap.add_argument("--write-dir", default=None,
                    help="also write each regenerated artifact under this dir")
    ap.add_argument("--compare-corpus", default=None,
                    help="cohort root (e.g. data/pilot_corpus/reference_c); "
                         "compare each regenerated artifact with the file at "
                         "<root>/<sample_id>/<technique_dir>/<label>_<rep>.c")
    args = ap.parse_args()

    scripts_dir = os.path.abspath(args.scripts_dir)
    sys.path.insert(0, scripts_dir)
    import verify_semantics as vs  # noqa: E402
    from reference_backend import REF_CATALOGUE, apply_transform  # noqa: E402

    progs = vs.read_programs(args.programs)
    indices = list(range(args.first_replicate,
                         args.first_replicate + args.replicates))
    hashes = {}
    corpus_cmp = {"compared": 0, "identical": 0, "differs": 0, "missing": 0,
                  "differs_list": [], "missing_list": []}
    for t in REF_CATALOGUE:
        for p in t.params:
            for path, suite in progs:
                sid = vs.sample_id_for(path, suite)
                with open(path) as fh:
                    original = fh.read()
                for rep in indices:
                    seed = vs.artifact_seed(sid, t.name, p.label, rep)
                    out = apply_transform(original, t.name, dict(p.options), seed)
                    data = out.encode()
                    key = f"{sid}|{t.name}|{p.label}|{rep}"
                    hashes[key] = {"seed": seed,
                                   "sha256": hashlib.sha256(data).hexdigest(),
                                   "bytes": len(data),
                                   "identical_to_input": out == original}
                    if args.write_dir:
                        d = os.path.join(args.write_dir, sid, t.technique_dir)
                        os.makedirs(d, exist_ok=True)
                        with open(os.path.join(d, f"{p.label}_{rep}.c"), "w") as fh:
                            fh.write(out)
                    if args.compare_corpus:
                        f = os.path.join(args.compare_corpus, sid,
                                         t.technique_dir, f"{p.label}_{rep}.c")
                        if not os.path.isfile(f):
                            corpus_cmp["missing"] += 1
                            corpus_cmp["missing_list"].append(key)
                            continue
                        corpus_cmp["compared"] += 1
                        with open(f, "rb") as fh:
                            if fh.read() == data:
                                corpus_cmp["identical"] += 1
                            else:
                                corpus_cmp["differs"] += 1
                                corpus_cmp["differs_list"].append(key)

    combined = hashlib.sha256(
        "\n".join(f"{k} {v['sha256']}" for k, v in sorted(hashes.items())).encode()
    ).hexdigest()
    per_param_noop = {}
    for k, v in hashes.items():
        lab = k.split("|")[2]
        per_param_noop.setdefault(lab, 0)
        per_param_noop[lab] += int(v["identical_to_input"])
    result = {
        "label": "AUDIT-GENERATED (run:semantics-v3)",
        "scripts_dir": scripts_dir,
        "cwd": os.getcwd(),
        "programs": os.path.abspath(args.programs),
        "replicate_indices": indices,
        "n_artifacts": len(hashes),
        "combined_sha256": combined,
        "identical_to_input_per_param": per_param_noop,
        "corpus_compare": corpus_cmp if args.compare_corpus else None,
        "artifacts": hashes,
    }
    os.makedirs(os.path.dirname(os.path.abspath(args.report)), exist_ok=True)
    with open(args.report, "w") as fh:
        json.dump(result, fh, indent=1, sort_keys=True)
    print(f"n_artifacts={len(hashes)} combined_sha256={combined}")
    if args.compare_corpus:
        print("corpus_compare:", {k: v for k, v in corpus_cmp.items()
                                  if not k.endswith('_list')})
    return 0


if __name__ == "__main__":
    sys.exit(main())
