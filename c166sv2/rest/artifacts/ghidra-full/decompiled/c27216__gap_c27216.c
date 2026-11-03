// c27216 gap_c27216 size=828 cc=unknown proto=undefined gap_c27216(void)

void gap_c27216(void)

{
  short sVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  char cVar6;
  ushort uVar7;
  
  if (sRamc07e74 == 0) {
    cRame00904 = '\0';
  }
  else {
    if (sRamc07e74 != 1) {
      if (sRamc07e74 == 2) {
        cRame008fe = '\x01';
        cRame00904 = '\0';
      }
      else if (sRamc07e74 == 3) {
        cRame00904 = '\x01';
        cRame008fe = '\x01';
      }
      goto LAB_c27272;
    }
    cRame00904 = '\x01';
  }
  cRame008fe = '\0';
LAB_c27272:
  cRame00903 = cRame006fc;
  if ((((cRame006fc == '\0') && (cRame00702 == '\0')) && (cVar6 = UNK_00cc32, cVar6 == '\0')) &&
     (((uVar7 = DAT_00c962, uRamc07e76 <= uVar7 && (uVar7 <= uRamc07e78)) &&
      (sVar1 = DAT_00c936, sRamc07e7a <= sVar1)))) {
    cRame00905 = '\x01';
  }
  else {
    cRame00905 = '\0';
  }
  if (cRame00904 != '\0') {
    if (((cRame00905 == '\0') || (uVar7 = Ram00ca0a, uVar7 <= uRamc07e7c)) ||
       ((uVar7 = DAT_00ca2a, uVar7 < uRamc07e7e ||
        (((uRamc07e80 < uVar7 || (uVar7 = DAT_00c9d0, uVar7 < uRamc07e82)) || (uRamc07e84 < uVar7)))
        ))) {
      cRame00902 = '\0';
    }
    else {
      cRame00902 = '\x01';
    }
    if ((cRame00902 == '\0') ||
       (((cVar6 = func_0xc24530(0x25), cVar6 != '\0' || (uVar7 = Ram00ca3e, uRamc07e86 < uVar7)) &&
        ((cVar6 = func_0xc24530(0x25), cVar6 == '\0' || (uVar7 = Ram00ca3e, uRamc07e88 < uVar7))))))
    {
      uRame008fa = 0;
    }
    else {
      uRame008fa = 1;
    }
    uVar2 = UNK_00ccaa;
    gap_c24cb4(uVar2,cRame00902,uRame008fa,(short)&UNK_00cca8,(short)&UNK_00ccb0);
    uVar4 = Ram00cca8;
    uVar5 = Ram00ccb0;
    gap_c24d1c(uVar4,uVar5,uRamc07e8c,uRamc07e8a,(short)&UNK_00ccaa,(short)&UNK_00ccb2);
    uVar2 = UNK_00ccaa;
    uVar3 = UNK_00ccb2;
    func_0xc24d82(0x25,uVar2,uVar3);
  }
  if (cRame008fe != '\0') {
    if (((cRame00905 == '\0') || (sRame00900 == 0)) ||
       ((uVar7 = Ram00ca0a, uRamc07e8e < uVar7 ||
        (((uVar7 = DAT_00ca2a, uRamc07e90 < uVar7 || (uVar7 = DAT_00c9d0, uVar7 < uRamc07e92)) ||
         (uRamc07e94 < uVar7)))))) {
      cRame00906 = '\0';
    }
    else {
      cRame00906 = '\x01';
    }
    cRame008fb = '\0';
    uRame008fc = 0;
    if (sRame00900 != 0) {
      uVar7 = Ram00ca3e;
      if (uVar7 < uRamc07e96) {
        if (cRame00906 != '\0') {
          uVar7 = FUN_c28852(sRame00900,uRame009d0);
          if (uVar7 < uRamc07e98) {
            uRame008fd = 1;
          }
          else {
            cRame008fb = '\x01';
            uRame008fd = 0;
          }
        }
      }
      else {
        uRame008fd = 0;
        uRame008fc = 1;
      }
    }
    sRame00900 = DAT_00c9d0;
    if ((cRame00ca6 != '\0') || (cRame008fb != '\0')) {
      Ram00ccae = 0;
      Ram00ccac = 0;
    }
    uVar2 = UNK_00cca6;
    gap_c24cb4(uVar2,cRame00906,uRame008fd,(short)&UNK_00ccae,(short)&UNK_00ccac);
    uVar5 = Ram00ccae;
    uVar4 = Ram00ccac;
    gap_c24d1c(uVar5,uVar4,uRamc07e9c,uRamc07e9a,(short)&UNK_00cca6,(short)&UNK_00cca7);
    uVar2 = UNK_00cca6;
    uVar3 = UNK_00cca7;
    func_0xc24d82(0x25,uVar2,uVar3);
  }
  return;
}

