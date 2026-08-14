// sato_binary_search_tree.sv
// Binary Search-Adder Tree for DAC 2022 Paper: "SATO: Spiking Neural Network Acceleration"
// Ref: Fangxin Liu et al. (SJTU) - DAC 2022 - Section 3.4 & Fig. 6
//
// Key Concepts:
// - Receives potential increments (\Delta V_mem) for T=8 time steps from PE array leaf nodes.
// - Performs binary search over time steps to immediately determine the time step where
//   accumulated potential exceeds threshold V_th, emitting the spike train with O(log T) cycles.

module sato_binary_search_tree #(
    parameter int ACC_W    = 16,
    parameter int TIMESTEPS = 8
) (
    input  logic                     clk,
    input  logic                     rst_n,

    // --- Inputs from PE Array Leaf Nodes ---
    input  logic signed [ACC_W-1:0]  v_inc_in [TIMESTEPS], // Increments for time steps t=0..7
    input  logic signed [ACC_W-1:0]  v_th,                // Spiking threshold

    // --- Control & Search Trigger ---
    input  logic                     start_search,

    // --- Spike Train Output ---
    output logic [TIMESTEPS-1:0]     spike_train_out,     // Emitted output spike train across time steps
    output logic                     search_done          // High when binary search completes
);

    // Cumulative sums across time steps: V_cum[t] = \sum_{i=0}^{t} v_inc_in[i]
    logic signed [ACC_W-1:0] v_cum [TIMESTEPS];

    always_comb begin
        v_cum[0] = v_inc_in[0];
        for (int t = 1; t < TIMESTEPS; t++) begin
            v_cum[t] = v_cum[t-1] + v_inc_in[t];
        end
    end

    // Binary Search Logic over T=8 time steps
    typedef enum logic [1:0] {IDLE, SEARCH, DONE} state_t;
    state_t state_q;

    logic [2:0] low_q, high_q, mid_q;
    logic [TIMESTEPS-1:0] spike_reg;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state_q         <= IDLE;
            search_done     <= 1'b0;
            spike_train_out <= '0;
            low_q           <= '0;
            high_q          <= '0;
            mid_q           <= '0;
            spike_reg       <= '0;
        end else begin
            case (state_q)
                IDLE: begin
                    search_done <= 1'b0;
                    if (start_search) begin
                        low_q     <= 3'd0;
                        high_q    <= 3'd7;
                        mid_q     <= 3'd3;
                        spike_reg <= '0;
                        state_q   <= SEARCH;
                    end
                end

                SEARCH: begin
                    // Evaluate threshold at mid time step
                    if (v_cum[mid_q] >= v_th) begin
                        // Fired at or before mid_q -> search lower half
                        spike_reg[mid_q] <= 1'b1;
                        if (mid_q == low_q) begin
                            state_q <= DONE;
                        end else begin
                            high_q <= mid_q;
                            mid_q  <= (low_q + mid_q) >> 1;
                        end
                    end else begin
                        // Did not fire -> search upper half
                        if (mid_q == high_q || mid_q == 3'd7) begin
                            state_q <= DONE;
                        end else begin
                            low_q <= mid_q + 1'b1;
                            mid_q <= (mid_q + 1'b1 + high_q) >> 1;
                        end
                    end
                end

                DONE: begin
                    spike_train_out <= spike_reg;
                    search_done     <= 1'b1;
                    state_q         <= IDLE;
                end

                default: state_q <= IDLE;
            endcase
        end
    end

endmodule
