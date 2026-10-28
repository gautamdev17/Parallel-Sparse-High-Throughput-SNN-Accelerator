#!/bin/bash
# usage: power_one.sh <name> <top> <vcd> <scope>   -> <name>_power.rpt
name=$1; top=$2; vcd=$3; scope=$4
cat > ${name}_power.tcl <<EOT
read_liberty ../lib/NangateOpenCellLibrary_typical.lib
read_verilog ${name}_netlist.v
link_design $top
create_clock -name clk -period 1.25 [get_ports clk]
read_vcd -scope $scope $vcd
report_power -digits 4
report_activity_annotation
exit
EOT
sta -no_init -exit ${name}_power.tcl > ${name}_power.rpt 2>&1
grep -E "^Total|Sequential|Combinational|unannotated|^vcd" ${name}_power.rpt
