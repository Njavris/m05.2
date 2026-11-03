// c18c5c gap_c18c5c size=44 cc=unknown proto=undefined gap_c18c5c(void)

void gap_c18c5c(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  
  uVar4 = Ram00c984;
  uVar4 = tbl16_interp(0x636c,0xc0,uVar4);
  Ram00c84e = uVar4;
  uVar3 = DAT_00ca2a;
  uVar1 = Ram00c84e;
  uVar2 = Ram00c84e;
  if (uVar3 != uVar2 && uVar1 <= uVar3) {
    UNK_00c851 = 0;
    return;
  }
  UNK_00c851 = 1;
  return;
}

