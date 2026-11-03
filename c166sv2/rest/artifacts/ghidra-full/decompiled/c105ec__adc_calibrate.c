// c105ec adc_calibrate size=44 cc=unknown proto=undefined adc_calibrate(void)

void adc_calibrate(void)

{
  ushort uVar1;
  
  can_bus_config();
  uVar1 = DAT_00f1be;
  DAT_00f1be = uVar1 & 0xbfff;
  do {
    uVar1 = DAT_00f110;
  } while ((uVar1 & 0x8000) == 0);
  DAT_00f110 = 0;
  T14 = 0xfc31;
  T14REL = 0xfc31;
  uVar1 = DAT_00f1a0;
  DAT_00f1a0 = uVar1 | 0x54;
  DAT_00f10c = 1;
  uVar1 = DAT_00f110;
  DAT_00f110 = uVar1 | 1;
  return;
}

