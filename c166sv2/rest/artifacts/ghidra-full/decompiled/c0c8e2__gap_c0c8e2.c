// c0c8e2 gap_c0c8e2 size=50 cc=unknown proto=undefined gap_c0c8e2(void)

void gap_c0c8e2(void)

{
  ushort uVar1;
  byte bVar2;
  
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xfffe;
  DAT_00c2b2 = 0;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xffbf;
  T5 = 0;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xff7f;
  uVar1 = CC24IC;
  CC24IC = uVar1 | 0x40;
  uVar1 = DAT_00fd00;
  DAT_00fd00 = uVar1 & 0xdfff;
  uVar1 = DAT_00c2aa;
  DAT_00c2aa = uVar1 | 1;
  gap_c0d70a();
  return;
}

