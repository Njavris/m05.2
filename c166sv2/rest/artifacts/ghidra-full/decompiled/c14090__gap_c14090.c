// c14090 gap_c14090 size=96 cc=unknown proto=undefined gap_c14090(void)

void gap_c14090(ushort param_1)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  byte bVar6;
  
  uVar3 = (uint)param_1 * 1000 >> 6;
  bVar6 = 0;
  do {
    sVar2 = (ushort)bVar6 * 4;
    uVar1 = (short)&DAT_00c384 + sVar2;
    *(short *)(uint3)(ushort)((short)&DAT_00c386 + sVar2) = (short)(uVar3 >> 0x10);
    *(short *)(uint3)uVar1 = (short)uVar3;
    uVar4 = DAT_00c374;
    uVar5 = DAT_00c37e;
    func_0xc0bbf6(bVar6,*(undefined2 *)(uint3)uVar1,
                  *(undefined2 *)(uint3)(ushort)((short)&DAT_00c386 + sVar2),
                  *(undefined2 *)(uint3)((short)&UNK_00c36a + (ushort)bVar6 * 2),uVar5,uVar4);
    bVar6 = bVar6 + 1;
  } while (bVar6 < 2);
  return;
}

