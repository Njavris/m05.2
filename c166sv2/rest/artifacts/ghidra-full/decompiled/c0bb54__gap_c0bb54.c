// c0bb54 gap_c0bb54 size=112 cc=unknown proto=undefined gap_c0bb54(void)

void gap_c0bb54(byte param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  short sVar1;
  char cVar2;
  ushort uVar3;
  
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x1fc;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003b54;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + CONCAT11(uRam000003,sRam000001._1_1_);
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x3a0;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003d9e;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + CONCAT11((undefined1)sRam000004,uRam000003);
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x492;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003fd8;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + sRam000001;
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x4cc;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003fda;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + sRam000001;
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x506;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003fdc;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + CONCAT11(uRam000003,sRam000001._1_1_);
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x546;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003fde;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + sRam000004;
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x550;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003ff2;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + CONCAT11(uRam000003,sRam000001._1_1_);
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x5fe;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003ffa;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + sRam000004;
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x3d1e;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003ffe;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + CONCAT11(uRam000003,sRam000001._1_1_);
  uVar3 = PSW;
  PSW = uVar3 & 0xf7ff;
  sVar1 = (ushort)param_1 * 0x12;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c412 + sVar1) = param_2;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c414 + sVar1) = param_3;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c410 + sVar1) = param_4;
  DAT_00c40c = *(undefined2 *)((short)&stack0x0000 * 4);
  DAT_00c400 = ((undefined2 *)((short)&stack0x0000 * 4))[1];
  event_schedule(param_1);
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  return;
}

