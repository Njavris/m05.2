// c13132 gap_c13132 size=46 cc=unknown proto=undefined gap_c13132(void)

undefined2 gap_c13132(void)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  
  cVar1 = UNK_00c5e2;
  if (cVar1 == '\0') {
    uVar4 = DAT_00fd18;
    DAT_00fd18 = uVar4 & 0xfffd;
  }
  else {
    if (cVar1 != '\a') {
      return 0;
    }
    bVar3 = DAT_00fd18._0_1_;
    if ((bVar3 & 0x7f) != 0) {
      return 0;
    }
    sVar2 = DAT_00c5e6;
    if (sVar2 == 0) {
      return 0;
    }
    DAT_00fd18._0_1_ = 0x82;
  }
  return 1;
}

