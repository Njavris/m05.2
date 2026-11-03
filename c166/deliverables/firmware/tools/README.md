# Tools

All tools are Python 3 and operate on the original 256 KB image. They do not
need a C166 toolchain.

| Tool | Purpose |
|---|---|
| `verify_checksums.py` | print SHA-256 and verify the three block checksums |
| `generate_listing.py` | regenerate `asm/firmware.s` from a dump |
| `assemble_listing.py` | assemble `asm/firmware.s` into a 256 KB image |
| `compare_image.py` | byte-compare two images and verify both checksums |
| `patch_calibration.py` | patch bytes and repair the containing checksum |
| `collect_ghidra.py` | combine the per-function C/ASM reference into `decompiled_all.c` and `.asm` |
| `visualize_maps.py` | render calibration maps as SVG/HTML (no third-party packages) |
| `fuel_map_viewer.py` | interactive 2D/3D fuel/VE map, with optional A/B diff |
| `build_reconstruction.py` | build `../../deliverables/reconstruction/` in three parts (bootloader/application/data) with C data arrays |

## Typical workflows

### Verify the supplied dump

```bash
python3 tools/verify_checksums.py ../../../dumps/mash_dump.bin
```

### Rebuild the exact original image

```bash
make repro
```

or manually:

```bash
python3 tools/assemble_listing.py asm/firmware.s build/firmware_rebuilt.bin
python3 tools/compare_image.py ../../../dumps/mash_dump.bin build/firmware_rebuilt.bin
```

### Patch a calibration table

```bash
python3 tools/patch_calibration.py ../../../dumps/mash_dump.bin /tmp/tuned.bin \
    0xC0794D 11,22,33,44
python3 tools/verify_checksums.py /tmp/tuned.bin
```

`patch_calibration.py` recomputes the checksum of the block containing the
patch. It does not recompute the other blocks and does not touch the adaptation
log.

### Build the reconstruction tree

```bash
make reconstruction
```

This writes `../../deliverables/reconstruction/` with `01-bootloader/`, `02-application/` and
`03-data/`. The executable parts have one consolidated C/ASM pair each; all
tables, records, live-data maps and the function index are C arrays/structs in
`03-data/`. There are no CSV files in the tree.

### Visualise the calibration maps

```bash
make maps
```

This writes `../c166sv2/deliverables/artifacts/maps/index.html`, one SVG per table, `maps.json`,
`decoded_tables.csv`, and the interactive `fuel_map.html`. The heatmap axes are
table indices; the physical axis descriptors are in external RAM and are not in
the dump.

For only the 9×9 fuel/VE map:

```bash
make fuel-map
```

Compare two dumps with:

```bash
python3 tools/fuel_map_viewer.py --dump ../../../dumps/mash_dump.bin \
    --compare ../../../dumps/mash_dump_05_0_2.bin \
    --out ../c166sv2/deliverables/artifacts/maps/fuel_map_diff.html
```

### Combine the Ghidra output

```bash
make collect
```

This writes `reference/decompiled_all.c` (all C function bodies) and
`reference/decompiled_all.asm` (all instruction listings).

### Regenerate the reproduction listing

Only needed if you change the baseline dump:

```bash
python3 tools/generate_listing.py ../../../dumps/mash_dump.bin asm/firmware.s
```
