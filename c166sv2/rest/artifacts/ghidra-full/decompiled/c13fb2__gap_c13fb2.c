// c13fb2 gap_c13fb2 size=48 cc=unknown proto=undefined gap_c13fb2(void)

bool gap_c13fb2(char param_1)

{
  ushort uVar1;
  
  if (param_1 == '\0') {
    uVar1 = DAT_00fd10;
    if ((uVar1 & 4) == 0) {
      return false;
    }
    uVar1 = DAT_00fd10;
  }
  else {
    uVar1 = DAT_00fd0c;
    if ((uVar1 & 4) == 0) {
      return false;
    }
    uVar1 = DAT_00fd0c;
  }
  return (uVar1 & 2) != 0;
}

