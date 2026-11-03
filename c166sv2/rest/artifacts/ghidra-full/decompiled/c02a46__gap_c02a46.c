// c02a46 gap_c02a46 size=130 cc=unknown proto=undefined gap_c02a46(void)

void gap_c02a46(void)

{
  byte bVar1;
  byte bVar2;
  undefined2 *puVar3;
  ushort uVar4;
  
  bVar1 = bRame00001;
  if ((bRame00001 & 1) != 0) {
    bVar1 = bRame00001 + 1;
  }
  puVar3 = (undefined2 *)CONCAT11(uRame00003,uRame00004);
  uVar4 = (ushort)&UNK_00c700;
  for (bVar2 = 0; bVar2 < bVar1 >> 1; bVar2 = bVar2 + 1) {
    *(undefined2 *)(uint3)uVar4 = *puVar3;
    __service_watchdog();
    puVar3 = puVar3 + 1;
    uVar4 = uVar4 + 2;
  }
  return;
}

