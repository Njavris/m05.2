// c022fc boot_hidden_xram2 size=34 cc=unknown proto=undefined boot_hidden_xram2(void)

void boot_hidden_xram2(void)

{
  T2CON = 6;
  T2 = 0;
  T3CON = 2;
  T3 = 0;
  T4CON = 1;
  T4 = 0;
  return;
}

