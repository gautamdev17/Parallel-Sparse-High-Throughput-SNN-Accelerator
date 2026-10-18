read_liberty ../lib/NangateOpenCellLibrary_typical.lib
read_verilog loas_plus_netlist.v
link_design tppe_plus
create_clock -name clk -period 1.25 [get_ports clk]
read_vcd -scope tb_loas_plus/dut loas_plus_gl.vcd
report_power -digits 4
report_activity_annotation
exit
