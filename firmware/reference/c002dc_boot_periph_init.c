/* c002dc boot_periph_init */

/* Boot peripheral initialization wrapper. */

void boot_periph_init(void)

{
  ushort uVar1;
  
  boot_bus_mode();
  P7 = 0x7f13;
  clock_init();
  asc0_init(boot_variant);
  capcom_timer_init(boot_variant);
  boot_extint_init();
  asc0_pin_init();
  boot_port_adc_init();
  can_twincan_init();
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


