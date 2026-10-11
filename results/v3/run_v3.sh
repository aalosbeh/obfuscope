#!/usr/bin/env bash
# AUDIT-GENERATED driver for the v3 open set runs (at most 3 concurrent processes).
# Run from anywhere; works in the repository root so that report["data"] reads
# "data/features_pilot.csv" exactly as in the committed reports.
set -u
REPO="$(cd "$(dirname "$0")/../.." && pwd)"
PY="${PY:-python3}"
export PYTHONPATH="$REPO/src" LOKY_MAX_CPU_COUNT=4 OMP_NUM_THREADS=1 PY REPO
cd "$REPO"
COMMON="--data data/features_pilot.csv --models random_forest extra_trees logreg svm_rbf knn mlp --knn-k 5"
A="--label technique"
B="--label sub_technique"
C="--label sub_technique --holdout-col technique"
GSS="--split gss"
KF="--novel-programs heldout --split program_kfold"
S="--seeds 0 1 2 3 4"
# name|out|args ; longest jobs first. B_kfold is split by seed (folds are
# independent of execution order) and merged by merge_parts.py.
{
echo "openset_A_kfold|results/v3/openset_A_kfold.json|$COMMON $A $KF $S"
echo "openset_C_kfold|results/v3/openset_C_kfold.json|$COMMON $C $KF $S"
for s in 0 1 2 3 4; do
echo "openset_B_kfold_s$s|results/v3/parts/openset_B_kfold_s$s.json|$COMMON $B $KF --seeds $s"
done
echo "openset_B_heldout|results/v3/openset_B_heldout.json|$COMMON $B --novel-programs heldout $GSS $S"
echo "openset_B_all|results/v3/openset_B_all.json|$COMMON $B --novel-programs all $GSS $S"
echo "openset_A_heldout|results/v3/openset_A_heldout.json|$COMMON $A --novel-programs heldout $GSS $S"
echo "openset_A_all|results/v3/openset_A_all.json|$COMMON $A --novel-programs all $GSS $S"
echo "openset_C_heldout|results/v3/openset_C_heldout.json|$COMMON $C --novel-programs heldout $GSS $S"
echo "openset_C_all|results/v3/openset_C_all.json|$COMMON $C --novel-programs all $GSS $S"
} | tr '\n' '\0' | xargs -0 -n 1 -P 3 bash -c '
IFS="|" read -r name out args <<< "$1"
if [ -s "$out" ] && [ -s "results/v3/diagnostics/$name.json" ]; then echo "skip $name"; exit 0; fi
echo "$(date +%T) start $name"
"$PY" results/v3/run_openset_instrumented.py --diagnostics "results/v3/diagnostics/$name.json" -- $args --report "$out" > "results/v3/logs/$name.log" 2> "results/v3/logs/$name.err"; rc=$?
echo "$(date +%T) done $name rc=$rc"
' _
echo "$(date +%T) all jobs finished"
