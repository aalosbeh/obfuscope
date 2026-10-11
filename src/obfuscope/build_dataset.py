"""
Corpus -> feature table builder.

Walks an extracted corpus directory, extracts static features from every ``.c``
artifact, attaches the three ground-truth labels, and writes a single tabular
dataset (CSV, and Parquet when ``pandas``/``pyarrow`` are available).

Usage
-----
    python -m obfuscope.build_dataset --corpus /path/to/extracted \
        --out data/features.csv [--jobs 4]

The builder streams rows to disk so that it scales to hundreds of thousands of
artifacts on a single HTC execution point without exhausting memory.

Row order
---------
Rows are written in the order in which ``os.walk`` enumerates the corpus,
whatever the value of ``--jobs``. With ``--jobs > 1`` the workers' results are
collected with the order-preserving ``Pool.imap``, so a parallel build is
byte-identical to a serial one. (An earlier version used ``imap_unordered``,
which wrote rows in completion order; because the tree ensembles and the
multilayer perceptron are sensitive to row order, a parallel rebuild could not
reproduce the committed feature tables or the results computed from them.)

``os.walk`` order is a property of the filesystem, not of this code. The row
order of the committed ``data/features_pilot.csv`` equals the ``os.walk`` order
of ``data/pilot_corpus`` on an APFS (macOS) checkout, where ``--jobs 1`` and
``--jobs 8`` both rebuild it byte for byte; a different filesystem may
enumerate the same files in a different order. The committed CSV, with its
checksum in ``results/v3/checksums.txt``, is therefore the reference table, and
a rebuild should be compared against that checksum rather than assumed
identical.
"""
from __future__ import annotations

import argparse
import csv
import os
import sys
import time
import zlib
from functools import partial
from multiprocessing import Pool
from typing import Iterator, List, Optional

from .features import extract_from_file, feature_names
from .labels import label_path

_LABEL_COLS = ["path", "cohort", "sample_id", "technique", "sub_technique", "malware_family"]


def iter_c_files(root: str) -> Iterator[str]:
    for dp, _dn, fn in os.walk(root):
        for f in fn:
            if f.endswith(".c"):
                yield os.path.join(dp, f)


def _in_shard(rel_path: str, shard_index: int, num_shards: int) -> bool:
    """Deterministic, order-independent assignment of an artifact to a shard.

    Uses CRC32 over the relative path so that the same file always lands on the
    same shard regardless of filesystem walk order. This is the identical
    partitioning used by the HTC feature-extraction stage, where each execution
    point builds exactly one shard.
    """
    if num_shards <= 1:
        return True
    return (zlib.crc32(rel_path.encode("utf-8")) % num_shards) == shard_index


def _process_one(path: str, corpus: str, names: List[str]) -> Optional[List]:
    lab = label_path(path, corpus)
    if lab is None:
        return None
    try:
        feats = extract_from_file(path)
    except Exception:  # noqa: BLE001
        return None
    return [
        os.path.relpath(path, corpus), lab.cohort, lab.sample_id,
        lab.technique, lab.sub_technique, lab.malware_family,
    ] + [feats.get(k, 0.0) for k in names]


def build(corpus: str, out_csv: str, limit: int = 0, verbose: bool = True,
          jobs: int = 1, shard_index: int = 0, num_shards: int = 1,
          write_header: bool = True) -> int:
    """Extract features for every (in-shard) artifact and write a CSV.

    Parameters
    ----------
    jobs        : number of worker processes for feature extraction.
    shard_index : this shard's index in ``[0, num_shards)``.
    num_shards  : total shards; only artifacts assigned to ``shard_index`` are
                  processed. With ``num_shards == 1`` the whole corpus is built.
    write_header: emit the CSV header row (set ``False`` when concatenating shards).
    """
    names = feature_names()
    header = _LABEL_COLS + names
    t0 = time.time()
    os.makedirs(os.path.dirname(os.path.abspath(out_csv)) or ".", exist_ok=True)

    paths = [p for p in iter_c_files(corpus)
             if _in_shard(os.path.relpath(p, corpus), shard_index, num_shards)]
    if limit:
        paths = paths[:limit]

    worker = partial(_process_one, corpus=corpus, names=names)
    n = 0
    with open(out_csv, "w", newline="", encoding="utf-8") as fh:
        writer = csv.writer(fh)
        if write_header:
            writer.writerow(header)
        if jobs > 1:
            with Pool(processes=jobs) as pool:
                # imap, not imap_unordered: results come back in the order of
                # ``paths``, so the output is identical for every --jobs value.
                for row in pool.imap(worker, paths, chunksize=16):
                    if row is not None:
                        writer.writerow(row)
                        n += 1
        else:
            for p in paths:
                row = worker(p)
                if row is not None:
                    writer.writerow(row)
                    n += 1
    if verbose:
        rate = n / max(1e-9, time.time() - t0)
        tag = f"shard {shard_index}/{num_shards} " if num_shards > 1 else ""
        print(f"[done] {tag}{n} artifacts -> {out_csv} in {time.time() - t0:.1f}s "
              f"({rate:.0f}/s)", file=sys.stderr)
    return n


def to_parquet(csv_path: str) -> Optional[str]:
    """Write a Parquet mirror of a features CSV; return its path or ``None``."""
    try:
        import pandas as pd  # noqa: WPS433
        df = pd.read_csv(csv_path)
        pq = os.path.splitext(csv_path)[0] + ".parquet"
        df.to_parquet(pq, index=False)
        return pq
    except Exception:  # noqa: BLE001
        return None


def main(argv=None):
    ap = argparse.ArgumentParser(description="Build the ObfuScope feature table.")
    ap.add_argument("--corpus", required=True, help="root of the extracted corpus")
    ap.add_argument("--out", default="data/features.csv", help="output CSV path")
    ap.add_argument("--limit", type=int, default=0, help="cap artifacts (0 = all)")
    ap.add_argument("--jobs", type=int, default=1, help="worker processes")
    ap.add_argument("--shard-index", type=int, default=0)
    ap.add_argument("--num-shards", type=int, default=1)
    ap.add_argument("--no-header", action="store_true", help="omit CSV header")
    ap.add_argument("--parquet", action="store_true", help="also write Parquet mirror")
    ap.add_argument("--quiet", action="store_true")
    args = ap.parse_args(argv)
    build(args.corpus, args.out, limit=args.limit, verbose=not args.quiet,
          jobs=args.jobs, shard_index=args.shard_index, num_shards=args.num_shards,
          write_header=not args.no_header)
    if args.parquet:
        to_parquet(args.out)


if __name__ == "__main__":
    main()
