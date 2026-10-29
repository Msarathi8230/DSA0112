#!/usr/bin/env bash
set -euo pipefail
CXX="${CXX:-g++}"
FLAGS=(-std=c++17 -Wall -Wextra -pedantic)
mkdir -p Task02/outputs Task03/outputs Task04/outputs Task05/outputs Task06/outputs Task07/outputs Task08/outputs Task09/outputs Task10/outputs Task11/outputs Task12/outputs
compile_run() {
  local src="$1" outdir="$2" input="${3:-}"
  local exe="${outdir}/program"
  "$CXX" "${FLAGS[@]}" "$src" -o "$exe" 2>"${outdir}/compile_warnings.txt"
  if [[ -n "$input" ]]; then printf '%s\n' "$input" | "$exe" >"${outdir}/stdout.txt" 2>"${outdir}/stderr.txt" || true
  else "$exe" >"${outdir}/stdout.txt" 2>"${outdir}/stderr.txt"; fi
}
compile_run Task02/tokens_constants.cpp Task02/outputs
compile_run Task03/types.cpp Task03/outputs
compile_run Task04/predict_output.cpp Task04/outputs
compile_run Task05/operators.cpp Task05/outputs
compile_run Task06/complete_code.cpp Task06/outputs
compile_run Task06/boundary_times.cpp Task06/outputs
cp Task06/outputs/stdout.txt Task06/outputs/boundary_times_stdout.txt
compile_run Task06/complete_code.cpp Task06/outputs
compile_run Task07/procedural.cpp Task07/outputs
cp Task07/outputs/stdout.txt Task07/outputs/procedural_stdout.txt
compile_run Task07/oop.cpp Task07/outputs
cp Task07/outputs/stdout.txt Task07/outputs/oop_stdout.txt
compile_run Task08/safe_io.cpp Task08/outputs 8
compile_run Task09/fare_tests.cpp Task09/outputs
compile_run Task10/totals.cpp Task10/outputs
compile_run Task11/final_design.cpp Task11/outputs
compile_run Task12/revised_design.cpp Task12/outputs
echo 'All task programs compiled and executed.'
