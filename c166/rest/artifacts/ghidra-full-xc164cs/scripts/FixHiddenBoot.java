// Correct the hidden boot block: entry at c02000, not c02020.
//@category C166
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class FixHiddenBoot extends GhidraScript {
    @Override
    public void run() throws Exception {
        Address old = toAddr(0xC02020L);
        Function f = getFunctionAt(old);
        if (f != null) { removeFunction(f); println("removed function at c02020"); }
        Address a = toAddr(0xC02000L);
        if (getInstructionAt(a) == null) disassemble(a);
        if (getFunctionAt(a) == null) {
            Function nf = createFunction(a, "boot_hidden_main");
            if (nf != null) println("created boot_hidden_main at c02000");
        }
        // standalone helpers after the infinite loop / in the hidden block
        String[] names = {
            "c020c4:boot_hidden_copy", "c0210a:boot_hidden_memcpy",
            "c02140:boot_hidden_periph", "c02250:boot_hidden_xram_init",
            "c022fc:boot_hidden_xram2", "c0231e:boot_hidden_xram3",
            "c0248a:boot_hidden_task", "c02b76:boot_hidden_eeprom",
            "c03cb8:boot_hidden_i2c_a", "c03cd0:boot_hidden_i2c_b",
            "c03ddc:boot_hidden_delay", "c03de2:boot_hidden_store32"
        };
        for (String s : names) {
            String[] p = s.split(":");
            Address x = toAddr(Long.parseLong(p[0], 16));
            if (getInstructionAt(x) == null) { try { disassemble(x); } catch (Exception e) {} }
            if (getInstructionAt(x) == null || getFunctionContaining(x) != null) continue;
            try { createFunction(x, p[1]); println("created " + p[1] + " at " + p[0]); }
            catch (Exception e) { println("fail " + p[0] + ": " + e); }
        }
        println("FixHiddenBoot functions=" + currentProgram.getFunctionManager().getFunctionCount() +
                " instructions=" + currentProgram.getListing().getNumInstructions());
    }
}
