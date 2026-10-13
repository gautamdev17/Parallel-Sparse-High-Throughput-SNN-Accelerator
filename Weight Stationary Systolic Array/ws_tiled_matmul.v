// =============================================================================
// ws_tiled_matmul : C[MxN] = A[MxK] x B[KxN] for ARBITRARY M, K, N.
//                   Hardware tiling controller around ws_systolic_array.
//                   (ws_pe.v / ws_systolic_array.v are used unchanged.)
//
//   Memory layout (all ROW-MAJOR, no pre-tiling):
//       A[m][k] at a_base + m*K + k      int8
//       B[k][n] at b_base + k*N + n      int8
//       C[m][n] at c_base + m*N + n      int32  (raw accumulators)
//
//   Interface: give dim_m/dim_k/dim_n + base addresses, pulse `start`,
//              wait for `done`.
//
//   Memory ports (ARR parallel ports each, synchronous read = 1 cycle latency):
//       A : port k reads the activation for array column k    (banked by k mod ARR)
//       B : port n reads the weight for array row n            (banked by n mod ARR)
//       C : port n writes output column n                      (banked by n mod ARR)
//
//   Loop order (weight-stationary: each loaded weight tile is reused for
//   every row of the current M-block):
//
//       for mt in M-blocks of MT rows          // bounds the accumulator size
//         for nt in N-tiles of ARR columns
//           for kt in K-tiles of ARR           // innermost: partial sums accumulate
//             WLOAD   : read ARR x ARR weights of B tile (kt,nt) into a staging reg
//             WPULSE  : load_w for 1 cycle  -> weights now sit in the PEs
//             STREAM  : R skewed rows of A  -> y_right -> acc[n][m] (+=)
//           WB       : write the finished MT x ARR block of C to memory
//
//   Edges (K or N not multiple of ARR, M not multiple of MT) are handled by
//   masking: out-of-range reads return 0, out-of-range writes are suppressed.
// =============================================================================
module ws_tiled_matmul #(
    parameter ARR   = 4,      // systolic array is ARR x ARR
    parameter DW    = 8,      // activation / weight width
    parameter AW    = 24,     // per-tile partial-sum width inside the array
    parameter ACCW  = 32,     // accumulator / output width
    parameter MT    = 16,     // rows per M-block (accumulator depth)
    parameter ADDRW = 20,
    parameter DIMW  = 16
) (
    input  wire                  clk, rst_n,
    // ---- descriptor ----
    input  wire                  start,
    input  wire [DIMW-1:0]       dim_m, dim_k, dim_n,
    input  wire [ADDRW-1:0]      a_base, b_base, c_base,
    output reg                   done,           // 1-cycle pulse, C fully written
    output wire                  busy,
    // ---- A memory (read) ----
    output reg  [ARR*ADDRW-1:0]  a_raddr,
    input  wire [ARR*DW-1:0]     a_rdata,
    // ---- B memory (read) ----
    output reg  [ARR*ADDRW-1:0]  b_raddr,
    input  wire [ARR*DW-1:0]     b_rdata,
    // ---- C memory (write) ----
    output reg  [ARR-1:0]        c_we,
    output reg  [ARR*ADDRW-1:0]  c_waddr,
    output reg  [ARR*ACCW-1:0]   c_wdata
);
    localparam S_IDLE = 3'd0, S_WLOAD = 3'd1, S_WPULSE = 3'd2,
               S_STREAM = 3'd3, S_WB = 3'd4, S_FLUSH = 3'd5;

    reg [2:0]       state;
    reg [DIMW-1:0]  m_dim, k_dim, n_dim;
    reg [ADDRW-1:0] a_b, b_b, c_b;
    reg [DIMW-1:0]  mt, nt, kt;                 // current tile indices
    reg [DIMW-1:0]  num_mt, num_nt, num_kt;     // tile counts
    reg [DIMW-1:0]  cnt;                        // cycle counter inside a state

    assign busy = (state != S_IDLE);

    // ---------------- tile geometry ----------------
    wire [31:0] row0 = mt * MT;                 // first row of this M-block
    wire [31:0] k0   = kt * ARR;                // first k of this K-tile
    wire [31:0] n0   = nt * ARR;                // first n of this N-tile
    wire [31:0] rem  = m_dim - row0;
    wire [31:0] R    = (rem < MT) ? rem : MT;   // rows in this M-block

    // ---------------- the (unchanged) systolic array ----------------
    reg  [ARR*ARR*DW-1:0] w_stage;              // staged weight tile, B[k][n] at (k*ARR+n)
    reg  [ARR-1:0]        a_valid_q, b_valid_q; // read-data valid masks (1 cycle after address)
    reg  [ARR-1:0]        a_valid_d, b_valid_d;
    wire [ARR*DW-1:0]     a_top;
    wire [ARR*AW-1:0]     y_right;
    wire                  load_w = (state == S_WPULSE);

    ws_systolic_array #(.N(ARR), .DW(DW), .AW(AW)) u_array (
        .clk(clk), .rst_n(rst_n), .load_w(load_w),
        .w_flat(w_stage), .a_top(a_top), .y_right(y_right));

    wire signed [AW-1:0] y_lane [0:ARR-1];
    genvar g;
    generate
        for (g = 0; g < ARR; g = g + 1) begin : lanes
            assign a_top[g*DW +: DW] = a_valid_q[g] ? a_rdata[g*DW +: DW] : {DW{1'b0}};
            assign y_lane[g]         = y_right[g*AW +: AW];
        end
    endgenerate

    // ---------------- accumulators: one bank per output column ----------------
    reg signed [ACCW-1:0] acc [0:ARR-1][0:MT-1];

    // ---------------- address generation (combinational) ----------------
    integer ci_i, kk, nn, mm, Rc, k0c, n0c, r0c;
    reg [31:0] addr32;
    always @* begin
        a_raddr = {ARR*ADDRW{1'b0}};
        b_raddr = {ARR*ADDRW{1'b0}};
        a_valid_d = {ARR{1'b0}};
        b_valid_d = {ARR{1'b0}};
        Rc = R; k0c = k0; n0c = n0; r0c = row0; ci_i = cnt;

        if (state == S_STREAM) begin
            // array column kk gets A[row0 + (cnt-kk)][k0+kk]   (column kk skewed by kk cycles)
            for (kk = 0; kk < ARR; kk = kk + 1) begin
                mm = ci_i - kk;
                if (mm >= 0 && mm < Rc && (k0c + kk) < k_dim) begin
                    addr32 = a_b + (r0c + mm) * k_dim + k0c + kk;
                    a_raddr[kk*ADDRW +: ADDRW] = addr32[ADDRW-1:0];
                    a_valid_d[kk] = 1'b1;
                end
            end
        end
        if (state == S_WLOAD && ci_i < ARR) begin
            // row (k0+cnt) of the weight tile; lane nn = column n0+nn
            for (nn = 0; nn < ARR; nn = nn + 1) begin
                if ((k0c + ci_i) < k_dim && (n0c + nn) < n_dim) begin
                    addr32 = b_b + (k0c + ci_i) * n_dim + n0c + nn;
                    b_raddr[nn*ADDRW +: ADDRW] = addr32[ADDRW-1:0];
                    b_valid_d[nn] = 1'b1;
                end
            end
        end
    end

    // ---------------- FSM ----------------
    integer n, mq, cs, Ri;
    always @(posedge clk) begin
        done      <= 1'b0;
        c_we      <= {ARR{1'b0}};
        a_valid_q <= a_valid_d;
        b_valid_q <= b_valid_d;
        Ri = R;

        if (!rst_n) begin
            state <= S_IDLE; cnt <= 0; mt <= 0; nt <= 0; kt <= 0;
        end else begin
            case (state)
            // ------------------------------------------------------------
            S_IDLE: if (start) begin
                m_dim <= dim_m; k_dim <= dim_k; n_dim <= dim_n;
                a_b <= a_base;  b_b <= b_base;  c_b <= c_base;
                num_mt <= (dim_m + MT  - 1) / MT;
                num_nt <= (dim_n + ARR - 1) / ARR;
                num_kt <= (dim_k + ARR - 1) / ARR;
                mt <= 0; nt <= 0; kt <= 0; cnt <= 0;
                state <= S_WLOAD;
            end

            // ------------------------------------------------------------
            // read the ARR x ARR weight tile, one row (k) per cycle
            S_WLOAD: begin
                if (cnt >= 1)                     // data for row k = cnt-1 is here
                    for (n = 0; n < ARR; n = n + 1)
                        w_stage[((cnt-1)*ARR + n)*DW +: DW] <=
                            b_valid_q[n] ? b_rdata[n*DW +: DW] : {DW{1'b0}};
                if (cnt == ARR) state <= S_WPULSE;
                else            cnt   <= cnt + 1;
            end

            // load_w is high this cycle (combinational) -> weights latch into PEs
            S_WPULSE: begin
                cnt   <= 0;
                state <= S_STREAM;
            end

            // ------------------------------------------------------------
            // stream R skewed rows; collect and accumulate the outputs.
            // address cycle = cnt, array input = cnt+1, y_right valid = cnt+2
            S_STREAM: begin
                cs = cnt - 2;                          // logical injection index now at y_right
                if (cnt >= 2)
                    for (n = 0; n < ARR; n = n + 1) begin
                        mq = cs - (ARR-1) - n;         // output row delivered by array row n
                        if (mq >= 0 && mq < Ri) begin
                            if (kt == 0) acc[n][mq] <= y_lane[n];
                            else         acc[n][mq] <= acc[n][mq] + y_lane[n];
                        end
                    end
                if (cnt == Ri + 2*ARR - 1) begin
                    cnt <= 0;
                    if (kt + 1 < num_kt) begin kt <= kt + 1; state <= S_WLOAD; end
                    else                 state <= S_WB;
                end else
                    cnt <= cnt + 1;
            end

            // ------------------------------------------------------------
            // write one finished row (ARR outputs) of the block per cycle
            S_WB: begin
                for (n = 0; n < ARR; n = n + 1) begin
                    c_we[n] <= ((n0 + n) < n_dim);
                    c_waddr[n*ADDRW +: ADDRW] <= c_b + (row0 + cnt) * n_dim + n0 + n;
                    c_wdata[n*ACCW +: ACCW]   <= acc[n][cnt];
                end
                if (cnt == Ri - 1) begin
                    cnt <= 0; kt <= 0;
                    if (nt + 1 < num_nt)      begin nt <= nt + 1; state <= S_WLOAD; end
                    else begin
                        nt <= 0;
                        if (mt + 1 < num_mt)  begin mt <= mt + 1; state <= S_WLOAD; end
                        else                  state <= S_FLUSH;
                    end
                end else
                    cnt <= cnt + 1;
            end

            // last write is on the ports this cycle; `done` rises after it commits
            S_FLUSH: begin
                done  <= 1'b1;
                state <= S_IDLE;
            end

            default: state <= S_IDLE;
            endcase
        end
    end
endmodule