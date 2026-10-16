#!/bin/bash
# usage: synth_one.sh <name> <top> <files...>   -> <name>_netlist.v, <name>_synth.log
name=$1; top=$2; shift 2
LIB=../lib/NangateOpenCellLibrary_typical.lib
cat > ${name}_synth.ys <<EOT
read_verilog -sv $*
hierarchy -top $top
synth -top $top -flatten
delete t:\$print t:\$check
opt_clean
dfflibmap -liberty $LIB
abc -liberty $LIB -D 1250
opt_clean -purge
hilomap -hicell LOGIC1_X1 Z -locell LOGIC0_X1 Z
stat -liberty $LIB
write_verilog -noattr -noexpr ${name}_netlist.v
EOT
yosys -q -l ${name}_synth.log ${name}_synth.ys
grep -A1 "Chip area" ${name}_synth.log
