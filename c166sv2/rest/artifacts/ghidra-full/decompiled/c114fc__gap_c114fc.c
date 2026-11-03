// c114fc gap_c114fc size=138 cc=unknown proto=undefined gap_c114fc(void)

short gap_c114fc(short param_1)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  char *pcVar5;
  ushort uVar6;
  ushort uVar7;
  short sVar8;
  ushort uVar9;
  
  uVar7 = *(short *)(uint3)(param_1 + 8) + 4;
  uVar2 = param_1 + 0x30;
  sVar8 = 0;
  *(undefined2 *)(uint3)uVar2 = 0;
  uVar3 = param_1 + 0x3c;
  *(short *)(uint3)uVar3 = *(short *)(uint3)uVar2 * 6 + 0x73d0;
  do {
    if ((*(short *)(uint3)uVar3 == 0) || (sVar8 != 0)) {
      return sVar8;
    }
    uVar4 = param_1 + 0x2e;
    uVar9 = *(ushort *)(uint3)*(ushort *)(uint3)uVar3;
    *(undefined2 *)(uint3)uVar4 = *(undefined2 *)(uint3)(*(short *)(uint3)uVar3 + 2);
    uVar6 = uVar7;
    while (uVar7 = uVar6, *(short *)(uint3)uVar4 != 0) {
      uVar7 = uVar6 + 1;
      pcVar5 = (char *)(uint3)uVar9;
      uVar9 = uVar9 + 1;
      if (*(char *)(uint3)uVar6 != *pcVar5) {
        sVar8 = 1;
        break;
      }
      *(short *)(uint3)uVar4 = *(short *)(uint3)uVar4 + -1;
      uVar6 = uVar7;
    }
    sVar1 = *(short *)(uint3)uVar2;
    *(short *)(uint3)uVar2 = sVar1 + 1;
    *(short *)(uint3)uVar3 = (sVar1 + 1) * 6 + 0x73d0;
  } while( true );
}

