"""
make_pe_arch.py -- the TIDES processing element (ours_pe in hw/rtl/ours/ours_core.v) as a block diagram, in the
visual format of make_arch_tides_ppu.py (Prosperity Fig. 5 palette): shadow / active weight registers with the
parity swap, one lane per timestep (x T) with slot index {f, l[t]}, 16:1 read, adder, gate v & s[t] & (w != 0) and
1:16 write-back, the running-sum bundle in from above / out below (untouched slots pass), and the row word passed
to the right. Wire crossings are drawn as jumps.

  python3 make_pe_arch.py   -> <repo>/TIDES_pe_arch.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_pe_arch")
FONT = "Helvetica"
INK, WHITE, NOTE = "#1A1A1A", "#FFFFFF", "#333333"
HDR, ONE = "#518CE6", "#679DD5"                         # logic blocks, muxes
NOY, SIG = "#FBEAB8", "#BFDDAA"                         # running sums, weight registers

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill=WHITE, stroke=INK, fs=10, fc=INK, sw=1.0):
    st = (f"whiteSpace=wrap;html=1;fillColor={fill};strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};"
          f"fontSize={fs};fontColor={fc};spacing=1;")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=9, color=NOTE, align="left", bold=False):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;fontStyle={1 if bold else 0};")
    add(label, st, geo(x, y, w, h))


def wire(pts, sw=1.1, end="block", size=4, color=INK):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow={end};endFill=1;endSize={size};html=1;rounded=0;strokeColor={color};strokeWidth={sw};"
          f"jumpStyle=arc;jumpSize=7;")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def dot(x, y):
    add("", f"ellipse;html=1;fillColor={INK};strokeColor={INK};", geo(x - 2.5, y - 2.5, 5, 5))


def mux(x, y, w, h, label, direction):
    add(label, f"shape=trapezoid;perimeter=trapezoidPerimeter;whiteSpace=wrap;html=1;fixedSize=1;size=8;"
               f"direction={direction};fillColor={ONE};strokeColor={INK};fontFamily={FONT};fontSize=8;"
               f"fontColor={WHITE};fontStyle=1;", geo(x, y, w, h))


def blue(x, y, w, h, title, sub):
    box(x, y, w, h, f"<b>{title}</b><br><span style='font-size:8px'>{sub}</span>", fill=HDR, stroke=HDR, fs=10,
        fc=WHITE)


def lbl(title, sub):
    return f"<b>{title}</b><br><span style='font-size:8px'>{sub}</span>"


# ---------------------------------------------------------------- weight registers (top left)
text(20, 22, 200, 13, "<b>weight load</b> (once per pass)", fs=9, color=INK)
text(20, 35, 200, 12, "w (8 b) · filter label f (2 b) · parity", fs=8)
wire([(70, 48), (70, 60)])
box(20, 60, 100, 44, lbl("Shadow Reg", "w | f | parity"), fill=SIG, fs=10)
mux(132, 54, 22, 56, "", "east")
box(166, 60, 104, 44, lbl("Active Reg", "w | f | parity"), fill=SIG, fs=10)
wire([(120, 82), (132, 82)], size=3)
wire([(154, 82), (166, 82)], size=3)
text(46, 131, 100, 12, "swap if parity ≠ active", fs=7.5)

# ---------------------------------------------------------------- running sums in (top)
wire([(380, 4), (380, 26)])
text(386, 4, 90, 12, "from PE above", fs=8)
box(285, 26, 190, 50, lbl("Bundle In", "16 slots × T × 10 b + 16 touch bits"), fill=NOY, fs=10)

# ---------------------------------------------------------------- one lane per timestep (x T)
LX, LY, LW, LH = 150, 140, 490, 190
for k in (2, 1):
    box(LX + 5 * k, LY - 5 * k, LW, LH, "", fill=WHITE, stroke="#9A9A9A", sw=0.8)
box(LX, LY, LW, LH, "", fill=WHITE, stroke=INK, sw=1.0)
text(LX + LW - 255, LY + LH - 17, 248, 13, "<b>lane t</b> (× T = 8, one adder per timestep)", fs=9,
     color=INK, align="right")

blue(165, 210, 100, 50, "Slot Index", "{f, ℓ[t]} → 4 b")
mux(300, 195, 28, 80, "16:1", "east")
add("+", f"ellipse;html=1;fillColor={HDR};strokeColor={HDR};fontColor={WHITE};fontFamily={FONT};fontSize=16;"
         f"fontStyle=1;", geo(360, 217, 36, 36))
mux(450, 195, 28, 80, "1:16", "west")
blue(500, 150, 125, 30, "Gate", "v ∧ s[t] ∧ (w ≠ 0)")

# datapath: read the selected slot, add w, write it back
wire([(314, 76), (314, 195)])                                   # bundle -> 16:1 read
text(318, 160, 60, 12, "sums", fs=8)
wire([(328, 235), (360, 235)], size=3)
text(330, 222, 30, 11, "10 b", fs=7.5)
wire([(396, 235), (450, 235)], size=3)
wire([(520, 180), (520, 187), (464, 187), (464, 195)], size=3)  # write enable
text(525, 182, 20, 11, "we", fs=7.5)
# slot select to the read and the write mux
wire([(215, 260), (215, 285), (464, 285), (464, 275)], size=3)
wire([(314, 285), (314, 275)], size=3)
dot(314, 285)
text(360, 287, 80, 12, "slot (4 b)", fs=7.5)

# from the active weight: filter label to the slot index, weight to the adder and to the zero test
wire([(200, 104), (200, 210)], size=3)
text(204, 150, 50, 12, "<b>f</b> (2 b)", fs=8, color=INK)
wire([(270, 92), (378, 92), (378, 217)], size=3)
text(382, 150, 50, 12, "<b>w</b> (8 b)", fs=8, color=INK)
dot(378, 92)
wire([(378, 92), (600, 92), (600, 110)], end="none")
box(588, 110, 24, 18, "≠0", fs=8)
wire([(600, 128), (600, 150)], size=3)

# ---------------------------------------------------------------- running sums out (right) and bypass
box(660, 205, 180, 60, lbl("Bundle Reg", "written slot + touch bit;<br>other slots pass unchanged"), fill=NOY, fs=10)
wire([(478, 235), (660, 235)])
text(486, 222, 110, 11, "new sum → slot", fs=7.5)
wire([(475, 51), (750, 51), (750, 205)])
text(756, 110, 90, 26, "untouched slots<br>pass through", fs=8)
wire([(750, 265), (750, 345)])
text(756, 329, 80, 12, "to PE below", fs=8)

# ---------------------------------------------------------------- row word: in from the left, registered, out right
wire([(0, 372), (790, 372)])
text(0, 377, 420, 12, "row word from the left PE: valid, parity, s[t] (T b), ℓ[t] (2 b × T)", fs=8)
box(790, 352, 120, 40, lbl("Row Reg", "valid, parity, s[t], ℓ[t]"), fs=10)
wire([(910, 372), (950, 372)])
text(912, 355, 60, 12, "to right PE", fs=8)
for x in (40, 60, 90):
    dot(x, 372)
wire([(40, 372), (40, 128), (143, 128), (143, 110)], size=3)   # parity -> swap
wire([(60, 372), (60, 235), (165, 235)], size=3)                # member labels -> slot index
text(96, 222, 60, 12, "ℓ[t]", fs=8, color=INK)
wire([(90, 372), (90, 300), (600, 300), (600, 180)], size=3)    # valid, spike bit -> gate
text(96, 287, 60, 12, "v, s[t]", fs=8, color=INK)

xml = ('<mxfile host="drawio"><diagram id="tidespe" name="TIDES PE"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "3", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "2.5", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
