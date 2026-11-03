// c0dba6 cc_compare_mode_set size=56 cc=unknown proto=undefined cc_compare_mode_set(void)

void cc_compare_mode_set(ushort param_1)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  
  cVar1 = *(char *)(uint3)((short)&UNK_00c41d + (param_1 & 0xff) * 0x12);
  cVar2 = DAT_00c40e;
  if (cVar2 != '\0') {
    if (cVar1 != '\x10') {
      uVar3 = DAT_00ff2c;
      DAT_00ff2c = uVar3 & 0xfffd;
      return;
    }
    uVar3 = DAT_00ff2c;
    DAT_00ff2c = uVar3 & 0xfffe;
    return;
  }
  if (cVar1 != '\x10') {
    uVar3 = DAT_00ff2c;
    DAT_00ff2c = uVar3 | 2;
    return;
  }
  uVar3 = DAT_00ff2c;
  DAT_00ff2c = uVar3 | 1;
  return;
}

