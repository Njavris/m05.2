// c13902 gap_c13902 size=382 cc=unknown proto=undefined gap_c13902(void)

void gap_c13902(void)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  short sVar4;
  undefined1 uVar5;
  undefined2 uStack_8;
  undefined1 uStack_6;
  undefined1 uStack_5;
  
  bVar1 = DAT_00c5c4;
  cVar2 = *(char *)(uint3)((short)&UNK_00f63e + (ushort)bVar1);
  if (cVar2 == '\x01') {
    cVar2 = UNK_00c578;
    if (cVar2 == '\x02') {
      cVar2 = func_0xc131be();
      if ((cVar2 == '\0') && (cVar2 = func_0xc138fc(), cVar2 == '\0')) {
        cVar2 = gap_c1267a();
        if (cVar2 == '\0') goto LAB_c139d4;
        UNK_00c5dc = 1;
        uVar3 = gap_c125f4();
        bVar1 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) = 1;
        uStack_5 = (undefined1)((ushort)uVar3 >> 8);
        bVar1 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1) = uStack_5;
        bVar1 = UNK_00c5c7;
        uStack_6 = (undefined1)uVar3;
        uVar5 = 4;
        *(undefined1 *)(uint3)((short)&UNK_00f640 + (ushort)bVar1) = uStack_6;
      }
      else {
        bVar1 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) = 1;
        bVar1 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1) = 0;
        bVar1 = UNK_00c5c7;
        uVar5 = 4;
        *(undefined1 *)(uint3)((short)&UNK_00f640 + (ushort)bVar1) = 0;
        func_0xc138f4();
      }
LAB_c13a3a:
      gap_c12910(uVar5);
      return;
    }
  }
  else if (cVar2 == '\x02') {
    cVar2 = gap_c1267a();
    if (cVar2 == '\0') {
LAB_c139d4:
      func_0xc128ec(0x37);
      return;
    }
    cVar2 = UNK_00c578;
    if (cVar2 == '\x04') {
      cVar2 = UNK_00c5dc;
      if (cVar2 == '\0') {
        func_0xc128ec(0x22);
        return;
      }
      bVar1 = DAT_00c5c4;
      uStack_8 = CONCAT11(*(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1),
                          *(undefined1 *)(uint3)((short)&UNK_00f640 + (ushort)bVar1));
      sVar4 = gap_c125fa();
      if (sVar4 != uStack_8) {
        cVar2 = UNK_00c5de;
        UNK_00c5de = cVar2 + '\x01';
        cVar2 = UNK_00c5de;
        if (cVar2 != '\x02') {
          func_0xc128ec(0x35);
          return;
        }
        func_0xc128ec(0x36);
        kline_start_timeout();
        UNK_00c5de = 0;
        return;
      }
      UNK_00c5dc = 0;
      func_0xc138f4();
      bVar1 = UNK_00c5c7;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) = 2;
      bVar1 = UNK_00c5c7;
      uVar5 = 3;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1) = 0x34;
      goto LAB_c13a3a;
    }
  }
  func_0xc128ec(0x12);
  return;
}

