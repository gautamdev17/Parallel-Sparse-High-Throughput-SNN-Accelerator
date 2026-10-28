#!/bin/bash
# queue.sh <job file> -- runs one job per line ("<design> <T>"; design ours = run_tides.sh), at most 4 run_*.sh at a
# time (counting jobs started elsewhere), refreshing results/core_by_T.json after each job.
TS=$(cd "$(dirname "$0")/.." && pwd)
cd $TS
running() { pgrep -f "scripts/run_(base|tides).sh" | wc -l; }
while read -r d T; do
  [ -z "$d" ] && continue
  while [ "$(running)" -ge 4 ]; do sleep 10; done
  mkdir -p build/T$T
  if [ "$d" = ours ]; then
    ( scripts/run_tides.sh $T > build/tides_T$T.log 2>&1; python3 py/collect.py > build/collect.log 2>&1 ) &
  else
    ( scripts/run_base.sh $d $T build/T$T rtl > build/T$T/$d.log 2>&1; python3 py/collect.py > build/collect.log 2>&1 ) &
  fi
  sleep 5
done < "$1"
wait
echo QUEUE_DONE
