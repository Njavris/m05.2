// c02ac8 gap_c02ac8 size=174 cc=unknown proto=undefined gap_c02ac8(void)

ushort gap_c02ac8(void)

{
  byte bVar1;
  byte bVar2;
  ushort in_r5;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  
  bVar1 = bRame00001;
  uRame00020 = 0;
  uVar4 = CONCAT11(uRame00003,uRame00004);
  uVar3 = uVar4;
  uVar5 = 5;
  for (bVar2 = 0; bVar2 < bVar1; bVar2 = bVar2 + 1) {
    *(undefined1 *)(uint3)uVar3 = *(undefined1 *)(uint3)uVar5;
    in_r5 = uVar3;
    uVar3 = uVar3 + 1;
    uVar5 = uVar5 + 1;
  }
  bVar2 = 0;
  uVar3 = 5;
  uVar5 = 0xe0;
  while( true ) {
    if (bVar1 <= bVar2) {
      return in_r5;
    }
    if (*(char *)(uint3)uVar4 != *(char *)(uint3)uVar3) break;
    bVar2 = bVar2 + 1;
    in_r5 = uVar5;
    uVar4 = uVar4 + 1;
    uVar3 = uVar3 + 1;
    uVar5 = uVar5 + (0xfffe < uVar3);
  }
  uRame00020 = 0xff;
  return uVar5;
}

