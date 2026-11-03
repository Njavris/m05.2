// c15028 gap_c15028 size=60 cc=unknown proto=undefined gap_c15028(void)

void gap_c15028(void)

{
  ushort uVar1;
  ushort uVar2;
  
  UNK_00c6ba = 0;
  uVar2 = 0;
  do {
    *(undefined1 *)(uint3)((short)&UNK_00c6a6 + uVar2) = 0;
    *(undefined1 *)(uint3)((short)&UNK_00c667 + uVar2) = 0;
    *(undefined1 *)(uint3)((short)&UNK_00c63b + uVar2) = 0;
    *(undefined1 *)(uint3)((short)&UNK_00c612 + uVar2) = 0;
    uVar1 = (short)&UNK_00c67c + uVar2 * 2;
    *(undefined1 *)(uint3)((short)&UNK_00c64f + uVar2) = 0;
    *(undefined1 *)(uint3)((short)&UNK_00c626 + uVar2) = 0;
    *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xfff0;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x14);
  return;
}

