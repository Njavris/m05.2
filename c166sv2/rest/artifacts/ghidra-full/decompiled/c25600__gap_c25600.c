// c25600 gap_c25600 size=272 cc=unknown proto=undefined gap_c25600(void)

void gap_c25600(void)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  
  bVar6 = 0;
  do {
    sVar2 = (ushort)bVar6 * 0x1e;
    uVar1 = (short)&UNK_00c10e + sVar2;
    cVar5 = FUN_c243a8(*(undefined2 *)(uint3)uVar1);
    if (cVar5 == '\0') {
      cVar5 = func_0xc2440a(*(undefined2 *)(uint3)uVar1);
      if (cVar5 == '\0') {
        if (*(short *)(uint3)uVar1 != 0) {
          uVar1 = (short)&UNK_00c112 + sVar2;
          bVar4 = (byte)((ushort)*(undefined2 *)(uint3)uVar1 >> 8);
          bVar3 = bVar4 + 1;
          if (bVar3 == 0) {
            bVar3 = bVar4;
          }
          *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xff | (ushort)bVar3 << 8;
        }
      }
      else {
        uVar1 = (short)&UNK_00c112 + sVar2;
        bVar3 = (byte)*(undefined2 *)(uint3)uVar1 + 1;
        if (bVar3 == 0) {
          bVar3 = (byte)*(undefined2 *)(uint3)uVar1;
        }
        *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xff00 | (ushort)bVar3;
      }
    }
    else {
      uVar1 = (short)&UNK_00c110 + sVar2;
      bVar4 = (byte)((ushort)*(undefined2 *)(uint3)uVar1 >> 8);
      bVar3 = bVar4 + 1;
      if (bVar3 == 0) {
        bVar3 = bVar4;
      }
      *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xff | (ushort)bVar3 << 8;
    }
    bVar6 = bVar6 + 1;
  } while (bVar6 < 3);
  return;
}

