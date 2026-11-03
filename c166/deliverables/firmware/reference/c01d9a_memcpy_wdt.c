/* c01d9a memcpy_wdt */

/* Byte copy with watchdog service. */

void memcpy_wdt(ushort param_1,ushort param_2,ushort param_3,ushort param_4,ushort unaff_00000000)

{
  bool bVar1;
  ushort uVar2;
  
  for (uVar2 = 0; uVar2 < unaff_00000000; uVar2 = uVar2 + 1) {
    *(undefined1 *)((uint3)param_1 + (uint3)param_2 * 0x10000) =
         *(undefined1 *)((uint3)param_3 + (uint3)param_4 * 0x10000);
    bVar1 = 0xfffe < param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + bVar1;
    bVar1 = 0xfffe < param_3;
    param_3 = param_3 + 1;
    param_4 = param_4 + bVar1;
    __service_watchdog();
  }
  return;
}


