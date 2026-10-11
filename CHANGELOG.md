# Changelog

## Revised release accompanying the Information Systems Frontiers submission (October 2026)

Corrections and additions made during the pre-submission audit, oldest first. Each was a separate, tested commit in the working repository.

- openset_baselines: held-out novel programs, program k-fold, both FPR95 conventions
- build_dataset: deterministic row order for any --jobs value
- protocols/experiment: opt-in --permute-groups for grouped_cv
- aggregate_seeds: reject duplicate (config, seed) cells; add fold-level paired summary
- docs(src): replace stale version 1 framing in docstrings and comments
- diversity_gate: inconclusive headroom, reference record, --repeats, docstring
- env: pin the environment of record; mark version 1 run paths as legacy
- remove stale build products: docs/_docx_text.txt, htc/obfuscope_src.tar.gz
- add scripts/eta_bias_example.py: reproducible raw eta^2 bias example (Section 4.2)
- holdout_inversion_sim: Bayes closed accuracy, labelled fitted scorers, random sibling layout, seed options
- verify_semantics: compare exit status, pin -std=c99, catch timeouts, path-free seeds
- add scripts/audit_noop_artifacts.py: artifacts identical to their input program
- tigress_spec: map Split to control (Collberg aggregation); legacy notes point to Supplement S1
- manuscript_v3: ledger, table and figure generators; audit diagnostics (nearest-neighbour mechanism, evasion re-analysis)
- results/v3: corrected open-set runs (matched, overlapping, program k-fold), gate, closed-set, semantics, simulation, mechanism and evasion re-analyses
- README: describe the corrected artifact and the revised manuscript
- manuscript_v3: generator updates from final verification (ledger keys, table captions, figure labels)
- Make v3 helper scripts portable: repo-relative defaults instead of absolute local paths

## Earlier state

The tree before these corrections is the state that was audited (the earlier commits of this repository and the archive obfuscope-main.zip).
