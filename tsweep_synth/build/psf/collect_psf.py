"""collect_psf.py <design...> -- results/core_by_T_<design>.json from build/psf/T<T>/<design> (power_t.sh runs).
Convention of py/collect.py / dac2027_sim same_node_table.core(): area = 'Chip area for module' of the (reused)
netlist's synthesis log; power at 500 MHz = (internal + switching of the 800 MHz gate-level run) x 500/800 + leakage."""
import json, os, re, sys

TS = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
NAME = {"ptb": "ptb", "spikex": "spikex", "spikeflow": "spikeflow_ext"}

for d in sys.argv[1:]:
    out = {}
    for T in (4, 8, 16, 32):
        b = os.path.join(TS, "build", "psf", f"T{T}", d)
        rpt = open(os.path.join(b, f"{NAME[d]}_power.rpt")).read()
        assert re.search(r"unannotated\s+0\b", rpt), (d, T)
        assert "mismatches = 0" in open(os.path.join(b, "rtl_check.log")).read(), (d, T)
        v = [float(x) for x in next(l for l in rpt.splitlines() if l.startswith("Total")).split()[1:5]]
        dyn, leak = (v[0] + v[1]) * 500e6 / 800e6, v[2]
        a = float(re.findall(r"Chip area for module '\\\S+': ([\d.]+)", open(os.path.join(b, f"{NAME[d]}_synth.log")).read())[-1])
        out[str(T)] = dict(area_mm2=a / 1e6, power_W=dyn + leak, dyn_W=dyn, leak_W=leak)
    json.dump(out, open(os.path.join(TS, "results", f"core_by_T_{d}.json"), "w"), indent=1)
    print(d, " | ".join(f"T={T}: {1e3 * r['power_W']:.2f} mW (dyn {1e3 * r['dyn_W']:.2f}, leak {1e3 * r['leak_W']:.2f})"
                        for T, r in out.items()), f"area {out['8']['area_mm2']:.4f} mm2")
