// c0d8fa gap_c0d8fa size=26 cc=unknown proto=undefined gap_c0d8fa(void)

void gap_c0d8fa(void)

{
  ushort uVar1;
  byte bVar2;
  undefined2 uVar3;
  
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xf7ff;
  uVar3 = CC24;
  Ram00c3b6 = uVar3;
  return;
}

