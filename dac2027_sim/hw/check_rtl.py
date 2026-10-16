"""check_rtl.py -- compare RTL simulation dumps with the dense reference. usage: check_rtl.py ptb|spikex|ours"""
import json, os, sys
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
kind = sys.argv[1]
d = os.path.join(HERE, "build", "stim", kind)
exp = np.load(os.path.join(d, "expected.npz"))["sums"]

if kind in ("ptb", "spikex"):
    rows = 16 if kind == "ptb" else 8
    got = {}
    for line in open(os.path.join(HERE, "build", f"psums_{kind}.txt")):
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
    for line in open(os.path.join(HERE, "build", "obuf_ours.txt")):
        v = [int(x) for x in line.split()]
        f, p = v[0], v[1]
        x = [u & 0xFFFFFF for u in v[2:]]                 # 24-bit output-buffer words
        got[f, p] = [u - (1 << 24) if u >> 23 else u for u in x]
    bad = int((got != exp).any(-1).sum())
    print(f"ours: output buffer {exp.shape[0]}x{exp.shape[1]} entries x 8 timesteps checked, mismatching entries = {bad}")
    gl = [list(map(int, l.split())) for l in open(os.path.join(HERE, "build", "groups_ours.txt"))]
    want = [g for kt in meta["groups"] for g in kt]
    gotg = [sorted(x for x in g) for g in gl]
    ok = gotg == want
    print(f"ours: packer emitted {len(gotg)} groups, expected {len(want)}, identical = {ok}")
    sys.exit(0 if (bad == 0 and ok) else 1)
