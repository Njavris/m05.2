// c1aedc gap_c1aedc size=280 cc=unknown proto=undefined gap_c1aedc(void)

/* WARNING: Removing unreachable block (ram,0xc1afb2) */

char gap_c1aedc(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  ushort uVar7;
  short sVar8;
  char cVar9;
  undefined2 uVar10;
  ushort uVar11;
  
  cVar5 = DAT_00c784;
  cVar4 = DAT_00c780;
  uVar11 = DAT_00c9d0;
  bVar1 = uRamc06c68 <= uVar11;
  uVar11 = DAT_00c9d0;
  bVar3 = uVar11 <= uRamc06c6a;
  sVar8 = Ram00ca26;
  bVar2 = sRamc0709e <= sVar8;
  cVar6 = UNK_00c9ba;
  uVar10 = DAT_00c9d0;
  uVar10 = axis16_unsigned(0x74e0,uVar10);
  uVar11 = tbl8_interp(0x6c20,0xc0,uVar10);
  cVar9 = DAT_00c954;
  if ((((((cVar9 == '\0') || (cVar5 != '\0')) || (cVar4 != '\0')) ||
       (((bVar1 || (bVar3)) || ((bVar2 || (uVar7 = Ram00ca1c, uVar7 <= uVar11)))))) ||
      ((cVar6 == '\0' && (uVar11 = Ram00c9ca, uRamc06c6c <= uVar11)))) ||
     ((DAT_c06b69 == '\0' &&
      ((((cVar9 = FUN_c243a8(0xb), cVar9 != '\0' || (cVar9 = FUN_c243a8(0xc), cVar9 != '\0')) ||
        (cVar9 = FUN_c243a8(0x12), cVar9 != '\0')) || (cVar9 = FUN_c243a8(0x13), cVar9 != '\0'))))))
  {
    DAT_00c92b = 0;
  }
  else {
    DAT_00c92b = 1;
  }
  return cVar9;
}

