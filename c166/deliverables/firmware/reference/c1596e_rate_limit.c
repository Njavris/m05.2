/* c1596e rate_limit */

/* Rate limiter / slew helper. */

ushort rate_limit(ushort param_1,ushort param_2,ushort param_3)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = param_1;
  if ((param_2 != param_1) && (param_3 != 0)) {
    if (param_1 < param_2) {
      sVar1 = (short)((uint)(param_2 - param_1) * (uint)param_3 >> 0x10);
    }
    else {
      sVar1 = -(short)((uint)(param_1 - param_2) * (uint)param_3 >> 0x10);
    }
    uVar2 = param_1 + sVar1;
    if (uVar2 == param_1) {
      if (param_1 < param_2) {
        uVar2 = uVar2 + 1;
      }
      else {
        uVar2 = uVar2 - 1;
      }
    }
  }
  return uVar2;
}


