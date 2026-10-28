read_liberty /Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/tsweep_synth/lib/NangateOpenCellLibrary_typical.lib
read_verilog n.v
link_design spikeflow_core
create_clock -name clk -period 1.25 [get_ports clk]
read_vcd -scope tb_spikeflow/dut spikeflow_ext_gl.vcd
set q [get_pins -of_objects [get_nets {lif_spk[*]}] -filter "direction==output"]
set ff [get_cells -of_objects $q]
set dp [get_pins -of_objects $ff -filter "direction==input"]
set cone [get_fanin -to $dp -flat -only_cells -trace_arcs timing]
set comb {}
foreach c $cone { if {![string match DFF* [get_property $c ref_name]]} { lappend comb $c } }
puts "lif_spk flops [llength $ff]  cone cells [llength $cone]  comb cells [llength $comb]"
report_power -instances $comb -digits 6 > cone_inst.rpt
exit
