/* c1482c diag_status_build */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Builds the packed diagnostic status bytes 0xC60C..0xC610. */

void diag_status_build(void)

{
  diag_status_byte2 =
       diag_flag_c784 | diag_flag_c850 << 1 | diag_flag_c786 << 2 | diag_flag_c780 << 3 |
       diag_flag_c781 << 4 | diag_flag_c78d << 5 | DAT_e00844 << 6 | diag_flag_cac6 << 7;
  diag_status_byte4 =
       diag_flag_cad6 | diag_flag_c014 << 1 | diag_flag_c824 << 2 | diag_flag_c841 << 3 |
       diag_flag_c830 << 4 | diag_flag_c836 << 5 | diag_flag_c840 << 6 | diag_flag_cad7 << 7;
  diag_status_byte3 =
       _diag_flag_cad0 == 1 | diag_flag_cac5 << 1 | DAT_e00810 << 2 | diag_flag_caf8 << 3;
  if (DAT_e0089e == '\0') {
    diag_status_byte3 = diag_status_byte3 | 0x10;
  }
  diag_status_byte3 = diag_status_byte3 | DAT_e0085c << 5 | DAT_e00846 << 6 | diag_flag_c954 << 7;
  diag_status_byte1 =
       diag_flag_c92b | diag_flag_c934 << 1 | DAT_e0081a << 2 | diag_flag_c81c << 3 |
       diag_flag_c77e << 4;
  if (ram_var_c604 == '\0') {
    diag_status_byte1 = diag_status_byte1 | 0x20;
  }
  if (diag_flag_c603 == '\0') {
    diag_status_byte1 = diag_status_byte1 | 0x40;
  }
  diag_status_byte1 = diag_status_byte1 | (_DAT_e0083e == 1) << 7;
  diag_status_bytes =
       diag_flag_c9f0 | diag_flag_c91c << 1 | diag_flag_c92e << 2 | diag_flag_ca44 << 3 |
       diag_flag_c89e << 4;
  if (engine_state == '\x03') {
    diag_status_bytes = diag_status_bytes | 0x20;
  }
  diag_status_bytes = diag_status_bytes | DAT_e00894 << 6 | diag_flag_caf9 << 7;
  return;
}


