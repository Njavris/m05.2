/* c01dec can_tx_confirm */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Set CAN message object transmission-request/confirm bits. */

void can_tx_confirm(void)

{
  if (can_tx_active == '\0') {
    _DAT_200434 = _DAT_200434 & 0xfff7 | 8;
    _DAT_200430 = _DAT_200430 & 0xbd | 0x59c0;
  }
  else {
    _DAT_200434 = _DAT_200434 & 0xfff7;
    _DAT_200430 = _DAT_200430 & 0xbd | 0x55c0;
  }
  _DAT_200430 = _DAT_200430 & 0xff7f | 0xc0;
  return;
}


