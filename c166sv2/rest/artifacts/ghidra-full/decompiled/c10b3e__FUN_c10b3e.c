// c10b3e FUN_c10b3e size=252 cc=unknown proto=undefined FUN_c10b3e(void)

short FUN_c10b3e(ushort param_1,ushort param_2,ushort param_3,ushort param_4)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  short in_r4;
  short sVar5;
  
  uVar2 = param_1 + 2;
  if (*(short *)(uint3)uVar2 == 0 && *(short *)(uint3)(param_1 + 4) == 0) {
    *(ushort *)(uint3)param_3 = *(ushort *)(uint3)param_3 & ~param_4;
    return in_r4;
  }
  uVar3 = param_1 + 6;
  sVar1 = *(short *)(uint3)(param_1 + 8);
  if (*(short *)(uint3)uVar3 == 0 && sVar1 == 0) {
    *(ushort *)(uint3)param_3 = *(ushort *)(uint3)param_3 | param_4;
    return sVar1;
  }
  if (*(short *)(uint3)param_1 == 0) {
    sVar1 = *(short *)(uint3)uVar2;
    sVar5 = *(short *)(uint3)(param_1 + 4) - (ushort)(sVar1 != -1);
    if ((sVar5 != 0 || sVar1 != -1) && (*(short *)(uint3)(param_1 + 4) != 0 || sVar1 == -1)) {
      uVar4 = param_1 + 10;
      sVar5 = CONCAT11((char)((ushort)sVar5 >> 8),*(char *)(uint3)uVar4 + -1);
      *(char *)(uint3)uVar4 = *(char *)(uint3)uVar4 + -1;
      if (*(char *)(uint3)uVar4 == '\0') goto LAB_c10c20;
    }
    if ((*(char *)(uint3)(param_1 + 10) < '\0') ||
       (sVar5 = *(short *)(uint3)(param_1 + 4) - (ushort)(*(short *)(uint3)uVar2 != -1),
       *(short *)(uint3)(param_1 + 4) == 0 && *(short *)(uint3)uVar2 != -1)) {
      *(undefined2 *)(uint3)param_1 = 1;
      *(ushort *)(uint3)param_3 = *(ushort *)(uint3)param_3 & ~param_4;
      if (*(short *)(uint3)(param_1 + 8) != 0 || *(short *)(uint3)uVar3 == -1) {
        *(char *)(uint3)(param_1 + 0xb) = (char)*(undefined2 *)(uint3)(param_1 + 8);
        return sVar5;
      }
LAB_c10be8:
      *(short *)(uint3)param_2 = *(short *)(uint3)param_2 + *(short *)(uint3)uVar3;
      return sVar5;
    }
  }
  else {
    sVar1 = *(short *)(uint3)uVar3;
    sVar5 = *(short *)(uint3)(param_1 + 8) - (ushort)(sVar1 != -1);
    if ((sVar5 != 0 || sVar1 != -1) && (*(short *)(uint3)(param_1 + 8) != 0 || sVar1 == -1)) {
      uVar4 = param_1 + 0xb;
      sVar5 = CONCAT11((char)((ushort)sVar5 >> 8),*(char *)(uint3)uVar4 + -1);
      *(char *)(uint3)uVar4 = *(char *)(uint3)uVar4 + -1;
      if (*(char *)(uint3)uVar4 == '\0') goto LAB_c10be8;
    }
    if ((*(char *)(uint3)(param_1 + 0xb) < '\0') ||
       (sVar5 = *(short *)(uint3)(param_1 + 8) - (ushort)(*(short *)(uint3)uVar3 != -1),
       *(short *)(uint3)(param_1 + 8) == 0 && *(short *)(uint3)uVar3 != -1)) {
      *(undefined2 *)(uint3)param_1 = 0;
      *(ushort *)(uint3)param_3 = *(ushort *)(uint3)param_3 | param_4;
      if (*(short *)(uint3)(param_1 + 4) == 0 && *(short *)(uint3)uVar2 != -1) {
LAB_c10c20:
        *(short *)(uint3)param_2 = *(short *)(uint3)param_2 + *(short *)(uint3)uVar2;
        return sVar5;
      }
      *(char *)(uint3)(param_1 + 10) = (char)*(undefined2 *)(uint3)(param_1 + 4);
    }
  }
  return sVar5;
}

