// c0face cc22_23_start_pair size=42 cc=unknown proto=undefined cc22_23_start_pair(void)

void cc22_23_start_pair(short param_1,undefined2 param_2)

{
  ushort uVar1;
  
  cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + param_1 * 2),param_1,param_2)
  ;
  if (param_1 == 0) {
    uVar1 = CC23IC;
    CC23IC = uVar1 | 0x40;
    return;
  }
  if (param_1 == 1) {
    uVar1 = CC22IC;
    CC22IC = uVar1 | 0x40;
  }
  return;
}

