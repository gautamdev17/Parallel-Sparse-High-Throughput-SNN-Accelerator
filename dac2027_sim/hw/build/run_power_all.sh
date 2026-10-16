#!/bin/bash
# gate-level VCD windows + OpenSTA power, in parallel
L=../lib/nangate45_cells.v
( iverilog -g2012 -DVCDFILE='"spikeflow_gl.vcd"' -o sf_gl.vvp ../tb/tb_spikeflow.v spikeflow_netlist.v $L && vvp -n sf_gl.vvp +vcd > sf_gl.log 2>&1 && ./power_one.sh spikeflow spikeflow_core spikeflow_gl.vcd tb_spikeflow/dut > spikeflow_power.out 2>&1 ) &
( iverilog -g2012 -DNCYC=600 -DND=600 -DSTIM='"stim/sato/in.hex"' -DDISP='"stim/sato/disp.hex"' -DVCDFILE='"sato_gl.vcd"' -o sato_gl.vvp ../tb/tb_sato.v sato_netlist.v $L && vvp -n sato_gl.vvp +vcd > sato_gl.log 2>&1 && ./power_one.sh sato sato_core sato_gl.vcd tb_sato/dut > sato_power.out 2>&1 ) &
( iverilog -g2012 -DPTB -DNCYC=500 -DSTIM='"stim/ptb/in.hex"' -DVCDFILE='"ptb_gl.vcd"' -o ptb_gl.vvp ../tb/tb_array.v ptb_netlist.v $L && vvp -n ptb_gl.vvp +vcd > ptb_gl.log 2>&1 && ./power_one.sh ptb ptb_core ptb_gl.vcd tb_array/dut > ptb_power.out 2>&1 ) &
( iverilog -g2012 -DNCYC=500 -DSTIM='"stim/spikex/in.hex"' -DVCDFILE='"spikex_gl.vcd"' -o sx_gl.vvp ../tb/tb_array.v spikex_netlist.v $L && vvp -n sx_gl.vvp +vcd > sx_gl.log 2>&1 && ./power_one.sh spikex spikex_core spikex_gl.vcd tb_array/dut > spikex_power.out 2>&1 ) &
wait
echo ALLDONE
