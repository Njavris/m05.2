// c13a9a gap_c13a9a size=270 cc=unknown proto=undefined gap_c13a9a(void)

void gap_c13a9a(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  
  bVar3 = DAT_00c5c4;
  bVar1 = *(byte *)(uint3)((short)&UNK_00f63e + (ushort)bVar3);
  cVar2 = *(char *)(uint3)((short)&UNK_00f63f + (ushort)bVar3);
  cVar5 = func_0xc131be();
  if (cVar5 != '\0') {
    func_0xc128ec(0x22);
    return;
  }
  cVar5 = UNK_00c578;
  if (cVar5 == '\x05') {
    if (((bVar1 < 0x90) && (0x7f < bVar1)) &&
       ((cVar2 == '\a' || ((cVar2 == -0x80 || (cVar2 == -0x7f)))))) {
      bVar1 = DAT_00c5c4;
      UNK_00c5e4 = *(undefined1 *)(uint3)((short)&UNK_00f641 + (ushort)bVar1);
LAB_c13b1e:
      bVar1 = DAT_00c5c4;
      UNK_00c5e3 = *(undefined1 *)(uint3)((short)&UNK_00f640 + (ushort)bVar1);
LAB_c13b4e:
      bVar1 = DAT_00c5c4;
      UNK_00c5e2 = *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1);
      UNK_00c5e1 = *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1);
      UNK_00c5e0 = 1;
      goto LAB_c13b7c;
    }
  }
  else {
    if (cVar5 != '\x04') {
      if (cVar5 != '\x03') {
        func_0xc128ec(0x12);
        goto LAB_c13b7c;
      }
      if (((0x8f < bVar1) || (bVar1 < 0x80)) ||
         ((cVar2 != '\0' && (((cVar2 != '\x01' && (cVar2 != '\x05')) && (cVar2 != -0x7e))))))
      goto LAB_c13b6a;
      goto LAB_c13b4e;
    }
    if (((bVar1 < 0x90) && (0x7f < bVar1)) &&
       ((cVar2 == '\a' || ((cVar2 == -0x80 || (cVar2 == -0x7f)))))) goto LAB_c13b1e;
  }
LAB_c13b6a:
  func_0xc128ec(0x31);
LAB_c13b7c:
  cVar2 = UNK_00c5e0;
  if (cVar2 == '\x01') {
    func_0xc13a92(0);
    cVar2 = UNK_00c5e1;
    if ((byte)(cVar2 + 0x80U) < 0x10) {
                    /* WARNING: Could not emulate address calculation at 0xc13ba4 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((ushort)(byte)(cVar2 + 0x80U) * 2 + 0x7194 & 0x3fff) | 0xc10000)
      )();
      return;
    }
    UNK_00c5e0 = 0;
    bVar1 = UNK_00c5e5;
    if (bVar1 < 4) {
      cVar2 = *(char *)(uint3)(bVar1 + 0x7190);
      if (((cVar2 == '\x12') || (cVar2 == '\"')) || (cVar2 == '1')) {
        func_0xc128ec(cVar2);
      }
      else {
        bVar1 = UNK_00c5c7;
        uVar4 = UNK_00c5e1;
        *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) = uVar4;
        uVar4 = UNK_00c5e2;
        *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1) = uVar4;
        cVar5 = UNK_00c5e2;
        if (cVar5 == '\0') {
          gap_c12910(3);
        }
        else {
          bVar1 = UNK_00c5c7;
          *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar1) = cVar2;
          gap_c12910(4);
        }
      }
    }
  }
  return;
}

