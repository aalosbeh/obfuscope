#!/usr/bin/env bash
# AUDIT-GENERATED driver for the v3 simulation runs (scripts/holdout_inversion_sim.py
# at commit 3e3ebdb, unmodified). At most 2 concurrent processes per driver
# instance; the random forest inside each uses n_jobs=-1, capped to 4 threads by
# LOKY_MAX_CPU_COUNT. Random forest results do not depend on the thread count
# (per-tree seeds are drawn from random_state), so the cap changes no value.
#
# Execution note: the first launch (00:43) started ordered_20seeds and
# random_5seeds and was then stopped (the two running jobs were left to finish)
# so that the remaining jobs could run alongside them; the relaunch skips any
# job whose report exists or whose lock directory exists. Each job's stdout,
# stderr and /usr/bin/time output are in logs/<name>.log / logs/<name>.err.
set -u
REPO="$(cd "$(dirname "$0")/../../.." && pwd)"
PY="${PY:-python3}"
export PYTHONPATH="$REPO/src" LOKY_MAX_CPU_COUNT=4 OMP_NUM_THREADS=1 PY REPO
cd "$REPO"
SIM=scripts/holdout_inversion_sim.py
OUT=results/v3/sim
P="${P:-2}"
# name|args   (default settings: 4 families x 3 siblings, dim 20, family spread 12,
# 400 per class, spreads 0.25 0.5 1 2 4 8)
{
echo "inversion_sim_ordered_5seeds|--sibling-layout ordered --seeds 5 --seed-start 0"
echo "inversion_sim_ordered_20seeds|--sibling-layout ordered --seeds 20 --seed-start 0"
echo "inversion_sim_random_5seeds|--sibling-layout random --seeds 5 --seed-start 0"
echo "inversion_sim_random_20seeds|--sibling-layout random --seeds 20 --seed-start 0"
# Supplementary AUDIT-GENERATED sweep: the zero-separation point quoted in the
# script docstring (AUROC 0.4985) and spreads between 2 and 4, where the
# retained-class Bayes accuracy passes 0.8 (spreads 2.0 and 4.0 are in the
# main runs with the same seeds).
echo "supp_fine_ordered_20seeds|--sibling-layout ordered --seeds 20 --seed-start 0 --sibling-spreads 0.0 2.5 2.75 3.0 3.5"
echo "supp_fine_random_20seeds|--sibling-layout random --seeds 20 --seed-start 0 --sibling-spreads 0.0 2.5 2.75 3.0 3.5"
} | tr '\n' '\0' | xargs -0 -n 1 -P "$P" bash -c '
IFS="|" read -r name args <<< "$1"
out="'"$OUT"'/$name.json"
if [ -s "$out" ]; then echo "skip $name (report exists)"; exit 0; fi
if ! mkdir "'"$OUT"'/logs/$name.lock" 2>/dev/null; then echo "skip $name (locked)"; exit 0; fi
echo "$(date +%T) start $name"
/usr/bin/time -p "$PY" '"$SIM"' $args --report "$out" > "'"$OUT"'/logs/$name.log" 2> "'"$OUT"'/logs/$name.err"; rc=$?
rmdir "'"$OUT"'/logs/$name.lock"
echo "$(date +%T) done $name rc=$rc"
' _
echo "$(date +%T) all simulation jobs finished (this driver instance)"
