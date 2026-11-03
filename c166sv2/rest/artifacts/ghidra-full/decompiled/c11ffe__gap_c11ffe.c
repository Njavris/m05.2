// c11ffe gap_c11ffe size=104 cc=unknown proto=undefined gap_c11ffe(void)

void gap_c11ffe(void)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  
  sVar1 = Ram00c5c2;
  if ((sVar1 == 0) && (cVar3 = UNK_00c578, cVar3 == '\x02')) {
    uVar4 = UNK_00f63e;
    cVar3 = func_0xc23c0e(uVar4,0x10);
    if (cVar3 == '\x01') {
      uVar4 = UNK_00f63e;
      UNK_00f640 = uVar4;
      bVar2 = UNK_00c5c7;
      uVar4 = UNK_00cb2c;
      uVar4 = func_0xc23cc2((short)&UNK_00f63d + (ushort)bVar2,2,uVar4);
      gap_c12910(uVar4);
      return;
    }
  }
  func_0xc128ec(0x12);
  return;
}

