// c1145c gap_c1145c size=110 cc=unknown proto=undefined gap_c1145c(void)

bool gap_c1145c(short param_1)

{
  short sVar1;
  
  func_0xc1128a();
  sVar1 = func_0xc114ca(*(undefined2 *)(uint3)(param_1 + 0x18),
                        *(undefined2 *)(uint3)(param_1 + 0x1a),
                        *(undefined2 *)(uint3)(param_1 + 0x3a));
  if (sVar1 == 0) {
    *(undefined2 *)(uint3)(param_1 + 0x30) = 0;
    *(ushort *)(uint3)(param_1 + 0x32) = *(ushort *)(uint3)(param_1 + 0x18) + 4;
    *(ushort *)(uint3)(param_1 + 0x34) =
         *(short *)(uint3)(param_1 + 0x1a) + (ushort)(0xfffb < *(ushort *)(uint3)(param_1 + 0x18));
    *(undefined2 *)(uint3)(param_1 + 0x36) = 0xaa55;
    *(undefined2 *)(uint3)(param_1 + 0x38) = 0;
    *(undefined2 *)(uint3)(param_1 + 0x2c) = 0;
    *(undefined2 *)(uint3)(param_1 + 0x2e) = 0;
    *(undefined2 *)(uint3)(param_1 + 0x24) =
         *(undefined2 *)(uint3)(*(short *)(uint3)(param_1 + 0x3a) * 8 + 0x7050);
    *(undefined2 *)(uint3)(param_1 + 0x26) = 0;
  }
  return sVar1 == 0;
}

