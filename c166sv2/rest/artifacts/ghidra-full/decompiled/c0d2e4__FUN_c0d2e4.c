// c0d2e4 FUN_c0d2e4 size=48 cc=unknown proto=undefined FUN_c0d2e4(void)

undefined2 FUN_c0d2e4(short param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_00c2ba;
  uVar2 = div32u(0,uVar1,-0x4c00 - param_1);
  uVar1 = mul32((short)uVar2,(short)((uint)uVar2 >> 0x10));
  return uVar1;
}

