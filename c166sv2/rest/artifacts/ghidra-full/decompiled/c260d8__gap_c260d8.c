// c260d8 gap_c260d8 size=314 cc=unknown proto=undefined gap_c260d8(void)

void gap_c260d8(void)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  char cVar5;
  
  func_0xc26212();
  FUN_c19846();
  uVar2 = UNK_00cc2a;
  gap_c24cb4(uVar2,uRame008df,cRame008dd,(short)&UNK_00cc34,(short)&UNK_00cc2e);
  uVar2 = UNK_00cc37;
  gap_c24cb4(uVar2,uRame008de,cRame008dc,(short)&UNK_00cc28,(short)&UNK_00cc30);
  uVar3 = Ram00cc34;
  uVar1 = Ram00cc2e;
  gap_c24d1c(uVar3,uVar1,uRamc07d7c,uRamc07d7e,(short)&UNK_00cc2a,(short)&UNK_00cc33);
  uVar1 = Ram00cc28;
  uVar3 = Ram00cc30;
  gap_c24d1c(uVar1,uVar3,uRamc07d78,uRamc07d7a,(short)&UNK_00cc37,(short)&UNK_00cc36);
  uVar2 = UNK_00cc2a;
  uVar4 = UNK_00cc33;
  func_0xc24d82(6,uVar2,uVar4);
  uVar4 = UNK_00cc37;
  uVar2 = UNK_00cc36;
  func_0xc24d82(5,uVar4,uVar2);
  cVar5 = func_0xc24530(6);
  if ((((cVar5 == '\0') && (cVar5 = func_0xc24530(5), cVar5 == '\0')) && (cRame008dd == '\0')) &&
     (cRame008dc == '\0')) {
    UNK_00cc38 = 0;
  }
  else {
    UNK_00cc38 = 1;
  }
  cVar5 = func_0xc24530(6);
  if ((cVar5 == '\0') && (cVar5 = func_0xc24530(5), cVar5 == '\0')) {
    UNK_00cc32 = 0;
    UNK_00cc2b = 0;
  }
  else {
    UNK_00cc32 = 1;
    UNK_00cc2b = 1;
  }
  if ((cRame008dd == '\0') && (cRame008dc == '\0')) {
    UNK_00cc2c = 0;
    return;
  }
  UNK_00cc2c = 1;
  return;
}

