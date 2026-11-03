/* c105ec adc_calibrate */

/* ADC calibration/start. */

void adc_calibrate(void)

{
  ushort uVar1;
  
  can_bus_config();
  uVar1 = DAT_00ffbe;
  DAT_00ffbe = uVar1 & 0xbfff;
  do {
    uVar1 = DAT_00f110;
  } while ((uVar1 & 0x8000) == 0);
  DAT_00f110 = 0;
  DAT_00f0d2 = 0xfc31;
  DAT_00f0d0 = 0xfc31;
  uVar1 = ADCON;
  ADCON = uVar1 | 0x54;
  DAT_00f10c = 1;
  uVar1 = PSW;
  PSW = uVar1 | 1;
  return;
}


