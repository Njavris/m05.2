// c01144 asc0_state_dispatch size=26 cc=unknown proto=undefined asc0_state_dispatch(void)

void asc0_state_dispatch(void)

{
  byte bVar1;
  
  bVar1 = DAT_00c0af;
  if (5 < bVar1) {
    DAT_00c0af = 0;
    return;
  }
                    /* WARNING: Could not emulate address calculation at 0xc01154 */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((ushort)bVar1 * 2 + 0x428) | 0xc00000))();
  return;
}

