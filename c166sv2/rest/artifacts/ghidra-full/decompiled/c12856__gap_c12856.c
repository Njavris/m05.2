// c12856 gap_c12856 size=112 cc=unknown proto=undefined gap_c12856(void)

void gap_c12856(byte param_1)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  ushort uVar4;
  
  bVar1 = UNK_00c5ae;
  if ((bVar1 & 0xc0) == 0xc0) {
    UNK_00c58b = 0x80;
  }
  else {
    bVar1 = UNK_00c5ae;
    UNK_00c58b = bVar1 & 0xc0;
  }
  if ((param_1 & 0x3f) == param_1) {
    bVar1 = UNK_00c58b;
    UNK_00c58b = bVar1 | param_1;
  }
  UNK_00c593 = param_1;
  bVar1 = UNK_00c5ae;
  if (((bVar1 & 0x80) != 0) || ((bVar1 & 0xc0) != 0)) {
    uVar2 = UNK_00c594;
    UNK_00c5b7 = uVar2;
    UNK_00c5c1 = 0x11;
  }
  uVar4 = DAT_00c5ac;
  uVar3 = DAT_00c5a6;
  if (uVar4 < uVar3) {
    DAT_00c584 = 10;
    return;
  }
  func_0xc127fe();
  return;
}

