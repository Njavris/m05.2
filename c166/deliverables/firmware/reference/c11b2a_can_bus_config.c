/* c11b2a can_bus_config */

/* CAN bus pin/mode configuration. */

void can_bus_config(void)

{
  ushort uVar1;
  undefined2 uVar2;
  
  uVar1 = DAT_00f0c2;
  if ((uVar1 & 0x1800) == 0x800) {
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x8e00;
  }
  uVar1 = DAT_00f0c2;
  if ((uVar1 & 0x1800) == 0x1800) {
    DAT_00f0c0 = 0xaaaa;
    PECC0 = 0x5554;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x9600;
    PECC0 = 0x800;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x8e00;
  }
  return;
}


