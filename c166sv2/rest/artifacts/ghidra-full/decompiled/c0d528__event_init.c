// c0d528 event_init size=58 cc=unknown proto=undefined event_init(void)

void event_init(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  capcom16_17_init();
  bVar3 = 0;
  do {
    capcom_event_config(bVar3,*(undefined1 *)(uint3)((short)&DAT_00c390 + (ushort)bVar3 * 8),1);
    bVar3 = bVar3 + 1;
  } while (bVar3 < 2);
  DAT_00c370 = 0;
  sVar1 = DAT_00c372;
  if (sVar1 == 0) {
    event_start();
  }
  event_reset();
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return;
}

