// c10370 adc_start size=32 cc=unknown proto=undefined adc_start(void)

void adc_start(void)

{
  DAT_00ffbe = 0x9000;
  DAT_00f09c = 0;
  if (DAT_c0506a != 0) {
    P5DIDIS = 0xc47f;
    return;
  }
  P5DIDIS = 0x847f;
  return;
}

