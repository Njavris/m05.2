#!/usr/bin/env python3
"""Interactive viewer for the 9x9 fuel/volume-efficiency map at 0xC0794A.

No third-party Python or JavaScript packages are required. The generated HTML
contains a hoverable heatmap, an adjustable 3D surface, and optional A/B/diff
views for two dumps. Axis descriptors are external RAM, so the axes are table
indices; the map is shown in raw counts and as an inferred VE percentage.
"""
import argparse
import hashlib
import json
import os
import sys

BASE = 0xC00000
MAP_OFFSET = 0x794A
CORRECTION_OFFSET = 0x79B6
VE_SCALE = 0.390625
ROOT = os.path.normpath(os.path.join(os.path.dirname(__file__), "..", "..", "..", ".."))
DEFAULT_DUMP = os.path.join(ROOT, "dumps", "mash_dump.bin")
DEFAULT_OUT = os.path.join(ROOT, "c166sv2", "deliverables", "artifacts", "maps", "fuel_map.html")


def display_path(path):
    try:
        return os.path.relpath(os.path.abspath(path), ROOT)
    except ValueError:
        return os.path.basename(path)


def load_dump(path):
    with open(path, "rb") as f:
        data = f.read()
    if len(data) < 0x40000:
        raise ValueError("dump must be at least 256 KB")
    return data


def parse_map(data):
    off = MAP_OFFSET
    cols = data[off]
    rows = data[off + 1]
    shift = data[off + 2]
    count = cols * rows
    values = list(data[off + 3:off + 3 + count])
    if len(values) != count:
        raise ValueError("short fuel map")
    return {
        "address": "0x%06X" % (BASE + off),
        "cols": cols,
        "rows": rows,
        "shift": shift,
        "values": values,
        "min": min(values),
        "max": max(values),
    }


def parse_correction(data):
    off = CORRECTION_OFFSET
    count = data[off]
    shift = data[off + 1]
    values = list(data[off + 2:off + 2 + count])
    return {
        "address": "0x%06X" % (BASE + off),
        "count": count,
        "shift": shift,
        "values": values,
    }


def map_payload(path):
    data = load_dump(path)
    fuel = parse_map(data)
    fuel["dump"] = display_path(path)
    fuel["sha256"] = hashlib.sha256(data).hexdigest()
    fuel["ve"] = [round(v * VE_SCALE, 4) for v in fuel["values"]]
    fuel["correction"] = parse_correction(data)
    return fuel


def print_text(fuel):
    print("%s  %dx%d  shift %d  min %d max %d" %
          (fuel["address"], fuel["cols"], fuel["rows"], fuel["shift"],
           fuel["min"], fuel["max"]))
    print("      " + " ".join("%5d" % c for c in range(fuel["cols"])))
    for r in range(fuel["rows"]):
        row = fuel["values"][r * fuel["cols"]:(r + 1) * fuel["cols"]]
        print("%4d  " % r + " ".join("%5d" % v for v in row))
    print("\nVE estimate (%):")
    for r in range(fuel["rows"]):
        row = fuel["ve"][r * fuel["cols"]:(r + 1) * fuel["cols"]]
        print("%4d  " % r + " ".join("%5.1f" % v for v in row))


HTML = r'''<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>__TITLE__</title>
<style>
:root { color-scheme: light; }
body { margin: 24px; font-family: system-ui, -apple-system, Segoe UI, Arial, sans-serif;
       color: #111827; background: #f8fafc; }
h1 { font-size: 24px; margin: 0 0 6px; }
h2 { font-size: 17px; margin: 28px 0 8px; border-bottom: 1px solid #e5e7eb; padding-bottom: 4px; }
.meta { font-family: ui-monospace, Consolas, monospace; font-size: 12px; color: #4b5563;
        background: #fff; border: 1px solid #e5e7eb; border-radius: 6px; padding: 10px; }
.warn { background: #fff7ed; border: 1px solid #fdba74; border-radius: 6px;
        padding: 10px 12px; margin: 14px 0; color: #7c2d12; }
.controls { display: flex; flex-wrap: wrap; gap: 10px; align-items: center; margin: 12px 0; }
button { border: 1px solid #cbd5e1; background: #fff; color: #111827; border-radius: 6px;
         padding: 6px 12px; cursor: pointer; font: inherit; }
button.active { background: #1f6feb; border-color: #1f6feb; color: #fff; }
.panel { background: #fff; border: 1px solid #e5e7eb; border-radius: 8px; padding: 14px;
         display: inline-block; vertical-align: top; margin: 0 14px 14px 0; }
canvas { display: block; }
.tooltip { position: fixed; pointer-events: none; background: #111827; color: #fff;
           padding: 5px 8px; border-radius: 4px; font: 12px ui-monospace, monospace;
           opacity: 0; transition: opacity .08s; z-index: 10; }
.legend { display: flex; align-items: center; gap: 8px; font-size: 12px; color: #4b5563; }
.legend-bar { width: 180px; height: 10px; border: 1px solid #cbd5e1;
              background: linear-gradient(to right, #1d4ed8, #22c55e, #eab308, #ef4444); }
.small { font-size: 12px; color: #4b5563; }
code { font-family: ui-monospace, Consolas, monospace; }
</style>
</head>
<body>
<h1>__TITLE__</h1>
<div class="meta" id="meta"></div>
<div class="warn">
  <b>Axis caveat:</b> the physical RPM/load descriptors live outside the flash
  image. The axes below are table indices, not measured RPM/kPa. The VE estimate
  uses the observed warm scale <code>value × 0.390625</code>.
</div>
<div class="controls">
  <button id="btnRaw" class="active">Raw counts</button>
  <button id="btnVE">VE estimate %</button>
  <button id="btnReset">Reset 3D view</button>
</div>
<div class="panel">
  <h2 id="mapTitle" style="margin-top:0">Fuel map A</h2>
  <canvas id="mapA" width="560" height="560"></canvas>
  <div class="legend"><span id="legendMin"></span><div class="legend-bar"></div><span id="legendMax"></span></div>
</div>
<div class="panel" id="comparePanel" style="display:none">
  <h2 style="margin-top:0">Map B / difference</h2>
  <canvas id="mapB" width="560" height="560"></canvas>
  <div class="small" id="diffInfo"></div>
</div>
<div class="panel">
  <h2 style="margin-top:0">3D surface</h2>
  <canvas id="surface" width="720" height="520"></canvas>
  <div class="small">Drag to rotate.</div>
</div>
<div class="tooltip" id="tip"></div>
<script>
const DATA = __DATA__;
const VE_SCALE = __VE_SCALE__;
const $ = (id) => document.getElementById(id);
let mode = 'raw';
let yaw = -0.65, pitch = 0.55;

function displayValue(v) {
  return mode === 've' ? v * VE_SCALE : v;
}
function fmt(v) {
  return mode === 've' ? v.toFixed(1) + '%' : String(v);
}
function colorFor(v, min, max) {
  const t = max > min ? (v - min) / (max - min) : 0;
  const stops = [[29,78,216],[34,197,94],[234,179,8],[239,68,68]];
  const p = Math.max(0, Math.min(0.9999, t)) * 3;
  const i = Math.floor(p), f = p - i;
  const a = stops[i], b = stops[i + 1];
  return `rgb(${Math.round(a[0]+(b[0]-a[0])*f)},${Math.round(a[1]+(b[1]-a[1])*f)},${Math.round(a[2]+(b[2]-a[2])*f)})`;
}
function stats(values) {
  return {min: Math.min(...values), max: Math.max(...values)};
}
function drawMeta() {
  const a = DATA.a;
  let text = `map ${a.address} · ${a.cols}×${a.rows} · shift ${a.shift} · ` +
             `dump ${a.dump} · sha256 ${a.sha256.slice(0,16)}…`;
  if (DATA.b) {
    text += `<br>compare ${DATA.b.dump} · sha256 ${DATA.b.sha256.slice(0,16)}…`;
  }
  $('meta').innerHTML = text;
  const s = stats(a.values);
  $('legendMin').textContent = fmt(displayValue(s.min));
  $('legendMax').textContent = fmt(displayValue(s.max));
}
function drawHeat(canvas, values, cols, rows, diff) {
  const ctx = canvas.getContext('2d');
  const left = 52, top = 36, cell = Math.min((canvas.width-left-16)/cols, (canvas.height-top-16)/rows);
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  const s = stats(values);
  const min = diff ? Math.min(-1, s.min) : s.min;
  const max = diff ? Math.max(1, s.max) : s.max;
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      const v = values[r*cols+c];
      ctx.fillStyle = diff ? (v < 0 ? colorFor(-v,0,max) : colorFor(v,0,max)) : colorFor(v,min,max);
      if (diff && v < 0) ctx.globalAlpha = 0.55;
      ctx.fillRect(left+c*cell, top+r*cell, cell-1, cell-1);
      ctx.globalAlpha = 1;
      ctx.fillStyle = '#111827';
      ctx.font = '11px ui-monospace, Consolas, monospace';
      ctx.textAlign = 'center';
      ctx.textBaseline = 'middle';
      const label = diff ? (v>0?'+':'')+v : (mode === 've' ? (v*VE_SCALE).toFixed(1) : String(v));
      ctx.fillText(label, left+c*cell+cell/2, top+r*cell+cell/2);
    }
  }
  ctx.fillStyle = '#374151';
  ctx.font = '12px system-ui, sans-serif';
  ctx.textAlign = 'center';
  for (let c = 0; c < cols; c++) ctx.fillText(String(c), left+c*cell+cell/2, top-12);
  ctx.textAlign = 'right';
  for (let r = 0; r < rows; r++) ctx.fillText(String(r), left-8, top+r*cell+cell/2);
  ctx.textAlign = 'center';
  ctx.fillText('column index', left+cols*cell/2, top+rows*cell+28);
  ctx.save();
  ctx.translate(14, top+rows*cell/2);
  ctx.rotate(-Math.PI/2);
  ctx.fillText('row index', 0, 0);
  ctx.restore();
}
function drawSurface(values, cols, rows) {
  const canvas = $('surface'), ctx = canvas.getContext('2d');
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  const s = stats(values);
  const range = Math.max(1, s.max - s.min);
  const cx = canvas.width/2, cy = canvas.height/2 + 40;
  const scale = Math.min(canvas.width/(cols+3), canvas.height/(rows+3));
  const quads = [];
  for (let r = 0; r < rows-1; r++) {
    for (let c = 0; c < cols-1; c++) {
      const pts = [[c,r],[c+1,r],[c+1,r+1],[c,r+1]].map(([x,y]) => {
        const z = (values[y*cols+x]-s.min)/range;
        let px = (x-(cols-1)/2), py = (y-(rows-1)/2), pz = z*1.8;
        let xx = px*Math.cos(yaw)-py*Math.sin(yaw);
        let yy = px*Math.sin(yaw)+py*Math.cos(yaw);
        let zz = pz*Math.cos(pitch)-yy*Math.sin(pitch);
        let yy2 = pz*Math.sin(pitch)+yy*Math.cos(pitch);
        return {x: cx+xx*scale, y: cy+zz*scale, depth: yy2};
      });
      const v = values[r*cols+c];
      quads.push({pts, v, depth: (pts[0].depth+pts[2].depth)/2});
    }
  }
  quads.sort((a,b) => a.depth-b.depth);
  for (const q of quads) {
    ctx.beginPath();
    ctx.moveTo(q.pts[0].x,q.pts[0].y);
    for (let i=1;i<q.pts.length;i++) ctx.lineTo(q.pts[i].x,q.pts[i].y);
    ctx.closePath();
    ctx.fillStyle = colorFor(q.v, s.min, s.max);
    ctx.globalAlpha = 0.9;
    ctx.fill();
    ctx.globalAlpha = 1;
    ctx.strokeStyle = '#ffffff';
    ctx.stroke();
  }
  ctx.fillStyle = '#374151';
  ctx.font = '12px system-ui, sans-serif';
  ctx.textAlign = 'center';
  ctx.fillText('drag to rotate · colour = map value', canvas.width/2, 22);
}
function redraw() {
  const a = DATA.a;
  drawMeta();
  drawHeat($('mapA'), a.values, a.cols, a.rows, false);
  $('comparePanel').style.display = DATA.b ? 'inline-block' : 'none';
  if (DATA.b) {
    drawHeat($('mapB'), DATA.diff, a.cols, a.rows, true);
    const sum = DATA.diff.reduce((x,y)=>x+y,0);
    $('diffInfo').textContent = `difference = B - A · sum ${sum} · changed cells ${DATA.diff.filter(v=>v!==0).length}`;
  }
  drawSurface(a.values, a.cols, a.rows);
  $('btnRaw').classList.toggle('active', mode === 'raw');
  $('btnVE').classList.toggle('active', mode === 've');
}
function pointerCell(ev, canvas, cols, rows) {
  const rect = canvas.getBoundingClientRect();
  const x = ev.clientX - rect.left, y = ev.clientY - rect.top;
  const left = 52, top = 36;
  const cell = Math.min((canvas.width-left-16)/cols, (canvas.height-top-16)/rows);
  const c = Math.floor((x-left)/cell), r = Math.floor((y-top)/cell);
  if (c >= 0 && c < cols && r >= 0 && r < rows) return {r,c};
  return null;
}
function bindMap(canvas, values, cols, rows, isDiff) {
  const tip = $('tip');
  canvas.addEventListener('mousemove', (ev) => {
    const cell = pointerCell(ev, canvas, cols, rows);
    if (!cell) { tip.style.opacity = 0; return; }
    const v = values[cell.r*cols+cell.c];
    tip.textContent = isDiff
      ? `row ${cell.r} col ${cell.c} · diff ${v>0?'+':''}${v}`
      : `row ${cell.r} col ${cell.c} · ${v} · ${ (v*VE_SCALE).toFixed(1) }% VE est.`;
    tip.style.left = (ev.clientX+12)+'px';
    tip.style.top = (ev.clientY+12)+'px';
    tip.style.opacity = 1;
  });
  canvas.addEventListener('mouseleave', () => { tip.style.opacity = 0; });
}
function bindSurface() {
  const canvas = $('surface');
  let drag = null;
  canvas.addEventListener('mousedown', (ev) => { drag = {x:ev.clientX,y:ev.clientY}; });
  window.addEventListener('mouseup', () => { drag = null; });
  window.addEventListener('mousemove', (ev) => {
    if (!drag) return;
    yaw += (ev.clientX-drag.x)*0.01;
    pitch = Math.max(-1.4, Math.min(1.4, pitch + (ev.clientY-drag.y)*0.01));
    drag = {x:ev.clientX,y:ev.clientY};
    drawSurface(DATA.a.values, DATA.a.cols, DATA.a.rows);
  });
}
$('btnRaw').onclick = () => { mode = 'raw'; redraw(); };
$('btnVE').onclick = () => { mode = 've'; redraw(); };
$('btnReset').onclick = () => { yaw = -0.65; pitch = 0.55; drawSurface(DATA.a.values, DATA.a.cols, DATA.a.rows); };
bindMap($('mapA'), DATA.a.values, DATA.a.cols, DATA.a.rows, false);
if (DATA.b) bindMap($('mapB'), DATA.diff, DATA.a.cols, DATA.a.rows, true);
bindSurface();
redraw();
</script>
</body>
</html>
'''


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--dump", default=DEFAULT_DUMP)
    ap.add_argument("--compare", default=None,
                    help="second dump for an A/B and difference view")
    ap.add_argument("--out", default=DEFAULT_OUT)
    ap.add_argument("--title", default="MT05.2 fuel / volume-efficiency map")
    ap.add_argument("--text", action="store_true", help="print the map and exit")
    args = ap.parse_args()

    fuel = map_payload(args.dump)
    if args.text:
        print_text(fuel)
        return 0

    payload = {"a": fuel}
    if args.compare:
        other = map_payload(args.compare)
        if (other["cols"], other["rows"]) != (fuel["cols"], fuel["rows"]):
            raise SystemExit("map dimensions differ")
        payload["b"] = other
        payload["diff"] = [b - a for a, b in zip(fuel["values"], other["values"])]

    os.makedirs(os.path.dirname(os.path.abspath(args.out)), exist_ok=True)
    html = HTML.replace("__TITLE__", args.title)
    html = html.replace("__VE_SCALE__", repr(VE_SCALE))
    html = html.replace("__DATA__", json.dumps(payload).replace("</", "<\\/"))
    with open(args.out, "w") as f:
        f.write(html)
    print("wrote %s" % args.out)
    print("map %s  %dx%d  min %d max %d" %
          (fuel["address"], fuel["cols"], fuel["rows"], fuel["min"], fuel["max"]))
    if args.compare:
        print("compare %s" % display_path(args.compare))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
