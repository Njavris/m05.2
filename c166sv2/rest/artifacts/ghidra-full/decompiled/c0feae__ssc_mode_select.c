// c0feae ssc_mode_select size=82 cc=unknown proto=undefined ssc_mode_select(void)

void ssc_mode_select(void)

{
  DAT_00c484 = 4;
  DAT_00c48c = 0;
  if (DAT_c06b68 == '\0') {
    DAT_00c48a = 1;
    if (DAT_c05036 == '\x01') {
      DAT_00c48a = 0;
      DAT_00c48c = 1;
      return;
    }
    if (DAT_c05036 == '\x02') {
      DAT_00c484 = 10;
      return;
    }
    if (DAT_c05036 == '\x03') {
      DAT_00c484 = 8;
      return;
    }
  }
  else {
    DAT_00c48a = 0;
  }
  return;
}

