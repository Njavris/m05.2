// c1331a gap_c1331a size=112 cc=unknown proto=undefined gap_c1331a(void)

void gap_c1331a(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  undefined2 uStack_2;
  
  bVar4 = DAT_00c5c4;
  uVar1 = *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar4);
  uVar2 = *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar4);
  uStack_2 = CONCAT11(uVar2,uVar1);
  cVar3 = UNK_00c578;
  if ((cVar3 == '\x03') && ((uStack_2 == 0 || (uStack_2 == -0x100)))) {
    gap_c25732(uStack_2);
    bVar4 = UNK_00c5c7;
    *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar4) = uVar1;
    bVar4 = UNK_00c5c7;
    *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar4) = uVar2;
    gap_c12910(3);
  }
  else {
    func_0xc128ec(0x12);
  }
  return;
}

