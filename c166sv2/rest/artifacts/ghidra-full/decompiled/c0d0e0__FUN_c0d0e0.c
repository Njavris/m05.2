// c0d0e0 FUN_c0d0e0 size=74 cc=unknown proto=undefined FUN_c0d0e0(void)

void FUN_c0d0e0(byte param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar1 = DAT_00c374;
  uVar2 = DAT_00c37e;
  capcom_event_config2
            (param_1,*(undefined2 *)(uint3)((short)&DAT_00c384 + (ushort)param_1 * 4),
             *(undefined2 *)(uint3)((short)&DAT_00c386 + (ushort)param_1 * 4),
             *(undefined2 *)(uint3)((short)&UNK_00c36a + (ushort)param_1 * 2),uVar2,uVar1);
  *(undefined2 *)(uint3)((short)&DAT_00c416 + (ushort)param_1 * 0x12) = 0;
  *(undefined2 *)(uint3)((short)&DAT_00c418 + (ushort)param_1 * 0x12) = 0;
  return;
}

