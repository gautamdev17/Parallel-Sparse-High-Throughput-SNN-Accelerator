read_liberty ../lib/NangateOpenCellLibrary_typical.lib
read_verilog ours_buf_netlist.v
link_design ours_core
create_clock -name clk -period 2.0 [get_ports clk]
read_vcd -scope tb_ours_closed/dut ../build/gl_stream/closed/stream.vcd
report_activity_annotation
puts "BLOCK total"
report_power -digits 6
set pes {}; set fifos {}; set lifs {}
foreach c [get_cells *] {
  set n [get_full_name $c]
  if {[string match "r*.pe" $n]} { lappend pes $c }
  if {[string match "ids*.fifo" $n]} { lappend fifos $c }
  if {[string match "lif*.u" $n]} { lappend lifs $c }
}
puts "BLOCK pe [llength $pes]"
report_power -instances $pes -digits 6
puts "BLOCK fifo [llength $fifos]"
report_power -instances $fifos -digits 6
puts "BLOCK lif [llength $lifs]"
report_power -instances $lifs -digits 6
set pks {}
foreach c [get_cells *] { if {[string match "lane*.packer" [get_full_name $c]]} { lappend pks $c } }
if {[llength $pks] == 0} { set pks [get_cells packer] }
puts "BLOCK packer [llength $pks]"
report_power -instances $pks -digits 6
exit
