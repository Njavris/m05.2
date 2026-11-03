// c020c4 boot_hidden_copy size=70 cc=unknown proto=undefined boot_hidden_copy(void)

void boot_hidden_copy(void)

{
  undefined4 uVar1;
  
  uVar1 = boot_hidden_store32(&stack0x0004,4);
  uVar1 = boot_hidden_store32((short)uVar1,(short)((uint)uVar1 >> 0x10),&stack0x0000);
  boot_hidden_memcpy((short)uVar1,(short)((uint)uVar1 >> 0x10));
  boot_hidden_delay();
  return;
}

