// c01218 asc0_state2_init size=58 cc=unknown proto=undefined asc0_state2_init(void)

void asc0_state2_init(char param_1)

{
  ushort uVar1;
  
  asc0_clear_state();
  if (param_1 == '\x02') {
    DAT_00c09e = 0x5e;
    DAT_00c0a0 = 0x49fb;
    DAT_00c0a2 = 0x79;
  }
  DAT_00c0af = 3;
  DAT_00c1d0 = 0;
  DAT_00c09a = 1;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x10;
  return;
}

