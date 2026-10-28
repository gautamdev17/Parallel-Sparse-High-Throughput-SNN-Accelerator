// tsweep_synth copy: TIMESTEPS-wide flattened result bus instead of 8 hard-coded ports (see CHANGES.md)
`timescale 1ns/1ps

// FIX: Port declarations used clog2(BITMASK_WIDTH) directly in the port list,
//      which is illegal in Verilog-2001 (functions cannot be called in the
//      port width expression of a module header).
//      Resolution: declare a localparam ADDR_BITS = $clog2(BITMASK_WIDTH) and
//      use that in all port and internal signal declarations.
//      $display calls are left intact (they are warnings only, not errors).

module accumulator_correction #(
    parameter TIMESTEPS            = 8,
    parameter WEIGHT_WIDTH         = 8,
    parameter PSEUDO_ACC_WIDTH     = 13,
    parameter CORRECTION_ACC_WIDTH = 12,
    parameter ADDR_WIDTH           = 8,
    parameter BITMASK_WIDTH        = 128
)(
    input wire clk,
    input wire rst,

    // Fast prefix (Fiber-B)
    // FIX: use $clog2(BITMASK_WIDTH) via localparam below; ports use the param directly
    input wire [$clog2(BITMASK_WIDTH)-1:0] matched_position,
    input wire [WEIGHT_WIDTH-1:0] matched_weight,
    input wire fast_valid,

    // Laggy prefix (Fiber-A)
    input wire [$clog2(BITMASK_WIDTH)-1:0] current_position,
    input wire [WEIGHT_WIDTH-1:0] current_weight,
    input wire [$clog2(BITMASK_WIDTH)-1:0] slow_offset,
    input wire slow_valid,
    input wire laggy_done,

    // Fibre-A bitmap per timestep
    input  wire [TIMESTEPS-1:0] fibre_a_data,
    input  wire                 fibre_a_valid,
    output reg  [ADDR_WIDTH-1:0] fibre_a_addr,
    output reg                  fibre_a_read_en,

    // Controls
    output reg  ready_for_fast,
    output wire ready_for_slow,
    output reg  fifo_read_req,

    // Final correction outputs, flattened: timestep t = results[t*CORRECTION_ACC_WIDTH +: CORRECTION_ACC_WIDTH]
    // (tsweep_synth: was 8 ports result_0..result_7, i.e. TIMESTEPS = 8 only)
    output reg [TIMESTEPS*CORRECTION_ACC_WIDTH-1:0] results,
    output reg result_valid
);

    // FIX: localparams used for internal signal widths derived from BITMASK_WIDTH
    //      so that the clog2 user-function is only called inside always blocks
    //      (where function calls are legal), not in port/signal declarations.
    localparam ADDR_BITS = $clog2(BITMASK_WIDTH);  // 7 for BITMASK_WIDTH=128

    // -----------------------------------------------------
    // simple clog2 function for Verilog-2001 (kept for
    // any remaining uses inside procedural blocks)
    // -----------------------------------------------------
    function integer clog2;
        input integer value;
        integer i;
        begin
            clog2 = 0;
            for (i = value-1; i > 0; i = i >> 1)
                clog2 = clog2 + 1;
        end
    endfunction

    // ------------------------------
    // State machine
    // ------------------------------
    localparam CORR_IDLE        = 3'd0;
    localparam WAITING_FOR_DATA = 3'd1;
    localparam CORRECTION       = 3'd2;
    localparam COMPLETE         = 3'd3;

    reg [2:0] corr_state;

    // ------------------------------
    // FSM internals
    // ------------------------------
    reg [PSEUDO_ACC_WIDTH-1:0] pseudo_accumulator;

    reg [WEIGHT_WIDTH-1:0]  stored_weight;
    reg [ADDR_BITS-1:0]     stored_offset;   // FIX: uses localparam not function call
    reg [TIMESTEPS-1:0]     stored_fibre_a;

    // per-timestep accumulators (internal array)
    reg [CORRECTION_ACC_WIDTH-1:0] corr [0:TIMESTEPS-1];

    reg have_seen_slow;

    // ------------------------------
    // ready_for_slow logic
    // ------------------------------
    assign ready_for_slow =
        (corr_state == CORR_IDLE || corr_state == COMPLETE) &&
        !(corr_state == CORR_IDLE && slow_valid && !laggy_done);

    // ------------------------------
    // Fast prefix -> pseudo accumulator
    // ------------------------------
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pseudo_accumulator <= 0;
            ready_for_fast     <= 1'b1;
        end else begin
            ready_for_fast <= 1'b1;

            if (fast_valid) begin
                pseudo_accumulator <= pseudo_accumulator + matched_weight;
                $display("ACC-FAST: +%0d -> %0d",
                    matched_weight, pseudo_accumulator + matched_weight);
            end
        end
    end

    // ------------------------------
    // Correction FSM
    // ------------------------------
    integer i;

    task write_results_out;
        integer k;
        begin
            for (k = 0; k < TIMESTEPS; k = k + 1)
                results[k*CORRECTION_ACC_WIDTH +: CORRECTION_ACC_WIDTH] <= corr[k];
        end
    endtask

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            corr_state      <= CORR_IDLE;
            stored_weight   <= 0;
            stored_offset   <= 0;
            stored_fibre_a  <= 0;

            fibre_a_addr    <= 0;
            fibre_a_read_en <= 0;
            fifo_read_req   <= 0;
            result_valid    <= 0;

            have_seen_slow  <= 0;

            for (i = 0; i < TIMESTEPS; i = i + 1)
                corr[i] <= 0;

            results <= 0;
        end
        else begin
            fibre_a_read_en <= 0;
            fifo_read_req   <= 0;
            result_valid    <= 0;

            case (corr_state)
                CORR_IDLE: begin
                    if (slow_valid && !laggy_done) begin
                        have_seen_slow  <= 1'b1;
                        fifo_read_req   <= 1'b1;

                        stored_weight   <= current_weight;
                        stored_offset   <= slow_offset;

                        fibre_a_addr    <= slow_offset;
                        fibre_a_read_en <= 1'b1;

                        corr_state      <= WAITING_FOR_DATA;

                        $display("ACC-LAGGY: match offset=%0d weight=%0d",
                                 slow_offset, current_weight);
                    end
                    else if (laggy_done && have_seen_slow) begin
                        for (i = 0; i < TIMESTEPS; i = i + 1)
                            corr[i] <= pseudo_accumulator - corr[i];

                        corr_state <= COMPLETE;
                    end
                end

                WAITING_FOR_DATA: begin
                    if (fibre_a_valid) begin
                        stored_fibre_a <= fibre_a_data;
                        $display("ACC: Loaded fibre-A: %b", fibre_a_data);

                        if (fibre_a_data == {TIMESTEPS{1'b1}}) begin
                            corr_state <= CORR_IDLE;
                        end else begin
                            corr_state <= CORRECTION;
                        end
                    end
                end

                CORRECTION: begin
                    for (i = 0; i < TIMESTEPS; i = i + 1) begin
                        if (!stored_fibre_a[i]) begin
                            corr[i] <= corr[i] + stored_weight;
                            $display("ACC: TS%0d inactive -> corr[%0d] += %0d",
                                     i, i, stored_weight);
                        end
                    end

                    corr_state <= CORR_IDLE;
                end

                COMPLETE: begin
                    write_results_out();
                    result_valid   <= 1'b1;
                    corr_state     <= CORR_IDLE;
                    have_seen_slow <= 0;
                end
            endcase
        end
    end

endmodule
