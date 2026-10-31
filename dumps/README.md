# Original ECU dumps

These are the read-only inputs for the analysis. They are four 262,144-byte
reads of the same Delphi MT05.2 ECU, taken minutes apart.

| File | Size | SHA-256 |
|---|---:|---|
| `mash_dump.bin` | 262,144 B | `e413f54ffa1c2c53cedaa603dd9d572e4b5485310d83ab477332efbd933a37d2` |
| `mash_dump_1.bin` | 262,144 B | `e413f54ffa1c2c53cedaa603dd9d572e4b5485310d83ab477332efbd933a37d2` |
| `mash_dump_05_0_2.bin` | 262,144 B | `b67c1d01e07ed8b063c24dcc70a5ca442f1243431846ba1e33b3f7da48356eaf` |
| `mash_dump_05_2_2.bin` | 262,144 B | `67eb490fed7dcdf20f1f8abe9a0baca5e582d74641cba649ac4e5783ac8b4295` |

`mash_dump.bin` and `mash_dump_1.bin` are byte-identical. The other two differ
only inside the adaptation log at offsets 0x4600–0x4BFF. `mash_dump.bin` is the
baseline used by the source tree and reports.

`SHA256SUMS.txt` is the machine-readable checksum file.
