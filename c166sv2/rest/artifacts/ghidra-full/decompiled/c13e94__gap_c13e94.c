// c13e94 gap_c13e94 size=156 cc=unknown proto=undefined gap_c13e94(void)

void gap_c13e94(void)

{
  undefined2 uVar1;
  
  uVar1 = gap_c10398(3);
  Ram00c5ec = uVar1;
  uVar1 = gap_c10398(2);
  Ram00c5ee = uVar1;
  uVar1 = gap_c10398(4);
  Ram00c5f0 = uVar1;
  uVar1 = gap_c10398(6);
  Ram00c5f2 = uVar1;
  uVar1 = gap_c10398(0);
  Ram00c5f6 = uVar1;
  uVar1 = gap_c10398(5);
  Ram00c5f4 = uVar1;
  if (sRamc05066 == 0) {
    uVar1 = gap_c10398(1);
    Ram00c5fc = uVar1;
    Ram00c5f8 = 0;
  }
  else {
    Ram00c5fc = 0;
    uVar1 = gap_c10398(1);
    Ram00c5f8 = uVar1;
  }
  if (DAT_c05068 == 1) {
    uVar1 = gap_c10398(0xf);
    Ram00c5fc = uVar1;
    Ram00c5fa = 0;
    return;
  }
  if (DAT_c05068 == 2) {
    Ram00c5fc = 0;
    uVar1 = gap_c10398(0xf);
    Ram00c5fa = uVar1;
  }
  return;
}

