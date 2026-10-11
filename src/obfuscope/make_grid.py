# VERSION 1 LEGACY: this file belongs to the version 1 pipeline and does not reproduce the article's tables (see Online Resource 1 (Section S1) of the article for the commands that do).
"""
Enumerate the experiment grid.

The Cartesian product of tasks, protocols, models, feature sets, and seeds
defines the full study. The same enumeration drives (a) the local resumable
runner and (b) the HTCondor/DAGMan job list, guaranteeing that the cluster and a
laptop execute *exactly* the same set of cells.
"""
from __future__ import annotations

import itertools
from dataclasses import dataclass
from typing import List

# NOTE: this module imports nothing that requires numpy/scikit-learn, so grid
# enumeration and manifest generation run on a bare access point.

SEEDS = [0, 1, 2]
FAST_MODELS = ["logreg", "random_forest", "extra_trees", "hist_gbdt", "knn", "mlp"]

# The study is the *union* of three purpose-built sub-grids. Expressing it this
# way keeps every cell scientifically motivated (no wasted compute) while still
# being a single reproducible enumeration shared by the laptop and the cluster.
SUBGRIDS = [
    # (A) Model x Protocol sweep at the full feature set: the headline tables.
    {"task": ["provenance"], "protocol": ["grouped_cv", "lomfo", "looo"],
     "model": FAST_MODELS, "feature_set": ["all"], "seed": SEEDS},
    # (B) Feature-family ablation with a strong, fast model on the two key
    #     protocols (closed-set provenance and open-set novelty).
    {"task": ["provenance"], "protocol": ["grouped_cv", "looo"],
     "model": ["random_forest"],
     "feature_set": ["lexical_only", "no_obfuscation", "structural", "semantic"],
     "seed": SEEDS},
    # (C) A single kernel-SVM reference point (O(n^2); one cell only).
    {"task": ["provenance"], "protocol": ["grouped_cv"], "model": ["svm_rbf"],
     "feature_set": ["all"], "seed": [0]},
    # (D) Fine-grained sub-transformation provenance, best model, closed-set.
    {"task": ["sub_provenance"], "protocol": ["grouped_cv"],
     "model": ["random_forest", "hist_gbdt"], "feature_set": ["all"], "seed": SEEDS},
]


@dataclass(frozen=True)
class Cell:
    task: str
    protocol: str
    model: str
    feature_set: str
    seed: int

    @property
    def cell_id(self) -> str:
        return (f"{self.task}__{self.protocol}__{self.model}__"
                f"{self.feature_set}__s{self.seed}")


def enumerate_cells(grid: dict | None = None) -> List[Cell]:
    keys = ["task", "protocol", "model", "feature_set", "seed"]
    grids = [grid] if grid else SUBGRIDS
    seen, cells = set(), []
    for g in grids:
        for vals in itertools.product(*(g[k] for k in keys)):
            c = Cell(*vals)
            if c.cell_id not in seen:
                seen.add(c.cell_id)
                cells.append(c)
    return cells


if __name__ == "__main__":
    for c in enumerate_cells():
        print(c.cell_id)
