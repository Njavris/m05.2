/* c2850e axis16_unsigned */

/* Unsigned axis descriptor -> 8.8 fixed-point index. */

ushort axis16_unsigned(ushort param_1,ushort param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *(ushort *)(uint3)(param_1 + 2);
  uVar2 = (*(short *)(uint3)param_1 + -1) * 0x100;
  if (uVar1 < param_2) {
    if (param_2 < *(ushort *)(uint3)(param_1 + 4)) {
      uVar2 = (ushort)(((uint)(param_2 - uVar1) * (uint)uVar2) /
                      (uint)(*(ushort *)(uint3)(param_1 + 4) - uVar1));
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


