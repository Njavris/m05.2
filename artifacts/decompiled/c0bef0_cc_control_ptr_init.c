/* c0bef0 cc_control_ptr_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Caches pointers to 0xFF2C and 0xFE2A. */

void cc_control_ptr_init(void)

{
  _cc_control_ptr = SUB32(&DAT_00ff2c,0);
  _cc_irq_ptr = SUB32(&DAT_00fe2a,0);
  return;
}


