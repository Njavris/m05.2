// c0d562 angle_init size=104 cc=unknown proto=undefined angle_init(void)

void angle_init(void)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  DAT_00c224 = 0xd076;
  DAT_00c226 = 0xc0;
  bVar3 = 0;
  do {
    uVar1 = (ushort)bVar3;
    uVar2 = (ushort)bVar3;
    bVar3 = bVar3 + 1;
    bVar4 = (char)(*(ushort *)(uint3)(uVar1 * 2 + 0x5032) / 0x3c0) + 4;
    if (0x18 < bVar4) {
      bVar4 = bVar4 % 0x18;
    }
    *(byte *)(uint3)((short)&DAT_00c382 + uVar2) = bVar4;
  } while (bVar3 < 2);
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}

