results/v3/gate  --  corrective gate analyses (AUDIT-GENERATED, run:gate-v3)

Environment: Python 3.9.6 venv of record (numpy 2.0.2, scipy 1.13.1, pandas 2.3.3,
scikit-learn 1.6.1), macOS, Apple M4 Max. Code: this repository at commit 1d579a1,
unmodified (no file outside results/v3/gate was changed; nothing committed).
PYTHONPATH=src, LOKY_MAX_CPU_COUNT=4, OMP_NUM_THREADS=1, at most 4 processes.
Run every command from the repository root. PY = the venv python.

1. Gate, self-contained (no --full-macro-f1) and with the supplied headline values
     results/v3/gate/run_gate_v3.sh t1
   -> gate_selfcontained_{technique,subtechnique,v1}.json
      gate_supplied_{technique,subtechnique,v1}.json   (--full-macro-f1 0.9542 / 0.8045 / 0.9915)
   $PY results/v3/gate/compare_reports.py
   -> compare_supplied_vs_committed.json  (0 differences on every committed key
      against results/gate_v2_technique.json, gate_v2_subtechnique.json,
      gate_original_technique.json; only revision fields added)

2. Diagnostic 4 seed sensitivity, split seeds 0-9 (verdict stays on seed 0)
     results/v3/gate/run_gate_v3.sh t2a ; results/v3/gate/run_gate_v3.sh t2b
   -> gate_repeats_{selfcontained,supplied}_{technique,subtechnique}.json

3. Consistent-protocol headroom (best-k probe under the headline lomfo protocol)
     $PY results/v3/gate/consistent_protocol_R.py
   -> consistent_protocol_R.json

4. Specificity re-scoring
     $PY scripts/gate_specificity.py --tmpdir <scratch> --report results/v3/gate/gate_specificity_rerun.json
     $PY results/v3/gate/specificity_policies.py
   -> gate_specificity_rerun.json (identical to results/gate_specificity.json)
      specificity_policies.json (policy (i), policy (ii) diagnostic 4 advisory,
      variant (ii-b) headroom-only advisory; Clopper-Pearson 95% CIs; R undefined count)

5. Raw eta squared bias example
     $PY scripts/eta_bias_example.py --report results/v3/gate/eta_bias_example.json

6. No-op artifacts and the gate without them
     $PY scripts/audit_noop_artifacts.py --corpus data/pilot_corpus \
         --programs corpus_inputs/programs.tsv --report results/v3/gate/noop_artifacts.json
     $PY results/v3/gate/filter_noop.py
   -> noop_filter.json, features_pilot_no_noop.csv (2368 rows; byte identical to
      results/v3/closed/noop/features_pilot_no_noop.csv)
     results/v3/gate/run_gate_v3.sh t6a ; results/v3/gate/run_gate_v3.sh t6b
   -> gate_noop_free_selfcontained_subtechnique.json
      gate_noop_free_supplied_subtechnique.json        (0.8045, manuscript, full table)
      gate_noop_free_supplied_noopRF_subtechnique.json (0.8165, RF lomfo on the
                                                        no-op-free table, from
                                                        results/v3/closed/noop/noop_sensitivity.json)
      gate_noop_free_selfcontained_technique.json

Summary: $PY results/v3/gate/collect_summary.py -> gate_v3_summary.json
Logs: logs/ (console output of every run, with /usr/bin/time).
Checksums: SHA256SUMS.txt.
