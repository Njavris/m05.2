/* c0dba6 cc_compare_mode_set */

/* Sets the CC16/CC17 compare-mode bit for a channel ID. */

void cc_compare_mode_set(ushort param_1)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = *(char *)(uint3)((param_1 & 0xff) * 0x12 + 0xc41d);
  if (event_var_c40e != '\0') {
    if (cVar1 != '\x10') {
      uVar2 = DAT_00ff2c;
      DAT_00ff2c = uVar2 & 0xfffd;
      return;
    }
    uVar2 = DAT_00ff2c;
    DAT_00ff2c = uVar2 & 0xfffe;
    return;
  }
  if (cVar1 != '\x10') {
    uVar2 = DAT_00ff2c;
    DAT_00ff2c = uVar2 | 2;
    return;
  }
  uVar2 = DAT_00ff2c;
  DAT_00ff2c = uVar2 | 1;
  return;
}


