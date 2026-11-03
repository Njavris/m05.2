/* c00434 can_twincan_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* TwinCAN initialization; message object 0 ID 0x7E0/0x7E4 (diagnostic). */

void can_twincan_init(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  
  _can_rx_flag = 0;
  _DAT_200200 = 0;
  _DAT_200210 = 0;
  _DAT_200222 = 0x60;
  uVar2 = DAT_00ff38;
  DAT_00ff38 = uVar2 | 8;
  uVar2 = BUSCON3;
  BUSCON3 = uVar2 & 0xfff7 | 8;
  uVar2 = DAT_00ff3a;
  DAT_00ff3a = uVar2 | 8;
  _DAT_20020c = 0x2387;
  _DAT_20020e = 0;
  _DAT_200214 = 0;
  _DAT_200216 = 0;
  _DAT_200314 = 0x80;
  _DAT_200316 = _DAT_200516 & 0xfff8;
  _DAT_20030c = 0xffff;
  _DAT_20030e = 0xffff;
  _DAT_200308 = 0;
  _DAT_20030a = 0x1f80;
  _DAT_200300 = 0;
  _DAT_200302 = 0;
  _DAT_200304 = 0;
  _DAT_200306 = 0;
  _DAT_200318 = 0;
  _DAT_20031a = _DAT_20031a & 0xffe0;
  _DAT_200310 = 0x1599;
  _DAT_200312 = 0;
  _DAT_200514 = 0x88;
  _DAT_200516 = _DAT_200356 & 0xfff8 | 2;
  _DAT_20050c = 0xffff;
  _DAT_20050e = 0xffff;
  _DAT_200508 = 0;
  _DAT_20050a = 0x1f90;
  _DAT_200500 = 0;
  _DAT_200502 = 0;
  _DAT_200504 = 0;
  _DAT_200506 = 0;
  _DAT_200518 = 0x200f;
  _DAT_20051a = 0x210;
  _DAT_200510 = 0x1595;
  _DAT_200512 = 0;
  bVar3 = 0;
  do {
    sVar1 = (ushort)bVar3 * 0x20;
    *(undefined2 *)((uint3)(sVar1 + 0x534) + 0x200000) = 8;
    *(undefined2 *)((uint3)(sVar1 + 0x536) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x52c) + 0x200000) = 0xffff;
    *(undefined2 *)((uint3)(sVar1 + 0x52e) + 0x200000) = 0xffff;
    *(undefined2 *)((uint3)(sVar1 + 0x528) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x52a) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x520) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x522) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x524) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x526) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x538) + 0x200000) = 0x200f;
    *(undefined2 *)((uint3)(sVar1 + 0x53a) + 0x200000) = 0x310;
    *(undefined2 *)((uint3)(sVar1 + 0x530) + 0x200000) = 0x1595;
    *(undefined2 *)((uint3)(sVar1 + 0x532) + 0x200000) = 0;
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0xf);
  uVar2 = XP2IC;
  XP2IC = uVar2 | 8;
  uVar2 = CC15IC;
  CC15IC = uVar2 | 0x40;
  ram_var_c000 = 0x10;
  _DAT_200004 = 0xb;
  _DAT_200200 = _DAT_200200 & 0xffbe;
  return;
}


