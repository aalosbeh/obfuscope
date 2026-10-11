"""AUDIT-GENERATED summaries of the v3 open set reports.

Reads results/v3/openset_{A,B,C}_{heldout,all,kfold}.json and
results/v3/sibling_position_{heldout,all,kfold}.json, and writes CSV/JSON to
results/v3/summary/:

  table14.csv              Table 14 analogue: MSP AUROC per estimator x
                           configuration x variant, sd over folds (population
                           and sample), fraction of folds < 0.5, closed accuracy
                           (predict and argmax), ECE (argmax-consistent and the
                           legacy predict-based value), n folds, mean n_novel,
                           novel prevalence.
  table17.csv              Table 17 analogue for logreg, mlp, svm_rbf in A, B, C:
                           msp/energy/openmax AUROC means and per-fold counts of
                           msp<energy, energy<openmax, msp<energy<openmax,
                           openmax>0.5; openmax FPR95 in both conventions.
  grid.csv                 Every estimator x scorer x configuration x variant:
                           AUROC, both FPR95 conventions with achieved TPR, OSCR,
                           AUPR-novel / AUPR-known with prevalence; not-applicable
                           and error cells marked.
  model_free.csv           knn_dist, mahalanobis, iforest per configuration and
                           variant, de-duplicated over estimators (their scores do
                           not depend on the estimator; checked).
  table15.csv, table16.csv Per-parameterisation and per-position AUROC for
                           configuration B (msp), with axis projection.
  sibling_tests.json       Fold-level Welch t, exact parameterisation-level
                           permutation p values, PC1 variance shares.
  bc_contrast.csv/.json    B minus C MSP AUROC per estimator with bootstrap CIs.
  bc_per_class.csv         Per held-out unit MSP AUROC means for B and C.
  sanity_all_vs_committed.json  v3 'all' runs against the committed
                           obfuscope-main/results/openset_v2_*.json.
  diagnostics_summary.json Runtimes, MLP non-convergence, Weibull fallbacks,
                           scorer errors.
  key_numbers.json         Headline values and manuscript comparisons.

Standard deviations: "sd_pop" is numpy's default (ddof=0), which is what the
script's own summary and the manuscript tables use; "sd" (ddof=1) is given as
well. A "fold" is one (estimator, seed, held-out unit) cell under gss and one
(estimator, seed, held-out unit, program block) cell under program_kfold.
"""
from __future__ import annotations

import csv
import itertools
import json
import os
import sys
from typing import Dict, List

import numpy as np
import pandas as pd

_SELF = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.normpath(os.path.join(_SELF, "..", ".."))
# V3_DIR overrides the input/output directory (used only for testing).
HERE = os.environ.get("V3_DIR", _SELF)
OUT = os.path.join(HERE, "summary")
COMMITTED = os.environ.get(
    "OBFUSCOPE_ORIGINAL",
    os.path.join(_SELF, "..", "..", "..", "..", "obfuscope-main"))

VARIANTS = {
    "heldout": "split gss, --novel-programs heldout (novel rows only from the "
               "6 evaluation programs)",
    "all": "split gss, --novel-programs all (novel rows from all 30 programs; "
           "the protocol of the committed reports and the manuscript)",
    "kfold": "split program_kfold, 5 blocks, --novel-programs heldout",
}
CONFIGS = {
    "A": "label technique, technique held out (4 classes)",
    "B": "label sub_technique, sub_technique held out (10 classes)",
    "C": "label sub_technique, technique held out (10 classes)",
}
COMMITTED_FILES = {"A": "openset_v2_technique.json",
                   "B": "openset_v2_subtechnique.json",
                   "C": "openset_v2_family.json"}
MODELS = ["random_forest", "extra_trees", "logreg", "svm_rbf", "knn", "mlp"]
SCORERS = ["msp", "energy", "knn_dist", "mahalanobis", "iforest", "openmax",
           "evt_posterior"]
MODEL_FREE = ["knn_dist", "mahalanobis", "iforest"]
LOGIT_MODELS = ["svm_rbf", "logreg", "mlp"]

EXPECTED_POS = {
    "ref_opq_junk": "end", "ref_lit_xor": "end", "ref_lit_sum": "end",
    "ref_opq_true": "end",
    "ref_str_xor": "end_of_pair", "ref_str_add": "end_of_pair",
    "ref_ren_long": "end_of_pair", "ref_ren_hex": "end_of_pair",
    "ref_lit_mixed": "interior", "ref_opq_both": "interior",
}
FAMILY_OF = {"ref_opq_junk": "addopaque", "ref_opq_true": "addopaque",
             "ref_opq_both": "addopaque", "ref_lit_xor": "encodeliterals",
             "ref_lit_sum": "encodeliterals", "ref_lit_mixed": "encodeliterals",
             "ref_str_xor": "encodestrings", "ref_str_add": "encodestrings",
             "ref_ren_long": "renameidentifiers",
             "ref_ren_hex": "renameidentifiers"}

BOOT_R = 10000
BOOT_SEED = 20261009


# --------------------------------------------------------------------------- #

def _f(x, nd=4):
    if x is None:
        return ""
    if isinstance(x, (float, np.floating)):
        if not np.isfinite(x):
            return "nan"
        return f"{float(x):.{nd}f}"
    return str(x)


def write_csv(name: str, rows: List[Dict]) -> str:
    path = os.path.join(OUT, name)
    if not rows:
        open(path, "w").close()
        return path
    keys: List[str] = []
    for r in rows:
        for k in r:
            if k not in keys:
                keys.append(k)
    with open(path, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=keys)
        w.writeheader()
        for r in rows:
            w.writerow({k: (_f(v, 6) if isinstance(v, (float, np.floating))
                            else v) for k, v in r.items()})
    return path


def write_json(name: str, obj) -> str:
    path = os.path.join(OUT, name)
    with open(path, "w") as fh:
        json.dump(obj, fh, indent=2, default=lambda o: o.item()
                  if hasattr(o, "item") else str(o))
    return path


def load_reports() -> Dict:
    reps = {}
    for v in VARIANTS:
        for c in CONFIGS:
            p = os.path.join(HERE, f"openset_{c}_{v}.json")
            if os.path.exists(p):
                reps[(c, v)] = json.load(open(p))
    return reps


def folds(rep: Dict, model: str) -> List[Dict]:
    return [f for f in rep["per_fold"] if f["model"] == model]


def sc(f: Dict, scorer: str, key: str = "auroc"):
    s = f["scorers"].get(scorer, {})
    return s.get(key)


def stats(v) -> Dict:
    v = np.asarray([x for x in v if x is not None], dtype=float)
    if v.size == 0:
        return {"n": 0}
    return {"n": int(v.size), "mean": float(v.mean()),
            "sd_pop": float(v.std()),
            "sd": float(v.std(ddof=1)) if v.size > 1 else 0.0,
            "min": float(v.min()), "max": float(v.max()),
            "frac_lt_0.5": float((v < 0.5).mean())}


# --------------------------------------------------------------------------- #
# (1) Table 14 analogue

def table14(reps) -> List[Dict]:
    rows = []
    for (c, v), rep in sorted(reps.items(), key=lambda kv: (list(VARIANTS).index(kv[0][1]), kv[0][0])):
        for m in MODELS:
            fs = folds(rep, m)
            if not fs:
                continue
            a = stats([sc(f, "msp") for f in fs])
            rows.append({
                "variant": v, "config": c, "model": m,
                "msp_auroc_mean": a["mean"], "msp_auroc_sd_pop": a["sd_pop"],
                "msp_auroc_sd": a["sd"], "msp_frac_folds_lt_0.5": a["frac_lt_0.5"],
                "closed_accuracy_predict": float(np.mean([f["closed_accuracy"] for f in fs])),
                "closed_accuracy_argmax": float(np.mean([f["closed_accuracy_argmax"] for f in fs])),
                "ece_argmax": float(np.mean([f["ece"] for f in fs])),
                "ece_legacy_predict": float(np.mean([f["ece_legacy_predict"] for f in fs])),
                "n_folds": len(fs),
                "n_novel_mean": float(np.mean([f["n_novel"] for f in fs])),
                "n_known_eval_mean": float(np.mean([f["n_known_eval"] for f in fs])),
                "novel_prevalence_mean": float(np.mean([f["novel_prevalence"] for f in fs])),
                "n_novel_from_fit_programs_mean": float(np.mean([f["n_novel_from_fit_programs"] for f in fs])),
            })
    return rows


# --------------------------------------------------------------------------- #
# (2) Table 17 analogue

def table17(reps) -> List[Dict]:
    rows = []
    for (c, v), rep in sorted(reps.items(), key=lambda kv: (list(VARIANTS).index(kv[0][1]), kv[0][0])):
        for m in LOGIT_MODELS:
            fs = folds(rep, m)
            if not fs:
                continue
            ms = np.array([sc(f, "msp") for f in fs], dtype=float)
            en = np.array([sc(f, "energy") for f in fs], dtype=float)
            om = np.array([sc(f, "openmax") for f in fs], dtype=float)
            rows.append({
                "variant": v, "config": c, "model": m, "n_folds": len(fs),
                "msp_auroc_mean": float(ms.mean()),
                "energy_auroc_mean": float(en.mean()),
                "openmax_auroc_mean": float(om.mean()),
                "mean_order_msp<energy<openmax": bool(ms.mean() < en.mean() < om.mean()),
                "n_msp<energy": int((ms < en).sum()),
                "n_energy<openmax": int((en < om).sum()),
                "n_msp<energy<openmax": int(((ms < en) & (en < om)).sum()),
                "n_openmax>0.5": int((om > 0.5).sum()),
                "n_energy>0.5": int((en > 0.5).sum()),
                "n_msp>0.5": int((ms > 0.5).sum()),
                "openmax_fpr95_known_pos_mean": float(np.mean([sc(f, "openmax", "fpr95_known_pos") for f in fs])),
                "openmax_tpr95_achieved_known_pos_mean": float(np.mean([sc(f, "openmax", "tpr95_achieved_known_pos") for f in fs])),
                "openmax_fpr95_novel_pos_mean": float(np.mean([sc(f, "openmax", "fpr95_novel_pos") for f in fs])),
                "openmax_tpr95_achieved_novel_pos_mean": float(np.mean([sc(f, "openmax", "tpr95_achieved_novel_pos") for f in fs])),
            })
    return rows


# --------------------------------------------------------------------------- #
# (3) full grid

GRID_KEYS = ["auroc", "fpr95_known_pos", "tpr95_achieved_known_pos",
             "fpr95_novel_pos", "tpr95_achieved_novel_pos", "oscr",
             "oscr_legacy_predict", "aupr_novel", "aupr_known"]


def grid(reps) -> List[Dict]:
    rows = []
    for (c, v), rep in sorted(reps.items(), key=lambda kv: (list(VARIANTS).index(kv[0][1]), kv[0][0])):
        for m in MODELS:
            fs = folds(rep, m)
            if not fs:
                continue
            prev = float(np.mean([f["novel_prevalence"] for f in fs]))
            for s in SCORERS:
                ents = [f["scorers"].get(s, {}) for f in fs]
                ok = [e for e in ents if "auroc" in e]
                na = [e for e in ents if "not_applicable" in e]
                er = [e for e in ents if "error" in e]
                row = {"variant": v, "config": c, "model": m, "scorer": s,
                       "n_folds": len(fs), "n_ok": len(ok),
                       "n_not_applicable": len(na), "n_error": len(er),
                       "novel_prevalence_mean": prev}
                if not ok:
                    row["status"] = ("not_applicable" if na else "error")
                    rows.append(row)
                    continue
                row["status"] = "ok" if len(ok) == len(fs) else "partial"
                for k in GRID_KEYS:
                    vals = np.array([e[k] for e in ok], dtype=float)
                    row[f"{k}_mean"] = float(vals.mean())
                    row[f"{k}_sd_pop"] = float(vals.std())
                    if k.startswith("tpr95"):
                        row[f"{k}_min"] = float(vals.min())
                row["auroc_frac_lt_0.5"] = float(np.mean([e["auroc"] < 0.5 for e in ok]))
                rows.append(row)
    return rows


# --------------------------------------------------------------------------- #
# (4) model-free scorers

def model_free(reps) -> List[Dict]:
    rows = []
    for (c, v), rep in sorted(reps.items(), key=lambda kv: (list(VARIANTS).index(kv[0][1]), kv[0][0])):
        for s in MODEL_FREE:
            by_key: Dict = {}
            for f in rep["per_fold"]:
                e = f["scorers"].get(s, {})
                if "auroc" not in e:
                    continue
                key = (f["seed"], f["novel_class"], f["block"])
                by_key.setdefault(key, []).append(e)
            maxdiff = 0.0
            uniq = []
            for key, es in by_key.items():
                a = np.array([e["auroc"] for e in es])
                maxdiff = max(maxdiff, float(a.max() - a.min()))
                uniq.append(es[0])
            a = stats([e["auroc"] for e in uniq])
            rows.append({
                "variant": v, "config": c, "scorer": s,
                "n_unique_folds": len(uniq),
                "auroc_mean": a["mean"], "auroc_sd_pop": a["sd_pop"],
                "auroc_sd": a["sd"], "auroc_frac_lt_0.5": a["frac_lt_0.5"],
                "fpr95_known_pos_mean": float(np.mean([e["fpr95_known_pos"] for e in uniq])),
                "fpr95_novel_pos_mean": float(np.mean([e["fpr95_novel_pos"] for e in uniq])),
                "aupr_novel_mean": float(np.mean([e["aupr_novel"] for e in uniq])),
                "aupr_known_mean": float(np.mean([e["aupr_known"] for e in uniq])),
                "max_abs_auroc_diff_across_estimators_same_fold": maxdiff,
            })
    return rows


# --------------------------------------------------------------------------- #
# (5) Table 15/16 analogues

def welch(a, b) -> Dict:
    from scipy import stats as st
    a, b = np.asarray(a, float), np.asarray(b, float)
    va, vb = a.var(ddof=1), b.var(ddof=1)
    se = np.sqrt(va / len(a) + vb / len(b))
    t = (a.mean() - b.mean()) / se
    num = (va / len(a) + vb / len(b)) ** 2
    den = (va / len(a)) ** 2 / (len(a) - 1) + (vb / len(b)) ** 2 / (len(b) - 1)
    df = num / den
    return {"mean_a": float(a.mean()), "mean_b": float(b.mean()),
            "difference": float(a.mean() - b.mean()), "n_a": int(len(a)),
            "n_b": int(len(b)), "t": float(t), "welch_df": float(df),
            "nominal_p_two_sided_NOT_VALID_folds_not_independent":
                float(2 * st.t.sf(abs(t), df))}


def perm_lower(values: Dict[str, float], group_a: List[str],
               group_b: List[str]) -> Dict:
    """Exact one-sided permutation p for mean(A) < mean(B).

    All C(n_a + n_b, n_a) relabellings of the pooled parameterisations;
    p = #{T* <= T_obs} / #arrangements, T = mean(A) - mean(B).
    """
    pool = group_a + group_b
    x = np.array([values[k] for k in pool])
    na = len(group_a)
    t_obs = x[:na].mean() - x[na:].mean()
    ts = []
    for idx in itertools.combinations(range(len(pool)), na):
        msk = np.zeros(len(pool), bool)
        msk[list(idx)] = True
        ts.append(x[msk].mean() - x[~msk].mean())
    ts = np.array(ts)
    k = int((ts <= t_obs + 1e-12).sum())
    return {"t_obs_mean_diff": float(t_obs), "n_arrangements": int(len(ts)),
            "n_as_or_more_extreme": k, "p_one_sided": k / len(ts),
            "min_attainable_p": 1.0 / len(ts)}


def pc1_shares(features_path: str) -> Dict:
    """Recompute sibling_position_analysis.sibling_positions without rounding."""
    df = pd.read_csv(features_path)
    label_cols = ["path", "cohort", "sample_id", "technique", "sub_technique",
                  "malware_family"]
    feats = [c for c in df.columns
             if c not in label_cols and pd.api.types.is_numeric_dtype(df[c])]
    x = df[feats].astype("float64").fillna(0.0)
    sd = x.std(axis=0).replace(0.0, 1.0)
    z = (x - x.mean(axis=0)) / sd
    out = {}
    for fam, grp in df.groupby("technique"):
        subs = sorted(grp["sub_technique"].unique())
        cen = np.stack([z.loc[grp.index[grp["sub_technique"] == s]].mean(axis=0)
                        .to_numpy() for s in subs])
        cen = cen - cen.mean(axis=0)
        _, s_vals, vt = np.linalg.svd(cen, full_matrices=False)
        proj = cen @ vt[0]
        out[str(fam)] = {"pc1_variance_share": float(s_vals[0] ** 2 / (s_vals ** 2).sum()),
                         "n_features_used": len(feats),
                         "projections": {s: float(p) for s, p in zip(subs, proj)}}
    return out


def sibling(reps, positions_by_variant) -> (List[Dict], List[Dict], Dict):
    t15, t16, tests = [], [], {}
    for v in VARIANTS:
        rep = reps.get(("B", v))
        pos = positions_by_variant.get(v)
        if rep is None or pos is None:
            continue
        pmap = {k: p["position"] for k, p in pos["positions"].items()}
        by_cls: Dict[str, List[float]] = {}
        for f in rep["per_fold"]:
            a = sc(f, "msp")
            if a is not None:
                by_cls.setdefault(f["novel_class"], []).append(a)
        means = {k: float(np.mean(x)) for k, x in by_cls.items()}
        for k in sorted(by_cls, key=lambda k: (pos["positions"][k]["family"],
                                               pos["positions"][k]["rank_in_family"])):
            p = pos["positions"][k]
            s = stats(by_cls[k])
            t15.append({"variant": v, "sub_technique": k, "family": p["family"],
                        "axis_projection": p["projection"],
                        "position": p["position"],
                        "position_matches_task_list": EXPECTED_POS.get(k) == p["position"],
                        "rank_in_family": p["rank_in_family"],
                        "pc1_share": p["axis_variance_explained"],
                        "n_folds": s["n"], "msp_auroc_mean": s["mean"],
                        "msp_auroc_sd": s["sd"], "frac_lt_0.5": s["frac_lt_0.5"],
                        "min": s["min"], "max": s["max"]})
        groups: Dict[str, List[float]] = {}
        for k, x in by_cls.items():
            groups.setdefault(pmap[k], []).extend(x)
        for g in ("end", "end_of_pair", "interior"):
            s = stats(groups.get(g, []))
            t16.append({"variant": v, "position": g, "n_folds": s["n"],
                        "n_parameterisations": sum(1 for k in pmap if pmap[k] == g),
                        "mean": s["mean"], "sd": s["sd"], "sd_pop": s["sd_pop"],
                        "frac_lt_0.5": s["frac_lt_0.5"],
                        "param_level_mean_of_means": float(np.mean(
                            [means[k] for k in means if pmap[k] == g]))})
        ends = [k for k in means if pmap[k] == "end"]
        ints = [k for k in means if pmap[k] == "interior"]
        pairs = [k for k in means if pmap[k] == "end_of_pair"]
        tests[v] = {
            "fold_level_welch_end_vs_interior": welch(groups["end"], groups["interior"]),
            "fold_level_welch_end_vs_pairs_and_interior": welch(
                groups["end"], groups["end_of_pair"] + groups["interior"]),
            "fold_level_welch_end_of_pair_vs_interior": welch(
                groups["end_of_pair"], groups["interior"]),
            "param_level_perm_ends_lt_interiors": perm_lower(means, sorted(ends), sorted(ints)),
            "param_level_perm_ends_lt_pairs_and_interiors": perm_lower(
                means, sorted(ends), sorted(pairs + ints)),
            "param_level_means": means,
            "positions_match_task_list": all(EXPECTED_POS[k] == pmap[k] for k in pmap),
            "sibling_script_report": {
                "grouped": pos.get("grouped"),
                "contrast_end_vs_interior": pos.get("contrast_end_vs_interior"),
                "verdict": pos.get("verdict")},
        }
    return t15, t16, tests


# --------------------------------------------------------------------------- #
# (6) B vs C contrast

def cell_matrix(rep: Dict, model: str):
    """Units x seeds matrix of MSP AUROC (mean over blocks under kfold)."""
    cells: Dict = {}
    for f in folds(rep, model):
        a = sc(f, "msp")
        if a is None:
            continue
        cells.setdefault((f["novel_class"], f["seed"]), []).append(a)
    units = sorted({u for u, _ in cells})
    seeds = sorted({s for _, s in cells})
    M = np.array([[np.mean(cells[(u, s)]) for s in seeds] for u in units])
    nb = sorted({len(x) for x in cells.values()})
    return units, seeds, M, nb


def boot_crossed(rng, M: np.ndarray, R: int) -> np.ndarray:
    nu, ns = M.shape
    wu = rng.multinomial(nu, np.full(nu, 1.0 / nu), size=R)
    ws = rng.multinomial(ns, np.full(ns, 1.0 / ns), size=R)
    return np.einsum("ru,us,rs->r", wu, M, ws) / (nu * ns)


def bc_contrast(reps):
    rows, per_class = [], []
    rng = np.random.default_rng(BOOT_SEED)
    for v in VARIANTS:
        rb, rc = reps.get(("B", v)), reps.get(("C", v))
        if rb is None or rc is None:
            continue
        for m in MODELS:
            ub, sb, MB, nbb = cell_matrix(rb, m)
            uc, scs, MC, nbc = cell_matrix(rc, m)
            fold_b = [sc(f, "msp") for f in folds(rb, m)]
            fold_c = [sc(f, "msp") for f in folds(rc, m)]
            mean_b, mean_c = float(np.mean(fold_b)), float(np.mean(fold_c))
            bb = boot_crossed(rng, MB, BOOT_R)
            bcv = boot_crossed(rng, MC, BOOT_R)
            d = bb - bcv
            # family-paired: d[f, s] = mean over B units of family f - C at f
            fams = uc
            D = np.array([[MB[[i for i, u in enumerate(ub) if FAMILY_OF[u] == fam], j].mean()
                           - MC[k, j] for j in range(len(sb))]
                          for k, fam in enumerate(fams)])
            dp = boot_crossed(rng, D, BOOT_R)
            rows.append({
                "variant": v, "model": m,
                "B_msp_auroc_mean": mean_b, "C_msp_auroc_mean": mean_c,
                "B_minus_C": mean_b - mean_c,
                "boot_ci95_lo": float(np.percentile(d, 2.5)),
                "boot_ci95_hi": float(np.percentile(d, 97.5)),
                "boot_frac_ge_0": float((d >= 0).mean()),
                "B_cell_mean_check": float(MB.mean()), "C_cell_mean_check": float(MC.mean()),
                "B_units": len(ub), "C_units": len(uc), "seeds": len(sb),
                "blocks_per_cell": f"{nbb}/{nbc}",
                "family_paired_mean_diff": float(D.mean()),
                "family_paired_ci95_lo": float(np.percentile(dp, 2.5)),
                "family_paired_ci95_hi": float(np.percentile(dp, 97.5)),
                "n_B_folds": len(fold_b), "n_C_folds": len(fold_c),
            })
            for i, u in enumerate(ub):
                per_class.append({"variant": v, "model": m, "config": "B",
                                  "held_out_unit": u, "family": FAMILY_OF[u],
                                  "msp_auroc_mean": float(MB[i].mean()),
                                  "seed_sd": float(MB[i].std(ddof=1)),
                                  "n_cells": MB.shape[1]})
            for k, u in enumerate(uc):
                per_class.append({"variant": v, "model": m, "config": "C",
                                  "held_out_unit": u, "family": u,
                                  "msp_auroc_mean": float(MC[k].mean()),
                                  "seed_sd": float(MC[k].std(ddof=1)),
                                  "n_cells": MC.shape[1]})
    scheme = {
        "replicates": BOOT_R, "rng": f"numpy default_rng({BOOT_SEED})",
        "cell": "one (held-out unit, seed) cell = the MSP AUROC of that fold "
                "under gss, or the mean over the 5 program blocks under "
                "program_kfold",
        "primary": "two-way crossed bootstrap drawn independently for B and C: "
                   "in each replicate draw the held-out units with replacement "
                   "(10 for B, 4 for C) and the seeds with replacement (5), "
                   "average the cells of the drawn unit x seed product, and "
                   "take B minus C; percentile 95% interval",
        "family_paired": "per family f and seed s, d[f,s] = mean of the B "
                         "cells of f's parameterisations minus the C cell of "
                         "f; crossed bootstrap over the 4 families and 5 "
                         "seeds; this weights families equally, so its point "
                         "estimate differs from the primary contrast (which "
                         "weights parameterisations equally)",
        "caveat": "C has only 4 held-out units, so the unit resampling of C is "
                  "coarse; seeds vary estimator randomness and (gss) the "
                  "program split, so seed is not a pure replicate either",
    }
    return rows, per_class, scheme


# --------------------------------------------------------------------------- #
# sanity

def sanity(reps) -> Dict:
    out = {}
    for c, fn in COMMITTED_FILES.items():
        rep = reps.get((c, "all"))
        p = os.path.join(COMMITTED, "results", fn)
        if rep is None or not os.path.exists(p):
            out[c] = {"skipped": "missing"}
            continue
        old = json.load(open(p))
        idx = {(f["model"], f["seed"], f["novel_class"]): f for f in old["per_fold"]}
        res = {"committed_file": p, "n_committed_folds": len(old["per_fold"]),
               "n_v3_folds": len(rep["per_fold"]), "n_matched": 0,
               "auroc_max_abs_diff_by_scorer": {}, "other_max_abs_diff": {}}
        diffs: Dict[str, float] = {}
        other: Dict[str, float] = {}
        nm = 0
        for f in rep["per_fold"]:
            o = idx.get((f["model"], f["seed"], f["novel_class"]))
            if o is None:
                continue
            nm += 1
            for s in SCORERS:
                a, b = f["scorers"].get(s, {}), o["scorers"].get(s, {})
                if "auroc" in a and "auroc" in b:
                    diffs[s] = max(diffs.get(s, 0.0), abs(a["auroc"] - b["auroc"]))
                    for k, k_old in (("fpr95_novel_pos", "fpr_at_95tpr"),
                                     ("aupr_novel", "aupr_novel"),
                                     ("oscr_legacy_predict", "oscr")):
                        if k_old in b:
                            kk = f"{s}.{k}_vs_committed_{k_old}"
                            other[kk] = max(other.get(kk, 0.0), abs(a[k] - b[k_old]))
                elif ("auroc" in a) != ("auroc" in b):
                    diffs[s + "_presence_mismatch"] = diffs.get(s + "_presence_mismatch", 0) + 1
            for k, k_old in (("closed_accuracy", "closed_accuracy"),
                             ("ece_legacy_predict", "ece"), ("n_novel", "n_novel"),
                             ("n_known_eval", "n_known_eval")):
                other[f"{k}_vs_committed_{k_old}"] = max(
                    other.get(f"{k}_vs_committed_{k_old}", 0.0), abs(f[k] - o[k_old]))
        res["n_matched"] = nm
        res["auroc_max_abs_diff_by_scorer"] = diffs
        res["auroc_max_abs_diff_overall"] = max(v for k, v in diffs.items()
                                                if not k.endswith("mismatch")) if diffs else None
        res["other_max_abs_diff"] = other
        # summary-level msp means
        res["msp_auroc_mean_committed_vs_v3"] = {
            m: [old["summary"][m]["scorers"]["msp"]["auroc_mean"],
                rep["summary"][m]["scorers"]["msp"]["auroc_mean"]]
            for m in MODELS if m in old["summary"]}
        out[c] = res
    # heldout and all share the known side under gss
    for c in CONFIGS:
        a, b = reps.get((c, "heldout")), reps.get((c, "all"))
        if a is None or b is None:
            continue
        ib = {(f["model"], f["seed"], f["novel_class"]): f for f in b["per_fold"]}
        mx = 0.0
        same_programs = True
        for f in a["per_fold"]:
            g = ib[(f["model"], f["seed"], f["novel_class"])]
            mx = max(mx, abs(f["closed_accuracy"] - g["closed_accuracy"]),
                     abs(f["ece"] - g["ece"]))
            same_programs &= f["eval_programs"] == g["eval_programs"]
        out[f"{c}_heldout_vs_all_known_side"] = {
            "max_abs_diff_closed_accuracy_and_ece": mx,
            "identical_eval_programs": bool(same_programs)}
    return out


# --------------------------------------------------------------------------- #
# cross-check against the earlier audit-generated program-overlap control

OVERLAP = os.environ.get(
    "OVERLAP_CONTROL_OUT",
    os.path.join(_SELF, "..", "..", "..", "audit_scratch", "experiment_program-overlap-control", "out"))


def crosscheck_overlap(reps) -> Dict:
    """v3 heldout vs control 'novel_unseen'; v3 kfold vs control kfold_*."""
    out = {"control_dir": OVERLAP}
    if not os.path.isdir(OVERLAP):
        out["skipped"] = "control outputs not found"
        return out
    files = {"A": ["A"], "B": ["B1", "B2"], "C": ["C"]}
    for c, names in files.items():
        for v, prefix in (("heldout", ""), ("kfold", "kfold_")):
            rep = reps.get((c, v))
            if rep is None:
                continue
            ctrl = {}
            for n in names:
                p = os.path.join(OVERLAP, f"{prefix}{n}.json")
                if not os.path.exists(p):
                    continue
                for f in json.load(open(p))["per_fold"]:
                    key = (f["model"], f["seed"], f["novel_class"], f.get("block"))
                    ctrl[key] = f
            diffs: Dict[str, float] = {}
            nm = 0
            for f in rep["per_fold"]:
                key = (f["model"], f["seed"], f["novel_class"], f["block"])
                g = ctrl.get(key)
                if g is None:
                    continue
                nm += 1
                for s in SCORERS:
                    a = f["scorers"].get(s, {})
                    b = g["scorers"].get(s, {})
                    if v == "heldout":
                        b = b.get("novel_unseen", {})
                    if "auroc" in a and "auroc" in b:
                        diffs[s] = max(diffs.get(s, 0.0), abs(a["auroc"] - b["auroc"]))
                    if "fpr95_known_pos" in a and "fpr95_knownpos" in b:
                        diffs[s + ".fpr95_known_pos"] = max(
                            diffs.get(s + ".fpr95_known_pos", 0.0),
                            abs(a["fpr95_known_pos"] - b["fpr95_knownpos"]))
            out[f"{c}_{v}"] = {"n_control_folds": len(ctrl), "n_matched": nm,
                               "max_abs_diff": diffs}
    return out


# --------------------------------------------------------------------------- #
# diagnostics

def diagnostics(reps) -> Dict:
    ddir = os.path.join(HERE, "diagnostics")
    out = {}
    for (c, v), rep in reps.items():
        name = f"openset_{c}_{v}"
        dp = os.path.join(ddir, name + ".json")
        d = json.load(open(dp)) if os.path.exists(dp) else {}
        errs: Dict[str, int] = {}
        for f in rep["per_fold"]:
            for s, e in f["scorers"].items():
                if "error" in e:
                    errs[f"{f['model']}.{s}"] = errs.get(f"{f['model']}.{s}", 0) + 1
        out[name] = {
            "n_folds": len(rep["per_fold"]),
            "runtime_seconds": d.get("runtime_seconds", d.get("runtime_seconds_sum")),
            "runtime_seconds_max_part": d.get("runtime_seconds_max_part"),
            "fits": d.get("fits"),
            "mlp_fits_reaching_max_iter": d.get("mlp_fits_reaching_max_iter"),
            "convergence_warnings": {m: x.get("ConvergenceWarning", 0) for m, x in
                                     (d.get("fit_warnings_by_category") or {}).items()},
            "fits_with_warning_category": d.get("fits_with_warning_category"),
            "mlp_fits_with_nonfinite_parameters": d.get("mlp_fits_with_nonfinite_parameters"),
            "weibull": d.get("weibull"),
            "tail_fallback_lt3_correct_classes": d.get("tail_fallback_lt3_correct_classes"),
            "tail_classes_total": d.get("tail_classes_total"),
            "scorer_errors": errs,
        }
    return out


# --------------------------------------------------------------------------- #
# manuscript comparison (values typed from docs/ObfuScope_manuscript_revised_2.md)

MS_T14 = {  # MS L544-549: model -> (A, B, C, accA, accB, accC)
    "random_forest": (0.8923, 0.2528, 0.9142, 0.9399, 0.8286, 0.8190),
    "extra_trees": (0.8808, 0.1914, 0.9073, 0.9258, 0.7849, 0.7800),
    "svm_rbf": (0.7549, 0.2799, 0.7543, 0.8310, 0.6243, 0.6245),
    "logreg": (0.6597, 0.3699, 0.5743, 0.8878, 0.6966, 0.6994),
    "mlp": (0.6453, 0.3604, 0.5983, 0.8776, 0.6682, 0.6828),
    "knn": (0.5156, 0.3469, 0.6643, 0.8714, 0.5967, 0.5848),
}
MS_T14_LINE = {"random_forest": 544, "extra_trees": 545, "svm_rbf": 546,
               "logreg": 547, "mlp": 548, "knn": 549}
MS_T15 = {  # MS L578-587
    "ref_opq_junk": (578, 0.1303, -3.0836), "ref_lit_xor": (579, 0.1541, -2.1615),
    "ref_lit_sum": (580, 0.2328, 2.2177), "ref_str_xor": (581, 0.2261, -0.1164),
    "ref_str_add": (582, 0.2431, 0.1164), "ref_opq_true": (583, 0.2375, 3.1463),
    "ref_ren_long": (584, 0.3503, 1.2404), "ref_lit_mixed": (585, 0.4405, -0.0562),
    "ref_opq_both": (586, 0.4129, -0.0626), "ref_ren_hex": (587, 0.5744, -1.2404),
}
MS_T16 = {"end": (593, 120, 0.1887, 0.1119, 0.9917),
          "end_of_pair": (594, 120, 0.3485, 0.1881, 0.8083),
          "interior": (595, 60, 0.4267, 0.1316, 0.6667)}
MS_T17 = {"svm_rbf": (614, 0.2799, 0.5324, 0.6355, 0.6782),
          "logreg": (615, 0.3699, 0.5028, 0.5202, 0.8669),
          "mlp": (616, 0.3604, 0.4496, 0.5115, 0.8699)}


def _status(ms, v, tol_exact=5e-5, tol_minor=1e-3):
    if v is None or ms is None or not np.isfinite(v):
        return "INSUFFICIENT INFORMATION"
    d = abs(ms - v)
    if d <= tol_exact:
        return "VERIFIED"
    if d <= tol_minor:
        return "MINOR NUMERICAL DIFFERENCE"
    return "NOT REPRODUCED"


def ms_comparison(reps, t14, t15, t16, t17, mfree, tests) -> List[Dict]:
    rows = []

    def get(tab, **kw):
        for r in tab:
            if all(r.get(k) == v for k, v in kw.items()):
                return r
        return None

    def add(item, line, ms, key_fn, tol=5e-5):
        vals = {v: key_fn(v) for v in VARIANTS}
        rows.append({"item": item, "ms_line": f"MS L{line}", "ms_value": ms,
                     "v3_all": vals["all"], "v3_heldout": vals["heldout"],
                     "v3_kfold": vals["kfold"],
                     "status_vs_v3_all": _status(ms, vals["all"], tol, max(tol * 20, 1e-3))})

    for m, vals in MS_T14.items():
        for i, c in enumerate("ABC"):
            add(f"T14 {m} {c} msp AUROC", MS_T14_LINE[m], vals[i],
                lambda v, m=m, c=c: (get(t14, variant=v, config=c, model=m) or {}).get("msp_auroc_mean"))
            add(f"T14 {m} {c} closed accuracy (predict)", MS_T14_LINE[m], vals[3 + i],
                lambda v, m=m, c=c: (get(t14, variant=v, config=c, model=m) or {}).get("closed_accuracy_predict"))
    for k, (line, a, proj) in MS_T15.items():
        add(f"T15 {k} AUROC", line, a,
            lambda v, k=k: (get(t15, variant=v, sub_technique=k) or {}).get("msp_auroc_mean"))
        add(f"T15 {k} axis projection", line, proj,
            lambda v, k=k: (get(t15, variant=v, sub_technique=k) or {}).get("axis_projection"))
    for g, (line, n, mean, sd, frac) in MS_T16.items():
        add(f"T16 {g} mean", line, mean, lambda v, g=g: (get(t16, variant=v, position=g) or {}).get("mean"))
        add(f"T16 {g} sd", line, sd, lambda v, g=g: (get(t16, variant=v, position=g) or {}).get("sd"))
        add(f"T16 {g} fraction below 0.5", line, frac,
            lambda v, g=g: (get(t16, variant=v, position=g) or {}).get("frac_lt_0.5"))
        add(f"T16 {g} folds", line, float(n),
            lambda v, g=g: float((get(t16, variant=v, position=g) or {}).get("n_folds", float("nan"))))
    add("L597 Welch |t| ends vs interior (fold level)", 597, 12.0,
        lambda v: abs(tests.get(v, {}).get("fold_level_welch_end_vs_interior", {}).get("t", float("nan"))), tol=0.05)
    add("L597 Welch df", 597, 102.7,
        lambda v: tests.get(v, {}).get("fold_level_welch_end_vs_interior", {}).get("welch_df"), tol=0.05)
    for m, (line, a, b, c, fpr) in MS_T17.items():
        for name, ms in (("msp", a), ("energy", b), ("openmax", c)):
            add(f"T17 {m} {name} AUROC", line, ms,
                lambda v, m=m, name=name: (get(t17, variant=v, config="B", model=m) or {}).get(f"{name}_auroc_mean"))
        add(f"T17 {m} openmax FPR95 (code: novel-positive)", line, fpr,
            lambda v, m=m: (get(t17, variant=v, config="B", model=m) or {}).get("openmax_fpr95_novel_pos_mean"))
        add(f"T17 {m} openmax FPR95 (text: known-positive)", line, fpr,
            lambda v, m=m: (get(t17, variant=v, config="B", model=m) or {}).get("openmax_fpr95_known_pos_mean"))
    for s_, ms in (("knn_dist", 0.1533), ("mahalanobis", 0.2054), ("iforest", 0.4522)):
        add(f"L625 B {s_} AUROC", 625, ms,
            lambda v, s_=s_: (get(mfree, variant=v, config="B", scorer=s_) or {}).get("auroc_mean"))
    for c, s_, ms in (("A", "knn_dist", 0.5465), ("C", "knn_dist", 0.5465),
                      ("A", "iforest", 0.5803), ("C", "iforest", 0.5803),
                      ("A", "mahalanobis", 0.5779), ("C", "mahalanobis", 0.5791)):
        add(f"L627 {c} {s_} AUROC", 627, ms,
            lambda v, c=c, s_=s_: (get(mfree, variant=v, config=c, scorer=s_) or {}).get("auroc_mean"))
    return rows


# --------------------------------------------------------------------------- #

def main() -> int:
    os.makedirs(OUT, exist_ok=True)
    reps = load_reports()
    print("reports:", sorted(reps))
    positions = {}
    for v in VARIANTS:
        p = os.path.join(HERE, f"sibling_position_{v}.json")
        if os.path.exists(p):
            positions[v] = json.load(open(p))
    files = []
    t14, t17, mfree = table14(reps), table17(reps), model_free(reps)
    gr = grid(reps)
    files.append(write_csv("table14.csv", t14))
    files.append(write_csv("table17.csv", t17))
    files.append(write_csv("grid.csv", gr))
    files.append(write_csv("model_free.csv", mfree))
    t15, t16, tests = sibling(reps, positions)
    files.append(write_csv("table15.csv", t15))
    files.append(write_csv("table16.csv", t16))
    tests["pc1_recomputed_unrounded"] = pc1_shares(os.path.join(REPO, "data", "features_pilot.csv"))
    files.append(write_json("sibling_tests.json", tests))
    files.append(write_csv("manuscript_comparison.csv",
                           ms_comparison(reps, t14, t15, t16, t17, mfree, tests)))
    bc, pcl, scheme = bc_contrast(reps)
    files.append(write_csv("bc_contrast.csv", bc))
    files.append(write_csv("bc_per_class.csv", pcl))
    files.append(write_json("bc_contrast.json", {"scheme": scheme, "rows": bc}))
    files.append(write_json("sanity_all_vs_committed.json", sanity(reps)))
    files.append(write_json("diagnostics_summary.json", diagnostics(reps)))
    files.append(write_json("crosscheck_overlap_control.json", crosscheck_overlap(reps)))
    files.append(write_json("manifest.json", {
        "generated_by": "AUDIT-GENERATED results/v3/summarise_openset.py",
        "variants": VARIANTS, "configs": CONFIGS,
        "reports": {f"{c}_{v}": f"results/v3/openset_{c}_{v}.json" for c, v in reps},
        "files": [os.path.relpath(f, REPO) for f in files]}))
    for f in files:
        print("wrote", f)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
