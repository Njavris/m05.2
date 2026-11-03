// c0d71e FUN_c0d71e size=96 cc=unknown proto=undefined FUN_c0d71e(void)

undefined4 FUN_c0d71e(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  
  uVar6 = div32u();
  sVar4 = (short)((uVar6 >> 6) >> 0x10);
  uVar1 = (ushort)(uVar6 >> 6);
  DAT_00c3a6 = uVar1;
  DAT_00c3a8 = sVar4;
  sVar2 = uVar1 + 0x100;
  sVar3 = sVar4 - (ushort)(uVar1 < 0xff00);
  if (sVar3 == 0 && sVar2 == 0 || sVar4 == 0 && uVar1 < 0xff00) {
    sVar4 = DAT_00c3a6;
    sVar5 = CC24;
    uVar1 = DAT_00c48e;
    *(short *)(uint3)uVar1 = sVar4 + sVar5;
    return CONCAT22(sVar3,sVar2);
  }
  uVar1 = DAT_00c3a6;
  DAT_00c3a6 = uVar1 + 0x100;
  sVar4 = DAT_00c3a8;
  DAT_00c3a8 = sVar4 - (ushort)(uVar1 < 0xff00);
  DAT_00c3aa = 1;
  sVar4 = CC24;
  uVar1 = DAT_00c48e;
  *(short *)(uint3)uVar1 = sVar4 + -0x100;
  return CONCAT22(sVar3,sVar2);
}

