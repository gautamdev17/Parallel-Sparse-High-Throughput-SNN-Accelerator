// =============================================================================
// ws_systolic_array : NxN weight-stationary systolic array (uses ws_pe.v)
//
//   C[m][j] = sum_k A[m][k] * W[k][j]
//   PE[k][j] permanently holds W[k][j].
//   Activations A[m][k] enter row k from the LEFT and move RIGHT.
//   Partial sums move DOWN, each PE adds  w * a  onto the sum from above.
//   C[m][j] pops out of the BOTTOM of column j.
// =============================================================================
module ws_systolic_array #(parameter N = 4, DW = 8, AW = 24) (
    input  wire                  clk, rst_n,
    input  wire                  load_w,
    input  wire [N*N*DW-1:0]     w_flat,           // W[k][j] at [(k*N+j)*DW +: DW]
    input  wire [N*DW-1:0]       a_left,           // row k's activation at [k*DW +: DW]
    output wire [N*AW-1:0]       y_bottom          // column j's output at [j*AW +: AW]
);
    wire signed [DW-1:0] a_w [0:N-1][0:N];         // horizontal wires
    wire signed [AW-1:0] p_w [0:N][0:N-1];         // vertical wires

    genvar k, j;
    generate
        for (k = 0; k < N; k = k + 1) begin : edge_left
            assign a_w[k][0] = a_left[k*DW +: DW];
        end
        for (j = 0; j < N; j = j + 1) begin : edge_top_bottom
            assign p_w[0][j] = {AW{1'b0}};                         // nothing above row 0
            assign y_bottom[j*AW +: AW] = p_w[N][j];
        end
        for (k = 0; k < N; k = k + 1) begin : row
            for (j = 0; j < N; j = j + 1) begin : col
                ws_pe #(.DW(DW), .AW(AW)) pe (
                    .clk(clk), .rst_n(rst_n), .load_w(load_w),
                    .w_in(w_flat[(k*N+j)*DW +: DW]),
                    .a_in(a_w[k][j]),     .a_out(a_w[k][j+1]),
                    .psum_in(p_w[k][j]),  .psum_out(p_w[k+1][j]));
            end
        end
    endgenerate
endmodule