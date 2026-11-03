// c14d36 gap_c14d36 size=514 cc=unknown proto=undefined gap_c14d36(void)

/* WARNING: Type propagation algorithm not settling */

ushort gap_c14d36(char param_1,short param_2)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  
  if (((param_2 == 3) || (param_2 == 1)) &&
     ((param_1 == '\0' || (((param_1 == '\x05' || (param_1 == '\x06')) || (param_1 == '\x01')))))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || ((param_2 != 3 && (param_2 != 1)))) {
    if (!bVar1) {
      if (param_1 == '\0') {
        if (param_2 == 2) {
          uVar2 = Ram00c4ae;
          return uVar2 & 1;
        }
        if (param_2 == 0) {
          uVar2 = Ram00c4ac;
          return uVar2 & 1;
        }
        uVar2 = Ram00c4ae;
        if (((uVar2 & 1) == 0) && (uVar2 = Ram00c4ac, (uVar2 & 1) == 0)) {
          return 0;
        }
        return 1;
      }
      if (param_1 == '\x01') {
        if (param_2 == 2) {
          uVar2 = Ram00c4ae;
          return uVar2 >> 2 & 1;
        }
        if (param_2 == 0) {
          uVar2 = Ram00c4ac;
          return uVar2 >> 2 & 1;
        }
        uVar2 = Ram00c4ae;
        if (((uVar2 & 4) == 0) && (uVar2 = Ram00c4ac, (uVar2 & 4) == 0)) {
          return 0;
        }
        return 1;
      }
      if (param_1 == '\x05') {
        if (param_2 == 2) {
          uVar2 = Ram00c4ae;
          return uVar2 >> 5 & 1;
        }
        if (param_2 == 0) {
          uVar2 = Ram00c4ac;
          return uVar2 >> 5 & 1;
        }
        uVar2 = Ram00c4ae;
        if (((uVar2 & 0x20) == 0) && (uVar2 = Ram00c4ac, (uVar2 & 0x20) == 0)) {
          return 0;
        }
        return 1;
      }
      if (param_1 != '\x06') {
        return 0;
      }
      if (param_2 == 2) {
        uVar2 = Ram00c4ae;
        return uVar2 >> 3 & 1;
      }
      if (param_2 == 0) {
        uVar2 = Ram00c4ac;
        return uVar2 >> 3 & 1;
      }
      uVar2 = Ram00c4ae;
      if (((uVar2 & 8) == 0) && (uVar2 = Ram00c4ac, (uVar2 & 8) == 0)) {
        return 0;
      }
      return 1;
    }
    if (param_1 == '\0') {
      sVar3 = Ram00c98c;
      if (sVar3 == -0x8000) {
        sVar3 = 2;
      }
      else {
        sVar3 = Ram00c98c;
        if (sVar3 == 0) {
          sVar3 = 1;
        }
        else {
          sVar3 = 0;
        }
      }
    }
    else if (param_1 == '\x01') {
      sVar3 = Ram00c990;
      if (sVar3 == -0x8000) {
        sVar3 = 2;
      }
      else {
        sVar3 = Ram00c990;
        if (sVar3 == 0) {
          sVar3 = 1;
        }
        else {
          sVar3 = 0;
        }
      }
    }
    else if (param_1 == '\x06') {
      sVar3 = Ram00c98c;
      if (sVar3 == -0x8000) {
        sVar3 = 2;
      }
      else {
        sVar3 = Ram00c98c;
        if (sVar3 == 0) {
          sVar3 = 1;
        }
        else {
          sVar3 = 0;
        }
      }
    }
    else {
      if (param_1 != '\x05') {
        return 0;
      }
      sVar3 = Ram00c98c;
      if (sVar3 == -0x8000) {
        sVar3 = 2;
      }
      else {
        sVar3 = Ram00c98c;
        if (sVar3 == 0) {
          sVar3 = 1;
        }
        else {
          sVar3 = 0;
        }
      }
    }
    if (sVar3 != 0) {
      if (sVar3 != 1) {
        return (ushort)(param_2 == 1);
      }
      return (ushort)(param_2 == 3);
    }
  }
  return 1;
}

