// c12066 gap_c12066 size=192 cc=unknown proto=undefined gap_c12066(void)

void gap_c12066(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  short sVar4;
  
  sVar4 = Ram00c5c2;
  if (sVar4 == 0) {
    UNK_00cb25 = 0;
    cVar2 = UNK_00c578;
    if (cVar2 == '\x03') {
      uVar3 = UNK_00f63e;
      cVar2 = func_0xc23c0e(uVar3,0x20);
      if ((cVar2 == '\x01') && (cVar2 = UNK_00f63f, cVar2 == '\0')) {
        uVar3 = UNK_00cb25;
        sVar4 = func_0xc234be(uVar3);
        if (((sVar4 != 0) ||
            ((((cVar2 = UNK_00f63e, cVar2 == '\x02' || (cVar2 == '\x03')) || (cVar2 == '\x04')) ||
             ((cVar2 == '\x05' || (cVar2 == '\a')))))) ||
           ((cVar2 == '\t' ||
            (((cVar2 == '\v' || (cVar2 == '\f')) ||
             ((cVar2 == '\r' || ((cVar2 == '\x11' || (cVar2 == '\x7f')))))))))) {
          uVar3 = UNK_00f63e;
          UNK_00f641 = uVar3;
          UNK_00f642 = 0;
          bVar1 = UNK_00c5c7;
          uVar3 = UNK_00cb2c;
          uVar3 = func_0xc23cc2((short)&UNK_00f63d + (ushort)bVar1,3,uVar3);
          gap_c12910(uVar3);
          return;
        }
      }
    }
  }
  func_0xc128ec(0x12);
  return;
}

