// c11eec scheduler_tick size=24 cc=unknown proto=undefined scheduler_tick(void)

void scheduler_tick(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  cVar1 = DAT_00c54c;
  DAT_00c54c = cVar1 + '\x01';
  bVar2 = DAT_00c54c;
  bVar3 = DAT_00c550;
  bVar4 = DAT_00c550;
  if (bVar2 != bVar4 && bVar3 <= bVar2) {
    DAT_00c54c = 0;
  }
  command_dispatch_index3();
  return;
}

