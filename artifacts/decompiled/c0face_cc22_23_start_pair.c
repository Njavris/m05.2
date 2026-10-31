/* c0face cc22_23_start_pair */

/* Starts both CC22/CC23 channels at a common timestamp. */

void cc22_23_start_pair(short param_1,undefined2 param_2)

{
  ushort uVar1;
  
  cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&cc22_23_input_0 + param_1 * 2),param_1,
                   param_2);
  if (param_1 == 0) {
    uVar1 = S0RIC;
    S0RIC = uVar1 | 0x40;
    return;
  }
  if (param_1 == 1) {
    uVar1 = S0TIC;
    S0TIC = uVar1 | 0x40;
  }
  return;
}


