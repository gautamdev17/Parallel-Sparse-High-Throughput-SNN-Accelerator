set -e
cd "$(dirname "$0")/.."
verilator --binary --timing --trace --trace-underscore -O2 -Wno-fatal -Wno-lint -Wno-style -Wno-MULTIDRIVEN --top-module tb_ours_closed -Mdir build/obj_closed_gl2 -j 8 --x-assign 0 --x-initial 0 -DGATE -DTB_MAXT=4 -DTB_MAXKT=11 -DTB_MAXP=12 -DTB_MAXS=17 tb/tb_ours_closed.v build_buf/ours_buf_netlist.v lib/nangate45_cells.v > build/verilator_gl2.log 2>&1
(cd build/gl_stream && rm -f closed/stream.vcd && ../obj_closed_gl2/Vtb_ours_closed +vcd_from=300 +vcd_len=1000 +vcd_file=closed/stream.vcd > stream_run.log 2>&1)
(cd build/gl_lif && rm -f closed/lif.vcd && ../obj_closed_gl2/Vtb_ours_closed +vcd_lif +vcd_file=closed/lif.vcd > lif_run.log 2>&1)
cd build_buf
sta -no_init -exit pw_stream.tcl > pw_stream.rpt 2>&1 &
sta -no_init -exit pw_lif.tcl > pw_lif.rpt 2>&1
wait
grep -E "^unannotated|^Total" pw_stream.rpt pw_lif.rpt
