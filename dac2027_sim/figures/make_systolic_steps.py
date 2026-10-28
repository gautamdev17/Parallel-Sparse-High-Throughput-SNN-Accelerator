"""
make_systolic_steps.py -- draw.io reproduction of the step-by-step systolic-array figure (packed weight column
(W*, label), packed spike groups (S*, labels), Steps 0..4 of the array, restored output). Values are the running
example: W* = [2|A, 3|B, 1|B, 1|A], G1 = {p0, p1}, G2 = {p2, p3}, outputs A = 2011 0000 1200 0122,
B = 0100 0041 0033 1000.

  python3 make_systolic_steps.py   -> <repo>/TIDES_systolic_steps.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_systolic_steps")
FONT, MONO = "Helvetica", "Courier New"
INK, WHITE = "#262626", "#FFFFFF"
RED, PINK = "#C00000", "#FFCCCC"
SLATE, SLATE_L = "#44546A", "#D6DCE5"
PX = {0: "#4472C4", 1: "#FFC000", 2: "#70AD47", 3: "#7030A0"}
GREEN, BLUE, GOLD = "#70AD47", "#4472C4", "#BF9000"
ACT, ORANGE, OUTG = "#FFF2CC", "#C55A11", "#548235"
YEL, CREAM = "#FFD966", "#FFF2CC"
GREY = "#A6A6A6"

# packed weight column: (weight, filter)
WCOL = [(2, "A"), (3, "B"), (1, "B"), (1, "A")]
# packed trains per row k (owner of each timestep, None = 0)
G = {"G1": [[0, None, None, None], [None, None, 1, None], [None, 0, 1, 1], [None, None, 0, 0]],
     "G2": [[None, 2, 3, 3], [None, None, 2, 2], [3, None, None, None], [2, 3, None, None]]}
# step -> {row: group}  (G1 enters row k at step k, G2 one step later)
SCHED = [{0: "G1"}, {0: "G2", 1: "G1"}, {1: "G2", 2: "G1"}, {2: "G2", 3: "G1"}, {3: "G2"}]
OUT_A = ["2011", "0000", "1200", "0122"]
OUT_B = ["0100", "0041", "0033", "1000"]

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill=WHITE, stroke=INK, fs=12, bold=False, fc=INK, sw=1.0, r=0, dashed=False,
        font=FONT, dash="8 6"):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={font};fontSize={fs};fontColor={fc};align=center;"
          f"verticalAlign=middle;spacing=0;{'fontStyle=1;' if bold else ''}"
          f"{'dashed=1;dashPattern=' + dash + ';' if dashed else ''}")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=12, bold=True, color=INK, font=FONT, rot=0):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={font};fontSize={fs};fontColor={color};align=center;"
          f"verticalAlign=middle;spacing=0;fontStyle={1 if bold else 0};rotation={rot};")
    add(label, st, geo(x, y, w, h))


def line(x0, y0, x1, y1, color=INK, sw=1.0, end="block", dashed=False, size=6):
    st = (f"endArrow={end};endFill=1;endSize={size};html=1;rounded=0;strokeColor={color};strokeWidth={sw};"
          f"{'dashed=1;dashPattern=6 4;' if dashed else ''}")
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/></mxGeometry>', vertex=False)


def train(x, y, owners, cw=24, ch=22, sw=1.0):
    for t, o in enumerate(owners):
        box(x + t * cw, y, cw, ch, "", fill=PX[o] if o is not None else WHITE, stroke=INK, sw=sw)


# ===================================================================================== input data
box(8, 32, 324, 1004, "", fill="none", stroke=GREEN, sw=3, r=24, dashed=True)
text(30, 56, 280, 40, "( W*, label )", fs=26)
for k, (w, f) in enumerate(WCOL):
    y = 122 + k * 67
    text(50, y, 46, 64, f"k{k}", fs=22, bold=False, color="#7F7F7F")
    dark, light = (RED, PINK) if f == "A" else (SLATE, SLATE_L)
    box(102, y, 64, 64, str(w), fill=dark, stroke=INK, fs=30, bold=True, fc=WHITE, sw=1.5)
    box(166, y, 64, 64, f, fill=light, stroke=INK, fs=30, bold=True, fc=RED if f == "A" else SLATE, sw=1.5)
text(30, 474, 280, 44, "Input Data", fs=30)
text(30, 572, 280, 40, "( S*, labels )", fs=26)
text(70, 624, 80, 32, "G1", fs=26)
text(198, 624, 80, 32, "G2", fs=26)
for k in range(4):
    y = 688 + k * 47
    train(59, y, G["G1"][k], cw=26, ch=26)
    train(186, y, G["G2"][k], cw=26, ch=26)
for i in range(4):
    x = 38 + i * 72
    box(x, 916, 30, 30, "", fill=PX[i], stroke=INK, sw=1)
    text(x + 30, 916, 40, 30, f"p{i}", fs=22, color=PX[i])

# ===================================================================================== systolic array
box(358, 32, 1586, 600, "", fill="none", stroke=BLUE, sw=3, r=24, dashed=True)
text(1826, 312, 300, 50, "Systolic Array", fs=32, rot=90)
SX, SW = 366, 317                                  # first column x, column width
for s in range(5):
    if s:
        line(SX + s * SW, 50, SX + s * SW, 620, color=GREY, sw=1.5, end="none", dashed=True)
    px = SX + s * SW + 137                         # PE left edge in this column
    for k, (w, f) in enumerate(WCOL):
        y = 78 + k * 119
        g = SCHED[s].get(k)
        col = RED if f == "A" else SLATE
        box(px, y, 144, 88, "", fill=ACT if g else WHITE, stroke=col, sw=4 if g else 2, r=12)
        text(px, y + 6, 144, 42, f"{w}|{f}", fs=28, color=col, font=MONO)
        owners = G[g][k] if g else [None] * 4
        train(px + 12, y + 52, owners, cw=30, ch=24, sw=0.9)
        if k < 3:
            line(px + 72, y + 88, px + 72, y + 119, color=ORANGE, sw=2, size=7)
        if g:
            text(px - 110, y - 4, 96, 32, g, fs=22)
            train(px - 126, y + 28, G[g][k], cw=24, ch=24)
            line(px - 30, y + 40, px, y + 40, color=BLUE, sw=2, size=7)
            if k == 3:
                line(px + 72, y + 88, px + 72, y + 146, color=OUTG, sw=3, size=8)
                text(px + 80, y + 108, 60, 40, g, fs=28, color=OUTG)

# ===================================================================================== output
box(358, 658, 1586, 378, "", fill="none", stroke=GOLD, sw=3, r=24, dashed=True)
text(1776, 822, 400, 50, "Output (Restored)", fs=32, rot=90)
for s in range(5):
    if s:
        line(SX + s * SW, 676, SX + s * SW, 1024, color=GREY, sw=1.5, end="none", dashed=True)
    ox = SX + s * SW + 42
    for p in range(4):
        text(ox + p * 60, 696, 60, 32, str(p), fs=26, color=PX[p])
    for r, (lab, vals) in enumerate((("A", OUT_A), ("B", OUT_B))):
        y = 738 + r * 104
        text(ox - 36, y + 14, 32, 40, lab, fs=28, color=RED if lab == "A" else SLATE)
        for p in range(4):
            done = (s >= 3 and p < 2) or (s >= 4)
            fresh = (s == 3 and p < 2) or (s == 4 and p >= 2)
            fill = YEL if fresh else (CREAM if done else WHITE)
            box(ox + p * 60, y, 60, 80, vals[p] if done else "", fill=fill, stroke=INK, fs=20, fc=INK,
                font=MONO, sw=1.2)
    text(SX + s * SW, 964, SW, 48, f"Step {s}", fs=30)

xml = ('<mxfile host="drawio"><diagram id="steps" name="systolic steps"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "3", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "1", "-b", "4", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
