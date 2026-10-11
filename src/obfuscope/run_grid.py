# VERSION 1 LEGACY: this file belongs to the version 1 pipeline and does not reproduce the article's tables (see Online Resource 1 (Section S1) of the article for the commands that do).
"""
Resumable local grid runner.

Runs every experiment cell that does not yet have a result JSON, each in an
isolated subprocess with a per-cell timeout. An overall wall budget lets the
runner exit cleanly before an external time limit; re-invoking it resumes where
it left off. This mirrors, on one machine, what DAGMan does across the OSPool:
independent, retry-safe cells with durable per-cell outputs.
"""
from __future__ import annotations

import argparse
import os
import subprocess
import sys
import time

from .make_grid import enumerate_cells


def main(argv=None):
    ap = argparse.ArgumentParser(description="Resumable ObfuScope grid runner.")
    ap.add_argument("--data", required=True)
    ap.add_argument("--out-dir", default="results/cells")
    ap.add_argument("--wall", type=float, default=40.0, help="stop after N seconds")
    ap.add_argument("--cell-timeout", type=float, default=35.0)
    ap.add_argument("--n-splits", type=int, default=5)
    ap.add_argument("--retry-failed", action="store_true",
                    help="ignore .fail markers and re-attempt failed cells")
    args = ap.parse_args(argv)

    os.makedirs(args.out_dir, exist_ok=True)
    cells = enumerate_cells()
    t0 = time.time()
    done = ran = failed = 0
    for c in cells:
        out = os.path.join(args.out_dir, c.cell_id + ".json")
        fail_marker = out + ".fail"
        if os.path.exists(out) and os.path.getsize(out) > 0:
            done += 1
            continue
        if os.path.exists(fail_marker) and not args.retry_failed:
            continue
        if time.time() - t0 > args.wall:
            break
        cmd = [sys.executable, "-m", "obfuscope.experiment", "--data", args.data,
               "--task", c.task, "--protocol", c.protocol, "--model", c.model,
               "--feature-set", c.feature_set, "--seed", str(c.seed),
               "--n-splits", str(args.n_splits), "--out", out]
        try:
            subprocess.run(cmd, timeout=args.cell_timeout, check=True,
                           capture_output=True, text=True)
            ran += 1
            print(f"[ok] {c.cell_id}")
        except subprocess.TimeoutExpired:
            failed += 1
            open(fail_marker, "w").write("timeout")
            print(f"[timeout] {c.cell_id}", file=sys.stderr)
        except subprocess.CalledProcessError as exc:
            failed += 1
            open(fail_marker, "w").write((exc.stderr or "")[-500:])
            print(f"[error] {c.cell_id}: {exc.stderr[-300:]}", file=sys.stderr)
    remaining = sum(
        1 for c in cells
        if not os.path.exists(os.path.join(args.out_dir, c.cell_id + ".json")))
    print(f"[grid] total={len(cells)} already_done={done} ran_now={ran} "
          f"failed={failed} remaining={remaining} elapsed={time.time()-t0:.0f}s")


if __name__ == "__main__":
    main()
