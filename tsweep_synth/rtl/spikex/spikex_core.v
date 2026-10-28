// spikex_core.v -- SpikeX (Xu et al.) systolic array as modelled in dac2027_sim/baselines.py, temporal-mode
// dispatch with TWS = 1 (the mode/TWS the cycle model picks on these layers): 8 x 8 PEs, one accumulator each.
// Row r = output channel r of the current pixel, column t = timestep t. Each cycle the next ACTIVE input of the
// receptive field streams in: its weight enters row r from the left and is shared along the row (moves right),
// its spike bit for timestep t enters column t from the top (moves down). Psums stay in place; a 'first' flag
// travelling with the weights starts a new NTWU batch. One integrate-and-fire unit per row.
// Uses ptb_pe-style PE with a single weight (no StSAP pairing in SpikeX).
`timescale 1ns/1ps

module spikex_pe #(parameter AW = 16, SPB = 96) (
    input  wire clk, rst,
    input  wire              v_in, first_in,
    input  wire [5:0]        a_in,
    input  wire signed [7:0] w_in,
    input  wire              s_in,
    output reg               v_out, first_out,
    output reg  [5:0]        a_out,
    output reg  signed [7:0] w_out,
    output reg               s_out,
    output reg  signed [AW-1:0] psum
);
    // SpikeX PE "small scratchpad memory" (size not given in the paper): 96 x 8-bit, same as PTB
    reg [7:0] sp [0:SPB-1];
    reg [5:0] cur;
    wire signed [7:0] w = s_in ? w_in : 8'sd0;
    wire signed [AW-1:0] old = {sp[{cur, 1'b1}], sp[{cur, 1'b0}]};
    wire [5:0] wa_slot = (v_in && first_in) ? a_in : cur;
    wire signed [AW-1:0] base = (v_in && first_in) ? {AW{1'b0}} : old;
    wire signed [AW-1:0] nv = base + {{(AW-8){w[7]}}, w};
    integer i;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            v_out <= 0; first_out <= 0; a_out <= 0; w_out <= 0; s_out <= 0; cur <= 0; psum <= 0;
            for (i = 0; i < SPB; i = i + 1) sp[i] <= 0;
        end else begin
            v_out <= v_in; first_out <= first_in; a_out <= v_in ? a_in : 6'd0;
            w_out <= v_in ? w_in : 8'sd0;
            s_out <= v_in & s_in;
            if (v_in && first_in) begin psum <= old; cur <= a_in; end
            if (v_in) begin sp[{wa_slot, 1'b0}] <= nv[7:0]; sp[{wa_slot, 1'b1}] <= nv[15:8]; end
        end
    end
endmodule

module spikex_core #(parameter ROWS = 8, COLS = 8, AW = 16) (
    input  wire clk, rst,
    input  wire                  in_v, in_first,
    input  wire [5:0]            in_a,
    input  wire [ROWS*8-1:0]     w,
    input  wire [COLS-1:0]       s,
    input  wire signed [AW-1:0]  theta,
    output wire [ROWS*COLS-1:0]  spk,
    output wire [ROWS*COLS*AW-1:0] psum_out
);
    genvar r, c;
    wire          lv [0:ROWS-1][0:COLS];
    wire          lf [0:ROWS-1][0:COLS];
    wire [7:0]    lw [0:ROWS-1][0:COLS];
    wire [5:0]    lA [0:ROWS-1][0:COLS];
    wire          ts [0:ROWS][0:COLS-1];
    generate
        for (r = 0; r < ROWS; r = r + 1) begin : lskew
            wire [15:0] now = {in_v, in_first, in_a, w[r*8 +: 8]};
            if (r == 0) begin : z
                assign {lv[0][0], lf[0][0], lA[0][0], lw[0][0]} = now;
            end else begin : d
                reg [15:0] sk [1:r];
                integer i;
                always @(posedge clk or posedge rst)
                    if (rst) for (i = 1; i <= r; i = i + 1) sk[i] <= 0;
                    else begin sk[1] <= now; for (i = 2; i <= r; i = i + 1) sk[i] <= sk[i-1]; end
                assign {lv[r][0], lf[r][0], lA[r][0], lw[r][0]} = sk[r];
            end
        end
        for (c = 0; c < COLS; c = c + 1) begin : tskew
            wire now = in_v & s[c];
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
        for (r = 0; r < ROWS; r = r + 1) begin : row
            wire [COLS*AW-1:0] ps;
            for (c = 0; c < COLS; c = c + 1) begin : col
                wire signed [AW-1:0] p;
                spikex_pe #(.AW(AW)) pe (.clk(clk), .rst(rst),
                    .v_in(lv[r][c]), .first_in(lf[r][c]), .a_in(lA[r][c]), .w_in(lw[r][c]), .s_in(ts[r][c]),
                    .v_out(lv[r][c+1]), .first_out(lf[r][c+1]), .a_out(lA[r][c+1]), .w_out(lw[r][c+1]), .s_out(ts[r+1][c]),
                    .psum(p));
                assign ps[c*AW +: AW] = p;
                assign psum_out[(r*COLS + c)*AW +: AW] = p;
            end
            row_if #(.T(COLS), .AW(AW)) lif (.clk(clk), .rst(rst), .go(lv[r][COLS] & lf[r][COLS]),
                                             .x(ps), .theta(theta), .spk(spk[r*COLS +: COLS]));
        end
    endgenerate
endmodule
