// c0e830 FUN_c0e830 size=100 cc=unknown proto=undefined FUN_c0e830(void)

/* WARNING: Removing unreachable block (ram,0xc0e864) */

void FUN_c0e830(short param_1)

{
  ushort uVar1;
  short sVar2;
  undefined1 uVar3;
  short *psVar4;
  
  param_1 = param_1 * 0x1a;
  psVar4 = (short *)((short)&UNK_00c3de + param_1);
  sVar2 = DAT_00c274;
  uVar3 = div32u(*(short *)ZEXT23(psVar4) - sVar2);
  uVar1 = (short)&UNK_00c3d8 + param_1;
  *(undefined1 *)(uint3)uVar1 = uVar3;
  *(ushort *)(uint3)(ushort)((short)&UNK_00c3dc + param_1) =
       *psVar4 + (ushort)*(byte *)(uint3)uVar1 * -0x780;
  return;
}

