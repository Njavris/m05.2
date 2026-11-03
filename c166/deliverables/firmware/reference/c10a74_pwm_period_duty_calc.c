/* c10a74 pwm_period_duty_calc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Computes PWM period/duty from the 32-bit division result. */

void pwm_period_duty_calc(undefined2 param_1,undefined2 param_2)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  
  uVar2 = _pwm_cfg_ac & 0xf;
  uVar3 = 0x4800;
  sVar4 = 0x1e8;
  while (bVar1 = uVar2 != 0, uVar2 = uVar2 - 1, bVar1) {
    uVar3 = uVar3 >> 1 | sVar4 << 0xf;
    sVar4 = sVar4 >> 1;
  }
  _pwm_divisor = div32_checked(uVar3,sVar4,param_1);
  _pwm_duty_calc = mul_div32(_pwm_divisor,0,param_2);
  if (_pwm_divisor == _pwm_duty_calc) {
    _pwm_duty_calc = _pwm_duty_calc + 1;
  }
  _pwm_period = _pwm_divisor;
  _pwm_duty = _pwm_duty_calc;
  _pwm_control = _pwm_control | 0x40;
  return;
}


