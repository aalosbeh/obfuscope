"""Tests for scripts/audit_noop_artifacts.py.

Run with ``PYTHONPATH=src python -m pytest -q`` from the repository root.
"""
import json
import os
import sys

import pytest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "scripts"))

import audit_noop_artifacts as noop  # noqa: E402

ORIGINAL = "int main(void)\n{\n    return 0;\n}\n"
WS_ONLY = "int main(void) {\n\treturn 0;   }\n\n"
CHANGED = "int main(void)\n{\n    int v0 = 0;\n    return v0;\n}\n"


def _write(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w") as fh:
        fh.write(text)


def _build(tmp_path):
    _write(str(tmp_path / "in" / "s" / "a.c"), ORIGINAL)
    _write(str(tmp_path / "in" / "s" / "b.c"), CHANGED)
    (tmp_path / "in" / "programs.tsv").write_text("s/a.c\ts\tmain\ns/b.c\ts\tmain\n")
    ren = tmp_path / "corpus" / "reference_c" / "s_a" / "renameidentifiers_variants"
    _write(str(ren / "ref_ren_hex_0.c"), ORIGINAL)      # byte identical
    _write(str(ren / "ref_ren_hex_1.c"), WS_ONLY)       # whitespace only
    _write(str(ren / "ref_ren_long_0.c"), CHANGED)      # really changed
    lit = tmp_path / "corpus" / "reference_c" / "s_b" / "encodeliterals_variants"
    _write(str(lit / "ref_lit_xor_0.c"), CHANGED)       # identical to s/b.c
    _write(str(lit / "ref_lit_xor_1.c"), ORIGINAL)      # differs from s/b.c
    # Not under a *_variants directory: ignored.
    _write(str(tmp_path / "corpus" / "reference_c" / "s_a" / "stray.c"), ORIGINAL)


def test_counts_per_parameterisation_and_program(tmp_path):
    _build(tmp_path)
    progs = noop.read_programs(str(tmp_path / "in" / "programs.tsv"))
    res = noop.audit(str(tmp_path / "corpus"), progs)

    assert res["artifacts_found"] == 5
    assert res["artifacts_unmatched"] == 0
    assert res["totals"]["byte_identical"] == 2
    assert res["totals"]["whitespace_identical"] == 3
    assert res["totals"]["whitespace_only_difference"] == 1

    pp = res["per_parameterisation"]
    assert pp["ref_ren_hex"] == {"artifacts": 2, "byte_identical": 1,
                                 "whitespace_identical": 2,
                                 "whitespace_only_difference": 1}
    assert pp["ref_ren_long"]["whitespace_identical"] == 0
    assert pp["ref_lit_xor"]["byte_identical"] == 1

    assert res["per_program"]["s_a"]["whitespace_identical"] == 2
    assert res["per_program"]["s_b"]["byte_identical"] == 1
    cells = {(c["sample_id"], c["param"]): c
             for c in res["per_program_parameterisation"]}
    assert set(cells) == {("s_a", "ref_ren_hex"), ("s_b", "ref_lit_xor")}

    listed = {a["artifact"]: a for a in res["artifacts"]}
    assert listed["reference_c/s_a/renameidentifiers_variants/ref_ren_hex_1.c"][
        "byte_identical"] is False
    assert listed["reference_c/s_a/renameidentifiers_variants/ref_ren_hex_0.c"][
        "replicate"] == 0
    json.dumps(res)


def test_cli_writes_json(tmp_path):
    _build(tmp_path)
    out = tmp_path / "r.json"
    code = noop.main(["--corpus", str(tmp_path / "corpus"),
                      "--programs", str(tmp_path / "in" / "programs.tsv"),
                      "--report", str(out)])
    assert code == 0
    assert json.loads(out.read_text())["totals"]["byte_identical"] == 2


def test_pilot_corpus_known_noops():
    corpus = os.path.join(ROOT, "data", "pilot_corpus")
    manifest = os.path.join(ROOT, "corpus_inputs", "programs.tsv")
    if not os.path.isdir(corpus):
        pytest.skip("pilot corpus not present")
    res = noop.audit(corpus, noop.read_programs(manifest))
    # 2 programs x 2 renaming parameterisations x 8 replicates.
    assert res["artifacts_checked"] == 2400
    assert res["totals"]["byte_identical"] == 32
    assert res["totals"]["whitespace_identical"] == 32
    assert {c["param"] for c in res["per_program_parameterisation"]} == \
        {"ref_ren_hex", "ref_ren_long"}
