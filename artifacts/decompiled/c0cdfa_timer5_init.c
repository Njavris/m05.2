/* c0cdfa timer5_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Timer T5/ASC0 error init. */

void timer5_init(void)

{
  ushort uVar1;
  byte bVar2;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xffbf;
  T5 = 0;
  uVar1 = S0EIC;
  S0EIC = uVar1 & 0xffbf;
  _speed_table_504c = 0x200;
  _speed_table_5038 = 0;
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  bVar2 = 0;
  do {
    uVar1 = (ushort)bVar2;
    bVar2 = bVar2 + 1;
    *(undefined2 *)(uint3)(uVar1 * 2 + 0xc282) = 0;
  } while (bVar2 < 0x18);
  input_status_flags = 0x8100;
  capture_state = 0;
  speed_input_ready = 0;
  capture_var_c277 = 0;
  capture_var_c264 = 0;
  capture_var_c272 = 0;
  uVar1 = input_status_flags;
  input_status_flags = uVar1 & 0xffbf;
  _capture_period_initial = 0xffff;
  _capture_period_a = 0xffff;
  _capture_period_b = 0xffff;
  speed_sample_counter = 0xff;
  _capture_overflow = 0;
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  _capture_callback_1 = 0xc8e2;
  _capture_callback_1_hi = 0xc0;
  _capture_callback_0 = 0xc914;
  _capture_callback_0_hi = 0xc0;
  _capture_enable = _capture_enable | 1;
  _capture_irq_mask = _capture_irq_mask | 2;
  _capture_irq_mask_2 = _capture_irq_mask_2 | 2;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xffbf;
  T5 = 0;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xff7f;
  uVar1 = S0EIC;
  S0EIC = uVar1 | 0x40;
  watchdog_pin();
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


