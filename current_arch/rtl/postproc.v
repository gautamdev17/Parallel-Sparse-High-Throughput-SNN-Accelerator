// postproc.v -- post-processing unit.
//
//  1. Collects the {m, n, spike byte} results that the neuron lanes produce (packed result
//     buffer, written in order, up to PORTS entries per cycle).
//  2. When the whole tile is done (tile_done) it UNPACKS the buffer: LANES (16) entries per cycle
//     become HBM writes {row = m-1, col = n-1, data = spike byte}, tile-local coordinates.
//     The output region of HBM is zero-filled beforehand, so positions that never spiked or were
//     never touched stay 0 -- the dense spike matrix (the next layer's B) is complete when
//     pp_done pulses.
//  Unpack takes ceil(entries / LANES) cycles (REPORT.md: only the last tile's tail is counted).
module postproc #(
    parameter PORTS  = 8,
    parameter LANES  = 16,
    parameter MAXRES = 8192
) (
    input                    clk,
    input                    rst_n,
    input                    tile_start,
    // from the neuron lanes
    input  [PORTS-1:0]       res_valid,
    input  [PORTS*8-1:0]     res_m,
    input  [PORTS*8-1:0]     res_n,
    input  [PORTS*8-1:0]     res_byte,
    input                    tile_done,
    // HBM write port
    output reg [LANES-1:0]   hbm_wr_valid,
    output reg [LANES*8-1:0] hbm_wr_row,
    output reg [LANES*8-1:0] hbm_wr_col,
    output reg [LANES*8-1:0] hbm_wr_data,
    output                   busy,
    output reg               pp_done,
    output reg [31:0]        pp_cycles,
    output [13:0]            nres
);
    reg [23:0] rbuf [0:MAXRES-1];       // {m, n, byte}
    reg [13:0] cnt, ptr;
    reg        unpack;
    integer    j, n, l, idx;
    reg [23:0] e;
    reg [7:0]  mm, nn;

    assign busy = unpack;
    assign nres = cnt;

    // unpack side (combinational read of the buffer)
    always @* begin
        for (l = 0; l < LANES; l = l + 1) begin
            idx = ptr + l;
            hbm_wr_valid[l]          = unpack && (idx < cnt);
            e                        = hbm_wr_valid[l] ? rbuf[idx] : 24'd0;
            mm                       = e[23:16];
            nn                       = e[15:8];
            hbm_wr_row[l*8 +: 8]     = hbm_wr_valid[l] ? (mm - 8'd1) : 8'd0;
            hbm_wr_col[l*8 +: 8]     = hbm_wr_valid[l] ? (nn - 8'd1) : 8'd0;
            hbm_wr_data[l*8 +: 8]    = e[7:0];
        end
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cnt <= 14'd0; ptr <= 14'd0; unpack <= 1'b0; pp_done <= 1'b0; pp_cycles <= 32'd0;
        end else begin
            pp_done <= 1'b0;
            if (tile_start) begin
                cnt <= 14'd0; pp_cycles <= 32'd0;
            end else begin
                // append this cycle's results, lane order
                n = cnt;
                for (j = 0; j < PORTS; j = j + 1)
                    if (res_valid[j]) begin
                        rbuf[n] <= {res_m[j*8 +: 8], res_n[j*8 +: 8], res_byte[j*8 +: 8]};
                        n = n + 1;
                    end
                cnt <= n;
            end
            if (tile_done) begin
                if (cnt == 0) pp_done <= 1'b1;
                else begin unpack <= 1'b1; ptr <= 14'd0; end
            end
            if (unpack) begin
                pp_cycles <= pp_cycles + 32'd1;
                ptr <= ptr + LANES;
                if (ptr + LANES >= cnt) begin
                    unpack  <= 1'b0;
                    pp_done <= 1'b1;
                end
            end
        end
    end
endmodule
