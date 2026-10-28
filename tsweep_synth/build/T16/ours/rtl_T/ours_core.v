// ours_core.v -- synthesizable core of the DAC2027 design (DAC2027_accelerator_explained_rows.pdf), sized like
// the cycle model's base point (dac2027_sim/ours.py Cfg()):
//   R x C = 4 x 4 weight-stationary PEs, T = 8 gated adders per PE, F = 4 filters per column (2-bit filter
//   label per weight), G = 4 pixels per group (2-bit pixel label per spike bit), double-buffered (shadow)
//   weights, running sums of SW = 10 bits per (filter, pixel, timestep) inside the array (R * 127 < 2^9),
//   edge unit with an 80-entry FIFO per column (16 writes, E = 4 read-modify-writes per cycle, 24-bit sums),
//   16 leaky LIF units (pipelined, 2 timesteps per stage), and the run-time packer: 8 lanes x 1 pixel slice per
//   cycle (each lane packs its own K-tile; first-fit, 4 open groups).
// Not inside the core (SRAM, the same exclusion as for LoAS/PTB/SpikeX): weight memory, spike memory, group
// buffer, output buffer. The output buffer is accessed through the obuf_* read-modify-write ports.
`timescale 1ns/1ps

module ours_pe #(parameter T = 8, F = 4, G = 4, SW = 10) (
    input  wire                  clk, rst,
    input  wire                  wl_en, wl_par,
    input  wire signed [7:0]     wl_w,
    input  wire [1:0]            wl_f,
    input  wire                  i_v, i_par,
    input  wire [T-1:0]          i_bits,
    input  wire [2*T-1:0]        i_lab,
    input  wire [F*G*T*SW-1:0]   b_sum,
    input  wire [F*G-1:0]        b_tch,
    output reg                   o_v, o_par,
    output reg  [T-1:0]          o_bits,
    output reg  [2*T-1:0]        o_lab,
    output reg  [F*G*T*SW-1:0]   ob_sum,
    output reg  [F*G-1:0]        ob_tch
);
    localparam NS = F * G;
    reg signed [7:0] wa, ws;      // active / shadow weight
    reg [1:0] fa, fs;             // active / shadow filter label
    reg pa, ps;                   // pass parity of active / shadow
    wire swap = i_v && (i_par != pa);
    wire signed [7:0] w = swap ? ws : wa;
    wire [1:0] f = swap ? fs : fa;

    reg [F*G*T*SW-1:0] nsum;
    reg [NS-1:0] ntch;
    reg [3:0] slot;
    reg signed [SW-1:0] old, add;
    integer t, s;
    always @(*) begin
        nsum = b_sum;
        ntch = b_tch;
        for (t = 0; t < T; t = t + 1) begin
            slot = {f, i_lab[2*t +: 2]};
            old = b_sum[(slot * T + t) * SW +: SW];
            add = old + {{(SW-8){w[7]}}, w};
            if (i_v && i_bits[t] && (w != 0)) begin
                for (s = 0; s < NS; s = s + 1)
                    if (slot == s) begin
                        nsum[(s * T + t) * SW +: SW] = add;
                        ntch[s] = 1'b1;
                    end
            end
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            wa <= 0; ws <= 0; fa <= 0; fs <= 0; pa <= 0; ps <= 0;
            o_v <= 0; o_par <= 0; o_bits <= 0; o_lab <= 0; ob_sum <= 0; ob_tch <= 0;
        end else begin
            if (swap) begin wa <= ws; fa <= fs; pa <= ps; end
            if (wl_en) begin ws <= wl_w; fs <= wl_f; ps <= wl_par; end
            o_v <= i_v; o_par <= i_par;
            o_bits <= i_v ? i_bits : {T{1'b0}};
            o_lab <= i_v ? i_lab : {2*T{1'b0}};
            ob_sum <= nsum;
            ob_tch <= i_v ? ntch : {NS{1'b0}};
        end
    end
endmodule


// 80-entry FIFO, up to 16 writes (the touched slots of one bundle) and up to 4 reads per cycle.
// Banked: entry n lives in bank n%16, row n/16, so 16 consecutive writes always hit 16 different banks.
// rd_v marks the (up to E) head entries on offer; the edge arbiter decides how many leave (pop, in order).
// The FIFO itself has no backpressure: the controller that injects groups holds a group unless every column's
// count + the entries still in the array above it + the group's own entries fit in D (hw/tb/tb_ours_closed.v,
// ours.py), so count never exceeds D; overflow is a sticky error flag only.
module ours_edge_fifo #(parameter EW = 93, NS = 16, BANKS = 16, ROWS = 5, E = 4) (
    input  wire               clk, rst,
    input  wire [NS-1:0]      wr_v,          // which slots carry an entry
    input  wire [NS*EW-1:0]   wr_d,
    input  wire [2:0]         pop,
    output wire [E-1:0]       rd_v,
    output wire [E*EW-1:0]    rd_d,
    output reg  [7:0]         count,
    output reg                overflow
);
    localparam D = BANKS * ROWS;
    reg [EW-1:0] mem [0:D-1];
    reg [6:0] wptr, rptr;
    // ranks of the written slots
    reg [4:0] rank [0:NS-1];
    reg [4:0] nwr;
    integer s, b, i, bb;
    always @(*) begin
        nwr = 0;
        for (s = 0; s < NS; s = s + 1) begin
            rank[s] = nwr;
            nwr = nwr + wr_v[s];
        end
    end
    wire [2:0] avail = (count >= E) ? E : count[2:0];
    wire [2:0] nrd = pop;
    // per-bank write select
    reg [EW-1:0] bdata [0:BANKS-1];
    reg [BANKS-1:0] bwe;
    reg [2:0] brow [0:BANKS-1];
    reg [6:0] dest;
    always @(*) begin
        for (b = 0; b < BANKS; b = b + 1) begin bwe[b] = 0; bdata[b] = 0; brow[b] = 0; end
        for (s = 0; s < NS; s = s + 1) begin
            dest = (wptr + rank[s] >= D) ? wptr + rank[s] - D : wptr + rank[s];
            if (wr_v[s]) begin
                bwe[dest % BANKS] = 1'b1;
                bdata[dest % BANKS] = wr_d[s*EW +: EW];
                brow[dest % BANKS] = dest / BANKS;
            end
        end
    end
    genvar g;
    generate for (g = 0; g < E; g = g + 1) begin : rp
        wire [6:0] a = (rptr + g >= D) ? rptr + g - D : rptr + g;
        assign rd_v[g] = (g < avail);
        assign rd_d[g*EW +: EW] = mem[a];
    end endgenerate
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            wptr <= 0; rptr <= 0; count <= 0; overflow <= 0;
        end else begin
            for (bb = 0; bb < BANKS; bb = bb + 1)
                if (bwe[bb]) mem[brow[bb] * BANKS + bb] <= bdata[bb];
            wptr <= (wptr + nwr >= D) ? wptr + nwr - D : wptr + nwr;
            rptr <= (rptr + nrd >= D) ? rptr + nrd - D : rptr + nrd;
            count <= count + nwr - nrd;
            if (count + nwr - nrd > D) overflow <= 1'b1;
        end
    end
endmodule


// one leaky integrate-and-fire neuron over T timesteps in one cycle (doc Sec. 8: V = V/2 + x; fire if
// V >= theta, then V -= theta), registered output.
module ours_lif #(parameter T = 8, PSW = 24, TPS = 2) (
    input  wire clk, rst, v,
    input  wire [T*PSW-1:0] x,
    input  wire signed [PSW-1:0] theta,
    output wire [T-1:0] spk
);
    // pipelined over the timesteps: stage k handles timesteps k*TPS .. k*TPS+TPS-1 (V = V/2 + x; fire if
    // V >= theta, then V -= theta); spk is valid T/TPS cycles after v
    localparam NST = T / TPS;
    reg [NST-1:0] sv;
    reg signed [PSW+1:0] sV [0:NST-1];
    reg [T-1:0] sS [0:NST-1];
    reg [T*PSW-1:0] sX [0:NST-1];
    reg signed [PSW+1:0] Vt;
    reg [T-1:0] St;
    reg [T*PSW-1:0] src;
    reg [PSW-1:0] xt;
    integer k, t;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            sv <= 0;
            for (k = 0; k < NST; k = k + 1) begin sV[k] <= 0; sS[k] <= 0; sX[k] <= 0; end
        end else begin
            for (k = NST - 1; k >= 0; k = k - 1) begin
                Vt = (k == 0) ? 0 : sV[k-1];
                St = (k == 0) ? 0 : sS[k-1];
                src = (k == 0) ? x : sX[k-1];
                for (t = 0; t < TPS; t = t + 1) begin
                    xt = src[(k * TPS + t) * PSW +: PSW];
                    Vt = (Vt >>> 1) + $signed(xt);
                    St[k * TPS + t] = (Vt >= theta);
                    if (St[k * TPS + t]) Vt = Vt - theta;
                end
                sv[k] <= (k == 0) ? v : sv[k-1];
                sV[k] <= Vt; sS[k] <= St; sX[k] <= (k == 0) ? x : sX[k-1];
            end
        end
    end
    assign spk = sS[NST-1];
endmodule


// run-time packer: 8 pixel slices (R*T = 32 bits) per cycle, first-fit into <= 4 open groups of <= G pixels,
// oldest group evicted when none fits and all are open; full groups leave at once; flush empties all.
// The open groups are an age-ordered list q[0] (oldest) .. q[3]; valid entries are kept at the front.
// One pk_step per slice, chained combinationally (structural so that synthesis stays tractable).
module pk_step #(parameter MW = 32, G = 4, PIDW = 7, GW = 1 + 3 + MW + 2*MW + G*PIDW) (
    input  wire [4*GW-1:0] qi,
    input  wire            v,
    input  wire [MW-1:0]   m,
    input  wire [PIDW-1:0] id,
    output wire [4*GW-1:0] qo,
    output wire            ev,
    output wire [GW-1:0]   eg
);
    // fields: {valid, count[2:0], mask[MW], labels[2*MW], ids[G*PIDW]}
    wire [GW-1:0] q [0:4];
    wire [3:0] val, fit;
    wire [GW-1:0] joined [0:3];
    wire [3:0] jfull;
    genvar j, b, c;
    generate
        for (j = 0; j < 4; j = j + 1) begin : e
            assign q[j] = qi[j*GW +: GW];
            wire        vj = q[j][GW-1];
            wire [2:0]  cj = q[j][GW-2 -: 3];
            wire [MW-1:0] mj = q[j][GW-5 -: MW];
            wire [2*MW-1:0] lj = q[j][GW-5-MW -: 2*MW];
            wire [G*PIDW-1:0] ij = q[j][G*PIDW-1:0];
            assign val[j] = vj;
            assign fit[j] = vj && ((mj & m) == 0);
            wire [2*MW-1:0] lnew;
            for (b = 0; b < MW; b = b + 1) begin : lb
                assign lnew[2*b +: 2] = lj[2*b +: 2] | ({2{m[b]}} & cj[1:0]);
            end
            wire [G*PIDW-1:0] inew;
            for (c = 0; c < G; c = c + 1) begin : ib
                assign inew[c*PIDW +: PIDW] = (cj == c) ? id : ij[c*PIDW +: PIDW];
            end
            wire [2:0] cn = cj + 3'd1;
            assign joined[j] = {1'b1, cn, mj | m, lnew, inew};
            assign jfull[j] = (cn == G);
        end
    endgenerate
    assign q[4] = {GW{1'b0}};
    wire act = v && (m != 0);
    wire [3:0] sel = fit & ~{fit[2:0], 1'b0} & ~{fit[1:0], 2'b0} & ~{fit[0], 3'b0};
    wire any = |fit;
    wire [GW-1:0] jsel = ({GW{sel[0]}} & joined[0]) | ({GW{sel[1]}} & joined[1]) |
                         ({GW{sel[2]}} & joined[2]) | ({GW{sel[3]}} & joined[3]);
    wire full = |(sel & jfull);
    wire [GW-1:0] fresh = {1'b1, 3'd1, m, {2*MW{1'b0}}, {(G-1)*PIDW{1'b0}}, id};
    wire [GW-1:0] o [0:3];
    generate
        for (j = 0; j < 4; j = j + 1) begin : out
            // index of the removed entry when a full group leaves: entries after it move up
            wire after = |(sel & ((4'b1 << j) - 4'b1 | (4'b1 << j)));   // removed index <= j
            wire [GW-1:0] keep_join = sel[j] ? joined[j] : q[j];
            wire [GW-1:0] removed   = after ? q[j+1] : q[j];
            wire first_free = !val[j] && (j == 0 ? 1'b1 : val[j-1]);
            wire [GW-1:0] append  = val[3] ? (j == 3 ? fresh : q[j+1])
                                           : (first_free ? fresh : q[j]);
            assign o[j] = !act ? q[j] : (any ? (full ? removed : keep_join) : append);
            assign qo[j*GW +: GW] = o[j];
        end
    endgenerate
    assign ev = act && ((any && full) || (!any && val[3]));
    assign eg = (any && full) ? jsel : q[0];
endmodule

module ours_packer #(parameter PP = 8, MW = 32, G = 4, OPEN = 4, PIDW = 7) (
    input  wire                  clk, rst,
    input  wire [PP-1:0]         sl_v,
    input  wire [PP*MW-1:0]      sl_m,
    input  wire [PP*PIDW-1:0]    sl_id,
    input  wire                  flush,
    output reg  [PP+OPEN-1:0]    gv,
    output reg  [(PP+OPEN)*MW-1:0] gm,
    output reg  [(PP+OPEN)*2*MW-1:0] gl,
    output reg  [(PP+OPEN)*G*PIDW-1:0] gid,
    output reg  [(PP+OPEN)*3-1:0] gc
);
    localparam GW = 1 + 3 + MW + 2*MW + G*PIDW;
    reg  [4*GW-1:0] q;
    wire [4*GW-1:0] chain [0:PP];
    wire [PP-1:0] ev;
    wire [GW-1:0] eg [0:PP+OPEN-1];
    assign chain[0] = q;
    genvar i;
    generate
        for (i = 0; i < PP; i = i + 1) begin : st
            pk_step #(.MW(MW), .G(G), .PIDW(PIDW)) s (.qi(chain[i]), .v(sl_v[i]), .m(sl_m[i*MW +: MW]),
                .id(sl_id[i*PIDW +: PIDW]), .qo(chain[i+1]), .ev(ev[i]), .eg(eg[i]));
        end
        for (i = 0; i < OPEN; i = i + 1) begin : fl
            assign eg[PP + i] = chain[PP][i*GW +: GW];
        end
    endgenerate
    integer j;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            q <= 0; gv <= 0; gm <= 0; gl <= 0; gid <= 0; gc <= 0;
        end else begin
            q <= flush ? {4*GW{1'b0}} : chain[PP];
            for (j = 0; j < PP + OPEN; j = j + 1) begin
                gv[j] <= (j < PP) ? ev[j] : (flush && eg[j][GW-1]);
                gm[j*MW +: MW] <= eg[j][GW-5 -: MW];
                gl[j*2*MW +: 2*MW] <= eg[j][GW-5-MW -: 2*MW];
                gid[j*G*PIDW +: G*PIDW] <= eg[j][G*PIDW-1:0];
                gc[j*3 +: 3] <= eg[j][GW-2 -: 3];
            end
        end
    end
endmodule


module ours_core #(parameter R = 4, C = 4, T = 16, F = 4, G = 4, SW = 10, PSW = 24, E = 4,
                   NLIF = 16, PL = 8, PP = 1, FIDW = 6, PIDW = 7) (
    input  wire clk, rst,
    // ---- array injection (row 0 timing; rows k>0 are skewed by k cycles inside)
    input  wire                    inj_v, inj_par,
    input  wire [R*T-1:0]          inj_bits,
    input  wire [R*2*T-1:0]        inj_lab,
    input  wire [G*PIDW-1:0]       inj_pid,          // pixel ids of the group
    input  wire [C*F*FIDW-1:0]     inj_fid,          // filter ids of every column for this pass
    // ---- shadow weight loads, one port per PE
    input  wire [R*C-1:0]          wl_en,
    input  wire [R*C*8-1:0]        wl_w,
    input  wire [R*C*2-1:0]        wl_f,
    input  wire [R*C-1:0]          wl_par,
    // ---- output buffer read-modify-write, E ports per column, synchronous SRAM, 2 stages:
    //      cycle 1 (issue): obuf_addr is read; cycle 2: obuf_rdata (the registered read data) + the running sum is
    //      written to obuf_waddr. The arbiter keeps an address issued in cycle 1 out of cycle 2 (read-after-write).
    output wire [C*E-1:0]          obuf_we,
    output wire [C*E*(FIDW+PIDW)-1:0] obuf_addr,
    output wire [C*E*(FIDW+PIDW)-1:0] obuf_waddr,
    input  wire [C*E*T*PSW-1:0]    obuf_rdata,
    output wire [C*E*T*PSW-1:0]    obuf_wdata,
    output wire [C-1:0]            fifo_overflow,
    // ---- LIF sweep (lif_x = output-buffer entries; spikes T/2 cycles after lif_v, pipelined over timesteps)
    input  wire [NLIF-1:0]         lif_v,
    input  wire [NLIF*T*PSW-1:0]   lif_x,
    input  wire signed [PSW-1:0]   theta,
    output wire [NLIF*T-1:0]       lif_spk,
    // ---- packer: PL independent lanes, each packing its own K-tile at PP pixel slices per cycle
    input  wire [PL*PP-1:0]           sl_v,
    input  wire [PL*PP*R*T-1:0]       sl_m,
    input  wire [PL*PP*PIDW-1:0]      sl_id,
    input  wire [PL-1:0]              pk_flush,
    output wire [PL*(PP+4)-1:0]       pk_gv,
    output wire [PL*(PP+4)*R*T-1:0]   pk_gm,
    output wire [PL*(PP+4)*2*R*T-1:0] pk_gl,
    output wire [PL*(PP+4)*G*PIDW-1:0] pk_gid,
    output wire [PL*(PP+4)*3-1:0]     pk_gc
);
    localparam NS = F * G, BW = NS * T * SW, EW = FIDW + PIDW + T * SW;

    // ---------------- feeder skew: row k sees the injection k cycles later
    localparam IW = 1 + 1 + T + 2*T;
    wire [IW-1:0] row_in [0:R-1];
    genvar k, c, e, tt;
    generate for (k = 0; k < R; k = k + 1) begin : feed
        wire [IW-1:0] now = {inj_v, inj_par, inj_bits[k*T +: T], inj_lab[k*2*T +: 2*T]};
        if (k == 0) begin : z
            assign row_in[0] = now;
        end else begin : d
            reg [IW-1:0] sk [1:k];
            integer i;
            always @(posedge clk or posedge rst)
                if (rst) for (i = 1; i <= k; i = i + 1) sk[i] <= 0;
                else begin
                    sk[1] <= now;
                    for (i = 2; i <= k; i = i + 1) sk[i] <= sk[i-1];
                end
            assign row_in[k] = sk[k];
        end
    end endgenerate

    // ---------------- PE array
    wire           sv [0:R-1][0:C];
    wire           sp [0:R-1][0:C];
    wire [T-1:0]   sb [0:R-1][0:C];
    wire [2*T-1:0] sl [0:R-1][0:C];
    wire [BW-1:0]  bs [0:R][0:C-1];
    wire [NS-1:0]  bt [0:R][0:C-1];
    generate
        for (k = 0; k < R; k = k + 1) begin : rowin
            assign {sv[k][0], sp[k][0], sb[k][0], sl[k][0]} = row_in[k];
        end
        for (c = 0; c < C; c = c + 1) begin : top
            assign bs[0][c] = {BW{1'b0}};
            assign bt[0][c] = {NS{1'b0}};
        end
        for (k = 0; k < R; k = k + 1) begin : r
            for (c = 0; c < C; c = c + 1) begin : col
                localparam P = k * C + c;
                ours_pe #(.T(T), .F(F), .G(G), .SW(SW)) pe (
                    .clk(clk), .rst(rst),
                    .wl_en(wl_en[P]), .wl_par(wl_par[P]), .wl_w(wl_w[P*8 +: 8]), .wl_f(wl_f[P*2 +: 2]),
                    .i_v(sv[k][c]), .i_par(sp[k][c]), .i_bits(sb[k][c]), .i_lab(sl[k][c]),
                    .b_sum(bs[k][c]), .b_tch(bt[k][c]),
                    .o_v(sv[k][c+1]), .o_par(sp[k][c+1]), .o_bits(sb[k][c+1]), .o_lab(sl[k][c+1]),
                    .ob_sum(bs[k+1][c]), .ob_tch(bt[k+1][c]));
            end
        end
    endgenerate

    // ---------------- edge arbiter: the C*E head entries on offer (priority: column 0 first, then FIFO order).
    // An entry may not update the output buffer in the same cycle as an earlier offered entry with the same
    // (filter, pixel) address (both would read the old value); it and the entries behind it in its FIFO wait.
    wire [C*E-1:0] cv, ok, iss, sbv;
    wire [C*E*(FIDW+PIDW)-1:0] ca, sba;
    wire [C*3-1:0] npop;
    genvar qa, qb;
    generate
        for (qa = 0; qa < C*E; qa = qa + 1) begin : arb
            wire [C*E-1:0] same;
            for (qb = 0; qb < C*E; qb = qb + 1) begin : cmp
                if (qb < qa) begin : lo
                    assign same[qb] = cv[qb] && (ca[qb*(FIDW+PIDW) +: FIDW+PIDW] == ca[qa*(FIDW+PIDW) +: FIDW+PIDW]);
                end else begin : hi
                    assign same[qb] = 1'b0;
                end
            end
            wire [C*E-1:0] prev;              // read-after-write: the address is being written this cycle
            for (qb = 0; qb < C*E; qb = qb + 1) begin : rw
                assign prev[qb] = sbv[qb] && (sba[qb*(FIDW+PIDW) +: FIDW+PIDW] == ca[qa*(FIDW+PIDW) +: FIDW+PIDW]);
            end
            assign ok[qa] = cv[qa] && !(|same) && !(|prev);
            if (qa % E == 0) begin : h
                assign iss[qa] = ok[qa];
            end else begin : t
                assign iss[qa] = ok[qa] && iss[qa - 1];
            end
        end
        for (qa = 0; qa < C; qa = qa + 1) begin : pc
            assign npop[qa*3 +: 3] = iss[qa*E] + iss[qa*E + 1] + iss[qa*E + 2] + iss[qa*E + 3];
        end
    endgenerate

    // ---------------- id sideband: column c needs the ids R + c cycles after injection
    localparam IDW = G * PIDW + F * FIDW;
    generate for (c = 0; c < C; c = c + 1) begin : ids
        localparam L = R + c;
        reg [IDW-1:0] dl [1:L];
        integer d;
        always @(posedge clk or posedge rst)
            if (rst) for (d = 1; d <= L; d = d + 1) dl[d] <= 0;
            else begin
                dl[1] <= {inj_pid, inj_fid[c*F*FIDW +: F*FIDW]};
                for (d = 2; d <= L; d = d + 1) dl[d] <= dl[d-1];
            end
        wire [G*PIDW-1:0] pid = dl[L][IDW-1 -: G*PIDW];
        wire [F*FIDW-1:0] fid = dl[L][F*FIDW-1:0];

        // ---- edge unit: entries of the touched slots -> FIFO -> E read-modify-writes
        wire [NS*EW-1:0] wd;
        for (e = 0; e < NS; e = e + 1) begin : ent
            wire [T*SW-1:0] sums;
            for (tt = 0; tt < T; tt = tt + 1) begin : ts
                assign sums[tt*SW +: SW] = bs[R][c][(e*T + tt)*SW +: SW];
            end
            assign wd[e*EW +: EW] = {fid[(e / G)*FIDW +: FIDW], pid[(e % G)*PIDW +: PIDW], sums};
        end
        wire [E-1:0] rv;
        wire [E*EW-1:0] rd;
        wire [7:0] cnt;
        ours_edge_fifo #(.EW(EW), .NS(NS), .E(E)) fifo (
            .clk(clk), .rst(rst), .wr_v(bt[R][c]), .wr_d(wd), .pop(npop[c*3 +: 3]), .rd_v(rv), .rd_d(rd),
            .count(cnt), .overflow(fifo_overflow[c]));
        for (e = 0; e < E; e = e + 1) begin : rmw
            localparam Q = c * E + e;
            wire [EW-1:0] ent = rd[e*EW +: EW];
            assign cv[Q] = rv[e];
            assign ca[Q*(FIDW+PIDW) +: FIDW+PIDW] = ent[EW-1 -: FIDW+PIDW];
            assign obuf_addr[Q*(FIDW+PIDW) +: FIDW+PIDW] = ent[EW-1 -: FIDW+PIDW];   // stage 1: read
            reg sb_v; reg [FIDW+PIDW-1:0] sb_a; reg [T*SW-1:0] sb_d;                  // stage 2 registers
            always @(posedge clk or posedge rst)
                if (rst) begin sb_v <= 1'b0; sb_a <= 0; sb_d <= 0; end
                else begin sb_v <= iss[Q]; sb_a <= ent[EW-1 -: FIDW+PIDW]; sb_d <= ent[T*SW-1:0]; end
            assign sbv[Q] = sb_v;
            assign sba[Q*(FIDW+PIDW) +: FIDW+PIDW] = sb_a;
            assign obuf_we[Q] = sb_v;
            assign obuf_waddr[Q*(FIDW+PIDW) +: FIDW+PIDW] = sb_a;
            for (tt = 0; tt < T; tt = tt + 1) begin : add
                wire signed [SW-1:0] v = sb_d[tt*SW +: SW];
                assign obuf_wdata[(Q*T + tt)*PSW +: PSW] =
                    $signed(obuf_rdata[(Q*T + tt)*PSW +: PSW]) + {{(PSW-SW){v[SW-1]}}, v};
            end
        end
    end endgenerate

    // ---------------- LIF units
    generate for (e = 0; e < NLIF; e = e + 1) begin : lif
        ours_lif #(.T(T), .PSW(PSW)) u (.clk(clk), .rst(rst), .v(lif_v[e]), .x(lif_x[e*T*PSW +: T*PSW]),
                                        .theta(theta), .spk(lif_spk[e*T +: T]));
    end endgenerate

    // ---------------- packer lanes
    generate for (e = 0; e < PL; e = e + 1) begin : lane
        localparam NO = PP + 4;
        ours_packer #(.PP(PP), .MW(R*T), .G(G), .OPEN(4), .PIDW(PIDW)) packer (
            .clk(clk), .rst(rst), .sl_v(sl_v[e*PP +: PP]), .sl_m(sl_m[e*PP*R*T +: PP*R*T]),
            .sl_id(sl_id[e*PP*PIDW +: PP*PIDW]), .flush(pk_flush[e]),
            .gv(pk_gv[e*NO +: NO]), .gm(pk_gm[e*NO*R*T +: NO*R*T]), .gl(pk_gl[e*NO*2*R*T +: NO*2*R*T]),
            .gid(pk_gid[e*NO*G*PIDW +: NO*G*PIDW]), .gc(pk_gc[e*NO*3 +: NO*3]));
    end endgenerate
endmodule
