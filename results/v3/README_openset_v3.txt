results/v3 open set runs (AUDIT-GENERATED run of the corrected code; label run:openset-v3)
=========================================================================================

Code: scripts/openset_baselines.py (git blob 5c2e9032, last changed in 27e4b6d) and
scripts/sibling_position_analysis.py (blob a2b8c50c). Both unchanged through HEAD 1d579a1;
scripts/ and src/ were clean against HEAD when the runs finished. Nothing was committed.

Environment: Python 3.9.6 venv (numpy 2.0.2, scipy 1.13.1, pandas 2.3.3, scikit-learn 1.6.1,
joblib 1.5.3), PYTHONPATH=<repo>/src, LOKY_MAX_CPU_COUNT=4, OMP_NUM_THREADS=1, at most 3
concurrent processes, Apple M4 Max shared with other jobs (load average 77 to 137 during the runs).

Driver: run_v3.sh. Every run goes through run_openset_instrumented.py, which calls
openset_baselines.main(argv) unchanged and writes a diagnostics sidecar
(diagnostics/<name>.json: fits, warnings inside fit, MLP n_iter_, Weibull fallbacks, runtime).
Common arguments: --data data/features_pilot.csv
  --models random_forest extra_trees logreg svm_rbf knn mlp --seeds 0 1 2 3 4 --knn-k 5
Configurations: A --label technique
                B --label sub_technique
                C --label sub_technique --holdout-col technique
Variants:       heldout  --novel-programs heldout --split gss
                all      --novel-programs all     --split gss   (protocol of the committed reports)
                kfold    --novel-programs heldout --split program_kfold (5 blocks)
Outputs: openset_{A,B,C}_{heldout,all,kfold}.json.
openset_B_kfold.json was run as five one-seed processes (parts/openset_B_kfold_s{0..4}.json)
and merged with merge_parts.py (per_fold reordered to the script's model, seed order; summary
recomputed with the script's own _summarise). Folds are independent of execution order because
every random component is seeded by the fold's seed.

Sibling analysis: scripts/sibling_position_analysis.py --openset openset_B_<v>.json
  --features data/features_pilot.csv --report sibling_position_<v>.json (v = heldout, all, kfold)

Summaries: summarise_openset.py -> summary/ (see the module docstring for every file).

Sanity checks (summary/sanity_all_vs_committed.json, summary/crosscheck_overlap_control.json):
  'all' runs against obfuscope-main/results/openset_v2_{technique,subtechnique,family}.json:
  all 540 folds matched; AUROC max abs diff over all seven scorers 5.6e-17.
  AUPR differs by up to 0.0048 (tie-sensitive average precision; already known).
  heldout runs against the earlier audit control (novel_unseen) and kfold runs against the
  control's kfold_* outputs: max abs AUROC diff 2.8e-17 over 3,240 matched folds.

Wall time: 23:06:06 to 00:38:29 (92 min). Process runtimes in summary/diagnostics_summary.json.
stderr logs (logs/*.err) hold numpy 2.0.2 / Accelerate "divide by zero / overflow / invalid value
encountered in matmul" RuntimeWarnings from scipy.linalg.pinvh in LedoitWolf. They are spurious:
a plain matmul of finite uniform [0,1) matrices raises the same flag, and the LedoitWolf precision
is finite and matches numpy.linalg.inv to 4e-14 relative.
