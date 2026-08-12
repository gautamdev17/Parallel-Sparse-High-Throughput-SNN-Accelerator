// mentha_array_ws_4x4.sv
// 4x4 weight-stationary Mentha PE array (SpGEMM-capable, threshold-4 sizing).
//
// A* stationary per-PE (loaded once, multi-entry per PE -- NUM_ABUF).
// B* flows top-to-bottom within each column, pass-through always.
// Each PE accumulates local partials into its own C* bank (NUM_CBUF slots
// per PE -- default 4, matching the paper's Fig. 9 SpGEMM "extra PE
// buffers" count at threshold=4).
//
// C* OUTPUT MODEL:
// Mentha's C* here is a small *set* of (out_idx,value) pairs per row,
// because packing can merge several output rows' worth of partials
// through the same physical PE row. Rather than serializing an in-flight
// westward psum bus every cycle (the paper's Fig. 5a/5c wire is a
// simplification for the single-slot OS/IS case), each PE accumulates
// locally into its own bank while B* streams through (non-stop, per the
// paper), and a separate drain phase performs a left-to-right per-row
// merge of all PE banks into a row output set. This keeps the B*/A* flow
// path never stalled by accumulation, matching the paper's emphasis that
// "the path for transmitting is non-stop."
//
// All module ports use flattened packed vectors for edge/bank I/O
// (unpacked-array ports do not propagate correctly at elaboration in
// Icarus Verilog -- same issue as the original IS-mode design's notes).
// Internal (non-port) unpacked arrays are used freely.
//
// No global buffer / HBM / pre-post-processing modules -- compute array only.

module mentha_array_ws_4x4 #(
    parameter int IDX_W    = 8,
    parameter int VAL_W    = 32,
    parameter int NUM_ABUF = 4,
    parameter int NUM_CBUF = 4,     // per-PE bank size (SpGEMM, threshold=4)
    parameter int ROWS     = 4,
    parameter int COLS     = 4,
    // max simultaneous distinct out_idx values a single row's drain can
    // hold; safe upper bound is COLS*NUM_CBUF (worst case: every PE bank
    // slot in the row maps to a distinct out_idx).
    parameter int ROW_OUT_CAP = COLS * NUM_CBUF
) (
    input  logic clk,
    input  logic rst_n,

    // A* load: preload a single PE's stationary register file slot
    input  logic                        a_load_en,
    input  logic [$clog2(ROWS)-1:0]     a_load_row,
    input  logic [$clog2(COLS)-1:0]     a_load_col,
    input  logic [$clog2(NUM_ABUF)-1:0] a_load_slot,
    input  logic [IDX_W-1:0]            a_load_idx,
    input  logic [IDX_W-1:0]            a_load_out_idx,
    input  logic signed [VAL_W-1:0]     a_load_val,

    // B* enters from the top edge, one stream per column
    input  logic [COLS*IDX_W-1:0]       b_edge_idx_flat,
    input  logic [COLS*VAL_W-1:0]       b_edge_val_flat,

    // B* exiting the bottom edge (unchanged pass-through, per paper)
    output logic [COLS*IDX_W-1:0]       b_out_idx_flat,
    output logic [COLS*VAL_W-1:0]       b_out_val_flat,

    // Drain control: pulse to read out each row's merged C* set this cycle
    // and evict every PE bank slot that was folded into it.
    input  logic                        drain_en,

    // Flattened merged C* output, ROW_OUT_CAP entries per row.
    // c_out_valid_flat[r*ROW_OUT_CAP+k]==0 marks an unused slot.
    output logic [ROWS*ROW_OUT_CAP*IDX_W-1:0]        c_out_idx_flat,
    output logic signed [ROWS*ROW_OUT_CAP*VAL_W-1:0] c_out_val_flat,
    output logic [ROWS*ROW_OUT_CAP-1:0]              c_out_valid_flat,

    output logic [ROWS*COLS-1:0]        overflow_flat
);

    // b_wire[r][c]: B* entering PE(r,c) from above (b_wire[0][c] = top edge)
    logic [IDX_W-1:0]        b_wire_idx [ROWS+1][COLS];
    logic signed [VAL_W-1:0] b_wire_val [ROWS+1][COLS];

    // Per-PE bank, flattened at the port boundary, unpacked internally
    logic [NUM_CBUF*IDX_W-1:0]        pe_cbuf_out_idx_flat [ROWS][COLS];
    logic signed [NUM_CBUF*VAL_W-1:0] pe_cbuf_val_flat     [ROWS][COLS];
    logic [NUM_CBUF-1:0]              pe_cbuf_valid_flat   [ROWS][COLS];
    logic [NUM_CBUF-1:0]              pe_evict_flat        [ROWS][COLS];

    genvar r, c;
    generate
        for (c = 0; c < COLS; c++) begin : g_edge_b
            assign b_wire_idx[0][c] = b_edge_idx_flat[c*IDX_W +: IDX_W];
            assign b_wire_val[0][c] = b_edge_val_flat[c*VAL_W +: VAL_W];
        end

        for (r = 0; r < ROWS; r++) begin : g_row
            for (c = 0; c < COLS; c++) begin : g_col
                mentha_pe_ws #(
                    .IDX_W    (IDX_W),
                    .VAL_W    (VAL_W),
                    .NUM_ABUF (NUM_ABUF),
                    .NUM_CBUF (NUM_CBUF)
                ) u_pe (
                    .clk                (clk),
                    .rst_n              (rst_n),
                    .a_load_en          (a_load_en && (a_load_row == r) && (a_load_col == c)),
                    .a_load_slot        (a_load_slot),
                    .a_load_idx         (a_load_idx),
                    .a_load_out_idx     (a_load_out_idx),
                    .a_load_val         (a_load_val),
                    .b_in_idx           (b_wire_idx[r][c]),
                    .b_in_val           (b_wire_val[r][c]),
                    .b_out_idx          (b_wire_idx[r+1][c]),
                    .b_out_val          (b_wire_val[r+1][c]),
                    .cbuf_out_idx_flat  (pe_cbuf_out_idx_flat[r][c]),
                    .cbuf_val_flat      (pe_cbuf_val_flat[r][c]),
                    .cbuf_valid_flat    (pe_cbuf_valid_flat[r][c]),
                    .cbuf_evict_flat    (pe_evict_flat[r][c]),
                    .overflow           (overflow_flat[r*COLS+c])
                );
            end
        end

        for (c = 0; c < COLS; c++) begin : g_out_b
            assign b_out_idx_flat[c*IDX_W +: IDX_W] = b_wire_idx[ROWS][c];
            assign b_out_val_flat[c*VAL_W +: VAL_W] = b_wire_val[ROWS][c];
        end
    endgenerate

    // ---------------- Row drain / merge network ----------------
    // On drain_en, for each row: walk PE(r,0)..PE(r,COLS-1) left to right,
    // merge every valid bank entry into a running (out_idx,val) set of
    // width ROW_OUT_CAP, matching-and-accumulating on out_idx collision.
    // Also pulse eviction on every bank slot consumed this cycle.
    integer rr, cc, s, k;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            c_out_idx_flat   <= '0;
            c_out_val_flat   <= '0;
            c_out_valid_flat <= '0;
            for (rr = 0; rr < ROWS; rr++)
                for (cc = 0; cc < COLS; cc++)
                    pe_evict_flat[rr][cc] <= '0;
        end else begin
            for (rr = 0; rr < ROWS; rr++)
                for (cc = 0; cc < COLS; cc++)
                    pe_evict_flat[rr][cc] <= '0;

            if (drain_en) begin
                for (rr = 0; rr < ROWS; rr++) begin : row_drain
                    // local working copy of this row's merged set
                    reg [IDX_W-1:0]        w_idx   [0:ROW_OUT_CAP-1];
                    reg signed [VAL_W-1:0] w_val   [0:ROW_OUT_CAP-1];
                    reg                    w_valid [0:ROW_OUT_CAP-1];
                    reg                    found;
                    reg [IDX_W-1:0]        this_idx;
                    reg signed [VAL_W-1:0] this_val;

                    for (k = 0; k < ROW_OUT_CAP; k = k + 1) begin
                        w_idx[k]   = '0;
                        w_val[k]   = '0;
                        w_valid[k] = 1'b0;
                    end

                    for (cc = 0; cc < COLS; cc = cc + 1) begin
                        for (s = 0; s < NUM_CBUF; s = s + 1) begin
                            if (pe_cbuf_valid_flat[rr][cc][s]) begin
                                this_idx = pe_cbuf_out_idx_flat[rr][cc][s*IDX_W +: IDX_W];
                                this_val = pe_cbuf_val_flat[rr][cc][s*VAL_W +: VAL_W];
                                found    = 1'b0;

                                for (k = 0; k < ROW_OUT_CAP; k = k + 1) begin
                                    if (!found && w_valid[k] && w_idx[k] == this_idx) begin
                                        w_val[k] = w_val[k] + this_val;
                                        found    = 1'b1;
                                    end
                                end
                                if (!found) begin
                                    for (k = 0; k < ROW_OUT_CAP; k = k + 1) begin
                                        if (!found && !w_valid[k]) begin
                                            w_idx[k]   = this_idx;
                                            w_val[k]   = this_val;
                                            w_valid[k] = 1'b1;
                                            found      = 1'b1;
                                        end
                                    end
                                end

                                // fold complete -> evict this PE bank slot
                                pe_evict_flat[rr][cc][s] <= 1'b1;
                            end
                        end
                    end

                    for (k = 0; k < ROW_OUT_CAP; k = k + 1) begin
                        c_out_idx_flat[(rr*ROW_OUT_CAP+k)*IDX_W +: IDX_W]   <= w_idx[k];
                        c_out_val_flat[(rr*ROW_OUT_CAP+k)*VAL_W +: VAL_W]   <= w_val[k];
                        c_out_valid_flat[rr*ROW_OUT_CAP+k]                 <= w_valid[k];
                    end
                end
            end
        end
    end

endmodule