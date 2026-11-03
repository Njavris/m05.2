// c0f3d2 cc22_23_task size=164 cc=unknown proto=undefined cc22_23_task(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cc22_23_task(void)

{
  undefined2 uVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  
  uVar4 = DAT_00c9d0;
  if (uVar4 < 0xc7ff) {
    uVar4 = DAT_00c9d0;
  }
  else {
    uVar4 = 0xc7ff;
  }
  cc22_23_hysteresis_a();
  cc22_23_hysteresis_b((short)(CONCAT22(uVar4 >> 0xb,uVar4 << 5) / 0x19));
  uVar4 = DAT_00fd02;
  if (((uVar4 & 0x400) == 0) && (uVar4 = DAT_00fd02, (uVar4 & 0x80) != 0)) {
    sVar3 = cc_irq_is_enabled(_DAT_007046);
    if (sVar3 == 1) {
      cc22_23_output_disable(0);
      cc_irq_enable(_DAT_007046,0);
      uVar4 = CC23IC;
      CC23IC = uVar4 & 0xffbf;
    }
    sVar3 = cc_irq_is_enabled(_DAT_007048);
    if (sVar3 == 1) {
      cc22_23_output_disable(1);
      cc_irq_enable(_DAT_007048,0);
      uVar4 = CC22IC;
      CC22IC = uVar4 & 0xffbf;
    }
  }
  uVar1 = DAT_00fd02;
  uVar4 = DAT_00fd02;
  uVar2 = DAT_00fd02;
  DAT_00fd02 = uVar2 & 0xff7f | ((uVar4 & 0x400) >> 10) << 7;
  cc_event_timeout_tick();
  return;
}

