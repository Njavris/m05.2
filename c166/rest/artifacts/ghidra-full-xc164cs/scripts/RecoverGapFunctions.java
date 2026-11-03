// Disassemble gap candidates and create functions for code-like blocks.
//@category C166
import java.io.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class RecoverGapFunctions extends GhidraScript {
    private boolean isTerm(String m) {
        return m.equalsIgnoreCase("rets") || m.equalsIgnoreCase("reti") ||
               m.equalsIgnoreCase("jmpa") || m.equalsIgnoreCase("jmps");
    }
    @Override
    public void run() throws Exception {
        String path = getScriptArgs().length > 0 ? getScriptArgs()[0] : "/tmp/opencode/gap_probe_args.txt";
        String line;
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            line = br.readLine();
        }
        String[] vals = line.trim().split("\\s+");
        int made = 0, dis = 0, skipped = 0;
        for (String s : vals) {
            long v = Long.parseLong(s.replace("0x", ""), 16);
            Address a = toAddr(v);
            if (a == null || !currentProgram.getMemory().contains(a)) continue;
            if (getInstructionAt(a) == null) {
                boolean ok = false;
                try { ok = disassemble(a); } catch (Exception e) { continue; }
                if (ok) dis++;
            }
            Instruction ins = getInstructionAt(a);
            if (ins == null) continue;
            if (getFunctionContaining(a) != null) { skipped++; continue; }
            int n = 0; String last = "";
            Address cur = a;
            while (ins != null && n < 200) {
                n++; last = ins.getMnemonicString();
                if (isTerm(last)) break;
                Instruction nx = ins.getNext();
                if (nx == null || nx.getAddress().getOffset() <= cur.getOffset()) break;
                cur = nx.getAddress();
                ins = nx;
            }
            if (n < 2 || !isTerm(last)) continue;
            try {
                Function f = createFunction(a, String.format("gap_%s", s));
                if (f != null) { made++; println("gap function " + s + " n=" + n); }
            } catch (Exception e) { println("gap fail " + s + ": " + e); }
        }
        println("RecoverGapFunctions disassembled=" + dis + " functions=" + made +
                " skipped_existing=" + skipped + " total=" + currentProgram.getFunctionManager().getFunctionCount());
    }
}
