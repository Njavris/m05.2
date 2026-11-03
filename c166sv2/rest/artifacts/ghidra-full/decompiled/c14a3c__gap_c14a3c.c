// c14a3c gap_c14a3c size=262 cc=unknown proto=undefined gap_c14a3c(void)

ushort gap_c14a3c(short param_1,short param_2)

{
  ushort uVar1;
  
  uVar1 = 0;
  if ((param_2 == 3) || (param_2 == 1)) {
    uVar1 = 1;
  }
  else if (param_1 == 0) {
    if (param_2 == 2) {
      uVar1 = Ram00c4ae;
      uVar1 = uVar1 >> 0xd & 1;
    }
    else if (param_2 == 0) {
      uVar1 = Ram00c4ac;
      uVar1 = uVar1 >> 0xd & 1;
    }
    else {
      uVar1 = Ram00c4ae;
      if (((uVar1 & 0x2000) == 0) && (uVar1 = Ram00c4ac, (uVar1 & 0x2000) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else if (param_1 == 1) {
    if (param_2 == 2) {
      uVar1 = Ram00c4ae;
      uVar1 = uVar1 >> 8 & 1;
    }
    else if (param_2 == 0) {
      uVar1 = Ram00c4ac;
      uVar1 = uVar1 >> 8 & 1;
    }
    else {
      uVar1 = Ram00c4ae;
      if (((uVar1 & 0x100) == 0) && (uVar1 = Ram00c4ac, (uVar1 & 0x100) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else if (param_1 == 2) {
    if (param_2 == 2) {
      uVar1 = Ram00c4ae;
      uVar1 = uVar1 >> 7 & 1;
    }
    else if (param_2 == 0) {
      uVar1 = Ram00c4ac;
      uVar1 = uVar1 >> 7 & 1;
    }
    else {
      uVar1 = Ram00c4ae;
      if (((uVar1 & 0x80) == 0) && (uVar1 = Ram00c4ac, (uVar1 & 0x80) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else if (param_1 == 3) {
    if (param_2 == 2) {
      uVar1 = Ram00c4ae;
      uVar1 = uVar1 >> 6 & 1;
    }
    else if (param_2 == 0) {
      uVar1 = Ram00c4ac;
      uVar1 = uVar1 >> 6 & 1;
    }
    else {
      uVar1 = Ram00c4ae;
      if (((uVar1 & 0x40) == 0) && (uVar1 = Ram00c4ac, (uVar1 & 0x40) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}

