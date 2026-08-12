// mentha_pe_ws.sv
// Weight-stationary (WS) Processing Element for Mentha (packed SpGEMM/SpMM).
//
// Key correction vs. the naive version: a compressed row/column can carry
// MULTIPLE merged (index,value) entries (that's the entire point of the
// paper's row/column packing -- see Fig 8b, "4 in 1" etc). So a PE cannot
// just hold one A* scalar and one running psum scalar. It must:
//   1. Hold up to NUM_ABUF stationary A* (index,value) entries.
//   2. Hold a bank of up to NUM_CBUF in-flight C* (out_idx,value,valid)
//      partial-sum entries -- this is exactly the paper's "extra PE
//      buffers" (Fig. 9: SpGEMM needs 4/8/8/8 extra buffers for
//      threshold 2/3/4/8). Default here is 4, matching an 4x4 SpGEMM
//      array at threshold=4.
//
// Dataflow (WS variant of paper Fig. 5a/5b, generalized to multi-entry):
//   - A* stationary, loaded once per tile into the register file.
//   - B* flows top->bottom (index,value), pass-through unconditionally.
//   - C* flows left->right as a STREAM of (out_idx,value) partials
//     entering from the west edge and the same (possibly updated) stream
//     exits east. On top of the streamed-through entries, the PE injects/
//     merges its own local partial(s) computed this cycle.
//   - Each cycle: for the incoming B* (b_idx,b_val), the PE searches all
//     stationary A* entries whose idx == b_idx (non-zero). For EACH match
//     found (there may only sensibly be one under Mentha's packing
//     convention -- distinct entries in one packed row have distinct
//     indices -- but the search is written generally), it computes a
//     product and needs to accumulate it into the C* bank slot whose
//     out_idx matches the product's own destination out-index. Following
//     the paper (Fig 5a: "concatenate the indices of A* and B*, then match
//     the items in C*"), the destination out-index for a WS PE is the
//     stationary entry's own row-tag, i.e. a_out_idx paired with each
//     a_val -- so we store an out_idx alongside every stationary A* entry.
//   - If the matching out_idx already has a valid slot in the local C*
//     bank, accumulate into it. Otherwise allocate a free slot. If the
//     bank is full and no match/free slot exists, that's an overflow --
//     flagged, not silently dropped (the paper handles this by choosing
//     threshold to keep the max concurrent count <= NUM_CBUF).
//   - If b_idx==0 or no A* match, skip compute (only pass-through).
//   - The C* stream itself is always forwarded east untouched, entry by
//     entry, EXCEPT the local bank's own entries are merged into that
//     stream on evict (see mentha_array_ws for the streaming/eviction
//     policy) -- at the single-PE level here, the PE exposes its bank
//     for the array wrapper to read/merge/evict, keeping this PE's own
//     logic simple and combinational-clean.
//
// No memory/global-buffer/pre/post-processing modeling -- PE compute only.
// Offline packing (graph coloring) is assumed done off-chip / in a
// testbench-side Python/behavioral model, matching the paper's treatment.

module mentha_pe_ws #(
    parameter int IDX_W   = 8,     // index field width (row/col tag)
    parameter int VAL_W   = 32,    // value field width
    parameter int NUM_ABUF = 4,    // stationary A* entries this PE holds
    parameter int NUM_CBUF = 4     // in-flight C* accumulator slots ("extra PE buffers")
) (
    input  logic clk,
    input  logic rst_n,

    // --- A* load interface (stationary; loaded once per matrix tile) ---
    // Each stationary entry carries: a_idx (matched against incoming B* idx),
    // a_out_idx (this entry's own row-tag -> destination index in C*),
    // a_val (the weight value).
    input  logic                        a_load_en,
    input  logic [$clog2(NUM_ABUF)-1:0] a_load_slot,
    input  logic [IDX_W-1:0]            a_load_idx,
    input  logic [IDX_W-1:0]            a_load_out_idx,
    input  logic signed [VAL_W-1:0]     a_load_val,

    // --- B* flowing in vertically (top -> bottom), pass-through always ---
    input  logic [IDX_W-1:0]           b_in_idx,
    input  logic signed [VAL_W-1:0]    b_in_val,
    output logic [IDX_W-1:0]           b_out_idx,
    output logic signed [VAL_W-1:0]    b_out_val,

    // --- local C* accumulator bank, exposed for the array-level streamer ---
    // Flattened (packed-vector) ports: unpacked-array output ports do not
    // elaborate correctly in Icarus Verilog (same issue noted for the
    // original IS-mode design's edge I/O), so the bank is exposed as
    // flattened vectors instead of `logic [..] x [NUM_CBUF]` port arrays.
    output logic [NUM_CBUF*IDX_W-1:0]      cbuf_out_idx_flat,
    output logic signed [NUM_CBUF*VAL_W-1:0] cbuf_val_flat,
    output logic [NUM_CBUF-1:0]            cbuf_valid_flat,

    // array-level streamer can evict any subset of slots in one cycle
    // (after merging each into the eastbound C* stream) via a per-slot
    // evict vector -- avoids losing an eviction when a PE has more than
    // one valid bank entry drained in the same cycle.
    input  logic [NUM_CBUF-1:0]        cbuf_evict_flat,

    output logic                       overflow   // no free/matching slot when needed
);

    // ---------------- Stationary A* register file ----------------
    logic [IDX_W-1:0]        a_idx_q     [NUM_ABUF];
    logic [IDX_W-1:0]        a_out_idx_q [NUM_ABUF];
    logic signed [VAL_W-1:0] a_val_q     [NUM_ABUF];

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i = 0; i < NUM_ABUF; i++) begin
                a_idx_q[i]     <= '0;
                a_out_idx_q[i] <= '0;
                a_val_q[i]     <= '0;
            end
        end else if (a_load_en) begin
            a_idx_q[a_load_slot]     <= a_load_idx;
            a_out_idx_q[a_load_slot] <= a_load_out_idx;
            a_val_q[a_load_slot]     <= a_load_val;
        end
    end

    // Search stationary A* entries for one whose idx matches incoming B*'s idx.
    // idx==0 is the "no data" sentinel, per Mentha's packing convention.
    logic                    a_match_found;
    logic signed [VAL_W-1:0] a_match_val;
    logic [IDX_W-1:0]        a_match_out_idx;

    always_comb begin
        a_match_found   = 1'b0;
        a_match_val     = '0;
        a_match_out_idx = '0;
        for (int i = 0; i < NUM_ABUF; i++) begin
            if (a_idx_q[i] != '0 && a_idx_q[i] == b_in_idx) begin
                a_match_found   = 1'b1;
                a_match_val     = a_val_q[i];
                a_match_out_idx = a_out_idx_q[i];
            end
        end
    end

    logic do_compute;
    assign do_compute = (b_in_idx != '0) && a_match_found;

    logic signed [VAL_W-1:0] product;
    assign product = a_match_val * b_in_val;

    // internal unpacked storage for the C* bank; packed/unpacked at the
    // flattened port boundary (see comment on the ports above)
    logic [IDX_W-1:0]        cbuf_out_idx [NUM_CBUF];
    logic signed [VAL_W-1:0] cbuf_val     [NUM_CBUF];
    logic                    cbuf_valid   [NUM_CBUF];
    logic                    cbuf_evict   [NUM_CBUF];

    always_comb begin
        for (int i = 0; i < NUM_CBUF; i++) begin
            cbuf_out_idx_flat[i*IDX_W +: IDX_W] = cbuf_out_idx[i];
            cbuf_val_flat[i*VAL_W +: VAL_W]     = cbuf_val[i];
            cbuf_valid_flat[i]                  = cbuf_valid[i];
            cbuf_evict[i]                       = cbuf_evict_flat[i];
        end
    end

    // ---------------- Local C* accumulator bank ----------------
    // For each cycle where do_compute: find a bank slot whose out_idx
    // already equals a_match_out_idx (accumulate), else the first free
    // (invalid) slot (allocate). If neither exists -> overflow.
    logic                        slot_match_found;
    logic [$clog2(NUM_CBUF)-1:0] slot_match_idx;
    logic                        slot_free_found;
    logic [$clog2(NUM_CBUF)-1:0] slot_free_idx;

    always_comb begin
        slot_match_found = 1'b0;
        slot_match_idx   = '0;
        slot_free_found  = 1'b0;
        slot_free_idx    = '0;
        for (int i = 0; i < NUM_CBUF; i++) begin
            if (cbuf_valid[i] && cbuf_out_idx[i] == a_match_out_idx) begin
                slot_match_found = 1'b1;
                slot_match_idx   = i[$clog2(NUM_CBUF)-1:0];
            end
            if (!slot_free_found && !cbuf_valid[i]) begin
                slot_free_found = 1'b1;
                slot_free_idx   = i[$clog2(NUM_CBUF)-1:0];
            end
        end
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i = 0; i < NUM_CBUF; i++) begin
                cbuf_out_idx[i] <= '0;
                cbuf_val[i]     <= '0;
                cbuf_valid[i]   <= 1'b0;
            end
            overflow <= 1'b0;
        end else begin
            overflow <= 1'b0;

            // eviction (array streamer merged/consumed slots -> free them)
            for (int i = 0; i < NUM_CBUF; i++) begin
                if (cbuf_evict[i]) begin
                    cbuf_valid[i] <= 1'b0;
                end
            end

            if (do_compute) begin
                if (slot_match_found) begin
                    // accumulate into existing slot
                    cbuf_val[slot_match_idx] <= cbuf_val[slot_match_idx] + product;
                    // guard: if this same slot was just evicted this cycle,
                    // eviction (stream-out) and accumulate should not target
                    // the same slot in the same cycle by construction of the
                    // array-level control (evict only completed slots).
                end else if (slot_free_found) begin
                    cbuf_out_idx[slot_free_idx] <= a_match_out_idx;
                    cbuf_val[slot_free_idx]     <= product;
                    cbuf_valid[slot_free_idx]   <= 1'b1;
                end else begin
                    overflow <= 1'b1; // bank full, no match -> threshold too low for NUM_CBUF
                end
            end
        end
    end

    // B* always continues downward unchanged ("the path for transmitting
    // is non-stop" -- only compute is gated).
    assign b_out_idx = b_in_idx;
    assign b_out_val = b_in_val;

endmodule