// c0bab4 FUN_c0bab4 size=30 cc=unknown proto=undefined FUN_c0bab4(void)

void FUN_c0bab4(void)

{
  ushort uVar1;
  byte bVar2;
  
  FUN_c1ac7c();
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  DAT_00c1fa = 0;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xdfff;
  return;
}

