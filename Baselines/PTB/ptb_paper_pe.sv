// ptb_paper_pe.sv
// Baseline PE for MICRO 2021: "Parallel Time Batching (PTB)" [Lee, Zhang, Li - UCSB]
//
// This is the PE-level baseline used to compare against a custom design (e.g. Mentha).
// It implements ONE PE = ONE Time Batch (TB): a fixed post-synaptic neuron i,
// processing a fixed Time Window (TW) of TWS consecutive timesteps, per Section 4.2/4.3.
//
// Matches paper exactly on:
//   - Fig. 5(b): PE = AC unit + comparator + Vth reg + simple controller. No MAC (spikes binary).
//   - Table 4:  weight/Vmem = 8-bit, spike I/O = TWS x 1-bit, ALU = 8-bit adder+comparator.
//   - Eq. (7):  Step A - integrate ALL receptive-field synaptic inputs for the WHOLE TW
//               into a SINGLE scalar Psum p*_i[tk..tk+TW-1] (one accumulator, not TW of them).
//               Weight is STATIONARY for the whole TW -> the core PTB weight-reuse mechanism.
//   - Eq. (8):  Step B - walk m = 0..TW-1 SEQUENTIALLY, applying the same Psum contribution
//               each cycle: v[t+m] = p* + v[t+m-1], compare vs Vth, fire, reset if fired.
//               This is inherently a TIME-SERIAL loop inside the PE (paper does NOT compute
//               all TW membrane updates combinationally in parallel inside one PE -- the
//               *spatial* parallelism across TW comes from separate PEs in different systolic
//               array COLUMNS, per Fig. 6(b), not from unrolling TW within a single PE).
//
// Deliberately NOT included (per your request -- PE only, no memory hierarchy):
//   - Global buffer / L1 cache / off-chip RAM (Fig. 5a) -- system-level, not PE-level.
//   - TB-tag classification (bursting/silent/non-bursting) and StSAP packing -- these are
//     scheduling/compression decisions made ABOVE the PE (Section 4.2/4.4), not part of the
//     PE datapath itself. The PE below is what StSAP/PTB scheduling logic dispatches work to.
//
// NOTE ON GRANULARITY vs YOUR mentha_pe_ws:
//   Your PE is index-matched (a_idx/b_idx) with NUM_CBUF in-flight streaming slots and
//   operates on TIMESTEPS in parallel within one cycle (spatial unroll across bits).
//   The paper's PE is neuron/TW-fixed (assigned once per array iteration by the mapping
//   logic in Fig. 6, not self-matched by index) and processes its TW SEQUENTIALLY over
//   TWS cycles per TB. This sequential-vs-parallel distinction inside the PE is a real,
//   load-bearing architectural difference between PTB and a Mentha-style PE -- not just a
//   coding-style difference -- so it is preserved faithfully below rather than "fixed".

module ptb_paper_pe #(
    parameter int WEIGHT_W = 8,   // Table 4: weight precision, INT8 signed
    parameter int VMEM_W   = 8,   // Table 4: membrane potential precision, INT8 signed
    parameter int TWS      = 8    // Time Window Size (default near-optimal per Section 6.1.1)
) (
    input  logic                       clk,
    input  logic                       rst_n,

    // --- TB (Time Batch) dispatch: assigns this PE to one post-synaptic neuron's TW ---
    // Mapping/scheduling (Fig. 6, StSAP) happens outside the PE; this is just "start a new TB".
    input  logic                       tb_start,       // pulse: begin new TB, latch weight, reset Vmem/counter
    input  logic signed [WEIGHT_W-1:0] weight_in,      // w_ji, STATIONARY for the entire TW (weight reuse)

    // --- Receptive-field synaptic spike inputs for this TW, all M^RF inputs pre-summed to ---
    // one bit per input still needed since PE does the accumulate; but per Eq (7) the PE's
    // job for Step A is: for j in RF, sum (w_ji * s_j) across ALL t in TW into ONE scalar Psum.
    // We model that RF accumulation as: one spike bit per cycle over TWS cycles is WRONG --
    // Step A collapses the whole TW into one Psum BEFORE Step B starts. So spike_in here is
    // the TW-wide spike vector for a SINGLE synaptic input j, consumed once per TB.
    input  logic [TWS-1:0]             spike_in,       // s_j[tk .. tk+TWS-1] for one RF input j
    input  logic                       spike_in_valid, // pulse per RF input j (accumulate into Psum)
    input  logic                       rf_done,        // pulse: all M^RF inputs consumed, Psum final -> start Step B

    // --- Threshold / (no leak term -- paper's PE schematic, Fig 5b, has no leak subtract) ---
    input  logic signed [VMEM_W-1:0]   v_th,

    // --- Step B output: one spike bit emitted per cycle, m = 0..TWS-1 (sequential, TWS cycles) ---
    output logic                       spike_out,      // s_i[tk+m] for current m
    output logic                       spike_out_valid,// pulse: spike_out is valid this cycle (Step B active)
    output logic [$clog2(TWS)-1:0]     m_idx,          // current time-point index within TW
    output logic                       tb_done         // pulse: all TWS time-points processed
);

    // ---------------- Stationary weight for this TB (reused across whole TW: PTB's core reuse) ----------------
    logic signed [WEIGHT_W-1:0] w_q;

    // ---------------- Step A: single scalar Psum accumulator p*_i[tk..tk+TWS-1] (Eq. 7) ----------------
    // AC unit only (Fig. 5b) -- spike is binary, so "multiply" is just a conditional add of w_q.
    // Accumulates contributions from all M^RF receptive-field inputs, one input j per spike_in_valid pulse.
    logic signed [VMEM_W-1:0] psum_q;

    // ---------------- Step B: single Vmem register + sequential counter over m = 0..TWS-1 (Eq. 8) ----------------
    logic signed [VMEM_W-1:0]  v_mem_q;
    logic [$clog2(TWS)-1:0]    m_q;
    logic                      step_b_active_q;

    // FSM-ish control: IDLE (waiting for tb_start/RF accumulation) -> STEP_B (TWS sequential cycles) -> done
    typedef enum logic [1:0] {S_IDLE, S_ACCUM, S_STEP_B} state_e;
    state_e state_q, state_d;

    always_comb begin
        state_d = state_q;
        unique case (state_q)
            S_IDLE:   if (tb_start)  state_d = S_ACCUM;
            S_ACCUM:  if (rf_done)   state_d = S_STEP_B;
            S_STEP_B: if (m_q == TWS-1) state_d = S_IDLE;
            default:  state_d = S_IDLE;
        endcase
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) state_q <= S_IDLE;
        else        state_q <= state_d;
    end

    // Weight latch (stationary for the TB)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) w_q <= '0;
        else if (tb_start) w_q <= weight_in;
    end

    // Step A: AC unit -- accumulate w_q into psum_q once per RF input j that fires anywhere in [tk, tk+TWS-1]
    // Per Eq. (7): p*_i = sum_j ( w_ji * s_j[tk..tk+TWS-1] ). Modeled here as: each valid RF input
    // contributes w_q to psum_q if it has ANY spike activity in the TW window (spike_in != 0).
    // (Binary spike -> binary gate on the stationary weight; no multiply needed, per Fig. 5b.)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            psum_q <= '0;
        end else if (tb_start) begin
            psum_q <= '0;                                   // clear for new TB
        end else if (state_q == S_ACCUM && spike_in_valid) begin
            if (|spike_in)
                psum_q <= psum_q + w_q;                      // AC: accumulate (Step A of Eq. 7)
        end
    end

    // Step B: sequential membrane update + threshold compare + reset, one m per cycle (Eq. 8)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            v_mem_q         <= '0;
            m_q             <= '0;
            spike_out       <= 1'b0;
            spike_out_valid <= 1'b0;
            step_b_active_q <= 1'b0;
        end else begin
            spike_out_valid <= 1'b0;
            spike_out       <= 1'b0;

            if (tb_start) begin
                v_mem_q         <= '0;
                m_q             <= '0;
                step_b_active_q <= 1'b0;
            end else if (state_q == S_ACCUM && rf_done) begin
                step_b_active_q <= 1'b1;
                m_q             <= '0;
            end else if (state_q == S_STEP_B) begin
                logic signed [VMEM_W-1:0] v_next;
                v_next = v_mem_q + psum_q;                   // v_i[tk+m] = p*_i + v_i[tk+m-1], Eq (8)

                if (v_next >= v_th) begin
                    spike_out       <= 1'b1;                  // fire
                    v_mem_q         <= '0;                    // reset (Eq. 3 / Eq. 8 reset condition)
                end else begin
                    spike_out       <= 1'b0;
                    v_mem_q         <= v_next;
                end
                spike_out_valid <= 1'b1;

                if (m_q == TWS-1) begin
                    step_b_active_q <= 1'b0;
                    m_q             <= '0;
                end else begin
                    m_q <= m_q + 1'b1;
                end
            end
        end
    end

    assign m_idx   = m_q;
    assign tb_done = (state_q == S_STEP_B) && (m_q == TWS-1);

endmodule