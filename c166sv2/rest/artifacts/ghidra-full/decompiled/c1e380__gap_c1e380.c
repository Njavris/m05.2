// c1e380 gap_c1e380 size=160 cc=unknown proto=undefined gap_c1e380(void)

void gap_c1e380(void)

{
  ushort uVar1;
  short *psVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  char cVar6;
  
  bVar5 = UNK_00ca41;
  if (bVar5 != 8) {
    if ((*(char *)(uint3)(bVar5 + 0x71b5) == '\0') ||
       (cVar6 = func_0xc24530(0x25,(0x8e4a < bVar5) + -0x40), cVar6 != '\0')) {
      bVar5 = UNK_00ca41;
      psVar2 = (short *)((ushort)bVar5 * 2 + 0x71a2);
      uVar1 = *(ushort *)ZEXT23(psVar2);
      uVar3 = DAT_00c9d0;
      uVar4 = DAT_00c9d0;
      if (uVar1 == uVar4 || uVar1 < uVar3) {
        UNK_00ca40 = 1;
      }
      if ((ushort)(*psVar2 - sRamc071b2) <= uRamc049d0) {
        return;
      }
    }
    else {
      bVar5 = UNK_00ca41;
      psVar2 = (short *)((ushort)bVar5 * 2 + 0x71be);
      uVar1 = *(ushort *)ZEXT23(psVar2);
      uVar3 = Ram00ca3e;
      uVar4 = Ram00ca3e;
      if (uVar1 == uVar4 || uVar1 < uVar3) {
        UNK_00ca40 = 1;
      }
      if ((ushort)(*psVar2 - sRamc071ce) <= uRamc04a3e) {
        return;
      }
    }
  }
  UNK_00ca40 = 0;
  return;
}

