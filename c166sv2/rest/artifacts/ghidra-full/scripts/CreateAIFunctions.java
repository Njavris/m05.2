// Create functions at code blocks found by Ghidra's Aggressive Instruction Finder.
//@category C166
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class CreateAIFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] addrs = {
            "c02020","c0210a","c02140","c02250","c022fc","c0231e","c03ddc",
            "c0d0a6","c11dd0","c11e0e","c12398","c124e0","c12600","c13484",
            "c13ba8","c13e54","c13e76","c14300","c15820","c17cb4","c181f8",
            "c193fc","c197e4","c19806","c19b6c","c1b682","c1bf0a","c1d0c2",
            "c1fff4","c22812","c22df8","c23042","c23058","c2315c","c23446",
            "c235ca","c23d06","c24864","c248ce","c24e72","c24f3e","c25c3e",
            "c26600","c27216"
        };
        int made = 0;
        for (String s : addrs) {
            Address a = toAddr(Long.parseLong(s, 16));
            if (a == null || getInstructionAt(a) == null) continue;
            if (getFunctionContaining(a) != null) continue;
            try {
                Function f = createFunction(a, "aif_" + s);
                if (f != null) { made++; println("AIF function " + s); }
            } catch (Exception e) { println("AIF function fail " + s + ": " + e); }
        }
        println("CreateAIFunctions made=" + made + " total=" + currentProgram.getFunctionManager().getFunctionCount());
    }
}
