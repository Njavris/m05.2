// c1da6e gap_c1da6e size=170 cc=unknown proto=undefined gap_c1da6e(void)

void gap_c1da6e(undefined2 param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar2 = DAT_00c9d0;
  uVar2 = gap_c28544(0x50dc,0xc0,uVar2);
  uVar3 = gap_c28544(0x6d0c,0xc0,param_1);
  uVar2 = tbl2d_interp(0x70f6,0xc0,uVar2,uVar3);
  Ram00ca00 = uVar2;
  bVar1 = UNK_00c9e7;
  if (bRamc070f2 < bVar1) {
    uVar2 = FUN_c28852(bVar1,bRamc070f2);
  }
  else {
    uVar2 = 0;
  }
  uVar3 = Ram00ca00;
  uVar2 = func_0xc2849c(uVar3,uVar2,8);
  uVar4 = func_0xc27b86(uVar2,0x6400,0xf);
  uVar5 = uRamc070f4;
  if (uVar4 <= uRamc070f4) {
    uVar5 = uVar4;
  }
  uVar5 = func_0xc276a4(uVar5,param_1);
  Ram00c9f4 = uVar5;
  if (0x8000 < uVar5) {
    Ram00c9f4 = 0x8000;
  }
  return;
}

