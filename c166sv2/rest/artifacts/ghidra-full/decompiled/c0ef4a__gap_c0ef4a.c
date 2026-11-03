// c0ef4a gap_c0ef4a size=232 cc=unknown proto=undefined gap_c0ef4a(void)

/* WARNING: Removing unreachable block (ram,0xc0efca) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c0ef4a(void)

{
  ushort uVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  undefined2 uVar6;
  short sVar7;
  
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xffef;
  uVar6 = DAT_00c27e;
  DAT_00c466 = uVar6;
  DAT_00c3d4 = uVar6;
  uVar1 = DAT_00fd08;
  if ((uVar1 & 0x2000) == 0) {
    uVar1 = DAT_00c266;
    uVar4 = Ram00c3dc;
    DAT_00c45c = uVar1;
    DAT_00c3cc = (short)(((uint)uVar4 * (uint)uVar1 & 0x7fff80) / 0x780);
  }
  else {
    uVar6 = Ram00c3dc;
    uVar6 = FUN_c0e7ec(uVar6);
    DAT_00c3cc = uVar6;
  }
  sVar7 = cc_irq_is_enabled(_DAT_007046);
  if ((sVar7 == 1) && (uVar1 = DAT_00fd08, (uVar1 & 0x10) != 0)) {
    sVar3 = DAT_00c3d4;
    sVar7 = DAT_00c3cc;
    FUN_c0fa2a(0);
    sVar5 = DAT_00c44c;
    if (sVar5 == 1) {
      FUN_c0fa2a(sVar3 + sVar7,1);
    }
  }
  uVar1 = DAT_00fd08;
  DAT_00fd08 = uVar1 | 2;
  sVar7 = DAT_00c44c;
  if (sVar7 == 1) {
    uVar6 = Ram00c3ca;
    Ram00c3e4 = uVar6;
    uVar6 = DAT_00c3cc;
    DAT_00c3e6 = uVar6;
    uVar6 = DAT_00c3d4;
    DAT_00c3ee = uVar6;
    uVar1 = DAT_00fd06;
    DAT_00fd06 = uVar1 | 2;
  }
  return;
}

