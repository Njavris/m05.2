// c0190c kwp_sid3D_write_mem size=200 cc=unknown proto=undefined kwp_sid3D_write_mem(void)

void kwp_sid3D_write_mem(void)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  ushort uVar6;
  ushort uVar7;
  
  bVar3 = DAT_00c14c;
  uVar2 = (ushort)bVar3;
  bVar3 = DAT_00c149;
  bVar5 = DAT_00c14a;
  uVar6 = (ushort)bVar5;
  bVar5 = DAT_00c14b;
  uVar7 = uVar6 * 0x100 + (ushort)bVar5;
  uVar6 = ((ushort)CARRY2((ushort)bVar3 * 0x100,uVar6) * 0x100 | (ushort)bVar3 * 0x100 + uVar6 >> 8)
          + (ushort)CARRY2(uVar6 * 0x100,(ushort)bVar5);
  if (((0xdf < uVar6) &&
      (uVar1 = uVar7 + uVar2, uVar6 = uVar6 + CARRY2(uVar7,uVar2),
      (short)&T78CON + uVar6 == (ushort)(uVar1 < 0x1800) && uVar1 == 0x1800 ||
      (uVar6 < 0xe0 || uVar6 == 0xe0 && uVar1 < 0x1800))) && (uVar2 < 0x81)) {
    uVar7 = uVar7 & 0x3fff;
    for (uVar6 = 1; uVar6 <= uVar2; uVar6 = uVar6 + 1) {
      *(undefined1 *)(uint3)(uVar7 & 0x3fff) = *(undefined1 *)(uint3)((short)&DAT_00c14c + uVar6);
      uVar7 = uVar7 + 1;
    }
    DAT_00c0b5 = 4;
    DAT_00c0b6 = 0x7d;
    uVar4 = DAT_00c149;
    DAT_00c0b7 = uVar4;
    uVar4 = DAT_00c14a;
    DAT_00c0b8 = uVar4;
    uVar4 = DAT_00c14b;
    DAT_00c0b9 = uVar4;
    return;
  }
  DAT_00c0b5 = 3;
  DAT_00c0b6 = 0x7f;
  DAT_00c0b7 = 0x3d;
  DAT_00c0b8 = 0x12;
  return;
}

