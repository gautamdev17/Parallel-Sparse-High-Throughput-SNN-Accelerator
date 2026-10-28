"""
make_pe_dense.py -- dense block diagram of the TIDES processing element (ours_pe in hw/rtl/ours/ours_core.v), in the
hand-drawn font of LoAS's TPPE figure (Comic Sans MS). Lanes are columns (t = 1, 2, ..., T): each reads its slot of
the incoming bundle (16:1), adds the stationary weight, and writes the sum into the outgoing bundle register (1:16),
with the slot {f, l[t]} and the write enable s[t] & v & (w != 0). Left: shadow / active weight registers with the
parity swap and the zero test, and the row register whose word (valid, parity, s[t], l[t]) is tapped per lane and
passed to the right PE. Untouched slots go from Bundle In to the Bundle Reg unchanged.

  python3 make_pe_dense.py   -> <repo>/TIDES_pe_dense.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_pe_dense")
FONT = "Comic Sans MS"
INK, GREY = "#1A1A1A", "#8C8C8C"
FRAME, FRAME_S = "#F3F6FB", "#4A6A9B"
WREG, WREG_S = "#D5E8D4", "#5E8F4E"
ROWR, ROWR_S = "#E1D5E7", "#7D5A93"
SEL, SEL_S = "#DDF1EA", "#4D8C7A"
MUX = "#7EA6E1"
BUN, BUN_S = "#FFF2CC", "#C9A93A"
LANE = "#FFFFFF"

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill="#FFFFFF", stroke=INK, fs=10, sw=1.0, r=5, fc=INK, horiz=True, dashed=False):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={fc};spacing=0;"
          f"horizontal={1 if horiz else 0};{'dashed=1;dashPattern=3 3;' if dashed else ''}")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=9, align="center", color=INK):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;")
    add(label, st, geo(x, y, w, h))


def wire(pts, sw=1.1, end="block", size=4, color=INK, jump=False):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    JUMP = "jumpStyle=arc;jumpSize=6;" if jump else ""
    st = (f"endArrow={end};endFill=1;endSize={size};html=1;rounded=0;strokeColor={color};strokeWidth={sw};"
          f"{JUMP}")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def dot(x, y, color=INK):
    add("", f"ellipse;html=1;fillColor={color};strokeColor={color};", geo(x - 2, y - 2, 4, 4))


def mux(x, y, w, h, label, direction):
    add(label, f"shape=trapezoid;perimeter=trapezoidPerimeter;whiteSpace=wrap;html=1;fixedSize=1;size=5;"
               f"direction={direction};fillColor={MUX};strokeColor={INK};fontFamily={FONT};fontSize=7;"
               f"fontColor=#FFFFFF;", geo(x, y, w, h))


def adder(cx, cy, r=9):
    add("+", f"ellipse;html=1;fillColor=#FFFFFF;strokeColor={INK};strokeWidth=1.2;fontFamily={FONT};fontSize=12;"
             f"fontStyle=1;", geo(cx - r, cy - r, 2 * r, 2 * r))


def and_gate(x, y, w=22, h=16):
    add("", "shape=mxgraph.electrical.logic_gates.logic_gate;operation=and;html=1;fillColor=#FFFFFF;"
            f"strokeColor={INK};strokeWidth=1;", geo(x, y, w, h))


# ---------------------------------------------------------------- frame
W, H = 572, 262
box(0, 0, W, H, "", fill=FRAME, stroke=FRAME_S, sw=2, r=12)
text(196, 22, 200, 16, "Processing Element", fs=13, align="left")

# ---------------------------------------------------------------- bus rows (y)
Y_BIN, Y_F, Y_ROW, Y_W, Y_BOUT = 46, 98, 114, 136, 212
LANES = [(242, "t=1"), (352, "t=2"), (500, "t=T")]

# Bundle In / Bundle Reg bars
box(198, Y_BIN, 356, 16, "<b>Bundle In</b>  16 slots × T sums (10 b) + 16 touch bits", fill=BUN, stroke=BUN_S, fs=9,
    r=2)
wire([(482, -22), (482, Y_BIN)])
text(488, -22, 80, 12, "from PE above", fs=8, align="left")
box(198, Y_BOUT, 356, 16, "<b>Bundle Reg</b>  written slots + touch; untouched slots pass", fill=BUN, stroke=BUN_S,
    fs=9, r=2)
wire([(548, Y_BIN + 16), (548, Y_BOUT)], size=4)
text(550, 140, 20, 40, "pass", fs=7, align="left", color=GREY)
wire([(482, Y_BOUT + 16), (482, H + 26)], jump=True)
text(488, H + 12, 80, 12, "to PE below", fs=8, align="left")

# ---------------------------------------------------------------- weight registers + swap + zero test (top left)
text(44, -22, 120, 12, "weight load", fs=8, align="left")
wire([(66, -10), (66, 26)], size=4)
box(38, 26, 56, 28, "Shadow<br><span style='font-size:7px'>w | f | p</span>", fill=WREG, stroke=WREG_S, fs=9)
mux(100, 26, 10, 28, "", "east")
box(116, 26, 60, 28, "Active<br><span style='font-size:7px'>w | f | p</span>", fill=WREG, stroke=WREG_S, fs=9)
wire([(94, 40), (100, 40)], size=3)
wire([(110, 40), (116, 40)], size=3)
box(146, 66, 26, 16, "≠0", fs=8)
wire([(160, 54), (160, 66)], size=3)
text(150, 82, 20, 12, "nz", fs=8, color=GREY)
text(32, 64, 80, 10, "swap if par ≠ p", fs=7, align="left", color=GREY)

# ---------------------------------------------------------------- row register (left) and the row word bus
box(10, 70, 18, 150, "Row Reg", fill=ROWR, stroke=ROWR_S, fs=9, horiz=False, r=4)
wire([(-40, 160), (10, 160)])
text(-42, 146, 70, 12, "from left PE", fs=8, align="left")
wire([(19, 70), (19, 62), (105, 62), (105, 54)], size=3)                       # row parity -> swap
wire([(19, 220), (19, 244), (W + 40, 244)], jump=True)                                     # row word passes on
text(W + 2, 230, 70, 12, "to right PE", fs=8, align="left")
wire([(28, Y_ROW), (532, Y_ROW)], end="none", color=ROWR_S, sw=1.6)
text(32, Y_ROW - 12, 120, 10, "v | par | s[t] | ℓ[t]", fs=7, align="left", color=ROWR_S)

# f and w buses from the active register
wire([(124, 54), (124, Y_F), (532, Y_F)], end="none", color=SEL_S, sw=1.4)
text(128, Y_F - 11, 20, 10, "f", fs=8, align="left", color=SEL_S)
wire([(136, 54), (136, Y_W), (532, Y_W)], end="none", color=WREG_S, sw=1.4)
text(140, Y_W + 2, 20, 10, "w", fs=8, align="left", color=WREG_S)

# ---------------------------------------------------------------- lanes (columns), one per timestep
for cx, lab in LANES:
    box(cx - 62, 66, 104, 140, "", fill="none", stroke="#B9C4D6", r=4, sw=0.8, dashed=True)
    text(cx - 60, 194, 40, 10, lab, fs=8, align="left", color=GREY)
    # slot select {f, l[t]}
    box(cx - 54, 72, 36, 16, "{f,ℓ}", fill=SEL, stroke=SEL_S, fs=8)
    wire([(cx - 26, Y_F), (cx - 26, 88)], size=3, color=SEL_S)                  # f
    dot(cx - 26, Y_F, SEL_S)
    wire([(cx - 46, Y_ROW), (cx - 46, 88)], size=3, color=ROWR_S)               # l[t]
    dot(cx - 46, Y_ROW, ROWR_S)
    # read: 16:1 from Bundle In
    mux(cx - 8, 70, 16, 22, "", "south")
    text(cx + 9, 74, 24, 10, "16:1", fs=7, align="left")
    wire([(cx, Y_BIN + 16), (cx, 70)], size=3)
    wire([(cx - 18, 80), (cx - 8, 80)], size=3)                                 # slot -> read select
    # add the weight
    wire([(cx, 92), (cx, 127)], size=3)
    adder(cx, Y_W)
    dot(cx - 9, Y_W, WREG_S)
    # write enable: v & s[t] & nz
    and_gate(cx - 54, 152)
    wire([(cx - 50, Y_ROW), (cx - 50, 156), (cx - 54, 156)], size=3, color=ROWR_S)
    text(cx - 60, 170, 36, 10, "v·s[t]·nz", fs=6, align="left", color=GREY)
    # write: 1:16 into Bundle Reg
    mux(cx - 8, 160, 16, 22, "", "north")
    text(cx + 9, 166, 24, 10, "1:16", fs=7, align="left")
    wire([(cx, Y_W + 9), (cx, 160)], size=3)
    wire([(cx - 32, 160), (cx - 8, 167)], size=3)                               # enable
    text(cx - 30, 150, 20, 10, "we", fs=6, align="left", color=GREY)
    wire([(cx - 36, 88), (cx - 36, 92), (cx - 36, 176), (cx - 8, 176)], size=3, color=SEL_S)   # slot -> write
    wire([(cx, 182), (cx, Y_BOUT)], size=3)
text(406, 120, 40, 20, "· · ·", fs=14)

xml = ('<mxfile host="drawio"><diagram id="tidespe4" name="TIDES PE"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "3", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "3", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
