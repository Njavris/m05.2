// c0fa2a FUN_c0fa2a size=100 cc=unknown proto=undefined FUN_c0fa2a(void)

void FUN_c0fa2a(short param_1,short param_2)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  
  sVar2 = cc_irq_is_enabled(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + param_2 * 2));
  if (sVar2 == 1) {
    sVar2 = DAT_00c458;
    uVar3 = FUN_c0ecb6(param_1 - sVar2,
                       *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3ce + param_2 * 0x1a));
    cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + param_2 * 2),param_2,uVar3)
    ;
    if (param_2 == 0) {
      uVar1 = CC23IC;
      CC23IC = uVar1 | 0x40;
    }
    else if (param_2 == 1) {
      uVar1 = CC22IC;
      CC22IC = uVar1 | 0x40;
    }
  }
  return;
}

