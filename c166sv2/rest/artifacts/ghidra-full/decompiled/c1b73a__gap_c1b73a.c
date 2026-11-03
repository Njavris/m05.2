// c1b73a gap_c1b73a size=70 cc=unknown proto=undefined gap_c1b73a(void)

void gap_c1b73a(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  undefined1 uVar4;
  
  cVar1 = UNK_00c94a;
  if (cVar1 == '\0') {
    cVar1 = DAT_00c954;
    if (cVar1 == '\x01') {
      DAT_00c93c = 1;
      gap_c19830();
    }
    else {
      uVar2 = DAT_00c9d0;
      if (uVar2 < 0xf1) {
        uVar2 = DAT_00fd02;
        DAT_00fd02 = uVar2 & 0xf3ff;
      }
    }
  }
  else {
    gap_c1983e();
    DAT_00c93c = 0;
  }
  uVar2 = DAT_00fd02;
  if (((uVar2 & 0x800) == 0) && (sVar3 = DAT_00c9d0, sVar3 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  UNK_00c93a = uVar4;
  return;
}

