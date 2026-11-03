// Probe candidate gap starts and summarize disassembly runs.
//@category C166
import java.io.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class ProbeGaps extends GhidraScript {
    @Override
    public void run() throws Exception {
        File out = new File("/tmp/opencode/gap_probe.txt");
        try (PrintWriter w = new PrintWriter(new FileWriter(out))) {
            for (String s : getScriptArgs()) {
                long v = Long.parseLong(s.replace("0x", ""), 16);
                Address a = toAddr(v);
                if (getInstructionAt(a) == null) {
                    try { disassemble(a); } catch (Exception e) { w.println(s + " FAIL"); continue; }
                }
                Instruction ins = getInstructionAt(a);
                if (ins == null) { w.println(s + " NONE"); continue; }
                int n = 0, calls = 0; String first = ins.toString(); String last = "";
                Address cur = a;
                while (ins != null && n < 200) {
                    n++;
                    last = ins.getMnemonicString();
                    if (last.equalsIgnoreCase("calls") || last.equalsIgnoreCase("calla")) calls++;
                    if (last.equalsIgnoreCase("rets") || last.equalsIgnoreCase("reti") ||
                        last.equalsIgnoreCase("jmpa") || last.equalsIgnoreCase("jmps")) break;
                    Instruction nx = ins.getNext();
                    if (nx == null) break;
                    if (cur != null && nx.getAddress().getOffset() <= cur.getOffset()) break;
                    cur = nx.getAddress();
                    ins = nx;
                }
                w.println(s + " n=" + n + " calls=" + calls + " last=" + last + " first=" + first);
            }
        }
        println("wrote " + out);
    }
}
