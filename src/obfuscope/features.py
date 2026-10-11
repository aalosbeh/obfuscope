"""
Static feature extraction for obfuscated C artifacts.

This module converts a single obfuscated ``.c`` source file into a fixed-length
numeric feature vector. The extractor is deliberately dependency-free (Python
standard library only) so that every High-Throughput Computing (HTC) execution
point can run it without a heavy software environment. Features are organised
into named *feature families* so that ablation studies can enable or disable a
whole family at a time.

Feature families
----------------
- ``lexical``      : size, line, token, and identifier statistics.
- ``entropy``      : byte- and token-level Shannon entropy.
- ``control_flow`` : branch, loop, and cyclomatic-complexity proxies.
- ``literal``      : numeric, hexadecimal, and string-literal statistics.
- ``operator``     : arithmetic, bitwise, and logical operator counts.
- ``api``          : buckets of security-relevant API / behavioural tokens.
- ``obfuscation``  : direct indicators of common obfuscation transforms.

The module is intentionally free of any code execution: only regular-expression
and character-level statistics are computed over the file text, so it is safe to
run on untrusted artifacts. (Version 1 applied it to a corpus whose samples
were named after malware; the released pilot corpus is built from synthetic
benign C programs.) The ``api`` buckets name Windows and POSIX APIs that the
pilot programs mostly do not call: six of the eight ``api_*`` columns are
identically zero on ``data/features_pilot.csv``.
"""
from __future__ import annotations

import math
import os
import re
from collections import Counter
from typing import Dict, List

# ---------------------------------------------------------------------------
# Regular expressions (compiled once at import time)
# ---------------------------------------------------------------------------
# Bounded analysis window (bytes). Text-scan features are computed over at most
# this many leading bytes so that per-artifact runtime is bounded even for the
# multi-megabyte translation-unit-embedding variants; the *true* file size is
# always recorded separately via ``os.path.getsize``.
MAX_SCAN_BYTES = 262_144

# Precompiled hot-path regexes (control-flow / operator scans).
_RX = {k: re.compile(v) for k, v in {
    "if": r"\bif\b", "for": r"\bfor\b", "while": r"\bwhile\b", "switch": r"\bswitch\b",
    "case": r"\bcase\b", "goto": r"\bgoto\b", "and": r"&&", "or": r"\|\|",
    "return": r"\breturn\b", "break": r"\bbreak\b", "arith": r"[+\-*/%]",
    "bitwise": r"[&|~]", "shift": r"<<|>>", "xor": r"\^", "assign": r"=",
    "preproc": r"(?m)^\s*#",
}.items()}
_IDENTIFIER = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
_FUNCTION_DEF = re.compile(r"[A-Za-z_][\w\s\*]*?\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*\{")
_STRING_LIT = re.compile(r'"(?:[^"\\]|\\.)*"')
_CHAR_LIT = re.compile(r"'(?:[^'\\]|\\.)*'")
_HEX_CONST = re.compile(r"\b0[xX][0-9a-fA-F]+\b")
_INT_CONST = re.compile(r"\b\d+\b")
_LINE_COMMENT = re.compile(r"//[^\n]*")
_BLOCK_COMMENT = re.compile(r"/\*.*?\*/", re.DOTALL)
_INCLUDE = re.compile(r"#\s*include")
_CHAR_ARRAY = re.compile(r"\b(?:unsigned\s+)?char\s+\w+\s*\[[^\]]*\]\s*=")

# Behavioural / API token buckets. Matching is case-insensitive and token based.
_API_BUCKETS: Dict[str, List[str]] = {
    "api_loader": ["LoadLibrary", "GetProcAddress", "GetModuleHandle", "dlopen", "dlsym"],
    "api_memory": ["VirtualAlloc", "VirtualProtect", "HeapAlloc", "mmap", "mprotect", "memcpy"],
    "api_process": ["CreateProcess", "CreateThread", "CreateRemoteThread", "WinExec",
                    "ShellExecute", "fork", "execve", "system"],
    "api_registry": ["RegOpenKey", "RegSetValue", "RegCreateKey", "RegQueryValue"],
    "api_network": ["socket", "connect", "InternetOpen", "WSAStartup", "recv", "send",
                    "URLDownloadToFile"],
    "api_crypto": ["encrypt", "decrypt", "AES", "Fernet", "CryptEncrypt", "RC4", "XOR",
                   "CryptAcquireContext"],
    "api_antidebug": ["IsDebuggerPresent", "CheckRemoteDebugger", "ptrace", "GDB", "LLDB",
                      "NtQueryInformation", "OutputDebugString"],
    "api_timing": ["usleep", "Sleep", "rdtsc", "QueryPerformanceCounter", "GetTickCount",
                   "nanosleep"],
}

# Direct obfuscation transform indicators.
_OBF_INDICATORS: Dict[str, str] = {
    "obf_opaque_pred": r"if\s*\(\s*0\s*\)",
    "obf_always_true": r"if\s*\(\s*1\s*\)",
    "obf_state_machine": r"\b(?:state|ob_cfl|dispatch|switch_state|__ob_)\w*",
    "obf_magic": r"\bmagic\d*\b",
    "obf_junk": r"\b(?:junk|dead|dummy|nop_func|filler)\w*",
    "obf_goto": r"\bgoto\b",
    "obf_xor_key": r"\^\s*0[xX][0-9a-fA-F]+",
    "obf_random_name": r"\b[A-Za-z]{1,3}[0-9A-Za-z]{5,}\b",
    "obf_vm_dispatch": r"\b(?:vm_|bytecode|opcode|interpret)\w*",
    "obf_selfmod": r"\b(?:self_modify|decrypt_at_runtime|rwx|WriteProcessMemory)\w*",
}

_OBF_RX = {name: re.compile(pat) for name, pat in _OBF_INDICATORS.items()}

_KEYWORDS = {
    "if", "else", "for", "while", "switch", "case", "do", "goto", "return",
    "break", "continue", "int", "char", "void", "unsigned", "long", "short",
    "float", "double", "struct", "typedef", "const", "static", "sizeof",
    "include", "define", "printf", "main",
}

# The canonical, ordered list of feature names. Keeping this explicit guarantees
# that every artifact yields an identically ordered vector across HTC jobs.
FEATURE_FAMILIES: Dict[str, List[str]] = {
    "lexical": [
        "size_bytes", "n_lines", "n_nonblank_lines", "mean_line_len", "max_line_len",
        "n_tokens", "n_unique_identifiers", "unique_identifier_ratio",
        "mean_identifier_len", "identifier_digit_ratio", "n_functions",
        "mean_function_name_len",
    ],
    "entropy": ["byte_entropy", "identifier_entropy", "line_len_entropy"],
    "control_flow": [
        "n_if", "n_for", "n_while", "n_switch", "n_case", "n_goto", "n_return",
        "n_break", "cyclomatic_proxy", "branch_density",
    ],
    "literal": [
        "n_hex_const", "n_int_const", "n_string_lit", "mean_string_len",
        "n_char_lit", "n_char_array", "hex_to_int_ratio",
    ],
    "operator": [
        "n_arith_op", "n_bitwise_op", "n_shift_op", "n_logical_op", "n_xor_op",
        "n_assign_op", "operator_density",
    ],
    "api": list(_API_BUCKETS.keys()),
    "obfuscation": list(_OBF_INDICATORS.keys()) + ["n_comments", "comment_char_ratio",
                                                   "n_includes", "preprocessor_ratio"],
}


def feature_names(families: List[str] | None = None) -> List[str]:
    """Return the ordered feature-name list, optionally for a subset of families."""
    fams = families or list(FEATURE_FAMILIES.keys())
    names: List[str] = []
    for fam in fams:
        names.extend(FEATURE_FAMILIES[fam])
    return names


def _shannon(counts) -> float:
    total = sum(counts)
    if total <= 0:
        return 0.0
    h = 0.0
    for c in counts:
        if c > 0:
            p = c / total
            h -= p * math.log2(p)
    return h


def extract_features(text: str, true_size_bytes: int | None = None) -> Dict[str, float]:
    """Compute the full feature dictionary for one C-artifact string.

    ``text`` may be truncated to :data:`MAX_SCAN_BYTES`; ``true_size_bytes`` (when
    supplied) records the untruncated on-disk size so that the ``size_bytes``
    feature always reflects the real artifact.
    """
    feats: Dict[str, float] = {}
    raw = text if len(text) <= MAX_SCAN_BYTES else text[:MAX_SCAN_BYTES]
    n_bytes = (true_size_bytes if true_size_bytes is not None
               else len(raw.encode("utf-8", "ignore")))
    lines = raw.split("\n")
    nonblank = [ln for ln in lines if ln.strip()]
    line_lens = [len(ln) for ln in lines] or [0]

    # ---- lexical ----
    idents = _IDENTIFIER.findall(raw)
    non_kw = [t for t in idents if t not in _KEYWORDS]
    uniq = set(non_kw)
    digit_ident = sum(1 for t in non_kw if any(ch.isdigit() for ch in t))
    funcs = _FUNCTION_DEF.findall(raw)
    feats["size_bytes"] = float(n_bytes)
    feats["n_lines"] = float(len(lines))
    feats["n_nonblank_lines"] = float(len(nonblank))
    feats["mean_line_len"] = sum(line_lens) / len(line_lens)
    feats["max_line_len"] = float(max(line_lens))
    feats["n_tokens"] = float(len(idents))
    feats["n_unique_identifiers"] = float(len(uniq))
    feats["unique_identifier_ratio"] = len(uniq) / max(1, len(non_kw))
    feats["mean_identifier_len"] = (sum(len(t) for t in non_kw) / max(1, len(non_kw)))
    feats["identifier_digit_ratio"] = digit_ident / max(1, len(non_kw))
    feats["n_functions"] = float(len(funcs))
    feats["mean_function_name_len"] = (sum(len(f) for f in funcs) / max(1, len(funcs)))

    # ---- entropy ----
    feats["byte_entropy"] = _shannon(Counter(raw).values())
    feats["identifier_entropy"] = _shannon(Counter(non_kw).values())
    feats["line_len_entropy"] = _shannon(Counter(line_lens).values())

    # ---- control flow ----
    def rc(key):
        return float(len(_RX[key].findall(raw)))
    n_if = rc("if"); n_for = rc("for"); n_while = rc("while")
    n_switch = rc("switch"); n_case = rc("case"); n_goto = rc("goto")
    n_and = rc("and"); n_or = rc("or")
    feats["n_if"] = n_if; feats["n_for"] = n_for; feats["n_while"] = n_while
    feats["n_switch"] = n_switch; feats["n_case"] = n_case; feats["n_goto"] = n_goto
    feats["n_return"] = rc("return"); feats["n_break"] = rc("break")
    feats["cyclomatic_proxy"] = 1.0 + n_if + n_for + n_while + n_case + n_and + n_or
    feats["branch_density"] = (n_if + n_for + n_while + n_switch) / max(1, len(nonblank))

    # ---- literal ----
    strs = _STRING_LIT.findall(raw)
    n_hex = float(len(_HEX_CONST.findall(raw)))
    n_int = float(len(_INT_CONST.findall(raw)))
    feats["n_hex_const"] = n_hex
    feats["n_int_const"] = n_int
    feats["n_string_lit"] = float(len(strs))
    feats["mean_string_len"] = (sum(len(s) for s in strs) / max(1, len(strs)))
    feats["n_char_lit"] = float(len(_CHAR_LIT.findall(raw)))
    feats["n_char_array"] = float(len(_CHAR_ARRAY.findall(raw)))
    feats["hex_to_int_ratio"] = n_hex / max(1.0, n_int)

    # ---- operator ----
    feats["n_arith_op"] = rc("arith")
    feats["n_bitwise_op"] = rc("bitwise")
    feats["n_shift_op"] = rc("shift")
    feats["n_logical_op"] = n_and + n_or
    feats["n_xor_op"] = rc("xor")
    feats["n_assign_op"] = rc("assign")
    feats["operator_density"] = (feats["n_arith_op"] + feats["n_bitwise_op"] +
                                 feats["n_xor_op"]) / max(1, len(raw))

    # ---- api buckets ----
    low = raw.lower()
    for bucket, toks in _API_BUCKETS.items():
        feats[bucket] = float(sum(low.count(t.lower()) for t in toks))

    # ---- obfuscation indicators ----
    for name, rx in _OBF_RX.items():
        feats[name] = float(len(rx.findall(raw)))
    comments = _LINE_COMMENT.findall(raw) + _BLOCK_COMMENT.findall(raw)
    comment_chars = sum(len(c) for c in comments)
    feats["n_comments"] = float(len(comments))
    feats["comment_char_ratio"] = comment_chars / max(1, len(raw))
    feats["n_includes"] = float(len(_INCLUDE.findall(raw)))
    feats["preprocessor_ratio"] = float(len(_RX["preproc"].findall(raw))) / max(1, len(lines))

    return feats


def extract_from_file(path: str) -> Dict[str, float]:
    """Read a file defensively (bounded window) and return its feature dict."""
    true_size = os.path.getsize(path)
    with open(path, "r", encoding="utf-8", errors="ignore") as fh:
        text = fh.read(MAX_SCAN_BYTES)
    return extract_features(text, true_size_bytes=true_size)


def vectorize(feats: Dict[str, float], families: List[str] | None = None) -> List[float]:
    """Project a feature dict onto the canonical ordered vector."""
    return [float(feats.get(name, 0.0)) for name in feature_names(families)]
