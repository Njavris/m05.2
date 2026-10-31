/* c11c62 app_main_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Application main initialization; enters scheduler. */

void app_main_init(void)

{
  ushort *puVar1;
  ushort uVar2;
  byte bVar3;
  
  if ((_scheduler_ext_1 | _scheduler_ext_0) != 0) {
    empty_stub_0(_scheduler_ext_1 | _scheduler_ext_0);
  }
  bVar3 = 0;
  do {
    puVar1 = (ushort *)((short)&scheduler_counter_table + (ushort)bVar3 * 6);
    uVar2 = (ushort)bVar3;
    bVar3 = bVar3 + 1;
    *(undefined1 *)(uint3)((short)&scheduler_counter + uVar2 * 2) =
         *(undefined1 *)(uint3)*(ushort *)ZEXT23(puVar1);
    *(undefined1 *)(uint3)(uVar2 * 2 + 0xc54d) = *(undefined1 *)(uint3)*puVar1;
  } while (bVar3 < 2);
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  uVar2 = P1H;
  P1H = uVar2 | 4;
  app_scheduler();
  return;
}


