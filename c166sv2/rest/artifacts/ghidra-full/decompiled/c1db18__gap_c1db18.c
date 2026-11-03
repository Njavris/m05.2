// c1db18 gap_c1db18 size=372 cc=unknown proto=undefined gap_c1db18(void)

void gap_c1db18(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  uVar7 = DAT_00c9d0;
  uVar6 = gap_c28544(0x5146,0xc0,uVar7);
  uVar7 = Ram00c9f4;
  uVar7 = axis16_unsigned(0x753a,uVar7);
  uVar7 = tbl2d_interp(0x6e50,0xc0,uVar7,uVar6);
  Ram00ca16 = uVar7;
  uVar7 = DAT_00c06a;
  uVar6 = func_0xc27b86(uVar7,uRamc06b96,8);
  Ram00ca12 = uVar6;
  uVar7 = Ram00ca16;
  uVar6 = func_0xc2849c(uVar6,uVar7,8);
  Ram00ca06 = uVar6;
  uVar7 = Ram00c9ee;
  uVar7 = func_0xc2849c(uVar6,uVar7,0xf);
  Ram00ca1c = uVar7;
  cVar3 = UNK_00cc32;
  if ((cVar3 == '\0') && (cVar3 = UNK_00ca18, cVar3 == '\0')) {
    uVar2 = DAT_00ca2a;
    if ((uVar2 < uRamc0714a) && (cVar3 = DAT_00c841, cVar3 == '\0')) {
      uVar7 = DAT_00ca04;
      Ram00ca1c = uVar7;
      UNK_00ca10 = 1;
      goto LAB_c1dbdc;
    }
    cVar3 = UNK_00ca10;
    if (((cVar3 == '\x01') && (uVar2 = DAT_00ca2a, uVar2 < uRamc0714c)) &&
       (cVar3 = DAT_00c841, cVar3 == '\0')) {
      uVar7 = DAT_00ca04;
      Ram00ca1c = uVar7;
      goto LAB_c1dbdc;
    }
  }
  UNK_00ca10 = 0;
LAB_c1dbdc:
  if (cRamc0507b == '\x01') {
    uVar7 = DAT_00ca04;
    Ram00ca1c = uVar7;
  }
  uVar2 = DAT_00c06a;
  uVar4 = Ram00ca1c;
  uVar5 = Ram00ca1c;
  if (uVar2 == uVar5 || uVar2 < uVar4) {
    Ram00c9fc = 0;
  }
  else {
    uVar7 = Ram00ca1c;
    uVar7 = FUN_c28852(uVar2,uVar7);
    Ram00c9fc = uVar7;
  }
  uVar2 = DAT_00c06a;
  uVar4 = DAT_00ca04;
  uVar5 = DAT_00ca04;
  if (uVar2 == uVar5 || uVar2 < uVar4) {
    Ram00ca1e = 0;
  }
  else {
    uVar7 = DAT_00ca04;
    uVar7 = FUN_c28852(uVar2,uVar7);
    Ram00ca1e = uVar7;
  }
  uVar2 = Ram00ca1c;
  bVar1 = uRame0086e < uVar2;
  if (bVar1) {
    uRame0086a = FUN_c28852(uVar2,uRame0086e);
  }
  else {
    uRame0086a = FUN_c28852(uRame0086e,uRame00a1c);
  }
  uRame0086c = bVar1;
  uRame0086e = Ram00ca1c;
  return;
}

