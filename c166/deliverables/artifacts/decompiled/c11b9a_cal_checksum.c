/* c11b9a cal_checksum */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Verify calibration block checksum 0xC05000-0xC0AFFD vs 0xC0AFFE. */

void cal_checksum(void)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar2 = 0x5000;
  _cal_checksum_accum = 0;
  for (uVar3 = 0xc0; uVar3 < 0xc0 || uVar3 == 0xc0 && uVar2 < 0xaffd; uVar3 = uVar3 + bVar1) {
    _cal_checksum_accum =
         _cal_checksum_accum + *(short *)((uint3)uVar2 + (uint3)uVar3 * 0x10000) * 0x100 +
         (*(ushort *)((uint3)uVar2 + (uint3)uVar3 * 0x10000) >> 8);
    bVar1 = 0xfffd < uVar2;
    uVar2 = uVar2 + 2;
  }
  _cal_checksum_valid = (ushort)(cal_checksum == _cal_checksum_accum);
  return;
}


