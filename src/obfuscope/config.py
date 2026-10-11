"""
Light, dependency-free configuration shared across the package.

This module deliberately imports nothing heavier than :mod:`obfuscope.features`
(itself standard-library only), so that grid enumeration and manifest generation
run on a bare HTCondor access point that has no numpy/scikit-learn installed.
The scientific stack is only needed inside the execution-point container, not to
build the list of jobs.
"""
from __future__ import annotations

from typing import Dict, List

from .features import FEATURE_FAMILIES

# Named feature-set presets for the ablation axis.
#
# Two of the original names were wrong in a way that mattered, and both are kept
# as deprecated aliases so published numbers stay reproducible under the names
# they were reported with.
#
# "structural" contained the whole lexical family plus entropy, so it was not
#   structural in any useful sense: identifier shape and comment density are
#   surface properties of the text, not structure, and a reader comparing
#   "structural" against "lexical_only" was told the two were disjoint when the
#   second is a subset of the first. The honest name is "surface_and_control".
#
# "semantic" contained the obfuscation marker family, which is a set of hand
#   written detectors for specific constructs. Those are pattern matches, not
#   semantics, and including them meant the set could not be read as evidence
#   about semantic features. The honest name is "markers_and_literals".
#
# A genuinely structural set, holding only control flow and operator mix with no
# surface or marker features, is added under "control_only" so the comparison
# the original name implied can actually be made.
FEATURE_SETS: Dict[str, List[str]] = {
    "all": list(FEATURE_FAMILIES.keys()),
    "lexical_only": ["lexical"],
    "no_obfuscation": [k for k in FEATURE_FAMILIES if k != "obfuscation"],
    "surface_and_control": ["lexical", "control_flow", "operator", "entropy"],
    "markers_and_literals": ["api", "obfuscation", "literal"],
    "control_only": ["control_flow", "operator"],
    "behavioral_only": ["control_flow", "literal", "operator", "api"],
    # Deprecated aliases. Identical membership to the renamed sets above, so a
    # command line from the first version of this work still runs and still
    # produces the same numbers.
    "structural": ["lexical", "control_flow", "operator", "entropy"],
    "semantic": ["api", "obfuscation", "literal"],
}

# Sets whose names misdescribe their contents. Reading one emits a warning so
# the mistake cannot propagate silently into a new result table.
DEPRECATED_FEATURE_SETS: Dict[str, str] = {
    "structural": "surface_and_control",
    "semantic": "markers_and_literals",
}

# Mapping from task name to the dataframe column holding its target label.
TASK_LABEL: Dict[str, str] = {
    "provenance": "technique",
    "sub_provenance": "sub_technique",
}

# Canonical classifier names. Kept here (rather than derived from the sklearn
# registry) so it is importable without sklearn; models.py asserts consistency.
MODEL_NAMES: List[str] = [
    "extra_trees", "hist_gbdt", "knn", "logreg", "mlp", "random_forest", "svm_rbf",
]
