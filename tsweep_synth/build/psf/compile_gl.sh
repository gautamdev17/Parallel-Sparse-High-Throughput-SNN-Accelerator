#!/bin/bash
# compile_gl.sh <design> : the gate-level testbench of run_base.sh for the reused netlist -> build/psf/gl/<d>/gl.vvp
TS=$(cd "$(dirname "$0")/../.." && pwd); cd $TS/build/psf/gl/$1; C=$TS/lib/nangate45_cells.v
case $1 in
ptb)    iverilog -g2012 -DPTB -DNCYC=500 -DSTIM='"stim/ptb/in.hex"' -DVCDFILE='"ptb_gl.vcd"' -o gl.vvp $TS/tb/tb_array.v ptb_netlist.v $C ;;
spikex) iverilog -g2012 -DNCYC=500 -DSTIM='"stim/spikex/in.hex"' -DVCDFILE='"spikex_gl.vcd"' -o gl.vvp $TS/tb/tb_array.v spikex_netlist.v $C ;;
spikeflow) iverilog -g2012 -DSF_EXT_SRAM -DVCDFILE='"spikeflow_ext_gl.vcd"' -o gl.vvp $TS/tb/tb_spikeflow.v spikeflow_ext_netlist.v $C ;;
esac
echo "compile $1 exit=$?"
