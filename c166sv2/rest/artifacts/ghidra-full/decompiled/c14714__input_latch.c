// c14714 input_latch size=36 cc=unknown proto=undefined input_latch(void)

void input_latch(void)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  uVar1 = input_status;
  uVar2 = DAT_00fd1c;
  uVar3 = DAT_00fd1c;
  DAT_00fd1c = uVar3 & 0xfffe | uVar1 >> 2 & 1;
  uVar1 = input_status;
  uVar2 = DAT_00fd1c;
  uVar3 = DAT_00fd1c;
  DAT_00fd1c = uVar3 & 0xfffd | (uVar1 >> 1 & 1) << 1;
  uVar1 = input_status;
  uVar2 = DAT_00fd1c;
  uVar3 = DAT_00fd1c;
  DAT_00fd1c = uVar3 & 0xfffb | (uVar1 & 1) << 2;
  return;
}

