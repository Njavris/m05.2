/* c0d528 event_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initialize event scheduler channels. */

void event_init(void)

{
  ushort uVar1;
  byte bVar2;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  capcom16_17_init();
  bVar2 = 0;
  do {
    capcom_event_config(bVar2,*(undefined1 *)(uint3)((short)&event_var_c390 + (ushort)bVar2 * 8),1);
    bVar2 = bVar2 + 1;
  } while (bVar2 < 2);
  event_var_c370 = 0;
  if (_event_var_c372 == 0) {
    event_start();
  }
  event_reset();
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


