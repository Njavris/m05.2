// c10a74 pwm_period_duty_calc size=106 cc=unknown proto=undefined pwm_period_duty_calc(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pwm_period_duty_calc(undefined2 param_1,undefined2 param_2)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  short sVar6;
  
  uVar3 = _DAT_00e8ac & 0xf;
  uVar5 = 0x4800;
  sVar6 = 0x1e8;
  while (bVar1 = uVar3 != 0, uVar3 = uVar3 - 1, bVar1) {
    uVar5 = uVar5 >> 1 | sVar6 << 0xf;
    sVar6 = sVar6 >> 1;
  }
  uVar4 = div32_checked(uVar5,sVar6,param_1);
  DAT_00c504 = uVar4;
  uVar4 = mul_div32(uVar4,0,param_2);
  DAT_00c4ea = uVar4;
  sVar2 = DAT_00c504;
  sVar6 = DAT_00c4ea;
  if (sVar2 == sVar6) {
    sVar6 = DAT_00c4ea;
    DAT_00c4ea = sVar6 + 1;
  }
  _DAT_00e892 = DAT_00c504;
  _DAT_00e8a2 = DAT_00c4ea;
  _DAT_00e8a6 = _DAT_00e8a6 | 0x40;
  return;
}

