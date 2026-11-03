// c0e6b0 FUN_c0e6b0 size=114 cc=unknown proto=undefined FUN_c0e6b0(void)

void FUN_c0e6b0(short param_1)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  if (param_1 == 0) {
    uVar3 = (ushort)&DAT_00fd08;
  }
  else {
    uVar3 = (ushort)&DAT_00fd06;
  }
  uVar2 = DAT_00c474;
  uVar2 = FUN_c0e606(uVar2);
  DAT_00c464 = uVar2;
  uVar2 = DAT_00c474;
  uVar2 = FUN_c0e62c(uVar2);
  DAT_00c44a = uVar2;
  FUN_c0e652();
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xf0ff;
  sVar1 = DAT_00c454;
  if (sVar1 == 0) {
    *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xf7ff | 0x800;
  }
  else if (sVar1 == 1) {
    *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfbff | 0x400;
  }
  else if (sVar1 == 2) {
    *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfdff | 0x200;
  }
  else if (sVar1 == 3) {
    *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfeff | 0x100;
  }
  return;
}

