// c0faa2 FUN_c0faa2 size=44 cc=unknown proto=undefined FUN_c0faa2(void)

undefined2 FUN_c0faa2(short param_1)

{
  char cVar1;
  undefined2 uVar2;
  
  uVar2 = 0;
  cVar1 = DAT_00c456;
  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
    uVar2 = DAT_00c448;
    cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + param_1 * 2),param_1,uVar2)
    ;
    uVar2 = 1;
    cVar1 = DAT_00c456;
    DAT_00c456 = cVar1 + '\x01';
  }
  return uVar2;
}

