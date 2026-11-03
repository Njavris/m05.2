// c03de2 boot_hidden_store32 size=22 cc=unknown proto=undefined boot_hidden_store32(void)

undefined4 boot_hidden_store32(void)

{
  ushort uVar1;
  ushort in_r4;
  
  uVar1 = *(ushort *)(uint3)((in_r4 >> 0xe) * 2 - 0x200);
  return CONCAT22(uVar1 >> 2,in_r4 & 0x3fff | (uVar1 & 1) << 0xe | ((uVar1 & 2) >> 1) << 0xf);
}

