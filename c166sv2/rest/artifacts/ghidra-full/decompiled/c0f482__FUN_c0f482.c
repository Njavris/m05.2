// c0f482 FUN_c0f482 size=216 cc=unknown proto=undefined FUN_c0f482(void)

undefined2 FUN_c0f482(short param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  undefined2 uVar7;
  
  uVar7 = 0;
  FUN_c0e7ca();
  sVar4 = param_1 * 0x1a;
  sVar5 = FUN_c0e7ec(*(undefined2 *)(uint3)(ushort)((short)&UNK_00c3de + sVar4));
  sVar6 = DAT_00c476;
  uVar1 = (short)&DAT_00c3cc + sVar4;
  *(short *)(uint3)uVar1 = sVar6 * 2 + sVar5;
  sVar6 = DAT_00c452;
  uVar3 = *(short *)(uint3)uVar1 - sVar6;
  uVar1 = (short)&UNK_00c3d6 + sVar4;
  uVar2 = (short)&UNK_00c3ca + sVar4;
  *(ushort *)(uint3)uVar2 = *(short *)(uint3)uVar1 + uVar3;
  sVar6 = DAT_00c476;
  if ((uVar3 < sVar6 + 0x1eU) || (0x7fff < uVar3)) {
    sVar6 = t7_timestamp();
    if (0x7fff < (ushort)(*(short *)(uint3)uVar2 - (sVar6 + 0x4b))) {
      sVar6 = t7_timestamp();
      *(short *)(uint3)uVar2 = sVar6 + 0x4b;
      sVar6 = DAT_00c476;
      FUN_c0f476(sVar6 * 2 + -0x4b);
    }
    FUN_c0f97a(*(undefined2 *)(uint3)uVar2,param_1);
    uVar7 = 1;
  }
  *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3d4 + sVar4) = *(undefined2 *)(uint3)uVar1;
  uVar1 = (short)&DAT_00c3d9 + sVar4;
  *(undefined1 *)(uint3)uVar1 = 1;
  sVar4 = DAT_00c44c;
  if ((sVar4 == 1) && (param_1 == 1)) {
    DAT_00c3f3 = 0;
  }
  FUN_c0f0e6(param_1,*(undefined1 *)(uint3)uVar1);
  return uVar7;
}

