// c233de gap_c233de size=104 cc=unknown proto=undefined gap_c233de(void)

undefined2 gap_c233de(undefined2 param_1,char param_2)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  undefined1 uVar4;
  ushort uVar5;
  
  Ram00cb1a = 0;
  UNK_00cb1d = 0;
  UNK_00cb1e = 0;
  uVar5 = func_0xc2425c(param_1);
  cVar3 = func_0xc24286(param_1);
  if ((cVar3 != '\0') && (uVar1 = Ram00cb22, uVar1 <= uVar5)) {
    uVar1 = Ram00cb20;
    uVar2 = Ram00cb20;
    if ((uVar5 == uVar2 || uVar5 < uVar1) &&
       ((param_2 == '\x01' || ((param_2 == '\0' && (cVar3 = func_0xc24530(param_1), cVar3 != '\0')))
        ))) {
      uVar4 = func_0xc231e0(param_1);
      Ram00cb1a = uVar5;
      UNK_00cb1d = uVar4;
      UNK_00cb1e = 1;
    }
  }
  return (short)&UNK_00cb1a;
}

