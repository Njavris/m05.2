// c0fd82 FUN_c0fd82 size=126 cc=unknown proto=undefined FUN_c0fd82(void)

void FUN_c0fd82(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  
  bVar1 = DAT_00fd12;
  if (0x10 < bVar1) {
    uVar3 = DAT_00fd10;
    DAT_00fd10 = uVar3 | 4;
  }
  bVar1 = DAT_00fd0e;
  if (0x10 < bVar1) {
    uVar3 = DAT_00fd0c;
    DAT_00fd0c = uVar3 | 4;
  }
  bVar1 = DAT_00c47c;
  if (0x10 < bVar1) {
    sVar2 = DAT_00c47e;
    if (sVar2 == 1) {
      bVar1 = DAT_00c47b;
      if (bVar1 < 8) {
        DAT_00c47e = 2;
      }
      else {
        DAT_00c47e = 0;
        uVar3 = DAT_00fd0c;
        DAT_00fd0c = uVar3 | 4;
      }
    }
    else if (sVar2 == 2) {
      bVar1 = DAT_00c480;
      if (bVar1 < 8) {
        DAT_00c47e = 3;
      }
      else {
        DAT_00c47e = 0;
        uVar3 = DAT_00fd10;
        DAT_00fd10 = uVar3 | 4;
      }
    }
    else {
      if (sVar2 != 3) {
        return;
      }
      bVar1 = DAT_00c47a;
      if (7 < bVar1) {
        uVar3 = DAT_00fd10;
        DAT_00fd10 = uVar3 | 4;
      }
      DAT_00c47e = 0;
    }
    DAT_00c47c = 0;
  }
  return;
}

