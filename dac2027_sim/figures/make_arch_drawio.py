"""
make_arch_drawio.py -- architecture figure of our accelerator as an editable draw.io file, exported to PDF and PNG.
Blocks, sizes and widths follow DAC2027_accelerator_explained_rows.pdf and hw/rtl/ours/ours_core.v
(4 x 4 PEs, T = 8 adders per PE, F = 4, G = 4, 8 packer lanes, 4 x 80-entry edge FIFOs, 16 RMW / cycle,
16 LIF units, 64 KB staging + 4 KB group + 192 KB output SRAM).
Style (from Phi Fig. 3 / Prosperity Fig. 5): one colour per block class, one accent for the new units, DRAM as a bar,
thick grey arrows for bulk data, few words, 16 / 13 / 12 px text (8 / 6.5 / 6 pt at 7 in width).

  python3 make_arch_drawio.py   -> arch.drawio, arch.pdf, arch.png
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
FONT = "Helvetica"
MEM = ("#FBE5E7", "#B0505A")      # SRAM
CMP = ("#E3E9FB", "#4A5FB0")      # conventional compute
NEW = ("#FFE2C2", "#D2691E")      # new in this work (accent)
NEU = ("#DDEFD8", "#4E8A3E")      # neuron
CTL = ("#6B7FE8", "#4A5FB0")      # controller (saturated)
REG = ("#F3F3F3", "#9A9A9A")      # chip backdrop
INK, GREY, BLUE, ORNG, GRN = "#1E1E1E", "#8C8C8C", "#2F6DB5", "#D2691E", "#4E8A3E"
T1, T2, T3 = 16, 13, 12           # text sizes (px)

cells, _id = [], [10]


def nid():
    _id[0] += 1
    return f"c{_id[0]}"


def add(value, style, geo, vertex=True):
    i = nid()
    kind = 'vertex="1"' if vertex else 'edge="1"'
    cells.append(f'<mxCell id="{i}" value="{html.escape(value, quote=True)}" style="{style}" {kind} parent="1">'
                 f"{geo}</mxCell>")
    return i


def box(x, y, w, h, label="", fill="#FFFFFF", stroke=INK, fs=T1, bold=False, sw=1.2, dashed=False, rounded=True,
        fc=INK, align="center", valign="middle", shape=""):
    st = (f"{shape}whiteSpace=wrap;html=1;fillColor={fill};strokeColor={stroke};strokeWidth={sw};"
          f"fontFamily={FONT};fontSize={fs};fontColor={fc};align={align};verticalAlign={valign};spacing=2;"
          f"rounded={1 if rounded else 0};arcSize=8;absoluteArcSize=1;"
          f"{'fontStyle=1;' if bold else ''}{'dashed=1;dashPattern=6 4;' if dashed else ''}")
    return add(label, st, f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>')


def text(x, y, w, h, label, fs=T3, bold=False, color=INK, align="center", italic=False, rot=0):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;fontStyle={(1 if bold else 0) + (2 if italic else 0)};rotation={rot};")
    return add(label, st, f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>')


def wire(pts, color=INK, sw=1.4, end="block", start="none", dashed=False):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    st = (f"endArrow={end};startArrow={start};endFill=1;startFill=1;endSize=6;startSize=6;html=1;rounded=0;"
          f"strokeColor={color};strokeWidth={sw};{'dashed=1;dashPattern=4 3;' if dashed else ''}")
    return add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                       f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def bulk(pts, both=False):
    """thick grey arrow for bulk data (Phi style)"""
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    st = (f"shape=flexArrow;endArrow=block;startArrow={'block' if both else 'none'};html=1;rounded=0;width=7;"
          f"endWidth=9;endSize=3.5;startWidth=9;startSize=3.5;fillColor=#A6A6A6;strokeColor=none;")
    return add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                       f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def step(x, y, n):
    add(str(n), f"ellipse;html=1;fillColor={INK};strokeColor=none;fontColor=#FFFFFF;fontFamily={FONT};fontSize=12;"
                f"fontStyle=1;", f'<mxGeometry x="{x}" y="{y}" width="20" height="20" as="geometry"/>')


def grid(x, y, bits, colors, cell=8, rows=4, cols=8, labels=None):
    """spike mask glyph: rows x T cells; bits = {(r, t): pixel}"""
    for r in range(rows):
        for t in range(cols):
            p = bits.get((r, t))
            box(x + t * cell, y + r * cell, cell, cell, "", fill=colors[p] if p is not None else "#FFFFFF",
                stroke="#7A7A7A", sw=0.6, rounded=False)


# =============================================================================================== (a) top level
box(0, 0, 1000, 392, "", fill=REG[0], stroke=REG[1], dashed=True, sw=1.2)
box(0, 402, 1000, 34, "DRAM", fill="#9A9A9A", stroke="none", fs=T1 + 2, fc="#FFFFFF", bold=False)

# staging SRAM (weight + spike memory)
box(30, 22, 142, 218, "", fill="#FFF7F8", stroke=MEM[1], sw=1.0)
text(30, 24, 142, 16, "Staging SRAM · 64 KB", fs=T3, bold=True, color=MEM[1])
box(40, 44, 122, 82, f"Weight<br>Memory<br><span style='font-size:{T3}px'>packed columns</span>",
    fill=MEM[0], stroke=MEM[1], fs=T1)
box(40, 140, 122, 90, f"Spike<br>Memory<br><span style='font-size:{T3}px'>T-bit trains</span>",
    fill=MEM[0], stroke=MEM[1], fs=T1)
bulk([(14, 402), (14, 131), (30, 131)], both=True)

# controller
box(196, 346, 158, 32, "Controller", fill=CTL[0], stroke=CTL[1], fs=T1, fc="#FFFFFF")

# packer (new) with glyph
box(196, 108, 158, 178, "", fill="#FFFFFF", stroke=NEW[1], sw=1.8)
box(196, 108, 158, 28, "Pixel Packer ×8", fill=NEW[0], stroke=NEW[1], sw=1.8, fs=T1, bold=True)
C0, C1 = "#4F8FD6", "#F0A35E"
p0 = {(0, 0): 0, (1, 3): 0, (2, 5): 0, (3, 1): 0}
p1 = {(0, 4): 1, (2, 2): 1, (3, 6): 1, (1, 7): 1}
grid(208, 150, p0, {0: C0}, cell=7)
text(208, 179, 56, 12, "pixel p0", fs=10)
grid(208, 202, p1, {1: C1}, cell=7)
text(208, 231, 56, 12, "pixel p1", fs=10)
wire([(268, 165), (282, 190)], color=GREY, sw=1.2)
wire([(268, 216), (282, 196)], color=GREY, sw=1.2)
merged = dict(p0)
merged.update(p1)
grid(286, 178, merged, {0: C0, 1: C1}, cell=7)
text(280, 207, 70, 12, "1 group", fs=10, bold=True)
text(200, 252, 150, 30, "no shared (row, t) bit<br>→ share one cycle", fs=11, color=NEW[1])
wire([(162, 185), (196, 185)], color=BLUE, sw=1.6)

# group buffer
box(196, 296, 158, 38, "Group Buffer · 4 KB", fill=MEM[0], stroke=MEM[1], fs=T2 + 1)
wire([(275, 286), (275, 296)], color=BLUE, sw=1.6)

# PE array (new)
AX, AY, P, G = 414, 58, 46, 14
box(392, 14, 262, 286, "", fill="#FFFFFF", stroke=NEW[1], sw=1.8)
box(392, 14, 262, 30, f"PE Array 4×4 <span style='font-size:{T3}px;font-weight:normal'>(8 adders / PE)</span>",
    fill=NEW[0], stroke=NEW[1], sw=1.8, fs=T1, bold=True)
for r in range(4):
    for c in range(4):
        x, y = AX + c * (P + G), AY + r * (P + G)
        hl = (r == 3 and c == 0)
        box(x, y, P, P, "PE", fill=NEW[0], stroke=INK if hl else NEW[1], sw=2.2 if hl else 1.0, fs=T2)
        if c < 3:
            wire([(x + P, y + 15), (x + P + G, y + 15)], color=BLUE, sw=1.2)
        if r < 3:
            wire([(x + 31, y + P), (x + 31, y + P + G)], color=ORNG, sw=1.2)
    wire([(392, AY + r * (P + G) + 15), (AX, AY + r * (P + G) + 15)], color=BLUE, sw=1.2)
text(392, AY + 3 * (P + G) + 26, 22, 14, "(b)", fs=10, bold=True)
# groups into the rows, weights from the top
wire([(354, 315), (376, 315), (376, 135), (392, 135)], color=BLUE, sw=1.6)
wire([(162, 70), (184, 70), (184, 6), (523, 6), (523, 14)], color="#8A5A00", sw=1.6)
text(200, 8, 300, 14, "weights + filter labels → all PEs", fs=T3, color="#8A5A00", align="left")

# edge unit
EY = 310
box(392, EY, 262, 68, "", fill=CMP[0], stroke=CMP[1], sw=1.2)
text(392, EY + 2, 262, 18, "Edge FIFOs ×4 · RMW ×16", fs=T2 + 1, bold=True, color=CMP[1])
for c in range(4):
    fx = AX + c * (P + G) + 8
    for k in range(4):
        box(fx, EY + 26 + k * 9, 30, 9, "", fill="#FFFFFF", stroke=CMP[1], sw=0.7, rounded=False)
    wire([(AX + c * (P + G) + 31, AY + 3 * (P + G) + P), (AX + c * (P + G) + 31, EY)], color=ORNG, sw=1.2)

# output buffer
box(684, 142, 140, 236, f"Output<br>Buffer<br><span style='font-size:{T2}px'>192 KB</span><br><br>"
    f"<span style='font-size:{T3}px'>(filter, pixel)<br>8 × 24-b sums</span>", fill=MEM[0], stroke=MEM[1], fs=T1)
bulk([(654, 344), (684, 344)], both=True)
text(654, 356, 30, 14, "RMW", fs=10)

# LIF array
box(852, 14, 136, 364, "", fill="#FFFFFF", stroke=NEU[1], sw=1.2)
box(852, 14, 136, 30, "Spiking Neuron", fill=NEU[0], stroke=NEU[1], fs=T2 + 1, bold=True)
for k, yy in enumerate((60, 108, 248, 296)):
    box(878, yy, 84, 36, "LIF", fill=NEU[0], stroke=NEU[1], fs=T1)
text(878, 164, 84, 60, "⋯<br>×16", fs=T1)
text(856, 340, 128, 30, f"<span style='font-size:11px'>4-stage pipeline</span>", fs=11)
bulk([(824, 260), (852, 260)])

# output spikes back to the spike memory (next layer)
wire([(920, 378), (920, 386), (101, 386), (101, 230)], color=GRN, sw=1.6)
text(420, 384, 380, 14, "", fs=10)

# step markers
step(168, 46, 1)
step(166, 162, 2)
step(368, 96, 3)
step(630, 280, 4)
step(372, 316, 5)
step(800, 146, 6)
step(964, 47, 7)
text(0, 440, 1000, 20, "(a)", fs=T1, bold=True)

# =============================================================================================== (b) PE
BX, BY = 0, 470
box(BX, BY, 488, 262, "", fill="#FBFBFB", stroke="#BDBDBD", sw=1.0, dashed=True)
text(BX + 10, BY + 6, 200, 18, "(b) PE", fs=T1, bold=True, align="left")
# weight registers (active + shadow)
box(BX + 18, BY + 92, 92, 40, "w | f", fill=NEW[0], stroke=NEW[1], fs=T1)
box(BX + 18, BY + 140, 92, 30, "w′ | f′", fill="#FFFFFF", stroke=NEW[1], fs=T2, dashed=True)
text(BX + 14, BY + 172, 100, 30, "active / shadow<br>(load overlaps)", fs=11)
# running sums in (from above)
wire([(BX + 300, BY + 30), (BX + 300, BY + 58)], color=ORNG, sw=1.8)
text(BX + 308, BY + 28, 175, 28, "running sums in:<br>16 slots × 8 t", fs=T3, color=ORNG, align="left")
box(BX + 130, BY + 58, 340, 26, "select slot {f, ℓ<sub>t</sub>}", fill="#FFFFFF", stroke=GREY, fs=T2)
for t in range(8):
    cx = BX + 146 + t * 41
    add("+", f"ellipse;html=1;fillColor=#FFFFFF;strokeColor={NEW[1]};strokeWidth=1.4;fontFamily={FONT};"
             f"fontSize=16;fontStyle=1;", f'<mxGeometry x="{cx}" y="{BY + 102}" width="28" height="28" as="geometry"/>')
    text(cx + 26, BY + 88, 16, 12, f"t{t}", fs=9, color="#555555")
    wire([(cx + 14, BY + 84), (cx + 14, BY + 102)], color=ORNG, sw=1.0)
    wire([(cx + 14, BY + 130), (cx + 14, BY + 150)], color=ORNG, sw=1.0)
wire([(BX + 110, BY + 112), (BX + 146, BY + 116)], color=INK, sw=1.4)
box(BX + 130, BY + 150, 340, 26, "write back if s<sub>t</sub> = 1 · set touch bit", fill="#FFFFFF", stroke=GREY, fs=T2)
wire([(BX + 300, BY + 176), (BX + 300, BY + 196)], color=ORNG, sw=1.8)
text(BX + 308, BY + 182, 170, 16, "to PE below", fs=T3, color=ORNG, align="left")
# spikes + labels: left to right
wire([(BX + 6, BY + 214), (BX + 482, BY + 214)], color=BLUE, sw=1.8)
text(BX + 10, BY + 220, 300, 30, "spike bits s<sub>t</sub> (8 b) + pixel labels ℓ<sub>t</sub> (8 × 2 b) "
     "→ next PE", fs=T3, color=BLUE, align="left")

# =============================================================================================== (c) packing formats
CX, CY = 506, 470
box(CX, CY, 494, 262, "", fill="#FBFBFB", stroke="#BDBDBD", sw=1.0, dashed=True)
text(CX + 10, CY + 6, 400, 18, "(c) Packed formats", fs=T1, bold=True, align="left")
text(CX + 12, CY + 34, 470, 16, "Group (127 b) — up to G = 4 pixels of one K-tile", fs=T2, bold=True, align="left")
x = CX + 12
for lab, w, f in (("32 spike bits", 120, "#FFFFFF"), ("32 × 2-b pixel labels", 172, NEW[0]),
                  ("4 × 7-b pixel ids", 120, CMP[0]), ("cnt", 38, CMP[0])):
    box(x, CY + 54, w, 30, lab, fill=f, stroke=INK, fs=T3, sw=1.0, rounded=False)
    x += w
for lab, x0, w in (("4 rows × 8 t", CX + 12, 120), ("which pixel owns each bit", CX + 132, 172),
                   ("routed to the edge unit", CX + 304, 158)):
    text(x0, CY + 88, w, 14, lab, fs=10, color="#555555")
text(CX + 12, CY + 118, 470, 16, "Weight column (64 b) — up to F = 4 filters of one K-tile", fs=T2, bold=True,
     align="left")
x = CX + 12
for lab, w, f in (("4 × 8-b weights", 150, "#FFFFFF"), ("4 × 2-b filter labels", 150, NEW[0]),
                  ("4 × 6-b filter ids", 150, CMP[0])):
    box(x, CY + 138, w, 30, lab, fill=f, stroke=INK, fs=T3, sw=1.0, rounded=False)
    x += w
text(CX + 12, CY + 176, 470, 74, "Filters share a column when their non-zero weights never fall in the same row "
     "(offline). Pixels share a group when their spikes never fall on the same (row, timestep) bit (run time). "
     "Labels route every addition, so no PE searches or compares.", fs=T3, align="left", color="#333333")

xml = ('<mxfile host="drawio"><diagram id="arch" name="architecture"><mxGraphModel grid="0" gridSize="10" guides="1" '
       'tooltips="1" connect="0" arrows="1" fold="1" page="0" pageScale="1" pageWidth="1000" pageHeight="740" '
       'math="0" shadow="0"><root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) +
       "</root></mxGraphModel></diagram></mxfile>")
src = os.path.join(HERE, "arch.drawio")
open(src, "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "4", "-o", os.path.join(HERE, "arch.pdf"), src], check=True,
               capture_output=True)
subprocess.run([app, "-x", "-f", "png", "-s", "3", "-b", "8", "-o", os.path.join(HERE, "arch.png"), src], check=True,
               capture_output=True)
print("ok")
