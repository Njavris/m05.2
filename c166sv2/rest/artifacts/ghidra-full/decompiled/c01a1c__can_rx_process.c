// c01a1c can_rx_process size=184 cc=unknown proto=undefined can_rx_process(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can_rx_process(void)

{
  short sVar1;
  byte bVar2;
  
  if ((_DAT_200284 & 0x400) == 0) {
    if ((_DAT_200284 & 0x200) == 0) {
      DAT_00c1d2 = 0;
    }
    else if (((_DAT_200430 & 2) != 0) && (((byte)(_DAT_200430 >> 8) & 3) == 2)) {
      DAT_00c1d2 = 9;
    }
  }
  else if (((_DAT_200450 & 2) != 0) && (((byte)(_DAT_200450 >> 8) & 3) == 2)) {
    DAT_00c1d2 = 10;
  }
  __service_watchdog();
  sVar1 = DAT_00c1d2;
  if (sVar1 != 0) {
    bVar2 = 0;
    do {
      sVar1 = DAT_00c1d2;
      *(undefined1 *)(uint3)(bVar2 + 0x3740 & 0x3fff) =
           *(undefined1 *)(uint3)((ushort)bVar2 + sVar1 * 0x20 + 0x300 & 0x3fff);
      bVar2 = bVar2 + 1;
    } while (bVar2 < 8);
    can_rx_dispatch(3);
    _DAT_200450 = 0x5599;
    _DAT_200430 = 0x5599;
  }
  return;
}

