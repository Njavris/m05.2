// c10afc pwm_output_enable size=16 cc=unknown proto=undefined pwm_output_enable(void)

void pwm_output_enable(void)

{
  ushort uVar1;
  
  __atomic(4);
  uVar1 = DAT_00f130;
  DAT_00f130 = uVar1 | 4;
  uVar1 = P1L;
  P1L = uVar1 | 4;
  __atomic(4);
  uVar1 = DP1L;
  DP1L = uVar1 | 4;
  return;
}

