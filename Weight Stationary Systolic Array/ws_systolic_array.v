// =============================================================================
// ws_systolic_array : NxN weight-stationary systolic array (uses ws_pe.v)
//                     + single-cycle ReLU on the psums leaving the right edge.
//
//   C[m][n] = relu( sum_k A[m][k] * B[k][n] )
//
//   ACTIVATIONS move TOP -> BOTTOM.   A[m][k] enters the top of COLUMN k.
//   PARTIAL SUMS move LEFT -> RIGHT.  Row r accumulates over the columns k.
//   After the last column, each row's psum goes through a registered ReLU
//   (1 cycle) and then out on y_out.
//
//   PE[row r][col c] holds  B[k=c][n=r]  (weights sit TRANSPOSED).
//   w_flat is given in the natural layout  w_flat[(k*N+n)*DW +: DW] = B[k][n]
//   and the transposition is done in the wiring below.
//
//   a_top[k*DW +: DW]   : activation entering top of column k
//   y_out[n*AW +: AW]   : ReLU'd result leaving row n   (1 cycle after the psum
//                         leaves the last PE)
// =============================================================================
module ws_systolic_array #(parameter N = 4, DW = 8, AW = 24) (
    input  wire                  clk, rst_n,
    input  wire                  load_w,
    input  wire [N*N*DW-1:0]     w_flat,           // B[k][n] at [(k*N+n)*DW +: DW]
    input  wire [N*DW-1:0]       a_top,            // column k's activation at [k*DW +: DW]
    output reg  [N*AW-1:0]       y_out             // row n's ReLU'd output at [n*AW +: AW]
);
    // a_w[r][c] : activation entering PE[r][c] from above    (vertical wires)
    // p_w[r][c] : partial sum entering PE[r][c] from the left (horizontal wires)
    wire signed [DW-1:0] a_w [0:N][0:N-1];
    wire signed [AW-1:0] p_w [0:N-1][0:N];
    wire signed [AW-1:0] y_raw [0:N-1];            // psums leaving the last column

    genvar r, c;
    generate
        for (c = 0; c < N; c = c + 1) begin : edge_top
            assign a_w[0][c] = a_top[c*DW +: DW];
        end
        for (r = 0; r < N; r = r + 1) begin : edge_left_right
            assign p_w[r][0] = {AW{1'b0}};                       // nothing enters from the left
            assign y_raw[r]  = p_w[r][N];                        // exits after the 4th column
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

    // ---------------- single-cycle ReLU on the right edge ----------------
    integer i;
    always @(posedge clk) begin
        if (!rst_n) y_out <= {N*AW{1'b0}};
        else
            for (i = 0; i < N; i = i + 1)
                y_out[i*AW +: AW] <= y_raw[i][AW-1] ? {AW{1'b0}} : y_raw[i];   // sign bit set -> 0
    end
endmodule