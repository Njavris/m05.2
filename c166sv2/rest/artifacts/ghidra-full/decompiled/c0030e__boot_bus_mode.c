// c0030e boot_bus_mode size=112 cc=unknown proto=undefined boot_bus_mode(void)

void boot_bus_mode(void)

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
    DAT_00f0c0 = 0x5554;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x9600;
    DAT_00f0c0 = 0x800;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x8e00;
  }
  return;
}

