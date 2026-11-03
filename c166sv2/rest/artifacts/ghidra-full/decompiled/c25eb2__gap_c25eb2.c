// c25eb2 gap_c25eb2 size=246 cc=unknown proto=undefined gap_c25eb2(void)

void gap_c25eb2(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  char cVar5;
  
  func_0xc25fa8();
  func_0xc25fd8();
  func_0xc26008();
  func_0xc26026();
  uVar1 = UNK_00cc15;
  gap_c24cb4(uVar1,uRame008d8,uRame00c1e,(short)&UNK_00cc18,(short)&UNK_00cc1c);
  uVar1 = UNK_00cc1f;
  gap_c24cb4(uVar1,uRame008d9,uRame00c1a,(short)&UNK_00cc20,(short)&UNK_00cc22);
  uVar2 = Ram00cc18;
  uVar3 = Ram00cc1c;
  gap_c24d1c(uVar2,uVar3,uRamc07d60,uRamc07d62,(short)&UNK_00cc15,(short)&UNK_00cc25);
  uVar2 = Ram00cc20;
  uVar3 = Ram00cc22;
  gap_c24d1c(uVar2,uVar3,uRamc07d5c,uRamc07d5e,(short)&UNK_00cc1f,(short)&UNK_00cc24);
  uVar1 = UNK_00cc15;
  uVar4 = UNK_00cc25;
  func_0xc24d82(4,uVar1,uVar4);
  uVar1 = UNK_00cc1f;
  uVar4 = UNK_00cc24;
  func_0xc24d82(3,uVar1,uVar4);
  cVar5 = func_0xc24530(4);
  if ((cVar5 == '\0') && (cVar5 = func_0xc24530(3), cVar5 == '\0')) {
    UNK_00cc16 = 0;
  }
  else {
    UNK_00cc16 = 1;
  }
  cVar5 = UNK_00cc1e;
  if ((cVar5 == '\0') && (cVar5 = UNK_00cc1a, cVar5 == '\0')) {
    UNK_00cc14 = 0;
    return;
  }
  UNK_00cc14 = 1;
  return;
}

