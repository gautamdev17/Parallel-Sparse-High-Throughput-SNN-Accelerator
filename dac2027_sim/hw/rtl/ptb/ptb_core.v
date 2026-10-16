// ptb_core.v -- PTB (Lee et al., MICRO'21) systolic array as modelled in dac2027_sim/baselines.py:
// ROWS x COLS = 16 x 8 PEs, one 8-bit-weight accumulate (AC) unit per PE, TWS = 1 (column t = timestep t).
// Row r = output channel r of the current output pixel; one packed input slot per cycle streams through:
// its weights (w_a, w_b of the two StSAP-packed inputs) enter row r from the left and move right, its spike
// bits (s_a[t], s_b[t], non-overlapping by construction) enter column t from the top and move down.
// The psum of each PE stays in place (output stationary); a 'first' flag that travels with the weights
// marks the first slot of a new iteration: the PE hands its finished psum to its out register and restarts.
// One integrate-and-fire unit per row (PTB Step B, eq. 8) turns the row's T psums into T spikes.
// Scratchpad: PTB Table 4's 96 x 8-bit scratchpad per PE is built and holds the psums (2 bytes each).
`timescale 1ns/1ps

module ptb_pe #(parameter AW = 16, SPB = 96) (
    input  wire clk, rst,
    input  wire              v_in, first_in,
    input  wire [5:0]        a_in,            // scratchpad slot (2 bytes) of this iteration's psum
    input  wire signed [7:0] wa_in, wb_in,
    input  wire              sa_in, sb_in,
    output reg               v_out, first_out,
    output reg  [5:0]        a_out,
    output reg  signed [7:0] wa_out, wb_out,
    output reg               sa_out, sb_out,
    output reg  signed [AW-1:0] psum
);
    // PTB Table 4: 96 x 8-bit scratchpad per PE; a 16-bit psum occupies 2 bytes (48 slots)
    reg [7:0] sp [0:SPB-1];
    reg [5:0] cur;
    wire signed [7:0] w = sa_in ? wa_in : (sb_in ? wb_in : 8'sd0);
    wire signed [AW-1:0] old = {sp[{cur, 1'b1}], sp[{cur, 1'b0}]};
    wire [5:0] wa_slot = (v_in && first_in) ? a_in : cur;
    wire signed [AW-1:0] base = (v_in && first_in) ? {AW{1'b0}} : old;
    wire signed [AW-1:0] nv = base + {{(AW-8){w[7]}}, w};
    integer i;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            v_out <= 0; first_out <= 0; a_out <= 0; wa_out <= 0; wb_out <= 0; sa_out <= 0; sb_out <= 0;
            cur <= 0; psum <= 0;
            for (i = 0; i < SPB; i = i + 1) sp[i] <= 0;
        end else begin
            v_out <= v_in; first_out <= first_in; a_out <= v_in ? a_in : 6'd0;
            wa_out <= v_in ? wa_in : 8'sd0; wb_out <= v_in ? wb_in : 8'sd0;
            sa_out <= v_in & sa_in; sb_out <= v_in & sb_in;
            if (v_in && first_in) begin psum <= old; cur <= a_in; end
            if (v_in) begin sp[{wa_slot, 1'b0}] <= nv[7:0]; sp[{wa_slot, 1'b1}] <= nv[15:8]; end
        end
    end
endmodule

module row_if #(parameter T = 8, AW = 16) (
    input  wire clk, rst, go,
    input  wire [T*AW-1:0] x,
    input  wire signed [AW-1:0] theta,
    output reg  [T-1:0] spk
);
    reg signed [AW+1:0] V;
    reg [T-1:0] s;
    integer t;
    always @(*) begin
        V = 0;
        for (t = 0; t < T; t = t + 1) begin
            V = V + $signed(x[t*AW +: AW]);
            s[t] = (V >= theta);
            if (s[t]) V = 0;                       // PTB eq. (8): reset to 0
        end
    end
    always @(posedge clk or posedge rst)
        if (rst) spk <= 0; else if (go) spk <= s;
endmodule

module ptb_core #(parameter ROWS = 16, COLS = 8, AW = 16) (
    input  wire clk, rst,
    input  wire                  in_v, in_first,
    input  wire [5:0]            in_a,
    input  wire [ROWS*8-1:0]     wa, wb,          // per row, unskewed (skewed inside)
    input  wire [COLS-1:0]       sa, sb,          // per column, unskewed
    input  wire signed [AW-1:0]  theta,
    output wire [ROWS*COLS-1:0]  spk,
    output wire [ROWS*COLS*AW-1:0] psum_out
);
    genvar r, c;
    // left-edge skew: row r delayed r cycles
    wire          lv [0:ROWS-1][0:COLS];
    wire          lf [0:ROWS-1][0:COLS];
    wire [7:0]    la [0:ROWS-1][0:COLS];
    wire [7:0]    lb [0:ROWS-1][0:COLS];
    wire [5:0]    lA [0:ROWS-1][0:COLS];
    wire          ta [0:ROWS][0:COLS-1];
    wire          tb [0:ROWS][0:COLS-1];
    generate
        for (r = 0; r < ROWS; r = r + 1) begin : lskew
            wire [23:0] now = {in_v, in_first, in_a, wa[r*8 +: 8], wb[r*8 +: 8]};
            if (r == 0) begin : z
                assign {lv[0][0], lf[0][0], lA[0][0], la[0][0], lb[0][0]} = now;
            end else begin : d
                reg [23:0] sk [1:r];
                integer i;
                always @(posedge clk or posedge rst)
                    if (rst) for (i = 1; i <= r; i = i + 1) sk[i] <= 0;
                    else begin sk[1] <= now; for (i = 2; i <= r; i = i + 1) sk[i] <= sk[i-1]; end
                assign {lv[r][0], lf[r][0], lA[r][0], la[r][0], lb[r][0]} = sk[r];
            end
        end
        for (c = 0; c < COLS; c = c + 1) begin : tskew
            wire [1:0] now = {in_v & sa[c], in_v & sb[c]};
            if (c == 0) begin : z
                assign {ta[0][0], tb[0][0]} = now;
            end else begin : d
                reg [1:0] sk [1:c];
                integer i;
                always @(posedge clk or posedge rst)
                    if (rst) for (i = 1; i <= c; i = i + 1) sk[i] <= 0;
                    else begin sk[1] <= now; for (i = 2; i <= c; i = i + 1) sk[i] <= sk[i-1]; end
                assign {ta[0][c], tb[0][c]} = sk[c];
            end
        end
        for (r = 0; r < ROWS; r = r + 1) begin : row
            wire [COLS*AW-1:0] ps;
            for (c = 0; c < COLS; c = c + 1) begin : col
                wire signed [AW-1:0] p;
                ptb_pe #(.AW(AW)) pe (.clk(clk), .rst(rst),
                    .v_in(lv[r][c]), .first_in(lf[r][c]), .a_in(lA[r][c]), .wa_in(la[r][c]), .wb_in(lb[r][c]),
                    .sa_in(ta[r][c]), .sb_in(tb[r][c]),
                    .v_out(lv[r][c+1]), .first_out(lf[r][c+1]), .a_out(lA[r][c+1]), .wa_out(la[r][c+1]), .wb_out(lb[r][c+1]),
                    .sa_out(ta[r+1][c]), .sb_out(tb[r+1][c]), .psum(p));
                assign ps[c*AW +: AW] = p;
                assign psum_out[(r*COLS + c)*AW +: AW] = p;
            end
            // the row's psums are all handed over once 'first' has passed the last column
            row_if #(.T(COLS), .AW(AW)) lif (.clk(clk), .rst(rst), .go(lv[r][COLS] & lf[r][COLS]),
                                             .x(ps), .theta(theta), .spk(spk[r*COLS +: COLS]));
        end
    endgenerate
endmodule
