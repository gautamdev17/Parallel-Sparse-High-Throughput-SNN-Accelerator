// sato_core.v (tsweep_synth copy: adder-search tree for any T, see CHANGES.md) -- SATO (sato.pdf, DAC'22) as modelled by the Prosperity repo (run_sato_conv_fc / run_sato_lif):
//   128 PEs (Table 3), PE = non-zero-element register + 8-bit-add accumulator, no comparator, no membrane
//   memory (Fig. 3a, Sec. 3.4); temporal-parallel dataflow: every spike row (time step t, output pixel p) is a
//   workload; the bucket-sort dispatcher (Sec. 3.3/3.4: popcount -> least-loaded PE) assigns rows to PEs;
//   for each output channel, every PE walks the spikes of its rows, one 8-bit add per cycle, so a layer takes
//   max_PE(spikes) x output channels cycles (the Prosperity-repo rule); 8 PE groups share input registers.
//   Binary adder-search tree (Sec. 3.4, Fig. 6): the T per-time-step integrations of a neuron -> prefix sums
//   -> binary search for the first time step at which the membrane exceeds Vth (log2 T + 1 cycles per neuron).
// Global buffer / weight buffer / input buffer = SRAM, outside the core (same exclusion as for all designs):
// each PE receives its weight through its own buffer read port (w_in).
`timescale 1ns/1ps

module sato_pe #(parameter AW = 16, IW = 12) (
    input  wire clk, rst,
    input  wire              v,          // a spike of this PE's current row is processed this cycle
    input  wire              row_end,    // ... and it is the row's last spike (for this output channel)
    input  wire [IW-1:0]     nz_idx,     // non-zero element (pre-synaptic index) -> weight address
    input  wire signed [7:0] w_in,       // weight (nz_idx, current output channel) from the weight buffer
    output reg  [IW-1:0]     nz_reg,     // non-zero element register (drives the weight-buffer address)
    output reg  signed [AW-1:0] res,     // finished integration of the row
    output reg               res_v
);
    reg signed [AW-1:0] acc;
    always @(posedge clk or posedge rst) begin
        if (rst) begin acc <= 0; res <= 0; res_v <= 0; nz_reg <= 0; end
        else begin
            res_v <= 0;
            if (v) begin
                nz_reg <= nz_idx;
                if (row_end) begin
                    res <= acc + {{(AW-8){w_in[7]}}, w_in};
                    res_v <= 1;
                    acc <= 0;
                end else
                    acc <= acc + {{(AW-8){w_in[7]}}, w_in};
            end
        end
    end
endmodule

// bucket-sort dispatcher: one row per cycle -> PE with the smallest load so far (popcount of the row added)
module sato_dispatch #(parameter NPE = 128, K = 16, LW = 16) (
    input  wire clk, rst, clr,
    input  wire          row_v,
    input  wire [K-1:0]  row_bits,       // one K-chunk of the spike row (popcount unit input)
    input  wire [5:0]    row_cnt_hi,     // pre-counted spikes of the rest of the row
    output reg  [6:0]    pe_sel,
    output reg           sel_v
);
    reg [LW-1:0] load [0:NPE-1];
    reg [5:0] pc;
    integer i;
    always @(*) begin
        pc = row_cnt_hi;
        for (i = 0; i < K; i = i + 1) pc = pc + row_bits[i];
    end
    // argmin tree over the PE loads
    reg [LW-1:0] mv; reg [6:0] mi;
    always @(*) begin
        mv = load[0]; mi = 0;
        for (i = 1; i < NPE; i = i + 1) if (load[i] < mv) begin mv = load[i]; mi = i; end
    end
    always @(posedge clk or posedge rst) begin
        if (rst) begin for (i = 0; i < NPE; i = i + 1) load[i] <= 0; pe_sel <= 0; sel_v <= 0; end
        else if (clr) begin for (i = 0; i < NPE; i = i + 1) load[i] <= 0; sel_v <= 0; end
        else begin
            sel_v <= row_v;
            if (row_v) begin load[mi] <= load[mi] + pc; pe_sel <= mi; end
        end
    end
endmodule

// binary adder-search tree: prefix sums of the T integrations, then a log2(T)-step binary search for the first
// time step whose membrane exceeds Vth (one comparison per cycle, log2 T + 1 cycles per neuron).
// tsweep_synth: written for any power-of-two T (was hard-coded for T = 8: 4-bit fire_t / lo / hi, 2-bit step
// counter ending at step 2, AW+4-bit prefix sums). Widths are the T = 8 ones generalised:
// prefix sums AW + log2(T) + 1 bits (20 at T = 8), fire_t / lo / hi log2(T) + 1 bits (4 at T = 8).
module sato_adder_search #(parameter T = 8, AW = 16, LT = $clog2(T), PW = AW + LT + 1, SW = (LT > 1) ? $clog2(LT) : 1) (
    input  wire clk, rst, go,
    input  wire [T*AW-1:0] x,
    input  wire signed [PW-1:0] vth,
    output reg  [LT:0] fire_t,           // first firing time step (T = no spike)
    output reg  done
);
    reg signed [PW-1:0] pre [0:T-1];
    reg signed [PW-1:0] cum;
    integer t;
    always @(posedge clk or posedge rst) begin
        if (rst) begin for (t = 0; t < T; t = t + 1) pre[t] <= 0; end
        else if (go) begin
            cum = 0;
            for (t = 0; t < T; t = t + 1) begin cum = cum + $signed(x[t*AW +: AW]); pre[t] <= cum; end
        end
    end
    reg [SW-1:0] step; reg [LT:0] lo, hi; reg busy;
    always @(posedge clk or posedge rst) begin
        if (rst) begin step <= 0; lo <= 0; hi <= T; busy <= 0; fire_t <= T; done <= 0; end
        else begin
            done <= 0;
            if (go) begin busy <= 1; step <= 0; lo <= 0; hi <= T; end
            else if (busy) begin
                // leaf comparator: membrane at the midpoint above threshold?
                if (pre[(lo + hi) >> 1] > vth) hi <= (lo + hi) >> 1; else lo <= ((lo + hi) >> 1) + 1;
                step <= step + 1;
                if (step == LT - 1) begin busy <= 0; done <= 1; fire_t <= (pre[(lo + hi) >> 1] > vth) ? (lo + hi) >> 1 : hi; end
            end
        end
    end
endmodule

module sato_core #(parameter NPE = 128, AW = 16, IW = 12, T = 4) (
    input  wire clk, rst,
    input  wire [NPE-1:0]       v, row_end,
    input  wire [NPE*IW-1:0]    nz_idx,
    input  wire [NPE*8-1:0]     w,
    output wire [NPE*AW-1:0]    res,
    output wire [NPE-1:0]       res_v,
    // dispatcher (runs ahead, one row per cycle)
    input  wire                 d_clr, d_row_v,
    input  wire [15:0]          d_bits,
    input  wire [5:0]           d_cnt,
    output wire [6:0]           d_sel,
    output wire                 d_sel_v,
    // adder-search tree (fed with a neuron's T integrations from the output buffer)
    input  wire                 a_go,
    input  wire [T*AW-1:0]      a_x,
    input  wire signed [AW+$clog2(T):0] vth,
    output wire [$clog2(T):0]   fire_t,
    output wire                 a_done
);
    genvar i;
    generate for (i = 0; i < NPE; i = i + 1) begin : pe
        sato_pe #(.AW(AW), .IW(IW)) u (.clk(clk), .rst(rst), .v(v[i]), .row_end(row_end[i]),
            .nz_idx(nz_idx[i*IW +: IW]), .w_in(w[i*8 +: 8]), .nz_reg(), .res(res[i*AW +: AW]), .res_v(res_v[i]));
    end endgenerate
    sato_dispatch #(.NPE(NPE)) disp (.clk(clk), .rst(rst), .clr(d_clr), .row_v(d_row_v), .row_bits(d_bits),
                                     .row_cnt_hi(d_cnt), .pe_sel(d_sel), .sel_v(d_sel_v));
    sato_adder_search #(.T(T), .AW(AW)) ast (.clk(clk), .rst(rst), .go(a_go), .x(a_x), .vth(vth),
                                             .fire_t(fire_t), .done(a_done));
endmodule
