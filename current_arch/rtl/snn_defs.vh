// snn_defs.vh -- shared constants for the dual-sparse weight-stationary SNN array.
// Everything here comes from REPORT.md section 4 (parameters).
`ifndef SNN_DEFS_VH
`define SNN_DEFS_VH

`define IDXW   8                         // index width: position+1, 0 = zero element
`define VALW   8                         // int8 weight / 8-bit spike mask
`define TS     8                         // timesteps = mask bits = gated adders per PE
`define SUMW   16                        // psum width per timestep inside the array
`define PBW    24                        // psum width per timestep in the partial buffer
`define SLOTS  4                         // register-file slots per PE
`define ARR    4                         // array is ARR x ARR

// one register-file entry: {sums[T*SUMW], cidx[IDXW], ridx[IDXW], valid}
//   bit 0                      valid
//   [IDXW:1]                   ridx  (weight row index  = original row + 1)
//   [2*IDXW:IDXW+1]            cidx  (activation column index = original column + 1)
//   [2*IDXW+1 +: T*SUMW]       sums, timestep t at 2*IDXW+1 + t*SUMW
`define ENTW   (1+2*`IDXW+`TS*`SUMW)     // 145 bits
`define SETW   (`SLOTS*`ENTW)            // 580 bits: one psum set (what travels right through the PEs)
`define LENW   (2*`IDXW+`TS*`SUMW)       // 144 bits: FIFO entry {sums, n, m}

`endif
