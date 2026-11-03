/* c19a2c command_dispatch */

/* Dispatches command index 0..6 through the external-RAM table at 0x7666. */

void command_dispatch(byte param_1)

{
  if (6 < param_1) {
    return;
  }
                    /* WARNING: Could not emulate address calculation at 0xc19a3a */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((short)&command_handler_table + (ushort)param_1 * 2 & 0x3fff) |
            0xc10000))();
  return;
}


