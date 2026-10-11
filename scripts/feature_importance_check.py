#!/usr/bin/env python3
"""
Diagnostic: how much of the provenance signal comes from the literal
generator-boilerplate tokens the ``obfuscation`` feature family regexes are
keyed to (e.g. ``ob_cfl_*``, ``magic1``/``magic2``, ``vm_``/``bytecode``,
``self_modify``/``decrypt_at_runtime``), versus generic structural/lexical
signal?

Fits a Random Forest under the same protocol as the paper's headline result
(grouped, stratified 5-fold, seed 0) on the full feature set, and reports:
  - mean feature importance per feature, ranked
  - what fraction of total importance mass sits in the 10 literal
    boilerplate-regex features (the ``obf_*`` entries of
    obfuscope.features._OBF_INDICATORS)

This does not resolve whether the *remaining* signal (dominated by
size/token/line-count features) reflects genuine obfuscation semantics or
each generator template's deterministic output shape -- both are consistent
with the numbers below. It only rules out the narrowest version of the
concern (that classification is mostly literal keyword matching).

Usage: python3 scripts/feature_importance_check.py --data data/features.csv
"""
from __future__ import annotations

import argparse
import os
import sys

import numpy as np
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import StratifiedGroupKFold

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "src"))
from obfuscope.features import feature_names  # noqa: E402

# The 10 "obf_*" entries of _OBF_INDICATORS in features.py -- regexes keyed
# directly to boilerplate tokens documented in dataset/README.md's per-module
# algorithm descriptions (ob_cfl_*, magic1/2, vm_/bytecode, self_modify/
# decrypt_at_runtime, junk/dead/dummy, ...).
BOILERPLATE_REGEX_FEATURES = {
    "obf_opaque_pred", "obf_always_true", "obf_state_machine", "obf_magic",
    "obf_junk", "obf_goto", "obf_xor_key", "obf_random_name",
    "obf_vm_dispatch", "obf_selfmod",
}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--data", default="data/features.csv")
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--top", type=int, default=15)
    args = ap.parse_args(argv)

    df = pd.read_csv(args.data)
    cols = feature_names()
    X = np.nan_to_num(df[cols].to_numpy(dtype=float), nan=0.0, posinf=0.0, neginf=0.0)
    y = df["technique"].to_numpy()
    groups = df["sample_id"].to_numpy()

    sgkf = StratifiedGroupKFold(n_splits=5, shuffle=True, random_state=args.seed)
    importances = np.zeros(len(cols))
    accs = []
    for tr, te in sgkf.split(X, y, groups):
        clf = RandomForestClassifier(n_estimators=400, class_weight="balanced_subsample",
                                     random_state=args.seed, n_jobs=-1)
        clf.fit(X[tr], y[tr])
        importances += clf.feature_importances_
        accs.append(clf.score(X[te], y[te]))
    importances /= sgkf.get_n_splits()

    order = np.argsort(-importances)
    print(f"grouped_cv accuracy across {sgkf.get_n_splits()} folds: {np.mean(accs):.4f}")
    print(f"\nTop {args.top} features by mean importance:")
    for i in order[:args.top]:
        tag = "  <-- generator-boilerplate regex" if cols[i] in BOILERPLATE_REGEX_FEATURES else ""
        print(f"  {cols[i]:28s} {importances[i]:.4f}{tag}")

    boilerplate_mass = sum(importances[cols.index(n)] for n in BOILERPLATE_REGEX_FEATURES)
    print(f"\nImportance mass in the {len(BOILERPLATE_REGEX_FEATURES)} literal "
          f"boilerplate-regex features: {boilerplate_mass:.3f} (of 1.0 total)")


if __name__ == "__main__":
    main()
