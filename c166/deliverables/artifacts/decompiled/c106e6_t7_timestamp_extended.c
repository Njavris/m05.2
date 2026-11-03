/* c106e6 t7_timestamp_extended */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Returns a T7 timestamp extended by the T7 overflow flag. */

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
  sVar3 = (uVar2 >> 8) + _t7_offset_extended;
  uVar2 = T7IC;
  if ((uVar2 & 0x80) != 0) {
    uVar2 = T7;
    sVar3 = _t7_offset_extended + 0x100 + (uVar2 >> 8);
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


