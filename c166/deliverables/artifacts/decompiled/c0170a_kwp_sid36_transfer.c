/* c0170a kwp_sid36_transfer */

/* KWP service 0x36 transfer data (0x80-byte blocks to flash/RAM). */

void kwp_sid36_transfer(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  
  if (security_unlocked == '\x01') {
    uVar3 = (ushort)ram_var_c149;
    uVar4 = (ushort)kwp_request_addr_hi;
    uVar5 = (ushort)kwp_request_addr_mid;
    uVar1 = uVar4 * 0x100 + uVar5;
    kline_response_payload_1 = '\0';
    uVar6 = 0;
    uVar7 = uVar1 & 0x3fff;
    do {
      uVar2 = (short)&kwp_request_addr_lo + uVar6;
      *(undefined1 *)
       ((uint3)uVar7 +
       (uint3)((((ushort)CARRY2(uVar3 * 0x100,uVar4) * 0x100 | uVar3 * 0x100 + uVar4 >> 8) +
               (ushort)CARRY2(uVar4 * 0x100,uVar5)) * 4 | uVar1 >> 0xe) * 0x4000) =
           *(undefined1 *)(uint3)uVar2;
      kline_response_payload_1 = kline_response_payload_1 + *(char *)(uint3)uVar2;
      uVar6 = uVar6 + 1;
      uVar7 = uVar7 + 1;
    } while (uVar6 < 0x80);
    kline_response_length = 2;
    kline_response_payload = 0x76;
    return;
  }
  kline_response_length = 3;
  kline_response_payload = 0x7f;
  kline_response_payload_1 = 0x36;
  kline_response_payload_2 = 0xbd;
  return;
}


