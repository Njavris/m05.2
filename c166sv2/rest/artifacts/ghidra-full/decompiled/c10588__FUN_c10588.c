// c10588 FUN_c10588 size=94 cc=unknown proto=undefined FUN_c10588(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c10588(short param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  undefined2 uVar4;
  
  DAT_00c4c2 = 0x4000;
  DAT_00c4c4 = 0xc0;
  do {
    uVar1 = DAT_00c4c2;
    _DAT_0004c0 = *(undefined2 *)(uVar1 & 0x3fff);
    uVar1 = TFR;
    if ((uVar1 & 0x10) != 0) {
      uVar1 = TFR;
      TFR = uVar1 & 0xffef;
      uVar2 = DAT_00c4c2;
      uVar4 = DAT_00c4c4;
      FUN_c10d8e(uVar2,uVar4,param_1);
    }
    uVar1 = DAT_00c4c2;
    DAT_00c4c2 = uVar1 + 2;
    sVar3 = DAT_00c4c4;
    DAT_00c4c4 = sVar3 + (ushort)(0xfffd < uVar1);
    sVar3 = DAT_00c4c2;
    uVar1 = DAT_00c4c4;
    param_1 = (uVar1 - 0xc1) - (ushort)(sVar3 != -1);
  } while (uVar1 < 0xc1 || uVar1 == 0xc1 && sVar3 != -1);
  return;
}

