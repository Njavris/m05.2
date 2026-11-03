// c143b8 gap_c143b8 size=44 cc=unknown proto=undefined gap_c143b8(void)

void gap_c143b8(char param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  if (param_1 == '\x02') {
    uVar1 = P3;
    uVar2 = P3;
    uVar3 = P3;
    P3 = uVar3 & 0xffbf | ((uVar2 & 0x40) >> 6 ^ 1) << 6;
  }
  else {
    if (param_1 == '\x03') {
      uVar1 = P1H;
      uVar2 = P1H;
      uVar3 = P1H;
      P1H = uVar3 & 0xfffd | ((uVar2 & 2) >> 1 ^ 1) << 1;
      return;
    }
    if (param_1 == '\x04') {
      uVar1 = P1H;
      uVar2 = P1H;
      uVar3 = P1H;
      P1H = uVar3 & 0xffdf | ((uVar2 & 0x20) >> 5 ^ 1) << 5;
      return;
    }
    if (param_1 == '\x06') {
      uVar1 = P1L;
      uVar2 = P1L;
      uVar3 = P1L;
      P1L = uVar3 & 0xffbf | ((uVar2 & 0x40) >> 6 ^ 1) << 6;
      return;
    }
  }
  return;
}

