// Export flash-only linear listing.
//@category C166
import java.io.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class ExportFlashListing extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File out = new File(args.length > 0 ? args[0] : "/tmp/opencode/ghidra_flash");
        out.mkdirs();
        Address start = toAddr(0xC00000L), end = toAddr(0xC3FFFFL);
        int n = 0;
        try (PrintWriter w = new PrintWriter(new File(out, "disassembly.txt"), "UTF-8")) {
            InstructionIterator ii = currentProgram.getListing().getInstructions(start, true);
            while (ii.hasNext()) {
                Instruction ins = ii.next();
                if (ins.getAddress().compareTo(end) > 0) break;
                StringBuilder bytes = new StringBuilder();
                try { for (byte b : ins.getBytes()) bytes.append(String.format("%02X", b)); } catch (Exception e) {}
                w.println(ins.getAddress() + "  " + bytes + "  " + ins.toString());
                n++;
            }
        }
        println("ExportFlashListing instructions=" + n);
    }
}
