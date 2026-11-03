// c0f378 gap_c0f378 size=90 cc=unknown proto=undefined gap_c0f378(void)

void gap_c0f378(void)

{
  undefined2 uVar1;
  byte bVar2;
  ushort uVar3;
  
  bVar2 = UNK_00c3b9;
  DAT_00c446 = (ushort)bVar2;
  uVar1 = DAT_00c27e;
  DAT_00c466 = uVar1;
  uVar3 = DAT_00fd06;
  if ((uVar3 & 0x8000) != 0) {
    uVar3 = DAT_00fd0a;
    if (((uVar3 & 1) == 0) || ((uVar3 = DAT_00fd0a, (uVar3 & 1) != 0 && (bVar2 == 1)))) {
      DAT_00c446 = 1;
      FUN_c0e7ca();
      uVar1 = DAT_00c466;
      Ram00c3f0 = uVar1;
      func_0xc0eafe();
      func_0xc0e910();
      uVar3 = DAT_00fd06;
      DAT_00fd06 = uVar3 | 1;
      return;
    }
    uVar3 = DAT_00fd06;
    if ((uVar3 & 0x800) == 0) {
      uVar1 = DAT_00c466;
      Ram00c3f0 = uVar1;
      FUN_c0f482(1);
    }
  }
  return;
}

