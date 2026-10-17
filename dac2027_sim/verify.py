"""
verify.py -- checks that must pass before any number from run_all.py is used.

  1. The worked example of DAC2027_accelerator_explained_rows.pdf (3x3 input, T=4, filters A and B):
     packing (one column for A and B, groups {p0,p1} {p2,p3}), the 8 running sums of Fig. 3,
     "last result leaves after 5 cycles" (Sec. 5.7), and the LIF output spike maps of Fig. 14.
  2. Random layers: the cycle-stepped PE simulator is bit-exact against the dense reference
     (W @ bit_t(S), then LIF) and its cycle count equals run_layer_fast, over many configurations.
  3. LoAS closed form reproduces EnergySpeedupSim.zip: VGG16 = 8,973,849 cycles (11.2173 ms @ 800 MHz).
"""
import itertools
import numpy as np

import workload as wl
from ours import Cfg, LayerPlan, pack_spikes, pack_weights, run_layer_fast, run_layer_stepped, tile_masks
from baselines import loas_layer_cycles, LOAS_P_ZIP


def bits(s):
    return sum(int(ch) << t for t, ch in enumerate(s))


def doc_example():
    T = 4
    S = np.array([[bits(x) for x in row] for row in [
        ["1000", "0000", "0100", "0011"],     # k0
        ["0000", "0010", "0011", "0000"],     # k1
        ["0100", "0011", "0000", "1000"],     # k2
        ["0011", "0000", "1000", "0100"]]], dtype=np.uint8)
    W = np.array([[2, 0, 0, 1], [0, 3, 1, 0]], dtype=np.int16)
    cfg = Cfg(R=4, C=1, T=T, F=2, G=2, W_open=4, pp=8, Mt=2, Nt=4, E=8, Lw=4, theta=2.0, leak=0.5, lif_units=8)
    assert pack_weights(W, 2) == [[0, 1]], "A and B should share one column"
    groups = pack_spikes(tile_masks(S, T), 2, 4)
    assert groups == [[0, 1], [2, 3]], groups
    spikes, sums, st = run_layer_stepped(W, S, cfg)
    want = {(0, 0): [2, 0, 1, 1], (0, 1): [0, 0, 0, 0], (0, 2): [1, 2, 0, 0], (0, 3): [0, 1, 2, 2],
            (1, 0): [0, 1, 0, 0], (1, 1): [0, 0, 4, 1], (1, 2): [0, 0, 3, 3], (1, 3): [1, 0, 0, 0]}
    for (f, p), v in want.items():
        assert list(sums[f, p]) == v, ((f, p), sums[f, p], v)
    assert np.array_equal(sums, wl.dense_sums(W, S, T))
    out = {(0, 0): "1000", (0, 1): "0000", (0, 2): "0100", (0, 3): "0011",
           (1, 0): "0000", (1, 1): "0011", (1, 2): "0011", (1, 3): "0000"}
    for (f, p), s in out.items():
        assert spikes[f, p] == bits(s), ((f, p), spikes[f, p], s)
    # Sec. 5.7: streaming starts after the 1-cycle weight load; last result leaves after 5 cycles
    fast = run_layer_fast(W, S, cfg)
    assert fast["cycles"] == st["cycles"]
    # total = weight load (L=1) + 5 stream cycles (G2 leaves the bottom after cycle 4) + 1 edge-FIFO write
    #         + 1 output-buffer read-modify-write + 1 LIF sweep cycle (7 dirty entries, (A,p1) never written,
    #         8 LIF units)
    stream = st["cycles"] - cfg.L - 1 - 1 - 1
    assert stream == 5, stream
    print(f"[ok] doc example: packing, 8 running sums, LIF spikes; stream = 5 cycles (Sec. 5.7), "
          f"total with load+LIF = {st['cycles']} cycles")


def random_layers():
    rng = np.random.default_rng(1)
    cases = stalled = 0
    shapes = [(6, 13, 9), (10, 24, 20), (16, 36, 40), (3, 5, 7), (20, 9, 33), (64 + 5, 20, 10)]
    cfgs = [Cfg(), Cfg(F=2, G=2), Cfg(shadow=False), Cfg(E=1), Cfg(Lw=4), Cfg(pp=2, W_open=2),
            Cfg(R=8, C=2, G=3), Cfg(Mt=8, Nt=16), Cfg(Mt=8, Nt=16, E=2, Lw=2, shadow=False), Cfg(R=3, C=5, F=3),
            # small edge FIFOs: backpressure stalls the feeder
            Cfg(D=16), Cfg(D=20, E=1), Cfg(D=24, E=2, shadow=False), Cfg(R=8, C=2, G=3, D=12, Lw=4)]
    for (M, K, N), cfg, (wd, ns) in itertools.product(shapes, cfgs, [(0.1, 0.1), (0.3, 0.3), (1.0, 0.5)]):
        W = wl.rand_weights(rng, M, K, wd)
        S = wl.rand_spikes(rng, (K, N), ns, 0.3)
        ref = wl.dense_sums(W, S)
        theta = float(max(1, np.abs(ref).max() // 3))
        cfg = Cfg(**{**cfg.__dict__, "theta": theta})
        spikes, sums, st = run_layer_stepped(W, S, cfg)
        assert np.array_equal(sums, ref), (M, K, N, cfg)
        assert np.array_equal(spikes, wl.lif(ref, theta)), (M, K, N, cfg)
        fast = run_layer_fast(W, S, cfg)
        assert fast["cycles"] == st["cycles"], (M, K, N, cfg, fast["cycles"], st["cycles"])
        assert fast["fifo_max"] == st["fifo_max"], (fast["fifo_max"], st["fifo_max"])
        assert fast["fifo_stalls"] == st["fifo_stalls"], (fast["fifo_stalls"], st["fifo_stalls"])
        assert st["fifo_max"] <= cfg.D
        cases += 1
        stalled += st["fifo_stalls"] > 0
    assert stalled > 0
    print(f"[ok] {cases} random layers: stepped simulator bit-exact vs dense, cycles == fast model "
          f"({stalled} with edge-FIFO backpressure stalls, FIFO never above D)")


def loas_zip():
    tot = sum(loas_layer_cycles(*wl.gemm_shape(l), LOAS_P_ZIP) for l in wl.vgg16_layers())
    assert round(tot) == 8_973_849, tot
    r19 = sum(loas_layer_cycles(*wl.gemm_shape(l), LOAS_P_ZIP) for l in wl.resnet19_layers())
    assert round(r19) == 16_895_567, r19
    print(f"[ok] LoAS closed form reproduces the zip: VGG16 {tot:,.0f} cycles = {tot / 800e3:.4f} ms @ 800 MHz, "
          f"ResNet19 {r19:,.0f}")


if __name__ == "__main__":
    doc_example()
    loas_zip()
    random_layers()
