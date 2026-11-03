// c01d9a memcpy_wdt size=40 cc=unknown proto=undefined memcpy_wdt(void)

void memcpy_wdt(ushort param_1,ushort param_2,ushort unaff_00000000)

{
  ushort uVar1;
  
  for (uVar1 = 0; uVar1 < unaff_00000000; uVar1 = uVar1 + 1) {
    *(undefined1 *)(uint3)param_1 = *(undefined1 *)(uint3)param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    __service_watchdog();
  }
  return;
}

