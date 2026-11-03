// c0f55a FUN_c0f55a size=206 cc=unknown proto=undefined FUN_c0f55a(void)

void FUN_c0f55a(short param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  FUN_c0e6b0();
  uVar2 = DAT_00c26e;
  DAT_00c458 = uVar2;
  if (param_1 == 0) {
    FUN_c0fa8e(0);
    uVar3 = (ushort)&DAT_00fd08;
    uVar1 = DAT_00fd0a;
    uVar1 = uVar1 >> 1;
  }
  else {
    FUN_c0fa98();
    uVar3 = (ushort)&DAT_00fd06;
    uVar1 = DAT_00fd0a;
  }
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfffd;
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfffe;
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xffdf;
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xffef;
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfffb;
  if ((*(ushort *)(uint3)uVar3 & 0x800) == 0) {
    if (((uVar1 & 1) == 0) && ((*(ushort *)(uint3)uVar3 & 0x8000) != 0)) {
      FUN_c0f482(param_1);
      goto LAB_c0f620;
    }
  }
  else if (param_1 == 0) {
    uVar1 = CC23IC;
    CC23IC = uVar1 & 0xffbf;
  }
  else if (param_1 == 1) {
    uVar1 = CC22IC;
    CC22IC = uVar1 & 0xffbf;
  }
  *(undefined1 *)(uint3)(ushort)((short)&DAT_00c3da + param_1 * 0x1a) = 0;
  *(undefined1 *)(uint3)(ushort)((short)&DAT_00c3d9 + param_1 * 0x1a) = 0;
LAB_c0f620:
  FUN_c0fd82();
  return;
}

