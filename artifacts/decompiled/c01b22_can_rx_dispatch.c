/* c01b22 can_rx_dispatch */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Dispatch received CAN message to ISO-TP transport. */

void can_rx_dispatch(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  if (_can_rx_object == 10) {
    uVar1 = can_msg_f744;
    uVar2 = can_msg_f745;
    _can_tx_remaining = CONCAT11(uVar1,uVar2);
    uVar1 = can_diag_rx_buffer;
    uVar2 = can_msg_f741;
    uVar3 = can_msg_f742;
    _can_rx_word_01 = CONCAT11(uVar1,uVar2);
    uVar1 = can_msg_f743;
    _can_rx_word_23 = CONCAT11(uVar3,uVar1);
    _can_tx_ptr = _can_rx_word_23;
    _can_tx_ptr_hi = _can_rx_word_01;
    can_rx_cmd();
  }
  if (_can_rx_object == 9) {
    can_isotp_send();
  }
  return;
}


