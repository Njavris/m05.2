// c2338a gap_c2338a size=84 cc=unknown proto=undefined gap_c2338a(void)

char gap_c2338a(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  ushort uVar4;
  char cVar5;
  ushort uVar6;
  
  uVar6 = 0;
  cVar5 = '\0';
  do {
    uVar4 = func_0xc2425c(uVar6);
    cVar3 = func_0xc24286(uVar6);
    if ((cVar3 != '\0') && (uVar1 = Ram00cb22, uVar1 <= uVar4)) {
      uVar1 = Ram00cb20;
      uVar2 = Ram00cb20;
      if ((uVar4 == uVar2 || uVar4 < uVar1) &&
         ((param_1 == '\x01' || ((param_1 == '\0' && (cVar3 = func_0xc24530(uVar6), cVar3 != '\0')))
          ))) {
        cVar5 = cVar5 + '\x01';
      }
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x27);
  return cVar5;
}

