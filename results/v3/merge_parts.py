"""AUDIT-GENERATED: merge per-seed parts of one open set run into one report.

Folds are independent of execution order (every random component is seeded by
the fold's seed: build_model(name, seed), GroupShuffleSplit(random_state=seed),
RandomState(seed).permutation for program_kfold, IsolationForest(random_state=
seed)), so running the seeds in separate processes and concatenating gives the
same per-fold rows as one process. The merged per_fold list is put in the order
the script itself uses (model order of --models, then seed order, then the
script's own within-seed order), and the summary is recomputed with the
script's own ``_summarise``.

Usage: python merge_parts.py OUT.json PART.json [PART.json ...]
       (diagnostics sidecars in results/v3/diagnostics/<part name>.json are
        merged into results/v3/diagnostics/<out name>.json)
"""
from __future__ import annotations

import importlib.util
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
SCRIPT = os.path.normpath(os.path.join(HERE, "..", "..", "scripts",
                                       "openset_baselines.py"))


def _load():
    spec = importlib.util.spec_from_file_location("openset_baselines", SCRIPT)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def _sum_nested(dicts):
    out = {}
    for d in dicts:
        for k, v in d.items():
            if isinstance(v, dict):
                out[k] = _sum_nested([out.get(k, {}), v])
            elif isinstance(v, (int, float)):
                out[k] = out.get(k, 0) + v
    return out


def main() -> int:
    out_path, parts = sys.argv[1], sys.argv[2:]
    osb = _load()
    reps = [json.load(open(p)) for p in parts]
    meta_keys = [k for k in reps[0] if k not in ("per_fold", "summary", "seeds")]
    for r in reps[1:]:
        for k in meta_keys:
            if r[k] != reps[0][k]:
                raise SystemExit(f"metadata mismatch on {k}")
    seeds = sorted({s for r in reps for s in r["seeds"]})
    if len(seeds) != sum(len(r["seeds"]) for r in reps):
        raise SystemExit("overlapping seeds across parts")
    models = reps[0]["models"]
    rows = []
    for r in sorted(reps, key=lambda r: r["seeds"][0]):
        rows.extend(r["per_fold"])
    # stable sort: model order, then seed; within (model, seed) keep part order
    rows = sorted(rows, key=lambda f: (models.index(f["model"]), f["seed"]))
    merged = {}
    for k in reps[0]:
        if k == "seeds":
            merged[k] = seeds
        elif k == "per_fold":
            merged[k] = rows
        elif k == "summary":
            merged[k] = osb._summarise(rows)
        else:
            merged[k] = reps[0][k]
    merged["merged_from_parts"] = [os.path.relpath(p, os.path.join(HERE, "..", ".."))
                                   for p in parts]
    with open(out_path, "w") as fh:
        json.dump(merged, fh, indent=2)
    print(f"wrote {out_path}: {len(rows)} folds, seeds {seeds}")

    ddir = os.path.join(HERE, "diagnostics")
    diags = []
    for p in parts:
        dp = os.path.join(ddir, os.path.basename(p))
        if os.path.exists(dp):
            diags.append(json.load(open(dp)))
    if diags:
        md = {"runner": diags[0]["runner"], "merged_from": [d["argv"] for d in diags],
              "runtime_seconds_sum": round(sum(d["runtime_seconds"] for d in diags), 1),
              "runtime_seconds_max_part": max(d["runtime_seconds"] for d in diags)}
        for key in ("fits", "fit_warnings_by_category", "fits_with_warning_category",
                    "mlp_fits_reaching_max_iter", "mlp_fits_with_nonfinite_parameters",
                    "weibull", "tail_fallback_lt3_correct_classes",
                    "tail_classes_total"):
            md[key] = _sum_nested([d.get(key, {}) for d in diags])
        md["mlp_n_iter_summary_parts"] = [d.get("mlp_n_iter_summary", {}) for d in diags]
        md["env"] = diags[0].get("env")
        md["python"] = diags[0].get("python")
        dout = os.path.join(ddir, os.path.basename(out_path))
        with open(dout, "w") as fh:
            json.dump(md, fh, indent=2)
        print(f"wrote {dout}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
