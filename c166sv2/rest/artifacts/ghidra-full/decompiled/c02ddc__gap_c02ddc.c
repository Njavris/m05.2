// c02ddc gap_c02ddc size=366 cc=unknown proto=undefined gap_c02ddc(void)

void gap_c02ddc(void)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  ushort uStack_6;
  ushort uStack_4;
  
  uVar3 = CONCAT11(uRame00003,uRame00004);
  uVar1 = CONCAT11(uRame00006,uRame00007) - uVar3;
  sVar5 = (((ushort)bRame00005 - (ushort)bRame00002) -
          (ushort)(CONCAT11(uRame00006,uRame00007) < uVar3)) + (ushort)(0xfffe < uVar1);
  uStack_6 = 0xffff;
  uStack_4 = 0xffff;
  for (sVar4 = uVar1 + 1; sVar4 != 0 || sVar5 != 0; sVar4 = sVar4 + -1) {
    uStack_6 = uStack_6 ^ *(byte *)(uint3)uVar3;
    bVar2 = 0;
    do {
      if ((uStack_6 & 1) == 0) {
        uStack_6 = uStack_6 >> 1 | uStack_4 << 0xf;
        uStack_4 = uStack_4 >> 1;
      }
      else {
        uStack_6 = (uStack_6 >> 1 | uStack_4 << 0xf) ^ 0x8320;
        uStack_4 = uStack_4 >> 1 ^ 0xedb8;
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < 8);
    sVar5 = sVar5 - (ushort)(sVar4 == 0);
    uVar3 = uVar3 + 1;
  }
  func_0xc02f4a(&uStack_6);
  uRame00020 = (char)(uStack_4 >> 8);
  uRame00021 = (char)uStack_4;
  uRame00022 = (char)((ushort)*(undefined2 *)((uint3)((ushort)&uStack_6 & 0x3fff) + 0xe00000) >> 8);
  uRame00023 = (char)*(undefined2 *)((uint3)((ushort)&uStack_6 & 0x3fff) + 0xe00000);
  return;
}

