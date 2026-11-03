// c142a4 gap_c142a4 size=30 cc=unknown proto=undefined gap_c142a4(void)

void gap_c142a4(void)

{
  ushort uVar1;
  
  timer5_init();
  uVar1 = DAT_00f130;
  DAT_00f130 = uVar1 & 0xff7f;
  uVar1 = P1L;
  P1L = uVar1 & 0xff7f;
  uVar1 = DAT_00f120;
  DAT_00f120 = uVar1 & 0xfffe;
  uVar1 = P1H;
  P1H = uVar1 & 0xfffe;
  capture_init();
  config_sensor_setup();
  DAT_00c3a4 = 0;
  return;
}

