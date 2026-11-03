// c002dc boot_periph_init size=50 cc=unknown proto=undefined boot_periph_init(void)

void boot_periph_init(void)

{
  undefined1 uVar1;
  ushort uVar2;
  
  boot_bus_mode();
  SYSCON2 = 0x7f13;
  clock_init();
  uVar1 = DAT_00c020;
  asc0_init(uVar1);
  uVar1 = DAT_00c020;
  capcom_timer_init(uVar1);
  boot_extint_init();
  asc0_pin_init();
  boot_port_adc_init();
  can_twincan_init();
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return;
}

