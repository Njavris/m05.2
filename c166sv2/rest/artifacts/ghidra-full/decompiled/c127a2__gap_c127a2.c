// c127a2 gap_c127a2 size=92 cc=unknown proto=undefined gap_c127a2(void)

void gap_c127a2(short param_1)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  undefined1 uVar4;
  char cVar5;
  ushort uVar6;
  
  uVar2 = S0CON;
  S0CON = uVar2 & 0xffef;
  sVar1 = DAT_00c57a;
  if ((sVar1 == 0) && (uVar2 = S0TBIC, (uVar2 & 0x80) == 0)) {
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5ac = 0;
      DAT_00c584 = 10;
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      Ram00c59a = 0;
      DAT_00c584 = 0xb;
      return;
    }
  }
  else {
    uVar6 = DAT_00c5be;
    uVar2 = DAT_00c586;
    if ((uVar6 < uVar2) && (param_1 = DAT_00c5a2, param_1 == 0)) {
      DAT_00c584 = 0xc;
      return;
    }
    uVar4 = UNK_00c5b3;
    gap_c11f5a(uVar4,param_1);
    cVar5 = UNK_00c5b3;
    cVar3 = UNK_00c5a4;
    UNK_00c5a4 = cVar3 + cVar5;
  }
  return;
}

