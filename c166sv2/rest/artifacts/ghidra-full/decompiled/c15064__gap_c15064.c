// c15064 gap_c15064 size=106 cc=unknown proto=undefined gap_c15064(void)

void gap_c15064(byte param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined1 auStack_4 [2];
  
  UNK_00c63a = (char)((ushort)*(undefined2 *)(uint3)((ushort)param_1 * 0xc + 0x73e6) >> 8);
  func_0xc150f2(param_1);
  if (*(char *)(uint3)((short)&UNK_00c667 + (ushort)param_1) != '\0') {
    func_0xc154fa(param_1);
    uVar1 = (short)&UNK_00c67c + (ushort)param_1 * 2;
    uVar2 = func_0xc150ce(param_1);
    gap_c24d9a(uVar2,*(ushort *)(uint3)uVar1 & 1,*(ushort *)(uint3)uVar1 >> 1 & 1,auStack_4);
  }
  return;
}

