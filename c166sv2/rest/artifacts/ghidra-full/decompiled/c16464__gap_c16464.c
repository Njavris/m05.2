// c16464 gap_c16464 size=236 cc=unknown proto=undefined gap_c16464(void)

void gap_c16464(void)

{
  undefined1 uVar1;
  char cVar2;
  short sVar3;
  char cVar4;
  
  gap_c149fc(0x73b4);
  UNK_00c70e = 0;
  Ram00c70c = 1;
  uVar1 = UNK_00c010;
  UNK_00c70f = uVar1;
  sVar3 = func_0xc16442(0x71e2);
  if (sVar3 == -1) {
    UNK_00c709 = 0;
  }
  else {
    UNK_00c709 = 1;
  }
  cVar4 = UNK_00c010;
  if ((cVar4 != '\0') || (cVar4 = UNK_00c003, cVar4 != '\0')) {
    cVar4 = '\x01';
    goto LAB_c16518;
  }
  cVar4 = '\0';
  cVar2 = UNK_00c6eb;
  if (cVar2 != '\0') goto LAB_c16518;
  UNK_00c6eb = 1;
  cVar2 = UNK_00c005;
  cVar4 = '\0';
  if (cVar2 == '\0') {
    UNK_00c710 = 1;
    sVar3 = func_0xc16442(0x71da);
    if (sVar3 == -1) {
      UNK_00c6ea = 0;
LAB_c16506:
      UNK_00c702 = 0;
      goto LAB_c16518;
    }
LAB_c1650c:
    UNK_00c6ea = 1;
  }
  else {
    UNK_00c710 = 0;
    func_0xc1665a((short)&UNK_00c005,0);
    sVar3 = func_0xc16442(0x71da);
    if (sVar3 != -1) goto LAB_c1650c;
    UNK_00c6ea = 0;
    sVar3 = func_0xc16442(0x71d2);
    if (sVar3 == -1) goto LAB_c16506;
  }
  UNK_00c702 = 1;
LAB_c16518:
  if ((cVar4 == '\0') && (cVar2 = UNK_00c702, cVar2 == '\0')) {
    cVar4 = UNK_00c710;
    if (cVar4 != '\0') {
      uVar1 = UNK_00c006;
      UNK_00c6ea = uVar1;
      UNK_00c702 = uVar1;
      uVar1 = UNK_00c004;
      UNK_00c70e = uVar1;
    }
  }
  else {
    func_0xc162f4(cVar4);
    UNK_00c010 = 0;
  }
  func_0xc163be();
  return;
}

