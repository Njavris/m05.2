// Add reset entry and far-jump vector targets explicitly.
//@category C166
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;

public class AddBootVectors extends GhidraScript {
    private void make(long v, String name) {
        Address a = toAddr(v);
        if (a == null || !currentProgram.getMemory().contains(a)) return;
        if (getInstructionAt(a) == null) { try { disassemble(a); } catch (Exception e) {} }
        if (getInstructionAt(a) == null) return;
        if (getFunctionAt(a) == null) {
            try { createFunction(a, name); println("vector function " + name + " @ " + a); }
            catch (Exception e) { println("vector fail " + a + ": " + e); }
        }
    }
    @Override
    public void run() throws Exception {
        make(0xC00000L, "boot_vector_reset");
        long[] targets = {0xC00A78L,0xC00F0CL,0xC00F6AL,0xC00FC8L,0xC00E14L,0xC00D34L,0xC01048L,0xC00694L};
        for (long t : targets) make(t, String.format("vector_%06x", t));
        println("AddBootVectors functions=" + currentProgram.getFunctionManager().getFunctionCount() +
                " instructions=" + currentProgram.getListing().getNumInstructions());
    }
}
