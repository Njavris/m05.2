// c0e894 FUN_c0e894 size=124 cc=unknown proto=undefined FUN_c0e894(void)

/* WARNING: Removing unreachable block (ram,0xc0e8ea) */

ushort FUN_c0e894(ushort param_1,ushort param_2,ushort param_3,ushort unaff_00000000)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  
  uVar2 = DAT_00c266;
  DAT_00c45c = uVar2;
  sVar1 = (param_1 & 0xff) * uVar2 + (short)(((uint)uVar2 * (uint)param_2 & 0x7fff80) / 0x780);
  *(short *)(uint3)unaff_00000000 = sVar1;
  sVar3 = DAT_00c452;
  sVar4 = DAT_00c466;
  *(short *)(uint3)param_3 = (sVar1 - sVar3) + sVar4;
  return (ushort)((uint)uVar2 * (uint)param_2 >> 0x17);
}

