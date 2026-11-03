// c16cde gap_c16cde size=796 cc=unknown proto=undefined gap_c16cde(void)

void gap_c16cde(void)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  ushort uVar7;
  
  cVar3 = DAT_00c93c;
  if (cVar3 != '\x03') {
    func_0xc1eb4a();
    cVar3 = DAT_00c93c;
    if ((cVar3 == '\x02') && (uVar7 = Ram00c996, uRamc06224 <= uVar7)) {
      UNK_00c7bc = 1;
      if ((bRamc06228 <= uRamc047e8) && (uVar7 = Ram00c76a, 0xcd < uVar7)) {
        Ram00c76a = (short)((uint)uVar7 * (uint)uRamc06226 >> 0x10);
        Ram00c7e8 = 0;
      }
      uVar7 = Ram00c76a;
      if (uVar7 < 0xce) {
        Ram00c7e8 = 0;
        UNK_00c7bc = 0;
        Ram00c76a = 0;
      }
    }
    else {
      UNK_00c7bc = 0;
      Ram00c7e8 = 0;
    }
    uVar2 = Ram00ca6e;
    uVar7 = Ram00c76a;
    uVar6 = Ram00c76a;
    if (uVar2 == uVar6 || uVar2 < uVar7) {
      Ram00c770 = 0xcd;
    }
    else {
      sVar1 = Ram00c76a;
      Ram00c770 = uVar2 - sVar1;
    }
    goto LAB_c16fce;
  }
  uVar5 = Ram00ca1c;
  uVar4 = gap_c28544(0x51aa,0xc0,uVar5);
  uVar5 = DAT_00c9d0;
  uVar5 = gap_c28544(0x5146,0xc0,uVar5);
  uVar5 = tbl2d_interp(0x5c62,0xc0,uVar4,uVar5);
  Ram00c776 = uVar5;
  func_0xc1eb2a();
  func_0xc1ebf8();
  if (cRamc05e04 == '\x01') {
LAB_c16dd8:
    uVar5 = Ram00ca5a;
    Ram00c772 = uVar5;
  }
  else {
    if (cRamc05e04 != '\x02') {
      if (cRamc05e04 != '\x03') goto LAB_c16dea;
      uVar7 = Ram00ca5a;
      uVar6 = Ram00ca5c;
      if (uVar7 < uVar6) goto LAB_c16dd8;
    }
    uVar5 = Ram00ca5c;
    Ram00c772 = uVar5;
  }
LAB_c16dea:
  if (cRame0089d == '\0') {
    cVar3 = DAT_00c77e;
    if ((cVar3 == '\0') || (cRame00832 != '\0')) {
      cVar3 = DAT_00c81c;
      if ((cVar3 == '\0') || (cRame00832 != '\0')) {
        cVar3 = DAT_00cad6;
        if (((cVar3 == '\0') && (cVar3 = DAT_00cad7, cVar3 == '\0')) ||
           ((sVar1 = DAT_00c936, sVar1 <= sRamc061a6 || (cRame00832 != '\0')))) {
          uVar5 = func_0xc1725c();
          Ram00c770 = uVar5;
        }
        else {
          sRamc04770 = sRamc06162;
        }
      }
      else {
        uVar6 = gap_c18d8a();
        uVar7 = DAT_00c9d0;
        if ((uVar7 < uRamc063b0) &&
           ((DAT_e0081a == '\x01' && (uVar2 = Ram00c774, uVar2 < uRamc0630e)))) {
          uVar5 = gap_c28544(0x5278,0xc0,uVar7);
          uVar7 = tbl8_interp(0x621c,0xc0,uVar5);
          uVar5 = DAT_00c97c;
          uVar6 = tbl8_interp(0x63c2,0xc0,uVar5);
          uVar7 = (ushort)((uint)uVar7 * (uint)uVar6) >> 0xf |
                  (short)((uint)uVar7 * (uint)uVar6 >> 0x10) << 1;
        }
        else {
          uVar7 = DAT_00ca2a;
          uVar2 = DAT_00ca2a;
          if (((uVar6 == uVar2 || uVar6 < uVar7) || (DAT_e0081a != '\0')) ||
             (uVar7 = Ram00c77a, uRamc06310 <= uVar7)) {
            uVar7 = Ram00c772;
            uVar6 = Ram00ca66;
            uVar7 = (ushort)((uint)uVar7 * (uint)uVar6) >> 0xf |
                    (short)((uint)uVar7 * (uint)uVar6 >> 0x10) << 1;
          }
          else {
            func_0xc1eb34();
            uVar5 = DAT_00c9d0;
            uVar5 = axis16_signed(0x7624,uVar5);
            uVar6 = tbl8_interp(0x6300,0xc0,uVar5);
            uVar7 = Ram00ca62;
            uVar7 = (ushort)((uint)uVar6 * (uint)uVar7) >> 0xf |
                    (short)((uint)uVar6 * (uint)uVar7 >> 0x10) << 1;
          }
        }
        if (uVar7 < 0xf801) {
          if (uVar7 < 0xcd) {
            uVar7 = 0xcd;
          }
        }
        else {
          uVar7 = 0xf800;
        }
        Ram00c770 = uVar7;
      }
    }
    else {
      uVar7 = Ram00c772;
      if (uVar7 < uRamc061a4) {
        Ram00c770 = 0;
      }
      else {
        sRamc04770 = Ram00c772;
        sRamc04770 = sRamc04770 - uRamc061a4;
      }
    }
  }
  else {
    sRamc04770 = sRamc061ec;
  }
  sVar1 = DAT_00c936;
  if ((sRamc0622a <= sVar1) || (uVar7 = Ram00c072, uRamc0622c <= uVar7)) {
    Ram00c7e8 = 0;
    UNK_00c7bc = 0;
    uRamc0476a = uRamc06222;
  }
LAB_c16fce:
  uVar7 = Ram00c770;
  if (uVar7 < 0xf801) {
    uVar7 = Ram00c770;
    if (uVar7 < 0xcd) {
      uVar5 = 0xcd;
    }
    else {
      uVar5 = Ram00c770;
    }
  }
  else {
    uVar5 = 0xf800;
  }
  Ram00c770 = uVar5;
  return;
}

