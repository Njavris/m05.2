/* c0fb8c cc_event_timeout_tick */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Decrements the CC event timeout counters. */

void cc_event_timeout_tick(void)

{
  char cVar1;
  byte bVar2;
  
  _event_var_c478 = _event_var_c478 + 1;
  if (0xa00 < _event_var_c478) {
    _event_var_c478 = 0;
    cVar1 = cc_event_timeout_0;
    if ((cVar1 != '\0') && (bVar2 = cc_event_timeout_0, bVar2 < 0x10)) {
      cVar1 = cc_event_timeout_0;
      cc_event_timeout_0 = cVar1 + -1;
    }
    cVar1 = cc_event_timeout_1;
    if ((cVar1 != '\0') && (bVar2 = cc_event_timeout_1, bVar2 < 0x10)) {
      cVar1 = cc_event_timeout_1;
      cc_event_timeout_1 = cVar1 + -1;
    }
  }
  return;
}


