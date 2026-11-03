/* c10370 adc_start */

/* Start ADC conversion; selects pin mode from calibration. */

void adc_start(void)

{
  DAT_00ffbe = 0x9000;
  CC14 = 0;
  if (cal_adc_config != 0) {
    P5DIDIS = 0xc47f;
    return;
  }
  P5DIDIS = 0x847f;
  return;
}


