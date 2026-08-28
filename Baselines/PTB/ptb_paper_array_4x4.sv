// ptb_paper_array_4x4.sv
// Baseline 4x4 systolic array for MICRO 2021: "Parallel Time Batching (PTB)" [Lee, Zhang, Li - UCSB]
//
// Direct equivalent of mentha_array_ws_4x4.sv, built from ptb_paper_pe.sv, following the
// paper's actual PE-to-array mapping rule (Section 4.3.1, Fig. 6b):
//
//   "Each row of the array is utilized to compute output activation of a single post-synaptic
//    neuron for different TWs with multiple time-batched inputs (TBs). PEs in each column
//    process the same TW but for different post-synaptic neurons."
//
//   => ROWS = distinct post-synaptic neurons (each row gets its own weight, stationary).
//   => COLS = distinct Time Windows (each column processes a different TW slice in parallel).
//
// This gives PTB's actual claimed parallelism: N_ROWS neurons x N_COLS time-windows computed
// simultaneously, with each individual PE still doing its TWS-cycle sequential Step B internally
// (see ptb_paper_pe.sv) -- i.e. PTB's "parallel in time" claim is SPATIAL (across array columns),
// not a within-PE unroll. This is the key structural contrast vs. Mentha's index-matched,
// streaming-slot PE that parallelizes across TIMESTEPS within a single PE.
//
// No memory hierarchy modeled here (off-chip RAM / global buffer / L1, Fig. 5a) -- PE/array
// compute fabric only, per your request.

module ptb_paper_array_4x4 #(
    parameter int WEIGHT_W = 8,     // Table 4: INT8 signed weight
    parameter int VMEM_W   = 8,     // Table 4: INT8 signed membrane potential
    parameter int TWS      = 8,     // Time Window Size (near-optimal default, Section 6.1.1)
    parameter int ROWS     = 4,     // post-synaptic neurons processed in parallel
    parameter int COLS     = 4      // time windows (TWs) processed in parallel
) (
    input  logic clk,
    input  logic rst_n,

    // --- Per-row TB dispatch: start a new Time Batch on every PE in row r simultaneously ---
    // (All COLS PEs in a row share tb_start/weight since Fig 6b ties one weight per row per TW-column set;
    //  in practice different columns hold the SAME post-synaptic neuron's weight for DIFFERENT TWs --
    //  weight is neuron-specific, not TW-specific, so it is broadcast across a row.)
    input  logic [ROWS-1:0]                     tb_start_row,
    input  logic signed [ROWS*WEIGHT_W-1:0]     weight_row_flat,   // w_ji per row (neuron), reused across TW cols
    input  logic signed [ROWS*VMEM_W-1:0]       v_th_row_flat,     // V_th per row (neuron)

    // --- Per-PE RF spike inputs: one RF input j delivered per (row, col) per cycle ---
    // North edge feed: each column c carries synaptic spike data for TW slice c, for whichever
    // row/neuron is currently being accumulated (Step A, Eq. 7). Since RF accumulation happens
    // BEFORE Step B, this is presented once per RF input over multiple spike_in_valid pulses.
    input  logic [ROWS*COLS*TWS-1:0]            spike_in_flat,
    input  logic [ROWS*COLS-1:0]                spike_in_valid_flat,
    input  logic [ROWS*COLS-1:0]                rf_done_flat,      // per-PE: RF accumulation complete -> Step B

    // --- Per-PE Step B outputs ---
    output logic [ROWS*COLS-1:0]                spike_out_flat,
    output logic [ROWS*COLS-1:0]                spike_out_valid_flat,
    output logic [ROWS*COLS*$clog2(TWS)-1:0]    m_idx_flat,
    output logic [ROWS*COLS-1:0]                tb_done_flat
);

    genvar r, c;
    generate
        for (r = 0; r < ROWS; r++) begin : g_row
            for (c = 0; c < COLS; c++) begin : g_col
                ptb_paper_pe #(
                    .WEIGHT_W (WEIGHT_W),
                    .VMEM_W   (VMEM_W),
                    .TWS      (TWS)
                ) u_pe (
                    .clk             (clk),
                    .rst_n           (rst_n),

                    // Weight/threshold/tb_start broadcast per row (same neuron across TW columns)
                    .tb_start        (tb_start_row[r]),
                    .weight_in       (weight_row_flat[r*WEIGHT_W +: WEIGHT_W]),
                    .v_th            (v_th_row_flat[r*VMEM_W +: VMEM_W]),

                    // Per-(row,col) RF spike delivery -- column c holds this neuron's TW-c slice
                    .spike_in        (spike_in_flat[(r*COLS + c)*TWS +: TWS]),
                    .spike_in_valid  (spike_in_valid_flat[r*COLS + c]),
                    .rf_done         (rf_done_flat[r*COLS + c]),

                    .spike_out       (spike_out_flat[r*COLS + c]),
                    .spike_out_valid (spike_out_valid_flat[r*COLS + c]),
                    .m_idx           (m_idx_flat[(r*COLS + c)*$clog2(TWS) +: $clog2(TWS)]),
                    .tb_done         (tb_done_flat[r*COLS + c])
                );
            end
        end
    endgenerate

endmodule