// c0d296 FUN_c0d296 size=78 cc=unknown proto=undefined FUN_c0d296(void)

void FUN_c0d296(void)

{
  ushort uVar1;
  char cVar2;
  
  DAT_00c20c = 0x1f16;
  DAT_00c20e = 0xc1;
  cVar2 = DAT_00c92f;
  if (cVar2 == '\0') {
    uVar1 = (short)&DAT_00c282 + (ushort)DAT_c05085 * 2;
    *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xbfff | 0x4000;
    return;
  }
  uVar1 = (short)&DAT_00c282 + (ushort)DAT_c05084 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xbfff | 0x4000;
  return;
}

