// c0fa8e FUN_c0fa8e size=10 cc=unknown proto=undefined FUN_c0fa8e(void)

void FUN_c0fa8e(void)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar2 = DAT_00fd10;
  if ((uVar2 & 4) == 0) {
    uVar1 = DAT_00fd08;
    uVar3 = DAT_00fd1a;
    uVar2 = DAT_00fd08;
    DAT_00fd08 = uVar2 & 0x7fff | ((uVar3 & 0x20) >> 5) << 0xf;
  }
  return;
}

