"""
make_arch_tides_ppu.py -- TIDES processing unit in the visual format of Prosperity's Fig. 5 (palette sampled from it):
Spike Buffer -> Pre-processing Unit (black box) -> (a) Group Buffer -> (b) PE Array (with one PE opened) ->
(c) Output stage: Post-processing Unit (black box) -> Output Buffer -> LIF, (d) one PE (ours_pe in
hw/rtl/ours/ours_core.v), with numbered steps.

Data: the running example of Fig. 1(b) / Fig. 3 (K0..K3, P0..P3, T = 4; filters A = [2,0,0,1], B = [0,3,1,0] packed
into one column), packed with the hardware threshold G_max = 4 (ours.pack_spikes: G1 = {P0, P1, P3}, G2 = {P2}).

  python3 make_arch_tides_ppu.py   -> <repo>/TIDES_ppu.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_ppu")
FONT = "Helvetica"
# palette sampled from Prosperity Fig. 5
INK, WHITE, NOTE = "#1A1A1A", "#FFFFFF", "#333333"
HDR = "#518CE6"                                         # title bars, PEs, black-box units
ONE = "#679DD5"                                         # '1' cells
RED = "#EB5149"
NOY, SIG = "#FBEAB8", "#BFDDAA"
TINT = {"a": "#EDF3FB", "b": "#F3EFF9", "c": "#F6FAEB"}
STEP = {"pre": "#E16979", "grp": "#8D5DB7", "pe": "#E2BE3F"}
WGT, OBUF, LIF = "#7CBA4C", "#F7CF46", "#FAE1E1"

S = {(0, 0): "1000", (0, 1): "0000", (0, 2): "0100", (0, 3): "0011",
     (1, 0): "0000", (1, 1): "0010", (1, 2): "0011", (1, 3): "0000",
     (2, 0): "0100", (2, 1): "0011", (2, 2): "0000", (2, 3): "1000",
     (3, 0): "0011", (3, 1): "0000", (3, 2): "1000", (3, 3): "0100"}
GROUPS = [("G1", [0, 1, 3]), ("G2", [2])]

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill=WHITE, stroke=INK, fs=10, bold=False, fc=INK, sw=1.0, r=0, dashed=False,
        align="center", valign="middle", rot=0):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={fc};align={align};"
          f"verticalAlign={valign};spacing=1;horizontal={0 if rot else 1};{'fontStyle=1;' if bold else ''}"
          f"{'dashed=1;dashPattern=4 3;' if dashed else ''}")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=10, bold=False, color=INK, align="center"):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;fontStyle={1 if bold else 0};")
    add(label, st, geo(x, y, w, h))


def wire(pts, color=INK, sw=1.2, end="block", start="none", size=5, dashed=False):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow={end};startArrow={start};endFill=1;startFill=1;endSize={size};startSize={size};html=1;"
          f"rounded=0;strokeColor={color};strokeWidth={sw};{'dashed=1;dashPattern=4 3;' if dashed else ''}")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def step(x, y, n, label, kind, side="right", w=70):
    add(str(n), f"ellipse;html=1;fillColor={STEP[kind]};strokeColor=none;fontColor={WHITE};fontFamily={FONT};"
                f"fontSize=10;fontStyle=1;", geo(x, y, 17, 17))
    if label:
        if side == "right":
            text(x + 20, y, w, 17, label, fs=10, align="left")
        else:
            text(x - w - 3, y, w, 17, label, fs=10, align="right")


def container(x, y, w, h, key, title, bottom=False):
    box(x, y, w, h, "", fill=TINT[key], stroke="#7F7F7F", sw=1.0, r=10, dashed=True)
    text(x, y + h - 24 if bottom else y + 4, w, 20, title, fs=14)


def block(x, y, w, h, title, th=18, fs=10):
    box(x, y, w, h, "", fill=WHITE, stroke=INK, sw=1.0)
    box(x, y, w, th, title, fill=HDR, stroke=HDR, fs=fs + 1, bold=True, fc=WHITE, sw=1.0)


def bit(x, y, b, label=None, cw=13, ch=15, fs=8):
    if b == "1":
        box(x, y, cw, ch, "1" if label is None else str(label), fill=ONE, stroke=INK, fs=fs, bold=True, sw=0.8,
            fc=WHITE)
    else:
        box(x, y, cw, ch, "0", fill=WHITE, stroke=INK, fs=fs, sw=0.8)


# ======================================================================================== spike buffer
box(8, 92, 196, 196, "", fill="#D8E6F4", stroke=INK, sw=1.0, r=6)
text(14, 266, 140, 18, "Spike Buffer", fs=12, align="left")
for k in range(4):
    text(34 + k * 42, 100, 42, 14, f"K{k}", fs=9, bold=True, color=NOTE)
for m in range(4):
    y = 118 + m * 22
    text(12, y, 20, 15, f"P{m}", fs=9, bold=True)
    for k in range(4):
        for t in range(4):
            bit(34 + k * 42 + t * 10, y, S[(k, m)][t], cw=10, ch=15, fs=7)
text(34, 210, 168, 28, "im2col rows: one T = 4 train<br>per (position, input)", fs=8, color=NOTE, align="left")
step(150, 296, 0, "Read", "pre")

# ======================================================================================== pre-processing (black box)
box(222, 92, 64, 196, "Pre-processing Unit", fill=HDR, stroke=HDR, fs=13, bold=True, fc=WHITE, rot=1)
wire([(204, 190), (222, 190)], sw=1.4)
wire([(286, 130), (330, 130)], sw=1.4)
step(293, 138, 1, "", "pre")
text(287, 108, 30, 16, "Pack", fs=10)

# ======================================================================================== (a) group buffer
container(318, 8, 404, 230, "a", "(a) Group Buffer")
block(330, 36, 380, 186, "Packed Groups")
text(336, 56, 40, 14, "group", fs=8, bold=True, color=NOTE)
text(376, 56, 80, 14, "member IDs", fs=8, bold=True, color=NOTE)
for k in range(4):
    text(460 + k * 62, 56, 58, 14, f"K{k}", fs=8, bold=True, color=NOTE)
for gi, (g, mem) in enumerate(GROUPS):
    y = 76 + gi * 66
    text(336, y + 18, 40, 16, f"<b>{g}</b>", fs=10)
    box(380, y + 18, 72, 16, "{" + ", ".join(f"P{m}" for m in mem) + "}", fill=NOY, stroke=INK, fs=9, bold=True,
        sw=0.8)
    for k in range(4):
        o = [next((m for m in mem if S[(k, m)][t] == "1"), None) for t in range(4)]
        for t in range(4):
            bit(460 + k * 62 + t * 13, y + 18, "1" if o[t] is not None else "0",
                label=mem.index(o[t]) if o[t] is not None else None, cw=13, ch=16)
    box(456, y + 14, 250, 24, "", fill="none", stroke=RED if gi == 0 else HDR, sw=1.3, dashed=True)
text(336, 200, 370, 14, "packed spike trains · member label per spike · member IDs per group", fs=8, color=NOTE,
     align="left")

# ======================================================================================== (b) PE array
X = 734
container(X, 8, 450, 460, "b", "(b) PE Array")
box(X + 14, 40, 424, 26, "<b>Weight Buffer</b> · packed offline (weight + 2-b filter label)", fill=WGT, stroke=INK,
    fs=10)
step(X - 2, 44, 3, "", "pe")
text(X + 308, 68, 120, 14, "Load Weight", fs=9, align="right")
PX0, PY0, P, PS, RP = X + 68, 108, 88, 44, 80
for c in range(4):
    wire([(PX0 + c * P + PS / 2, 66), (PX0 + c * P + PS / 2, PY0)], sw=1.2, size=4)
for r in range(4):
    yy = PY0 + r * RP
    text(X + 20, yy + 14, 26, 16, f"K{r}", fs=9, bold=True, color=NOTE)
    wire([(X + 48, yy + PS / 2), (PX0, yy + PS / 2)], sw=1.0, size=3)
    for c in range(4):
        hl = (r, c) == (3, 3)
        box(PX0 + c * P, yy, PS, PS, "PE", fill=HDR, stroke=RED if hl else HDR, fs=11, bold=True, fc=WHITE,
            sw=2 if hl else 1)
        if c < 3:
            wire([(PX0 + c * P + PS, yy + PS / 2), (PX0 + (c + 1) * P, yy + PS / 2)], sw=0.9, size=3)
        if r < 3:
            wire([(PX0 + c * P + PS / 2, yy + PS), (PX0 + c * P + PS / 2, yy + RP)], sw=0.9, size=3)
wire([(722, 130), (728, 130), (728, PY0 + PS / 2), (X + 48, PY0 + PS / 2)], sw=1.2, end="none")
wire([(X + 48, PY0 + PS / 2), (X + 48, PY0 + 3 * RP + PS / 2)], sw=1.2, end="none")
step(X + 2, 84, 2, "Issue", "grp", w=40)
step(PX0 + 3 * P + PS + 4, PY0 + RP + 12, 4, "Add", "pe", w=40)
text(PX0 - 8, PY0 + 3 * RP + PS + 6, 4 * P, 14, "trains → along rows · partial sums ↓ down columns", fs=8, color=NOTE)

# ======================================================================================== (c) output stage
container(318, 250, 404, 218, "c", "(c) Output Stage", bottom=True)
box(330, 272, 380, 50, "Post-processing Unit", fill=HDR, stroke=HDR, fs=13, bold=True, fc=WHITE)
wire([(PX0 + PS / 2, PY0 + 3 * RP + PS), (PX0 + PS / 2, 452), (728, 452), (728, 297), (710, 297)], sw=1.4)
step(712, 274, 5, "", "pe")
box(330, 360, 270, 34, "<b>Output Buffer</b> · partial sums per (filter, position)", fill=OBUF, stroke=INK, fs=10)
box(612, 360, 98, 34, "<b>LIF</b>", fill=LIF, stroke=INK, fs=11)
wire([(520, 322), (520, 360)], sw=1.2, size=4)
wire([(600, 377), (612, 377)], sw=1.2, size=4)
step(526, 332, 6, "Accumulate", "pe", w=80)
step(616, 400, 7, "Fire (last tile)", "pe", w=100)
wire([(710, 377), (716, 377), (716, 476), (106, 476), (106, 288)], sw=1.0, dashed=True)
text(150, 478, 300, 12, "output spikes → Spike Buffer (next layer)", fs=8, color=NOTE)


# ======================================================================================== (d) processing element
D0, DY, DW, DH = 8, 498, 1176, 236
container_d = box(D0, DY, DW, DH, "", fill="#FCF1E9", stroke="#7F7F7F", sw=1.0, r=10, dashed=True)
text(D0, DY + DH - 24, DW, 20, "(d) Processing Element", fs=14)
hl = (PX0 + 3 * P, PY0 + 3 * RP)                           # the highlighted PE in (b)
wire([(hl[0], hl[1] + PS), (D0 + 760, DY)], color="#7F7F7F", sw=0.8, end="none", dashed=True)
wire([(hl[0] + PS, hl[1] + PS), (D0 + 1170, DY)], color="#7F7F7F", sw=0.8, end="none", dashed=True)


def mux(x, y, w, h, label="", direction="east"):
    add(label, f"shape=trapezoid;perimeter=trapezoidPerimeter;whiteSpace=wrap;html=1;fixedSize=1;size=8;"
               f"direction={direction};fillColor={ONE};strokeColor={INK};fontFamily={FONT};fontSize=8;"
               f"fontColor={WHITE};fontStyle=1;", geo(x, y, w, h))


# inputs from the left PE
for i, (lab, yy) in enumerate([("valid, parity", DY + 128), ("spike bits s[t]  (T)", DY + 152),
                               ("member labels ℓ[t]  (2 b × T)", DY + 176)]):
    text(D0 + 12, yy - 16, 190, 14, lab, fs=9, align="left")
    wire([(D0 + 12, yy), (D0 + 236, yy)], sw=1.1, size=4)
text(D0 + 12, DY + 92, 190, 14, "<b>from the left PE</b>", fs=9, align="left", color=NOTE)
# weight path
text(D0 + 12, DY + 22, 160, 14, "weight load (per tile)", fs=9, align="left")
text(D0 + 12, DY + 36, 160, 14, "w (8 b) · filter label f (2 b)", fs=8, align="left", color=NOTE)
wire([(D0 + 12, DY + 54), (D0 + 180, DY + 54)], sw=1.1, size=4)
box(D0 + 180, DY + 38, 100, 32, "<b>Shadow Reg</b><br><span style='font-size:8px'>w | f | parity</span>", fill=SIG,
    stroke=INK, fs=9)
mux(D0 + 296, DY + 32, 22, 44, "", "east")
text(D0 + 286, DY + 78, 60, 12, "swap", fs=8, color=NOTE)
box(D0 + 334, DY + 38, 100, 32, "<b>Active Reg</b><br><span style='font-size:8px'>w | f | parity</span>", fill=SIG,
    stroke=INK, fs=9)
wire([(D0 + 280, DY + 54), (D0 + 296, DY + 54)], sw=1.0, size=3)
wire([(D0 + 318, DY + 54), (D0 + 334, DY + 54)], sw=1.0, size=3)
text(D0 + 446, DY + 30, 230, 48, "new pass (parity ≠ active) → shadow becomes active;<br>the next tile's weight "
     "loads behind the current pass", fs=8, align="left", color=NOTE)
# T lanes
LX, LY = D0 + 246, DY + 96
for k in (2, 1):
    box(LX + 4 * k, LY - 4 * k, 486, 100, "", fill=WHITE, stroke="#7F7F7F", sw=0.8)
box(LX, LY, 486, 100, "", fill=WHITE, stroke=INK, sw=1.0)
text(LX + 250, LY + 4, 230, 14, "<b>lane t</b> (× T = 8, one per timestep)", fs=9, align="right")
box(LX + 10, LY + 30, 92, 40, "<b>Slot Index</b><br><span style='font-size:8px'>{f, ℓ[t]} → 4 b</span>",
    fill=HDR, stroke=HDR, fs=9, fc=WHITE)
mux(LX + 120, LY + 22, 26, 56, "16:1", "east")
add("+", f"ellipse;html=1;fillColor={HDR};strokeColor={HDR};fontColor={WHITE};fontFamily={FONT};fontSize=14;"
         f"fontStyle=1;", geo(LX + 168, LY + 38, 24, 24))
box(LX + 212, LY + 30, 108, 40, "<b>Gate</b><br><span style='font-size:8px'>v ∧ s[t] ∧ (w ≠ 0)</span>", fill=HDR,
    stroke=HDR, fs=9, fc=WHITE)
mux(LX + 340, LY + 22, 26, 56, "1:16", "west")
text(LX + 380, LY + 26, 100, 48, "write back to the<br>selected slot,<br>set its touch bit", fs=8, align="left",
     color=NOTE)
wire([(LX + 102, LY + 50), (LX + 120, LY + 50)], sw=1.0, size=3)
wire([(LX + 146, LY + 50), (LX + 168, LY + 50)], sw=1.0, size=3)
wire([(LX + 192, LY + 50), (LX + 212, LY + 50)], sw=1.0, size=3)
wire([(LX + 320, LY + 50), (LX + 340, LY + 50)], sw=1.0, size=3)
wire([(LX + 56, LY + 70), (LX + 56, LY + 86), (LX + 133, LY + 86), (LX + 133, LY + 72)], sw=0.9, size=3)
wire([(LX + 133, LY + 86), (LX + 353, LY + 86), (LX + 353, LY + 72)], sw=0.9, size=3)
text(LX + 160, LY + 86, 120, 12, "slot select", fs=7, color=NOTE)
wire([(D0 + 384, DY + 70), (D0 + 384, DY + 84), (LX + 180, DY + 84), (LX + 180, LY + 38)], sw=1.0, size=3)
text(LX + 184, DY + 76, 20, 12, "w", fs=8, bold=True)
wire([(D0 + 400, DY + 70), (D0 + 400, DY + 88), (LX + 40, DY + 88), (LX + 40, LY + 30)], sw=1.0, size=3)
text(LX + 44, DY + 84, 20, 12, "f", fs=8, bold=True)
# partial-sum bundle in / out
box(LX + 506, DY + 20, 200, 44, "<b>Bundle In</b> (from PE above)<br><span style='font-size:8px'>16 slots × T × 10 b "
                               "+ 16 touch bits</span>", fill=NOY, stroke=INK, fs=9)
wire([(LX + 606, DY + 64), (LX + 606, DY + 82), (LX + 133, DY + 82), (LX + 133, LY + 22)], sw=1.0, size=3)
text(LX + 410, DY + 70, 110, 12, "read: old sum", fs=8, color=NOTE)
box(LX + 506, LY + 30, 200, 44, "<b>Bundle Reg</b> → PE below<br><span style='font-size:8px'>untouched slots pass "
                               "through</span>", fill=NOY, stroke=INK, fs=9)
wire([(LX + 486, LY + 52), (LX + 506, LY + 52)], sw=1.1, size=4)
wire([(LX + 606, LY + 74), (LX + 606, LY + 104)], sw=1.1, size=4)
text(LX + 612, LY + 92, 90, 12, "to PE below", fs=8, color=NOTE, align="left")
box(LX + 726, LY + 30, 150, 44, "<b>Pass-through Reg</b><br><span style='font-size:8px'>s[t], ℓ[t], v, parity</span>",
    fill=WHITE, stroke=INK, fs=9)
wire([(D0 + 236, DY + 152), (D0 + 236, LY + 112), (LX + 801, LY + 112), (LX + 801, LY + 74)], sw=1.0, size=3)
wire([(LX + 876, LY + 52), (LX + 912, LY + 52)], sw=1.1, size=4)
text(LX + 878, LY + 34, 50, 14, "to right PE", fs=7, color=NOTE)

xml = ('<mxfile host="drawio"><diagram id="tidesppu" name="TIDES processing unit"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "3", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "2.5", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
