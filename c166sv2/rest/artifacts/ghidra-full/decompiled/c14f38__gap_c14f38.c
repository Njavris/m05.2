// c14f38 gap_c14f38 size=174 cc=unknown proto=undefined gap_c14f38(void)

void gap_c14f38(char param_1,short param_2)

{
  ushort uVar1;
  
  if ((param_2 != 3) && (param_2 != 1)) {
    if (param_1 == '\0') {
      uVar1 = DAT_00c4a8;
      if ((uVar1 & 0x80) != 0) {
        if (param_2 == 2) {
          uVar1 = Ram00c4ae;
          Ram00c4ae = uVar1 & 0xfffe;
          return;
        }
        if (param_2 == 0) {
          uVar1 = Ram00c4ac;
          Ram00c4ac = uVar1 & 0xfffe;
        }
      }
    }
    else if (param_1 == '\x01') {
      uVar1 = DAT_00c4a8;
      if ((uVar1 & 0x20) != 0) {
        if (param_2 == 2) {
          uVar1 = Ram00c4ae;
          Ram00c4ae = uVar1 & 0xfffb;
          return;
        }
        if (param_2 == 0) {
          uVar1 = Ram00c4ac;
          Ram00c4ac = uVar1 & 0xfffb;
          return;
        }
      }
    }
    else if (param_1 == '\x05') {
      uVar1 = DAT_00c4a8;
      if ((uVar1 & 4) != 0) {
        if (param_2 == 2) {
          uVar1 = Ram00c4ae;
          Ram00c4ae = uVar1 & 0xffdf;
          return;
        }
        if (param_2 == 0) {
          uVar1 = Ram00c4ac;
          Ram00c4ac = uVar1 & 0xffdf;
          return;
        }
      }
    }
    else if ((param_1 == '\x06') && (uVar1 = DAT_00c4a8, (uVar1 & 0x10) != 0)) {
      if (param_2 == 2) {
        uVar1 = Ram00c4ae;
        Ram00c4ae = uVar1 & 0xfff7;
        return;
      }
      if (param_2 == 0) {
        uVar1 = Ram00c4ac;
        Ram00c4ac = uVar1 & 0xfff7;
        return;
      }
    }
  }
  return;
}

