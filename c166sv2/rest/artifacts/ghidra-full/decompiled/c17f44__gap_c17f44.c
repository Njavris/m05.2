// c17f44 gap_c17f44 size=280 cc=unknown proto=undefined gap_c17f44(void)

void gap_c17f44(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  short sVar4;
  undefined2 uVar5;
  ushort uVar6;
  
  sVar4 = Ram00c818;
  if (sVar4 == 1) {
    uVar5 = DAT_00c9d0;
    uVar5 = gap_c28544(0x5252,0xc0,uVar5);
    uVar5 = tbl16_interp(0x5db0,0xc0,uVar5);
    Ram00c814 = uVar5;
    uVar5 = DAT_00c936;
    uVar5 = axis16_signed(0x7534,uVar5);
    uVar5 = tbl16_interp(0x7cdc,0xc0,uVar5);
    Ram00c810 = uVar5;
    UNK_00c7c1 = 1;
  }
  else {
    uVar5 = DAT_00c936;
    uVar5 = axis16_signed(0x7534,uVar5);
    uVar5 = tbl16_interp(0x5d9c,0xc0,uVar5);
    Ram00c814 = uVar5;
    Ram00c810 = 0;
  }
  uVar2 = Ram00c814;
  uVar6 = Ram00c80c;
  uVar1 = Ram00c80c;
  if (uVar2 == uVar1 || uVar2 < uVar6) {
    uVar1 = Ram00c814;
    uVar6 = Ram00c80c;
    if (uVar6 <= uVar1) goto LAB_c1804a;
    uVar5 = Ram00c80c;
    uVar3 = Ram00c814;
    uVar6 = FUN_c28852(uVar5,uVar3);
    if (uRamc05c4c < uVar6) {
      uVar6 = Ram00c7c6;
      if (uVar6 < uRamc05c4e) goto LAB_c1804a;
      uVar5 = Ram00c80c;
      uVar5 = FUN_c28852(uVar5,uRamc05c4c);
      Ram00c80c = uVar5;
      goto LAB_c18038;
    }
  }
  else {
    uVar5 = Ram00c80c;
    uVar6 = FUN_c28852(uVar5);
    if (uRamc05c4c < uVar6) {
      uVar6 = Ram00c7c6;
      if (uVar6 < uRamc05c4e) goto LAB_c1804a;
      uVar5 = Ram00c80c;
      uVar5 = func_0xc276a4(uVar5,uRamc05c4c);
      Ram00c80c = uVar5;
LAB_c18038:
      Ram00c7c6 = 0;
      goto LAB_c1804a;
    }
  }
  uVar5 = Ram00c814;
  Ram00c80c = uVar5;
  UNK_00c7c1 = 0;
LAB_c1804a:
  uVar5 = Ram00c80c;
  gap_c1c2b8(uVar5);
  uVar5 = Ram00c810;
  func_0xc1c2be(uVar5);
  return;
}

