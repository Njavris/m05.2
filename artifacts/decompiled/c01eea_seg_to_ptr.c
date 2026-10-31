/* c01eea seg_to_ptr */

/* Convert 16-bit pointer/DPP offset into a 24-bit pointer. */

undefined4 seg_to_ptr(void)

{
  ushort uVar1;
  ushort in_r4;
  
  uVar1 = *(ushort *)(uint3)((in_r4 >> 0xe) * 2 - 0x200);
  return CONCAT22(uVar1 >> 2,in_r4 & 0x3fff | (uVar1 & 1) << 0xe | ((uVar1 & 2) >> 1) << 0xf);
}


