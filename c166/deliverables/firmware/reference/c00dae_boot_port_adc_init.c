/* c00dae boot_port_adc_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boot-block port/ADC-related register initialization. */

void boot_port_adc_init(void)

{
  _boot_port_cfg_c080 = 0xffff;
  boot_port_cfg_c092 = 2;
  boot_port_cfg_c091 = 0;
  boot_port_cfg_c090 = 0;
  boot_port_cfg_c08f = 0x1f;
  boot_port_cfg_c08e = 0;
  boot_port_cfg_c08d = 0;
  boot_port_cfg_c08c = 0;
  ssc_start_frame();
  return;
}


