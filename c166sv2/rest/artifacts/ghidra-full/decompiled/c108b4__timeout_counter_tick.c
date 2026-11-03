// c108b4 timeout_counter_tick size=26 cc=unknown proto=undefined timeout_counter_tick(void)

void timeout_counter_tick(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = DAT_00c4cc;
  if (bVar1 < 0x81) {
    cVar2 = DAT_00c4cc;
    DAT_00c4cc = cVar2 + '\x01';
    return;
  }
  DAT_00c4d2 = 0;
  DAT_00c4d4 = 0;
  return;
}

