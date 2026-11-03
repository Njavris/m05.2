// Disassemble and print from selected addresses without analysis.
//@category C166
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class ProbeAddresses extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String s : getScriptArgs()) {
            long v = Long.parseLong(s.replace("0x", ""), 16);
            Address a = toAddr(v);
            println("=== " + a);
            if (getInstructionAt(a) == null) {
                try { disassemble(a); } catch (Exception e) { println("FAIL " + e); continue; }
            }
            Address cur = a;
            for (int i = 0; i < 25 && cur != null; i++) {
                Instruction ins = getInstructionAt(cur);
                if (ins == null) { println(cur + "  <undefined>"); break; }
                println(ins.getAddress() + "  " + ins);
                Instruction nx = ins.getNext(); cur = nx == null ? null : nx.getAddress();
            }
        }
    }
}
