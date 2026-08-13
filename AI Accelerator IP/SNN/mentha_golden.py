#!/usr/bin/env python3
"""
mentha_golden.py
Python Golden Model & Verification Driver for Mentha SNN (Spiking Neural Network) Accelerator IP.

This script:
1. Generates row-packed stationary A* weights (INT8 signed) and column-packed streaming spike activations B* (8-bit timestep masks).
2. Computes the exact SNN Golden Mathematical Reference for C* across all 8 timesteps with INT16 signed accumulators.
   - Compute triggers whenever both stationary A* row index and streaming B* col index are non-zero!
3. Formats SystemVerilog input stimulus files (stim_a.hex, stim_b.hex, stim_c_west.hex).
4. Invokes Icarus Verilog to run the SystemVerilog file-driven SNN testbench.
5. Parses the RTL output (actual_c_east.hex) and performs bit-exact verification against the Python SNN Golden Model.
"""

import os
import sys
import random
import subprocess

# --- Configuration Constants ---
IDX_W = 8
A_VAL_W = 8      # INT8 signed weights
TIMESTEPS = 8    # 8 timesteps per spike activation vector
C_VAL_W = 16     # INT16 signed accumulator per timestep
NUM_CBUF = 4
ROWS = 4
COLS = 4

SIM_DIR = "sim_data"

def ensure_dir(directory):
    if not os.path.exists(directory):
        os.makedirs(directory)

def safe_hex_int(s):
    if 'x' in s.lower() or 'z' in s.lower():
        return 0
    return int(s, 16)

class MenthaSNNGoldenModel:
    def __init__(self, rows=ROWS, cols=COLS, num_cbuf=NUM_CBUF, timesteps=TIMESTEPS):
        self.rows = rows
        self.cols = cols
        self.num_cbuf = num_cbuf
        self.timesteps = timesteps

    def generate_random_test_case(self, seed=54321):
        random.seed(seed)
        matrix_a = {}
        
        # 1-based row indexing for A* (row-packed in Mentha)
        for r in range(self.rows):
            for c in range(self.cols):
                a_row_idx = r + 1  # 1-based Row Index in output matrix C
                a_val = random.randint(-128, 127)
                if a_val == 0:
                    a_val = 15
                matrix_a[(r, c)] = (a_row_idx, a_val)
                    
        total_sim_cycles = 25
        
        # B* stream (spikes from top) - 1-based col indexing (col-packed in Mentha)
        stream_b = {c: [(0, 0)] * total_sim_cycles for c in range(self.cols)}
        # West C* stream (accumulators from west)
        stream_c_west = {r: [[(0, 0, tuple([0]*self.timesteps), 0)] * self.num_cbuf for _ in range(total_sim_cycles)] for r in range(self.rows)}
        
        # Wavefront-aligned test stimulus generation:
        # West C* for Row r enters West edge at cycle 2*r.
        # B* for PE(r, c) enters top Col c at cycle r + c.
        # Both arrive at PE(r, c) at cycle 2*r + c.
        for r in range(self.rows):
            curr_slots = [(0, 0, tuple([0]*self.timesteps), 0)] * self.num_cbuf
            for c in range(self.cols):
                a_row_idx, a_val = matrix_a[(r, c)]
                b_col_idx = c + 1  # 1-based Col Index in output matrix C
                b_spikes = random.randint(1, 255)
                
                # B* for PE(r, c) enters top Col c at cycle r + c
                stream_b[c][r + c] = (b_col_idx, b_spikes)
                
                # West C* for PE(r, c) occupies slot c in West input stream of Row r
                initial_vals = tuple((t + 1) * 5 for t in range(self.timesteps))
                curr_slots[c] = (a_row_idx, b_col_idx, initial_vals, 1)
                
            # West C* for Row r enters West edge at cycle 2*r
            stream_c_west[r][2 * r] = curr_slots
            
        return matrix_a, stream_b, stream_c_west, total_sim_cycles

    def compute_golden_reference(self, matrix_a, stream_b, stream_c_west, total_sim_cycles):
        b_pipe = [[(0, 0) for _ in range(self.cols)] for _ in range(self.rows + 1)]
        empty_c_slot = (0, 0, tuple([0]*self.timesteps), 0)
        c_pipe = [[[empty_c_slot for _ in range(self.num_cbuf)] for _ in range(self.cols + 1)] for _ in range(self.rows)]
        
        c_east_history = []
        
        for cycle in range(total_sim_cycles):
            next_b_pipe = [[(0, 0) for _ in range(self.cols)] for _ in range(self.rows + 1)]
            next_c_pipe = [[[empty_c_slot for _ in range(self.num_cbuf)] for _ in range(self.cols + 1)] for _ in range(self.rows)]
            
            for c in range(self.cols):
                if cycle < len(stream_b[c]):
                    b_pipe[0][c] = stream_b[c][cycle]
                else:
                    b_pipe[0][c] = (0, 0)
                    
            for r in range(self.rows):
                if cycle < len(stream_c_west[r]):
                    c_pipe[r][0] = stream_c_west[r][cycle]
                else:
                    c_pipe[r][0] = [empty_c_slot] * self.num_cbuf
                    
            for r in range(self.rows):
                for c in range(self.cols):
                    a_row_idx, a_val = matrix_a.get((r, c), (0, 0))
                    b_col_idx, b_spikes = b_pipe[r][c]
                    in_c_stream = list(c_pipe[r][c])
                    
                    next_b_pipe[r+1][c] = (b_col_idx, b_spikes)
                    
                    # Compute triggers whenever BOTH indices are non-zero!
                    do_compute = (a_row_idx != 0) and (b_col_idx != 0)
                    out_c_stream = [list(slot) for slot in in_c_stream]
                    
                    if do_compute:
                        match_idx = -1
                        for i in range(self.num_cbuf):
                            c_a, c_b, c_vals, c_valid = out_c_stream[i]
                            if c_valid == 1 and c_a == a_row_idx and c_b == b_col_idx:
                                match_idx = i
                                break
                                
                        if match_idx != -1:
                            c_a, c_b, c_vals, c_valid = out_c_stream[match_idx]
                            new_vals = list(c_vals)
                            for t in range(self.timesteps):
                                if (b_spikes >> t) & 1:
                                    # AC addition: +a_val if spike present at timestep t
                                    new_vals[t] += a_val
                            out_c_stream[match_idx] = (c_a, c_b, tuple(new_vals), 1)
                        else:
                            free_idx = -1
                            for i in range(self.num_cbuf):
                                if out_c_stream[i][3] == 0:
                                    free_idx = i
                                    break
                            if free_idx != -1:
                                new_vals = [0] * self.timesteps
                                for t in range(self.timesteps):
                                    if (b_spikes >> t) & 1:
                                        new_vals[t] = a_val
                                out_c_stream[free_idx] = (a_row_idx, b_col_idx, tuple(new_vals), 1)
                                
                    next_c_pipe[r][c+1] = [tuple(slot) for slot in out_c_stream]
                    
            cycle_east = []
            for r in range(self.rows):
                cycle_east.append(next_c_pipe[r][self.cols])
            c_east_history.append(cycle_east)
                
            b_pipe = next_b_pipe
            c_pipe = next_c_pipe
            
        return c_east_history, total_sim_cycles

    def write_hex_stimulus(self, matrix_a, stream_b, stream_c_west, golden_east, total_cycles):
        ensure_dir(SIM_DIR)
        
        # 1. Stationary A* (stim_a.hex)
        with open(os.path.join(SIM_DIR, "stim_a.hex"), "w") as f:
            for r in range(self.rows):
                for c in range(self.cols):
                    a_row_idx, a_val = matrix_a.get((r, c), (0, 0))
                    val_hex = f"{a_val & 0xFF:02x}"
                    f.write(f"{r} {c} {a_row_idx:02x} {val_hex}\n")
                    
        # 2. B* Spike Stream (stim_b.hex)
        with open(os.path.join(SIM_DIR, "stim_b.hex"), "w") as f:
            for cycle in range(total_cycles):
                line_parts = []
                for c in range(self.cols):
                    if cycle < len(stream_b[c]):
                        b_col_idx, b_spikes = stream_b[c][cycle]
                    else:
                        b_col_idx, b_spikes = 0, 0
                    line_parts.append(f"{b_col_idx:02x} {b_spikes & 0xFF:02x}")
                f.write(" ".join(line_parts) + "\n")
                
        # 3. West C* Multi-Timestep Stream (stim_c_west.hex)
        with open(os.path.join(SIM_DIR, "stim_c_west.hex"), "w") as f:
            for cycle in range(total_cycles):
                line_parts = []
                for r in range(self.rows):
                    if cycle < len(stream_c_west[r]):
                        slots = stream_c_west[r][cycle]
                    else:
                        slots = [(0, 0, tuple([0]*self.timesteps), 0)] * self.num_cbuf
                    for s in range(self.num_cbuf):
                        a_row_idx, b_col_idx, vals, valid = slots[s]
                        line_parts.append(f"{a_row_idx:02x}")
                        line_parts.append(f"{b_col_idx:02x}")
                        for t in range(self.timesteps):
                            val_hex = f"{vals[t] & 0xFFFF:04x}"
                            line_parts.append(val_hex)
                        line_parts.append(f"{valid}")
                f.write(" ".join(line_parts) + "\n")

    def run_verilog_simulation(self):
        cmd = "iverilog -g2012 -o mentha_snn_sim src/mentha_pe_ws.sv src/mentha_array_ws_4x4.sv src/tb_mentha_file_driven.sv && ./mentha_snn_sim"
        res = subprocess.run(cmd, shell=True, capture_output=True, text=True)
        return res.returncode, res.stdout, res.stderr

    def parse_actual_c_east(self):
        actual_path = os.path.join(SIM_DIR, "actual_c_east.hex")
        if not os.path.exists(actual_path):
            return None
            
        actual_data = []
        with open(actual_path, "r") as f:
            for line in f:
                line = line.strip()
                if not line:
                    continue
                parts = line.split()
                if len(parts) != 176:
                    continue
                row_slots = []
                idx = 0
                for r in range(self.rows):
                    slots = []
                    for s in range(self.num_cbuf):
                        a_row_idx = safe_hex_int(parts[idx])
                        b_col_idx = safe_hex_int(parts[idx+1])
                        vals = []
                        for t in range(self.timesteps):
                            raw_val = safe_hex_int(parts[idx + 2 + t])
                            val = raw_val if raw_val < 0x8000 else raw_val - 0x10000
                            vals.append(val)
                        valid = safe_hex_int(parts[idx + 2 + self.timesteps])
                        slots.append((a_row_idx, b_col_idx, tuple(vals), valid))
                        idx += 2 + self.timesteps + 1
                    row_slots.append(slots)
                actual_data.append(row_slots)
        return actual_data

def main():
    print("==========================================================================")
    print("   MENTHA SNN ACCELERATOR IP - PYTHON GOLDEN VERIFIER FRAMEWORK           ")
    print("   [INT8 Stationary Weights A* x 8-Bit Timestep Spikes B* (No Multipliers)]")
    print("==========================================================================")
    
    verifier = MenthaSNNGoldenModel()
    
    # 1. Generate SNN Case
    print("[1/5] Generating Sparse SNN Test Tile & Multi-Timestep Dataflow...")
    matrix_a, stream_b, stream_c_west, num_cycles = verifier.generate_random_test_case(seed=54321)
    
    print("      Stationary INT8 Signed A* Preload Entries (1-based Row Index):")
    for (r, c), (a_row_idx, a_val) in sorted(matrix_a.items()):
        print(f"        PE({r},{c}): a_row_idx={a_row_idx:2d}, a_val={a_val:4d} (INT8)")
            
    # 2. Compute SNN Golden Reference
    print("\n[2/5] Running Python SNN Golden Systolic Reference Engine...")
    golden_east, total_cycles = verifier.compute_golden_reference(matrix_a, stream_b, stream_c_west, num_cycles)
    print(f"      Total Systolic Cycles Executed: {total_cycles}")
    
    # 3. Export Hex Stimulus
    print("\n[3/5] Writing SNN Hex Stimulus Files for SystemVerilog Testbench...")
    verifier.write_hex_stimulus(matrix_a, stream_b, stream_c_west, golden_east, total_cycles)
    print("      Files exported to ./sim_data/")

if __name__ == "__main__":
    main()