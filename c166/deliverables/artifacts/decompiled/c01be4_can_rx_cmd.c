/* c01be4 can_rx_cmd */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAN diagnostic receive command handling. */

void can_rx_cmd(void)

{
  bool bVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  
  cVar2 = can_msg_f746;
  if (cVar2 == -1) {
    can_tx_confirm();
    while (_can_tx_remaining != 0) {
      uVar3 = _can_tx_remaining;
      if (8 < _can_tx_remaining) {
        uVar3 = 8;
      }
      uVar4 = seg_to_ptr((short)&xram_var_f750,uVar3);
      memcpy_wdt((short)uVar4,(short)((uint)uVar4 >> 0x10),_can_tx_ptr,_can_tx_ptr_hi);
      can_tx_frame(uVar3);
      _can_tx_remaining = _can_tx_remaining - uVar3;
      bVar1 = CARRY2(_can_tx_ptr,uVar3);
      _can_tx_ptr = _can_tx_ptr + uVar3;
      _can_tx_ptr_hi = _can_tx_ptr_hi + (ushort)bVar1;
      __service_watchdog();
    }
  }
  else {
    cVar2 = can_msg_f746;
    if ((cVar2 == '\0') && (_can_tx_remaining != 0)) {
      can_tx_active = 1;
      can_tx_confirm();
    }
  }
  return;
}


