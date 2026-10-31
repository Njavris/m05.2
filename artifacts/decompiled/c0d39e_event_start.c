/* c0d39e event_start */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Start event scheduler channels. */

void event_start(void)

{
  short sVar1;
  byte bVar2;
  
  sVar1 = t7_timestamp_extended();
  bVar2 = 0;
  do {
    capcom_event_config2
              (bVar2,*(undefined2 *)(uint3)((short)&event_var_c384 + (ushort)bVar2 * 4),
               *(undefined2 *)(uint3)((short)&event_var_c386 + (ushort)bVar2 * 4),sVar1 + 4,
               _event_var_c37e,_event_var_c374);
    *(undefined2 *)(uint3)((ushort)bVar2 * 0x12 + 0xc416) = 0;
    *(undefined2 *)(uint3)((ushort)bVar2 * 0x12 + 0xc418) = 0;
    bVar2 = bVar2 + 1;
  } while (bVar2 < 2);
  _event_var_c36e = 0;
  return;
}


