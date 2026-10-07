# RTL: dual-sparse weight-stationary 4x4 SNN array (Mentha + WS + T=8 parallel + one-cycle IF)

Built from `../REPORT.md`. Verilog-2005 + a few 2012 niceties, simulated with Icarus Verilog 12.
Run everything: `python3 run_tests.py full` (14 cases) and `python3 run_chain.py` (3-layer chain).

## Files

| File | What it is |
|---|---|
| `snn_defs.vh` | shared widths: index 8 bit, T=8, psum 16 bit (array) / 24 bit (partial buffer), 4 slots, entry/set formats |
| `lif.v` | the one-cycle neuron (named lif as asked; it is IF with soft reset, no leak): `v+=sum[t]; if v>theta {spike; v-=theta}` for t=0..7, unrolled, output registered |
| `pe.v` | one PE: stationary weight + row index; per cycle skip-and-pass if either index is 0, else search the 4-slot set for key (row idx, col idx): hit = add, miss = take lowest free slot; 8 gated adders |
| `systolic_array.v` | 4x4 PEs; weight load one PE row per cycle; activations flow down, psum sets flow right; tap column = `keff-1` |
| `packer.v` | Mentha graph-colouring packer for ONE operand of ONE K-slab (mask histogram -> degree per mask -> counting sort by degree -> greedy groups of up to 4 non-conflicting vertices -> `{index,value}` per K position, index = vertex+1, 0 = empty) |
| `preproc.v` | two packers in parallel: weight rows (up to 64) and activation columns (up to 128) |
| `exit_stage.v` | arrivals + FIFO (64) + 8 lanes: partial buffer (192 KB, 8x24 bit) read-modify-write on non-final K-slabs; add-partial + one-cycle neuron on the final slab; sweep of dirty entries after the last slab |
| `postproc.v` | result buffer (`{m,n,byte}`) and the unpack: 16 HBM writes per cycle at `(m-1, n-1)` |
| `snn_top.v` | one output tile (<=64x128): FSM PRE -> (LOAD -> RUN)* per chunk of 4 packed rows -> SWEEP -> TAIL -> FIN; counters |
| `tb_snn.v` | testbench: plays HBM/tile memory, loops over tiles, prints per-tile cycles |
| `run_tests.py`, `run_chain.py` | drive the RTL and compare with the dense reference and `snn_sim.py` |

## What was verified (all on Icarus Verilog, this machine)

* 14 random layers (tiny, K not a multiple of 4, K=1, 90% sparse, 64x16x128 at density 1.0 / 0.5 / 0.3 / 0.1, multi-tile 70x21x150 and 130x24x140, deep K, 64x64x128 at 5%):
  * output spikes **bit-exact equal** to the dense reference (`W @ bit_t(B)` then IF),
  * **cycle-exact equal** to `snn_sim.py` for every tile: total array cycles, passes, stall cycles, and the post-proc unpack cycles,
  * no slot-overflow, alignment or FIFO-overflow flag.
* 3-layer chain: the RTL's spike bytes of layer L used as layer L+1's activations, equal to the dense chain.
* Because passes, stalls and cycles all match `snn_sim.py` exactly, the hardware packer produces the same number of packed rows/columns, with the same fill, as `snn_sim.pack_weights/pack_acts`.

## How the RTL maps to the report

* `cyc_array` = LOAD + RUN + SWEEP + TAIL cycles = `Sim.run_tile` total. `cyc_pre` (pre-proc) is reported separately: the report assumes packing is free (done ahead, packed tiles sit in SRAM). A real design would double-buffer so that slab s+1 is packed while slab s runs; that ping-pong is NOT built here.
* Pass ends when all P packed columns have gone through AND the FIFO is empty (drain barrier). Freeze when `fifo + R*slots > 64`.
* The exit stage serves FIFO entries first and new arrivals second, `PORTS=8` per cycle (same as the simulator).

## Known limits (be honest about these)

* Behavioural memories: PB (8192 x 192 bit), FIFO, packed buffers and the result buffer are plain arrays. Eight lanes read/write the PB in one cycle; a real chip needs banking. The sweep uses a find-first-8 over the dirty bitmap (behavioural priority network).
* Not synthesized. The 8-step neuron (8 chained 28-bit add/compare/subtract) plus the 24-bit PB add in one cycle at 800 MHz is NOT proven. If it does not meet timing, split the neuron into two cycles (+1 cycle per tile).
* Weight-load shadow registers are not implemented (sensitivity run in the report says they would cut VGG16 latency by ~25%).
* Tile sequencing across a layer (which 64x128 tile next, HBM addresses) is done by the host / testbench. `snn_top` handles one tile.
* Post-proc also writes entries whose spike byte is 0 (harmless, HBM output starts at zero); dropping them would shorten the unpack tail slightly.
* Index width is 8 bits, so a tile window is at most 255 rows/columns (64 x 128 used).
