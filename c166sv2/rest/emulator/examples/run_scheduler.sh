#!/usr/bin/env bash
set -eu
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
cd "$ROOT"
python3 -m emulator.tools.run \
  --dump dumps/mash_dump.bin \
  --reset \
  --no-default-stops \
  --out emulator/out/scheduler \
  --stop-after 4000000 \
  --trace-limit 200000 \
  --tick-every 1000 \
  --watch-phys 0x00C93C \
  --watch-phys 0x00C962 \
  --watch-phys 0xC0B09C
