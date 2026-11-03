// c0d5ca FUN_c0d5ca size=222 cc=unknown proto=undefined FUN_c0d5ca(void)

void FUN_c0d5ca(void)

{
  short sVar1;
  byte bVar2;
  undefined1 uVar3;
  short extraout_r3;
  undefined2 uVar4;
  ushort uVar5;
  short sVar6;
  ushort uVar7;
  short sVar8;
  
  sVar1 = DAT_00c372;
  if (sVar1 == 1) {
    bVar2 = DAT_00c38f;
    uVar5 = (short)&DAT_00c382 + (ushort)bVar2;
    if ((2 < *(byte *)(uint3)uVar5) && (*(byte *)(uint3)uVar5 < 0x15)) {
      uVar5 = (short)&DAT_00c282 + (ushort)*(byte *)(uint3)uVar5 * 2;
      *(ushort *)(uint3)uVar5 = *(ushort *)(uint3)uVar5 & 0xfeff;
    }
    DAT_00c38e = 0;
    bVar2 = DAT_00c38f;
    uVar5 = (ushort)bVar2;
    uVar7 = DAT_00c2ba;
    sVar8 = 0;
    div32u(0,0);
    sVar6 = uVar5 * 2;
    uVar4 = DAT_00c206;
    uVar5 = mul32((*(ushort *)(sVar6 + 0x5032) >> 6) % 0xb4);
    sVar1 = uVar7 * 4 + uVar5;
    *(short *)(uint3)(ushort)((short)&UNK_00c36a + sVar6) = extraout_r3 + sVar1;
    *(short *)(uint3)(ushort)((short)&UNK_00c37a + sVar6) = sVar1;
    uVar4 = DAT_00c376;
    uVar4 = FUN_c0d2e4(uVar4,(sVar8 * 2 + (ushort)CARRY2(uVar7,uVar7)) * 2 +
                             (ushort)CARRY2(uVar7 * 2,uVar7 * 2) + (ushort)CARRY2(uVar7 * 4,uVar5));
    DAT_00c37e = uVar4;
    uVar4 = DAT_00c380;
    uVar4 = FUN_c0d2e4(uVar4);
    DAT_00c374 = uVar4;
    uVar3 = DAT_00c38f;
    FUN_c0d0e0(uVar3);
  }
  return;
}

