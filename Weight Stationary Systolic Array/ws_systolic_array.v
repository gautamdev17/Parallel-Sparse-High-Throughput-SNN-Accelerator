// =============================================================================
// ws_systolic_array : NxN weight-stationary systolic array (uses ws_pe.v)
//
//   C[m][n] = sum_k A[m][k] * B[k][n]
//
//   ACTIVATIONS move TOP -> BOTTOM.   A[m][k] enters the top of COLUMN k.
//   PARTIAL SUMS move LEFT -> RIGHT.  Row r accumulates over the columns k.
//   C[m][n] comes out of the RIGHT edge of ROW n.
//
//   So PE[row r][col c] holds  B[k=c][n=r]  (the weights sit TRANSPOSED).
//   w_flat is given in the natural layout  w_flat[(k*N+n)*DW +: DW] = B[k][n]
//   and the transposition is done in the wiring below.
//
//   a_top[k*DW +: DW]    : activation entering top of column k
//   y_right[n*AW +: AW]  : result leaving right edge of row n
// =============================================================================
module ws_systolic_array #(parameter N = 4, DW = 8, AW = 24) (
    input  wire                  clk, rst_n,
    input  wire                  load_w,
    input  wire [N*N*DW-1:0]     w_flat,           // B[k][n] at [(k*N+n)*DW +: DW]
    input  wire [N*DW-1:0]       a_top,            // column k's activation at [k*DW +: DW]
    output wire [N*AW-1:0]       y_right           // row n's output at [n*AW +: AW]
);
    // a_w[r][c] : activation entering PE[r][c] from above   (vertical wires)
    // p_w[r][c] : partial sum entering PE[r][c] from the left (horizontal wires)
    wire signed [DW-1:0] a_w [0:N][0:N-1];
    wire signed [AW-1:0] p_w [0:N-1][0:N];

    genvar r, c;
    generate
        for (c = 0; c < N; c = c + 1) begin : edge_top
            assign a_w[0][c] = a_top[c*DW +: DW];
        end
        for (r = 0; r < N; r = r + 1) begin : edge_left_right
            assign p_w[r][0] = {AW{1'b0}};                       // nothing enters from the left
            assign y_right[r*AW +: AW] = p_w[r][N];
        end
        for (r = 0; r < N; r = r + 1) begin : row
            for (c = 0; c < N; c = c + 1) begin : col
                // PE[r][c] holds B[k=c][n=r]
                ws_pe #(.DW(DW), .AW(AW)) pe (
                    .clk(clk), .rst_n(rst_n), .load_w(load_w),
                    .w_in(w_flat[(c*N + r)*DW +: DW]),
                    .a_in(a_w[r][c]),     .a_out(a_w[r+1][c]),
                    .psum_in(p_w[r][c]),  .psum_out(p_w[r][c+1]));
            end
        end
    endgenerate
endmodule