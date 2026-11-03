// c0cac2 watchdog_pin size=24 cc=unknown proto=undefined watchdog_pin(void)

void watchdog_pin(void)

{
  ushort uVar1;
  
  uVar1 = input_status;
  if (((uVar1 & 1) == 0) && (uVar1 = input_status, (uVar1 & 2) == 0)) {
    uVar1 = DAT_00fd00;
    DAT_00fd00 = uVar1 & 0xffdf;
    return;
  }
  uVar1 = DAT_00fd00;
  DAT_00fd00 = uVar1 | 0x20;
  return;
}

