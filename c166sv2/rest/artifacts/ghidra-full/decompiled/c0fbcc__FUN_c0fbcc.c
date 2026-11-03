// c0fbcc FUN_c0fbcc size=118 cc=unknown proto=undefined FUN_c0fbcc(void)

void FUN_c0fbcc(short param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  
  FUN_c0e6b0();
  uVar1 = DAT_00c26e;
  DAT_00c458 = uVar1;
  if (param_1 == 0) {
    uVar2 = (ushort)&DAT_00fd08;
  }
  else {
    uVar2 = (ushort)&DAT_00fd06;
  }
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xfffd;
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xfffe;
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xffdf;
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xffef;
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xfffb;
  *(undefined1 *)(uint3)(ushort)((short)&DAT_00c3da + param_1 * 0x1a) = 0;
  *(undefined1 *)(uint3)(ushort)((short)&DAT_00c3d9 + param_1 * 0x1a) = 0;
  FUN_c0fd82();
  return;
}

