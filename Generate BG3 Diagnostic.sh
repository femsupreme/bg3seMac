#!/usr/bin/env bash
OUT_FILE="${TMPDIR:-/tmp}/BG3 Diagnostic Data.txt"
{
  echo "Basic System Information"
  echo "========================"
  sw_vers 2>/dev/null
  uname -a
  echo
  echo "BG3 Install Locations"
  ls -d /Applications/*Baldur*Gate*3* 2>/dev/null || true
} > "$OUT_FILE"

if command -v open >/dev/null; then
  open -R "$OUT_FILE"
else
  echo "Diagnostic data written to $OUT_FILE"
fi
