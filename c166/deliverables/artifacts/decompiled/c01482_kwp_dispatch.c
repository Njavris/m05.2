/* c01482 kwp_dispatch */

/* KWP2000 service dispatcher (0x10/0x23/0x27/0x31/0x34/0x36/0x38/0x3D/0x83). */

void kwp_dispatch(void)

{
  if (kwp_request_pending == '\x01') {
    if (kwp_request == -0x7f) {
      kwp_sid81();
    }
    else if (ram_var_c148 == '\x10') {
      kwp_sid10_session();
    }
    else if (ram_var_c148 == -0x7d) {
      kwp_sid83();
    }
    else if (ram_var_c148 == '#') {
      kwp_sid23_read_mem();
    }
    else if (ram_var_c148 == '\'') {
      kwp_sid27_security();
    }
    else if (ram_var_c148 == '1') {
      kwp_sid31_routine();
    }
    else if (ram_var_c148 == '4') {
      kwp_sid34_download();
    }
    else if (ram_var_c148 == '6') {
      kwp_sid36_transfer();
    }
    else if (ram_var_c148 == '8') {
      kwp_sid38();
    }
    else if (ram_var_c148 == '=') {
      kwp_sid3D_write_mem();
    }
    else {
      kwp_negative();
    }
    kwp_request_pending = '\0';
    kline_frame_flag = 1;
  }
  return;
}


