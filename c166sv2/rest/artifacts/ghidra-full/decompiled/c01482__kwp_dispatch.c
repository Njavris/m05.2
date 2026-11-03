// c01482 kwp_dispatch size=154 cc=unknown proto=undefined kwp_dispatch(void)

void kwp_dispatch(void)

{
  char cVar1;
  
  cVar1 = DAT_00c1d1;
  if (cVar1 == '\x01') {
    cVar1 = DAT_00c147;
    if (cVar1 == -0x7f) {
      kwp_sid81();
    }
    else {
      cVar1 = DAT_00c148;
      if (cVar1 == '\x10') {
        kwp_sid10_session();
      }
      else if (cVar1 == -0x7d) {
        kwp_sid83();
      }
      else if (cVar1 == '#') {
        kwp_sid23_read_mem();
      }
      else if (cVar1 == '\'') {
        kwp_sid27_security();
      }
      else if (cVar1 == '1') {
        kwp_sid31_routine();
      }
      else if (cVar1 == '4') {
        kwp_sid34_download();
      }
      else if (cVar1 == '6') {
        kwp_sid36_transfer();
      }
      else if (cVar1 == '8') {
        kwp_sid38();
      }
      else if (cVar1 == '=') {
        kwp_sid3D_write_mem();
      }
      else {
        kwp_negative();
      }
    }
    DAT_00c1d1 = 0;
    DAT_00c13c = 1;
  }
  return;
}

