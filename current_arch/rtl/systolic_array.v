// systolic_array.v -- the 4x4 weight-stationary array.
//
//   * Rows i = packed weight rows (up to 4 per pass).   Columns k = the 4 K-positions of a slab.
//   * Packed activation columns enter the top of column k (already skewed by the feeder:
//     column k gets packed column n one cycle later than column k-1) and move DOWN.
//   * Psum sets start empty at column 0 and move RIGHT, picking up one product per PE at most.
//   * A set leaves the array at the tap column keff-1 (the last used column of the slab).
//
// Weight load: one PE row per cycle (ld_row), 4 (idx,val) pairs for the 4 columns.
// ld_clr zeroes every stationary weight (rows that are not loaded stay off).
`include "snn_defs.vh"
module systolic_array (
    input                         clk,
    input                         rst_n,
    input                         en,
    input                         clr,
    // weight load
    input                         ld_clr,
    input                         ld_en,
    input  [1:0]                  ld_row,
    input  [`ARR*`IDXW-1:0]       ld_idx,        // column k at [k*IDXW +: IDXW]
    input  [`ARR*`VALW-1:0]       ld_val,
    // activation inputs (top row), one per column
    input  [`ARR-1:0]             in_valid,
    input  [`ARR*`IDXW-1:0]       in_idx,
    input  [`ARR*`TS-1:0]         in_mask,
    input  [2:0]                  keff,          // slab width, 1..4: the tap column is keff-1
    // exit tap
    output reg [`ARR-1:0]         tap_valid,
    output reg [`ARR*`SETW-1:0]   tap_sets,      // row i at [i*SETW +: SETW]
    output                        err_slot,
    output                        err_align
);
    localparam N = `ARR * `ARR;

    wire [N-1:0]          aov, sov, es, ea;
    wire [N*`IDXW-1:0]    aoi;
    wire [N*`TS-1:0]      aom;
    wire [N*`SETW-1:0]    sout;

    genvar i, k;
    generate
        for (i = 0; i < `ARR; i = i + 1) begin : row
            for (k = 0; k < `ARR; k = k + 1) begin : col
                localparam ID = i*`ARR + k;
                wire                a_v;
                wire [`IDXW-1:0]    a_i;
                wire [`TS-1:0]      a_m;
                wire                s_v;
                wire [`SETW-1:0]    s_i;

                if (i == 0) begin : top
                    assign a_v = in_valid[k];
                    assign a_i = in_idx[k*`IDXW +: `IDXW];
                    assign a_m = in_mask[k*`TS +: `TS];
                end else begin : below
                    assign a_v = aov[(i-1)*`ARR + k];
                    assign a_i = aoi[((i-1)*`ARR + k)*`IDXW +: `IDXW];
                    assign a_m = aom[((i-1)*`ARR + k)*`TS +: `TS];
                end

                if (k == 0) begin : left
                    assign s_v = a_v;                       // a new, empty set starts with every activation
                    assign s_i = {`SETW{1'b0}};
                end else begin : right
                    assign s_v = sov[i*`ARR + k - 1];
                    assign s_i = sout[(i*`ARR + k - 1)*`SETW +: `SETW];
                end

                pe u_pe (
                    .clk(clk), .rst_n(rst_n), .en(en), .clr(clr),
                    .ld_clr(ld_clr),
                    .ld_en(ld_en && (ld_row == i)),
                    .ld_idx(ld_idx[k*`IDXW +: `IDXW]),
                    .ld_val(ld_val[k*`VALW +: `VALW]),
                    .a_valid(a_v), .a_idx(a_i), .a_mask(a_m),
                    .s_valid(s_v), .s_in(s_i),
                    .ao_valid(aov[ID]),
                    .ao_idx(aoi[ID*`IDXW +: `IDXW]),
                    .ao_mask(aom[ID*`TS +: `TS]),
                    .so_valid(sov[ID]),
                    .s_out(sout[ID*`SETW +: `SETW]),
                    .err_slot(es[ID]),
                    .err_align(ea[ID])
                );
            end
        end
    endgenerate

    // columns at or beyond keff never receive data (the tap is column keff-1): their alignment check is meaningless
    reg [N-1:0] cmask;
    integer ci, cj;
    always @* begin
        for (ci = 0; ci < `ARR; ci = ci + 1)
            for (cj = 0; cj < `ARR; cj = cj + 1)
                cmask[ci*`ARR + cj] = (cj < keff);
    end
    assign err_slot  = |(es & cmask);
    assign err_align = |(ea & cmask);

    // tap column select: the set leaves at column keff-1
    integer r;
    always @* begin
        for (r = 0; r < `ARR; r = r + 1) begin
            tap_valid[r]                   = sov[r*`ARR + keff - 1];
            tap_sets[r*`SETW +: `SETW]     = sout[(r*`ARR + keff - 1)*`SETW +: `SETW];
        end
    end
endmodule
