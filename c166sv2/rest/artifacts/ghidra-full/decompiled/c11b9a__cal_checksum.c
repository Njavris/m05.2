// c11b9a cal_checksum size=90 cc=unknown proto=undefined cal_checksum(void)

void cal_checksum(void)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  
  uVar3 = (ushort)&DAT_005000;
  uVar4 = 0xc0;
  DAT_00c546 = 0;
  DAT_00c548 = 0;
  for (; uVar4 < 0xc0 || uVar4 == 0xc0 && uVar3 < 0xaffd; uVar4 = uVar4 + bVar1) {
    sVar2 = DAT_00c546;
    DAT_00c546 = sVar2 + *(short *)(uint3)uVar3 * 0x100;
    sVar2 = DAT_00c546;
    DAT_00c546 = sVar2 + (*(ushort *)(uint3)uVar3 >> 8);
    bVar1 = 0xfffd < uVar3;
    uVar3 = uVar3 + 2;
  }
  if (DAT_c0affe == DAT_c08546) {
    DAT_00c548 = 1;
  }
  return;
}

