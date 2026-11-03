// c24350 gap_c24350 size=56 cc=unknown proto=undefined gap_c24350(void)

void gap_c24350(short param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if ((sVar1 != -1) &&
     (uVar2 = (short)&UNK_00c168 + sVar1 * 2, (*(ushort *)(uint3)uVar2 >> 6 & 3) != 0)) {
    *(ushort *)(uint3)uVar2 =
         *(ushort *)(uint3)uVar2 & 0xff3f | ((*(ushort *)(uint3)uVar2 >> 6 & 3) - 1 & 3) << 6;
  }
  return;
}

