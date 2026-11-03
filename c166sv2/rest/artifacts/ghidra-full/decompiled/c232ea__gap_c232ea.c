// c232ea gap_c232ea size=160 cc=unknown proto=undefined gap_c232ea(void)

byte gap_c232ea(undefined2 param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  
  cVar1 = func_0xc24286();
  bVar2 = func_0xc24530(param_1);
  bVar3 = func_0xc2446c(param_1);
  bVar4 = gap_c244ce(param_1);
  bVar5 = func_0xc2465c(param_1);
  bVar2 = cVar1 != '\0' | (bVar2 & 1) << 1 | (bVar3 & 1) << 2 | (bVar4 & 1) << 3 | (bVar5 & 1) << 4;
  cVar1 = func_0xc2440a(param_1);
  if (cVar1 == '\0') {
    bVar2 = bVar2 | 0x20;
  }
  bVar3 = FUN_c243a8(param_1);
  cVar1 = func_0xc245fa(param_1);
  return bVar2 | (bVar3 & 1) << 6 | cVar1 << 7;
}

