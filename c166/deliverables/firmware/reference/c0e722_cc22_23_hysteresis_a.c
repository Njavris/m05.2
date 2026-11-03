/* c0e722 cc22_23_hysteresis_a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Hysteresis thresholds for the first CC22/CC23 input; state in cc22_23_state_machine_a. */

void cc22_23_hysteresis_a(ushort param_1)

{
  if (_cc22_23_state_machine_a == 0) {
    if (param_1 < 0x6901) {
      return;
    }
  }
  else {
    if (_cc22_23_state_machine_a == 1) {
      if (param_1 < 0x6400) {
        _cc22_23_state_machine_a = 0;
      }
      if (param_1 < 0xa401) {
        return;
      }
      _cc22_23_state_machine_a = 2;
      return;
    }
    if (_cc22_23_state_machine_a != 2) {
      return;
    }
    if (0x9fff < param_1) {
      return;
    }
  }
  _cc22_23_state_machine_a = 1;
  return;
}


