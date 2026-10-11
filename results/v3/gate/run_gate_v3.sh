#!/bin/bash
# AUDIT-GENERATED driver for results/v3/gate (run:gate-v3). Does not modify code.
set -u
ROOT="$(cd "$(dirname "$0")/../../.." && pwd)"
PY="${PY:-python3}"
OUT="$ROOT/results/v3/gate"
export PYTHONPATH=$ROOT/src LOKY_MAX_CPU_COUNT=4 OMP_NUM_THREADS=1 OPENBLAS_NUM_THREADS=1 MKL_NUM_THREADS=1 PYTHONHASHSEED=0
cd "$ROOT"
G=scripts/diversity_gate.py
PILOT=data/features_pilot.csv
V1=data/features.csv
PROT_T="manuscript Table 19 (MS L664): random_forest, feature set all, domain holdout (lomfo, StratifiedGroupKFold over malware_family, 5 folds), estimator seeds 0-4, mean macro F1 of 25 fold measurements; value taken from the manuscript"
PROT_S="manuscript Table 20 (MS L676): random_forest, feature set all, domain holdout (lomfo, StratifiedGroupKFold over malware_family, 5 folds), estimator seeds 0-4, mean macro F1 of 25 fold measurements; value taken from the manuscript"
run() { name=$1; shift; echo "== $name $(date +%T)"; /usr/bin/time -p $PY $G "$@" --report $OUT/$name.json > $OUT/logs/$name.log 2>&1; echo "   exit=$? $(date +%T)"; }
mkdir -p $OUT/logs
case "${1:-all}" in
  t1)
    run gate_selfcontained_technique --features $PILOT --label technique
    run gate_selfcontained_subtechnique --features $PILOT --label sub_technique
    run gate_selfcontained_v1 --features $V1 --label technique
    run gate_supplied_technique --features $PILOT --label technique --full-macro-f1 0.9542
    run gate_supplied_subtechnique --features $PILOT --label sub_technique --full-macro-f1 0.8045
    run gate_supplied_v1 --features $V1 --label technique --full-macro-f1 0.9915
    ;;
  t2a)
    run gate_repeats_selfcontained_technique --features $PILOT --label technique --repeats 10
    run gate_repeats_supplied_technique --features $PILOT --label technique --full-macro-f1 0.9542 --full-macro-f1-protocol "$PROT_T" --repeats 10
    ;;
  t2b)
    run gate_repeats_selfcontained_subtechnique --features $PILOT --label sub_technique --repeats 10
    run gate_repeats_supplied_subtechnique --features $PILOT --label sub_technique --full-macro-f1 0.8045 --full-macro-f1-protocol "$PROT_S" --repeats 10
    ;;
esac
# task 6: gate on the no-op-free table (written by results/v3/gate/filter_noop.py)
NN=$OUT/features_pilot_no_noop.csv
case "${1:-all}" in
  t6a)
    run gate_noop_free_selfcontained_subtechnique --features $NN --label sub_technique
    run gate_noop_free_supplied_subtechnique --features $NN --label sub_technique --full-macro-f1 0.8045 --full-macro-f1-protocol "manuscript Table 20 value (MS L676), measured on the full 2400-row table, not on this filtered table"
    ;;
  t6b)
    run gate_noop_free_supplied_noopRF_subtechnique --features $NN --label sub_technique --full-macro-f1 0.8165 --full-macro-f1-protocol "random_forest lomfo seeds 0-4 on the no-op-free table, from results/v3/closed/noop/noop_sensitivity.json (run:closedset-v3)"
    run gate_noop_free_selfcontained_technique --features $NN --label technique
    ;;
esac
