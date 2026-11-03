// c0170a kwp_sid36_transfer size=158 cc=unknown proto=undefined kwp_sid36_transfer(void)

ushort kwp_sid36_transfer(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  ushort uVar8;
  ushort uVar9;
  
  cVar7 = DAT_00c09a;
  if (cVar7 == '\x01') {
    bVar4 = DAT_00c149;
    bVar5 = DAT_00c14a;
    uVar3 = (ushort)bVar5 * 0x100;
    bVar6 = DAT_00c14b;
    uVar1 = uVar3 + bVar6;
    cVar7 = '\0';
    uVar8 = 0;
    uVar9 = uVar1 & 0x3fff;
    do {
      uVar2 = (short)&DAT_00c14c + uVar8;
      *(undefined1 *)(uint3)(uVar9 & 0x3fff) = *(undefined1 *)(uint3)uVar2;
      cVar7 = cVar7 + *(char *)(uint3)(uVar2 & 0x3fff);
      uVar8 = uVar8 + 1;
      uVar9 = uVar9 + 1;
    } while (uVar8 < 0x80);
    DAT_00c0b5 = 2;
    DAT_00c0b6 = 0x76;
    DAT_00c0b7 = cVar7;
    return (((ushort)bVar4 * 0x100 + (ushort)bVar5 >> 8) + (ushort)CARRY2(uVar3,(ushort)bVar6)) * 4
           | uVar1 >> 0xe;
  }
  DAT_00c0b5 = 3;
  DAT_00c0b6 = 0x7f;
  DAT_00c0b7 = 0x36;
  DAT_00c0b8 = 0xbd;
  return 0xbd;
}

