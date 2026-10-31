/* c01cc8 can_tx_frame */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Load and transmit one 8-byte CAN frame. */

void can_tx_frame(ushort param_1)

{
  ushort uVar1;
  
  do {
  } while (((byte)(_DAT_200430 >> 0xc) & 3) == 2);
  _DAT_200430 = _DAT_200430 & 0xf0ff | 0x200;
  if (param_1 < 8) {
    _DAT_200434 = _DAT_200434 & 0xff0f | (param_1 & 0xf) << 4;
  }
  else {
    _DAT_200434 = _DAT_200434 & 0xff7f | 0xf0;
  }
  uVar1 = 0;
  do {
    *(undefined1 *)((uint3)(uVar1 + 0x420) + 0x200000) =
         *(undefined1 *)((uint3)(uVar1 + 0x3750) + 0xc000);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  _DAT_200430 = _DAT_200430 & 0xc3ff | 0x2400;
  do {
  } while (((byte)(_DAT_200430 >> 0xc) & 3) == 2);
  return;
}


