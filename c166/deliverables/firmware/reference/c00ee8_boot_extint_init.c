/* c00ee8 boot_extint_init */

/* Boot external-interrupt init: bus mode, EXICON, T1IC. */

void boot_extint_init(void)

{
  boot_bus_mode();
  DAT_00ffda = 0;
  boot_bus_mode();
  DAT_00ffd8 = 0;
  boot_bus_mode();
  EXICON = 0;
  T1IC = 0x44;
  return;
}


