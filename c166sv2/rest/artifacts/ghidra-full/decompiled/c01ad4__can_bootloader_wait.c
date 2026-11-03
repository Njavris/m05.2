// c01ad4 can_bootloader_wait size=78 cc=unknown proto=undefined can_bootloader_wait(void)

void can_bootloader_wait(void)

{
  undefined4 uVar1;
  undefined1 auStack_8 [4];
  undefined1 local_4 [4];
  
  can_diag_object_init();
  uVar1 = seg_to_ptr(local_4,4);
  uVar1 = seg_to_ptr((short)uVar1,(short)((uint)uVar1 >> 0x10),auStack_8);
  memcpy_wdt((short)uVar1,(short)((uint)uVar1 >> 0x10));
  __service_watchdog();
  ret_stub();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

