// c03a04 gap_c03a04 size=18 cc=unknown proto=undefined gap_c03a04(void)

void gap_c03a04(void)

{
  ushort uVar1;
  
  uVar1 = P1L;
  P1L = uVar1 & 0xfffe | 1;
  __service_watchdog();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

