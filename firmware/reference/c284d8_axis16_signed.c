/* c284d8 axis16_signed */

/* Signed axis descriptor -> 8.8 fixed-point index. */

ushort axis16_signed(ushort param_1,short param_2)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(uint3)(param_1 + 2);
  uVar2 = (*(short *)(uint3)param_1 + -1) * 0x100;
  if (sVar1 < param_2) {
    if (param_2 < *(short *)(uint3)(param_1 + 4)) {
      uVar2 = (ushort)(((uint)(ushort)(param_2 - sVar1) * (uint)uVar2) /
                      (uint)(ushort)(*(short *)(uint3)(param_1 + 4) - sVar1));
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


