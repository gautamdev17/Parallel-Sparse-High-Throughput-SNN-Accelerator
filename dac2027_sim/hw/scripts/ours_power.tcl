read_liberty ../lib/NangateOpenCellLibrary_typical.lib
read_verilog ours_netlist_r.v
link_design ours_core
create_clock -name clk -period 1.25 [get_ports clk]
read_vcd -scope tb_ours/dut ours_gl.vcd
report_power -digits 4
report_activity_annotation
exit
