// c201ae calc_limit2 size=320 cc=unknown proto=undefined calc_limit2(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void calc_limit2(void)

{
  ushort uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  
  if (DAT_e0085b != '\0') {
    _DAT_e008b0 = 0;
    _DAT_e008aa = 0;
    return;
  }
  cVar2 = DAT_00c93c;
  if (cVar2 == '\x03') {
    cVar2 = DAT_00c93c;
    if (((cVar2 == '\x03') && (DAT_00c885 = 1, 0x80 < _DAT_e008aa)) &&
       (uVar1 = DAT_00c86c, DAT_c07834 <= uVar1)) {
      DAT_00c885 = 0;
      DAT_00c86c = 0;
      _DAT_e008aa = (ushort)((uint)_DAT_e008aa * (uint)DAT_c07830 >> 0x10);
      if (_DAT_e008aa < 0x81) {
        _DAT_e008aa = 0;
      }
    }
  }
  else {
    DAT_00c885 = 0;
    DAT_00c86c = 0;
    uVar4 = DAT_00c97c;
    _DAT_e008aa = tbl8_interp(0x7860,0xc0,uVar4);
  }
  cVar2 = DAT_00c93c;
  if (cVar2 != '\x03') {
    DAT_00c86a = 0;
    _DAT_e008b0 = 0;
    return;
  }
  uVar3 = DAT_00c9d0;
  uVar1 = DAT_00c86a;
  if ((uVar3 < DAT_c0781e) || (DAT_00c884 = 1, uVar1 < DAT_c07832)) {
    DAT_e008a2 = '\0';
  }
  else {
    DAT_00c884 = 0;
    DAT_e008a2 = '\x01';
  }
  uVar4 = DAT_c0783c;
  if (DAT_e008a2 != '\0') {
    uVar4 = DAT_00c958;
  }
  uVar4 = axis16_unsigned(0x7510,uVar4);
  _DAT_e008b0 = tbl8_interp(0x784c,0xc0,uVar4);
  return;
}

