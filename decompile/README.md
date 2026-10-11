# decompile/ -- decompilation-only staging tool

**Scope: this directory turns one raw sample into `<sample>.c` +
`<sample>_analysis.json`. Nothing else.** It does not generate any obfuscated
variant, does not encrypt or repackage anything, and does not execute or
interpret any sample. It is the *only* piece of the documented
`malware_analysis_pipeline` (see `../../dataset/README.md`) reproduced in this
repository.

## Why this exists, and what's still missing

`dataset/README.md` describes a pipeline with two conceptually separate
stages:

1. **Decompilation / surrogate generation** -- turn a raw sample into a `.c`
   translation unit + analysis JSON (Ghidra headless for native binaries, a
   synthetic text stub for scripts). Purely static, execution-free.
2. **Obfuscation-variant generation** -- 11 modules that transform that `.c`
   file into 44 obfuscated artifacts per sample (encryption carriers,
   polymorphic generators, anti-debugging, VM obfuscation, packers, ROP
   stubs, ...).

Only **stage 1** is implemented here. Stage 2 is a general-purpose malware
obfuscation/evasion engine, which is not something built in this repository
(see the discussion that led to this directory). To get from this tool's
output to a corpus `obfuscope.build_dataset` can consume, you still need
stage 2 -- source it from the pipeline's original author
(dataset/README.md credits Khaled Saleh, Wright State University) or your own
institution's tooling.

## What's in here

```
decompile/
├── run_headless.sh              # Ghidra analyzeHeadless wrapper for ONE native binary
├── ghidra_scripts/
│   └── ExportDecompiled.py      # Ghidra post-script: decompile + export (Jython, runs inside Ghidra)
├── script_stub.py                # non-binary (.ps1/.vbs/.bat/.js/.py) text-embedding fallback
└── decompile_batch.py            # drives run_headless.sh / script_stub.py over a whole directory
```

## Safety

- Samples are **live malware** (per `dataset/README.md`). Run this only in an
  isolated VM with no production network and no shared storage.
- `analyzeHeadless` performs static disassembly/decompilation only -- Ghidra
  never executes the target binary. `script_stub.py` never interprets the
  script it reads; it only embeds the raw text as an opaque C string literal
  and computes text statistics (line count, size, quoted-literal extraction).
- Neither tool produces anything that evades detection or adds capability to
  the sample -- the output is strictly less capable than the input (inert
  text/JSON, not executable).

## Requirements

- [Ghidra](https://ghidra-sre.org/) installed, with `GHIDRA_HOME` pointing at
  its install directory (so `$GHIDRA_HOME/support/analyzeHeadless` exists), or
  `analyzeHeadless` already on `PATH`.
- Plain Python 3 for `script_stub.py` / `decompile_batch.py` (stdlib only, no
  dependency on the `obfuscope` package or its scientific-stack requirements).

## Usage

Single native binary:

```bash
./run_headless.sh /path/to/sample.exe output_reports/sample.exe
```

Single script sample (no Ghidra needed):

```bash
python3 script_stub.py /path/to/sample.ps1 output_reports/sample.ps1
```

Whole directory, dispatching automatically by extension:

```bash
python3 decompile_batch.py --input-dir /path/to/isolated_vm/raw_samples \
    --out output_reports --limit 0
```

Each sample gets its own `output_reports/<sample>/<sample>.c` and
`output_reports/<sample>/<sample>_analysis.json`. That's as far as this
directory takes you -- there are no `*_variants/` subfolders, because those
come from the (not-included) obfuscation-generation stage.

## Notes on the analysis JSON schema

`ExportDecompiled.py` and `script_stub.py` both emit `complexity_metrics` /
`extracted_strings` / `decompiled_code_path`-shaped keys because
`dataset/README.md` §6 mentions those field names as inputs to the (missing)
`dataset_generator.py`. The exact schema was inferred from that description,
not copied from the original tool's source, so field names may need minor
adjustment if you later plug in the real obfuscation-generation stage.
