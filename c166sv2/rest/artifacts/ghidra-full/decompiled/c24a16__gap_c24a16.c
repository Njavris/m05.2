// c24a16 gap_c24a16 size=122 cc=unknown proto=undefined gap_c24a16(void)

void gap_c24a16(void)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  ushort uVar4;
  short sVar5;
  
  gap_c2492e();
  sVar5 = 0;
  uRame0083c = 0;
  uRame00bdb = 0;
  for (uVar4 = 0; uVar4 < 0x27; uVar4 = uVar4 + 1) {
    sVar1 = *(short *)(uint3)(uVar4 * 2 + 0x7286);
    if (sVar1 != -1) {
      cVar3 = func_0xc259ee(sVar1);
      if (cVar3 == '\0') {
        *(undefined2 *)(uint3)(ushort)((short)&UNK_00cb86 + sVar5 * 2) = 0xffff;
      }
      else {
        uVar2 = (short)&UNK_00c168 + sVar1 * 2;
        *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0x9fff;
        sVar1 = Ram00cb84;
        Ram00cb84 = sVar1 + 1;
        *(ushort *)(uint3)(ushort)((short)&UNK_00cb86 + sVar5 * 2) = uVar4;
      }
      sVar5 = sVar5 + 1;
    }
  }
  UNK_00c1b6 = 0;
  UNK_00c1ba = 0;
  return;
}

