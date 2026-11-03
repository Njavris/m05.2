// c170e6 gap_c170e6 size=140 cc=unknown proto=undefined gap_c170e6(void)

void gap_c170e6(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  
  cVar1 = DAT_00c93c;
  if (cVar1 != '\x03') {
    DAT_00c77e = 0;
    return;
  }
  cVar1 = DAT_00c77e;
  if (cVar1 == '\0') {
    cVar1 = DAT_00c81c;
    if ((cVar1 == '\0') || (sVar3 = DAT_00c936, sVar3 <= sRamc0619e)) {
      Ram00c7ca = 0;
    }
    else {
      UNK_00c7f8 = 1;
      Ram00c7cc = 0;
      uVar2 = Ram00c7ca;
      if (uVar2 <= uRamc061a0) {
        DAT_00c77e = 0;
        goto LAB_c17134;
      }
      DAT_00c77e = 1;
    }
    UNK_00c7f8 = 0;
  }
LAB_c17134:
  cVar1 = DAT_00c77e;
  if ((cVar1 != '\0') && (cVar1 = DAT_00c81c, cVar1 == '\0')) {
    UNK_00c7f9 = 1;
    uVar2 = Ram00c7cc;
    if (uVar2 <= uRamc061a2) {
      return;
    }
    DAT_00c77e = 0;
    UNK_00c7f9 = 0;
    Ram00c7ca = 0;
    return;
  }
  Ram00c7cc = 0;
  UNK_00c7f9 = 0;
  return;
}

