"""
make_arch_tides.py -- TIDES architecture figure (draw.io), styled after the baseline papers' figures: Prosperity's
DRAM bar + CTRL + tinted core with colour-coded units and numbered dataflow steps, Phi's compact grouped blocks and
xN neuron column, SATO / SpikeX's PE grid with a dotted zoom into one PE.

  (a) TIDES core: the six blocks of DAC2027_accelerator_explained_rows.pdf (Sec. 9: weight memory, packer, PE array,
      edge unit, output buffer, LIF) with the evaluated sizes (Table I) and the dataflow steps 1-7
  (b) one label-indexed PE, the PDF's Fig. 10 example (PE k2: w = 1 | B, group G1 = 0111, labels -, p0, p1, p1)
  (c) spatiotemporal packing of one K-tile, the PDF's Sec. 5.2-5.3 example (p0..p3 -> G1 = p0+p1, G2 = p2+p3)

  python3 make_arch_tides.py   -> <repo>/TIDES_architecture.drawio (+ .pdf, .png next to it)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_architecture")
FONT = "Helvetica"
INK, WHITE, GREY = "#1E1E1E", "#FFFFFF", "#8A8A8A"
BLUE, BLUE_L, BLUE_S = "#3A8EED", "#D9E8FB", "#2F6FD0"
GREEN, GREEN_D = "#5DB234", "#3F8A1F"
YELLOW, YELLOW_D = "#FFC607", "#C99A00"
ORANGE, ORANGE_L = "#EE8A2A", "#FCE3C8"
PURPLE, PURPLE_L, PURPLE_D = "#B48BE6", "#EFE5FB", "#7A4FBF"
PINK, PINK_D = "#FCC5C5", "#D98C8C"
NAVY = "#1E3A5F"
PX = {0: "#3A8EED", 1: "#F39C12", 2: "#2EAD5B", 3: "#9B59B6"}      # pixels p0..p3
FL = {"A": "#E0505A", "B": "#1FA2B6"}                                # filters A, B

# the PDF's example (T = 4): S[(k, p)] = spike train of window position k seen by output pixel p, bit string t0..t3
S = {(0, 0): "1000", (0, 1): "0000", (0, 2): "0100", (0, 3): "0011",
     (1, 0): "0000", (1, 1): "0010", (1, 2): "0011", (1, 3): "0000",
     (2, 0): "0100", (2, 1): "0011", (2, 2): "0000", (2, 3): "1000",
     (3, 0): "0011", (3, 1): "0000", (3, 2): "1000", (3, 3): "0100"}
GROUPS = [(1, [0, 1]), (2, [2, 3])]

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill=WHITE, stroke=INK, fs=13, bold=False, fc=INK, sw=1.0, r=4, dashed=False,
        align="center", valign="middle", shadow=False):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={fc};align={align};"
          f"verticalAlign={valign};spacing=2;{'fontStyle=1;' if bold else ''}"
          f"{'dashed=1;dashPattern=6 3;' if dashed else ''}{'shadow=1;' if shadow else ''}")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=12, bold=False, color=INK, align="center", italic=False, rot=0, valign="middle"):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign={valign};spacing=0;fontStyle={(1 if bold else 0) + (2 if italic else 0)};rotation={rot};")
    add(label, st, geo(x, y, w, h))


def wire(pts, color=INK, sw=1.4, end="block", start="none", dashed=False, size=5):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow={end};startArrow={start};endFill=1;startFill=1;endSize={size};startSize={size};html=1;"
          f"rounded=0;strokeColor={color};strokeWidth={sw};{'dashed=1;dashPattern=4 3;' if dashed else ''}")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def step(x, y, n, label="", color=NAVY, w=120, fs=12):
    add(str(n), f"ellipse;html=1;fillColor={color};strokeColor=none;fontColor={WHITE};fontFamily={FONT};"
                f"fontSize=11;fontStyle=1;", geo(x, y, 18, 18))
    if label:
        text(x + 21, y - 1, w, 20, label, fs=fs, bold=True, color=color, align="left")


def bit(x, y, b, color, cw=14, ch=14, fs=10):
    if b == "1":
        box(x, y, cw, ch, "1", fill=color, stroke=INK, fs=fs, fc=WHITE, bold=True, sw=0.6, r=0)
    else:
        box(x, y, cw, ch, "0", fill=WHITE, stroke="#9A9A9A", fs=fs, fc="#9A9A9A", sw=0.6, r=0)


# ============================================================================================= (a) TIDES core
box(8, 6, 580, 26, "DRAM  (DDR4, 64 GB/s)", fill=PINK, stroke=PINK_D, fs=14, bold=True, r=3)
box(596, 6, 60, 26, "CTRL", fill="#CFC9F7", stroke="#8A80D9", fs=14, bold=True, r=3)
box(8, 40, 648, 426, "", fill="#EEF4FC", stroke="#86ABD9", sw=1.4, r=8)
text(200, 433, 264, 16, "<b>TIDES Core</b> <span style='font-size:12px'>· 4×4 PEs × T adders</span>", fs=15,
     color=BLUE_S)

# --- left column: weight memory, group buffer, packer, spike staging buffer
box(20, 50, 150, 52, "<b>Weight Memory</b><br><span style='font-size:12px'>8-b weight | 2-b filter label</span>",
    fill=GREEN, stroke=GREEN_D, fs=14, fc=WHITE, r=4)
box(20, 118, 150, 40, "<b>Group Buffer</b>  4 KB", fill=BLUE_L, stroke=BLUE, fs=13, r=4)
box(20, 174, 150, 150, "", fill=BLUE, stroke="#2A73C9", r=4)
step(26, 180, 3, "", color=NAVY)
text(46, 178, 120, 22, "<b>Run-time Packer</b>", fs=14, color=WHITE, align="left")
text(46, 196, 120, 16, "×8 lanes", fs=12, color=WHITE, align="left")
for i, lab in enumerate(["AND check per (input, t)", "first-fit, 4 open groups", "merge ≤ G pixels + labels"]):
    box(28, 216 + i * 34, 134, 28, lab, fill=WHITE, stroke="#2A73C9", fs=12, r=3)
    if i:
        wire([(95, 216 + i * 34 - 6), (95, 216 + i * 34)], color=WHITE, sw=1.2, size=4)
box(20, 346, 150, 84, "", fill=BLUE_L, stroke=BLUE, r=4)
text(20, 350, 150, 20, "<b>Spike Staging Buffer</b>", fs=13)
text(20, 368, 150, 16, "64 KB · T-bit spike trains", fs=12)
for t, b in enumerate("00100110"):
    bit(39 + t * 14, 394, b, BLUE)
wire([(95, 346), (95, 324)], color=BLUE, sw=1.8)
step(102, 326, 2, "Read", w=60)
wire([(95, 174), (95, 158)], color=BLUE, sw=1.8)
wire([(95, 32), (95, 50)], color=GREEN_D, sw=1.8, start="block")
wire([(14, 32), (14, 388), (20, 388)], color=BLUE, sw=1.8, start="block")

# --- PE array (4 x 4), skewed row feeders, weight bus
PX0, PY0, PS, PP = 228, 128, 44, 56
cols = [PX0 + c * PP for c in range(4)]
rows = [PY0 + r * PP for r in range(4)]
wire([(170, 76), (cols[-1] + PS / 2, 76)], color=GREEN_D, sw=2.0, end="none")
for c in range(4):
    wire([(cols[c] + PS / 2, 76), (cols[c] + PS / 2, PY0)], color=GREEN_D, sw=1.6, size=4)
step(180, 54, 1, "Load weights + filter labels (shadow regs)", color=GREEN_D, w=260, fs=12)
wire([(170, 138), (200, 138), (200, rows[-1] + PS / 2)], color=BLUE, sw=1.8, end="none")
step(176, 112, 4, "", color=NAVY)
for r in range(4):
    yc = rows[r] + PS / 2
    wire([(200, yc), (PX0, yc)], color=BLUE, sw=1.6, size=4)
    for j in range(r):                                         # row r is delayed r cycles (skew registers)
        box(PX0 - 10 - (j + 1) * 7, yc - 7, 6, 14, "", fill=WHITE, stroke=BLUE, sw=0.8, r=0)
text(200, 112, 30, 14, "skew", fs=11, color=GREY)
text(86, 220, 200, 16, "merged trains + pixel labels", fs=12, color=BLUE_S, bold=True, rot=270)
for r in range(4):
    for c in range(4):
        hl = (r, c) == (0, 3)
        box(cols[c], rows[r], PS, PS, "PE", fill=BLUE, stroke=INK if hl else "#2A73C9", fs=14, bold=True,
            fc=WHITE, sw=2.4 if hl else 1.0, r=3)
        if c < 3:
            wire([(cols[c] + PS, rows[r] + PS / 2), (cols[c + 1], rows[r] + PS / 2)], color=BLUE, sw=1.4, size=4)
        if r < 3:
            wire([(cols[c] + PS / 2 + 10, rows[r] + PS), (cols[c] + PS / 2 + 10, rows[r + 1])], color=ORANGE,
                 sw=1.6, size=4)
text(cols[-1] + PS + 13 - 70, rows[1] + PP - 9, 140, 18, "running-sum bundles ↓", fs=12, color=ORANGE,
     bold=True, rot=90)
step(cols[-1] + PS + 4, rows[3] + 4, 5, "", color=NAVY)

# --- edge unit, output buffer, LIF
box(212, 362, 240, 70, "", fill=ORANGE_L, stroke=ORANGE, r=5)
for c in range(4):
    xc = cols[c] + PS / 2 + 10
    wire([(xc, rows[3] + PS), (xc, 380)], color=ORANGE, sw=1.6, size=4)
    for j in range(3):
        box(xc - 12, 381 + j * 7, 24, 7, "", fill=WHITE, stroke=ORANGE, sw=0.8, r=0)
text(212, 404, 240, 28, "<b>Edge Unit</b> · 4 FIFOs × 80<br>labels → (filter, pixel) · 4 RMW / col / cycle",
     fs=11)
box(480, 362, 160, 70, "<b>Output Buffer</b>  192 KB<br><span style='font-size:12px'>Σ per (filter, pixel) × T</span>",
    fill=YELLOW, stroke=YELLOW_D, fs=13, r=4)
wire([(452, 397), (480, 397)], color=ORANGE, sw=2.0, start="block")
step(457, 372, 6, "", color=NAVY)
box(492, 222, 148, 96, "", fill=PURPLE_L, stroke=PURPLE, sw=0.8, r=4)
box(486, 228, 148, 96, "", fill=PURPLE_L, stroke=PURPLE, sw=0.8, r=4)
box(480, 234, 148, 96, "<b>LIF Units ×16</b><br><span style='font-size:12px'>4-stage pipeline<br>"
    "V ← λV + I[t]<br>fire if V ≥ θ, V −= θ</span>", fill=PURPLE, stroke=PURPLE_D, fs=13, fc=WHITE, r=4)
wire([(554, 362), (554, 330)], color=ORANGE, sw=2.0)
text(560, 336, 80, 20, "last K-tile", fs=11, color=GREY, align="left")
wire([(628, 282), (650, 282), (650, 456), (95, 456), (95, 430)], color=PURPLE_D, sw=1.8, dashed=True)
step(612, 438, 7, "", color=PURPLE_D)
text(466, 440, 144, 14, "output spikes → next layer", fs=11, color=PURPLE_D, bold=True, align="right")

# zoom lines to (b)
wire([(cols[3] + PS, rows[0]), (676, 26)], color=GREY, sw=0.9, end="none", dashed=True)
wire([(cols[3] + PS, rows[0] + PS), (676, 226)], color=GREY, sw=0.9, end="none", dashed=True)

# ============================================================================================= (b) one PE
BX, BW = 676, 506
box(BX, 6, BW, 222, "", fill="#FFF6EC", stroke="#E3A27E", sw=1.3, r=10, dashed=True)
text(BX + 10, 9, BW - 20, 20, "<b>(b) Label-indexed PE</b> <span style='font-size:12px;color:#555555'>"
     "all T timesteps in one cycle (T = 4 shown)</span>", fs=15, align="left")
# incoming merged train (group G1 at PE k2): bits and the pixel label of every bit
TB = [("0", None), ("1", 0), ("1", 1), ("1", 1)]
AX0, AP = 832, 52
text(BX + 12, 36, 140, 16, "group G1 from left PE", fs=12, color=BLUE_S, bold=True, align="left")
wire([(BX + 12, 60), (AX0 - 6, 60)], color=BLUE, sw=1.6, size=4)
for t, (b, p) in enumerate(TB):
    x = AX0 + t * AP
    bit(x, 52, b, PX[p] if p is not None else BLUE, cw=24, ch=18, fs=12)
    box(x, 70, 24, 16, "–" if p is None else f"p{p}", fill=WHITE, stroke="#9A9A9A", fs=11,
        fc=PX[p] if p is not None else GREY, bold=p is not None, sw=0.6, r=0)
    text(x - 6, 36, 36, 14, f"t{t}", fs=11, color=GREY)
    wire([(x + 12, 86), (x + 12, 100)], color=BLUE if b == "1" else "#BBBBBB", sw=1.2, size=3)
    add("+", f"ellipse;html=1;fillColor={WHITE};strokeColor={ORANGE if b == '1' else '#BBBBBB'};"
             f"strokeWidth={1.8 if b == '1' else 1.0};fontColor={ORANGE if b == '1' else '#BBBBBB'};fontFamily={FONT};"
             f"fontSize=18;fontStyle=1;", geo(x, 100, 24, 24))
    wire([(x + 12, 124), (x + 12, 142)], color=ORANGE if b == "1" else "#BBBBBB", sw=1.2, size=3)
wire([(AX0 + 3 * AP + 24, 60), (AX0 + 3 * AP + 52, 60)], color=BLUE, sw=1.6, size=4)
box(BX + 12, 92, 100, 40, "<b>w = 1</b><br>filter label <b>B</b>", fill=GREEN, stroke=GREEN_D, fs=12, fc=WHITE, r=3)
text(BX + 12, 133, 100, 14, "stationary", fs=11, color=GREY)
wire([(BX + 112, 112), (AX0, 112)], color=GREEN_D, sw=1.6, size=4)
for t in range(1, 4):
    wire([(AX0 + (t - 1) * AP + 24, 112), (AX0 + t * AP, 112)], color=GREEN_D, sw=1.2, size=3)
box(AX0 - 8, 142, 3 * AP + 40, 26, "slot = {filter label, pixel label of bit t}", fill=WHITE, stroke=INK, fs=12, r=3)
# running-sum bundle in / out
RX = 1050


def bundle(y, title, rows_, hot=()):
    text(RX, y, 128, 14, title, fs=11, color=ORANGE, bold=True, align="left")
    for i, (lab, vals) in enumerate(rows_):
        f = lab[0]
        box(RX, y + 16 + i * 15, 40, 15, lab, fill=FL[f], stroke=INK, fs=10, fc=WHITE, bold=True, sw=0.6, r=0)
        for t, v in enumerate(vals):
            h = (lab, t) in hot
            box(RX + 40 + t * 21, y + 16 + i * 15, 21, 15, str(v), fill="#FFE07A" if h else WHITE, stroke="#9A9A9A",
                fs=10, bold=h, sw=0.6, r=0)


bundle(34, "sums in (from PE above)", [("A,p0", [2, 0, 0, 0]), ("A,p1", [0, 0, 0, 0]), ("B,p0", [0, 0, 0, 0]),
                                       ("B,p1", [0, 0, 3, 0])])
bundle(122, "sums out (to PE below)", [("A,p0", [2, 0, 0, 0]), ("A,p1", [0, 0, 0, 0]), ("B,p0", [0, 1, 0, 0]),
                                       ("B,p1", [0, 0, 4, 1])], hot={("B,p0", 1), ("B,p1", 2), ("B,p1", 3)})
wire([(AX0 + 3 * AP + 32, 155), (RX - 4, 168)], color=ORANGE, sw=1.6, size=4)
wire([(RX + 124, 110), (RX + 124, 122)], color=ORANGE, sw=1.4, size=3)
text(BX + 12, 176, 330, 46, "Adder t adds w only if bit t = 1; the two labels pick the sum: +1 → (B,p0)@t1 and "
     "(B,p1)@t2, t3. No compare, no search: every other sum passes through.", fs=11, align="left", color="#333333")

# ============================================================================================= (c) packing
CY = 236
box(BX, CY, BW, 230, "", fill="#F5F0FB", stroke="#A98ED2", sw=1.3, r=10, dashed=True)
text(BX + 10, CY + 3, BW - 20, 20, "<b>(c) Spatiotemporal packing</b> <span style='font-size:12px;color:#555555'>"
     "one K-tile in the packer (T = 4)</span>", fs=15, align="left")
CW = 12
text(BX + 12, CY + 27, 290, 14, "per-pixel spike trains: rows k0–k3, columns t0–t3", fs=11, color=GREY,
     align="left")
for p in range(4):
    x0 = BX + 30 + p * 62
    text(x0, CY + 44, 4 * CW, 14, f"<b>p{p}</b>", fs=12, color=PX[p])
    for k in range(4):
        for t, b in enumerate(S[(k, p)]):
            bit(x0 + t * CW, CY + 60 + k * CW, b, PX[p], cw=CW, ch=CW, fs=8)
for k in range(4):
    text(BX + 12, CY + 60 + k * CW, 16, CW, f"k{k}", fs=10, color=GREY)
# first-fit decisions
log = [("p0", "opens G1", "#333333"), ("p1 ∧ G1 = 0", "join G1", GREEN_D),
       ("p2 ∧ G1 ≠ 0 at (k1, t2)", "open G2", "#C0392B"), ("p3 ∧ G2 = 0", "join G2", GREEN_D)]
for i, (a, b, col) in enumerate(log):
    y = CY + 124 + i * 18
    text(BX + 14, y, 170, 16, a, fs=11, align="left")
    text(BX + 186, y, 70, 16, f"<b>{b}</b>", fs=11, color=col, align="left")
text(BX + 14, CY + 198, 250, 26, "checked per (input, timestep), not per train; first-fit over 4 open groups",
     fs=11, color="#333333", italic=True, align="left")
wire([(BX + 282, CY + 84), (BX + 312, CY + 84)], color=PURPLE_D, sw=2.0)
# merged groups with pixel ownership and labels
for gi, (g, ps) in enumerate(GROUPS):
    x0 = BX + 322 + gi * 92
    text(x0 - 6, CY + 30, 90, 14, f"<b>G{g}</b> = p{ps[0]} + p{ps[1]}", fs=12, align="left")
    for k in range(4):
        for t in range(4):
            own = [p for p in ps if S[(k, p)][t] == "1"]
            b = "1" if own else "0"
            bit(x0 + t * 16, CY + 48 + k * 16, b, PX[own[0]] if own else BLUE, cw=16, ch=16, fs=10)
    text(x0 - 8, CY + 114, 100, 14, "+ 2-b pixel labels", fs=10, color=GREY, align="left")
text(BX + 316, CY + 138, 180, 54, "4 pixels → 2 groups: half the streaming steps, each pass still applies "
     "one weight to all T timesteps", fs=11, color="#333333", align="left")
for p in range(4):
    box(BX + 322 + p * 42, CY + 200, 12, 12, "", fill=PX[p], stroke=INK, sw=0.6, r=0)
    text(BX + 337 + p * 42, CY + 199, 24, 14, f"p{p}", fs=11, color=PX[p], bold=True, align="left")

# ============================================================================================= write + export
xml = ('<mxfile host="drawio"><diagram id="tides" name="TIDES architecture"><mxGraphModel grid="0" page="0" '
       'pageWidth="1190" pageHeight="472"><root><mxCell id="0"/><mxCell id="1" parent="0"/>'
       + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "4", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "2.5", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
