# Running ObfuScope on the CHTC and the OSPool

This guide takes you from a fresh access-point login to a completed, aggregated
run of the full experiment grid. It assumes an OSPool access point (e.g.
`ap40.uw.osg-htc.org`) or a CHTC submit node; the commands are identical apart
from the OSDF namespace prefix.

The workflow is deliberately structured as a DAG of four stages so that it maps
cleanly onto High-Throughput Computing: many small, independent, retry-safe jobs
rather than one long monolithic job.

```
FEATURES (N shards) ─▶ MERGE ─▶ GRID (thousands of cells) ─▶ AGGREGATE
```

## 0. One-time setup

```bash
# On the access point
git clone <your-fork>/obfuscope.git
cd obfuscope

# Package the source so every job can carry it (a few hundred KB).
bash htc/package_src.sh
# (equivalent to: tar czf htc/obfuscope_src.tar.gz src)
# condor_submit_dag also runs this automatically as the FEATURES PRE script,
# so it is only needed here for submitting an individual stage by hand.

# Identify your OSDF data namespace. On the OSPool this is typically:
export OSDF_USER_NS=/ospool/ap40/data/$USER
```

## 1. Build and stage the container

Every job runs inside a pinned Apptainer image so the software stack is identical
across thousands of heterogeneous execution points.

```bash
cd htc
bash build_container.sh          # builds obfuscope.sif and copies it to the OSDF
# Verify it published:
ls -lh $OSDF_USER_NS/obfuscope.sif
```

The submit files reference the image as
`container_image = osdf:///ospool/ap40/data/$(User)/obfuscope.sif`.

## 2. Stage the corpus on the OSDF

The obfuscated-malware corpus is large and read by every feature-extraction
shard, so it is served from the OSDF cache rather than the access point.

```bash
bash htc/stage_corpus.sh /path/to/extracted_corpus
# equivalent to:
#   tar czf corpus.tar.gz -C /path/to/extracted_corpus .
#   mkdir -p $OSDF_USER_NS/obfuscope
#   cp corpus.tar.gz $OSDF_USER_NS/obfuscope/corpus.tar.gz
```

> Safety note: the corpus is derived from live malware. Keep it inside your
> project's OSDF namespace, never on shared scratch, and follow your
> institution's handling policy. The feature extractor performs **no code
> execution** — it computes text statistics only — but the raw artifacts remain
> sensitive.

## 3. Feature extraction (FEATURES stage)

```bash
mkdir -p logs data/shards
condor_submit features.sub num_shards=64
# 64 shards, each ~1–2 CPU-minutes. Watch progress:
condor_q
condor_watch_q
```

Each shard writes `data/shards/features_shard_<k>.csv`. The partition is
`CRC32(path) % num_shards`, so shards are disjoint and order-independent.

## 4. Merge (MERGE stage)

```bash
condor_submit merge.sub          # concatenates shards -> data/features.csv
```

## 5. Experiment grid (GRID stage)

Generate the manifest and submit the grid. Use `--full` for the paper-scale run.

```bash
python3 make_manifest.py --full --seeds 10 --out grid.txt   # ~2,100 cells
condor_submit experiment.sub
```

Each cell is one `(task, protocol, model, feature_set, seed)` combination, runs
in a few CPU-minutes, and returns exactly one JSON to
`results/cells/`. Cells are idempotent: `max_retries = 5` lets HTCondor transparently
re-run any preempted cell.

## 6. Aggregate (AGGREGATE stage)

```bash
tar czf results/cells.tar.gz -C results cells
condor_submit aggregate.sub
tar xzf outputs.tar.gz          # -> results/tables/, results/summary.json, figures/
```

## Or: run the whole thing with one command

```bash
condor_submit_dag obfuscope.dag
```

DAGMan submits each stage when its parents finish, retries failed stages, and
throttles idle jobs per `dagman.config`.

## Doing it all on a laptop first (recommended)

The identical pipeline runs locally, which is how the numbers in the paper were
produced during development:

```bash
pip install -r requirements.txt
python3 -m obfuscope.build_dataset --corpus extracted_corpus --out data/features.csv --jobs 4
python3 -m obfuscope.run_grid      --data data/features.csv --out-dir results/cells --wall 1e9
python3 -m obfuscope.aggregate     --cells results/cells --out results
python3 -m obfuscope.plots         --cells results/cells --summary results/summary.json --out paper/figures
```

Because `run_grid` and `make_manifest` share `enumerate_cells`, the laptop and
the OSPool execute exactly the same set of cells.

## Sizing guidance

| Quantity | Curated grid | Full paper grid |
|---|---|---|
| Experiment cells | 85 | ~2,100 |
| Feature shards | 16–64 | 64–256 |
| Wall-clock (OSPool, well-provisioned) | minutes | tens of minutes |
| Core-hours | ~1 | ~40–80 |

Scaling the seed count and re-enabling every `model × feature_set × protocol`
combination is the intended way to grow the grid: the cost is linear in the
number of cells and each cell remains a short, independent job — the regime HTC
is built for.

## Troubleshooting

- **Jobs idle for a long time**: check `condor_q -better-analyze <id>`; usually the
  container image has not finished staging to the OSDF, or the `requirements`
  expression is too strict for currently-available capacity.
- **`container_image` not found**: confirm the `.sif` is readable at
  `$OSDF_USER_NS/obfuscope.sif` and that the submit file's `$(User)` expands to
  your username.
- **A cell fails deterministically**: run it locally with the same arguments via
  `python3 -m obfuscope.experiment ...` to see the traceback.
