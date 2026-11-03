// c276f0 gap_c276f0 size=72 cc=unknown proto=undefined gap_c276f0(void)

ushort gap_c276f0(ushort param_1,ushort param_2)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar3 = param_1 + param_2;
  sVar1 = ((short)param_1 >> 0xf) + ((short)param_2 >> 0xf) + (ushort)CARRY2(param_1,param_2);
  if (sVar1 < (short)(ushort)(uVar3 < 0x7fff)) {
    uVar2 = (ushort)(uVar3 < 0x8000);
    if (sVar1 + 1U == uVar2 && uVar3 == 0x8000 ||
        (short)((sVar1 + 1U) - uVar2) < 0 !=
        (SBORROW2(sVar1,-1) != SBORROW2(sVar1 + 1,(ushort)(uVar3 < 0x8000)))) {
      uVar3 = 0x8000;
    }
  }
  else {
    uVar3 = 0x7fff;
  }
  return uVar3;
}

