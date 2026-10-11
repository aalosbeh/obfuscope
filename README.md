# ObfuScope

ObfuScope studies obfuscation provenance attribution on source text: given an
obfuscated C program, which transformation family and which parameterisation
produced it, and was that transformation absent from training. The repository
contains a corpus generator with one in-house backend, a static feature
extractor (61 feature columns), a corpus validity gate (a standalone check run on
a feature table before results are interpreted), closed-set and open-set
evaluation protocols, a mixture simulation, and the scripts that build every
table and figure of the article and its supplement from the result files. This
is the corrected release that accompanies the revised manuscript.

## What is measured, and what is not

Measured:

- One backend (`scripts/reference_backend.py`): 4 transformation families,
  10 parameterisations.
- 30 synthetic benign input programs in 5 domains, 9 to 32 lines each
  (535 lines in total), in `corpus_inputs/`; 2400 artifacts in
  `data/pilot_corpus/reference_c/`; feature table `data/features_pilot.csv`.
- Source text only. Features are computed statically from the C source.

Not measured:

- No second obfuscator. The Tigress cohort is specified
  (`scripts/tigress_spec.py` prints its catalogue) and was not run, so no result
  is a cross-tool result.
- No real-world code and no programs longer than 32 lines.
- No binaries. `decompile/` is present but not exercised.

## Headline numbers

Copied from the ledger that `scripts/manuscript_v3/make_ledger.py` builds; if this
list and the ledger disagree, the ledger is right. Open-set protocols:
**program-matched** (primary; known-evaluation and novel artifacts come from the
same input programs, none of which is used for fitting), **program-overlapping**
(the released protocol; novel artifacts come from all 30 programs) and
**program k-fold** (robustness check). Configurations: A (family label, a family
held out), B (parameterisation label, one parameterisation held out while its
siblings stay in training), C (parameterisation label, a whole family held out).
AUROC values are means over folds and seeds.

| Quantity | Protocol | Value |
| --- | --- | --- |
| Semantic preservation, stdout and exit status, `cc -std=c99 -O0` | released corpus / regenerated replicates 8 and 9 | 2400/2400; 600/600 |
| No-op artifacts (renamed copies byte-identical to their input) | corpus audit | 32 (1.33%), 2 programs |
| Gate, family label: headroom R (threshold 0.50) | self-contained / supplied headline F1 / consistent protocol | 0.4327 / 0.4486 / 0.4262 |
| Gate failures, family / parameterisation label | self-contained | 2 (diagnostic 4) / 2 (diagnostics 4 and 6) |
| Gate failures, parameterisation label, no-op-free table | self-contained | 1 (diagnostic 4; diagnostic 6 passes) |
| Gate on 21 tables with fixed verdicts: sensitivity, specificity | policy (i), all failures disqualify | 12/12, 8/9 |
| Same | policy (ii), diagnostic 4 advisory | 9/12, 9/9 |
| Gate on the template-generated table | self-contained | 26 failures; `n_lines` alone: macro F1 0.9102 |
| Closed set, family label, macro F1 (fold sd) | domain holdout | random_forest 0.9542 (0.0356), hist_gbdt 0.9480 (0.0339) |
| Closed set, parameterisation label | domain holdout | random_forest 0.8045 (0.0731), hist_gbdt 0.8124 (0.0816) |
| Closed set, effect of removing the 32 no-op artifacts | domain holdout | at most 0.0120 |
| Open set B, MSP AUROC, six estimators | program-matched | 0.3831 (knn) to 0.4849 (svm_rbf); random_forest 0.4482 |
| Open set B, random_forest MSP FPR95 (known-positive convention) | program-matched | 0.9446 |
| Open set C, random_forest MSP AUROC | program-matched | 0.9073 |
| B minus C, random_forest MSP, crossed bootstrap 95% CI | program-matched | -0.4591 [-0.5722, -0.3455] |
| B minus C, logreg MSP | program-matched | -0.0553 [-0.2635, 0.1479] |
| Open set B, OpenMax AUROC: logreg, mlp, svm_rbf | program-matched | 0.6427, 0.6241, 0.6402 |
| Open set B / C, random_forest MSP AUROC | program-overlapping | 0.2528 / 0.9142 |
| Novel rows whose nearest fitting row has the same input program | program-overlapping / program-matched | 98.4% / 0.0% |
| Mean 5-NN distance: novel (overlapping), novel (matched), known evaluation | | 1.99, 6.22, 5.93 |
| Sibling axis, MSP AUROC: ends / interiors | program-matched | 0.3303 / 0.5215 |
| Ends versus interiors; ends versus all others, exact permutation p | program-matched | 0.0667 (minimum attainable); 0.0095 |
| Simulation, spread 1, end / interior holdout | ordered / random sibling layout, 20 seeds | 0.2798 / 0.6342; 0.5658 / 0.5615 |

Read the open-set rows with their protocol. Under the program-matched protocol,
near-novelty detection by MSP in configuration B is at or below chance; the B
minus C interval excludes 0 for random_forest, extra_trees, svm_rbf and knn and
does not for logreg and mlp. The OpenMax values are an observation, not evidence
about score scale. The `evt_posterior` scorer is excluded from every comparison
(it is inverted by construction); six scorers remain.

## Environment of record

Python 3.9.6, numpy 2.0.2, scipy 1.13.1, pandas 2.3.3, scikit-learn 1.6.1,
matplotlib 3.9.4, pytest 8.4.2. `requirements.txt` and `environment.yml` pin
exactly these. `pyproject.toml` states lower bounds only, so install the pins
first.

```bash
python3.9 -m venv .venv                      # a Python 3.9.6 interpreter
.venv/bin/pip install -r requirements.txt
export PY="$PWD/.venv/bin/python" PYTHONPATH="$PWD/src"
# alternative to PYTHONPATH: .venv/bin/pip install --no-deps -e .
export LOKY_MAX_CPU_COUNT=4 OMP_NUM_THREADS=1
$PY -m pytest -q tests
```

Run every command from the repository root.

## Reproducing the article's tables and figures

Online Resource 1 (Section S1) of the article (Corrected Runbook) gives every command in dependency order and
maps each generated table and figure to the result files it reads. No table or
figure is typed by hand. The key commands:

```bash
# Open set: configuration B, program-matched (primary)
$PY scripts/openset_baselines.py --data data/features_pilot.csv \
    --models random_forest extra_trees logreg svm_rbf knn mlp --knn-k 5 \
    --seeds 0 1 2 3 4 --label sub_technique \
    --novel-programs heldout --split gss \
    --report results/v3/openset_B_heldout.json
#   A: --label technique;  C: --label sub_technique --holdout-col technique
#   program-overlapping: --novel-programs all --split gss
#   program k-fold:      --novel-programs heldout --split program_kfold
bash results/v3/run_v3.sh                    # all configurations and protocols

# Validity gate (self-contained: omit --full-macro-f1)
$PY scripts/diversity_gate.py --features data/features_pilot.csv \
    --label technique --full-macro-f1 0.9542 \
    --report results/v3/gate/gate_supplied_technique.json

# Semantic preservation (stdout and exit status)
$PY scripts/verify_semantics.py --programs corpus_inputs/programs.tsv \
    --corpus data/pilot_corpus --report results/v3/semantics/semantics_corpus_O0.json

# Simulation (ordered and random sibling layouts, 20 seeds)
bash results/v3/sim/run_sim_v3.sh            # drives scripts/holdout_inversion_sim.py

# Closed-set aggregation, fold and seed variance, fold-level paired summary
$PY scripts/aggregate_seeds.py --results results/pilot5 \
    --report results/closed_set_five_seed.json

# Ledger, tables, figures
export OBFUSCOPE_WORK=<work directory> OBFUSCOPE_TEX=<LaTeX project>
$PY scripts/manuscript_v3/make_ledger.py
$PY scripts/manuscript_v3/make_tables.py
$PY scripts/manuscript_v3/make_figures.py --out "$OBFUSCOPE_TEX/figures"
```

`results/v3/gate/README.txt`, `results/v3/closed/README.txt` and
`results/v3/README_openset_v3.txt` list the remaining drivers. The
nearest-neighbour mechanism and the evasion re-analysis are written by
`scripts/manuscript_v3/audit/nn_mechanism.py` and
`scripts/manuscript_v3/audit/evasion_diagnostics.py`. Known limitation: the gate
driver `results/v3/gate/run_gate_v3.sh` and its helpers set `ROOT` and `PY` to
absolute paths at their top; edit both before rerunning.

## Repository layout

```
src/obfuscope/            Python package
  features.py               static feature extraction (61 feature columns)
  labels.py                 family and parameterisation labels
  build_dataset.py          corpus to feature table (row order independent of --jobs)
  models.py                 seven scikit-learn estimators
  protocols.py, experiment.py  grouped CV, domain holdout (lomfo), --permute-groups
  aggregate.py, config.py   aggregation; named feature sets
  make_grid.py, run_grid.py legacy, see below
scripts/
  reference_backend.py      the backend that generated the corpus
  build_corpus_tigress.py   corpus builder (reference backend; Tigress not run)
  tigress_spec.py           Tigress cohort specification
  diversity_gate.py         validity gate (diagnostics 1, 1b, 2 to 6)
  gate_specificity.py       gate on 21 tables with verdicts fixed by construction
  audit_dead_features.py    declared features without variation
  audit_noop_artifacts.py   artifacts identical to their input program
  eta_bias_example.py       raw eta squared bias example
  openset_baselines.py      open-set protocols and scorers
  sibling_position_analysis.py  sibling-axis analysis
  holdout_inversion_sim.py  mixture simulation
  verify_semantics.py       compile-and-run equivalence check
  aggregate_seeds.py        fold and seed variance, paired summaries
  evasion_matched.py        released evasion analysis (supplement only)
  manuscript_v3/            make_ledger.py, make_tables.py, make_figures.py
    audit/                  nn_mechanism.py, evasion_diagnostics.py
tests/                    unit tests, including the corrected behaviour
corpus_inputs/            30 input programs and programs.tsv
data/                     pilot_corpus/, features_pilot.csv, template-generated tables
results/                  released result files (unchanged)
  v3/                       corrected analyses: openset_{A,B,C}_{heldout,all,kfold}.json,
                            sibling_position_*.json, summary/, gate/, closed/,
                            semantics/, sim/, openset_mechanism/, evasion/,
                            diagnostics/, logs/, drivers and checksums
docs/                     legacy HTCondor/OSPool runbook (reproduces no table)
htc/, decompile/          legacy, see below
```

`results/README.md` describes an earlier draft and is not the revised
manuscript; section and table numbers there do not match it.

## Corrections in this release

Each correction was made and tested as a separate commit during the revision;
this repository publishes them as one release, and `CHANGELOG.md` lists every
entry. The corrections are:

- `openset_baselines.py`: novel artifacts restricted to evaluation
  programs (`--novel-programs heldout`, now the default; `all` reproduces the
  released reports), program k-fold split, FPR95 in both conventions.
- `build_dataset.py`: deterministic row order for any `--jobs`.
- `protocols.py`, `experiment.py`: opt-in `--permute-groups`, so seeds
  give distinct program partitions in grouped CV.
- `aggregate_seeds.py`: rejects duplicate (configuration, seed) cells;
  fold-level paired summary.
- docstrings and comments in `src/` no longer use stale framing.
- `diversity_gate.py`: headroom R reported as undefined when the
  reference does not exceed chance; origin of a supplied reference recorded;
  `--repeats` for diagnostic 4.
- environment pinned to the environment of record; legacy run paths
  marked; `pyproject.toml` accepts Python 3.9.
- stale build products removed.
- new `scripts/eta_bias_example.py`.
- `holdout_inversion_sim.py`: Bayes classifier accuracy on retained
  classes, labelled fitted scorers, random sibling layout, seed options.
- `verify_semantics.py`: exit status compared, `-std=c99` pinned,
  time-outs caught, per-artifact seeds independent of the corpus path.
- new `scripts/audit_noop_artifacts.py`.
- `tigress_spec.py`: Split mapped to control (aggregation) in the
  Collberg taxonomy; legacy notes point to Online Resource 1 (Section S1) of the article.
- `scripts/manuscript_v3/`: ledger, table and figure generators and
  the two audit diagnostics.
- `results/v3/`: corrected open-set runs under all three protocols,
  gate, closed-set, semantics, simulation, mechanism and evasion re-analyses.

The released result files under `results/` are unchanged; corrected analyses
are under `results/v3/` with their drivers, logs and digests.

## Legacy components (reproduce nothing)

`htc/` (scheduler workflow and container recipes, which pin a different software
stack), `src/obfuscope/make_grid.py`, `src/obfuscope/run_grid.py` and
`scripts/run_all.sh` belong to an earlier pipeline and reproduce no table or
figure of the article or supplement; each begins with a note saying so.
`decompile/` is present and not exercised. No result depends on any of them.

## Template-generated table: `data/features.csv`

`data/features.csv` (4121 rows, 11 classes; `data/features_full.csv` is a
byte-identical copy) is a feature table from an earlier, template-generated
pipeline. The article uses it only as a negative control for the validity gate,
and `scripts/evasion_matched.py` reads it for the supplementary evasion
analysis. Its corpus is not released, so it cannot be rebuilt. SHA-256:
`a4e3f5022ffb2cade9cd3fd9f75968fefdd697bfb11129cfbf4d5ac23cea027b`.

**[TODO-ETH] Provenance unresolved.** The table's sample identifiers and paths
name malware samples (for example `WannaCrypt0r`), and earlier repository
documents describe its source samples as live malware. What was handled, by
whom and under which policy has not been established. Until the authors resolve
this, make no claim about whether malware-derived material was involved in
producing this table; whether it stays in the public release is also pending.
The file holds extracted feature values and path strings, not program text.

## Safety

The corpus of the article consists of synthetic benign C programs written for
this study and their transformed variants. Feature extraction is static and
executes nothing. `scripts/verify_semantics.py` compiles and runs those
synthetic programs and their artifacts with the system C compiler; run it in an
ordinary sandbox if you prefer. For the template-generated table, see the
provenance note above.

## License

MIT, see [`LICENSE`](LICENSE).
