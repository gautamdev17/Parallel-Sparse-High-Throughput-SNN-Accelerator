"""
make_pe_grid.py -- the TIDES processing element (ours_pe in hw/rtl/ours/ours_core.v) on a clean grid, Verdana bold
(the font of the paper's Fig. 2). Top row: Row Reg, Bundle In, Weight Reg (shadow + active). One lane,
stacked x T: Read (16:1) -> + w -> Write (1:16), driven by the Lane Decode (slot = {f, l[t]}, we = v & s[t] &
(w != 0)). Right: Bundle Reg (written slot + touch, untouched slots copied) to the PE below; the row word goes on to
the right PE.

  python3 make_pe_grid.py   -> <repo>/TIDES_pe_grid.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_pe_grid")
FONT = "Verdana"                                      # as in the paper's Fig. 2
INK, NOTE = "#1A1A1A", "#555555"
FRAME, FRAME_S = "#F3F6FB", "#4A6A9B"
ROWR, ROWR_S = "#E1D5E7", "#7D5A93"                  # row register
WREG, WREG_S = "#D5E8D4", "#5E8F4E"                  # weight register
BUN, BUN_S = "#FFF2CC", "#C9A93A"                    # running sums
LOGIC, LOGIC_S = "#DAE8FC", "#5A7FB5"                # lane datapath
DEC, DEC_S = "#DDF1EA", "#4D8C7A"                    # lane decode

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill="#FFFFFF", stroke=INK, fs=12, sw=1.2, r=8):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={INK};spacing=2;fontStyle=1;")
    add(label, st, geo(x, y, w, h))


def lbl(title, sub):
    return f"{title}<br><span style='font-size:9px;color:{NOTE}'>{sub}</span>"


def text(x, y, w, h, label, fs=10, align="left", color=NOTE):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;fontStyle=1;")
    add(label, st, geo(x, y, w, h))


def wire(pts, label="", jump=False, size=6):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow=block;endFill=1;endSize={size};html=1;rounded=0;strokeColor={INK};strokeWidth=1.3;"
          f"{'jumpStyle=arc;jumpSize=8;' if jump else ''}")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


C1, C2, C3, C4, C5 = 70, 200, 320, 440, 560          # grid columns
W, H = 610, 300

# ---------------------------------------------------------------- frame
box(0, 0, W, H, "", fill=FRAME, stroke=FRAME_S, sw=2.2, r=16)
text(16, 6, 200, 20, "Processing Element", fs=14, color=INK)

# ---------------------------------------------------------------- top row: registers
box(C1 - 50, 32, 100, 48, lbl("Row Reg", "v · s[t] · ℓ[t]"), fill=ROWR, stroke=ROWR_S)
box(C2 - 55, 32, 110, 48, lbl("Bundle In", "16 slots × T sums"), fill=BUN, stroke=BUN_S)
box(C3 - 44, 26, 100, 48, "", fill="#EAF3E7", stroke=WREG_S)                      # shadow copy behind
box(C3 - 50, 32, 100, 48, lbl("Weight Reg", "w · f  (+ shadow)"), fill=WREG, stroke=WREG_S)

wire([(-40, 56), (C1 - 50, 56)])
text(-42, 36, 80, 16, "from left PE", fs=9, color=INK)
wire([(C2, -24), (C2, 32)])
text(C2 + 6, -24, 90, 16, "from PE above", fs=9, color=INK)
wire([(C3 + 6, -24), (C3 + 6, 26)])
text(C3 + 12, -24, 90, 16, "weight load", fs=9, color=INK)

# ---------------------------------------------------------------- one lane, stacked x T
LX, LY, LW, LH = 140, 112, 350, 152
for k in (2, 1):
    box(LX + 5 * k, LY - 5 * k, LW, LH, "", fill="#FFFFFF", stroke="#A9B6CC", sw=0.9, r=10)
box(LX, LY, LW, LH, "", fill="#FFFFFF", stroke=LOGIC_S, sw=1.2, r=10)
text(LX + LW - 196, LY + LH - 18, 190, 14, "lane t  (× T, one per timestep)", fs=9, align="right")

box(C2 - 40, 130, 80, 44, lbl("Read", "16 : 1"), fill=LOGIC, stroke=LOGIC_S)
add("+ w", f"ellipse;html=1;fillColor={LOGIC};strokeColor={LOGIC_S};strokeWidth=1.2;fontFamily={FONT};"
           f"fontSize=12;fontStyle=1;", geo(C3 - 21, 131, 42, 42))
box(C4 - 40, 130, 80, 44, lbl("Write", "1 : 16"), fill=LOGIC, stroke=LOGIC_S)
box(C2 - 40, 194, C3 + 40 - (C2 - 40), 52,
    lbl("Lane Decode", "slot = {f, ℓ[t]}<br>we = v · s[t] · (w ≠ 0)"), fill=DEC, stroke=DEC_S)

# ---------------------------------------------------------------- right: bundle register
box(C5 - 32, 32, 64, 232, lbl("Bundle<br>Reg", "written<br>slot +<br>touch;<br>others<br>copied"), fill=BUN,
    stroke=BUN_S)

# ---------------------------------------------------------------- wires
wire([(C2, 80), (C2, 130)])                                       # old sums
text(C2 + 6, 92, 60, 14, "old sum", fs=9)
wire([(C3, 80), (C3, 131)])                                       # weight
text(C3 + 6, 92, 20, 14, "w", fs=10)
wire([(C2 + 40, 152), (C3 - 21, 152)])
wire([(C3 + 21, 152), (C4 - 40, 152)])
wire([(C4 + 40, 152), (C5 - 32, 152)])                            # new sum
text(C4 + 42, 134, 40, 14, "sum", fs=9)
wire([(C3 + 40, 80), (C3 + 40, 194)], jump=True)                  # f, w != 0 -> decode
text(C3 + 46, 92, 60, 14, "f, w≠0", fs=9)
wire([(C1, 80), (C1, 222), (C2 - 40, 222)])                       # row word -> decode
text(C1 + 6, 182, 70, 14, "s[t], ℓ[t], v", fs=9)
wire([(C2, 194), (C2, 174)], size=5)                              # slot -> read
text(C2 + 6, 177, 30, 14, "slot", fs=9)
wire([(C3 + 40, 222), (C4, 222), (C4, 174)], size=5)              # slot, we -> write
text(C4 + 6, 178, 60, 14, "slot, we", fs=9)
wire([(C1 - 24, 80), (C1 - 24, 284), (W + 40, 284)])   # row word -> right PE
text(W - 6, 266, 90, 14, "to right PE", fs=9, color=INK)
wire([(C5, 264), (C5, H + 34)], jump=True)
text(C5 + 6, H + 18, 90, 14, "to PE below", fs=9, color=INK)

xml = ('<mxfile host="drawio"><diagram id="tidespe5" name="TIDES PE"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "3", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "3", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
