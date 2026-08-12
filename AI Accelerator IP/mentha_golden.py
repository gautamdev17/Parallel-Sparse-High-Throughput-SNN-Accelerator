#!/usr/bin/env python3
"""
mentha_golden.py
Python Golden Model & Verification Driver for Mentha Weight-Stationary AI Accelerator IP.

This script:
1. Generates sparse matrices A and B with Mentha non-conflicting index packing.
2. Computes the exact Golden Mathematical Reference for C = A x B.
3. Formats SystemVerilog input stimulus files (stim_a.hex, stim_b.hex, stim_c_west.hex).
4. Invokes Icarus Verilog to run the SystemVerilog file-driven testbench.
5. Parses the RTL output (actual_c_east.hex) and performs bit-exact verification against the Golden Model.
"""

import os
import sys
import random
import subprocess

# --- Configuration Constants ---
IDX_W = 8
VAL_W = 32
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

class MenthaGoldenModel:
    def __init__(self, rows=ROWS, cols=COLS, num_cbuf=NUM_CBUF):
        self.rows = rows
        self.cols = cols
        self.num_cbuf = num_cbuf

    def generate_random_test_case(self, seed=42):
        random.seed(seed)
        matrix_a = {}
        idx_pool = list(range(10, 250, 10))
        random.shuffle(idx_pool)
        
        for r in range(self.rows):
            for c in range(self.cols):
                a_idx = idx_pool.pop()
                a_val = random.randint(-15, 15)
                if a_val == 0:
                    a_val = 5
                matrix_a[(r, c)] = (a_idx, a_val)
                    
        num_cycles = 10
        stream_b = {c: [] for c in range(self.cols)}
        
        for cycle in range(num_cycles):
            for c in range(self.cols):
                target_row = cycle % self.rows
                a_idx, _ = matrix_a[(target_row, c)]
                b_idx = a_idx
                b_val = random.randint(1, 10)
                stream_b[c].append((b_idx, b_val))
                    
        stream_c_west = {r: [] for r in range(self.rows)}
        for r in range(self.rows):
            for cycle in range(num_cycles):
                west_slots = []
                if cycle == 0:
                    a_idx, _ = matrix_a[(r, 0)]
                    west_slots.append((a_idx, a_idx, 50, 1))
                while len(west_slots) < self.num_cbuf:
                    west_slots.append((0, 0, 0, 0))
                stream_c_west[r].append(west_slots)
            
        return matrix_a, stream_b, stream_c_west, num_cycles

    def compute_golden_reference(self, matrix_a, stream_b, stream_c_west, num_cycles):
        total_sim_cycles = num_cycles + self.rows + self.cols + 4
        
        b_pipe = [[(0, 0) for _ in range(self.cols)] for _ in range(self.rows + 1)]
        c_pipe = [[[(0, 0, 0, 0) for _ in range(self.num_cbuf)] for _ in range(self.cols + 1)] for _ in range(self.rows)]
        
        c_east_history = []
        
        for cycle in range(total_sim_cycles):
            next_b_pipe = [[(0, 0) for _ in range(self.cols)] for _ in range(self.rows + 1)]
            next_c_pipe = [[[(0, 0, 0, 0) for _ in range(self.num_cbuf)] for _ in range(self.cols + 1)] for _ in range(self.rows)]
            
            for c in range(self.cols):
                if cycle < len(stream_b[c]):
                    b_pipe[0][c] = stream_b[c][cycle]
                else:
                    b_pipe[0][c] = (0, 0)
                    
            for r in range(self.rows):
                if cycle < len(stream_c_west[r]):
                    c_pipe[r][0] = stream_c_west[r][cycle]
                else:
                    c_pipe[r][0] = [(0, 0, 0, 0)] * self.num_cbuf
                    
            for r in range(self.rows):
                for c in range(self.cols):
                    a_idx, a_val = matrix_a.get((r, c), (0, 0))
                    b_idx, b_val = b_pipe[r][c]
                    in_c_stream = list(c_pipe[r][c])
                    
                    next_b_pipe[r+1][c] = (b_idx, b_val)
                    
                    do_compute = (a_idx != 0) and (b_idx != 0) and (a_idx == b_idx)
                    product = a_val * b_val
                    
                    out_c_stream = [list(slot) for slot in in_c_stream]
                    
                    if do_compute:
                        match_idx = -1
                        for i in range(self.num_cbuf):
                            c_a, c_b, c_v, c_valid = out_c_stream[i]
                            if c_valid == 1 and c_a == a_idx and c_b == b_idx:
                                match_idx = i
                                break
                                
                        if match_idx != -1:
                            c_a, c_b, c_v, c_valid = out_c_stream[match_idx]
                            out_c_stream[match_idx] = (c_a, c_b, c_v + product, 1)
                        else:
                            free_idx = -1
                            for i in range(self.num_cbuf):
                                if out_c_stream[i][3] == 0:
                                    free_idx = i
                                    break
                            if free_idx != -1:
                                out_c_stream[free_idx] = (a_idx, b_idx, product, 1)
                                
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
        
        # 1. Stationary A* (stim_a.hex): row col a_idx a_val
        with open(os.path.join(SIM_DIR, "stim_a.hex"), "w") as f:
            for r in range(self.rows):
                for c in range(self.cols):
                    a_idx, a_val = matrix_a.get((r, c), (0, 0))
                    val_hex = f"{a_val & 0xFFFFFFFF:08x}"
                    f.write(f"{r} {c} {a_idx:02x} {val_hex}\n")
                    
        # 2. B* Stream (stim_b.hex): space separated b_idx b_val for 4 cols = 8 hex numbers
        with open(os.path.join(SIM_DIR, "stim_b.hex"), "w") as f:
            for cycle in range(total_cycles):
                line_parts = []
                for c in range(self.cols):
                    if cycle < len(stream_b[c]):
                        b_idx, b_val = stream_b[c][cycle]
                    else:
                        b_idx, b_val = 0, 0
                    val_hex = f"{b_val & 0xFFFFFFFF:08x}"
                    line_parts.append(f"{b_idx:02x} {val_hex}")
                f.write(" ".join(line_parts) + "\n")
                
        # 3. West C* Stream (stim_c_west.hex): space separated a_idx b_idx val valid for 4 rows x 4 slots = 64 numbers
        with open(os.path.join(SIM_DIR, "stim_c_west.hex"), "w") as f:
            for cycle in range(total_cycles):
                line_parts = []
                for r in range(self.rows):
                    if cycle < len(stream_c_west[r]):
                        slots = stream_c_west[r][cycle]
                    else:
                        slots = [(0,0,0,0)] * self.num_cbuf
                    for s in range(self.num_cbuf):
                        a_idx, b_idx, val, valid = slots[s]
                        val_hex = f"{val & 0xFFFFFFFF:08x}"
                        line_parts.append(f"{a_idx:02x} {b_idx:02x} {val_hex} {valid}")
                f.write(" ".join(line_parts) + "\n")

    def run_verilog_simulation(self):
        cmd = "iverilog -g2012 -o mentha_file_sim src/mentha_pe_ws.sv src/mentha_array_ws_4x4.sv src/tb_mentha_file_driven.sv && ./mentha_file_sim"
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
                if len(parts) != 64:
                    continue
                row_slots = []
                idx = 0
                for r in range(self.rows):
                    slots = []
                    for s in range(self.num_cbuf):
                        a_idx = safe_hex_int(parts[idx])
                        b_idx = safe_hex_int(parts[idx+1])
                        raw_val = safe_hex_int(parts[idx+2])
                        val = raw_val if raw_val < 0x80000000 else raw_val - 0x100000000
                        valid = safe_hex_int(parts[idx+3])
                        slots.append((a_idx, b_idx, val, valid))
                        idx += 4
                    row_slots.append(slots)
                actual_data.append(row_slots)
        return actual_data

def main():
    print("===============================================================")
    print("   MENTHA AI ACCELERATOR IP - PYTHON GOLDEN VERIFIER FRAMEWORK  ")
    print("===============================================================")
    
    verifier = MenthaGoldenModel()
    
    # 1. Generate Case
    print("[1/5] Generating Sparse Test Tile & Mentha Dataflow...")
    matrix_a, stream_b, stream_c_west, num_cycles = verifier.generate_random_test_case(seed=12345)
    
    print("      Stationary A* Preload Entries:")
    for (r, c), (a_idx, a_val) in sorted(matrix_a.items()):
        print(f"        PE({r},{c}): a_idx={a_idx:3d}, a_val={a_val:3d}")
            
    # 2. Compute Golden Reference
    print("\n[2/5] Running Python Golden Systolic Reference Engine...")
    golden_east, total_cycles = verifier.compute_golden_reference(matrix_a, stream_b, stream_c_west, num_cycles)
    print(f"      Total Systolic Cycles Executed: {total_cycles}")
    
    # 3. Export Hex Stimulus
    print("\n[3/5] Writing Hex Stimulus Files for SystemVerilog Testbench...")
    verifier.write_hex_stimulus(matrix_a, stream_b, stream_c_west, golden_east, total_cycles)
    print("      Files exported to ./sim_data/")
    
    # 4. Run RTL Simulation
    print("\n[4/5] Invoking SystemVerilog RTL Co-Simulation (Icarus Verilog)...")
    returncode, stdout, stderr = verifier.run_verilog_simulation()
    print("--- RTL stdout ---")
    print(stdout)
    if returncode != 0:
        print(f"ERROR: Verilog Simulation Failed!\nStderr:\n{stderr}")
        sys.exit(1)
    
    # 5. Parse & Compare Results
    print("\n[5/5] Performing Bit-Exact Verification (Python Golden vs SV RTL)...")
    actual_data = verifier.parse_actual_c_east()
    
    if actual_data is None:
        print("ERROR: Could not find actual_c_east.hex from simulation output!")
        sys.exit(1)
        
    mismatches = 0
    total_checks = 0
    
    print("\n      --- Detailed East Edge C* Stream Results Comparison ---")
    print("      Cycle | Row | Golden Output (a_idx, b_idx, val) | SV RTL Output (a_idx, b_idx, val) | Status")
    print("      " + "-"*85)
    
    for cycle in range(min(len(golden_east), len(actual_data))):
        for r in range(ROWS):
            golden_slots = golden_east[cycle][r]
            actual_slots = actual_data[cycle][r]
            
            for g_slot in golden_slots:
                g_a, g_b, g_val, g_valid = g_slot
                if g_valid == 1:
                    total_checks += 1
                    match_in_actual = False
                    found_val = None
                    for a_slot in actual_slots:
                        a_a, a_b, a_val, a_valid = a_slot
                        if a_valid == 1 and a_a == g_a and a_b == g_b:
                            found_val = a_val
                            if a_val == g_val:
                                match_in_actual = True
                                print(f"      {cycle:5d} |  {r}  | (a={g_a:3d}, b={g_b:3d}, val={g_val:5d})     | (a={a_a:3d}, b={a_b:3d}, val={a_val:5d})     |  PASS")
                            else:
                                print(f"      {cycle:5d} |  {r}  | (a={g_a:3d}, b={g_b:3d}, val={g_val:5d})     | (a={a_a:3d}, b={a_b:3d}, val={a_val:5d})     |  MISMATCH")
                                mismatches += 1
                            break
                    if not match_in_actual and found_val is None:
                        print(f"      {cycle:5d} |  {r}  | (a={g_a:3d}, b={g_b:3d}, val={g_val:5d})     | MISSING AT RTL OUTPUT             |  FAIL")
                        mismatches += 1
                        
    print("---------------------------------------------------------------")
    if mismatches == 0 and total_checks > 0:
        print(f"   SUCCESS! 100% BIT-EXACT VERIFICATION PASSED ({total_checks} non-zero partials verified)")
        print("   Python Golden Reference == SystemVerilog Hardware Accelerator IP")
    else:
        print(f"   RESULTS: {total_checks - mismatches} / {total_checks} matched. {mismatches} mismatches.")
    print("---------------------------------------------------------------")

if __name__ == "__main__":
    main()