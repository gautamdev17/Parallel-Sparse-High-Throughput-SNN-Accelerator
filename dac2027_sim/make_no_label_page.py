"""make_no_label_page.py -- one A4 page, in the style of DAC2027_accelerator_explained_rows.pdf: why the running sums
that leave a column carry no (filter, pixel) labels. Same example as Fig. 9-12 of that document (filters A, B; pixels
p0..p3; groups G1 = {p0, p1}, G2 = {p2, p3}). Every number is computed below with the PE rule of
hw/rtl/ours/ours_core.v (slot = {filter label, member label}) and asserted against the dense GEMM.

  python3 make_no_label_page.py          -> ../TIDES_no_psum_labels.pdf (HTML rendered by headless Chrome)
  python3 make_no_label_page.py append   -> also appends it to ../DAC2027_accelerator_explained_rows.pdf as Section 13
                                             (page 12; run once on the 11-page notes)
"""
import os, subprocess, sys, tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
OUT = os.path.join(ROOT, "TIDES_no_psum_labels.pdf")                      # the page alone
DOC = os.path.join(ROOT, "DAC2027_accelerator_explained_rows.pdf")             # the notes it is appended to
JOIN = "/System/Library/Automator/Combine PDF Pages.action/Contents/MacOS/join"
CHROME = "/Applications/Google Chrome.app/Contents/MacOS/Google Chrome"
DATE = "15 Oct 2026"

# ------------------------------------------------------------------------------------------- the example
T, K = 4, 4
FILT = ["A", "B"]                                   # filter label 0, 1 (one packed column)
W = {"A": [2, 0, 0, 1], "B": [0, 3, 1, 0]}          # weight of each filter on k0..k3
S = {                                               # spike train of pixel p on input k, t0..t3
    "p0": ["1000", "0000", "0100", "0011"],
    "p1": ["0000", "0010", "0011", "0000"],
    "p2": ["0100", "0011", "0000", "1000"],
    "p3": ["0011", "0000", "1000", "0100"],
}
GROUPS = {"G1": ["p0", "p1"], "G2": ["p2", "p3"]}
F, G = len(FILT), 2
PCOL = {"p0": "#3B6FD1", "p1": "#D9822B", "p2": "#4C9A5B", "p3": "#8A55C2"}

# dense GEMM: out[f][p][t] = sum_k W[f][k] * s[p][k][t]
dense = {f: {p: [sum(W[f][k] * int(S[p][k][t]) for k in range(K)) for t in range(T)] for p in S} for f in FILT}


def run_group(members):
    """the column: PE k holds the non-zero weight of one filter (filter label); the group's packed train on row k has
    one bit per timestep, labelled with its member. Bundle = F*G slots x T sums, slot = F-label * G + member label."""
    pes = [(k, f) for k in range(K) for f in FILT if W[f][k] != 0]            # packed column: one weight per row
    assert sorted(k for k, _ in pes) == list(range(K))
    bundle = [[0] * T for _ in range(F * G)]
    touch = [0] * (F * G)
    trace = {}
    for k, f in pes:
        bits, labs = [], []
        for t in range(T):
            who = [m for m, p in enumerate(members) if S[p][k][t] == "1"]
            assert len(who) <= 1                                               # Eq. (tip): no clash
            bits.append(1 if who else 0)
            labs.append(who[0] if who else None)
        lanes = []
        for t in range(T):
            if bits[t]:
                slot = FILT.index(f) * G + labs[t]                             # {filter label, member label}
                bundle[slot][t] += W[f][k]
                touch[slot] = 1
                lanes.append(slot)
            else:
                lanes.append(None)
        trace[k] = dict(f=f, w=W[f][k], bits="".join(map(str, bits)), labs=labs, lanes=lanes)
    return bundle, touch, trace


RES = {g: run_group(m) for g, m in GROUPS.items()}
out = {f: {p: [0] * T for p in S} for f in FILT}
for g, members in GROUPS.items():
    bundle, touch, _ = RES[g]
    for e in range(F * G):
        if touch[e]:
            out[FILT[e // G]][members[e % G]] = bundle[e]
assert out == dense, (out, dense)                                              # lossless, no labels on the sums


# ------------------------------------------------------------------------------------------- the page
def vec(v):
    return "[" + ",".join(map(str, v)) + "]"


def fbox(f, inner):
    return f'<span class="f{f}">{inner}</span>'


def pix(p):
    return f'<b style="color:{PCOL[p]}">{p}</b>'


def slot_table():
    rows = "".join(f"<tr><td class=c><b>{e}</b></td><td class=c>{e // G} ({fbox(FILT[e // G], FILT[e // G])})</td>"
                   f"<td class=c>{e % G}</td><td>{pix(GROUPS['G1'][e % G])}</td><td>{pix(GROUPS['G2'][e % G])}</td></tr>"
                   for e in range(F * G))
    return ("<table><tr><th>slot e</th><th>filter label = e / 2</th><th>member label = e % 2</th>"
            "<th>member in G1</th><th>member in G2</th></tr>" + rows + "</table>")


def pe_table():
    tr = RES["G1"][2][2]                                                       # PE k2, group G1 (Fig. 10)
    head = "".join(f"<th>lane t{t}</th>" for t in range(T))
    bits = "".join(f"<td class=c>{tr['bits'][t]}</td>" for t in range(T))
    labs = "".join(f"<td class=c>{'-' if l is None else l} {'' if l is None else '(' + pix(GROUPS['G1'][l]) + ')'}</td>"
                   for l in tr["labs"])
    lanes = "".join("<td class=c style='color:#999'>no spike</td>" if s is None else
                    f"<td class=c>2&middot;1 + {s % G} = <b>{s}</b> &rarr; +{tr['w']}</td>" for s in tr["lanes"])
    return (f"<table><tr><th>PE k2: weight {tr['w']}, filter label 1 ({fbox('B', 'B')})</th>{head}</tr>"
            f"<tr><td>spike bit of G1</td>{bits}</tr><tr><td>member label</td>{labs}</tr>"
            f"<tr><td>slot = 2 &middot; filter label + member label</td>{lanes}</tr></table>")


def bundle_block(g):
    bundle, touch, _ = RES[g]
    cells = "".join(f'<div class="slot {"" if touch[e] else "idle"}"><span class=sn>slot {e}</span>'
                    f'<span class=sv>{vec(bundle[e])}</span><span class=tb>touch {touch[e]}</span></div>'
                    for e in range(F * G))
    mem = ", ".join(pix(p) for p in GROUPS[g])
    return (f'<div class="bun"><div class=bt>{g} leaves the column</div>{cells}'
            f'<div class=side>sideband (once per group): members [{mem}]<br>column filter list [{fbox("A", "A")}, '
            f'{fbox("B", "B")}] (fixed for the pass)</div></div>')


def decode_table(g):
    members = GROUPS[g]
    bundle, touch, _ = RES[g]
    rows = []
    for e in range(F * G):
        f, p = FILT[e // G], members[e % G]
        act = f"output[{fbox(f, f)}][{pix(p)}]" if touch[e] else "<span style='color:#999'>skip (touch 0)</span>"
        rows.append(f"<tr><td class=c>{e}</td><td class=mono>{vec(bundle[e])}</td>"
                    f"<td class=c>{fbox(f, f)}</td><td class=c>{pix(p)}</td><td>{act}</td></tr>")
    return (f"<table><tr><th>{g} slot</th><th>bare sums</th><th>list[e/2]</th>"
            "<th>members[e%2]</th><th>write to</th></tr>" + "".join(rows) + "</table>")


def out_table():
    head = "".join(f"<th>{pix(p)}</th>" for p in S)
    rows = "".join(f"<tr><th>{fbox(f, f)}</th>" + "".join(
        f'<td class="mono c o{f}">{vec(out[f][p])}</td>' for p in S) + "</tr>" for f in FILT)
    return f"<table class=outt><tr><th></th>{head}</tr>{rows}</table>"


HTML = f"""<!doctype html><html><head><meta charset="utf-8"><style>
@page {{ size: A4; margin: 10mm 13mm 9mm 13mm; }}
body {{ font-family: Helvetica, Arial, sans-serif; font-size: 9.1pt; color: #222; line-height: 1.27; }}
.hdr {{ font-size: 7.5pt; color: #777; border-bottom: 1px solid #ddd; padding-bottom: 3px; margin-bottom: 6px;
        display: flex; justify-content: space-between; }}
.sec {{ font-size: 11.5pt; margin: 2px 0 3px; }}
h1 {{ color: #1F5FAF; font-size: 14pt; margin: 3px 0 4px; }}
h2 {{ font-size: 9.6pt; margin: 6px 0 2px; }}
p {{ margin: 3px 0 5px; }}
table {{ border-collapse: collapse; margin: 2px 0 3px; font-size: 8.2pt; }}
th, td {{ border: 1px solid #d5dbe3; padding: 1.5px 5px; text-align: left; }}
th {{ background: #EEF2F7; }}
.c {{ text-align: center; }}
.mono {{ font-family: Menlo, Courier, monospace; }}
.fA {{ color: #B03A2E; font-weight: bold; }} .fB {{ color: #2E7D8A; font-weight: bold; }}
.oA {{ background: #F6DEDA; }} .oB {{ background: #DCE8EB; }}
.row {{ display: flex; gap: 14px; align-items: flex-start; }}
.bun {{ border: 1px solid #c9d1db; border-radius: 4px; padding: 5px 7px; width: 47%; }}
.bt {{ font-weight: bold; margin-bottom: 4px; }}
.slot {{ display: flex; justify-content: space-between; border: 1px solid #888; background: #FFF6DA;
        padding: 1px 6px; margin: 2px 0; font-family: Menlo, Courier, monospace; font-size: 8.1pt; }}
.slot.idle {{ background: #fafafa; color: #999; border-color: #ccc; }}
.sn {{ width: 48px; }} .tb {{ color: #666; }}
.side {{ margin-top: 4px; font-size: 8.2pt; color: #333; background: #F2F4F7; padding: 3px 5px; border-radius: 3px; }}
.key {{ border-left: 4px solid #1F5FAF; background: #F3F7FD; padding: 4px 9px; margin: 6px 0 4px; }}
.cap {{ font-size: 8.2pt; color: #666; margin: 1px 0 4px; }}
</style></head><body>
<div class=hdr><span>Our accelerator, explained from scratch (spike trains stream along rows) - internal working notes, {DATE}</span><span>12</span></div>
<h1>13. Optimizations</h1>
<h2 class=sec>13.1 The running sums carry no labels</h2>
<p>Section 6 wrote every running sum as "(A, p0) [2,0,1,1]". The pair (A, p0) is correct, but it is <b>not stored</b>
next to the sum. The labels are needed only inside the PE, to choose <i>which</i> running sum to add to. After that,
the place of the sum in the bundle already says whose it is.</p>

<h2>(a) The bundle is a row of numbered slots</h2>
<p>A group carries F &times; G = 2 &times; 2 = 4 running sums down the column, always in the same order:
<b>slot = 2 &middot; filter label + member label</b>. The member label is local to the group: member 0 of G1 is p0,
member 0 of G2 is p2.</p>
{slot_table()}

<h2>(b) Inside the PE, the two labels pick the slot</h2>
<p>The PE computes the slot number from its own filter label and the label on each spike bit; it reads that slot,
adds its weight, and writes it back. Nothing is searched: the number is known the moment the bits arrive.</p>
{pe_table()}
<div class=cap>Same cycle as Figure 10: +1 to slot 2 (B, p0) at t1 and to slot 3 (B, p1) at t2 and t3.</div>

<h2>(c) What leaves the bottom: bare sums, one touch bit each, and one small sideband per group</h2>
<div class=row>{bundle_block("G1")}{bundle_block("G2")}</div>

<h2>(d) The unit below the array turns slot numbers back into (filter, pixel)</h2>
<p>For slot e: filter = filter list[e / 2], pixel = members[e % 2]. Since e is fixed for every slot, this is plain
wiring, not arithmetic (in the RTL: <span class=mono>{{fid[e / G], pid[e % G], sums}}</span>).</p>
<div class=row style="gap:10px">{decode_table("G1")}{decode_table("G2")}</div>
<div class=row style="align-items:center; gap:18px"><div>{out_table()}</div>
<div class=cap style="max-width:52%">Output after both groups: identical to the GEMM (checked for every entry). Slot 1
of G1, (A, p1), was never touched, so nothing is written and output[A][p1] stays [0,0,0,0].</div></div>

<div class=key><b>Rule.</b> A label is needed to <i>choose</i> a place; once a value sits in a fixed place, the place
is its label. The weights and the spike bits carry labels because a PE cannot tell their filter or pixel from where
they are. The running sums sit in fixed slots, so they carry none; the only extra data is the group's member list,
sent once per group beside the column.</div>

<h2>(e) What this saves in the real design (4 &times; 4 array, 16 slots of T = 8 sums)</h2>
<table><tr><th></th><th>flip-flops</th><th>where</th></tr>
<tr><td><b>Fixed slots + ID sideband (ours)</b></td><td class=c><b>1,144</b></td>
<td>one 52-bit ID record per group, delayed R + c cycles beside each column (4 + 5 + 6 + 7 stages)</td></tr>
<tr><td>13-bit (filter, pixel) address stored on every slot</td><td class=c>3,328</td>
<td>16 slots &times; 13 b in the bundle register of each of the 16 PEs</td></tr></table>
<div class=cap>Flip-flop counts from the RTL widths; about 2.9&times; fewer, and no comparator in any PE.</div>
</body></html>"""

with tempfile.TemporaryDirectory() as d:
    src = os.path.join(d, "page.html")
    open(src, "w").write(HTML)
    subprocess.run([CHROME, "--headless", "--disable-gpu", "--no-pdf-header-footer", f"--print-to-pdf={OUT}",
                    "file://" + src], check=True, capture_output=True)
print(OUT)

if len(sys.argv) > 1 and sys.argv[1] == "append":
    with tempfile.TemporaryDirectory() as d:
        tmp = os.path.join(d, "joined.pdf")
        subprocess.run([JOIN, "-o", tmp, DOC, OUT], check=True, capture_output=True)
        os.replace(tmp, DOC)
    print(DOC)
