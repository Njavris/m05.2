/* c10242 input_debounce_sample */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Samples P1L pins and updates input_state_bits/input_low_bits/input_high_bits. */

void input_debounce_sample(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = 1;
  do {
    __service_watchdog();
    if ((uVar2 & _input_state_bits) == 0) {
      _input_low_bits = _input_low_bits | uVar2;
    }
    else {
      _input_high_bits = _input_high_bits | uVar2;
    }
    if (uVar2 == 8) {
      uVar1 = P1L;
      if ((uVar1 & 0x40) == 0) {
        _input_state_bits = _input_state_bits & 0xfff7;
      }
      else {
        _input_state_bits = _input_state_bits | 8;
      }
    }
    else if (uVar2 == 0x80) {
      uVar1 = P1L;
      if ((uVar1 & 1) == 0) {
        _input_state_bits = _input_state_bits & 0xff7f;
      }
      else {
        _input_state_bits = _input_state_bits | 0x80;
      }
    }
    else if (uVar2 == 0x20) {
      uVar1 = P1L;
      if ((uVar1 & 4) == 0) {
        _input_state_bits = _input_state_bits & 0xffdf;
      }
      else {
        _input_state_bits = _input_state_bits | 0x20;
      }
    }
    else if (uVar2 == 0x10) {
      uVar1 = P1L;
      if ((uVar1 & 0x20) == 0) {
        _input_state_bits = _input_state_bits & 0xffef;
      }
      else {
        _input_state_bits = _input_state_bits | 0x10;
      }
    }
    uVar2 = uVar2 * 2;
  } while (uVar2 < 0x81);
  return;
}


