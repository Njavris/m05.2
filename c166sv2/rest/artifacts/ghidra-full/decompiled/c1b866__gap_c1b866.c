// c1b866 gap_c1b866 size=284 cc=unknown proto=undefined gap_c1b866(void)

void gap_c1b866(void)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  ushort uVar4;
  char cVar5;
  ushort uVar6;
  undefined2 uVar7;
  
  if ((DAT_e00810 == '\0') && (cRame00811 == '\0')) {
    uRame00834 = 0;
  }
  else {
    uVar3 = DAT_00c97c;
    uVar6 = tbl16_interp(0x6b6a,0xc0,uVar3);
    uVar4 = DAT_00c9d0;
    if ((uVar4 <= uRamc06b92) || (uVar4 = Ram00ca1c, bVar1 = bRamc06b91, uVar4 <= uRamc06b94)) {
      bVar1 = bRamc06b90;
    }
    iVar2 = (uint)uVar6 * (uint)bVar1 * 0x100;
    uRame00834 = (ushort)iVar2 >> 0xf | (short)((uint)iVar2 >> 0x10) << 1;
    if (0x8000 < uRame00834) {
      uRame00834 = 0x8000;
    }
  }
  uVar3 = uRamc06b8e;
  uVar7 = func_0xc27b86(uRame00834,0x8000,0xf);
  Ram00c98c = uVar7;
  uVar7 = FUN_c28852(0x8000,uVar7);
  Ram00c98c = uVar7;
  func_0xc14c70(0,uVar3,uVar7);
  if (cRamc0506d == '\x01') {
    uVar7 = Ram00c98c;
    func_0xc14c70(5,uVar3,uVar7);
  }
  cVar5 = cRame00811;
  if (DAT_e00810 == '\x01') {
    func_0xc14cec(0);
  }
  if ((cRamc0506d == '\x01') && (cVar5 == '\x01')) {
    func_0xc14cec(5);
  }
  return;
}

