/* c0e236 event_accum */

/* Accumulate event time. */

void event_accum(ushort param_1,short param_2)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  sVar3 = (param_1 & 0xff) * 0x12;
  uVar2 = param_2 - *(short *)(sVar3 + -0x3be6);
  if (uVar2 < 0x7f01) {
    uVar1 = *(ushort *)(uint3)(sVar3 + 0xc416U);
    *(ushort *)(uint3)(sVar3 + 0xc418) =
         *(short *)(uint3)(sVar3 + 0xc418) + (ushort)CARRY2(uVar1,uVar2);
    *(ushort *)(uint3)(sVar3 + 0xc416U) = uVar1 + uVar2;
    *(short *)ZEXT23((short *)(sVar3 + -0x3be6)) = param_2;
    *(byte *)(uint3)(sVar3 + 0xc41cU) = *(byte *)(uint3)(sVar3 + 0xc41cU) & 0x7f;
  }
  return;
}


