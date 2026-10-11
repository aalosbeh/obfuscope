"""
Ground-truth labelling for the obfuscated C corpora.

Three generators share this labeller: the version 1 corpus (cohorts
``Testing_trojans_*``, whose sample directories are named after malware
samples), the Tigress source-to-source corpus (cohort ``tigress_c``) and the
reference backend used for the released pilot corpus (cohort ``reference_c``).
The Tigress and reference inputs are the synthetic benign C programs listed in
``corpus_inputs/programs.tsv``; the pilot corpus contains no malware.

Every ``.c`` artifact in the corpus is addressed by a path of the form::

    <cohort>/<sample_dir>/<technique_dir>/<sub_variant_file>.c

Three labels are derived from that path:

- ``technique``      : the coarse obfuscation-transformation family, taken from the
                       ``*_variants`` directory. This is the primary target for the
                       provenance task and the axis held out in the
                       Leave-One-Obfuscation-Out (open-set) protocol.
- ``sub_technique``  : the fine-grained transformation, taken from the file stem
                       (e.g. ``control_flow_flattened`` vs ``dead_code_inserted``).
                       The stem is stripped of a trailing integer, which is how the
                       replicate index is removed, so a sub-technique name must never
                       end in a digit.
- ``malware_family`` : a grouping string parsed from the sample directory name. The
                       column name is version 1 legacy. In the version 1 cohorts
                       this is a best-effort malware family name. In the Tigress and
                       reference cohorts the sample directory is ``<suite>_<program>``
                       (for example ``textproc_trim``), where the suite of
                       ``corpus_inputs/programs.tsv`` is the program domain, and the
                       parser cuts at the first underscore, so the column holds the
                       program domain (five domains on the pilot corpus). Used only as a grouping
                       variable (the program domain holdout, code name ``lomfo``),
                       never as a classification target.

The ``sample_id`` (the sample directory, i.e. the input program) is the unit
of grouping for all cross-validation so that no obfuscated sibling of a
training artifact can leak into the test fold.
"""
from __future__ import annotations

import os
import re
from dataclasses import dataclass
from typing import Optional

# Coarse transformation families of the original single-pipeline corpus.
LEGACY_TECHNIQUE_DIRS = [
    "advanced_variants",
    "code_based_variants",
    "api_obfuscated_variants",
    "vm_obfuscated_variants",
    "self_modifying_variants",
    "advanced_technique_variants",
    "cryptographic_variants",
    "advanced_microcode_variants",
    "advanced_code_variants",
    "rop_obfuscated_variants",
    "packer_obfuscated_variants",
]

# Coarse transformation families of the Tigress source-to-source corpus. These
# mirror ``scripts/tigress_spec.CATALOGUE``; the two lists are checked against
# each other by ``scripts/tigress_spec.py --verify-labels`` so a catalogue edit
# cannot leave artifacts unlabelled. An unrecognised directory is dropped
# silently by ``label_path``, which would show up as a short feature table
# rather than as an error, so the check matters.
TIGRESS_TECHNIQUE_DIRS = [
    "flatten_variants",
    "virtualize_variants",
    "encodearithmetic_variants",
    "encodeliterals_variants",
    "addopaque_variants",
    "split_variants",
]

# Coarse families of the reference backend in ``scripts/reference_backend.py``,
# the token level stand in used to exercise the generation and gating chain on a
# machine without Tigress installed. Two of these names coincide with Tigress
# transformation names, which is why the combined list below is deduplicated.
# Reference artifacts are written under the cohort ``reference_c`` rather than
# ``tigress_c``, so a feature table always records which generator produced each
# row and the two can never be pooled by accident.
REFERENCE_TECHNIQUE_DIRS = [
    "encodeliterals_variants",
    "encodestrings_variants",
    "addopaque_variants",
    "renameidentifiers_variants",
]


def _dedup(*groups: list) -> list:
    out: list = []
    for g in groups:
        for name in g:
            if name not in out:
                out.append(name)
    return out


TECHNIQUE_DIRS = _dedup(
    LEGACY_TECHNIQUE_DIRS, TIGRESS_TECHNIQUE_DIRS, REFERENCE_TECHNIQUE_DIRS
)

_MD5_PREFIX = re.compile(r"^[a-f0-9]{32}_")
_SHA256 = re.compile(r"[a-f0-9]{64}")
_EXT = re.compile(r"\.(exe|bat|vbs|js|ps1|com|py|msu|scr|dll|elf)\b.*", re.IGNORECASE)


@dataclass
class Labelled:
    path: str
    cohort: str
    sample_id: str
    technique: str
    sub_technique: str
    malware_family: str


def parse_family(sample_dir: str) -> str:
    """Grouping name from a sample directory name.

    For version 1 sample directories this is a best-effort malware family
    name; for ``<suite>_<program>`` directories (Tigress and reference
    cohorts) it is the suite, i.e. the program domain.
    """
    s = _MD5_PREFIX.sub("", sample_dir)
    s = _SHA256.sub("", s).strip("_")
    if not s:
        return "unknown_hash"
    s = _EXT.sub("", s)
    m = re.match(r"([A-Za-z][A-Za-z0-9\-\.]+)", s)
    fam = (m.group(1) if m else s)[:24]
    return fam or "unknown"


def technique_of(path: str) -> Optional[str]:
    """Return the coarse transformation family for a path, or ``None``."""
    parts = path.replace("\\", "/").split("/")
    hits = [p for p in parts if p.endswith("_variants")]
    return hits[-1] if hits else None


def sub_technique_of(path: str) -> str:
    """Fine-grained transformation from the file stem (normalised)."""
    stem = os.path.splitext(os.path.basename(path))[0]
    stem = re.sub(r"_real$", "", stem)
    stem = re.sub(r"\d+$", "", stem).strip("_")
    return stem or "unknown"


def label_path(path: str, corpus_root: str) -> Optional[Labelled]:
    """Produce a :class:`Labelled` record for one artifact path, or ``None`` if
    the path does not sit under a recognised transformation directory."""
    tech = technique_of(path)
    if tech is None or tech not in TECHNIQUE_DIRS:
        return None
    rel = os.path.relpath(path, corpus_root).replace("\\", "/")
    parts = rel.split("/")
    cohort = parts[0] if len(parts) > 1 else "root"
    # sample dir is the path component immediately above the technique dir
    try:
        ti = parts.index(tech)
        sample_dir = parts[ti - 1]
    except (ValueError, IndexError):
        sample_dir = parts[1] if len(parts) > 2 else "unknown"
    return Labelled(
        path=path,
        cohort=cohort,
        sample_id=sample_dir,
        technique=tech.replace("_variants", ""),
        sub_technique=sub_technique_of(path),
        malware_family=parse_family(sample_dir),
    )
