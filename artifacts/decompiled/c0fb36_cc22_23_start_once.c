/* c0fb36 cc22_23_start_once */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* One-shot start of the CC22/CC23 pair. */

void cc22_23_start_once(void)

{
  short sVar1;
  
  if (cc22_23_started == '\0') {
    cc22_23_started = '\x01';
    p1l1_set();
    sVar1 = t7_timestamp();
    cc22_23_start_pair(0,sVar1);
    cc22_23_start_pair(1,sVar1);
    _cc22_23_start_time = sVar1 + cal_cc_start_offset;
  }
  return;
}


