// c1385e gap_c1385e size=148 cc=unknown proto=undefined gap_c1385e(void)

void gap_c1385e(void)

{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  ushort uStack_6;
  undefined2 uStack_4;
  
  cVar5 = UNK_00c578;
  if (cVar5 == '\x05') {
    bVar1 = DAT_00c5c4;
    uVar2 = (ushort)bVar1;
    uStack_4 = CONCAT11(*(undefined1 *)(uint3)((short)&UNK_00f640 + uVar2),
                        *(undefined1 *)(uint3)((short)&UNK_00f63f + uVar2));
    uStack_6 = (ushort)*(byte *)(uint3)((short)&UNK_00f63e + uVar2) << 8;
    bVar1 = *(byte *)(uint3)((short)&UNK_00f641 + uVar2);
    cVar5 = gap_c12602(uStack_6,uStack_4,bVar1);
    if ((cVar5 == '\0') || (0x87 < bVar1)) {
      func_0xc128ec(0x31);
    }
    else {
      for (bVar4 = 1; bVar4 <= bVar1; bVar4 = bVar4 + 1) {
        bVar3 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar3 + (ushort)bVar4) =
             *(undefined1 *)(uint3)uStack_6;
        uStack_6 = uStack_6 + 1;
      }
      gap_c12910(bVar4);
    }
  }
  else {
    func_0xc128ec(0x12);
  }
  return;
}

