// c03a3a gap_c03a3a size=290 cc=unknown proto=undefined gap_c03a3a(void)

void gap_c03a3a(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  byte bVar4;
  
  bVar4 = bRame00002;
  if (0x41 < bRame00002) {
    bVar4 = 0x41;
  }
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf;
  T3 = 0;
  if (cRame00001 == '\x01') {
    uVar3 = P1L;
    P1L = uVar3 & 0xfffd | 2;
    uVar3 = P1L;
    P1L = uVar3 & 0xfff7;
    uVar3 = P1H;
    P1H = uVar3 & 0xfffe;
  }
  else {
    if (cRame00001 == '\x02') {
      uVar3 = P1L;
      P1L = uVar3 & 0xfffd;
      uVar3 = P1L;
      P1L = uVar3 & 0xfff7 | 8;
    }
    else {
      if (cRame00001 != '\x03') goto LAB_c03ad2;
      uVar3 = P1L;
      P1L = uVar3 & 0xfffd | 2;
    }
    uVar3 = P1H;
    P1H = uVar3 & 0xfffe | 1;
  }
LAB_c03ad2:
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf | 0x40;
  sVar1 = T3;
  uVar3 = P1L;
  P1L = uVar3 & 0xff7f | 0x80;
  while (sVar2 = T3, (ushort)(sVar2 - sVar1) < (ushort)bVar4 * 1000) {
    __service_watchdog();
  }
  uVar3 = P5;
  if ((uVar3 & 0x1000) == 0) {
    uRame00020 = 0;
  }
  else {
    uRame00020 = 0xff;
  }
  uVar3 = P1L;
  P1L = uVar3 & 0xff7f;
  uVar3 = P1H;
  P1H = uVar3 & 0xfffe;
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf;
  uVar3 = P1L;
  P1L = uVar3 & 0xfffd;
  uVar3 = P1L;
  P1L = uVar3 & 0xfff7;
  return;
}

