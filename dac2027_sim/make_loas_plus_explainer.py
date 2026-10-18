"""make_loas_plus_explainer.py -- "LoAS+, Explained from Scratch" (ReportLab, A4), in the style of
DAC2027_accelerator_explained_rows.pdf: one small example followed from start to finish.

Every number of the worked example is computed below (and asserted), not typed in.
  python3 make_loas_plus_explainer.py  -> ../LoAS_plus_explained.pdf
"""
import os
from reportlab.lib.pagesizes import A4
from reportlab.lib import colors
from reportlab.lib.styles import ParagraphStyle
from reportlab.lib.enums import TA_LEFT, TA_CENTER
from reportlab.platypus import (SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle, Image, KeepTogether,
                                PageBreak, Flowable)
from reportlab.graphics.shapes import Drawing, Rect, String, Line, Polygon, Circle, Group

HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(os.path.dirname(HERE), "LoAS_plus_explained.pdf")
RES = os.path.join(HERE, "results")
DATE = "18 October 2026"

# ------------------------------------------------------------------------------------------- the example
T = 4
A = ["1010", "0000", "0110", "0000", "1111", "0001", "0000", "0100",
     "0000", "0011", "1000", "0000", "0101", "0000", "1100", "0010"]          # spike train of input k (t0..t3)
W = [0, 4, 3, 0, 2, 0, 0, 1, 0, -2, 3, 0, 1, 5, 0, 2]                       # weight of input k (one filter)
K, Q, VTH, TAU = 16, 4, 6, 0.5
bmA = [int(a != "0000") for a in A]
bmB = [int(w != 0) for w in W]
AND = [a & b for a, b in zip(bmA, bmB)]
M = [k for k in range(K) if AND[k]]
O = [sum(W[k] * int(A[k][t]) for k in M) for t in range(T)]
packA = [k for k in range(K) if bmA[k]]
packB = [k for k in range(K) if bmB[k]]
baseA = [sum(bmA[:4 * s]) for s in range(4)]
baseB = [sum(bmB[:4 * s]) for s in range(4)]
PSEUDO = sum(W[k] for k in M)
CORR = [sum(W[k] * (1 - int(A[k][t])) for k in M) for t in range(T)]
QUART = [[k for k in M if k // 4 == q] for q in range(Q)]
SET1 = [q[0] for q in QUART if q]
SET2 = [q[1] for q in QUART if len(q) > 1]
assert [PSEUDO - c for c in CORR] == O == [5, 7, 5, 1]
LIF, U, SPK = [], 0.0, ""
for t in range(T):
    X = O[t] + U
    c = int(X > VTH)
    LIF.append((X, c))
    SPK += str(c)
    U = TAU * X * (1 - c)
assert SPK == "0100"


def contrib(k):
    return [W[k] * int(A[k][t]) for t in range(T)]


def vec(v):
    return "[" + ",".join(f"{x:g}" for x in v) + "]"


def acc_after(sets):
    acc = [0] * T
    for s in sets:
        for k in s:
            acc = [a + c for a, c in zip(acc, contrib(k))]
    return acc


# ----------------------------------------------------------------------------------------------- styles
BLUE = colors.HexColor("#1a5fb4")
GREY = colors.HexColor("#666666")
INK = colors.HexColor("#111111")
EDGE = colors.HexColor("#9aa3ad")
QFILL = [colors.HexColor(c) for c in ("#dbe7f7", "#fbe3cf", "#dcefe1", "#e9dff5")]
QSTRK = [colors.HexColor(c) for c in ("#2f6fd0", "#e07b22", "#2e9b55", "#8a4fc8")]
QTEXT = [colors.HexColor(c) for c in ("#1f56a8", "#b85d10", "#23774a", "#6c3aa3")]
RED_F, RED_S = colors.HexColor("#f8dede"), colors.HexColor("#c0392b")
YEL_F, YEL_S = colors.HexColor("#fff4cc"), colors.HexColor("#e6c86e")
ORA_F, ORA_S = colors.HexColor("#fde2bf"), colors.HexColor("#e8871e")
GRN_F, GRN_S = colors.HexColor("#dcefe1"), colors.HexColor("#2e9b55")
BLU_F, BLU_S = colors.HexColor("#e3edf9"), colors.HexColor("#2f6fd0")
PUR_F, PUR_S = colors.HexColor("#ece3f7"), colors.HexColor("#8a4fc8")
SIL = colors.HexColor("#f1f1f1")
HDR = colors.HexColor("#eef2f7")

ss = {}
ss["title"] = ParagraphStyle("title", fontName="Helvetica-Bold", fontSize=20, leading=24, textColor=INK, spaceAfter=4)
ss["sub"] = ParagraphStyle("sub", fontName="Helvetica", fontSize=10.5, leading=14, textColor=GREY, spaceAfter=8)
ss["h1"] = ParagraphStyle("h1", fontName="Helvetica-Bold", fontSize=14, leading=18, textColor=BLUE, spaceBefore=10,
                          spaceAfter=5, keepWithNext=1)
ss["body"] = ParagraphStyle("body", fontName="Helvetica", fontSize=9.5, leading=13.2, textColor=INK, spaceAfter=5)
ss["bullet"] = ParagraphStyle("bullet", parent=ss["body"], leftIndent=12, bulletIndent=2, spaceAfter=2)
ss["cap"] = ParagraphStyle("cap", fontName="Helvetica", fontSize=8.2, leading=10.5, textColor=GREY, spaceBefore=3,
                           spaceAfter=8)
ss["cell"] = ParagraphStyle("cell", fontName="Helvetica", fontSize=8, leading=10, textColor=INK)
ss["cellb"] = ParagraphStyle("cellb", parent=ss["cell"], fontName="Helvetica-Bold")
ss["mono"] = ParagraphStyle("mono", fontName="Courier", fontSize=8, leading=10, textColor=INK, alignment=TA_CENTER)
ss["box"] = ParagraphStyle("box", parent=ss["body"], backColor=YEL_F, borderColor=YEL_S, borderWidth=0.7,
                           borderPadding=6, spaceBefore=4, spaceAfter=10)
ss["note"] = ParagraphStyle("note", parent=ss["body"], backColor=colors.HexColor("#f4f7fb"),
                            borderColor=colors.HexColor("#c9d6e6"), borderWidth=0.6, borderPadding=6, spaceBefore=4,
                            spaceAfter=10)


def P(t, s="body"):
    return Paragraph(t, ss[s])


def H(t):
    return Paragraph(t, ss["h1"])


def C(t):
    return Paragraph(t, ss["cap"])


def bullets(items):
    return [Paragraph(i, ss["bullet"], bulletText="•") for i in items]


def cell(t, bold=False):
    return Paragraph(t, ss["cellb" if bold else "cell"])


def grid(data, widths, extra=(), header=True, font=8):
    t = Table(data, colWidths=widths)
    st = [("FONT", (0, 0), (-1, -1), "Helvetica", font), ("GRID", (0, 0), (-1, -1), 0.4, EDGE),
          ("VALIGN", (0, 0), (-1, -1), "MIDDLE"), ("TOPPADDING", (0, 0), (-1, -1), 2.5),
          ("BOTTOMPADDING", (0, 0), (-1, -1), 2.5), ("LEFTPADDING", (0, 0), (-1, -1), 3.5),
          ("RIGHTPADDING", (0, 0), (-1, -1), 3.5)]
    if header:
        st += [("BACKGROUND", (0, 0), (-1, 0), HDR), ("FONT", (0, 0), (-1, 0), "Helvetica-Bold", font)]
    t.setStyle(TableStyle(st + list(extra)))
    return t


# ------------------------------------------------------------------------------------------ draw helpers
def arrow(d, x1, y1, x2, y2, col=INK, w=0.8, dash=None):
    ln = Line(x1, y1, x2, y2, strokeColor=col, strokeWidth=w)
    if dash:
        ln.strokeDashArray = dash
    d.add(ln)
    import math
    a = math.atan2(y2 - y1, x2 - x1)
    s = 4.5
    d.add(Polygon([x2, y2, x2 - s * math.cos(a - 0.4), y2 - s * math.sin(a - 0.4),
                   x2 - s * math.cos(a + 0.4), y2 - s * math.sin(a + 0.4)], fillColor=col, strokeColor=col,
                  strokeWidth=0.3))


def box(d, x, y, w, h, fill, stroke, title, lines=(), tcol=None, fs=8.2, lfs=6.8, sw=0.9):
    d.add(Rect(x, y, w, h, rx=4, ry=4, fillColor=fill, strokeColor=stroke, strokeWidth=sw))
    n = len(lines)
    top = y + h / 2 + (n * (lfs + 2.2)) / 2 + 2
    d.add(String(x + w / 2, top, title, fontName="Helvetica-Bold", fontSize=fs, fillColor=tcol or INK,
                 textAnchor="middle"))
    for i, l in enumerate(lines):
        d.add(String(x + w / 2, top - (i + 1) * (lfs + 2.4) - 1, l, fontName="Helvetica", fontSize=lfs,
                     fillColor=colors.HexColor("#333333"), textAnchor="middle"))


def badge(d, x, y, n):
    d.add(Circle(x, y, 7, fillColor=RED_S, strokeColor=RED_S))
    d.add(String(x, y - 2.6, str(n), fontName="Helvetica-Bold", fontSize=7.5, fillColor=colors.white,
                 textAnchor="middle"))


# ------------------------------------------------------------------------------------------ the figures
def fig_inputs():
    """Figure 1: the 16 inputs of the chunk: spike trains and weights, coloured by quarter."""
    hdr = [cell("", True)] + [cell(f"k{k}", True) for k in range(K)]
    r1 = [cell("spike train<br/>(t0 t1 t2 t3)", True)] + [Paragraph(A[k], ss["mono"]) for k in range(K)]
    r2 = [cell("weight", True)] + [Paragraph(f"{W[k]}", ss["mono"]) for k in range(K)]
    cw = 495 / 17.6
    t = grid([hdr, r1, r2], [cw * 1.6] + [cw] * K, header=False)
    st = [("BACKGROUND", (0, 0), (-1, 0), HDR)]
    for k in range(K):
        q = k // 4
        st += [("TEXTCOLOR", (k + 1, 0), (k + 1, 0), QTEXT[q]), ("BACKGROUND", (k + 1, 0), (k + 1, 0), QFILL[q])]
        if not bmA[k]:
            st.append(("BACKGROUND", (k + 1, 1), (k + 1, 1), SIL))
        if not bmB[k]:
            st.append(("BACKGROUND", (k + 1, 2), (k + 1, 2), SIL))
        if AND[k]:
            st += [("BOX", (k + 1, 1), (k + 1, 2), 1.2, QSTRK[q])]
    t.setStyle(TableStyle(st))
    return t


def fig_answer():
    rows = [["input", "weight", "spike train", "adds (t0..t3)"]]
    for k in M:
        rows.append([f"k{k}", f"{W[k]}", A[k], vec(contrib(k))])
    rows.append(["", "", "sum = output current", vec(O)])
    t = grid(rows, [45, 45, 110, 110],
             extra=[("FONT", (0, len(rows) - 1), (-1, len(rows) - 1), "Helvetica-Bold", 8),
                    ("FONT", (2, 1), (2, -2), "Courier", 8), ("ALIGN", (0, 0), (-1, -1), "CENTER")])
    lif = [["timestep", "current", "V before = current + carried", "fires? (V > 6)", "carried to next = 0.5 V"]]
    U = 0.0
    for t_ in range(T):
        X, c = LIF[t_]
        lif.append([f"t{t_}", f"{O[t_]}", f"{O[t_]} + {U:g} = {X:g}", "yes" if c else "no",
                    "0 (reset)" if c else f"{TAU * X:g}"])
        U = TAU * X * (1 - c)
    l = grid(lif, [50, 50, 140, 70, 110], extra=[("ALIGN", (0, 0), (-1, -1), "CENTER"),
                                                 ("BACKGROUND", (3, 2), (3, 2), GRN_F)])
    return t, l


def fig_format():
    """Figure 3: what LoAS keeps in memory for the chunk."""
    cw = 495 / 17.6
    hdr = [cell("position", True)] + [cell(f"k{k}", True) for k in range(K)]
    ra = [cell("bitmask A", True)] + [Paragraph(str(bmA[k]), ss["mono"]) for k in range(K)]
    rb = [cell("bitmask B", True)] + [Paragraph(str(bmB[k]), ss["mono"]) for k in range(K)]
    t1 = grid([hdr, ra, rb], [cw * 1.6] + [cw] * K, header=False,
              extra=[("BACKGROUND", (0, 0), (-1, 0), HDR)] +
                    [("BACKGROUND", (k + 1, 0), (k + 1, 0), QFILL[k // 4]) for k in range(K)] +
                    [("BACKGROUND", (k + 1, 1), (k + 1, 1), BLU_F) for k in range(K) if bmA[k]] +
                    [("BACKGROUND", (k + 1, 2), (k + 1, 2), ORA_F) for k in range(K) if bmB[k]])
    cw2 = 495 / 11.6
    pa = [[cell("packed spike trains (fibre A)", True)] + [cell(f"<b>{i}</b>: k{k}") for i, k in enumerate(packA)],
          [cell("value", True)] + [Paragraph(A[k], ss["mono"]) for k in packA]]
    t2 = grid(pa, [cw2 * 1.6] + [cw2] * len(packA), header=False,
              extra=[("BACKGROUND", (1, 0), (-1, -1), BLU_F), ("BACKGROUND", (0, 0), (0, -1), HDR)])
    pb = [[cell("packed weights (fibre B)", True)] + [cell(f"<b>{i}</b>: k{k}") for i, k in enumerate(packB)],
          [cell("value", True)] + [Paragraph(str(W[k]), ss["mono"]) for k in packB]]
    t3 = grid(pb, [cw2 * 1.6] + [cw2] * len(packB) + [], header=False,
              extra=[("BACKGROUND", (1, 0), (-1, -1), ORA_F), ("BACKGROUND", (0, 0), (0, -1), HDR)])
    return t1, t2, t3


def timeline(rows, ncyc, title_w=118):
    """rows: [(label, {cycle: (text, fill)})] -> table with one column per cycle."""
    cw = (495 - title_w) / ncyc
    data = [[cell("unit \\ cycle", True)] + [cell(str(c), True) for c in range(ncyc)]]
    st = []
    for r, (lab, cells) in enumerate(rows, start=1):
        line = [cell(lab, True)]
        for c in range(ncyc):
            txt, fill = cells.get(c, ("", None))
            line.append(Paragraph(f"<font size=6.3>{txt}</font>", ss["mono"]))
            if fill is not None:
                st.append(("BACKGROUND", (c + 1, r), (c + 1, r), fill))
        data.append(line)
    t = grid(data, [title_w] + [cw] * ncyc, extra=st + [("LEFTPADDING", (1, 0), (-1, -1), 0.5),
                                                       ("RIGHTPADDING", (1, 0), (-1, -1), 0.5),
                                                       ("ALIGN", (1, 0), (-1, 0), "CENTER")])
    return t


def fig_loas_timeline():
    rows = [("load bitmasks + weights", {0: ("bm", BLU_F), 1: ("w", ORA_F)}),
            ("inner join (AND)", {2: ("AND", YEL_F)})]
    fast = {}
    run = 0
    for i, k in enumerate(M):
        run += W[k]
        fast[3 + i] = (f"k{k}<br/>{run}", ORA_F)
    rows.append(("fast prefix sum +<br/>pseudo-accumulator", fast))
    rows.append(("laggy prefix sum", {c: ("..." if c < 10 else "rdy", RED_F) for c in range(3, 11)}))
    cor = {}
    for i, k in enumerate(M):
        cor[11 + i] = (f"k{k}<br/>{A[k]}", GRN_F)
    cor[18] = ("last", GRN_F)
    rows.append(("correction (fibre A read<br/>from cache, subtract)", cor))
    return timeline(rows, 19)


def fig_offsets():
    rows = [["match", "segment", "offset in fibre A", "spike train", "offset in fibre B", "weight"]]
    for k in M:
        s = k // 4
        ca, cb = sum(bmA[4 * s:k]), sum(bmB[4 * s:k])
        oa, ob = baseA[s] + ca, baseB[s] + cb
        assert packA[oa] == k and packB[ob] == k
        rows.append([f"k{k}", f"{s}  (k{4 * s}-k{4 * s + 3})", f"{baseA[s]} + {ca} = {oa}", A[k],
                     f"{baseB[s]} + {cb} = {ob}", f"{W[k]}"])
    t = grid(rows, [45, 80, 95, 70, 95, 50], extra=[("ALIGN", (0, 0), (-1, -1), "CENTER"),
                                                    ("FONT", (3, 1), (3, -1), "Courier", 8)] +
                                                   [("BACKGROUND", (0, r), (0, r), QFILL[M[r - 1] // 4])
                                                    for r in range(1, len(rows))])
    bases = [["segment", "0 (k0-k3)", "1 (k4-k7)", "2 (k8-k11)", "3 (k12-k15)"],
             ["base A: non-silent inputs before it"] + [str(b) for b in baseA],
             ["base B: non-zero weights before it"] + [str(b) for b in baseB]]
    tb = grid(bases, [175, 80, 80, 80, 80], extra=[("ALIGN", (1, 0), (-1, -1), "CENTER")] +
                                                  [("BACKGROUND", (s + 1, 0), (s + 1, 0), QFILL[s]) for s in range(4)])
    return tb, t


def fig_c1_timeline():
    rows = [("load bitmasks + bases + weights", {0: ("bm", BLU_F), 1: ("w", ORA_F)}),
            ("start: AND", {2: ("AND", YEL_F)})]
    s0, s1, s2, s3 = {}, {}, {}, {}
    acc = [0] * T
    for i, k in enumerate(M):
        s0[3 + i] = (f"k{k}", YEL_F)
        s1[4 + i] = (f"k{k}", ORA_F)
        s2[5 + i] = (f"k{k}", BLU_F)
        acc = [a + c for a, c in zip(acc, contrib(k))]
        s3[6 + i] = (f"k{k}", GRN_F)
    rows += [("S0 find next match", s0), ("S1 offsets + weight", s1), ("S2 read spike train", s2),
             ("S3 add into t0..t3", s3)]
    return timeline(rows, 13)


def fig_quarters():
    cw = 495 / 17.6
    hdr = [cell("AND bit", True)] + [cell(f"k{k}", True) for k in range(K)]
    r0 = [cell("", True)] + [Paragraph(str(AND[k]), ss["mono"]) for k in range(K)]
    r1 = [cell("found in cycle 3", True)] + [Paragraph("X" if k in SET1 else "", ss["mono"]) for k in range(K)]
    r2 = [cell("found in cycle 4", True)] + [Paragraph("X" if k in SET2 else "", ss["mono"]) for k in range(K)]
    st = [("BACKGROUND", (0, 0), (-1, 0), HDR)]
    for k in range(K):
        q = k // 4
        st += [("BACKGROUND", (k + 1, 0), (k + 1, 0), QFILL[q]), ("TEXTCOLOR", (k + 1, 0), (k + 1, 0), QTEXT[q])]
        if k in SET1:
            st.append(("BACKGROUND", (k + 1, 2), (k + 1, 2), QFILL[q]))
        if k in SET2:
            st.append(("BACKGROUND", (k + 1, 3), (k + 1, 3), QFILL[q]))
        if k % 4 == 0 and k:
            st.append(("LINEBEFORE", (k + 1, 0), (k + 1, -1), 1.6, INK))
    return grid([hdr, r0, r1, r2], [cw * 1.6] + [cw] * K, header=False, extra=st)


def fig_c2_timeline():
    rows = [("load bitmasks + bases + weights", {0: ("bm", BLU_F), 1: ("w", ORA_F)}),
            ("start: AND", {2: ("AND", YEL_F)})]
    a1 = " ".join(f"k{k}" for k in SET1[:2]) + "<br/>" + " ".join(f"k{k}" for k in SET1[2:])
    a2 = " ".join(f"k{k}" for k in SET2[:2]) + "<br/>" + " ".join(f"k{k}" for k in SET2[2:])
    rows += [("S0 find (4 quarters)", {3: (a1, YEL_F), 4: (a2, YEL_F)}),
             ("S1 offsets + weights", {4: (a1, ORA_F), 5: (a2, ORA_F)}),
             ("S2 read spike trains", {5: (a1, BLU_F), 6: (a2, BLU_F)}),
             ("S3 add into t0..t3", {6: (vec(acc_after([SET1])), GRN_F), 7: (vec(acc_after([SET1, SET2])), GRN_F)})]
    return timeline(rows, 8, title_w=130)


def fig_gantt():
    """Figure: chunk scheduling of two TPPEs: lock step / + double buffering / elastic queues (C3)."""
    cost = [[5, 1, 5, 1], [1, 5, 1, 5]]

    def sched(Qd, lock):
        f = [0, 0]; b = 0; F = []; out = {"b": [], 0: [], 1: []}
        for i in range(4):
            slot = F[i - Qd] if i - Qd >= 0 else 0
            b = max(b, slot) + 1
            out["b"].append((b - 1, b, i))
            start = [max(max(f), b)] * 2 if lock else [max(f[j], b) for j in range(2)]
            for j in range(2):
                out[j].append((start[j], start[j] + cost[j][i], i))
                f[j] = start[j] + cost[j][i]
            F.append(max(f))
        return out, max(f)

    panels = [("Lock step, one buffer (LoAS)", sched(1, True)), ("Lock step, double-buffered", sched(2, True)),
              ("C3: elastic TPPEs, 4-deep queue", sched(4, False))]
    assert [p[1][1] for p in panels] == [24, 21, 13]
    unit, x0, rowh = 14, 110, 13
    h = len(panels) * (3 * rowh + 22) + 18
    d = Drawing(495, h)
    ccol = [QFILL[0], QFILL[1], QFILL[2], QFILL[3]]
    cstr = [QSTRK[0], QSTRK[1], QSTRK[2], QSTRK[3]]
    y = h - 14
    for title, (s, tot) in panels:
        d.add(String(0, y, title, fontName="Helvetica-Bold", fontSize=8, fillColor=INK))
        d.add(String(x0 + tot * unit + 4, y - 3 * rowh + 3, f"done at {tot}", fontName="Helvetica-Bold",
                     fontSize=7.5, fillColor=RED_S if tot > 13 else GRN_S))
        for r, (lab, key) in enumerate([("broadcast weights", "b"), ("TPPE 0", 0), ("TPPE 1", 1)]):
            yy = y - (r + 1) * rowh
            d.add(String(x0 - 6, yy + 3, lab, fontName="Helvetica", fontSize=7, textAnchor="end", fillColor=GREY))
            for (a, e, i) in s[key]:
                d.add(Rect(x0 + a * unit, yy, (e - a) * unit, rowh - 3, fillColor=ccol[i], strokeColor=cstr[i],
                           strokeWidth=0.7))
                d.add(String(x0 + (a + e) / 2 * unit, yy + 2.6, f"c{i}", fontName="Helvetica", fontSize=6.3,
                             textAnchor="middle", fillColor=INK))
        y -= 3 * rowh + 22
    for c in range(0, 25, 2):
        d.add(Line(x0 + c * unit, 6, x0 + c * unit, 10, strokeColor=GREY, strokeWidth=0.5))
        d.add(String(x0 + c * unit, -2, str(c), fontName="Helvetica", fontSize=6.3, textAnchor="middle", fillColor=GREY))
    return d


def fig_blocks():
    d = Drawing(495, 215)
    box(d, 0, 130, 112, 58, RED_F, RED_S, "Global cache", ["256 KB, banked", "spike fibres + bases (A)", "weight fibres + bases (B)"], RED_S)
    badge(d, 6, 186, 1)
    box(d, 0, 30, 112, 52, BLU_F, BLU_S, "Offline weight packer", ["bitmask, non-zeros in", "quarter slots, 5-bit bases"], BLU_S)
    badge(d, 6, 80, 2)
    box(d, 140, 118, 100, 80, YEL_F, YEL_S, "Broadcaster", ["skips empty weight chunks", "double-buffered: loads the", "next chunk while TPPEs", "compute this one"], colors.HexColor("#8a6d00"))
    badge(d, 146, 196, 3)
    box(d, 268, 100, 120, 110, ORA_F, ORA_S, "16 TPPEs", ["each: 4-deep chunk queue", "S0 4 quarter encoders", "S1 base + popcount offsets", "S2 4 spike-train reads", "S3 8 lanes x 4-input add", "one output neuron each"], colors.HexColor("#a0520a"))
    badge(d, 274, 208, 4)
    box(d, 410, 140, 85, 52, GRN_F, GRN_S, "P-LIF", ["8 sums -> 8 spikes", "at the end of an output"], GRN_S)
    badge(d, 416, 190, 5)
    box(d, 410, 40, 85, 64, PUR_F, PUR_S, "Compressor", ["drops silent neurons,", "writes bitmask A +", "7-bit segment bases"], PUR_S)
    badge(d, 416, 102, 6)
    arrow(d, 112, 165, 140, 165, RED_S)
    d.add(String(126, 170, "B", fontName="Helvetica", fontSize=6.5, fillColor=RED_S, textAnchor="middle"))
    arrow(d, 240, 158, 268, 158, colors.HexColor("#8a6d00"))
    arrow(d, 112, 138, 268, 110, RED_S)
    d.add(String(128, 106, "A: 4 spike-train reads per TPPE per cycle", fontName="Helvetica", fontSize=6.3, fillColor=RED_S))
    arrow(d, 56, 82, 56, 130, BLU_S)
    arrow(d, 388, 166, 410, 166, ORA_S)
    arrow(d, 452, 140, 452, 104, GRN_S)
    ln = Line(410, 92, 90, 92, strokeColor=PUR_S, strokeWidth=0.8); ln.strokeDashArray = [3, 2]; d.add(ln)
    arrow(d, 90, 92, 90, 130, PUR_S, dash=[3, 2])
    d.add(String(270, 82, "output spikes + bases = next layer's spike fibres", fontName="Helvetica", fontSize=6.5, fillColor=PUR_S, textAnchor="middle"))
    return d


def fig_tppe():
    d = Drawing(495, 150)
    st = [("S0  find", ["rem = AND of bitmasks", "4 priority encoders,", "one per 32-bit quarter", "-> up to 4 positions"], YEL_F, YEL_S),
          ("S1  offsets", ["base[seg] + popcount16", "for A (7 bit) and B (5 bit)", "weight = buffer[q*32 + off]", "(32:1 per lane)"], ORA_F, ORA_S),
          ("S2  read", ["4 spike-train reads", "from fibre A", "(1-cycle latency)", ""], BLU_F, BLU_S),
          ("S3  add", ["8 lanes (one per t)", "lane t adds every weight", "whose train has bit t = 1", "(5-input adder)"], GRN_F, GRN_S)]
    x = 0
    for i, (t, ls, f, s) in enumerate(st):
        box(d, x, 62, 100, 78, f, s, t, ls, s if s != YEL_S else colors.HexColor("#8a6d00"), lfs=6.5)
        if i:
            arrow(d, x - 18, 101, x, 101)
        x += 118
    box(d, 0, 0, 470, 46, colors.HexColor("#f6f6f6"), colors.HexColor("#bbbbbb"), "Removed from the LoAS TPPE",
        ["fast prefix-sum (52% of TPPE power, 67% of area in LoAS Table IV), laggy prefix-sum,",
         "pseudo-accumulator with all-ones speculation, FIFO-mp, FIFO-B, correction path"], GREY, lfs=6.8)
    return d


# --------------------------------------------------------------------------------------------- document
def bind(story):
    """keep every caption on the same page as the tables / drawings / images right above it."""
    out = []
    for f in story:
        if isinstance(f, Paragraph) and f.style.name == "cap":
            grp = [f]
            while out and not isinstance(out[-1], (Paragraph, KeepTogether)):
                grp.insert(0, out.pop())
            if out and isinstance(out[-1], Paragraph) and out[-1].style.name == "h1":
                grp.insert(0, out.pop())               # never leave a heading alone above its figure
            out.append(KeepTogether(grp))
        else:
            out.append(f)
    return out


def footer(canv, doc):
    canv.saveState()
    canv.setFont("Helvetica", 7.5)
    canv.setFillColor(GREY)
    canv.drawString(50, 28, f"LoAS+, explained from scratch - internal working notes, {DATE}")
    canv.drawRightString(A4[0] - 50, 28, str(doc.page))
    canv.restoreState()


def build():
    doc = SimpleDocTemplate(OUT, pagesize=A4, leftMargin=50, rightMargin=50, topMargin=48, bottomMargin=48,
                            title="LoAS+, Explained from Scratch", author="Project team")
    s = []
    s += [P("LoAS+, Explained from Scratch", "title"),
          P("One small example, followed from start to finish: first through LoAS, then through each of the three "
            f"changes that make LoAS+. Internal working notes, {DATE}.", "sub"),
          P("<b>Eight words used throughout. Spike train</b>: what one input neuron does over the T timesteps, "
            "written as T bits (1 = spike), e.g. 0110 = spikes at t1 and t2. <b>Silent</b>: an input whose spike train "
            "is all zeros. <b>Weight</b>: one number of a filter. <b>Bitmask</b>: one bit per position, 1 where the "
            "value is non-zero (non-silent input, non-zero weight). <b>Fibre</b>: a bitmask plus its non-zero values "
            "packed one after another. <b>Chunk</b>: the part of a fibre one bitmask covers (128 positions in the real "
            "design). <b>Match</b>: a position where both the input is non-silent and the weight is non-zero. "
            "<b>TPPE</b>: LoAS's processing element; it computes one output neuron for all timesteps.", "box")]

    s += [H("1. The problem"),
          P("A spiking layer is simple arithmetic: for every output neuron and every timestep, add up the weights of "
            "the inputs that spiked. After pruning, most weights are 0 and most inputs are silent, so most of that "
            "work is about zeros. LoAS (Yin et al.) already handles this well in three ways:"),
          *bullets(["<b>All timesteps at once:</b> each TPPE keeps T sums, one per timestep, so T never multiplies "
                    "the time.",
                    "<b>Only non-silent inputs and non-zero weights are stored:</b> each is a fibre (bitmask + "
                    "packed values), so zeros cost neither memory nor traffic.",
                    "<b>Inner join:</b> the TPPE ANDs the two bitmasks to find the matches, and touches only those."]),
          P("What LoAS still wastes is <b>time inside and between chunks</b>. To find where a match's values sit in "
            "the packed fibres it needs prefix sums (counting the 1s before a position). These are large circuits, so "
            "LoAS makes one fast and one slow (\"laggy\"). That forces it to guess the spike train (all ones) and correct "
            "the guess later, and it finds only one match per cycle. In addition, the 16 TPPEs move from chunk to "
            "chunk in lock step, each chunk starts with a fixed load and wait, and the slowest TPPE sets the pace. "
            "LoAS+ changes three things:"),
          *bullets(["<b>C1 Offsets without prefix sums</b> (Section 5): each fibre stores a small count at the start "
                    "of every 16-position segment, so an offset is a lookup plus a count over 16 bits. No guess, no "
                    "correction.",
                    "<b>C2 Four matches per cycle</b> (Section 6): the chunk is split into four quarters, each with "
                    "its own match finder.",
                    "<b>C3 No waiting between chunks</b> (Section 7): empty weight chunks are skipped, the next chunk "
                    "loads while the current one computes, and each TPPE runs at its own pace from a small queue."]),
          P("Nothing is approximated. LoAS+ computes exactly the same sums and spikes as LoAS. It is "
            "about 3.4x faster on the same model, with 2.9-3.3x less energy (Section 10).")]

    s += [H("2. The example and the correct answer"),
          P(f"We follow <b>one output neuron</b> (one filter at one output pixel) over one chunk of <b>{K} inputs</b>, "
            f"k0 to k15, with <b>T = {T}</b> timesteps. The real design has 128 inputs per chunk, 32 per quarter, 16 per "
            "segment and T = 8; here everything is scaled down by 8 (16 inputs, 4 per quarter, 4 per segment). The "
            "colours mark the four quarters (k0-k3, k4-k7, k8-k11, k12-k15)."),
          fig_inputs(),
          C("Figure 1. The chunk. Grey = silent input or zero weight. Outlined = a <b>match</b> (non-silent input and "
            f"non-zero weight): k{', k'.join(map(str, M))}. Only the matches change the result."),
          P("<b>The answer.</b> \"3 x 0110\" means: add 3 at every timestep whose bit is 1. Adding the 7 matches gives "
            f"the output current {vec(O)} (one number per timestep):")]
    t_ans, t_lif = fig_answer()
    s += [KeepTogether([t_ans, C(f"Figure 2. The output current of the neuron: {vec(O)}. Every design below must reproduce it.")]),
          P(f"<b>The neuron.</b> LoAS uses a leaky integrate-and-fire neuron with hard reset: V = current + carried; "
            f"if V > {VTH} the neuron spikes and nothing is carried, otherwise half of V is carried to the next "
            f"timestep. Here it spikes once, at t1, so its spike train is <b>{SPK}</b>. This spike train goes into the "
            "next layer's spike fibre."),
          t_lif, C(f"Figure 3. The neuron turns the current {vec(O)} into the spike train {SPK}. It runs once per output "
                   "neuron, after its last chunk.")]

    t1, t2, t3 = fig_format()
    s += [H("3. How LoAS stores a chunk"),
          P("LoAS never stores zeros. For the spikes (fibre A) it keeps a bitmask with 1 for every non-silent input, "
            "followed by the non-silent spike trains packed one after another. All T bits of a train are kept together, "
            "so one read gets all timesteps. The weights (fibre B) work the same way: a bitmask, then the non-zero weights."),
          t1, Spacer(1, 5), t2, Spacer(1, 4), t3,
          C(f"Figure 4. The chunk in memory. Fibre A holds {len(packA)} trains instead of {K}, and fibre B holds "
            f"{len(packB)} weights instead of {K}. The small bold number is the <b>offset</b>: where a value sits in "
            "its packed list."),
          P("The catch: the packed lists have no gaps, so position k9 is not at offset 9. Its weight is at offset "
            "4 of fibre B (four non-zero weights come before it), and its spike train is at offset 5 of fibre A. "
            "To find an offset you have to <b>count the 1s in the bitmask before that position</b>. That count is a "
            "prefix sum, and how fast you can do it decides how fast a TPPE runs.")]

    s += [H("4. How LoAS computes the chunk"),
          P("<b>4.1 Find the matches.</b> The TPPE ANDs the two bitmasks; the 1s of the result are the matches: "
            f"<b>{' '.join(str(x) for x in AND)}</b> = k{', k'.join(map(str, M))}."),
          P("<b>4.2 Two prefix sums, one fast and one slow.</b> A full-speed prefix sum over 128 bits is large: in "
            "LoAS's own breakdown the fast one alone is 52% of a TPPE's power and 67% of its area. So LoAS uses one fast "
            "prefix sum for the weights (one offset per cycle) and a cheap laggy one for the spikes (16 adders, ready "
            "after 128/16 = 8 cycles; the scaled example also takes 8 cycles with 2 adders)."),
          P("<b>4.3 Guess, then correct.</b> Because the spike trains are not known until the laggy prefix sum is ready, "
            "LoAS guesses that every matched input spiked at <b>every</b> timestep (1111). The weights go into one "
            f"pseudo-accumulator, which reaches {PSEUDO}. When the laggy prefix sum is ready, LoAS reads each matched "
            "train and subtracts its weight at every timestep where the bit is 0:"),
          grid([["timestep", "t0", "t1", "t2", "t3"], ["pseudo-accumulator (guess: all ones)"] + [str(PSEUDO)] * 4,
                ["correction (weights at the 0 bits)"] + [str(c) for c in CORR],
                ["result = guess - correction"] + [str(o) for o in O]],
               [190, 60, 60, 60, 60], extra=[("ALIGN", (1, 0), (-1, -1), "CENTER"),
                                             ("FONT", (0, 3), (-1, 3), "Helvetica-Bold", 8)]),
          C("Figure 5. The guess and the correction. The result matches Figure 2."),
          P(f"The guess costs work. The 7 matched trains have {sum(A[k].count('1') for k in M)} ones but "
            f"{sum(A[k].count('0') for k in M)} zeros, so correcting takes more additions than adding the 1s directly "
            "would have. Real spike trains are mostly zeros: on Prosperity's real VGG16 and ResNet18 traces a "
            "non-silent train has only 2-3 ones out of 8 bits."),
          P("<b>4.4 Cycle by cycle.</b> Each row is a unit inside the TPPE, each column is a clock cycle. In the "
            "fast-prefix row each cell shows the match found in that cycle and the pseudo-accumulator after it."),
          fig_loas_timeline(),
          C("Figure 6. LoAS on the chunk: 19 cycles. The fast prefix sum finishes at cycle 9, but the corrections "
            "cannot start until the laggy prefix sum is ready (cycle 10), and then go one per cycle. This is the cycle "
            "model of loas_model.py: load + join + (8 + matches + 1)."),
          P("<b>4.5 Between chunks.</b> The 16 TPPEs work on 16 output pixels of the same output channel, so they share "
            "the weight chunk, which is read once and broadcast to all 16. They move to the next chunk together. "
            "A round therefore lasts as long as the slowest TPPE plus the load, and a TPPE that finished early waits. A "
            "weight chunk with no non-zeros at all is still loaded and joined.")]

    tb, toff = fig_offsets()
    s += [H("5. Change 1 (C1): offsets without prefix sums"),
          P("<b>5.1 The idea.</b> We need the number of 1s before a position. Instead of counting from the start of the "
            "chunk, we cut the bitmask into <b>segments</b> of 16 positions (4 in the example) and store, next to the "
            "bitmask, how many 1s come before each segment. Then:"),
          P("<para alignment='center'><b>offset = base[segment] + (number of 1s in the segment before the position)</b>"
            "</para>"),
          P("The second term counts over at most 16 bits, which is a small circuit. The bases cost nothing at run "
            "time. The weights are fixed, so their bases are computed <b>offline</b> when the weights are packed. The "
            "spike fibres are written by LoAS's own output compressor (Section 8), which already counts 1s to pack the "
            "trains, so it writes the bases as it goes."),
          tb, C("Figure 7. The stored bases of the chunk: a few bits per segment, next to each bitmask."),
          toff, C("Figure 8. Every match's offsets, from a base and a small count. Example: k9 is in segment 2; fibre "
                  "A has 5 non-silent inputs before segment 2 and none in segment 2 before k9, so its train is at offset "
                  "5. Every offset here equals the one in Figure 4."),
          P("<b>5.2 What disappears.</b> Both offsets are known one cycle after the match is found, so the TPPE reads "
            "the real spike train straight away and adds the weight only at the timesteps whose bit is 1. There is "
            "nothing to guess, so there is nothing to correct: the fast and laggy prefix sums, the pseudo-accumulator, "
            "the two correction FIFOs and the correction path are all removed. Each of the T accumulators adds directly."),
          P("<b>5.3 Cycle by cycle.</b> The new TPPE is a 4-stage pipeline: <b>S0</b> finds the next match, <b>S1</b> "
            "computes both offsets and picks the weight, <b>S2</b> reads the spike train, and <b>S3</b> adds the weight "
            "into the timesteps whose bit is 1. A new match enters every cycle."),
          fig_c1_timeline(),
          C(f"Figure 9. C1 alone: 13 cycles instead of 19. The 8-cycle wait is gone. After the last match the "
            "pipeline needs 3 more cycles to drain. The accumulators end at "
            f"{vec(O)}, the same as Figure 2.")]

    s += [H("6. Change 2 (C2): four matches per cycle"),
          P("<b>6.1 The idea.</b> With C1, finding one match per cycle is the limit. Finding several at once is now "
            "cheap, because each offset only needs its own segment. LoAS+ cuts the AND result into four <b>quarters</b> "
            "(32 positions each, 4 in the example), and each quarter gets its own match finder (a priority encoder). "
            "Every cycle, each quarter hands over its lowest remaining match."),
          fig_quarters(),
          C(f"Figure 10. The four quarters of the AND result. Cycle 3 takes k{', k'.join(map(str, SET1))} (one per "
            f"quarter); cycle 4 takes k{', k'.join(map(str, SET2))}. Quarter 0 has nothing left in cycle 4. A chunk "
            "takes as many cycles as its busiest quarter has matches, here 2."),
          P("<b>6.2 Where the four weights come from.</b> Four matches need four weights per cycle. Because weights "
            "are packed offline, the packer stores each quarter's non-zero weights in that quarter's own block of the "
            "TPPE's 128-entry weight buffer (slots 0-31, 32-63, ...). A weight then sits at "
            "<i>quarter x 32 + base + count</i>, and each of the four weight selectors chooses among 32 entries "
            "instead of 128. In the example, k15's weight sits in slot 12 + 2 = 14. The buffer is 128 entries anyway, "
            "so this layout costs no storage."),
          P("<b>6.3 Adding four weights at once.</b> Each timestep has its own lane, and lane t adds every arriving "
            "weight whose spike train has a 1 at t: up to 4 weights per lane per cycle (a 5-input adder with the "
            "accumulator). In cycle 6 below, lane t1 adds k2's 3, k4's 2 and k12's 1 (k9's train has a 0 at t1)."),
          fig_c2_timeline(),
          C(f"Figure 11. C1 + C2: 8 cycles instead of 19. S3 shows the accumulators after each step: "
            f"{vec(acc_after([SET1]))} after the first four matches, then {vec(O)}, the correct answer."),
          P("<b>6.4 The price.</b> Each TPPE now reads up to four spike trains per cycle, so the global cache must "
            "serve four read ports per TPPE (more banks, same capacity). A quarter that holds most of the matches "
            "limits the chunk, so in the cycle model a chunk takes its busiest quarter's match count. That is exactly "
            "what the RTL does, not the ideal matches / 4.")]

    s += [H("7. Change 3 (C3): no waiting between chunks"),
          P("A layer is many chunks. In LoAS the 16 TPPEs share each weight chunk and step through the chunks together. "
            "Three things are lost there, and C3 removes each:"),
          *bullets(["<b>Empty weight chunks.</b> With 90-98% of weights pruned, some 128-position weight chunks hold "
                    "no non-zero weight at all, but LoAS still loads and joins them. LoAS+ keeps one \"non-empty\" bit "
                    "per chunk and skips empty ones entirely. If a chunk has weights but no TPPE finds a match, only "
                    "the bitmask is sent and the weight values are not loaded.",
                    "<b>Load, then compute.</b> LoAS loads a chunk, then computes it. LoAS+ double-buffers: the "
                    "next chunk loads while the current one is computed.",
                    "<b>Lock step.</b> Each TPPE gets a queue of 4 chunks and moves on as soon as it finishes. The "
                    "broadcast stops only when some TPPE's queue is full."]),
          P("The example below uses two TPPEs and four chunks. TPPE 0's chunks take 5, 1, 5, 1 cycles and TPPE 1's take "
            "1, 5, 1, 5 (different pixels have different matches). Broadcasting a chunk takes 1 cycle."),
          fig_gantt(),
          C("Figure 12. The same work scheduled three ways. Lock step (LoAS): every round lasts its slowest TPPE plus the "
            "load, 24 cycles. Double-buffering hides the loads: 21. Elastic queues let the short chunks fill the gaps "
            "left by the long ones: 13 cycles, the time of the busier TPPE alone. These three numbers are what "
            "loas_plus.py's scheduler computes for this case.")]

    s += [H("8. The neuron and the next layer"),
          P("When an output neuron's last chunk is added, its T accumulators hold the current. In the example that is "
            f"{vec(O)}. The P-LIF unit turns it into the spike train ({SPK}), exactly as in LoAS (Figure 3). The "
            "compressor then writes the next layer's spike fibre. It drops silent neurons, sets the bitmask bit, "
            "appends the train, and, new in LoAS+, writes each segment's base. That base is the running count the "
            "compressor already keeps to know where the next train goes."),
          P("<b>Extra memory.</b> Per 128-position chunk, fibre A gets 8 bases of 7 bits (56 bits, next to its 128-bit "
            "bitmask), and fibre B gets 8 bases of 5 bits (40 bits, offsets inside a quarter). These are small next "
            "to the values: a chunk of 128 inputs with 26% non-silent holds about 33 trains x 8 bits = 266 bits.")]

    s += [KeepTogether([H("9. The hardware, block by block"),
          fig_blocks(), C("Figure 13. The blocks of LoAS+ and the order data passes through them. The numbers match the "
                          "table below.")]),
          grid([[cell("#", True), cell("Block", True), cell("What it does in the example", True)],
                ["1", "Global cache", cell("Holds the fibres of Figure 4 together with their bases (Figure 7). Serves "
                                           "4 spike-train reads per TPPE per cycle.")],
                ["2", "Offline weight packer", cell("Builds fibre B once: the bitmask, the non-zero weights in their "
                                                    "quarter slots, the 5-bit bases and one \"chunk non-empty\" bit.")],
                ["3", "Broadcaster", cell("Sends each non-empty weight chunk to all 16 TPPEs and loads the next one "
                                          "while they compute (C3).")],
                ["4", "16 TPPEs", cell("Each computes one output neuron: S0-S3 of Figure 14 on every chunk, from its own "
                                       "4-deep queue (C1, C2, C3).")],
                ["5", "P-LIF", cell(f"After an output's last chunk, turns its T sums {vec(O)} into spikes {SPK}.")],
                ["6", "Compressor", cell("Packs the output spikes into the next layer's fibre A and writes its segment "
                                         "bases.")]],
               [18, 105, 372]),
          Spacer(1, 8), fig_tppe(),
          C("Figure 14. Inside one LoAS+ TPPE: four pipeline stages replace LoAS's prefix sums and correction path. "
            "RTL: dac2027_sim/hw/rtl/loas_plus/tppe_plus.v (bit-exact against a reference model, at RTL and gate "
            "level).")]

    s += [H("10. How much faster, and at what energy"),
          P("<b>Method.</b> Speed comes from the same cycle model as our LoAS numbers (loas_model.py: 16 TPPEs, 128-position "
            "chunks, 16-byte weight bus), with C1-C3 added (loas_plus.py). The C1 and C2 rules are the measured "
            "behaviour of the RTL. Workloads: VGG16 and ResNet18 with synthetic tensors (90% sparse weights and "
            "spikes, and LoAS's own statistics), and Prosperity's real spike traces with 90% and 98% sparse weights. "
            "Power: each TPPE is synthesized to Nangate45 45 nm and simulated at gate level on the same stimulus as "
            "the LoAS TPPE, at 800 MHz. Energy = (16 TPPEs + 256 KB cache leakage) x latency."),
          Image(os.path.join(RES, "loas_plus_speedup.png"), width=495, height=495 * 1230 / 4200),
          C("Figure 15. Speedup over LoAS, adding one change at a time. All three together: 3.4-3.5x on synthetic "
            "layers and 3.0-3.5x on real spikes, at batch 1 and 16."),
          grid([["", "LoAS TPPE", "LoAS+ TPPE"],
                ["area (Nangate45)", "0.0231 mm²", "0.0117 mm²  (-49%)"],
                ["power at 800 MHz (same stimulus)", "5.64 mW", "6.90 mW"],
                ["cycles per match (RTL, incl. the neuron)", "6.3", "0.77"],
                ["slowest register-to-register path", "3.14 ns", "2.42 ns"]],
               [200, 140, 155], extra=[("ALIGN", (1, 0), (-1, -1), "CENTER")]),
          C("Figure 16. One TPPE before and after."),
          Image(os.path.join(RES, "loas_plus_energy.png"), width=495, height=495 * 1200 / 4200),
          C("Figure 17. Power, energy per image and energy-delay product. LoAS+ draws slightly more power (410 vs 390 "
            "mW with the cache) but finishes about 3.4x sooner. That gives 2.9-3.3x less energy and 8.6-11.3x lower "
            "EDP."),
          P("<b>Both comparisons favour LoAS.</b> The LoAS TPPE RTL we measure fails its own reference check and runs "
            "slowly (6.3 cycles per match), so its measured power reflects low activity. The LoAS+ TPPE is measured "
            "while it is busy every cycle.")]

    s += [H("11. How this differs from LoAS"),
          grid([[cell("", True), cell("LoAS", True), cell("LoAS+", True)],
                [cell("finding a match's offset", True), cell("prefix sum over 128 bits (one fast, one laggy)"),
                 cell("stored base per 16-bit segment + count over 16 bits")],
                [cell("spike train of a match", True), cell("guessed as all ones, corrected 8+ cycles later"),
                 cell("read directly, 1 cycle after the match")],
                [cell("matches per cycle", True), cell("1"), cell("up to 4 (one per 32-bit quarter)")],
                [cell("additions per match", True), cell("one guess + one correction per 0 bit"),
                 cell("one per 1 bit")],
                [cell("empty weight chunk", True), cell("loaded and joined"), cell("skipped")],
                [cell("next chunk's load", True), cell("after the current chunk"), cell("during the current chunk")],
                [cell("16 TPPEs", True), cell("lock step, wait for the slowest"),
                 cell("each from its own 4-deep queue")],
                [cell("extra stored data", True), cell("-"),
                 cell("56 bits (spikes) + 40 bits (weights) per 128-chunk")],
                [cell("cache read ports per TPPE", True), cell("1"), cell("4")]],
               [130, 180, 185]),
          C("Figure 18. LoAS and LoAS+, part by part."),
          P("The dataflow (inner product, all timesteps in parallel, one output neuron per TPPE), the compression "
            "format, the neuron and the results are all LoAS's. LoAS+ changes how a TPPE walks through a chunk and how "
            "the TPPEs walk through the chunks.", "body")]

    s += [H("12. What it costs, and what is still open"),
          *bullets(["<b>Metadata:</b> 96 bits of bases per 128-position chunk (Section 8). The memory footprint grows "
                    "slightly; this is not yet counted in the traffic model.",
                    "<b>Cache ports:</b> four spike-train reads per TPPE per cycle. The 256 KB cache needs 4x the banks or "
                    "ports. Its leakage is counted, but cache read/write energy is not counted for either design.",
                    "<b>Pipeline drain:</b> the TPPE drains its 3-stage pipeline after every chunk. Chunks of the "
                    "same output neuron add into the same accumulators, so the drain is only needed once per neuron. "
                    "Removing it should take VGG16 from 3.4x to about 5.9x. This is the next RTL change.",
                    "<b>Clock:</b> neither TPPE meets 800 MHz in synthesis without placement, so both are compared at "
                    "the same clock. The LoAS+ datapath is the shorter of the two.",
                    "<b>Baseline:</b> the LoAS TPPE RTL we have fails its own testbench; a corrected LoAS RTL would "
                    "draw more power and make LoAS+ look better, not worse.",
                    "<b>Open:</b> real trained weights (the weights here are synthetic at a given sparsity), a "
                    "full-chip area comparison, and the ideas not yet modelled: keeping each TPPE's spike fibre local "
                    "(cache energy), and skipping the negative weights of outputs that provably cannot spike."])]

    doc.build(bind(s), onFirstPage=footer, onLaterPages=footer)
    print("wrote", OUT)


if __name__ == "__main__":
    build()
