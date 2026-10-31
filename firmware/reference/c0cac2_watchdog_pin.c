/* c0cac2 watchdog_pin */

/* Watchdog/port pin control. */

void watchdog_pin(void)

{
  ushort uVar1;
  
  uVar1 = input_status;
  if (((uVar1 & 1) == 0) && (uVar1 = input_status, (uVar1 & 2) == 0)) {
    uVar1 = input_status_flags;
    input_status_flags = uVar1 & 0xffdf;
    return;
  }
  uVar1 = input_status_flags;
  input_status_flags = uVar1 | 0x20;
  return;
}


