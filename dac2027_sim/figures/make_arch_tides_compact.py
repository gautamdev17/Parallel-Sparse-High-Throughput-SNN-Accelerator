"""
make_arch_tides_compact.py -- condensed but detailed TIDES overview (Prosperity Fig. 4 style): DRAM + CTRL on top, one
TIDES Processing Unit box with every unit opened into its sub-blocks, a PE inset, bus widths, numbered steps.
Everything is taken from hw/rtl/ours/ours_core.v (R = C = 4, T = 8, F = G = 4, SW = 10, PSW = 24, E = 4,
8 packer lanes with OPEN = 4 open groups, group entry GW = 1+3+32+64+28 = 128 b, row word IW = 1+1+T+2T = 26 b,
column bundle F*G*T*SW = 1280 b, edge entry EW = 93 b in 16 banks x 5 rows = 80, LIF 4 stages of 2 timesteps) and
Table I (buffers). Colours: pastel tints of the paper's Fig. 3 palette.

  python3 make_arch_tides_compact.py   -> <repo>/TIDES_overview.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_overview")
FONT = "Verdana"
INK, WHITE, GREY, GREY_S = "#1A1A1A", "#FFFFFF", "#F2F2F2", "#8C8C8C"
BLUE, BLUE_L = "#5E8FD6", "#DCE8F8"          # pre-processing
GREEN, GREEN_L = "#6FB24A", "#E6F4DD"        # PE array
PURP, PURP_L = "#8E64A6", "#EFE6F4"          # post-processing
YEL, YEL_L = "#D9A400", "#FFF4CC"            # buffers
RED = "#C0392B"
PPU_F, PPU_S = "#FAFBFD", "#7F7F7F"
NOTE = "#555555"

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill=WHITE, stroke=INK, fs=9, bold=False, fc=INK, sw=1.0, r=3, dashed=False,
        valign="middle", align="center"):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={fc};align={align};"
          f"verticalAlign={valign};spacing=2;{'fontStyle=1;' if bold else ''}"
          f"{'dashed=1;dashPattern=5 3;' if dashed else ''}")
    add(label, st, geo(x, y, w, h))


def text(x, y, w, h, label, fs=8, bold=False, color=INK, align="center", italic=False, rot=0):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;fontStyle={(1 if bold else 0) + (2 if italic else 0)};rotation={rot};")
    add(label, st, geo(x, y, w, h))


def wire(pts, color=INK, sw=1.2, end="block", start="none", dashed=False, size=4):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow={end};startArrow={start};endFill=1;startFill=1;endSize={size};startSize={size};html=1;"
          f"rounded=0;strokeColor={color};strokeWidth={sw};{'dashed=1;dashPattern=4 3;' if dashed else ''}")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def bus(x, y, label, align="left", w=120):
    text(x, y, w, 11, label, fs=7, italic=True, color=NOTE, align=align)


def step(x, y, n):
    add(str(n), f"ellipse;html=1;fillColor={INK};strokeColor=none;fontColor={WHITE};fontFamily={FONT};"
                f"fontSize=9;fontStyle=1;", geo(x, y, 15, 15))


def unit(x, y, w, h, title, fill, stroke, sub=""):
    box(x, y, w, h, "", fill=fill, stroke=stroke, sw=1.4, r=4)
    text(x + 6, y + 3, w - 12, 14, f"<b>{title}</b>" + (f" <span style='font-size:8px;color:{NOTE}'>{sub}</span>"
                                                       if sub else ""), fs=10, align="left")


# ================================================================ top: DRAM, CTRL
box(0, 0, 880, 24, "<b>Off-chip DRAM</b> <span style='font-size:9px'>DDR4 · 64 GB/s</span>", fill=GREY, fs=11)
box(890, 0, 150, 24, "<b>CTRL</b>", fill=GREY, fs=11)
box(890, 30, 150, 58, "", fill=GREY, stroke=INK)
for i, s in enumerate(["tile scheduler (M_t = 64, N_t = 128)", "pass parity · weight swap", "ID sideband"]):
    text(896, 33 + i * 17, 140, 16, s, fs=7.5, align="left")

# ================================================================ left: buffers
unit(0, 40, 170, 98, "Weight Buffer", YEL_L, YEL, "packed offline")
for i in range(4):
    box(10 + i * 38, 64, 34, 26, f"w|f", fill=WHITE, stroke=YEL, fs=8, sw=0.8)
text(8, 92, 156, 12, "8-b weight + 2-b filter label", fs=7.5, color=NOTE, align="left")
text(8, 104, 156, 12, "+ column filter list (per tile)", fs=7.5, color=NOTE, align="left")
text(8, 118, 156, 14, "double-buffered (shadow regs)", fs=7.5, color=NOTE, align="left")
wire([(85, 24), (85, 40)], start="block")

unit(0, 404, 170, 96, "Spike Buffer", YEL_L, YEL, "64 KB")
for r in range(3):
    for t in range(8):
        on = (r * 3 + t * 5) % 7 == 0
        box(12 + t * 15, 428 + r * 14, 15, 14, "", fill="#7EA6E1" if on else WHITE, stroke=GREY_S, sw=0.6, r=0)
text(134, 428, 34, 42, "T-bit<br>trains", fs=7.5, color=NOTE)
text(8, 474, 160, 22, "layer output spikes, im2col-addressed", fs=7.5, color=NOTE, align="left")
wire([(-8, 24), (-8, 452), (0, 452)], start="block")

# ================================================================ TIDES Processing Unit
box(186, 34, 694, 476, "", fill=PPU_F, stroke=PPU_S, sw=1.3, r=8)
text(192, 494, 682, 14, "<b>TIDES Processing Unit</b>", fs=11)

# ---- pre-processing unit (×8 lanes)
for k in (2, 1):
    box(196 + 4 * k, 300 - 4 * k, 214, 182, "", fill=BLUE_L, stroke=BLUE, sw=0.8, r=4)
unit(196, 300, 214, 182, "Pre-processing Unit", BLUE_L, BLUE, "TIP packer · ×8 lanes")
box(206, 324, 92, 34, "<b>Mask Gen</b><br>R·T = 32 b / position", fill=WHITE, stroke=BLUE, fs=7.5)
box(306, 324, 94, 34, "<b>Silent Filter</b><br>mask = 0 → drop", fill=WHITE, stroke=BLUE, fs=7.5)
text(206, 364, 194, 12, "<b>Open-Group Table</b> (Q = 4)", fs=8, align="left")
hdr = ["mask (32 b)", "members ≤ 4", "#"]
cw = [96, 74, 22]
xx = 206
for j, h in enumerate(hdr):
    box(xx, 378, cw[j], 13, h, fill=GREY, stroke=BLUE, fs=7, sw=0.6, r=0)
    xx += cw[j]
for i in range(4):
    xx = 206
    for j in range(3):
        v = ["▮▯▮▯▯▮▯…", "P0 P1", "2"][j] if i == 0 else ""
        box(xx, 391 + i * 11, cw[j], 11, v, fill=WHITE, stroke=BLUE, fs=6.5, sw=0.5, r=0)
        xx += cw[j]
box(206, 440, 92, 34, "<b>Conflict Check</b><br>4 × AND · first-fit", fill=WHITE, stroke=BLUE, fs=7.5)
box(306, 440, 94, 34, "<b>Merge + Labels</b><br>OR · 2-b member ID", fill=WHITE, stroke=BLUE, fs=7.5)
wire([(252, 358), (252, 378)], color=BLUE, sw=1.0, size=3)
wire([(298, 341), (306, 341)], color=BLUE, sw=1.0, size=3)
wire([(252, 435), (252, 440)], color=BLUE, sw=1.0, size=3)
wire([(298, 457), (306, 457)], color=BLUE, sw=1.0, size=3)
wire([(353, 440), (353, 435)], color=BLUE, sw=1.0, size=3)
wire([(170, 452), (196, 452)])
bus(171, 437, "spikes", w=30)

# ---- group buffer
unit(196, 196, 214, 84, "Group Buffer", YEL_L, YEL, "4 KB · 2 × 2 KB")
fields = [("v", 10), ("cnt", 18), ("32 spike bits", 58), ("32 × 2-b labels", 66), ("4 × 7-b IDs", 50)]
xx = 204
for f, w_ in fields:
    box(xx, 222, w_, 18, f, fill=WHITE, stroke=YEL, fs=6.5, sw=0.7, r=0)
    xx += w_
text(204, 242, 200, 12, "one group entry = 128 b", fs=7.5, color=NOTE, align="left")
text(204, 256, 200, 20, "groups queue per tile; read in lock-step by all rows", fs=7, color=NOTE, align="left")
wire([(303, 300), (303, 280)])
bus(306, 284, "groups", w=50)

# ---- PE array with skew and weight bus
AX0, AY0, S, P = 470, 82, 34, 44
box(AX0 - 12, AY0 - 34, 4 * P + 20, 4 * P + 64, "", fill=GREEN_L, stroke=GREEN, sw=1.4, r=4)
text(AX0 - 8, AY0 - 31, 4 * P + 12, 14, "<b>PE Array</b> <span style='font-size:8px;color:#555555'>4 × 4 · "
                                        "weight-stationary</span>", fs=10, align="left")
wire([(170, 64), (180, 64), (180, AY0 - 12), (AX0 + 3 * P + S / 2, AY0 - 12)], sw=1.2, end="none")
bus(196, AY0 - 24, "16 × (8 + 2) b / cycle · per tile", w=170)
for c in range(4):
    wire([(AX0 + c * P + S / 2, AY0 - 12), (AX0 + c * P + S / 2, AY0)], sw=0.9, size=3)
wire([(410, 238), (430, 238), (430, AY0 + 3 * P + S / 2)], sw=1.2, end="none")
wire([(430, AY0 + S / 2), (430, 238)], sw=1.2, end="none")
for r in range(4):
    yc = AY0 + r * P + S / 2
    wire([(430, yc), (AX0, yc)], sw=0.9, size=3)
    for j in range(r):
        box(AX0 - 7 - (j + 1) * 6, yc - 6, 5, 12, "", fill=WHITE, stroke=INK, sw=0.6, r=0)
bus(414, AY0 + 4 * P - 4, "26 b / row", w=60)
for r in range(4):
    for c in range(4):
        hl = (r, c) == (0, 3)
        box(AX0 + c * P, AY0 + r * P, S, S, "PE", fill=WHITE, stroke=RED if hl else INK, fs=9, bold=True,
            sw=1.8 if hl else 0.9, r=2)
        if c < 3:
            wire([(AX0 + c * P + S, AY0 + r * P + S / 2), (AX0 + (c + 1) * P, AY0 + r * P + S / 2)], sw=0.8,
                 size=2)
        if r < 3:
            wire([(AX0 + c * P + S / 2 + 6, AY0 + r * P + S), (AX0 + c * P + S / 2 + 6, AY0 + (r + 1) * P)],
                 sw=0.8, size=2, color=GREEN)
bus(AX0, AY0 + 4 * P + 2, "partial sums ↓  F·G·T·10 b = 1280 b / column", w=200)

# ---- PE inset
IX, IY = 682, 48
box(IX, IY, 190, 214, "", fill=WHITE, stroke=RED, sw=1.4, r=4, dashed=True)
text(IX + 6, IY + 3, 178, 14, "<b>Processing Element</b>", fs=9.5, align="left")
wire([(AX0 + 3 * P + S, AY0), (IX, IY + 20)], color=RED, sw=0.8, end="none", dashed=True)
wire([(AX0 + 3 * P + S, AY0 + S), (IX, IY + 214)], color=RED, sw=0.8, end="none", dashed=True)
box(IX + 8, IY + 22, 84, 30, "<b>Weight Reg</b><br>8 b + 2-b label", fill=GREY, fs=7.5)
box(IX + 98, IY + 22, 84, 30, "<b>Shadow Reg</b><br>next tile", fill=GREY, fs=7.5)
text(IX + 8, IY + 56, 174, 12, "row in: T spike bits + T × 2-b member labels", fs=7, color=NOTE, align="left")
for t in range(8):
    add("+", f"ellipse;html=1;fillColor={WHITE};strokeColor={INK};strokeWidth=1;fontFamily={FONT};fontSize=10;"
             f"fontStyle=1;", geo(IX + 10 + t * 21, IY + 72, 17, 17))
text(IX + 8, IY + 90, 174, 12, "T = 8 adders: + w where bit t = 1", fs=7, color=NOTE, align="left")
box(IX + 8, IY + 106, 174, 30, "<b>Slot Select</b><br>(filter label, member label) → 1 of F·G = 16", fill=WHITE,
    fs=7.5)
box(IX + 8, IY + 144, 174, 34, "<b>Partial-Sum Bundle Reg</b><br>16 slots × T × 10 b + touch bits", fill=GREEN_L,
    stroke=GREEN, fs=7.5)
text(IX + 8, IY + 182, 174, 26, "untouched slots pass unchanged · no compare / search", fs=7, color=NOTE,
     align="left")

# ---- post-processing unit (title at the bottom so the column buses drop in cleanly)
box(458, 300, 414, 182, "", fill=PURP_L, stroke=PURP, sw=1.4, r=4)
text(464, 462, 400, 16, "<b>Post-processing Unit</b> <span style='font-size:8px;color:#555555'>edge unit · one "
                        "lane per column</span>", fs=10, align="left")
wire([(AX0 + 2 * P - 5, AY0 + 4 * P + 30), (AX0 + 2 * P - 5, 292)], sw=1.4, end="none", color=GREEN)
wire([(515, 292), (809, 292)], sw=1.4, end="none", color=GREEN)
bus(AX0 + 2 * P, 278, "4 × 1280 b", w=70)
for c in range(4):
    x0 = 470 + c * 98
    wire([(x0 + 45, 292), (x0 + 45, 312)], sw=1.0, size=3, color=GREEN)
    box(x0, 312, 90, 30, "<b>Addr Decode</b><br>labels + IDs → (n, m)", fill=WHITE, stroke=PURP, fs=7)
    text(x0, 345, 90, 12, f"FIFO {c} · 80 × 93 b", fs=7, color=NOTE)
    for b in range(5):
        box(x0 + 8, 358 + b * 9, 74, 9, "", fill=WHITE, stroke=PURP, sw=0.6, r=0)
    text(x0, 403, 90, 11, "16 banks × 5 rows", fs=6.5, color=NOTE)
    wire([(x0 + 45, 342), (x0 + 45, 358)], color=PURP, sw=0.9, size=3)
    wire([(x0 + 45, 403), (x0 + 45, 420)], color=PURP, sw=0.9, size=3)
box(470, 420, 392, 36, "<b>Arbiter + RMW</b>: 4 read-modify-writes per column per cycle · backpressure stalls "
                       "injection when a FIFO is full", fill=WHITE, stroke=PURP, fs=7.5)

# ================================================================ right: output buffer, LIF
unit(890, 300, 150, 182, "Output Buffer", YEL_L, YEL, "192 KB")
for i in range(6):
    box(900, 324 + i * 16, 130, 14, "", fill=WHITE, stroke=YEL, sw=0.6, r=0)
text(896, 422, 140, 24, "24-B entry = T × 24-b sum<br>per (filter, position)", fs=7.5, color=NOTE)
text(896, 450, 140, 26, "tiles accumulate here until the last K-tile", fs=7, color=NOTE)
wire([(862, 438), (890, 438)], sw=1.4)
bus(864, 424, "RMW", w=30)

unit(890, 110, 150, 170, "LIF Array", GREY, INK, "×16")
for i, s in enumerate(["leak  V ← λV", "add  V += I[t]", "fire  V ≥ θ", "reset  V −= θ"]):
    box(902, 136 + i * 26, 126, 20, s, fill=WHITE, fs=7.5, sw=0.8)
    if i < 3:
        wire([(965, 156 + i * 26), (965, 162 + i * 26)], sw=0.8, size=2)
text(896, 240, 140, 34, "4-stage pipeline, 2 timesteps / stage; after the last tile", fs=7, color=NOTE)
wire([(965, 300), (965, 280)], sw=1.4)
wire([(1040, 195), (1052, 195), (1052, 522), (85, 522), (85, 500)], sw=1.2, dashed=True)
text(400, 526, 300, 12, "output spike trains → Spike Buffer (next layer)", fs=8, color=NOTE)

# ================================================================ steps
step(92, 26, 1)        # load packed weights (+ labels)
step(178, 458, 2)      # spikes into the pre-processing unit
step(282, 283, 3)      # packed groups into the group buffer
step(416, 188, 4)      # groups stream along the rows
step(660, 252, 5)      # one weight x all T timesteps, slot select
step(846, 300, 6)      # restore (n, m), FIFO, RMW
step(1046, 270, 7)     # LIF after the last tile

xml = ('<mxfile host="drawio"><diagram id="tidesov" name="TIDES overview"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "3", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "2.5", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
