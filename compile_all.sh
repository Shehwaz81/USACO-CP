#!/usr/bin/env bash
set -euo pipefail
ROOT="$(pwd)"
find . -name '*.cpp' | while read -r f; do
  out="${f%.cpp}"
  echo "[BUILD] $f -> $out"
  /usr/bin/clang++ -std=c++17 -O2 -Wall -Wextra -g "$f" -o "$out"
done
echo "Done."