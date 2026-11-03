// c0fe0c FUN_c0fe0c size=114 cc=unknown proto=undefined FUN_c0fe0c(void)

/* WARNING: Removing unreachable block (ram,0xc0fe22) */
/* WARNING: Removing unreachable block (ram,0xc0fe30) */
/* WARNING: Removing unreachable block (ram,0xc0fe34) */

undefined2 FUN_c0fe0c(short param_1)

{
  short sVar1;
  ushort uVar2;
  
  if (param_1 == 0) {
    uVar2 = DAT_00fd10;
    if ((uVar2 & 4) == 0) {
      sVar1 = DAT_00c47e;
      if (sVar1 != 1) {
        return 0;
      }
    }
    else {
      uVar2 = CC23IC;
      CC23IC = uVar2 & 0xffbf;
    }
  }
  else {
    uVar2 = DAT_00fd0c;
    if ((uVar2 & 4) == 0) {
      sVar1 = DAT_00c47e;
      if (sVar1 != 2) {
        return 0;
      }
    }
    else if (param_1 == 0) {
      uVar2 = CC23IC;
      CC23IC = uVar2 & 0xffbf;
    }
    else if (param_1 == 1) {
      uVar2 = CC22IC;
      CC22IC = uVar2 & 0xffbf;
    }
  }
  return 1;
}

