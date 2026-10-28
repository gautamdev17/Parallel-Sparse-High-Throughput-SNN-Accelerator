"""
make_pe_ftp.py -- the TIDES processing element (ours_pe in hw/rtl/ours/ours_core.v), Verdana bold as the paper's
Fig. 2, showing explicitly
  * full temporal parallelism: the packed train arrives as T = 8 bits (+ member labels), bit t drops into lane t, and
    the T lanes (one adder each) are drawn as a stack, all updating in the same cycle;
  * the 16 running sums: Bundle In and Bundle Reg as 16 slots (4 filter labels x 4 member labels) x T grids, with the
    cells written this cycle shaded.
Example cycle: weight w with filter label f = 1; train bits 0 1 1 0 1 0 0 1 with member labels - 0 1 - 1 - - 3, so
lane t writes slot 4 f + l[t]: slot 4 at t1, slot 5 at t2 and t4, slot 7 at t7 (computed below).

  python3 make_pe_ftp.py   -> <repo>/TIDES_pe_ftp.drawio (+ .pdf, .png)
"""
import html, os, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
OUT = os.path.join(REPO, "TIDES_pe_ftp")
FONT = "Verdana"
INK, NOTE = "#1A1A1A", "#555555"
FRAME, FRAME_S = "#F3F6FB", "#4A6A9B"
ROWR_S = "#7D5A93"
WREG, WREG_S = "#D5E8D4", "#5E8F4E"
BUN, BUN_S, HOT = "#FFF2CC", "#C9A93A", "#F2B544"
LOGIC, LOGIC_S = "#DAE8FC", "#5A7FB5"
DEC, DEC_S = "#DDF1EA", "#4D8C7A"
SPIKE = "#7EA6E1"
FBAND = ["#F8CECC", "#DAE8FC", "#D5E8D4", "#E1D5E7"]   # filter label 0..3 bands of the grids

T, F, G = 8, 4, 4
BITS = [0, 1, 1, 0, 1, 0, 0, 1]
LABS = [None, 0, 1, None, 1, None, None, 3]
FL = 1
WRITES = {(FL * G + LABS[t], t) for t in range(T) if BITS[t]}        # (slot, timestep)
assert WRITES == {(4, 1), (5, 2), (5, 4), (7, 7)}

cells, _id = [], [10]


def add(v, st, geo, vertex=True):
    _id[0] += 1
    cells.append(f'<mxCell id="c{_id[0]}" value="{html.escape(v, quote=True)}" style="{st}" '
                 f'{"vertex" if vertex else "edge"}="1" parent="1">{geo}</mxCell>')


def geo(x, y, w, h):
    return f'<mxGeometry x="{x}" y="{y}" width="{w}" height="{h}" as="geometry"/>'


def box(x, y, w, h, label="", fill="#FFFFFF", stroke=INK, fs=11, sw=1.2, r=8, fc=INK):
    st = (f"whiteSpace=wrap;html=1;rounded={1 if r else 0};arcSize={r};absoluteArcSize=1;fillColor={fill};"
          f"strokeColor={stroke};strokeWidth={sw};fontFamily={FONT};fontSize={fs};fontColor={fc};spacing=1;"
          f"fontStyle=1;")
    add(label, st, geo(x, y, w, h))


def lbl(title, sub):
    return f"{title}<br><span style='font-size:8px;color:{NOTE}'>{sub}</span>"


def text(x, y, w, h, label, fs=9, align="left", color=NOTE):
    st = (f"text;html=1;whiteSpace=wrap;fontFamily={FONT};fontSize={fs};fontColor={color};align={align};"
          f"verticalAlign=middle;spacing=0;fontStyle=1;")
    add(label, st, geo(x, y, w, h))


def wire(pts, jump=False, size=6, sw=1.3, color=INK):
    (x0, y0), (x1, y1) = pts[0], pts[-1]
    mid = "".join(f'<mxPoint x="{x}" y="{y}"/>' for x, y in pts[1:-1])
    st = (f"endArrow=block;endFill=1;endSize={size};html=1;rounded=0;strokeColor={color};strokeWidth={sw};"
          f"{'jumpStyle=arc;jumpSize=8;' if jump else ''}")
    arr = f'<Array as="points">{mid}</Array>' if mid else ""
    add("", st, f'<mxGeometry relative="1" as="geometry"><mxPoint x="{x0}" y="{y0}" as="sourcePoint"/>'
                f'<mxPoint x="{x1}" y="{y1}" as="targetPoint"/>{arr}</mxGeometry>', vertex=False)


def grid(gx, gy, hot, labels_left):
    """16 slots (rows, grouped by filter label) x T timesteps (columns); hot = {(slot, t)} shaded."""
    cw, ch = 12, 9
    for t in range(T):
        text(gx + t * cw, gy - 12, cw, 10, f"{t}", fs=7, align="center")
    for s in range(F * G):
        f = s // G
        for t in range(T):
            box(gx + t * cw, gy + s * ch, cw, ch, "", fill=HOT if (s, t) in hot else FBAND[f], stroke="#8A8A8A",
                sw=0.5, r=0)
    for f in range(F):
        y = gy + f * G * ch
        if labels_left:
            text(gx - 30, y, 28, G * ch, f"f={f}", fs=8, align="right")
        else:
            text(gx + T * cw + 3, y, 30, G * ch, f"f={f}", fs=8)
    box(gx - 1, gy - 1, T * cw + 2, F * G * ch + 2, "", fill="none", stroke=BUN_S, sw=1.4, r=0)
    return gx + T * cw, gy + F * G * ch


W, H = 770, 400
box(0, 0, W, H, "", fill=FRAME, stroke=FRAME_S, sw=2.2, r=16)
text(14, 6, 240, 20, "Processing Element", fs=14, color=INK)

# ---------------------------------------------------------------- lane stack (T lanes, one adder each)
CX, CY, CW, CH, D = 176, 206, 330, 150, 13
for t in reversed(range(T)):
    x, y = CX + D * t, CY - D * t
    box(x, y, CW, CH, "", fill="#FFFFFF" if t else "#FFFFFF", stroke=LOGIC_S if t == 0 else "#A9B6CC",
        sw=1.3 if t == 0 else 0.9, r=8)
    text(x + CW - 34, y + 1, 30, 11, f"t{t}", fs=7, align="right", color="#7A8BA8")

# front lane in detail
box(CX + 18, CY + 26, 72, 40, lbl("Read", "16 : 1"), fill=LOGIC, stroke=LOGIC_S)
add("+ w", f"ellipse;html=1;fillColor={LOGIC};strokeColor={LOGIC_S};strokeWidth=1.2;fontFamily={FONT};"
           f"fontSize=11;fontStyle=1;", geo(CX + 118, CY + 26, 40, 40))
box(CX + 186, CY + 26, 72, 40, lbl("Write", "1 : 16"), fill=LOGIC, stroke=LOGIC_S)
box(CX + 18, CY + 90, 240, 40, lbl("Lane Decode", "slot = 4f + ℓ[t]   ·   we = v · s[t] · (w ≠ 0)"), fill=DEC,
    stroke=DEC_S)
wire([(CX + 90, CY + 46), (CX + 118, CY + 46)])
wire([(CX + 158, CY + 46), (CX + 186, CY + 46)])
wire([(CX + 54, CY + 90), (CX + 54, CY + 66)], size=5)
text(CX + 58, CY + 70, 30, 12, "slot", fs=8)
wire([(CX + 222, CY + 90), (CX + 222, CY + 66)], size=5)
text(CX + 226, CY + 70, 60, 12, "slot, we", fs=8)
text(CX + 270, CY + CH - 16, 56, 12, "lane t", fs=8, align="right", color=LOGIC_S)

# ---------------------------------------------------------------- packed train: bit t -> lane t (FTP)
TY = 46
text(CX - 82, TY - 1, 76, 12, "s[t]", fs=8, align="right", color=INK)
text(CX - 82, TY + 13, 76, 12, "ℓ[t]", fs=8, align="right", color=INK)
text(CX - 82, TY - 18, 120, 12, "Row Reg", fs=10, color=ROWR_S)
for t in range(T):
    x = CX + D * t + 1
    box(x, TY, 12, 13, str(BITS[t]), fill=SPIKE if BITS[t] else "#FFFFFF", r=0, fs=7, sw=0.8,
        fc="#FFFFFF" if BITS[t] else NOTE)
    box(x, TY + 13, 12, 13, "–" if LABS[t] is None else str(LABS[t]), r=0, fs=7, sw=0.8)
    wire([(x + 6, TY + 26), (x + 6, CY - D * t)], size=4, sw=1.0, color=ROWR_S)
text(CX + D * T + 6, TY + 4, 220, 20, "bit t → lane t: all T timesteps in one cycle", fs=8, color=ROWR_S)
wire([(10, TY + 13), (CX - 4, TY + 13)], jump=True)
text(10, TY + 15, 90, 12, "from left PE", fs=8, color=INK)
wire([(CX + D * (T - 1) + 7, TY), (CX + D * (T - 1) + 7, 22), (W + 40, 22)], jump=True)
text(W - 4, 6, 90, 14, "to right PE", fs=8, color=INK)

# ---------------------------------------------------------------- weight register: broadcast to all lanes
box(560, 52, 110, 44, lbl("Weight Reg", "w · f = 1 (+ shadow)"), fill=WREG, stroke=WREG_S)
wire([(615, -24), (615, 52)])
text(621, -24, 80, 14, "weight load", fs=8, color=INK)
wire([(580, 96), (580, CY - D * (T - 1) + 40), (CX + D * (T - 1) + CW, CY - D * (T - 1) + 40)], size=5)
text(584, 102, 130, 12, "w, f → all T lanes", fs=8, color=WREG_S)

# ---------------------------------------------------------------- running sums: 16 slots x T
gx1, gy = 44, 206
x1, y1 = grid(gx1, gy, set(), labels_left=True)
text(gx1 - 30, y1 + 4, 130, 26, "Bundle In<br><span style='font-weight:normal'>16 sums × T</span>", fs=9,
     color=INK, align="center")
wire([(gx1 + 48, -24), (gx1 + 48, gy - 14)], jump=True)
text(gx1 + 54, -24, 90, 14, "from PE above", fs=8, color=INK)
wire([(x1, CY + 46), (CX + 18, CY + 46)])
text(x1 + 2, CY + 32, 40, 12, "old", fs=8)

gx2 = 652
x2, y2 = grid(gx2, gy, WRITES, labels_left=False)
wire([(CX + 258, CY + 46), (gx2 - 1, CY + 46)])
text(gx2 - 40, CY + 32, 36, 12, "new", fs=8, align="right")
text(gx2 - 30, y2 + 4, 140, 26, "Bundle Reg<br><span style='font-weight:normal'>shaded: written</span>", fs=9,
     color=INK, align="center")
wire([(gx2 + 48, y2 + 30), (gx2 + 48, H + 30)])
text(gx2 + 54, H + 14, 90, 14, "to PE below", fs=8, color=INK)

xml = ('<mxfile host="drawio"><diagram id="tidespe6" name="TIDES PE"><mxGraphModel grid="0" page="0">'
       '<root><mxCell id="0"/><mxCell id="1" parent="0"/>' + "".join(cells) + "</root></mxGraphModel></diagram></mxfile>")
open(OUT + ".drawio", "w").write(xml)
app = "/Applications/draw.io.app/Contents/MacOS/draw.io"
if os.path.exists(app):
    subprocess.run([app, "-x", "-f", "pdf", "--crop", "-b", "3", "-o", OUT + ".pdf", OUT + ".drawio"],
                   check=True, capture_output=True)
    subprocess.run([app, "-x", "-f", "png", "-s", "3", "-b", "6", "-o", OUT + ".png", OUT + ".drawio"],
                   check=True, capture_output=True)
print(OUT + ".drawio")
