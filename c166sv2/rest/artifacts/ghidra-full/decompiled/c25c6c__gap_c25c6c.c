// c25c6c gap_c25c6c size=310 cc=unknown proto=undefined gap_c25c6c(void)

void gap_c25c6c(void)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  char cVar5;
  
  func_0xc25da2();
  func_0xc25e00();
  uVar2 = UNK_00cc08;
  gap_c24cb4(uVar2,uRame008d6,cRame00700,(short)&UNK_00cc0c,(short)&UNK_00cc04);
  uVar2 = UNK_00cc10;
  gap_c24cb4(uVar2,uRame008d7,cRame006fe,(short)&UNK_00cc0e,(short)&UNK_00cc06);
  uVar4 = Ram00cc0c;
  uVar1 = Ram00cc04;
  gap_c24d1c(uVar4,uVar1,uRamc07d3c,uRamc07d3e,(short)&UNK_00cc08,(short)&UNK_00cc0a);
  uVar4 = Ram00cc0e;
  uVar1 = Ram00cc06;
  gap_c24d1c(uVar4,uVar1,uRamc07d38,uRamc07d3a,(short)&UNK_00cc10,(short)&UNK_00cc09);
  uVar2 = UNK_00cc08;
  uVar3 = UNK_00cc0a;
  func_0xc24d82(2,uVar2,uVar3);
  uVar3 = UNK_00cc10;
  uVar2 = UNK_00cc09;
  func_0xc24d82(1,uVar3,uVar2);
  cVar5 = func_0xc24530(1);
  if ((cVar5 == '\0') && (cVar5 = func_0xc24530(2), cVar5 == '\0')) {
    uRame006fc = 0;
  }
  else {
    uRame006fc = 1;
  }
  cVar5 = func_0xc24530(1);
  if ((cVar5 == '\0') && (cVar5 = func_0xc24530(2), cVar5 == '\0')) {
    uRame006fd = 0;
  }
  else {
    uRame006fd = 1;
  }
  if ((cRame00700 == '\0') && (cRame006fe == '\0')) {
    uRame006ff = 0;
    return;
  }
  uRame006ff = 1;
  return;
}

