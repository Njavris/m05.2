// c11c62 app_main_init size=76 cc=unknown proto=undefined app_main_init(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void app_main_init(void)

{
  ushort *puVar1;
  ushort uVar2;
  byte bVar3;
  
  if ((_DAT_007092 | _DAT_007090) != 0) {
    empty_stub_0(_DAT_007092 | _DAT_007090);
  }
  bVar3 = 0;
  do {
    puVar1 = (ushort *)((ushort)bVar3 * 6 + 0x7088);
    uVar2 = (ushort)bVar3;
    bVar3 = bVar3 + 1;
    *(undefined1 *)(uint3)((short)&DAT_00c54c + uVar2 * 2) =
         *(undefined1 *)(uint3)*(ushort *)ZEXT23(puVar1);
    *(undefined1 *)(uint3)((short)&DAT_00c54d + uVar2 * 2) = *(undefined1 *)(uint3)*puVar1;
  } while (bVar3 < 2);
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  uVar2 = P1H;
  P1H = uVar2 | 4;
  app_scheduler();
  return;
}

