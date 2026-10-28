"""check_rtl.py -- compare RTL simulation dumps with the dense reference.
usage: check_rtl.py ptb|spikex|ours|spikeflow|sato|prosperity [build dir]

ptb, spikex and ours compare against the expected.npz written by gen_stim.py. spikeflow, sato and prosperity
recompute their expectation here from workload.dense_sums on the same layer tensors (gen_stim.tensors()), following
each testbench's output order, so the check does not reuse the stimulus generator's own arithmetic."""
import json, os, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
kind = sys.argv[1]
B = sys.argv[2] if len(sys.argv) > 2 else os.path.join(HERE, "build")
d = os.path.join(B, "stim", kind)


def check_spikeflow(W, S, ref, T=8, pcd=16, rows=16):
    """psums_spikeflow.txt: one line per finished row, 'r p0 .. p15'; column c holds pixel c // T, timestep c % T of
    the pass. The passes are those of passes.txt (non-silent pixel pairs in order); the first row_done of each row
    hands over the empty initial sums, and the trailing flush pass finishes the last real pass."""
    g = pcd // T
    npass = sum(1 for l in open(os.path.join(d, "passes.txt")) if len(l.split()) == 1) - 1     # minus flush
    pxs = []
    for p0 in range(0, S.shape[1], g):
        if len(pxs) == npass:
            break
        px = list(range(p0, min(p0 + g, S.shape[1])))
        if any(S[k, p] for k in range(S.shape[0]) for p in px):
            pxs.append(px)
    got = {}
    for line in open(os.path.join(B, "psums_spikeflow.txt")):
        v = [int(x) for x in line.split()]
        got.setdefault(v[0], []).append(v[1:])
    bad = 0
    for r in range(rows):
        seq = got.get(r, [])[1:]
        assert len(seq) == len(pxs), (r, len(seq), len(pxs))
        for px, row in zip(pxs, seq):
            want = [int(ref[r, px[c // T], c % T]) if c // T < len(px) else 0 for c in range(pcd)]
            bad += want != row
    print(f"spikeflow: {len(pxs)} passes x {rows} rows x {pcd} psums checked, mismatching rows = {bad}")
    return bad == 0


def check_sato(W, S, ref, nch=8, npe=128, T=8):
    """res_sato.txt: 'pe value' per finished row integration. A row is (t, pixel), t-major; rows go to the least
    loaded PE (first index on ties), and for each output channel n every PE walks its non-empty rows in order."""
    K, N = S.shape
    rows = [[k for k in range(K) if (int(S[k, p]) >> t) & 1] for t in range(T) for p in range(N)]
    load = np.zeros(npe, dtype=np.int64)
    per_pe = [[] for _ in range(npe)]
    for ri, r in enumerate(rows):
        i = int(np.argmin(load))
        load[i] += len(r)
        if r:
            per_pe[i].append(ri)
    want = {i: [int(ref[n, ri % N, ri // N]) for n in range(nch) for ri in per_pe[i]] for i in range(npe)}
    got = {i: [] for i in range(npe)}
    for line in open(os.path.join(B, "res_sato.txt")):
        i, v = (int(x) for x in line.split())
        got[i].append(v)
    nres = sum(len(v) for v in want.values())
    bad = sum(a != b for i in range(npe) for a, b in zip(want[i], got[i]))
    missing = sum(abs(len(want[i]) - len(got[i])) for i in range(npe))
    print(f"sato: {nres} row integrations ({nch} channels) checked, mismatches = {bad}, missing/extra = {missing}")
    return bad == 0 and missing == 0


def check_prosperity(W, S, T=8, m=256, k=16, n=128):
    """res_prosperity.txt: 'tile row acc[0..n-1]' per written-back row. Row r of k-tile kt is pixel r // T,
    timestep r % T, restricted to inputs kt*k .. kt*k+k-1 and filters 0..n-1; all-zero rows are never written."""
    nt = int(open(os.path.join(B, "cyc_prosperity.txt")).read().split()[-3]) + 1
    want = {}
    for kt in range(nt):
        ks = slice(kt * k, (kt + 1) * k)
        ref = __import__("workload").dense_sums(W[:n, ks], S[ks, :m // T])         # (n, pixels, T)
        for r in range(m):
            p, t = divmod(r, T)
            if any((int(S[kk, p]) >> t) & 1 for kk in range(kt * k, (kt + 1) * k)):
                want[(kt, r)] = [int(x) for x in ref[:, p, t]]
    got = {}
    for line in open(os.path.join(B, "res_prosperity.txt")):
        v = [int(x) for x in line.split()]
        got[(v[0], v[1])] = v[2:]
    bad = sum(got.get(key) != val for key, val in want.items())
    extra = len(set(got) - set(want))
    print(f"prosperity: {nt} tiles, {len(want)} non-zero rows x {n} filters checked, mismatching rows = {bad}, "
          f"extra rows = {extra}")
    return bad == 0 and extra == 0


if kind in ("spikeflow", "sato", "prosperity"):
    sys.path.insert(0, os.path.dirname(HERE))
    sys.path.insert(0, HERE)
    import workload as wl
    from gen_stim import tensors
    _, W, S = tensors()
    if kind == "spikeflow":
        ok = check_spikeflow(W, S, wl.dense_sums(W[:16], S))
    elif kind == "sato":
        ok = check_sato(W, S, wl.dense_sums(W[:8], S))
    else:
        ok = check_prosperity(W, S)
    sys.exit(0 if ok else 1)

exp = np.load(os.path.join(d, "expected.npz"))["sums"]

if kind in ("ptb", "spikex"):
    rows = 16 if kind == "ptb" else 8
    got = {}
    for line in open(os.path.join(B, f"psums_{kind}.txt")):
        v = [int(x) for x in line.split()]
        got.setdefault(v[0], []).append(v[1:])
    bad = 0
    for r in range(rows):
        seq = got[r][1:]                      # first 'go' hands over the empty initial psums
        assert len(seq) == exp.shape[0], (r, len(seq), exp.shape[0])
        for it in range(exp.shape[0]):
            if list(exp[it, r]) != seq[it]:
                bad += 1
    print(f"{kind}: {exp.shape[0]} iterations x {rows} rows x 8 timesteps checked, mismatches = {bad}")
    sys.exit(1 if bad else 0)
else:
    meta = json.load(open(os.path.join(d, "meta.json")))
    m0, m1 = meta["m"]
    n0, n1 = meta["n"]
    got = np.zeros_like(exp)
    for line in open(os.path.join(B, "obuf_ours.txt")):
        v = [int(x) for x in line.split()]
        f, p = v[0], v[1]
        x = [u & 0xFFFFFF for u in v[2:]]                 # 24-bit output-buffer words
        got[f, p] = [u - (1 << 24) if u >> 23 else u for u in x]
    bad = int((got != exp).any(-1).sum())
    print(f"ours: output buffer {exp.shape[0]}x{exp.shape[1]} entries x 8 timesteps checked, mismatching entries = {bad}")
    gl = [list(map(int, l.split())) for l in open(os.path.join(B, "groups_ours.txt"))]
    want = [g for kt in meta["groups"] for g in kt]
    gotg = [sorted(x for x in g) for g in gl]
    ok = gotg == want
    print(f"ours: packer emitted {len(gotg)} groups, expected {len(want)}, identical = {ok}")
    sys.exit(0 if (bad == 0 and ok) else 1)
