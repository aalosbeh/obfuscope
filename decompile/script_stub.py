#!/usr/bin/env python3
"""
Lightweight, execution-free stand-in for Ghidra decompilation on script-type
samples (.ps1, .vbs, .bat, .js, .py, ...) that Ghidra cannot decompile as
native binaries.

Produces the same two-file shape as ghidra_scripts/ExportDecompiled.py
(<sample>.c + <sample>_analysis.json) so both paths feed the same downstream
layout, but this never executes or interprets the script: the original text
is embedded verbatim as an opaque C string literal and only static text
statistics are computed over it.
"""
from __future__ import annotations

import argparse
import json
import os
import re
import time
from typing import Tuple

_STRING_ISH = re.compile(r'"([^"\n]{4,120})"|\'([^\'\n]{4,120})\'')


def _c_escape(text: str) -> str:
    return (text.replace("\\", "\\\\").replace('"', '\\"')
                .replace("\r", "\\r").replace("\n", "\\n"))


def build_stub(sample_path: str, out_dir: str) -> Tuple[str, str]:
    """Write ``<out_dir>/<sample>.c`` and ``..._analysis.json``; return their paths."""
    sample_name = os.path.basename(sample_path)
    with open(sample_path, "r", encoding="utf-8", errors="ignore") as fh:
        text = fh.read()

    os.makedirs(out_dir, exist_ok=True)

    escaped = _c_escape(text)
    c_source = (
        f"/* OBFUSCOPE SCRIPT STUB -- static text embedding for {sample_name}.\n"
        f" * Not decompiled (script, not a native binary); the source below is\n"
        f" * the original text as an opaque string literal, never executed\n"
        f" * or interpreted. See decompile/README.md for scope. */\n\n"
        f"static const char *ORIGINAL_SOURCE =\n    \"{escaped}\";\n"
    )
    c_path = os.path.join(out_dir, sample_name + ".c")
    with open(c_path, "w") as fh:
        fh.write(c_source)

    literals = [a or b for a, b in _STRING_ISH.findall(text)][:500]
    analysis = {
        "sample": sample_name,
        "generated_by": "obfuscope/decompile script_stub.py (text embedding, no execution)",
        "generated_at": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        "n_lines": text.count("\n") + 1,
        "size_bytes": os.path.getsize(sample_path),
        "extracted_strings": literals,
        "decompiled_code_path": c_path,
    }
    json_path = os.path.join(out_dir, sample_name + "_analysis.json")
    with open(json_path, "w") as fh:
        json.dump(analysis, fh, indent=2)
    return c_path, json_path


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("input", help="path to the script-type sample")
    ap.add_argument("out_dir", help="directory to write <sample>.c / _analysis.json into")
    args = ap.parse_args(argv)
    c_path, json_path = build_stub(args.input, args.out_dir)
    print(f"[script_stub] wrote {c_path} and {json_path}")


if __name__ == "__main__":
    main()
