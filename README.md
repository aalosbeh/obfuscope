# ObfuScope

**Fingerprinting the transformation, not the template. Corpus validity and open
set protocol design for obfuscation provenance attribution.**

Given the static source text of an obfuscated C program, this work asks two
questions. Which obfuscating transformation produced it, and was that
transformation one the model has never seen. The main contribution is not an
accuracy figure. It is a corpus validity gate that runs before any model is
trained and that refuses a corpus whose accuracy would be meaningless, together
with a measurement showing that the open set result on a single label space is
decided by how a novel class is defined.

> **Read this first.** The current manuscript is
> [`docs/ObfuScope_manuscript_revised_2.docx`](docs/ObfuScope_manuscript_revised_2.docx).
> It withdraws nine claims made in earlier versions of this work, including the
> headline accuracy that the previous README advertised. If you have seen an
> earlier draft or an earlier README, the numbers below supersede it.

## Important corrections to earlier descriptions of this project

| Earlier claim | Status |
| --- | --- |
| Macro F1 of 0.9915 over eleven transformation families | Withdrawn. The corpus behind it fails the validity gate on fifteen counts, and the figure measures template reuse rather than transformation signal |
| The corpus is derived from live malware | False, and corrected here. No malware was collected, executed or analysed at any point. Every artifact derives from a synthetic benign C program written for this study |
| Results are malware agnostic, shown by a leave malware families out protocol | Withdrawn as stated. The protocol is named `lomfo` and its column is named `malware_family` for version 1 legacy reasons, but the column holds one of five program domains. It is a program domain holdout |
| Open set AUROC of 0.988 | Withdrawn. It was computed with a scorer that read the logarithm of a vote fraction as a logit |
| Tree ensembles rank above linear models and k nearest neighbour | Withdrawn. The two strongest models win 8 and 15 of 25 paired folds at the two label granularities, which does not separate them |
| A feature set ablation shows the result does not rest on obfuscation markers | Withdrawn. The set meant to remove those markers removed 4 live features of 14 declared, and the two sets compared were nested rather than alternative |

Section 9.4 of the manuscript lists all nine withdrawn claims with labels. Section
9.5 lists six known defects in this artifact.

## What the current measurements are

All figures below come from the `reference_c` cohort, which is 2400 artifacts
generated from 30 synthetic input programs. Every one is reproducible with the
commands in Appendix A of the manuscript.

| Question | Protocol | Result |
| --- | --- | --- |
| Which transformation family? | Grouped by input program, 5 folds, 5 seeds | 0.9542 macro F1 |
| Which parameterisation? | Same, at the finer label granularity | 0.8045 macro F1 |
| Is the transformation unseen, when a whole family is held out? | Open set, 10 classes | 0.9142 AUROC, FPR95 of 0.3021 |
| Is the transformation unseen, when a parameterisation is held out and a sibling stays in training? | Open set, same 10 classes | 0.2528 AUROC |
| Does the validity gate discriminate, or does it just fail hard corpora? | 21 synthetic tables with verdicts fixed by construction | Fails all 12 degenerate instances, passes 8 of 9 sound ones |

The fourth row is the central result. Task, features, models and seeds are
identical to the third row. Only the definition of a novel class changes, and the
score inverts to far below chance. The manuscript explains this with a mixture
model whose prediction was tested and held: a removed class inverts the posterior
when it sits at an end of an ordered sibling axis, measured at 0.1887 for ends
against 0.4267 for interior members.

The gate also fails this corpus on two checks, and the manuscript reports those
failures rather than hiding them. Chance corrected headroom is 0.4486 and 0.7671
against a threshold of 0.50, so attribution here is substantially a matter of
counting integer constants, hexadecimal constants and XOR operators. Cross class
duplicate vectors put a ceiling of 0.9933 on accuracy at the parameterisation
granularity.

## What this work does not cover

Stated here because the vocabulary of the surrounding literature invites the
opposite assumption.

- **No malware.** The corpus is synthetic benign C.
- **One backend only.** The licensed obfuscator cohort is specified in the
  manuscript and was not built. No result here is a cross tool claim.
- **Synthetic input programs.** No result here covers real code such as coreutils
  or busybox.
- **Source text only.** The threat model is narrowed to source level artifacts. A
  decompiled binary input is not evaluated.

## Repository layout

```
obfuscope/
├── src/obfuscope/         # the Python package
│   ├── features.py        # static feature extraction, 61 declared features
│   ├── labels.py          # family and parameterisation labels
│   ├── build_dataset.py   # corpus to feature table
│   ├── models.py          # 7 model scikit-learn registry
│   ├── protocols.py       # grouped CV and open set splits
│   ├── experiment.py      # one experiment cell
│   ├── aggregate.py       # per cell JSON to tables
│   └── config.py          # named feature sets
├── scripts/               # the validity gate and every analysis in the paper
│   ├── diversity_gate.py          # the six diagnostics
│   ├── gate_specificity.py        # the gate measured against known verdicts
│   ├── audit_dead_features.py     # which declared features carry no variation
│   ├── openset_baselines.py       # the 7 novelty scorers
│   ├── sibling_position_analysis.py  # the ordered sibling axis test
│   ├── holdout_inversion_sim.py   # the mixture simulation
│   ├── evasion_matched.py         # evasion at matched class count
│   ├── build_corpus_tigress.py    # corpus generator, both backends
│   ├── verify_semantics.py        # compile and run equivalence check
│   └── aggregate_seeds.py         # fold and seed variance decomposition
├── htc/                   # HTCondor and DAGMan workflow
├── docs/                  # manuscripts and reviews, see below
├── data/                  # input programs, generated corpus, feature tables
├── results/               # every result file behind every table in the paper
└── requirements.txt, environment.yml, pyproject.toml, LICENSE
```

## Documents

| File | What it is |
| --- | --- |
| `docs/ObfuScope_manuscript_revised_2.docx` | **Current manuscript.** 35 tables, 61 references |
| `docs/ObfuScope_manuscript_revised.docx` | Previous revision, kept for comparison |
| `docs/review_v1_peer_review.docx` | Peer review of version 1 that prompted the rebuild |
| `docs/design_multitool_corpus.md` | Design note on the multiple backend corpus |
| `docs/RUNNING_ON_CHTC_OSPOOL.md` | Running the workflow at scale |

## Quickstart

```bash
pip install -r requirements.txt

# 1. Run the validity gate before trusting any accuracy
python3 scripts/diversity_gate.py \
    --features data/features_pilot.csv \
    --label technique --group sample_id \
    --full-macro-f1 0.9542 \
    --report results/gate_v2_technique.json

# 2. Show that the gate discriminates rather than failing everything
python3 scripts/gate_specificity.py --report results/gate_specificity.json

# 3. Which declared features are actually alive
python3 scripts/audit_dead_features.py \
    --features data/features_pilot.csv \
    --report results/dead_features.json \
    --set-report results/feature_set_live_counts.json
```

Point the same gate at the version 1 feature table to reproduce the fifteen
failures that forced the rebuild:

```bash
python3 scripts/diversity_gate.py \
    --features data/features.csv \
    --label technique --group sample_id \
    --full-macro-f1 0.9915 \
    --report results/gate_original_technique.json
```

Appendix A.2 of the manuscript gives every command behind every table, in
dependency order.

## Environment of record

Python 3.9.6, numpy 2.0.2, scipy 1.13.1, pandas 2.3.3, scikit-learn 1.6.1.

Note that `requirements.txt` pins different versions from these. The pins are
wrong and the versions above are the ones that produced the results. This is
recorded as a defect in Section 9.5 of the manuscript rather than corrected
silently, because correcting the pins without rerunning the grid would assert a
reproduction that has not been performed.

## Safety

The pipeline is static and execution free for feature extraction. The semantic
preservation check compiles and runs the synthetic benign programs in the
ordinary way. No malware is present in this repository and none was used in the
study.

## License

MIT, see [`LICENSE`](LICENSE).
