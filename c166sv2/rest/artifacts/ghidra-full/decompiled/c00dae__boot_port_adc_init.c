// c00dae boot_port_adc_init size=44 cc=unknown proto=undefined boot_port_adc_init(void)

void boot_port_adc_init(void)

{
  DAT_00c080 = 0xffff;
  DAT_00c092 = 2;
  DAT_00c091 = 0;
  DAT_00c090 = 0;
  DAT_00c08f = 0x1f;
  DAT_00c08e = 0;
  DAT_00c08d = 0;
  DAT_00c08c = 0;
  ssc_start_frame();
  return;
}

