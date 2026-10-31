/* c01144 asc0_state_dispatch */

/* Dispatch ASC0 K-line state 0..5 through table at 0xC00428. */

void asc0_state_dispatch(void)

{
  if (5 < kline_state_machine) {
    kline_state_machine = 0;
    return;
  }
                    /* WARNING: Could not emulate address calculation at 0xc01154 */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((ushort)kline_state_machine * 2 + 0x428) | 0xc00000))();
  return;
}


