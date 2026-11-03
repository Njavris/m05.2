// c13d5e test_command_dispatch size=106 cc=unknown proto=undefined test_command_dispatch(void)

void test_command_dispatch(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  byte bVar5;
  ushort uVar6;
  
  bVar5 = DAT_00fd18._0_1_;
  if ((bVar5 & 0x7f) == 0) {
    DAT_00c5e8 = 0;
    DAT_00c5ea = 0;
    return;
  }
  uVar1 = DAT_00c5e8;
  sVar3 = DAT_00c5ea;
  if (sVar3 == 0 && uVar1 < 1000) {
    sVar2 = DAT_00c5e8;
    DAT_00c5e8 = sVar2 + 1;
    sVar4 = DAT_00c5ea;
    DAT_00c5ea = (sVar4 + 1) - (ushort)(sVar2 != -1);
    uVar6 = DAT_00fd18;
    if ((uVar6 & 1) != 0) {
      cc22_23_start_once(sVar3 - (ushort)(uVar1 < 1000));
      return;
    }
    uVar1 = DAT_00fd18;
    if ((uVar1 & 2) != 0) {
      event_start_fixed();
      return;
    }
    uVar1 = DAT_00fd18;
    if ((uVar1 & 4) != 0) {
      pwm_output_enable();
      pwm_period_duty_calc(0xfa,0);
      return;
    }
  }
  else {
    bVar5 = DAT_00fd18._0_1_;
    DAT_00fd18._0_1_ = bVar5 & 0x80;
  }
  return;
}

