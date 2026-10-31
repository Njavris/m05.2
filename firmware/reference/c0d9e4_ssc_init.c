/* c0d9e4 ssc_init */

/* WARNING: Removing unreachable block (ram,0xc0da4c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* SSC/CC26 initialization; installs handlers at 0xC0D8FA and 0xC0D914. */

void ssc_init(void)

{
  ushort uVar1;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  _ssc_callback_ptr_1 = 0xd8fa;
  _ssc_callback_ptr_1_hi = 0xc0;
  _ssc_callback_ptr_2 = 0xd914;
  _ssc_callback_ptr_2_hi = 0xc0;
  cc26_ptr_init();
  *(ushort *)(uint3)_ssc_cc26_flags = *(ushort *)(uint3)_ssc_cc26_flags | 0x68;
  ssc_pin_config();
  if (_ssc_var_c48a != 0) {
    _ssc_callback_ptr_0 = 0xd8ce;
    _ssc_callback_ptr_0_hi = 0xc0;
  }
  if ((_ssc_var_c48c == 0) && (_ssc_var_c48a == 0)) {
    _ssc_var_c3ba = 1;
    _ssc_callback_ptr_0 = 0xd8ce;
    _ssc_callback_ptr_0_hi = 0xc0;
  }
  else {
    _ssc_var_c3ba = 0;
  }
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


