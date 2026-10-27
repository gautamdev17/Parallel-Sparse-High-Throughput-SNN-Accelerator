# Baseline cycle models audited against their papers

Each `<design>_paper.py` is a per-layer cycle (and, for LoAS, memory-traffic) model written from the design's own
paper, next to the model used before the audit; each `*_VGG16.json` holds its per-layer results on the chained VGG-16
IF T = 8 traces of `prune_chain.py` (dense / 90 / 95 / 98 %). Every model's "current" variant reproduces the previously
cached cycles exactly, layer by layer. Line numbers (`L###`, `l.###`) refer to the paper text extracted with PDFKit
from `ptb.pdf`, `spikex.pdf`, `Spikeflow.pdf`, `LoAS.pdf`, `sato.pdf` (not in the repo).

| Design | Finding | Used in `audited_vgg16.py` |
|---|---|---|
| PTB | official Prosperity-repo model uses TW = 4 and folds 4 pixels per row; the paper uses TW = 1 at T = 8 (8 TW columns) and one post-synaptic neuron per row -> official model ~2.1-2.4x too slow | `ptb_paper.py` "paper" (compute + fill) |
| SpikeX | current model = the paper's lenient reading (strict reading ~2x slower) | current model |
| SpikeFlow | faithful; fill/drain per pass adds 2.8 %; the one-fill model fits the paper's Fig. 17 averages best (-12 % / +3 %) | current model (`spikeflow_paper.py` "medium" in the tables) |
| SATO | official model maps each (t, pixel) row over all M on one PE (FC layers use 8 of 128 PEs); the paper's Fig. 2b loop nest runs PEs over a neuron's time steps (l.855-862), 128/T neurons per wave at T = 8; its single search tree finds one spike (SNN-T), so multi-spike IF needs T cycles per neuron | `sato_paper.py` loop nest int_S with the T-step tree overlapped (Fig. 8 PE scaling x5.1 vs paper x6.4); ideal balance and strict in the tables |
| LoAS | per-layer best of two mappings, serial fibre-B load, missing "Others" power, per-bit SRAM charging | `loas_paper.py` "paper", Table IV Others power, per-access SRAM |
| Prosperity | the official simulator (which reproduces the paper's published numbers, as does our `../prosperity_own.py` within +1.3..+3.8 %) omits the per-tile pipeline of its paper's Sec. VI (>= m + 4 cycles per tile) | `../prosperity_own_correct_final.py` |

`ours_access.py` / `ours_access_VGG16.json`: TIDES on-chip access records per layer (for the per-access SRAM rule).
