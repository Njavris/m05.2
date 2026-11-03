// c0c65a FUN_c0c65a size=152 cc=unknown proto=undefined FUN_c0c65a(void)

void FUN_c0c65a(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  
  uVar2 = DAT_00fd00;
  DAT_00fd00 = uVar2 & 0xffef;
  cVar3 = DAT_00c256;
  DAT_00c276 = cVar3 + '\x01';
  while (bVar4 = DAT_00c276, *(short *)(uint3)((short)&DAT_00c282 + (ushort)bVar4 * 2) == 0) {
    cVar3 = DAT_00c276;
    DAT_00c276 = cVar3 + '\x01';
  }
  bVar5 = DAT_00c276;
  bVar4 = DAT_00c256;
  uVar2 = (ushort)bVar5 - (ushort)bVar4 & 0xff;
  uVar8 = T5;
  uVar6 = CC24IC;
  uVar7 = PSW;
  PSW = uVar7 & 0xffbf | ((uVar6 & 0x80) >> 7) << 6;
  uVar6 = PSW;
  bVar1 = (uVar6 & 0x40) != 0;
  if (bVar1) {
    uVar8 = T5;
  }
  if (uVar2 <= uVar8) {
    uVar6 = DAT_00fd00;
    DAT_00fd00 = uVar6 | 0x10;
  }
  uVar6 = T5CON;
  T5CON = uVar6 & 0xffbf;
  T5 = uVar8 - uVar2;
  uVar6 = T5CON;
  T5CON = uVar6 | 0x40;
  uVar6 = CC24IC;
  uVar7 = PSW;
  PSW = uVar7 & 0xffbf | ((uVar6 & 0x80) >> 7) << 6;
  uVar6 = PSW;
  if (((uVar6 & 0x40) != 0) && (!bVar1)) {
    uVar6 = DAT_00fd00;
    DAT_00fd00 = uVar6 & 0xffef;
    if (uVar2 <= uVar8 + 1) {
      uVar6 = DAT_00fd00;
      DAT_00fd00 = uVar6 | 0x10;
    }
    uVar6 = T5CON;
    T5CON = uVar6 & 0xffbf;
    T5 = (uVar8 + 1) - uVar2;
    uVar2 = T5CON;
    T5CON = uVar2 | 0x40;
  }
  uVar2 = DAT_00fd00;
  if ((uVar2 & 0x10) != 0) {
    uVar2 = T5IC;
    T5IC = uVar2 & 0xff7f;
  }
  return;
}

