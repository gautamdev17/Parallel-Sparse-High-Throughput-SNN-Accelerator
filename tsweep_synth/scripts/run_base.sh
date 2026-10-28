#!/bin/bash
# run_base.sh <design> <T> <run_dir> <rtl_dir>   design: ptb spikex sato spikeflow prosperity loas
# One baseline at T timesteps, the dac2027_sim/hw/build flow: RTL simulation + check (check_rtl.py), Yosys + ABC
# synthesis (synth_one.sh: flatten, Nangate45 typical, abc -D 1250), gate-level simulation of the netlist (iverilog,
# same windows as dac2027_sim/hw/build/run_power_all.sh and the logs there), OpenSTA report_power at 800 MHz
# (power_one.sh). The stimulus must already be in <run_dir>/stim/<design> (gen_stim_t.py).
#   -> <run_dir>/<design>/{<name>_synth.log, <name>_power.rpt, rtl_check.log}
set -e
# A T-independent netlist (PTB, SpikeX, SpikeFlow, Prosperity) is reused: put <name>_netlist.v, <name>_synth.log
# and the compiled gate-level testbench gl.vvp (its stimulus is read at run time) into <run_dir>/<design> first.
D=$1; T=$2; RUN=$(cd "$3" && pwd); RTL=$4
TS=$(cd "$(dirname "$0")/.." && pwd)
LIB=$TS/lib/NangateOpenCellLibrary_typical.lib
CELLS=$TS/lib/nangate45_cells.v
R=$TS/$RTL
TBS=$TS/tb; [ $RTL = orig_rtl ] && TBS=$TS/tb/orig     # original testbenches for the original RTL (T = 8 reproduction)
B=$RUN/$D
mkdir -p $B; cd $B
ln -sfn $RUN/stim stim
meta() { python3 -c "import json;print(json.load(open('stim/$1/meta.json'))['$2'])"; }

# T-sized designs (SATO, LoAS): T is set by rewriting the parameter default in a copy of the RTL (identical file at
# T = 8), so the original synthesis script runs unchanged (read_verilog -defer + chparam reorders elaboration and
# moves the ABC result slightly).
specialize() {   # file pattern_with_8 -> prints the path of the T copy
  mkdir -p rtl_T; local f=rtl_T/$(basename $1)
  sed "s/$2 = 8/$2 = $T/" $1 > $f; grep -q "$2 = $T" $f; echo $f
}
synth() {   # name top defines unused files...
  local name=$1 top=$2 defs=$3 chp=$4; shift 4
  if [ ! -f ${name}_netlist.v ]; then
    cat > ${name}_synth.ys <<EOT
read_verilog -sv $defs $*
hierarchy -top $top
synth -top $top -flatten
delete t:\$print t:\$check
opt_clean
dfflibmap -liberty $LIB
abc -liberty $LIB -D 1250
opt_clean -purge
hilomap -hicell LOGIC1_X1 Z -locell LOGIC0_X1 Z
stat -liberty $LIB
write_verilog -noattr -noexpr ${name}_netlist.v.tmp
EOT
    yosys -q -l ${name}_synth.log ${name}_synth.ys > /dev/null
    grep -v "^\s*\$display\|ACC\|LIF\]" ${name}_synth.log > /dev/null || true
    mv ${name}_netlist.v.tmp ${name}_netlist.v
  fi
  grep -A1 "Chip area for module" ${name}_synth.log | tail -2
}

power() {   # name top vcd scope
  cat > $1_power.tcl <<EOT
read_liberty $LIB
read_verilog $1_netlist.v
link_design $2
create_clock -name clk -period 1.25 [get_ports clk]
read_vcd -scope $4 $3
report_power -digits 4
report_activity_annotation
exit
EOT
  sta -no_init -exit $1_power.tcl > $1_power.rpt 2>&1
  grep -E "^Total|unannotated" $1_power.rpt
}

case $D in
ptb|spikex)
  name=$D; top=${D}_core; src=$R/$D/${D}_core.v
  def=""; [ $D = ptb ] && def="-DPTB"
  [ $D = spikex ] && src="$R/ptb/ptb_core.v $R/spikex/spikex_core.v"
  N=$(meta $D ncyc)
  iverilog -g2012 $def -DCHECK -DNCYC=$N -DSTIM="\"stim/$D/in.hex\"" -DVCDFILE='"rtl.vcd"' -o rtl.vvp $TS/tb/tb_array.v $src
  vvp -n rtl.vvp > rtl_run.log 2>&1; mv psums.txt psums_$D.txt
  python3 $TS/py/check_rtl.py $D $B $T > rtl_check.log 2>&1 || { cat rtl_check.log; exit 1; }
  # spikex_core.v uses row_if from ptb_core.v; synthesize the core with it (as the dac2027_sim build did)
  synth $name $top "" "" $src
  [ -f gl.vvp ] || iverilog -g2012 $def -DNCYC=500 -DSTIM="\"stim/$D/in.hex\"" -DVCDFILE="\"${name}_gl.vcd\"" -o gl.vvp $TS/tb/tb_array.v ${name}_netlist.v $CELLS
  vvp -n gl.vvp +vcd > gl_run.log 2>&1
  power $name $top ${name}_gl.vcd tb_array/dut ;;
sato)
  name=sato; N=$(meta sato ncyc)
  iverilog -g2012 -DTB_T=$T -DNCYC=$N -DND=$N -DSTIM='"stim/sato/in.hex"' -DDISP='"stim/sato/disp.hex"' -DVCDFILE='"rtl.vcd"' -o rtl.vvp $TS/tb/tb_sato.v $R/sato/sato_core.v
  vvp -n rtl.vvp > rtl_run.log 2>&1
  python3 $TS/py/check_rtl.py sato $B $T > rtl_check.log 2>&1 || { cat rtl_check.log; exit 1; }
  synth sato sato_core "" "" $(specialize $R/sato/sato_core.v "IW = 12, T")
  iverilog -g2012 -DTB_T=$T -DGATE -DNCYC=600 -DND=600 -DSTIM='"stim/sato/in.hex"' -DDISP='"stim/sato/disp.hex"' -DVCDFILE='"sato_gl.vcd"' -o gl.vvp $TS/tb/tb_sato.v sato_netlist.v $CELLS
  vvp -n gl.vvp +vcd > gl_run.log 2>&1
  power sato sato_core sato_gl.vcd tb_sato/dut ;;
spikeflow)
  name=spikeflow_ext
  iverilog -g2012 -DSF_EXT_SRAM -DVCDFILE='"rtl.vcd"' -o rtl.vvp $TBS/tb_spikeflow.v $R/spikeflow/spikeflow_core.v
  vvp -n rtl.vvp > rtl_run.log 2>&1
  python3 $TS/py/check_rtl.py spikeflow $B $T > rtl_check.log 2>&1 || { cat rtl_check.log; exit 1; }
  synth $name spikeflow_core "-DSF_EXT_SRAM" "" $R/spikeflow/spikeflow_core.v
  [ -f gl.vvp ] || iverilog -g2012 -DSF_EXT_SRAM -DVCDFILE='"spikeflow_ext_gl.vcd"' -o gl.vvp $TBS/tb_spikeflow.v ${name}_netlist.v $CELLS
  vvp -n gl.vvp +vcd > gl_run.log 2>&1
  power $name spikeflow_core spikeflow_ext_gl.vcd tb_spikeflow/dut ;;
prosperity)
  name=prosperity
  iverilog -g2012 -DNT=16 -DVCDFILE='"rtl.vcd"' -o rtl.vvp $TS/tb/tb_prosperity.v $R/prosperity/prosperity_core.v
  vvp -n rtl.vvp > rtl_run.log 2>&1
  python3 $TS/py/check_rtl.py prosperity $B $T > rtl_check.log 2>&1 || { cat rtl_check.log; exit 1; }
  synth prosperity prosperity_core "" "" $R/prosperity/prosperity_core.v
  [ -f gl.vvp ] || iverilog -g2012 -DNT=16 -DVCDFILE='"prosperity_ss_raw.vcd"' -o gl.vvp $TS/tb/tb_prosperity_ss.v prosperity_netlist.v $CELLS
  vvp -n gl.vvp +vcd > gl_run.log 2>&1
  python3 $TS/py/splice_vcd.py prosperity_ss_raw.vcd prosperity_ss_gl.vcd && rm -f prosperity_ss_raw.vcd
  power prosperity prosperity_core prosperity_ss_gl.vcd tb_prosperity/dut ;;
loas)
  name=loas; L=$R/loas
  src="$L/tppe.v $L/fast_prefix.v $L/laggy_prefix.v $L/accumulator_correction.v $L/lif_model.v"
  iverilog -g2012 -DTB_T=$T -DNCHUNK=576 -DSEED=1 -DSTIM='"stim/loas/chunks.hex"' -DVCDFILE='"rtl.vcd"' -o rtl.vvp $TBS/tb_loas.v $src
  vvp -n rtl.vvp > rtl_run.log 2>&1
  grep LOAS_RESULT rtl_run.log > rtl_check.log; grep -q "errors=0" rtl_check.log || { cat rtl_check.log; exit 1; }
  synth loas tppe "" "" $(specialize $L/tppe.v "parameter TIMESTEPS           ") $L/fast_prefix.v $L/laggy_prefix.v $L/accumulator_correction.v $L/lif_model.v
  iverilog -g2012 -DTB_T=$T -DGATE -DNCHUNK=576 -DSEED=1 -DSTIM='"stim/loas/chunks.hex"' -DVCDFILE='"loas_gl.vcd"' -o gl.vvp $TBS/tb_loas.v loas_netlist.v $CELLS
  vvp -n gl.vvp +vcd > gl_run.log 2>&1
  grep LOAS_RESULT gl_run.log
  power loas tppe loas_gl.vcd tb_loas/dut ;;
esac
cat rtl_check.log
rm -f *.vcd
echo "${D}_T${T}_DONE"
