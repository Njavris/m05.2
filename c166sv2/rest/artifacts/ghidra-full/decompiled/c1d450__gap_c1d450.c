// c1d450 gap_c1d450 size=30 cc=unknown proto=undefined gap_c1d450(void)

void gap_c1d450(void)

{
  ushort uVar1;
  char cVar2;
  byte bVar3;
  
  cVar2 = UNK_00c702;
  if (cVar2 != '\0') {
    bVar3 = 0;
    do {
      uVar1 = (ushort)bVar3;
      bVar3 = bVar3 + 1;
      *(undefined2 *)(uint3)((short)&UNK_00c07a + uVar1 * 2) = 0x8000;
    } while (bVar3 < 0x10);
  }
  return;
}

