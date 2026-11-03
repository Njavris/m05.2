# 6. Calibration block and table formats

## 6.1 Location and identity

| Item | Value |
|---|---|
| Block range | 0xC05000–0xC0AFFF (24 KB) |
| First bytes | `44 30 30 30 31 30 31 20` = `D000101 ` |
| Checksum | 16-bit sum over 0xC05000–0xC0AFFD stored at **0xC0AFFE = 0x8D79** |
| Coverage | Not covered by the application checksum, so calibration can be changed independently |
| Address form in code | segment 0xC0, 16-bit offsets 0x5000–0xAFFF |

The block is referenced both as a physical segment (`param_2 = 0xC0` in the
table lookup functions) and through DPP page 0x301 (0xC04000–0xC07FFF) when the
code uses 16-bit pointers.

## 6.2 Header / configuration bytes

The first 0x100 bytes contain the ID and a set of small configuration values.
The most useful observed bytes:

| Address | Value | Used by | Meaning |
|---|---:|---|---|
| 0xC05000 | `D000101 ` | `cal_checksum` reference start | calibration ID string |
| 0xC05036 | 0x0001 | 0xC0FEBC, 0xC0F632 | configuration selector |
| 0xC05064 | 0x0000 | 0xC13F74 | capture/config flag |
| 0xC05068 | 0x0003 | 0xC1074C | timer T8 / CAPCOM configuration |
| 0xC0506A | 0x0000 | 0xC1037E | ADC/pin configuration |
| 0xC0507A | 0x0001 | 0xC1FD9C | calculation variant flag |
| 0xC05080 | 0x0001 | 0xC0BDA6 | timer T4 config flag |
| 0xC05081 | 0x0000 | 0xC1093E | PWM config flag (code checks for 2; inactive here) |

These are read as bits/bytes by the application; the names above are inferred
from the functions that read them, not from any symbol table.

## 6.3 Table formats

Three table formats are used by the calibration access layer.

### 6.3.1 16-bit axis descriptor (`axis16_unsigned` / `axis16_signed`)

`axis16_unsigned` at 0xC2850E and `axis16_signed` at 0xC284D8 take a pointer to
a three-word descriptor:

```c
struct axis16 {
    uint16_t count;     /* number of points */
    uint16_t min;       /* input value at point 0 */
    uint16_t max;       /* input value at point count-1 */
};
```

They return an **8.8 fixed-point index**:

```c
index = (value - min) * (count - 1) * 256 / (max - min);
```

The caller then uses `index` with one of the table lookup functions. Axis
descriptors used by the engine calculations are at logical **0x750A, 0x7510,
0x7552, 0x755E, 0x7564**. With `DPP1 = 0x302` they map to physical flash
`0xC0B50A`, `0xC0B510`, `0xC0B552`, `0xC0B55E`, `0xC0B564` and are present in
the dump.

### 6.3.2 8-bit table (`tbl8_interp`, 0xC27FCA)

```
byte 0: count
byte 1: shift (usually 0; used as an output scaling shift)
byte 2..: count bytes of data
```

The function reads `data[integer_index]` and linearly interpolates to
`data[integer_index+1]` using the low byte of the 8.8 index. It is used for
small correction curves.

### 6.3.3 16-bit table (`tbl16_interp`, 0xC27CA4)

```
word 0: count
word 1..: count 16-bit values
```

Same interpolation, but on 16-bit entries.

### 6.3.4 2D map (`tbl2d_interp`, 0xC2826E)

```
byte 0: number of columns (9 for the recovered map)
byte 1: row count (9 for the recovered map; not used by the interpolator itself)
byte 2: interpolation shift (1 for the recovered map)
byte 3..: row-major 8-bit cells
```

The index is:

```c
cell_index = (y >> 8) * columns + (x >> 8);
```

and the function bilinearly interpolates between the four surrounding cells.
The 9×9 map at 0xC0794A is the main recovered map.

## 6.4 Recovered tables referenced by code

All table addresses below are **physical**; the code sometimes uses the
equivalent segment-0xC0 offset (e.g. 0x794A → 0xC0794A). Raw data is in
`c166sv2/deliverables/artifacts/calibration_tables.csv`.

| Physical address | Kind | Used by | Format | Preview |
|---|---|---|---|---|
| 0xC0784C | 8-bit | `calc_limit2` 0xC201AE | count 17, shift 1 | 05 05 05 05 05 05 05 03 00 ... |
| 0xC07860 | 8-bit | `calc_limit2` 0xC201AE | count 17, shift 1 | 49 48 43 3E 39 14 0C 06 04 ... |
| 0xC07874 | 8-bit | `calc_limit3` 0xC202EE | count 17, shift 1 | 61 54 43 2E 1F 05 05 05 05 ... |
| 0xC078D8 | 8-bit | `calc_limit3` 0xC202EE | count 6, shift 0 | B7 75 5B 34 20 20 |
| 0xC078E2 | 8-bit | `calc_limit3` 0xC202EE | count 17, shift 0 | F9 F9 F9 F9 F9 F8 F7 F7 ... |
| 0xC07912 | 16-bit | `calc_limit1/2/3` | count 17 | 015B 0132 0100 00BC 00B6 ... |
| 0xC0794A | 2D 8-bit | `calc_load` 0xC1FD9C | 9 columns × 9 rows, shift 1 | see below |
| 0xC0799E | 8-bit | `calc_load` 0xC1FD9C | count 9, shift 0 | 03 03 03 03 03 03 03 03 03 |
| 0xC079AA | 8-bit | `calc_load` 0xC1FD9C | count 9, shift 0 | 03 03 03 03 03 03 03 03 03 |
| 0xC079B6 | 8-bit | `calc_load` 0xC1FD9C | count 17, shift 0 | B4 B4 B4 AB 9F 95 8A 80 80 ... |

> live-data-range cross-check: the 17-point `0xC07860` curve divided by 2 spans
> 2.0–36.5 °CA, close to the logged spark-advance range 10.5–36.25 °CA; the
> 16-bit `0xC07912` table divided by 64 spans 2.47–5.42 ms, inside the logged
> injector-time range. The `calc_limit*` names are therefore provisional; these
> may be ignition/injection calculations with limit flags, not pure limits.

### The 9×9 map at 0xC0794A

```
row 0:  00 00 0A 0C 0D 0E 0F 0F 10
row 1:  00 08 0A 0C 0D 0E 0F 0F 10
row 2:  00 0C 18 1D 21 21 23 24 23
row 3:  00 12 23 30 38 35 33 35 36
row 4:  00 22 35 47 50 50 50 52 57
row 5:  00 33 47 62 72 7B 84 7A 7C
row 6:  00 42 63 81 9E AA AD A6 AC
row 7:  00 5A 89 A2 BD D5 DD DE E3
row 8:  00 65 97 B9 E3 F1 F4 F4 F2
```

The map is monotonic in both axes and saturates near row 8. the live-data profile's live-data
profile labels the corresponding quantity **Volume Efficiency** (`FVE1`/`FVE2`).
A 1-cylinder MT05.2 log confirms the scaling: the largest map cell is 244,
and the logged `FVE1` maximum is 95.20%, while `244 * 0.390625 = 95.31%`.
With the warm correction at 0x80 (128), `calc_load` produces `map/2`;
the live-data profile's `FVE1` raw value is that result times 256. This strongly identifies the map as a
**volumetric-efficiency/load map**, not a generic fuel or advance map. The exact
input axes, idle-point correction and normalized unit remain unresolved; the
max-cell match is the strongest evidence.

The `0xC079B6` curve starts at 0xB4 (180), falls to 0x80 (128), and stays at
0x80. 0x80 is the natural 8-bit "1.0" point, so this looks like a
**multiplicative correction** (warm-up, voltage, or temperature), saturated at
1.0. `calc_load` computes:

```c
map = tbl2d_interp(0xC0794A, segment_C0, x_index, y_index);
corr = tbl8_interp(0xC079B6, segment_C0, correction_index);
result = (map * corr) >> 15;
```

That is a base value times a correction factor. The result is stored in XRAM at
0xE008B2. An interactive 2D/3D view of this map is generated at
[`../../deliverables/artifacts/maps/fuel_map.html`](../../deliverables/artifacts/maps/fuel_map.html).

## 6.5 Calibration-related code

| Function | Address | Role |
|---|---|---|
| `axis16_unsigned` | 0xC2850E | unsigned count/min/max → 8.8 index |
| `axis16_signed` | 0xC284D8 | signed variant |
| `tbl8_interp` | 0xC27FCA | 8-bit table + interpolation |
| `tbl16_interp` | 0xC27CA4 | 16-bit table + interpolation |
| `tbl2d_interp` | 0xC2826E | 2D 8-bit map + bilinear interpolation |
| `mul32` | 0xC28B64 | 32-bit multiply helper used by the interpolators |
| `calc_load` | 0xC1FD9C | VE/load map + correction; live-data `FVE1` |
| `calc_limit1` | 0xC200AA | provisional injection-time/limit calculation using 0xC07912 |
| `calc_limit2` | 0xC201AE | provisional spark/limit calculation using 0xC0784C/0xC07860 |
| `calc_limit3` | 0xC202EE | provisional spark/limit calculation using 0xC07874/0xC078D8/0xC078E2 |
| `cal_checksum` | 0xC11B9A | verify calibration block vs 0xC0AFFE |

The calculation functions read engine variables in **external RAM** at
0x00C9xx/0x00CAxx (for example 0xC9D0, 0xC97C, 0xCA2A) and write XRAM results
at 0xE008A0–0xE008B2. Those variables are produced by other tasks and are not
present in the dump.

## 6.6 Limitations

* The axis descriptors at logical 0x750A–0x7564 map through DPP1 to physical
  flash `0xC0B50A–0xC0B564` and are present in the image.
* The scheduler task table at logical 0x705E maps to physical `0xC0B05E` and is
  present.
* The table at 0xC0794A is proven to be a 9×9 8-bit map. live-data `FVE1` and the
  log scaling identify it as a volumetric-efficiency/load map; the exact
  normalized unit is still raw counts.
* The calibration block contains more data between 0xC05000 and 0xC07500 that
  is not directly referenced by the recovered functions. It is preserved in the
  dump and can be inspected as raw bytes; no semantic labels are assigned.
