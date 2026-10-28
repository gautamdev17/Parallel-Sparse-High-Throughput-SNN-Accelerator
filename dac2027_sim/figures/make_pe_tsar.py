"""
make_pe_tsar.py -- the TIDES processing element (ours_pe in hw/rtl/ours/ours_core.v) drawn in the visual style of
T-SAR (arXiv 2511.13676) Fig. 6: black title bars with white bold text, lavender / pink register cells, circled
operators, trapezoid multiplexers, many thin arrows into a mux, braces with bit widths, stacked lanes, mint side
labels and a beige configuration box.

PE (T = 8, F_max = G_max = 4, SW = 10): active + shadow weight registers {w (8 b), f (2 b), parity}, swap when a row
word of the other parity arrives; T lanes, lane t: slot = {f, l[t]} (4 b) -> 16:1 read of the incoming bundle ->
+w -> write back to the same slot and set its touch bit when v & s[t] & (w != 0); untouched slots pass down; the row
word (v, parity, s[0:T-1], l[0:T-1]) passes right.

  python3 make_pe_tsar.py   -> <repo>/TIDES_pe.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_pe")
FONT = "Arial"
INK, WHITE, BLACK = "#1A1A1A", "#FFFFFF", "#111111"
LAV, PINK, GREY = "#DCDDF2", "#F7DADA", "#E6E6E6"
MINT, BEIGE = "#CDEBD7", "#F3EDD3"
RED, TEAL, PURP = "#C0504D", "#2E9E8F", "#7B4FC9"

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill=WHITE, stroke=INK, fs=11, bold=True, fc=INK, sw=1.0, r=0, dashed=False,
        align="center"):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={fc};align={align};"
          f"verticalAlign=middle;spacing=1;{'fontStyle=1;' if bold else ''}"
          f"{'dashed=1;dashPattern=4 3;' if dashed else ''}")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=11, bold=True, color=INK, align="center", rot=0):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;fontStyle={1 if bold else 0};rotation={rot};")
    add(label, st, geo(x, y, w, h))


def wire(pts, sw=1.0, end="block", size=4, color=INK, dashed=False):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow={end};endFill=1;endSize={size};html=1;rounded=0;strokeColor={color};strokeWidth={sw};"
          f"{'dashed=1;dashPattern=4 3;' if dashed else ''}")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def bar(x, y, w, label, h=24, fs=13):
    box(x, y, w, h, label, fill=BLACK, stroke=BLACK, fs=fs, fc=WHITE)


def mux(x, y, w, h, direction="south", fill=LAV):
    add("", f"shape=trapezoid;perimeter=trapezoidPerimeter;whiteSpace=wrap;html=1;fixedSize=1;size=10;"
            f"direction={direction};fillColor={fill};strokeColor={INK};strokeWidth=1;", geo(x, y, w, h))


def op(x, y, sym, d=24):
    add(sym, f"ellipse;html=1;fillColor={WHITE};strokeColor={INK};strokeWidth=1.3;fontFamily={FONT};"
             f"fontSize=16;fontStyle=1;", geo(x, y, d, d))


def brace(x, y, w, label, below=True):
    yy = y + (6 if below else -6)
    wire([(x, y), (x, yy), (x + w, yy), (x + w, y)], sw=0.8, end="none")
    text(x, yy + (2 if below else -18), w, 16, label, fs=10)


def mint(x, y, w, h, label):
    box(x, y, w, h, label, fill=MINT, stroke=MINT, fs=11)


def slots(x, y, n=16, w=24, h=26, hot=()):
    """partial-sum bundle: 16 slots, 4 per filter label (alternating lavender / pink groups)."""
    for s in range(n):
        f = s // 4
        fill = "#FFE699" if s in hot else (LAV if f % 2 == 0 else PINK)
        box(x + s * w, y, w, h, "", fill=fill, stroke=INK, sw=0.8)
        for t in range(1, 4):
            wire([(x + s * w + 2, y + t * h / 4), (x + s * w + w - 2, y + t * h / 4)], sw=0.4, end="none",
                 color="#9A9A9A")


# ============================================================================ title + config
bar(10, 10, 960, "Processing Element (PE) · one per array cell, 4 × 4 in TIDES", h=28, fs=14)
box(10, 48, 190, 92, "", fill=BEIGE, stroke=INK)
text(16, 50, 180, 18, "PE Cfg.", fs=12, align="left")
for i, (k, v, c) in enumerate([("T", "8 lanes", RED), ("F<sub>max</sub>", "4 · f = 2 b", PURP),
                               ("G<sub>max</sub>", "4 · ℓ = 2 b", TEAL), ("slots", "F·G = 16 × T × 10 b", INK)]):
    text(16, 68 + i * 17, 180, 16, f"<font color='{c}'>{k}</font> = {v}", fs=11, align="left")

# ============================================================================ weight registers (left)
text(10, 148, 130, 14, "Weight load: w, f, p", fs=10, bold=False, align="left")
wire([(55, 162), (55, 170)], size=3)
CW = [70, 26, 22]
def wreg(y, tag):
    for i, (lab, fill) in enumerate([("w [7:0]", LAV), ("f", PINK), ("p", GREY)]):
        box(20 + sum(CW[:i]), y, CW[i], 24, lab, fill=fill, fs=10)
    text(142, y, 60, 24, tag, fs=10, bold=False, align="left")
wreg(170, "Shadow")
add("", f"shape=trapezoid;perimeter=trapezoidPerimeter;whiteSpace=wrap;html=1;fixedSize=1;size=8;flipV=1;"
        f"fillColor={GREY};strokeColor={INK};", geo(30, 200, 50, 14))
text(84, 200, 50, 14, "swap", fs=9, bold=False, align="left")
wire([(55, 194), (55, 200)], size=2)
wire([(55, 214), (55, 222)], size=2)
wreg(222, "Active")

# ============================================================================ bundle in (top right)
bar(470, 48, 400, "Partial-Sum Bundle In · from PE above", h=22, fs=12)
slots(478, 76)
brace(478, 102, 384, "16 slots × T × 10 b + 16 touch bits")

# ============================================================================ lanes (stacked x T)
LX, LY, LW, LH = 226, 186, 646, 236
for k in (3, 2, 1):
    box(LX + 6 * k, LY - 6 * k, LW, LH, "", fill=WHITE, stroke="#9A9A9A", sw=0.8)
box(LX, LY, LW, LH, "", fill=WHITE, stroke=INK, sw=1.2)
text(LX + 8, LY + LH - 22, 220, 16, "lane t · <font color='#C0504D'>×T</font> lanes in parallel", fs=11, align="left")
for s_ in range(16):
    wire([(490 + s_ * 24, 128), (490 + s_ * 24, 196)], sw=0.6, size=3)
add("16 : 1 read", f"shape=trapezoid;perimeter=trapezoidPerimeter;whiteSpace=wrap;html=1;fixedSize=1;size=60;"
                   f"flipV=1;fillColor={LAV};strokeColor={INK};fontFamily={FONT};fontSize=11;fontStyle=1;",
    geo(478, 196, 384, 30))
box(244, 200, 124, 40, "Slot Index<br><span style='font-weight:normal'>{f, ℓ[t]} → 4 b</span>", fill=GREY, fs=11)
wire([(368, 211), (520, 211)], size=3)
text(380, 196, 80, 14, "select", fs=9, bold=False)
wire([(103, 246), (103, 262), (232, 262), (232, 236), (244, 236)], size=3, color=PURP)
text(150, 262, 30, 14, "f", fs=10, color=PURP)
op(658, 278, "+")
wire([(670, 226), (670, 278)], sw=1.2)
text(676, 240, 60, 14, "old sum", fs=9, bold=False, align="left")
wire([(55, 246), (55, 290), (658, 290)], sw=1.2, color=RED)
text(560, 274, 30, 14, "w", fs=11, color=RED)
box(616, 320, 108, 34, "Gate<br><span style='font-weight:normal'>v ∧ s[t] ∧ w≠0</span>", fill=PINK, fs=11)
wire([(670, 302), (670, 320)], sw=1.2)
add("1 : 16 write-back · set touch bit", f"shape=trapezoid;perimeter=trapezoidPerimeter;whiteSpace=wrap;html=1;"
    f"fixedSize=1;size=60;fillColor={LAV};strokeColor={INK};fontFamily={FONT};fontSize=11;fontStyle=1;",
    geo(478, 376, 384, 30))
wire([(670, 354), (670, 376)], sw=1.2)
wire([(270, 240), (270, 391), (533, 391)], size=3)
text(276, 368, 60, 14, "select", fs=9, bold=False, align="left")
text(LX + 56, 300, 200, 30, "untouched slots pass<br>through unchanged", fs=9, bold=False, align="left")

# ============================================================================ row word in (left)
bar(10, 300, 180, "Row Word In · left PE", h=22, fs=11)
for t in range(8):
    on = t in (1, 2, 3)
    box(14 + t * 19, 336, 19, 22, "1" if on else "0", fill=LAV if on else WHITE, fs=10, bold=on)
brace(14, 358, 152, "s[0:T−1] · T b")
lab = ["", "0", "1", "1", "", "", "", ""]
for t in range(8):
    box(14 + t * 19, 392, 19, 22, lab[t], fill=PINK if lab[t] else WHITE, fs=10)
brace(14, 414, 152, "ℓ[0:T−1] · 2 b each")
wire([(166, 347), (214, 347), (214, 337), (616, 337)], size=3, color=RED)
text(560, 322, 50, 14, "v, s[t]", fs=10, color=RED)
wire([(166, 403), (204, 403), (204, 228), (244, 228)], size=3, color=TEAL)
text(206, 300, 30, 14, "ℓ[t]", fs=10, color=TEAL, align="left")

# ============================================================================ row word reg + bundle out (bottom)
bar(10, 452, 180, "Row Word Reg", h=22, fs=12)
wire([(100, 438), (100, 452)], size=3)
text(10, 476, 180, 28, "v, parity, s, ℓ → right PE", fs=10, bold=False)
wire([(190, 463), (226, 463)], sw=1.2, size=5)
for s_ in range(16):
    wire([(490 + s_ * 24, 406), (490 + s_ * 24, 452)], sw=0.6, size=3)
bar(470, 452, 400, "Partial-Sum Bundle Reg · to PE below", h=22, fs=12)
slots(478, 482, hot=(4, 5))
brace(478, 508, 384, "1280 b + 16 touch bits, every cycle")

# ============================================================================ mint labels
mint(886, 76, 86, 40, "Bundle<br>In")
mint(886, 196, 86, 40, "Slot<br>Select")
mint(886, 300, 86, 40, "Gated<br>Adders")
mint(886, 482, 86, 40, "Bundle<br>Regs")
mint(130, 108, 0, 0, "")

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
