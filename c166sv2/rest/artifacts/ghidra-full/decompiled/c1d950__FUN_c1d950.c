// c1d950 FUN_c1d950 size=286 cc=unknown proto=undefined FUN_c1d950(void)

void FUN_c1d950(void)

{
  undefined2 uVar1;
  ushort uVar2;
  short sVar3;
  char cVar4;
  ushort uVar5;
  ushort uVar6;
  undefined2 uVar7;
  
  uVar5 = FUN_c13dc8(3);
  uVar5 = FUN_c276ba(DAT_c06c4e,(short)((uint)uVar5 * (uint)DAT_c06c4c >> 0x10));
  DAT_00c9f2 = uVar5;
  if ((uVar5 < DAT_c06c76) && (DAT_c06c78 < uVar5)) {
    uVar7 = DAT_00ca0c;
    uVar6 = rate_limit(uVar7,uVar5,DAT_c06c74);
    DAT_00ca0c = uVar6;
    sVar3 = DAT_00ca1a;
    DAT_00c9f6 = uVar6 + sVar3 >> 1;
    uVar5 = DAT_00c9f6;
    if (uVar6 < uVar5) {
      uVar7 = DAT_00c9f6;
      uVar1 = DAT_00ca0c;
      uVar7 = FUN_c28852(uVar7,uVar1);
    }
    else {
      uVar1 = DAT_00ca0c;
      uVar7 = DAT_00c9f6;
      uVar7 = FUN_c28852(uVar1,uVar7);
    }
    DAT_00ca02 = uVar7;
    uVar7 = DAT_00ca0c;
    DAT_00ca1a = uVar7;
    DAT_00ca14 = 0;
    cVar4 = DAT_00c934;
    if (cVar4 == '\0') {
      uVar2 = DAT_00ca0c;
      uVar5 = DAT_00c9f6;
      uVar6 = DAT_00c9f6;
      if (uVar2 == uVar6 || uVar2 < uVar5) {
LAB_c1da2a:
        uVar1 = DAT_00ca04;
        uVar7 = DAT_00c9f2;
        uVar7 = rate_limit(uVar1,uVar7,DAT_c06c92);
        DAT_00ca04 = uVar7;
        return;
      }
    }
    else {
      if (DAT_c06b68 == '\0') {
        cVar4 = DAT_00c92f;
      }
      else {
        cVar4 = DAT_00c930;
      }
      if (cVar4 == '\0') {
        cVar4 = DAT_00c9f8;
        if (cVar4 == '\0') {
          DAT_00c9f8 = 1;
          DAT_00ca08 = 0;
          uVar7 = DAT_00c9f2;
          DAT_00ca04 = uVar7;
          return;
        }
        DAT_00ca08 = 1;
        goto LAB_c1da2a;
      }
    }
  }
  else {
    DAT_00ca14 = 1;
    DAT_00ca08 = 0;
    uVar7 = DAT_00c06a;
    uVar7 = axis16_unsigned(0x7546,uVar7);
    uVar7 = tbl16_interp(0x6c7a,0xc0,uVar7);
    DAT_00ca04 = uVar7;
  }
  return;
}

