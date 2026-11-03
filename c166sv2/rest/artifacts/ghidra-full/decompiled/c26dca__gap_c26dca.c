// c26dca gap_c26dca size=268 cc=unknown proto=undefined gap_c26dca(void)

void gap_c26dca(void)

{
  undefined2 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  ushort uVar6;
  
  uVar4 = FUN_c1aeac();
  uVar1 = DAT_00c06a;
  uVar5 = FUN_c28852(uVar1,uVar4);
  uVar6 = FUN_c28852(uRame008ee,uRame00962);
  if ((((cRame008f4 == '\0') ||
       ((((cVar2 = DAT_00c93c, cVar2 != '\x04' && (cVar2 != '\x01')) ||
         (cVar2 = UNK_00cc32, cVar2 != '\0')) ||
        ((cVar2 = UNK_00ca18, cVar2 != '\0' || (uVar3 = DAT_00fd00, (uVar3 & 0x2000) != 0)))))) ||
      (uVar5 < uRamc07e3c)) || (uVar6 < uRamc07e40)) {
    UNK_00cc8f = 0;
  }
  else {
    UNK_00cc8f = 1;
  }
  if (cRame008f0 != '\0') {
    cRame008f0 = '\0';
  }
  if (cRame008f4 == '\0') {
    UNK_00cc8d = 0;
    cVar2 = DAT_00c93c;
    if ((cVar2 != '\x03') && (uVar5 = Ram00cc92, uVar5 < uRamc07e42)) {
      UNK_00cc8e = 1;
      return;
    }
    uRame008ec = 0;
    uRame00c8e = 0;
    Ram00cc92 = 0;
  }
  else {
    UNK_00cc8e = 0;
    Ram00cc92 = 0;
    cVar2 = UNK_00cc8f;
    if (cVar2 == '\0') {
      UNK_00cc8d = 0;
      return;
    }
    uVar5 = Ram00cc90;
    if (uVar5 < uRamc07e3e) {
      UNK_00cc8d = 1;
      return;
    }
    uRame008ec = 1;
    uRame00c8d = 0;
  }
  Ram00cc90 = 0;
  cRame008f0 = 1;
  return;
}

