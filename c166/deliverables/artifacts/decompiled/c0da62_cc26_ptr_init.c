/* c0da62 cc26_ptr_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Stores CC26/CCM6/CC26IC pointers used by the SSC timing path. */

void cc26_ptr_init(void)

{
  _event_var_c48e = SUB32(&CC26,0);
  _ssc_var_c482 = SUB32(&CCM6,0);
  _ssc_cc26_flags = SUB32(&CC26IC,0);
  _ssc_var_c488 = SUB32(&DAT_00fe28,0);
  _event_var_c486 = SUB32(&DAT_00fe2a,0);
  return;
}


