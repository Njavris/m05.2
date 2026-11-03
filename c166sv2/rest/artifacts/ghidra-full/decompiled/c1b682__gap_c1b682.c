// c1b682 gap_c1b682 size=36 cc=unknown proto=undefined gap_c1b682(void)

void gap_c1b682(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  
  cVar1 = DAT_00c954;
  if (cVar1 == '\0') {
    DAT_00c93c = 5;
    func_0xc19806();
  }
  else {
    cVar1 = UNK_00c939;
    if (cVar1 != '\0') {
      DAT_00c93c = 2;
      func_0xc19810();
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

