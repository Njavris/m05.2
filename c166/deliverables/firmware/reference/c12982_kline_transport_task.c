/* c12982 kline_transport_task */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line transport state machine; state 0xC584 selects a handler table at 0x7164. */

void kline_transport_task(short param_1,undefined2 param_2)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  
  if (param_1 == 0) {
    kline_state_reset(6);
    uVar1 = S0CON;
    S0CON = uVar1 & 0xffef;
    kline_start_timeout();
    kline_var_c5ab = '\0';
    kline_var_c568 = '\0';
    empty_stub_2();
    store32();
    test_command_clear();
  }
  else if (param_1 == 1) {
    if (_kline_state < 0x10) {
                    /* WARNING: Could not emulate address calculation at 0xc129d2 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((short)&kline_handler_table + _kline_state * 2 & 0x3fff) |
                0xc10000))();
      return;
    }
    if (_kline_timeout != 0) {
      _kline_timeout = _kline_timeout + -1;
    }
    if ((_kline_state != 0xd) && (_kline_state != 10)) {
      if (kline_var_c5ab != '\0') {
        uVar1 = PSW;
        PSW = uVar1 & 0xf7ff;
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      param_2 = 0;
    }
    if (kline_flag_c57d == '\0') {
      kline_var_c568 = '\0';
    }
    else if (kline_var_c568 == '\0') {
      kline_var_c568 = '\x01';
      empty_stub_1(param_2);
    }
    if ((((kline_var_c5b6 == '\0') && (cVar3 = kline_get_status(), cVar3 == '\0')) ||
        (_kline_state == 0xd)) || (_kline_state == 10)) {
      if (_kline_state == 9) {
        bVar2 = false;
        for (kline_var_c56c = 0; kline_var_c56c <= kline_table_count;
            kline_var_c56c = kline_var_c56c + 1) {
          if (*(char *)(uint3)((ushort)kline_var_c56c * 10 + 0x70c2) ==
              *(char *)(uint3)((short)&UNK_00f63d + (ushort)kline_var_c5c4)) {
            empty_stub_0();
            bVar2 = true;
            break;
          }
        }
        if (!bVar2) {
          empty_stub_0();
        }
      }
    }
    else {
      empty_stub_0();
    }
  }
  return;
}


