// c0bd9e gap_c0bd9e size=4 cc=unknown proto=undefined gap_c0bd9e(void)

void gap_c0bd9e(void)

{
  ushort uVar1;
  
  if (DAT_c05080 == '\x01') {
    T4CON = 5;
    T4 = 0xff83;
    uVar1 = T4IC;
    T4IC = uVar1 | 0x61;
    uVar1 = DAT_00f138;
    DAT_00f138 = uVar1 & 0xfffd;
    uVar1 = DAT_00f13a;
    DAT_00f13a = uVar1 & 0xfffd;
    uVar1 = T4CON;
    T4CON = uVar1 | 0x40;
    DAT_00c3a4 = 0;
  }
  return;
}

