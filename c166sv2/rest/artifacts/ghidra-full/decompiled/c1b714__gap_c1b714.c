// c1b714 gap_c1b714 size=38 cc=unknown proto=undefined gap_c1b714(void)

void gap_c1b714(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  
  cVar1 = DAT_00c954;
  if (cVar1 == '\x01') {
    DAT_00c93c = 1;
    gap_c1981a();
  }
  else {
    cVar1 = UNK_00c940;
    if (cVar1 != '\0') {
      DAT_00c93c = 6;
      gap_c197f8();
    }
  }
  uVar3 = DAT_00fd02;
  if (((uVar3 & 0x800) == 0) && (sVar2 = DAT_00c9d0, sVar2 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  UNK_00c93a = uVar4;
  return;
}

