/* c10afc pwm_output_enable */

/* Enables the PWM output (PWMCON0 and P1L.4). */

void pwm_output_enable(void)

{
  ushort uVar1;
  
  __atomic(4);
  uVar1 = PWMCON0;
  PWMCON0 = uVar1 | 4;
  uVar1 = P1L;
  P1L = uVar1 | 4;
  __atomic(4);
  uVar1 = P1L;
  P1L = uVar1 | 4;
  return;
}


