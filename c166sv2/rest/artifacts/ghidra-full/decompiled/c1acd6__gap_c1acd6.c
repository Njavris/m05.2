// c1acd6 gap_c1acd6 size=470 cc=unknown proto=undefined gap_c1acd6(void)

void gap_c1acd6(void)

{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  cVar1 = UNK_00cc32;
  if ((cVar1 != '\0') || (cVar1 = UNK_00ca18, cVar1 != '\0')) {
    UNK_00c926 = 1;
    DAT_00c91c = 0;
    cVar1 = DAT_00c93c;
    if (cVar1 == '\x01') {
      uRamc0406a = uRamc06c50;
    }
    else {
      uRame0006a = uRame00826;
    }
    goto LAB_c1ae66;
  }
  UNK_00c926 = 0;
  uVar5 = DAT_00fd02;
  if (((uVar5 & 0x800) != 0) ||
     ((sVar2 = DAT_00c9d0, sVar2 != 0 || (uVar5 = DAT_00fd02, (uVar5 & 0x200) != 0)))) {
    func_0xc1d39c();
    cVar1 = DAT_00c93c;
    if ((((cVar1 == '\x03') && (cVar1 = DAT_00c934, cVar1 != '\0')) &&
        (uVar5 = DAT_00c9d0, uVar5 <= uRamc06c52)) &&
       (((cVar1 = UNK_00c9ea, cVar1 != '\0' && (uVar5 = Ram00c9ca, uVar5 < uRamc06ccc)) &&
        (cRamc0507b == '\0')))) {
      DAT_00c91c = 1;
      cVar1 = DAT_00c920;
      if (cVar1 != '\0') {
        DAT_00c920 = 0;
        uVar4 = DAT_00c91e;
        uVar3 = Ram00c924;
        uVar3 = func_0xc276a4(uVar4,uVar3);
        uVar4 = DAT_00c06a;
        uVar4 = rate_limit(uVar4,uVar3,uRamc06c56);
        DAT_00c06a = uVar4;
      }
    }
    else {
      DAT_00c920 = 0;
      DAT_00c91c = 0;
    }
    uVar4 = DAT_00c9d0;
    uVar4 = gap_c28544(0x50dc,0xc0,uVar4);
    uVar4 = tbl8_interp(0x6ca4,0xc0,uVar4);
    Ram00c922 = uVar4;
    goto LAB_c1ae66;
  }
  cVar1 = UNK_00cc2c;
  if (cVar1 != '\0') {
    uRamc0406a = uRamc06c50;
    UNK_00c926 = 1;
    goto LAB_c1ae66;
  }
  uVar4 = FUN_c1aeac();
  uVar5 = func_0xc27b10(uRame00824,uVar4);
  if (uRame00828 == 0) {
    uRame00824 = FUN_c1aeac(0);
LAB_c1ade6:
    uRame00828 = uRame00828 + 1;
  }
  else {
    if (uVar5 <= uRamc06cc2) goto LAB_c1ade6;
    uRame00828 = 0;
  }
  if (uRamc06cd6 < uRame00828) {
    uVar4 = DAT_00c06a;
    uVar4 = rate_limit(uVar4,uRame00824,uRamc06c54);
    DAT_00c06a = uVar4;
    uRame00828 = 0;
  }
LAB_c1ae66:
  uVar5 = DAT_00c06a;
  if (uVar5 <= uRamc06c5a) {
    uVar5 = uRamc06c5a;
  }
  if (uRamc06c58 < uVar5) {
    uRamc0406a = uRamc06c58;
  }
  else {
    DAT_00c06a = uVar5;
  }
  uRame00826 = DAT_00c06a;
  return;
}

