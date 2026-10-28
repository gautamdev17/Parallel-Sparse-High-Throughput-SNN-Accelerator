"""
make_pe_example.py -- the TIDES PE drawn in the visual language of the paper's Fig. 2 (Figures/Compression.png):
framed panels, coloured spike cells with member labels, dashed group boxes, hollow grey block arrows, bold captions
under each panel and a legend box. One cycle of the PE in row K2 processing G1 = {P0, P1} of Fig. 2(d):
weight 1 | B, packed train 0111 with member labels (-, 0, 1, 1) -> +1 to (B,P0) @t1 and (B,P1) @t2, t3.
Partial sums in/out are those of the running example (DAC2027_accelerator_explained_rows.pdf, Fig. 10).

  python3 make_pe_example.py   -> <repo>/TIDES_pe.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_pe")
FONT = "Verdana"
INK, WHITE = "#000000", "#FFFFFF"
PX = {0: "#7EA6E1", 1: "#FFD966", 2: "#96D076", 3: "#A680B8"}
SILENT = "#F2F2F2"
RED, PINK, SLATE, SLATE_L = "#C00000", "#FFCCCC", "#44546A", "#D6DCE5"
HOT, G1 = "#FFE699", "#E04040"

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill=WHITE, stroke=INK, fs=11, bold=True, fc=INK, sw=1.0, dashed=False, r=0):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={fc};spacing=0;"
          f"{'fontStyle=1;' if bold else ''}{'dashed=1;dashPattern=4 3;' if dashed else ''}")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=11, bold=True, color=INK, align="center"):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;fontStyle={1 if bold else 0};")
    add(label, st, geo(x, y, w, h))


def line(pts, color=INK, sw=1.0, end="block", size=5, dashed=False):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow={end};endFill=1;endSize={size};html=1;rounded=0;strokeColor={color};strokeWidth={sw};"
          f"{'dashed=1;dashPattern=4 3;' if dashed else ''}")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def big_arrow(x, y, w, h, direction="east"):
    add("", f"shape=singleArrow;direction={direction};whiteSpace=wrap;html=1;arrowWidth=0.45;arrowSize=0.42;"
            f"fillColor=#F2F2F2;strokeColor=#7F7F7F;strokeWidth=1.2;", geo(x, y, w, h))


def train(x, y, owners, labels=None, cw=26, ch=24, fs=11):
    for t, o in enumerate(owners):
        lab = "" if (labels is None or o is None) else str(labels[t])
        box(x + t * cw, y, cw, ch, lab, fill=PX[o] if o is not None else WHITE, fs=fs)


def sums(x, y, rows, hot=(), cw=30, lw=56):
    for i, (lab, vals) in enumerate(rows):
        yy = y + i * 26
        f = lab[0]
        box(x, yy, lw, 26, lab, fill=PINK if f == "A" else SLATE_L, fc=RED if f == "A" else SLATE, fs=11)
        for t, v in enumerate(vals):
            box(x + lw + t * cw, yy, cw, 26, str(v), fill=HOT if (lab, t) in hot else WHITE, fs=11)
    for t in range(4):
        text(x + lw + t * cw, y - 18, cw, 14, f"t{t}", fs=10, bold=False)


SIN = [("A,P0", [2, 0, 0, 0]), ("A,P1", [0, 0, 0, 0]), ("B,P0", [0, 0, 0, 0]), ("B,P1", [0, 0, 3, 0])]
SOUT = [("A,P0", [2, 0, 0, 0]), ("A,P1", [0, 0, 0, 0]), ("B,P0", [0, 1, 0, 0]), ("B,P1", [0, 0, 4, 1])]
OWN = [None, 0, 1, 1]          # G1 on K2: bit t1 from P0, t2 and t3 from P1
LAB = [None, 0, 1, 1]

# ===================================================================== frames
W1, W2, W3, H = 330, 520, 330, 380
X1, X2, X3 = 10, 10 + W1, 10 + W1 + W2
for x, w in ((X1, W1), (X2, W2), (X3, W3)):
    box(x, 10, w, H, "", fill=WHITE, sw=1.2)

# ===================================================================== (a) inputs
text(X1, 26, W1, 18, "Weight (stationary)", fs=12)
box(X1 + 112, 50, 52, 46, "1", fill=SLATE, fc=WHITE, fs=20)
box(X1 + 164, 50, 52, 46, "B", fill=SLATE_L, fc=SLATE, fs=20)
text(X1 + 112, 98, 104, 14, "w | filter label", fs=9, bold=False)
text(X1, 126, W1, 18, "G1 on K2 (from left)", fs=12)
train(X1 + 112, 150, OWN, LAB)
box(X1 + 108, 146, 112, 32, "", fill="none", stroke=G1, sw=1.4, dashed=True)
for t in range(4):
    text(X1 + 112 + t * 26, 180, 26, 12, f"t{t}", fs=9, bold=False)
text(X1, 200, W1, 18, "Partial sums in (from above)", fs=12)
sums(X1 + 52, 236, SIN)
text(X1 + 10, 352, W1 - 20, 22, "(a) Inputs of PE (K2)", fs=12)

# ===================================================================== (b) one cycle
text(X2, 26, W2, 18, "T adders, one per timestep", fs=12)
CX = X2 + 70
for t in range(4):
    x = CX + t * 106
    text(x, 52, 80, 14, f"lane t{t}", fs=10, bold=False)
    o = OWN[t]
    box(x + 27, 70, 26, 24, "" if o is None else str(LAB[t]), fill=PX[o] if o is not None else WHITE, fs=11)
    line([(x + 40, 94), (x + 40, 118)], color=INK if o is not None else "#BFBFBF", size=4)
    add("+1" if o is not None else "0", f"ellipse;html=1;fillColor={WHITE if o is not None else SILENT};"
        f"strokeColor={INK if o is not None else '#BFBFBF'};strokeWidth={1.4 if o is not None else 1};"
        f"fontFamily={FONT};fontSize=12;fontStyle=1;fontColor={INK if o is not None else '#9A9A9A'};",
        geo(x + 22, 118, 36, 36))
    line([(x + 40, 154), (x + 40, 182)], color=INK if o is not None else "#BFBFBF", size=4)
    if o is None:
        box(x + 4, 182, 72, 30, "no add", fill=SILENT, stroke="#BFBFBF", fs=10, fc="#9A9A9A", bold=False)
    else:
        box(x + 4, 182, 72, 30, f"(B, P{o})", fill=SLATE_L, fc=SLATE, fs=11)
        text(x - 10, 214, 100, 28, f"slot = B·{LAB[t]}", fs=9, bold=False)
text(X2 + 10, 352, W2 - 20, 22, "(b) One cycle: each adder adds w where its bit is 1; labels pick the sum", fs=12)

# ===================================================================== (c) outputs
text(X3, 26, W3, 18, "Partial sums out (to below)", fs=12)
sums(X3 + 52, 66, SOUT, hot={("B,P0", 1), ("B,P1", 2), ("B,P1", 3)})
text(X3, 186, W3, 18, "Row word out (to right)", fs=12)
train(X3 + 112, 212, OWN, LAB)
box(X3 + 108, 208, 112, 32, "", fill="none", stroke=G1, sw=1.4, dashed=True)
text(X3 + 10, 352, W3 - 20, 22, "(c) Outputs of PE (K2)", fs=12)

big_arrow(X2 - 22, 180, 44, 30)
big_arrow(X3 - 22, 180, 44, 30)

# ===================================================================== legend
LX, LY = 250, 404
box(LX, LY, 760, 40, "", fill=WHITE, sw=1.0)
x = LX + 16
for p in range(4):
    box(x, LY + 10, 22, 20, "", fill=PX[p])
    text(x + 26, LY + 10, 70, 20, f"spike of P{p}", fs=10, align="left")
    x += 112
box(x, LY + 8, 40, 24, "", fill="none", stroke=G1, sw=1.4, dashed=True)
text(x + 46, LY + 10, 60, 20, "group", fs=10, align="left")
x += 110
box(x, LY + 10, 26, 20, "1", fill=HOT, fs=10)
text(x + 32, LY + 10, 80, 20, "updated", fs=10, align="left")

xml = ('<mxfile host="drawio"><diagram id="pe" name="TIDES PE"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "3", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "2", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
