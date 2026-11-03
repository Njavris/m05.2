/* c0bda2 timer4_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Timer T4 initialization. */

void timer4_init(void)

{
  ushort uVar1;
  
  if (cal_cc22_config == '\x01') {
    T4CON = 5;
    T4 = 0xff83;
    uVar1 = T4IC;
    T4IC = uVar1 | 0x61;
    uVar1 = DAT_00f138;
    DAT_00f138 = uVar1 & 0xfffd;
    uVar1 = DAT_00ff3a;
    DAT_00ff3a = uVar1 & 0xfffd;
    uVar1 = T4CON;
    T4CON = uVar1 | 0x40;
    _ram_var_c3a4 = 0;
  }
  return;
}


