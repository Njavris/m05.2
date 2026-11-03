// c26baa gap_c26baa size=64 cc=unknown proto=undefined gap_c26baa(void)

void gap_c26baa(void)

{
  char cVar1;
  ushort uVar2;
  
  uVar2 = 0x7a9c;
  do {
    if (0x26 < *(short *)(uint3)uVar2) {
      UNK_00cc7e = 0;
LAB_c26be0:
      gap_c26a3a();
      return;
    }
    cVar1 = func_0xc24530(*(undefined2 *)(uint3)uVar2);
    if ((cVar1 != '\0') && (cVar1 = func_0xc24e0a(*(undefined2 *)(uint3)uVar2), cVar1 == '\0')) {
      UNK_00cc7e = 1;
      goto LAB_c26be0;
    }
    uVar2 = uVar2 + 2;
  } while( true );
}

