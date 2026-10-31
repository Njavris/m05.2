/* c108ce pwm_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* PWM/CAPCOM6 initialization. */

void pwm_init(void)

{
  ushort uVar1;
  
  _pwm_period = 0xf423;
  _pwm_cfg_ac = 0x805;
  _pwm_cfg_ae = 0x20;
  _pwm_cfg_a0 = 0x5780;
  _pwm_duty = 0x4b00;
  _pwm_cfg_a4 = 0;
  _pwm_cfg_94 = 1;
  _pwm_cfg_c6 = 0x110;
  _pwm_cfg_a8 = 0;
  _pwm_cfg_c4 = 0;
  _pwm_cfg_c0 = 0x8014;
  _pwm_cfg_ca = 0;
  _pwm_cfg_ce = 0;
  _pwm_cfg_c2 = 0;
  uVar1 = CC19IC;
  CC19IC = uVar1 | 0x5c;
  uVar1 = CC20IC;
  CC20IC = uVar1 | 0x5d;
  uVar1 = T4IC;
  T4IC = uVar1 | 0x5e;
  if (cal_pwm_config == '\x02') {
    uVar1 = PWMCON0;
    PWMCON0 = uVar1 | 0x10;
    uVar1 = P1L;
    P1L = uVar1 & 0xffef | 0x10;
    uVar1 = DP1L;
    DP1L = uVar1 & 0xffef | 0x10;
  }
  _pwm_control = 0x202;
  return;
}


