// c01cc8 can_tx_frame size=210 cc=unknown proto=undefined can_tx_frame(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can_tx_frame(ushort param_1)

{
  ushort uVar1;
  
  do {
  } while (((byte)((ushort)_DAT_200430 >> 0xc) & 3) == 2);
  _DAT_000430 = _DAT_000430 & 0xf0ff | 0x200;
  if (param_1 < 8) {
    _DAT_000434 = _DAT_000434 & 0xff0f | (param_1 & 0xf) << 4;
  }
  else {
    _DAT_000434 = _DAT_000434 & 0xff7f | 0xf0;
  }
  uVar1 = 0;
  do {
    *(undefined1 *)(uint3)(uVar1 + 0x420 & 0x3fff) = *(undefined1 *)(uint3)(uVar1 + 0x3750 & 0x3fff)
    ;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  _DAT_000430 = _DAT_000430 & 0xc3ff | 0x2400;
  do {
  } while (((byte)((ushort)_DAT_200430 >> 0xc) & 3) == 2);
  return;
}

