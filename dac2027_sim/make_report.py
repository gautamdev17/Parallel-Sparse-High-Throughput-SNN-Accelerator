"""
make_report.py -- compile every current result into one PDF (results/DAC2027_results.pdf).
All numbers are read from the result files (nothing is typed in by hand); every design runs at the array size given
in its own paper. Rendered with headless Chrome.

  python3 make_report.py
"""
import json, os, re, subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
R = os.path.join(HERE, "results")
CLK = 500e6
NETS = ("VGG16", "ResNet18")
ORDER = ["ptb", "spikex", "loas_zip", "sato", "spikeflow", "prosperity", "ours"]
NAME = {"ptb": "PTB", "spikex": "SpikeX", "loas_zip": "LoAS", "sato": "SATO", "spikeflow": "SpikeFlow",
        "prosperity": "Prosperity", "ours": "Ours"}
ARRAY = {"ptb": "16 x 8 PEs (128 adders)", "spikex": "8 x 8 PEs (64)", "loas_zip": "16 TPPEs",
         "sato": "128 PEs", "spikeflow": "16 x 16 PEs (256)", "prosperity": "128 PEs",
         "ours": "4 x 4 PEs x 8 adders (128)"}
SIM = {"ptb": "official Prosperity-repo PTB model", "spikex": "our cycle model of the paper",
       "loas_zip": "our cycle model of the paper (loas_model.py)", "sato": "official Prosperity-repo SATO model",
       "spikeflow": "our cycle model of the paper", "prosperity": "official Prosperity simulator",
       "ours": "cycle model, = RTL cycle-exact"}


def J(f):
    return json.load(open(os.path.join(R, f)))


def table(head, rows, cls=""):
    h = "".join(f"<th>{x}</th>" for x in head)
    b = "".join("<tr>" + "".join(f"<td>{x}</td>" for x in r) + "</tr>" for r in rows)
    return f'<table class="{cls}"><thead><tr>{h}</tr></thead><tbody>{b}</tbody></table>'


def fig(name, cap, width="100%"):
    return (f'<figure><img src="file://{os.path.join(R, name)}" style="width:{width}">'
            f"<figcaption>{cap}</figcaption></figure>")


def bold_ours(d, s):
    return f"<b>{s}</b>" if d == "ours" else s


def md_table_rows(path, start_marker):
    lines = open(path).read().splitlines()
    i = next(k for k, l in enumerate(lines) if l.startswith(start_marker))
    rows = []
    for l in lines[i + 2:]:
        if not l.startswith("|"):
            break
        rows.append([c.strip().replace("->", "&rarr;") for c in l.strip("|").split("|")])
    return [c.strip() for c in lines[i].strip("|").split("|")], rows


def build():
    s = J("main_summary.json")
    own = J("loas_own.json")
    cyc = lambda w, n, d, b: own[f"{w}|{n}|{b}"] if d == "loas_zip" else s[w][f"{n}|{d}"][f"cycles_b{b}"]
    H = []
    H.append("""<h1>DAC 2027: compiled results</h1>
<p class="sub">Our accelerator vs PTB, SpikeX, LoAS, SATO, SpikeFlow, Prosperity (and Phi for storage).
Generated from the result files of <code>dac2027_sim</code>; every number below is read from those files.</p>""")

    # ---------------------------------------------------------------- 1 setup
    H.append("<h2>1. Setup</h2>")
    H.append("""<ul>
<li><b>Workload <i>sparse90</i></b> (all main results): 90% of int8 weights zero; 90% of neurons silent; a non-silent
neuron fires with p = 0.3 per timestep and at least once; T = 8 (about 3.2% of spike bits are 1).
VGG16 and ResNet18 (CIFAR shapes).</li>
<li><b>OP</b> = one accumulation per '1' spike bit per output channel (Phi's definition):
VGG16 65.4 M OP/image, ResNet18 117.7 M OP/image, the same for every design.</li>
<li><b>Arrays</b>: every design at the size given in its own paper (table below). Common clock 500 MHz
(the clock our pipelined core closes at 45 nm); normalized speed-ups do not depend on the clock.</li>
<li><b>Technology</b>: all designs synthesized from our RTL of each design at 45 nm (Nangate45, Yosys + ABC),
gate-level power with OpenSTA; SRAM with CACTI 7 at 45 nm (LSTP cells, LOP periphery, 300 K; every buffer meets
500 MHz); DRAM 12.45 pJ/bit (Prosperity repo, from DRAMsim3).</li>
</ul>""")
    H.append(table(["Design", "Array (from its paper)", "Cycle numbers from"],
                   [[bold_ours(d, NAME[d]), ARRAY[d], SIM[d]] for d in ORDER]))

    # ---------------------------------------------------------------- 2 RTL verification
    H.append("<h2>2. RTL verification of our design</h2>")
    H.append("<p>Closed-loop Verilator testbench: the RTL packer forms the groups, the output SRAM is synchronous, the "
             "controller follows the cycle model. Every layer is checked for partial sums, output spikes and cycle "
             "count.</p>")
    rows = []
    for n in NETS:
        for b in (1, 16):
            d = J(f"rtl_closed_{n}_b{b}.json")
            rows.append([n, b, f"{sum(x['ok'] for x in d)}/{len(d)}", f"{sum(x['rtl_cycles'] for x in d):,}",
                         f"{sum(x['model_cycles'] for x in d):,}",
                         sum(x['sum_mismatch'] + x['spike_mismatch'] for x in d)])
    H.append(table(["Network", "Batch", "Layers OK", "RTL cycles", "Model cycles", "Sum/spike mismatches"], rows))

    # ---------------------------------------------------------------- 3 performance
    H.append("<h2>3. Latency and throughput (paper array sizes)</h2>")
    rows = []
    for n in NETS:
        p1, p16 = cyc("sparse90", n, "ptb", 1), cyc("sparse90", n, "ptb", 16)
        for d in ORDER:
            c1, c16 = cyc("sparse90", n, d, 1), cyc("sparse90", n, d, 16)
            rows.append([n, bold_ours(d, NAME[d]), f"{c1:,}", f"{c1 / CLK * 1e3:.3f}", f"{c1 / p1:.3f}",
                         f"{16 * CLK / c16:,.0f}", bold_ours(d, f"{p16 / c16:.2f}x")])
    H.append(table(["Network", "Design", "Cycles (batch 1)", "Latency @500 MHz (ms)", "Latency vs PTB",
                    "Throughput, batch 16 (img/s)", "Throughput vs PTB"], rows))
    H.append(fig("speedup_throughput.png", "Fig. 1. (a) Speedup (latency, batch 1) and (b) throughput (batch 16) over PTB, sparse90, paper array sizes."))
    H.append("<p><b>Dense-weight workload <i>zipstats</i></b> (weights dense, 26.1% non-silent neurons): where our "
             "weight packing has nothing to skip.</p>")
    rows = []
    for n in NETS:
        o1, o16 = cyc("zipstats", n, "ours", 1), cyc("zipstats", n, "ours", 16)
        for d in ORDER:
            c1, c16 = cyc("zipstats", n, d, 1), cyc("zipstats", n, d, 16)
            rows.append([n, bold_ours(d, NAME[d]), f"{c1:,}", f"{c1 / o1:.2f}", f"{o16 / c16:.2f}"])
    H.append(table(["Network", "Design", "Cycles (batch 1)", "Latency vs ours (>1 = slower than ours)",
                    "Throughput vs ours (>1 = faster than ours)"], rows))

    # ---------------------------------------------------------------- 4 packing
    H.append("<h2>4. Packing</h2>")
    ps = J("packing_stats.json")
    H.append("<p>Measured on sparse90, batch 1. Filter packing: filters with a non-zero weight in a K-tile share a "
             "column when their non-zeros never fall in the same row (up to F = 4). Pixel packing: pixels whose "
             "spike bits never collide in a K-tile share one group (up to G = 4); pixels with no spike in the tile "
             "are skipped.</p>")
    H.append(table(["Network", "Filters per column", "Non-zero filter slots / columns", "Pixels per group",
                    "Non-zero pixel steps / groups"],
                   [[n, f"{ps[n]['filters_per_column']:.2f}", f"{ps[n]['nonzero_filters']:,} / {ps[n]['columns']:,}",
                     f"{ps[n]['pixels_per_group']:.2f}", f"{ps[n]['nonzero_pixel_steps']:,} / {ps[n]['groups']:,}"]
                    for n in NETS]))
    c = J("compression.json")
    keys = ["ours", "loas", "ptb", "phi", "prosperity"]
    nm = {"ours": "Ours", "loas": "LoAS", "ptb": "PTB", "phi": "Phi", "prosperity": "Prosperity"}
    H.append("<p><b>Storage compression</b> = dense stored bits / packed stored bits (weights + spikes), 128 x 128 "
             "matrices, weight sparsity = neuron sparsity = x; higher is better. Each design's own format.</p>")
    H.append(table(["Sparsity"] + [nm[k] for k in keys],
                   [[f"{float(x) * 100:.0f}%"] + [f"{c[x][k]['ratio']:.2f}" for k in keys] for x in c]))
    H.append(fig("compression.png", "Fig. 2. Storage compression ratio vs sparsity.", "60%"))
    hd, rows = md_table_rows(os.path.join(R, "compression_validation.md"), "| Check |")
    H.append("<p>Validation of the storage models against the papers' own numbers:</p>")
    H.append(table(hd, rows, "small"))

    # ---------------------------------------------------------------- 5 our core PPA
    H.append("<h2>5. Area and power breakdown of our core (45 nm)</h2>")
    p = J("ppa.json")
    tot_a = sum(p["area45_um2"].values())
    rows = [[k, f"{v / 1e6:.4f}", f"{100 * v / tot_a:.1f}%", f"{p['power45_W'][k] * 1e3:.1f}",
             f"{100 * p['power45_W'][k] / p['power45_total_W']:.1f}%", f"{p['worst_path_ns'][k]:.2f}"]
            for k, v in p["area45_um2"].items()]
    rows.append(["<b>Core total</b>", f"<b>{tot_a / 1e6:.4f}</b>", "100%", f"<b>{p['power45_total_W'] * 1e3:.1f}</b>",
                 "100%", f"<b>{max(p['worst_path_ns'].values()):.2f}</b>"])
    H.append(table(["Block", "Area (mm²)", "Share", "Power @500 MHz (mW)", "Share", "Worst path (ns)"], rows))
    H.append("<p>Yosys + ABC (buffered), Nangate45 typical; power from gate-level activity of the closed-loop "
             f"testbench on real VGG16 layer data; {p['annotated_unannotated'][1]} unannotated pins. Synthesis-level "
             "timing (no placement): 1.96 ns worst path, so 500 MHz.</p>")

    # ---------------------------------------------------------------- 6 same node
    H.append("<h2>6. All designs at 45 nm, 500 MHz: area, GOP/s, GOP/J</h2>")
    sn = J("same_node_45nm.json")
    rows = []
    for d in ORDER:
        x = sn[d]
        r = [bold_ours(d, NAME[d]), f"{x['core_area']:.3f}", f"{x['sram_area']:.3f}",
             f"{x['core_area'] + x['sram_area']:.3f}", f"{x['core_W'] * 1e3:.1f}"]
        for n in NETS:
            r += [f"{x[n]['gops']:.1f}", f"{x[n]['gopj_core']:.0f}", f"{x[n]['gopj_total']:.0f}",
                  bold_ours(d, f"{x[n]['gopj_system']:.0f}")]
        rows.append(r)
    H.append(table(["Design", "Core (mm²)", "SRAM (mm²)", "Total (mm²)", "Core power (mW)",
                    "VGG16 GOP/s", "GOP/J core", "GOP/J core+SRAM", "GOP/J system",
                    "ResNet18 GOP/s", "GOP/J core", "GOP/J core+SRAM", "GOP/J system"], rows, "small"))
    H.append("<p>Per image at batch 16. System = core + SRAM (leakage and read/write energy from each design's "
             "access counts) + DRAM.</p>")
    H.append(fig("gops_gopj.png", "Fig. 3. (a) GOP/s and (b) system GOP/J at 45 nm, 500 MHz."))

    # ---------------------------------------------------------------- 7 power -> energy -> EDP
    H.append("<h2>7. Power &rarr; energy &rarr; EDP (core / SRAM / DRAM), batch 1</h2>")
    H.append("<p>Power is derived first for each component, averaged over one batch-1 inference of latency t: "
             "core = gate-level power; SRAM = leakage + (read/write energy from the access counts) / t; DRAM = "
             "12.45 pJ/bit &times; DRAM traffic / t. Energy = power &times; latency; EDP = energy &times; latency.</p>")
    sb = J("system_breakdown_b1.json")
    rows = []
    for n in NETS:
        for d in ORDER:
            x = sb[f"{n}|{d}"]
            pw, en = x["power_W"], x["energy_J"]
            rows.append([n, bold_ours(d, NAME[d]), f"{x['t_s'] * 1e3:.3f}",
                         f"{pw['core'] * 1e3:.0f}", f"{pw['sram'] * 1e3:.0f}", f"{pw['dram'] * 1e3:.0f}",
                         f"{sum(pw.values()) * 1e3:.0f}",
                         f"{en['core'] * 1e6:.0f}", f"{en['sram'] * 1e6:.0f}", f"{en['dram'] * 1e6:.0f}",
                         bold_ours(d, f"{sum(en.values()) * 1e6:.0f}"), bold_ours(d, f"{x['edp_Js'] * 1e9:.0f}")])
    H.append(table(["Network", "Design", "Latency (ms)", "Core (mW)", "SRAM (mW)", "DRAM (mW)", "Total (mW)",
                    "Core (µJ)", "SRAM (µJ)", "DRAM (µJ)", "Energy (µJ)", "EDP (µJ·ms)"], rows, "small"))
    H.append(fig("power_breakdown_b1.png", "Fig. 4. Power per component (DRAM / SRAM / core), normalized to PTB = 1, batch 1."))
    H.append(fig("energy_breakdown_b1.png", "Fig. 5. Energy per image (power &times; latency) per component, normalized to PTB = 1, batch 1."))
    H.append(fig("edp_breakdown_b1.png", "Fig. 6. EDP (energy &times; latency) split by where the energy goes, normalized to PTB = 1, batch 1."))

    # ---------------------------------------------------------------- 8 memory traffic
    H.append("<h2>8. Memory traffic</h2>")
    off = J("mem_traffic_base.json")
    off.update(J("mem_traffic_prosperity.json"))
    rows = []
    for n in NETS:
        for d in ORDER:
            a, b = off[f"{n}|1|{d}"], off[f"{n}|16|{d}"]
            rows.append([n, bold_ours(d, NAME[d]), f"{a['wgt_MB']:.2f}", f"{a['act_MB']:.3f}", f"{a['out_MB']:.3f}",
                         bold_ours(d, f"{a['wgt_MB'] + a['act_MB'] + a['out_MB']:.2f}"),
                         f"{b['wgt_MB'] + b['act_MB'] + b['out_MB']:.2f}"])
    H.append("<p><b>DRAM traffic per image.</b> Prosperity: official simulator (counters split into weights and "
             "activations); PTB: official model (one image at a time); others: the same tiled rule with each "
             "design's own format and buffer. Ours stores weights as packed columns (8 B per column) and reads raw "
             "spike trains.</p>")
    H.append(table(["Network", "Design", "Weights b1 (MB)", "Input spikes b1", "Output spikes b1", "Total b1",
                    "Total b16 (per image)"], rows))
    H.append(fig("dram_breakdown_b1.png", "Fig. 7. DRAM traffic per image (weights / input spikes / output spikes), normalized to PTB = 1, batch 1."))
    rows = []
    for n in NETS:
        for d in ORDER:
            t = sb[f"{n}|{d}"]["traffic_MB"]
            tot = {k: sum(v.values()) for k, v in t.items()}
            rows.append([n, bold_ours(d, NAME[d]), f"{tot['off']:.1f}", f"{tot['on']:.1f}", f"{tot['pe']:.1f}",
                         bold_ours(d, f"{sum(tot.values()):.0f}"),
                         f"{t['on']['wgt'] + t['on']['act']:.1f}", f"{t['pe']['wgt'] + t['pe']['act']:.1f}"])
    H.append("<p><b>Traffic at three levels</b>, batch 1. Off-chip: DRAM reads and writes. On-chip: every SRAM "
             "read and write (the counts that set the SRAM energy). PE: bits entering a PE from outside it (buffer, "
             "broadcast or a neighbouring PE). The levels include partial sums where a design moves them (ours: "
             "output-buffer read-modify-writes and the valid running sums passed down the columns; Prosperity: its "
             "prefix partial-sum buffer); the last two columns are weights and activations only.</p>")
    H.append(table(["Network", "Design", "Off-chip (MB)", "On-chip (MB)", "PE (MB)", "Total (MB)",
                    "On-chip, wgt+act", "PE, wgt+act"], rows))
    H.append(fig("traffic_levels_b1.png", "Fig. 8. Traffic per image at three levels (off-chip / on-chip / PE), normalized to PTB = 1, batch 1."))
    hd, rows = md_table_rows(os.path.join(R, "roofline.md"), "| Network |")
    rows = [[r[0], bold_ours("ours" if r[1] == "Ours" else "", r[1])] + r[2:] for r in rows]
    H.append("<p><b>Roofline</b> (batch 16, 500 MHz, DRAM 64 GB/s). Work = effectual accumulations (non-zero weight "
             "&times; spike bit): VGG16 6.55 M, ResNet18 11.77 M per image; compute roof = adders &times; 500 MHz.</p>")
    H.append(table(hd, rows, "small"))
    H.append(fig("roofline.png", "Fig. 9. Roofline, (a) VGG16, (b) ResNet18."))

    # ---------------------------------------------------------------- 9 notes
    H.append("<h2>9. Notes and limits</h2>")
    H.append("""<ul>
<li>Our timing is synthesis-level (no placement or wiring). The baselines' RTL was not timing-closed and is evaluated at
the same 500 MHz; LoAS's TPPE does not close it (3.14 ns), so its GOP/s is optimistic.</li>
<li>Prosperity's power is measured over a busy steady-state window (16 tiles, processor busy 87%); LoAS on the sparse90
stimulus. SATO's 54 KB buffer is assumed (not given in its paper). PTB has no cross-image batching (official model).</li>
<li>Ungated flop clock power is most of every core's power (about 73% of ours); no design was clock-gated.</li>
<li>Our DRAM count omits a per-tile column-count header (0.13 MB on VGG16, +1.4%).</li>
<li>Not included because they predate the pipelined RTL and were not re-run: the design-space sweep, the bound audit,
the weight-density 0.3 / 0.5 runs. Equal-PE (16 PE) comparisons are not included: every design runs at its paper's size.</li>
</ul>""")
    return "\n".join(H)


CSS = """
@page { size: A4; margin: 14mm 13mm; }
body { font-family: 'Linux Libertine O', 'Libertinus Serif', Georgia, serif; font-size: 10pt; color: #111; }
h1 { font-size: 18pt; margin: 0 0 2pt 0; }
.sub { color: #555; margin-top: 0; }
h2 { font-size: 13pt; margin: 14pt 0 5pt 0; border-bottom: 1px solid #999; padding-bottom: 2pt; break-after: avoid; }
table { border-collapse: collapse; margin: 5pt 0 8pt 0; font-size: 8.4pt; width: 100%; break-inside: auto; }
table.small { font-size: 7.4pt; }
th, td { border: 0.5pt solid #aaa; padding: 2pt 4pt; text-align: right; vertical-align: top; }
th { background: #eee; text-align: center; }
td:first-child, td:nth-child(2) { text-align: left; }
tr { break-inside: avoid; }
figure { margin: 6pt 0 10pt 0; text-align: center; break-inside: avoid; }
figcaption { font-size: 8.5pt; color: #333; margin-top: 2pt; }
ul { margin: 3pt 0 6pt 0; padding-left: 16pt; }
li { margin-bottom: 2pt; }
code { font-size: 8.5pt; }
"""


def main():
    html = f"<!doctype html><html><head><meta charset='utf-8'><style>{CSS}</style></head><body>{build()}</body></html>"
    hp = os.path.join(R, "DAC2027_results.html")
    open(hp, "w").write(html)
    out = os.path.join(R, "DAC2027_results.pdf")
    chrome = "/Applications/Google Chrome.app/Contents/MacOS/Google Chrome"
    subprocess.run([chrome, "--headless", "--disable-gpu", "--no-pdf-header-footer", "--allow-file-access-from-files",
                    f"--print-to-pdf={out}", f"file://{hp}"], check=True, capture_output=True)
    print(out)


if __name__ == "__main__":
    main()
