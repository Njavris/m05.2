// c0248a boot_hidden_task size=212 cc=unknown proto=undefined boot_hidden_task(void)

void boot_hidden_task(void)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  ushort uVar4;
  
  uVar4 = 0x20;
  cVar1 = DAT_00f800;
  if (cVar1 == -1) {
    uVar4 = 0x22;
  }
  ADCIC = 0;
  uVar2 = ADCON;
  ADCON = uVar2 & 0xff7f;
  DAT_00ffbe = 0;
  DAT_00f09c = 0;
  uVar2 = ADCIC;
  ADCIC = uVar2 & 0xff7f;
  bVar3 = 0;
  do {
    if ((bVar3 < 7) || (0xe < bVar3)) {
      uVar2 = ADCON;
      ADCON = uVar2 & 0xfff0 | bVar3 & 0xf;
      uVar2 = ADCON;
      ADCON = uVar2 & 0xff7f | 0x80;
      while (uVar2 = ADCIC, (uVar2 & 0x80) == 0) {
        __service_watchdog();
      }
      uVar2 = ADCON;
      ADCON = uVar2 & 0xff7f;
      uVar2 = ADCIC;
      ADCIC = uVar2 & 0xff7f;
      uVar2 = ADDAT;
      *(ushort *)(uint3)uVar4 = uVar2 & 0x3ff;
      uVar4 = uVar4 + 2;
    }
    __service_watchdog();
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0x10);
  uVar4 = ADCON;
  if ((uVar4 & 0x100) != 0) {
    uVar4 = ADCON;
    ADCON = uVar4 & 0xff7f;
  }
  return;
}

