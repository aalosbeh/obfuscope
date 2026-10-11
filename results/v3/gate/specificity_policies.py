"""AUDIT-GENERATED (run:gate-v3). Re-score the gate specificity experiment.

Regenerates exactly the 21 synthetic tables of scripts/gate_specificity.py
(same generators, rng = default_rng(1000 + seed), seeds 0..2, the script's
default thresholds, gate seed = table seed, full_macro_f1 = None), runs
diversity_gate.run() with a JSON report per instance so that diagnostic 4's R,
headroom status and best-k scores are recorded, tags every failure message
with gate_specificity.which_checks_fired() (using the report's full failure
list, not the console lines), and scores agreement / sensitivity /
specificity under two policies:

  (i)  every failure disqualifies (the gate's own exit status)
  (ii) diagnostic 4 advisory: an instance is failed only when a check other
       than 4_feature_ceiling / 4b_headroom fired (MS L242: 1, 1b, 2, 3 and 6
       disqualifying; diagnostic 5 is also treated as disqualifying here, it
       is not named in MS L242)
  (ii-b, variant) only the headroom sub-check 4b advisory, the absolute
       best-k ceiling stays disqualifying

Clopper-Pearson exact 95% intervals (scipy.stats.beta).
The per-instance tags are cross-checked against gate_specificity_rerun.json
(the unmodified script's output) and results/gate_specificity.json.
"""
from __future__ import annotations
import tempfile

import io
import json
import os
import sys
from contextlib import redirect_stdout

import numpy as np
from scipy.stats import beta

ROOT = os.environ.get("OBFUSCOPE_REPO", os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "..")))
OUT = os.path.join(ROOT, "results/v3/gate")
TMP = os.environ.get("GATE_SPEC_TMP", os.path.join(tempfile.gettempdir(), "gate_v3_spec_tmp"))
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import diversity_gate as gate  # noqa: E402
import gate_specificity as gs  # noqa: E402

TH = dict(min_distinct_ratio=0.80, max_constant_fraction=0.50,
          max_affected_fraction=0.05, max_cross_class_fraction=0.005,
          max_single_feature_f1=0.70, min_headroom=0.50,
          min_input_dependence=0.20, input_dependence_alpha=0.05,
          permutation_tolerance=0.08)
D4 = {"4_feature_ceiling", "4b_headroom"}


def cp(x, n, alpha=0.05):
    lo = 0.0 if x == 0 else float(beta.ppf(alpha / 2, x, n - x + 1))
    hi = 1.0 if x == n else float(beta.ppf(1 - alpha / 2, x + 1, n - x))
    return [round(lo, 4), round(hi, 4)]


def score(rows, fail_fn, name):
    pos = [r for r in rows if not r["should_pass"]]
    neg = [r for r in rows if r["should_pass"]]
    tp = sum(1 for r in pos if fail_fn(r))
    tn = sum(1 for r in neg if not fail_fn(r))
    agree = tp + tn
    n = len(rows)
    fam = {}
    for f in gs.GENERATORS:
        rs = [r for r in rows if r["family"] == f]
        fam[f] = {"expected": "pass" if rs[0]["should_pass"] else "fail",
                  "failed_seeds": [r["seed"] for r in rs if fail_fn(r)],
                  "correct_seeds": sum(1 for r in rs
                                       if fail_fn(r) != r["should_pass"]),
                  "n_seeds": len(rs)}
    return {
        "policy": name,
        "agreement": f"{agree}/{n}", "agreement_rate": round(agree / n, 4),
        "agreement_cp95": cp(agree, n),
        "sensitivity": f"{tp}/{len(pos)}", "sensitivity_rate": round(tp / len(pos), 4),
        "sensitivity_cp95": cp(tp, len(pos)),
        "specificity": f"{tn}/{len(neg)}", "specificity_rate": round(tn / len(neg), 4),
        "specificity_cp95": cp(tn, len(neg)),
        "per_family": fam,
    }


def main():
    os.makedirs(TMP, exist_ok=True)
    rows = []
    for name, (fn, should_pass, note) in gs.GENERATORS.items():
        for seed in range(3):
            rng = np.random.default_rng(1000 + seed)
            df = fn(rng)
            csv = os.path.join(TMP, f"{name}_s{seed}.csv")
            rep = os.path.join(TMP, f"{name}_s{seed}.json")
            df.to_csv(csv, index=False)
            buf = io.StringIO()
            with redirect_stdout(buf):
                code = gate.run(features_path=csv, label="technique",
                                group="sample_id", seed=seed, report_path=rep,
                                skip_single_feature=False, full_macro_f1=None,
                                **TH)
            r = json.load(open(rep))
            sf = r["single_feature"]
            tags = gs.which_checks_fired(r["failures"])
            rows.append({
                "family": name, "seed": seed, "should_pass": should_pass,
                "n_rows": int(len(df)), "exit_code": code,
                "passed_policy_i": code == 0,
                "checks_fired": sorted(set(tags)),
                "n_failure_messages": len(r["failures"]),
                "n_classes": sf.get("n_classes"),
                "chance": sf.get("chance_macro_f1"),
                "best_feature": sf.get("best_feature"),
                "best_1": sf.get("best_macro_f1"),
                "best_k": sf.get("macro_f1_by_k"),
                "full_set_probe_macro_f1": sf.get("full_set_probe_macro_f1"),
                "headroom_gap": sf.get("headroom_gap"),
                "headroom_R": sf.get("headroom_R"),
                "headroom_status": sf.get("headroom_status"),
                "permuted_macro_f1": r["permuted_labels"].get("permuted_macro_f1"),
                "inconclusive": r.get("inconclusive", []),
            })
            os.remove(csv)
            print(name, seed, code, rows[-1]["checks_fired"], sf.get("headroom_R"),
                  sf.get("headroom_status"), sf.get("best_macro_f1"),
                  sf.get("full_set_probe_macro_f1"), flush=True)

    pol_i = score(rows, lambda r: bool(r["checks_fired"]), "(i) every failure disqualifies")
    pol_ii = score(rows, lambda r: bool(set(r["checks_fired"]) - D4),
                   "(ii) diagnostic 4 advisory (4_feature_ceiling and 4b_headroom ignored)")
    pol_iib = score(rows, lambda r: bool(set(r["checks_fired"]) - {"4b_headroom"}),
                    "(ii-b) only headroom 4b advisory, best-k ceiling disqualifying")

    # consistency checks against the script's own outputs
    cross = {}
    for label, path in (("rerun", os.path.join(OUT, "gate_specificity_rerun.json")),
                        ("committed", os.path.join(ROOT, "results/gate_specificity.json"))):
        if not os.path.exists(path):
            cross[label] = "file not found"
            continue
        d = json.load(open(path))
        mism = []
        for a in d["per_run"]:
            b = next(x for x in rows if x["family"] == a["family"] and x["seed"] == a["seed"])
            if (a["checks_fired"] != b["checks_fired"] or a["passed"] != b["passed_policy_i"]
                    or a["n_rows"] != b["n_rows"]):
                mism.append({"family": a["family"], "seed": a["seed"],
                             "script": [a["passed"], a["checks_fired"]],
                             "wrapper": [b["passed_policy_i"], b["checks_fired"]]})
        cross[label] = {"instances": len(d["per_run"]), "mismatches": mism,
                        "agreement": d.get("agreement"), "sensitivity": d.get("sensitivity"),
                        "specificity": d.get("specificity")}

    undefined = [r for r in rows if r["headroom_R"] is None]
    out = {
        "label": "AUDIT-GENERATED specificity re-scoring (run:gate-v3)",
        "thresholds": TH,
        "per_instance": rows,
        "policy_i": pol_i,
        "policy_ii": pol_ii,
        "policy_ii_b_variant": pol_iib,
        "R_undefined": {
            "count": len(undefined), "of": len(rows),
            "instances": [{"family": r["family"], "seed": r["seed"],
                           "full_set_probe_macro_f1": r["full_set_probe_macro_f1"],
                           "chance": r["chance"], "headroom_gap": r["headroom_gap"]}
                          for r in undefined],
            "note": ("R undefined means F1_full (probe tree on all features, no "
                     "--full-macro-f1 supplied) minus chance <= 1e-9; the gate "
                     "reports headroom_status 'inconclusive' and the headroom "
                     "sub-check neither passes nor fails"),
        },
        "headroom_status_counts": {s: sum(1 for r in rows if r["headroom_status"] == s)
                                   for s in sorted({r["headroom_status"] for r in rows})},
        "cross_check": cross,
    }
    with open(os.path.join(OUT, "specificity_policies.json"), "w") as fh:
        json.dump(out, fh, indent=2)
    for p in (pol_i, pol_ii, pol_iib):
        print(p["policy"], p["agreement"], p["agreement_cp95"], p["sensitivity"],
              p["sensitivity_cp95"], p["specificity"], p["specificity_cp95"])
    print("R undefined", len(undefined), "cross", json.dumps(cross)[:600])


if __name__ == "__main__":
    main()
