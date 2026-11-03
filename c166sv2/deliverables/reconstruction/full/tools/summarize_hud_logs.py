#!/usr/bin/env python3
"""Summarize HUD ECU Hacker MT05/MT05.3 log files for the reconstruction.

The 21 01 payload is decoded with the HUD parameter offsets and simple HUD
scaling formulas. This is evidence for units/ranges, not a runtime trace of
the target ECU.
"""
from __future__ import annotations
import base64, csv, math, re, xml.etree.ElementTree as ET
from pathlib import Path

ROOT = Path(__file__).resolve().parents[5]
CAT = Path(__file__).resolve().parents[1] / "catalog"
LOGS = [ROOT / "secret" / "MT05" / "LogFiles", ROOT / "secret" / "MT05.3" / "LogFiles"]
FIELDS = list(csv.DictReader(open(CAT / "HUD_PARAMETERS.csv")))

selected = ["VRPM", "VMAP", "VCLTS", "VIAT", "FVE1", "FPWVC1", "SPDWELL", "SAESTA", "VTHROT", "VO2", "IARDRPM"]
fmap = {r["uid"]: r for r in FIELDS if r["command"] == "21 01"}


def decode_byte(b, off, n, signed):
    if n == 1:
        v = b[off]
    else:
        v = (b[off] << 8) | b[off + 1]
    if signed and v & 0x8000:
        v -= 0x10000
    return v


def scale(uid, raw):
    f = fmap.get(uid, {}).get("formula", "")
    m = re.fullmatch(r"\$Val/([0-9.]+)", f)
    if m:
        return raw / float(m.group(1))
    return float(raw)


rows = []
for folder in LOGS:
    if not folder.exists():
        continue
    for p in sorted(folder.glob("*.xml")):
        try:
            root = ET.parse(p).getroot()
        except Exception:
            continue
        vals = {uid: [] for uid in selected}
        samples = 0
        for sample in root.findall("Sample"):
            cmds = sample.findall("Cmd")
            c = next((x for x in cmds if x.attrib.get("ID", "").lower() == "2101"), None)
            if c is None or not c.text:
                continue
            try:
                b = base64.b64decode(c.text.strip(), validate=False)
            except Exception:
                continue
            if len(b) < 100:
                continue
            samples += 1
            for uid in selected:
                f = fmap.get(uid)
                if not f or not f["offset"]:
                    continue
                off = int(f["offset"], 16)
                n = int(f["bytes"] or 0)
                if off + n > len(b):
                    continue
                raw = decode_byte(b, off, n, f["type"] == "Signed")
                vals[uid].append(scale(uid, raw))
        if not samples:
            continue
        row = {
            "file": p.name,
            "ecu": root.attrib.get("ECU", ""),
            "date": root.attrib.get("Date", ""),
            "samples": samples,
        }
        for uid in selected:
            xs = vals[uid]
            row[uid + "_min"] = f"{min(xs):.4g}" if xs else ""
            row[uid + "_max"] = f"{max(xs):.4g}" if xs else ""
        rows.append(row)

fields = ["file", "ecu", "date", "samples"]
for uid in selected:
    fields += [uid + "_min", uid + "_max"]
with open(CAT / "HUD_LOG_SUMMARY.csv", "w", newline="", encoding="utf-8") as f:
    w = csv.DictWriter(f, fieldnames=fields)
    w.writeheader()
    w.writerows(rows)
print("logs", len(rows), "samples", sum(r["samples"] for r in rows))
