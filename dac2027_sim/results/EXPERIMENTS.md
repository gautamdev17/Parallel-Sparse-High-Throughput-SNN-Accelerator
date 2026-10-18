# DAC 2027: all experiments, compiled (state as of 2026-10-18)

The architecture is the one described in `DAC2027_accelerator_explained_rows.pdf`:
- weight-stationary 4x4 PE array, 8 adders per PE (one per timestep);
- offline filter packing (F=4) and run-time pixel packing (G=4);
- 4 edge FIFOs of 80 entries, 16 LIF units.

The only RTL change is pipelining for timing: 8 packer lanes, a 4-stage LIF, and a 2-stage SRAM read-modify-write. It changes no behaviour and was re-verified.

Baselines: PTB, SpikeX, SATO, SpikeFlow, LoAS, Prosperity, Phi (Phi in the compression study only).

**Workload `sparse90`** (all main results):
- 90% of int8 weights are zero.
- 90% of neurons are silent.
- A non-silent neuron fires with p = 0.3 in each timestep and at least once; T = 8.
- About 3.2% of spike bits are 1.

**OP** = one accumulation per '1' spike bit per output channel (Phi's definition): VGG16 65.4 M OP/image, ResNet18 117.7 M.

## 1. RTL verification (closed loop, bit-exact and cycle-exact)
Script: `hw/rtl_closed.py`. Results: `rtl_closed_*.json`.

Setup:
- Verilator testbench (`hw/tb/tb_ours_closed.v`).
- The RTL packer forms the groups itself.
- The output SRAM is synchronous.
- The controller follows the cycle model's rules.

Every layer of both networks is checked: partial sums, output spikes and cycle count against the cycle model.

| Run | Layers | RTL cycles | Model cycles | Sum / spike mismatches |
|---|---:|---:|---:|---:|
| VGG16 b1 | 16/16 ok | 364,930 | 364,930 | 0 |
| VGG16 b16 | 16/16 ok | 4,576,997 | 4,576,997 | 0 |
| ResNet18 b1 | 21/21 ok | 543,056 | 543,056 | 0 |
| ResNet18 b16 | 21/21 ok | 7,977,322 | 7,977,322 | 0 |
| VGG16 b1, wd 0.3 / 0.5 † | 16/16 ok | 894,017 / 1,347,020 | same | 0 |
| ResNet18 b1, wd 0.3 † | 21/21 ok | 1,235,650 | same | 0 |

† Run before pipelining (2026-10-17). Not re-run on the pipelined RTL.

The cycle model runs in three versions that agree with each other: the fast C version (`edge_sim.c`), the stepped Python one, and an independent audit (`audit_ours.py`).

## 2. Latency and throughput vs baselines
Files: `main_tables.md`, `main_summary.json`. Figures: `v1_fig`, `v3_latency_throughput(_normalized)`.

Simulators used:
- Prosperity: its official simulator.
- PTB: the official model from the Prosperity repository.
- LoAS, SpikeX, SATO, SpikeFlow: our cycle models of each paper.
- Ours: the cycle model, which the RTL confirms (Section 1).

Cycles: sparse90, VGG16

| Design | Cycles b1 | Latency vs ours | Throughput gain of ours (b16) |
|---|---:|---:|---:|
| LoAS | 8,973,849 | 24.6x | 31.4x |
| SpikeX (8x8) | 3,335,686 | 9.1x | 11.7x |
| PTB | 3,701,483 | 10.1x | **13.0x** |
| SATO | 2,448,376 | 6.7x | 5.9x |
| SpikeFlow | 1,601,259 | 4.4x | 5.6x |
| Prosperity | 666,778 | 1.8x | 1.7x |
| **Ours** | **364,930** | 1.0x | 1.0x |

Cycles: sparse90, ResNet18

| Design | Cycles b1 | Latency vs ours | Throughput gain of ours (b16) |
|---|---:|---:|---:|
| LoAS | 15,076,980 | 27.8x | 30.2x |
| SpikeX (8x8) | 5,977,620 | 11.0x | 12.1x |
| PTB | 6,352,976 | 11.7x | **12.9x** |
| SATO | 3,555,140 | 6.6x | 6.8x |
| SpikeFlow | 2,854,289 | 5.3x | 5.8x |
| Prosperity | 1,025,513 | 1.9x | 2.0x |
| **Ours** | **543,056** | 1.0x | 1.0x |

Normalized to PTB: latency 0.099 (VGG16) and 0.085 (ResNet18); throughput 12.99x and 12.85x.

**Weakness: on the dense-weight workload `zipstats` we are not the fastest.**
- On VGG16, Prosperity is 4.1x faster than ours and SATO is level with ours. ResNet18 is similar.
- The full table is in `main_tables.md`.
- Our gain depends on weight sparsity. Section 10 shows how the gain changes with weight density.

**Iso-PE comparison** (`v4_tables.md`, `v4_fig`): with 16 PEs in every design, ours reaches 8.9x the throughput of LoAS on VGG16 and 8.7x on ResNet18. The other designs are 0.10–0.75x LoAS.

## 3. Power and EDP (gate-level, our RTL of each design, Nangate45)
Files: `v1_power_edp.md/.png`.

- Power is measured at 800 MHz on gate-level activity.
- SpikeFlow is measured with its buffer as external SRAM, like every other design.

| Design | Power (mW) | VGG16 EDP (mJ·ms) | ResNet18 EDP (mJ·ms) |
|---|---:|---:|---:|
| PTB | 600.5 | 12.86 | 37.87 |
| SpikeX | 295.7 | 5.14 | 16.51 |
| LoAS | 90.2 | 0.916 | 2.651 |
| SATO | 33.7 | 0.316 | 0.666 |
| SpikeFlow | 74.1 | 0.297 | 0.943 |
| Prosperity | 156.2 | 0.109 | 0.257 |
| **Ours** | 460.6 | **0.0958** | **0.212** |

- **EDP:** ours is the lowest on both networks.
- **Energy per inference:** ours is not the lowest (VGG16: SATO 0.103 mJ, Prosperity 0.130 mJ, ours 0.210 mJ).

## 4. Area and power breakdown of our core
Files: `ppa_breakdown.md`, `ppa.json`. Script: `hw/ppa_report.py`.

Flow: Yosys + ABC with a buffering script, Nangate45, OpenSTA power on gate-level activity from the closed-loop testbench.

Timing at 45 nm (synthesis-level, no placement or wiring): the worst path is 1.96 ns, so the core runs at 500 MHz (fmax 510 MHz).

| Block | Area 45 nm (mm²) | Share | Power @500 MHz (mW) | Share | Worst path (ns) |
|---|---:|---:|---:|---:|---:|
| PE array (16 PEs) | 0.219 | 23.0% | 89.7 | 30.3% | 0.86 |
| Edge FIFOs (4 x 80) | 0.480 | 50.6% | 118.7 | 40.1% | 1.96 |
| Packer (8 lanes) | 0.106 | 11.1% | 39.4 | 13.3% | 1.30 |
| LIF units (16) | 0.098 | 10.3% | 26.2 | 8.8% | 1.88 |
| Arbiter, skew, id sideband, RMW adders | 0.048 | 5.0% | 22.3 | 7.5% | 1.59 |
| **Core** | **0.950** | | **296.3** | | **1.96** |

SRAM buffers, CACTI 7 at 45 nm:
- Output buffer, 192 KB: 0.705 mm².
- Staging buffer, 64 KB: 0.234 mm².
- Group buffer, 4 KB: 0.016 mm².
- Total SRAM area 0.955 mm²; SRAM leakage 358 mW.

A 28 nm version (Stillmaker & Baas scaling plus CACTI at 28 nm) is also in `ppa_breakdown.md`: core 0.368 mm², core + SRAM 0.806 mm², 166 GOP/J.

## 5. Comparison table across papers (as published)
File: `comparison_table.md`.

- The table lists node, clock, area, power, GOP/s and GOP/J as each paper reports them.
- PTB, SpikeX, LoAS and SpikeFlow report only normalized results, so their cells are mostly empty.
- Workloads differ between papers, so this table is context, not a like-for-like comparison.

## 6. All designs at 45 nm, 500 MHz (like-for-like)
Files: `same_node_45nm.md/.json`, `gops_gopj.*`, `energy_breakdown.*`. Scripts: `hw/same_node_table.py`, `plot_gops.py`.

Method:
- **Core:** each design's core is our RTL of it, put through the same synthesis and gate-level power flow.
  - Prosperity was re-measured over a busy steady-state window: all 16 tiles, processor busy 87%, where before it was 24% busy over 2 tiles.
  - LoAS was re-measured on the sparse90 stimulus.
- **SRAM:** sizes are taken from each paper and costed with CACTI 7 at 45 nm, using LSTP cells, LOP periphery and 300 K. Every buffer meets 500 MHz.
  - Area, leakage and read/write energy are counted, with access counts from `mem_levels.py` at batch 16.
  - Prosperity's own simulator counters cover its activation, weight and partial-sum buffers.
- **DRAM:** 12.45 pJ/bit (the Prosperity repo, from DRAMsim3) × each design's DRAM traffic per image.
- **Earlier version:** ITRS-HP SRAM at 360 K, no access energy, and the old Prosperity and LoAS power. It is kept in `same_node_45nm_hpsram_old.md`.

| Design | Total area (mm²) | Core power (mW) | VGG16 GOP/s | VGG16 energy core / SRAM / DRAM (µJ/img) | VGG16 GOP/J core | VGG16 GOP/J core + SRAM | VGG16 GOP/J system |
|---|---:|---:|---:|---:|---:|---:|---:|
| PTB | 1.232 | 381.4 | 8.8 | 2834 / 76 / 3372 | 23 | 22 | 10 |
| SpikeX | 0.747 | 187.8 | 9.8 | 1253 / 45 / 742 | 52 | 50 | 32 |
| SATO | 0.355 | 21.6 | 19.5 | 72 / 83 / 742 | **903** | **421** | 73 |
| SpikeFlow | 0.207 | 47.2 | 20.5 | 150 / 19 / 510 | 435 | 385 | 96 |
| LoAS | 1.478 | 57.7 | 12.9 | 294 / 132 / 139 | 223 | 153 | **116** |
| Prosperity | 1.035 | 239.8 | 67.1 | 234 / 540 / 1161 | 280 | 85 | 34 |
| **Ours** | 2.128 | 296.3 | **114.3** | 170 / 272 / 180 | 386 | 148 | 105 |

ResNet18, ours: 118.1 GOP/s; 398 / 150 / 115 GOP/J for core / core + SRAM / system. On system GOP/J, ResNet18 ranks SpikeFlow 151, LoAS 126, SATO 123, ours 115.

- **Fastest:** ours, at 1.7x Prosperity and 13x PTB.
- **System GOP/J:** ours is 2nd on VGG16 and 4th on ResNet18, and ahead of Prosperity by about 3x.
- **Our energy is mostly SRAM:** the 192 KB output buffer's read-modify-writes, about 248 µJ per VGG16 image.
- **Core power is mostly clock:** ungated flop clock power is about 73% of ours.
- **Largest area,** because of the 192 KB output buffer.
- **LoAS caveat:** its TPPE does not close 500 MHz (3.14 ns), so its GOP/s is optimistic.

## 6b. Weight and activation traffic at three levels
Files: `mem_levels.md/.png`. Script: `mem_levels.py`. Batch 1, normalized to PTB.

The three levels are DRAM to on-chip buffers, buffers to the PE array, and into the PEs. Rules for each design are in the script header.

| Level | VGG16, ours | ResNet18, ours | Position |
|---|---:|---:|---|
| Off-chip | 0.28x | 0.32x | 2nd, after LoAS |
| On-chip | 0.54x | 0.41x | lowest |
| PE | 0.08x | 0.06x | lowest |

Our on-chip activation traffic is the highest of all designs. The packer reads raw spike trains for every m-block, and the 127-bit groups are read once per pass.

## 7. Storage compression (dual-side packing)
Files: `compression.json/.png`, `compression_validation.md`. Script: `storage_compression.py`.

- Compression ratio = dense stored bits / packed stored bits, on 128x128 matrices.
- Weight and neuron sparsity are both equal to x (the x-axis).
- The plot shows only designs that pack, plus Prosperity.

| Sparsity | Ours | LoAS | PTB | Phi | Prosperity |
|---|---:|---:|---:|---:|---:|
| 50% | 0.71 | 1.58 | 0.94 | 1.00 | 1.00 |
| 70% | 1.19 | 2.30 | 1.13 | 1.19 | 1.00 |
| 80% | 1.69 | 2.99 | 1.25 | 1.32 | 1.00 |
| 90% | 3.00 | 4.26 | 1.40 | 1.50 | 1.00 |
| 95% | 5.41 | 5.41 | 1.49 | 1.64 | 1.00 |
| 98% | **10.88** | 6.46 | 1.55 | 1.77 | 1.00 |

- **Where we lead:** at 95% sparsity we tie LoAS; at 98% we are best.
- **Below 95%:** LoAS leads.
- **Validation:**
  - Prosperity's product sparsity matches its paper exactly (34.21% → 2.79%).
  - Phi's Table 4 and Fig 12 are reproduced within about 10%.

## 8. DRAM traffic: weights / activations / outputs
Files: `mem_traffic.md/.png`. Script: `mem_traffic.py`.

Method:
- Prosperity: its official simulator, with only the read counters split into activation and weight counts.
- PTB: the official model from the Prosperity repository.
- All other designs: the same tiled rule, using each design's own data format and buffer size.

VGG16, batch 1 (MB):

| Design | Weights | Activations | Outputs | Total |
|---|---:|---:|---:|---:|
| PTB | 33.63 | 0.194 | 0.036 | 33.86 |
| SpikeX | 33.77 | 0.260 | 0.285 | 34.32 |
| LoAS | 7.57 | 0.421 | 0.285 | 8.27 |
| SATO | 33.77 | 0.260 | 0.285 | 34.32 |
| SpikeFlow | 33.66 | **0.044** | 0.285 | 33.99 |
| Prosperity | 37.79 | 0.441 | 0.285 | 38.52 |
| **Ours** | 9.38 | 0.194 | 0.285 | 9.86 |

At batch 16, ours is 1.81 MB per image and LoAS 1.39.

- **Activations:** SpikeFlow reads fewer bytes than ours. It sends only non-silent neurons plus 1 label bit per neuron. Our DRAM holds raw spike trains, and our pixel packing happens on chip, so it saves compute cycles, not DRAM bytes. Checked: our packed groups would take 0.37–0.60 MB if stored in DRAM, more than the raw 0.194 MB.
- **Weights:** our offline filter packing gives 3.6x less weight traffic than the dense-weight designs.
- **Total:** ours is lower than every design except LoAS.

## 9. Roofline
Files: `roofline.md/.png`. Script: `roofline.py`.

Setup:
- Batch 16, 500 MHz, DRAM at 64 GB/s.
- Work = effectual operations: VGG16 6.55 M per image, ResNet18 11.77 M.

| Design | VGG16 OI (op/B) | VGG16 attained (GOP/s) | Bound | % of roof |
|---|---:|---:|---|---:|
| PTB | 0.19 | 0.88 | memory | 7% |
| SpikeX | 0.88 | 0.98 | compute | 3% |
| LoAS | 4.70 | 1.29 | compute | 2% |
| SATO | 0.88 | 1.95 | memory | 3% |
| SpikeFlow | 1.28 | 2.05 | memory | 3% |
| Prosperity | 0.56 | 6.72 | memory | 19% |
| **Ours** | 3.62 | **11.44** | compute | 18% |

On ResNet18, ours attains 11.80 GOP/s at OI 4.93, again the highest attained performance.

## 10. Other results (older; read the caveats)
- **Sensitivity / design-space sweep** (`sensitivity.json`, `sweep.json`):
  - sweeps array size, F, G and E;
  - run on the pre-pipelining model (2026-10-17); re-run before quoting in the paper.
- **Weight-density runs** (wd 0.3 / 0.5; RTL-verified, Section 1): also pre-pipelining.
- **Bound audit** (`audit_bounds.md`): pre-pipelining (405,230 cycles for VGG16 b1, now 364,930); re-run before quoting.
- **Packing-gain figure** (`packing_gains.*`): superseded by the compression figure (Section 7).
- **LoAS+ study** (`loas_plus*.md`), a separate line of work on improving LoAS:
  - 3.4x fewer cycles than LoAS;
  - 3.2x less energy and 11x lower EDP;
  - its own RTL TPPE and gate-level power.

## Consistency caveats to fix before submission
1. **Clocks:**
   - Sections 2–3 use 800 MHz for every design; Sections 4, 6 and 9 use 500 MHz.
   - Our core only closes timing at 500 MHz (synthesis-level), and the baselines' RTL was never timing-closed.
   - Normalized latency and throughput ratios do not depend on the clock. The absolute ms and the power at 800 MHz in Section 3 do. Pick one clock (500 MHz) for the paper.
2. **The compression study's 50–90% range** does not favour us. The headline is the gain at high sparsity and in weight traffic.
3. **Phi** has no RTL or cycle model here. It appears only in the compression study and the as-published table.
