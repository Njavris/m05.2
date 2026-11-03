// c0f2b8 gap_c0f2b8 size=116 cc=unknown proto=undefined gap_c0f2b8(void)

void gap_c0f2b8(void)

{
  undefined2 uVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  
  if (cRamc07468 == '\x01') {
    bVar2 = UNK_00c3b9;
    DAT_00c446 = bVar2 ^ 1;
  }
  else {
    bVar2 = UNK_00c3b9;
    DAT_00c446 = (ushort)bVar2;
  }
  sVar3 = DAT_00c446;
  uVar1 = DAT_00c27e;
  DAT_00c466 = uVar1;
  uVar4 = DAT_00fd08;
  if ((uVar4 & 0x8000) != 0) {
    uVar4 = DAT_00fd0a;
    if (((uVar4 & 2) == 0) || ((uVar4 = DAT_00fd0a, (uVar4 & 2) != 0 && (sVar3 == 0)))) {
      DAT_00c446 = 0;
      FUN_c0e7ca(0);
      uVar1 = DAT_00c466;
      Ram00c3d6 = uVar1;
      func_0xc0eafe();
      func_0xc0e910();
      uVar4 = DAT_00fd08;
      DAT_00fd08 = uVar4 | 1;
      sVar3 = DAT_00c44c;
      if (sVar3 == 1) {
        uVar1 = DAT_00c466;
        Ram00c3f0 = uVar1;
        uVar4 = DAT_00fd06;
        DAT_00fd06 = uVar4 | 1;
        return;
      }
    }
    else {
      uVar4 = DAT_00fd08;
      if ((uVar4 & 0x800) == 0) {
        uVar1 = DAT_00c466;
        Ram00c3d6 = uVar1;
        sVar5 = FUN_c0f482(0);
        sVar3 = DAT_00c44c;
        if (sVar3 == 1) {
          if (sVar5 == 1) {
            uVar1 = Ram00c3ca;
            FUN_c0f97a(uVar1,1);
          }
          uVar1 = Ram00c3ca;
          Ram00c3e4 = uVar1;
          uVar1 = DAT_00c3cc;
          DAT_00c3e6 = uVar1;
          uVar1 = DAT_00c3d4;
          DAT_00c3ee = uVar1;
          uVar1 = Ram00c3d6;
          Ram00c3f0 = uVar1;
        }
      }
    }
  }
  return;
}

