"""3-layer chain through the RTL: the spike bytes the RTL writes for layer L are the activation masks of layer L+1."""
import sys, numpy as np
sys.path.insert(0, "..")
import run_tests as r
from snn_sim import rand_weights, rand_masks, dense_sums, if_vec, pick_theta

r.compile_rtl()
rng = np.random.default_rng(21)
x_rtl = rand_masks(rng, 32, 40, .6)
x_ref = x_rtl.copy()
allok = True
for li, (M, K) in enumerate([(48, 32), (24, 48), (70, 24)]):
    W = rand_weights(rng, M, K, .4)
    th = pick_theta(W, x_ref, .2)
    ref = if_vec(dense_sums(W, x_ref), th)
    ok, out, tiles, nerr, _ = r.run_rtl(W, x_rtl, th, f"chain{li}")
    same = ok and np.array_equal(out, ref)
    print(f"layer {li+1}: {M}x{K} theta={th} RTL==dense: {same}  RTL cycles {sum(t[4] for t in tiles)}  err flags {nerr}  nonzero outputs {np.mean(ref>0):.2f}")
    allok &= same and nerr == 0
    x_rtl, x_ref = out, ref
print("CHAIN PASS" if allok else "CHAIN FAIL")
