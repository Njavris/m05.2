// c0be6a cc22_23_schedule size=134 cc=unknown proto=undefined cc22_23_schedule(void)

void cc22_23_schedule(short param_1,short param_2)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  
  sVar3 = t7_timestamp();
  if (((ushort)(param_2 - sVar3) < 3) || (0x1fff < (ushort)(param_2 - sVar3))) {
    sVar1 = T7;
    if (param_1 == 0) {
      __atomic(2);
      CC23 = sVar1 + 7;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x80;
    }
    else {
      __atomic(2);
      CC22 = sVar1 + 7;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x40;
    }
    *(short *)(uint3)(ushort)((short)&DAT_00c3d2 + param_1 * 0x1a) = sVar3;
  }
  else {
    if (param_1 == 0) {
      __atomic(2);
      CC23 = param_2 << 3;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x80;
    }
    else {
      __atomic(2);
      CC22 = param_2 << 3;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x40;
    }
    *(short *)(uint3)(ushort)((short)&DAT_00c3d2 + param_1 * 0x1a) = param_2;
  }
  return;
}

