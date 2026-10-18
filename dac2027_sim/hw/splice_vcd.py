"""
splice_vcd.py -- remove the $dumpoff..$dumpon gaps of a VCD and close them up in time, so OpenSTA's read_vcd
(activity = transitions / (last time - first time)) sees only the dumped windows back to back.

  python3 splice_vcd.py in.vcd out.vcd

The X values of the $dumpoff block are dropped; the values of the $dumpon block are written at the (shifted)
time the gap started, so a signal that changed during the gap shows exactly one transition at the splice
(e.g. the TCAM bits rewritten by the pre-load). Gaps must be whole clock periods (cut at the same clock phase).
"""
import sys


def splice(src, dst):
    off = 0            # total removed time
    cur = None         # raw time of the current block (None before the first timestamp)
    t_off = None       # raw time of the pending $dumpoff
    emitted = None     # last shifted time written
    state = "hdr"      # hdr | body | off | offblk | onblk
    gaps = 0
    with open(src) as fi, open(dst, "w") as fo:
        for line in fi:
            s = line.strip()
            if state == "hdr":
                fo.write(line)
                if s.startswith("$enddefinitions"):
                    state = "body"
                continue
            if s.startswith("#"):
                cur = int(s[1:])
                if state in ("body", "onblk"):
                    state = "body"
                continue                                     # timestamps are written lazily
            if state == "off":
                if s.startswith("$dumpon"):
                    off += cur - t_off
                    gaps += 1
                    state = "onblk"
                continue
            if state == "offblk":
                if s.startswith("$end"):
                    state = "off"
                continue
            if s.startswith("$dumpoff"):
                if emitted != cur - off:
                    fo.write(f"#{cur - off}\n"); emitted = cur - off
                t_off = cur
                state = "offblk"
                continue
            if s.startswith("$dumpon"):                      # (only reached without a preceding $dumpoff)
                state = "onblk"
                continue
            if state == "onblk" and s.startswith("$end"):
                state = "body"
                continue
            if s.startswith("$end") and state == "body":
                fo.write(line)
                continue
            if not s:
                continue
            if cur is not None and emitted != cur - off:
                fo.write(f"#{cur - off}\n"); emitted = cur - off
            fo.write(line)
        if state == "body" and emitted != cur - off:
            fo.write(f"#{cur - off}\n")
    print(f"{gaps} gaps removed, {off} time units cut, last time {cur - off if state != 'off' else t_off - off}")


if __name__ == "__main__":
    splice(sys.argv[1], sys.argv[2])
