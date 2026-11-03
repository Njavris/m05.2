// c0fa98 FUN_c0fa98 size=10 cc=unknown proto=undefined FUN_c0fa98(void)

void FUN_c0fa98(void)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar2 = DAT_00fd0c;
  if ((uVar2 & 4) == 0) {
    uVar1 = DAT_00fd06;
    uVar3 = DAT_00fd1a;
    uVar2 = DAT_00fd06;
    DAT_00fd06 = uVar2 & 0x7fff | ((uVar3 & 0x10) >> 4) << 0xf;
  }
  return;
}

