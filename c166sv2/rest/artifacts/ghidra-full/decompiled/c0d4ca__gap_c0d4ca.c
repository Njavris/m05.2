// c0d4ca gap_c0d4ca size=76 cc=unknown proto=undefined gap_c0d4ca(void)

void gap_c0d4ca(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  
  sVar1 = DAT_00c372;
  if (sVar1 == 0) {
    uVar2 = DAT_00c384;
    uVar3 = DAT_00c386;
    uVar4 = DAT_00c416;
    uVar5 = DAT_00c418;
    if (uVar3 - uVar5 == (ushort)(uVar2 < uVar4) && uVar2 == uVar4 ||
        (uVar3 < uVar5 || uVar3 == uVar5 && uVar2 < uVar4)) {
      sVar6 = DAT_00c418;
      sVar1 = DAT_00c416;
      if (sVar6 != 0 || sVar1 != 0) goto LAB_c0d50e;
    }
  }
  sVar1 = DAT_00c372;
  if (sVar1 != 0) {
    return;
  }
  uVar2 = DAT_00c388;
  uVar3 = DAT_00c38a;
  uVar4 = Ram00c428;
  uVar5 = Ram00c42a;
  if ((uVar3 - uVar5 != (ushort)(uVar2 < uVar4) || uVar2 != uVar4) &&
      (uVar5 <= uVar3 && (uVar3 != uVar5 || uVar2 >= uVar4))) {
    return;
  }
  sVar6 = Ram00c42a;
  sVar1 = Ram00c428;
  if (sVar6 == 0 && sVar1 == 0) {
    return;
  }
LAB_c0d50e:
  DAT_00c36e = 1;
  return;
}

