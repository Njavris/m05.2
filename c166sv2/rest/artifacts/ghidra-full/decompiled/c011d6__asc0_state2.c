// c011d6 asc0_state2 size=2 cc=unknown proto=undefined asc0_state2(void)

void asc0_state2(void)

{
  ushort uVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  
  while (uVar1 = S0RIC, (uVar1 & 0x80) != 0) {
    uVar4 = asc0_read_rx_clear();
    bVar2 = DAT_00c0ae;
    uVar1 = (short)&DAT_00c144 + (ushort)bVar2;
    *(undefined1 *)(uint3)uVar1 = uVar4;
    if (*(char *)(uint3)uVar1 == *(char *)(uint3)((short)&UNK_00c0a3 + (ushort)bVar2)) {
      cVar3 = DAT_00c0ae;
      if (cVar3 == '\x04') {
        cVar3 = DAT_00c0af;
        DAT_00c0af = cVar3 + '\x01';
        DAT_00c1d1 = 1;
      }
      else {
        cVar3 = DAT_00c0ae;
        DAT_00c0ae = cVar3 + '\x01';
      }
    }
    else {
      DAT_00c0af = 1;
    }
  }
  return;
}

