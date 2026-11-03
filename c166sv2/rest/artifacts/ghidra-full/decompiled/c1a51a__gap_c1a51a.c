// c1a51a gap_c1a51a size=628 cc=unknown proto=undefined gap_c1a51a(void)

short gap_c1a51a(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  short sVar6;
  short sVar7;
  
  if (cRame0089d == '\0') {
    sVar6 = sRamc079f2;
    if ((cRame008ba == '\0') && (cVar1 = UNK_00c78c, sVar6 = sRamc0650a, cVar1 == '\0')) {
      if (DAT_e0081a == '\0') {
        uVar5 = Ram00ca1c;
        uVar4 = axis16_unsigned(0x74f2,uVar5);
        uVar5 = Ram00c94e;
        uVar5 = axis16_signed(0x7552,uVar5);
        sVar6 = func_0xc28080(0x6646,0xc0,uVar4,uVar5);
        uVar5 = Ram00ca1c;
        uVar4 = axis16_unsigned(0x74f2,uVar5);
        uVar5 = DAT_00c936;
        uVar5 = axis16_signed(0x7552,uVar5);
        sVar7 = func_0xc28080(0x66e2,0xc0,uVar4,uVar5);
        Ram00c8ee = sVar6 + sVar7;
        func_0xc1ea58();
        if (cRame00832 == '\0') {
          cVar1 = DAT_00c81c;
          if (cVar1 == '\0') {
            uVar5 = DAT_00c9d0;
            uVar4 = gap_c28544(0x5122,0xc0,uVar5);
            uVar5 = Ram00ca1c;
            uVar5 = gap_c28544(0x51da,0xc0,uVar5);
            uVar5 = func_0xc28080(0x677e,0xc0,uVar4,uVar5);
            Ram00c8f2 = uVar5;
            func_0xc1ea12();
            sVar7 = Ram00c8f2;
            sVar6 = Ram00c8ee;
            Ram00c8fa = sVar7 + sVar6;
          }
          else {
            func_0xc1ea5a();
            sVar7 = Ram00ca56;
            sVar6 = Ram00c8ee;
            Ram00c8fa = sVar7 + sVar6;
          }
        }
        else {
          uVar5 = DAT_00c9d0;
          uVar4 = gap_c28544(0x5122,0xc0,uVar5);
          uVar5 = Ram00ca1c;
          uVar5 = gap_c28544(0x51da,0xc0,uVar5);
          sVar7 = func_0xc28080(0x6a24,0xc0,uVar4,uVar5);
          sVar6 = Ram00c8ee;
          Ram00c8fa = sVar7 + sVar6;
        }
        sVar6 = Ram00c8fa;
      }
      else {
        func_0xc1e9f2();
        uVar5 = DAT_00c06a;
        uVar5 = axis16_unsigned(0x7546,uVar5);
        sVar7 = gap_c27f0e(0x68bc,0xc0,uVar5);
        uVar5 = Ram00c8f8;
        uVar4 = DAT_00c962;
        uVar4 = rate_limit(uVar5,uVar4,uRamc0650c);
        uVar5 = axis16_unsigned(0x74da,uVar4);
        sVar2 = gap_c27f0e(0x68ca,0xc0,uVar5);
        uVar5 = DAT_00c9d0;
        uVar5 = gap_c28544(0x526a,0xc0,uVar5);
        sVar3 = gap_c27f0e(0x6a1c,0xc0,uVar5);
        sVar6 = Ram00ca58;
        Ram00c8f8 = uVar4;
        Ram00c8f6 = sVar6 + sVar7 + sVar2 + sVar3;
        cVar1 = UNK_00c8fe;
        if (cVar1 == '\0') {
          Ram00c8f4 = 0;
        }
        else {
          sVar6 = Ram00c88e;
          sVar7 = DAT_00c9d0;
          uVar5 = axis16_signed(0x74ec,sVar6 - sVar7);
          uVar5 = gap_c27f0e(0x68de,0xc0,uVar5);
          Ram00c8f4 = uVar5;
        }
        sVar2 = Ram00c8f6;
        sVar7 = Ram00c8f4;
        uVar5 = DAT_00c9d0;
        uVar5 = axis16_unsigned(0x74fe,uVar5);
        sVar6 = gap_c27f0e(0x68b4,0xc0,uVar5);
        if (sVar2 + sVar7 < sVar6) {
          sVar6 = sVar2 + sVar7;
        }
      }
    }
  }
  else {
    uRamc048f4 = 0;
    sVar6 = sRamc06a1a;
  }
  return sVar6;
}

