// c0fc42 FUN_c0fc42 size=78 cc=unknown proto=undefined FUN_c0fc42(void)

void FUN_c0fc42(short param_1)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  undefined2 uVar4;
  
  sVar3 = t7_timestamp();
  sVar1 = *(short *)(uint3)(ushort)((short)&DAT_00c3d2 + param_1 * 0x1a);
  uVar2 = sVar1 - sVar3;
  if ((uVar2 != 1 && sVar1 != sVar3) && (uVar2 < 0x8000)) {
    uVar4 = t7_timestamp();
    cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + param_1 * 2),param_1,uVar4)
    ;
    FUN_c0fbcc(param_1);
  }
  if (param_1 == 0) {
    uVar2 = DAT_00fd10;
    DAT_00fd10 = uVar2 | 2;
  }
  else {
    uVar2 = DAT_00fd0c;
    DAT_00fd0c = uVar2 | 2;
  }
  return;
}

