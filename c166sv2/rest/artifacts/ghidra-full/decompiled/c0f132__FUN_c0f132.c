// c0f132 FUN_c0f132 size=386 cc=unknown proto=undefined FUN_c0f132(void)

void FUN_c0f132(ushort param_1)

{
  short sVar1;
  undefined2 *puVar2;
  ushort uVar3;
  undefined2 uVar4;
  short sVar5;
  short sVar6;
  char cVar7;
  byte bVar8;
  ushort uVar9;
  ushort local_a;
  
  if (param_1 == 0) {
    local_a = DAT_00fd08;
    bVar8 = DAT_00c3d9;
    cVar7 = *(char *)(uint3)((ushort)bVar8 * 2 + 0x700f);
  }
  else {
    local_a = DAT_00fd06;
    bVar8 = DAT_00c3f3;
    cVar7 = *(char *)(uint3)((short)&DAT_00c469 + (ushort)bVar8 * 2);
  }
  sVar5 = cc_irq_is_enabled(*(undefined2 *)(uint3)((short)&DAT_007046 + param_1 * 2));
  if (sVar5 == 0) {
    sVar5 = param_1 * 0x1a;
    uVar9 = (short)&DAT_00c3d9 + sVar5;
    *(char *)(uint3)uVar9 = *(char *)(uint3)uVar9 + '\x01';
    uVar3 = DAT_00c266;
    DAT_00c45c = uVar3;
    if (uVar3 < 0x105) {
      FUN_c0f0e6(param_1,*(undefined1 *)(uint3)uVar9);
      bVar8 = *(byte *)(uint3)((ushort)*(byte *)(uint3)uVar9 * 2 + 0x700f);
      if (bVar8 == 0) {
        bVar8 = 3;
      }
      uVar4 = DAT_00c27e;
      DAT_00c466 = uVar4;
      *(undefined2 *)(uint3)(ushort)((short)&UNK_00c3d6 + sVar5) = uVar4;
      uVar4 = DAT_00c466;
      *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3d4 + sVar5) = uVar4;
      FUN_c0e7ca(param_1);
      FUN_c0e830(param_1);
      uVar9 = (short)&UNK_00c3d8 + sVar5;
      *(char *)(uint3)uVar9 = *(char *)(uint3)uVar9 + cVar7;
      puVar2 = (undefined2 *)((short)&UNK_00c3ca + sVar5);
      sVar1 = *(short *)ZEXT23(puVar2);
      FUN_c0e894(param_1,*(undefined1 *)(uint3)uVar9,
                 *(undefined2 *)(uint3)(ushort)((short)&UNK_00c3dc + sVar5),puVar2,
                 (short)&DAT_00c3cc + sVar5);
      sVar6 = DAT_00c466;
      uVar9 = *(short *)ZEXT23(puVar2) - sVar6;
      if ((uVar9 & 0x8000) != 0) {
        uVar9 = 0;
      }
      uVar3 = DAT_00c45c;
      if (uVar9 < (short)((uint)bVar8 * (uint)uVar3) + 0x1eU) {
        sVar6 = t7_timestamp((short)((uint)bVar8 * (uint)uVar3 >> 0x10));
        if (((0x19 < (ushort)(sVar1 - sVar6)) && ((ushort)(sVar1 - sVar6) < 0x8000)) ||
           ((local_a & 4) == 0)) {
          FUN_c0f97a(*(undefined2 *)ZEXT23(puVar2),param_1);
          sVar1 = DAT_00c44c;
          if (sVar1 == 1) {
            FUN_c0f97a(*(undefined2 *)ZEXT23(puVar2),param_1 ^ 1);
            sVar1 = (param_1 ^ 1) * 0x1a;
            *(undefined2 *)(uint3)((short)&UNK_00c3ca + (param_1 ^ 1) * 0x1a) = *puVar2;
            *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3cc + sVar1) =
                 *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3cc + sVar5);
            *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3d4 + sVar1) =
                 *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3d4 + sVar5);
          }
        }
      }
    }
  }
  else {
    *(undefined1 *)(uint3)((short)&DAT_00c3d9 + param_1 * 0x1a) = 0;
    *(undefined1 *)(uint3)((short)&DAT_00c3da + param_1 * 0x1a) = 0;
  }
  return;
}

