/* c0e760 cc22_23_hysteresis_b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Hysteresis thresholds for the second CC22/CC23 input; state in cc22_23_state_machine_b. */

void cc22_23_hysteresis_b(ushort param_1)

{
  if (_cc22_23_state_machine_b == 0) {
    if (0x1c00 < param_1) {
      _cc22_23_state_machine_b = 1;
    }
  }
  else if (_cc22_23_state_machine_b == 1) {
    if (param_1 < 0x1800) {
      _cc22_23_state_machine_b = 0;
    }
    if ((0x5f00 < param_1) || (_cc22_23_state_machine_a != 0)) {
      _cc22_23_state_machine_b = 2;
      return;
    }
  }
  else if (_cc22_23_state_machine_b == 2) {
    if ((param_1 < 0x5a00) && (_cc22_23_state_machine_a == 0)) {
      _cc22_23_state_machine_b = 1;
    }
    if (0x8400 < param_1) {
      _cc22_23_state_machine_b = 3;
      return;
    }
  }
  else if ((_cc22_23_state_machine_b == 3) && (param_1 < 0x8000)) {
    _cc22_23_state_machine_b = 2;
    return;
  }
  return;
}


