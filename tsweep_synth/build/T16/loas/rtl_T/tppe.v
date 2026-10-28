// tsweep_synth copy: results as one TIMESTEPS-wide bus (was 8 ports), so TIMESTEPS can be 4/8/16/32 (see CHANGES.md)
`timescale 1ns/1ps

module tppe #(
    parameter BITMASK_WIDTH        = 128,
    parameter WEIGHT_WIDTH         = 8,    // default
    parameter TIMESTEPS            = 16,    // <-- default changed to 8
    parameter ADDR_WIDTH           = 8,
    parameter PSEUDO_ACC_WIDTH     = 13,
    parameter CORRECTION_ACC_WIDTH = 12,
    parameter Q                    = CORRECTION_ACC_WIDTH
)(
    input  wire clk,
    input  wire rst,

    input  wire start_new_batch,
    output wire ready_for_input,
    output wire tppe_done,

    input  wire valid_match,
    input  wire [BITMASK_WIDTH-1:0] bitmask_b,
    input  wire [BITMASK_WIDTH*WEIGHT_WIDTH-1:0] fibre_b_data_flat,

    input  wire [BITMASK_WIDTH-1:0] bitmask_a,

    // Fibre-A memory response
    input  wire [TIMESTEPS-1:0] fibre_a_data,
    input  wire                 fibre_a_valid,
    output wire [ADDR_WIDTH-1:0] fibre_a_addr,
    output wire                  fibre_a_read_en,

    input  wire [Q-1:0] lif_threshold,

    // OUTPUTS
    output wire [TIMESTEPS-1:0] spike_out,

    // flattened results: timestep t = results[t*CORRECTION_ACC_WIDTH +: CORRECTION_ACC_WIDTH]
    // (tsweep_synth: was result_0..result_7, TIMESTEPS = 8 only)
    output wire [TIMESTEPS*CORRECTION_ACC_WIDTH-1:0] results,
    output wire result_valid
);

    wire sub_rst = rst | start_new_batch;
    wire [BITMASK_WIDTH-1:0] and_result = bitmask_a & bitmask_b;

    wire [$clog2(BITMASK_WIDTH)-1:0] matched_position;
    wire [WEIGHT_WIDTH-1:0]          matched_weight;
    wire                             fast_valid;

    wire [$clog2(BITMASK_WIDTH)-1:0] slow_offset;
    wire [$clog2(BITMASK_WIDTH)-1:0] current_position;
    wire [WEIGHT_WIDTH-1:0]          current_weight;
    wire                             slow_valid;
    wire                             laggy_done;

    wire fifo_read_req;
    wire ready_for_fast_from_acc;
    wire ready_for_new_calc_from_laggy;
    wire ready_for_slow_from_acc;   // dac2027_sim edit: was a second driver of ready_for_new_calc_from_laggy

    // FAST PREFIX
    fast_prefix #(
        .BITMASK_WIDTH(BITMASK_WIDTH),
        .WEIGHT_WIDTH(WEIGHT_WIDTH)
    ) fast_inst (
        .clk(clk),
        .rst(sub_rst),
        .and_result(and_result),
        .bitmask_b(bitmask_b),
        .valid_match(valid_match),
        .fibre_b_data_flat(fibre_b_data_flat),

        .fast_offset(),
        .matched_position(matched_position),
        .matched_weight(matched_weight),
        .fast_valid(fast_valid),
        .processing_done(),
        .fast_all_matches_done()
    );

    // LAGGY PREFIX
    laggy_prefix #(
        .BITMASK_WIDTH(BITMASK_WIDTH),
        .NUM_ADDERS(16),
        .WEIGHT_WIDTH(WEIGHT_WIDTH),
        .FIFO_DEPTH(8)
    ) laggy_inst (
        .clk(clk),
        .rst(sub_rst),

        .and_result(and_result),
        .bitmask_a(bitmask_a),
        .matched_position(matched_position),
        .matched_weight(matched_weight),
        .valid_match(fast_valid),

        .fifo_mp_read_en(fifo_read_req),
        .fifo_weight_read_en(fifo_read_req),

        .slow_offset(slow_offset),
        .current_position(current_position),
        .current_weight(current_weight),
        .slow_valid(slow_valid),
        .ready_for_new_calc(ready_for_new_calc_from_laggy),

        .fifo_mp_empty(), .fifo_mp_full(),
        .fifo_weight_empty(), .fifo_weight_full(),

        .laggy_done(laggy_done)
    );

    // ACCUMULATOR CORRECTION (8-timestep variant)
    accumulator_correction #(
        .TIMESTEPS(TIMESTEPS),
        .WEIGHT_WIDTH(WEIGHT_WIDTH),
        .PSEUDO_ACC_WIDTH(PSEUDO_ACC_WIDTH),
        .CORRECTION_ACC_WIDTH(CORRECTION_ACC_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH),
        .BITMASK_WIDTH(BITMASK_WIDTH)
    ) acc_inst (
        .clk(clk),
        .rst(sub_rst),

        .matched_position(matched_position),
        .matched_weight(matched_weight),
        .fast_valid(fast_valid),

        .current_position(current_position),
        .current_weight(current_weight),
        .slow_offset(slow_offset),
        .slow_valid(slow_valid),
        .laggy_done(laggy_done),

        .fibre_a_data(fibre_a_data),
        .fibre_a_valid(fibre_a_valid),
        .fibre_a_addr(fibre_a_addr),
        .fibre_a_read_en(fibre_a_read_en),

        .ready_for_fast(ready_for_fast_from_acc),
        .ready_for_slow(ready_for_slow_from_acc),
        .fifo_read_req(fifo_read_req),

        .results(results),
        .result_valid(result_valid)
    );

    // LIF (8-timestep variant)
    lif_model #(
        .T(TIMESTEPS),
        .Q(Q)
    ) lif_inst (
        .clk(clk),
        .rst(sub_rst),

        .start(result_valid),
        .result_val(result_valid),

        .inputs(results),

        .threshold(lif_threshold),

        .spike_out(spike_out),
        .lif_done(tppe_done)
    );

    assign ready_for_input = ready_for_fast_from_acc & ready_for_new_calc_from_laggy & ready_for_slow_from_acc;

endmodule
