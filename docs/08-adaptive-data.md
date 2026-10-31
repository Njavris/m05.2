# 8. Runtime adaptation/EEPROM log (0xC04000–0xC04CFF)

## 8.1 Why this region matters

The four dumps were taken minutes apart. All three flash checksums are identical
in every dump, but bytes in **0x4600–0x4BFF** change. This region is therefore
runtime-mutable data, not immutable flash code. It is outside every flash
checksum by design.

Physical possibilities:

1. an external serial EEPROM read by the SSC0 engine and placed at this offset
   by the dump tool;
2. an emulated EEPROM area in a spare flash sector that the ECU erases/rewrites;
3. a RAM/adaptation snapshot embedded by the reading tool.

The dump alone does not prove which one. What is proven is that the data is
**wear-leveled**, **record-structured**, and **changes while the ECU is running**.

## 8.2 Record layout

The region is organized as 0x200-byte records:

```
+0x000  uint16_t sequence        (little-endian, e.g. 0x0448)
+0x002  payload                 (0x1FA bytes)
+0x1FC  0x5A 0xA5               fixed signature
+0x1FE  uint16_t tail_value      (big-endian, e.g. 0x2B03)
```

Observed records in `dumps/mash_dump.bin` (file offsets; physical = 0xC00000 + offset):

| Offset | Sequence | Tail |
|---:|---:|---:|
| 0x004000 | 0x044B | 0x2E00 |
| 0x004200 | 0x044C | 0x2E00 |
| 0x004400 | 0x044D | 0x2FFF |
| 0x004600 | 0x0448 | 0x2B03 |
| 0x004800 | 0x0449 | 0x2B03 |
| 0x004A00 | 0x044A | 0x2B03 |
| 0x004C00 | 0x0001 | 0x52AD (0x100-byte record; signature at 0x4CFC) |

The 0x4C00 area is a 0x100-byte record (first word 0x0001, `5A A5 52 AD`
signature at 0x4CFC). It is structurally different from the 0x200-byte records
and is probably a header or a partially written record; its exact role is
unknown.

The tail value is **not** a simple 16-bit sum or one of the common CRC-16
variants over the whole record. It is likely a payload checksum or record tag
computed by a proprietary routine. The `5A A5` signature is constant.

## 8.3 Dump-to-dump changes

| Dump | 0x4600 record | 0x4800 record | 0x4A00 record | Interpretation |
|---|---|---|---|---|
| `dumps/mash_dump.bin` | seq 0x0448, tail 0x2B03 | seq 0x0449, tail 0x2B03 | seq 0x044A, tail 0x2B03 | base read |
| `mash_dump_1.bin` | identical to base | identical | identical | same ECU state |
| `mash_dump_05_2_2.bin` | seq 0x044E, tail 0x2D01 | seq 0x044F, tail 0x2D01 | seq 0x044A, tail 0x2B03 | two slots updated |
| `mash_dump_05_0_2.bin` | seq 0x044E, tail 0x2D01 | seq 0x044F, tail 0x2D01 | seq 0x0450, tail 0x2E00 | all three updated |

This is a clear chronological sequence:

1. base dump: slots 1–3 contain the old adaptation set (tail 0x2B03);
2. intermediate read: slots 1–2 were rewritten (tail 0x2D01), slot 3 still old;
3. later read: slot 3 was rewritten too (tail 0x2E00).

The ECU writes the adaptation set **one 0x200-byte slot at a time**. The records
at 0x4000–0x4400 (sequence 0x44B–0x44D) are another generation of the same
log and were not rewritten between these reads.

## 8.4 What changed in the payload

The changed bytes are concentrated in the record header and in a set of
counter-like fields, for example:

* first word 0x0448 → 0x044E (sequence)
* 0x4604 `BE` → `8F`, 0x460C `40` → `6F`, 0x460E `E9` → `E5`
* repeated values in the 0x0080/0x9A79 pattern (learned table cells)
* small counters near the end of the record

The payload is consistent with **adaptive/learned values** (idle learn, fuel
trim, sensor offsets, or a combination). the live-data profile's live-data fields identify the
fuel-learning quantities the ECU exposes: `VAFCMULT` (airflow correction),
`FBLMCOR1/2` (long-term fuel trim), `FCLCINT1/2`/`FCLCMUL1/2` (closed-loop
integrators/multipliers), `FCNO`/`VAFCCLNUM` (BLM/airflow cell), `PRUNTIME`,
and `IGNCOUNT` (via `21 FF`). The log's learned cells are therefore most likely
fuel-trim/BLM and runtime/ignition counters, but the individual bytes still
cannot be assigned without a RAM snapshot or a controlled write/read session.
`artifacts/eeprom_records.csv` lists the record headers; `artifacts/dump_differences.csv`
lists every differing byte range.

## 8.5 Why the checksums do not change

The three integrity blocks are:

| Block | Checksum range |
|---|---|
| Boot | 0xC00000–0xC01FFD |
| Calibration | 0xC05000–0xC0AFFD |
| Application | 0xC0B000–0xC3FFFB |

The adaptation log at 0xC04000–0xC04CFF lies in the **gap** between the boot
block and the calibration block and is deliberately excluded from all three
sums. This is consistent with a data area that is rewritten during normal
operation.

## 8.6 Confidence and unknowns

| Claim | Confidence |
|---|---|
| Region is runtime-mutable, record-structured, and outside all flash checksums | High |
| 0x200-byte records with sequence word, payload, `5A A5`, 16-bit tail | High |
| Sequence number is a generation counter | High from the observed progression |
| Tail is a checksum/tag of the payload | Medium (simple sums/CRCs ruled out) |
| Physical storage is external EEPROM vs. emulated flash vs. tool snapshot | Unknown |
| Payload includes fuel-trim/BLM/runtime learning | Medium from live-data fields |
| Meaning of individual learned values | Unknown |
