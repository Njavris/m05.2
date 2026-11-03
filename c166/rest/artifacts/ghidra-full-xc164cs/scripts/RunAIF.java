// Run Ghidra's Aggressive Instruction Finder over undefined bytes.
//@category C166
import ghidra.app.script.GhidraScript;
import ghidra.app.util.importer.MessageLog;
import ghidra.app.plugin.prototype.analysis.AggressiveInstructionFinderAnalyzer;

public class RunAIF extends GhidraScript {
    @Override
    public void run() throws Exception {
        MessageLog log = new MessageLog();
        AggressiveInstructionFinderAnalyzer a = new AggressiveInstructionFinderAnalyzer();
        boolean ok = a.added(currentProgram, currentProgram.getMemory(), monitor, log);
        println("AIF ok=" + ok);
        println("AIF log: " + log.toString());
        println("AIF functions=" + currentProgram.getFunctionManager().getFunctionCount() +
                " instructions=" + currentProgram.getListing().getNumInstructions());
    }
}
