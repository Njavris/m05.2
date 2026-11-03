// c106e6 t7_timestamp_extended size=68 cc=unknown proto=undefined t7_timestamp_extended(void)

short t7_timestamp_extended(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  uVar1 = PSW;
  uVar1 = (uVar1 & 0x800) >> 0xb;
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = T7;
  sVar3 = DAT_00c4ca;
  sVar3 = (uVar2 >> 8) + sVar3;
  uVar2 = T7IC;
  if ((uVar2 & 0x80) != 0) {
    sVar3 = DAT_00c4ca;
    uVar2 = T7;
    sVar3 = sVar3 + 0x100 + (uVar2 >> 8);
  }
  if (uVar1 == 1) {
    uVar1 = PSW;
    PSW = uVar1 | 0x800;
  }
  else if (uVar1 == 0) {
    uVar1 = PSW;
    PSW = uVar1 & 0xf7ff;
  }
  return sVar3;
}

