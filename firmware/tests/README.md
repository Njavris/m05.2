# Tests

The host model's tests are compiled into `firmware_model` and run with:

```bash
make test
```

They use the real dump (`../dumps/mash_dump.bin`) and check:

* the three stored/computed checksums;
* the boot decision and ADC mode selection;
* the 128-slot vector table and the eight active handlers;
* KWP2000 seed/key, wrong-key, session, read-memory, transfer-data and
  write-memory paths;
* the K-line request/response framing and checksum;
* axis scaling, 8/16-bit table interpolation, the 9×9 map and `calc_load`;
* the adaptation-log record layout and sequence/tail values.

The test harness lives in `../src/main.c` (`--test` mode). No external test
framework is required.
