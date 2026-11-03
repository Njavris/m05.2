// c136a0 gap_c136a0 size=86 cc=unknown proto=undefined gap_c136a0(void)

void gap_c136a0(short param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  
  bVar3 = DAT_00c5c4;
  bVar2 = 2;
  bVar1 = UNK_00c5c7;
  *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) =
       *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar3);
  for (bVar3 = 0; bVar3 < param_2; bVar3 = bVar3 + 1) {
    uVar4 = (ushort)bVar2;
    bVar1 = UNK_00c5c7;
    bVar2 = bVar2 + 1;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + bVar1 + uVar4) =
         *(undefined1 *)(uint3)(param_1 + (ushort)bVar3);
  }
  gap_c12910(bVar2);
  return;
}

