/* c01c6e can_isotp_send */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Send up to 8 bytes over the diagnostic CAN message object. */

void can_isotp_send(void)

{
  bool bVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  if ((can_tx_active != '\0') && (_can_tx_remaining != 0)) {
    uVar2 = _can_tx_remaining;
    if (8 < _can_tx_remaining) {
      uVar2 = 8;
    }
    uVar3 = seg_to_ptr(_can_tx_ptr,_can_tx_ptr_hi,(short)&can_diag_rx_buffer,uVar2);
    memcpy_wdt((short)uVar3,(short)((uint)uVar3 >> 0x10));
    _can_tx_remaining = _can_tx_remaining - uVar2;
    bVar1 = CARRY2(_can_tx_ptr,uVar2);
    _can_tx_ptr = _can_tx_ptr + uVar2;
    _can_tx_ptr_hi = _can_tx_ptr_hi + (ushort)bVar1;
    if (_can_tx_remaining == 0) {
      can_tx_active = '\0';
    }
  }
  return;
}


