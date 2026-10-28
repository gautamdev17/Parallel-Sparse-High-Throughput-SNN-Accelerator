"""make_prosperity_vs_tides.py -- A4 notes, in the style of DAC2027_accelerator_explained_rows.pdf: how Prosperity works
and how it differs from TIDES, traced on one small GEMM (4 tokens, 4 inputs, 2 filters, T = 4), then the same counts on
a real BERT layer.

Every number is computed here and checked:
  Prosperity  find_product_sparsity() of third_party/prosperity/simulator.py (copied below in numpy, same rules: a row
              with >= 2 spikes takes as prefix its largest proper subset, an identical row only if it is earlier),
              steps = remaining spike bits + exact-match rows (the official cycle count), issue order = stable sort
              by number of ones; output rows checked against the dense GEMM.
  TIDES       pack_weights / pack_spikes / tile_masks of ours.py (offline filter packing, TIP); slot = 4 * filter
              label + member label; output checked against the dense GEMM.
  Real layer  BERT block 0 FC1 (768 -> 3072), the real sentence of lm_chain.py (LMC_REAL=1), weight sparsity 90 / 99 %;
              cycles from results/lm_chain_real_cache.json, counts recomputed (cached in
              results/prosperity_vs_tides_fc1.json).

  python3 make_prosperity_vs_tides.py   -> ../Prosperity_vs_TIDES_explained.pdf (HTML rendered by headless Chrome)
"""
import json, math, os, subprocess, sys, tempfile
import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
from ours import Cfg, LayerPlan, pack_spikes, pack_weights, run_layer_fast, tile_masks

OUT = os.path.join(ROOT, "Prosperity_vs_TIDES_explained.pdf")
REAL_JSON = os.path.join(HERE, "results", "prosperity_vs_tides_fc1.json")
CHROME = "/Applications/Google Chrome.app/Contents/MacOS/Google Chrome"
DATE = "25 Oct 2026"


def prosparsity(tile):
    """numpy copy of simulator.find_product_sparsity -> (pattern rows, prefix index or -1)."""
    pat, pre = tile.copy(), -np.ones(len(tile), int)
    nnz = tile.sum(1)
    for i in range(len(tile)):
        if nnz[i] < 2:
            continue
        sub = np.all((tile & tile[i]) == tile, 1)
        sub &= ~(np.all(tile == tile[i], 1) & (np.arange(len(tile)) >= i))
        if not sub.any():
            continue
        idx = np.nonzero(sub)[0]
        j = idx[np.argmax(nnz[idx])]
        if nnz[j] < 1:
            continue
        pre[i], pat[i] = j, tile[i] ^ tile[j]
    return pat, pre


# ------------------------------------------------------------------------------------------- the example
T, K, P = 4, 4, 4
FILT = ["A", "B"]
W = np.array([[2, 0, 0, 1],            # filter A on k0..k3
              [0, 3, 1, 0]])           # filter B
ROWS = {(0, 0): "1100", (0, 1): "1110", (0, 2): "0000", (0, 3): "1100",
        (1, 0): "0000", (1, 1): "1100", (1, 2): "0001", (1, 3): "0000",
        (2, 0): "0010", (2, 1): "0000", (2, 2): "1110", (2, 3): "0000",
        (3, 0): "0000", (3, 1): "0001", (3, 2): "0000", (3, 3): "0011"}      # spikes of token p at t on k0..k3
PCOL = {0: "#3B6FD1", 1: "#D9822B", 2: "#4C9A5B", 3: "#8A55C2"}
bit = {(p, t, k): int(ROWS[p, t][k]) for p in range(P) for t in range(T) for k in range(K)}
dense = {(f, p, t): sum(W[f, k] * bit[p, t, k] for k in range(K)) for f in range(2) for p in range(P) for t in range(T)}
NBITS = sum(bit.values())

# ---- Prosperity: rows r = T*p + t (token-major, simulator.run_fc), one tile (16 rows x 4 inputs), n = 2 channels
order_pt = [(p, t) for p in range(P) for t in range(T)]
A = np.array([[int(c) for c in ROWS[pt]] for pt in order_pt], dtype=bool)
PAT, PRE = prosparsity(A)
NO = A.sum(1)
ISSUE = sorted([r for r in range(len(A)) if NO[r] > 0], key=lambda r: NO[r])          # stable sort, zero rows free
res, done, PSTEPS = {}, set(), {}
for r in ISSUE:
    assert PRE[r] < 0 or PRE[r] in done                                               # prefix already in the buffer
    acc = res[PRE[r]].copy() if PRE[r] >= 0 else np.zeros(2, int)
    for k in np.nonzero(PAT[r])[0]:
        acc = acc + W[:, k]                                                           # whole weight row, n channels
    PSTEPS[r] = int(PAT[r].sum()) or 1
    res[r] = acc
    done.add(r)
for r, (p, t) in enumerate(order_pt):
    got = res.get(r, np.zeros(2, int))
    assert all(got[f] == dense[f, p, t] for f in range(2)), (r, got)
P_STEPS = sum(PSTEPS.values())
P_PATBITS = int(PAT.sum())
P_EM = sum(1 for r in ISSUE if PAT[r].sum() == 0)
P_ADDS = P_PATBITS * 2
P_USEFUL = int(sum(np.count_nonzero(W[:, k]) for r in ISSUE for k in np.nonzero(PAT[r])[0]))

# ---- TIDES: one K-tile (R = 4 inputs), offline packing into one column, TIP groups of <= 4 tokens
S = np.zeros((K, P), np.uint8)
for (p, t, k), b in bit.items():
    S[k, p] |= b << t
COLS = pack_weights(W, 4)
assert COLS == [[0, 1]]                                   # A and B share one column (no row with both non-zero)
PE = {k: int(np.nonzero(W[:, k])[0][0]) for k in range(K)}                            # PE k holds filter PE[k]
GROUPS = sorted(pack_spikes(tile_masks(S, T), 4, 4))
assert GROUPS == [[0, 2, 3], [1]]
tsum = {}
TR = {}
for gi, mem in enumerate(GROUPS):
    for k in range(K):
        f = PE[k]
        lanes = []
        for t in range(T):
            who = [m for m, p in enumerate(mem) if bit[p, t, k]]
            assert len(who) <= 1                                                       # TIP: no clash
            if who:
                slot = 4 * f + who[0]
                tsum[gi, slot, t] = tsum.get((gi, slot, t), 0) + W[f, k]
                lanes.append((who[0], slot))
            else:
                lanes.append(None)
        TR[gi, k] = lanes
for (f, p, t), v in dense.items():
    gi = next(i for i, m in enumerate(GROUPS) if p in m) if any(p in m for m in GROUPS) else None
    got = tsum.get((gi, 4 * f + GROUPS[gi].index(p), t), 0) if gi is not None else 0
    assert got == v, (f, p, t, got, v)
T_STEPS = len(GROUPS) * len(COLS)
T_ADDS = sum(1 for v in TR.values() for x in v if x)
assert T_ADDS == NBITS                                     # every spike meets exactly one stored (non-zero) weight


# ------------------------------------------------------------------------------------------- the real layer
def real_layer():
    if os.path.exists(REAL_JSON):
        return {float(k): v for k, v in json.load(open(REAL_JSON)).items()}
    os.environ["LMC_REAL"] = "1"
    import lm_chain as L
    cache = json.load(open(L.CACHE))
    Tr, out = 8, {}
    for ws in (0.90, 0.99):
        Mo, Ki = 3072, 768
        Wr = L.pruned_weights("BERT", 0, "fc1", Mo, Ki, ws)
        Sr = np.load(os.path.join(L.SD, f"BERT_{ws:.2f}.npz"))["0_fc1"]
        N = Sr.shape[1]
        act = ((Sr[None] >> np.arange(Tr)[:, None, None]) & 1).astype(bool).transpose(2, 0, 1).reshape(N * Tr, Ki)
        patk, em = np.zeros(Ki, int), 0
        for m0 in range(0, len(act), 256):
            for k0 in range(0, Ki, 16):
                tl = act[m0:m0 + 256, k0:k0 + 16]
                pt, _ = prosparsity(tl)
                patk[k0:k0 + 16] += pt.sum(0)
                em += int(((pt.sum(1) == 0) & (tl.sum(1) > 0)).sum())
        nzk = (Wr != 0).sum(0)
        st = run_layer_fast(Wr, Sr, Cfg(T=Tr))
        plan = LayerPlan(Wr, Cfg(T=Tr))
        key = repr(("BERT", ws, 0, "fc1", Mo, Ki))
        out[ws] = dict(tokens=N, rows=N * Tr, bits=int(act.sum()), pattern_bits=int(patk.sum()), em=em,
                       ntiles=math.ceil(Mo / 128), steps=(int(patk.sum()) + em) * math.ceil(Mo / 128),
                       pros_cycles=cache[key]["prosperity"], pros_useful=int((patk * nzk).sum()),
                       nnz_w=int((Wr != 0).sum()), packed_cols=sum(len(c[0]) for c in plan.cols.values()),
                       ktiles=st["ktiles_run"], passes=st["passes"], group_steps=st["groups"],
                       ours_cycles=cache[key]["ours"], ours_useful=int((act.sum(0) * nzk).sum()),
                       nonsilent=int((Sr != 0).sum()), trains=int(Sr.size))
        assert st["cycles"] == cache[key]["ours"]
    json.dump(out, open(REAL_JSON, "w"), indent=1)
    return out


REAL = real_layer()


# ------------------------------------------------------------------------------------------- page helpers
def fb(f):
    return f'<span class="f{FILT[f]}">{FILT[f]}</span>'


def px(p):
    return f'<b style="color:{PCOL[p]}">p{p}</b>'


def bits_html(s, on="#222"):
    return "".join(f'<span class="b{c}">{c}</span>' for c in s)


def vec(v):
    return "[" + ",".join(str(int(x)) for x in v) + "]"


def n(x):
    return f"{x:,}"


def weight_table():
    head = "".join(f"<th>k{k}</th>" for k in range(K))
    rows = "".join(f"<tr><th>{fb(f)}</th>" + "".join(
        f'<td class="c mono{"" if W[f, k] else " z"}">{W[f, k]}</td>' for k in range(K)) + "</tr>" for f in range(2))
    return f"<table><tr><th>W</th>{head}</tr>{rows}</table>"


def train_table():
    head = "".join(f"<th>{px(p)}</th>" for p in range(P))
    rows = ""
    for k in range(K):
        cells = "".join(f'<td class="c mono">{bits_html("".join(str(bit[p, t, k]) for t in range(T)))}</td>'
                        for p in range(P))
        rows += f"<tr><th>k{k}</th>{cells}</tr>"
    return f"<table><tr><th>train t0..t3</th>{head}</tr>{rows}</table>"


def out_table():
    head = "".join(f"<th>{px(p)}</th>" for p in range(P))
    rows = "".join(f"<tr><th>{fb(f)}</th>" + "".join(
        f'<td class="mono c o{FILT[f]}">{vec([dense[f, p, t] for t in range(T)])}</td>' for p in range(P)) + "</tr>"
        for f in range(2))
    return f"<table><tr><th>out t0..t3</th>{head}</tr>{rows}</table>"


def pros_matrix():
    rows = ""
    for r, (p, t) in enumerate(order_pt):
        rows += (f'<tr{" class=zr" if NO[r] == 0 else ""}><td class=c>{r}</td><td>{px(p)} t{t}</td>'
                 f'<td class="c mono">{bits_html(ROWS[p, t])}</td></tr>')
    return f"<table><tr><th>row</th><th>(token, t)</th><th>k0 k1 k2 k3</th></tr>{rows}</table>"


def tides_matrix():
    head = "".join(f"<th>{px(p)}</th>" for p in range(P))
    rows = "".join(f"<tr><th>k{k}</th>" + "".join(
        f'<td class="c mono">{bits_html("".join(str(bit[p, t, k]) for t in range(T)))}</td>' for p in range(P))
        + "</tr>" for k in range(K))
    return f"<table><tr><th></th>{head}</tr>{rows}</table>"


def issue_table():
    kind = {}
    for r in ISSUE:
        if NO[r] < 2:
            kind[r] = "1 spike: not searched"
        elif PRE[r] < 0:
            kind[r] = "no subset row: computed fully"
        elif PAT[r].sum() == 0:
            kind[r] = f"<b>exact match</b> of row {PRE[r]}: copy"
        else:
            kind[r] = f"<b>partial match</b>: row {PRE[r]} + rest"
    body = ""
    for i, r in enumerate(ISSUE):
        p, t = order_pt[r]
        ks = [f"W[k{k}]" for k in np.nonzero(PAT[r])[0]]
        start = f"out[row {PRE[r]}]" if PRE[r] >= 0 else "0"
        op = " + ".join([start] + ks) if ks or PRE[r] >= 0 else start
        body += (f"<tr><td class=c>{i + 1}</td><td class=c>{r}</td><td>{px(p)} t{t}</td>"
                 f'<td class="c mono">{bits_html(ROWS[p, t])}</td><td class=c>{NO[r]}</td>'
                 f'<td class=c>{PRE[r] if PRE[r] >= 0 else "-"}</td>'
                 f'<td class="c mono">{bits_html("".join(str(int(x)) for x in PAT[r]))}</td>'
                 f"<td>{kind[r]}</td><td class=mono>{op}</td><td class=\"c mono\">{vec(res[r])}</td>"
                 f"<td class=c><b>{PSTEPS[r]}</b></td></tr>")
    return ("<table><tr><th>issue</th><th>row</th><th>(token, t)</th><th>spikes</th><th>ones</th><th>prefix</th>"
            "<th>pattern = row XOR prefix</th><th>what the Pruner found</th><th>Processor</th>"
            f"<th>[{fb(0)},{fb(1)}]</th><th>steps</th></tr>{body}"
            f"<tr><td colspan=10 style='text-align:right'><b>total (7 all-zero rows are free)</b></td>"
            f"<td class=c><b>{P_STEPS}</b></td></tr></table>")


def pe_column():
    cells = "".join(f'<tr><td class=c>PE k{k}</td><td class=c>{fb(PE[k])} (label {PE[k]})</td>'
                    f'<td class="c mono">{W[PE[k], k]}</td></tr>' for k in range(K))
    return f"<table><tr><th>column 0</th><th>filter</th><th>weight</th></tr>{cells}</table>"


def group_table(gi):
    mem = GROUPS[gi]
    head = "".join(f"<th>lane t{t}</th>" for t in range(T))
    rows = ""
    for k in range(K):
        f = PE[k]
        tds = ""
        for t in range(T):
            x = TR[gi, k][t]
            tds += ("<td class='c' style='color:#aaa'>-</td>" if x is None else
                    f"<td class=c>{px(mem[x[0]])} &rarr; slot {x[1]} <b>+{W[f, k]}</b></td>")
        rows += f"<tr><td>PE k{k} ({fb(f)}, {W[f, k]})</td>{tds}</tr>"
    names = ", ".join(f"m{m} = {px(p)}" for m, p in enumerate(mem))
    return (f"<div class=cap><b>Group g{gi + 1}</b> = {{{names}}}: one cycle through the column, all four lanes "
            f"(timesteps) of every PE at once</div><table><tr><th>PE</th>{head}</tr>{rows}</table>")


def toy_summary():
    rows = [("one step does", "1 spike bit &times; a whole weight row (all n output channels)",
             "1 packed group (&le; 4 tokens &times; all T timesteps) &times; the 4 inputs of the column"),
            ("adders used per step here", "n = 2 (one per output channel)", "4 PEs &times; T = 4 lanes = 16"),
            ("steps", f"<b>{P_STEPS}</b> ({P_PATBITS} remaining spike bits + {P_EM} exact-match copies)",
             f"<b>{T_STEPS}</b> ({len(GROUPS)} groups &times; {len(COLS)} pass)"),
            ("spike bits (of 17) not added again", f"{NBITS - P_PATBITS} (reused from prefix rows)", "0"),
            ("weight additions issued", f"{P_ADDS} ({P_PATBITS} bits &times; 2 channels)", f"{T_ADDS}"),
            ("of which with a non-zero weight", f"{P_USEFUL} (the other {P_ADDS - P_USEFUL} add 0)",
             f"{T_ADDS} (zero weights are not stored)")]
    body = "".join(f"<tr><td>{a}</td><td>{b}</td><td>{c}</td></tr>" for a, b, c in rows)
    return f"<table class=wide><tr><th></th><th>Prosperity</th><th>TIDES</th></tr>{body}</table>"


def real_table():
    a, b = REAL[0.90], REAL[0.99]
    r = lambda k: f"<td class=c>{n(a[k])}</td><td class=c>{n(b[k])}</td>"
    upc = lambda d, use, cyc: f"{d[use] / d[cyc]:.1f}"
    return f"""<table class=wide>
<tr><th colspan=2>BERT block 0, FC1 (768 &rarr; 3072), {a['tokens']} tokens, T = 8</th><th>90 % pruned</th><th>99 % pruned</th></tr>
<tr><td rowspan=6><b>Prosperity</b><br>256 &times; 16 tiles,<br>n = 128</td><td>spike bits ({a['rows']} rows &times; 768)</td>{r('bits')}</tr>
<tr><td>left after ProSparsity (+ exact-match rows)</td>
<td class=c>{n(a['pattern_bits'])} (+{a['em']})</td><td class=c>{n(b['pattern_bits'])} (+{b['em']})</td></tr>
<tr><td>&times; 3072 / 128 = {a['ntiles']} channel tiles &rarr; steps</td>{r('steps')}</tr>
<tr><td>cycles (official simulator)</td><td class=c><b>{n(a['pros_cycles'])}</b></td><td class=c><b>{n(b['pros_cycles'])}</b></td></tr>
<tr><td>additions with a non-zero weight</td>{r('pros_useful')}</tr>
<tr><td>useful additions per cycle (of 128 adders)</td><td class=c>{upc(a, 'pros_useful', 'pros_cycles')}</td><td class=c>{upc(b, 'pros_useful', 'pros_cycles')}</td></tr>
<tr><td rowspan=6><b>TIDES</b><br>4 &times; 4 PEs, T adders,<br>tiles 64 &times; 128</td><td>non-zero weights &rarr; packed columns</td>
<td class=c>{n(a['nnz_w'])} &rarr; {n(a['packed_cols'])}</td><td class=c>{n(b['nnz_w'])} &rarr; {n(b['packed_cols'])}</td></tr>
<tr><td>(64-filter block, 4-input K-tile) pairs run &rarr; passes</td>
<td class=c>{n(a['ktiles'])} &rarr; {n(a['passes'])}</td><td class=c>{n(b['ktiles'])} &rarr; {n(b['passes'])}</td></tr>
<tr><td>group steps (groups &times; passes)</td>{r('group_steps')}</tr>
<tr><td>cycles (cycle model)</td><td class=c><b>{n(a['ours_cycles'])}</b></td><td class=c><b>{n(b['ours_cycles'])}</b></td></tr>
<tr><td>additions with a non-zero weight (no reuse)</td>{r('ours_useful')}</tr>
<tr><td>useful additions per cycle (of 128 adders)</td><td class=c>{upc(a, 'ours_useful', 'ours_cycles')}</td><td class=c>{upc(b, 'ours_useful', 'ours_cycles')}</td></tr>
<tr><td colspan=2><b>TIDES speed vs Prosperity</b></td><td class=c><b>{a['pros_cycles'] / a['ours_cycles']:.2f}&times;</b></td>
<td class=c><b>{b['pros_cycles'] / b['ours_cycles']:.2f}&times;</b></td></tr></table>"""


a9, a99 = REAL[0.90], REAL[0.99]
HTML = f"""<!doctype html><html><head><meta charset="utf-8"><style>
@page {{ size: A4; margin: 10mm 13mm 9mm 13mm; }}
body {{ font-family: Helvetica, Arial, sans-serif; font-size: 9.1pt; color: #222; line-height: 1.27; }}
.hdr {{ font-size: 7.5pt; color: #777; border-bottom: 1px solid #ddd; padding-bottom: 3px; margin-bottom: 6px;
        display: flex; justify-content: space-between; }}
.sec {{ font-size: 11.5pt; margin: 8px 0 3px; }}
h1 {{ color: #1F5FAF; font-size: 14pt; margin: 3px 0 4px; }}
h2 {{ font-size: 9.6pt; margin: 7px 0 2px; }}
p {{ margin: 3px 0 5px; }}
ul {{ margin: 2px 0 5px 0; padding-left: 16px; }} li {{ margin: 1px 0; }}
table {{ border-collapse: collapse; margin: 2px 0 3px; font-size: 8.2pt; }}
table.wide {{ width: 100%; }}
th, td {{ border: 1px solid #d5dbe3; padding: 1.5px 5px; text-align: left; vertical-align: top; }}
th {{ background: #EEF2F7; }}
.c {{ text-align: center; }}
.mono {{ font-family: Menlo, Courier, monospace; }}
.z {{ color: #bbb; }}
.b1 {{ font-weight: bold; color: #111; }} .b0 {{ color: #bbb; }}
tr.zr td {{ color: #aaa; }}
.fA {{ color: #B03A2E; font-weight: bold; }} .fB {{ color: #2E7D8A; font-weight: bold; }}
.oA {{ background: #F6DEDA; }} .oB {{ background: #DCE8EB; }}
.row {{ display: flex; gap: 14px; align-items: flex-start; }}
.col {{ flex: 1; }}
.key {{ border-left: 4px solid #1F5FAF; background: #F3F7FD; padding: 4px 9px; margin: 6px 0 4px; }}
.cap {{ font-size: 8.2pt; color: #555; margin: 3px 0 2px; }}
.pb {{ break-before: page; }}
.tag {{ display: inline-block; background: #1F5FAF; color: white; border-radius: 3px; padding: 0 5px; font-size: 8pt;
        font-weight: bold; margin-right: 4px; }}
</style></head><body>
<div class=hdr><span>Prosperity and TIDES, traced on one example - internal working notes, {DATE}</span><span>1</span></div>
<h1>14. Prosperity vs TIDES on one example</h1>
<p>Both designs compute the same spiking GEMM: for every filter f, token p and timestep t,
<b>out[f][p][t] = &Sigma;<sub>k</sub> W[f][k] &middot; s[p][k][t]</b>, where s is a spike (0 or 1). The example below is
small enough to trace by hand: 2 filters, 4 inputs, 4 tokens, T = 4. Both traces are run in code and checked against
the GEMM.</p>

<h2 class=sec>14.1 The example</h2>
<div class=row>
<div><div class=cap style="white-space:nowrap">Weights (half are 0)</div>{weight_table()}</div>
<div><div class=cap>Spike train of token p on input k</div>{train_table()}</div>
<div><div class=cap>Output both designs must produce</div>{out_table()}</div></div>
<p>There are <b>{NBITS} spikes</b> in total. Every input row k has exactly one non-zero weight (A or B), so every
spike needs exactly one useful addition.</p>

<h2 class=sec>14.2 The same spikes, stored two ways</h2>
<div class=row>
<div class=col><p><span class=tag>Prosperity</span>a <b>bit matrix of (tokens &times; T) rows &times; K columns</b>.
One row = one token at one timestep, one bit per input. The row number is the label: row = T &middot; p + t (the
official simulator reshapes T &times; tokens &times; K to tokens &times; T &times; K). Nothing else is stored per row.</p>
{pros_matrix()}
<div class=cap>Real size: a tile is 256 rows (32 tokens &times; T = 8) &times; 16 inputs.</div></div>
<div class=col><p><span class=tag>TIDES</span>a <b>K &times; tokens matrix of T-bit trains</b>. One entry = all T
timesteps of one token on one input; the whole train is used in one cycle by the T adders of a PE.</p>
{tides_matrix()}
<div class=cap>Real size: an output tile is 64 filters &times; 128 tokens; a K-tile is 4 inputs (the 4 PE rows).</div>
<div class=key style="margin-top:10px"><b>First difference.</b> Prosperity treats each timestep as a separate row and
looks for <i>rows that repeat</i>. TIDES keeps the T timesteps of a token together and looks for <i>tokens whose
spikes do not collide</i>, so several tokens can share one trip through the array.</div></div></div>

<div class=pb></div>
<div class=hdr><span>Prosperity and TIDES, traced on one example - internal working notes, {DATE}</span><span>2</span></div>
<h2 class=sec>14.3 Prosperity: reuse the result of a subset row</h2>
<p>Prosperity's ProSparsity Processing Unit has four stages. All four run per 256 &times; 16 tile; here the tile is
the whole 16 &times; 4 matrix.</p>
<ul>
<li><b>Detector</b> (1 KB TCAM + popcounts): loads the tile into a TCAM, then for each row searches, in one cycle,
for every row whose spikes are a subset of it (the row's 1s are masked to "don't care"). It also counts the 1s.</li>
<li><b>Pruner</b>: keeps one <b>prefix</b> per row, the subset with the most 1s (an identical row only if it comes
earlier), and computes the <b>pattern = row XOR prefix</b>: the spikes still to be added. Rows with one spike are
not searched; reusing them would save nothing.</li>
<li><b>Dispatcher</b> (1.5 KB product-sparsity table: prefix + pattern per row): stable-sorts the rows by number of
1s, so every prefix is issued before the rows that reuse it.</li>
<li><b>Processor</b> (128 adders, one per output channel): for each issued row, loads the prefix's result from the
output buffer, then adds one whole <b>weight row W[k] (all n output channels)</b> per remaining spike, one spike per
cycle. An exact match costs one cycle (copy). All-zero rows cost nothing.</li></ul>
{issue_table()}
<div class=cap>W[k0] = [{fb(0)} 2, {fb(1)} 0], W[k1] = [0, 3], W[k2] = [0, 1], W[k3] = [1, 0]. Every result was checked
against the GEMM output in 14.1.</div>
<div class=key><b>What Prosperity saves:</b> {NBITS} spikes need only {P_STEPS} steps, because {NBITS - P_PATBITS}
spikes are covered by prefix rows (rows 3, 5 and 10 repeat earlier rows; rows 1 and 15 extend one).<br>
<b>What it cannot save:</b> each step adds a whole weight row. Here half of every row is 0, so {P_ADDS - P_USEFUL} of
its {P_ADDS} additions add 0. Pruning the weights does not remove a single step.</div>

<h2 class=sec>14.4 TIDES: pack non-zero weights offline, pack non-colliding tokens at run time</h2>
<div class=row>
<div class=col><p><b>Offline (filter packing).</b> A and B never have a non-zero weight on the same input, so they share
<b>one column</b>. PE k keeps only its one non-zero weight and that filter's label. The zero weights are never stored
or added.</p>{pe_column()}</div>
<div class=col><p><b>Run time (TIP, in the pre-processing unit).</b> Tokens are first-fit into groups of up to 4
such that, on every input, <b>at most one member spikes per timestep</b>. Token {px(1)} cannot join {px(0)}: both
spike on k0 at t1 (and on k1 at t1). {px(2)} and {px(3)} fit beside {px(0)}:</p>
<p style="margin-left:8px">g1 = {{{px(0)}, {px(2)}, {px(3)}}}, &nbsp; g2 = {{{px(1)}}}</p>
<p>Each lane t of a PE carries one bit plus the member label; the PE adds its weight to
<b>slot = 4 &middot; filter label + member label</b> (Section 13). The sums leave the column with no labels.</p></div></div>
{group_table(0)}
{group_table(1)}
<div class=pb></div>
<div class=hdr><span>Prosperity and TIDES, traced on one example - internal working notes, {DATE}</span><span>3</span></div>
<div class=key style="margin-top:0"><b>What TIDES saves:</b> the whole GEMM is <b>{T_STEPS} steps</b> (2 groups &times; 1 pass) instead of
{P_STEPS}. It never adds a zero weight, never spends a cycle on a silent token, and fills g1's lanes on k0, k1 and k2
completely (12 of 12 lanes).<br><b>What it cannot save:</b> it has no reuse between rows, so it performs all {T_ADDS}
additions. Rows 3, 5 and 10, which Prosperity copied, are added again.</div>

<h2 class=sec>14.5 The example side by side</h2>
{toy_summary()}

<h2 class=sec>14.6 The main difference</h2>
<table class=wide><tr><th></th><th>Prosperity</th><th>TIDES</th></tr>
<tr><td>sparsity it exploits</td><td>spikes (bit sparsity) + repeated or nested rows (product sparsity)</td>
<td>spikes + <b>weights</b> (both packed)</td></tr>
<tr><td>weights</td><td>dense: every step adds a whole 128-wide weight row, zeros included</td>
<td>only non-zeros are stored, loaded and added</td></tr>
<tr><td>timesteps</td><td>T separate rows per token, matched against each other</td><td>all T in one cycle (T adders per PE)</td></tr>
<tr><td>cycles &asymp;</td><td>(remaining spike bits + exact matches) &times; &lceil;N / 128&rceil;</td>
<td>&Sigma; over (filter block, K-tile) of groups &times; &lceil;packed columns / 4&rceil;</td></tr>
<tr><td>gets faster when</td><td>activations get sparser or more repetitive</td>
<td>activations get sparser <b>or weights get sparser</b></td></tr>
<tr><td>wastes cycles on</td><td>zero weights (pruning does not help)</td>
<td>groups with few spikes: a pass costs one cycle per group, even if it carries one spike</td></tr>
<tr><td>per-row labels</td><td>none (row number = T&middot;p + t); prefix + pattern per row in a 1.5 KB table</td>
<td>none on sums; filter label per weight, member label per spike bit</td></tr>
<tr><td>DRAM</td><td>dense 8-bit weights, re-read for every 256-row tile</td><td>packed non-zero weights only</td></tr></table>

<h2 class=sec>14.7 The same counts on a real layer</h2>
<p>BERT, real sentence, spikes chained from layer to layer (lm_chain.py, BN re-estimated). Both designs have 128
adders at 500 MHz.</p>
{real_table()}
<div class=key><b>Reading the table.</b> At 90 % pruning both designs keep about 12 of their 128 adders busy with
useful work, but Prosperity needs {a9['ours_useful'] / a9['pros_useful']:.2f}&times; fewer additions because of reuse,
so it is faster. Going to 99 % pruning, Prosperity's steps fall only because the spikes fall
({n(a9['bits'])} &rarr; {n(a99['bits'])} bits); its weight rows are now 99 % zeros, so only
{a99['pros_useful'] / a99['pros_cycles']:.1f} useful additions happen per cycle. TIDES's packed columns fall
{a9['packed_cols'] / a99['packed_cols']:.1f}&times; ({n(a9['packed_cols'])} &rarr; {n(a99['packed_cols'])}) and it
overtakes. In the whole-model BERT run the crossover is at about 97 % pruning (64 GB/s DRAM), and lower when DRAM is
slower, because Prosperity re-reads dense weights.</div>
</body></html>"""

if __name__ == "__main__":
    with tempfile.TemporaryDirectory() as d:
        src = os.path.join(d, "page.html")
        open(src, "w").write(HTML)
        subprocess.run([CHROME, "--headless", "--disable-gpu", "--no-pdf-header-footer", f"--print-to-pdf={OUT}",
                        "file://" + src], check=True, capture_output=True)
    print(OUT)
    print(f"Prosperity {P_STEPS} steps ({P_PATBITS} bits + {P_EM} EM), TIDES {T_STEPS} steps; real:",
          {k: (v['pros_cycles'], v['ours_cycles']) for k, v in REAL.items()})
