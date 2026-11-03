// c00ca2 capcom_timer_init size=146 cc=unknown proto=undefined capcom_timer_init(void)

void capcom_timer_init(char param_1)

{
  ushort uVar1;
  
  T78CON = 0;
  if (param_1 == '\x02') {
    T7 = 0xfbe0;
    T7REL = 0xfbe0;
  }
  else {
    T7 = 0xf060;
    T7REL = 0xf060;
  }
  T8 = 0xffff;
  T8REL = 0;
  T7IC = 0x58;
  CC16 = 0;
  CC17 = 0;
  CC18 = 0;
  CC19 = 0;
  CC20 = 0;
  CC21 = 0;
  CC22 = 0;
  CC23 = 0;
  CC24 = 0;
  CC25 = 0;
  CC26 = 0;
  CC27 = 0;
  CC28 = 0;
  CC29 = 0;
  CC30 = 0;
  CC31 = 0;
  CCM4 = 0;
  CCM5 = 0;
  CCM6 = 0;
  CCM7 = 0;
  DAT_00ff2a = 0;
  DAT_00fe28 = 0;
  DAT_00fe2a = 0;
  DAT_00ff2c = 0;
  uVar1 = T78CON;
  T78CON = uVar1 | 0x40;
  return;
}

