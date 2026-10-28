#!/bin/bash
# power_t.sh <design> <T> : gate-level run + OpenSTA power of run_base.sh, on the reused netlist (build/psf/gl/<d>)
# with the stimulus of build/psf/T<T>/stim (RTL check already done in build/psf/T<T>/<d>/rtl_check.log).
set -e
D=$1; T=$2
TS=$(cd "$(dirname "$0")/../.." && pwd); LIB=$TS/lib/NangateOpenCellLibrary_typical.lib
G=$TS/build/psf/gl/$D; B=$TS/build/psf/T$T/$D
case $D in ptb|spikex) name=$D; top=${D}_core; scope=tb_array/dut ;;
           spikeflow) name=spikeflow_ext; top=spikeflow_core; scope=tb_spikeflow/dut ;; esac
cd $B; ln -sfn ../stim stim
ln -sfn $G/${name}_netlist.v ${name}_netlist.v; cp $G/${name}_synth.log .
vvp -n ${VVP:-$G/gl.vvp} +vcd > gl_run.log 2>&1
# SpikeFlow logs its psums / LIF spikes at gate level too: check them as well
[ $D = spikeflow ] && { python3 $TS/py/check_rtl.py spikeflow $B $T > gl_check.log 2>&1 || { cat gl_check.log; exit 1; }; }
cat > ${name}_power.tcl <<EOT
read_liberty $LIB
read_verilog ${name}_netlist.v
link_design $top
create_clock -name clk -period 1.25 [get_ports clk]
read_vcd -scope $scope ${name}_gl.vcd
report_power -digits 4
report_activity_annotation
exit
EOT
sta -no_init -exit ${name}_power.tcl > ${name}_power.rpt 2>&1
grep -E "^Total|unannotated" ${name}_power.rpt
rm -f *.vcd
echo "${D}_T${T}_DONE"
