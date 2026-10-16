// spikeflow_core.v -- SpikeFlow (Spikeflow.pdf) as modelled in baselines.spikeflow_layer_cycles:
//   16 x 16 output-stationary systolic array (Table 1), PE = 1-bit spike gating an 8-bit-weight accumulator
//   (Fig. 10, Sec. 4.3.1); rows = 16 output channels, columns = PCD = 16 (16/T pixels x T timesteps, Sec. 4.1);
//   16 LIF-PEs in a row, membrane passed from LIF-PE t to t+1 (Fig. 11/12, Sec. 4.3.2); on-chip memory 18.5 KB,
//   double-buffered (Table 1, Sec. 4.3): weight 2 x 5120 B, spike 2 x 2560 B, output 2 x 1792 B = 18,944 B.
// Silence processing (Sec. 4.2) happens before the data reaches the buffers: a pass streams only its non-silent
// K entries, one per cycle, read from the active buffer half by the sequencer; passes run back to back while
// the DMA (testbench) fills the idle half.
`timescale 1ns/1ps

module sf_pe #(parameter PSW = 16) (
    input  wire clk, rst,
    input  wire              v_in, first_in,
    input  wire signed [7:0] w_in,
    input  wire              s_in,
    output reg               v_out, first_out,
    output reg  signed [7:0] w_out,
    output reg               s_out,
    output reg  signed [PSW-1:0] psum_done,       // finished psum of the previous pass
    output reg               done
);
    reg signed [PSW-1:0] acc;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            v_out <= 0; first_out <= 0; w_out <= 0; s_out <= 0; acc <= 0; psum_done <= 0; done <= 0;
        end else begin
            v_out <= v_in; first_out <= first_in;
            w_out <= v_in ? w_in : 8'sd0;
            s_out <= v_in & s_in;
            done <= v_in & first_in;
            if (v_in && first_in) begin
                psum_done <= acc;
                acc <= s_in ? {{(PSW-8){w_in[7]}}, w_in} : {PSW{1'b0}};   // 1-bit spike gates the accumulator
            end else if (v_in && s_in)
                acc <= acc + {{(PSW-8){w_in[7]}}, w_in};
        end
    end
endmodule

// LIF-PE row: column t of a finished SA row is timestep t (T = PCD case); membrane passed along the row.
module sf_lif_row #(parameter C = 16, PSW = 16) (
    input  wire clk, rst, go,
    input  wire [C*PSW-1:0] x,
    input  wire signed [PSW+1:0] vth, vset,
    output reg  [C-1:0] spk
);
    reg signed [PSW+1:0] vm;
    reg [C-1:0] s;
    integer t;
    always @(*) begin
        vm = vset;
        for (t = 0; t < C; t = t + 1) begin
            vm = vm + $signed(x[t*PSW +: PSW]);
            s[t] = (vm > vth);
            if (s[t]) vm = vset;
        end
    end
    always @(posedge clk or posedge rst) if (rst) spk <= 0; else if (go) spk <= s;
endmodule

module spikeflow_core #(parameter R = 16, C = 16, PSW = 16,
                        WB_WORDS = 320, SB_WORDS = 1280, OB_WORDS = 896) (
    input  wire clk, rst,
    // DMA side (testbench = off-chip memory): fills the idle half of each double buffer
    input  wire                  dma_w_we,  input wire [8:0]  dma_w_addr, input wire [R*8-1:0] dma_w_data,
    input  wire                  dma_s_we,  input wire [10:0] dma_s_addr, input wire [C-1:0]   dma_s_data,
    // next pass (its data already in the idle halves): passes chain back to back, halves flip at pass start
    input  wire                  nxt_v,
    input  wire [10:0]           nxt_n,
    output wire                  nxt_take,
    output reg                   busy,
    output reg                   act,
    input  wire signed [PSW+1:0] vth, vset,
    output wire [R*C*PSW-1:0]    psum_out,
    output wire [R-1:0]          row_done,
    output wire [C-1:0]          lif_spk
);
    // ---------------- double-buffered on-chip memory (18.5 KB)
    reg [R*8-1:0] wbuf [0:1][0:WB_WORDS-1];
    reg [C-1:0]   sbuf [0:1][0:SB_WORDS-1];
    reg [C-1:0]   obuf [0:1][0:OB_WORDS-1];
    always @(posedge clk) begin
        if (dma_w_we) wbuf[~act][dma_w_addr] <= dma_w_data;
        if (dma_s_we) sbuf[~act][dma_s_addr] <= dma_s_data;
    end

    // ---------------- sequencer: one non-silent K entry per cycle, passes back to back
    reg [10:0] k, n;
    reg first, in_v, first_d;
    reg [R*8-1:0] w_now;
    reg [C-1:0] s_now;
    wire last = busy && (k + 1 == n);
    assign nxt_take = nxt_v && (!busy || last);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            act <= 0; busy <= 0; k <= 0; n <= 0; first <= 0; in_v <= 0; first_d <= 0; w_now <= 0; s_now <= 0;
        end else begin
            in_v <= busy;
            first_d <= busy & first;
            if (busy) begin
                w_now <= wbuf[act][k[8:0]];
                s_now <= sbuf[act][k];
            end
            if (nxt_take) begin
                busy <= 1; k <= 0; n <= nxt_n; first <= 1; act <= ~act;
            end else if (busy) begin
                k <= k + 1; first <= 0;
                if (last) busy <= 0;
            end
        end
    end

    // ---------------- edge skew + PE array
    genvar r, c;
    wire          lv [0:R-1][0:C];
    wire          lf [0:R-1][0:C];
    wire [7:0]    lw [0:R-1][0:C];
    wire          ts [0:R][0:C-1];
    generate
        for (r = 0; r < R; r = r + 1) begin : lskew
            wire [9:0] now = {in_v, first_d, w_now[r*8 +: 8]};
            if (r == 0) begin : z
                assign {lv[0][0], lf[0][0], lw[0][0]} = now;
            end else begin : d
                reg [9:0] sk [1:r];
                integer i;
                always @(posedge clk or posedge rst)
                    if (rst) for (i = 1; i <= r; i = i + 1) sk[i] <= 0;
                    else begin sk[1] <= now; for (i = 2; i <= r; i = i + 1) sk[i] <= sk[i-1]; end
                assign {lv[r][0], lf[r][0], lw[r][0]} = sk[r];
            end
        end
        for (c = 0; c < C; c = c + 1) begin : tskew
            wire now = in_v & s_now[c];
            if (c == 0) begin : z
                assign ts[0][0] = now;
            end else begin : d
                reg sk [1:c];
                integer i;
                always @(posedge clk or posedge rst)
                    if (rst) for (i = 1; i <= c; i = i + 1) sk[i] <= 0;
                    else begin sk[1] <= now; for (i = 2; i <= c; i = i + 1) sk[i] <= sk[i-1]; end
                assign ts[0][c] = sk[c];
            end
        end
        for (r = 0; r < R; r = r + 1) begin : row
            wire [C-1:0] dn;
            for (c = 0; c < C; c = c + 1) begin : col
                wire signed [PSW-1:0] p;
                sf_pe #(.PSW(PSW)) pe (.clk(clk), .rst(rst),
                    .v_in(lv[r][c]), .first_in(lf[r][c]), .w_in(lw[r][c]), .s_in(ts[r][c]),
                    .v_out(lv[r][c+1]), .first_out(lf[r][c+1]), .w_out(lw[r][c+1]), .s_out(ts[r+1][c]),
                    .psum_done(p), .done(dn[c]));
                assign psum_out[(r*C + c)*PSW +: PSW] = p;
            end
            assign row_done[r] = dn[C-1];
        end
    endgenerate

    // ---------------- LIF module: SA rows finish one cycle apart (stepped); one LIF-PE row serves them in turn
    reg [3:0] rsel;
    reg lgo;
    reg [C*PSW-1:0] lx;
    integer q;
    always @(*) begin
        lgo = |row_done; rsel = 0;
        for (q = 0; q < R; q = q + 1) if (row_done[q]) rsel = q;
        lx = psum_out[rsel*C*PSW +: C*PSW];
    end
    sf_lif_row #(.C(C), .PSW(PSW)) lif (.clk(clk), .rst(rst), .go(lgo), .x(lx), .vth(vth), .vset(vset), .spk(lif_spk));
    reg [9:0] owp;
    reg lgo_d;
    always @(posedge clk or posedge rst)
        if (rst) begin owp <= 0; lgo_d <= 0; end
        else begin
            lgo_d <= lgo;
            if (lgo_d) begin obuf[act][owp] <= lif_spk; owp <= (owp == OB_WORDS - 1) ? 0 : owp + 1; end
        end
endmodule
