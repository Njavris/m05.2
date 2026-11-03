// c10fe8 gap_c10fe8 size=118 cc=unknown proto=undefined gap_c10fe8(void)

bool gap_c10fe8(short param_1,short param_2,undefined2 param_3)

{
  short sVar1;
  short sVar2;
  
  sVar1 = 0;
  if (*(ushort *)(uint3)(param_1 + 0x2c) <=
      *(short *)(uint3)(*(short *)(uint3)(param_1 + 0x3a) * 8 + 0x7050) - 0x80U) {
    sVar1 = func_0xc10e44(*(undefined2 *)(uint3)(param_1 + 0x32),
                          *(undefined2 *)(uint3)(param_1 + 0x34),param_2,param_3);
    for (sVar2 = 0; sVar2 < 0x80; sVar2 = sVar2 + 1) {
      *(undefined1 *)(uint3)(ushort)(param_2 + sVar2) = 0;
    }
  }
  if (sVar1 == 0) {
    sVar1 = func_0xc10f06(param_1);
  }
  return sVar1 == 0;
}

