/* c0bd58 capcom16_17_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAPCOM CC16/CC17 channel setup. */

void capcom16_17_init(void)

{
  ushort uVar1;
  
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 1;
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 2;
  event_var_c390 = 0x10;
  _ram_var_c392 = SUB32(&CC16,0);
  _ram_var_c394 = SUB32(&CCM4,0);
  _ram_var_c396 = SUB32(&CC16IC,0);
  event_var_c398 = 0x11;
  _ram_var_c39a = SUB32(&CC17,0);
  _ram_var_c39c = SUB32(&CCM4,0);
  _ram_var_c39e = SUB32(&CC17IC,0);
  return;
}


