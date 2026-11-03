/* c0cd24 speed_timing_calc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Maps engine speed input 0xC9D0 through axis 0x7000 and tables 0x504C/0x5038. */

void speed_timing_calc(void)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  bVar1 = (byte)(speed_sample_counter + 1) < speed_sample_counter;
  speed_sample_counter = speed_sample_counter + 1;
  if (bVar1) {
    speed_sample_counter = 0xff;
  }
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = input_status_flags;
  uVar3 = input_status_flags;
  input_status_flags = uVar3 & 0xffbf;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = speed_status_flags;
  speed_status_flags = uVar3 & 0xbfff | (uVar2 >> 6 & 1) << 0xe;
  uVar2 = speed_status_flags;
  if ((uVar2 & 0x4000) != 0) {
    uVar2 = speed_status_flags;
    speed_status_flags = uVar2 | 0x8000;
  }
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = input_status_flags;
  uVar3 = input_status_flags;
  input_status_flags = uVar3 & 0xf7ff;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = speed_status_flags;
  speed_status_flags = uVar3 & 0xdfff | (uVar2 >> 0xb & 1) << 0xd;
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = input_status_flags;
  uVar3 = input_status_flags;
  input_status_flags = uVar3 & 0xfdff;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = speed_status_flags;
  speed_status_flags = uVar3 & 0xefff | (uVar2 >> 9 & 1) << 0xc;
  uVar2 = speed_status_flags;
  if ((uVar2 & 0x1000) != 0) {
    uVar2 = speed_status_flags;
    speed_status_flags = uVar2 & 0xf3ff | 0xc00;
  }
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  _speed_axis_index = axis16_unsigned(0x7000,_engine_speed_input);
  _speed_table_504c = tbl16_interp(0x504c,0xc0,_speed_axis_index);
  _speed_table_5038 = tbl16_interp(0x5038,0xc0,_speed_axis_index);
  return;
}


