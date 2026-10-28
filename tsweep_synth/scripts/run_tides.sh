#!/bin/bash
# run_tides.sh <T> [rtl_dir] -- TIDES (ours_core) at T timesteps: closed-loop RTL check, synthesis, gate-level VCD
# windows, OpenSTA power. Same flow as dac2027_sim/hw/build_buf (ours_buf_synth.ys + abc_buf.script, 500 MHz) and
# dac2027_sim/hw/build/power_run.sh (Verilator gate-level closed loop: stream window = cycles 300..1300 of VGG16 b2c2,
# LIF window = output tile 0's LIF sweep of ResNet18 l2.0.ds).
#   -> build/T<T>/ours/{ours_buf_synth.log, pw_stream.rpt, pw_lif.rpt, rtl_check.log}
set -e
T=$1
RTL=${2:-rtl}
TS=$(cd "$(dirname "$0")/.." && pwd)
B=$TS/build/T$T/ours
mkdir -p $B/stream $B/lif
cd $B
LIB=$TS/lib/NangateOpenCellLibrary_typical.lib
VFLAGS="--binary --timing -Wno-fatal -Wno-lint -Wno-style -Wno-MULTIDRIVEN --top-module tb_ours_closed -j 2 --x-assign 0 --x-initial 0 -DTB_T=$T -DTB_MAXT=4 -DTB_MAXKT=11 -DTB_MAXP=12 -DTB_MAXS=17"

# ---- offline data (stream: VGG16 b2c2, LIF: ResNet18 l2.0.ds; batch 1, sparse90)
python3 $TS/py/tides_data.py gen $B/stream $T VGG16 3
python3 $TS/py/tides_data.py gen $B/lif $T ResNet18 7

# ---- RTL closed loop on both layers: every partial sum and LIF spike vs the dense reference
if [ ! -f rtl_check.ok ]; then
  verilator $VFLAGS -O3 -Mdir obj_rtl $TS/tb/tb_ours_closed.v $TS/$RTL/ours/ours_core.v > verilator_rtl.log 2>&1
  (cd stream && ../obj_rtl/Vtb_ours_closed > rtl_run.log 2>&1)
  (cd lif && ../obj_rtl/Vtb_ours_closed > rtl_run.log 2>&1)
  { grep CLOSED_DONE stream/rtl_run.log lif/rtl_run.log
    python3 $TS/py/tides_data.py check $B/stream $T VGG16 3
    python3 $TS/py/tides_data.py check $B/lif $T ResNet18 7; } > rtl_check.log 2>&1 && touch rtl_check.ok
  cat rtl_check.log
fi

# ---- synthesis (hierarchical, as build_buf)
# T is set by rewriting the parameter default in a copy of the RTL (identical file at T = 8): the original script
# runs unchanged (read_verilog -defer + chparam reorders elaboration and moves the ABC result by ~1 %)
mkdir -p rtl_T
sed "s/module ours_core #(parameter R = 4, C = 4, T = 8,/module ours_core #(parameter R = 4, C = 4, T = $T,/" $TS/$RTL/ours/ours_core.v > rtl_T/ours_core.v
grep -q "C = 4, T = $T," rtl_T/ours_core.v
if [ ! -f ours_buf_netlist.v ]; then
  cp $TS/scripts/abc_buf.script .
  cat > ours_buf_synth.ys <<EOT
read_verilog -sv rtl_T/ours_core.v
hierarchy -top ours_core
synth -top ours_core
delete t:\$print t:\$check
opt_clean
dfflibmap -liberty $LIB
abc -liberty $LIB -D 2000 -script abc_buf.script
opt_clean -purge
hilomap -hicell LOGIC1_X1 Z -locell LOGIC0_X1 Z
stat -liberty $LIB
write_verilog -noattr -noexpr ours_buf_netlist.v.tmp
EOT
  yosys -q -l ours_buf_synth.log ours_buf_synth.ys
  mv ours_buf_netlist.v.tmp ours_buf_netlist.v
fi
grep "Chip area for top module" ours_buf_synth.log | tail -1

# ---- gate-level closed loop (Verilator), VCD windows
# --trace-max-width: the widest core ports (obuf_rdata/wdata, lif_x = 16*T*24 bits; pk_gl = 8*5*2*4*T bits) pass
# Verilator's default trace width above T = 8 and were left out of the VCD (23552 unannotated pins at T = 16);
# 16384 covers T = 32. At T <= 8 every signal was already traced, so the VCDs there are unchanged.
if [ ! -f obj_gl/Vtb_ours_closed ]; then
  verilator $VFLAGS --trace --trace-underscore --trace-max-width 16384 -O2 -DGATE -Mdir obj_gl $TS/tb/tb_ours_closed.v ours_buf_netlist.v $TS/lib/nangate45_cells.v > verilator_gl.log 2>&1
fi
(cd stream && rm -f closed/stream.vcd && ../obj_gl/Vtb_ours_closed +vcd_from=300 +vcd_len=1000 +vcd_file=closed/stream.vcd > gl_run.log 2>&1)
(cd lif && rm -f closed/lif.vcd && ../obj_gl/Vtb_ours_closed +vcd_lif +vcd_file=closed/lif.vcd > gl_run.log 2>&1)
grep VCD_WINDOW stream/gl_run.log lif/gl_run.log

# ---- OpenSTA power at 500 MHz (pw_stream.tcl / pw_lif.tcl of build_buf, paths adapted)
for w in stream lif; do
  sed -e "s#../lib/NangateOpenCellLibrary_typical.lib#$LIB#" \
      -e "s#../build/gl_$w/closed/$w.vcd#$w/closed/$w.vcd#" $TS/scripts/pw_$w.tcl > pw_$w.tcl
done
sta -no_init -exit pw_stream.tcl > pw_stream.rpt 2>&1 &
sta -no_init -exit pw_lif.tcl > pw_lif.rpt 2>&1
wait
grep -E "^unannotated|^Total" pw_stream.rpt pw_lif.rpt
rm -f stream/closed/stream.vcd lif/closed/lif.vcd
echo "TIDES_T${T}_DONE"
