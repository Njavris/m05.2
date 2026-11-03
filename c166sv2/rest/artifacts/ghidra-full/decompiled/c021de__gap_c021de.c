// c021de gap_c021de size=114 cc=unknown proto=undefined gap_c021de(void)

void gap_c021de(void)

{
  ushort uVar1;
  
  uVar1 = T78CON;
  T78CON = uVar1 & 0xfffa | 7;
  uVar1 = T78CON;
  T78CON = uVar1 & 0xfff7;
  uVar1 = T78CON;
  T78CON = uVar1 & 0xffbf;
  DAT_00ff2a = 0x5555;
  DAT_00f066 = 4;
  T7 = 0;
  T7REL = 0;
  uVar1 = CCM5;
  CCM5 = uVar1 & 0xffdf | 0x70;
  uVar1 = CCM5;
  CCM5 = uVar1 & 0xff7f;
  uVar1 = CCM6;
  CCM6 = uVar1 & 0xfffd | 7;
  uVar1 = CCM6;
  CCM6 = uVar1 & 0xfff7;
  T7IC = 0;
  return;
}

