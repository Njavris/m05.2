// c0cea2 capcom_start size=118 cc=unknown proto=undefined capcom_start(void)

void capcom_start(void)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = DAT_00f066;
  DAT_00f066 = uVar2 | 4;
  uVar2 = T78CON;
  T78CON = uVar2 | 5;
  T7 = 0;
  T7REL = 0;
  T8 = 0;
  T8REL = 0;
  bVar1 = 0;
  uVar2 = (ushort)&CC16;
  do {
    bVar1 = bVar1 + 1;
    *(undefined2 *)(uint3)uVar2 = 0;
    uVar2 = uVar2 + 2;
  } while (bVar1 < 0x10);
  CCM4 = 0;
  CCM7 = 0;
  CCM6 = 3;
  DAT_00ff2a = 0;
  DAT_00fe28 = 0;
  DAT_00fe2a = 0;
  DAT_00ff2c = 0;
  uVar2 = CC24IC;
  CC24IC = uVar2 | 0x38;
  uVar2 = T5CON;
  T5CON = uVar2 | 10;
  T5 = 0;
  CAPREL = 0;
  uVar2 = T5IC;
  T5IC = uVar2 | 0x24;
  uVar2 = T7IC;
  T7IC = uVar2 | 0x79;
  uVar2 = T5CON;
  T5CON = uVar2 | 0x40;
  uVar2 = T78CON;
  T78CON = uVar2 | 0x40;
  uVar2 = CC31IC;
  CC31IC = uVar2 | 0xcc;
  return;
}

