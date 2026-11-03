// c0cd24 speed_timing_calc size=214 cc=unknown proto=undefined speed_timing_calc(void)

void speed_timing_calc(void)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  byte bVar4;
  undefined2 uVar5;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  bVar1 = DAT_00c268;
  bVar4 = bVar1 + 1;
  if (bVar4 < bVar1) {
    bVar4 = 0xff;
  }
  DAT_00c268 = bVar4;
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = DAT_00fd00;
  uVar3 = DAT_00fd00;
  DAT_00fd00 = uVar3 & 0xffbf;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = DAT_00fd02;
  DAT_00fd02 = uVar3 & 0xbfff | (uVar2 >> 6 & 1) << 0xe;
  uVar2 = DAT_00fd02;
  if ((uVar2 & 0x4000) != 0) {
    uVar2 = DAT_00fd02;
    DAT_00fd02 = uVar2 | 0x8000;
  }
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = DAT_00fd00;
  uVar3 = DAT_00fd00;
  DAT_00fd00 = uVar3 & 0xf7ff;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = DAT_00fd02;
  DAT_00fd02 = uVar3 & 0xdfff | (uVar2 >> 0xb & 1) << 0xd;
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = DAT_00fd00;
  uVar3 = DAT_00fd00;
  DAT_00fd00 = uVar3 & 0xfdff;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = DAT_00fd02;
  DAT_00fd02 = uVar3 & 0xefff | (uVar2 >> 9 & 1) << 0xc;
  uVar2 = DAT_00fd02;
  if ((uVar2 & 0x1000) != 0) {
    uVar2 = DAT_00fd02;
    DAT_00fd02 = uVar2 & 0xf3ff | 0xc00;
  }
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  uVar5 = DAT_00c9d0;
  uVar5 = axis16_unsigned(0x7000,uVar5);
  DAT_00c254 = uVar5;
  uVar5 = tbl16_interp(0x504c,0xc0,uVar5);
  DAT_00c274 = uVar5;
  uVar5 = DAT_00c254;
  uVar5 = tbl16_interp(0x5038,0xc0,uVar5);
  DAT_00c26e = uVar5;
  return;
}

