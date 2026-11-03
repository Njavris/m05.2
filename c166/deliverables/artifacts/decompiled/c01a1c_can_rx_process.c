/* c01a1c can_rx_process */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* TwinCAN receive processing and message-object copy. */

void can_rx_process(void)

{
  byte bVar1;
  
  if ((_DAT_200284 & 0x400) == 0) {
    if ((_DAT_200284 & 0x200) == 0) {
      _can_rx_object = 0;
    }
    else if (((_DAT_200430 & 2) != 0) && (((byte)(_DAT_200430 >> 8) & 3) == 2)) {
      _can_rx_object = 9;
    }
  }
  else if (((_DAT_200450 & 2) != 0) && (((byte)(_DAT_200450 >> 8) & 3) == 2)) {
    _can_rx_object = 10;
  }
  __service_watchdog();
  if (_can_rx_object != 0) {
    bVar1 = 0;
    do {
      *(undefined1 *)((uint3)(bVar1 + 0x3740) + 0xc000) =
           *(undefined1 *)((uint3)((ushort)bVar1 + _can_rx_object * 0x20 + 0x300) + 0x200000);
      bVar1 = bVar1 + 1;
    } while (bVar1 < 8);
    can_rx_dispatch();
    _DAT_200450 = 0x5599;
    _DAT_200430 = 0x5599;
  }
  return;
}


