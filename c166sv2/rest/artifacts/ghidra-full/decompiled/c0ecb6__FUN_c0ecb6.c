// c0ecb6 FUN_c0ecb6 size=48 cc=unknown proto=undefined FUN_c0ecb6(void)

short FUN_c0ecb6(short param_1,short param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar1 = param_1 - param_2;
  if (uVar1 < 0x8000) {
    uVar2 = DAT_00c472;
    uVar3 = DAT_00c472;
    if (uVar1 == uVar3 || uVar1 < uVar2) {
      uVar2 = DAT_00c45a;
      if (uVar1 < uVar2) {
        param_1 = DAT_00c45a;
        param_1 = param_2 + param_1;
      }
    }
    else {
      param_1 = DAT_00c472;
      param_1 = param_2 + param_1;
    }
  }
  else {
    param_1 = DAT_00c452;
    param_1 = param_2 + param_1;
  }
  return param_1;
}

