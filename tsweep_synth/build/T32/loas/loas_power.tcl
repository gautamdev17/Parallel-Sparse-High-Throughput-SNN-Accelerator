read_liberty /Users/gautamdevaraj/Parallel-Sparse-High-Throughput-SNN-Accelerator/tsweep_synth/lib/NangateOpenCellLibrary_typical.lib
read_verilog loas_netlist.v
link_design tppe
create_clock -name clk -period 1.25 [get_ports clk]
read_vcd -scope tb_loas/dut loas_gl.vcd
report_power -digits 4
report_activity_annotation
exit
