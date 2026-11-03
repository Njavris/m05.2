// c0f32c gap_c0f32c size=76 cc=unknown proto=undefined gap_c0f32c(void)

void gap_c0f32c(void)

{
  undefined2 uVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  
  uVar3 = DAT_00fd08;
  if ((uVar3 & 0x800) == 0) {
    uVar1 = DAT_00c466;
    Ram00c3d6 = uVar1;
    sVar4 = FUN_c0f482(0);
    sVar2 = DAT_00c44c;
    if (sVar2 == 1) {
      if (sVar4 == 1) {
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
  return;
}

