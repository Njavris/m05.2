/* c0190c kwp_sid3D_write_mem */

/* KWP service 0x3D write memory by address. */

void kwp_sid3D_write_mem(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar2 = (ushort)kwp_request_addr_lo;
  uVar3 = (ushort)kwp_request_addr_hi;
  uVar1 = uVar3 * 0x100 + (ushort)kwp_request_addr_mid;
  uVar3 = ((ushort)CARRY2((ushort)ram_var_c149 * 0x100,uVar3) * 0x100 |
          (ushort)ram_var_c149 * 0x100 + uVar3 >> 8) +
          (ushort)CARRY2(uVar3 * 0x100,(ushort)kwp_request_addr_mid);
  if (((0xdf < uVar3) &&
      (uVar4 = uVar1 + uVar2, uVar5 = uVar3 + CARRY2(uVar1,uVar2),
      (short)&T78CON + uVar5 == (ushort)(uVar4 < 0x1800) && uVar4 == 0x1800 ||
      (uVar5 < 0xe0 || uVar5 == 0xe0 && uVar4 < 0x1800))) && (uVar2 < 0x81)) {
    uVar5 = uVar1 & 0x3fff;
    for (uVar4 = 1; uVar4 <= uVar2; uVar4 = uVar4 + 1) {
      *(undefined1 *)((uint3)uVar5 + (uint3)(uVar3 * 4 | uVar1 >> 0xe) * 0x4000) =
           *(undefined1 *)(uint3)((short)&kwp_request_addr_lo + uVar4);
      uVar5 = uVar5 + 1;
    }
    kline_response_length = 4;
    kline_response_payload = 0x7d;
    kline_response_payload_1 = ram_var_c149;
    kline_response_payload_2 = kwp_request_addr_hi;
    kline_response_payload_3 = kwp_request_addr_mid;
    return;
  }
  kline_response_length = 3;
  kline_response_payload = 0x7f;
  kline_response_payload_1 = 0x3d;
  kline_response_payload_2 = 0x12;
  return;
}


