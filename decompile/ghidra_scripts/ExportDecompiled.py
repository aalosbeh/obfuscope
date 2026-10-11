# Ghidra headless post-script: decompile every function in the current
# program and export a concatenated pseudo-C file plus a lightweight analysis
# JSON. Static only -- this never executes the target program; it drives
# Ghidra's decompiler against the already-imported/analyzed binary.
#
# Invoked by ../run_headless.sh via:
#   analyzeHeadless <project> <name> -import <file> -scriptPath <this dir> \
#       -postScript ExportDecompiled.py <out_dir>
#
# Runs inside Ghidra's embedded Jython 2.7 -- only the Python 2 stdlib and
# Ghidra's Java API (via the `ghidra` / `java` bridges Ghidra injects) are
# available here, not the project's own Python 3 code.
import json
import os
import time

from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

args = getScriptArgs()
if len(args) < 1:
    raise RuntimeError("ExportDecompiled.py requires <out_dir> as its argument")
out_dir = args[0]
if not os.path.isdir(out_dir):
    os.makedirs(out_dir)

program = currentProgram
sample_name = program.getName()

monitor = ConsoleTaskMonitor()
decomp = DecompInterface()
decomp.openProgram(program)

func_manager = program.getFunctionManager()
functions = list(func_manager.getFunctions(True))

c_chunks = []
func_records = []
DECOMPILE_TIMEOUT_S = 30

for f in functions:
    try:
        res = decomp.decompileFunction(f, DECOMPILE_TIMEOUT_S, monitor)
        if res is not None and res.decompileCompleted():
            code = res.getDecompiledFunction().getC()
        else:
            code = "/* decompilation did not complete for %s */\n" % f.getName()
    except Exception as e:
        code = "/* decompilation error for %s: %s */\n" % (f.getName(), str(e))
    c_chunks.append(code)
    try:
        sig = f.getSignature().getPrototypeString()
    except Exception:
        sig = ""
    func_records.append({
        "name": f.getName(),
        "entry_point": str(f.getEntryPoint()),
        "size_bytes": int(f.getBody().getNumAddresses()),
        "signature": sig,
    })

decomp.dispose()

c_path = os.path.join(out_dir, sample_name + ".c")
c_file = open(c_path, "w")
try:
    c_file.write(
        "/* Ghidra headless decompilation export for %s -- static, "
        "execution-free. See ../../README.md for scope. */\n\n" % sample_name)
    c_file.write("\n\n".join(c_chunks))
finally:
    c_file.close()

# Best-effort defined-string extraction, bounded so this stays fast on large
# binaries. Purely a listing read -- no execution.
strings = []
try:
    data_iter = program.getListing().getDefinedData(True)
    count = 0
    while data_iter.hasNext() and count < 500:
        d = data_iter.next()
        if d.hasStringValue():
            strings.append(str(d.getValue()))
            count += 1
except Exception:
    pass

analysis = {
    "sample": sample_name,
    "generated_by": "obfuscope/decompile ExportDecompiled.py (Ghidra headless)",
    "generated_at": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
    "language_id": str(program.getLanguageID()),
    "n_functions": len(functions),
    "complexity_metrics": {
        "n_functions": len(functions),
        "total_bytes": int(program.getMemory().getSize()),
    },
    "function_hashes": dict((r["name"], hash(r["signature"])) for r in func_records),
    "functions": func_records,
    "extracted_strings": strings,
    "decompiled_code_path": c_path,
}

json_path = os.path.join(out_dir, sample_name + "_analysis.json")
json_file = open(json_path, "w")
try:
    json_file.write(json.dumps(analysis, indent=2))
finally:
    json_file.close()

print("[ExportDecompiled] wrote %s and %s" % (c_path, json_path))
