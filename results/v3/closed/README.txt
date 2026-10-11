results/v3/closed  --  corrective closed set analyses (AUDIT-GENERATED, run:closedset-v3)

Environment: Python 3.9.6, numpy 2.0.2, scipy 1.13.1, pandas 2.3.3, scikit-learn 1.6.1
(macOS, Apple M4 Max). Code: this repository at commit 27e4b6d, unmodified
(src/obfuscope/models.py is not changed; the MLP sensitivity uses a wrapper).
Every subprocess ran single threaded (OMP/OpenBLAS/vecLib/MKL = 1,
LOKY_MAX_CPU_COUNT = 1), at most 4 processes at a time. Run all commands from the
repository root.

Reproduction check
  repro_check/*.json          13 seed 0 cells re-run with default settings
  repro_check/_compare.json   per fold macro F1 and confusion matrices identical to
                              the committed cells (max abs diff 0.0) for all 13

1. Partition variance (grouped_cv --permute-groups, technique task, 7 models x seeds 0-4)
  python results/v3/closed/scripts/run_jobs.py pg
  python scripts/aggregate_seeds.py --results results/v3/closed/pg --report results/v3/closed/pg_aggregate.json
  python results/v3/closed/scripts/analyze_pg.py <obfuscope-main>/results
  -> pg/*.json, pg_aggregate.json, pg_partition_variance.json, pg_vs_table19.csv,
     pg_paired_corrected.csv (corrected repeated CV t, r=5 x k=5, df=24, Holm over 21)

2. No-op sensitivity (32 byte-identical renaming artifacts removed; lomfo; RF, hist_gbdt; both tasks; seeds 0-4)
  python results/v3/closed/scripts/noop_identify.py --features data/features_pilot.csv \
      --corpus data/pilot_corpus --inputs corpus_inputs --out-dir results/v3/closed/noop
  python results/v3/closed/scripts/run_jobs.py noop
  python scripts/aggregate_seeds.py --results results/v3/closed/noop/cells --report results/v3/closed/noop/noop_aggregate.json
  python results/v3/closed/scripts/noop_analysis.py <obfuscope-main>/results
  -> noop/noop_rows.json, noop/features_pilot_no_noop.csv (2368 rows), noop/cells/*.json,
     noop/noop_aggregate.json, noop/noop_sensitivity.json (part A: cells vs Tables 19/20;
     part B: train full/no-op-free x test full/no-op-free)

3. Fold level paired statistics, all 21 pairs x 3 settings, from the committed cells
  python results/v3/closed/scripts/paired_foldlevel.py --orig-results <obfuscope-main>/results
  -> paired_foldlevel.csv, paired_foldlevel_meta.json
  (also: agg_committed_pilot5.json, agg_committed_pilot5sub.json = scripts/aggregate_seeds.py
   on the committed grids, for cross checking)

4. Estimator settings and convergence
  python results/v3/closed/scripts/hyperparameters.py      -> hyperparameters.json
  python results/v3/closed/scripts/convergence.py --orig-results <obfuscope-main>/results
                                                           -> convergence.json

5. MLP max_iter=2000 (lomfo, both tasks, seeds 0-4)
  python results/v3/closed/scripts/run_jobs.py mlp2000
  python scripts/aggregate_seeds.py --results results/v3/closed/mlp2000 --report results/v3/closed/mlp2000/mlp2000_aggregate.json
  python results/v3/closed/scripts/analyze_mlp2000.py <obfuscope-main>/results
  -> mlp2000/*.json, mlp2000/mlp_maxiter_sensitivity.json

Summary: summary_v3_closed.json (python results/v3/closed/scripts/collect_summary.py).
Logs: logs/. Checksums: SHA256SUMS.txt.

Known harmless noise: numpy 2.0.2 on this macOS build emits RuntimeWarnings
("divide by zero / overflow / invalid value encountered in matmul") from
sklearn/utils/extmath.py:203 during mlp and logreg fits; a direct check on the
standardised feature matrix gives finite results that agree with np.einsum, and
all re-run cells match the committed cells exactly.
