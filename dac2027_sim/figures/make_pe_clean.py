"""
make_pe_clean.py -- the TIDES processing element (ours_pe in hw/rtl/ours/ours_core.v) in the layout of LoAS's TPPE
figure: one rounded container, top-to-bottom flow, few boxes, labelled arrows. Registers on top (row word, shadow /
active weight), the slot index {f, l[t]} in the middle, the T adders (one per timestep, fed by the stationary weight,
enabled by s[t]) in one panel, and the running-sum bundle (16 slots x T) at the bottom, in from the PE above and
out to the PE below.

  python3 make_pe_clean.py   -> <repo>/TIDES_pe_clean.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_pe_clean")
FONT = "Helvetica"
INK = "#1A1A1A"
PEACH, ORANGE = "#FFE6CC", "#D79B00"                 # container
LAV = "#E1D5E7"                                      # registers
MINT = "#DDF1EA"                                     # slot index
PANEL, PANEL_S = "#D6E2F3", "#7A8FB0"                # adder panel
BUN, BUN_S = "#F5F5F5", "#666666"                    # running-sum bundle

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill="#FFFFFF", stroke=INK, fs=12, sw=1.0, r=8, valign="middle"):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={INK};"
          f"verticalAlign={valign};spacing=2;")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=11, align="center"):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={INK};align={align};"
          f"verticalAlign=middle;spacing=0;")
    add(label, st, geo(x, y, w, h))


def wire(pts, sw=1.2, end="block", size=6):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = f"endArrow={end};endFill=1;endSize={size};html=1;rounded=0;strokeColor={INK};strokeWidth={sw};"
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def adder(cx, cy, r=11):
    add("+", f"ellipse;html=1;fillColor=#FFFFFF;strokeColor={INK};strokeWidth=1.2;fontFamily={FONT};fontSize=14;"
             f"fontStyle=1;verticalAlign=middle;spacingBottom=2;", geo(cx - r, cy - r, 2 * r, 2 * r))


# ---------------------------------------------------------------- container
W, H = 640, 590
box(0, 0, W, H, "", fill=PEACH, stroke=ORANGE, sw=2.2, r=18)
text(170, 12, 300, 30, "Processing Element", fs=20)

# ---------------------------------------------------------------- registers (top)
box(40, 80, 160, 46, "Row Reg<br><span style='font-size:10px'>s[t], ℓ[t], valid, parity</span>", fill=LAV)
wire([(-60, 103), (40, 103)])
text(-62, 84, 100, 16, "from left PE", fs=10, align="left")
wire([(120, 80), (120, 58), (W + 60, 58)])                         # row word passes on
text(W + 2, 40, 80, 16, "to right PE", fs=10, align="left")

box(440, 80, 160, 40, "Shadow Reg<br><span style='font-size:10px'>next w | f</span>", fill=LAV)
wire([(W + 60, 100), (600, 100)])
text(W + 2, 104, 90, 16, "weight load", fs=10, align="left")
box(440, 146, 160, 40, "Active Reg<br><span style='font-size:10px'>w (8 b) | f (2 b)</span>", fill=LAV)
wire([(520, 120), (520, 146)], size=5)
text(526, 124, 110, 16, "swap on new pass", fs=10, align="left")

# ---------------------------------------------------------------- slot index (middle)
box(240, 196, 160, 40, "Slot Index<br><span style='font-size:10px'>{f, ℓ[t]} → 1 of 16</span>", fill=MINT,
    stroke="#4D8C7A")
wire([(80, 126), (80, 216), (240, 216)])
text(86, 196, 60, 16, "ℓ[t]", fs=11, align="left")
wire([(470, 186), (470, 216), (400, 216)])
text(440, 196, 30, 16, "f", fs=11, align="left")

# ---------------------------------------------------------------- T adders (one per timestep)
PX, PY, PW, PH = 60, 278, 520, 100
box(PX, PY, PW, PH, "", fill=PANEL, stroke=PANEL_S, r=4)
text(PX + 8, PY + 3, 230, 16, "T adders, one per timestep", fs=12, align="left")
XS = [130, 190, 250, 310, 510]                                     # t = 1, 2, 3, 4, ..., T
BUS = PY + 22
wire([(570, 186), (570, BUS), (XS[0], BUS)], end="none")           # stationary weight to every adder
text(574, 230, 60, 16, "w", fs=11, align="left")
for x in XS:
    wire([(x, BUS), (x, PY + 49)], size=5)
    adder(x, PY + 60)
for i, x in enumerate((370, 400, 430, 460)):
    add("", f"ellipse;html=1;fillColor={INK};strokeColor={INK};", geo(x - 2.5, PY + 57.5, 5, 5))
for x, t in zip(XS, ("t=1", "t=2", "t=3", "t=4", "t=T")):
    text(x + 13, PY + 53, 30, 14, t, fs=9, align="left")
wire([(320, 236), (320, PY)])                                      # slot index -> lanes
text(326, 244, 120, 16, "slot of each lane", fs=10, align="left")
wire([(40, 126), (40, PY + 60), (PX, PY + 60)], size=5)            # spike bits enable the lanes
text(4, PY + 64, 56, 28, "s[t]<br>enables t", fs=9)

# ---------------------------------------------------------------- running-sum bundle (bottom)
BX, BY, BW, BH = 120, 440, 400, 126
box(BX, BY, BW, BH, "Running-Sum Bundle  <span style='font-size:10px'>(16 slots × T × 10 b + touch bits)</span>",
    fill=BUN, stroke=BUN_S, r=0, valign="top", fs=12)
CW, CH, GX, GY = 36, 18, BX + 62, BY + 30
for r, lab in enumerate(("slot 0", "slot 1", "⋮", "slot 15")):
    text(BX + 6, GY + r * CH, 54, CH, lab, fs=10)
    for c, t in enumerate(("t=1", "t=2", "t=3", "t=4", "t=5", "t=6", "t=7", "t=8")):
        if lab == "⋮":
            continue
        box(GX + c * CW, GY + r * CH, CW, CH, t if r == 0 else "", fill="#FFFFFF", r=0, fs=9, sw=0.8)
for x in XS:                                                       # adders write into the selected slot
    wire([(x, PY + 71), (320, BY - 18)], end="none", sw=1.0)
wire([(320, BY - 18), (320, BY)])
text(328, BY - 17, 220, 14, "read slot, add w, write back", fs=10, align="left")
wire([(-60, BY + 63), (BX, BY + 63)])
text(-62, BY + 44, 120, 16, "from PE above", fs=10, align="left")
wire([(BX + BW, BY + 63), (W + 60, BY + 63)])
text(W + 2, BY + 44, 90, 16, "to PE below", fs=10, align="left")

xml = ('<mxfile host="drawio"><diagram id="tidespe2" name="TIDES PE"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "3", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "2.5", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
