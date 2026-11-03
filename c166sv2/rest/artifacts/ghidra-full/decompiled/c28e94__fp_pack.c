// c28e94 fp_pack size=62 cc=unknown proto=undefined fp_pack(void)

undefined4 fp_pack(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort in_r4;
  undefined2 unaff_r6;
  undefined2 unaff_r7;
  undefined2 unaff_r8;
  undefined2 unaff_r9;
  ushort in_r10;
  ushort in_r11;
  
  *(undefined2 *)(uint3)(in_r11 + 6) = param_3;
  *(undefined2 *)(uint3)(in_r11 + 4) = param_2;
  *(undefined2 *)(uint3)(in_r11 + 2) = param_1;
  uVar1 = *(ushort *)(uint3)in_r11;
  *(undefined2 *)(uint3)in_r11 = unaff_r6;
  uVar3 = PSW;
  uVar3 = *(undefined2 *)(uint3)(in_r10 + 6);
  *(undefined2 *)(uint3)(in_r10 + 6) = 1;
  *(undefined2 *)(uint3)(in_r10 + 4) = unaff_r9;
  *(undefined2 *)(uint3)(in_r10 + 2) = unaff_r8;
  uVar2 = *(ushort *)(uint3)in_r10;
  *(undefined2 *)(uint3)in_r10 = unaff_r7;
  uVar4 = PSW;
  return CONCAT22(uVar3,in_r4 & 0xfffc | (uVar1 >> 0xf) << 1 | uVar2 >> 0xf);
}

