// c28860 gap_c28860 size=72 cc=unknown proto=undefined gap_c28860(void)

ushort gap_c28860(ushort param_1,ushort param_2)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  
  uVar3 = param_1 - param_2;
  sVar2 = (((short)param_1 >> 0xf) - ((short)param_2 >> 0xf)) - (ushort)(param_1 < param_2);
  if (sVar2 < (short)(ushort)(uVar3 < 0x7fff)) {
    uVar1 = (ushort)(uVar3 < 0x8000);
    if (sVar2 + 1U == uVar1 && uVar3 == 0x8000 ||
        (short)((sVar2 + 1U) - uVar1) < 0 !=
        (SBORROW2(sVar2,-1) != SBORROW2(sVar2 + 1,(ushort)(uVar3 < 0x8000)))) {
      uVar3 = 0x8000;
    }
  }
  else {
    uVar3 = 0x7fff;
  }
  return uVar3;
}

