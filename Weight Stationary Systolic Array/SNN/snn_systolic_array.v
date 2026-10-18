`timescale 1ns/1ps
// =============================================================================
// snn_systolic_array : NxN weight-stationary SNN systolic array + LIF per row
//                      minimum-width / minimum-flop version
//
//   P[m][n][t] = sum_k  S[m][k][t] * W[k][n]        (S is 0/1 -> conditional add)
//   O[m][n]    = LIF( P[m][n][0..T-1], threshold )  (T-bit output spike train)
//
//   SPIKE TRAINS move TOP -> BOTTOM.  S[m][k] enters the top of COLUMN k (skewed k).
//   PARTIAL SUMS move LEFT -> RIGHT.  Row r carries T accumulators.
//   PE[row r][col c] holds W[k=c][n=r]  (transposed in the wiring).
//
//   Widths (DW=8, N=4, T=8):
//     psum after column c : DW + clog2(c+1)       -> 8 (comb), 9, 10, 10 bits
//     LIF membrane        : Q = DW+clog2(N)+clog2(T) = 13 bits   |m| <= T*N*128 = 4096
//     threshold           : Q-1 = 12 bits UNSIGNED (0..4095). Any threshold >= 4064
//                           already means "never fires" (max membrane = 8*4*127),
//                           so every non-negative threshold is covered by clamping.
//
//   Valid: in_valid (row m entering column 0) -> N-flop delay -> LIF row 0.
//          Row r+1's LIF launch = row r's lif_done (already exactly 1 cycle later),
//          so only N valid flops in total.
//
//   s_top[k*T +: T]     : spike train entering top of column k
//   spike_out[n*T +: T] : LIF output spike train of row n
//   out_valid[n]        : lif_done of row n
// =============================================================================
module snn_systolic_array #(parameter N = 4, DW = 8, T = 8,
                            Q    = DW + $clog2(N) + $clog2(T),   // derived, don't override
                            TH_W = Q - 1)                        // derived, don't override
(
    input  wire                  clk, rst_n,
    input  wire                  load_w,
    input  wire [N*N*DW-1:0]     w_flat,      // W[k][n] at [(k*N+n)*DW +: DW]
    input  wire [N*T-1:0]        s_top,
    input  wire                  in_valid,
    input  wire [TH_W-1:0]       threshold,   // unsigned
    output wire [N*T-1:0]        spike_out,
    output wire [N-1:0]          out_valid
);
    localparam PWM = DW + $clog2(N);           // widest psum (bus slot width)

    wire [T-1:0]     s_w [0:N][0:N-1];
    wire [T*PWM-1:0] p_w [0:N-1][0:N];

    // ---------------- valid: N flops ----------------
    reg  [N-1:0] v_sr;
    always @(posedge clk)
        if (!rst_n) v_sr <= {N{1'b0}};
        else        v_sr <= {v_sr[N-2:0], in_valid};

    wire [N-1:0] lif_go;
    assign lif_go[0] = v_sr[N-1];

    wire signed [Q-1:0] thr = {1'b0, threshold};

    genvar r, c, t;
    generate
        for (c = 0; c < N; c = c + 1) begin : edge_top
            assign s_w[0][c] = s_top[c*T +: T];
        end

        for (r = 1; r < N; r = r + 1) begin : vchain
            assign lif_go[r] = out_valid[r-1];
        end

        for (r = 0; r < N; r = r + 1) begin : row
            assign p_w[r][0] = {T*PWM{1'b0}};

            for (c = 0; c < N; c = c + 1) begin : col
                snn_pe #(.DW(DW), .T(T), .PWM(PWM),
                         .PIW(c == 0 ? DW : DW + $clog2(c)),
                         .POW(DW + $clog2(c + 1)),
                         .FIRST(c == 0), .PASS_S(r < N - 1)) pe (
                    .clk(clk), .rst_n(rst_n), .load_w(load_w),
                    .w_in(w_flat[(c*N + r)*DW +: DW]),
                    .s_in(s_w[r][c]),     .s_out(s_w[r+1][c]),
                    .psum_in(p_w[r][c]),  .psum_out(p_w[r][c+1]));
            end

            // ---------------- LIF neuron on the right edge ----------------
            wire signed [Q-1:0] lif_in [0:T-1];
            for (t = 0; t < T; t = t + 1) begin : unpack
                assign lif_in[t] = $signed(p_w[r][N][t*PWM +: PWM]);
            end

            lif_model #(.T(T), .Q(Q)) lif (
                .clk(clk), .rst(~rst_n), .result_val(lif_go[r]),
                .inputs(lif_in), .threshold(thr),
                .spike_out(spike_out[r*T +: T]), .lif_done(out_valid[r]));
        end
    endgenerate
endmodule