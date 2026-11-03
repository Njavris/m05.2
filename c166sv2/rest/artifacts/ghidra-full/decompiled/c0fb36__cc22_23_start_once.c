// c0fb36 cc22_23_start_once size=56 cc=unknown proto=undefined cc22_23_start_once(void)

void cc22_23_start_once(void)

{
  char cVar1;
  short sVar2;
  
  cVar1 = DAT_00c456;
  if (cVar1 == '\0') {
    DAT_00c456 = 1;
    p1l1_set();
    sVar2 = t7_timestamp();
    cc22_23_start_pair(0,sVar2);
    cc22_23_start_pair(1,sVar2);
    DAT_c04448 = sVar2 + DAT_c079da;
  }
  return;
}

