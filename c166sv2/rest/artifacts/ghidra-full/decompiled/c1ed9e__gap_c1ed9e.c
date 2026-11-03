// c1ed9e gap_c1ed9e size=408 cc=unknown proto=undefined gap_c1ed9e(void)

void gap_c1ed9e(void)

{
  ushort uVar1;
  short sVar2;
  char cVar3;
  ushort uVar4;
  undefined2 uVar5;
  ushort uVar6;
  
  cVar3 = UNK_00ca7a;
  if (cVar3 == '\x01') {
    func_0xc14cec(6);
  }
  cVar3 = UNK_00ca7a;
  if (cVar3 == '\x01') {
    func_0xc1f2b0();
    uVar5 = DAT_00c9d0;
    uVar5 = gap_c28544(0x5122,0xc0,uVar5);
    uVar5 = tbl16_interp(0x7616,0xc0,uVar5);
    if (DAT_e0081a == '\x01') {
      uRamc04a7c = uRamc07614;
    }
    else {
      Ram00ca7c = uVar5;
    }
    if (cRame0087e == '\0') {
      uVar4 = Ram00ca7e;
      uVar1 = Ram00ca7c;
      if (uVar4 < uVar1) {
        sVar2 = Ram00c862;
        uVar6 = *(ushort *)(sVar2 * 2 + 0x77d6);
        uVar1 = Ram00ca80;
        uVar4 = Ram00ca80;
        if (uVar6 == uVar4 || uVar6 < uVar1) {
          uVar1 = *(ushort *)(uint3)(sVar2 * 2 + 0x774e);
          sVar2 = Ram00ca7e;
          Ram00ca7e = sVar2 + uVar1;
          uVar4 = Ram00ca7e;
          uVar6 = Ram00ca7e;
          if (uVar1 != uVar6 && uVar4 <= uVar1) {
            Ram00ca7e = 0xffff;
          }
          Ram00ca80 = 0;
        }
        else {
          UNK_00ca82 = 1;
        }
        uVar1 = Ram00ca7e;
        if (uVar1 <= uRamc07612) {
          uRamc04a7e = uRamc07612;
        }
        goto LAB_c1ef08;
      }
      Ram00ca80 = 0;
      UNK_00ca82 = 0;
    }
    else {
      if (cRame0087e == '\x01') {
        sVar2 = Ram00c862;
        uVar6 = *(ushort *)(sVar2 * 2 + 0x77d6);
        uVar1 = Ram00ca80;
        uVar4 = Ram00ca80;
        if (uVar6 == uVar4 || uVar6 < uVar1) {
          uVar1 = *(ushort *)(uint3)(sVar2 * 2 + 0x7792);
          uVar4 = Ram00ca7e;
          uVar6 = Ram00ca7e;
          if (uVar1 == uVar6 || uVar1 < uVar4) {
            sVar2 = Ram00ca7e;
            Ram00ca7e = sVar2 - uVar1;
          }
          else {
            Ram00ca7e = 0;
          }
          Ram00ca80 = 0;
        }
        else {
          UNK_00ca82 = 1;
        }
        uVar1 = Ram00ca7e;
        if (uRamc07612 <= uVar1) goto LAB_c1ef08;
        goto LAB_c1eefc;
      }
      Ram00ca80 = 0;
      UNK_00ca82 = 0;
      uVar4 = Ram00ca7e;
      uVar1 = Ram00ca7c;
      if (uVar4 < uVar1) goto LAB_c1ef08;
    }
    uVar5 = Ram00ca7c;
    Ram00ca7e = uVar5;
  }
  else {
LAB_c1eefc:
    Ram00ca80 = 0;
    UNK_00ca82 = 0;
    Ram00ca7e = 0;
  }
LAB_c1ef08:
  uVar5 = Ram00ca7e;
  uVar5 = func_0xc27b86(uVar5,0x8000,0xf);
  Ram00c98c = uVar5;
  uVar5 = FUN_c28852(0x8000,uVar5);
  Ram00c98c = uVar5;
  func_0xc14c70(6,0x40,uVar5);
  return;
}

