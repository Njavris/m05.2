// c131d6 gap_c131d6 size=278 cc=unknown proto=undefined gap_c131d6(void)

void gap_c131d6(void)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  char cVar4;
  
  bVar2 = DAT_00c5c4;
  uVar1 = *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2);
  bVar2 = UNK_00c5c7;
  UNK_00c5c8 = uVar1;
  *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar1;
  UNK_00c5c0 = 0;
  UNK_00c5c5 = 0;
  cVar4 = UNK_00c578;
  if ((cVar4 == '\x03') || (cVar4 == '\x02')) {
    cVar4 = UNK_00c578;
    if (cVar4 == '\x02') {
      cVar4 = UNK_00c5c8;
      if (cVar4 == -0x7f) {
        cVar4 = func_0xc131be();
        if (cVar4 == '\0') {
          UNK_00c5c0 = 1;
          Ram00c5c2 = 0;
        }
        else {
          DAT_00c5ab = 1;
        }
        gap_c12910(2);
        return;
      }
      if (cVar4 == -0x7b) {
        cVar4 = func_0xc125e6();
        if (cVar4 == '\0') {
          func_0xc12688();
          return;
        }
        gap_c131ce();
        func_0xc12690();
        uVar3 = DAT_00fd14;
        DAT_00fd14 = uVar3 | 0x2000;
        gap_c12910(2);
        store32();
        return;
      }
    }
    else {
      cVar4 = UNK_00c5c8;
      if (cVar4 == -0x7b) {
        cVar4 = func_0xc125e6();
        if (cVar4 == '\0') {
          func_0xc12688();
          bVar2 = DAT_00c5c4;
          UNK_00c5c9 = *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2);
          UNK_00c5c5 = 1;
          return;
        }
        gap_c131ce();
        func_0xc12690();
        bVar2 = DAT_00c5c4;
        uVar1 = *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2);
        bVar2 = UNK_00c5c7;
        UNK_00c5c9 = uVar1;
        *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar1;
        cVar4 = UNK_00c5c9;
        if (cVar4 == '\x03') {
          gap_c12910(3);
          store32();
          return;
        }
        func_0xc128ec(0x31);
        return;
      }
    }
  }
  func_0xc128ec(0x12);
  return;
}

