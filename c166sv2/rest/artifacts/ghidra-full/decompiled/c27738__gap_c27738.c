// c27738 gap_c27738 size=28 cc=unknown proto=undefined gap_c27738(void)

undefined4 gap_c27738(ushort param_1,short param_2,ushort param_3,ushort param_4)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = param_1 + param_3;
  uVar2 = param_2 + param_4 + (ushort)CARRY2(param_1,param_3);
  if (uVar2 < param_4 || uVar2 == param_4 && uVar1 < param_3) {
    uVar1 = 0xffff;
    uVar2 = 0xffff;
  }
  return CONCAT22(uVar2,uVar1);
}

