"""AUDIT-GENERATED (run:closedset-v3). Run batches of obfuscope.experiment cells, at most 4 at a time.

Every subprocess gets single threaded math libraries (OMP/OpenBLAS/vecLib/MKL = 1)
and LOKY_MAX_CPU_COUNT=1, so n_jobs=-1 in the tree ensembles resolves to one
thread; 4 workers therefore use at most 4 cores. Estimator results do not
depend on the thread count for these models (checked against the committed
cells by the ``repro`` batch).

Batches (run from the repository root, PYTHONPATH=src):
  repro   seed 0 cells re-run with default settings, compared to the committed grid
  pg      grouped_cv --permute-groups, technique task, 7 models x seeds 0-4
  noop    lomfo on the no-op-free table, random_forest/hist_gbdt x both tasks x seeds 0-4
  mlp2000 lomfo, mlp with max_iter=2000 (wrapper), both tasks x seeds 0-4
"""
from __future__ import annotations

import argparse
import os
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

MODELS = ["random_forest", "hist_gbdt", "extra_trees", "svm_rbf", "logreg", "mlp", "knn"]
SEEDS = [0, 1, 2, 3, 4]
HERE = os.path.dirname(os.path.abspath(__file__))
CLOSED = os.path.dirname(HERE)
DATA = "data/features_pilot.csv"
NOOP_DATA = os.path.join(CLOSED, "noop", "features_pilot_no_noop.csv")


def env() -> dict:
    e = dict(os.environ)
    e.update({"PYTHONPATH": os.path.abspath("src"), "LOKY_MAX_CPU_COUNT": "1",
              "OMP_NUM_THREADS": "1", "OPENBLAS_NUM_THREADS": "1",
              "VECLIB_MAXIMUM_THREADS": "1", "MKL_NUM_THREADS": "1",
              "PYTHONHASHSEED": "0"})
    return e


def cell(task, protocol, model, seed, out, data=DATA, extra=()):
    return [sys.executable, "-m", "obfuscope.experiment", "--data", data,
            "--task", task, "--protocol", protocol, "--model", model,
            "--feature-set", "all", "--seed", str(seed), "--n-splits", "5",
            *extra, "--out", out]


def jobs_for(batch: str):
    J = []
    if batch == "repro":
        d = os.path.join(CLOSED, "repro_check")
        for m in MODELS:
            J.append(cell("provenance", "grouped_cv", m, 0,
                          f"{d}/provenance_grouped_cv_{m}_all_s0.json"))
        for task in ("provenance", "sub_provenance"):
            for m in ("random_forest", "hist_gbdt", "mlp"):
                J.append(cell(task, "lomfo", m, 0, f"{d}/{task}_lomfo_{m}_all_s0.json"))
    elif batch == "pg":
        d = os.path.join(CLOSED, "pg")
        for s in SEEDS:
            for m in MODELS:
                J.append(cell("provenance", "grouped_cv", m, s,
                              f"{d}/provenance_grouped_cv_{m}_all_s{s}.json",
                              extra=("--permute-groups",)))
    elif batch == "noop":
        d = os.path.join(CLOSED, "noop", "cells")
        for task in ("provenance", "sub_provenance"):
            for m in ("random_forest", "hist_gbdt"):
                for s in SEEDS:
                    J.append(cell(task, "lomfo", m, s,
                                  f"{d}/{task}_lomfo_{m}_all_s{s}.json", data=NOOP_DATA))
    elif batch == "mlp2000":
        d = os.path.join(CLOSED, "mlp2000")
        for task in ("sub_provenance", "provenance"):
            for s in SEEDS:
                J.append([sys.executable, os.path.join(HERE, "mlp_maxiter_wrapper.py"),
                          "--data", DATA, "--task", task, "--protocol", "lomfo",
                          "--seed", str(s), "--max-iter", "2000",
                          "--out", f"{d}/{task}_lomfo_mlp_maxiter2000_all_s{s}.json"])
    else:
        raise SystemExit(f"unknown batch {batch}")
    return J


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("batches", nargs="+")
    ap.add_argument("--workers", type=int, default=4)
    a = ap.parse_args()
    assert a.workers <= 4
    J = [j for b in a.batches for j in jobs_for(b)]
    log_dir = os.path.join(CLOSED, "logs")
    os.makedirs(log_dir, exist_ok=True)
    e = env()

    def run(cmd):
        out = cmd[cmd.index("--out") + 1]
        os.makedirs(os.path.dirname(out), exist_ok=True)
        t0 = time.time()
        p = subprocess.run(cmd, env=e, capture_output=True, text=True)
        return out, p.returncode, round(time.time() - t0, 1), p.stdout.strip(), p.stderr

    t0 = time.time()
    with ThreadPoolExecutor(max_workers=a.workers) as ex, \
            open(os.path.join(log_dir, "_".join(a.batches) + ".log"), "w") as log:
        for out, rc, dt, so, se in ex.map(run, J):
            line = f"rc={rc} {dt}s {os.path.relpath(out, CLOSED)} :: {so}"
            print(line, flush=True)
            log.write(line + "\n")
            if rc != 0:
                log.write(se + "\n")
                print(se, file=sys.stderr)
            elif se.strip():
                # keep warnings (e.g. ConvergenceWarning) for the record
                warn = [l for l in se.splitlines() if "Warning" in l]
                if warn:
                    log.write(f"   stderr warnings: {len(warn)} e.g. {warn[0][:200]}\n")
        log.write(f"total {round(time.time() - t0, 1)}s, {len(J)} jobs\n")
    print(f"total {round(time.time() - t0, 1)}s, {len(J)} jobs")


if __name__ == "__main__":
    main()
