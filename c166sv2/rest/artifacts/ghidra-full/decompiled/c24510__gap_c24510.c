// c24510 gap_c24510 size=32 cc=unknown proto=undefined gap_c24510(void)

void gap_c24510(short param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 != -1) {
    uVar2 = (short)&UNK_00c168 + sVar1 * 2;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xfffb;
  }
  return;
}

