"""
make_arch_tides_hw.py -- TIDES hardware figure in the visual style of the paper's Fig. 3 (Figures/Compression.png):
white panels with thin black frames, the P0..P3 colours of Fig. 3 (sampled: #7EA6E1, #FFD966, #96D076, #A680B8),
red / blue dashed boxes for groups G1 / G2, grey block arrows, Verdana, bold captions under the panels, and a
legend box at the bottom. Every value is the running example of Fig. 1(b) / Fig. 3 (K0..K3, P0..P3, T = 4, filters
A = [2, 0, 0, 1], B = [0, 3, 1, 0]; G_max = 2 as in Fig. 3(d)), i.e. DAC2027_accelerator_explained_rows.pdf.

  (a) TIDES: memories, pre-processing unit (TIP packer), 4 x 4 PE array with T adders per PE, post-processing unit
      (edge unit), output buffer, LIF units; numbered dataflow steps
  (b) label-indexed PE (row K2, weight 1 | B) applying one weight to G1's packed train 0111 in one cycle
  (c) pre-processing unit: per-(input, timestep) AND of P2 against G1 (conflict at K1, t2), P2 opens G2, P3 joins
  (d) post-processing unit: G1's partial sums leave the column; filter and member labels restore (filter, position);
      FIFO -> read-modify-write into the output buffer; LIF after the last tile

  python3 make_arch_tides_hw.py   -> <repo>/TIDES_hw.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_hw")
FONT = "Verdana"
INK, WHITE, GREY_F, GREY_S, ARROW = "#1A1A1A", "#FFFFFF", "#F2F2F2", "#BFBFBF", "#D9D9D9"
PX = {0: "#7EA6E1", 1: "#FFD966", 2: "#96D076", 3: "#A680B8"}
G1C, G2C = "#D93025", "#6C8EBF"                      # dashed group boxes (red G1, blue G2), as in Fig. 3(d)
HOT = "#FFF2CC"                                      # updated partial sums

S = {(0, 0): "1000", (0, 1): "0000", (0, 2): "0100", (0, 3): "0011",
     (1, 0): "0000", (1, 1): "0010", (1, 2): "0011", (1, 3): "0000",
     (2, 0): "0100", (2, 1): "0011", (2, 2): "0000", (2, 3): "1000",
     (3, 0): "0011", (3, 1): "0000", (3, 2): "1000", (3, 3): "0100"}
W = {"A": [2, 0, 0, 1], "B": [0, 3, 1, 0]}

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill=WHITE, stroke=INK, fs=12, bold=False, fc=INK, sw=1.0, r=0, dashed=False,
        align="center", valign="middle", dash="6 3"):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={fc};align={align};"
          f"verticalAlign={valign};spacing=1;{'fontStyle=1;' if bold else ''}"
          f"{'dashed=1;dashPattern=' + dash + ';' if dashed else ''}")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=12, bold=False, color=INK, align="center", rot=0, italic=False):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;fontStyle={(1 if bold else 0) + (2 if italic else 0)};rotation={rot};")
    add(label, st, geo(x, y, w, h))


def wire(pts, color=INK, sw=1.2, end="block", start="none", dashed=False, size=5):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow={end};startArrow={start};endFill=1;startFill=1;endSize={size};startSize={size};html=1;"
          f"rounded=0;strokeColor={color};strokeWidth={sw};{'dashed=1;dashPattern=5 3;' if dashed else ''}")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def big_arrow(x, y, w, h, direction="south"):
    add("", f"shape=singleArrow;direction={direction};whiteSpace=wrap;html=1;arrowWidth=0.45;arrowSize=0.45;"
            f"fillColor={WHITE};strokeColor=#7F7F7F;strokeWidth=1.2;", geo(x, y, w, h))


def step(x, y, n):
    add(str(n), f"ellipse;html=1;fillColor={INK};strokeColor=none;fontColor={WHITE};fontFamily={FONT};"
                f"fontSize=11;fontStyle=1;", geo(x, y, 18, 18))


def train(x, y, bits, owner=None, labels=None, cw=18, ch=18, fs=10):
    """one T-bit train: '1' cells filled with the owner's colour (optionally with the member label), '0' white."""
    for t, b in enumerate(bits):
        o = owner[t] if owner else None
        if b == "1":
            lab = "" if labels is None else str(labels[t])
            box(x + t * cw, y, cw, ch, lab, fill=PX[o], stroke=INK, fs=fs, bold=True, sw=0.8)
        else:
            box(x + t * cw, y, cw, ch, "", fill=WHITE, stroke=INK, sw=0.8)


def panel(x, w, caption):
    box(x, 10, w, 600, "", fill=WHITE, stroke=INK, sw=1.2)
    text(x + 10, 548, w - 20, 54, f"<b>{caption}</b>", fs=13)


def sums(x, y, rows, title="", hot=(), cw=24, lw=48, dim=()):
    if title:
        text(x, y - 24, 230, 16, title, fs=11, bold=True, color="#555555", align="left")
    for i, (lab, vals) in enumerate(rows):
        yy = y + i * 18
        box(x, yy, lw, 18, lab, fill=GREY_F, stroke=INK, fs=10, bold=True, sw=0.8)
        for t, v in enumerate(vals):
            h = (lab, t) in hot
            box(x + lw + t * cw, yy, cw, 18, str(v), fill=HOT if h else WHITE, stroke=INK, fs=10, bold=h, sw=0.8,
                fc="#AAAAAA" if lab in dim else INK)


# =================================================================================================== (a) TIDES
AX, AW = 10, 560
panel(AX, AW, "(a) TIDES: offline-packed weights, run-time TIP in the pre-processing unit, "
              "4×4 PEs with T adders each")
box(AX + 20, 26, AW - 40, 26, "Off-chip DRAM", fill=GREY_F, stroke=INK, fs=12, bold=True)
# left column
box(AX + 20, 74, 150, 54, "<b>Weight Memory</b><br><span style='font-size:10px'>packed offline<br>"
                          "weight | filter label</span>", fs=12)
box(AX + 20, 300, 150, 120, "", fill=WHITE, stroke=INK, sw=1.4)
text(AX + 24, 304, 142, 18, "<b>Pre-processing unit</b>", fs=11)
text(AX + 24, 320, 142, 14, "TIP packer · ×8 lanes", fs=10, color="#555555")
for i, lab in enumerate(["AND per (input, t)", "first-fit, open groups", "packed trains + labels"]):
    box(AX + 30, 340 + i * 25, 130, 20, lab, fill=GREY_F, stroke=INK, fs=9, sw=0.8)
box(AX + 20, 222, 150, 44, "<b>Group Buffer</b><br><span style='font-size:10px'>4 KB · packed groups</span>",
    fs=12)
box(AX + 20, 450, 150, 64, "", fill=WHITE, stroke=INK)
text(AX + 20, 452, 150, 18, "<b>Spike Buffer</b>", fs=12)
text(AX + 20, 468, 150, 14, "64 KB · spike trains", fs=10, color="#555555")
train(AX + 59, 488, "0100", owner=[None, 0, None, None], cw=18, ch=16)
big_arrow(AX + 80, 420, 30, 30, "north")
big_arrow(AX + 80, 266, 30, 34, "north")
step(AX + 116, 428, 2)
step(AX + 116, 274, 3)
wire([(AX + 95, 52), (AX + 95, 74)], sw=1.4, start="block")
# PE array
PX0, PY0, PS, PP = AX + 236, 150, 44, 56
cols = [PX0 + c * PP for c in range(4)]
rows = [PY0 + r * PP for r in range(4)]
wire([(AX + 170, 101), (cols[-1] + PS / 2, 101)], sw=1.4, end="none")
for c in range(4):
    wire([(cols[c] + PS / 2, 101), (cols[c] + PS / 2, PY0)], sw=1.2, size=4)
step(AX + 180, 80, 1)
text(AX + 202, 78, 270, 20, "weights + filter labels (loaded per tile)", fs=10, color="#555555", align="left")
wire([(AX + 170, 244), (AX + 200, 244), (AX + 200, rows[0] + PS / 2)], sw=1.4, end="none")
wire([(AX + 200, 244), (AX + 200, rows[-1] + PS / 2)], sw=1.4, end="none")
for r in range(4):
    yc = rows[r] + PS / 2
    wire([(AX + 200, yc), (PX0, yc)], sw=1.2, size=4)
    for j in range(r):                                           # skew registers: row r waits r cycles
        box(PX0 - 8 - (j + 1) * 7, yc - 7, 6, 14, "", fill=WHITE, stroke=INK, sw=0.7)
step(AX + 178, 196, 4)
for r in range(4):
    for c in range(4):
        hl = (r, c) == (2, 0)
        box(cols[c], rows[r], PS, PS, "PE", fill=WHITE, stroke=INK, fs=12, bold=True, sw=1.0)
        if hl:
            box(cols[c] - 4, rows[r] - 4, PS + 8, PS + 8, "", fill="none", stroke=G1C, sw=1.6, dashed=True)
        if c < 3:
            wire([(cols[c] + PS, rows[r] + PS / 2), (cols[c + 1], rows[r] + PS / 2)], sw=1.0, size=3)
        if r < 3:
            wire([(cols[c] + PS / 2, rows[r] + PS), (cols[c] + PS / 2, rows[r + 1])], sw=1.0, size=3,
                 color="#7F7F7F")
text(cols[0] - 6, rows[3] + PS + 4, 4 * PP, 14, "trains → rows · partial sums ↓ columns", fs=9,
     color="#555555")
step(cols[3] + PS - 12, rows[3] + PS + 22, 5)
# post-processing, output buffer, LIF
box(AX + 222, 400, 218, 74, "", fill=WHITE, stroke=INK, sw=1.4)
text(AX + 222, 402, 218, 18, "<b>Post-processing unit</b>", fs=11)
for c in range(4):
    xc = cols[c] + PS / 2
    wire([(xc, rows[3] + PS + 20), (xc, 424)], sw=1.0, size=3, color="#7F7F7F")
    for j in range(3):
        box(xc - 11, 425 + j * 6, 22, 6, "", fill=GREY_F, stroke=INK, sw=0.6)
text(AX + 222, 448, 218, 24, "labels → (filter, position) · FIFO · RMW", fs=10, color="#555555")
box(AX + 458, 400, 82, 74, "<b>Output<br>Buffer</b><br><span style='font-size:10px'>192 KB</span>", fs=11)
wire([(AX + 440, 437), (AX + 458, 437)], sw=1.4)
step(AX + 440, 412, 6)
box(AX + 458, 230, 82, 110, "<b>LIF</b><br><span style='font-size:10px'>×16<br>after the<br>last tile</span>",
    fs=12)
wire([(AX + 499, 400), (AX + 499, 340)], sw=1.4)
wire([(AX + 540, 285), (AX + 552, 285), (AX + 552, 528), (AX + 95, 528), (AX + 95, 514)], sw=1.2, dashed=True)
step(AX + 520, 504, 7)
text(AX + 250, 508, 250, 14, "output spikes → next layer", fs=10, color="#555555", align="right")

# =================================================================================================== (b) PE
BX, BW = AX + AW, 470
panel(BX, BW, "(b) Label-indexed PE: one weight serves all T timesteps of a packed train in one cycle")
text(BX + 20, 30, 260, 16, "PE in row K2 · G1 arrives from the left", fs=10, bold=True, color="#555555", align="left")
TX = BX + 150
own = [None, 0, 1, 1]
for t in range(4):
    text(TX + t * 56 - 4, 50, 34, 14, f"t{t}", fs=10, color="#555555")
    b = "1" if own[t] is not None else "0"
    if b == "1":
        box(TX + t * 56, 66, 26, 22, str(own[t]), fill=PX[own[t]], stroke=INK, fs=11, bold=True, sw=0.9)
    else:
        box(TX + t * 56, 66, 26, 22, "", fill=WHITE, stroke=INK, sw=0.9)
box(TX - 6, 62, 3 * 56 + 38, 30, "", fill="none", stroke=G1C, sw=1.4, dashed=True)
wire([(BX + 20, 77), (TX - 8, 77)], sw=1.2, size=4)
wire([(TX + 3 * 56 + 32, 77), (TX + 3 * 56 + 60, 77)], sw=1.2, size=4)
box(BX + 20, 118, 100, 46, "<b>w = 1</b><br><span style='font-size:10px'>filter label B</span>", fill=GREY_F,
    fs=12)
text(BX + 20, 166, 100, 14, "stationary", fs=9, color="#777777")
wire([(BX + 120, 141), (TX, 141)], sw=1.2, size=4)
for t in range(4):
    on = own[t] is not None
    x = TX + t * 56
    wire([(x + 13, 88), (x + 13, 128)], sw=1.0, size=3, color=INK if on else "#BBBBBB")
    add("+", f"ellipse;html=1;fillColor={WHITE};strokeColor={INK if on else '#BBBBBB'};strokeWidth={1.6 if on else 0.8};"
             f"fontColor={INK if on else '#BBBBBB'};fontFamily={FONT};fontSize=16;fontStyle=1;", geo(x, 128, 26, 26))
    wire([(x + 13, 154), (x + 13, 178)], sw=1.0, size=3, color=INK if on else "#BBBBBB")
box(TX - 6, 178, 3 * 56 + 38, 26, "select by (filter label, member label)", fill=GREY_F, fs=10, sw=0.9)
sums(BX + 40, 248, [("A,P0", [2, 0, 0, 0]), ("A,P1", [0, 0, 0, 0]), ("B,P0", [0, 0, 0, 0]),
                    ("B,P1", [0, 0, 3, 0])], title="sums in (from above)")
sums(BX + 260, 248, [("A,P0", [2, 0, 0, 0]), ("A,P1", [0, 0, 0, 0]), ("B,P0", [0, 1, 0, 0]),
                     ("B,P1", [0, 0, 4, 1])], title="sums out (to below)",
     hot={("B,P0", 1), ("B,P1", 2), ("B,P1", 3)})
big_arrow(BX + 196, 268, 56, 34, "east")
wire([(TX + 85, 204), (TX + 85, 226)], sw=1.0, size=4)
text(BX + 20, 340, BW - 40, 70, "Adder t adds w only when bit t is 1. The label picks the member: +1 to "
     "(B, P0) at t1, +1 to (B, P1) at t2 and t3. All other partial sums pass through unchanged; the PE never "
     "compares or searches.", fs=11, align="left")
text(BX + 20, 420, BW - 40, 110, "<b>Per PE</b><br>1 weight + 2-bit filter label (shadow copy for the next "
     "tile)<br>T adders, one per timestep<br>F<sub>max</sub>·G<sub>max</sub>·T partial sums carried down "
     "the column", fs=11, align="left")

# =================================================================================================== (c) pre-processing
CX, CW = BX + BW, 470
panel(CX, CW, "(c) Pre-processing unit: one AND per (input, timestep) mask, first-fit into open groups")


def mask_grid(x, y, members, frame=None, conflict=None, title=""):
    """K x t grid: the spikes of `members` on the tile, coloured by owner."""
    if title:
        text(x - 30, y - 22, 4 * 18 + 60, 16, title, fs=10, bold=True, color="#333333")
    for k in range(4):
        text(x - 26, y + k * 18, 22, 18, f"K{k}", fs=9, color="#555555")
        for t in range(4):
            o = next((p for p in members if S[(k, p)][t] == "1"), None)
            hit = conflict == (k, t)
            box(x + t * 18, y + k * 18, 18, 18, "×" if hit else "", fill=PX[o] if o is not None else WHITE,
                stroke=G1C if hit else INK, sw=2.0 if hit else 0.7, fs=13, bold=True, fc=G1C)
    for t in range(4):
        text(x + t * 18, y + 79, 18, 12, f"t{t}", fs=8, color="#777777")
    if frame:
        box(x - 4, y - 4, 80, 80, "", fill="none", stroke=frame, sw=1.4, dashed=True)


mask_grid(CX + 60, 60, [0, 1], frame=G1C, title="open G1 = P0 + P1")
text(CX + 150, 90, 30, 30, "∧", fs=22, bold=True)
mask_grid(CX + 210, 60, [2], title="incoming P2")
text(CX + 300, 90, 30, 30, "=", fs=20, bold=True)
mask_grid(CX + 350, 60, [], conflict=(1, 2), title="AND ≠ 0")
text(CX + 20, 160, CW - 40, 32, "P2 and P1 both fire on K1 at t2, so P2 cannot join G1 and opens G2; "
     "P3 then fits G2 (AND = 0).", fs=10, align="left")
mask_grid(CX + 60, 222, [2, 3], frame=G2C, title="G2 = P2 + P3")
# group buffer entries, Fig. 3(d) style
text(CX + 180, 200, 270, 16, "group buffer entries (packed trains + labels)", fs=10, bold=True,
     color="#333333", align="left")
for k in range(4):
    yy = 222 + k * 24
    text(CX + 178, yy, 26, 18, f"K{k}", fs=9, bold=True, color="#555555")
    for gi, (members, col) in enumerate((([0, 1], G1C), ([2, 3], G2C))):
        x0 = CX + 210 + gi * 120
        o = [next((m for m in members if S[(k, m)][t] == "1"), None) for t in range(4)]
        bits = "".join("1" if v is not None else "0" for v in o)
        train(x0, yy, bits, owner=o, labels=[members.index(v) if v is not None else "" for v in o], cw=18, ch=18,
              fs=9)
        box(x0 - 3, yy - 3, 78, 24, "", fill="none", stroke=col, sw=1.2, dashed=True)
        text(x0 + 78, yy, 26, 18, f"G{gi + 1}", fs=9, bold=True)
text(CX + 178, 322, 280, 30, "+ member IDs per group: G1 = {P0, P1}, G2 = {P2, P3} (7 bits each)", fs=10,
     align="left", color="#333333")
text(CX + 20, 372, CW - 40, 150, "<b>Hardware</b><br>8 lanes, each scanning one tile; per position: a "
     "R·T-bit mask, Q = 4 AND checks against the open groups, OR-merge on a fit<br>A group leaves when it "
     "holds G<sub>max</sub> members or when the oldest open group is evicted<br>Silent positions are dropped "
     "before the array", fs=11, align="left")

# =================================================================================================== (d) post-processing
DX, DW = CX + CW, 470
panel(DX, DW, "(d) Post-processing unit: labels restore (filter, position); the output buffer sums the tiles")
sums(DX + 30, 60, [("A,0", [2, 0, 1, 1]), ("A,1", [0, 0, 0, 0]), ("B,0", [0, 1, 0, 0]), ("B,1", [0, 0, 4, 1])],
     title="G1 leaves the column", dim=("A,1",), lw=40)
box(DX + 26, 56, 4 * 24 + 48, 80, "", fill="none", stroke=G1C, sw=1.4, dashed=True)
text(DX + 180, 64, 270, 36, "untouched sums (A,1) are not written", fs=10, color="#777777", align="left")
box(DX + 220, 100, 110, 50, "<b>filter list</b><br>0 → A · 1 → B", fill=GREY_F, fs=10)
box(DX + 340, 100, 110, 50, "<b>member IDs</b><br>0 → P0 · 1 → P1", fill=GREY_F, fs=10)
big_arrow(DX + 210, 160, 44, 40, "south")
text(DX + 30, 166, 170, 30, "(A,0)→(A,P0) · (B,0)→(B,P0) · (B,1)→(B,P1)", fs=9, align="left", color="#333333")
text(DX + 30, 212, 100, 16, "edge FIFO", fs=10, bold=True, color="#555555", align="left")
for i, lab in enumerate(["(A,P0)", "(B,P0)", "(B,P1)"]):
    box(DX + 30 + i * 62, 230, 58, 22, lab, fill=WHITE, fs=10, bold=True, sw=0.9)
wire([(DX + 216, 241), (DX + 250, 241)], sw=1.2)
add("+", f"ellipse;html=1;fillColor={WHITE};strokeColor={INK};strokeWidth=1.6;fontFamily={FONT};fontSize=16;"
         f"fontStyle=1;", geo(DX + 252, 228, 26, 26))
text(DX + 240, 256, 60, 14, "RMW", fs=9, bold=True, color="#555555")
wire([(DX + 278, 241), (DX + 300, 241)], sw=1.2)
text(DX + 300, 202, 160, 16, "output buffer (after tile)", fs=10, bold=True, color="#555555", align="left")
outb = {("A", 0): [2, 0, 1, 1], ("A", 1): [0, 0, 0, 0], ("A", 2): [1, 2, 0, 0], ("A", 3): [0, 1, 2, 2],
        ("B", 0): [0, 1, 0, 0], ("B", 1): [0, 0, 4, 1], ("B", 2): [0, 0, 3, 3], ("B", 3): [1, 0, 0, 0]}
for j, p in enumerate(range(4)):
    text(DX + 330 + j * 32, 220, 32, 14, f"P{p}", fs=9, bold=True, color="#555555")
for i, f in enumerate("AB"):
    text(DX + 304, 236 + i * 26, 24, 24, f, fs=10, bold=True)
    for j in range(4):
        hit = (f, j) in {("A", 0), ("B", 0), ("B", 1)}
        box(DX + 330 + j * 32, 236 + i * 26, 32, 24, "", fill=PX[j] if hit else WHITE, stroke=INK, sw=0.8)
big_arrow(DX + 372, 292, 40, 36, "south")
box(DX + 300, 330, 150, 46, "<b>LIF ×16</b><br><span style='font-size:10px'>after the last tile</span>", fs=12)
text(DX + 300, 380, 150, 16, "A,P0: [2,0,1,1] → 1000", fs=9, color="#333333")
text(DX + 20, 410, DW - 40, 120, "<b>Hardware</b><br>4 FIFOs × 80 entries, one per column; 4 read-modify-"
     "writes per column per cycle into the 192 KB output buffer<br>Labels (2 bits) + per-group member IDs "
     "and per-column filter lists give the address (n, m); no search", fs=11, align="left")

# =================================================================================================== legend
LY, LX = 628, 560
box(LX, LY, 900, 40, "", fill=WHITE, stroke=INK, sw=1.0)
x = LX + 16
for p in range(4):
    box(x, LY + 11, 18, 18, "", fill=PX[p], stroke=INK, sw=0.8)
    text(x + 22, LY + 10, 70, 20, f"spike of P{p}", fs=11, bold=True, align="left")
    x += 108
box(x, LY + 11, 18, 18, "", fill=WHITE, stroke=INK, sw=0.8)
text(x + 22, LY + 10, 40, 20, "0", fs=11, bold=True, align="left")
x += 50
box(x, LY + 8, 34, 24, "", fill="none", stroke=G1C, sw=1.4, dashed=True)
box(x + 40, LY + 8, 34, 24, "", fill="none", stroke=G2C, sw=1.4, dashed=True)
text(x + 80, LY + 10, 110, 20, "group G1 / G2", fs=11, bold=True, align="left")
x += 190
box(x, LY + 11, 24, 18, "1", fill=HOT, stroke=INK, sw=0.8, fs=10, bold=True)
text(x + 28, LY + 10, 120, 20, "updated sum", fs=11, bold=True, align="left")

xml = ('<mxfile host="drawio"><diagram id="tideshw" name="TIDES hardware"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "4", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "2", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
