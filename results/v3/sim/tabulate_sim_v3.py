"""AUDIT-GENERATED post-processing of the v3 simulation runs.

Reads the reports written by scripts/holdout_inversion_sim.py (commit 3e3ebdb,
unmodified) in results/v3/sim/, and

1. checks the default ordered 5-seed run against the committed
   results/inversion_sim.json of the original tree (every pre-existing leaf value)
   and against Table 18 as printed in the manuscript (MS L641-646);
2. adds, to each report, a key ``audit_monte_carlo`` with per-cell Monte Carlo
   summaries over seeds (mean, sd, standard error, t-based 95% interval of the
   mean, 2.5/97.5 percentiles of the per-seed values, min, max, count below 0.5).
   The script-written report is first copied unchanged to results/v3/sim/raw/;
   every other key of the augmented report is verbatim script output;
3. writes table18_v3.csv (wide, one row per layout x seeds x spread) and
   table18_v3_long.csv (one row per layout x seeds x spread x holdout x metric);
4. writes sim_v3_summary.json with the reproduction check and the answers to
   (a) end-holdout inversion under the random layout, (b) Bayes family-holdout
   inversion near Bayes retained accuracy 0.8, (c) fitted forest inversion
   under family holdout.

Usage (from the repository root):
    python results/v3/sim/tabulate_sim_v3.py \
        --original ../../../obfuscope-main/results/inversion_sim.json \
        --manuscript ../../../obfuscope-main/docs/ObfuScope_manuscript_revised_2.md
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import math
import os
import re
import shutil
from typing import Dict, List

import numpy as np
from scipy import stats

HERE = os.path.dirname(os.path.abspath(__file__))

RUNS = {
    ("ordered", 5): "inversion_sim_ordered_5seeds.json",
    ("ordered", 20): "inversion_sim_ordered_20seeds.json",
    ("random", 5): "inversion_sim_random_5seeds.json",
    ("random", 20): "inversion_sim_random_20seeds.json",
}
SUPP = {
    ("ordered", 20): "supp_fine_ordered_20seeds.json",
    ("random", 20): "supp_fine_random_20seeds.json",
}

PER_SEED_METRICS = [
    "auroc_bayes_msp", "auroc_bayes_max_logit", "auroc_logreg_msp",
    "auroc_random_forest_msp", "closed_accuracy_bayes",
    "closed_accuracy_random_forest", "closed_accuracy_logreg",
    "mean_bayes_msp_known", "mean_bayes_msp_novel",
]

# Wide table: (column stem, holdout, per-seed metric)
WIDE = [
    ("bayes_posterior_auroc_end", "edge", "auroc_bayes_msp"),
    ("bayes_posterior_auroc_interior", "interior", "auroc_bayes_msp"),
    ("bayes_posterior_auroc_family", "family", "auroc_bayes_msp"),
    ("bayes_maxscore_auroc_end", "edge", "auroc_bayes_max_logit"),
    ("bayes_maxscore_auroc_interior", "interior", "auroc_bayes_max_logit"),
    ("bayes_maxscore_auroc_family", "family", "auroc_bayes_max_logit"),
    ("bayes_retained_acc_family", "family", "closed_accuracy_bayes"),
    ("rf_retained_acc_family", "family", "closed_accuracy_random_forest"),
    ("bayes_retained_acc_end", "edge", "closed_accuracy_bayes"),
    ("rf_retained_acc_end", "edge", "closed_accuracy_random_forest"),
    ("fitted_lr_auroc_end", "edge", "auroc_logreg_msp"),
    ("fitted_lr_auroc_interior", "interior", "auroc_logreg_msp"),
    ("fitted_lr_auroc_family", "family", "auroc_logreg_msp"),
    ("fitted_rf_auroc_end", "edge", "auroc_random_forest_msp"),
    ("fitted_rf_auroc_interior", "interior", "auroc_random_forest_msp"),
    ("fitted_rf_auroc_family", "family", "auroc_random_forest_msp"),
]

# Table 18 columns (MS L639) -> (holdout, row key in the report)
T18 = [
    ("Bayes posterior, end held out", "edge", "auroc_bayes_msp_mean"),
    ("Bayes maximum score, end held out", "edge", "auroc_bayes_max_logit_mean"),
    ("Bayes posterior, interior held out", "interior", "auroc_bayes_msp_mean"),
    ("Bayes posterior, family held out", "family", "auroc_bayes_msp_mean"),
    ("Bayes maximum score, family held out", "family", "auroc_bayes_max_logit_mean"),
    ("Retained class closed accuracy, family holdout", "family",
     "closed_accuracy_random_forest_mean"),
]


def sha256(path: str) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as fh:
        h.update(fh.read())
    return h.hexdigest()


def mc(values: List[float]) -> Dict:
    v = np.asarray(values, dtype=float)
    n = len(v)
    mean = float(v.mean())
    sd = float(v.std(ddof=1)) if n > 1 else 0.0
    se = sd / math.sqrt(n) if n > 1 else 0.0
    tq = float(stats.t.ppf(0.975, n - 1)) if n > 1 else float("nan")
    return {
        "n": n, "mean": mean, "sd": sd, "se": se,
        "ci95_mean_lo": mean - tq * se, "ci95_mean_hi": mean + tq * se,
        "t_quantile": tq,
        "pct2_5": float(np.percentile(v, 2.5)),
        "pct97_5": float(np.percentile(v, 97.5)),
        "min": float(v.min()), "max": float(v.max()),
        "n_below_0_5": int((v < 0.5).sum()),
    }


def summarise(report: Dict) -> Dict:
    cells = []
    for row in report["rows"]:
        cell = {"sibling_spread": row["sibling_spread"], "holdout": row["holdout"],
                "n_seeds": row["n_seeds"], "metrics": {}}
        for m in PER_SEED_METRICS:
            vals = [r[m] for r in row["per_seed"] if m in r]
            if vals:
                cell["metrics"][m] = mc(vals)
        # paired edge - interior difference is computed separately below
        cells.append(cell)
    # Paired (same seed, hence same class centres) edge minus interior difference
    # of the Bayes posterior AUROC.
    paired = []
    spreads = sorted({r["sibling_spread"] for r in report["rows"]})
    for s in spreads:
        e = [r for r in report["rows"] if r["sibling_spread"] == s and r["holdout"] == "edge"]
        i = [r for r in report["rows"] if r["sibling_spread"] == s and r["holdout"] == "interior"]
        if not (e and i):
            continue
        de = {r["seed"]: r["auroc_bayes_msp"] for r in e[0]["per_seed"]}
        di = {r["seed"]: r["auroc_bayes_msp"] for r in i[0]["per_seed"]}
        common = sorted(set(de) & set(di))
        d = [de[k] - di[k] for k in common]
        rec = {"sibling_spread": s, "edge_minus_interior": mc(d)}
        rec["edge_minus_interior"]["n_below_0"] = int((np.asarray(d) < 0).sum())
        if len(d) > 1:
            rec["paired_t_p_two_sided"] = float(stats.ttest_1samp(d, 0.0).pvalue)
            rec["wilcoxon_p_two_sided"] = float(stats.wilcoxon(d).pvalue) if any(d) else 1.0
        paired.append(rec)
    return {
        "note": ("AUDIT-GENERATED by results/v3/sim/tabulate_sim_v3.py. Monte Carlo "
                 "summaries over seeds of the per_seed values in this report: "
                 "ci95_mean_* is the t-based 95% interval of the mean "
                 "(mean +/- t(0.975, n-1) * sd/sqrt(n)); pct2_5/pct97_5 are "
                 "percentiles of the per-seed values; sd uses ddof=1. Every other "
                 "key of this file is verbatim output of "
                 "scripts/holdout_inversion_sim.py; the unmodified script output "
                 "is in raw/."),
        "cells": cells,
        "paired_edge_minus_interior_bayes_msp": paired,
    }


def cell(summary: Dict, spread: float, holdout: str, metric: str):
    for c in summary["cells"]:
        if c["sibling_spread"] == spread and c["holdout"] == holdout:
            return c["metrics"].get(metric)
    return None


def leaf_compare(a, b, path="", out=None):
    """Compare every leaf of ``a`` (the original) against ``b``."""
    if out is None:
        out = {"n": 0, "mismatch": []}
    if isinstance(a, dict):
        for k, v in a.items():
            if not isinstance(b, dict) or k not in b:
                out["mismatch"].append((path + "/" + k, "missing"))
                continue
            leaf_compare(v, b[k], path + "/" + str(k), out)
    elif isinstance(a, list):
        if not isinstance(b, list) or len(a) != len(b):
            out["mismatch"].append((path, "list length"))
            return out
        for i, (x, y) in enumerate(zip(a, b)):
            leaf_compare(x, y, f"{path}[{i}]", out)
    else:
        out["n"] += 1
        if a != b:
            out["mismatch"].append((path, f"{a!r} != {b!r}"))
    return out


def parse_ms_table18(ms_path: str) -> Dict[float, List[float]]:
    rows = {}
    with open(ms_path) as fh:
        lines = fh.read().splitlines()
    for ln in range(640, 647):  # MS L641-646 (1-indexed), with margin
        m = re.match(r"^\|\s*([0-9.]+)\s*\|(.*)\|\s*$", lines[ln])
        if m:
            vals = [float(x) for x in m.group(2).split("|")]
            rows[float(m.group(1))] = (ln + 1, vals)
    return rows


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--original", required=True)
    ap.add_argument("--manuscript", required=True)
    args = ap.parse_args()

    os.makedirs(os.path.join(HERE, "raw"), exist_ok=True)
    reports = {}
    raw_hashes = {}
    for key, fname in list(RUNS.items()) + [(("supp",) + k, v) for k, v in SUPP.items()]:
        path = os.path.join(HERE, fname)
        raw = os.path.join(HERE, "raw", fname)
        if not os.path.exists(raw):
            shutil.copyfile(path, raw)  # first pass: keep the script output
        with open(raw) as fh:
            rep = json.load(fh)
        raw_hashes[fname] = sha256(raw)
        rep["audit_monte_carlo"] = summarise(rep)
        with open(path, "w") as fh:
            json.dump(rep, fh, indent=2)
        reports[key] = rep

    # 1. reproduction check
    with open(args.original) as fh:
        orig = json.load(fh)
    new = reports[("ordered", 5)]
    cmp = leaf_compare({k: orig[k] for k in ("rows", "inverting_spreads")},
                       {k: new[k] for k in ("rows", "inverting_spreads")})
    settings_keys = list(orig["settings"].keys())
    set_cmp = {k: (orig["settings"][k], new["settings"].get(k))
               for k in settings_keys if orig["settings"][k] != new["settings"].get(k)}
    ms = parse_ms_table18(args.manuscript)
    t18 = []
    n_t18_match = 0
    for spread, (ln, ms_vals) in sorted(ms.items()):
        for (label, hold, key), ms_v in zip(T18, ms_vals):
            o = [r for r in orig["rows"] if r["sibling_spread"] == spread and r["holdout"] == hold][0][key]
            v = [r for r in new["rows"] if r["sibling_spread"] == spread and r["holdout"] == hold][0][key]
            ok = (o == v == ms_v)
            n_t18_match += ok
            t18.append({"ms_line": ln, "sibling_spread": spread, "column": label,
                        "manuscript": ms_v, "committed_json": o, "v3_rerun": v,
                        "match": ok})
    repro = {
        "original_file": os.path.abspath(args.original),
        "original_sha256": sha256(args.original),
        "rows_and_inverting_spreads_leaves_compared": cmp["n"],
        "rows_and_inverting_spreads_mismatches": cmp["mismatch"],
        "settings_original_keys_that_differ": set_cmp,
        "table18_cells_compared": len(t18),
        "table18_cells_matching_ms_committed_and_rerun": n_t18_match,
        "table18_cells": t18,
    }

    # 3. tables
    wide_rows, long_rows = [], []
    for (layout, nseeds), rep in sorted(((k, v) for k, v in reports.items() if len(k) == 2), key=lambda kv: str(kv[0])):
        if False:  # supplementary runs are tabulated separately below
            continue
        summ = rep["audit_monte_carlo"]
        for spread in sorted({c["sibling_spread"] for c in summ["cells"]}):
            w = {"layout": layout, "n_seeds": nseeds, "sibling_spread": spread}
            for stem, hold, metric in WIDE:
                s = cell(summ, spread, hold, metric)
                w[stem + "_mean"] = round(s["mean"], 4)
                w[stem + "_ci95_lo"] = round(s["ci95_mean_lo"], 4)
                w[stem + "_ci95_hi"] = round(s["ci95_mean_hi"], 4)
            wide_rows.append(w)
            for c in summ["cells"]:
                if c["sibling_spread"] != spread:
                    continue
                for metric, s in c["metrics"].items():
                    long_rows.append({
                        "layout": layout, "n_seeds": nseeds, "sibling_spread": spread,
                        "holdout": c["holdout"], "metric": metric,
                        "mean": round(s["mean"], 4), "sd": round(s["sd"], 4),
                        "se": round(s["se"], 4),
                        "ci95_mean_lo": round(s["ci95_mean_lo"], 4),
                        "ci95_mean_hi": round(s["ci95_mean_hi"], 4),
                        "pct2_5": round(s["pct2_5"], 4),
                        "pct97_5": round(s["pct97_5"], 4),
                        "min": round(s["min"], 4), "max": round(s["max"], 4),
                        "n_below_0_5": s["n_below_0_5"],
                    })
    order = {"ordered": 0, "random": 1}
    wide_rows.sort(key=lambda r: (order[r["layout"]], r["n_seeds"], r["sibling_spread"]))
    long_rows.sort(key=lambda r: (order[r["layout"]], r["n_seeds"], r["sibling_spread"],
                                  r["holdout"], r["metric"]))
    with open(os.path.join(HERE, "table18_v3.csv"), "w", newline="") as fh:
        wr = csv.DictWriter(fh, fieldnames=list(wide_rows[0].keys()))
        wr.writeheader()
        wr.writerows(wide_rows)
    with open(os.path.join(HERE, "table18_v3_long.csv"), "w", newline="") as fh:
        wr = csv.DictWriter(fh, fieldnames=list(long_rows[0].keys()))
        wr.writeheader()
        wr.writerows(long_rows)

    # Supplementary fine sweep table
    supp_rows = []
    for (tag, layout, nseeds), rep in [(k, v) for k, v in reports.items() if k[0] == "supp"]:
        summ = rep["audit_monte_carlo"]
        for spread in sorted({c["sibling_spread"] for c in summ["cells"]}):
            w = {"layout": layout, "n_seeds": nseeds, "sibling_spread": spread}
            for stem, hold, metric in WIDE:
                s = cell(summ, spread, hold, metric)
                w[stem + "_mean"] = round(s["mean"], 4)
                w[stem + "_ci95_lo"] = round(s["ci95_mean_lo"], 4)
                w[stem + "_ci95_hi"] = round(s["ci95_mean_hi"], 4)
            supp_rows.append(w)
    supp_rows.sort(key=lambda r: (order[r["layout"]], r["sibling_spread"]))
    with open(os.path.join(HERE, "supp_fine_sweep_v3.csv"), "w", newline="") as fh:
        wr = csv.DictWriter(fh, fieldnames=list(supp_rows[0].keys()))
        wr.writeheader()
        wr.writerows(supp_rows)

    # 4. answers
    def per_layout(layout, nseeds, include_supp=False):
        reps = [reports[(layout, nseeds)]]
        if include_supp and ("supp", layout, nseeds) in reports:
            reps.append(reports[("supp", layout, nseeds)])
        out = {}
        for rep in reps:
            for c in rep["audit_monte_carlo"]["cells"]:
                out.setdefault(c["sibling_spread"], {})[c["holdout"]] = c["metrics"]
        return dict(sorted(out.items()))

    answers = {}
    # (a)
    a = {}
    for nseeds in (5, 20):
        d = per_layout("random", nseeds)
        a[f"random_{nseeds}seeds"] = [{
            "sibling_spread": s,
            "edge_bayes_msp_mean": round(h["edge"]["auroc_bayes_msp"]["mean"], 4),
            "edge_ci95": [round(h["edge"]["auroc_bayes_msp"]["ci95_mean_lo"], 4),
                          round(h["edge"]["auroc_bayes_msp"]["ci95_mean_hi"], 4)],
            "edge_seeds_below_0_5": h["edge"]["auroc_bayes_msp"]["n_below_0_5"],
            "interior_bayes_msp_mean": round(h["interior"]["auroc_bayes_msp"]["mean"], 4),
            "interior_ci95": [round(h["interior"]["auroc_bayes_msp"]["ci95_mean_lo"], 4),
                              round(h["interior"]["auroc_bayes_msp"]["ci95_mean_hi"], 4)],
            "edge_mean_below_0_5": h["edge"]["auroc_bayes_msp"]["mean"] < 0.5,
            "edge_ci_entirely_below_0_5": h["edge"]["auroc_bayes_msp"]["ci95_mean_hi"] < 0.5,
        } for s, h in d.items()]
        a[f"random_{nseeds}seeds_paired_edge_minus_interior"] = [
            {"sibling_spread": p["sibling_spread"],
             "mean": round(p["edge_minus_interior"]["mean"], 4),
             "ci95": [round(p["edge_minus_interior"]["ci95_mean_lo"], 4),
                      round(p["edge_minus_interior"]["ci95_mean_hi"], 4)],
             "paired_t_p": p.get("paired_t_p_two_sided")}
            for p in reports[("random", nseeds)]["audit_monte_carlo"][
                "paired_edge_minus_interior_bayes_msp"]]
    answers["a_end_holdout_inversion_random_layout"] = a

    # (b)
    b = {}
    for layout in ("ordered", "random"):
        d = per_layout(layout, 20, include_supp=True)
        b[f"{layout}_20seeds_family"] = [{
            "sibling_spread": s,
            "bayes_retained_acc_mean": round(h["family"]["closed_accuracy_bayes"]["mean"], 4),
            "rf_retained_acc_mean": round(h["family"]["closed_accuracy_random_forest"]["mean"], 4),
            "bayes_posterior_auroc_mean": round(h["family"]["auroc_bayes_msp"]["mean"], 4),
            "bayes_posterior_auroc_ci95": [
                round(h["family"]["auroc_bayes_msp"]["ci95_mean_lo"], 4),
                round(h["family"]["auroc_bayes_msp"]["ci95_mean_hi"], 4)],
            "bayes_posterior_seeds_below_0_5": h["family"]["auroc_bayes_msp"]["n_below_0_5"],
            "inverts_mean_below_0_5": h["family"]["auroc_bayes_msp"]["mean"] < 0.5,
        } for s, h in d.items()]
        for nseeds in (5,):
            d5 = per_layout(layout, nseeds)
            b[f"{layout}_{nseeds}seeds_family"] = [{
                "sibling_spread": s,
                "bayes_retained_acc_mean": round(h["family"]["closed_accuracy_bayes"]["mean"], 4),
                "rf_retained_acc_mean": round(h["family"]["closed_accuracy_random_forest"]["mean"], 4),
                "bayes_posterior_auroc_mean": round(h["family"]["auroc_bayes_msp"]["mean"], 4),
            } for s, h in d5.items()]
    answers["b_family_holdout_vs_bayes_retained_accuracy"] = b

    # (c)
    c = {}
    for layout in ("ordered", "random"):
        for nseeds in (5, 20):
            d = per_layout(layout, nseeds, include_supp=(nseeds == 20))
            per_seed_min = []
            reps = [reports[(layout, nseeds)]]
            if nseeds == 20:
                reps.append(reports[("supp", layout, 20)])
            for rep in reps:
                for row in rep["rows"]:
                    if row["holdout"] == "family":
                        per_seed_min += [r["auroc_random_forest_msp"] for r in row["per_seed"]]
            c[f"{layout}_{nseeds}seeds"] = {
                "fitted_rf_family_auroc_by_spread": {
                    str(s): round(h["family"]["auroc_random_forest_msp"]["mean"], 4)
                    for s, h in d.items()},
                "fitted_lr_family_auroc_by_spread": {
                    str(s): round(h["family"]["auroc_logreg_msp"]["mean"], 4)
                    for s, h in d.items()},
                "fitted_rf_family_min_per_seed": round(min(per_seed_min), 4),
                "fitted_rf_family_seeds_below_0_5": int(sum(v < 0.5 for v in per_seed_min)),
                "n_family_cells_per_seed": len(per_seed_min),
            }
    answers["c_fitted_rf_family_holdout"] = c

    # Supporting evidence for the "diffuse and uninformative for every input"
    # reading (MS L650): mean Bayes novelty score (1 - max posterior) of known
    # versus novel artifacts under the family holdout, from the reports' own
    # mean_bayes_msp_known / mean_bayes_msp_novel per-seed values.
    fam_nov = {}
    for layout in ("ordered", "random"):
        d = per_layout(layout, 20, include_supp=True)
        fam_nov[f"{layout}_20seeds"] = [{
            "sibling_spread": s,
            "bayes_retained_acc_mean": round(h["family"]["closed_accuracy_bayes"]["mean"], 4),
            "mean_novelty_known": round(h["family"]["mean_bayes_msp_known"]["mean"], 4),
            "mean_novelty_novel": round(h["family"]["mean_bayes_msp_novel"]["mean"], 4),
            "bayes_posterior_auroc_mean": round(h["family"]["auroc_bayes_msp"]["mean"], 4),
        } for s, h in d.items()]
    answers["family_holdout_mean_novelty_known_vs_novel"] = fam_nov

    # Seeds 0-4 of every 20-seed run must equal the 5-seed run record for record
    # (one_condition seeds its own generator from the seed alone).
    seed_check = {}
    for layout in ("ordered", "random"):
        r5, r20 = reports[(layout, 5)], reports[(layout, 20)]
        n_cmp, n_bad = 0, 0
        for row5 in r5["rows"]:
            row20 = [r for r in r20["rows"] if r["sibling_spread"] == row5["sibling_spread"]
                     and r["holdout"] == row5["holdout"]][0]
            by_seed = {p["seed"]: p for p in row20["per_seed"]}
            for p in row5["per_seed"]:
                q = by_seed[p["seed"]]
                for k, v in p.items():
                    n_cmp += 1
                    n_bad += (q.get(k) != v)
        seed_check[layout] = {"per_seed_leaves_compared": n_cmp, "mismatches": n_bad}
    repro["seeds_0_4_of_20seed_run_equal_5seed_run"] = seed_check

    summary = {
        "note": "AUDIT-GENERATED. See tabulate_sim_v3.py for definitions.",
        "script": "scripts/holdout_inversion_sim.py",
        "script_sha256": sha256(os.path.join(HERE, "..", "..", "..", "scripts",
                                             "holdout_inversion_sim.py")),
        "raw_report_sha256": raw_hashes,
        "reproduction_check": repro,
        "answers": answers,
    }
    with open(os.path.join(HERE, "sim_v3_summary.json"), "w") as fh:
        json.dump(summary, fh, indent=2)
    print(json.dumps({"repro": {k: v for k, v in repro.items() if k != "table18_cells"}},
                     indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
