// c1c956 gap_c1c956 size=102 cc=unknown proto=undefined gap_c1c956(void)

undefined4 gap_c1c956(undefined2 param_1,undefined2 param_2,ushort param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar2 = CONCAT22(param_2,param_1);
  uVar1 = param_3 + 4;
  if ((*(byte *)(uint3)uVar1 & 0x7f) == 1) {
    if ((*(byte *)(uint3)uVar1 & 0x80) == 0) {
      uVar2 = CONCAT22(*(undefined2 *)(uint3)(param_3 + 2),*(undefined2 *)(uint3)param_3);
    }
    else {
      uVar2 = mul32();
    }
  }
  else if ((*(byte *)(uint3)uVar1 & 0x7f) == 2) {
    if ((*(byte *)(uint3)uVar1 & 0x80) == 0) {
      uVar2 = gap_c27738(*(undefined2 *)(uint3)param_3,*(undefined2 *)(uint3)(param_3 + 2));
    }
    else {
      uVar2 = gap_c288a8(*(undefined2 *)(uint3)param_3,*(undefined2 *)(uint3)(param_3 + 2));
    }
  }
  return uVar2;
}

