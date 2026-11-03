// c003c2 delay_ticks size=28 cc=unknown proto=undefined delay_ticks(void)

void delay_ticks(short param_1)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  
  for (sVar3 = 0; sVar3 < param_1; sVar3 = sVar3 + 1) {
    __service_watchdog();
    sVar2 = 0;
    do {
      bVar1 = sVar2 < 0x7bbf;
      sVar2 = sVar2 + 1;
    } while (bVar1);
  }
  return;
}

