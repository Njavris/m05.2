// c0d39e event_start size=88 cc=unknown proto=undefined event_start(void)

void event_start(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  short sVar3;
  byte bVar4;
  
  sVar3 = t7_timestamp_extended();
  bVar4 = 0;
  do {
    uVar1 = DAT_00c374;
    uVar2 = DAT_00c37e;
    capcom_event_config2
              (bVar4,*(undefined2 *)(uint3)((short)&DAT_00c384 + (ushort)bVar4 * 4),
               *(undefined2 *)(uint3)((short)&DAT_00c386 + (ushort)bVar4 * 4),sVar3 + 4,uVar2,uVar1)
    ;
    *(undefined2 *)(uint3)((short)&DAT_00c416 + (ushort)bVar4 * 0x12) = 0;
    *(undefined2 *)(uint3)((short)&DAT_00c418 + (ushort)bVar4 * 0x12) = 0;
    bVar4 = bVar4 + 1;
  } while (bVar4 < 2);
  DAT_00c36e = 0;
  return;
}

