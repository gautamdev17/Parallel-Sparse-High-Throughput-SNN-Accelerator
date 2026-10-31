# tsweep_synth: RTL changes for the T sweep (T = 4, 8, 16, 32)

Everything here is a copy; nothing under `dac2027_sim/` was modified. `orig_rtl/` is the unmodified copy of
`dac2027_sim/hw/rtl/` (used to reproduce the existing T = 8 numbers), `rtl/` is the edited copy used for the sweep.
Diff them with `diff -r orig_rtl rtl`.

Rule followed: change the RTL only where T really enters the hardware of the design as its paper describes it (or,
where the paper is silent, as the cycle model used for the sweep runs it). Everything else, including the
simplifications our RTL already made at T = 8, is kept as is, so that the T = 8 point stays the existing design.

Sources for the audit: the papers (`~/Downloads/{ptb,spikex,sato,Spikeflow,LoAS,prosperity}.pdf`), the official
Prosperity simulator / PTB / SATO models in `dac2027_sim/third_party/prosperity/`, the cycle models
`dac2027_sim/baselines.py` and `dac2027_sim/ours.py`, and every module of every RTL file, line by line.

| Design | Sized by T in hardware? | RTL change | Netlist per T |
|---|---|---|---|
| TIDES (ours) | yes: T gated adders per PE, T running sums per slot, T-bit trains/labels, T x 24-bit output-buffer words, LIF over T | none needed (parameter `T` everywhere); testbench made T-generic | one per T |
| PTB | no | none | one (identical at every T) |
| SpikeX | no | none | one (identical at every T) |
| SATO | adder-search tree only | `sato_adder_search` generalised (was hard-coded for T = 8) | one per T |
| SpikeFlow | no (fixed chip, configured per T by its master control) | LIF row: configurable pixel segmentation + membrane carry for T > 16 (was missing) | one (identical at every T) |
| Prosperity | no | none | one (identical at every T) |
| LoAS | yes: T-bit fibre-A, T correction accumulators, T-step LIF | 8 hard-coded result ports -> one T-wide bus | one per T |

## TIDES (`rtl/ours/ours_core.v`) -- no RTL change

The user's decision: 4 x 4 PEs with T adders per PE at every T. The RTL is fully parameterised by `T`, checked
module by module:

* `ours_pe`: `T` gated adders (one per timestep), `i_bits[T]`, labels `2*T` bits, running sums `F*G*T*SW`
  (SW = 10 bits stays: it bounds the sum of R = 4 int8 weights of one timestep, independent of T).
* `ours_edge_fifo`: entry width `EW = FIDW + PIDW + T*SW` (passed from the core); depth 80, 16 writes, E = 4
  reads: independent of T.
* `ours_lif`: T timesteps, `TPS = 2` timesteps per pipeline stage (kept: it sets the 500 MHz critical path), so
  T/2 stages (2 at T = 4 ... 16 at T = 32).
* `pk_step` / `ours_packer`: slice masks `MW = R*T` bits, labels `2*MW`.
* `ours_core`: injection `R*T` bits, output-buffer RMW ports `T*PSW` (PSW = 24 per timestep, independent of T),
  LIF ports `NLIF*T*PSW`, packer ports `R*T`.
* Synthesis: `chparam -set T <T> ours_core` on the `read_verilog -defer` design (the original script had no
  `chparam`; T = 8 is the default).

Testbench `tb/tb_ours_closed.v`: `T` from `-DTB_T` (was `localparam T = 8`), LIF latency `LIFP = T/2` (was 4 =
8/2), ring of LIF issue slots 32 deep (was 8, must exceed LIFP = 16 at T = 32), `slices` words `R*T` bits (were
32), `#(.T(T))` on the RTL instance. Offline data: `py/tides_data.py` = `dac2027_sim/hw/rtl_closed.py gen()` with
T-bit masks held as Python ints (the original `ours.tile_masks` packs into `uint64`, which overflows at R*T = 128,
i.e. T = 32) and `R*T`-bit slice words. At T = 8 it regenerates the files of `dac2027_sim/hw/build/gl_stream/closed`
and `gl_lif/closed` byte for byte.

## PTB (`rtl/ptb/ptb_core.v`) -- no change, because ...

* PTB paper (Sec. 4.1, Fig. 5(b), Table 4): 128 PEs (16 x 8), each one 8-bit AC unit + comparator + 96 x 8-bit
  scratchpad; nothing is sized by T. T only enters through the time-window (TW) mapping: columns = time windows,
  one PE processes the TWS time points of its window sequentially.
* Official model (Prosperity repo `run_PTB_convfc`, the PTB cycle count of the sweep): TWS fixed at 4; the T/4
  windows x output positions are folded into the 8 columns; each packed StSAP slot costs 4 cycles. The array is
  16 x 8 at every T.
* Our RTL: `ptb_pe` (1 accumulate unit, 96 B scratchpad) and the left/top skew are independent of T.
  `row_if` is our fixed 8-column integrate-and-fire unit (`T = COLS = 8` is the column count, not the model's T):
  its size is set by the array width, which does not change with T, so it is kept.
* What changes with T is the stimulus only (`py/gen_stim_t.py gen_array_t`): the official TWS = 4 folding at
  every T (T = 4: 8 positions x 1 window, 8: 4 x 2, 16: 2 x 4, 32: 1 x 8), StSAP on the 8-bit column tags, each
  slot streamed for the 4 time points of its windows (one sub-iteration per time point, its own scratchpad slot,
  so each PE psum is one (output channel, position, timestep) sum and is checked against the dense reference).
  The existing T = 8 number used TWS = 1 (column t = timestep t); it is reproduced with that original stimulus,
  and the sweep's T = 8 point uses the TWS = 4 mapping of the official model (both are reported).

## SpikeX (`rtl/spikex/spikex_core.v`) -- no change, because ...

* SpikeX paper (Sec. III-A, V-A): fixed 8 x 8 systolic array, one reusable accumulator + comparator + scratchpad
  per PE; TWS is reconfigurable; nothing is sized by T.
* Cycle model (`baselines.spikex_layer_cycles`): best of temporal / spatial mode x TWS with T/TWS <= 8 columns.
  On the power layer it picks temporal mode with TWS = 1, 1, 2, 4 at T = 4, 8, 16, 32 (= max(1, T/8)).
* Our RTL (`spikex_pe`, skew, `row_if` from `ptb_core.v`) is independent of T; the stimulus streams each active
  input for TWS cycles (one sub-iteration per time point), T = 4 uses 4 of the 8 columns.

## SATO (`rtl/sato/sato_core.v`) -- `sato_adder_search` generalised

* SATO paper (Fig. 2(b), 3(a), 6, Table 2/3): 128 PEs (non-zero register + 8-bit add accumulator), bucket-sort
  dispatcher and PE groups: none depends on T (a row = one timestep of one pixel). The binary adder-search tree
  takes the T integrations of a neuron in parallel (T leaves) and finds the firing step in log2(T) + 1 cycles
  (Prosperity-repo `run_sato_lif`: log2(T) + 1 cycles per neuron). So the tree is the only T-sized block.
* Original RTL: hard-coded for T = 8 (4-bit `fire_t`, `lo`, `hi`; 2-bit step counter stopping at step 2;
  `AW+4`-bit prefix sums and Vth). Changed to: `LT = log2 T`, prefix sums / Vth `AW + LT + 1` bits, `fire_t`,
  `lo`, `hi` `LT + 1` bits, step counter `clog2(LT)` bits stopping at `LT - 1`. At T = 8 every width and the
  step count are the original ones. The structure (T prefix sums + one comparator, binary search) is kept as at
  T = 8. Unit test `tb/tb_sato_tree.v`: 300 random neurons per T, fire_t = first crossing, 0 mismatches at
  T = 4, 8, 16, 32.
* `sato_pe`, `sato_dispatch`: no change (no T). `sato_core`: `vth` / `fire_t` port widths follow the tree.
* Testbench `tb/tb_sato.v`: T from `-DTB_T`, the tree gets a new neuron every log2(T) + 1 cycles (was every 4),
  `a_x` T x 16 bits.
* Testbench tree feed (2026-10-28): `a_x = res[(n % 128)*16 +: T*16]` ran past the 2048-bit `res` bus for
  n % 128 > 128 - T, i.e. X leaves in the gate-level run (7/128 tree loads at T = 8, 31/128 at T = 32). Now
  wraps round the 128 PE results (`{res, res}`). Effect at T = 8 on the original netlist: dynamic +0.05 %.
* T = 8 check of the generalised RTL: Yosys `equiv_induct` proves `sato_adder_search` (T = 8) equivalent to the
  original (176/176 cells); its netlist is 75,295 um2 vs 75,506 um2 (-0.28 %, ABC ordering noise), power
  21.65 vs 21.63 mW. Full-core RTL check 0 mismatches at T = 4 / 8 / 16 / 32 (8192 / 16384 / 32768 / 65536 row
  integrations). Results: `results/core_by_T_sato.json`.

## SpikeFlow (`rtl/spikeflow/spikeflow_core.v`) -- LIF row made configurable, membrane carry added

* SpikeFlow paper (Table 1, Sec. 4.1, 4.3.2, 5.2.1): 16 x 16 PEs, 16 LIF-PEs, 18.5 KB memory, identical hardware
  for every T ("configurable logic ... set via the MC module"). Columns = 16/T pixels x T timesteps for T <= 16;
  T > 16 is split into chunks of 16 run one after another, the last LIF-PE's membrane is stored and fed back to
  the first LIF-PE (Vm(pre)). In the LIF row a mux in front of every LIF-PE selects the previous LIF-PE's Vm or
  Vset; Vset is taken at each pixel's first column.
* Original RTL: `sf_lif_row` chained all 16 columns as one neuron (the T = 16 case only); at T = 8 the membrane
  of pixel 0 ran on into pixel 1. Changed to the paper's configurable row: input `cfg_seg` (MC configuration:
  neuron length 4 / 8 / 16 columns) drives the Vset mux of every LIF-PE; `carry` selects Vm(pre) for the first
  LIF-PE; `vlast` (membrane after LIF-PE 15) is output for storage. The carry flag of a pass travels with the
  pass's 'first' wave (`csr` shift register, tap = row + 16). Membranes are stored outside the core (16 entries,
  one per SA row: the paper's "temporary on-chip memory", where it is not specified; outside like the 18.5 KB
  buffer). Ports added: `nxt_carry`, `cfg_seg`, `lif_vpre`, `lif_vlast`, `lif_row`, `lif_go`.
* The netlist is the same at every T (configuration is a run-time input), as in the paper. PE array, skew,
  sequencer, buffers: no change.
* Testbench `tb/tb_spikeflow.v`: pass header `n seg carry`, membrane store, LIF spike log; `check_rtl.py`
  checks every psum and every LIF spike word (segment and carry) against the dense reference: 0 mismatches at
  T = 4, 8, 16, 32 (T = 32: 8 carry passes).

## Prosperity (`rtl/prosperity/prosperity_core.v`) -- no change, because ...

* Paper (Table III, Sec. II-B, V-B): spike matrix (T x L) x d_in, tiles m = 256 rows x k = 16, 128 PEs, 1 KB
  TCAM, 32 LIF cells; m is chosen by design-space exploration, not by T. The official simulator has no T in the
  accelerator configuration; T only changes the rows (pixel-major, row = pixel * T + t) and the LIF cycle count
  (`ceil(neurons/32) * T * 2`, sequential over T).
* Our RTL: detector, pruner, sorter, processor and `pr_lif` (sequential over T with a `first` flag) are all
  independent of T. Only the stimulus changes: 256/T pixels x T timesteps per tile (`gen_stim.gen_prosperity(T)`).
* The netlist is identical at every T: it is not re-synthesised; the existing netlist
  (`dac2027_sim/hw/build/prosperity_netlist.v`, from this same unchanged `prosperity_core.v`; that synthesis took
  44,015 s and 10.8 GB) is used at every T.

## LoAS (`rtl/loas/*.v`) -- result bus generalised to TIMESTEPS

* LoAS paper (Alg. 1, Sec. III, IV-A, IV-D, V, VI-B): the TPPE is sized by T: T-bit packed spike trains
  (fibre-A), 1 pseudo-accumulator + T correction accumulators, P-LIF over T; "all TPPE components other than
  accumulators and the input data buffer are agnostic" to T. Fig. 16(a) reports TPPE area / power growing with T.
* Original RTL: `TIMESTEPS` parameter exists (fibre-A width, `corr[0:TIMESTEPS-1]`, the all-ones check, the
  LIF's `T`), but `tppe`, `accumulator_correction` and `lif_model` had 8 hard-coded ports `result_0..7` /
  `input_0..7`, so only T = 8 worked. Changed to one flattened bus `results[TIMESTEPS*12-1:0]` /
  `inputs[T*Q-1:0]` and loops over T. Nothing else: fast / laggy prefix (128-bit bitmasks, 16 adders, depth-8
  FIFOs) and the pseudo-accumulator are T-independent; accumulator widths (13 / 12 bits) depend on the chunk,
  not on T. The LIF stays sequential (T + 2 cycles per neuron) as in our T = 8 RTL (the paper's P-LIF is
  unrolled; not changed, to keep the existing design at T = 8).
* Testbench `tb/tb_loas.v`: T from `-DTB_T`, flat result bus. Stimulus: `gen_stim.gen_loas(T)` (T-bit fibre-A).
  The testbench's behavioural reference checks every per-timestep result.

## Stimulus / workload (all designs)

`py/workload.py`: spike trains of any T (uint8/16/32), same RNG draws, so T = 8 is bit-identical to
`dac2027_sim/workload.py` (checked). Same layer (VGG16 b2c2), same seed, same workload (sparse90: 10 % non-zero
weights, 10 % non-silent neurons firing w.p. 0.3 per timestep, at least once) at every T. At T = 8 every
stimulus file of `dac2027_sim/hw/build/stim/` is regenerated byte for byte (`build/T8o/stim`).

## TIDES neuron: leaky LIF -> IF (2026-10-31)

The paper uses IF neurons. `ours_lif` in `rtl/ours/ours_core.v` (and `dac2027_sim/hw/rtl/ours/ours_core.v`) now
computes `V = V + x` (was `V = (V >>> 1) + x`); fire if V >= theta, then V -= theta (reset by subtraction, unchanged).
Without the leak V is no longer bounded by 2x the input, so it is widened from PSW + 2 to PSW + clog2(T) + 1 bits
(|V| <= T * 2^(PSW-1) + theta). Module and instance names are kept, so the synthesis and power scripts run
unchanged. The integer references (`lif_int` in `py/rtl_closed.py`, `py/tides_data.py`,
`dac2027_sim/hw/rtl_closed.py`) follow. `orig_rtl/` is untouched.

Re-checked: closed loop over every layer of VGG16 and ResNet18 (batch 1) and 20 random layers, all sums and
spikes bit-exact, RTL cycles == model (364,930 / 543,056 / 138,983); `tides_data.py` check at T = 4, 8, 16, 32 on
VGG16 L3 and ResNet18 L7, 0 wrong sums and spikes (13-15 % of the IF output bits fire). Nangate45 area/power of
the LIF block were not re-run.
