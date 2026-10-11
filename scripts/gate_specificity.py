"""Does the corpus gate fail only corpora that deserve to fail?

A gate that rejects everything is useless, and version 1 of this work never
established that its gate does anything else. The gate was run on two corpora,
both built by the same authors, and both failed. That is consistent with a
working diagnostic and equally consistent with thresholds tuned until the known
bad corpus failed. Nothing in the paper distinguished the two readings, and a
reviewer was right to say so.

Specificity cannot be demonstrated on corpora whose answer is already known.
This script therefore runs the gate across a set of synthetic feature tables
whose ground truth is fixed by construction, so for each one there is a correct
verdict that was decided before the gate ran. The families are:

  clean                  classes genuinely separated by many features, variation
                         driven by the input program. The gate must PASS. This is
                         the case that matters: a gate that fails this is useless.

  leaked_id              a clean table plus one column that is a deterministic
                         function of the class. The gate must FAIL on the single
                         feature ceiling.

  seed_jitter_only       class centres identical, every artifact distinct because
                         of independent noise, no dependence on the input program.
                         The gate must FAIL on input dependence, and the distinct
                         vector ratio alone must not catch it. This is the case
                         version 1's diagnostic 1 was defeated by.

  duplicated_rows        a clean table in which some artifacts are byte identical
                         copies appearing under two different input programs. The
                         gate must FAIL on cross group duplicates.

  ambiguous_labels       a clean table in which some identical vectors carry two
                         different class labels. The gate must FAIL on cross class
                         duplicates, the diagnostic version 1 did not have.

  hard_but_honest        classes genuinely overlapping, so accuracy is low and no
                         single feature is close to sufficient, but nothing is
                         degenerate. The gate must PASS. A gate that fails this is
                         confusing difficulty with invalidity, which would make it
                         a difficulty detector rather than a validity check.

  near_chance            classes carry essentially no signal. The gate must PASS,
                         because an unlearnable corpus is not an invalid one. The
                         paper's claim is about whether a reported result can be
                         trusted, not about whether a result exists.

The last two are the important ones for specificity. ``hard_but_honest`` and
``near_chance`` are corpora a careless gate would reject, and rejecting them
would mean the gate penalises honest difficulty. Reporting them is the part of
this analysis that can embarrass the gate, which is why they are included.

Each table is generated at several seeds and the verdict is recorded per seed, so
a diagnostic that fires only sometimes is visible as such rather than being
averaged away.

Usage
    python3 scripts/gate_specificity.py --report results/gate_specificity.json
"""

from __future__ import annotations

import argparse
import io
import json
import os
import sys
from contextlib import redirect_stdout
from typing import Callable, Dict, List, Optional, Sequence, Tuple

import numpy as np
import pandas as pd

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import diversity_gate as gate  # noqa: E402


# --------------------------------------------------------------- the generators

def _base(
    rng: np.random.Generator,
    n_classes: int,
    n_groups: int,
    n_per: int,
    n_feats: int,
    class_sep: float,
    group_sep: float,
    noise: float,
) -> pd.DataFrame:
    """Feature table with a class effect, a group effect, and noise.

    ``class_sep`` controls how far apart the classes sit, which is the signal a
    classifier should find. ``group_sep`` controls how much the input program
    shifts an artifact, which is what makes the variation input dependent rather
    than random. ``noise`` is independent per artifact and stands for generator
    randomness.
    """
    class_dirs = rng.normal(size=(n_classes, n_feats))
    class_dirs /= np.linalg.norm(class_dirs, axis=1, keepdims=True)
    group_dirs = rng.normal(size=(n_groups, n_feats))
    group_dirs /= np.linalg.norm(group_dirs, axis=1, keepdims=True)

    rows, labels, groups = [], [], []
    for c in range(n_classes):
        for g in range(n_groups):
            centre = class_sep * class_dirs[c] + group_sep * group_dirs[g]
            rows.append(rng.normal(loc=centre, scale=noise,
                                   size=(n_per, n_feats)))
            labels += [f"class_{c}"] * n_per
            groups += [f"prog_{g}"] * n_per

    X = np.vstack(rows)
    df = pd.DataFrame(X, columns=[f"f{i:02d}" for i in range(n_feats)])
    df.insert(0, "sample_id", groups)
    df.insert(0, "technique", labels)
    return df


def gen_clean(rng) -> pd.DataFrame:
    return _base(rng, 4, 12, 20, 30, class_sep=3.0, group_sep=2.0, noise=1.0)


def gen_leaked_id(rng) -> pd.DataFrame:
    df = gen_clean(rng)
    # One column that is a deterministic function of the label. Nothing else
    # changes, so any failure must come from this column.
    codes = df["technique"].astype("category").cat.codes.to_numpy()
    df["f_leak"] = codes.astype(float) * 100.0
    return df


def gen_seed_jitter_only(rng) -> pd.DataFrame:
    # Classes separated, but group_sep is zero, so the input program has no
    # effect at all. Every artifact is still distinct because of the noise, so
    # the distinct vector ratio stays at one and only the input dependence
    # diagnostic can see the problem.
    return _base(rng, 4, 12, 20, 30, class_sep=3.0, group_sep=0.0, noise=1.0)


def gen_duplicated_rows(rng) -> pd.DataFrame:
    df = gen_clean(rng).reset_index(drop=True)
    feats = [c for c in df.columns if c.startswith("f")]
    # Copy 8 percent of rows verbatim onto a different input program, which is
    # exactly the leak that grouping by program is supposed to prevent.
    n_copy = int(0.08 * len(df))
    src = rng.choice(len(df), size=n_copy, replace=False)
    dup = df.iloc[src].copy()
    others = sorted(df["sample_id"].unique())
    dup["sample_id"] = [
        rng.choice([o for o in others if o != s])
        for s in dup["sample_id"].to_numpy()
    ]
    return pd.concat([df, dup], ignore_index=True)


def gen_ambiguous_labels(rng) -> pd.DataFrame:
    df = gen_clean(rng).reset_index(drop=True)
    # Copy 3 percent of rows verbatim but relabel them, creating identical
    # vectors under two class labels. No model can get both right.
    n_copy = int(0.03 * len(df))
    src = rng.choice(len(df), size=n_copy, replace=False)
    dup = df.iloc[src].copy()
    classes = sorted(df["technique"].unique())
    dup["technique"] = [
        rng.choice([c for c in classes if c != t])
        for t in dup["technique"].to_numpy()
    ]
    return pd.concat([df, dup], ignore_index=True)


def gen_hard_but_honest(rng) -> pd.DataFrame:
    # Classes barely separated against the noise, so accuracy will be poor, but
    # the variation is input dependent and nothing is duplicated or leaked.
    return _base(rng, 6, 12, 20, 30, class_sep=0.6, group_sep=2.0, noise=1.0)


def gen_near_chance(rng) -> pd.DataFrame:
    # Essentially no class signal. Unlearnable, but not invalid.
    return _base(rng, 4, 12, 20, 30, class_sep=0.05, group_sep=2.0, noise=1.0)


GENERATORS: Dict[str, Tuple[Callable, bool, str]] = {
    "clean": (gen_clean, True,
              "separated classes, input dependent variation, nothing degenerate"),
    "hard_but_honest": (gen_hard_but_honest, True,
                        "genuinely overlapping classes; difficult, not invalid"),
    "near_chance": (gen_near_chance, True,
                    "almost no class signal; unlearnable, not invalid"),
    "leaked_id": (gen_leaked_id, False,
                  "one column is a deterministic function of the label"),
    "seed_jitter_only": (gen_seed_jitter_only, False,
                         "distinct vectors from noise alone, no input dependence"),
    "duplicated_rows": (gen_duplicated_rows, False,
                        "identical vectors under two different input programs"),
    "ambiguous_labels": (gen_ambiguous_labels, False,
                         "identical vectors under two different class labels"),
}


# ------------------------------------------------------------------- the harness

def which_checks_fired(failures: Sequence[str]) -> List[str]:
    """Label each failure message with the diagnostic that produced it."""
    tags = []
    for msg in failures:
        if "distinct vectors in" in msg:
            tags.append("1_distinctness")
        elif "have zero" in msg and "variance" in msg:
            tags.append("2_constant_features")
        elif "between program share" in msg or "does not track the" in msg:
            tags.append("1b_input_dependence")
        elif "span more than one" in msg:
            tags.append("3_cross_group_duplicates")
        elif "carry more than one" in msg:
            tags.append("6_cross_class_duplicates")
        elif "headroom" in msg:
            tags.append("4b_headroom")
        elif "single feature" in msg or "features together reach" in msg:
            tags.append("4_feature_ceiling")
        elif "permuted" in msg:
            tags.append("5_permuted_labels")
        else:
            tags.append("unlabelled")
    return tags


def run(args) -> int:
    print("Gate specificity on feature tables with a known correct verdict")
    print(f"  seeds per family {args.seeds}")
    print()
    print("  Each family below has a verdict fixed by construction, decided "
          "before the gate ran.")
    print("  The cases that can embarrass the gate are hard_but_honest and "
          "near_chance: a gate")
    print("  that fails those is a difficulty detector, not a validity check.")
    print()

    rows: List[Dict] = []
    for name, (fn, should_pass, note) in GENERATORS.items():
        for seed in range(args.seeds):
            rng = np.random.default_rng(1000 + seed)
            df = fn(rng)
            path = os.path.join(args.tmpdir, f"{name}_s{seed}.csv")
            os.makedirs(args.tmpdir, exist_ok=True)
            df.to_csv(path, index=False)

            buf = io.StringIO()
            with redirect_stdout(buf):
                code = gate.run(
                    features_path=path, label="technique", group="sample_id",
                    min_distinct_ratio=args.min_distinct_ratio,
                    max_constant_fraction=args.max_constant_fraction,
                    max_affected_fraction=args.max_cross_group_fraction,
                    max_single_feature_f1=args.max_single_feature_f1,
                    permutation_tolerance=args.permutation_tolerance,
                    seed=seed, report_path=None, skip_single_feature=False,
                    max_cross_class_fraction=args.max_cross_class_fraction,
                    min_headroom=args.min_headroom,
                    min_input_dependence=args.min_input_dependence,
                    input_dependence_alpha=args.input_dependence_alpha,
                    full_macro_f1=None,
                )
            text = buf.getvalue()
            failures = [l.strip() for l in text.splitlines()
                        if l.strip().startswith(tuple(f"{i}." for i in range(1, 10)))]
            fired = which_checks_fired(failures)
            passed = (code == 0)
            correct = (passed == should_pass)
            rows.append({
                "family": name, "seed": seed, "note": note,
                "should_pass": should_pass, "passed": passed,
                "correct": correct, "checks_fired": sorted(set(fired)),
                "n_rows": int(len(df)),
                "failure_messages": failures,
            })
            os.remove(path)

    # Summary per family.
    print(f"  {'family':20s} {'expect':7s} {'got':7s} {'correct':>8s}  "
          f"checks that fired")
    print("  " + "-" * 92)
    summary: Dict[str, Dict] = {}
    for name, (_, should_pass, note) in GENERATORS.items():
        rs = [r for r in rows if r["family"] == name]
        n_correct = sum(1 for r in rs if r["correct"])
        got = ("pass" if all(r["passed"] for r in rs)
               else "fail" if not any(r["passed"] for r in rs) else "mixed")
        fired = sorted({c for r in rs for c in r["checks_fired"]})
        summary[name] = {
            "expected": "pass" if should_pass else "fail",
            "observed": got,
            "correct_seeds": n_correct, "n_seeds": len(rs),
            "checks_fired": fired, "note": note,
        }
        print(f"  {name:20s} {('pass' if should_pass else 'fail'):7s} {got:7s} "
              f"{n_correct}/{len(rs):<6d}  {', '.join(fired) if fired else '(none)'}")
    print()

    n_tot = len(rows)
    n_ok = sum(1 for r in rows if r["correct"])
    pos = [r for r in rows if not r["should_pass"]]
    neg = [r for r in rows if r["should_pass"]]
    sens = sum(1 for r in pos if not r["passed"]) / len(pos) if pos else float("nan")
    spec = sum(1 for r in neg if r["passed"]) / len(neg) if neg else float("nan")

    print("  overall")
    print(f"    agreement with the constructed verdict   {n_ok}/{n_tot} "
          f"({n_ok / n_tot:.1%})")
    print(f"    sensitivity, degenerate tables failed    {sens:.1%} "
          f"({len(pos)} table instances)")
    print(f"    specificity, sound tables passed         {spec:.1%} "
          f"({len(neg)} table instances)")
    print()
    print("  Sensitivity and specificity here are properties of these "
          "constructed families at these")
    print("  thresholds, not of corpora in general. They establish that the "
          "gate discriminates, which")
    print("  is what version 1 failed to establish, and they do not establish "
          "that the thresholds are")
    print("  right for any particular real corpus.")

    if args.report:
        os.makedirs(os.path.dirname(args.report) or ".", exist_ok=True)
        with open(args.report, "w") as fh:
            json.dump({
                "thresholds": {
                    "min_distinct_ratio": args.min_distinct_ratio,
                    "max_constant_fraction": args.max_constant_fraction,
                    "max_cross_group_fraction": args.max_cross_group_fraction,
                    "max_cross_class_fraction": args.max_cross_class_fraction,
                    "max_single_feature_f1": args.max_single_feature_f1,
                    "min_headroom": args.min_headroom,
                    "min_input_dependence": args.min_input_dependence,
                    "permutation_tolerance": args.permutation_tolerance,
                },
                "per_run": rows, "per_family": summary,
                "agreement": round(n_ok / n_tot, 4),
                "sensitivity": round(sens, 4),
                "specificity": round(spec, 4),
            }, fh, indent=2)
        print()
        print(f"report written to {args.report}")
    return 0


def main(argv: Optional[Sequence[str]] = None) -> int:
    ap = argparse.ArgumentParser(
        description="Run the corpus gate on synthetic feature tables whose "
                    "correct verdict is fixed by construction, to show the "
                    "gate discriminates rather than rejecting everything.")
    ap.add_argument("--seeds", type=int, default=3)
    ap.add_argument("--tmpdir", default="/tmp/gate_specificity")
    ap.add_argument("--min-distinct-ratio", type=float, default=0.80)
    ap.add_argument("--max-constant-fraction", type=float, default=0.50)
    ap.add_argument("--max-cross-group-fraction", type=float, default=0.05)
    ap.add_argument("--max-cross-class-fraction", type=float, default=0.005)
    ap.add_argument("--max-single-feature-f1", type=float, default=0.70)
    ap.add_argument("--min-headroom", type=float, default=0.50)
    ap.add_argument("--min-input-dependence", type=float, default=0.20)
    ap.add_argument("--input-dependence-alpha", type=float, default=0.05)
    ap.add_argument("--permutation-tolerance", type=float, default=0.08)
    ap.add_argument("--report", default=None)
    args = ap.parse_args(argv)
    return run(args)


if __name__ == "__main__":
    raise SystemExit(main())
