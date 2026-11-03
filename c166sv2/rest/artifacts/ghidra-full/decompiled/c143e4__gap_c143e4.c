// c143e4 gap_c143e4 size=190 cc=unknown proto=undefined gap_c143e4(void)

ushort gap_c143e4(char param_1,short param_2)

{
  byte bVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  if (param_1 == '\x06') {
    if (param_2 == 3) {
      uVar2 = DAT_00c4b6;
      bVar1 = (byte)uVar2;
    }
    else {
      if (param_2 != 1) {
        if (param_2 == 2) {
          uVar3 = Ram00c4ae;
          return uVar3 >> 4 & 1;
        }
        if (param_2 == 0) {
          uVar3 = Ram00c4ac;
          return uVar3 >> 4 & 1;
        }
        uVar3 = Ram00c4ae;
        if (((uVar3 & 0x10) == 0) && (uVar3 = Ram00c4ac, (uVar3 & 0x10) == 0)) {
          return 0;
        }
        return 1;
      }
      uVar2 = DAT_00c49c;
      bVar1 = (byte)uVar2;
    }
    if ((bVar1 & 8) != 8) {
      return 0;
    }
  }
  else {
    if (param_1 != '\x05') {
      return 0;
    }
    if ((param_2 != 3) && (param_2 != 1)) {
      if (param_2 == 2) {
        uVar3 = Ram00c4b2;
        return uVar3 >> 4 & 1;
      }
      if (param_2 == 0) {
        uVar3 = Ram00c4b0;
        return uVar3 >> 0xc & 1;
      }
      uVar3 = Ram00c4b2;
      if (((uVar3 & 0x10) == 0) && (uVar3 = Ram00c4b0, (uVar3 & 0x1000) == 0)) {
        return 0;
      }
      return 1;
    }
  }
  return 1;
}

