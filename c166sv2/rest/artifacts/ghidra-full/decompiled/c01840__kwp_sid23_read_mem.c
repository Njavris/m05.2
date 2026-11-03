// c01840 kwp_sid23_read_mem size=204 cc=unknown proto=undefined kwp_sid23_read_mem(void)

short kwp_sid23_read_mem(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  short sVar7;
  ushort uVar8;
  ushort uVar9;
  
  bVar6 = DAT_00c14c;
  uVar2 = (ushort)bVar6;
  bVar4 = DAT_00c149;
  bVar5 = DAT_00c14a;
  uVar3 = (ushort)bVar5;
  bVar5 = DAT_00c14b;
  uVar8 = uVar3 * 0x100 + (ushort)bVar5;
  uVar3 = ((ushort)CARRY2((ushort)bVar4 * 0x100,uVar3) * 0x100 | (ushort)bVar4 * 0x100 + uVar3 >> 8)
          + (ushort)CARRY2(uVar3 * 0x100,(ushort)bVar5);
  uVar9 = uVar8 & 0x3fff;
  sVar7 = (short)&T2CON + uVar3;
  if ((((0xbf < uVar3) &&
       (sVar7 = 0, uVar1 = uVar3 + CARRY2(uVar8,uVar2),
       uVar1 == 0xc4 && uVar8 + uVar2 == 0 || uVar1 < 0xc4)) ||
      ((0xdf < uVar3 &&
       (uVar1 = uVar8 + uVar2, uVar3 = uVar3 + CARRY2(uVar8,uVar2),
       (short)&T78CON + uVar3 == (ushort)(uVar1 < 0x1800) && uVar1 == 0x1800 ||
       (uVar3 < 0xe0 || uVar3 == 0xe0 && uVar1 < 0x1800))))) && (uVar2 < 0x81)) {
    for (uVar8 = 1; uVar8 <= uVar2; uVar8 = uVar8 + 1) {
      uVar3 = uVar9 & 0x3fff;
      uVar9 = uVar9 + 1;
      *(undefined1 *)(uint3)(uVar8 + 0xb6 & 0x3fff) = *(undefined1 *)(uint3)uVar3;
    }
    DAT_00c0b5 = bVar6 + 1;
    DAT_00c0b6 = 99;
    return sVar7;
  }
  DAT_00c0b5 = 3;
  DAT_00c0b6 = 0x7f;
  DAT_00c0b7 = 0x23;
  DAT_00c0b8 = 0x12;
  return CONCAT11((char)((ushort)sVar7 >> 8),0x12);
}

