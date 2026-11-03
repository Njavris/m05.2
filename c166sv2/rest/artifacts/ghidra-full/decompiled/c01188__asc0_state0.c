// c01188 asc0_state0 size=22 cc=unknown proto=undefined asc0_state0(void)

void asc0_state0(void)

{
  ushort uVar1;
  
  DAT_00c0af = 1;
  DAT_00c0b0 = 0;
  asc0_clear_state();
  DAT_00c13a = 0;
  uVar1 = S0CON;
  S0CON = uVar1 & 0xffef;
  return;
}

