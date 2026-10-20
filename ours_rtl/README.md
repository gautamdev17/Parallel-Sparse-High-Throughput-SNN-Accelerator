# Our accelerator: RTL package

Copies of the files in dac2027_sim/hw (those are the originals; scripts use paths relative to hw/ and hw/build_buf/).

| Folder | File | What it is |
|---|---|---|
| rtl | ours_core.v | the whole design: ours_pe (weight + filter label, 8 adders, slot = {filter label, pixel label}), ours_edge_fifo (80 entries, 16 banks), ours_lif (4-stage LIF), pk_step / ours_packer (first-fit pixel packer, 4 open groups, G = 4), ours_core (top: feeder skew, 4x4 PE array, edge arbiter + 16 RMW / cycle, id sideband, 8 packer lanes, 16 LIF units) |
| tb | tb_ours_closed.v | closed-loop testbench: RTL packer makes the groups, controller schedules from RTL signals, synchronous output SRAM; checks every partial sum, output spike and cycle count against the cycle model |
| tb | tb_ours.v | replay testbench used for the gate-level power runs (VCD) |
| verify | rtl_closed.py | builds and runs the closed-loop check with Verilator: `python3 rtl_closed.py net VGG16 1` (whole network) or `random N` |
| synth | ours_buf_synth.ys, abc_buf.script | Yosys + ABC (buffered) synthesis, Nangate45 typical |
| synth | sta_end2.tcl, pw_stream.tcl, pw_lif.tcl | OpenSTA timing and gate-level power (streaming and LIF windows) |
| reports | ours_buf_synth.log, sta_end2.rpt, pw_stream.rpt, pw_lif.rpt | area (0.950 mm²), worst path 1.96 ns (500 MHz), power 296.3 mW at 500 MHz |

Verified: VGG16 and ResNet18, batch 1 and 16, every layer bit-exact and cycle-exact (0 mismatches).
