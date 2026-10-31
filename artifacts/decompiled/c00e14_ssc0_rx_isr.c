/* c00e14 ssc0_rx_isr */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* SSC0 receive interrupt; 7-byte frame engine. */

void ssc0_rx_isr(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  byte bVar16;
  
  isr_save_fc60 = &stack0x0000;
  uVar7 = DPP0;
  DPP0 = 0x300;
  uVar8 = DPP2;
  DPP2 = 0x302;
  uVar15 = DAT_00ffde;
  uVar9 = DAT_00fe5c;
  uVar10 = DAT_00fe5e;
  uVar14 = DAT_00ffdc;
  uVar13 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar11 = DAT_00ff08;
  uVar12 = DAT_00ff0a;
  uVar2 = DAT_00f000;
  uVar3 = DAT_00f002;
  uVar4 = DAT_00f004;
  uVar5 = DPP3;
  uVar6 = SSCRB;
  *(undefined1 *)(uint3)_ssc_tx_ptr = uVar6;
  ssc_frame_bytes = ssc_frame_bytes + -1;
  if (ssc_frame_bytes == '\0') {
    uVar1 = P1H;
    P1H = uVar1 | 8;
    bVar16 = 0;
    do {
      uVar1 = (ushort)bVar16;
      bVar16 = bVar16 + 1;
      *(undefined1 *)(uint3)(uVar1 + 0xc082) = *(undefined1 *)(uint3)((short)&ssc_rx_frame + uVar1);
    } while (bVar16 < 7);
    ssc_frame_bytes = '\a';
    _ssc_rx_ptr = (short)&boot_port_cfg_c08c;
    _ssc_tx_ptr = (ushort)&ssc_rx_frame;
  }
  else {
    _ssc_rx_ptr = _ssc_rx_ptr + 1;
    _ssc_tx_ptr = _ssc_tx_ptr + 1;
    ssc_send_byte(_ssc_rx_ptr,uVar5,uVar4,uVar3,uVar2,uVar12,uVar11,uVar13,uVar14,uVar10,uVar9,
                  uVar15,uVar8,uVar7);
  }
  DAT_00f006 = uVar5;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  DAT_00f004 = uVar4;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  DAT_00f002 = uVar3;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DAT_00ff0a = uVar12;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  DAT_00ff08 = uVar11;
  uVar2 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  DAT_00ffda = uVar13;
  uVar2 = DAT_00ffda;
  uVar2 = DAT_00ffda;
  uVar2 = DAT_00ffda;
  DAT_00ffdc = uVar14;
  uVar2 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  DAT_00fe5e = uVar10;
  uVar2 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  DAT_00fe5c = uVar9;
  uVar2 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  DAT_00ffde = uVar15;
  uVar2 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  DPP2 = uVar8;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar7;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}


