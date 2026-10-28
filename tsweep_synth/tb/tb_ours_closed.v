// tb_ours_closed.v (tsweep_synth copy: T = `TB_T) -- closed-loop run of ours_core over a whole layer (every output tile, every K-tile).
// Unlike tb_ours.v, nothing here is replayed from the Python schedule: only the OFFLINE data are read from files
// (packed weight columns per pass, raw spike slices). At run time:
//   * the RTL packer receives the raw slices (8 per cycle); the groups it emits are captured into a double-buffered
//     group buffer and are the groups that get injected (the Python packer is not used);
//   * a controller (below, written from the doc's rules) decides every cycle:
//       - packer: K-tile i starts when the packer is free and K-tile i-2's buffer is free (all its groups injected);
//       - array : a pass starts when its K-tile's groups are all packed and the previous pass has injected its
//                 groups (L = 1 weight-load cycle at the start of an output tile); one group per cycle;
//       - edge-FIFO backpressure: a group is injected only if, for every column c, the RTL FIFO count + the
//                 entries of the groups still in the array above that FIFO (injected in the last R + c cycles)
//                 + this group's entries <= 80. A group's entries per column are predicted from the group buffer
//                 (spike bits, pixel labels) and the pass's weights (non-zero, filter label): the distinct
//                 (filter label, pixel label) slots that receive an addition. Otherwise the feeder holds a cycle.
//                 The prediction is checked against the RTL FIFO's write count when the bundle arrives;
//       - shadow weights of pass q+1 are written into PE (k,c) in the cycle pass q's first group reaches that PE;
//       - tile end: last bundle out of the array AND all four RTL edge FIFOs empty (read from the RTL), then the
//                   LIF sweep over the dirty entries, 16 per cycle through the RTL LIF units;
//   * the output buffer SRAM (async read, write at the edge, 16 RMW ports) counts same-address conflicts.
// Writes out_closed.txt (tile, address, 8 sums, LIF spikes) and a summary line with the total cycle count.
`timescale 1ns/1ps
module tb_ours_closed;
`ifndef TB_T
 `define TB_T 8
`endif
    // tsweep_synth: T from -DTB_T; LIFP = T/2 LIF pipeline stages (TPS = 2 timesteps per stage in ours_lif);
    // DLR = ring of LIF issue slots (was 8, must exceed LIFP)
    localparam R = 4, C = 4, T = `TB_T, F = 4, G = 4, PSW = 24, E = 4, NLIF = 16, PL = 8, PPL = 1, NSL = PL + 2,
               AW = 13, PIDW = 7, FIDW = 6, LIFP = T / 2, DLR = 32;   // packer lanes x slices; group-buffer slots; LIF stages
`ifndef TB_MAXT
 `define TB_MAXT 14
 `define TB_MAXKT 20
 `define TB_MAXP 20
 `define TB_MAXS 23
`endif
    localparam MAXT = 1 << `TB_MAXT, MAXKT = 1 << `TB_MAXKT, MAXP = 1 << `TB_MAXP, MAXS = 1 << `TB_MAXS;
    reg clk = 0, rst = 1;
    always #1 clk = ~clk;

    // ------------------------------------------------------------------ DUT
    reg inj_v = 0, inj_par = 0;
    reg [R*T-1:0] inj_bits = 0;
    reg [R*2*T-1:0] inj_lab = 0;
    reg [G*PIDW-1:0] inj_pid = 0;
    reg [C*F*FIDW-1:0] inj_fid = 0;
    reg [R*C-1:0] wl_en = 0, wl_par = 0;
    reg [R*C*8-1:0] wl_w = 0;
    reg [R*C*2-1:0] wl_f = 0;
    reg [PL*PPL-1:0] sl_v = 0;
    reg [PL*PPL*R*T-1:0] sl_m = 0;
    reg [PL*PPL*PIDW-1:0] sl_id = 0;
    reg [PL-1:0] pk_flush = 0;
    reg [NLIF-1:0] lif_v = 0;
    reg [NLIF*T*PSW-1:0] lif_x = 0;
    reg signed [PSW-1:0] theta = 0;
    wire [C*E-1:0] obuf_we;
    wire [C*E*AW-1:0] obuf_addr, obuf_waddr;
    wire [C*E*T*PSW-1:0] obuf_rdata, obuf_wdata;
    wire [C-1:0] ovf;
    wire [NLIF*T-1:0] lif_spk;
    localparam NO = PPL + 4;                                  // group outputs per lane and cycle
    wire [PL*NO-1:0] gv;
    wire [PL*NO*R*T-1:0] gm;
    wire [PL*NO*2*R*T-1:0] glab;
    wire [PL*NO*G*PIDW-1:0] gid;
    wire [PL*NO*3-1:0] gc;

`ifdef GATE
    ours_core dut(           // netlist synthesized at T = `TB_T
`else
    ours_core #(.T(T)) dut(
`endif
                 .clk(clk), .rst(rst), .inj_v(inj_v), .inj_par(inj_par), .inj_bits(inj_bits), .inj_lab(inj_lab),
        .inj_pid(inj_pid), .inj_fid(inj_fid), .wl_en(wl_en), .wl_w(wl_w), .wl_f(wl_f), .wl_par(wl_par),
        .obuf_we(obuf_we), .obuf_addr(obuf_addr), .obuf_waddr(obuf_waddr), .obuf_rdata(obuf_rdata),
        .obuf_wdata(obuf_wdata),
        .fifo_overflow(ovf), .lif_v(lif_v), .lif_x(lif_x), .theta(theta), .lif_spk(lif_spk),
        .sl_v(sl_v), .sl_m(sl_m), .sl_id(sl_id), .pk_flush(pk_flush),
        .pk_gv(gv), .pk_gm(gm), .pk_gl(glab), .pk_gid(gid), .pk_gc(gc));

    // edge FIFO occupancy, read from the RTL
`ifdef GATE   // hierarchical gate-level netlist: generate-block instance names are escaped
    wire [7:0] fc0 = dut.\ids[0].fifo .count, fc1 = dut.\ids[1].fifo .count,
               fc2 = dut.\ids[2].fifo .count, fc3 = dut.\ids[3].fifo .count;
`else
    wire [7:0] fc0 = dut.ids[0].fifo.count, fc1 = dut.ids[1].fifo.count,
               fc2 = dut.ids[2].fifo.count, fc3 = dut.ids[3].fifo.count;
`endif
    // entries written into each FIFO at the coming clock edge (the bundle leaving the array this cycle)
`ifdef GATE   // nwr is optimised away in the netlist: count the FIFO's write-valid input port instead
    function automatic [4:0] pc16(input [15:0] v);
        integer b; begin pc16 = 0; for (b = 0; b < 16; b = b + 1) pc16 = pc16 + v[b]; end
    endfunction
    wire [15:0] wv0 = dut.\ids[0].fifo .wr_v, wv1 = dut.\ids[1].fifo .wr_v,
                wv2 = dut.\ids[2].fifo .wr_v, wv3 = dut.\ids[3].fifo .wr_v;
    wire [4:0] nw0 = pc16(wv0), nw1 = pc16(wv1), nw2 = pc16(wv2), nw3 = pc16(wv3);
`else
    wire [4:0] nw0 = dut.ids[0].fifo.nwr, nw1 = dut.ids[1].fifo.nwr, nw2 = dut.ids[2].fifo.nwr, nw3 = dut.ids[3].fifo.nwr;
`endif
    localparam FDEPTH = 80;

    // ------------------------------------------------------------------ output buffer SRAM (tagged per tile)
    reg [T*PSW-1:0] obuf [0:(1<<AW)-1];
    reg [15:0] otag [0:(1<<AW)-1];
    reg [15:0] cur_tag = 1;
    reg [AW-1:0] dlist [0:(1<<AW)-1];
    integer nd_w = 0, conflicts = 0, rmw = 0;
    reg [15:0] nd_tag = 0;
    wire [31:0] nd = (nd_tag == cur_tag) ? nd_w : 0;     // dirty entries of the current tile
    // synchronous SRAM: the read data of obuf_addr is registered (obuf_rdata in the next cycle); writes from the
    // core's second RMW stage (obuf_waddr / obuf_wdata) at the edge; a read and a write of the same edge return the
    // old value (the core's arbiter never issues such a read)
    reg [C*E*T*PSW-1:0] rdq = 0;
    assign obuf_rdata = rdq;
    integer i, j;
    reg [AW-1:0] ra;
    always @(posedge clk) if (rst) begin
        for (i = 0; i < (1<<AW); i = i + 1) otag[i] = 0;
    end else begin
        for (i = 0; i < C*E; i = i + 1) begin
            ra = obuf_addr[i*AW +: AW];
            rdq[i*T*PSW +: T*PSW] <= (otag[ra] == cur_tag) ? obuf[ra] : {T*PSW{1'b0}};
        end
        if (nd_tag != cur_tag) begin nd_w = 0; nd_tag = cur_tag; end
        for (i = 0; i < C*E; i = i + 1) if (obuf_we[i]) begin
            for (j = 0; j < i; j = j + 1)
                if (obuf_we[j] && obuf_waddr[j*AW +: AW] == obuf_waddr[i*AW +: AW]) conflicts = conflicts + 1;
            obuf[obuf_waddr[i*AW +: AW]] <= obuf_wdata[i*T*PSW +: T*PSW];
            if (otag[obuf_waddr[i*AW +: AW]] != cur_tag) begin
                otag[obuf_waddr[i*AW +: AW]] = cur_tag;
                dlist[nd_w] = obuf_waddr[i*AW +: AW];
                nd_w = nd_w + 1;
            end
            rmw = rmw + 1;
        end
    end

    // ------------------------------------------------------------------ offline data
    integer ntiles, nkt, npass, nslc, th, fd, rc;
    integer t_kf [0:MAXT-1], t_kc [0:MAXT-1], t_pc [0:MAXT-1];
    integer k_nn [0:MAXKT-1], k_sb [0:MAXKT-1], k_pf [0:MAXKT-1], k_np [0:MAXKT-1], k_tile [0:MAXKT-1];
    reg [7:0] p_w [0:MAXP*16-1];
    reg [1:0] p_f [0:MAXP*16-1];
    reg [FIDW-1:0] p_fid [0:MAXP*16-1];
    reg [R*T-1:0] slices [0:MAXS-1];
    integer p_tile [0:MAXP-1], p_kt [0:MAXP-1];

    // ------------------------------------------------------------------ run-time state
    integer pk_ready [0:MAXKT-1], freed [0:MAXKT-1], ngr [0:MAXKT-1];
    reg [R*T-1:0] gb_m [0:NSL*128-1];
    reg [2*R*T-1:0] gb_l [0:NSL*128-1];
    reg [G*PIDW-1:0] gb_id [0:NSL*128-1];
    integer ln_kt [0:PL-1], ln_fq [0:PL-1], ln_fed [0:PL-1], ln_fl [0:PL-1], l, sb;
    integer skipk = -1;
    integer lif_end = 0, pend_n = 0, dl_n [0:DLR-1], dl_a [0:DLR*NLIF-1];
    integer pend_a [0:NLIF-1];
    reg [NLIF*T*PSW-1:0] pend_x;
    integer st_cyc [0:15], st_q [0:15];
    integer cyc = 0, fk = 0;
    integer ti = 0, state = 0, aj = 0, ap = 0, s_next = 0, injecting = 0, ig = 0, cur_q = 0, cur_P = 0, cur_kt = 0;
    integer arr_end = 0, tstart = 0, li = 0, lif_n = 0, slot, k, c, d, q, pe, x, nwait, fmax = 0, tot = -1;
    integer lif_a [0:NLIF-1];
    integer pe_act [0:R*C-1], pe_sh [0:R*C-1];     // pass active in / loaded into the shadow of each PE (-1: none)
    reg pe_par [0:R*C-1];                           // parity of the pass active in each PE
    reg last_par = 0;                               // parity of the last pass started (toggles per executed pass)
    reg cur_par = 0;
    integer nq;
    // backpressure: entries per column of the groups injected in the last R + C cycles (ring by cycle)
    integer hist_t [0:R+C-1];
    integer hist_n [0:(R+C)*C-1];
    integer need [0:C-1];
    integer stalls = 0, pred_err = 0, fr_kt = -1, bp_ok = 0, hy, hk;

    // entries the bundle of group-buffer slot sl in pass q will write into each column FIFO
    task automatic predict(input integer pq, input integer psl);
        integer cc, kk, t2, s2;
        reg [15:0] tch;
        begin
            for (cc = 0; cc < C; cc = cc + 1) begin
                tch = 0;
                for (kk = 0; kk < R; kk = kk + 1)
                    if (p_w[pq*16 + kk*C + cc] != 0)
                        for (t2 = 0; t2 < T; t2 = t2 + 1)
                            if (gb_m[psl][kk*T + t2]) tch[{p_f[pq*16 + kk*C + cc], gb_l[psl][kk*2*T + 2*t2 +: 2]}] = 1'b1;
                need[cc] = 0;
                for (s2 = 0; s2 < 16; s2 = s2 + 1) need[cc] = need[cc] + tch[s2];
            end
        end
    endtask

    // bp_ok = 1 if need[] fits in every column FIFO with the entries still above it
    task automatic bp_check;
        integer cc, dd, tot;
        begin
            bp_ok = 1;
            for (cc = 0; cc < C; cc = cc + 1) begin
                tot = need[cc] + (cc == 0 ? fc0 : cc == 1 ? fc1 : cc == 2 ? fc2 : fc3);
                for (dd = 1; dd <= R + cc; dd = dd + 1)
                    if (hist_t[(cyc - dd + R + C) % (R + C)] == cyc - dd) tot = tot + hist_n[((cyc - dd + R + C) % (R + C))*C + cc];
                if (tot > FDEPTH) bp_ok = 0;
            end
        end
    endtask

    task automatic pass_done;
        if (fr_kt >= 0) freed[fr_kt] = cyc + 1;       // the K-tile's group buffer is free after its last group
    endtask

    // next pass that will run after pass q in the current tile (q = -1: the tile's first); -1: none left.
    // Passes of K-tiles already packed to zero groups are skipped; a K-tile still being packed is assumed to have
    // groups (speculative load). If it turns out empty, the next call returns a later pass and the shadow is
    // rewritten -- always before that pass can start, since that K-tile was packed at least a cycle earlier.
    function automatic integer next_exec(input integer q0);
        integer qq, kk, r;
        begin
            qq = (q0 < 0) ? k_pf[t_kf[ti]] : q0 + 1;
            r = -3;
            while (r == -3) begin
                if (q0 < 0 && t_pc[ti] == 0) r = -1;
                else if (qq >= npass || p_tile[qq] != ti) r = -1;
                else begin
                    kk = p_kt[qq];
                    if (pk_ready[kk] < 0 || pk_ready[kk] > cyc) r = qq;
                    else if (ngr[kk] == 0) qq = k_pf[kk] + k_np[kk];
                    else r = qq;
                end
            end
            next_exec = r;
        end
    endfunction
    reg [T-1:0] spk_of [0:(1<<AW)-1];
    integer fo;
    integer vcd_from = -1, vcd_len = 0, vcd_on = 0, vcd_lif = 0, vcd_done = 0;
    reg [8*80-1:0] vcd_file;

    task automatic start_tile;
        begin
            tstart = cyc; arr_end = cyc; s_next = cyc + 1; aj = t_kf[ti]; ap = 0; state = 0; skipk = -1;
            cur_tag = ti[15:0] + 16'd1;
            // L = 1: the shadow registers are free from the tile's first cycle; the first pass that runs is
            // written into them (below) as soon as it is known, and cannot start before start + L
            for (pe = 0; pe < R*C; pe = pe + 1) begin pe_act[pe] = -1; pe_sh[pe] = -1; pe_par[pe] = last_par; end
        end
    endtask

    task automatic inject(input integer g);
        begin
            slot = (cur_kt % NSL) * 128 + g;
            inj_v = 1; inj_par = cur_par;
            arr_end = cyc + R + C;
            hist_t[cyc % (R + C)] = cyc;
            for (x = 0; x < C; x = x + 1) hist_n[(cyc % (R + C))*C + x] = need[x];
            inj_bits = gb_m[slot]; inj_lab = gb_l[slot]; inj_pid = gb_id[slot];
            for (x = 0; x < C*F; x = x + 1) inj_fid[x*FIDW +: FIDW] = p_fid[cur_q*16 + x];
            if ($test$plusargs("dbg")) $display("INJ cyc=%0d tile=%0d kt=%0d q=%0d g=%0d slot=%0d bits=%h lab=%h need=%0d %0d %0d %0d",
                                                cyc, ti, cur_kt, cur_q, g, slot, gb_m[slot], gb_l[slot], need[0], need[1], need[2], need[3]);
        end
    endtask

    task automatic dump_tile;
        begin
            for (x = 0; x < nd; x = x + 1) begin
                $fwrite(fo, "%0d %0d", ti, dlist[x]);
                for (k = 0; k < T; k = k + 1) $fwrite(fo, " %0h", obuf[dlist[x]][k*PSW +: PSW]);
                $fwrite(fo, " %0d\n", spk_of[dlist[x]]);
            end
        end
    endtask

    initial begin
        fd = $fopen("closed/cfg.txt", "r");
        rc = $fscanf(fd, "%d %d %d %d %d", ntiles, nkt, npass, nslc, th);
        $fclose(fd);
        theta = th;
        fd = $fopen("closed/tiles.txt", "r");
        for (x = 0; x < ntiles; x = x + 1) rc = $fscanf(fd, "%d %d %d", t_kf[x], t_kc[x], t_pc[x]);
        $fclose(fd);
        fd = $fopen("closed/kt.txt", "r");
        for (x = 0; x < nkt; x = x + 1) begin
            rc = $fscanf(fd, "%d %d %d %d %d", k_tile[x], k_nn[x], k_sb[x], k_pf[x], k_np[x]);
            pk_ready[x] = -1; freed[x] = -1; ngr[x] = 0;
            for (q = k_pf[x]; q < k_pf[x] + k_np[x]; q = q + 1) begin p_tile[q] = k_tile[x]; p_kt[q] = x; end
        end
        $fclose(fd);
        fd = $fopen("closed/pass.txt", "r");
        for (x = 0; x < npass; x = x + 1)
            for (pe = 0; pe < 16; pe = pe + 1) begin
                rc = $fscanf(fd, "%d %d %d", k, c, d);
                p_w[x*16 + pe] = k[7:0]; p_f[x*16 + pe] = c[1:0]; p_fid[x*16 + pe] = d[FIDW-1:0];
            end
        $fclose(fd);
        $readmemh("closed/slices.hex", slices, 0, nslc - 1);
        for (x = 0; x < 16; x = x + 1) begin st_cyc[x] = -1; st_q[x] = -1; end
        for (x = 0; x < PL; x = x + 1) begin ln_kt[x] = -1; ln_fed[x] = -1; ln_fl[x] = 0; end
        for (x = 0; x < DLR; x = x + 1) dl_n[x] = 0;
        for (x = 0; x < R + C; x = x + 1) hist_t[x] = -100;
        fo = $fopen("closed/out_closed.txt", "w");
        if (!$value$plusargs("vcd_from=%d", vcd_from)) vcd_from = -1;
        if (!$value$plusargs("vcd_len=%d", vcd_len)) vcd_len = 0;
        vcd_lif = $test$plusargs("vcd_lif");
        if (!$value$plusargs("vcd_file=%s", vcd_file)) vcd_file = "closed/window.vcd";
        if (vcd_from >= 0 || vcd_lif) $dumpfile(vcd_file);
        repeat (3) @(negedge clk);
        rst = 0;
    end

    // ------------------------------------------------------------------ controller: one step per cycle
    always @(negedge clk) if (!rst && tot < 0) begin
        // ---- observe the registers updated at the last edge (results of cycle cyc-1)
        for (l = 0; l < PL; l = l + 1) if (ln_fed[l] >= 0) begin
            for (x = l * NO; x < (l + 1) * NO; x = x + 1) if (gv[x]) begin
                slot = (ln_fed[l] % NSL) * 128 + ngr[ln_fed[l]];
                gb_m[slot] = gm[x*R*T +: R*T]; gb_l[slot] = glab[x*2*R*T +: 2*R*T]; gb_id[slot] = gid[x*G*PIDW +: G*PIDW];
                ngr[ln_fed[l]] = ngr[ln_fed[l]] + 1;
            end
            if (ln_fl[l]) begin
                pk_ready[ln_fed[l]] = cyc;
                if (ngr[ln_fed[l]] == 0) freed[ln_fed[l]] = cyc;
            end
        end
        // LIF results of the entries presented LIFP cycles ago (pipelined LIF)
        for (x = 0; x < dl_n[(cyc - LIFP + DLR) % DLR]; x = x + 1)
            spk_of[dl_a[((cyc - LIFP + DLR) % DLR) * NLIF + x]] = lif_spk[x*T +: T];
        if (fc0 > fmax) fmax = fc0;
        if (fc1 > fmax) fmax = fc1;
        if (fc2 > fmax) fmax = fc2;
        if (fc3 > fmax) fmax = fc3;
        // the bundle leaving column c now was injected at cyc - R - c: its predicted entries must match the RTL
        for (c = 0; c < C; c = c + 1) begin
            hy = cyc - R - c; hk = (hy + R + C) % (R + C);
            if (((hist_t[hk] == hy) ? hist_n[hk*C + c] : 0) != (c == 0 ? nw0 : c == 1 ? nw1 : c == 2 ? nw2 : nw3)) begin
                pred_err = pred_err + 1;
                if ($test$plusargs("dbg") && pred_err < 6)
                    $display("PRED cyc=%0d col=%0d inj_cyc=%0d hist_t=%0d pred=%0d rtl=%0d", cyc, c, hy, hist_t[hk],
                             hist_n[hk*C + c], (c == 0 ? nw0 : c == 1 ? nw1 : c == 2 ? nw2 : nw3));
            end
        end
        hist_t[cyc % (R + C)] = -100;                        // no injection yet in this cycle
        // ---- VCD window control (the dump covers whole cycles of the DUT only)
        if (!vcd_done) begin
            if (!vcd_on && ((vcd_from >= 0 && cyc == vcd_from) || (vcd_lif && ti == 0 && state == 1))) begin
                $dumpvars(0, tb_ours_closed.dut); vcd_on = cyc;
                $display("VCD_ON cyc=%0d", cyc);
            end else if (vcd_on && ((vcd_from >= 0 && cyc == vcd_from + vcd_len) || (vcd_lif && ti == 1))) begin
                $dumpoff; vcd_done = 1;
                $display("VCD_WINDOW %0d cycles (%0d..%0d)", cyc - vcd_on, vcd_on, cyc);
                $finish;
            end
        end
        // ---- defaults for this cycle
        inj_v = 0; wl_en = 0; sl_v = 0; pk_flush = 0; lif_v = 0; lif_n = 0;
        for (l = 0; l < PL; l = l + 1) begin ln_fed[l] = -1; ln_fl[l] = 0; end
        // the entries issued to the LIF sweep last cycle: their output-buffer read data arrives now
        dl_n[cyc % DLR] = pend_n;
        for (x = 0; x < pend_n; x = x + 1) begin lif_v[x] = 1'b1; dl_a[(cyc % DLR) * NLIF + x] = pend_a[x]; end
        lif_x = pend_x;
        pend_n = 0;
        if (cyc == 0) begin ti = 0; start_tile; end
        // ---- array side (state transitions can chain within one cycle)
        nwait = 0;
        while (nwait == 0) begin
            nwait = 1;
            if (state == 0) begin                                   // RUN: inject passes
                if (injecting) begin
                    predict(cur_q, (cur_kt % NSL) * 128 + ig);
                    bp_check;
                    if (bp_ok) begin
                        inject(ig); ig = ig + 1;
                        if (ig == cur_P) begin injecting = 0; pass_done; end
                    end else stalls = stalls + 1;
                end else begin
                    while (aj < t_kf[ti] + t_kc[ti] && pk_ready[aj] >= 0 && pk_ready[aj] <= cyc && ngr[aj] == 0) begin
                        if (pk_ready[aj] > skipk) skipk = pk_ready[aj];   // shadow weights rewritten in that cycle
                        aj = aj + 1; ap = 0;
                    end
                    if (aj == t_kf[ti] + t_kc[ti]) begin
                        state = 1; nwait = 0;
                    end else if (pk_ready[aj] >= 0 && pk_ready[aj] <= cyc && cyc >= s_next && cyc > skipk) begin
                        predict(k_pf[aj] + ap, (aj % NSL) * 128);
                        bp_check;
                        if (bp_ok) begin
                            cur_kt = aj; cur_q = k_pf[aj] + ap; cur_P = ngr[aj];
                            cur_par = ~last_par; last_par = cur_par;
                            st_cyc[cyc % 16] = cyc; st_q[cyc % 16] = cur_q;
                            fr_kt = (ap == k_np[aj] - 1) ? aj : -1;
                            inject(0); ig = 1; injecting = (cur_P > 1); skipk = -1;
                            s_next = cyc + 1;                       // L = 1 (and after this pass's last group)
                            if (ap == k_np[aj] - 1) begin aj = aj + 1; ap = 0; end
                            else ap = ap + 1;
                            if (cur_P == 1) pass_done;
                        end else stalls = stalls + 1;
                    end
                end
            end else if (state == 1) begin                          // DRAIN: array, edge FIFOs and RMW writes done
                if (cyc >= arr_end && fc0 == 0 && fc1 == 0 && fc2 == 0 && fc3 == 0 && obuf_we == 0) begin
                    state = 2; li = 0; nwait = 0;
                end
            end else if (state == 2) begin                          // LIF sweep, 16 dirty entries per cycle
                if (li < nd) begin                                  // issue: read the entries (data next cycle)
                    for (x = 0; x < NLIF && li < nd; x = x + 1) begin
                        pend_x[x*T*PSW +: T*PSW] = obuf[dlist[li]]; pend_a[x] = dlist[li];
                        li = li + 1; pend_n = pend_n + 1;
                    end
                    if (li >= nd) begin state = 3; lif_end = cyc + 1 + LIFP; end   // last results captured then
                end else begin
                    state = 3; lif_end = cyc; nwait = 0;            // nothing dirty: ends now
                end
            end else if (state == 3 && cyc >= lif_end) begin        // tile end: next tile starts this cycle
                dump_tile;
                ti = ti + 1;
                if (ti == ntiles) tot = cyc;
                else begin start_tile; nwait = 0; end
            end
        end
        // ---- shadow weights: the next pass that runs is written into PE (k,c) from the cycle the current pass
        //      reaches it (its swap frees the shadow), as soon as that next pass is known
        if (tot < 0)
        for (k = 0; k < R; k = k + 1)
            for (c = 0; c < C; c = c + 1) begin
                pe = k * C + c;
                d = cyc - k - c;
                if (d >= 0 && st_cyc[d % 16] == d && p_tile[st_q[d % 16]] == ti) begin
                    pe_act[pe] = st_q[d % 16]; pe_par[pe] = ~pe_par[pe];
                end
                nq = next_exec(pe_act[pe]);
                if (nq >= 0 && pe_sh[pe] != nq) begin
                    pe_sh[pe] = nq;
                    wl_en[pe] = 1'b1; wl_w[pe*8 +: 8] = p_w[nq*16 + pe]; wl_f[pe*2 +: 2] = p_f[nq*16 + pe];
                    wl_par[pe] = ~pe_par[pe];
                end
            end
        // ---- packer lanes: K-tiles start in scan order on a free lane once their group-buffer slot is free
        //      (K-tile fk - NSL released); each lane feeds PPL slices of its K-tile per cycle
        for (l = 0; l < PL; l = l + 1)
            if (ln_kt[l] < 0 && fk < nkt && (fk < NSL || (freed[fk - NSL] >= 0 && freed[fk - NSL] <= cyc))) begin
                ln_kt[l] = fk; ln_fq[l] = 0; fk = fk + 1;
            end
        for (l = 0; l < PL; l = l + 1) if (ln_kt[l] >= 0) begin
            for (x = 0; x < PPL; x = x + 1) if (ln_fq[l] + x < k_nn[ln_kt[l]]) begin
                sb = l * PPL + x;
                sl_v[sb] = 1'b1; sl_m[sb*R*T +: R*T] = slices[k_sb[ln_kt[l]] + ln_fq[l] + x];
                sl_id[sb*PIDW +: PIDW] = ln_fq[l] + x;
            end
            ln_fed[l] = ln_kt[l]; ln_fq[l] = ln_fq[l] + PPL;
            if (ln_fq[l] >= k_nn[ln_kt[l]]) begin pk_flush[l] = 1'b1; ln_fl[l] = 1; ln_kt[l] = -1; end
        end
        if (tot >= 0) begin
            $fclose(fo);
            $display("CLOSED_DONE cycles=%0d rmw=%0d conflicts=%0d overflow=%b fifo_max=%0d tiles=%0d stalls=%0d pred_err=%0d",
                     tot, rmw, conflicts, ovf, fmax, ntiles, stalls, pred_err);
            $finish;
        end
        cyc = cyc + 1;
    end
endmodule
