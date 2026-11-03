// c19a2c command_dispatch size=20 cc=unknown proto=undefined command_dispatch(void)

void command_dispatch(byte param_1)

{
  if (6 < param_1) {
    return;
  }
                    /* WARNING: Could not emulate address calculation at 0xc19a3a */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((ushort)param_1 * 2 + 0x7666 & 0x3fff) | 0xc10000))();
  return;
}

