// c02b76 boot_hidden_eeprom size=36 cc=unknown proto=undefined boot_hidden_eeprom(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort boot_hidden_eeprom(void)

{
  while ((_DAT_fff000 & 1) != 0) {
    __service_watchdog();
  }
  return _DAT_fff000;
}

