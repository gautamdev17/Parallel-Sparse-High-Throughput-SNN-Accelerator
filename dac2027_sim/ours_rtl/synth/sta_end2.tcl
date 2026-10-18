read_liberty ../lib/NangateOpenCellLibrary_typical.lib
read_verilog ours_buf_netlist.v
link_design ours_core
create_clock -name clk -period 2.0 [get_ports clk]
set_input_delay 0 -clock clk [delete_from_list [all_inputs] [get_ports clk]]
set_output_delay 0 -clock clk [all_outputs]
report_checks -path_delay max -format end -group_path_count 200000 -endpoint_path_count 1 -unique_paths_to_endpoint
exit
