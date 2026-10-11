# Result files

Each file here backs a specific claim in
`docs/ObfuScope_manuscript_revised_2.docx`. Appendix A.2 of that document gives
the command that produces each one, in dependency order.

## Current

| File | Backs |
| --- | --- |
| `gate_v2_technique.json` | Section 4.5, the gate on this corpus at the family granularity |
| `gate_v2_subtechnique.json` | Section 4.5, the same at the parameterisation granularity, including the 0.9933 accuracy ceiling |
| `gate_original_technique.json` | Section 4.4, the twenty six failures of the version 1 corpus |
| `gate_specificity.json` | Section 4.3, Table 2, the gate measured against verdicts fixed by construction |
| `closed_set_five_seed.json` | Section 7.6, family granularity, fold and seed variance separated |
| `closed_set_five_seed_sub.json` | Section 7.6, parameterisation granularity |
| `openset_v2_technique.json` | Configuration A, family held out, 4 classes |
| `openset_v2_subtechnique.json` | Configuration B, parameterisation held out, 10 classes |
| `openset_v2_family.json` | Configuration C, family held out, 10 classes |
| `sibling_position.json` | Section 7.3, the ordered sibling axis test |
| `inversion_sim.json` | Section 7.5, the mixture simulation |
| `evasion_matched.json` | Section 7.8, Table 22, evasion at matched class count |
| `dead_features.json` | Section 5.6, Table 9, the seventeen constant columns |
| `feature_set_live_counts.json` | Section 5.6, Table 10, declared against live size of each feature set |
| `semantics_reference.json` | Section 5.5, semantic preservation on this corpus |
| `semantics_pilot_corpus.json` | Section 5.5, the same check on the pilot corpus |

## Superseded, kept only for history

These two were produced by the validity gate before it was extended in the
current version of the work. They lack the sixth diagnostic and they use the
uncalibrated input dependence statistic. No table in the manuscript cites them.
Use the `gate_v2_*` files instead.

- `gate_pilot_technique.json`
- `gate_pilot_subtechnique.json`

## A note on regenerating

Every file above except the three open set reports and the two closed set grids
regenerates in seconds. Those five are the expensive ones: the closed set grids
are 650 and 375 fold measurements, and the open set grid is 540 estimator fold
evaluations over 90 folds producing 3240 applicable scorer cells.

If you regenerate a gate report, pass the `--full-macro-f1` value that the
manuscript reports for that granularity, 0.9542 for the family labels and 0.8045
for the parameterisation labels. The chance corrected headroom is computed
relative to that value, so a different input changes the reported statistic.
