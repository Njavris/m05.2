// c00ee8 boot_extint_init size=36 cc=unknown proto=undefined boot_extint_init(void)

void boot_extint_init(void)

{
  boot_bus_mode();
  EXISEL = 0;
  boot_bus_mode();
  DAT_00f1d8 = 0;
  boot_bus_mode();
  EXICON = 0;
  XP3IC = 0x44;
  return;
}

