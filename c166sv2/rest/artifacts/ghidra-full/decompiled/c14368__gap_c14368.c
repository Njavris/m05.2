// c14368 gap_c14368 size=80 cc=unknown proto=undefined gap_c14368(void)

void gap_c14368(char param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  if (param_1 == '\x02') {
    uVar1 = PSW;
    uVar2 = PSW;
    uVar3 = PSW;
    PSW = uVar3 & 0xffbf | ((uVar2 & 8) >> 3 ^ 1) << 6;
    uVar1 = P3;
    uVar2 = PSW;
    uVar3 = P3;
    P3 = uVar3 & 0xffbf | uVar2 & 0x40;
  }
  else {
    if (param_1 == '\x03') {
      uVar1 = PSW;
      uVar2 = PSW;
      uVar3 = PSW;
      PSW = uVar3 & 0xffbf | ((uVar2 & 8) >> 3 ^ 1) << 6;
      uVar1 = P1H;
      uVar3 = PSW;
      uVar2 = P1H;
      P1H = uVar2 & 0xfffd | ((uVar3 & 0x40) >> 6) << 1;
      return;
    }
    if (param_1 == '\x04') {
      uVar1 = PSW;
      uVar2 = PSW;
      uVar3 = PSW;
      PSW = uVar3 & 0xffbf | ((uVar2 & 8) >> 3 ^ 1) << 6;
      uVar1 = P1H;
      uVar3 = PSW;
      uVar2 = P1H;
      P1H = uVar2 & 0xffdf | ((uVar3 & 0x40) >> 6) << 5;
      return;
    }
    if (param_1 == '\x06') {
      uVar1 = PSW;
      uVar2 = PSW;
      uVar3 = PSW;
      PSW = uVar3 & 0xffbf | ((uVar2 & 8) >> 3 ^ 1) << 6;
      uVar1 = P1L;
      uVar3 = PSW;
      uVar2 = P1L;
      P1L = uVar2 & 0xffbf | uVar3 & 0x40;
      return;
    }
  }
  return;
}

