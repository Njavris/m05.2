// c0f97a FUN_c0f97a size=176 cc=unknown proto=undefined FUN_c0f97a(void)

void FUN_c0f97a(short param_1,short param_2)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  
  sVar2 = FUN_c0fe0c(param_2);
  if (sVar2 != 1) {
    if (param_2 == 0) {
      uVar5 = (ushort)&DAT_00fd08;
    }
    else {
      uVar5 = (ushort)&DAT_00fd06;
    }
    sVar2 = param_2 * 2;
    sVar3 = cc_irq_is_enabled(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + sVar2));
    if ((sVar3 == 0) && ((*(ushort *)(uint3)uVar5 & 0x20) == 0)) {
      sVar3 = DAT_00c458;
      sVar4 = t7_timestamp();
      if ((ushort)((param_1 - sVar3) - sVar4) < 0x8000) {
        cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + sVar2),param_2,
                         param_1 - sVar3);
      }
      else {
        sVar3 = t7_timestamp();
        cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + sVar2),param_2,
                         sVar3 + 0xe);
      }
      if (param_2 == 0) {
        uVar1 = CC23IC;
        CC23IC = uVar1 | 0x40;
      }
      else if (param_2 == 1) {
        uVar1 = CC22IC;
        CC22IC = uVar1 | 0x40;
      }
      *(ushort *)(uint3)uVar5 = *(ushort *)(uint3)uVar5 & 0xfffb | 4;
    }
  }
  return;
}

