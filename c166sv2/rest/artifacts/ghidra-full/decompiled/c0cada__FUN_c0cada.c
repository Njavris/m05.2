// c0cada FUN_c0cada size=586 cc=unknown proto=undefined FUN_c0cada(void)

undefined2 FUN_c0cada(void)

{
  short sVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  ushort uVar8;
  ushort uVar9;
  short sVar10;
  undefined2 uVar11;
  uint uVar12;
  
  uVar5 = DAT_00fd00;
  if ((uVar5 & 0x2000) != 0) {
    uVar11 = CC24;
    DAT_00c25e = uVar11;
    uVar12 = FUN_c0c5de();
    DAT_00c260 = (short)uVar12;
    DAT_00c262 = (short)(uVar12 >> 0x10);
    uVar11 = DAT_00c27e;
    DAT_00c2c4 = uVar11;
    sVar1 = (short)(uVar12 >> 3);
    DAT_00c27e = sVar1;
    uVar11 = DAT_00c266;
    DAT_00c27c = uVar11;
    sVar10 = DAT_00c2c4;
    DAT_00c266 = sVar1 - sVar10;
    return (short)((uVar12 >> 3) >> 0x10);
  }
  cVar2 = DAT_00c1fd;
  DAT_00c1fd = cVar2 + '\x01';
  uVar11 = CC24;
  DAT_00c25e = uVar11;
  uVar12 = FUN_c0c5de();
  DAT_00c260 = (short)uVar12;
  DAT_00c262 = (short)(uVar12 >> 0x10);
  uVar11 = (undefined2)((uVar12 >> 3) >> 0x10);
  DAT_00c27e = (short)(uVar12 >> 3);
  uVar5 = DAT_00fd00;
  if ((uVar5 & 0x8000) != 0) {
    uVar5 = DAT_00fd00;
    DAT_00fd00 = uVar5 & 0x7fff;
    goto LAB_c0cce2;
  }
  sVar1 = DAT_00c27e;
  sVar10 = DAT_00c2c4;
  DAT_00c252 = sVar1 - sVar10;
  uVar5 = DAT_00fd00;
  if ((uVar5 & 0x100) == 0) {
    cVar2 = DAT_00c1fd;
    cVar3 = DAT_00c3da;
    if (cVar2 == cVar3) {
      uVar11 = FUN_c0f132(0);
    }
    cVar2 = DAT_00c1fd;
    cVar3 = DAT_00c3f4;
    if (cVar2 == cVar3) {
      uVar11 = FUN_c0f132(1);
    }
    cVar2 = DAT_00c1fd;
    cVar3 = DAT_00c38e;
    if (cVar2 == cVar3) {
      uVar11 = FUN_c0d076();
    }
    cVar2 = DAT_00c1fd;
    cVar3 = DAT_00c3ae;
    if (cVar2 == cVar3) {
      uVar11 = FUN_c0d956();
    }
    cVar3 = DAT_00c1fd;
    cVar2 = DAT_00c1fa;
    if (cVar3 == cVar2) {
      uVar11 = FUN_c0bab4();
    }
    cVar2 = DAT_00c1fd;
    if (cVar2 == '\x04') {
      uVar11 = FUN_c0d296();
    }
    uVar5 = DAT_00fd00;
    DAT_00fd00 = uVar5 | 0x200;
    uVar5 = DAT_00fd00;
    if ((uVar5 & 0x400) == 0) {
      uVar5 = DAT_00fd00;
      DAT_00fd00 = uVar5 | 0x400;
    }
    else {
      uVar5 = DAT_00fd18;
      if ((uVar5 & 0x80) == 0) {
        uVar5 = DAT_00fd00;
        if ((uVar5 & 0x4000) == 0) {
          uVar8 = DAT_00c270;
          sVar1 = DAT_00c270;
          uVar5 = DAT_00c252;
          if ((uVar8 >> 1) + sVar1 < uVar5) {
            uVar5 = DAT_00fd00;
            DAT_00fd00 = uVar5 | 0x4000;
          }
        }
        else {
          uVar5 = DAT_00c252;
          sVar1 = DAT_00c252;
          uVar8 = DAT_00c270;
          if ((uVar5 >> 1) + sVar1 < uVar8) {
            uVar5 = DAT_00fd00;
            DAT_00fd00 = uVar5 & 0xbfff;
            uVar5 = DAT_00fd00;
            DAT_00fd00 = uVar5 | 0x2000;
            uVar5 = DAT_00fd00;
            DAT_00fd00 = uVar5 | 0x800;
            uVar5 = DAT_00fd00;
            DAT_00fd00 = uVar5 | 0x80;
          }
          else {
            uVar5 = DAT_00c252;
            uVar8 = DAT_00c270;
            uVar9 = DAT_00c270;
            if (uVar5 == uVar9 || uVar5 < uVar8) {
              uVar5 = DAT_00fd00;
              DAT_00fd00 = uVar5 & 0xbfff;
            }
          }
        }
      }
      uVar5 = DAT_00fd00;
      if ((uVar5 & 0x2000) != 0) {
        uVar11 = DAT_00c260;
        uVar6 = DAT_00c262;
        DAT_00c24c = uVar11;
        DAT_00c24e = uVar6;
        DAT_00c256 = 2;
        uVar7 = DAT_00c256;
        DAT_00c1fc = uVar7;
        cVar2 = DAT_00c2b2;
        cVar3 = T5._0_1_;
        DAT_00c2b2 = cVar3 + cVar2;
        uVar5 = T5CON;
        T5CON = uVar5 & 0xffbf;
        T5 = 0;
        uVar11 = FUN_c0c65a();
        uVar5 = T5IC;
        T5IC = uVar5 | 0x40;
        DAT_00c1fd = 0;
        uVar5 = DAT_00fd00;
        DAT_00fd00 = uVar5 & 0xfbff;
        uVar5 = DAT_00fd00;
        if ((uVar5 & 0x1000) == 0) {
          uVar5 = DAT_00fd00;
          DAT_00fd00 = uVar5 | 0x1000;
        }
        else {
          bVar4 = DAT_00c2b2;
          if (bVar4 < 5) {
            cVar2 = DAT_00c264;
            DAT_00c264 = cVar2 + '\x01';
LAB_c0cc80:
            DAT_00c280 = 0;
          }
          else {
            bVar4 = DAT_00c2b2;
            if (5 < bVar4) {
              cVar2 = DAT_00c272;
              DAT_00c272 = cVar2 + '\x01';
              goto LAB_c0cc80;
            }
            cVar2 = DAT_00c2b2;
            if (cVar2 == '\x05') {
              cVar2 = DAT_00c280;
              DAT_00c280 = cVar2 + '\x01';
            }
          }
          cVar2 = DAT_00c264;
          cVar3 = DAT_00c272;
          DAT_00c277 = cVar2 + cVar3;
        }
        uVar5 = DAT_00fd00;
        if ((uVar5 & 0x10) != 0) {
          uVar11 = FUN_c0c6f2();
        }
      }
      uVar5 = DAT_00fd00;
      if ((uVar5 & 0x4000) == 0) {
        uVar6 = DAT_00c266;
        DAT_00c27c = uVar6;
        uVar6 = DAT_00c252;
        DAT_00c266 = uVar6;
      }
      else {
        uVar6 = DAT_00c266;
        DAT_00c27c = uVar6;
        uVar5 = DAT_00c252;
        DAT_00c266 = uVar5 >> 1;
      }
    }
  }
  else {
    uVar5 = DAT_00fd00;
    if ((uVar5 & 0x20) == 0) {
      uVar5 = DAT_00c252;
      if ((uVar5 < 0x9d) || (uVar5 = DAT_00c252, 0xc34 < uVar5)) {
        DAT_00c202 = 0;
      }
      else {
        cVar2 = DAT_00c202;
        DAT_00c202 = cVar2 + '\x01';
        bVar4 = DAT_00c202;
        if ((byte)PTR_DAT_c05030 <= bVar4) {
          uVar5 = DAT_00fd00;
          DAT_00fd00 = uVar5 | 0x200;
          uVar5 = DAT_00fd00;
          DAT_00fd00 = uVar5 & 0xfeff;
          uVar5 = DAT_00fd00;
          DAT_00fd00 = uVar5 | 0x400;
          DAT_00c202 = 0;
        }
        cVar2 = DAT_00c202;
        if (cVar2 == '\x02') {
          uVar5 = DAT_00fd02;
          DAT_00fd02 = uVar5 | 0x100;
          DAT_00c3b4 = 0;
        }
      }
    }
    else {
      uVar5 = DAT_00fd00;
      DAT_00fd00 = uVar5 & 0xfeff;
      uVar5 = DAT_00fd00;
      DAT_00fd00 = uVar5 | 0x400;
      uVar5 = DAT_00fd00;
      DAT_00fd00 = uVar5 & 0xffdf;
    }
    uVar5 = DAT_00fd02;
    DAT_00fd02 = uVar5 | 0x200;
  }
  uVar6 = DAT_00c252;
  DAT_00c270 = uVar6;
LAB_c0cce2:
  uVar6 = DAT_00c27e;
  DAT_00c2c4 = uVar6;
  return uVar11;
}

