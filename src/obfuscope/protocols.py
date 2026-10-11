"""
Evaluation protocols for ObfuScope.

Three protocols operationalise the study's central question -- *how well does a
static obfuscation-provenance model generalise beyond the exact artifacts it was
trained on?* -- along progressively harder axes of distribution shift.

``grouped_cv``  (closed-set provenance, unseen samples)
    Stratified group k-fold over ``sample_id``. Every obfuscated sibling of a
    test artifact is confined to the same fold, so reported accuracy reflects
    generalisation to malware samples never seen in training.

``lomfo``       (Leave-One-Malware-Family-Out, unseen malware)
    Each malware family is held out in turn as the test set; the model trains on
    all other families. This isolates whether the transformation fingerprint is
    *malware-agnostic* -- the key robustness claim.

``looo``        (Leave-One-Obfuscation-Out, novel toolchain / open-set)
    One transformation family is removed from training entirely and re-injected
    at test time as an *unknown* class. The task is no longer closed-set
    classification but open-set recognition: can the system flag artifacts from a
    previously-unseen obfuscator as novel? Scored by the AUROC of an inlier score
    (maximum class posterior) separating known-class from held-out artifacts.

Each generator yields ``Split`` records that the single-cell runner consumes.
"""
from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, Iterator, List

import numpy as np


@dataclass
class Split:
    protocol: str
    fold_id: str
    train_idx: np.ndarray
    test_idx: np.ndarray
    # For LOOO the held-out technique is the "novel" class at test time.
    holdout_label: str = ""
    meta: Dict = field(default_factory=dict)


def grouped_cv(groups: np.ndarray, y: np.ndarray, n_splits: int = 5,
               seed: int = 0) -> Iterator[Split]:
    """Stratified-by-label, grouped-by-sample k-fold."""
    from sklearn.model_selection import StratifiedGroupKFold
    sgkf = StratifiedGroupKFold(n_splits=n_splits, shuffle=True, random_state=seed)
    for k, (tr, te) in enumerate(sgkf.split(np.zeros(len(y)), y, groups)):
        yield Split("grouped_cv", f"fold{k}", tr, te)


def lomfo(families: np.ndarray, y: np.ndarray, n_splits: int = 5,
          seed: int = 0) -> Iterator[Split]:
    """Leave-Malware-Families-Out via family-grouped k-fold.

    The corpus is singleton-dominated along the malware axis (most families
    contribute a single sample), so a literal leave-one-family-out loop would
    fit ~90 nearly-identical models. Instead the families are partitioned into
    ``n_splits`` disjoint groups; in each fold the model trains on the families
    of the other groups and is tested on the held-out families. Because train
    and test family sets are disjoint, accuracy still measures generalisation to
    malware unseen at training time, while keeping the fold count small and the
    per-fold test set statistically substantial."""
    from sklearn.model_selection import StratifiedGroupKFold
    n_fam = len(set(families.tolist()))
    k = max(2, min(n_splits, n_fam))
    sgkf = StratifiedGroupKFold(n_splits=k, shuffle=True, random_state=seed)
    for i, (tr, te) in enumerate(sgkf.split(np.zeros(len(y)), y, families)):
        yield Split("lomfo", f"famfold{i}", tr, te,
                    meta={"n_test_families": int(len(set(families[te].tolist())))})


def looo(techniques: np.ndarray) -> Iterator[Split]:
    """Leave-One-Obfuscation-Out (open-set). ``test_idx`` covers the entire
    corpus; the held-out technique's rows are the novel (positive) class and all
    other rows are known (negative). ``train_idx`` excludes the held-out
    technique so the model never observes it during fitting."""
    for tech in sorted(set(techniques.tolist())):
        tr = np.where(techniques != tech)[0]
        te = np.arange(len(techniques))
        yield Split("looo", f"novel={tech}", tr, te, holdout_label=tech,
                    meta={"novel_technique": tech})


def iter_splits(protocol: str, *, groups=None, y=None, families=None,
                techniques=None, n_splits: int = 5, seed: int = 0) -> List[Split]:
    if protocol == "grouped_cv":
        return list(grouped_cv(groups, y, n_splits=n_splits, seed=seed))
    if protocol == "lomfo":
        return list(lomfo(families, y, n_splits=n_splits, seed=seed))
    if protocol == "looo":
        return list(looo(techniques))
    raise ValueError(f"unknown protocol '{protocol}'")
