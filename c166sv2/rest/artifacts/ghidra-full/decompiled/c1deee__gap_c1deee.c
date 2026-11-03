// c1deee gap_c1deee size=210 cc=unknown proto=undefined gap_c1deee(void)

void gap_c1deee(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  
  UNK_00ca3c = 0;
  cVar1 = UNK_00c702;
  if (cVar1 == '\0') {
    uVar2 = Ram00c008;
    uVar2 = func_0xc276a4(uVar2,uRamc07090);
    gap_c166a2((short)&UNK_00c008,uVar2);
  }
  else {
    gap_c166a2((short)&UNK_00c008,uRamc07098);
  }
  Ram00ca26 = 0;
  uVar3 = FUN_c13dc8(5);
  Ram00ca38 = uVar3;
  uVar2 = Ram00c008;
  uVar2 = func_0xc28a54(uVar3,uVar2,1,1);
  uVar4 = func_0xc2849c(uRamc0709c,uVar2,0xe);
  if (uVar4 == 0) {
    uVar4 = 0;
  }
  if (uVar4 < 0x8001) {
    DAT_00ca2a = uVar4;
  }
  else {
    DAT_00ca2a = 0x8000;
  }
  if (cRamc0507b == '\x01') {
    uVar2 = Ram00ca0a;
    uVar2 = gap_c28544(0x51aa,0xc0,uVar2);
    uVar2 = tbl8_interp(0x6d48,0xc0,uVar2);
    DAT_00ca2a = uVar2;
  }
  uVar2 = DAT_00ca2a;
  Ram00ca3a = uVar2;
  Ram00ca2c = uVar2;
  Ram00ca2e = uVar2;
  Ram00ca30 = 0;
  Ram00ca20 = uVar2;
  return;
}

