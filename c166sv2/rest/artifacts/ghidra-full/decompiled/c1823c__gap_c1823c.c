// c1823c gap_c1823c size=152 cc=unknown proto=undefined gap_c1823c(void)

void gap_c1823c(void)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  func_0xc18da6();
  cVar3 = DAT_00c93c;
  if (cVar3 != '\x03') {
    Ram00c79c = 0;
    UNK_00c7ef = 0;
    DAT_00c81c = 0;
    return;
  }
  cVar3 = UNK_00c853;
  if (cVar3 != '\0') {
    uVar4 = Ram00c984;
    uVar5 = tbl16_interp(0x613e,0xc0,uVar4);
    uVar1 = Ram00c79c;
    uVar2 = Ram00c79c;
    if ((uVar5 == uVar2 || uVar5 < uVar1) || (cVar3 = UNK_00c81d, cVar3 != '\0')) {
      UNK_00c81d = 1;
      UNK_00c7ef = 0;
      DAT_00c81c = 1;
    }
    else {
      UNK_00c7ef = 1;
    }
    Ram00c7ac = 0;
    UNK_00c7f7 = 0;
    return;
  }
  cVar3 = UNK_00c852;
  if (cVar3 != '\0') {
    uVar4 = Ram00c984;
    uVar5 = tbl16_interp(0x61f4,0xc0,uVar4);
    uVar1 = Ram00c7ac;
    uVar2 = Ram00c7ac;
    if (uVar5 == uVar2 || uVar5 < uVar1) {
      UNK_00c7f7 = 0;
      DAT_00c81c = 0;
    }
    else {
      UNK_00c7f7 = 1;
    }
    UNK_00c7ef = 0;
    return;
  }
  UNK_00c7ef = 0;
  return;
}

