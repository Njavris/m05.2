// c03b5c gap_c03b5c size=230 cc=unknown proto=undefined gap_c03b5c(void)

void gap_c03b5c(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  
  uVar3 = P1H;
  P1H = uVar3 & 0xfffb | 4;
  ADCIC = 0;
  uVar3 = ADCON;
  ADCON = uVar3 & 0xff7f;
  DAT_00ffbe = 0;
  DAT_00f09c = 0;
  uVar3 = ADCIC;
  ADCIC = uVar3 & 0xff7f;
  uVar3 = ADCON;
  ADCON = uVar3 & 0xfffd | 0xf;
  do {
    uVar3 = ADCON;
    ADCON = uVar3 & 0xff7f | 0x80;
    while (uVar3 = ADCIC, (uVar3 & 0x80) == 0) {
      __service_watchdog();
    }
    uVar3 = ADCON;
    ADCON = uVar3 & 0xff7f;
    uVar3 = ADCON;
    if ((uVar3 & 0x100) != 0) {
      uVar3 = ADCON;
      ADCON = uVar3 & 0xff7f;
    }
    uVar3 = ADCIC;
    ADCIC = uVar3 & 0xff7f;
    uVar3 = ADDAT;
  } while (0xf < (uVar3 & 0x3ff));
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf;
  uVar3 = T3CON;
  T3CON = uVar3 & 0xfffa | 7;
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf | 0x40;
  sVar1 = T3;
  while (sVar2 = T3, (ushort)(sVar2 - sVar1) < 0x186a) {
    __service_watchdog();
  }
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf;
  uVar3 = P1H;
  P1H = uVar3 & 0xfffb;
  return;
}

