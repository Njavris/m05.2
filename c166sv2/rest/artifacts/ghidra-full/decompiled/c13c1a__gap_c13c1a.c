// c13c1a gap_c13c1a size=22 cc=unknown proto=undefined gap_c13c1a(void)

void gap_c13c1a(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  
  uVar3 = UNK_00c5e2;
  gap_c130b2(uVar3,(short)&UNK_00c6de,(short)&UNK_00c6dc,0x80);
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}

