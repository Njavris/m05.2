// c1b6a6 gap_c1b6a6 size=38 cc=unknown proto=undefined gap_c1b6a6(void)

void gap_c1b6a6(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  
  cVar1 = UNK_00c943;
  if (cVar1 == '\0') {
    cVar1 = UNK_00c944;
    if (cVar1 != '\0') {
      DAT_00c93c = 4;
      gap_c197ac();
    }
  }
  else {
    DAT_00c93c = 3;
    func_0xc197e4();
    uVar3 = DAT_00fd02;
    DAT_00fd02 = uVar3 & 0xfdff;
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

