"""
make_pe_compact.py -- compact diagram of the TIDES processing element (ours_pe in hw/rtl/ours/ours_core.v), in the
hand-drawn font of LoAS's TPPE figure (Comic Sans MS) but its own layout: the T lanes are drawn as rows, one per
timestep (spike bit + member label -> slot select {f, l[t]} -> +w), the stationary weight register feeds w and f
down two buses, and the running-sum bundle (16 slots x T) is a strip flowing from the PE above to the PE below, with
each active lane writing its timestep of the selected slot. Lane t=2 is shown idle (no spike, no add).

  python3 make_pe_compact.py   -> <repo>/TIDES_pe_compact.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_pe_compact")
FONT = "Comic Sans MS"
INK, GREY = "#1A1A1A", "#9A9A9A"
FRAME, FRAME_S = "#F3F6FB", "#4A6A9B"                # PE container
WREG, WREG_S = "#D5E8D4", "#5E8F4E"                  # weight register
ROWR = "#E1D5E7"                                     # row register
SEL, SEL_S = "#DDF1EA", "#4D8C7A"                    # slot select
SPIKE = "#7EA6E1"                                    # a '1' spike bit
BUN, BUN_S, HOT = "#FFF2CC", "#C9A93A", "#F7C873"    # running-sum strip, written slot

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill="#FFFFFF", stroke=INK, fs=11, sw=1.0, r=6, fc=INK, dashed=False, horiz=True):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={fc};spacing=1;"
          f"horizontal={1 if horiz else 0};{'dashed=1;dashPattern=3 3;' if dashed else ''}")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=10, align="center", color=INK):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;")
    add(label, st, geo(x, y, w, h))


def wire(pts, sw=1.2, end="block", size=5, color=INK, dashed=False):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow={end};endFill=1;endSize={size};html=1;rounded=0;strokeColor={color};strokeWidth={sw};"
          f"jumpStyle=arc;jumpSize=7;{'dashed=1;dashPattern=3 3;' if dashed else ''}")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def circle(cx, cy, r, label, stroke=INK, fc=INK, fill="#FFFFFF"):
    add(label, f"ellipse;html=1;fillColor={fill};strokeColor={stroke};strokeWidth=1.2;fontFamily={FONT};"
               f"fontSize=11;fontColor={fc};", geo(cx - r, cy - r, 2 * r, 2 * r))


# ---------------------------------------------------------------- container
W, H = 430, 318
box(0, 0, W, H, "", fill=FRAME, stroke=FRAME_S, sw=2, r=14)
text(12, 8, 160, 20, "Processing Element", fs=14, align="left")

# ---------------------------------------------------------------- weight register (stationary, double-buffered)
box(186, 26, 112, 38, "", fill="#EEF5EC", stroke=WREG_S, r=6)                       # shadow behind
box(180, 32, 112, 38, "Weight Reg<br><span style='font-size:9px'>w | f</span>", fill=WREG, stroke=WREG_S)
wire([(236, -26), (236, 26)])
text(242, -26, 120, 14, "weight load (shadow)", fs=9, align="left")

# ---------------------------------------------------------------- lanes, one per timestep
SX, SY, SW_, SH = 330, 38, 46, 224                  # running-sum strip
LANES = [("t=1", 98, "1", "0"), ("t=2", 138, "0", ""), (None, 178, None, None), ("t=T", 218, "1", "2")]
BX = 34                                             # row register
box(BX - 20, 80, 20, 156, "Row Reg", fill=ROWR, r=4, fs=9, horiz=False)
wire([(-46, 158), (BX - 20, 158)])
text(-48, 140, 70, 14, "from left PE", fs=9, align="left")
wire([(BX - 10, 236), (BX - 10, 292), (W + 50, 292)])                              # row word passes on
text(W + 4, 276, 70, 14, "to right PE", fs=9, align="left")

# buses from the weight register (drawn first, the blocks sit on top)
wire([(205, 70), (205, 204)], end="none", color=SEL_S, sw=1.4)
text(209, 72, 12, 12, "f", fs=10, align="left", color=SEL_S)
wire([(258, 70), (258, 204)], end="none", color=WREG_S, sw=1.4)
text(262, 72, 14, 12, "w", fs=10, align="left", color=WREG_S)

for lab, y, s, l in LANES:
    if lab is None:
        text(BX + 12, y - 10, 44, 20, "⋮", fs=14)
        text(BX + 60, y - 7, 84, 14, "× T lanes", fs=9, align="left")
        continue
    on = s == "1"
    wire([(BX, y), (BX + 12, y)], size=4, color=INK if on else GREY)
    box(BX + 12, y - 11, 22, 22, s, fill=SPIKE if on else "#FFFFFF", r=0, fs=10,
        fc="#FFFFFF" if on else GREY, stroke=INK if on else GREY)
    box(BX + 34, y - 11, 22, 22, l if on else "–", fill="#FFFFFF", r=0, fs=10, fc=INK if on else GREY,
        stroke=INK if on else GREY)
    wire([(BX + 56, y), (178, y)], size=4, color=INK if on else GREY, dashed=not on)
    box(178, y - 14, 54, 28, "{f, ℓ}", fill=SEL if on else "#F4F4F4", stroke=SEL_S if on else GREY, fs=10,
        fc=INK if on else GREY)
    wire([(232, y), (245, y)], size=4, color=INK if on else GREY, dashed=not on)
    circle(258, y, 13, "+w", stroke=INK if on else GREY, fc=INK if on else GREY)
    if on:
        wire([(271, y), (SX, y)], size=5)
        text(276, y - 15, 50, 12, lab, fs=9, align="left")
    else:
        text(276, y - 15, 50, 12, lab, fs=9, align="left", color=GREY)
        text(272, y - 2, 60, 14, "no add", fs=8, color=GREY, align="left")
text(BX + 12, 72, 44, 12, "s[t]   ℓ[t]", fs=8)

# ---------------------------------------------------------------- running-sum strip (16 slots x T)
NS = 16
rh = SH / NS
for i in range(NS):
    y0 = SY + i * rh
    hot = any(lab and s == "1" and y0 <= y < y0 + rh for lab, y, s, l in LANES)
    box(SX, y0, SW_, rh, "", fill=HOT if hot else BUN, stroke=BUN_S, r=0, sw=0.8)
text(SX + SW_ + 4, SY + 64, 64, 92, "running<br>sums<br>16 slots<br>× T<br>× 10 b", fs=9, align="left")
wire([(SX + SW_ / 2, -26), (SX + SW_ / 2, SY)])
text(SX + SW_ / 2 + 6, -26, 90, 14, "from PE above", fs=9, align="left")
wire([(SX + SW_ / 2, SY + SH), (SX + SW_ / 2, H + 40)])
text(SX + SW_ / 2 + 6, H + 24, 90, 14, "to PE below", fs=9, align="left")

xml = ('<mxfile host="drawio"><diagram id="tidespe3" name="TIDES PE"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "3", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "3", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
