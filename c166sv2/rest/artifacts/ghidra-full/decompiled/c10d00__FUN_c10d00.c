// c10d00 FUN_c10d00 size=24 cc=unknown proto=undefined FUN_c10d00(void)

undefined2 FUN_c10d00(void)

{
  ushort uVar1;
  
  __service_watchdog();
  do {
    uVar1 = DAT_00f000;
  } while ((uVar1 & 1) != 0);
  return 0;
}

