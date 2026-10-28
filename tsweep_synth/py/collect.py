"""
collect.py -- core area and power of every design at T = 4, 8, 16, 32 -> results/core_by_T.json, results/summary.md.

Convention = dac2027_sim/hw/same_node_table.core():
  baselines: area = 'Chip area for module' of the synthesis log (x 16 for LoAS); power = OpenSTA report_power
             'Total' of the gate-level run at 800 MHz, rescaled to 500 MHz: (internal + switching) x 500/800 + leakage
             (x 16 for LoAS).
  ours     : area = 'Chip area for top module' of the hierarchical synthesis; power at 500 MHz (measured there):
             (1 - F_LIF) x stream window + F_LIF x LIF window, F_LIF = 0.0401 (the LIF share of VGG16 cycles at T = 8).
  python3 collect.py
"""
import json, os, re, sys

HERE = os.path.dirname(os.path.abspath(__file__))
TS = os.path.dirname(HERE)
B = os.path.join(TS, "build")
RES = os.path.join(TS, "results")
DSN = os.path.join(TS, "..", "dac2027_sim", "hw")
CLK = 500e6
F_LIF = 0.0401
TS_ = (4, 8, 16, 32)
ORDER = ["ptb", "spikex", "loas_zip", "sato", "spikeflow", "prosperity", "ours"]
HWN = {"ptb": ("ptb", "ptb", 1), "spikex": ("spikex", "spikex", 1), "sato": ("sato", "sato", 1),
       "spikeflow": ("spikeflow", "spikeflow_ext", 1), "loas_zip": ("loas", "loas", 16),
       "prosperity": ("prosperity", "prosperity", 1)}


def rpt_total(path):
    for l in open(path):
        if l.startswith("Total"):
            v = [float(x) for x in l.split()[1:5]]
            return v[0] + v[1], v[2]
    raise ValueError(path)


def unannotated(path):
    m = re.search(r"unannotated\s+(\d+)", open(path).read())
    return int(m.group(1)) if m else None


def area_um2(log, top=False):
    pat = r"Chip area for top module '\\\S+': ([\d.]+)" if top else r"Chip area for module '\\\S+': ([\d.]+)"
    return float(re.findall(pat, open(log).read())[-1])


def core(d, run):
    """-> dict(area_mm2, power_W, ...) of design d in build/<run>/, or None if not there."""
    if d == "ours":
        p = os.path.join(B, run, "ours")
        fs = [os.path.join(p, f) for f in ("ours_buf_synth.log", "pw_stream.rpt", "pw_lif.rpt")]
        if not all(os.path.exists(f) for f in fs):
            return None
        a = area_um2(fs[0], top=True) / 1e6
        (ds, ls), (dl, ll) = rpt_total(fs[1]), rpt_total(fs[2])
        dyn, leak = (1 - F_LIF) * ds + F_LIF * dl, (1 - F_LIF) * ls + F_LIF * ll
        return dict(area_mm2=a, power_W=dyn * CLK / 500e6 + leak, stream_W=ds + ls, lif_W=dl + ll,
                    leak_W=leak, unannotated=[unannotated(fs[1]), unannotated(fs[2])])
    dirn, n, mult = HWN[d]
    p = os.path.join(B, run, dirn)
    fs = [os.path.join(p, f"{n}_synth.log"), os.path.join(p, f"{n}_power.rpt")]
    if not all(os.path.exists(f) for f in fs):
        return None
    dyn, leak = rpt_total(fs[1])
    return dict(area_mm2=area_um2(fs[0]) / 1e6 * mult, power_W=mult * (dyn * CLK / 800e6 + leak),
                leak_W=mult * leak, dyn800_W=mult * dyn, unannotated=unannotated(fs[1]))


def safe(d, run):
    """core() of a finished run; None for a missing or interrupted one (no 'Total' line yet)."""
    try:
        return core(d, run)
    except (ValueError, IndexError):
        return None


def existing():
    """same_node_table.core(d) of dac2027_sim (read only)."""
    sys.path.insert(0, DSN)
    sys.path.insert(0, os.path.dirname(DSN))
    import same_node_table as snt
    return {d: snt.core(d) for d in ORDER}


if __name__ == "__main__":
    ex = existing()
    out, rep = {}, {}
    for d in ORDER:
        out[d] = {str(T): safe(d, f"T{T}") for T in TS_}
        rep[d] = safe(d, "T8o") if d != "ours" else safe(d, "T8")
    json.dump({d: {T: (None if v is None else dict(area_mm2=v["area_mm2"], power_W=v["power_W"]))
                   for T, v in out[d].items()} for d in ORDER},
              open(os.path.join(RES, "core_by_T.json"), "w"), indent=1)
    json.dump(dict(sweep=out, reproduction_T8_original_rtl_and_stimulus=rep,
                   existing_same_node_table={d: dict(area_mm2=a, power_W=p) for d, (a, p) in ex.items()}),
              open(os.path.join(RES, "core_by_T_detail.json"), "w"), indent=1)
    for d in ORDER:
        a, p = ex[d]
        r = rep[d]
        rs = "-" if r is None else f"{r['area_mm2']:.4f} ({100 * (r['area_mm2'] / a - 1):+.2f} %) / " \
                                   f"{1e3 * r['power_W']:.2f} mW ({100 * (r['power_W'] / p - 1):+.2f} %)"
        sw = " | ".join("-" if out[d][str(T)] is None else
                        f"{out[d][str(T)]['area_mm2']:.4f} / {1e3 * out[d][str(T)]['power_W']:.2f}" for T in TS_)
        print(f"{d:11s} existing {a:.4f} mm2 / {1e3 * p:.2f} mW | repro {rs} | sweep {sw}")
