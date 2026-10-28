#!/bin/bash
# cone.sh <tag> <gl.vvp> : GL run in <tag>/ (stim, n.v already linked), then power of the LIF spike flops' fan-in cone
LIB=/Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/tsweep_synth/lib/NangateOpenCellLibrary_typical.lib
cd "$(dirname "$0")/$1"; rm -f *.vcd; vvp -n $2 +vcd > gl.log 2>&1
cat > c.tcl <<EOT
read_liberty $LIB
read_verilog n.v
link_design spikeflow_core
create_clock -name clk -period 1.25 [get_ports clk]
read_vcd -scope tb_spikeflow/dut spikeflow_ext_gl.vcd
set q [get_pins -of_objects [get_nets {lif_spk[*]}] -filter "direction==output"]
set ff [get_cells -of_objects \$q]
set dp [get_pins -of_objects \$ff -filter "direction==input"]
set cone [get_fanin -to \$dp -flat -only_cells -trace_arcs timing]
set comb {}
foreach c \$cone { if {![string match DFF* [get_property \$c ref_name]]} { lappend comb \$c } }
puts "lif_spk flops [llength \$ff]  cone cells [llength \$cone]  comb cells [llength \$comb]"
report_power -instances \$comb -digits 6 > cone_inst.rpt
exit
EOT
sta -no_init -exit c.tcl > c.rpt 2>&1; grep -E "flops|Error" c.rpt
awk 'NF==5 && $1 ~ /^[0-9]/ {a+=$1; b+=$2; c+=$3; d+=$4; n++} END {printf "cone comb (%d inst): internal %.4e switching %.4e leakage %.4e total %.4e\n", n, a, b, c, d}' cone_inst.rpt
rm -f *.vcd
