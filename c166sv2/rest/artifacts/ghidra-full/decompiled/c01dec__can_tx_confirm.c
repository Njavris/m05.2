// c01dec can_tx_confirm size=212 cc=unknown proto=undefined can_tx_confirm(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can_tx_confirm(void)

{
  if (DAT_0001d6 == '\0') {
    _DAT_000434 = _DAT_000434 & 0xfff7 | 8;
    _DAT_000430 = _DAT_000430 & 0xbd | 0x59c0;
  }
  else {
    _DAT_000434 = _DAT_000434 & 0xfff7;
    _DAT_000430 = _DAT_000430 & 0xbd | 0x55c0;
  }
  _DAT_000430 = _DAT_000430 & 0xff7f | 0xc0;
  return;
}

