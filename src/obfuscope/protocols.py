"""
Evaluation protocols for ObfuScope.

The protocols ask how well a static transformation-attribution model
generalises beyond the input programs it was trained on. On the released pilot
corpus every artifact is a source-to-source rewrite of one of 30 synthetic
benign C programs (``sample_id``), grouped into five program domains; there is
no malware in it.

``grouped_cv``  (closed set, unseen input programs)
    Stratified group k-fold over ``sample_id``. Every obfuscated sibling of a
    test artifact is confined to the same fold, so the score reflects
    generalisation to input programs never seen in training. In scikit-learn
    1.6.1 the seed does not change this partition on the pilot corpus; see
    :func:`grouped_cv` and its opt-in ``permute_groups``.

``lomfo``       (program domain holdout; the code name is version 1 legacy)
    Group k-fold over the ``malware_family`` column. Both names come from
    version 1, whose grouping column held malware family names parsed from
    sample directory names. On the pilot corpus the column
    holds the program domain (bitops, dsalgo, mathlib, statemach, textproc,
    six programs each), so with five folds each fold holds out one whole
    domain and the model is tested on a kind of program it has not seen. The
    names are kept so that result files on disk still match the code.

``looo``        (leave one transformation out)
    One transformation family is removed from training and its artifacts are
    the novel class at test time. ``obfuscope.experiment`` runs this protocol
    through its own ``_run_looo`` (maximum class posterior only, novel rows from
    every program); the open set results of the revised manuscript come from
    ``scripts/openset_baselines.py`` instead, and the :func:`looo` generator
    below is reachable only through :func:`iter_splits`, which no script in
    this repository calls with ``"looo"``.

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


def permuted_group_codes(groups: np.ndarray, seed: int) -> np.ndarray:
    """Relabel group ids with a seed dependent random permutation.

    The sorted unique group ids are mapped to
    ``np.random.RandomState(seed).permutation(n_groups)``, so the same seed
    always gives the same relabelling and the grouping itself (which rows
    share a group) is unchanged.
    """
    groups = np.asarray(groups)
    uniq = sorted(set(groups.tolist()))
    codes = np.random.RandomState(seed).permutation(len(uniq))
    lookup = dict(zip(uniq, codes.tolist()))
    return np.array([lookup[g] for g in groups.tolist()], dtype=int)


def grouped_cv(groups: np.ndarray, y: np.ndarray, n_splits: int = 5,
               seed: int = 0, permute_groups: bool = False) -> Iterator[Split]:
    """Stratified-by-label, grouped-by-sample k-fold.

    ``shuffle=True, random_state=seed`` does not by itself reseed the
    partition. In scikit-learn 1.6.1 ``StratifiedGroupKFold`` shuffles the
    rows of its per group label count matrix rather than the group identities,
    so when every group has the same label counts (as in the pilot corpus,
    where every program contributes the same number of artifacts of every
    class) the shuffle is a no-op and every seed yields the same partition,
    fixed by the sorted order of the group ids.

    With ``permute_groups=True`` the group ids are first relabelled with
    :func:`permuted_group_codes`, which changes the order in which the greedy
    splitter visits the groups, so different seeds give genuinely different
    partitions. The default (``False``) keeps the original behaviour, so
    existing results are reproduced unchanged.
    """
    from sklearn.model_selection import StratifiedGroupKFold
    sgkf = StratifiedGroupKFold(n_splits=n_splits, shuffle=True, random_state=seed)
    g = permuted_group_codes(groups, seed) if permute_groups else groups
    for k, (tr, te) in enumerate(sgkf.split(np.zeros(len(y)), y, g)):
        yield Split("grouped_cv", f"fold{k}", tr, te)


def lomfo(families: np.ndarray, y: np.ndarray, n_splits: int = 5,
          seed: int = 0) -> Iterator[Split]:
    """Program domain holdout via domain-grouped k-fold (code name ``lomfo``).

    ``families`` is the ``malware_family`` column, which on the pilot corpus
    holds the program domain of each input program. The domains are
    partitioned into ``min(n_splits, n_domains)`` disjoint groups; in each fold
    the model trains on the other groups' domains and is tested on the held
    out ones, so train and test never share a domain. With five domains and
    five folds every fold holds out exactly one domain, whatever the seed.
    (The grouped rather than literal leave-one-out design, and the name, come
    from version 1, whose grouping column held malware family names.)"""
    from sklearn.model_selection import StratifiedGroupKFold
    n_fam = len(set(families.tolist()))
    k = max(2, min(n_splits, n_fam))
    sgkf = StratifiedGroupKFold(n_splits=k, shuffle=True, random_state=seed)
    for i, (tr, te) in enumerate(sgkf.split(np.zeros(len(y)), y, families)):
        yield Split("lomfo", f"famfold{i}", tr, te,
                    meta={"n_test_families": int(len(set(families[te].tolist())))})


def looo(techniques: np.ndarray) -> Iterator[Split]:
    """Leave one transformation out (open set); not used by any script in this
    repository, see the module docstring. ``test_idx`` covers the entire
    corpus; the held-out technique's rows are the novel (positive) class and all
    other rows are known (negative). ``train_idx`` excludes the held-out
    technique so the model never observes it during fitting."""
    for tech in sorted(set(techniques.tolist())):
        tr = np.where(techniques != tech)[0]
        te = np.arange(len(techniques))
        yield Split("looo", f"novel={tech}", tr, te, holdout_label=tech,
                    meta={"novel_technique": tech})


def iter_splits(protocol: str, *, groups=None, y=None, families=None,
                techniques=None, n_splits: int = 5, seed: int = 0,
                permute_groups: bool = False) -> List[Split]:
    """Materialise the splits of one protocol.

    ``permute_groups`` applies to ``grouped_cv`` only (see :func:`grouped_cv`);
    it is ignored by the other protocols.
    """
    if protocol == "grouped_cv":
        return list(grouped_cv(groups, y, n_splits=n_splits, seed=seed,
                               permute_groups=permute_groups))
    if protocol == "lomfo":
        return list(lomfo(families, y, n_splits=n_splits, seed=seed))
    if protocol == "looo":
        return list(looo(techniques))
    raise ValueError(f"unknown protocol '{protocol}'")
