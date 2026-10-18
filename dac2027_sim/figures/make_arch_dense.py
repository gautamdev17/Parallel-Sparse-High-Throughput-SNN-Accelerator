"""
make_arch_dense.py -- dense, example-driven architecture figure (style of Prosperity's Fig. 5): four tinted panels,
(a) offline weight packing, (b) run-time pixel packing, (c) weight-stationary PE array with one PE zoomed in,
(d) edge unit, output buffer and LIF. Every bit and number is the worked example of
DAC2027_accelerator_explained_rows.pdf (3x3 input, filters A and B, output pixels p0..p3, T = 4).

  python3 make_arch_dense.py   -> arch_dense.drawio, arch_dense.pdf, arch_dense.png
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
FONT = "Helvetica"
BLUE, WHITE, INK = "#3A8EED", "#FFFFFF", "#1E1E1E"
GREEN, YELLOW = "#68BC36", "#FFC607"
PX = {0: "#3A8EED", 1: "#F39C12", 2: "#2EAD5B", 3: "#9B59B6"}          # pixel colours p0..p3
FL = {"A": "#E0505A", "B": "#1FA2B6"}                                     # filter colours
TINT = [("#FFF3EA", "#E3A27E"), ("#EAF2FB", "#86ABD9"), ("#F2F8EA", "#93BE69"), ("#F5F0FB", "#A98ED2")]
STEP = {"off": "#F26077", "pack": "#955ABD", "comp": "#F08A24", "out": "#D4A200"}

# ------------------------------------------------------------------ the example (rows k0..k3, bits t0..t3)
S = {(0, 0): "1000", (0, 1): "0000", (0, 2): "0100", (0, 3): "0011",
     (1, 0): "0000", (1, 1): "0010", (1, 2): "0011", (1, 3): "0000",
     (2, 0): "0100", (2, 1): "0011", (2, 2): "0000", (2, 3): "1000",
     (3, 0): "0011", (3, 1): "0000", (3, 2): "1000", (3, 3): "0100"}
W = {"A": [2, 0, 0, 1], "B": [0, 3, 1, 0]}
COLUMN = [(2, "A"), (3, "B"), (1, "B"), (1, "A")]
GROUPS = [[0, 1], [2, 3]]
SUMS = {("A", 0): [2, 0, 1, 1], ("A", 1): [0, 0, 0, 0], ("A", 2): [1, 2, 0, 0], ("A", 3): [0, 1, 2, 2],
        ("B", 0): [0, 1, 0, 0], ("B", 1): [0, 0, 4, 1], ("B", 2): [0, 0, 3, 3], ("B", 3): [1, 0, 0, 0]}
SPK = {("A", 0): "1000", ("A", 1): "0000", ("A", 2): "0100", ("A", 3): "0011",
       ("B", 0): "0000", ("B", 1): "0011", ("B", 2): "0011", ("B", 3): "0000"}

cells, _id = [], [10]


def nid():
    _id[0] += 1
    return f"c{_id[0]}"


def add(v, st, geo, vertex=True):
    i = nid()
    cells.append(f'<mxCell id="{i}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')
    return i


def box(x, y, w, h, label="", fill=WHITE, stroke=INK, fs=12, bold=False, fc=INK, sw=1.0, r=4, dashed=False,
        align="center", valign="middle"):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={fc};align={align};"
          f"verticalAlign={valign};spacing=1;{'fontStyle=1;' if bold else ''}{'dashed=1;dashPattern=5 3;' if dashed else ''}")
    return add(label, st, f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>')


def text(x, y, w, h, label, fs=12, bold=False, color=INK, align="center", italic=False, rot=0):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;fontStyle={(1 if bold else 0) + (2 if italic else 0)};rotation={rot};")
    return add(label, st, f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>')


def wire(pts, color=INK, sw=1.6, end="block", start="none", dashed=False):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow={end};startArrow={start};endFill=1;startFill=1;endSize=5;startSize=5;html=1;rounded=0;"
          f"strokeColor={color};strokeWidth={sw};{'dashed=1;dashPattern=4 3;' if dashed else ''}")
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>'
                f'{("<Array as=" + chr(34) + "points" + chr(34) + ">" + mid + "</Array>") if mid else ""}'
                f'</mxGeometry>', vertex=False)


def step(x, y, n, label, phase, color=INK, w=220):
    add(str(n), f"ellipse;html=1;fillColor={STEP[phase]};strokeColor=none;fontColor=#FFFFFF;fontFamily={FONT};"
                f"fontSize=11;fontStyle=1;", f'<mxGeometry x="{x}" y="{y}" width="18" height="18" as="geometry"/>')
    if label:
        text(x + 22, y - 1, w, 20, label, fs=13, color=color, align="left")


def bits(x, y, s, owner=None, cw=16, ch=18, fs=11, base=None):
    """a row of bit cells; a '1' is filled with its owner's colour (pixel colour), '0' white"""
    for t, b in enumerate(s):
        o = owner[t] if owner else None
        if b == "1":
            fill = PX[o] if o is not None else (base or BLUE)
            box(x + t * cw, y, cw, ch, "1", fill=fill, stroke=INK, fs=fs, fc=WHITE, bold=True, sw=0.8, r=0)
        else:
            box(x + t * cw, y, cw, ch, "0", fill=WHITE, stroke=INK, fs=fs, fc="#888888", sw=0.8, r=0)


def panel(x, w, i, title, sub):
    f, s = TINT[i]
    box(x, 8, w, 552, "", fill=f, stroke=s, sw=1.4, r=10, dashed=True)
    text(x, 12, w, 26, f"<b>{title}</b> <span style='font-size:13px;color:#555555'>{sub}</span>", fs=19)


# =============================================================================================== (a) weight packer
AX = 8
panel(AX, 336, 0, "(a) Weight Packer", "offline")
box(AX + 18, 48, 300, 26, "Filter Weights W", fill=BLUE, stroke=BLUE, fs=14, bold=True, fc=WHITE, r=0)
for j, f in enumerate("AB"):
    box(AX + 66 + j * 40, 82, 40, 22, f, fill=FL[f], stroke=INK, fs=13, bold=True, fc=WHITE, r=0, sw=0.8)
for k in range(4):
    y = 104 + k * 26
    text(AX + 26, y, 36, 26, f"k{k}", fs=14)
    for j, f in enumerate("AB"):
        v = W[f][k]
        box(AX + 66 + j * 40, y, 40, 26, str(v), fill="#FBE1E3" if (v and f == "A") else ("#D9F1F4" if v else WHITE),
            stroke=INK, fs=14, bold=bool(v), fc=INK if v else "#AAAAAA", sw=0.8, r=0)
# row-occupancy masks and the AND check
text(AX + 162, 82, 120, 22, "row masks", fs=12, color="#444444")
for j, f in enumerate("AB"):
    for k in range(4):
        b = "1" if W[f][k] else "0"
        box(AX + 170 + j * 30, 104 + k * 26, 30, 26, b, fill=FL[f] if b == "1" else WHITE, stroke=INK, fs=13,
            fc=WHITE if b == "1" else "#AAAAAA", bold=b == "1", sw=0.8, r=0)
text(AX + 230, 104, 36, 104, "∧", fs=22, bold=True)
for k in range(4):
    box(AX + 266, 104 + k * 26, 30, 26, "0", fill=WHITE, stroke=INK, fs=13, fc="#AAAAAA", sw=0.8, r=0)
step(AX + 26, 216, 0, "No row used twice → share", "off", color="#B03050")
# packed column
box(AX + 18, 252, 300, 26, "Packed Column  (weight | filter label)", fill=GREEN, stroke=GREEN, fs=14, bold=True,
    fc=WHITE, r=0)
for k, (w, f) in enumerate(COLUMN):
    y = 286 + k * 30
    text(AX + 26, y, 36, 30, f"k{k}", fs=14)
    box(AX + 66, y + 2, 70, 26, str(w), fill=WHITE, stroke=INK, fs=15, bold=True, sw=0.8, r=0)
    box(AX + 136, y + 2, 50, 26, f, fill=FL[f], stroke=INK, fs=14, bold=True, fc=WHITE, sw=0.8, r=0)
text(AX + 196, 286, 130, 120, "8 PEs → 4 PEs:<br>every PE holds a<br>real weight<br><br>≤ F = 4 filters<br>per column",
     fs=12, color="#444444", align="left")
box(AX + 18, 418, 300, 26, "Weight Memory", fill=GREEN, stroke=GREEN, fs=14, bold=True, fc=WHITE, r=0)
text(AX + 18, 446, 300, 40, "packed offline, per (filter block, K-tile)<br>column = 4 × (8-b weight + 2-b label) + ids",
     fs=12, color="#444444")
wire([(AX + 168, 404), (AX + 168, 418)], color=GREEN, sw=2)
step(AX + 26, 500, 4, "Load weights → PEs", "comp")

# =============================================================================================== (b) pixel packer
BX = 352
panel(BX, 420, 1, "(b) Pixel Packer", "run time")
box(BX + 16, 48, 388, 26, "Spike Buffer  S[k][p]  (T = 4 bits t0..t3)", fill=BLUE, stroke=BLUE, fs=14, bold=True,
    fc=WHITE, r=0)
GX = BX + 56
for p in range(4):
    box(GX + p * 86, 80, 66, 20, f"p{p}", fill=PX[p], stroke=INK, fs=13, bold=True, fc=WHITE, r=0, sw=0.8)
for k in range(4):
    text(BX + 18, 104 + k * 24, 36, 20, f"k{k}", fs=14)
    for p in range(4):
        bits(GX + p * 86 + 1, 104 + k * 24, S[k, p], owner=[p] * 4, cw=16, ch=20)
step(BX + 18, 206, 1, "Read a K-tile", "pack")
# first-fit check
box(BX + 16, 232, 388, 26, "First-Fit  (≤ 4 open groups, ≤ G = 4 pixels)", fill=BLUE, stroke=BLUE, fs=14,
    bold=True, fc=WHITE, r=0)
rows = [("p1", "G1 = {p0}", "∧ = 0", "join G1", "#2E8B57"),
        ("p2", "G1 = {p0,p1}", "≠ 0 @ (k1,t2)", "open G2", "#C0392B"),
        ("p3", "G2 = {p2}", "∧ = 0", "join G2", "#2E8B57")]
for i, (p, g, r, a, col) in enumerate(rows):
    y = 264 + i * 26
    box(BX + 16, y, 44, 24, p, fill=PX[int(p[1])], stroke=INK, fs=13, bold=True, fc=WHITE, r=0, sw=0.8)
    box(BX + 60, y, 112, 24, g, fill=WHITE, stroke=INK, fs=12, r=0, sw=0.8)
    box(BX + 172, y, 128, 24, r, fill=WHITE, stroke=INK, fs=12, fc=col, bold=True, r=0, sw=0.8)
    box(BX + 300, y, 104, 24, a, fill="#E8F5E9" if col == "#2E8B57" else "#FDECEA", stroke=INK, fs=12, bold=True,
        fc=col, r=0, sw=0.8)
step(BX + 18, 346, 2, "Check: no shared (row, t) bit", "pack")
# group buffer: merged bits coloured by the pixel that owns them = the pixel labels
box(BX + 16, 372, 388, 26, "Group Buffer  (merged bits + 2-b pixel labels)", fill=GREEN, stroke=GREEN, fs=14,
    bold=True, fc=WHITE, r=0)
for gi, grp in enumerate(GROUPS):
    x0 = BX + 50 + gi * 190
    text(x0 - 34, 404, 160, 20, f"G{gi + 1} = " + " + ".join(f"p{p}" for p in grp), fs=13, bold=True)
    for k in range(4):
        own, s = [None] * 4, ["0"] * 4
        for p in grp:
            for t, b in enumerate(S[k, p]):
                if b == "1":
                    s[t], own[t] = "1", p
        text(x0 - 30, 426 + k * 22, 26, 20, f"k{k}", fs=12)
        bits(x0, 426 + k * 22, "".join(s), owner=own, cw=20, ch=20)
step(BX + 18, 524, 3, "Merge: 4 pixels → 2 groups", "pack")
text(BX + 250, 520, 160, 26, "8 lanes, one K-tile each", fs=12, color="#444444")

# =============================================================================================== (c) PE array
CX = 780
panel(CX, 452, 2, "(c) Weight-Stationary PE Array", "")
PY = 70
for k, (w, f) in enumerate(COLUMN):
    y = PY + k * 74
    own, s = [None] * 4, ["0"] * 4
    for p in GROUPS[0]:
        for t, b in enumerate(S[k, p]):
            if b == "1":
                s[t], own[t] = "1", p
    bits(CX + 14, y + 18, "".join(s), owner=own, cw=14, ch=18, fs=10)
    wire([(CX + 72, y + 27), (CX + 92, y + 27)], color=BLUE, sw=1.8)
    hl = k == 2
    box(CX + 92, y, 92, 54, f"<b>PE k{k}</b><br><span style='font-size:13px'>{w} | {f}</span>", fill=BLUE,
        stroke=INK if hl else BLUE, sw=2.4 if hl else 1, fs=14, fc=WHITE, r=4)
    if k < 3:
        wire([(CX + 138, y + 54), (CX + 138, y + 74)], color="#F08A24", sw=2.2)
wire([(CX + 138, PY + 3 * 74 + 54), (CX + 138, PY + 3 * 74 + 80)], color="#F08A24", sw=2.2)
text(CX + 14, PY + 3 * 74 + 58, 120, 22, "sums → edge ↓", fs=12, color="#C06010", align="right")
step(CX + 14, PY - 26, 5, "Stream G1 into the rows", "comp")
# zoom of PE k2
ZX, ZY = CX + 214, 120
wire([(CX + 184, PY + 2 * 74), (ZX, ZY)], color="#888888", sw=1, dashed=True, end="none")
wire([(CX + 184, PY + 2 * 74 + 54), (ZX, ZY + 300)], color="#888888", sw=1, dashed=True, end="none")
box(ZX, ZY, 226, 300, "", fill=WHITE, stroke=INK, sw=1.2, r=6)
text(ZX + 6, ZY + 4, 214, 20, "PE k2 · weight 1 | B · G1 arrives", fs=13, bold=True)
own2 = [None, 0, 1, 1]
bits(ZX + 40, ZY + 32, "0111", owner=own2, cw=36, ch=22, fs=12)
for t, o in enumerate(own2):
    text(ZX + 40 + t * 36, ZY + 54, 36, 16, "–" if o is None else f"p{o}", fs=11, color=PX[o] if o is not None else "#999999",
         bold=o is not None)
    add("+", f"ellipse;html=1;fillColor={'#FFE7C2' if o is not None else WHITE};strokeColor=#F08A24;strokeWidth=1.4;"
             f"fontFamily={FONT};fontSize=15;fontStyle=1;", f'<mxGeometry x="{ZX + 47 + t * 36}" y="{ZY + 74}" width="22" '
                                                            f'height="22" as="geometry"/>')
    text(ZX + 40 + t * 36, ZY + 96, 36, 14, f"t{t}", fs=10, color="#666666")
text(ZX + 4, ZY + 74, 36, 22, "w=1", fs=11, bold=True)
step(ZX + 196, ZY + 76, 6, "", "comp")
text(ZX + 6, ZY + 112, 214, 18, "running sums (filter, pixel) × t", fs=11, color="#444444")
before = {("A", 0): [2, 0, 0, 0], ("A", 1): [0, 0, 0, 0], ("B", 0): [0, 0, 0, 0], ("B", 1): [0, 0, 3, 0]}
after = {("A", 0): [2, 0, 0, 0], ("A", 1): [0, 0, 0, 0], ("B", 0): [0, 1, 0, 0], ("B", 1): [0, 0, 4, 1]}
for i, key in enumerate([("A", 0), ("A", 1), ("B", 0), ("B", 1)]):
    y = ZY + 134 + i * 24
    f, p = key
    box(ZX + 6, y, 56, 22, f"{f},p{p}", fill=FL[f], stroke=INK, fs=11, bold=True, fc=WHITE, r=0, sw=0.8)
    for t in range(4):
        ch = after[key][t] != before[key][t]
        box(ZX + 62 + t * 36, y, 36, 22, str(after[key][t]), fill="#FFE27A" if ch else WHITE, stroke=INK, fs=12,
            bold=ch, r=0, sw=0.8)
text(ZX + 6, ZY + 234, 214, 62, "adder t adds w if bit t = 1; the filter<br>label (B) and the bit's pixel label<br>"
     "pick the sum — no search, no compare", fs=11, color="#444444")
text(CX + 14, 428, 430, 60, "4 × 4 PEs, T adders per PE: all timesteps of a train in one cycle.<br>"
     "Spikes move right, running sums move down; weights stay<br>(shadow registers load the next pass meanwhile).",
     fs=12, color="#444444", align="left")

# =============================================================================================== (d) edge + LIF
DX = 1240
panel(DX, 352, 3, "(d) Edge Unit & LIF", "")
box(DX + 16, 48, 320, 26, "Edge FIFO  (touched sums only)", fill=BLUE, stroke=BLUE, fs=14, bold=True, fc=WHITE, r=0)
for i, (key, v) in enumerate([(("B", 1), [0, 0, 4, 1]), (("B", 0), [0, 1, 0, 0]), (("A", 0), [2, 0, 1, 1])]):
    y = 82 + i * 24
    f, p = key
    box(DX + 16, y, 64, 22, f"({f},p{p})", fill=FL[f], stroke=INK, fs=11, bold=True, fc=WHITE, r=0, sw=0.8)
    for t in range(4):
        box(DX + 80 + t * 30, y, 30, 22, str(v[t]), fill=WHITE, stroke=INK, fs=12, r=0, sw=0.8)
box(DX + 220, 82, 116, 70, "<b>Addr</b><br>(filter, pixel)<br>4 RMW / col", fill=WHITE, stroke=INK, fs=12, r=4)
wire([(DX + 200, 117), (DX + 220, 117)])
step(DX + 16, 160, 7, "Enqueue", "out", w=80)
step(DX + 120, 160, 8, "RMW (+=)", "out", w=100)
wire([(DX + 278, 152), (DX + 278, 186)], sw=1.8)
box(DX + 16, 186, 320, 26, "Output Buffer  (sums across K-tiles)", fill=YELLOW, stroke=YELLOW, fs=14, bold=True,
    fc=INK, r=0)
for p in range(4):
    box(DX + 56 + p * 70, 216, 70, 20, f"p{p}", fill=PX[p], stroke=INK, fs=12, bold=True, fc=WHITE, r=0, sw=0.8)
for i, f in enumerate("AB"):
    y = 236 + i * 26
    box(DX + 16, y, 40, 26, f, fill=FL[f], stroke=INK, fs=13, bold=True, fc=WHITE, r=0, sw=0.8)
    for p in range(4):
        box(DX + 56 + p * 70, y, 70, 26, " ".join(map(str, SUMS[f, p])), fill="#FFF6D6", stroke=INK, fs=12, r=0,
            sw=0.8)
wire([(DX + 176, 288), (DX + 176, 314)], sw=1.8)
box(DX + 16, 314, 320, 26, "LIF Units ×16  (after the last K-tile)", fill=GREEN, stroke=GREEN, fs=14, bold=True,
    fc=WHITE, r=0)
text(DX + 16, 342, 320, 22, "V ← V/2 + I<sub>t</sub>;  spike if V ≥ θ, then V −= θ", fs=12)
step(DX + 16, 368, 9, "Fire → next layer's spike trains", "out")
for p in range(4):
    box(DX + 56 + p * 70, 392, 70, 20, f"p{p}", fill=PX[p], stroke=INK, fs=12, bold=True, fc=WHITE, r=0, sw=0.8)
for i, f in enumerate("AB"):
    y = 412 + i * 26
    box(DX + 16, y, 40, 26, f, fill=FL[f], stroke=INK, fs=13, bold=True, fc=WHITE, r=0, sw=0.8)
    for p in range(4):
        bits(DX + 59 + p * 70, y + 3, SPK[f, p], cw=16, ch=20, fs=10, base="#333333")
text(DX + 16, 474, 320, 60, "Exactly the dense GEMM + LIF result:<br>packing is lossless; labels route every add.",
     fs=12, color="#444444")

xml = ('<mxfile host="drawio"><diagram id="dense" name="architecture"><mxGraphModel grid="0" page="0" '
       'pageWidth="1600" pageHeight="570" math="0" shadow="0"><root><mxCell id="0"/><mxCell id="1" parent="0"/>' +
       "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
src = os.path.join(HERE, "arch_dense.drawio")
open(src, "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "4", "-o", os.path.join(HERE, "arch_dense.pdf"), src],
               check=True, capture_output=True)
subprocess.run([app, "-x", "-f", "png", "-s", "2.5", "-b", "6", "-o", os.path.join(HERE, "arch_dense.png"), src],
               check=True, capture_output=True)
print("ok")
