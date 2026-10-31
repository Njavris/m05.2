/* c1072a timer8_init */

/* Timer T8/CAPCOM init. */

void timer8_init(void)

{
  ushort uVar1;
  
  uVar1 = T78CON;
  T78CON = uVar1 & 0xff | 0x500;
  T8 = 0;
  T8REL = 0;
  uVar1 = CC2IC;
  CC2IC = uVar1 | 0xe9;
  if ((cal_timer_config == 0) || (cal_timer_config == 4)) {
    CC21 = 0;
    uVar1 = CCM5;
    CCM5 = uVar1 & 0xff8f;
    uVar1 = CCM5;
    CCM5 = uVar1 | 0x30;
    uVar1 = CCM5;
    CCM5 = uVar1 | 0x80;
    uVar1 = CRIC;
    CRIC = uVar1 | 0xe0;
  }
  uVar1 = T78CON;
  T78CON = uVar1 | 0x4000;
  return;
}


