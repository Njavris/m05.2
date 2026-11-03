// c10342 ssc_task size=46 cc=unknown proto=undefined ssc_task(void)

void ssc_task(void)

{
  char cVar1;
  ushort uVar2;
  
  ssc_rx_start();
  cVar1 = DAT_00c498;
  if (cVar1 == '\0') {
    uVar2 = DAT_00c4ba;
    DAT_00c4ba = uVar2 | 0x200;
    ssc_rx_start();
    empty_stub_3();
    DAT_00c498 = 0x50;
  }
  else {
    cVar1 = DAT_00c498;
    DAT_00c498 = cVar1 + -1;
  }
  input_debounce_sample();
  return;
}

