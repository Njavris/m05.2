// c0faf8 FUN_c0faf8 size=62 cc=unknown proto=undefined FUN_c0faf8(void)

undefined2 FUN_c0faf8(short param_1)

{
  char cVar1;
  ushort uVar2;
  undefined2 uVar3;
  
  uVar3 = 0;
  cVar1 = DAT_00c456;
  if ((cVar1 == '\x03') || (cVar1 == '\x04')) {
    if (param_1 == 0) {
      uVar2 = CC23IC;
      CC23IC = uVar2 | 0x40;
    }
    else if (param_1 == 1) {
      uVar2 = CC22IC;
      CC22IC = uVar2 | 0x40;
    }
    uVar3 = 1;
    cVar1 = DAT_00c456;
    DAT_00c456 = cVar1 + '\x01';
  }
  cVar1 = DAT_00c456;
  if (cVar1 == '\x05') {
    DAT_00c456 = 0;
  }
  return uVar3;
}

