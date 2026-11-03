// c0fb6e timer6_start size=30 cc=unknown proto=undefined timer6_start(void)

void timer6_start(void)

{
  timer6_init();
  ssc_state_reset();
  DAT_00fd12 = 0;
  DAT_00fd10 = 0;
  DAT_00fd0e = 0;
  DAT_00fd0c = 0;
  DAT_00c478 = 0;
  return;
}

