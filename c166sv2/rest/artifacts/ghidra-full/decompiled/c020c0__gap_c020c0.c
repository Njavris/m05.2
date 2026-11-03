// c020c0 gap_c020c0 size=4 cc=unknown proto=undefined gap_c020c0(void)

void gap_c020c0(void)

{
  undefined4 uVar1;
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  uVar1 = boot_hidden_store32(auStack_4,4);
  uVar1 = boot_hidden_store32((short)uVar1,(short)((uint)uVar1 >> 0x10),auStack_8);
  boot_hidden_memcpy((short)uVar1,(short)((uint)uVar1 >> 0x10));
  boot_hidden_delay();
  return;
}

