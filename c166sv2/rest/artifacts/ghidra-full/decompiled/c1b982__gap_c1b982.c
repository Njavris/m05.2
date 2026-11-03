// c1b982 gap_c1b982 size=138 cc=unknown proto=undefined gap_c1b982(void)

void gap_c1b982(void)

{
  undefined2 uVar1;
  char cVar2;
  undefined2 uVar3;
  
  uVar1 = uRamc06b8e;
  uRame00834 = 0;
  uVar3 = func_0xc27b86(0,0x8000,0xf);
  Ram00c98c = uVar3;
  uVar3 = FUN_c28852(0x8000,uVar3);
  Ram00c98c = uVar3;
  func_0xc14c70(0,uVar1,uVar3);
  if (cRamc0506d == '\x01') {
    uVar3 = Ram00c98c;
    func_0xc14c70(5,uVar1,uVar3);
  }
  cVar2 = cRame00811;
  if (DAT_e00810 == '\x01') {
    func_0xc14cec(0);
  }
  if ((cRamc0506d == '\x01') && (cVar2 == '\x01')) {
    func_0xc14cec(5);
  }
  return;
}

