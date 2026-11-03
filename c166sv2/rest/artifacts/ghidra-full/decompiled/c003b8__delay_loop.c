// c003b8 delay_loop size=10 cc=unknown proto=undefined delay_loop(void)

void delay_loop(void)

{
  bool bVar1;
  short sVar2;
  
  sVar2 = 0;
  do {
    bVar1 = sVar2 < 0x62f;
    sVar2 = sVar2 + 1;
  } while (bVar1);
  return;
}

