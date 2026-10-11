#!/usr/bin/env python3
"""
Batch driver for the decompilation-only stage: walk a directory of raw
samples and produce ``output_reports/<sample>/<sample>.c`` +
``<sample>_analysis.json`` for each one, dispatching to Ghidra headless
(native binaries, via run_headless.sh) or the text-embedding stub
(script_stub.py, for .ps1/.vbs/.bat/.js/.py).

This is the decompilation-only stage; it produces no ``*_variants/``
subfolders and is not by itself a corpus ``obfuscope.build_dataset`` can
consume -- see README.md for what's still missing (the obfuscation-variant
generation stage).
"""
from __future__ import annotations

import argparse
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from script_stub import build_stub  # noqa: E402

SCRIPT_EXTS = {".ps1", ".vbs", ".bat", ".js", ".py"}
_DEFAULT_HEADLESS = os.path.join(os.path.dirname(os.path.abspath(__file__)), "run_headless.sh")


def _is_script(path: str) -> bool:
    return os.path.splitext(path)[1].lower() in SCRIPT_EXTS


def process_one(path: str, out_root: str, run_headless: str) -> None:
    sample_name = os.path.basename(path)
    out_dir = os.path.join(out_root, sample_name)
    if _is_script(path):
        build_stub(path, out_dir)
    else:
        subprocess.run([run_headless, path, out_dir], check=True)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--input-dir", required=True, help="directory of raw samples")
    ap.add_argument("--out", default="output_reports", help="output_reports root")
    ap.add_argument("--run-headless", default=_DEFAULT_HEADLESS,
                    help="path to run_headless.sh (native-binary path only)")
    ap.add_argument("--limit", type=int, default=0, help="cap number of samples (0 = all)")
    args = ap.parse_args(argv)

    samples = sorted(
        os.path.join(args.input_dir, f) for f in os.listdir(args.input_dir)
        if os.path.isfile(os.path.join(args.input_dir, f)) and not f.startswith(".")
    )
    if args.limit:
        samples = samples[:args.limit]

    ok = fail = 0
    for path in samples:
        try:
            process_one(path, args.out, args.run_headless)
            ok += 1
        except Exception as exc:  # noqa: BLE001
            print(f"[decompile_batch] FAILED {path}: {exc}", file=sys.stderr)
            fail += 1
    print(f"[decompile_batch] done: {ok} ok, {fail} failed, out={args.out}")


if __name__ == "__main__":
    main()
