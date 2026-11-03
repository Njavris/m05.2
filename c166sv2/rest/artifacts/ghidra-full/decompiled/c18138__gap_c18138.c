// c18138 gap_c18138 size=62 cc=unknown proto=undefined gap_c18138(void)

void gap_c18138(void)

{
  ushort uVar1;
  byte bVar2;
  
  UNK_00c816 = 0;
  func_0xc1c2d6(0);
  UNK_00c81a = 0;
  UNK_00c9a5 = 0;
  bVar2 = 0;
  do {
    *(undefined2 *)(uint3)((short)&UNK_00c808 + (ushort)bVar2 * 2) = 0;
    uVar1 = (ushort)bVar2;
    bVar2 = bVar2 + 1;
    *(undefined1 *)(uint3)((short)&UNK_00c806 + uVar1) = 0;
  } while (bVar2 < 2);
  func_0xc1c296((short)&UNK_00c808);
  func_0xc1c312((short)&UNK_00c806);
  return;
}

