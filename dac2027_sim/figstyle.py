"""figstyle.py -- one figure style for the DAC paper (ACM `acmart` sigconf template).

* Font: Linux Libertine O, the acmart body font, at 8 pt (body text is 9 pt). TrueType versions of the CTAN
  `libertine` fonts are in fonts/ (licence fonts/LICENCE.txt); they are embedded as TrueType (pdf.fonttype 42),
  so the PDFs contain no Type 3 fonts (required by ACM/IEEE PDF checks).
* Sizes: draw at the final printed size -- COL = \\columnwidth (241.14 pt = 3.335 in), TEXT = \\textwidth
  (506.3 pt = 7.0 in). Include with \\includegraphics[width=\\columnwidth] / [width=\\textwidth] (no rescaling).
* Lines: 0.6 pt frame and ticks (inward), 0.5 pt bar edges, light grid.
"""
import os
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib import font_manager as fm

HERE = os.path.dirname(os.path.abspath(__file__))
COL = 3.335            # in, ACM sigconf \columnwidth
TEXT = 7.0             # in, ACM sigconf \textwidth
EDGE = "#262626"
OURS = "#e8871e"       # ours (orange accent); value labels in OURS_TEXT
OURS_TEXT = "#a0520a"

for f in ("LinLibertine_R", "LinLibertine_RI", "LinLibertine_RB", "LinBiolinum_R"):
    p = os.path.join(HERE, "fonts", f + ".ttf")
    if os.path.exists(p):
        fm.fontManager.addfont(p)

plt.rcParams.update({
    "font.family": "serif", "font.serif": ["Linux Libertine O", "Times New Roman", "DejaVu Serif"],
    "mathtext.fontset": "custom", "mathtext.rm": "Linux Libertine O", "mathtext.it": "Linux Libertine O:italic",
    "mathtext.bf": "Linux Libertine O:bold",
    "font.size": 8, "axes.labelsize": 8, "xtick.labelsize": 7.5, "ytick.labelsize": 7.5, "legend.fontsize": 7,
    "axes.linewidth": 0.6, "axes.edgecolor": EDGE, "axes.labelcolor": "black", "axes.labelpad": 2.5,
    "xtick.direction": "in", "ytick.direction": "in", "xtick.top": True, "ytick.right": True,
    "xtick.major.width": 0.6, "ytick.major.width": 0.6, "xtick.major.size": 2.8, "ytick.major.size": 2.8,
    "xtick.minor.visible": False, "ytick.minor.visible": False, "xtick.major.pad": 2.5, "ytick.major.pad": 2.0,
    "hatch.linewidth": 0.4, "hatch.color": EDGE, "lines.linewidth": 1.0, "patch.linewidth": 0.5,
    "grid.linewidth": 0.4, "grid.color": "#dcdcdc",
    "pdf.fonttype": 42, "ps.fonttype": 42, "svg.fonttype": "none",
    "savefig.dpi": 600,                      # no bbox trimming: the saved size is exactly the drawn size
    "figure.dpi": 150,
})


def inside_legend(ax, h, l, ncol=3, loc="upper center", handlelength=1.0, fontsize=7):
    """compact boxed legend inside the axes: square patch handles, square-cornered thin frame."""
    lg = ax.legend(h, l, ncol=ncol, loc=loc, frameon=True, fancybox=False, framealpha=1.0, edgecolor=EDGE,
                   fontsize=fontsize, handlelength=handlelength, handleheight=handlelength if handlelength <= 1.2 else 0.7,
                   handletextpad=0.4, columnspacing=0.9, borderpad=0.4, labelspacing=0.3, borderaxespad=0.45)
    lg.get_frame().set_linewidth(0.5)
    lg.set_zorder(10)
    return lg


def panel_tag(ax, tag, y=-0.2):
    ax.text(0.5, y, tag, transform=ax.transAxes, ha="center", va="top", fontsize=8)
