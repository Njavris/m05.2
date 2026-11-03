// c0f032 gap_c0f032 size=180 cc=unknown proto=undefined gap_c0f032(void)

/* WARNING: Removing unreachable block (ram,0xc0f0b2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c0f032(void)

{
  ushort uVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  undefined2 uVar5;
  short sVar6;
  
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xffdf;
  uVar5 = DAT_00c27e;
  DAT_00c466 = uVar5;
  DAT_00c3ee = uVar5;
  uVar1 = DAT_00fd06;
  if ((uVar1 & 0x2000) == 0) {
    uVar1 = DAT_00c266;
    uVar4 = Ram00c3f6;
    DAT_00c45c = uVar1;
    DAT_00c3e6 = (short)(((uint)uVar4 * (uint)uVar1 & 0x7fff80) / 0x780);
  }
  else {
    uVar5 = Ram00c3f6;
    uVar5 = FUN_c0e7ec(uVar5);
    DAT_00c3e6 = uVar5;
  }
  sVar6 = cc_irq_is_enabled(_DAT_007048);
  if ((sVar6 == 1) && (uVar1 = DAT_00fd06, (uVar1 & 0x10) != 0)) {
    sVar3 = DAT_00c3ee;
    sVar6 = DAT_00c3e6;
    FUN_c0fa2a(sVar3 + sVar6,1);
  }
  uVar1 = DAT_00fd06;
  DAT_00fd06 = uVar1 | 2;
  return;
}

