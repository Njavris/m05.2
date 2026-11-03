// c00daa gap_c00daa size=4 cc=unknown proto=undefined gap_c00daa(void)

void gap_c00daa(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd00;
  DAT_00fd00 = uVar1 | 0x8000;
  DAT_00c080 = 0xffff;
  DAT_00c092 = 2;
  DAT_00c091 = 0;
  DAT_00c090 = 0;
  DAT_00c08f = 0x1f;
  DAT_00c08e = 0;
  DAT_00c08d = 0;
  DAT_00c08c = 0;
  ssc_start_frame();
  return;
}

