// c28e50 fp_compare size=68 cc=unknown proto=undefined fp_compare(void)

ushort fp_compare(void)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort in_r10;
  ushort in_r11;
  
  uVar2 = *(ushort *)(uint3)in_r10;
  uVar3 = *(ushort *)(uint3)in_r11;
  if (((uVar2 | uVar3) & 0x7ff0) == 0) {
    return 0;
  }
  uVar4 = (short)uVar2 >> 0xf | 1;
  if ((!(bool)(((byte)(uVar2 >> 8) & 0x80 ^ (byte)(uVar3 >> 8) & 0x80) >> 7)) && (uVar2 <= uVar3)) {
    if (uVar3 <= uVar2) {
      uVar2 = *(ushort *)(uint3)(in_r10 + 2);
      bVar1 = *(ushort *)(in_r11 + 2) <= uVar2;
      if (uVar2 != *(ushort *)(in_r11 + 2) && bVar1) {
        return uVar4;
      }
      if (bVar1) {
        uVar2 = *(ushort *)(uint3)(in_r10 + 4);
        bVar1 = *(ushort *)(in_r11 + 4) <= uVar2;
        if (uVar2 != *(ushort *)(in_r11 + 4) && bVar1) {
          return uVar4;
        }
        if (bVar1) {
          uVar2 = *(ushort *)(uint3)(in_r10 + 6);
          bVar1 = *(ushort *)(in_r11 + 6) <= uVar2;
          if (uVar2 != *(ushort *)(in_r11 + 6) && bVar1) {
            return uVar4;
          }
          if (bVar1) {
            return 0;
          }
        }
      }
    }
    uVar4 = -uVar4;
  }
  return uVar4;
}

