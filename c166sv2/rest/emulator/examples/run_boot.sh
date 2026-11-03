#!/usr/bin/env bash
set -eu
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$ROOT"
python3 -m emulator.tools.run \
  --dump dumps/mash_dump.bin \
  --reset \
  --out emulator/out/boot \
  --stop-after 3000000 \
  --trace-limit 200000
