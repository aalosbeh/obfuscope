#!/usr/bin/env bash
# Ghidra-headless wrapper: decompile ONE native binary sample to
# <out_dir>/<sample>.c + <out_dir>/<sample>_analysis.json.
#
# Purely static: analyzeHeadless disassembles/decompiles the target without
# ever executing it. See README.md for the safety notes and the scope
# boundary (decompilation only -- no obfuscation/evasion generation).
#
# Requires Ghidra: set GHIDRA_HOME to its install directory (so
# $GHIDRA_HOME/support/analyzeHeadless exists), or have analyzeHeadless
# already on PATH.
#
# Usage: run_headless.sh <input_file> <out_dir> [project_dir]
set -euo pipefail

INPUT="${1:?usage: run_headless.sh <input_file> <out_dir> [project_dir]}"
OUT_DIR="${2:?usage: run_headless.sh <input_file> <out_dir> [project_dir]}"
PROJECT_DIR="${3:-$(mktemp -d -t obfuscope_ghidra_proj.XXXXXX)}"

if [ -n "${GHIDRA_HOME:-}" ]; then
    HEADLESS="${GHIDRA_HOME}/support/analyzeHeadless"
else
    HEADLESS="analyzeHeadless"
fi

if ! command -v "${HEADLESS}" >/dev/null 2>&1 && [ ! -x "${HEADLESS}" ]; then
    echo "error: analyzeHeadless not found. Set GHIDRA_HOME or put it on PATH." >&2
    exit 1
fi

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)/ghidra_scripts"
SAMPLE="$(basename "${INPUT}")"

mkdir -p "${OUT_DIR}" "${PROJECT_DIR}"

echo "[decompile] ${SAMPLE} -> ${OUT_DIR} (project: ${PROJECT_DIR})"

"${HEADLESS}" "${PROJECT_DIR}" "obfuscope_$$" \
    -import "${INPUT}" \
    -scriptPath "${SCRIPT_DIR}" \
    -postScript ExportDecompiled.py "${OUT_DIR}" \
    -deleteProject \
    -overwrite

echo "[decompile] done: ${OUT_DIR}/${SAMPLE}.c"
