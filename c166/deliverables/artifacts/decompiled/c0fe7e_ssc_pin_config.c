/* c0fe7e ssc_pin_config */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* SSC/port configuration. */

void ssc_pin_config(void)

{
  ssc_mode_select();
  *(ushort *)(uint3)_ssc_var_c482 = *(ushort *)(uint3)_ssc_var_c482 & 0xf0ff;
  *(ushort *)(uint3)_ssc_var_c482 = *(ushort *)(uint3)_ssc_var_c482 | 0x400;
  *(ushort *)(uint3)_ssc_var_c488 = *(ushort *)(uint3)_ssc_var_c488 | 0x400;
  *(ushort *)(uint3)_ssc_cc26_flags = *(ushort *)(uint3)_ssc_cc26_flags & 0xff7f;
  return;
}


