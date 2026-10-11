"""Tests for scripts/verify_semantics.py: exit status comparison, compiler
flags, timeouts, and the machine independent regeneration seed stream.

Run with ``PYTHONPATH=src python -m pytest -q`` from the repository root.
Tests that compile C are skipped when no ``cc`` is on PATH.
"""
import json
import os
import shutil
import sys

import pytest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "src"))
sys.path.insert(0, os.path.join(ROOT, "scripts"))

import verify_semantics as vs  # noqa: E402

HAVE_CC = shutil.which("cc") is not None
needs_cc = pytest.mark.skipif(not HAVE_CC, reason="no C compiler on PATH")

# Generous: the machine running the suite may be heavily loaded.
TIMEOUT = 120

ORIGINAL = '#include <stdio.h>\nint main(void) { printf("hello 42\\n"); return 0; }\n'
SAME = ('#include <stdio.h>\nint main(void) { int x = 40 + 2; '
        'printf("hello %d\\n", x); return 0; }\n')
EXIT_ONLY = '#include <stdio.h>\nint main(void) { printf("hello 42\\n"); return 3; }\n'
STDOUT_ONLY = '#include <stdio.h>\nint main(void) { printf("hello 43\\n"); return 0; }\n'
BOTH = '#include <stdio.h>\nint main(void) { printf("bye\\n"); return 5; }\n'
BROKEN = 'int main(void) { return undeclared_symbol; }\n'


def _write(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w") as fh:
        fh.write(text)


def test_compile_flags_default_c99_O0():
    assert vs.compile_flags() == ["-std=c99", "-w", "-O0"]
    assert vs.compile_flags(opt="2") == ["-std=c99", "-w", "-O2"]
    assert vs.compile_flags(std="") == ["-w", "-O0"]


@needs_cc
def test_compile_and_run_captures_exit_status(tmp_path):
    src = tmp_path / "exit3.c"
    src.write_text(EXIT_ONLY)
    res = vs.compile_and_run(str(src), "cc", TIMEOUT)
    assert res["ok"] and res["stage"] is None
    assert res["stdout"] == "hello 42\n"
    assert res["exit_status"] == 3


def test_classify_reports_stdout_and_exit_status_separately():
    base = {"stdout": "a\n", "exit_status": 0}
    run = lambda out, rc: {"ok": True, "stage": None, "stdout": out,  # noqa: E731
                           "exit_status": rc, "error": ""}
    assert vs.classify(base, run("a\n", 0))[:2] == ("preserved", ["preserved"])
    o, c, r = vs.classify(base, run("a\n", 3))
    assert o == "failed" and set(c) == {"behaviour_differs", "exit_status_differs"}
    assert "exit status differs" in r
    o, c, r = vs.classify(base, run("b\n", 0))
    assert set(c) == {"behaviour_differs", "output_differs"}
    o, c, r = vs.classify(base, run("b\n", 3))
    assert set(c) == {"behaviour_differs", "output_differs",
                      "exit_status_differs", "output_and_exit_status_differ"}


def test_classify_timeouts():
    base = {"stdout": "a\n", "exit_status": 0}
    ct = {"ok": False, "stage": "compile_timeout", "stdout": "",
          "exit_status": None, "error": "compilation timed out"}
    rt = {"ok": False, "stage": "run_timeout", "stdout": "",
          "exit_status": None, "error": "execution timed out"}
    assert set(vs.classify(base, ct)[1]) == {"compile_failed", "compile_timeout"}
    assert vs.classify(base, rt)[1] == ["run_timeout"]


def test_compile_timeout_is_caught(tmp_path, monkeypatch):
    import subprocess

    def boom(*a, **k):
        raise subprocess.TimeoutExpired(cmd="cc", timeout=1)

    monkeypatch.setattr(vs.subprocess, "run", boom)
    src = tmp_path / "x.c"
    src.write_text(ORIGINAL)
    res = vs.compile_and_run(str(src), "cc", 1)
    assert res["ok"] is False and res["stage"] == "compile_timeout"


@needs_cc
def test_corpus_mode_detects_exit_status_mismatch(tmp_path):
    prog = tmp_path / "inputs" / "suite" / "prog.c"
    _write(str(prog), ORIGINAL)
    manifest = tmp_path / "inputs" / "programs.tsv"
    manifest.write_text("suite/prog.c\tsuite\tmain\n")

    adir = tmp_path / "corpus" / "reference_c" / "suite_prog" / "addopaque_variants"
    _write(str(adir / "ref_same_0.c"), SAME)
    _write(str(adir / "ref_exit_0.c"), EXIT_ONLY)
    _write(str(adir / "ref_stdout_0.c"), STDOUT_ONLY)
    _write(str(adir / "ref_both_0.c"), BOTH)
    _write(str(adir / "ref_broken_0.c"), BROKEN)

    progs = vs.read_programs(str(manifest))
    res = vs.run_corpus(str(tmp_path / "corpus"), progs, "cc", TIMEOUT)
    pp = res["per_parameterisation"]

    assert pp["ref_same"]["preserved"] == 1
    # Same stdout, different exit status: version 1 of this script counted it
    # as preserved.
    assert pp["ref_exit"]["preserved"] == 0
    assert pp["ref_exit"]["exit_status_differs"] == 1
    assert pp["ref_exit"]["output_differs"] == 0
    assert pp["ref_stdout"]["output_differs"] == 1
    assert pp["ref_stdout"]["exit_status_differs"] == 0
    assert pp["ref_both"]["output_and_exit_status_differ"] == 1
    assert pp["ref_broken"]["compile_failed"] == 1
    for r in pp.values():
        assert r["attempted"] == (r["preserved"] + r["compile_failed"]
                                  + r["run_timeout"] + r["transform_failed"]
                                  + r["behaviour_differs"])
    exit_fail = [f for f in res["failures"] if f["param"] == "ref_exit"][0]
    assert exit_fail["expected_exit_status"] == 0
    assert exit_fail["exit_status"] == 3
    assert res["mode"] == "corpus"
    assert res["compiler"]["flags"] == ["-std=c99", "-w", "-O0"]
    json.dumps(res)  # serialisable


def test_artifact_seed_matches_corpus_builder():
    import build_corpus_tigress as bct
    from reference_backend import REF_CATALOGUE

    t = REF_CATALOGUE[0]
    p = t.params[0]
    prog = bct.Program(path="/anywhere/at/all/quicksort.c", suite="dsalgo")
    for rep in (0, 7, 8, 9):
        cell = bct.Cell(prog, t, p, rep)
        assert vs.artifact_seed(prog.sample_id, t.name, p.label, rep) == cell.seed
    # The key does not involve the path, so the stream is machine independent.
    other = bct.Program(path="/elsewhere/quicksort.c", suite="dsalgo")
    assert bct.Cell(other, t, p, 8).seed == bct.Cell(prog, t, p, 8).seed


def test_regenerated_replicate_reproduces_released_artifact():
    """Replicate 0 regenerated with artifact_seed equals the pilot corpus file,
    so replicates 8 and 9 are the artifacts the builder would add next."""
    from reference_backend import REF_CATALOGUE, apply_transform

    progs = vs.read_programs(os.path.join(ROOT, "corpus_inputs", "programs.tsv"))
    path, suite = progs[0]
    sid = vs.sample_id_for(path, suite)
    t = REF_CATALOGUE[0]
    p = t.params[0]
    released = os.path.join(ROOT, "data", "pilot_corpus", "reference_c", sid,
                            t.technique_dir, f"{p.label}_0.c")
    if not os.path.isfile(released):
        pytest.skip("pilot corpus not present")
    with open(path) as fh:
        src = fh.read()
    seed = vs.artifact_seed(sid, t.name, p.label, 0)
    with open(released) as fh:
        assert apply_transform(src, t.name, dict(p.options), seed) == fh.read()
    # The released corpus holds replicates 0..7 only.
    d = os.path.dirname(released)
    reps = {int(f.rsplit("_", 1)[1][:-2]) for f in os.listdir(d)
            if f.endswith(".c")}
    assert max(reps) < vs.DEFAULT_FIRST_REPLICATE


@needs_cc
def test_regenerate_mode_fields_and_indices(tmp_path, monkeypatch):
    from reference_backend import REF_CATALOGUE, RefTransform

    t = REF_CATALOGUE[0]
    one = RefTransform(name=t.name, collberg=t.collberg, params=[t.params[0]])
    monkeypatch.setattr(vs, "REF_CATALOGUE", [one])

    prog = tmp_path / "suite" / "prog.c"
    _write(str(prog), '#include <stdio.h>\nint main(void) { int a = 7; '
                      'printf("%d\\n", a * 6); return 0; }\n')
    progs = [(str(prog), "suite")]
    res = vs.run(progs, 2, "cc", TIMEOUT)
    assert res["mode"] == "regenerate"
    assert res["replicates"] == 2
    assert res["replicate_indices"] == [8, 9]
    assert res["replicates_overlap_corpus"] is False
    rec = res["per_parameterisation"][t.params[0].label]
    assert rec["attempted"] == 2
    assert rec["preserved"] == 2
