/* c01840 kwp_sid23_read_mem */

/* KWP service 0x23 read memory by address. */

short kwp_sid23_read_mem(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint3 uVar5;
  byte bVar6;
  short sVar7;
  ushort uVar8;
  ushort uVar9;
  
  bVar6 = kwp_request_addr_lo;
  uVar3 = (ushort)kwp_request_addr_lo;
  uVar4 = (ushort)kwp_request_addr_hi;
  uVar1 = uVar4 * 0x100 + (ushort)kwp_request_addr_mid;
  uVar4 = ((ushort)CARRY2((ushort)ram_var_c149 * 0x100,uVar4) * 0x100 |
          (ushort)ram_var_c149 * 0x100 + uVar4 >> 8) +
          (ushort)CARRY2(uVar4 * 0x100,(ushort)kwp_request_addr_mid);
  uVar9 = uVar1 & 0x3fff;
  sVar7 = (short)&T2CON + uVar4;
  if ((((0xbf < uVar4) &&
       (sVar7 = 0, uVar8 = uVar4 + CARRY2(uVar1,uVar3),
       uVar8 == 0xc4 && uVar1 + uVar3 == 0 || uVar8 < 0xc4)) ||
      ((0xdf < uVar4 &&
       (uVar8 = uVar1 + uVar3, uVar2 = uVar4 + CARRY2(uVar1,uVar3),
       (short)&T78CON + uVar2 == (ushort)(uVar8 < 0x1800) && uVar8 == 0x1800 ||
       (uVar2 < 0xe0 || uVar2 == 0xe0 && uVar8 < 0x1800))))) && (uVar3 < 0x81)) {
    for (uVar8 = 1; uVar8 <= uVar3; uVar8 = uVar8 + 1) {
      uVar5 = (uint3)uVar9;
      uVar9 = uVar9 + 1;
      *(undefined1 *)(uint3)((short)&kline_response_payload + uVar8) =
           *(undefined1 *)(uVar5 + (uint3)(uVar4 * 4 | uVar1 >> 0xe) * 0x4000);
    }
    kline_response_length = bVar6 + 1;
    kline_response_payload = 99;
    return sVar7;
  }
  kline_response_length = 3;
  kline_response_payload = 0x7f;
  kline_response_payload_1 = 0x23;
  kline_response_payload_2 = 0x12;
  return CONCAT11((char)((ushort)sVar7 >> 8),0x12);
}


