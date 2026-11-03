#!/usr/bin/env python3
"""Build the full MT05.2 reconstruction catalog and reference tree.

Inputs are the evidence already in the repository:
  * c166sv2/rest/artifacts/ghidra-full/{functions.csv,decompiled/}
  * c166/deliverables/firmware/{SEMANTIC_INDEX,AUTO_NAMES,AUTO_VARIABLES}.csv
  * c166sv2/deliverables/artifacts/live_firmware_map.csv
  * secret/MT05/Parameters/Delphi + Rongmao MT05.xml
  * secret/MT05/Translation/English.xml
  * secret/MT05/Tuning/*.xml

Outputs are C catalogs, public headers and a named reference tree.
"""
from __future__ import annotations

import base64
import csv
import hashlib
import os
import re
import shutil
import xml.etree.ElementTree as ET
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[5]
FW = ROOT / "c166" / "deliverables" / "firmware"
FULL = Path(__file__).resolve().parents[1]
ART = ROOT / "c166sv2" / "rest" / "artifacts" / "ghidra-full"
LIVE_MAP = ROOT / "c166sv2" / "deliverables" / "artifacts" / "live_firmware_map.csv"
DEC = ART / "decompiled"
CAT = FULL / "catalog"
INC = FULL / "include" / "mt05"
SRC = FULL / "src"
REF = FULL / "reference"
HUD_XML = ROOT / "secret" / "MT05" / "Parameters" / "Delphi + Rongmao MT05.xml"
HUD_EN = ROOT / "secret" / "MT05" / "Translation" / "English.xml"
TUNING = ROOT / "secret" / "MT05" / "Tuning"

for p in (CAT, INC, SRC, REF):
    p.mkdir(parents=True, exist_ok=True)
if REF.exists():
    shutil.rmtree(REF)
REF.mkdir(parents=True, exist_ok=True)


def read_csv(path):
    with open(path, newline="", encoding="utf-8") as f:
        return list(csv.DictReader(f))


def write_csv(path, fields, rows):
    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=fields)
        w.writeheader()
        w.writerows(rows)


def clean(s):
    return re.sub(r"\s+", " ", (s or "")).strip()


def cstr(s):
    return '"' + clean(s).replace("\\", "\\\\").replace('"', '\\"') + '"'


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for b in iter(lambda: f.read(1 << 20), b""):
            h.update(b)
    return h.hexdigest()


def addr_value(s):
    try:
        return int(str(s).strip().lower().replace("0x", ""), 16)
    except Exception:
        return None


# ---------------------------------------------------------------------------
# Evidence maps
# ---------------------------------------------------------------------------
curated = {}
for r in read_csv(FW / "SEMANTIC_INDEX.csv"):
    if r["kind"] != "function":
        continue
    a = addr_value(r["address_or_range"])
    if a is not None:
        curated[a] = r

auto = {}
for r in read_csv(FW / "AUTO_NAMES.csv"):
    a = addr_value(r["address"])
    if a is not None:
        auto[a] = r

variables = {}
for r in read_csv(FW / "SEMANTIC_INDEX.csv"):
    if r["kind"] != "variable":
        continue
    a = addr_value(r["address_or_range"])
    if a is None:
        continue
    variables.setdefault(a, []).append(
        {
            "name": r["name"],
            "category": r["category"],
            "kind": "ram" if a < 0xC00000 else "flash",
            "width": 0,
            "evidence": r["evidence"],
            "confidence": "high" if r["confidence"] == "semantic" else "low",
            "source": "SEMANTIC_INDEX.csv",
        }
    )
for r in read_csv(FW / "AUTO_VARIABLES.csv"):
    a = addr_value(r["address"])
    if a is None:
        continue
    variables.setdefault(a, []).append(
        {
            "name": r["name"],
            "category": r["kind"],
            "kind": r["kind"],
            "width": int(r["width"] or 0),
            "evidence": r["evidence"],
            "confidence": r["confidence"],
            "source": "AUTO_VARIABLES.csv",
        }
    )

live_alias = defaultdict(list)
for r in read_csv(LIVE_MAP):
    a = addr_value(r["firmware_address"])
    if a is None:
        continue
    live_alias[a].append(r)

GENERIC = re.compile(
    r"^(DAT_|ram_var_|UNK_|LAB_|diag_flag_|ssc_var_|event_var_|"
    r"kline_var_|sensor_var_|capture_var_)"
)
SEMANTIC_CALLEE = (
    "tbl8_interp", "tbl16_interp", "tbl2d_interp", "axis16_unsigned",
    "axis16_signed", "mul32", "div32u", "sat_add_u16", "sat_add_s16",
    "sat_sub_u16", "mul_shift_u16", "rate_limit",
)


def semantic_names_for_addr(a):
    out = []
    for v in variables.get(a, []):
        if not GENERIC.match(v["name"]) and v["name"] not in out:
            out.append(v["name"])
    return out


C_GROUPS = {
    "00-reset": "mt05_boot.c",
    "01-boot": "mt05_boot.c",
    "02-hidden-boot": "mt05_boot.c",
    "04-kline-kwp": "mt05_comm.c",
    "05-can": "mt05_comm.c",
    "06-ssc": "mt05_comm.c",
    "07-diagnostics": "mt05_diagnostics.c",
    "11-adaptation": "mt05_diagnostics.c",
    "08-io-timing": "mt05_io_timing.c",
    "09-engine-calc": "mt05_engine.c",
    "10-math": "mt05_math.c",
    "12-app-low": "mt05_application.c",
    "13-app-io": "mt05_application.c",
    "14-app-runtime": "mt05_application.c",
}
C_GROUP_ORDER = [
    "mt05_boot.c", "mt05_comm.c", "mt05_diagnostics.c",
    "mt05_io_timing.c", "mt05_engine.c", "mt05_math.c",
    "mt05_application.c",
]


def merge_asm_refs(funcs, fn_map):
    """Merge the 902 named ASM files into the same domain-level groups."""
    groups = {name: [] for name in C_GROUP_ORDER}
    for f in funcs:
        groups[C_GROUPS[f["area"]]].append(f)
    for group_name in C_GROUP_ORDER:
        asm_name = Path(group_name).with_suffix(".asm").name
        members = sorted(groups[group_name], key=lambda f: int(f["address"], 16))
        lines = [
            "; ============================================================================",
            f"; MT05.2 / C166SV2 reconstruction: {asm_name}",
            "; Generated by c166sv2/deliverables/reconstruction/full/tools/build_catalog.py.",
            "; Each function starts with an address/name/source separator.",
            "; This is Ghidra instruction output, not original source.",
            "; ============================================================================",
            "",
        ]
        for f in members:
            src = DEC / Path(f["source_asm"]).name
            if not src.exists():
                continue
            lines += [
                "; -------------------------------------------------------------------------",
                f"; {f['address']}  {f['name']}",
                f"; area={f['area']} category={f['category']} confidence={f['confidence']}",
                f"; source={f['source_asm']}",
                "; -------------------------------------------------------------------------",
            ]
            start_line = len(lines) + 1
            body = src.read_text(errors="ignore")
            lines += body.rstrip("\n").splitlines()
            lines.append("")
            f["reference_asm"] = f"reference/asm_project/{asm_name}"
            f["reference_asm_line"] = str(start_line)
        out = REF / "asm_project" / asm_name
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text("\n".join(lines) + "\n")

def build_rename_maps(funcs):
    old_by_addr = {int(r["address"], 16): r["name"] for r in read_csv(ART / "functions.csv")}
    fn_map = {}
    for f in funcs:
        a = int(f["address"], 16)
        old = old_by_addr.get(a, "")
        if old and old != f["name"]:
            fn_map[old] = f["name"]
        if old.startswith("FUN_"):
            fn_map[f"func_0x{a:x}"] = f["name"]
    # Calls into addresses that the final pass did not expose as functions can
    # still be named from the reviewed/archived XC164CS evidence.
    archive = {}
    archive_path = FW / "AUTO_NAMES_XC164CS.csv"
    if archive_path.exists():
        for r in read_csv(archive_path):
            a = addr_value(r["address"])
            if a is not None:
                archive[a] = r["auto_name"]
    for a, name in archive.items():
        fn_map.setdefault(f"func_0x{a:x}", name)
        fn_map.setdefault(f"FUN_c{a:x}", name)
        fn_map.setdefault(f"gap_c{a:x}", name)
    var_map = {}
    for addr, entries in variables.items():
        names = [v["name"] for v in entries
                 if v["name"] and not re.match(r"^(DAT_|ram_var_|UNK_|LAB_)", v["name"])
                 and v["confidence"] in ("high", "medium")]
        if not names:
            continue
        name = names[0]
        for key in (f"DAT_{addr:06x}", f"DAT_{addr:04x}", f"UNK_{addr:06x}",
                    f"Ram{addr:06x}", f"Ram{addr:04x}",
                    f"uRam{addr:06x}", f"bRam{addr:06x}", f"_DAT_{addr:06x}"):
            var_map[key] = name
    mem_map = {}
    for addr, entries in variables.items():
        names = [v["name"] for v in entries
                 if v["name"] and not re.match(r"^(DAT_|ram_var_|UNK_|LAB_)", v["name"])]
        if not names:
            continue
        name = names[0]
        for key in (f"mem_{addr:06x}", f"unk_{addr:06x}", f"ram_{addr:06x}",
                    f"uram_{addr:06x}", f"bram_{addr:06x}", f"ptr_mem_{addr:06x}"):
            mem_map[key] = name
    return fn_map, var_map, mem_map


def rename_tokens(text, *maps):
    table = {}
    for m in maps:
        table.update(m)
    # longest first so aliases such as thunk_FUN_c... do not win over the exact name
    pat = re.compile(r"\b[A-Za-z_][A-Za-z0-9_]*\b")
    def repl(m):
        return table.get(m.group(0), m.group(0))
    return pat.sub(repl, text)


TYPE_REPLACEMENTS = [
    (r"\bundefined8\b", "uint64_t"),
    (r"\bundefined3\b", "uint32_t"),
    (r"\bundefined4\b", "uint32_t"),
    (r"\bundefined2\b", "uint16_t"),
    (r"\bundefined1\b", "uint8_t"),
    (r"\bundefined\b", "uint8_t"),
    (r"\buint3\b", "uint32_t"),
    (r"\bushort\b", "uint16_t"),
    (r"\bshort\b", "int16_t"),
    (r"\buint\b", "uint32_t"),
    (r"\bbyte\b", "uint8_t"),
    (r"\bcode\b", "code"),
]


def sanitize_c_text(text):
    """Make Ghidra pseudo-C read like ordinary typed C."""
    lines = []
    for line in text.splitlines():
        if "/* WARNING:" in line:
            continue
        if line.strip() == "/* Do nothing block with infinite loop */":
            continue
        lines.append(line)
    text = "\n".join(lines)
    for pattern, replacement in TYPE_REPLACEMENTS:
        text = re.sub(pattern, replacement, text)
    text = re.sub(r"\bDAT_([0-9a-fA-F]{4,8})\b", r"mem_\1", text)
    text = re.sub(r"\b_DAT_([0-9a-fA-F]{4,8})\b", r"mem_\1", text)
    text = re.sub(r"\bPTR_DAT_([0-9a-fA-F]{4,8})\b", r"ptr_mem_\1", text)
    text = re.sub(r"\bUNK_([0-9a-fA-F]{4,8})\b", r"unk_\1", text)
    text = re.sub(r"\buRam([0-9a-fA-F]{4,8})\b", r"uram_\1", text)
    text = re.sub(r"\bbRam([0-9a-fA-F]{4,8})\b", r"bram_\1", text)
    text = re.sub(r"\bRam([0-9a-fA-F]{4,8})\b", r"ram_\1", text)
    text = re.sub(r"\bfunc_0x([0-9a-fA-F]+)\b", r"sub_c\1", text)
    text = re.sub(
        r"^// (c[0-9a-f]+) ([A-Za-z0-9_]+) size=(\d+).*$",
        r"/* source \1: \2, \3 bytes */",
        text,
        flags=re.MULTILINE,
    )
    text = re.sub(r"\)\n\n\{", ")\n{", text)
    text = re.sub(r"\n{3,}", "\n\n", text)
    return text


DECL_RE = re.compile(
    r"^\s*(?:uint8_t|uint16_t|uint32_t|uint64_t|int8_t|int16_t|int32_t|"
    r"uint|ushort|short|byte|bool|code|float|char|int|long)\s+([A-Za-z_]\w*)\s*;\s*$"
)
ASSIGN_RE = re.compile(r"^\s*([A-Za-z_]\w*)\s*=\s*(.+);\s*$")


def inline_single_use_temps(text):
    """Inline locals that are declared once, assigned once and used once next."""
    lines = text.splitlines()
    changed = True
    while changed:
        changed = False
        for i, line in enumerate(lines):
            m = ASSIGN_RE.match(line)
            if not m:
                continue
            var, rhs = m.group(1), m.group(2)
            if not var.startswith(("uVar", "bVar", "sVar", "iVar", "cVar", "vVar")):
                continue
            if re.search(r"\b[A-Za-z_]\w*\s*\(", rhs) or "++" in rhs or "--" in rhs:
                continue
            if len(re.findall(r"\b%s\b" % re.escape(var), "\n".join(lines))) != 3:
                continue
            decl = next((j for j, l in enumerate(lines) if DECL_RE.match(l) and
                         DECL_RE.match(l).group(1) == var), None)
            if decl is None:
                continue
            use = i + 1
            while use < len(lines) and lines[use].strip() == "":
                use += 1
            if use >= len(lines) or len(re.findall(r"\b%s\b" % re.escape(var), lines[use])) != 1:
                continue
            if lines[use].strip().startswith(("return", "if", "while", "for", "switch")):
                # still safe, but parenthesized expressions read better
                pass
            replacement = "(" + rhs + ")"
            lines[use] = re.sub(r"\b%s\b" % re.escape(var), replacement, lines[use], count=1)
            # Remove only the assignment; the declaration is cleaned at the end.
            del lines[i]
            changed = True
            break
    # Fold x = (x) op y into compound assignments.
    text = "\n".join(lines)
    text = re.sub(r"(\b[A-Za-z_]\w*\b)\s*=\s*\(\s*\1\s*\)\s*([&|^])\s*([^;]+);",
                  r"\1 \2= \3;", text)
    return text


MEM_TYPES = {
    "uint8_t": "MEM8", "char": "MEM8S", "int8_t": "MEM8S",
    "uint16_t": "MEM16", "int16_t": "MEM16S",
    "uint32_t": "MEM32", "int32_t": "MEM32S",
}


def replace_memory_derefs(text):
    """Turn layered pointer casts into explicit memory-access macros."""
    changed = True
    while changed:
        changed = False
        for typ, macro in MEM_TYPES.items():
            marker = f"*({typ} *)"
            start = 0
            while True:
                pos = text.find(marker, start)
                if pos < 0:
                    break
                j = pos + len(marker)
                while j < len(text) and text[j] in " \t":
                    j += 1
                if j < len(text) and text[j] == "(":
                    depth = 0
                    k = j
                    while k < len(text):
                        if text[k] == "(":
                            depth += 1
                        elif text[k] == ")":
                            depth -= 1
                            if depth == 0:
                                break
                        k += 1
                    if k < len(text):
                        inner = text[j + 1:k].lstrip()
                        bad = inner.startswith(("MEM", "*")) or re.match(
                            r"\(\s*(?:uint16_t|int16_t|uint32_t|int32_t|char)\s*\*+\)",
                            inner,
                        )
                        if not bad:
                            text = text[:pos] + f"{macro}" + text[j:k + 1] + text[k + 1:]
                            changed = True
                            start = pos + 1
                            continue
                m = re.match(r"([A-Za-z_]\w*)", text[j:])
                if m:
                    end = j + len(m.group(1))
                    text = text[:pos] + f"{macro}({m.group(1)})" + text[end:]
                    changed = True
                    start = pos + 1
                    continue
                start = pos + 1
    return text


def refactor_indirect_calls(text):
    """Name table-dispatched calls instead of inline address/cast expressions."""
    app_pat = re.compile(
        r"\(\*\(code \*\)\(\(uint32_t\)\*\(uint16_t \*\)"
        r"\((.+?) & 0x3fff\) \| 0xc10000\)\s*\)\s*\(\)"
    )

    def app_repl(m):
        inner = m.group(1)
        mm = re.match(r"(.+?)\s*\*\s*2\s*\+\s*0x([0-9a-fA-F]+)\s*$", inner)
        if not mm:
            return m.group(0)
        index, table = mm.group(1).strip(), int(mm.group(2), 16)
        return f"call_app_slot(0x{table:04x}, (uint16_t)({index}))"

    text = app_pat.sub(app_repl, text)
    boot_pat = re.compile(
        r"\(\*\(code \*\)\(\(uint32_t\)\*\(uint16_t \*\)"
        r"\((.+?)\) \| 0xc00000\)\)\(\)"
    )

    def boot_repl(m):
        inner = m.group(1)
        mm = re.match(r"(.+?)\s*\*\s*2\s*\+\s*0x([0-9a-fA-F]+)\s*$", inner)
        if not mm:
            return m.group(0)
        index, table = mm.group(1).strip(), int(mm.group(2), 16)
        return f"call_boot_slot(0x{table:04x}, (uint16_t)({index}))"

    return boot_pat.sub(boot_repl, text)


def simplify_comma_conditions(text):
    """Replace the common `(x = v, x == c)` idiom with a named macro."""
    text = re.sub(
        r"\((\w+) = ([^,()]+), \1 == ([^,()]+)\)",
        r"ASSIGN_EQ(\1, \2, \3)",
        text,
    )
    text = re.sub(
        r"\((\w+) = ([^,()]+), \1 != ([^,()]+)\)",
        r"ASSIGN_NE(\1, \2, \3)",
        text,
    )
    return text


def simplify_pointer_casts(text):
    # *(T *)(uint32_t)((int16_t)&sym + off) -> *(T *)((uint8_t *)&sym + off)
    text = re.sub(
        r"\*\((uint(?:8|16|32)_t) \*\)\(uint32_t\)\(\(int16_t\)&([A-Za-z_]\w*)",
        r"*(\1 *)((uint8_t *)&\2",
        text,
    )
    # *(T *)(uint32_t)(uint16_t)((int16_t)&sym ...) -> byte-pointer form
    text = re.sub(
        r"\*\((uint(?:8|16|32)_t) \*\)\(uint32_t\)\(uint16_t\)\(\(int16_t\)&([A-Za-z_]\w*)",
        r"*(\1 *)((uint8_t *)&\2",
        text,
    )
    # *(T *)(uint32_t)(uint16_t)(expr) -> *(T *)(expr)
    text = re.sub(
        r"\*\(((?:u?int(?:8|16|32|64)_t)|char) \*\)\(uint32_t\)\(uint16_t\)",
        r"*(\1 *)",
        text,
    )
    # *(T *)(uint32_t)(expr) / *(T *)(uint32_t)var -> *(T *)(expr) / *(T *)var
    text = re.sub(
        r"\*\(((?:u?int(?:8|16|32|64)_t)|char) \*\)\(uint32_t\)",
        r"*(\1 *)",
        text,
    )
    # (uint32_t)((int16_t)&sym -> (uint32_t)&sym
    text = re.sub(r"\(uint32_t\)\(\(int16_t\)&([A-Za-z_]\w*)", r"(uint32_t)&\1", text)
    return text


def compound_sfr_rewrites(text):
    """Fold `tmp = sfr; sfr = tmp & mask;` into `sfr &= mask;`."""
    lines = text.splitlines()
    i = 0
    while i + 1 < len(lines):
        m1 = re.match(r"^(\s*)([A-Za-z_]\w*) = ([A-Za-z_]\w*);\s*$", lines[i])
        m2 = re.match(r"^(\s*)([A-Za-z_]\w*) = ([A-Za-z_]\w*) ([&|^]) ([^;]+);\s*$", lines[i + 1])
        if m1 and m2 and m1.group(2) == m2.group(3) and m1.group(3) == m2.group(2):
            tmp, sfr = m1.group(2), m1.group(3)
            lines[i + 1] = f"{m2.group(1)}{sfr} {m2.group(4)}= {m2.group(5)};"
            # Drop the snapshot assignment when the temp has no later read.
            if not re.search(r"\b%s\b" % re.escape(tmp), "\n".join(lines[i + 2:])):
                del lines[i]
                continue
        i += 1
    return "\n".join(lines)


def remove_dead_snapshots(text):
    """Drop temp assignments whose next use is an overwrite, not a read."""
    lines = text.splitlines()
    changed = True
    while changed:
        changed = False
        for i, line in enumerate(lines):
            m = re.match(r"^\s*([A-Za-z_]\w*)\s*=\s*[^;]+;\s*$", line)
            if not m:
                continue
            var = m.group(1)
            if not var.startswith(("uVar", "bVar", "sVar", "iVar", "cVar", "vVar")):
                continue
            rhs = line.split("=", 1)[1]
            locals_ = {d.group(1) for l in lines if DECL_RE.match(l) for d in [DECL_RE.match(l)]}
            ids = set(re.findall(r"\b[A-Za-z_]\w*\b", rhs)) - {
                "true", "false", "NULL", "u8", "u16", "u32", "s8", "s16", "s32",
            }
            # A dead scalar is only removable when its RHS cannot touch hardware
            # state or call a function.
            if ids - locals_ or re.search(r"\b[A-Za-z_]\w*\s*\(", rhs):
                continue
            use = None
            for j in range(i + 1, len(lines)):
                if re.search(r"\b%s\b" % re.escape(var), lines[j]):
                    use = j
                    break
            if use is not None and not re.match(r"^\s*%s\s*=" % re.escape(var), lines[use]):
                continue
            del lines[i]
            changed = True
            break
    return "\n".join(lines)


def strip_redundant_casts(text):
    decls = {}
    for line in text.splitlines():
        m = DECL_RE.match(line)
        if m:
            parts = line.split()
            decls[m.group(1)] = parts[0]
    for var, typ in decls.items():
        text = re.sub(r"\(%s\)\s*\b%s\b" % (re.escape(typ), re.escape(var)), var, text)
    for typ in ("uint8_t", "uint16_t", "uint32_t", "uint64_t",
                "int8_t", "int16_t", "int32_t"):
        text = re.sub(r"\(%s\)\s*\(%s\)" % (typ, typ), f"({typ})", text)
    return text


LOCAL_RENAME = {
    "uVar": "u16_value",
    "bVar": "u8_value",
    "sVar": "s16_value",
    "iVar": "s32_value",
    "cVar": "char_value",
    "vVar": "value",
    "puVar": "pointer",
    "extraout_": "extra_result_",
    "in_r": "in_reg_",
    "auStack": "stack_",
}


def rename_locals(text):
    # Rename only decompiler-generated local names, never globals.
    mapping = {}
    for line in text.splitlines():
        m = DECL_RE.match(line)
        if not m:
            continue
        name = m.group(1)
        for old, new in LOCAL_RENAME.items():
            if not name.startswith(old):
                continue
            suffix = name[len(old):]
            typ = line.split()[0]
            base = new
            # Prefer a name from the first value copied into the temporary.
            am = re.search(r"\b%s\s*=\s*(?:\()?([A-Za-z_]\w*)" % re.escape(name), text)
            if am:
                src = am.group(1)
                if src.startswith(("uVar", "bVar", "sVar", "iVar", "cVar", "vVar", "puVar")):
                    pass
                elif src.startswith(("mem_", "unk_", "ram_", "uram_", "bram_")):
                    base = "mem_value"
                elif src in {"int8_t", "uint8_t", "int16_t", "uint16_t", "int32_t",
                             "uint32_t", "char", "short", "int", "long", "CONCAT11",
                             "CONCAT12", "CONCAT21", "CONCAT22", "ZEXT23", "CARRY2"}:
                    pass
                elif typ in ("bool",):
                    base = "flag_value"
                else:
                    short = next((d for d in ("kline", "ssc", "event", "diag", "capture", "sensor")
                                  if src.startswith(d + "_")), None)
                    if short:
                        base = short + "_value"
                    elif len(src) > 22:
                        base = new
                    else:
                        base = src.lower() + "_value"
            elif typ in ("bool",):
                base = "flag_value"
            if old in ("extraout_", "in_r", "auStack"):
                mapping[name] = base + suffix
            else:
                mapping[name] = base + "_" + suffix
            break
    if not mapping:
        return text
    pattern = re.compile(r"\b(" + "|".join(re.escape(x) for x in sorted(mapping, key=len, reverse=True)) + r")\b")
    return pattern.sub(lambda m: mapping[m.group(1)], text)


def use_compound_assignments(text):
    """Rewrite `x = x op y` as `x op= y` for simple lvalues."""
    pattern = re.compile(
        r"(?m)^(\s*)([A-Za-z_]\w*)\s*=\s*\2\s*"
        r"(<<|>>|[+\-*/%&|^])\s*([^;\n]+);"
    )

    def repl(m):
        indent, name, op, rhs = m.groups()
        return f"{indent}{name} {op}= ({rhs.strip()});"

    text = pattern.sub(repl, text)
    for_pat = re.compile(
        r"(for\s*\([^;]*;\s*)([A-Za-z_]\w*)\s*=\s*\2\s*"
        r"(<<|>>|[+\-*/%&|^])\s*([^;)]+)"
    )
    text = for_pat.sub(lambda m: f"{m.group(1)}{m.group(2)} {m.group(3)}= ({m.group(4).strip()})", text)
    tail_pat = re.compile(
        r"(?m)^(\s*)([A-Za-z_]\w*)\s*=\s*\2\s*"
        r"(<<|>>|[+\-*/%&|^])\s*([^;\n]+?)\)\s*(\{?)\s*$"
    )
    text = tail_pat.sub(
        lambda m: f"{m.group(1)}{m.group(2)} {m.group(3)}= ({m.group(4).strip()})){m.group(5)}",
        text,
    )
    return text


def inline_pure_locals(text):
    """Inline single-assignment locals whose value is parameter/constant-only."""
    lines = text.splitlines()
    changed = True
    while changed:
        changed = False
        for i, line in enumerate(lines):
            decl = DECL_RE.match(line)
            if not decl:
                continue
            var = decl.group(1)
            if not re.search(r"_value_\d", var):
                continue
            assigns = [j for j, l in enumerate(lines)
                       if re.match(r"^\s*%s\s*=" % re.escape(var), l)]
            if len(assigns) != 1:
                continue
            j = assigns[0]
            m = re.match(r"^\s*%s\s*=\s*(.+);\s*$" % re.escape(var), lines[j])
            if not m:
                continue
            rhs = m.group(1)
            if re.search(r"\b[A-Za-z_]\w*\s*\(", rhs):
                continue
            ids = set(re.findall(r"\b[A-Za-z_]\w*\b", rhs))
            if any(not (x.startswith("param_") or x in ("true", "false", "NULL"))
                   for x in ids):
                continue
            if re.search(r"\b(?:%s)\b\s*(?:\+\+|--)|(?:\+\+|--)\s*%s\b|&%s\b" %
                         (re.escape(var), re.escape(var), re.escape(var)), text):
                continue
            use_lines = [k for k, l in enumerate(lines)
                         if k not in (i, j) and re.search(r"\b%s\b" % re.escape(var), l)]
            if not use_lines:
                continue
            for k in use_lines:
                lines[k] = re.sub(r"\b%s\b" % re.escape(var), "(" + rhs + ")", lines[k])
            for k in sorted({i, j}, reverse=True):
                del lines[k]
            changed = True
            break
    return "\n".join(lines)


def strip_unused_declarations(text):
    lines = text.splitlines()
    out = []
    for line in lines:
        m = DECL_RE.match(line)
        if m and len(re.findall(r"\b%s\b" % re.escape(m.group(1)), text)) == 1:
            continue
        out.append(line)
    return "\n".join(out)


def write_reconstruction_header():
    (REF / "c_project").mkdir(parents=True, exist_ok=True)
    lines = [
        "#ifndef MT05_RECONSTRUCTION_H",
        "#define MT05_RECONSTRUCTION_H",
        "",
        "#include <stdint.h>",
        "#include <stdbool.h>",
        "#include <stddef.h>",
        "",
        "typedef uint8_t u8;",
        "typedef uint16_t u16;",
        "typedef uint32_t u32;",
        "typedef int8_t s8;",
        "typedef int16_t s16;",
        "typedef int32_t s32;",
        "typedef void code(void);",
        "typedef uint16_t (*mt05_code_ptr_t)(void);",
        "",
        "static inline uint16_t call_ptr(uint32_t address)",
        "{",
        "    return ((mt05_code_ptr_t)(uintptr_t)address)();",
        "}",
        "static inline uint16_t call_app_slot(uint16_t table, uint16_t index)",
        "{",
        "    uint16_t offset = *(uint16_t *)(uintptr_t)",
        "        (0xC08000u + ((((uint32_t)index * 2u) + table) & 0x3fffu));",
        "    return call_ptr((uint32_t)offset | 0xc10000u);",
        "}",
        "static inline uint16_t call_boot_slot(uint16_t table, uint16_t index)",
        "{",
        "    uint16_t offset = *(uint16_t *)(uintptr_t)",
        "        (0xC00000u + ((uint32_t)index * 2u) + table);",
        "    return call_ptr((uint32_t)offset | 0xc00000u);",
        "}",
        "",
        "#define CONCAT11(a,b) ((uint16_t)(((uint16_t)(uint8_t)(a) << 8) | (uint8_t)(b)))",
        "#define CONCAT12(a,b) ((uint32_t)(((uint32_t)(uint8_t)(a) << 16) | (uint16_t)(b)))",
        "#define CONCAT21(a,b) ((uint32_t)(((uint32_t)(uint16_t)(a) << 16) | (uint8_t)(b)))",
        "#define CONCAT22(a,b) ((uint32_t)(((uint32_t)(uint16_t)(a) << 16) | (uint16_t)(b)))",
        "#define CARRY2(a,b) ((uint16_t)(((uint32_t)(a) + (uint32_t)(b)) > 0xffffu))",
        "#define SBORROW1(a,b) ((int16_t)((int16_t)(a) - (int16_t)(b)) < -128)",
        "#define SBORROW2(a,b) ((int16_t)((int32_t)(int16_t)(a) - (int32_t)(int16_t)(b)) < -32768)",
        "#define ASSIGN_EQ(var,value,expected) (((var) = (value)) == (expected))",
        "#define ASSIGN_NE(var,value,expected) (((var) = (value)) != (expected))",
        "#define ZEXT23(a) ((uint32_t)(a) & 0xffffffu)",
        "",
        "static inline void __atomic(int x) { (void)x; }",
        "static inline void __disable_watchdog(void) {}",
        "static inline void __service_watchdog(void) {}",
        "static inline void __software_reset(void) {}",
        "static inline void __idle(void) {}",
        "static inline void __end_of_init(void) {}",
        "static inline void halt_baddata(void) { __builtin_trap(); }",
        "",
        "/* Hardware registers from the recovered SFR catalog. */",
    ]
    sfr_path = FW / "SEMANTIC_INDEX.csv"
    if sfr_path.exists():
        for r in read_csv(sfr_path):
            if r.get("kind") != "sfr":
                continue
            name = r.get("name", "")
            a = addr_value(r.get("address_or_range", ""))
            if not name or name.startswith(("DAT_", "UNK_")) or a is None:
                continue
            if name in {"CONCAT11", "CONCAT12", "CONCAT21", "CONCAT22", "CARRY2",
                        "SBORROW1", "SBORROW2", "ZEXT23"}:
                continue
            lines.append(f"#define {name} (*(volatile uint16_t *)0x{a:06X}u)")
    lines += ["", "/* Memory-mapped data and dispatch targets. */"]
    ids = set()
    for f in funcs:
        src = DEC / Path(f["source_c"]).name
        if not src.exists():
            continue
        text = src.read_text(errors="ignore")
        ids.update(re.findall(r"\b(?:mem|unk|ram|uram|bram)_[0-9a-fA-F]{4,8}\b", text))
        ids.update(re.findall(r"\bsub_c[0-9a-fA-F]+\b", text))
        for m in re.finditer(r"\b(PTR_DAT_|_DAT_|DAT_|UNK_|uRam|bRam|Ram)([0-9a-fA-F]{4,8})\b", text):
            prefix, a = m.group(1), m.group(2).lower()
            if prefix == "PTR_DAT_":
                ids.add("ptr_mem_" + a)
            elif prefix in ("DAT_", "_DAT_"):
                ids.add("mem_" + a)
            elif prefix == "UNK_":
                ids.add("unk_" + a)
            elif prefix == "uRam":
                ids.add("uram_" + a)
            elif prefix == "bRam":
                ids.add("bram_" + a)
            elif prefix == "Ram":
                ids.add("ram_" + a)
        for m in re.finditer(r"\bfunc_0x([0-9a-fA-F]+)\b", text):
            ids.add("sub_c" + m.group(1).lower())
    for name in sorted(ids):
        if name.startswith("sub_c"):
            lines.append(f"uint32_t {name}();")
        else:
            a = int(name.rsplit("_", 1)[1], 16)
            typ = "uint8_t" if name.startswith(("bram_", "ptr_mem_")) else "uint16_t"
            lines.append(f"#define {name} (*(volatile {typ} *)0x{a:06X}u)")
    # Export semantic variables as memory macros as well.
    known = {re.match(r"#define (\w+)", l).group(1) for l in lines if re.match(r"#define (\w+)", l)}
    var_path = CAT / "VARIABLES.csv"
    if var_path.exists():
        for r in read_csv(var_path):
            name = r.get("name", "")
            if not re.fullmatch(r"[A-Za-z_]\w*", name) or name in known:
                continue
            if name.startswith(("DAT_", "UNK_", "ram_var_")):
                continue
            a = addr_value(r.get("address", ""))
            if a is None:
                continue
            if 0x4000 <= a <= 0x7FFF:
                a = 0xC08000 + (a - 0x4000)
            width = int(r.get("width") or 0)
            typ = "uint8_t" if width == 1 else ("uint32_t" if width == 4 else "uint16_t")
            lines.append(f"#define {name} (*(volatile {typ} *)0x{a:06X}u)")
            known.add(name)

    # Uppercase names used as hardware registers but absent from the SFR catalog.
    upper = set()
    for f in funcs:
        src = DEC / Path(f["source_c"]).name
        if src.exists():
            upper.update(re.findall(r"\b[A-Z][A-Z0-9_]{2,}\b", src.read_text(errors="ignore")))
    skip = {"CONCAT11", "CONCAT12", "CONCAT21", "CONCAT22", "CARRY2",
            "SBORROW1", "SBORROW2", "ZEXT23", "NULL", "MT05", "C166SV2"}
    for name in sorted(upper - known - skip):
        if name in {"PSW", "DPP0", "DPP1", "DPP2", "DPP3", "SP", "STKOV", "STKUN"}:
            continue
        lines.append(f"extern volatile uint16_t {name};")

    lines += ["", "#endif"]
    (REF / "c_project" / "mt05_reconstruction.h").write_text("\n".join(lines) + "\n")


def merge_c_refs(funcs, fn_map, var_map):
    groups = {name: [] for name in C_GROUP_ORDER}
    for f in funcs:
        groups[C_GROUPS[f["area"]]].append(f)
    for group_name in C_GROUP_ORDER:
        members = sorted(groups[group_name], key=lambda f: int(f["address"], 16))
        lines = [
            "/* ============================================================================",
            f" * MT05.2 / C166SV2 reconstruction: {group_name}",
            " * Generated by c166sv2/deliverables/reconstruction/full/tools/build_catalog.py.",
            " * Each function starts with an address/name/source separator.",
            " * This is Ghidra decompiler output, not original or compilable source.",
            " * ========================================================================== */",
            "",
            "#include \"mt05_reconstruction.h\"",
            "",
        ]
        for f in members:
            a = int(f["address"], 16)
            src = DEC / Path(f["source_c"]).name
            if not src.exists():
                continue
            lines += [
                "/* -------------------------------------------------------------------------",
                f" * {f['address']}  {f['name']}",
                f" * area={f['area']} category={f['category']} confidence={f['confidence']}",
                f" * source={f['source_c']}",
                " * ------------------------------------------------------------------------- */",
            ]
            start_line = len(lines) + 1
            raw = rename_tokens(src.read_text(errors="ignore"), fn_map, var_map)
            raw = simplify_comma_conditions(rename_tokens(sanitize_c_text(raw), mem_map))
            body = inline_pure_locals(rename_locals(simplify_pointer_casts(
                strip_unused_declarations(strip_redundant_casts(remove_dead_snapshots(
                    use_compound_assignments(compound_sfr_rewrites(inline_single_use_temps(
                        refactor_indirect_calls(raw))))))))))
            lines += body.rstrip("\n").splitlines()
            lines.append("")
            f["reference_c"] = f"reference/c_project/{group_name}"
            f["reference_c_line"] = str(start_line)
        out = REF / "c_project" / group_name
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text("\n".join(lines) + "\n")


def annotate_reachability(funcs):
    byaddr = {int(f["address"], 16): f for f in funcs}
    roots = {}  # address -> label

    def add_root(a, label):
        if a in byaddr:
            roots.setdefault(a, [])
            if label not in roots[a]:
                roots[a].append(label)

    add_root(0xC00000, "reset_vector")
    add_root(0xC02000, "hidden_boot")
    vector_path = ROOT / "c166sv2" / "deliverables" / "artifacts" / "vector_table.csv"
    if vector_path.exists():
        for r in read_csv(vector_path):
            if r.get("status") != "active":
                continue
            a = addr_value(r.get("handler_address", ""))
            if a is not None:
                add_root(a, "vector:" + r.get("source", "?"))
    dump_path = ROOT / "dumps" / "mash_dump.bin"
    if dump_path.exists():
        data = dump_path.read_bytes()
        for i in range(128):
            off = 0x10000 + i * 4
            if off + 4 > len(data):
                break
            if data[off] not in (0xFA, 0xEA):
                continue
            target = (data[off + 1] << 16) | (data[off + 3] << 8) | data[off + 2]
            if target in byaddr:
                add_root(target, f"farcall[0x{i:02X}]")
        # ASC0 state table at flash 0x0428 (ORed with 0xC00000).
        for i in range(6):
            off = 0x0428 + i * 2
            target = int.from_bytes(data[off:off + 2], "little") | 0xC00000
            if target in byaddr:
                add_root(target, f"jump_table:0x0428[{i}]")

    for a, labels in roots.items():
        f = byaddr[a]
        f["root_kind"] = ";".join(labels)
        current = f.get("callers", "")
        extra = ";".join(labels)
        f["callers"] = (current + ";" + extra).strip(";") if current else extra

    def callee_addrs(f):
        return split_refs(f.get("callees", ""))

    reachable = set(roots)
    stack = list(roots)
    while stack:
        a = stack.pop()
        for c in callee_addrs(byaddr[a]):
            if c in byaddr and c not in reachable:
                reachable.add(c)
                stack.append(c)
    for f in funcs:
        f.setdefault("root_kind", "")
        a = int(f["address"], 16)
        f["call_graph"] = "reachable" if a in reachable else "orphan_candidate"


def area_for(a, name):
    if a < 0xC00200:
        return "00-reset"
    if a < 0xC02000:
        return "01-boot"
    if a < 0xC04000:
        return "02-hidden-boot"
    if a < 0xC0B000:
        return "03-calibration-data"
    if name.startswith("kline_") or name.startswith("kwp_") or name.startswith("asc0_"):
        return "04-kline-kwp"
    if name.startswith("can_"):
        return "05-can"
    if name.startswith("ssc_"):
        return "06-ssc"
    if name.startswith("diag_") or name.startswith("dtc_"):
        return "07-diagnostics"
    if name.startswith("boot_"):
        return "01-boot"
    if name.startswith(("capture_", "cc_", "cc22", "cc23", "timer", "event", "pwm", "output_", "io_")):
        return "08-io-timing"
    if name.startswith(("calc_", "map_", "table_", "limit_", "speed_", "engine_", "axis_", "ve_")):
        return "09-engine-calc"
    if name.startswith(("math_", "sat_", "mul_", "div_", "fp_")):
        return "10-math"
    if name.startswith(("adapt_", "record_", "config_", "mode_")):
        return "11-adaptation"
    if a < 0xC14000:
        return "12-app-low"
    if a < 0xC1A000:
        return "13-app-io"
    if a < 0xC28000:
        return "09-engine-calc"
    return "14-app-runtime"


def category_for(a, name, area):
    if name.startswith("boot_") or area.startswith("0"):
        return "boot"
    for p, c in (
        ("kline_", "kline"), ("kwp_", "kwp"), ("asc0_", "asc0"),
        ("can_", "can"), ("ssc_", "ssc"), ("diag_", "diag"),
        ("dtc_", "dtc"), ("calc_", "calc"), ("map_", "map"),
        ("table_", "table"), ("limit_", "limit"), ("math_", "math"),
        ("adapt_", "adapt"), ("capture_", "capture"), ("cc_", "cc"),
        ("timer", "timer"), ("pwm_", "pwm"),
    ):
        if name.startswith(p):
            return c
    return area.split("-", 1)[-1]


def table_refs(ctext):
    out = []
    for m in re.finditer(
        r"(tbl8_interp|tbl16_interp|tbl2d_interp|axis16_unsigned|axis16_signed)"
        r"\(0x([0-9a-fA-F]+),0xc0", ctext):
        out.append(f"{m.group(1)}@0x{int(m.group(2), 16):04X}")
    return out


def memory_refs(atext):
    hits = []
    for m in re.finditer(r"(?<!#)\b0x([0-9a-fA-F]{4,6})\b", atext):
        v = int(m.group(1), 16)
        if v in variables:
            for n in semantic_names_for_addr(v):
                if n not in hits:
                    hits.append(n)
    return hits


def yes(s):
    return str(s).strip().lower() in ("1", "true", "yes")


# ---------------------------------------------------------------------------
# Function naming
# ---------------------------------------------------------------------------
manual = {
    0xC00000: ("reset_vector", "far jump at the reset vector; targets boot_reset"),
    0xC00428: ("boot_timer_a_init", "boot gap block; timer setup"),
    0xC0077C: ("boot_timer_b_setup", "boot gap block; timer/compare setup"),
    0xC00898: ("boot_ssc_rx_setup", "boot gap; SSC pointer setup"),
    0xC00C30: ("boot_idle", "boot gap; single idle/rets block"),
    0xC00C92: ("boot_timer_clear_stub", "boot gap; short timer clear"),
    0xC00DAA: ("boot_fill_words", "boot gap; word initialization"),
    0xC00DDA: ("boot_fill_bytes", "boot gap; byte initialization"),
    0xC01130: ("boot_capture_vector_stub", "boot gap; capture setup"),
    0xC01DC2: ("boot_clock_check", "boot gap; reads 0x450 clock/config constant"),
    0xC01EC0: ("boot_atomic_stub", "boot gap; atomic sequence"),
    0xC01F00: ("boot_fill_page", "boot gap; zero-fill helper"),
    0xC020C0: ("boot_hidden_copy_tail", "hidden boot copy tail"),
    0xC02132: ("boot_hidden_pin_stub", "hidden boot pin helper"),
    0xC021DE: ("boot_hidden_cmd_decode", "hidden boot command decode"),
    0xC02430: ("boot_hidden_task_dispatch", "hidden boot task dispatch"),
    0xC02A46: ("boot_hidden_eeprom_tail", "hidden boot EEPROM tail"),
    0xC02DDC: ("boot_hidden_serial_loop", "hidden boot serial/EEPROM loop"),
    0xC03A04: ("boot_hidden_serial_cmd", "hidden boot serial command helper"),
    0xC03DD4: ("boot_hidden_atomic_stub", "hidden boot atomic helper"),
    0xC03DF8: ("boot_hidden_final", "hidden boot final helper"),
    0xC0BB54: ("update_event_offset_3", "writes event_offset_3/0"),
    0xC0C8E2: ("update_capture_state", "writes capture_state/capture_enable"),
    0xC0CADA: ("update_capture_speed_state", "writes capture_state/speed flags"),
    0xC0D010: ("update_t7_offset_short", "writes T7 offset"),
    0xC0D2E4: ("math_mul_div_32", "calls mul32/div32u"),
    0xC0D5CA: ("math_mul_div_32_b", "calls mul32/div32u"),
    0xC0D71E: ("math_div_32", "calls div32u"),
    0xC0DF4C: ("math_div_32_b", "calls div32u"),
    0xC0E830: ("math_div_32_c", "calls div32u"),
    0xC0EE3C: ("update_output_gate_1", "writes output gate"),
    0xC0EF4A: ("update_output_gates", "writes output gates"),
    0xC0F032: ("update_output_gate_1_b", "writes output gate"),
    0xC0F2B8: ("update_app_flags", "writes app flag/gates"),
    0xC0F378: ("update_app_flag", "writes app flag/gate"),
    0xC0F842: ("update_output_gate_0", "writes output gate"),
    0xC0F8DE: ("update_output_gate_1_c", "writes output gate"),
    0xC0FA8E: ("update_output_gate_0_b", "writes output gate"),
    0xC0FA98: ("update_output_gate_1_d", "writes output gate"),
    0xC0FAA2: ("update_cc22_23_started", "writes CC22/23 started"),
    0xC0FAF8: ("update_cc22_23_started_b", "writes CC22/23 started"),
    0xC0FC42: ("update_capture_status", "writes capture status"),
    0xC0FCA6: ("update_cc_event_timeout", "writes CC event timeout"),
    0xC0FD82: ("update_capture_status_b", "writes capture status"),
    0xC102DC: ("update_ssc_control_flags", "writes SSC control flags"),
    0xC10618: ("update_scheduler_event_flag", "writes scheduler event flag"),
    0xC1078C: ("math_mul_div_32_d", "calls mul32/div32u"),
    0xC10B0C: ("math_div_32_d", "calls div32u"),
    0xC1105E: ("load_axis_pair_7052", "indexes 0x7052/0x7054"),
    0xC11D98: ("update_kline_state", "writes K-line/scheduler state"),
    0xC11DBA: ("update_kline_event_flag", "writes scheduler event flag"),
    0xC11DD0: ("update_kline_event_flag_b", "writes scheduler event flag"),
    0xC11E3C: ("update_kline_event_flag_c", "writes scheduler event flag"),
    0xC11E94: ("update_kline_event_flag_d", "writes scheduler event flag"),
    0xC127A2: ("update_kline_state_b", "writes K-line state"),
    0xC12856: ("update_kline_state_c", "writes K-line state"),
    0xC129D6: ("update_kline_timeout", "writes K-line timeout"),
    0xC13104: ("update_test_command", "writes test command"),
    0xC13132: ("update_test_command_b", "writes test command"),
    0xC13160: ("update_test_command_c", "writes test command"),
    0xC1318E: ("update_test_command_d", "writes test command"),
    0xC131D6: ("update_scheduler_event_flag_b", "writes scheduler event flag"),
    0xC13F3C: ("math_mul_div_32_e", "calls mul32/div32u"),
    0xC13F84: ("update_capture_input_select", "writes capture input select"),
    0xC13F88: ("update_capture_input_select_b", "writes capture input select"),
    0xC13FE6: ("update_capture_input_select_c", "writes capture input select"),
    0xC141DE: ("update_event_offset_1", "writes event offset"),
    0xC14682: ("math_div_32_e", "calls div32u"),
    0xC16CDE: ("calc_map_5c62", "calls tbl2d 0x5C62 and correction curves"),
    0xC17F44: ("calc_table_5db0", "calls tbl16 0x5DB0/0x7CDC/0x5D9C"),
    0xC18176: ("calc_table_5d9c", "calls tbl16 0x5D9C"),
    0xC1823C: ("calc_table_613e", "calls tbl16 0x613E/0x61F4"),
    0xC18C5C: ("calc_table_636c", "calls tbl16 0x636C"),
    0xC18D8A: ("calc_table_63b4", "calls tbl8 0x63B4"),
    0xC1AC8C: ("update_calc_input_w", "writes calc_input_w"),
    0xC1ACD6: ("calc_table_6ca4", "calls tbl8 0x6CA4"),
    0xC1AEDC: ("limit_condition_eval", "speed/threshold limiter check"),
    0xC1B2FC: ("update_calc_input_z", "writes calc_input_z/correction"),
    0xC1B34A: ("update_calc_input_z_b", "writes calc_input_z"),
    0xC1B682: ("update_engine_state", "writes engine_state"),
    0xC1B866: ("calc_table_6b6a", "calls tbl16 0x6B6A"),
    0xC1C024: ("update_calc_correction", "writes calc_input_correction"),
    0xC1C410: ("update_timer7_tick", "writes timer7_tick"),
    0xC1C718: ("update_speed_status", "writes speed flags/input"),
    0xC1C956: ("math_mul32", "calls mul32"),
    0xC1CB9E: ("update_ssc_rx_frame", "writes SSC RX frame"),
    0xC1D8C6: ("calc_table_6c7a", "calls tbl16 0x6C7A"),
    0xC1D950: ("calc_table_6c7a_b", "calls tbl16 0x6C7A"),
    0xC1DA6E: ("calc_map_70f6", "axis 0x50DC, map 0x70F6"),
    0xC1DB18: ("calc_map_6e50", "map 0x6E50"),
    0xC1DEEE: ("calc_table_6d48", "calls tbl8 0x6D48"),
    0xC1ED9E: ("calc_table_7616", "calls tbl16 0x7616"),
    0xC2006E: ("calc_table_7860", "calls tbl8 0x7860"),
    0xC20398: ("update_kline_response_source", "writes K-line response source"),
    0xC2042A: ("update_kline_rx_index", "writes K-line RX index"),
    0xC20450: ("update_kline_response_payload", "writes K-line response payload"),
    0xC2046C: ("update_kline_response_source_b", "writes K-line response source"),
    0xC240FE: ("select_active_record", "record table 0x71EA"),
    0xC243A8: ("dtc_status_bit5", "fault-index table 0x7286, bit 5"),
    0xC25600: ("update_adapt_age", "walks 0x1E records"),
    0xC27216: ("config_mode_update", "writes XRAM mode flags"),
    0xC276BA: ("sat_add_s16", "signed saturating add"),
    0xC27BF8: ("math_mul32_b", "calls mul32"),
    0xC27F0E: ("math_mul32_c", "calls mul32"),
    0xC28450: ("math_mul32_d", "calls mul32"),
    0xC28544: ("math_div32", "calls div32u"),
    0xC286CA: ("math_div32_b", "calls div32u"),
    0xC28852: ("sat_sub_u16", "unsigned saturating subtract"),
    0xC28B88: ("math_div32_c", "calls div32u"),
}

def strip_ref_address(name):
    n = re.sub(r"_(wrapper|helper|dispatch)(_[0-9a-f]{4,6})?$", "", name)
    n = re.sub(r"_[0-9a-f]{4,6}$", "", n)
    return n or name


def split_refs(s):
    out = []
    for item in (s or "").split(";"):
        if ":" not in item:
            continue
        try:
            out.append(int(item.split(":", 1)[0], 16))
        except ValueError:
            pass
    return out


def common_prefix(names):
    parts = [n.split("_") for n in names]
    out = []
    for group in zip(*parts):
        if len(set(group)) != 1:
            break
        out.append(group[0])
    return "_".join(out)


def refine_functions(funcs):
    byaddr = {int(f["address"], 16): f for f in funcs}
    for iteration in range(20):
        known = {
            a for a, f in byaddr.items()
            if f["confidence"] in ("high", "medium")
            and not f["name"].startswith(("FUN_", "gap_", "aif_"))
        }
        changed = 0
        for a, f in byaddr.items():
            if f["confidence"] != "low":
                continue
            callees = split_refs(f["callees"])
            callers = split_refs(f["callers"])
            kcallees = [byaddr[x] for x in callees if x in known]
            kcallers = [byaddr[x] for x in callers if x in known]
            new_name = None
            evidence = None
            if len(kcallees) == 1:
                base = strip_ref_address(kcallees[0]["name"])
                new_name = f"{base}_wrapper_{a:x}"
                evidence = f"calls {kcallees[0]['name']} ({kcallees[0]['address']})"
            elif len(kcallers) == 1 and not callees:
                base = strip_ref_address(kcallers[0]["name"])
                new_name = f"{base}_helper_{a:x}"
                evidence = f"called only by {kcallers[0]['name']} ({kcallers[0]['address']})"
            elif len(kcallees) >= 2 and len(kcallers) <= 1:
                base = strip_ref_address(kcallees[0]["name"])
                new_name = f"{base}_dispatch_{a:x}"
                evidence = "calls " + ",".join(x["name"] for x in kcallees[:5])
            elif len(kcallers) == 1 and kcallees:
                base = strip_ref_address(kcallers[0]["name"])
                new_name = f"{base}_helper_{a:x}"
                evidence = (
                    f"called by {kcallers[0]['name']} ({kcallers[0]['address']}); "
                    "calls " + ",".join(x["name"] for x in kcallees[:3])
                )
            elif kcallers and not callees:
                base = common_prefix([x["name"] for x in kcallers])
                if base in ("update", "app", "engine", "code", "gap"):
                    base = ""
                if not base:
                    areas = {x["area"] for x in kcallers}
                    if len(areas) == 1:
                        base = areas.pop().split("-", 1)[-1].replace("-", "_")
                if base:
                    new_name = f"{base}_helper_{a:x}"
                    evidence = "called by " + ",".join(x["name"] for x in kcallers[:5])
            elif kcallees and kcallers:
                base = common_prefix([x["name"] for x in kcallers + kcallees])
                if base in ("update", "app", "engine", "code", "gap"):
                    base = ""
                if not base:
                    areas = {x["area"] for x in kcallers + kcallees}
                    if len(areas) == 1:
                        base = areas.pop().split("-", 1)[-1].replace("-", "_")
                if base:
                    new_name = f"{base}_helper_{a:x}"
                    evidence = "callers/callees " + ",".join(
                        x["name"] for x in (kcallers + kcallees)[:5])
            if new_name and re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", new_name):
                f["name"] = new_name
                f["evidence"] = evidence
                f["confidence"] = "medium"
                changed += 1
        if changed == 0:
            break


funcs = []
name_counts = Counter()
for r in read_csv(ART / "functions.csv"):
    a = int(r["address"], 16)
    cpath = DEC / r["file"]
    ctext = cpath.read_text(errors="ignore") if cpath.exists() else ""
    apath = cpath.with_suffix(".asm")
    atext = apath.read_text(errors="ignore") if apath.exists() else ""
    callees = [x.split(":", 1)[1] for x in r["callees"].split(";") if ":" in x]
    tables = table_refs(ctext)
    refs = memory_refs(atext)
    crefs = curated.get(a)
    ar = auto.get(a)
    conf = "low"
    evidence = "C166SV2 whole-image pass; no strong callee/table/variable signal"
    if crefs:
        name = crefs["name"]
        conf = crefs["confidence"]
        evidence = crefs["evidence"]
        category = crefs["category"]
    elif a in manual:
        name, evidence = manual[a]
        conf = "high" if (a in {
            0xC00000, 0xC16CDE, 0xC02000, 0xC0210A, 0xC02140, 0xC02250,
            0xC022FC, 0xC0231E, 0xC0248A, 0xC02B76, 0xC03CB8, 0xC03CD0,
            0xC03DDC, 0xC03DE2, 0xC1AEDC, 0xC1DA6E, 0xC1DB18, 0xC240FE,
            0xC243A8, 0xC25600, 0xC27216, 0xC276BA, 0xC28852, 0xC1105E,
        } or (ar and ar["confidence"] == "high")) else "medium"
        category = category_for(a, name, area_for(a, name))
    elif ar and ar["confidence"] in ("high", "medium"):
        name = ar["auto_name"]
        conf = ar["confidence"]
        evidence = ar["evidence"]
        category = category_for(a, name, area_for(a, name))
    elif tables:
        kind, t = tables[0].split("@0x")
        pref = "map" if kind == "tbl2d_interp" else ("axis" if kind.startswith("axis") else "table")
        name = f"{pref}_{int(t, 16):04x}_{a:x}"
        evidence = "calls " + ", ".join(tables)
        conf = "high" if kind == "tbl2d_interp" else "medium"
        category = "map" if pref == "map" else "table"
    elif any(c.startswith("dtc_status_bit") for c in callees):
        name = f"dtc_check_{a:x}"
        evidence = "calls " + ",".join(c for c in callees if c.startswith("dtc_status_bit"))
        conf = "medium"
        category = "dtc"
    elif refs:
        w = any(re.search(r"(?:mov|movb|bset|bclr|and|or|xor)\s+0x%x\b" % addr_value(v["address_or_range"]), atext, re.I)
                for v in variables.get(addr_value("0x" + ""), []))
        # The above empty lookup is a type guard; actual write test uses variable addresses.
        writes = []
        for vaddr, vlist in variables.items():
            for v in vlist:
                if v["name"] not in refs or GENERIC.match(v["name"]):
                    continue
                if re.search(r"(?:mov|movb|bset|bclr|and|or|xor)\s+0x%x\b" % vaddr, atext, re.I):
                    if v["name"] not in writes:
                        writes.append(v["name"])
        if writes:
            name = f"update_{re.sub(r'[^a-z0-9_]+', '_', writes[0].lower()).strip('_')}_{a:x}"
            evidence = "writes " + ",".join(writes[:4])
            conf = "medium"
        else:
            name = f"use_{re.sub(r'[^a-z0-9_]+', '_', refs[0].lower()).strip('_')}_{a:x}"
            evidence = "references " + ",".join(refs[:4])
            conf = "low"
        category = category_for(a, name, area_for(a, name))
    elif any(c in SEMANTIC_CALLEE for c in callees):
        name = f"math_{a:x}"
        evidence = "calls " + ",".join(c for c in callees if c in SEMANTIC_CALLEE)
        conf = "medium"
        category = "math"
    elif callees:
        known = [c for c in callees if not c.startswith(("FUN_", "gap_", "aif_"))]
        if known:
            name = f"call_{re.sub(r'[^a-z0-9_]+', '_', known[0].lower()).strip('_')}_{a:x}"
            evidence = "calls " + ",".join(known[:4])
            conf = "low"
            category = category_for(a, name, area_for(a, name))
        else:
            domain = area_for(a, "code").split("-", 1)[-1].replace("-", "_")
            name = f"{domain}_sub_{a:x}"
            category = "app"
    else:
        domain = area_for(a, "code").split("-", 1)[-1].replace("-", "_")
        name = f"{domain}_sub_{a:x}"
        category = "app"

    area = area_for(a, name)
    funcs.append({
        "address": f"0x{a:06X}",
        "name": name,
        "category": category,
        "area": area,
        "size": r["size"],
        "confidence": conf,
        "evidence": evidence,
        "callers": r["callers"],
        "callees": r["callees"],
        "tables": ";".join(tables),
        "variables": ";".join(refs[:12]),
        "source_c": f"{ART.relative_to(ROOT)}/decompiled/{r['file']}",
        "source_asm": f"{ART.relative_to(ROOT)}/decompiled/{Path(r['file']).with_suffix('.asm').name}",
        "reference_c": "",
        "reference_c_line": "",
        "reference_asm": "",
        "reference_asm_line": "",
    })
    name_counts[name] += 1

refine_functions(funcs)
# Guarantee unique names by adding the address to collisions.
for f in funcs:
    if name_counts[f["name"]] > 1:
        f["name"] = f"{f['name']}_{int(f['address'], 16):x}"

if REF.exists():
    shutil.rmtree(REF)
REF.mkdir(parents=True, exist_ok=True)
annotate_reachability(funcs)
fn_map, var_map, mem_map = build_rename_maps(funcs)
write_reconstruction_header()
merge_c_refs(funcs, fn_map, var_map)
merge_asm_refs(funcs, fn_map)

write_csv(CAT / "FUNCTIONS.csv", list(funcs[0].keys()), funcs)
orphans = [f for f in funcs if f.get("call_graph") == "orphan_candidate"]
write_csv(CAT / "ORPHANS.csv", ["address", "name", "area", "confidence", "evidence", "callees"],
          [{k: f[k] for k in ("address", "name", "area", "confidence", "evidence", "callees")} for f in orphans])

# ---------------------------------------------------------------------------
# Variables
# ---------------------------------------------------------------------------
var_rows = []
for a in sorted(variables):
    for v in variables[a]:
        aliases = live_alias.get(a, [])
        var_rows.append({
            "address": f"0x{a:06X}",
            "name": v["name"],
            "category": v["category"],
            "kind": v["kind"],
            "width": v["width"],
            "evidence": v["evidence"],
            "confidence": v["confidence"],
            "source": v["source"],
            "hud_uid": ";".join(sorted({x["live_uid"] for x in aliases})),
            "hud_name": ";".join(sorted({x["live_name"] for x in aliases})),
        })
write_csv(CAT / "VARIABLES.csv", list(var_rows[0].keys()), var_rows)

# ---------------------------------------------------------------------------
# Structures
# ---------------------------------------------------------------------------
ftypes = (FULL / "include" / "mt05" / "firmware_types.h").read_text() if (FULL / "include" / "mt05" / "firmware_types.h").exists() else ""
struct_rows = []
for m in re.finditer(r"typedef struct \{(.*?)\}\s*([A-Za-z_][A-Za-z0-9_]*)\s*;", ftypes, re.S):
    body, name = m.group(1), m.group(2)
    fields = sum(1 for line in body.splitlines() if re.match(r"\s*(u8|u16|u32|s8|s16|s32|fp32_t|[A-Za-z_][A-Za-z0-9_]*)\s+[A-Za-z_]", line))
    struct_rows.append({
        "name": name,
        "category": "firmware",
        "fields": fields,
        "source": "include/mt05/firmware_types.h",
        "evidence": "recovered from access patterns; logical view where marked",
        "confidence": "high" if "logical view" not in body else "medium",
    })
for name, fields, evidence in [
    ("mt05_function_t", 14, "catalog record for one Ghidra function"),
    ("mt05_variable_t", 10, "catalog record for one RAM/flash variable"),
    ("mt05_structure_t", 6, "catalog record for one recovered structure"),
    ("mt05_live_field_t", 10, "HUD ECU Hacker 21 01 field"),
    ("mt05_live_bit_t", 9, "HUD ECU Hacker status bit"),
    ("mt05_hud_command_t", 5, "HUD ECU Hacker command"),
    ("mt05_slew_t", 10, "HUD ECU Hacker data-slewing entry"),
]:
    struct_rows.append({
        "name": name, "category": "catalog", "fields": fields,
        "source": "include/mt05/catalog.h" if name.startswith("mt05_function") or name.startswith("mt05_variable") or name.startswith("mt05_structure") else "include/mt05/live_data.h",
        "evidence": evidence, "confidence": "high",
    })
write_csv(CAT / "STRUCTURES.csv", list(struct_rows[0].keys()), struct_rows)
struct_md = ["# Structures", "", "| Name | Category | Fields | Confidence | Source |", "|---|---|---:|---|---|"]
for r in struct_rows:
    struct_md.append(f"| `{r['name']}` | {r['category']} | {r['fields']} | {r['confidence']} | `{r['source']}` |")
(CAT / "STRUCTURES.md").write_text("\n".join(struct_md) + "\n")

area_counts = Counter(f["area"] for f in funcs)
func_md = [
    "# Function catalog",
    "",
    "Full catalog: `FUNCTIONS.csv` (902 functions). Generated from the C166SV2",
    "listing and decompilation. `confidence` is evidence strength, not a claim",
    "that every low-confidence name is a proven role.",
    "",
    "## Areas",
    "",
    "| Area | Functions |",
    "|---|---:|",
]
for area, count in sorted(area_counts.items()):
    func_md.append(f"| `{area}` | {count} |")
conf_counts = Counter(f["confidence"] for f in funcs)
func_md += ["", "## Confidence", "", "| Confidence | Functions |", "|---|---:|"]
for conf in ("high", "medium", "low"):
    func_md.append(f"| {conf} | {conf_counts.get(conf, 0)} |")
func_md += ["", "## High/medium confidence", "", "| Address | Name | Confidence | Evidence |", "|---|---|---|---|"]
for f in funcs:
    if f["confidence"] in ("high", "medium"):
        func_md.append(f"| `{f['address']}` | `{f['name']}` | {f['confidence']} | {clean(f['evidence'])[:140]} |")
(CAT / "FUNCTIONS.md").write_text("\n".join(func_md) + "\n")

ref_md = [
    "# Named reference tree",
    "",
    "This directory contains the full C166SV2 decompilation, renamed by the",
    "full catalog. Both C and ASM are merged into seven matching domain-level",
    "files. Function identifiers and known data symbols have been replaced with",
    "the catalog names; unresolved calls remain `func_0x...`. The `.c` files in",
    "`c_project/` are Ghidra decompiler output, not original source and not",
    "compilable C; the matching `.asm` files in `asm_project/` are the",
    "instruction-level authority.",
    "",
    "| Merged file | Functions |",
    "|---|---:|",
]
group_counts = Counter(C_GROUPS[f["area"]] for f in funcs)
for group_name in C_GROUP_ORDER:
    ref_md.append(f"| `c_project/{group_name}` + `asm_project/{Path(group_name).with_suffix('.asm').name}` | {group_counts.get(group_name, 0)} |")
ref_md += ["", "The mapping back to the artifact is in `../catalog/FUNCTIONS.csv`."]
(REF / "README.md").write_text("\n".join(ref_md) + "\n")

# ---------------------------------------------------------------------------
# HUD XML
# ---------------------------------------------------------------------------
hud = ET.parse(HUD_XML).getroot()
main = hud.find("Main")
eng = ET.parse(HUD_EN).getroot()
trans = {}
for p in eng.findall("./Parameters/Param"):
    trans[p.attrib.get("UID", "")] = {
        "name": p.attrib.get("DispName", ""),
        "description": p.attrib.get("Description", ""),
    }


def translated(uid):
    return trans.get(uid, {"name": uid, "description": ""})


commands, params, bits, slews = [], [], [], []
vendor = main.find("Vendor")
for ci, cmd in enumerate(vendor.findall("Command")):
    tx = cmd.attrib.get("TxBytes", "")
    c_id = f"{ci:02d}"
    commands.append({
        "id": c_id,
        "tx_bytes": tx,
        "rx_size": cmd.attrib.get("RxPacketSize", ""),
        "read": cmd.attrib.get("Read", ""),
        "byte_order": cmd.attrib.get("ByteOrder", ""),
        "scan_interval": cmd.attrib.get("ScanInterval", ""),
        "description": clean(cmd.text) or f"Vendor command {tx}",
    })
    for pi, p in enumerate(cmd.findall("RxParam")):
        uid = p.attrib.get("UID", "")
        t = translated(uid)
        off = p.attrib.get("ByteOffset", "")
        params.append({
            "command": tx,
            "command_id": c_id,
            "param_index": pi,
            "offset": off or "",
            "bytes": p.attrib.get("ByteCount", ""),
            "type": p.attrib.get("Type", ""),
            "uid": uid,
            "name": t["name"],
            "formula": p.attrib.get("Formula", ""),
            "unit": p.attrib.get("Unit", ""),
            "digits": p.attrib.get("Digits", ""),
            "description": t["description"],
        })
        if p.attrib.get("Type") == "BitFlags":
            for bit_el in p:
                b = int(bit_el.tag.replace("Bit", ""))
                buid = bit_el.attrib.get("UID", "")
                bt = translated(buid)
                bits.append({
                    "offset": off,
                    "bit": b,
                    "uid": buid,
                    "name": bt["name"],
                    "description": bt["description"],
                    "inverted": bit_el.attrib.get("Inverted", ""),
                    "disp_vals": bit_el.attrib.get("DispVals", ""),
                    "firmware_alias": ";".join(
                        sorted({r["firmware_alias"] for r in live_alias_rows
                                if r["live_uid"] == buid})
                    ) if "live_alias_rows" in globals() else "",
                })

# live_alias_rows must exist before bit construction above; load it now for a
# second pass if the first pass ran before the local was defined.
live_alias_rows = read_csv(LIVE_MAP)
for b in bits:
    b["firmware_alias"] = ";".join(sorted({
        r["firmware_alias"] for r in live_alias_rows if r["live_uid"] == b["uid"]
    }))

slew_root = main.find("DataSlewing")
if slew_root is not None:
    for p in slew_root.findall("./Parameters/Param"):
        uid = p.attrib.get("UID", "")
        t = translated(uid)
        slews.append({
            "slew_id": p.attrib.get("SlewID", ""),
            "type": p.attrib.get("Type", ""),
            "uid": uid,
            "name": t["name"],
            "display": p.attrib.get("Display", ""),
            "formula_set": p.attrib.get("FormulaSet", ""),
            "min": p.attrib.get("Min", ""),
            "max": p.attrib.get("Max", ""),
            "unit": p.attrib.get("Unit", ""),
            "value_on": p.attrib.get("ValueOn", ""),
            "description": t["description"],
        })

write_csv(CAT / "HUD_COMMANDS.csv", list(commands[0].keys()), commands)
write_csv(CAT / "HUD_PARAMETERS.csv", list(params[0].keys()), params)
write_csv(CAT / "HUD_STATUS_BITS.csv", list(bits[0].keys()), bits)
write_csv(CAT / "HUD_SLEW.csv", list(slews[0].keys()), slews)

# Tuning patch tables (cross-firmware HUD evidence).
patch_rows = []
for p in sorted(TUNING.glob("*.xml")):
    try:
        root = ET.parse(p).getroot()
    except Exception:
        continue
    for ti, tab in enumerate(root.findall("Table")):
        data = tab.text or ""
        try:
            raw = base64.b64decode(data, validate=False)
            n = len(raw)
        except Exception:
            n = 0
        patch_rows.append({
            "source_file": p.name,
            "source_bin": root.attrib.get("SourceFile", ""),
            "source_crc": root.attrib.get("SourceCRC", ""),
            "calibration": root.attrib.get("Calibration", ""),
            "table_index": ti,
            "address": tab.attrib.get("Addr", ""),
            "shift": tab.attrib.get("Shift", ""),
            "head": tab.attrib.get("Head", ""),
            "data_width": tab.attrib.get("Data", ""),
            "decoded_bytes": n,
        })
if patch_rows:
    write_csv(CAT / "HUD_TUNING_PATCHES.csv", list(patch_rows[0].keys()), patch_rows)
else:
    write_csv(CAT / "HUD_TUNING_PATCHES.csv", ["source_file"], [])
shutil.copyfile(LIVE_MAP, CAT / "HUD_FIRMWARE_MAP.csv")
shutil.copyfile(FW / "APP_INIT_TABLE.csv", CAT / "APP_INIT_TABLE.csv")

# ---------------------------------------------------------------------------
# Evidence note
# ---------------------------------------------------------------------------
ev = [
    "# Full reconstruction evidence",
    "",
    "Generated by `tools/build_catalog.py` from the repository evidence.",
    "",
    "## Inputs",
    "",
    "| Input | SHA-256 | Use |",
    "|---|---|---|",
    f"| `{ART.relative_to(ROOT)}/functions.csv` | `{sha256(ART / 'functions.csv')}` | 902 Ghidra functions |",
    f"| `{ART.relative_to(ROOT)}/disassembly.txt` | `{sha256(ART / 'disassembly.txt')}` | instruction evidence |",
    f"| `{ART.relative_to(ROOT)}/decompiled/` | `{sha256(ART / 'decompiled' / 'c1da6e__gap_c1da6e.c')}` (sample) | C/ASM per function |",
    f"| `c166/deliverables/firmware/SEMANTIC_INDEX.csv` | `{sha256(FW / 'SEMANTIC_INDEX.csv')}` | curated 195 functions and variables |",
    f"| `c166/deliverables/firmware/AUTO_NAMES.csv` | `{sha256(FW / 'AUTO_NAMES.csv')}` | prior automatic names |",
    f"| `c166/deliverables/firmware/AUTO_VARIABLES.csv` | `{sha256(FW / 'AUTO_VARIABLES.csv')}` | prior automatic variables |",
    f"| `c166/deliverables/firmware/APP_INIT_TABLE.csv` | `{sha256(FW / 'APP_INIT_TABLE.csv')}` | 0xC0BB56 RAM-init copies |",
    f"| `{HUD_XML.relative_to(ROOT)}` | `{sha256(HUD_XML)}` | HUD ECU Hacker command/parameter profile |",
    f"| `{HUD_EN.relative_to(ROOT)}` | `{sha256(HUD_EN)}` | HUD display names and descriptions |",
    f"| `c166sv2/deliverables/artifacts/live_firmware_map.csv` | `{sha256(LIVE_MAP)}` | firmware to live-data aliases |",
    f"| `reconstruction/full/catalog/HUD_FIRMWARE_MAP.csv` | `{sha256(LIVE_MAP)}` | copied HUD/firmware alias map |",
    f"| `secret/MT05/Tuning/` | `{len(patch_rows)} table records` | cross-firmware HUD map shapes |",
]
for x in sorted((ROOT / "secret" / "MT05" / "FlashMemory").glob("*.definitions")):
    ev.append(f"| `{x.relative_to(ROOT)}` | `{sha256(x)}` | encrypted HUD definitions; hashed, not parsed |")
if (CAT / "HUD_LOG_SUMMARY.csv").exists():
    ev.append(f"| `reconstruction/full/catalog/HUD_LOG_SUMMARY.csv` | `{sha256(CAT / 'HUD_LOG_SUMMARY.csv')}` | HUD log range summary |")
ev += [
    "",
    "## Naming policy",
    "",
    "* Curated names from `SEMANTIC_INDEX.csv` are authoritative.",
    "* HUD ECU Hacker names are used only for live-data/status fields, not as",
    "  original firmware symbols.",
    "* A function is `high` only with a named table/axis call, a curated entry,",
    "  or a reviewed manual mapping.",
    "* `medium` means one strong call-graph/table/variable signal.",
    "* `low` names are address-derived evidence labels, not semantic claims.",
    "* The encrypted `secret/MT05/FlashMemory/*.definitions` files were hashed",
    "  but not parsed; their payload is high-entropy/encrypted.",
    "",
    "## Counts",
    "",
    f"* Functions: {len(funcs)}",
    f"* Variables: {len(var_rows)}",
    f"* Structures: {len(struct_rows)}",
    f"* HUD fields: {len(params)}",
    f"* HUD status bits: {len(bits)}",
    f"* HUD slew entries: {len(slews)}",
    f"* HUD tuning table records: {len(patch_rows)}",
]
(CAT / "EVIDENCE.md").write_text("\n".join(ev) + "\n")

# ---------------------------------------------------------------------------
# Generated C catalogs
# ---------------------------------------------------------------------------
def emit_catalog():
    out = ['#include "mt05/catalog.h"', ""]
    out.append("const mt05_function_t mt05_functions[] = {")
    for f in funcs:
        out.append(
            '    { %s, %s, %s, %s, %s, %s, %s, %s, %s, %s },'
            % (
                f["address"], cstr(f["name"]), cstr(f["category"]), cstr(f["area"]),
                f["size"], cstr(f["confidence"]), cstr(f["evidence"]),
                cstr(f["tables"]), cstr(f["variables"]), cstr(f["reference_c"]),
            )
        )
    out.append("};")
    out.append("const size_t mt05_function_count = sizeof(mt05_functions) / sizeof(mt05_functions[0]);")
    out.append("")
    out.append("const mt05_variable_t mt05_variables[] = {")
    for v in var_rows:
        out.append(
            '    { %s, %s, %s, %s, %s, %s, %s, %s, %s },'
            % (
                v["address"], cstr(v["name"]), cstr(v["category"]), cstr(v["kind"]),
                v["width"], cstr(v["confidence"]), cstr(v["evidence"]),
                cstr(v["hud_uid"]), cstr(v["hud_name"]),
            )
        )
    out.append("};")
    out.append("const size_t mt05_variable_count = sizeof(mt05_variables) / sizeof(mt05_variables[0]);")
    out.append("")
    out.append("const mt05_structure_t mt05_structures[] = {")
    for s in struct_rows:
        out.append(
            '    { %s, %s, %s, %s, %s },'
            % (cstr(s["name"]), cstr(s["category"]), s["fields"],
               cstr(s["confidence"]), cstr(s["evidence"]))
        )
    out.append("};")
    out.append("const size_t mt05_structure_count = sizeof(mt05_structures) / sizeof(mt05_structures[0]);")
    (SRC / "catalog_data.c").write_text("\n".join(out) + "\n")


def emit_live_data():
    out = ['#include "mt05/live_data.h"', ""]
    out.append("const mt05_hud_command_t mt05_hud_commands[] = {")
    for c in commands:
        out.append('    { %s, %s, %s, %s, %s },'
                   % (cstr(c["tx_bytes"]), cstr(c["rx_size"]), cstr(c["read"]),
                      cstr(c["byte_order"]), cstr(c["description"])))
    out.append("};")
    out.append("const size_t mt05_hud_command_count = sizeof(mt05_hud_commands) / sizeof(mt05_hud_commands[0]);")
    out.append("")
    out.append("const mt05_live_field_t mt05_live_fields[] = {")
    for p in params:
        off = p["offset"]
        oval = addr_value(off) if off else 0xFF
        if oval is None:
            oval = 0xFF
        out.append(
            '    { %s, %s, %s, %s, %s, %s, %s, %s, %s },'
            % (hex(oval), p["bytes"] or "0", cstr(p["type"]), cstr(p["uid"]),
               cstr(p["name"]), cstr(p["formula"]), cstr(p["unit"]),
               p["digits"] or "0", cstr(p["description"]))
        )
    out.append("};")
    out.append("const size_t mt05_live_field_count = sizeof(mt05_live_fields) / sizeof(mt05_live_fields[0]);")
    out.append("")
    out.append("const mt05_live_bit_t mt05_live_bits[] = {")
    for b in bits:
        off = addr_value(b["offset"]) if b["offset"] else 0
        out.append(
            '    { %s, %s, %s, %s, %s, %s, %s },'
            % (hex(off or 0), b["bit"], cstr(b["uid"]), cstr(b["name"]),
               cstr(b["description"]), cstr(b["inverted"]), cstr(b["firmware_alias"]))
        )
    out.append("};")
    out.append("const size_t mt05_live_bit_count = sizeof(mt05_live_bits) / sizeof(mt05_live_bits[0]);")
    out.append("")
    out.append("const mt05_slew_t mt05_slew[] = {")
    for s in slews:
        vals = [x for x in (s["slew_id"],) if x]
        sid = addr_value(s["slew_id"]) or 0
        mn = s["min"] or "0"
        mx = s["max"] or "0"
        try: mn = int(mn) if str(mn).lstrip("-").isdigit() else 0
        except Exception: mn = 0
        try: mx = int(mx) if str(mx).lstrip("-").isdigit() else 0
        except Exception: mx = 0
        von = addr_value(s["value_on"]) or 0
        out.append(
            '    { %s, %s, %s, %s, %s, %s, %s, %s, %s },'
            % (hex(sid), cstr(s["type"]), cstr(s["uid"]), cstr(s["name"]),
               cstr(s["formula_set"]), mn, mx, hex(von), cstr(s["description"]))
        )
    out.append("};")
    out.append("const size_t mt05_slew_count = sizeof(mt05_slew) / sizeof(mt05_slew[0]);")
    (SRC / "live_data_data.c").write_text("\n".join(out) + "\n")


emit_catalog()
emit_live_data()

print("functions", len(funcs), Counter(f["confidence"] for f in funcs))
print("variables", len(var_rows))
print("structures", len(struct_rows))
print("hud fields/bits/slew/commands", len(params), len(bits), len(slews), len(commands))
print("areas", Counter(f["area"] for f in funcs))
