// c0210a boot_hidden_memcpy size=40 cc=unknown proto=undefined boot_hidden_memcpy(void)

void boot_hidden_memcpy(ushort param_1,ushort param_2,byte unaff_00000000)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < unaff_00000000; bVar1 = bVar1 + 1) {
    *(undefined1 *)(uint3)param_1 = *(undefined1 *)(uint3)param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    __service_watchdog();
  }
  return;
}

