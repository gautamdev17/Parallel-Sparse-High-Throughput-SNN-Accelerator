"""
make_pe_schematic.py -- the TIDES PE (ours_pe in hw/rtl/ours/ours_core.v) as a plain circuit schematic for the paper:
registers with clock marks, trapezoid muxes, a circled adder, an AND gate, bus slashes with widths, and one lane
stacked x T. Few words, thin black lines, two light fills, one accent for the weight path.

  python3 make_pe_schematic.py   -> <repo>/TIDES_pe.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_pe")
FONT = "Helvetica"
INK, WHITE = "#000000", "#FFFFFF"
REG = "#E7E6E6"          # registers
LANE = "#EDF2FA"         # lane tint
ACC = "#C0504D"          # weight path

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill=WHITE, stroke=INK, fs=10, sw=1.0, italic=False):
    st = (f"whiteSpace=wrap;html=1;fillColor={fill};strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};"
          f"fontSize={fs};fontColor={INK};spacing=0;fontStyle={2 if italic else 0};")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=10, align="center", italic=False, color=INK, bold=False):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;fontStyle={(2 if italic else 0) + (1 if bold else 0)};")
    add(label, st, geo(x, y, w, h))


def wire(pts, sw=1.0, end="block", size=4, color=INK):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow={end};endFill=1;endSize={size};html=1;rounded=0;strokeColor={color};strokeWidth={sw};")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def dot(x, y, color=INK):
    add("", f"ellipse;html=1;fillColor={color};strokeColor={color};", geo(x - 2, y - 2, 4, 4))


def slash(x, y, label, vertical=True, color=INK):
    wire([(x - 4, y + 4), (x + 4, y - 4)], sw=0.9, end="none", color=color)
    if vertical:
        text(x + 6, y - 7, 80, 12, label, fs=8, align="left", color=color)
    else:
        text(x - 30, y - 17, 60, 12, label, fs=8, color=color)


def reg(x, y, w, h, label=""):
    box(x, y, w, h, label, fill=REG)
    add("", "triangle;whiteSpace=wrap;html=1;direction=north;fillColor=none;strokeColor=#000000;strokeWidth=0.8;",
        geo(x + w / 2 - 4, y + h - 6, 8, 6))


def mux(x, y, w, h, label="", wide_top=True):
    add(label, f"shape=trapezoid;perimeter=trapezoidPerimeter;whiteSpace=wrap;html=1;fixedSize=1;size={h * 0.6};"
               f"{'flipV=1;' if wide_top else ''}fillColor={WHITE};strokeColor={INK};fontFamily={FONT};fontSize=9;",
        geo(x, y, w, h))


def adder(x, y, d=20):
    add("+", f"ellipse;html=1;fillColor={WHITE};strokeColor={INK};fontFamily={FONT};fontSize=14;", geo(x, y, d, d))


def and_gate(x, y, w=30, h=24):
    add("", "shape=mxgraph.electrical.logic_gates.logic_gate;operation=and;html=1;fillColor=#FFFFFF;"
            "strokeColor=#000000;strokeWidth=1;", geo(x, y, w, h))


# ------------------------------------------------------------------ row word: left -> register -> right
text(0, 22, 70, 12, "from left PE", fs=8, italic=True, align="left")
wire([(0, 50), (74, 50)], size=4)
slash(24, 50, "", vertical=False)
text(30, 34, 40, 12, "3T+2", fs=8, align="left")
reg(74, 38, 22, 24)
wire([(96, 50), (520, 50)], size=4)
text(470, 30, 56, 12, "to right PE", fs=8, italic=True, align="right")
text(4, 54, 60, 12, "v, s, ℓ", fs=9, italic=True, align="left")

# ------------------------------------------------------------------ bundle from above
text(440, 64, 80, 12, "from PE above", fs=8, italic=True, align="left")
wire([(430, 66), (430, 112)], size=3, end="none")
slash(430, 84, "16·T·10")

# ------------------------------------------------------------------ weight registers
text(0, 104, 60, 12, "load w, f", fs=8, italic=True, align="left")
wire([(0, 128), (24, 128)], size=3)
reg(24, 116, 44, 24, "W<sub>sh</sub>")
mux(30, 148, 32, 12, "", wide_top=True)
wire([(46, 140), (46, 148)], size=3, end="none")
wire([(46, 160), (46, 170)], size=3)
reg(24, 170, 44, 24, "W<sub>act</sub>")
text(64, 146, 34, 14, "swap", fs=8, italic=True, align="left")

# ------------------------------------------------------------------ lane t, stacked x T
LX, LY, LW, LH = 110, 92, 300, 186
for k in (2, 1):
    box(LX + 5 * k, LY - 5 * k, LW, LH, "", fill=WHITE, stroke="#808080", sw=0.7)
box(LX, LY, LW, LH, "", fill=LANE, stroke=INK, sw=0.9)
text(LX + LW - 40, LY + LH - 16, 36, 14, "× T", fs=10, bold=True, align="right")
text(LX + 5, LY + LH - 16, 50, 14, "lane t", fs=9, italic=True, align="left")

# taps of s[t], l[t], v from the row word (before its register)
dot(54, 50)
wire([(54, 50), (54, 78), (150, 78), (150, 104)], size=3)
text(154, 80, 30, 12, "ℓ[t]", fs=9, italic=True, align="left")
dot(40, 50)
wire([(40, 50), (40, 96), (96, 96), (96, 238), (196, 238)], size=3)
text(100, 222, 50, 12, "v, s[t]", fs=9, italic=True, align="left")

# slot index -> 16:1 read mux
box(124, 104, 58, 20, "{ f, ℓ[t] }", fs=9)
wire([(68, 182), (88, 182), (88, 114), (124, 114)], size=3, color=ACC)
text(76, 104, 12, 12, "f", fs=9, italic=True, color=ACC)
wire([(182, 114), (300, 114)], size=3)
slash(240, 114, "4", vertical=False)
dot(430, 112)
wire([(430, 112), (430, 100), (345, 100), (345, 104)], size=3, end="block")
mux(300, 104, 90, 24, "16 : 1", wide_top=True)
# adder: old sum + w
wire([(345, 128), (345, 150)], size=3)
adder(335, 150)
wire([(68, 186), (92, 186), (92, 160), (335, 160)], size=3, color=ACC)
text(310, 146, 14, 12, "w", fs=9, italic=True, color=ACC)
slash(280, 160, "8", vertical=False, color=ACC)
# write enable: v & s[t] & (w != 0)
dot(226, 160, ACC)
box(212, 192, 28, 16, "≠0", fs=9)
wire([(226, 160), (226, 192)], size=3, color=ACC)
and_gate(196, 228)
wire([(226, 208), (226, 220), (204, 220), (204, 232)], size=2)
wire([(226, 240), (300, 240)], size=3)
text(250, 226, 30, 12, "we", fs=8, italic=True)
# write-back mux: new sum into the selected slot; untouched slots pass
wire([(345, 170), (345, 228)], size=3)
slash(345, 196, "T·10")
dot(430, 112)
wire([(430, 112), (430, 228)], size=3)
mux(300, 228, 150, 24, "insert at slot · set touch", wide_top=False)
dot(194, 114)
wire([(194, 114), (194, 180), (318, 180), (318, 228)], size=3)
text(256, 168, 40, 12, "slot", fs=8, italic=True)

# ------------------------------------------------------------------ bundle register -> below
wire([(375, 252), (375, 290)], size=4)
reg(325, 290, 100, 24, "bundle + touch")
wire([(375, 314), (375, 344)], size=4)
slash(375, 328, "16·T·10 + 16")
text(384, 340, 80, 12, "to PE below", fs=8, italic=True, align="left")

xml = ('<mxfile host="drawio"><diagram id="pe" name="TIDES PE"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "3", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "3", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
