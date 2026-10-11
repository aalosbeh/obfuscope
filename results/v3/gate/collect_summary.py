"""AUDIT-GENERATED (run:gate-v3). Collect the key numbers of results/v3/gate
into gate_v3_summary.json. Reads only files in results/v3/gate and the
committed results/*.json reports."""
import hashlib
import json
import os

ROOT = os.environ.get("OBFUSCOPE_REPO", os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "..")))
G = os.path.join(ROOT, "results/v3/gate")


def load(name):
    p = os.path.join(G, name)
    return json.load(open(p)) if os.path.exists(p) else None


def d4(rep):
    sf = rep["single_feature"]
    return {k: sf.get(k) for k in (
        "n_classes", "chance_macro_f1", "best_feature", "best_macro_f1",
        "macro_f1_by_k", "full_set_macro_f1", "full_set_source",
        "full_set_probe_macro_f1", "headroom_R", "headroom_R_probe_reference",
        "headroom_status", "full_set_shallow_depth3")}


def gate_summary(name):
    r = load(name)
    if r is None:
        return None
    cc = {k: v for k, v in r["cross_class_duplicates"].items() if k != "worst_clusters"}
    per_class = [{k: c.get(k) for k in ("class", "n", "distinct_vectors", "distinct_ratio",
                                        "dependence_omega2", "dependence_p")}
                 for c in r["per_class"]]
    return {"passed": r["passed"], "n_failures": len(r["failures"]),
            "failures_short": [f[:160] for f in r["failures"]],
            "inconclusive": r.get("inconclusive"), "diagnostic_4": d4(r),
            "diagnostic_6": cc, "diagnostic_3": r["cross_group_duplicates"],
            "diagnostic_5": r["permuted_labels"], "per_class": per_class}


def rep_summary(name):
    r = load(name)
    if r is None:
        return None
    s = r["single_feature_repeats"]
    out = {"seeds": s["seeds"], "best_feature_by_seed": s["best_feature_by_seed"],
           "headroom_status_by_seed": s["headroom_status_by_seed"]}
    for key in ("best_1_macro_f1", "headroom_R", "headroom_R_probe_reference",
                "full_set_probe_macro_f1"):
        out[key] = {k: s[key][k] for k in ("mean", "min", "max", "n_defined", "values")}
    for k, v in s["best_k_macro_f1"].items():
        out[f"best_{k}_macro_f1"] = {kk: v[kk] for kk in ("mean", "min", "max", "n_defined", "values")}
    out["seed0_rank_of_best_1_ascending"] = sorted(s["best_1_macro_f1"]["values"]).index(
        s["best_1_macro_f1"]["values"][0]) + 1
    return out


summary = {
    "label": "AUDIT-GENERATED run:gate-v3 summary",
    "task1_selfcontained": {n: gate_summary(f"gate_selfcontained_{n}.json")
                            for n in ("technique", "subtechnique", "v1")},
    "task1_supplied": {n: gate_summary(f"gate_supplied_{n}.json")
                       for n in ("technique", "subtechnique", "v1")},
    "task1_supplied_vs_committed": load("compare_supplied_vs_committed.json"),
    "task2_repeats": {n: rep_summary(f"gate_repeats_{n}.json") for n in (
        "selfcontained_technique", "supplied_technique",
        "selfcontained_subtechnique", "supplied_subtechnique")},
    "task3_consistent_protocol": {
        lab: {k: v for k, v in r.items() if k not in ("all_singles",)}
        for lab, r in (load("consistent_protocol_R.json") or {"results": {}})["results"].items()},
    "task4_specificity": None,
    "task5_eta_bias": load("eta_bias_example.json"),
    "task6_noop": {
        "audit_totals": (load("noop_artifacts.json") or {}).get("totals"),
        "filter": load("noop_filter.json"),
        "gate_noop_free": {n: gate_summary(f"gate_noop_free_{n}.json") for n in (
            "selfcontained_subtechnique", "supplied_subtechnique",
            "supplied_noopRF_subtechnique", "selfcontained_technique")},
    },
}
sp = load("specificity_policies.json")
if sp is not None:
    summary["task4_specificity"] = {
        k: sp[k] for k in ("policy_i", "policy_ii", "policy_ii_b_variant",
                           "R_undefined", "headroom_status_counts", "cross_check")}
    summary["task4_specificity"]["per_instance"] = [
        {k: r[k] for k in ("family", "seed", "should_pass", "passed_policy_i", "checks_fired",
                           "best_1", "best_k", "full_set_probe_macro_f1", "headroom_gap",
                           "headroom_R", "headroom_status")}
        for r in sp["per_instance"]]

files = sorted(f for f in os.listdir(G) if os.path.isfile(os.path.join(G, f)))
summary["sha256"] = {f: hashlib.sha256(open(os.path.join(G, f), "rb").read()).hexdigest()
                     for f in files if f != "gate_v3_summary.json"}
json.dump(summary, open(os.path.join(G, "gate_v3_summary.json"), "w"), indent=2)
print("written gate_v3_summary.json")
