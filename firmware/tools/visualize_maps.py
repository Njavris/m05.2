#!/usr/bin/env python3
"""Visualise the recovered MT05.2 calibration maps as SVG/HTML.

No third-party packages are required. The tool parses the self-describing
tables in the calibration block and writes:

  index.html             - all maps/curves in one page
  maps.json              - decoded tables
  decoded_tables.csv     - flat table values
  *.svg                  - individual heatmaps/line charts
  README.md              - output description and caveats

Axes are table indices, not physical RPM/load: the original axis descriptors
live in external RAM (0x7000/0x750A..0x7564), which is not in the flash dump.
"""
import argparse
import csv
import hashlib
import json
import os
import struct
import sys

BASE = 0xC00000
DEFAULT_DUMP = os.path.join(os.path.dirname(__file__), "..", "..", "dumps", "mash_dump.bin")
DEFAULT_OUT = os.path.join(os.path.dirname(__file__), "..", "..", "artifacts", "maps")
PROJECT_ROOT = os.path.normpath(os.path.join(os.path.dirname(__file__), "..", ".."))


def display_path(path):
    try:
        return os.path.relpath(os.path.abspath(path), PROJECT_ROOT)
    except ValueError:
        return os.path.basename(path)

# (name, segment-0xC0 offset, kind)
TABLES = [
    ("cal_load_map",          0x794A, "tbl2d"),
    ("cal_correction_curve",  0x79B6, "tbl8"),
    ("cal_limit_curve_0",     0x784C, "tbl8"),
    ("cal_limit_curve_1",     0x7860, "tbl8"),
    ("cal_limit_curve_2",     0x7874, "tbl8"),
    ("cal_limit_curve_3",     0x78D8, "tbl8"),
    ("cal_limit_multiplier",  0x78E2, "tbl8"),
    ("cal_constant_curve_0",  0x799E, "tbl8"),
    ("cal_constant_curve_1",  0x79AA, "tbl8"),
    ("cal_limit_table16",     0x7912, "tbl16"),
]


def load_dump(path):
    data = open(path, "rb").read()
    if len(data) != 0x40000:
        raise SystemExit(f"expected 256 KB dump, got {len(data)} bytes")
    return data


def u8(data, addr):
    return data[addr - BASE]


def u16(data, addr):
    off = addr - BASE
    return struct.unpack_from("<H", data, off)[0]


def parse_table(data, offset, kind):
    addr = BASE + offset
    if kind == "tbl8":
        count = u8(data, addr)
        shift = u8(data, addr + 1)
        values = [u8(data, addr + 2 + i) for i in range(count)]
        return {"kind": kind, "count": count, "shift": shift, "data": values}
    if kind == "tbl16":
        count = u16(data, addr)
        values = [u16(data, addr + 2 + 2 * i) for i in range(count)]
        return {"kind": kind, "count": count, "shift": 0, "data": values}
    if kind == "tbl2d":
        cols = u8(data, addr)
        rows = u8(data, addr + 1)
        shift = u8(data, addr + 2)
        values = [u8(data, addr + 3 + i) for i in range(cols * rows)]
        return {"kind": kind, "cols": cols, "rows": rows, "shift": shift, "data": values}
    raise ValueError(kind)


# ---------------------------------------------------------------------------
# SVG helpers
# ---------------------------------------------------------------------------

STOPS = [
    (0.00, (24, 32, 88)),
    (0.25, (28, 112, 168)),
    (0.50, (55, 176, 122)),
    (0.75, (232, 198, 62)),
    (1.00, (214, 56, 42)),
]


def color(value, vmin, vmax):
    if vmax <= vmin:
        t = 0.0
    else:
        t = (value - vmin) / float(vmax - vmin)
    t = max(0.0, min(1.0, t))
    for i in range(len(STOPS) - 1):
        a, ca = STOPS[i]
        b, cb = STOPS[i + 1]
        if a <= t <= b:
            f = (t - a) / (b - a)
            rgb = tuple(int(round(ca[j] + (cb[j] - ca[j]) * f)) for j in range(3))
            return "#%02x%02x%02x" % rgb
    return "#%02x%02x%02x" % STOPS[-1][1]


def luminance(rgb_hex):
    r = int(rgb_hex[1:3], 16) / 255.0
    g = int(rgb_hex[3:5], 16) / 255.0
    b = int(rgb_hex[5:7], 16) / 255.0
    return 0.2126 * r + 0.7152 * g + 0.0722 * b


def svg_text(x, y, text, size=11, anchor="start", fill="#1c2430", weight="normal", rotate=None):
    tr = f' transform="rotate({rotate} {x} {y})"' if rotate is not None else ""
    return (f'<text x="{x}" y="{y}" font-size="{size}" text-anchor="{anchor}" '
            f'fill="{fill}" font-weight="{weight}" font-family="Consolas, monospace"{tr}>'
            f'{text}</text>')


def heatmap_svg(title, addr, table, vmin, vmax):
    cols = table["cols"]
    rows = table["rows"]
    data = table["data"]
    cell = 44
    left = 76
    top = 58
    width = left + cols * cell + 24
    height = top + rows * cell + 64
    parts = [f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" '
             f'viewBox="0 0 {width} {height}">']
    parts.append(f'<rect x="0" y="0" width="{width}" height="{height}" fill="#ffffff"/>')
    parts.append(svg_text(left, 26, title, 15, "start", "#111827", "bold"))
    parts.append(svg_text(left, 44, f"0x{addr:06X}  {cols}x{rows} cells  shift={table['shift']}",
                          10, "start", "#4b5563"))
    for r in range(rows):
        for c in range(cols):
            v = data[r * cols + c]
            fill = color(v, vmin, vmax)
            x = left + c * cell
            y = top + r * cell
            fg = "#ffffff" if luminance(fill) < 0.55 else "#111827"
            parts.append(f'<rect x="{x}" y="{y}" width="{cell}" height="{cell}" '
                         f'fill="{fill}" stroke="#ffffff" stroke-width="1">'
                         f'<title>row {r}, col {c} = {v}</title></rect>')
            parts.append(svg_text(x + cell / 2, y + cell / 2 + 4, str(v), 13, "middle", fg, "bold"))
    for c in range(cols):
        parts.append(svg_text(left + c * cell + cell / 2, top + rows * cell + 16, str(c),
                              10, "middle", "#4b5563"))
    parts.append(svg_text(left + cols * cell / 2, top + rows * cell + 36, "column index",
                          10, "middle", "#4b5563"))
    for r in range(rows):
        parts.append(svg_text(left - 10, top + r * cell + cell / 2 + 4, str(r),
                              10, "end", "#4b5563"))
    parts.append(svg_text(14, top + rows * cell / 2, "row index", 10, "middle", "#4b5563", rotate=-90))
    parts.append(svg_text(left, height - 10, f"range {vmin}..{vmax}; darker = lower, red = higher",
                          9, "start", "#6b7280"))
    parts.append("</svg>")
    return "\n".join(parts)


def line_svg(title, addr, table, vmin, vmax):
    values = table["data"]
    n = len(values)
    width = 780
    height = 330
    left = 62
    top = 52
    plotw = width - left - 24
    ploth = height - top - 54
    parts = [f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" '
             f'viewBox="0 0 {width} {height}">']
    parts.append(f'<rect x="0" y="0" width="{width}" height="{height}" fill="#ffffff"/>')
    kind = table["kind"]
    parts.append(svg_text(left, 24, title, 15, "start", "#111827", "bold"))
    parts.append(svg_text(left, 42, f"0x{addr:06X}  {n} points  {kind}  shift={table['shift']}",
                          10, "start", "#4b5563"))
    # grid and y labels
    for i in range(5):
        frac = i / 4.0
        y = top + frac * ploth
        val = vmax - frac * (vmax - vmin)
        parts.append(f'<line x1="{left}" y1="{y:.1f}" x2="{left + plotw}" y2="{y:.1f}" '
                     f'stroke="#e5e7eb" stroke-width="1"/>')
        parts.append(svg_text(left - 8, y + 4, f"{int(round(val))}", 10, "end", "#6b7280"))
    # x labels (all if <=20, otherwise every few)
    step = 1 if n <= 20 else max(1, n // 10)
    for i in range(0, n, step):
        x = left + (i / (n - 1)) * plotw if n > 1 else left
        parts.append(svg_text(x, top + ploth + 16, str(i), 10, "middle", "#6b7280"))
    parts.append(svg_text(left + plotw / 2, top + ploth + 36, "table index", 10, "middle", "#4b5563"))
    # polyline
    pts = []
    for i, v in enumerate(values):
        x = left + (i / (n - 1)) * plotw if n > 1 else left
        y = top + (1.0 - (v - vmin) / (vmax - vmin if vmax > vmin else 1)) * ploth
        pts.append((x, y, v))
    path = " ".join(f"{x:.1f},{y:.1f}" for x, y, _ in pts)
    parts.append(f'<polyline points="{path}" fill="none" stroke="#1f6feb" stroke-width="2"/>')
    for i, (x, y, v) in enumerate(pts):
        parts.append(f'<circle cx="{x:.1f}" cy="{y:.1f}" r="3.2" fill="#1f6feb">'
                     f'<title>index {i} = {v}</title></circle>')
        if n <= 20:
            parts.append(svg_text(x, y - 8, str(v), 9, "middle", "#1f2937", "bold"))
    parts.append("</svg>")
    return "\n".join(parts)


# ---------------------------------------------------------------------------
# Output
# ---------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--dump", default=DEFAULT_DUMP)
    ap.add_argument("--out", default=DEFAULT_OUT)
    args = ap.parse_args()

    data = load_dump(args.dump)
    sha = hashlib.sha256(data).hexdigest()
    dump_display = display_path(args.dump)
    out = os.path.abspath(args.out)
    os.makedirs(out, exist_ok=True)

    tables = []
    for name, offset, kind in TABLES:
        table = parse_table(data, offset, kind)
        table["name"] = name
        table["offset"] = offset
        table["address"] = BASE + offset
        tables.append(table)

    # JSON
    with open(os.path.join(out, "maps.json"), "w") as f:
        json.dump({"dump": dump_display, "sha256": sha,
                   "base": "0x%06X" % BASE, "tables": tables}, f, indent=2)

    # CSV
    with open(os.path.join(out, "decoded_tables.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["table", "address", "kind", "row", "col", "index", "value"])
        for t in tables:
            if t["kind"] == "tbl2d":
                for r in range(t["rows"]):
                    for c in range(t["cols"]):
                        i = r * t["cols"] + c
                        w.writerow([t["name"], "0x%06X" % t["address"], t["kind"],
                                    r, c, i, t["data"][i]])
            else:
                for i, v in enumerate(t["data"]):
                    w.writerow([t["name"], "0x%06X" % t["address"], t["kind"],
                                "", "", i, v])

    html = []
    html.append("<!doctype html><html><head><meta charset='utf-8'>")
    html.append("<title>MT05.2 calibration maps</title>")
    html.append("<style>")
    html.append("body{font-family:system-ui,Segoe UI,Arial,sans-serif;margin:24px;color:#111827;background:#f8fafc}")
    html.append("h1{font-size:24px}h2{font-size:17px;margin-top:28px;border-bottom:1px solid #e5e7eb;padding-bottom:4px}")
    html.append(".meta{font-family:Consolas,monospace;font-size:12px;color:#4b5563;background:#fff;border:1px solid #e5e7eb;padding:10px;border-radius:6px}")
    html.append(".warn{background:#fff7ed;border:1px solid #fdba74;padding:10px;border-radius:6px;margin:14px 0}")
    html.append(".table{margin:10px 0 28px 0;background:#fff;border:1px solid #e5e7eb;border-radius:6px;padding:12px}")
    html.append("code{font-family:Consolas,monospace}")
    html.append("</style></head><body>")
    html.append("<h1>Delphi MT05.2 calibration maps</h1>")
    html.append("<div class='meta'>dump: %s<br>sha256: %s<br>base: 0x%06X<br>tables: %d</div>" %
                (dump_display, sha, BASE, len(tables)))
    html.append("<div class='warn'><b>Axis caveat:</b> the heatmap axes are table indices. "
                "The physical axis descriptors live in external RAM (0x7000/0x750A..0x7564) "
                "and are not present in the flash dump. The physical units of these tables "
                "are inferred, not proven. See <code>docs/06-calibration.md</code>.</div>")

    for t in tables:
        html.append("<div class='table'>")
        if t["kind"] == "tbl2d":
            vals = t["data"]
            vmin, vmax = min(vals), max(vals)
            svg = heatmap_svg(t["name"], t["address"], t, vmin, vmax)
            fname = t["name"] + ".svg"
            open(os.path.join(out, fname), "w").write(svg)
            html.append(f"<h2>{t['name']} <small>0x{t['address']:06X} · {t['cols']}×{t['rows']} · shift {t['shift']}</small></h2>")
            html.append(svg)
        else:
            vals = t["data"]
            vmin, vmax = min(vals), max(vals)
            svg = line_svg(t["name"], t["address"], t, vmin, vmax)
            fname = t["name"] + ".svg"
            open(os.path.join(out, fname), "w").write(svg)
            html.append(f"<h2>{t['name']} <small>0x{t['address']:06X} · {t['count']} points · shift {t['shift']}</small></h2>")
            html.append(svg)
        html.append("</div>")

    html.append("<p><a href='maps.json'>maps.json</a> · "
                "<a href='decoded_tables.csv'>decoded_tables.csv</a></p>")
    html.append("</body></html>")
    open(os.path.join(out, "index.html"), "w").write("\n".join(html))

    readme = f"""# Map visualiser output

Generated by `firmware/tools/visualize_maps.py` from:

```
{dump_display}
sha256: {sha}
```

Files:

* `index.html` — all recovered tables in one page
* `*.svg` — individual heatmaps/line charts
* `maps.json` — decoded table data
* `decoded_tables.csv` — flat per-cell/per-point values

The heatmap axes are table indices. The physical axis descriptors live in
external RAM (0x7000/0x750A..0x7564) and are not in the flash dump, so the
RPM/load breakpoints and physical units are not shown. See
`docs/06-calibration.md` and `firmware/ALGORITHMS.md`.

To regenerate from the project root:

```bash
cd firmware
make maps
```
"""
    open(os.path.join(out, "README.md"), "w").write(readme)

    print(f"wrote {out}: {len(tables)} tables")
    print(f"  {out}/index.html")
    print(f"  {out}/maps.json")
    print(f"  {out}/decoded_tables.csv")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
