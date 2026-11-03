; ============================================================================
; Delphi MT05.2 semantic reconstruction: application firmware part
; Generated from Ghidra decompiler output; not compilable source.
; Functions are grouped by area and sorted by address.
; ============================================================================

; ============================== Startup / runtime ==============================

; ----------------------------------------------------------------------------
; app_clear_flag
; Address: 0xC0BFD2
; Area:    application/00-startup-runtime
; Size:    6 bytes
; --------------------------------------------------------------------------
c0bfd2: mov 0xc446,0xff1c
c0bfd6: rets


; ----------------------------------------------------------------------------
; app_run
; Address: 0xC0BFE2
; Area:    application/00-startup-runtime
; Size:    16 bytes
; --------------------------------------------------------------------------
c0bfe2: cmp r12,#0x0
c0bfe4: jmpr cc_EQ,0xc0bfec
c0bfe6: cmp r12,#0x1
c0bfe8: jmpr cc_EQ,0xc0bfec
c0bfea: jmpr cc_UC,0xc0bfea
c0bfec: calls 0xc11c62
c0bff0: rets


; ----------------------------------------------------------------------------
; app_main
; Address: 0xC0FFDE
; Area:    application/00-startup-runtime
; Size:    16 bytes
; --------------------------------------------------------------------------
c0ffde: calls 0xc14714
c0ffe2: calls 0xc11bf4
c0ffe6: mov r12,#0x0
c0ffe8: calls 0xc0bfe2
c0ffec: rets


; ----------------------------------------------------------------------------
; app_entry
; Address: 0xC10000
; Area:    application/00-startup-runtime
; Size:    4 bytes
; --------------------------------------------------------------------------
c10000: jmps 0xc11aa0


; ----------------------------------------------------------------------------
; timeout_counter_tick
; Address: 0xC108B4
; Area:    application/00-startup-runtime
; Size:    26 bytes
; --------------------------------------------------------------------------
c108b4: movbz r12,0xc4cc
c108b8: cmp r12,#0x80
c108bc: jmpr cc_SLE,0xc108c8
c108be: mov 0xc4d2,0xff1c
c108c2: mov 0xc4d4,0xff1c
c108c6: rets
c108c8: subb 0xc4cc,0xff1e
c108cc: rets


; ----------------------------------------------------------------------------
; app_cinit
; Address: 0xC1192C
; Area:    application/00-startup-runtime
; Size:    372 bytes
; --------------------------------------------------------------------------
c1192c: mov r1,#0xfdfe
c11930: cmp r1,#0xfcc2
c11934: jmpr cc_EQ,0xc11940
c11936: cmp r1,#0xfcc0
c1193a: jmpr cc_EQ,0xc11940
c1193c: mov [r1],0xff1c
c11940: cmpd2 r1,#0xfd00
c11944: jmpr cc_NE,0xc11930
c11946: mov r4,#0x3b56
c1194a: mov 0xfe00,#0x302
c1194e: nop
c11950: mov r5,[r4+]
c11952: cmp r5,#0x1
c11954: jmpr cc_EQ,0xc11a0e
c11956: cmp r5,#0x5
c11958: jmpr cc_EQ,0xc119fa
c1195a: cmp r5,#0x6
c1195c: jmpr cc_EQ,0xc119c0
c1195e: cmp r5,#0x7
c11960: jmpr cc_NE,0xc11a14
c11962: mov r1,[r4+]
c11964: mov r3,[r4+]
c11966: movb RH3,RH1
c11968: rol r3,#0x2
c1196a: and r3,#0x3ff
c1196e: mov 0xfe02,r3
c11972: bclr r1.0xf
c11974: bset r1.0xe
c11976: mov r2,[r4+]
c11978: mov r3,[r4+]
c1197a: movb RH3,RH2
c1197c: rol r3,#0x2
c1197e: and r3,#0x3ff
c11982: mov 0xfe04,r3
c11986: bset r2.0xf
c11988: bclr r2.0xe
c1198a: mov r5,[r4+]
c1198c: mov r6,[r4+]
c1198e: cmpd1 r5,#0x0
c11990: jmpr cc_NE,0xc11996
c11992: cmpd1 r6,#0x0
c11994: jmpr cc_EQ,0xc119b6
c11996: movb [r1],[r2]
c11998: cmpi1 r1,#0x7fff
c1199c: jmpr cc_NE,0xc119a6
c1199e: mov r1,#0x4000
c119a2: add 0xfe02,#0x1
c119a6: cmpi1 r2,#0xbfff
c119aa: jmpr cc_NE,0xc1198e
c119ac: mov r2,#0x8000
c119b0: add 0xfe04,#0x1
c119b4: jmpr cc_UC,0xc1198e
c119b6: mov 0xfe02,#0x302
c119ba: mov 0xfe04,#0x303
c119be: jmpr cc_UC,0xc11950
c119c0: mov r1,[r4+]
c119c2: bclr r1.0xf
c119c4: bset r1.0xe
c119c6: mov 0xfe02,[r4]
c119ca: add r4,#0x2
c119cc: mov r2,[r4+]
c119ce: bset r2.0xf
c119d0: bclr r2.0xe
c119d2: mov 0xfe04,[r4]
c119d6: add r4,#0x2
c119d8: mov r5,[r4+]
c119da: cmpd1 r5,#0x0
c119dc: jmpr cc_EQ,0xc119f0
c119de: movb [r1],[r2+]
c119e0: cmpi1 r1,#0x7fff
c119e4: jmpr cc_NE,0xc119da
c119e6: mov r1,#0x4000
c119ea: add 0xfe02,#0x1
c119ee: jmpr cc_UC,0xc119da
c119f0: mov 0xfe02,#0x302
c119f4: mov 0xfe04,#0x303
c119f8: jmpr cc_UC,0xc11950
c119fa: mov r1,[r4+]
c119fc: mov r2,[r4+]
c119fe: mov r5,[r4+]
c11a00: mov 0xfe00,#0x301
c11a04: cmpd1 r5,#0x0
c11a06: jmpr cc_EQ,0xc1194a
c11a08: movb [r1],[r2+]
c11a0a: add r1,#0x1
c11a0c: jmpr cc_UC,0xc11a04
c11a0e: add r4,#0xc
c11a12: jmpr cc_UC,0xc11950
c11a14: mov r4,#0x0
c11a18: mov 0xfe00,#0x303
c11a1c: nop
c11a1e: mov r5,[r4+]
c11a20: cmp r5,#0x5
c11a22: jmpr cc_EQ,0xc11a86
c11a24: cmp r5,#0x6
c11a26: jmpr cc_EQ,0xc11a66
c11a28: cmp r5,#0x7
c11a2a: jmpr cc_NE,0xc11a9a
c11a2c: mov r1,[r4+]
c11a2e: mov r3,[r4+]
c11a30: movb RH3,RH1
c11a32: rol r3,#0x2
c11a34: and r3,#0x3ff
c11a38: mov 0xfe02,r3
c11a3c: bclr r1.0xf
c11a3e: bset r1.0xe
c11a40: mov r5,[r4+]
c11a42: mov r6,[r4+]
c11a44: cmpd1 r5,#0x0
c11a46: jmpr cc_NE,0xc11a4c
c11a48: cmpd1 r6,#0x0
c11a4a: jmpr cc_EQ,0xc11a60
c11a4c: movb [r1],0xff1c
c11a50: cmpi1 r1,#0x7fff
c11a54: jmpr cc_NE,0xc11a44
c11a56: mov r1,#0x4000
c11a5a: add 0xfe02,#0x1
c11a5e: jmpr cc_UC,0xc11a44
c11a60: mov 0xfe02,#0x302
c11a64: jmpr cc_UC,0xc11a1e
c11a66: mov r1,[r4+]
c11a68: bclr r1.0xf
c11a6a: bset r1.0xe
c11a6c: mov 0xfe02,[r4]
c11a70: add r4,#0x2
c11a72: mov r5,[r4+]
c11a74: cmpd1 r5,#0x0
c11a76: jmpr cc_EQ,0xc11a80
c11a78: movb [r1],0xff1c
c11a7c: add r1,#0x1
c11a7e: jmpr cc_UC,0xc11a74
c11a80: mov 0xfe02,#0x302
c11a84: jmpr cc_UC,0xc11a1e
c11a86: mov r1,[r4+]
c11a88: mov r5,[r4+]
c11a8a: mov 0xfe00,#0x301
c11a8e: cmpd1 r5,#0x0
c11a90: jmpr cc_EQ,0xc11a18
c11a92: movb [r1],0xff1c
c11a96: add r1,#0x1
c11a98: jmpr cc_UC,0xc11a8e
c11a9a: mov 0xfe00,#0x301
c11a9e: rets


; ----------------------------------------------------------------------------
; app_cstart
; Address: 0xC11AA0
; Area:    application/00-startup-runtime
; Size:    138 bytes
; --------------------------------------------------------------------------
c11aa0: bclr 0xff10.0xb
c11aa2: diswdt
c11aa6: mov 0xfe18,#0x17
c11aaa: mov 0xfe1a,#0x8fbb
c11aae: extr #0x1
c11ab0: mov 0xffdc,#0x0
c11ab4: extr #0x1
c11ab6: mov 0xffd4,#0x0
c11aba: mov 0xffaa,#0x0
c11abe: extr #0x1
c11ac0: mov 0xfefa,#0x8000
c11ac4: mov 0xff12,#0xc1
c11ac8: atomic #0x3
c11aca: mov 0xfe12,#0xfc00
c11ace: mov 0xfe14,#0xfada
c11ad2: mov 0xfe16,#0xfc00
c11ad6: mov r1,#0xface
c11ada: mov r2,#0x165
c11ade: mov [r1],r2
c11ae0: cmpi2 r1,#0xfbfe
c11ae4: jmpr cc_NE,0xc11ade
c11ae6: push 0xfe00
c11ae8: mov 0xfe00,#0x3
c11aec: mov r1,#0x2ca
c11af0: mov r2,#0x167
c11af4: mov [r1],r2
c11af6: cmpi2 r1,#0x368
c11afa: jmpr cc_NE,0xc11af4
c11afc: pop 0xfe00
c11afe: nop
c11b00: mov 0xfe10,#0xfcc0
c11b04: nop
c11b06: mov 0xfe00,#0x301
c11b0a: mov 0xfe02,#0x302
c11b0e: mov 0xfe04,#0x303
c11b12: mov r0,#0xc36a
c11b16: calls 0xc1192c
c11b1a: mov r12,#0x0
c11b1c: mov r13,#0x0
c11b1e: mov r14,#0x0
c11b20: calls 0xc0ffde
c11b24: idle
c11b28: jmpr cc_UC,0xc11b24


; ----------------------------------------------------------------------------
; app_hw_init
; Address: 0xC11BF4
; Area:    application/00-startup-runtime
; Size:    102 bytes
; --------------------------------------------------------------------------
c11bf4: calls 0xc11b2a
c11bf8: extr #0x2
c11bfa: or 0xf0fe,#0x1
c11bfe: mov 0xffd0,#0x7f13
c11c02: calls 0xc103c0
c11c06: calls 0xc105ec
c11c0a: calls 0xc10370
c11c0e: calls 0xc11f1c
c11c12: calls 0xc0ff00
c11c16: calls 0xc10200
c11c1a: calls 0xc108ce
c11c1e: calls 0xc1072a
c11c22: calls 0xc0cea2
c11c26: calls 0xc0cdfa
c11c2a: calls 0xc0bfd2
c11c2e: calls 0xc14298
c11c32: calls 0xc0f628
c11c36: calls 0xc0fb6e
c11c3a: calls 0xc0d562
c11c3e: calls 0xc0d528
c11c42: calls 0xc0bda2
c11c46: calls 0xc0d9e4
c11c4a: calls 0xc0ba9e
c11c4e: calls 0xc11b9a
c11c52: calls 0xc11b2a
c11c56: mov 0xffae,#0xbc01


; ----------------------------------------------------------------------------
; app_main_init
; Address: 0xC11C62
; Area:    application/00-startup-runtime
; Size:    76 bytes
; --------------------------------------------------------------------------
c11c62: mov [-r0],r6
c11c64: mov r12,0x7092
c11c68: or r12,0x7090
c11c6c: jmpr cc_EQ,0xc11c7a
c11c6e: mov r4,0x7090
c11c72: mov r5,0x7092
c11c76: calls 0xc28c4e
c11c7a: movb RL6,#0x0
c11c7c: mov r13,#0x7088
c11c80: movbz r14,RL6
c11c82: mov r15,r14
c11c84: shl r15,#0x2
c11c86: sub r15,r14
c11c88: shl r15,#0x1
c11c8a: add r13,r15
c11c8c: movbz r12,RL6
c11c8e: shl r12,#0x1
c11c90: mov r14,[r13]
c11c92: addb RL6,#0x1
c11c94: movb RL1,[r14]
c11c96: movb [r12+#0xc54c],RL1
c11c9a: mov r13,[r13]
c11c9c: movb RL1,[r13]
c11c9e: movb [r12+#0xc54d],RL1
c11ca2: cmpb RL6,#0x2
c11ca4: jmpr cc_C,0xc11c7c
c11ca6: bset 0xff10.0xb
c11ca8: bset 0xff06.0x2
c11caa: jmpa cc_UC,0xc11eb4


; ----------------------------------------------------------------------------
; app_idle_wait
; Address: 0xC11CAE
; Area:    application/00-startup-runtime
; Size:    238 bytes
; --------------------------------------------------------------------------
c11cae: mov r6,0xfd14
c11cb2: jb r6.0x2,0xc11cba
c11cb6: jmpa cc_UC,0xc11eb4
c11cba: srvwdt
c11cbe: bclr 0xfd14.0x2
c11cc0: subb 0xc54a,0xff1e
c11cc4: calls 0xc0f3d2
c11cc8: calls 0xc10342
c11ccc: calls 0xc108b4
c11cd0: movb RL6,0xc54a
c11cd4: jnb r6.0x0,0xc11d18
c11cd8: calls 0xc0cd24
c11cdc: mov r6,0xc962
c11ce0: cmp r6,#0x5800
c11ce4: jmpr cc_C,0xc11d04
c11ce6: cmp r6,#0x6800
c11cea: jmpr cc_UGT,0xc11d04
c11cec: mov r12,0xcb60
c11cf0: jmpr cc_NE,0xc11d04
c11cf2: movb RL1,0xc280
c11cf6: jmpr cc_NE,0xc11d04
c11cf8: mov r13,#0x1
c11cfa: mov 0xc5e6,r13
c11cfe: calls 0xc13d5e
c11d02: jmpr cc_UC,0xc11d18
c11d04: mov 0xc5e6,0xff1c
c11d08: movb RL6,#0x80
c11d0c: andb 0xfd18,RL6
c11d10: mov 0xc5e8,0xff1c
c11d14: mov 0xc5ea,0xff1c
c11d18: calls 0xc11eec
c11d1c: movb RL6,#0x0
c11d1e: movbz r13,RL6
c11d20: shl r13,#0x1
c11d22: mov r12,#0xc54d
c11d26: add r12,r13
c11d28: mov r2,r12
c11d2a: movb RL1,[r13+#0xc54c]
c11d2e: cmpb RL1,[r2]
c11d30: jmpr cc_EQ,0xc11d60
c11d32: movb RL1,[r12]
c11d34: movbz r13,RL6
c11d36: mov r14,r13
c11d38: shl r13,#0x2
c11d3a: sub r13,r14
c11d3c: shl r13,#0x1
c11d3e: addb RL1,#0x1
c11d40: movb [r12],RL1
c11d42: mov r1,[r13+#0x7088]
c11d46: movb RL2,[r12]
c11d48: cmpb RL2,[r1]
c11d4a: jmpr cc_ULE,0xc11d50
c11d4c: movb RL1,#0x0
c11d4e: movb [r12],RL1
c11d50: movb RL1,[r12]
c11d52: movbz r12,RL1
c11d54: mov r4,[r13+#0x7084]
c11d58: mov r5,[r13+#0x7086]
c11d5c: calls 0xc28c4e
c11d60: addb RL6,#0x1
c11d62: cmpb RL6,#0x2
c11d64: jmpr cc_C,0xc11d1e
c11d66: jb 0xfd14.0x2,0xc11d78
c11d6a: mov r4,0x7098
c11d6e: mov r5,0x709a
c11d72: calls 0xc28c4e
c11d76: jmpr cc_UC,0xc11d7a
c11d78: bset 0xfd14.0x4
c11d7a: mov r12,#0x1
c11d7c: calls 0xc12982
c11d80: mov r6,0xc584
c11d84: sub r6,#0x4
c11d86: cmp r6,#0xb
c11d8a: jmpa cc_UGT,0xc11eb0
c11d8e: shl r6,#0x1
c11d90: add r6,#0x705e
c11d94: mov r6,[r6]
c11d96: jmpi cc_UC,[r6]
c11eb0: calls 0xc1482c


; ----------------------------------------------------------------------------
; app_scheduler
; Address: 0xC11EB4
; Area:    application/00-startup-runtime
; Size:    18 bytes
; --------------------------------------------------------------------------
c11eb4: mov r4,0x709c
c11eb8: mov r5,0x709e
c11ebc: calls 0xc28c4e
c11ec0: cmp r4,#0x0
c11ec2: jmpa cc_EQ,0xc11cae


; ----------------------------------------------------------------------------
; app_scheduler_path
; Address: 0xC11EC6
; Area:    application/00-startup-runtime
; Size:    38 bytes
; --------------------------------------------------------------------------
c11ec6: bclr 0xff10.0xb
c11ec8: diswdt
c11ecc: mov r6,0x7096
c11ed0: or r6,0x7094
c11ed4: jmpr cc_EQ,0xc11ee2
c11ed6: mov r4,0x7094
c11eda: mov r5,0x7096
c11ede: calls 0xc28c4e
c11ee2: bclr 0xff06.0x2
c11ee4: srst
c11ee8: mov r6,[r0+]
c11eea: rets


; ----------------------------------------------------------------------------
; scheduler_tick
; Address: 0xC11EEC
; Area:    application/00-startup-runtime
; Size:    24 bytes
; --------------------------------------------------------------------------
c11eec: subb 0xc54c,0xff1e
c11ef0: movb RL1,0xc54c
c11ef4: cmpb RL1,0xc550
c11ef8: jmpr cc_ULE,0xc11efe
c11efa: movb 0xc54c,0xff1c
c11efe: calls 0xc147c6
c11f02: rets


; ----------------------------------------------------------------------------
; command_dispatch_index3
; Address: 0xC147C6
; Area:    application/00-startup-runtime
; Size:    8 bytes
; --------------------------------------------------------------------------
c147c6: mov r12,#0x3
c147c8: calls 0xc19a2c
c147cc: rets


; ----------------------------------------------------------------------------
; command_dispatch
; Address: 0xC19A2C
; Area:    application/00-startup-runtime
; Size:    20 bytes
; --------------------------------------------------------------------------
c19a2c: mov r1,r12
c19a2e: cmpb RL1,#0x6
c19a30: jmpr cc_UGT,0xc19a66
c19a32: movbz r12,RL1
c19a34: shl r12,#0x1
c19a36: add r12,#0x7666
c19a3a: mov r12,[r12]
c19a3c: jmpi cc_UC,[r12]
c19a66: rets


; ============================== Drivers / CAN ==============================

; ----------------------------------------------------------------------------
; can_twincan_init
; Address: 0xC00434
; Area:    application/01-drivers/can
; Size:    608 bytes
; --------------------------------------------------------------------------
c00434: mov 0xc016,0xff1c
c00438: mov r12,#0x41
c0043c: mov r13,#0x0
c0043e: extp 0x80, #0x2
c00442: mov 0x200,r12
c00446: mov 0x210,r13
c0044a: mov r14,#0x60
c0044e: extp 0x80, #0x1
c00452: mov 0x222,r14
c00456: extr #0x1
c00458: or 0xff38,#0x8
c0045c: mov r15,0xff18
c00460: bclr r15.0x3
c00462: bset r15.0x3
c00464: mov 0xff18,r15
c00468: extr #0x1
c0046a: or 0xff3a,#0x8
c0046e: mov r15,#0x2387
c00472: extp 0x80, #0x2
c00476: mov 0x20c,r15
c0047a: mov 0x20e,r13
c0047e: extp 0x80, #0x2
c00482: mov 0x214,r13
c00486: mov 0x216,r13
c0048a: mov r1,#0x80
c0048e: extp 0x80, #0x2
c00492: mov 0x314,r1
c00496: mov r2,0x516
c0049a: and r2,#0xfff8
c0049e: mov r3,#0xffff
c004a2: extp 0x80, #0x2
c004a6: mov 0x316,r2
c004aa: mov 0x30c,r3
c004ae: extp 0x80, #0x2
c004b2: mov 0x30e,r3
c004b6: mov 0x308,r13
c004ba: mov r4,#0x1f80
c004be: extp 0x80, #0x2
c004c2: mov 0x30a,r4
c004c6: mov 0x300,r13
c004ca: extp 0x80, #0x2
c004ce: mov 0x302,r13
c004d2: mov 0x304,r13
c004d6: extp 0x80, #0x2
c004da: mov 0x306,r13
c004de: mov 0x318,r13
c004e2: extp 0x80, #0x1
c004e6: mov r5,0x31a
c004ea: and r5,#0xffe0
c004ee: mov r10,#0x1599
c004f2: extp 0x80, #0x2
c004f6: mov 0x31a,r5
c004fa: mov 0x310,r10
c004fe: mov r11,#0x88
c00502: extp 0x80, #0x2
c00506: mov 0x312,r13
c0050a: mov 0x514,r11
c0050e: extp 0x80, #0x1
c00512: mov r12,0x356
c00516: and r12,#0xfff8
c0051a: bset r12.0x1
c0051c: extp 0x80, #0x2
c00520: mov 0x516,r12
c00524: mov 0x50c,r3
c00528: extp 0x80, #0x2
c0052c: mov 0x50e,r3
c00530: mov 0x508,r13
c00534: mov r12,#0x1f90
c00538: extp 0x80, #0x2
c0053c: mov 0x50a,r12
c00540: mov 0x500,r13
c00544: extp 0x80, #0x2
c00548: mov 0x502,r13
c0054c: mov 0x504,r13
c00550: mov r12,#0x200f
c00554: extp 0x80, #0x2
c00558: mov 0x506,r13
c0055c: mov 0x518,r12
c00560: mov r12,#0x210
c00564: extp 0x80, #0x1
c00568: mov 0x51a,r12
c0056c: mov r12,#0x1595
c00570: extp 0x80, #0x2
c00574: mov 0x510,r12
c00578: mov 0x512,r13
c0057c: movb RL1,#0x0
c0057e: movbz r12,RL1
c00580: shl r12,#0x5
c00582: mov r14,#0x534
c00586: mov r15,#0x80
c0058a: add r14,r12
c0058c: extp r15, #0x2
c0058e: mov r13,#0x8
c00590: mov [r14],r13
c00592: mov r15,#0x536
c00596: mov r2,#0x80
c0059a: add r15,r12
c0059c: extp r2, #0x2
c0059e: mov r14,#0x0
c005a0: mov [r15],r14
c005a2: mov r2,#0x52c
c005a6: mov r3,#0x80
c005aa: add r2,r12
c005ac: extp r3, #0x2
c005ae: mov r15,#0xffff
c005b2: mov [r2],r15
c005b4: mov r2,#0x52e
c005b8: add r2,r12
c005ba: mov r3,#0x80
c005be: extp r3, #0x1
c005c0: mov [r2],r15
c005c2: mov r2,#0x528
c005c6: add r2,r12
c005c8: mov r3,#0x80
c005cc: extp r3, #0x1
c005ce: mov [r2],r14
c005d0: mov r2,#0x52a
c005d4: add r2,r12
c005d6: mov r3,#0x80
c005da: extp r3, #0x1
c005dc: mov [r2],r14
c005de: mov r2,#0x520
c005e2: add r2,r12
c005e4: mov r3,#0x80
c005e8: extp r3, #0x1
c005ea: mov [r2],r14
c005ec: mov r2,#0x522
c005f0: add r2,r12
c005f2: mov r3,#0x80
c005f6: extp r3, #0x1
c005f8: mov [r2],r14
c005fa: mov r2,#0x524
c005fe: add r2,r12
c00600: mov r3,#0x80
c00604: extp r3, #0x1
c00606: mov [r2],r14
c00608: mov r2,#0x526
c0060c: add r2,r12
c0060e: mov r3,#0x80
c00612: extp r3, #0x1
c00614: mov [r2],r14
c00616: mov r3,#0x538
c0061a: mov r4,#0x80
c0061e: add r3,r12
c00620: extp r4, #0x2
c00622: mov r2,#0x200f
c00626: mov [r3],r2
c00628: mov r4,#0x53a
c0062c: mov r5,#0x80
c00630: add r4,r12
c00632: extp r5, #0x2
c00634: mov r3,#0x310
c00638: mov [r4],r3
c0063a: mov r5,#0x530
c0063e: mov r10,#0x80
c00642: add r5,r12
c00644: extp r10, #0x2
c00646: mov r4,#0x1595
c0064a: mov [r5],r4
c0064c: mov r5,#0x532
c00650: add r5,r12
c00652: mov r10,#0x80
c00656: extp r10, #0x1
c00658: mov [r5],r14
c0065a: addb RL1,#0x1
c0065c: movbz r12,RL1
c0065e: cmp r12,#0xe
c00662: jmpr cc_SLE,0xc0057e
c00664: extr #0x2
c00666: or 0xf196,#0x8
c0066a: bset 0xff96.0x6
c0066c: movb RL1,#0x10
c00670: movb 0xc000,RL1
c00674: mov r12,#0xb
c00676: extp 0x80, #0x1
c0067a: mov 0x4,r12
c0067e: mov r5,#0x200
c00682: mov r10,#0x80
c00686: extp r10, #0x1
c00688: mov r11,[r5]
c0068a: and r11,#0xffbe
c0068e: extp r10, #0x1
c00690: mov [r5],r11
c00692: rets


; ----------------------------------------------------------------------------
; can0_isr
; Address: 0xC00694
; Area:    application/01-drivers/can
; Size:    232 bytes
; --------------------------------------------------------------------------
c00694: mov 0xfc00,r0
c00698: scxt 0xfe10,#0xfc00
c0069c: scxt 0xff0e,#0x10
c006a0: push 0xfe00
c006a2: mov 0xfe00,#0x300
c006a6: push 0xfe04
c006a8: mov 0xfe04,#0x302
c006ac: push 0xfe0c
c006ae: push 0xfe0e
c006b0: push 0xffde
c006b2: push 0xfe5c
c006b4: push 0xfe5e
c006b6: push 0xffdc
c006b8: scxt 0xffda,#0x0
c006bc: push 0xff08
c006be: push 0xff0a
c006c0: extr #0x4
c006c2: push 0xf000
c006c4: push 0xf002
c006c6: push 0xf004
c006c8: push 0xfe06
c006ca: calls 0xc01a1c
c006ce: jmpr cc_UC,0xc0073e
c006d0: extp 0x80, #0x1
c006d4: mov r8,0x310
c006d8: and r8,#0x3
c006da: cmp r8,#0x2
c006dc: jmpr cc_NE,0xc0073e
c006de: extp 0x80, #0x1
c006e2: mov r8,0x284
c006e6: jnb r8.0x0,0xc00732
c006ea: extp 0x80, #0x1
c006ee: mov r9,0x310
c006f2: and r9,#0x300
c006f6: cmp r9,#0x200
c006fa: jmpr cc_NE,0xc00732
c006fc: extp 0x80, #0x1
c00700: mov r9,0x310
c00704: and r9,#0xc00
c00708: cmp r9,#0x800
c0070c: jmpr cc_EQ,0xc0071e
c0070e: movb RL1,#0x0
c00710: addb RL1,#0x1
c00712: cmpb RL1,#0x8
c00716: jmpr cc_C,0xc00710
c00718: mov r8,#0x1
c0071a: mov 0xc016,r8
c0071e: mov r8,#0xf7ff
c00722: mov r9,#0xfdff
c00726: extp 0x80, #0x2
c0072a: mov 0x310,r8
c0072e: mov 0x310,r9
c00732: mov r8,#0xfffd
c00736: extp 0x80, #0x1
c0073a: mov 0x310,r8
c0073e: mov r8,#0x0
c00740: extp 0x80, #0x2
c00744: mov r9,0x286
c00748: mov r6,0x284
c0074c: mov r7,#0x0
c0074e: add r8,r6
c00750: addc r9,r7
c00752: jb r8.0x0,0xc006d0
c00756: extr #0x4
c00758: pop 0xf006
c0075a: pop 0xf004
c0075c: pop 0xf002
c0075e: pop 0xfe00
c00760: pop 0xff0a
c00762: pop 0xff08
c00764: pop 0xffda
c00766: pop 0xffdc
c00768: pop 0xfe5e
c0076a: pop 0xfe5c
c0076c: pop 0xffde
c0076e: pop 0xfe0e
c00770: pop 0xfe0c
c00772: pop 0xfe04
c00774: pop 0xfe00
c00776: pop 0xff0e
c00778: pop 0xfe10
c0077a: reti


; ----------------------------------------------------------------------------
; set_can_flag
; Address: 0xC0BA9E
; Area:    application/01-drivers/can
; Size:    22 bytes
; --------------------------------------------------------------------------
c0ba9e: bclr 0xff10.0xb
c0baa0: mov r12,#0xbab4
c0baa4: mov r13,#0xc0
c0baa8: mov 0xc210,r12
c0baac: mov 0xc212,r13
c0bab0: bset 0xff10.0xb
c0bab2: rets


; ----------------------------------------------------------------------------
; can_bus_config
; Address: 0xC11B2A
; Area:    application/01-drivers/can
; Size:    112 bytes
; --------------------------------------------------------------------------
c11b2a: mov r12,0xf0c2
c11b2e: and r12,#0x1800
c11b32: cmp r12,#0x800
c11b36: jmpr cc_NE,0xc11b4e
c11b38: mov r12,0xf0c2
c11b3c: and r12,#0xff
c11b40: mov r1,r12
c11b42: cplb RL1
c11b44: movbz r12,RL1
c11b46: or r12,#0x8e00
c11b4a: mov 0xf0c0,r12
c11b4e: mov r12,0xf0c2
c11b52: and r12,#0x1800
c11b56: cmp r12,#0x1800
c11b5a: jmpr cc_NE,0xc11b98
c11b5c: extr #0x2
c11b5e: mov 0xf0c0,#0xaaaa
c11b62: mov 0xfec0,#0x5554
c11b66: mov r12,0xf0c2
c11b6a: and r12,#0xff
c11b6e: mov r1,r12
c11b70: cplb RL1
c11b72: movbz r12,RL1
c11b74: or r12,#0x9600
c11b78: mov 0xf0c0,r12
c11b7c: extr #0x1
c11b7e: mov 0xfec0,#0x800
c11b82: mov r12,0xf0c2
c11b86: and r12,#0xff
c11b8a: mov r1,r12
c11b8c: cplb RL1
c11b8e: movbz r12,RL1
c11b90: or r12,#0x8e00
c11b94: mov 0xf0c0,r12
c11b98: rets


; ============================== Drivers / K-line ASC0 ==============================

; ----------------------------------------------------------------------------
; asc0_init
; Address: 0xC00C36
; Area:    application/01-drivers/kline-asc0
; Size:    78 bytes
; --------------------------------------------------------------------------
c00c36: mov r1,r12
c00c38: cmpb RL1,#0x2
c00c3a: jmpr cc_NE,0xc00c46
c00c3c: mov 0xfeb6,#0x1ce
c00c40: mov 0xfeb4,#0x2e
c00c44: jmpr cc_UC,0xc00c4e
c00c46: mov 0xfeb6,#0xcd
c00c4a: mov 0xfeb4,#0x4c
c00c4e: mov 0xffb0,#0x811
c00c52: extr #0x3
c00c54: mov 0xf0c6,#0x807
c00c58: mov 0xf0c4,#0x807
c00c5c: or 0xff26,#0x400
c00c60: mov r12,0xffc4
c00c64: bclr r12.0xa
c00c66: bset r12.0xa
c00c68: mov 0xffc4,r12
c00c6c: mov r12,0xffc6
c00c70: bclr r12.0xa
c00c72: bset r12.0xa
c00c74: mov 0xffc6,r12
c00c78: extr #0x1
c00c7a: bset 0xff9c.0x7
c00c7c: bset 0xff6c.0x7
c00c7e: or 0xffb0,#0x8000
c00c82: rets


; ----------------------------------------------------------------------------
; asc0_tx_byte
; Address: 0xC00C84
; Area:    application/01-drivers/kline-asc0
; Size:    6 bytes
; --------------------------------------------------------------------------
c00c84: mov 0xfeb0,r12
c00c88: rets


; ----------------------------------------------------------------------------
; asc0_read_rx_clear
; Address: 0xC00C8A
; Area:    application/01-drivers/kline-asc0
; Size:    8 bytes
; --------------------------------------------------------------------------
c00c8a: bclr 0xff6e.0x7
c00c8c: mov r4,0xfeb2
c00c90: rets


; ----------------------------------------------------------------------------
; asc0_pin_init
; Address: 0xC00DDC
; Area:    application/01-drivers/kline-asc0
; Size:    44 bytes
; --------------------------------------------------------------------------
c00ddc: bclr 0xffb2.0xf
c00dde: extr #0x1
c00de0: mov 0xfeb4,#0x1
c00de4: bclr 0xffc4.0xd
c00de6: extr #0x1
c00de8: bset 0xff26.0xd
c00dea: bset 0xffc6.0xd
c00dec: mov 0xffb2,#0xc037
c00df0: bset 0xffc4.0xd
c00df2: bclr 0xffc6.0x8
c00df4: bset 0xffc4.0x9
c00df6: extr #0x1
c00df8: bset 0xff26.0x9
c00dfa: bset 0xffc6.0x9
c00dfc: or 0xff74,#0x10
c00e00: bset 0xff74.0x6
c00e02: bset 0xff74.0x7
c00e04: bset 0xff72.0x7
c00e06: rets


; ----------------------------------------------------------------------------
; asc0_state_dispatch
; Address: 0xC01144
; Area:    application/01-drivers/kline-asc0
; Size:    26 bytes
; --------------------------------------------------------------------------
c01144: movb RL1,0xc0af
c01148: cmpb RL1,#0x5
c0114a: jmpr cc_UGT,0xc0117c
c0114c: movbz r12,RL1
c0114e: shl r12,#0x1
c01150: add r12,#0x428
c01154: mov r12,[r12]
c01156: jmpi cc_UC,[r12]
c0117c: movb 0xc0af,0xff1c
c01180: rets


; ----------------------------------------------------------------------------
; asc0_task0
; Address: 0xC01158
; Area:    application/01-drivers/kline-asc0
; Size:    6 bytes
; --------------------------------------------------------------------------
c01158: calls 0xc01188
c0115c: rets


; ----------------------------------------------------------------------------
; asc0_task1
; Address: 0xC0115E
; Area:    application/01-drivers/kline-asc0
; Size:    6 bytes
; --------------------------------------------------------------------------
c0115e: calls 0xc0119e
c01162: rets


; ----------------------------------------------------------------------------
; asc0_task2
; Address: 0xC01164
; Area:    application/01-drivers/kline-asc0
; Size:    6 bytes
; --------------------------------------------------------------------------
c01164: calls 0xc011d6
c01168: rets


; ----------------------------------------------------------------------------
; asc0_task3
; Address: 0xC0116A
; Area:    application/01-drivers/kline-asc0
; Size:    6 bytes
; --------------------------------------------------------------------------
c0116a: calls 0xc01252
c0116e: rets


; ----------------------------------------------------------------------------
; asc0_task4
; Address: 0xC01170
; Area:    application/01-drivers/kline-asc0
; Size:    6 bytes
; --------------------------------------------------------------------------
c01170: calls 0xc012e6
c01174: rets


; ----------------------------------------------------------------------------
; asc0_task5
; Address: 0xC01176
; Area:    application/01-drivers/kline-asc0
; Size:    6 bytes
; --------------------------------------------------------------------------
c01176: calls 0xc013e8
c0117a: rets


; ----------------------------------------------------------------------------
; asc0_clear_state
; Address: 0xC01182
; Area:    application/01-drivers/kline-asc0
; Size:    6 bytes
; --------------------------------------------------------------------------
c01182: mov 0xc13e,0xff1c
c01186: rets


; ----------------------------------------------------------------------------
; asc0_state0
; Address: 0xC01188
; Area:    application/01-drivers/kline-asc0
; Size:    22 bytes
; --------------------------------------------------------------------------
c01188: movb RL1,#0x1
c0118a: movb 0xc0af,RL1
c0118e: mov 0xc0b0,0xff1c
c01192: calls 0xc01182
c01196: mov 0xc13a,0xff1c
c0119a: bclr 0xffb0.0x4
c0119c: rets


; ----------------------------------------------------------------------------
; asc0_state1
; Address: 0xC0119E
; Area:    application/01-drivers/kline-asc0
; Size:    56 bytes
; --------------------------------------------------------------------------
c0119e: jb 0xffc4.0xb,0xc011a8
c011a2: sub 0xc0b0,0xff1e
c011a6: rets
c011a8: mov r12,0xc0b0
c011ac: cmp r12,#0x14
c011b0: jmpr cc_ULE,0xc011d0
c011b2: cmp r12,#0x1c
c011b6: jmpr cc_NC,0xc011d0
c011b8: movb RL1,#0x2
c011ba: mov r13,#0xf0c6
c011be: movb 0xc0af,RL1
c011c2: movb 0xc0ae,0xff1c
c011c6: mov r14,[r13]
c011c8: bfldl r14,#0x2,#0x2
c011cc: mov [r13],r14
c011ce: bset 0xffb0.0x4
c011d0: mov 0xc0b0,0xff1c
c011d4: rets


; ----------------------------------------------------------------------------
; asc0_state2
; Address: 0xC011D6
; Area:    application/01-drivers/kline-asc0
; Size:    60 bytes
; --------------------------------------------------------------------------
c011d6: jmpr cc_UC,0xc01212
c011d8: calls 0xc00c8a
c011dc: mov r13,#0xc144
c011e0: movbz r12,0xc0ae
c011e4: add r13,r12
c011e6: movb [r13],RL4
c011e8: movb RL1,[r13]
c011ea: movb RL2,[r12+#0xc0a3]
c011ee: cmpb RL1,RL2
c011f0: jmpr cc_EQ,0xc011fa
c011f2: movb RL1,#0x1
c011f4: movb 0xc0af,RL1
c011f8: jmpr cc_UC,0xc01212
c011fa: movb RL1,0xc0ae
c011fe: cmpb RL1,#0x4
c01200: jmpr cc_NE,0xc0120e
c01202: subb 0xc0af,0xff1e
c01206: movb RL2,#0x1
c01208: movb 0xc1d1,RL2
c0120c: jmpr cc_UC,0xc01212
c0120e: subb 0xc0ae,0xff1e


; ----------------------------------------------------------------------------
; asc0_state2_init
; Address: 0xC01218
; Area:    application/01-drivers/kline-asc0
; Size:    58 bytes
; --------------------------------------------------------------------------
c01218: mov [-r0],r12
c0121a: calls 0xc01182
c0121e: mov r12,[r0+]
c01220: mov r1,r12
c01222: cmpb RL1,#0x2
c01224: jmpr cc_NE,0xc0123e
c01226: movb RL1,#0x5e
c0122a: movb 0xc09e,RL1
c0122e: mov r12,#0x49fb
c01232: mov 0xc0a0,r12
c01236: movb RL2,#0x79
c0123a: movb 0xc0a2,RL2
c0123e: movb RL1,#0x3
c01240: movb 0xc0af,RL1
c01244: movb 0xc1d0,0xff1c
c01248: movb RL2,#0x1
c0124a: movb 0xc09a,RL2
c0124e: bset 0xffb0.0x4
c01250: rets


; ----------------------------------------------------------------------------
; asc0_state3
; Address: 0xC01252
; Area:    application/01-drivers/kline-asc0
; Size:    148 bytes
; --------------------------------------------------------------------------
c01252: movb RL1,0xc1d0
c01256: jmpr cc_EQ,0xc01260
c01258: cmpb RL1,#0x1
c0125a: jmpr cc_EQ,0xc0126e
c0125c: jmpa cc_UC,0xc012b6
c01260: movb 0xc140,0xff1c
c01264: movb RL1,#0x1
c01266: movb 0xc1d0,RL1
c0126a: jmpa cc_UC,0xc012ba
c0126e: jnb 0xff6e.0x7,0xc0127a
c01272: movb RL1,#0x4
c01274: movb 0xc0af,RL1
c01278: jmpr cc_UC,0xc01292
c0127a: movb RL1,0xc13c
c0127e: cmpb RL1,#0x1
c01280: jmpr cc_NE,0xc0129a
c01282: movb RL2,0xc140
c01286: cmpb RL2,0xc09e
c0128a: jmpr cc_ULE,0xc0129a
c0128c: movb RL3,#0x5
c0128e: movb 0xc0af,RL3
c01292: movb 0xc1d0,0xff1c
c01296: jmpa cc_UC,0xc012b0
c0129a: movb RL1,0xc13c
c0129e: jmpa cc_NE,0xc012b0
c012a2: movb RL2,0xc09b
c012a6: cmpb RL2,#0x1
c012a8: jmpa cc_NE,0xc012b0
c012ac: jmps 0xe00000
c012b0: subb 0xc140,0xff1e
c012b4: jmpr cc_UC,0xc012ba
c012b6: movb 0xc1d0,0xff1c
c012ba: sub 0xc13e,0xff1e
c012be: mov r12,0xc13e
c012c2: cmp r12,0xc0a0
c012c6: jmpr cc_ULE,0xc012e4
c012c8: mov 0xc13e,0xff1c
c012cc: movb RL1,#0x2
c012ce: mov r12,#0xf0c6
c012d2: movb 0xc0af,RL1
c012d6: movb 0xc0ae,0xff1c
c012da: mov r13,[r12]
c012dc: bfldl r13,#0x2,#0x2
c012e0: mov [r12],r13
c012e2: bset 0xffb0.0x4
c012e4: rets


; ----------------------------------------------------------------------------
; asc0_state4
; Address: 0xC012E6
; Area:    application/01-drivers/kline-asc0
; Size:    258 bytes
; --------------------------------------------------------------------------
c012e6: mov r13,#0x0
c012e8: movb RL1,0xc1d0
c012ec: jmpr cc_EQ,0xc012f8
c012ee: cmpb RL1,#0x1
c012f0: jmpr cc_EQ,0xc0130c
c012f2: cmpb RL1,#0x2
c012f4: jmpr cc_EQ,0xc0135a
c012f6: jmpr cc_UC,0xc013de
c012f8: movb 0xc0ae,0xff1c
c012fc: movb RL1,#0x4
c012fe: movb 0xc147,RL1
c01302: movb RL2,#0x1
c01304: movb 0xc1d0,RL2
c01308: mov 0xc09c,0xff1c
c0130c: jmpr cc_UC,0xc0133e
c0130e: calls 0xc00c8a
c01312: mov r12,#0xc144
c01316: movbz r13,0xc0ae
c0131a: add r12,r13
c0131c: movb [r12],RL4
c0131e: movbz r13,0xc0ae
c01322: shl r13,#0x1
c01324: movb RL1,[r12]
c01326: movbz r12,RL1
c01328: mov r14,[r13+#0xc0a8]
c0132c: cmp r12,r14
c0132e: jmpr cc_EQ,0xc0133a
c01330: movb RL1,#0x3
c01332: movb 0xc0af,RL1
c01336: movb 0xc1d0,0xff1c
c0133a: subb 0xc0ae,0xff1e
c0133e: jnb 0xff6e.0x7,0xc0134a
c01342: movb RL1,0xc0ae
c01346: cmpb RL1,#0x3
c01348: jmpr cc_C,0xc0130e
c0134a: movb RL1,0xc0ae
c0134e: cmpb RL1,#0x3
c01350: jmpr cc_NE,0xc013e2
c01352: movb RL2,#0x2
c01354: movb 0xc1d0,RL2
c01358: jmpr cc_UC,0xc013e2
c0135a: jmpr cc_UC,0xc01374
c0135c: mov [-r0],r13
c0135e: calls 0xc00c8a
c01362: movbz r12,0xc0ae
c01366: movb [r12+#0xc144],RL4
c0136a: mov r13,[r0+]
c0136c: subb 0xc0ae,0xff1e
c01370: mov 0xc09c,0xff1c
c01374: jnb 0xff6e.0x7,0xc01386
c01378: movbz r12,0xc147
c0137c: add r12,#0x4
c0137e: movbz r14,0xc0ae
c01382: cmp r12,r14
c01384: jmpr cc_SGE,0xc0135c
c01386: sub 0xc09c,0xff1e
c0138a: movbz r12,0xc147
c0138e: add r12,#0x4
c01390: mov 0xc142,r12
c01394: movbz r14,0xc0ae
c01398: cmp r14,0xc142
c0139c: jmpr cc_ULE,0xc013c4
c0139e: mov r12,#0x0
c013a0: jmpr cc_UC,0xc013ac
c013a2: movb RL1,[r12+#0xc144]
c013a6: movbz r14,RL1
c013a8: add r13,r14
c013aa: add r12,#0x1
c013ac: cmp r12,0xc142
c013b0: jmpr cc_C,0xc013a2
c013b2: movb RL1,#0x3
c013b4: movb 0xc0af,RL1
c013b8: movb 0xc1d0,0xff1c
c013bc: movb RL2,#0x1
c013be: movb 0xc1d1,RL2
c013c2: jmpr cc_UC,0xc013e2
c013c4: movbz r12,0xc0a2
c013c8: cmp r12,0xc09c
c013cc: jmpr cc_NC,0xc013e2
c013ce: movb RL1,#0x3
c013d0: movb 0xc0af,RL1
c013d4: movb 0xc1d0,0xff1c
c013d8: movb 0xc144,0xff1c
c013dc: jmpr cc_UC,0xc013e2
c013de: movb 0xc1d0,0xff1c
c013e2: sub 0xc13e,0xff1e
c013e6: rets


; ----------------------------------------------------------------------------
; asc0_state5
; Address: 0xC013E8
; Area:    application/01-drivers/kline-asc0
; Size:    154 bytes
; --------------------------------------------------------------------------
c013e8: movb RL1,#0x0
c013ea: movb RL2,0xc1d0
c013ee: jmpr cc_EQ,0xc013fa
c013f0: cmpb RL2,#0x1
c013f2: jmpr cc_EQ,0xc01444
c013f4: cmpb RL2,#0x2
c013f6: jmpr cc_EQ,0xc01468
c013f8: jmpr cc_UC,0xc01474
c013fa: mov 0xc138,0xff1c
c013fe: movb RL2,#0x80
c01402: movb 0xc0b2,RL2
c01406: movb RL3,#0xf1
c0140a: movb 0xc0b3,RL3
c0140e: movb RL4,#0x11
c01412: movb 0xc0b4,RL4
c01416: movbz r12,0xc0b5
c0141a: add r12,#0x4
c0141c: mov 0xc142,r12
c01420: mov r12,#0x0
c01422: jmpr cc_UC,0xc0142c
c01424: movb RL2,[r12+#0xc0b2]
c01428: addb RL1,RL2
c0142a: add r12,#0x1
c0142c: cmp r12,0xc142
c01430: jmpr cc_C,0xc01424
c01432: mov r12,0xc142
c01436: movb [r12+#0xc0b2],RL1
c0143a: movb RL1,#0x1
c0143c: movb 0xc1d0,RL1
c01440: bclr 0xffb0.0x4
c01442: jmpr cc_UC,0xc01478
c01444: mov r12,0xc138
c01448: sub 0xc138,0xff1e
c0144c: movb RL1,[r12+#0xc0b2]
c01450: movbz r12,RL1
c01452: calls 0xc00c84
c01456: mov r12,0xc138
c0145a: cmp r12,0xc142
c0145e: jmpr cc_ULE,0xc01478
c01460: movb RL1,#0x2
c01462: movb 0xc1d0,RL1
c01466: jmpr cc_UC,0xc01478
c01468: bset 0xffb0.0x4
c0146a: movb RL1,#0x3
c0146c: movb 0xc0af,RL1
c01470: movb 0xc13c,0xff1c
c01474: movb 0xc1d0,0xff1c
c01478: subb 0xc140,0xff1e
c0147c: mov 0xc13e,0xff1c
c01480: rets


; ----------------------------------------------------------------------------
; asc0_init_app
; Address: 0xC11F1C
; Area:    application/01-drivers/kline-asc0
; Size:    62 bytes
; --------------------------------------------------------------------------
c11f1c: mov 0xfeb6,#0x1a2
c11f20: mov 0xfeb4,#0x9c
c11f24: mov 0xffb0,#0x811
c11f28: extr #0x3
c11f2a: mov 0xf0c6,#0x807
c11f2e: mov 0xf0c4,#0x107
c11f32: or 0xff26,#0x400
c11f36: mov r12,0xffc4
c11f3a: bclr r12.0xa
c11f3c: bset r12.0xa
c11f3e: mov 0xffc4,r12
c11f42: mov r12,0xffc6
c11f46: bclr r12.0xa
c11f48: bset r12.0xa
c11f4a: mov 0xffc6,r12
c11f4e: or 0xff6e,#0x49
c11f52: or 0xff6c,#0x4a
c11f56: bset 0xffb0.0xf
c11f58: rets


; ----------------------------------------------------------------------------
; asc0_read_rx_raw
; Address: 0xC11F60
; Area:    application/01-drivers/kline-asc0
; Size:    6 bytes
; --------------------------------------------------------------------------
c11f60: movb RL4,0xfeb2
c11f64: rets


; ----------------------------------------------------------------------------
; asc0_rx_handler
; Address: 0xC11F66
; Area:    application/01-drivers/kline-asc0
; Size:    52 bytes
; --------------------------------------------------------------------------
c11f66: mov 0xfce0,r0
c11f6a: scxt 0xfe10,#0xfce0
c11f6e: scxt 0xff0e,#0x10
c11f72: push 0xfe00
c11f74: mov 0xfe00,#0x301
c11f78: push 0xfe04
c11f7a: mov 0xfe04,#0x303
c11f7e: push 0xfe0c
c11f80: push 0xfe0e
c11f82: calls 0xc11f60
c11f86: movbz r12,RL4
c11f88: calls 0xc1293c
c11f8c: pop 0xfe0e
c11f8e: pop 0xfe0c
c11f90: pop 0xfe04
c11f92: pop 0xfe00
c11f94: pop 0xff0e
c11f96: pop 0xfe10
c11f98: reti


; ----------------------------------------------------------------------------
; asc0_tx_handler
; Address: 0xC11F9A
; Area:    application/01-drivers/kline-asc0
; Size:    98 bytes
; --------------------------------------------------------------------------
c11f9a: mov 0xfce0,r0
c11f9e: scxt 0xfe10,#0xfce0
c11fa2: scxt 0xff0e,#0x10
c11fa6: push 0xfe00
c11fa8: mov 0xfe00,#0x301
c11fac: push 0xfe04
c11fae: mov 0xfe04,#0x303
c11fb2: push 0xfe0c
c11fb4: push 0xfe0e
c11fb6: mov r8,0xc57a
c11fba: cmp r8,#0x6
c11fbc: jmpr cc_NE,0xc11fee
c11fbe: mov r9,0xc5a2
c11fc2: cmp r9,#0x1
c11fc4: jmpr cc_NE,0xc11fe2
c11fc6: mov 0xc5ac,0xff1c
c11fca: movb RL6,0xc57d
c11fce: jmpr cc_EQ,0xc11fdc
c11fd0: movb RL7,0xc5b6
c11fd4: jmpr cc_EQ,0xc11fe2
c11fd6: calls 0xc12848
c11fda: jmpr cc_UC,0xc11fe2
c11fdc: mov r12,#0x5
c11fde: calls 0xc126bc
c11fe2: mov r8,0xc5a2
c11fe6: jmpr cc_NE,0xc11fee
c11fe8: mov r12,#0x0
c11fea: calls 0xc126da
c11fee: pop 0xfe0e
c11ff0: pop 0xfe0c
c11ff2: pop 0xfe04
c11ff4: pop 0xfe00
c11ff6: pop 0xff0e
c11ff8: pop 0xfe10
c11ffa: reti


; ============================== Drivers / SSC ==============================

; ----------------------------------------------------------------------------
; ssc_send_byte
; Address: 0xC00E08
; Area:    application/01-drivers/ssc
; Size:    12 bytes
; --------------------------------------------------------------------------
c00e08: bclr 0xff72.0x7
c00e0a: movb RL1,[r12]
c00e0c: movbz r12,RL1
c00e0e: mov 0xf0b0,r12
c00e12: rets


; ----------------------------------------------------------------------------
; ssc0_rx_isr
; Address: 0xC00E14
; Area:    application/01-drivers/ssc
; Size:    182 bytes
; --------------------------------------------------------------------------
c00e14: mov 0xfc60,r0
c00e18: scxt 0xfe10,#0xfc60
c00e1c: scxt 0xff0e,#0x10
c00e20: push 0xfe00
c00e22: mov 0xfe00,#0x300
c00e26: push 0xfe04
c00e28: mov 0xfe04,#0x302
c00e2c: push 0xfe0c
c00e2e: push 0xfe0e
c00e30: push 0xffde
c00e32: push 0xfe5c
c00e34: push 0xfe5e
c00e36: push 0xffdc
c00e38: scxt 0xffda,#0x0
c00e3c: push 0xff08
c00e3e: push 0xff0a
c00e40: extr #0x4
c00e42: push 0xf000
c00e44: push 0xf002
c00e46: push 0xf004
c00e48: push 0xfe06
c00e4a: movb RL6,0xf0b2
c00e4e: mov r8,0xc098
c00e52: movb [r8],RL6
c00e54: addb 0xc094,0xff1e
c00e58: movb RL6,0xc094
c00e5c: jmpr cc_NE,0xc00e8a
c00e5e: bset 0xff06.0x3
c00e60: movb RL1,#0x0
c00e62: movbz r12,RL1
c00e64: addb RL1,#0x1
c00e66: movb RL6,[r12+#0xc078]
c00e6a: movb [r12+#0xc082],RL6
c00e6e: cmpb RL1,#0x6
c00e70: jmpr cc_ULE,0xc00e62
c00e72: movb RL6,#0x7
c00e74: movb 0xc094,RL6
c00e78: mov r8,#0xc08c
c00e7c: mov 0xc096,r8
c00e80: mov r9,#0xc078
c00e84: mov 0xc098,r9
c00e88: jmpr cc_UC,0xc00ea4
c00e8a: mov r8,0xc096
c00e8e: add r8,#0x1
c00e90: mov 0xc096,r8
c00e94: mov r9,0xc098
c00e98: add r9,#0x1
c00e9a: mov 0xc098,r9
c00e9e: mov r12,r8
c00ea0: calls 0xc00e08
c00ea4: extr #0x4
c00ea6: pop 0xf006
c00ea8: pop 0xf004
c00eaa: pop 0xf002
c00eac: pop 0xfe00
c00eae: pop 0xff0a
c00eb0: pop 0xff08
c00eb2: pop 0xffda
c00eb4: pop 0xffdc
c00eb6: pop 0xfe5e
c00eb8: pop 0xfe5c
c00eba: pop 0xffde
c00ebc: pop 0xfe0e
c00ebe: pop 0xfe0c
c00ec0: pop 0xfe04
c00ec2: pop 0xfe00
c00ec4: pop 0xff0e
c00ec6: pop 0xfe10
c00ec8: reti


; ----------------------------------------------------------------------------
; ssc_start_frame
; Address: 0xC00ECA
; Area:    application/01-drivers/ssc
; Size:    30 bytes
; --------------------------------------------------------------------------
c00eca: bclr 0xff06.0x3
c00ecc: movb RL1,#0x7
c00ece: movb 0xc094,RL1
c00ed2: mov r12,#0xc08c
c00ed6: mov 0xc096,r12
c00eda: mov r13,#0xc078
c00ede: mov 0xc098,r13
c00ee2: calls 0xc00e08
c00ee6: rets


; ----------------------------------------------------------------------------
; ssc_init
; Address: 0xC0D9E4
; Area:    application/01-drivers/ssc
; Size:    126 bytes
; --------------------------------------------------------------------------
c0d9e4: bclr 0xff10.0xb
c0d9e6: mov r12,#0xd8fa
c0d9ea: mov r13,#0xc0
c0d9ee: mov 0xc218,r12
c0d9f2: mov 0xc21a,r13
c0d9f6: mov r12,#0xd914
c0d9fa: mov r13,#0xc0
c0d9fe: mov 0xc21c,r12
c0da02: mov 0xc21e,r13
c0da06: calls 0xc0da62
c0da0a: mov r12,0xc490
c0da0e: mov r13,[r12]
c0da10: or r13,#0x68
c0da14: mov [r12],r13
c0da16: calls 0xc0fe7e
c0da1a: mov r12,0xc48a
c0da1e: jmpr cc_EQ,0xc0da30
c0da20: mov r12,#0xd8ce
c0da24: mov r13,#0xc0
c0da28: mov 0xc214,r12
c0da2c: mov 0xc216,r13
c0da30: mov r12,0xc48c
c0da34: jmpr cc_NE,0xc0da3c
c0da36: mov r13,0xc48a
c0da3a: jmpr cc_EQ,0xc0da42
c0da3c: mov 0xc3ba,0xff1c
c0da40: jmpr cc_UC,0xc0da5e
c0da42: mov r12,#0x1
c0da44: mov 0xc3ba,r12
c0da48: mov r13,0xc48a
c0da4c: jmpr cc_NE,0xc0da5e
c0da4e: mov r12,#0xd8ce
c0da52: mov r13,#0xc0
c0da56: mov 0xc214,r12
c0da5a: mov 0xc216,r13
c0da5e: bset 0xff10.0xb
c0da60: rets


; ----------------------------------------------------------------------------
; cc26_ptr_init
; Address: 0xC0DA62
; Area:    application/01-drivers/ssc
; Size:    42 bytes
; --------------------------------------------------------------------------
c0da62: mov r12,#0xfe74
c0da66: mov 0xc48e,r12
c0da6a: mov r13,#0xff26
c0da6e: mov 0xc482,r13
c0da72: mov r14,#0xf174
c0da76: mov 0xc490,r14
c0da7a: mov r15,#0xfe28
c0da7e: mov 0xc488,r15
c0da82: mov r1,#0xfe2a
c0da86: mov 0xc486,r1
c0da8a: rets


; ----------------------------------------------------------------------------
; ssc_state_reset
; Address: 0xC0FC90
; Area:    application/01-drivers/ssc
; Size:    22 bytes
; --------------------------------------------------------------------------
c0fc90: mov 0xc47e,0xff1c
c0fc94: movb 0xc47c,0xff1c
c0fc98: movb 0xc480,0xff1c
c0fc9c: movb 0xc47b,0xff1c
c0fca0: movb 0xc47a,0xff1c
c0fca4: rets


; ----------------------------------------------------------------------------
; ssc_pin_config
; Address: 0xC0FE7E
; Area:    application/01-drivers/ssc
; Size:    48 bytes
; --------------------------------------------------------------------------
c0fe7e: calls 0xc0feae
c0fe82: mov r12,0xc482
c0fe86: mov r13,[r12]
c0fe88: and r13,#0xf0ff
c0fe8c: mov [r12],r13
c0fe8e: mov r12,0xc482
c0fe92: mov r13,[r12]
c0fe94: bset r13.0xa
c0fe96: mov [r12],r13
c0fe98: mov r12,0xc488
c0fe9c: mov r13,[r12]
c0fe9e: bset r13.0xa
c0fea0: mov [r12],r13
c0fea2: mov r12,0xc490
c0fea6: mov r13,[r12]
c0fea8: bclr r13.0x7
c0feaa: mov [r12],r13
c0feac: rets


; ----------------------------------------------------------------------------
; ssc_mode_select
; Address: 0xC0FEAE
; Area:    application/01-drivers/ssc
; Size:    82 bytes
; --------------------------------------------------------------------------
c0feae: movb RL1,#0x4
c0feb0: movb 0xc484,RL1
c0feb4: mov 0xc48c,0xff1c
c0feb8: extp 0x301, #0x1
c0febc: movb RL2,0x2b68
c0fec0: jmpr cc_NE,0xc0fefa
c0fec2: mov r12,#0x1
c0fec4: mov 0xc48a,r12
c0fec8: extp 0x301, #0x1
c0fecc: movb RL3,0x1036
c0fed0: cmpb RL3,#0x1
c0fed2: jmpr cc_EQ,0xc0feee
c0fed4: cmpb RL3,#0x2
c0fed6: jmpr cc_EQ,0xc0fede
c0fed8: cmpb RL3,#0x3
c0feda: jmpr cc_EQ,0xc0fee6
c0fedc: jmpr cc_UC,0xc0fefe
c0fede: movb RL1,#0xa
c0fee0: movb 0xc484,RL1
c0fee4: rets
c0fee6: movb RL1,#0x8
c0fee8: movb 0xc484,RL1
c0feec: rets
c0feee: mov 0xc48a,0xff1c
c0fef2: mov r12,#0x1
c0fef4: mov 0xc48c,r12
c0fef8: rets
c0fefa: mov 0xc48a,0xff1c
c0fefe: rets


; ----------------------------------------------------------------------------
; ssc0_init_app
; Address: 0xC0FF00
; Area:    application/01-drivers/ssc
; Size:    40 bytes
; --------------------------------------------------------------------------
c0ff00: bclr 0xffb2.0xf
c0ff02: extr #0x1
c0ff04: mov 0xfeb4,#0x3
c0ff08: bclr 0xffc4.0xd
c0ff0a: extr #0x1
c0ff0c: bset 0xff26.0xd
c0ff0e: bset 0xffc6.0xd
c0ff10: mov 0xffb2,#0xc037
c0ff14: bset 0xffc4.0xd
c0ff16: bclr 0xffc6.0x8
c0ff18: bset 0xffc4.0x9
c0ff1a: extr #0x1
c0ff1c: bset 0xff26.0x9
c0ff1e: bset 0xffc6.0x9
c0ff20: or 0xff74,#0xd0
c0ff24: bset 0xff72.0x7
c0ff26: rets


; ----------------------------------------------------------------------------
; ssc_send
; Address: 0xC0FF28
; Area:    application/01-drivers/ssc
; Size:    12 bytes
; --------------------------------------------------------------------------
c0ff28: bclr 0xff72.0x7
c0ff2a: movb RL1,[r12]
c0ff2c: movbz r12,RL1
c0ff2e: mov 0xf0b0,r12
c0ff32: rets


; ----------------------------------------------------------------------------
; ssc_rx_start
; Address: 0xC0FFC0
; Area:    application/01-drivers/ssc
; Size:    30 bytes
; --------------------------------------------------------------------------
c0ffc0: bclr 0xff06.0x3
c0ffc2: movb RL1,#0x7
c0ffc4: movb 0xc492,RL1
c0ffc8: mov r12,#0xc4b8
c0ffcc: mov 0xc494,r12
c0ffd0: mov r13,#0xc4a0
c0ffd4: mov 0xc496,r13
c0ffd8: calls 0xc0ff28
c0ffdc: rets


; ----------------------------------------------------------------------------
; ssc_rx_queue_init
; Address: 0xC10200
; Area:    application/01-drivers/ssc
; Size:    64 bytes
; --------------------------------------------------------------------------
c10200: mov 0xc4a8,0xff1e
c10204: bset 0xff06.0x3
c10206: movb RL1,#0x40
c1020a: movb 0xc4be,RL1
c1020e: movb 0xc4bd,0xff1c
c10212: movb 0xc4bc,0xff1c
c10216: movb RL2,#0x1f
c1021a: movb 0xc4bb,RL2
c1021e: movb RL3,#0xfc
c10222: movb 0xc4ba,RL3
c10226: movb 0xc4b9,0xff1c
c1022a: movb 0xc4b8,0xff1c
c1022e: calls 0xc0ffc0
c10232: movb 0xc4aa,0xff1c
c10236: movb 0xc49e,0xff1c
c1023a: movb 0xc4b4,0xff1c
c1023e: rets


; ----------------------------------------------------------------------------
; ssc_task
; Address: 0xC10342
; Area:    application/01-drivers/ssc
; Size:    46 bytes
; --------------------------------------------------------------------------
c10342: calls 0xc0ffc0
c10346: movb RL1,0xc498
c1034a: jmpr cc_NE,0xc10366
c1034c: mov r12,#0x200
c10350: or 0xc4ba,r12
c10354: calls 0xc0ffc0
c10358: calls 0xc10240
c1035c: movb RL1,#0x50
c10360: movb 0xc498,RL1
c10364: jmpr cc_UC,0xc1036a
c10366: addb 0xc498,0xff1e
c1036a: calls 0xc10242
c1036e: rets


; ============================== Drivers / timers ==============================

; ----------------------------------------------------------------------------
; capcom_timer_init
; Address: 0xC00CA2
; Area:    application/01-drivers/timers
; Size:    146 bytes
; --------------------------------------------------------------------------
c00ca2: mov 0xff20,#0x0
c00ca6: mov r1,r12
c00ca8: cmpb RL1,#0x2
c00caa: jmpr cc_NE,0xc00cb8
c00cac: extr #0x2
c00cae: mov 0xf050,#0xfbe0
c00cb2: mov 0xfe54,#0xfbe0
c00cb6: jmpr cc_UC,0xc00cc2
c00cb8: extr #0x2
c00cba: mov 0xf050,#0xf060
c00cbe: mov 0xfe54,#0xf060
c00cc2: extr #0x3
c00cc4: mov 0xf052,#0xffff
c00cc8: mov 0xf056,#0x0
c00ccc: mov 0xff7a,#0x58
c00cd0: mov 0xfe60,#0x0
c00cd4: mov 0xfe62,#0x0
c00cd8: mov 0xfe64,#0x0
c00cdc: mov 0xfe66,#0x0
c00ce0: mov 0xfe68,#0x0
c00ce4: mov 0xfe6a,#0x0
c00ce8: mov 0xfe6c,#0x0
c00cec: mov 0xfe6e,#0x0
c00cf0: mov 0xfe70,#0x0
c00cf4: mov 0xfe72,#0x0
c00cf8: mov 0xfe74,#0x0
c00cfc: mov 0xfe76,#0x0
c00d00: mov 0xfe78,#0x0
c00d04: mov 0xfe7a,#0x0
c00d08: mov 0xfe7c,#0x0
c00d0c: mov 0xfe7e,#0x0
c00d10: mov 0xff22,#0x0
c00d14: mov 0xff24,#0x0
c00d18: mov 0xff26,#0x0
c00d1c: mov 0xff28,#0x0
c00d20: mov 0xff2a,#0x0
c00d24: mov 0xfe28,#0x0
c00d28: mov 0xfe2a,#0x0
c00d2c: mov 0xff2c,#0x0
c00d30: bset 0xff20.0x6
c00d32: rets


; ----------------------------------------------------------------------------
; timer7_isr
; Address: 0xC00D34
; Area:    application/01-drivers/timers
; Size:    118 bytes
; --------------------------------------------------------------------------
c00d34: mov 0xfc40,r0
c00d38: scxt 0xfe10,#0xfc40
c00d3c: scxt 0xff0e,#0x10
c00d40: push 0xfe00
c00d42: mov 0xfe00,#0x300
c00d46: push 0xfe04
c00d48: mov 0xfe04,#0x302
c00d4c: push 0xfe0c
c00d4e: push 0xfe0e
c00d50: push 0xffde
c00d52: push 0xfe5c
c00d54: push 0xfe5e
c00d56: push 0xffdc
c00d58: scxt 0xffda,#0x0
c00d5c: push 0xff08
c00d5e: push 0xff0a
c00d60: extr #0x4
c00d62: push 0xf000
c00d64: push 0xf002
c00d66: push 0xf004
c00d68: push 0xfe06
c00d6a: calls 0xc01144
c00d6e: calls 0xc01482
c00d72: mov r8,0xc06e
c00d76: sub 0xc06e,0xff1e
c00d7a: cmp r8,#0x3e8
c00d7e: jmpr cc_ULE,0xc00d84
c00d80: mov 0xc06e,0xff1c
c00d84: extr #0x4
c00d86: pop 0xf006
c00d88: pop 0xf004
c00d8a: pop 0xf002
c00d8c: pop 0xfe00
c00d8e: pop 0xff0a
c00d90: pop 0xff08
c00d92: pop 0xffda
c00d94: pop 0xffdc
c00d96: pop 0xfe5e
c00d98: pop 0xfe5c
c00d9a: pop 0xffde
c00d9c: pop 0xfe0e
c00d9e: pop 0xfe0c
c00da0: pop 0xfe04
c00da2: pop 0xfe00
c00da4: pop 0xff0e
c00da6: pop 0xfe10
c00da8: reti


; ----------------------------------------------------------------------------
; timer4_init
; Address: 0xC0BDA2
; Area:    application/01-drivers/timers
; Size:    38 bytes
; --------------------------------------------------------------------------
c0bda2: extp 0x301, #0x1
c0bda6: movb RL1,0x1080
c0bdaa: cmpb RL1,#0x1
c0bdac: jmpr cc_NE,0xc0bdc6
c0bdae: mov 0xff44,#0x5
c0bdb2: mov 0xfe44,#0xff83
c0bdb6: or 0xff64,#0x61
c0bdba: extr #0x2
c0bdbc: bclr 0xf138.0x1
c0bdbe: bclr 0xff3a.0x1
c0bdc0: bset 0xff44.0x6
c0bdc2: mov 0xc3a4,0xff1c
c0bdc6: rets


; ----------------------------------------------------------------------------
; timer6_init
; Address: 0xC0BF40
; Area:    application/01-drivers/timers
; Size:    20 bytes
; --------------------------------------------------------------------------
c0bf40: mov 0xff48,#0x800a
c0bf44: mov 0xfe48,#0xffff
c0bf48: mov 0xfe4a,#0xffff
c0bf4c: or 0xff68,#0x7a
c0bf50: bset 0xff48.0x6
c0bf52: rets


; ----------------------------------------------------------------------------
; timer5_init
; Address: 0xC0CDFA
; Area:    application/01-drivers/timers
; Size:    168 bytes
; --------------------------------------------------------------------------
c0cdfa: bclr 0xff10.0xb
c0cdfc: bclr 0xff66.0x6
c0cdfe: mov 0xfe46,#0x0
c0ce02: extr #0x1
c0ce04: bclr 0xff70.0x6
c0ce06: mov r12,#0x200
c0ce0a: mov 0xc274,r12
c0ce0e: mov 0xc26e,0xff1c
c0ce12: bclr 0xff10.0xb
c0ce14: movb RL1,#0x0
c0ce16: movbz r13,RL1
c0ce18: shl r13,#0x1
c0ce1a: addb RL1,#0x1
c0ce1c: mov r12,#0x0
c0ce1e: mov [r13+#0xc282],r12
c0ce22: cmpb RL1,#0x17
c0ce26: jmpr cc_ULE,0xc0ce16
c0ce28: mov r13,#0x8100
c0ce2c: mov 0xfd00,r13
c0ce30: movb 0xc2b2,0xff1c
c0ce34: movb 0xc280,0xff1c
c0ce38: movb 0xc277,0xff1c
c0ce3c: movb 0xc264,0xff1c
c0ce40: movb 0xc272,0xff1c
c0ce44: bclr 0xfd00.0x6
c0ce46: mov 0xc2b4,0xff1e
c0ce4a: mov 0xc26a,0xff1e
c0ce4e: mov 0xc26c,0xff1e
c0ce52: movb 0xc268,0xff1e
c0ce56: mov 0xc25c,0xff1c
c0ce5a: bset 0xff10.0xb
c0ce5c: mov r12,#0xc8e2
c0ce60: mov r13,#0xc0
c0ce64: mov 0xc244,r12
c0ce68: mov 0xc246,r13
c0ce6c: mov r12,#0xc914
c0ce70: mov r13,#0xc0
c0ce74: mov 0xc240,r12
c0ce78: mov 0xc242,r13
c0ce7c: mov r14,#0x1
c0ce7e: or 0xc2aa,r14
c0ce82: mov r14,#0x2
c0ce84: or 0xc28a,r14
c0ce88: mov r14,#0x2
c0ce8a: or 0xc2a2,r14
c0ce8e: bclr 0xff66.0x6
c0ce90: mov 0xfe46,#0x0
c0ce94: bclr 0xff66.0x7
c0ce96: extr #0x1
c0ce98: bset 0xff70.0x6
c0ce9a: calls 0xc0cac2
c0ce9e: bset 0xff10.0xb
c0cea0: rets


; ----------------------------------------------------------------------------
; capcom_start
; Address: 0xC0CEA2
; Area:    application/01-drivers/timers
; Size:    118 bytes
; --------------------------------------------------------------------------
c0cea2: extr #0x1
c0cea4: or 0xfe66,#0x4
c0cea8: or 0xff20,#0x5
c0ceac: extr #0x4
c0ceae: mov 0xf050,#0x0
c0ceb2: mov 0xf054,#0x0
c0ceb6: mov 0xf052,#0x0
c0ceba: mov 0xfe56,#0x0
c0cebe: mov r12,#0xfe60
c0cec2: movb RL1,#0x0
c0cec4: mov r13,#0x0
c0cec6: mov r14,r12
c0cec8: add r12,#0x2
c0ceca: addb RL1,#0x1
c0cecc: cmpb RL1,#0x10
c0ced0: mov [r14],r13
c0ced2: jmpr cc_C,0xc0cec4
c0ced4: mov 0xff22,#0x0
c0ced8: mov 0xff28,#0x0
c0cedc: mov 0xff26,#0x3
c0cee0: mov 0xff2a,#0x0
c0cee4: mov 0xfe28,#0x0
c0cee8: mov 0xfe2a,#0x0
c0ceec: mov 0xff2c,#0x0
c0cef0: extr #0x1
c0cef2: or 0xff70,#0x38
c0cef6: or 0xff46,#0xa
c0cefa: mov 0xfe46,#0x0
c0cefe: mov 0xfe4a,#0x0
c0cf02: or 0xff66,#0x24
c0cf06: extr #0x1
c0cf08: or 0xff7a,#0x79
c0cf0c: bset 0xff46.0x6
c0cf0e: bset 0xff20.0x6
c0cf10: extr #0x1
c0cf12: or 0xff94,#0xcc
c0cf16: rets


; ----------------------------------------------------------------------------
; timer6_start
; Address: 0xC0FB6E
; Area:    application/01-drivers/timers
; Size:    30 bytes
; --------------------------------------------------------------------------
c0fb6e: calls 0xc0bf40
c0fb72: calls 0xc0fc90
c0fb76: movb 0xfd12,0xff1c
c0fb7a: mov 0xfd10,0xff1c
c0fb7e: movb 0xfd0e,0xff1c
c0fb82: mov 0xfd0c,0xff1c
c0fb86: mov 0xc478,0xff1c
c0fb8a: rets


; ----------------------------------------------------------------------------
; t7_timestamp
; Address: 0xC1064C
; Area:    application/01-drivers/timers
; Size:    40 bytes
; --------------------------------------------------------------------------
c1064c: mov r12,0xf050
c10650: cmp r12,#0x8000
c10654: jmpr cc_UGT,0xc1066a
c10656: mov r13,0xf17a
c1065a: jnb r13.0x7,0xc1066a
c1065e: shr r12,#0x3
c10660: add r12,0xc4c8
c10664: add r12,#0x2000
c10668: jmpr cc_UC,0xc10670
c1066a: shr r12,#0x3
c1066c: add r12,0xc4c8
c10670: mov r4,r12
c10672: rets


; ----------------------------------------------------------------------------
; t7_timestamp_extended
; Address: 0xC106E6
; Area:    application/01-drivers/timers
; Size:    68 bytes
; --------------------------------------------------------------------------
c106e6: mov r13,#0x0
c106e8: bmov r13.0x0,0xff10.0xb
c106ec: bclr 0xff10.0xb
c106ee: mov r12,0xf050
c106f2: shr r12,#0x8
c106f4: mov r14,0xc4ca
c106f8: add r12,r14
c106fa: mov r14,0xf17a
c106fe: jnb r14.0x7,0xc10712
c10702: mov r12,0xc4ca
c10706: add r12,#0x100
c1070a: mov r14,0xf050
c1070e: shr r14,#0x8
c10710: add r12,r14
c10712: cmp r13,#0x1
c10714: jmpa cc_NE,0xc1071e
c10718: bset 0xff10.0xb
c1071a: jmpa cc_UC,0xc10726
c1071e: cmp r13,#0x0
c10720: jmpa cc_NE,0xc10726
c10724: bclr 0xff10.0xb
c10726: mov r4,r12
c10728: rets


; ----------------------------------------------------------------------------
; timer8_init
; Address: 0xC1072A
; Area:    application/01-drivers/timers
; Size:    76 bytes
; --------------------------------------------------------------------------
c1072a: mov r12,0xff20
c1072e: and r12,#0xff
c10732: or r12,#0x500
c10736: mov 0xff20,r12
c1073a: extr #0x3
c1073c: mov 0xf052,#0x0
c10740: mov 0xf056,#0x0
c10744: or 0xff7c,#0xe9
c10748: extp 0x301, #0x1
c1074c: mov r12,0x1068
c10750: jmpr cc_EQ,0xc10756
c10752: cmp r12,#0x4
c10754: jmpr cc_NE,0xc10772
c10756: mov 0xfe6a,#0x0
c1075a: mov r12,0xff24
c1075e: and r12,#0xff8f
c10762: mov 0xff24,r12
c10766: or 0xff24,#0x30
c1076a: bset 0xff24.0x7
c1076c: extr #0x1
c1076e: or 0xff6a,#0xe0
c10772: bset 0xff20.0xe
c10774: rets


; ============================== Drivers / ADC ==============================

; ----------------------------------------------------------------------------
; adc_start
; Address: 0xC10370
; Area:    application/01-drivers/adc
; Size:    32 bytes
; --------------------------------------------------------------------------
c10370: mov 0xffbe,#0x9000
c10374: extr #0x1
c10376: mov 0xfe9c,#0x0
c1037a: extp 0x301, #0x1
c1037e: mov r12,0x106a
c10382: jmpr cc_NE,0xc1038a
c10384: mov 0xffa4,#0x847f
c10388: rets
c1038a: mov 0xffa4,#0xc47f
c1038e: rets


; ----------------------------------------------------------------------------
; adc_calibrate
; Address: 0xC105EC
; Area:    application/01-drivers/adc
; Size:    44 bytes
; --------------------------------------------------------------------------
c105ec: calls 0xc11b2a
c105f0: extr #0x1
c105f2: bclr 0xffbe.0xe
c105f4: mov r12,0xf110
c105f8: jnb r12.0xf,0xc105f4
c105fc: extr #0x4
c105fe: mov 0xf110,#0x0
c10602: mov 0xf0d2,#0xfc31
c10606: mov 0xf0d0,#0xfc31
c1060a: or 0xffa0,#0x54
c1060e: extr #0x2
c10610: mov 0xf10c,#0x1
c10614: bset 0xff10.0x0
c10616: rets


; ============================== Drivers / IO ==============================

; ----------------------------------------------------------------------------
; p1l1_set
; Address: 0xC0BD54
; Area:    application/01-drivers/io
; Size:    4 bytes
; --------------------------------------------------------------------------
c0bd54: bset 0xff04.0x1
c0bd56: rets


; ----------------------------------------------------------------------------
; watchdog_pin
; Address: 0xC0CAC2
; Area:    application/01-drivers/io
; Size:    24 bytes
; --------------------------------------------------------------------------
c0cac2: mov r12,0xf1e4
c0cac6: jb r12.0x0,0xc0cad2
c0caca: mov r13,0xf1e4
c0cace: jnb r13.0x1,0xc0cad6
c0cad2: bset 0xfd00.0x5
c0cad4: rets
c0cad6: bclr 0xfd00.0x5
c0cad8: rets


; ----------------------------------------------------------------------------
; input_debounce_sample
; Address: 0xC10242
; Area:    application/01-drivers/io
; Size:    154 bytes
; --------------------------------------------------------------------------
c10242: mov r12,#0x1
c10244: srvwdt
c10248: mov r13,r12
c1024a: and r13,0xc49a
c1024e: jmpr cc_EQ,0xc10256
c10250: or 0xc4b6,r12
c10254: jmpr cc_UC,0xc1025a
c10256: or 0xc49c,r12
c1025a: cmp r12,#0x8
c1025e: jmpr cc_EQ,0xc10274
c10260: cmp r12,#0x80
c10264: jmpr cc_EQ,0xc10282
c10266: cmp r12,#0x20
c1026a: jmpr cc_EQ,0xc1029a
c1026c: cmp r12,#0x10
c10270: jmpr cc_EQ,0xc102b2
c10272: jmpr cc_UC,0xc102d0
c10274: jb 0xff04.0x6,0xc102ca
c10278: mov r13,#0xfff7
c1027c: and 0xc49a,r13
c10280: jmpr cc_UC,0xc102d0
c10282: jnb 0xff04.0x0,0xc10290
c10286: mov r13,#0x80
c1028a: or 0xc49a,r13
c1028e: jmpr cc_UC,0xc102d0
c10290: mov r13,#0xff7f
c10294: and 0xc49a,r13
c10298: jmpr cc_UC,0xc102d0
c1029a: jnb 0xff04.0x2,0xc102a8
c1029e: mov r13,#0x20
c102a2: or 0xc49a,r13
c102a6: jmpr cc_UC,0xc102d0
c102a8: mov r13,#0xffdf
c102ac: and 0xc49a,r13
c102b0: jmpr cc_UC,0xc102d0
c102b2: jnb 0xff04.0x5,0xc102c0
c102b6: mov r13,#0x10
c102ba: or 0xc49a,r13
c102be: jmpr cc_UC,0xc102d0
c102c0: mov r13,#0xffef
c102c4: and 0xc49a,r13
c102c8: jmpr cc_UC,0xc102d0
c102ca: mov r13,#0x8
c102cc: or 0xc49a,r13
c102d0: shl r12,#0x1
c102d2: cmp r12,#0x80
c102d6: jmpa cc_ULE,0xc10244
c102da: rets


; ----------------------------------------------------------------------------
; port_bus_init
; Address: 0xC103C0
; Area:    application/01-drivers/io
; Size:    260 bytes
; --------------------------------------------------------------------------
c103c0: extr #0x1
c103c2: mov 0xffc4,#0x80
c103c6: mov 0xff02,#0x0
c103ca: extr #0x2
c103cc: mov 0xf082,#0x0
c103d0: mov 0xff02,#0x0
c103d4: mov 0xff00,#0x0
c103d8: extr #0x2
c103da: mov 0xf080,#0x0
c103de: mov 0xff00,#0x0
c103e2: mov 0xff06,#0x4
c103e6: extr #0x3
c103e8: mov 0xf120,#0x0
c103ec: mov 0xf086,#0x0
c103f0: mov 0xff06,#0x2e
c103f4: mov 0xff04,#0x0
c103f8: extr #0x4
c103fa: mov 0xf130,#0x0
c103fe: mov 0xf084,#0x0
c10402: mov 0xf104,#0x71
c10406: or 0xff04,#0xa
c1040a: extr #0x2
c1040c: or 0xf104,#0x40
c10410: mov 0xffc6,#0x0
c10414: mov 0xffc4,#0x0
c10418: extr #0x3
c1041a: mov 0xf126,#0x0
c1041e: mov 0xf128,#0x0
c10422: mov 0xfe8a,#0x0
c10426: mov 0xffc6,#0x8040
c1042a: extr #0x1
c1042c: mov 0xffca,#0x0
c10430: mov 0xffc8,#0x0
c10434: extr #0x3
c10436: mov 0xf12a,#0x0
c1043a: mov 0xf136,#0x0
c1043e: mov 0xfe8c,#0x0
c10442: mov 0xffca,#0x0
c10446: mov 0xff1a,#0x0
c1044a: mov 0xff16,#0x0
c1044e: extr #0x3
c10450: mov 0xf138,#0x0
c10454: mov 0xf13a,#0x3
c10458: mov 0xfe94,#0x0
c1045c: bclr 0xff18.0x5
c1045e: mov 0xff18,#0x0
c10462: bset 0xff18.0x4
c10464: mov 0xffb4,#0x0
c10468: extr #0x1
c1046a: mov 0xfeaa,#0x0
c1046e: mov 0xffb6,#0x0
c10472: jb 0xffa2.0x7,0xc104c2
c10476: extr #0x1
c10478: mov 0xfe82,#0x3333
c1047c: mov 0xff02,#0x0
c10480: extr #0x2
c10482: mov 0xf102,#0xff
c10486: mov 0xfe80,#0x3333
c1048a: mov 0xff00,#0x0
c1048e: extr #0x1
c10490: mov 0xff00,#0xff
c10494: and 0xff06,#0x3f
c10498: extr #0x1
c1049a: or 0xff06,#0xc0
c1049e: and 0xffc4,#0x6fff
c104a2: or 0xffc6,#0x9000
c104a6: extr #0x1
c104a8: mov 0xfe8c,#0x3333
c104ac: mov 0xffc8,#0x0
c104b0: mov 0xffca,#0xff
c104b4: extr #0x1
c104b6: mov 0xfeaa,#0x3333
c104ba: mov 0xffb4,#0x0
c104be: mov 0xffb6,#0xffff
c104c2: rets


; ----------------------------------------------------------------------------
; capture_control
; Address: 0xC13F6C
; Area:    application/01-drivers/io
; Size:    24 bytes
; --------------------------------------------------------------------------
c13f6c: jb 0xfd10.0x2,0xc13f7c
c13f70: extp 0x301, #0x1
c13f74: mov r12,0x1064
c13f78: jmpr cc_NE,0xc13f7c
c13f7a: bset 0xfd1a.0x5
c13f7c: jb 0xfd0c.0x2,0xc13f82
c13f80: bset 0xfd1a.0x4
c13f82: rets


; ----------------------------------------------------------------------------
; capture_input_select
; Address: 0xC13F9A
; Area:    application/01-drivers/io
; Size:    24 bytes
; --------------------------------------------------------------------------
c13f9a: mov r13,0xfd1a
c13f9e: and r13,#0xfffc
c13fa2: mov r1,r13
c13fa4: movbz r13,RL1
c13fa6: mov r1,r12
c13fa8: movbz r12,RL1
c13faa: or r13,r12
c13fac: mov 0xfd1a,r13
c13fb0: rets


; ----------------------------------------------------------------------------
; capture_init
; Address: 0xC14298
; Area:    application/01-drivers/io
; Size:    12 bytes
; --------------------------------------------------------------------------
c14298: calls 0xc13f6c
c1429c: mov r12,#0x0
c1429e: calls 0xc13f9a
c142a2: rets


; ----------------------------------------------------------------------------
; input_latch
; Address: 0xC14714
; Area:    application/01-drivers/io
; Size:    36 bytes
; --------------------------------------------------------------------------
c14714: mov r12,0xf1e4
c14718: shr r12,#0x2
c1471a: and r12,#0x1
c1471c: bmov 0xfd1c.0x0,r12.0x0
c14720: mov r12,0xf1e4
c14724: shr r12,#0x1
c14726: and r12,#0x1
c14728: bmov 0xfd1c.0x1,r12.0x0
c1472c: mov r12,0xf1e4
c14730: and r12,#0x1
c14732: bmov 0xfd1c.0x2,r12.0x0
c14736: rets


; ============================== Drivers / PWM ==============================

; ----------------------------------------------------------------------------
; pwm_init
; Address: 0xC108CE
; Area:    application/01-drivers/pwm
; Size:    160 bytes
; --------------------------------------------------------------------------
c108ce: mov r12,#0xf423
c108d2: mov 0xe892,r12
c108d6: mov r13,#0x805
c108da: mov 0xe8ac,r13
c108de: mov r14,#0x20
c108e2: mov 0xe8ae,r14
c108e6: mov r15,#0x5780
c108ea: mov 0xe8a0,r15
c108ee: mov r1,#0x4b00
c108f2: mov 0xe8a2,r1
c108f6: mov 0xe8a4,0xff1c
c108fa: mov r2,#0x1
c108fc: mov 0xe894,r2
c10900: mov r3,#0x110
c10904: mov 0xe8c6,r3
c10908: mov 0xe8a8,0xff1c
c1090c: mov 0xe8c4,0xff1c
c10910: mov r4,#0x8014
c10914: mov 0xe8c0,r4
c10918: mov 0xe8ca,0xff1c
c1091c: mov 0xe8ce,0xff1c
c10920: mov r5,#0x40
c10924: mov 0xe8a6,r5
c10928: mov 0xe8c2,0xff1c
c1092c: extr #0x3
c1092e: or 0xf166,#0x5c
c10932: or 0xf168,#0x5d
c10936: or 0xff64,#0x5e
c1093a: extp 0x301, #0x1
c1093e: movb RL1,0x1081
c10942: cmpb RL1,#0x2
c10944: jmpr cc_NE,0xc10964
c10946: extr #0x1
c10948: or 0xff30,#0x10
c1094c: mov r10,0xff04
c10950: bclr r10.0x4
c10952: bset r10.0x4
c10954: mov 0xff04,r10
c10958: mov r10,0xf104
c1095c: bclr r10.0x4
c1095e: bset r10.0x4
c10960: mov 0xf104,r10
c10964: mov r12,#0x202
c10968: mov 0xe8a6,r12
c1096c: rets


; ----------------------------------------------------------------------------
; pwm_period_duty_calc
; Address: 0xC10A74
; Area:    application/01-drivers/pwm
; Size:    106 bytes
; --------------------------------------------------------------------------
c10a74: mov r1,0xe8ac
c10a78: and r1,#0xf
c10a7c: mov r14,#0x4800
c10a80: mov r15,#0x1e8
c10a84: jmpr cc_UC,0xc10a8e
c10a86: shr r14,#0x1
c10a88: bmov r14.0xf,r15.0x0
c10a8c: ashr r15,#0x1
c10a8e: cmpd1 r1,#0x0
c10a90: jmpr cc_NE,0xc10a86
c10a92: mov [-r0],r13
c10a94: mov r1,r12
c10a96: mov r12,r14
c10a98: mov r13,r15
c10a9a: mov r14,r1
c10a9c: calls 0xc1096e
c10aa0: mov 0xc504,r4
c10aa4: mov r13,[r0+]
c10aa6: mov r14,r13
c10aa8: mov r12,r4
c10aaa: mov r13,#0x0
c10aac: calls 0xc109a2
c10ab0: mov 0xc4ea,r4
c10ab4: mov r12,0xc504
c10ab8: cmp r12,0xc4ea
c10abc: jmpr cc_NE,0xc10ac2
c10abe: sub 0xc4ea,0xff1e
c10ac2: mov r12,0xc504
c10ac6: mov 0xe892,r12
c10aca: mov r13,0xc4ea
c10ace: mov 0xe8a2,r13
c10ad2: mov r14,0xe8a6
c10ad6: bset r14.0x6
c10ad8: mov 0xe8a6,r14
c10adc: rets


; ----------------------------------------------------------------------------
; pwm_output_enable
; Address: 0xC10AFC
; Area:    application/01-drivers/pwm
; Size:    16 bytes
; --------------------------------------------------------------------------
c10afc: atomic #0x4
c10afe: extr #0x1
c10b00: bset 0xff30.0x2
c10b02: bset 0xff04.0x2
c10b04: atomic #0x4
c10b06: extr #0x1
c10b08: bset 0xff04.0x2
c10b0a: rets


; ============================== Drivers / clock ==============================

; ----------------------------------------------------------------------------
; pll_isr
; Address: 0xC01048
; Area:    application/01-drivers/clock
; Size:    56 bytes
; --------------------------------------------------------------------------
c01048: push 0xffde
c0104a: push 0xfe5c
c0104c: push 0xfe5e
c0104e: push 0xffdc
c01050: scxt 0xffda,#0x0
c01054: push 0xff08
c01056: push 0xff0a
c01058: extr #0x4
c0105a: push 0xf000
c0105c: push 0xf002
c0105e: push 0xf004
c01060: push 0xfe06
c01062: srst
c01066: extr #0x4
c01068: pop 0xf006
c0106a: pop 0xf004
c0106c: pop 0xf002
c0106e: pop 0xfe00
c01070: pop 0xff0a
c01072: pop 0xff08
c01074: pop 0xffda
c01076: pop 0xffdc
c01078: pop 0xfe5e
c0107a: pop 0xfe5c
c0107c: pop 0xffde
c0107e: reti


; ----------------------------------------------------------------------------
; clock_init
; Address: 0xC01080
; Area:    application/01-drivers/clock
; Size:    176 bytes
; --------------------------------------------------------------------------
c01080: extr #0x1
c01082: mov 0xffc4,#0x0
c01086: mov 0xff02,#0x0
c0108a: extr #0x2
c0108c: mov 0xf082,#0x0
c01090: mov 0xff02,#0x0
c01094: mov 0xff00,#0x0
c01098: extr #0x2
c0109a: mov 0xf080,#0x0
c0109e: mov 0xff00,#0x0
c010a2: mov 0xff06,#0x8
c010a6: extr #0x3
c010a8: mov 0xf120,#0x0
c010ac: mov 0xf086,#0x0
c010b0: mov 0xff06,#0x2e
c010b4: mov 0xff04,#0x0
c010b8: extr #0x4
c010ba: mov 0xf130,#0x0
c010be: mov 0xf084,#0x0
c010c2: mov 0xf104,#0x71
c010c6: or 0xff04,#0xa
c010ca: extr #0x2
c010cc: or 0xf104,#0x40
c010d0: mov 0xffc6,#0x0
c010d4: mov 0xffc4,#0x0
c010d8: extr #0x3
c010da: mov 0xf126,#0x0
c010de: mov 0xf128,#0x0
c010e2: mov 0xfe8a,#0x0
c010e6: mov 0xffc6,#0x2240
c010ea: extr #0x1
c010ec: mov 0xffca,#0x0
c010f0: mov 0xffc8,#0x0
c010f4: extr #0x3
c010f6: mov 0xf12a,#0x0
c010fa: mov 0xf136,#0x0
c010fe: mov 0xfe8c,#0x0
c01102: mov 0xffca,#0x0
c01106: mov 0xff1a,#0x0
c0110a: mov 0xff16,#0x0
c0110e: extr #0x3
c01110: mov 0xf138,#0x0
c01114: mov 0xf13a,#0x3
c01118: mov 0xfe94,#0x0
c0111c: mov 0xff18,#0x10
c01120: mov 0xffb4,#0x0
c01124: extr #0x1
c01126: mov 0xfeaa,#0x0
c0112a: mov 0xffb6,#0x0
c0112e: rets


; ============================== Diagnostics / KWP2000 ==============================

; ----------------------------------------------------------------------------
; kwp_dispatch
; Address: 0xC01482
; Area:    application/02-diagnostics/kwp
; Size:    154 bytes
; --------------------------------------------------------------------------
c01482: movb RL1,0xc1d1
c01486: cmpb RL1,#0x1
c01488: jmpr cc_NE,0xc0151a
c0148a: movb RL2,0xc147
c0148e: cmpb RL2,#0x81
c01492: jmpr cc_NE,0xc0149a
c01494: calls 0xc0151c
c01498: jmpr cc_UC,0xc01510
c0149a: movb RL1,0xc148
c0149e: cmpb RL1,#0x10
c014a2: jmpr cc_EQ,0xc014d6
c014a4: cmpb RL1,#0x83
c014a8: jmpr cc_EQ,0xc014dc
c014aa: cmpb RL1,#0x23
c014ae: jmpr cc_EQ,0xc014e2
c014b0: cmpb RL1,#0x27
c014b4: jmpr cc_EQ,0xc014e8
c014b6: cmpb RL1,#0x31
c014ba: jmpr cc_EQ,0xc014ee
c014bc: cmpb RL1,#0x34
c014c0: jmpr cc_EQ,0xc014f4
c014c2: cmpb RL1,#0x36
c014c6: jmpr cc_EQ,0xc014fa
c014c8: cmpb RL1,#0x38
c014cc: jmpr cc_EQ,0xc01500
c014ce: cmpb RL1,#0x3d
c014d2: jmpr cc_EQ,0xc01506
c014d4: jmpr cc_UC,0xc0150c
c014d6: calls 0xc015f8
c014da: jmpr cc_UC,0xc01510
c014dc: calls 0xc0166a
c014e0: jmpr cc_UC,0xc01510
c014e2: calls 0xc01840
c014e6: jmpr cc_UC,0xc01510
c014e8: calls 0xc01544
c014ec: jmpr cc_UC,0xc01510
c014ee: calls 0xc017a8
c014f2: jmpr cc_UC,0xc01510
c014f4: calls 0xc016c2
c014f8: jmpr cc_UC,0xc01510
c014fa: calls 0xc0170a
c014fe: jmpr cc_UC,0xc01510
c01500: calls 0xc017ea
c01504: jmpr cc_UC,0xc01510
c01506: calls 0xc0190c
c0150a: jmpr cc_UC,0xc01510
c0150c: calls 0xc015da
c01510: movb 0xc1d1,0xff1c
c01514: movb RL1,#0x1
c01516: movb 0xc13c,RL1
c0151a: rets


; ----------------------------------------------------------------------------
; kwp_sid81
; Address: 0xC0151C
; Area:    application/02-diagnostics/kwp
; Size:    40 bytes
; --------------------------------------------------------------------------
c0151c: movb RL1,#0x80
c01520: movb 0xc0b2,RL1
c01524: movb RL2,#0x3
c01526: movb 0xc0b5,RL2
c0152a: movb RL3,#0xc1
c0152e: movb 0xc0b6,RL3
c01532: movb RL4,#0xef
c01536: movb 0xc0b7,RL4
c0153a: movb RL5,#0x8f
c0153e: movb 0xc0b8,RL5
c01542: rets


; ----------------------------------------------------------------------------
; kwp_sid27_security
; Address: 0xC01544
; Area:    application/02-diagnostics/kwp
; Size:    150 bytes
; --------------------------------------------------------------------------
c01544: movb RL1,0xc149
c01548: cmpb RL1,#0x1
c0154a: jmpr cc_EQ,0xc01552
c0154c: cmpb RL1,#0x2
c0154e: jmpr cc_EQ,0xc01580
c01550: jmpr cc_UC,0xc015d8
c01552: movb RL1,#0x80
c01556: movb 0xc0b2,RL1
c0155a: movb RL2,#0x4
c0155c: movb 0xc0b5,RL2
c01560: movb RL3,#0x67
c01564: movb 0xc0b6,RL3
c01568: movb RL4,#0x1
c0156a: movb 0xc0b7,RL4
c0156e: movb RL5,#0x12
c01572: movb 0xc0b8,RL5
c01576: movb RL1,#0x34
c0157a: movb 0xc0b9,RL1
c0157e: rets
c01580: movb RL1,#0x3
c01582: movb 0xc0b5,RL1
c01586: movb RL2,#0x80
c0158a: movb 0xc0b2,RL2
c0158e: movb RL3,0xc14a
c01592: cmpb RL3,#0x84
c01596: jmpr cc_NE,0xc015c0
c01598: movb RL4,0xc14b
c0159c: cmpb RL4,#0x74
c015a0: jmpr cc_NE,0xc015c0
c015a2: movb RL5,#0x1
c015a4: movb 0xc09a,RL5
c015a8: movb RL1,#0x67
c015ac: movb 0xc0b6,RL1
c015b0: movb RL1,#0x2
c015b2: movb 0xc0b7,RL1
c015b6: movb RL1,#0x34
c015ba: movb 0xc0b8,RL1
c015be: rets
c015c0: movb RL1,#0x7f
c015c4: movb 0xc0b6,RL1
c015c8: movb RL2,#0x27
c015cc: movb 0xc0b7,RL2
c015d0: movb RL3,#0x35
c015d4: movb 0xc0b8,RL3
c015d8: rets


; ----------------------------------------------------------------------------
; kwp_negative
; Address: 0xC015DA
; Area:    application/02-diagnostics/kwp
; Size:    30 bytes
; --------------------------------------------------------------------------
c015da: movb RL1,#0x3
c015dc: movb 0xc0b5,RL1
c015e0: movb RL2,#0x7f
c015e4: movb 0xc0b6,RL2
c015e8: movb RL3,#0x10
c015ec: movb 0xc0b7,RL3
c015f0: movb RL4,#0x1
c015f2: movb 0xc0b8,RL4
c015f6: rets


; ----------------------------------------------------------------------------
; kwp_sid10_session
; Address: 0xC015F8
; Area:    application/02-diagnostics/kwp
; Size:    114 bytes
; --------------------------------------------------------------------------
c015f8: movb RL1,0xc149
c015fc: cmpb RL1,#0x81
c01600: jmpr cc_EQ,0xc0160a
c01602: cmpb RL1,#0x85
c01606: jmpr cc_EQ,0xc01622
c01608: jmpr cc_UC,0xc01660
c0160a: movb RL1,#0x2
c0160c: movb 0xc0b5,RL1
c01610: movb RL2,#0x50
c01614: movb 0xc0b6,RL2
c01618: movb RL3,#0x81
c0161c: movb 0xc0b7,RL3
c01620: jmpr cc_UC,0xc01660
c01622: movb RL1,0xc09a
c01626: cmpb RL1,#0x1
c01628: jmpr cc_NE,0xc01642
c0162a: movb RL2,#0x2
c0162c: movb 0xc0b5,RL2
c01630: movb RL3,#0x50
c01634: movb 0xc0b6,RL3
c01638: movb RL4,#0x85
c0163c: movb 0xc0b7,RL4
c01640: jmpr cc_UC,0xc01660
c01642: movb RL1,#0x3
c01644: movb 0xc0b5,RL1
c01648: movb RL2,#0x7f
c0164c: movb 0xc0b6,RL2
c01650: movb RL3,#0x10
c01654: movb 0xc0b7,RL3
c01658: movb RL4,#0x85
c0165c: movb 0xc0b8,RL4
c01660: movb RL1,#0x80
c01664: movb 0xc0b2,RL1
c01668: rets


; ----------------------------------------------------------------------------
; kwp_sid83
; Address: 0xC0166A
; Area:    application/02-diagnostics/kwp
; Size:    88 bytes
; --------------------------------------------------------------------------
c0166a: movb RL1,0xc149
c0166e: jmpr cc_EQ,0xc01692
c01670: cmpb RL1,#0x3
c01672: jmpr cc_NE,0xc016c0
c01674: movb RL1,#0x82
c01678: movb 0xc0b2,RL1
c0167c: movb RL2,#0x2
c0167e: movb 0xc0b5,RL2
c01682: movb RL3,#0xc3
c01686: movb 0xc0b6,RL3
c0168a: movb RL4,#0x3
c0168c: movb 0xc0b7,RL4
c01690: rets
c01692: movb RL1,#0x87
c01696: movb 0xc0b2,RL1
c0169a: movb RL2,#0x7
c0169c: movb 0xc0b5,RL2
c016a0: movb RL3,#0xc3
c016a4: movb 0xc0b6,RL3
c016a8: movb 0xc0b7,0xff1c
c016ac: movb 0xc0b8,0xff1c
c016b0: movb 0xc0b9,0xff1e
c016b4: movb 0xc0ba,0xff1c
c016b8: movb 0xc0bb,0xff1e
c016bc: movb 0xc0bc,0xff1c
c016c0: rets


; ----------------------------------------------------------------------------
; kwp_sid34_download
; Address: 0xC016C2
; Area:    application/02-diagnostics/kwp
; Size:    72 bytes
; --------------------------------------------------------------------------
c016c2: movb RL1,0xc09a
c016c6: cmpb RL1,#0x1
c016c8: jmpr cc_NE,0xc016ea
c016ca: movb RL2,#0x82
c016ce: movb 0xc0b2,RL2
c016d2: movb RL3,#0x2
c016d4: movb 0xc0b5,RL3
c016d8: movb RL4,#0x74
c016dc: movb 0xc0b6,RL4
c016e0: movb RL5,#0xfb
c016e4: movb 0xc0b7,RL5
c016e8: rets
c016ea: movb RL1,#0x3
c016ec: movb 0xc0b5,RL1
c016f0: movb RL2,#0x7f
c016f4: movb 0xc0b6,RL2
c016f8: movb RL3,#0x10
c016fc: movb 0xc0b7,RL3
c01700: movb RL4,#0x33
c01704: movb 0xc0b8,RL4
c01708: rets


; ----------------------------------------------------------------------------
; kwp_sid36_transfer
; Address: 0xC0170A
; Area:    application/02-diagnostics/kwp
; Size:    158 bytes
; --------------------------------------------------------------------------
c0170a: movb RL1,0xc09a
c0170e: cmpb RL1,#0x1
c01710: jmpr cc_NE,0xc01788
c01712: movbz r12,0xc149
c01716: mov r13,#0x0
c01718: mov r14,r12
c0171a: shl r12,#0x8
c0171c: shl r13,#0x8
c0171e: shr r14,#0x8
c01720: or r13,r14
c01722: movbz r14,0xc14a
c01726: mov r15,#0x0
c01728: add r12,r14
c0172a: addc r13,r15
c0172c: mov r14,r12
c0172e: shl r12,#0x8
c01730: shl r13,#0x8
c01732: shr r14,#0x8
c01734: or r13,r14
c01736: movbz r14,0xc14b
c0173a: mov r2,#0x0
c0173c: add r12,r14
c0173e: addc r13,r2
c01740: mov r14,r13
c01742: mov r13,r12
c01744: mov [-r0],r13
c01746: shr r13,#0xe
c01748: shl r14,#0x2
c0174a: or r14,r13
c0174c: mov r13,[r0+]
c0174e: and r13,#0x3fff
c01752: movb RL1,#0x0
c01754: mov r12,r2
c01756: mov r15,#0xc14c
c0175a: add r15,r12
c0175c: mov r3,r13
c0175e: mov r4,r14
c01760: add r13,#0x1
c01762: movb RL2,[r15]
c01764: extp r4, #0x1
c01766: movb [r3],RL2
c01768: movb RL2,[r15]
c0176a: addb RL1,RL2
c0176c: add r12,#0x1
c0176e: cmp r12,#0x7f
c01772: jmpr cc_ULE,0xc01756
c01774: movb RL2,#0x2
c01776: movb 0xc0b5,RL2
c0177a: movb RL3,#0x76
c0177e: movb 0xc0b6,RL3
c01782: movb 0xc0b7,RL1
c01786: rets
c01788: movb RL1,#0x3
c0178a: movb 0xc0b5,RL1
c0178e: movb RL2,#0x7f
c01792: movb 0xc0b6,RL2
c01796: movb RL3,#0x36
c0179a: movb 0xc0b7,RL3
c0179e: movb RL4,#0xbd
c017a2: movb 0xc0b8,RL4
c017a6: rets


; ----------------------------------------------------------------------------
; kwp_sid31_routine
; Address: 0xC017A8
; Area:    application/02-diagnostics/kwp
; Size:    66 bytes
; --------------------------------------------------------------------------
c017a8: movb RL1,0xc09a
c017ac: cmpb RL1,#0x1
c017ae: jmpr cc_NE,0xc017ca
c017b0: movb RL2,#0x1
c017b2: movb 0xc09b,RL2
c017b6: movb RL3,#0x2
c017b8: movb 0xc0b5,RL3
c017bc: movb RL4,#0x71
c017c0: movb 0xc0b6,RL4
c017c4: movb 0xc0b7,RL3
c017c8: rets
c017ca: movb RL1,#0x3
c017cc: movb 0xc0b5,RL1
c017d0: movb RL2,#0x7f
c017d4: movb 0xc0b6,RL2
c017d8: movb RL3,#0x31
c017dc: movb 0xc0b7,RL3
c017e0: movb RL4,#0xbd
c017e4: movb 0xc0b8,RL4
c017e8: rets


; ----------------------------------------------------------------------------
; kwp_sid38
; Address: 0xC017EA
; Area:    application/02-diagnostics/kwp
; Size:    86 bytes
; --------------------------------------------------------------------------
c017ea: movb RL1,0xc09a
c017ee: cmpb RL1,#0x1
c017f0: jmpr cc_NE,0xc01820
c017f2: movb RL2,#0x1
c017f4: movb 0xc09b,RL2
c017f8: movb RL3,#0x4
c017fa: movb 0xc0b5,RL3
c017fe: movb RL4,#0x78
c01802: movb 0xc0b6,RL4
c01806: movb RL5,0xc149
c0180a: movb 0xc0b7,RL5
c0180e: movb RL1,0xc14a
c01812: movb 0xc0b8,RL1
c01816: movb RL1,0xc14b
c0181a: movb 0xc0b9,RL1
c0181e: rets
c01820: movb RL1,#0x3
c01822: movb 0xc0b5,RL1
c01826: movb RL2,#0x7f
c0182a: movb 0xc0b6,RL2
c0182e: movb RL3,#0x31
c01832: movb 0xc0b7,RL3
c01836: movb RL4,#0xbd
c0183a: movb 0xc0b8,RL4
c0183e: rets


; ----------------------------------------------------------------------------
; kwp_sid23_read_mem
; Address: 0xC01840
; Area:    application/02-diagnostics/kwp
; Size:    204 bytes
; --------------------------------------------------------------------------
c01840: movbz r14,0xc14c
c01844: movbz r12,0xc149
c01848: mov r13,#0x0
c0184a: mov r15,r12
c0184c: shl r12,#0x8
c0184e: shl r13,#0x8
c01850: shr r15,#0x8
c01852: or r13,r15
c01854: movbz r15,0xc14a
c01858: mov r1,#0x0
c0185a: add r12,r15
c0185c: addc r13,r1
c0185e: mov r15,r12
c01860: shl r12,#0x8
c01862: shl r13,#0x8
c01864: shr r15,#0x8
c01866: or r13,r15
c01868: movbz r15,0xc14b
c0186c: mov r2,#0x0
c0186e: add r12,r15
c01870: addc r13,r2
c01872: mov r15,r12
c01874: mov r1,r13
c01876: mov [-r0],r15
c01878: shr r15,#0xe
c0187a: shl r1,#0x2
c0187c: or r1,r15
c0187e: mov r15,[r0+]
c01880: and r15,#0x3fff
c01884: mov r3,r12
c01886: mov r4,r13
c01888: sub r3,#0x0
c0188a: subc r4,#0xc0
c0188e: jmpr cc_C,0xc018a4
c01890: mov r3,r14
c01892: mov r4,#0x0
c01894: mov r5,r12
c01896: mov r10,r13
c01898: add r5,r3
c0189a: addc r10,r4
c0189c: sub r5,#0x0
c0189e: subc r10,#0xc4
c018a2: jmpr cc_ULE,0xc018c2
c018a4: mov r2,r12
c018a6: mov r3,r13
c018a8: sub r2,#0x0
c018aa: subc r3,#0xe0
c018ae: jmpr cc_C,0xc018ec
c018b0: mov r2,r14
c018b2: mov r3,#0x0
c018b4: add r12,r2
c018b6: addc r13,r3
c018b8: sub r12,#0x1800
c018bc: subc r13,#0xe0
c018c0: jmpr cc_UGT,0xc018ec
c018c2: cmp r14,#0x80
c018c6: jmpr cc_UGT,0xc018ec
c018c8: mov r12,#0x1
c018ca: jmpr cc_UC,0xc018d6
c018cc: extp r1, #0x1
c018ce: movb RL2,[r15+]
c018d0: movb [r12+#0xc0b6],RL2
c018d4: add r12,#0x1
c018d6: cmp r12,r14
c018d8: jmpr cc_ULE,0xc018cc
c018da: add r14,#0x1
c018dc: mov r1,r14
c018de: movb 0xc0b5,RL1
c018e2: movb RL2,#0x63
c018e6: movb 0xc0b6,RL2
c018ea: rets
c018ec: movb RL1,#0x3
c018ee: movb 0xc0b5,RL1
c018f2: movb RL2,#0x7f
c018f6: movb 0xc0b6,RL2
c018fa: movb RL3,#0x23
c018fe: movb 0xc0b7,RL3
c01902: movb RL4,#0x12
c01906: movb 0xc0b8,RL4
c0190a: rets


; ----------------------------------------------------------------------------
; kwp_sid3D_write_mem
; Address: 0xC0190C
; Area:    application/02-diagnostics/kwp
; Size:    200 bytes
; --------------------------------------------------------------------------
c0190c: movbz r14,0xc14c
c01910: movbz r12,0xc149
c01914: mov r13,#0x0
c01916: mov r15,r12
c01918: shl r12,#0x8
c0191a: shl r13,#0x8
c0191c: shr r15,#0x8
c0191e: or r13,r15
c01920: movbz r15,0xc14a
c01924: mov r1,#0x0
c01926: add r12,r15
c01928: addc r13,r1
c0192a: mov r15,r12
c0192c: shl r12,#0x8
c0192e: shl r13,#0x8
c01930: shr r15,#0x8
c01932: or r13,r15
c01934: movbz r15,0xc14b
c01938: mov r2,#0x0
c0193a: add r12,r15
c0193c: addc r13,r2
c0193e: mov r15,r12
c01940: mov r1,r13
c01942: mov [-r0],r15
c01944: shr r15,#0xe
c01946: shl r1,#0x2
c01948: or r1,r15
c0194a: mov r15,[r0+]
c0194c: and r15,#0x3fff
c01950: mov r3,r12
c01952: mov r4,r13
c01954: sub r3,#0x0
c01956: subc r4,#0xe0
c0195a: jmpr cc_C,0xc019b4
c0195c: mov r3,r14
c0195e: mov r4,#0x0
c01960: add r12,r3
c01962: addc r13,r4
c01964: sub r12,#0x1800
c01968: subc r13,#0xe0
c0196c: jmpr cc_UGT,0xc019b4
c0196e: cmp r14,#0x80
c01972: jmpr cc_UGT,0xc019b4
c01974: mov r12,#0x1
c01976: jmpr cc_UC,0xc01988
c01978: movb RL2,[r12+#0xc14c]
c0197c: mov r13,r15
c0197e: mov r3,r1
c01980: add r15,#0x1
c01982: extp r3, #0x1
c01984: movb [r13],RL2
c01986: add r12,#0x1
c01988: cmp r12,r14
c0198a: jmpr cc_ULE,0xc01978
c0198c: movb RL1,#0x4
c0198e: movb 0xc0b5,RL1
c01992: movb RL2,#0x7d
c01996: movb 0xc0b6,RL2
c0199a: movb RL3,0xc149
c0199e: movb 0xc0b7,RL3
c019a2: movb RL4,0xc14a
c019a6: movb 0xc0b8,RL4
c019aa: movb RL5,0xc14b
c019ae: movb 0xc0b9,RL5
c019b2: rets
c019b4: movb RL1,#0x3
c019b6: movb 0xc0b5,RL1
c019ba: movb RL2,#0x7f
c019be: movb 0xc0b6,RL2
c019c2: movb RL3,#0x3d
c019c6: movb 0xc0b7,RL3
c019ca: movb RL4,#0x12
c019ce: movb 0xc0b8,RL4
c019d2: rets


; ============================== Diagnostics / K-line transport ==============================

; ----------------------------------------------------------------------------
; kline_receive_pattern
; Address: 0xC01212
; Area:    application/02-diagnostics/kline-transport
; Size:    6 bytes
; --------------------------------------------------------------------------
c01212: jb 0xff6e.0x7,0xc011d8
c01216: rets


; ----------------------------------------------------------------------------
; kline_get_status
; Address: 0xC12696
; Area:    application/02-diagnostics/kline-transport
; Size:    6 bytes
; --------------------------------------------------------------------------
c12696: movb RL4,0xc56d
c1269a: rets


; ----------------------------------------------------------------------------
; kline_start_timeout
; Address: 0xC126B0
; Area:    application/02-diagnostics/kline-transport
; Size:    10 bytes
; --------------------------------------------------------------------------
c126b0: mov r12,#0x500
c126b4: mov 0xc56a,r12
c126b8: rets


; ----------------------------------------------------------------------------
; kline_state_reset
; Address: 0xC126BC
; Area:    application/02-diagnostics/kline-transport
; Size:    22 bytes
; --------------------------------------------------------------------------
c126bc: mov r1,r12
c126be: movb 0xc582,RL1
c126c2: movb 0xc57d,0xff1c
c126c6: bclr 0xffb0.0x4
c126c8: movb 0xc588,0xff1c
c126cc: mov 0xc584,0xff1c
c126d0: rets


; ----------------------------------------------------------------------------
; kline_prepare_frame
; Address: 0xC126DA
; Area:    application/02-diagnostics/kline-transport
; Size:    200 bytes
; --------------------------------------------------------------------------
c126da: mov r1,r12
c126dc: movb 0xc5a9,RL1
c126e0: mov 0xc59e,0xff1c
c126e4: movb RL2,0xc5a0
c126e8: jmpr cc_EQ,0xc12790
c126ea: movb RL3,0xc599
c126ee: movb RL4,0xc57f
c126f2: movbz r12,RL3
c126f4: add r12,#0xf
c126f8: mov r13,r12
c126fa: ashr r13,#0x3
c126fc: shr r13,#0xc
c126fe: add r13,r12
c12700: ashr r13,#0x4
c12702: mov 0xc5a6,r13
c12706: movbz r12,RL4
c12708: cmp r12,#0xf0
c1270c: jmpr cc_ULE,0xc12714
c1270e: shl r12,#0x8
c12710: sub r12,#0xf000
c12714: shl r12,#0x5
c12716: mov r13,#0xa
c12718: mov 0xfe0e,r12
c1271c: divu r13
c1271e: movb 0xc5a5,RL4
c12722: movb RL5,0xc598
c12726: movb 0xc57e,RL5
c1272a: movb RL1,0xc580
c1272e: movb 0xc5a8,RL1
c12732: movb RL1,0xc592
c12736: movb 0xc577,RL1
c1273a: movbz r14,0xc57e
c1273e: add r14,#0xf
c12742: mov r15,r14
c12744: ashr r15,#0x3
c12746: shr r15,#0xc
c12748: add r15,r14
c1274a: ashr r15,#0x4
c1274c: mov 0xc5bc,r15
c12750: movbz r14,0xc5a8
c12754: movb 0xc57c,RL3
c12758: mov 0xc59c,0xfe0e
c1275c: mov r12,0xfe0e
c12760: cmp r14,#0xff
c12764: jmpr cc_NE,0xc1276c
c12766: mov 0xc5b4,0xff1e
c1276a: jmpr cc_UC,0xc12776
c1276c: movbz r12,0xc5a8
c12770: shl r12,#0x5
c12772: mov 0xc5b4,r12
c12776: movbz r12,0xc577
c1277a: add r12,#0xf
c1277e: mov r13,r12
c12780: ashr r13,#0x3
c12782: shr r13,#0xc
c12784: add r13,r12
c12786: ashr r13,#0x4
c12788: mov 0xc586,r13
c1278c: movb 0xc5a0,0xff1c
c12790: mov r12,#0x6
c12792: mov 0xc584,r12
c12796: movb 0xc58c,0xff1c
c1279a: movb 0xc56f,0xff1c
c1279e: bset 0xffb0.0x4
c127a0: rets


; ----------------------------------------------------------------------------
; kline_rx_state_7
; Address: 0xC12826
; Area:    application/02-diagnostics/kline-transport
; Size:    34 bytes
; --------------------------------------------------------------------------
c12826: mov r12,0xc5a2
c1282a: cmp r12,#0x1
c1282c: jmpr cc_NE,0xc12832
c1282e: mov 0xc5be,0xff1c
c12832: mov r12,0xc5a2
c12836: jmpr cc_NE,0xc1283c
c12838: mov 0xc5b0,0xff1c
c1283c: mov 0xc574,0xff1c
c12840: mov r12,#0x7
c12842: mov 0xc584,r12
c12846: rets


; ----------------------------------------------------------------------------
; kline_rx_state_8
; Address: 0xC12848
; Area:    application/02-diagnostics/kline-transport
; Size:    14 bytes
; --------------------------------------------------------------------------
c12848: mov r12,#0x8
c1284a: mov 0xc584,r12
c1284e: mov r13,#0x2
c12850: mov 0xc5ba,r13
c12854: rets


; ----------------------------------------------------------------------------
; kline_push_rx_byte
; Address: 0xC1293C
; Area:    application/02-diagnostics/kline-transport
; Size:    50 bytes
; --------------------------------------------------------------------------
c1293c: mov r1,r12
c1293e: movb RL2,0xc58c
c12942: movbz r12,RL2
c12944: subb 0xc58c,0xff1e
c12948: movb [r12+#0xf600],RL1
c1294c: mov r12,0xc584
c12950: cmp r12,#0x6
c12952: jmpr cc_NE,0xc1295e
c12954: movb RL1,0xf600
c12958: jmpr cc_EQ,0xc1295e
c1295a: calls 0xc12826
c1295e: movb RL1,0xc58c
c12962: cmpb RL1,#0x3d
c12966: jmpr cc_NE,0xc1296c
c12968: movb 0xc58c,0xff1c
c1296c: rets


; ----------------------------------------------------------------------------
; kline_transport_task
; Address: 0xC12982
; Area:    application/02-diagnostics/kline-transport
; Size:    324 bytes
; --------------------------------------------------------------------------
c12982: sub r0,#0x2
c12984: cmp r12,#0x0
c12986: jmpr cc_EQ,0xc12990
c12988: cmp r12,#0x1
c1298a: jmpr cc_EQ,0xc129c0
c1298c: jmpa cc_UC,0xc1305a
c12990: mov r12,#0x6
c12992: calls 0xc126bc
c12996: bclr 0xffb0.0x4
c12998: calls 0xc126b0
c1299c: movb 0xc5ab,0xff1c
c129a0: movb 0xc568,0xff1c
c129a4: calls 0xc0bff6
c129a8: mov r10,#0x0
c129aa: mov r11,#0x0
c129ac: mov r4,#0x7fc
c129b0: mov r5,#0xe0
c129b4: calls 0xc28c62
c129b8: calls 0xc13d50
c129bc: jmpa cc_UC,0xc1305a
c129c0: mov r12,0xc584
c129c4: cmp r12,#0xf
c129c8: jmpa cc_UGT,0xc12f6e
c129cc: shl r12,#0x1
c129ce: add r12,#0x7164
c129d2: mov r12,[r12]
c129d4: jmpi cc_UC,[r12]
c12f6e: mov r12,0xc56a
c12f72: jmpr cc_EQ,0xc12f78
c12f74: add 0xc56a,0xff1e
c12f78: mov r12,0xc584
c12f7c: cmp r12,#0xd
c12f80: jmpa cc_EQ,0xc12f9c
c12f84: cmp r12,#0xa
c12f88: jmpa cc_EQ,0xc12f9c
c12f8c: movbz r13,0xc5ab
c12f90: jmpa cc_EQ,0xc12f9c
c12f94: movb 0xc5ab,0xff1c
c12f98: bclr 0xff10.0xb
c12f9a: jmpr cc_UC,0xc12f9a
c12f9c: movb RL1,0xc57d
c12fa0: jmpr cc_EQ,0xc12fb4
c12fa2: movb RL2,0xc568
c12fa6: jmpr cc_NE,0xc12fb8
c12fa8: movb RL3,#0x1
c12faa: movb 0xc568,RL3
c12fae: calls 0xc0bff4
c12fb2: jmpr cc_UC,0xc12fb8
c12fb4: movb 0xc568,0xff1c
c12fb8: movb RL1,0xc5b6
c12fbc: jmpr cc_NE,0xc12fc6
c12fbe: calls 0xc12696
c12fc2: cmpb RL4,#0x0
c12fc4: jmpr cc_EQ,0xc12ff4
c12fc6: mov r12,0xc584
c12fca: cmp r12,#0xd
c12fce: jmpr cc_EQ,0xc12ff4
c12fd0: cmp r12,#0xa
c12fd4: jmpr cc_EQ,0xc12ff4
c12fd6: movb RL1,0xc56c
c12fda: mov r1,r1
c12fdc: movbz r13,RL1
c12fde: mov r14,r13
c12fe0: shl r14,#0x2
c12fe2: add r14,r13
c12fe4: shl r14,#0x1
c12fe6: mov r4,[r14+#0x70c8]
c12fea: mov r5,[r14+#0x70ca]
c12fee: calls 0xc28c4e
c12ff2: jmpr cc_UC,0xc1305a
c12ff4: mov r12,0xc584
c12ff8: cmp r12,#0x9
c12ffc: jmpr cc_NE,0xc13002
c12ffe: mov r13,#0x1
c13000: jmpr cc_UC,0xc13004
c13002: mov r13,#0x0
c13004: cmp r13,#0x0
c13006: jmpr cc_EQ,0xc1305a
c13008: movbz r12,0xc5c4
c1300c: movb RL1,#0x0
c1300e: movb RL2,0x7162
c13012: movb RL3,[r12+#0xf63d]
c13016: movb 0xc56c,0xff1c
c1301a: jmpr cc_UC,0xc13044
c1301c: movbz r12,0xc56c
c13020: mov r13,r12
c13022: shl r12,#0x2
c13024: add r12,r13
c13026: shl r12,#0x1
c13028: movb RL4,[r12+#0x70c2]
c1302c: cmpb RL4,RL3
c1302e: jmpr cc_NE,0xc13040
c13030: mov r4,[r12+#0x70c4]
c13034: mov r5,[r12+#0x70c6]
c13038: calls 0xc28c4e
c1303c: movb RL1,#0x1
c1303e: jmpr cc_UC,0xc1304a
c13040: subb 0xc56c,0xff1e
c13044: cmpb RL2,0xc56c
c13048: jmpr cc_NC,0xc1301c
c1304a: cmpb RL1,#0x0
c1304c: jmpr cc_NE,0xc1305a
c1304e: mov r4,0x70c4
c13052: mov r5,0x70c6
c13056: calls 0xc28c4e
c1305a: add r0,#0x2
c1305c: rets


; ============================== Diagnostics / CAN transport ==============================

; ----------------------------------------------------------------------------
; can_diag_object_init
; Address: 0xC019D6
; Area:    application/02-diagnostics/can-transport
; Size:    70 bytes
; --------------------------------------------------------------------------
c019d6: mov r12,#0x1fb8
c019da: mov r13,#0x5599
c019de: extp 0x80, #0x2
c019e2: mov 0x44a,r12
c019e6: mov 0x450,r13
c019ea: mov r14,#0xffff
c019ee: extp 0x80, #0x2
c019f2: mov 0x44c,r14
c019f6: mov 0x44c,r14
c019fa: mov r15,#0x1fbc
c019fe: extp 0x80, #0x2
c01a02: mov 0x42a,r15
c01a06: mov 0x430,r13
c01a0a: mov r1,#0xffff
c01a0e: extp 0x80, #0x2
c01a12: mov 0x42c,r1
c01a16: mov 0x42e,r1
c01a1a: rets


; ----------------------------------------------------------------------------
; can_rx_process
; Address: 0xC01A1C
; Area:    application/02-diagnostics/can-transport
; Size:    184 bytes
; --------------------------------------------------------------------------
c01a1c: extp 0x80, #0x1
c01a20: mov r12,0x284
c01a24: jnb r12.0xa,0xc01a4e
c01a28: extp 0x80, #0x1
c01a2c: mov r13,0x450
c01a30: jnb r13.0x1,0xc01a84
c01a34: extp 0x80, #0x1
c01a38: mov r14,0x450
c01a3c: shr r14,#0x8
c01a3e: and r14,#0x3
c01a40: mov r1,r14
c01a42: cmpb RL1,#0x2
c01a44: jmpr cc_NE,0xc01a84
c01a46: mov r14,#0xa
c01a48: mov 0xc1d2,r14
c01a4c: jmpr cc_UC,0xc01a84
c01a4e: extp 0x80, #0x1
c01a52: mov r12,0x284
c01a56: jnb r12.0x9,0xc01a80
c01a5a: extp 0x80, #0x1
c01a5e: mov r13,0x430
c01a62: jnb r13.0x1,0xc01a84
c01a66: extp 0x80, #0x1
c01a6a: mov r14,0x430
c01a6e: shr r14,#0x8
c01a70: and r14,#0x3
c01a72: mov r1,r14
c01a74: cmpb RL1,#0x2
c01a76: jmpr cc_NE,0xc01a84
c01a78: mov r14,#0x9
c01a7a: mov 0xc1d2,r14
c01a7e: jmpr cc_UC,0xc01a84
c01a80: mov 0xc1d2,0xff1c
c01a84: srvwdt
c01a88: mov r12,0xc1d2
c01a8c: jmpr cc_EQ,0xc01ad2
c01a8e: movb RL1,#0x0
c01a90: mov r12,0xc1d2
c01a94: shl r12,#0x5
c01a96: movbz r13,RL1
c01a98: add r13,r12
c01a9a: mov r12,#0x300
c01a9e: add r12,r13
c01aa0: mov r14,#0x80
c01aa4: extp r14, #0x1
c01aa6: movb RL2,[r12]
c01aa8: movbz r12,RL1
c01aaa: mov r13,#0x3740
c01aae: add r13,r12
c01ab0: mov r14,#0x3
c01ab2: extp r14, #0x1
c01ab4: movb [r13],RL2
c01ab6: addb RL1,#0x1
c01ab8: cmpb RL1,#0x8
c01abc: jmpr cc_C,0xc01a90
c01abe: calls 0xc01b22
c01ac2: mov r12,#0x5599
c01ac6: extp 0x80, #0x2
c01aca: mov 0x450,r12
c01ace: mov 0x430,r12
c01ad2: rets


; ----------------------------------------------------------------------------
; can_rx_dispatch
; Address: 0xC01B22
; Area:    application/02-diagnostics/can-transport
; Size:    194 bytes
; --------------------------------------------------------------------------
c01b22: mov r12,0xc1d2
c01b26: cmp r12,#0xa
c01b2a: jmpr cc_NE,0xc01bd4
c01b2c: extp 0x3, #0x1
c01b30: movb RL1,0x3744
c01b34: movbz r13,RL1
c01b36: mov 0xc1d4,r13
c01b3a: shl r13,#0x8
c01b3c: mov 0xc1d4,r13
c01b40: extp 0x3, #0x1
c01b44: movb RL2,0x3745
c01b48: movbz r14,RL2
c01b4a: or 0xc1d4,r14
c01b4e: extp 0x3, #0x1
c01b52: movb RL3,0x3740
c01b56: movbz r3,RL3
c01b58: mov r13,#0x0
c01b5a: mov 0xc1d8,r3
c01b5e: mov 0xc1da,r13
c01b62: mov r14,r3
c01b64: shl r3,#0x8
c01b66: shl r13,#0x8
c01b68: shr r14,#0x8
c01b6a: or r13,r14
c01b6c: extp 0x3, #0x1
c01b70: movb RL4,0x3741
c01b74: movbz r4,RL4
c01b76: mov r14,#0x0
c01b78: or r3,r4
c01b7a: or r13,r14
c01b7c: mov 0xc1d8,r3
c01b80: mov 0xc1da,r13
c01b84: mov r15,r3
c01b86: shl r3,#0x8
c01b88: shl r13,#0x8
c01b8a: shr r15,#0x8
c01b8c: or r13,r15
c01b8e: extp 0x3, #0x1
c01b92: movb RL4,0x3742
c01b96: movbz r4,RL4
c01b98: mov r15,#0x0
c01b9a: or r3,r4
c01b9c: or r13,r15
c01b9e: mov 0xc1d8,r3
c01ba2: mov 0xc1da,r13
c01ba6: mov r4,r3
c01ba8: shl r3,#0x8
c01baa: shl r13,#0x8
c01bac: shr r4,#0x8
c01bae: or r13,r4
c01bb0: extp 0x3, #0x1
c01bb4: movb RL4,0x3743
c01bb8: movbz r4,RL4
c01bba: mov r5,#0x0
c01bbc: or r3,r4
c01bbe: or r13,r5
c01bc0: mov 0xc1d8,r3
c01bc4: mov 0xc1da,r13
c01bc8: mov 0xc1dc,r3
c01bcc: mov 0xc1de,r13
c01bd0: calls 0xc01be4
c01bd4: mov r12,0xc1d2
c01bd8: cmp r12,#0x9
c01bdc: jmpr cc_NE,0xc01be2
c01bde: calls 0xc01c6e
c01be2: rets


; ----------------------------------------------------------------------------
; can_rx_cmd
; Address: 0xC01BE4
; Area:    application/02-diagnostics/can-transport
; Size:    138 bytes
; --------------------------------------------------------------------------
c01be4: mov [-r0],r8
c01be6: extp 0x3, #0x1
c01bea: movb RL1,0x3746
c01bee: cmpb RL1,#0xff
c01bf2: jmpr cc_NE,0xc01c4e
c01bf4: calls 0xc01dec
c01bf8: jmpr cc_UC,0xc01c44
c01bfa: mov r12,0xc1d4
c01bfe: cmp r12,#0x8
c01c02: jmpr cc_ULE,0xc01c08
c01c04: mov r12,#0x8
c01c06: jmpr cc_UC,0xc01c0c
c01c08: mov r12,0xc1d4
c01c0c: mov r8,r12
c01c0e: mov [-r0],r8
c01c10: mov r12,#0xf750
c01c14: mov r4,r12
c01c16: calls 0xc01eea
c01c1a: mov r12,r4
c01c1c: mov r13,r5
c01c1e: mov r14,0xc1dc
c01c22: mov r15,0xc1de
c01c26: calls 0xc01d9a
c01c2a: add r0,#0x2
c01c2c: mov r12,r8
c01c2e: calls 0xc01cc8
c01c32: sub 0xc1d4,r8
c01c36: mov r12,#0x0
c01c38: add 0xc1dc,r8
c01c3c: addc 0xc1de,r12
c01c40: srvwdt
c01c44: mov r8,0xc1d4
c01c48: cmp r8,#0x0
c01c4a: jmpr cc_UGT,0xc01bfa
c01c4c: jmpr cc_UC,0xc01c6a
c01c4e: extp 0x3, #0x1
c01c52: movb RL1,0x3746
c01c56: jmpr cc_NE,0xc01c6a
c01c58: mov r8,0xc1d4
c01c5c: cmp r8,#0x0
c01c5e: jmpr cc_ULE,0xc01c6a
c01c60: movb RL2,#0x1
c01c62: movb 0xc1d6,RL2
c01c66: calls 0xc01dec
c01c6a: mov r8,[r0+]
c01c6c: rets


; ----------------------------------------------------------------------------
; can_isotp_send
; Address: 0xC01C6E
; Area:    application/02-diagnostics/can-transport
; Size:    90 bytes
; --------------------------------------------------------------------------
c01c6e: mov [-r0],r8
c01c70: movb RL1,0xc1d6
c01c74: jmpr cc_EQ,0xc01cc4
c01c76: mov r12,0xc1d4
c01c7a: cmp r12,#0x0
c01c7c: jmpr cc_ULE,0xc01cc4
c01c7e: cmp r12,#0x8
c01c82: jmpr cc_ULE,0xc01c88
c01c84: mov r12,#0x8
c01c86: jmpr cc_UC,0xc01c8c
c01c88: mov r12,0xc1d4
c01c8c: mov r8,r12
c01c8e: mov [-r0],r8
c01c90: mov r12,0xc1dc
c01c94: mov r13,0xc1de
c01c98: mov r14,#0xf740
c01c9c: mov r4,r14
c01c9e: calls 0xc01eea
c01ca2: mov r14,r4
c01ca4: mov r15,r5
c01ca6: calls 0xc01d9a
c01caa: add r0,#0x2
c01cac: sub 0xc1d4,r8
c01cb0: mov r12,#0x0
c01cb2: add 0xc1dc,r8
c01cb6: addc 0xc1de,r12
c01cba: mov r8,0xc1d4
c01cbe: jmpr cc_NE,0xc01cc4
c01cc0: movb 0xc1d6,0xff1c
c01cc4: mov r8,[r0+]
c01cc6: rets


; ----------------------------------------------------------------------------
; can_tx_frame
; Address: 0xC01CC8
; Area:    application/02-diagnostics/can-transport
; Size:    210 bytes
; --------------------------------------------------------------------------
c01cc8: extp 0x80, #0x1
c01ccc: mov r13,0x430
c01cd0: shr r13,#0xc
c01cd2: and r13,#0x3
c01cd4: mov r1,r13
c01cd6: cmpb RL1,#0x2
c01cd8: jmpr cc_EQ,0xc01cc8
c01cda: mov r13,#0x430
c01cde: mov r14,#0x80
c01ce2: extp r14, #0x1
c01ce4: mov r15,[r13]
c01ce6: bfldh r15,#0xc,#0x8
c01cea: extp r14, #0x1
c01cec: mov [r13],r15
c01cee: mov r13,#0x430
c01cf2: mov r14,#0x80
c01cf6: extp r14, #0x1
c01cf8: mov r15,[r13]
c01cfa: bfldh r15,#0x3,#0x2
c01cfe: extp r14, #0x1
c01d00: mov [r13],r15
c01d02: cmp r12,#0x8
c01d06: jmpr cc_NC,0xc01d26
c01d08: mov r13,#0x434
c01d0c: mov r14,#0x80
c01d10: and r12,#0xf
c01d14: shl r12,#0x4
c01d16: extp r14, #0x1
c01d18: mov r15,[r13]
c01d1a: and r15,#0xff0f
c01d1e: or r15,r12
c01d20: extp r14, #0x1
c01d22: mov [r13],r15
c01d24: jmpr cc_UC,0xc01d3a
c01d26: mov r12,#0x434
c01d2a: mov r13,#0x80
c01d2e: extp r13, #0x1
c01d30: mov r14,[r12]
c01d32: bfldl r14,#0x80,#0xf0
c01d36: extp r13, #0x1
c01d38: mov [r12],r14
c01d3a: mov r12,#0x0
c01d3c: mov r13,#0x3750
c01d40: add r13,r12
c01d42: mov r14,#0x3
c01d44: extp r14, #0x1
c01d46: movb RL1,[r13]
c01d48: mov r13,#0x420
c01d4c: add r13,r12
c01d4e: mov r14,#0x80
c01d52: extp r14, #0x1
c01d54: movb [r13],RL1
c01d56: add r12,#0x1
c01d58: cmp r12,#0x8
c01d5c: jmpr cc_C,0xc01d3c
c01d5e: mov r12,#0x430
c01d62: mov r13,#0x80
c01d66: extp r13, #0x1
c01d68: mov r14,[r12]
c01d6a: bfldh r14,#0xc,#0x4
c01d6e: extp r13, #0x1
c01d70: mov [r12],r14
c01d72: mov r12,#0x430
c01d76: mov r13,#0x80
c01d7a: extp r13, #0x1
c01d7c: mov r14,[r12]
c01d7e: bfldh r14,#0x30,#0x20
c01d82: extp r13, #0x1
c01d84: mov [r12],r14
c01d86: extp 0x80, #0x1
c01d8a: mov r12,0x430
c01d8e: shr r12,#0xc
c01d90: and r12,#0x3
c01d92: mov r1,r12
c01d94: cmpb RL1,#0x2
c01d96: jmpr cc_EQ,0xc01d86
c01d98: rets


; ----------------------------------------------------------------------------
; can_tx_confirm
; Address: 0xC01DEC
; Area:    application/02-diagnostics/can-transport
; Size:    212 bytes
; --------------------------------------------------------------------------
c01dec: mov r12,#0x430
c01df0: mov r13,#0x80
c01df4: extp r13, #0x1
c01df6: mov r14,[r12]
c01df8: bfldl r14,#0x40,#0xc0
c01dfc: extp r13, #0x1
c01dfe: mov [r12],r14
c01e00: mov r12,#0x420
c01e04: add r12,#0x10
c01e08: mov r13,#0x80
c01e0c: extp r13, #0x1
c01e0e: mov r14,[r12]
c01e10: bclr r14.0x1
c01e12: extp r13, #0x1
c01e14: mov [r12],r14
c01e16: mov r12,#0x430
c01e1a: mov r13,#0x80
c01e1e: extp r13, #0x1
c01e20: mov r14,[r12]
c01e22: bfldh r14,#0xc0,#0x40
c01e26: extp r13, #0x1
c01e28: mov [r12],r14
c01e2a: mov r12,#0x430
c01e2e: mov r13,#0x80
c01e32: extp r13, #0x1
c01e34: mov r14,[r12]
c01e36: bfldh r14,#0x30,#0x10
c01e3a: extp r13, #0x1
c01e3c: mov [r12],r14
c01e3e: mov r12,#0x430
c01e42: mov r13,#0x80
c01e46: extp r13, #0x1
c01e48: mov r14,[r12]
c01e4a: bfldh r14,#0x3,#0x1
c01e4e: extp r13, #0x1
c01e50: mov [r12],r14
c01e52: movb RL1,0xc1d6
c01e56: jmpr cc_EQ,0xc01e82
c01e58: mov r12,#0x434
c01e5c: mov r13,#0x80
c01e60: extp r13, #0x1
c01e62: mov r14,[r12]
c01e64: and r14,#0xfff7
c01e68: extp r13, #0x1
c01e6a: mov [r12],r14
c01e6c: mov r12,#0x430
c01e70: mov r13,#0x80
c01e74: extp r13, #0x1
c01e76: mov r14,[r12]
c01e78: bfldh r14,#0xc,#0x4
c01e7c: extp r13, #0x1
c01e7e: mov [r12],r14
c01e80: jmpr cc_UC,0xc01eaa
c01e82: mov r12,#0x434
c01e86: mov r13,#0x80
c01e8a: extp r13, #0x1
c01e8c: mov r14,[r12]
c01e8e: bfldl r14,#0x8,#0x8
c01e92: extp r13, #0x1
c01e94: mov [r12],r14
c01e96: mov r12,#0x430
c01e9a: mov r13,#0x80
c01e9e: extp r13, #0x1
c01ea0: mov r14,[r12]
c01ea2: bfldh r14,#0xc,#0x8
c01ea6: extp r13, #0x1
c01ea8: mov [r12],r14
c01eaa: mov r12,#0x430
c01eae: mov r13,#0x80
c01eb2: extp r13, #0x1
c01eb4: mov r14,[r12]
c01eb6: bfldl r14,#0x80,#0xc0
c01eba: extp r13, #0x1
c01ebc: mov [r12],r14
c01ebe: rets


; ============================== Diagnostics / status ==============================

; ----------------------------------------------------------------------------
; diag_status_build
; Address: 0xC1482C
; Area:    application/02-diagnostics/status
; Size:    464 bytes
; --------------------------------------------------------------------------
c1482c: movb 0xc60f,0xff1c
c14830: movb RL1,0xc784
c14834: movb 0xc60e,RL1
c14838: movbz r2,0xc850
c1483c: shl r2,#0x1
c1483e: orb 0xc60e,RL2
c14842: movbz r1,0xc786
c14846: shl r1,#0x2
c14848: orb 0xc60e,RL1
c1484c: movbz r1,0xc780
c14850: shl r1,#0x3
c14852: orb 0xc60e,RL1
c14856: movbz r1,0xc781
c1485a: shl r1,#0x4
c1485c: orb 0xc60e,RL1
c14860: movbz r1,0xc78d
c14864: shl r1,#0x5
c14866: orb 0xc60e,RL1
c1486a: extp 0x380, #0x1
c1486e: movbz r1,0x844
c14872: shl r1,#0x6
c14874: orb 0xc60e,RL1
c14878: movbz r1,0xcac6
c1487c: shl r1,#0x7
c1487e: orb 0xc60e,RL1
c14882: movb RL1,0xcad6
c14886: movb 0xc610,RL1
c1488a: movbz r2,0xc014
c1488e: shl r2,#0x1
c14890: orb 0xc610,RL2
c14894: movbz r1,0xc824
c14898: shl r1,#0x2
c1489a: orb 0xc610,RL1
c1489e: movbz r1,0xc841
c148a2: shl r1,#0x3
c148a4: orb 0xc610,RL1
c148a8: movbz r1,0xc830
c148ac: shl r1,#0x4
c148ae: orb 0xc610,RL1
c148b2: movbz r1,0xc836
c148b6: shl r1,#0x5
c148b8: orb 0xc610,RL1
c148bc: movbz r1,0xc840
c148c0: shl r1,#0x6
c148c2: orb 0xc610,RL1
c148c6: movbz r1,0xcad7
c148ca: shl r1,#0x7
c148cc: orb 0xc610,RL1
c148d0: mov r12,0xcad0
c148d4: cmp r12,#0x1
c148d6: jmpr cc_NE,0xc148de
c148d8: movb RL1,#0x1
c148da: movb 0xc60f,RL1
c148de: movbz r1,0xcac5
c148e2: shl r1,#0x1
c148e4: orb 0xc60f,RL1
c148e8: extp 0x380, #0x1
c148ec: movbz r1,0x810
c148f0: shl r1,#0x2
c148f2: orb 0xc60f,RL1
c148f6: movbz r1,0xcaf8
c148fa: shl r1,#0x3
c148fc: orb 0xc60f,RL1
c14900: extp 0x380, #0x1
c14904: movb RL1,0x89e
c14908: jmpr cc_NE,0xc14912
c1490a: movb RL2,#0x10
c1490e: orb 0xc60f,RL2
c14912: extp 0x380, #0x1
c14916: movbz r1,0x85c
c1491a: shl r1,#0x5
c1491c: orb 0xc60f,RL1
c14920: extp 0x380, #0x1
c14924: movbz r1,0x846
c14928: shl r1,#0x6
c1492a: orb 0xc60f,RL1
c1492e: movbz r1,0xc954
c14932: shl r1,#0x7
c14934: orb 0xc60f,RL1
c14938: movb RL1,0xc92b
c1493c: movb 0xc60d,RL1
c14940: movbz r2,0xc934
c14944: shl r2,#0x1
c14946: orb 0xc60d,RL2
c1494a: extp 0x380, #0x1
c1494e: movbz r1,0x81a
c14952: shl r1,#0x2
c14954: orb 0xc60d,RL1
c14958: movbz r1,0xc81c
c1495c: shl r1,#0x3
c1495e: orb 0xc60d,RL1
c14962: movbz r1,0xc77e
c14966: shl r1,#0x4
c14968: orb 0xc60d,RL1
c1496c: movb RL1,0xc604
c14970: jmpr cc_NE,0xc1497a
c14972: movb RL2,#0x20
c14976: orb 0xc60d,RL2
c1497a: movb RL1,0xc603
c1497e: jmpr cc_NE,0xc14988
c14980: movb RL2,#0x40
c14984: orb 0xc60d,RL2
c14988: extp 0x380, #0x1
c1498c: mov r12,0x83e
c14990: cmp r12,#0x1
c14992: jmpr cc_NE,0xc14998
c14994: movb RL1,#0x1
c14996: jmpr cc_UC,0xc1499a
c14998: movb RL1,#0x0
c1499a: movbs r1,RL1
c1499c: shl r1,#0x7
c1499e: orb 0xc60d,RL1
c149a2: movb RL1,0xc9f0
c149a6: movb 0xc60c,RL1
c149aa: movbz r2,0xc91c
c149ae: shl r2,#0x1
c149b0: orb 0xc60c,RL2
c149b4: movbz r1,0xc92e
c149b8: shl r1,#0x2
c149ba: orb 0xc60c,RL1
c149be: movbz r1,0xca44
c149c2: shl r1,#0x3
c149c4: orb 0xc60c,RL1
c149c8: movbz r1,0xc89e
c149cc: shl r1,#0x4
c149ce: orb 0xc60c,RL1
c149d2: movb RL1,0xc93c
c149d6: cmpb RL1,#0x3
c149d8: jmpr cc_NE,0xc149e2
c149da: movb RL2,#0x20
c149de: orb 0xc60c,RL2
c149e2: extp 0x380, #0x1
c149e6: movbz r1,0x894
c149ea: shl r1,#0x6
c149ec: orb 0xc60c,RL1
c149f0: movbz r1,0xcaf9
c149f4: shl r1,#0x7
c149f6: orb 0xc60c,RL1
c149fa: rets


; ============================== Diagnostics / test commands ==============================

; ----------------------------------------------------------------------------
; test_command_clear
; Address: 0xC13D50
; Area:    application/02-diagnostics/test-commands
; Size:    14 bytes
; --------------------------------------------------------------------------
c13d50: movb 0xfd18,0xff1c
c13d54: mov 0xc5e8,0xff1c
c13d58: mov 0xc5ea,0xff1c
c13d5c: rets


; ----------------------------------------------------------------------------
; test_command_dispatch
; Address: 0xC13D5E
; Area:    application/02-diagnostics/test-commands
; Size:    106 bytes
; --------------------------------------------------------------------------
c13d5e: movbz r12,0xfd18
c13d62: and r12,#0xff7f
c13d66: jmpr cc_NE,0xc13d72
c13d68: mov 0xc5e8,0xff1c
c13d6c: mov 0xc5ea,0xff1c
c13d70: rets
c13d72: mov r12,0xc5e8
c13d76: mov r13,0xc5ea
c13d7a: sub r12,#0x3e8
c13d7e: subc r13,#0x0
c13d80: jmpr cc_NC,0xc13dbe
c13d82: sub 0xc5e8,0xff1e
c13d86: subc 0xc5ea,0xff1e
c13d8a: mov r12,0xfd18
c13d8e: jnb r12.0x0,0xc13d98
c13d92: calls 0xc0fb36
c13d96: rets
c13d98: mov r12,0xfd18
c13d9c: jnb r12.0x1,0xc13da6
c13da0: calls 0xc0d6f0
c13da4: rets
c13da6: mov r12,0xfd18
c13daa: jnb r12.0x2,0xc13dc6
c13dae: calls 0xc10afc
c13db2: mov r12,#0xfa
c13db6: mov r13,#0x0
c13db8: calls 0xc10a74
c13dbc: rets
c13dbe: movb RL1,#0x80
c13dc2: andb 0xfd18,RL1
c13dc6: rets


; ============================== Calibration / accessors ==============================

; ----------------------------------------------------------------------------
; tbl16_interp
; Address: 0xC27CA4
; Area:    application/03-calibration/accessors
; Size:    168 bytes
; --------------------------------------------------------------------------
c27ca4: mov [-r0],r9
c27ca6: mov [-r0],r8
c27ca8: mov [-r0],r7
c27caa: mov [-r0],r6
c27cac: mov r15,r12
c27cae: mov r1,r13
c27cb0: add r12,#0x2
c27cb2: addc r13,#0x0
c27cb4: mov r15,r12
c27cb6: mov r1,r13
c27cb8: mov r15,r14
c27cba: and r15,#0xff
c27cbe: mov r1,#0x8
c27cc0: shr r14,r1
c27cc2: mov r2,#0x0
c27cc4: add r14,r14
c27cc6: addc r2,r2
c27cc8: add r12,r14
c27cca: addc r13,r2
c27ccc: exts r13, #0x1
c27cce: mov r14,[r12]
c27cd0: mov r6,r14
c27cd2: mov r7,#0x0
c27cd4: cmp r15,#0x0
c27cd6: jmpr cc_EQ,0xc27d40
c27cd8: add r12,#0x2
c27cda: addc r13,#0x0
c27cdc: exts r13, #0x1
c27cde: mov r12,[r12]
c27ce0: mov r8,r12
c27ce2: mov r9,#0x0
c27ce4: sub r8,r6
c27ce6: subc r9,r7
c27ce8: mov r14,r1
c27cea: mov r2,r8
c27cec: mov r3,r9
c27cee: jmpr cc_NN,0xc27cfc
c27cf0: mov r1,r8
c27cf2: mov r2,r9
c27cf4: neg r1
c27cf6: addc r2,#0x0
c27cf8: neg r2
c27cfa: jmpr cc_UC,0xc27d00
c27cfc: mov r1,r8
c27cfe: mov r2,r9
c27d00: mov r12,r1
c27d02: mov r13,r2
c27d04: mov r1,r14
c27d06: mov r4,r12
c27d08: mov r5,r13
c27d0a: mov r10,r15
c27d0c: mov r11,#0x0
c27d0e: calls 0xc28b64
c27d12: mov r12,r4
c27d14: mov r13,r5
c27d16: jmpr cc_UC,0xc27d20
c27d18: shr r12,#0x1
c27d1a: bmov r12.0xf,r13.0x0
c27d1e: shr r13,#0x1
c27d20: cmpd1 r1,#0x0
c27d22: jmpr cc_NE,0xc27d18
c27d24: cmp r9,#0x0
c27d26: jmpr cc_NN,0xc27d34
c27d28: mov r14,r12
c27d2a: mov r15,r13
c27d2c: neg r14
c27d2e: addc r15,#0x0
c27d30: neg r15
c27d32: jmpr cc_UC,0xc27d38
c27d34: mov r14,r12
c27d36: mov r15,r13
c27d38: mov r8,r14
c27d3a: mov r9,r15
c27d3c: add r6,r8
c27d3e: addc r7,r9
c27d40: mov r4,r6
c27d42: mov r6,[r0+]
c27d44: mov r7,[r0+]
c27d46: mov r8,[r0+]
c27d48: mov r9,[r0+]
c27d4a: rets


; ----------------------------------------------------------------------------
; tbl8_interp
; Address: 0xC27FCA
; Area:    application/03-calibration/accessors
; Size:    182 bytes
; --------------------------------------------------------------------------
c27fca: mov [-r0],r9
c27fcc: mov [-r0],r8
c27fce: mov r15,r12
c27fd0: mov r1,r13
c27fd2: mov r1,r12
c27fd4: mov r2,r13
c27fd6: add r1,#0x2
c27fd8: addc r2,#0x0
c27fda: add r12,#0x1
c27fdc: addc r13,#0x0
c27fde: exts r13, #0x1
c27fe0: movb RL4,[r12]
c27fe2: movbz r12,RL4
c27fe4: mov r3,#0x8
c27fe6: sub r3,r12
c27fe8: mov r10,r14
c27fea: and r10,#0xff
c27fee: mov r15,#0x8
c27ff0: shr r14,r15
c27ff2: mov r12,#0x0
c27ff4: add r1,r14
c27ff6: addc r2,r12
c27ff8: exts r2, #0x1
c27ffa: movb RL4,[r1]
c27ffc: movbz r12,RL4
c27ffe: mov r13,#0x0
c28000: mov r8,r12
c28002: mov r9,r13
c28004: mov r14,r3
c28006: jmpr cc_UC,0xc2800c
c28008: add r8,r8
c2800a: addc r9,r9
c2800c: cmpd1 r14,#0x0
c2800e: jmpr cc_NE,0xc28008
c28010: cmp r10,#0x0
c28012: jmpr cc_EQ,0xc28078
c28014: sub r15,r3
c28016: add r1,#0x1
c28018: addc r2,#0x0
c2801a: exts r2, #0x1
c2801c: movb RL1,[r1]
c2801e: mov r14,r12
c28020: mov r2,r13
c28022: movbz r12,RL1
c28024: sub r12,r14
c28026: subc r13,r2
c28028: mov r4,r12
c2802a: mov r5,r13
c2802c: mov r11,#0x0
c2802e: calls 0xc28b64
c28032: mov r12,r4
c28034: mov r13,r5
c28036: mov r14,r12
c28038: mov r1,r13
c2803a: jmpr cc_NN,0xc2805e
c2803c: mov r14,r12
c2803e: mov r1,r13
c28040: neg r14
c28042: addc r1,#0x0
c28044: neg r1
c28046: mov r2,r15
c28048: jmpr cc_UC,0xc28052
c2804a: shr r14,#0x1
c2804c: bmov r14.0xf,r1.0x0
c28050: ashr r1,#0x1
c28052: cmpd1 r2,#0x0
c28054: jmpr cc_NE,0xc2804a
c28056: neg r14
c28058: addc r1,#0x0
c2805a: neg r1
c2805c: jmpr cc_UC,0xc28070
c2805e: mov r14,r12
c28060: mov r1,r13
c28062: jmpr cc_UC,0xc2806c
c28064: shr r14,#0x1
c28066: bmov r14.0xf,r1.0x0
c2806a: ashr r1,#0x1
c2806c: cmpd1 r15,#0x0
c2806e: jmpr cc_NE,0xc28064
c28070: mov r12,r14
c28072: mov r13,r1
c28074: add r8,r12
c28076: addc r9,r13
c28078: mov r4,r8
c2807a: mov r8,[r0+]
c2807c: mov r9,[r0+]
c2807e: rets


; ----------------------------------------------------------------------------
; tbl2d_interp
; Address: 0xC2826E
; Area:    application/03-calibration/accessors
; Size:    482 bytes
; --------------------------------------------------------------------------
c2826e: mov [-r0],r9
c28270: mov [-r0],r8
c28272: mov [-r0],r7
c28274: mov [-r0],r6
c28276: sub r0,#0x2
c28278: mov r1,r12
c2827a: mov r2,r13
c2827c: add r12,#0x3
c2827e: addc r13,#0x0
c28280: mov r3,r1
c28282: mov r4,r2
c28284: add r3,#0x2
c28286: addc r4,#0x0
c28288: exts r4, #0x1
c2828a: movb RL3,[r3]
c2828c: movbz r3,RL3
c2828e: mov r6,#0x8
c28290: sub r6,r3
c28292: exts r2, #0x1
c28294: movb RL1,[r1]
c28296: movbz r7,RL1
c28298: mov r1,#0x8
c2829a: mov [r0],r1
c2829c: mov r3,r14
c2829e: and r3,#0xff
c282a2: mov r2,[r0]
c282a4: mov r4,r15
c282a6: shr r4,r2
c282a8: mulu r4,r7
c282aa: shr r14,r1
c282ac: mov r4,0xfe0e
c282b0: add r4,r14
c282b2: mov r14,#0x0
c282b4: add r12,r4
c282b6: addc r13,r14
c282b8: exts r13, #0x1
c282ba: movb RL4,[r12]
c282bc: movbz r8,RL4
c282be: mov r9,#0x0
c282c0: mov r14,r8
c282c2: mov r2,r9
c282c4: mov r4,r6
c282c6: jmpr cc_UC,0xc282cc
c282c8: add r14,r14
c282ca: addc r2,r2
c282cc: cmpd1 r4,#0x0
c282ce: jmpr cc_NE,0xc282c8
c282d0: cmp r3,#0x0
c282d2: jmpr cc_EQ,0xc28350
c282d4: sub r1,r6
c282d6: mov r4,r12
c282d8: mov r5,r13
c282da: add r4,#0x1
c282dc: addc r5,#0x0
c282de: exts r5, #0x1
c282e0: movb RL4,[r4]
c282e2: mov r5,r8
c282e4: mov r10,r9
c282e6: movbz r8,RL4
c282e8: sub r8,r5
c282ea: subc r9,r10
c282ec: mov r4,r8
c282ee: mov r5,r9
c282f0: mov r10,r3
c282f2: mov r11,#0x0
c282f4: calls 0xc28b64
c282f8: mov r8,r4
c282fa: mov r9,r5
c282fc: mov [-r0],r2
c282fe: mov [-r0],r1
c28300: mov [-r0],r3
c28302: mov r4,r8
c28304: mov r5,r9
c28306: jmpr cc_NN,0xc2832c
c28308: mov r1,r8
c2830a: mov r2,r9
c2830c: neg r1
c2830e: addc r2,#0x0
c28310: neg r2
c28312: mov r3,[r0+#0x2]
c28316: jmpr cc_UC,0xc28320
c28318: shr r1,#0x1
c2831a: bmov r1.0xf,r2.0x0
c2831e: ashr r2,#0x1
c28320: cmpd1 r3,#0x0
c28322: jmpr cc_NE,0xc28318
c28324: neg r1
c28326: addc r2,#0x0
c28328: neg r2
c2832a: jmpr cc_UC,0xc28342
c2832c: mov r1,r8
c2832e: mov r2,r9
c28330: mov r3,[r0+#0x2]
c28334: jmpr cc_UC,0xc2833e
c28336: shr r1,#0x1
c28338: bmov r1.0xf,r2.0x0
c2833c: ashr r2,#0x1
c2833e: cmpd1 r3,#0x0
c28340: jmpr cc_NE,0xc28336
c28342: mov r8,r1
c28344: mov r9,r2
c28346: mov r3,[r0+]
c28348: mov r1,[r0+]
c2834a: mov r2,[r0+]
c2834c: add r14,r8
c2834e: addc r2,r9
c28350: and r15,#0xff
c28354: mov r8,r15
c28356: cmp r15,#0x0
c28358: jmpr cc_EQ,0xc28442
c2835a: mov r8,#0x0
c2835c: add r12,r7
c2835e: addc r13,r8
c28360: exts r13, #0x1
c28362: movb RL7,[r12]
c28364: movbz r8,RL7
c28366: mov r9,#0x0
c28368: mov r4,r6
c2836a: mov r6,r8
c2836c: mov r7,r9
c2836e: jmpr cc_UC,0xc28374
c28370: add r6,r6
c28372: addc r7,r7
c28374: cmpd1 r4,#0x0
c28376: jmpr cc_NE,0xc28370
c28378: cmp r3,#0x0
c2837a: jmpr cc_EQ,0xc283e6
c2837c: add r12,#0x1
c2837e: addc r13,#0x0
c28380: exts r13, #0x1
c28382: movb RL4,[r12]
c28384: mov r12,r8
c28386: mov r13,r9
c28388: movbz r8,RL4
c2838a: sub r8,r12
c2838c: subc r9,r13
c2838e: mov r4,r8
c28390: mov r5,r9
c28392: mov r10,r3
c28394: mov r11,#0x0
c28396: calls 0xc28b64
c2839a: mov r8,r4
c2839c: mov r9,r5
c2839e: mov r12,r1
c283a0: mov r13,r2
c283a2: mov r1,r8
c283a4: mov r2,r9
c283a6: jmpr cc_NN,0xc283ca
c283a8: mov r1,r8
c283aa: mov r2,r9
c283ac: neg r1
c283ae: addc r2,#0x0
c283b0: neg r2
c283b2: mov r3,r12
c283b4: jmpr cc_UC,0xc283be
c283b6: shr r1,#0x1
c283b8: bmov r1.0xf,r2.0x0
c283bc: ashr r2,#0x1
c283be: cmpd1 r3,#0x0
c283c0: jmpr cc_NE,0xc283b6
c283c2: neg r1
c283c4: addc r2,#0x0
c283c6: neg r2
c283c8: jmpr cc_UC,0xc283dc
c283ca: mov r1,r8
c283cc: mov r2,r9
c283ce: jmpr cc_UC,0xc283d8
c283d0: shr r1,#0x1
c283d2: bmov r1.0xf,r2.0x0
c283d6: ashr r2,#0x1
c283d8: cmpd1 r12,#0x0
c283da: jmpr cc_NE,0xc283d0
c283dc: mov r8,r1
c283de: mov r9,r2
c283e0: mov r2,r13
c283e2: add r6,r8
c283e4: addc r7,r9
c283e6: sub r6,r14
c283e8: subc r7,r2
c283ea: mov r4,r6
c283ec: mov r5,r7
c283ee: mov r10,r15
c283f0: mov r11,#0x0
c283f2: calls 0xc28b64
c283f6: mov r6,r4
c283f8: mov r7,r5
c283fa: mov r8,r2
c283fc: mov r9,r6
c283fe: mov r12,r7
c28400: jmpr cc_NN,0xc28424
c28402: mov r9,r6
c28404: mov r12,r7
c28406: neg r9
c28408: addc r12,#0x0
c2840a: neg r12
c2840c: mov r13,[r0]
c2840e: jmpr cc_UC,0xc28418
c28410: shr r9,#0x1
c28412: bmov r9.0xf,r12.0x0
c28416: ashr r12,#0x1
c28418: cmpd1 r13,#0x0
c2841a: jmpr cc_NE,0xc28410
c2841c: neg r9
c2841e: addc r12,#0x0
c28420: neg r12
c28422: jmpr cc_UC,0xc28438
c28424: mov r9,r6
c28426: mov r12,r7
c28428: mov r13,[r0]
c2842a: jmpr cc_UC,0xc28434
c2842c: shr r9,#0x1
c2842e: bmov r9.0xf,r12.0x0
c28432: ashr r12,#0x1
c28434: cmpd1 r13,#0x0
c28436: jmpr cc_NE,0xc2842c
c28438: mov r6,r9
c2843a: mov r7,r12
c2843c: mov r2,r8
c2843e: add r14,r6
c28440: addc r2,r7
c28442: add r0,#0x2
c28444: mov r4,r14
c28446: mov r6,[r0+]
c28448: mov r7,[r0+]
c2844a: mov r8,[r0+]
c2844c: mov r9,[r0+]
c2844e: rets


; ----------------------------------------------------------------------------
; axis16_signed
; Address: 0xC284D8
; Area:    application/03-calibration/accessors
; Size:    54 bytes
; --------------------------------------------------------------------------
c284d8: mov r14,[r12+#0x2]
c284dc: mov r15,[r12+#0x4]
c284e0: mov r1,[r12]
c284e2: sub r1,#0x1
c284e4: shl r1,#0x8
c284e6: mov r12,r1
c284e8: cmp r13,r14
c284ea: jmpr cc_SGT,0xc284f0
c284ec: mov r4,#0x0
c284ee: jmpr cc_UC,0xc2850c
c284f0: cmp r13,r15
c284f2: jmpr cc_SLT,0xc284f8
c284f4: mov r4,r12
c284f6: jmpr cc_UC,0xc2850c
c284f8: sub r13,r14
c284fa: mulu r13,r12
c284fc: sub r15,r14
c284fe: mov r1,0xfe0c
c28502: mov r13,0xfe0e
c28506: divlu r15
c28508: mov r4,0xfe0e
c2850c: rets


; ----------------------------------------------------------------------------
; axis16_unsigned
; Address: 0xC2850E
; Area:    application/03-calibration/accessors
; Size:    54 bytes
; --------------------------------------------------------------------------
c2850e: mov r14,[r12+#0x2]
c28512: mov r15,[r12+#0x4]
c28516: mov r1,[r12]
c28518: sub r1,#0x1
c2851a: shl r1,#0x8
c2851c: mov r12,r1
c2851e: cmp r13,r14
c28520: jmpr cc_UGT,0xc28526
c28522: mov r4,#0x0
c28524: jmpr cc_UC,0xc28542
c28526: cmp r13,r15
c28528: jmpr cc_C,0xc2852e
c2852a: mov r4,r12
c2852c: jmpr cc_UC,0xc28542
c2852e: sub r13,r14
c28530: mulu r13,r12
c28532: sub r15,r14
c28534: mov r1,0xfe0c
c28538: mov r13,0xfe0e
c2853c: divlu r15
c2853e: mov r4,0xfe0e
c28542: rets


; ============================== Calibration / checksum ==============================

; ----------------------------------------------------------------------------
; cal_checksum
; Address: 0xC11B9A
; Area:    application/03-calibration/checksum
; Size:    90 bytes
; --------------------------------------------------------------------------
c11b9a: mov r12,#0x5000
c11b9e: mov r13,#0xc0
c11ba2: mov 0xc546,0xff1c
c11ba6: mov 0xc548,0xff1c
c11baa: jmpr cc_UC,0xc11bcc
c11bac: exts r13, #0x1
c11bae: mov r14,[r12]
c11bb0: and r14,#0xff
c11bb4: shl r14,#0x8
c11bb6: add 0xc546,r14
c11bba: exts r13, #0x1
c11bbc: mov r14,[r12]
c11bbe: and r14,#0xff00
c11bc2: shr r14,#0x8
c11bc4: add 0xc546,r14
c11bc8: add r12,#0x2
c11bca: addc r13,#0x0
c11bcc: mov r14,r12
c11bce: mov r15,r13
c11bd0: mov r1,#0xaffd
c11bd4: mov r2,#0xc0
c11bd8: sub r14,r1
c11bda: subc r15,r2
c11bdc: jmpr cc_C,0xc11bac
c11bde: extp 0x302, #0x1
c11be2: mov r12,0x2ffe
c11be6: cmp r12,0xc546
c11bea: jmpr cc_NE,0xc11bf2
c11bec: mov r13,#0x1
c11bee: mov 0xc548,r13
c11bf2: rets


; ============================== Engine control / events ==============================

; ----------------------------------------------------------------------------
; capcom_event_config2
; Address: 0xC0BBC4
; Area:    application/04-engine-control/events
; Size:    50 bytes
; --------------------------------------------------------------------------
c0bbc4: mov r1,r12
c0bbc6: bclr 0xff10.0xb
c0bbc8: movbz r12,RL1
c0bbca: mov r2,r12
c0bbcc: shl r12,#0x3
c0bbce: add r12,r2
c0bbd0: shl r12,#0x1
c0bbd2: mov r1,r1
c0bbd4: mov [r12+#0xc412],r13
c0bbd8: mov [r12+#0xc414],r14
c0bbdc: mov [r12+#0xc410],r15
c0bbe0: mov 0xc40c,[r0]
c0bbe4: mov r12,[r0+#0x2]
c0bbe8: mov 0xc400,r12
c0bbec: movbz r12,RL1
c0bbee: calls 0xc0dc8a
c0bbf2: bset 0xff10.0xb
c0bbf4: rets


; ----------------------------------------------------------------------------
; capcom_event_config
; Address: 0xC0BCA4
; Area:    application/04-engine-control/events
; Size:    176 bytes
; --------------------------------------------------------------------------
c0bca4: mov r1,r12
c0bca6: mov r2,r13
c0bca8: bclr 0xff10.0xb
c0bcaa: cmp r14,#0x0
c0bcac: jmpr cc_EQ,0xc0bcb4
c0bcae: movb RL3,#0x1
c0bcb0: movb 0xc40e,RL3
c0bcb4: movbz r3,RL2
c0bcb6: movbz r12,RL1
c0bcb8: mov r14,r12
c0bcba: shl r14,#0x3
c0bcbc: add r14,r12
c0bcbe: shl r14,#0x1
c0bcc0: mov r13,#0xc394
c0bcc4: movbz r15,RL1
c0bcc6: shl r15,#0x3
c0bcc8: add r13,r15
c0bcca: and r3,#0x3
c0bccc: movb [r14+#0xc41d],RL2
c0bcd0: mov r3,[r13]
c0bcd2: mov r13,[r13]
c0bcd4: mov r4,#0xff22
c0bcd8: mov r12,[r3]
c0bcda: mov [r13],r12
c0bcdc: mov r12,[r15+#0xc392]
c0bce0: mov [r14+#0xc41e],r12
c0bce4: mov r12,#0xfe28
c0bce8: mov 0xc3fe,r12
c0bcec: mov r13,#0xfe2a
c0bcf0: mov 0xc404,r13
c0bcf4: mov r3,#0xff2c
c0bcf8: mov 0xc40a,r3
c0bcfc: mov 0xc402,r4
c0bd00: mov r13,#0xc396
c0bd04: add r13,r15
c0bd06: mov r5,#0xf050
c0bd0a: mov 0xc3fc,r5
c0bd0e: mov r15,[r13]
c0bd10: mov [r14+#0xc420],r15
c0bd14: mov r14,[r13]
c0bd16: movbz r2,RL2
c0bd18: and r2,#0xf
c0bd1c: mov r12,[r14]
c0bd1e: or r12,#0x30
c0bd22: movbz r14,RL1
c0bd24: or r12,r14
c0bd26: mov r14,[r13]
c0bd28: mov [r14],r12
c0bd2a: mov r12,0xc3fe
c0bd2e: mov r15,#0x1
c0bd30: shl r15,r2
c0bd32: mov r14,[r12]
c0bd34: or r14,r15
c0bd36: mov [r12],r14
c0bd38: mov [-r0],r1
c0bd3a: mov [-r0],r13
c0bd3c: movbz r12,RL1
c0bd3e: calls 0xc0dc62
c0bd42: mov r13,[r0+]
c0bd44: add r0,#0x2
c0bd46: mov r14,[r13]
c0bd48: mov r13,[r13]
c0bd4a: mov r12,[r14]
c0bd4c: bset r12.0x6
c0bd4e: mov [r13],r12
c0bd50: bset 0xff10.0xb
c0bd52: rets


; ----------------------------------------------------------------------------
; capcom16_17_init
; Address: 0xC0BD58
; Area:    application/04-engine-control/events
; Size:    70 bytes
; --------------------------------------------------------------------------
c0bd58: bset 0xff18.0x0
c0bd5a: bset 0xff18.0x1
c0bd5c: movb RL1,#0x10
c0bd60: movb 0xc390,RL1
c0bd64: mov r12,#0xfe60
c0bd68: mov 0xc392,r12
c0bd6c: mov r13,#0xff22
c0bd70: mov 0xc394,r13
c0bd74: mov r14,#0xf160
c0bd78: mov 0xc396,r14
c0bd7c: movb RL2,#0x11
c0bd80: movb 0xc398,RL2
c0bd84: mov r15,#0xfe62
c0bd88: mov 0xc39a,r15
c0bd8c: mov r3,#0xff22
c0bd90: mov 0xc39c,r3
c0bd94: mov r4,#0xf162
c0bd98: mov 0xc39e,r4
c0bd9c: rets


; ----------------------------------------------------------------------------
; cc_control_ptr_init
; Address: 0xC0BEF0
; Area:    application/04-engine-control/events
; Size:    18 bytes
; --------------------------------------------------------------------------
c0bef0: mov r12,#0xff2c
c0bef4: mov 0xc3c4,r12
c0bef8: mov r13,#0xfe2a
c0befc: mov 0xc3c2,r13
c0bf00: rets


; ----------------------------------------------------------------------------
; cc_irq_enable
; Address: 0xC0BF54
; Area:    application/04-engine-control/events
; Size:    56 bytes
; --------------------------------------------------------------------------
c0bf54: cmp r13,#0x0
c0bf56: jmpr cc_EQ,0xc0bf74
c0bf58: mov r14,0xc3c4
c0bf5c: shr r12,#0x1
c0bf5e: and r12,#0xf
c0bf62: mov r13,#0x1
c0bf64: shl r13,r12
c0bf66: mov r12,r13
c0bf68: cpl r12
c0bf6a: mov r15,[r14]
c0bf6c: and r15,r12
c0bf6e: or r15,r13
c0bf70: mov [r14],r15
c0bf72: rets
c0bf74: mov r13,0xc3c4
c0bf78: shr r12,#0x1
c0bf7a: and r12,#0xf
c0bf7e: mov r15,#0x1
c0bf80: shl r15,r12
c0bf82: cpl r15
c0bf84: mov r14,[r13]
c0bf86: and r14,r15
c0bf88: mov [r13],r14
c0bf8a: rets


; ----------------------------------------------------------------------------
; cc_irq_is_enabled
; Address: 0xC0BF8C
; Area:    application/04-engine-control/events
; Size:    36 bytes
; --------------------------------------------------------------------------
c0bf8c: mov r14,0xc3c4
c0bf90: shr r12,#0x1
c0bf92: and r12,#0xf
c0bf96: mov r13,#0x1
c0bf98: shl r13,r12
c0bf9a: mov r15,[r14]
c0bf9c: and r15,r13
c0bf9e: mov r12,r15
c0bfa0: jmpr cc_EQ,0xc0bfaa
c0bfa2: cmp r13,#0x0
c0bfa4: jmpr cc_EQ,0xc0bfaa
c0bfa6: mov r12,#0x1
c0bfa8: jmpr cc_UC,0xc0bfac
c0bfaa: mov r12,#0x0
c0bfac: mov r4,r12
c0bfae: rets


; ----------------------------------------------------------------------------
; event_start
; Address: 0xC0D39E
; Area:    application/04-engine-control/events
; Size:    88 bytes
; --------------------------------------------------------------------------
c0d39e: mov [-r0],r8
c0d3a0: mov [-r0],r6
c0d3a2: calls 0xc106e6
c0d3a6: mov r8,r4
c0d3a8: add r8,#0x4
c0d3aa: movb RL6,#0x0
c0d3ac: mov r12,0xc374
c0d3b0: mov [-r0],r12
c0d3b2: mov r13,0xc37e
c0d3b6: movbz r14,RL6
c0d3b8: shl r14,#0x2
c0d3ba: mov r15,r14
c0d3bc: mov [-r0],r13
c0d3be: movbz r12,RL6
c0d3c0: mov r13,[r15+#0xc384]
c0d3c4: mov r14,[r15+#0xc386]
c0d3c8: mov r15,r8
c0d3ca: calls 0xc0bbc4
c0d3ce: add r0,#0x4
c0d3d0: movbz r14,RL6
c0d3d2: mov r15,r14
c0d3d4: shl r15,#0x3
c0d3d6: add r15,r14
c0d3d8: shl r15,#0x1
c0d3da: mov r12,#0x0
c0d3dc: mov r13,#0x0
c0d3de: mov [r15+#0xc416],r12
c0d3e2: mov [r15+#0xc418],r13
c0d3e6: addb RL6,#0x1
c0d3e8: cmpb RL6,#0x2
c0d3ea: jmpr cc_C,0xc0d3ac
c0d3ec: mov 0xc36e,0xff1c
c0d3f0: mov r6,[r0+]
c0d3f2: mov r8,[r0+]
c0d3f4: rets


; ----------------------------------------------------------------------------
; event_reset
; Address: 0xC0D516
; Area:    application/04-engine-control/events
; Size:    18 bytes
; --------------------------------------------------------------------------
c0d516: mov 0xc378,0xff1c
c0d51a: mov 0xc37e,0xff1c
c0d51e: mov 0xc374,0xff1c
c0d522: movb 0xc370,0xff1c
c0d526: rets


; ----------------------------------------------------------------------------
; event_init
; Address: 0xC0D528
; Area:    application/04-engine-control/events
; Size:    58 bytes
; --------------------------------------------------------------------------
c0d528: mov [-r0],r6
c0d52a: bclr 0xff10.0xb
c0d52c: calls 0xc0bd58
c0d530: movb RL6,#0x0
c0d532: movbz r13,RL6
c0d534: shl r13,#0x3
c0d536: mov r14,#0x1
c0d538: movbz r12,RL6
c0d53a: movb RL1,[r13+#0xc390]
c0d53e: movbz r13,RL1
c0d540: calls 0xc0bca4
c0d544: addb RL6,#0x1
c0d546: cmpb RL6,#0x2
c0d548: jmpr cc_C,0xc0d532
c0d54a: movb 0xc370,0xff1c
c0d54e: mov r6,0xc372
c0d552: jmpr cc_NE,0xc0d558
c0d554: calls 0xc0d39e
c0d558: calls 0xc0d516
c0d55c: bset 0xff10.0xb
c0d55e: mov r6,[r0+]
c0d560: rets


; ----------------------------------------------------------------------------
; event_start_fixed
; Address: 0xC0D6F0
; Area:    application/04-engine-control/events
; Size:    26 bytes
; --------------------------------------------------------------------------
c0d6f0: mov r12,#0x1194
c0d6f4: mov 0xc384,r12
c0d6f8: mov 0xc386,0xff1c
c0d6fc: mov 0xc388,r12
c0d700: mov 0xc38a,0xff1c
c0d704: calls 0xc0d39e
c0d708: rets


; ----------------------------------------------------------------------------
; cc_irq_enable_bit
; Address: 0xC0DB90
; Area:    application/04-engine-control/events
; Size:    22 bytes
; --------------------------------------------------------------------------
c0db90: mov r1,r12
c0db92: cmpb RL1,#0x10
c0db96: jmpa cc_NE,0xc0dba0
c0db9a: or 0xfe2a,#0x1
c0db9e: rets
c0dba0: or 0xfe2a,#0x2
c0dba4: rets


; ----------------------------------------------------------------------------
; cc_compare_mode_set
; Address: 0xC0DBA6
; Area:    application/04-engine-control/events
; Size:    56 bytes
; --------------------------------------------------------------------------
c0dba6: mov r2,r12
c0dba8: movbz r12,RL2
c0dbaa: mov r13,r12
c0dbac: shl r13,#0x3
c0dbae: add r13,r12
c0dbb0: shl r13,#0x1
c0dbb2: movb RL1,[r13+#0xc41d]
c0dbb6: movb RL2,0xc40e
c0dbba: jmpa cc_EQ,0xc0dbce
c0dbbe: cmpb RL1,#0x10
c0dbc2: jmpa cc_NE,0xc0dbca
c0dbc6: bclr 0xff2c.0x0
c0dbc8: rets
c0dbca: bclr 0xff2c.0x1
c0dbcc: rets
c0dbce: cmpb RL1,#0x10
c0dbd2: jmpa cc_NE,0xc0dbda
c0dbd6: bset 0xff2c.0x0
c0dbd8: rets
c0dbda: bset 0xff2c.0x1
c0dbdc: rets


; ----------------------------------------------------------------------------
; event_force
; Address: 0xC0DBDE
; Area:    application/04-engine-control/events
; Size:    132 bytes
; --------------------------------------------------------------------------
c0dbde: mov [-r0],r6
c0dbe0: mov r1,r12
c0dbe2: movbz r12,RL1
c0dbe4: mov r13,r12
c0dbe6: shl r13,#0x3
c0dbe8: add r13,r12
c0dbea: shl r13,#0x1
c0dbec: mov r12,0xc40a
c0dbf0: sub r0,#0x2
c0dbf2: movb RL6,[r13+#0xc41d]
c0dbf6: movbz r1,RL6
c0dbf8: and r1,#0xf
c0dbfc: mov r14,[r12]
c0dbfe: movb [r0],RL1
c0dc00: movbz r15,RL1
c0dc02: mov r2,#0x1
c0dc04: shl r2,r15
c0dc06: and r14,r2
c0dc08: cmp r14,#0x0
c0dc0a: jmpr cc_ULE,0xc0dc10
c0dc0c: mov r12,#0x1
c0dc0e: jmpr cc_UC,0xc0dc12
c0dc10: mov r12,#0x0
c0dc12: movb RL1,0xc40e
c0dc16: jmpr cc_NE,0xc0dc1c
c0dc18: mov r14,#0x1
c0dc1a: jmpr cc_UC,0xc0dc1e
c0dc1c: mov r14,#0x0
c0dc1e: cmp r12,r14
c0dc20: jmpr cc_NE,0xc0dc32
c0dc22: mov r12,0xc3fc
c0dc26: mov r15,[r13+#0xc41e]
c0dc2a: mov r14,[r12]
c0dc2c: add r14,#0xa
c0dc30: mov [r15],r14
c0dc32: mov r13,0xc402
c0dc36: movb RL1,[r0]
c0dc38: movbz r12,RL1
c0dc3a: shl r12,#0x2
c0dc3c: mov r15,#0xf
c0dc3e: shl r15,r12
c0dc40: cpl r15
c0dc42: mov r14,[r13]
c0dc44: and r14,r15
c0dc46: mov [r13],r14
c0dc48: mov r13,0xc402
c0dc4c: mov r15,#0x5
c0dc4e: shl r15,r12
c0dc50: mov r14,[r13]
c0dc52: or r14,r15
c0dc54: mov [r13],r14
c0dc56: movbz r12,RL6
c0dc58: calls 0xc0db90
c0dc5c: add r0,#0x2
c0dc5e: mov r6,[r0+]
c0dc60: rets


; ----------------------------------------------------------------------------
; event_cancel
; Address: 0xC0DC62
; Area:    application/04-engine-control/events
; Size:    40 bytes
; --------------------------------------------------------------------------
c0dc62: mov r1,r12
c0dc64: movbz r12,RL1
c0dc66: mov r15,r12
c0dc68: shl r12,#0x3
c0dc6a: add r12,r15
c0dc6c: shl r12,#0x1
c0dc6e: mov r13,#0x0
c0dc70: mov r14,#0x0
c0dc72: mov [r12+#0xc416],r13
c0dc76: mov [r12+#0xc418],r14
c0dc7a: movb RL2,#0x0
c0dc7c: movb [r12+#0xc41c],RL2
c0dc80: mov r1,r1
c0dc82: movbz r12,RL1
c0dc84: calls 0xc0e1b6
c0dc88: rets


; ----------------------------------------------------------------------------
; event_schedule
; Address: 0xC0DC8A
; Area:    application/04-engine-control/events
; Size:    428 bytes
; --------------------------------------------------------------------------
c0dc8a: mov [-r0],r9
c0dc8c: mov [-r0],r8
c0dc8e: mov [-r0],r7
c0dc90: mov [-r0],r6
c0dc92: mov r6,r12
c0dc94: movbz r12,RL6
c0dc96: mov r9,r12
c0dc98: shl r9,#0x3
c0dc9a: add r9,r12
c0dc9c: shl r9,#0x1
c0dc9e: mov r8,#0xc41c
c0dca2: add r8,r9
c0dca4: mov r7,#0xc41e
c0dca8: add r7,r9
c0dcaa: movb RL2,[r8]
c0dcac: andb RL2,#0xe3
c0dcb0: movb RL1,[r9+#0xc41d]
c0dcb4: movb [r8],RL2
c0dcb6: mov r12,[r7]
c0dcb8: mov r14,0xc3fc
c0dcbc: mov r13,[r12]
c0dcbe: mov r12,[r14]
c0dcc0: mov [-r0],r1
c0dcc2: mov [-r0],r13
c0dcc4: mov [-r0],r12
c0dcc6: movbz r12,RL6
c0dcc8: calls 0xc0dba6
c0dccc: mov r12,[r0+]
c0dcce: mov r13,[r0+]
c0dcd0: mov r1,[r0+]
c0dcd2: movb RL2,[r8]
c0dcd4: jnb r2.0x0,0xc0dcea
c0dcd8: movb RL2,[r8]
c0dcda: jb r2.0x2,0xc0dcee
c0dcde: mov r14,[r9+#0xc420]
c0dce2: mov r14,[r14]
c0dce4: jb r14.0x7,0xc0dcee
c0dce8: mov r13,r12
c0dcea: mov r14,[r7]
c0dcec: mov [r14],r12
c0dcee: mov r12,[r9+#0xc420]
c0dcf2: mov r14,[r12]
c0dcf4: bclr r14.0x7
c0dcf6: mov [r12],r14
c0dcf8: movb RL2,[r8]
c0dcfa: bset r2.0x5
c0dcfc: movb [r8],RL2
c0dcfe: movb RL2,[r8]
c0dd00: jnb r2.0x0,0xc0ddbe
c0dd04: mov [-r0],r1
c0dd06: movbz r12,RL6
c0dd08: calls 0xc0e236
c0dd0c: mov r1,[r0+]
c0dd0e: movb RL2,[r8]
c0dd10: mov r12,#0xc412
c0dd14: add r12,r9
c0dd16: bclr r2.0x0
c0dd18: movb [r8],RL2
c0dd1a: mov r13,[r12]
c0dd1c: mov r14,[r12+#0x2]
c0dd20: or r13,r14
c0dd22: jmpr cc_EQ,0xc0ddb6
c0dd24: mov [-r0],r1
c0dd26: mov [-r0],r12
c0dd28: calls 0xc106e6
c0dd2c: mov r15,[r9+#0xc410]
c0dd30: mov r12,[r0+]
c0dd32: mov r1,[r0+]
c0dd34: sub r15,r4
c0dd36: mov r13,[r12+]
c0dd38: mov r14,[r12]
c0dd3a: mov r9,0xc408
c0dd3e: mov r12,#0x0
c0dd40: add r13,r9
c0dd42: addc r14,r12
c0dd44: mov r2,0xc406
c0dd48: mov r3,#0x0
c0dd4a: add r13,r2
c0dd4c: addc r14,r3
c0dd4e: and r14,#0xff
c0dd52: mov r4,r14
c0dd54: shr r13,#0x8
c0dd56: shr r14,#0x8
c0dd58: shl r4,#0x8
c0dd5a: or r13,r4
c0dd5c: mov r12,r13
c0dd5e: cmp r12,r15
c0dd60: jmpr cc_NC,0xc0dda8
c0dd62: mov r6,0xc3fc
c0dd66: mov r7,[r7]
c0dd68: mov r12,[r6]
c0dd6a: add r12,0xc406
c0dd6e: mov [r7],r12
c0dd70: mov r9,0xc402
c0dd74: movbz r7,RL1
c0dd76: and r7,#0xf
c0dd7a: mov r12,r7
c0dd7c: shl r12,#0x2
c0dd7e: mov r7,#0xf
c0dd80: shl r7,r12
c0dd82: cpl r7
c0dd84: mov r6,[r9]
c0dd86: and r6,r7
c0dd88: mov [r9],r6
c0dd8a: mov r9,0xc402
c0dd8e: mov r7,#0x4
c0dd90: shl r7,r12
c0dd92: mov r6,[r9]
c0dd94: or r6,r7
c0dd96: mov [r9],r6
c0dd98: mov r9,r1
c0dd9a: movbz r12,RL1
c0dd9c: calls 0xc0db90
c0dda0: movb RL6,[r8]
c0dda2: bset r6.0x1
c0dda4: movb [r8],RL6
c0dda6: jmpr cc_UC,0xc0de2c
c0dda8: movbz r12,RL6
c0ddaa: calls 0xc0dbde
c0ddae: movb RL6,[r8]
c0ddb0: bset r6.0x6
c0ddb2: movb [r8],RL6
c0ddb4: jmpr cc_UC,0xc0de2c
c0ddb6: movbz r12,RL6
c0ddb8: calls 0xc0e1b6
c0ddbc: jmpr cc_UC,0xc0de2c
c0ddbe: movb RL2,[r8]
c0ddc0: jnb r2.0x1,0xc0de26
c0ddc4: mov r8,0xc3fc
c0ddc8: mov r12,#0xc41a
c0ddcc: add r12,r9
c0ddce: mov r2,r12
c0ddd0: mov r13,[r8]
c0ddd2: sub r13,[r2]
c0ddd4: add r13,#0xa
c0ddd8: cmp r13,0xc406
c0dddc: jmpr cc_ULE,0xc0ddea
c0ddde: mov r6,[r7]
c0dde0: mov r9,[r8]
c0dde2: add r9,#0xa
c0dde6: mov [r6],r9
c0dde8: jmpr cc_UC,0xc0ddf4
c0ddea: mov r9,[r7]
c0ddec: mov r8,[r12]
c0ddee: add r8,0xc406
c0ddf2: mov [r9],r8
c0ddf4: mov r8,0xc402
c0ddf8: movbz r6,RL1
c0ddfa: and r6,#0xf
c0ddfe: mov r12,r6
c0de00: shl r12,#0x2
c0de02: mov r6,#0xf
c0de04: shl r6,r12
c0de06: cpl r6
c0de08: mov r9,[r8]
c0de0a: and r9,r6
c0de0c: mov [r8],r9
c0de0e: mov r8,0xc402
c0de12: mov r6,#0x4
c0de14: shl r6,r12
c0de16: mov r9,[r8]
c0de18: or r9,r6
c0de1a: mov [r8],r9
c0de1c: mov r8,r1
c0de1e: movbz r12,RL1
c0de20: calls 0xc0db90
c0de24: jmpr cc_UC,0xc0de2c
c0de26: movbz r12,RL6
c0de28: calls 0xc0e27c
c0de2c: mov r6,[r0+]
c0de2e: mov r7,[r0+]
c0de30: mov r8,[r0+]
c0de32: mov r9,[r0+]
c0de34: rets


; ----------------------------------------------------------------------------
; event_idle
; Address: 0xC0E1B6
; Area:    application/04-engine-control/events
; Size:    128 bytes
; --------------------------------------------------------------------------
c0e1b6: mov [-r0],r8
c0e1b8: mov [-r0],r6
c0e1ba: mov r1,r12
c0e1bc: movbz r12,RL1
c0e1be: mov r8,r12
c0e1c0: shl r8,#0x3
c0e1c2: add r8,r12
c0e1c4: shl r8,#0x1
c0e1c6: mov r1,r1
c0e1c8: movbz r12,RL1
c0e1ca: movb RL6,[r8+#0xc41d]
c0e1ce: calls 0xc0dba6
c0e1d2: mov r12,#0xc41c
c0e1d6: add r12,r8
c0e1d8: movb RL1,[r12]
c0e1da: bclr r1.0x5
c0e1dc: movb [r12],RL1
c0e1de: mov r13,0xc3fc
c0e1e2: movbz r1,RL6
c0e1e4: mov r15,[r8+#0xc41e]
c0e1e8: mov r14,[r13]
c0e1ea: add r14,#0x7000
c0e1ee: mov [r15],r14
c0e1f0: mov r14,0xc402
c0e1f4: and r1,#0xf
c0e1f8: mov r13,r1
c0e1fa: shl r13,#0x2
c0e1fc: mov r1,#0xf
c0e1fe: shl r1,r13
c0e200: cpl r1
c0e202: mov r15,[r14]
c0e204: and r15,r1
c0e206: mov [r14],r15
c0e208: mov r14,0xc402
c0e20c: mov r1,#0x4
c0e20e: shl r1,r13
c0e210: mov r15,[r14]
c0e212: or r15,r1
c0e214: mov [r14],r15
c0e216: mov [-r0],r12
c0e218: movbz r12,RL6
c0e21a: calls 0xc0db90
c0e21e: mov r12,[r0+]
c0e220: movb RL6,[r12]
c0e222: bset r6.0x2
c0e224: movb [r12],RL6
c0e226: mov r6,[r8+#0xc420]
c0e22a: mov r8,[r6]
c0e22c: bclr r8.0x7
c0e22e: mov [r6],r8
c0e230: mov r6,[r0+]
c0e232: mov r8,[r0+]
c0e234: rets


; ----------------------------------------------------------------------------
; event_accum
; Address: 0xC0E236
; Area:    application/04-engine-control/events
; Size:    70 bytes
; --------------------------------------------------------------------------
c0e236: mov r1,#0xc41a
c0e23a: mov r2,r12
c0e23c: movbz r14,RL2
c0e23e: mov r15,r14
c0e240: shl r14,#0x3
c0e242: add r14,r15
c0e244: shl r14,#0x1
c0e246: add r1,r14
c0e248: mov r15,r13
c0e24a: sub r15,[r1]
c0e24c: mov r12,r15
c0e24e: cmp r12,#0x7f00
c0e252: jmpr cc_UGT,0xc0e27a
c0e254: mov r15,#0xc416
c0e258: add r15,r14
c0e25a: mov r4,#0x0
c0e25c: mov r2,[r15]
c0e25e: mov r3,[r15+#0x2]
c0e262: add r2,r12
c0e264: addc r3,r4
c0e266: mov [r15+#0x2],r3
c0e26a: mov r12,#0xc41c
c0e26e: add r12,r14
c0e270: mov [r15],r2
c0e272: mov [r1],r13
c0e274: movb RL1,[r12]
c0e276: bclr r1.0x7
c0e278: movb [r12],RL1
c0e27a: rets


; ----------------------------------------------------------------------------
; event_schedule_duration
; Address: 0xC0E27C
; Area:    application/04-engine-control/events
; Size:    350 bytes
; --------------------------------------------------------------------------
c0e27c: mov [-r0],r9
c0e27e: mov [-r0],r8
c0e280: mov [-r0],r7
c0e282: mov [-r0],r6
c0e284: mov r7,r12
c0e286: movbz r12,RL7
c0e288: mov r13,r12
c0e28a: shl r12,#0x3
c0e28c: add r12,r13
c0e28e: shl r12,#0x1
c0e290: mov r8,#0xc412
c0e294: add r8,r12
c0e296: mov r9,#0xc41d
c0e29a: add r9,r12
c0e29c: mov r13,[r8]
c0e29e: mov r14,[r8+#0x2]
c0e2a2: movb RL6,[r9]
c0e2a4: or r13,r14
c0e2a6: jmpa cc_EQ,0xc0e3ca
c0e2aa: mov [-r0],r12
c0e2ac: calls 0xc106e6
c0e2b0: mov r12,[r0+]
c0e2b2: mov r1,#0x0
c0e2b4: mov r13,r4
c0e2b6: mov r15,[r12+#0xc410]
c0e2ba: sub r15,r13
c0e2bc: mov r13,[r8+]
c0e2be: mov r14,[r8]
c0e2c0: mov r8,0xc408
c0e2c4: add r13,r8
c0e2c6: addc r14,r1
c0e2c8: mov r8,#0xc41c
c0e2cc: add r8,r12
c0e2ce: movb RL2,[r8]
c0e2d0: jnb r2.0x3,0xc0e2fa
c0e2d4: mov r2,[r12+#0xc416]
c0e2d8: mov r3,[r12+#0xc418]
c0e2dc: sub r13,r2
c0e2de: subc r14,r3
c0e2e0: mov r2,r14
c0e2e2: shr r13,#0x8
c0e2e4: shr r14,#0x8
c0e2e6: shl r2,#0x8
c0e2e8: or r13,r2
c0e2ea: mov r2,0xc400
c0e2ee: mov r3,#0x0
c0e2f0: add r2,r13
c0e2f2: addc r3,r14
c0e2f4: mov r13,r2
c0e2f6: mov r14,r3
c0e2f8: jmpr cc_UC,0xc0e312
c0e2fa: mov r1,r14
c0e2fc: shr r13,#0x8
c0e2fe: shr r14,#0x8
c0e300: shl r1,#0x8
c0e302: or r13,r1
c0e304: mov r1,0xc40c
c0e308: mov r2,#0x0
c0e30a: add r1,r13
c0e30c: addc r2,r14
c0e30e: mov r13,r1
c0e310: mov r14,r2
c0e312: mov r1,r13
c0e314: mov r2,r14
c0e316: sub r1,#0xffff
c0e31a: subc r2,#0x0
c0e31c: jmpr cc_ULE,0xc0e324
c0e31e: mov r13,#0xffff
c0e322: mov r14,#0x0
c0e324: cmp r13,r15
c0e326: jmpr cc_C,0xc0e330
c0e328: movbz r12,RL7
c0e32a: calls 0xc0dbde
c0e32e: jmpr cc_UC,0xc0e3c2
c0e330: sub r15,r13
c0e332: mov r13,r15
c0e334: cmp r13,#0x7f
c0e338: jmpr cc_ULE,0xc0e380
c0e33a: mov r9,0xc3fc
c0e33e: movbz r1,RL6
c0e340: mov r13,[r12+#0xc41e]
c0e344: mov r7,[r9]
c0e346: add r7,#0x7000
c0e34a: mov [r13],r7
c0e34c: mov r9,0xc402
c0e350: and r1,#0xf
c0e354: mov r12,r1
c0e356: shl r12,#0x2
c0e358: mov r13,#0xf
c0e35a: shl r13,r12
c0e35c: cpl r13
c0e35e: mov r7,[r9]
c0e360: and r7,r13
c0e362: mov [r9],r7
c0e364: mov r9,0xc402
c0e368: mov r13,#0x4
c0e36a: shl r13,r12
c0e36c: mov r7,[r9]
c0e36e: or r7,r13
c0e370: mov [r9],r7
c0e372: movbz r12,RL6
c0e374: calls 0xc0db90
c0e378: movb RL6,[r8]
c0e37a: bset r6.0x2
c0e37c: movb [r8],RL6
c0e37e: jmpr cc_UC,0xc0e3d0
c0e380: movb RL1,[r9]
c0e382: mov r9,0xc3fc
c0e386: mov r7,[r12+#0xc41e]
c0e38a: shl r13,#0x8
c0e38c: mov r6,[r9]
c0e38e: add r6,r13
c0e390: mov [r7],r6
c0e392: mov r9,0xc402
c0e396: movbz r7,RL1
c0e398: and r7,#0xf
c0e39c: mov r12,r7
c0e39e: shl r12,#0x2
c0e3a0: mov r7,#0xf
c0e3a2: shl r7,r12
c0e3a4: cpl r7
c0e3a6: mov r6,[r9]
c0e3a8: and r6,r7
c0e3aa: mov [r9],r6
c0e3ac: mov r9,0xc402
c0e3b0: mov r7,#0x5
c0e3b2: shl r7,r12
c0e3b4: mov r6,[r9]
c0e3b6: or r6,r7
c0e3b8: mov [r9],r6
c0e3ba: mov r9,r1
c0e3bc: movbz r12,RL1
c0e3be: calls 0xc0db90
c0e3c2: movb RL6,[r8]
c0e3c4: bclr r6.0x2
c0e3c6: movb [r8],RL6
c0e3c8: jmpr cc_UC,0xc0e3d0
c0e3ca: movbz r12,RL7
c0e3cc: calls 0xc0e1b6
c0e3d0: mov r6,[r0+]
c0e3d2: mov r7,[r0+]
c0e3d4: mov r8,[r0+]
c0e3d6: mov r9,[r0+]
c0e3d8: rets


; ============================== Engine control / CC22-23 outputs ==============================

; ----------------------------------------------------------------------------
; cc22_23_output_disable
; Address: 0xC0BE46
; Area:    application/04-engine-control/outputs-cc22-23
; Size:    18 bytes
; --------------------------------------------------------------------------
c0be46: cmp r12,#0x0
c0be48: jmpa cc_NE,0xc0be52
c0be4c: bfldh 0xff24,#0x70,#0x0
c0be50: rets
c0be52: bfldh 0xff24,#0x7,#0x0
c0be56: rets


; ----------------------------------------------------------------------------
; cc22_23_schedule
; Address: 0xC0BE6A
; Area:    application/04-engine-control/outputs-cc22-23
; Size:    134 bytes
; --------------------------------------------------------------------------
c0be6a: mov [-r0],r9
c0be6c: mov [-r0],r8
c0be6e: mov [-r0],r7
c0be70: mov [-r0],r6
c0be72: mov r9,r13
c0be74: mov r6,r14
c0be76: calls 0xc1064c
c0be7a: mov r7,r4
c0be7c: mov r12,r6
c0be7e: sub r12,r7
c0be80: cmp r12,#0x2
c0be82: jmpr cc_ULE,0xc0beb8
c0be84: cmp r12,#0x2000
c0be88: jmpr cc_NC,0xc0beb8
c0be8a: mov r8,r6
c0be8c: shl r8,#0x3
c0be8e: cmp r9,#0x0
c0be90: jmpr cc_NE,0xc0be9e
c0be92: atomic #0x2
c0be94: mov 0xfe6e,r8
c0be98: or 0xfe2a,#0x80
c0be9c: jmpr cc_UC,0xc0bea8
c0be9e: atomic #0x2
c0bea0: mov 0xfe6c,r8
c0bea4: or 0xfe2a,#0x40
c0bea8: mov r8,#0x1a
c0beac: mulu r9,r8
c0beae: mov r9,0xfe0e
c0beb2: mov [r9+#0xc3d2],r6
c0beb6: jmpr cc_UC,0xc0bee6
c0beb8: mov r8,0xf050
c0bebc: add r8,#0x7
c0bebe: cmp r9,#0x0
c0bec0: jmpr cc_NE,0xc0bece
c0bec2: atomic #0x2
c0bec4: mov 0xfe6e,r8
c0bec8: or 0xfe2a,#0x80
c0becc: jmpr cc_UC,0xc0bed8
c0bece: atomic #0x2
c0bed0: mov 0xfe6c,r8
c0bed4: or 0xfe2a,#0x40
c0bed8: mov r8,#0x1a
c0bedc: mulu r9,r8
c0bede: mov r9,0xfe0e
c0bee2: mov [r9+#0xc3d2],r7
c0bee6: mov r6,[r0+]
c0bee8: mov r7,[r0+]
c0beea: mov r8,[r0+]
c0beec: mov r9,[r0+]
c0beee: rets


; ----------------------------------------------------------------------------
; cc22_23_output_init
; Address: 0xC0BF02
; Area:    application/04-engine-control/outputs-cc22-23
; Size:    62 bytes
; --------------------------------------------------------------------------
c0bf02: or 0xfe28,#0xc0
c0bf06: or 0xff24,#0x5500
c0bf0a: extr #0x4
c0bf0c: bset 0xf130.0x7
c0bf0e: bset 0xf120.0x0
c0bf10: bset 0xf104.0x7
c0bf12: bset 0xff06.0x0
c0bf14: extr #0x2
c0bf16: or 0xf16c,#0x34
c0bf1a: or 0xff6e,#0x35
c0bf1e: mov r12,#0xfe6e
c0bf22: mov 0xc3c6,r12
c0bf26: mov r13,#0xfe6c
c0bf2a: mov 0xc3e0,r13
c0bf2e: mov r14,#0xf16e
c0bf32: mov 0xc3c8,r14
c0bf36: mov r15,#0xf16c
c0bf3a: mov 0xc3e2,r15
c0bf3e: rets


; ----------------------------------------------------------------------------
; cc22_23_hysteresis_a
; Address: 0xC0E722
; Area:    application/04-engine-control/outputs-cc22-23
; Size:    62 bytes
; --------------------------------------------------------------------------
c0e722: mov r13,0xc450
c0e726: jmpr cc_EQ,0xc0e732
c0e728: cmp r13,#0x1
c0e72a: jmpr cc_EQ,0xc0e73a
c0e72c: cmp r13,#0x2
c0e72e: jmpr cc_EQ,0xc0e752
c0e730: jmpr cc_UC,0xc0e75e
c0e732: cmp r12,#0x6900
c0e736: jmpr cc_ULE,0xc0e75e
c0e738: jmpr cc_UC,0xc0e758
c0e73a: cmp r12,#0x6400
c0e73e: jmpr cc_NC,0xc0e744
c0e740: mov 0xc450,0xff1c
c0e744: cmp r12,#0xa400
c0e748: jmpr cc_ULE,0xc0e75e
c0e74a: mov r12,#0x2
c0e74c: mov 0xc450,r12
c0e750: rets
c0e752: cmp r12,#0xa000
c0e756: jmpr cc_NC,0xc0e75e
c0e758: mov r12,#0x1
c0e75a: mov 0xc450,r12
c0e75e: rets


; ----------------------------------------------------------------------------
; cc22_23_hysteresis_b
; Address: 0xC0E760
; Area:    application/04-engine-control/outputs-cc22-23
; Size:    106 bytes
; --------------------------------------------------------------------------
c0e760: mov r13,0xc454
c0e764: jmpr cc_EQ,0xc0e774
c0e766: cmp r13,#0x1
c0e768: jmpr cc_EQ,0xc0e77c
c0e76a: cmp r13,#0x2
c0e76c: jmpr cc_EQ,0xc0e794
c0e76e: cmp r13,#0x3
c0e770: jmpr cc_EQ,0xc0e7b4
c0e772: jmpr cc_UC,0xc0e7c8
c0e774: cmp r12,#0x1c00
c0e778: jmpr cc_ULE,0xc0e7c8
c0e77a: jmpr cc_UC,0xc0e7c2
c0e77c: cmp r12,#0x1800
c0e780: jmpr cc_NC,0xc0e786
c0e782: mov 0xc454,0xff1c
c0e786: cmp r12,#0x5f00
c0e78a: jmpr cc_UGT,0xc0e7ba
c0e78c: mov r12,0xc450
c0e790: jmpr cc_EQ,0xc0e7c8
c0e792: jmpr cc_UC,0xc0e7ba
c0e794: cmp r12,#0x5a00
c0e798: jmpr cc_NC,0xc0e7a6
c0e79a: mov r13,0xc450
c0e79e: jmpr cc_NE,0xc0e7a6
c0e7a0: mov r14,#0x1
c0e7a2: mov 0xc454,r14
c0e7a6: cmp r12,#0x8400
c0e7aa: jmpr cc_ULE,0xc0e7c8
c0e7ac: mov r12,#0x3
c0e7ae: mov 0xc454,r12
c0e7b2: rets
c0e7b4: cmp r12,#0x8000
c0e7b8: jmpr cc_NC,0xc0e7c8
c0e7ba: mov r12,#0x2
c0e7bc: mov 0xc454,r12
c0e7c0: rets
c0e7c2: mov r12,#0x1
c0e7c4: mov 0xc454,r12
c0e7c8: rets


; ----------------------------------------------------------------------------
; cc_output_gate_update
; Address: 0xC0EBE6
; Area:    application/04-engine-control/outputs-cc22-23
; Size:    38 bytes
; --------------------------------------------------------------------------
c0ebe6: jb 0xfd10.0x2,0xc0ebf6
c0ebea: mov r12,0xfd1a
c0ebee: jnb r12.0x5,0xc0ebf6
c0ebf2: bset 0xfd08.0xf
c0ebf4: jmpr cc_UC,0xc0ebf8
c0ebf6: bclr 0xfd08.0xf
c0ebf8: jb 0xfd0c.0x2,0xc0ec08
c0ebfc: mov r12,0xfd1a
c0ec00: jnb r12.0x4,0xc0ec08
c0ec04: bset 0xfd06.0xf
c0ec06: rets
c0ec08: bclr 0xfd06.0xf
c0ec0a: rets


; ----------------------------------------------------------------------------
; cc22_23_task
; Address: 0xC0F3D2
; Area:    application/04-engine-control/outputs-cc22-23
; Size:    164 bytes
; --------------------------------------------------------------------------
c0f3d2: mov [-r0],r8
c0f3d4: mov r13,0xc9d0
c0f3d8: cmp r13,#0xc7ff
c0f3dc: jmpr cc_NC,0xc0f3e4
c0f3de: mov r13,0xc9d0
c0f3e2: jmpr cc_UC,0xc0f3e8
c0f3e4: mov r13,#0xc7ff
c0f3e8: mov r14,#0x0
c0f3ea: mov r15,r13
c0f3ec: shl r13,#0x5
c0f3ee: shl r14,#0x5
c0f3f0: shr r15,#0xb
c0f3f2: or r14,r15
c0f3f4: mov r15,#0x19
c0f3f8: mov 0xfe0c,r14
c0f3fc: mov 0xfe0e,r13
c0f400: divlu r15
c0f402: mov r12,0xfe0e
c0f406: mov r8,r12
c0f408: calls 0xc0e722
c0f40c: mov r12,r8
c0f40e: calls 0xc0e760
c0f412: jnb 0xfd02.0xa,0xc0f41a
c0f416: jmpa cc_UC,0xc0f46a
c0f41a: mov r8,0xfd02
c0f41e: jb r8.0x7,0xc0f426
c0f422: jmpa cc_UC,0xc0f46a
c0f426: mov r12,0x7046
c0f42a: calls 0xc0bf8c
c0f42e: cmp r4,#0x1
c0f430: jmpa cc_NE,0xc0f448
c0f434: mov r12,#0x0
c0f436: calls 0xc0be46
c0f43a: mov r12,0x7046
c0f43e: mov r13,#0x0
c0f440: calls 0xc0bf54
c0f444: extr #0x1
c0f446: bclr 0xff6e.0x6
c0f448: mov r12,0x7048
c0f44c: calls 0xc0bf8c
c0f450: cmp r4,#0x1
c0f452: jmpa cc_NE,0xc0f46a
c0f456: mov r12,#0x1
c0f458: calls 0xc0be46
c0f45c: mov r12,0x7048
c0f460: mov r13,#0x0
c0f462: calls 0xc0bf54
c0f466: extr #0x1
c0f468: bclr 0xff6c.0x6
c0f46a: bmov 0xfd02.0x7,0xfd02.0xa
c0f46e: calls 0xc0fb8c
c0f472: mov r8,[r0+]
c0f474: rets


; ----------------------------------------------------------------------------
; cc22_23_start_pair
; Address: 0xC0FACE
; Area:    application/04-engine-control/outputs-cc22-23
; Size:    42 bytes
; --------------------------------------------------------------------------
c0face: mov [-r0],r12
c0fad0: shl r12,#0x1
c0fad2: mov r14,r12
c0fad4: mov r12,[r14+#0x7046]
c0fad8: mov r14,r13
c0fada: mov r13,[r0]
c0fadc: calls 0xc0be6a
c0fae0: mov r12,[r0+]
c0fae2: jmpa cc_NE,0xc0faec
c0fae6: extr #0x1
c0fae8: bset 0xff6e.0x6
c0faea: rets
c0faec: cmp r12,#0x1
c0faee: jmpa cc_NE,0xc0faf6
c0faf2: extr #0x1
c0faf4: bset 0xff6c.0x6
c0faf6: rets


; ----------------------------------------------------------------------------
; cc22_23_start_once
; Address: 0xC0FB36
; Area:    application/04-engine-control/outputs-cc22-23
; Size:    56 bytes
; --------------------------------------------------------------------------
c0fb36: mov [-r0],r8
c0fb38: movb RL1,0xc456
c0fb3c: jmpr cc_NE,0xc0fb6a
c0fb3e: movb RL2,#0x1
c0fb40: movb 0xc456,RL2
c0fb44: calls 0xc0bd54
c0fb48: calls 0xc1064c
c0fb4c: mov r8,r4
c0fb4e: mov r12,#0x0
c0fb50: mov r13,r8
c0fb52: calls 0xc0face
c0fb56: mov r12,#0x1
c0fb58: mov r13,r8
c0fb5a: calls 0xc0face
c0fb5e: extp 0x301, #0x1
c0fb62: add r8,0x39da
c0fb66: mov 0xc448,r8
c0fb6a: mov r8,[r0+]
c0fb6c: rets


; ----------------------------------------------------------------------------
; cc_event_timeout_tick
; Address: 0xC0FB8C
; Area:    application/04-engine-control/outputs-cc22-23
; Size:    64 bytes
; --------------------------------------------------------------------------
c0fb8c: sub 0xc478,0xff1e
c0fb90: mov r12,0xc478
c0fb94: cmp r12,#0xa00
c0fb98: jmpr cc_ULE,0xc0fbca
c0fb9a: mov 0xc478,0xff1c
c0fb9e: movb RL1,0xfd12
c0fba2: cmpb RL1,#0x0
c0fba4: jmpr cc_ULE,0xc0fbb4
c0fba6: movb RL1,0xfd12
c0fbaa: cmpb RL1,#0x10
c0fbae: jmpr cc_NC,0xc0fbb4
c0fbb0: addb 0xfd12,0xff1e
c0fbb4: movb RL1,0xfd0e
c0fbb8: cmpb RL1,#0x0
c0fbba: jmpr cc_ULE,0xc0fbca
c0fbbc: movb RL1,0xfd0e
c0fbc0: cmpb RL1,#0x10
c0fbc4: jmpr cc_NC,0xc0fbca
c0fbc6: addb 0xfd0e,0xff1e
c0fbca: rets


; ============================== Engine control / speed ==============================

; ----------------------------------------------------------------------------
; speed_timing_calc
; Address: 0xC0CD24
; Area:    application/04-engine-control/speed
; Size:    214 bytes
; --------------------------------------------------------------------------
c0cd24: bclr 0xff10.0xb
c0cd26: mov r12,#0x3c80
c0cd2a: mov r13,#0x0
c0cd2c: mov r12,#0x0
c0cd2e: movb RL2,0xc268
c0cd32: movbz r14,RL2
c0cd34: add r14,#0x1
c0cd36: mov r1,r14
c0cd38: cmpb RL1,RL2
c0cd3a: jmpr cc_C,0xc0cd42
c0cd3c: cmpb RL1,#0xff
c0cd40: jmpr cc_ULE,0xc0cd46
c0cd42: movb RL1,#0xff
c0cd46: movb RL2,RL1
c0cd48: movbz r1,RL1
c0cd4a: mov r12,#0x0
c0cd4c: movb 0xc268,RL1
c0cd50: bclr 0xff10.0xb
c0cd52: mov r13,0xfd00
c0cd56: shr r13,#0x6
c0cd58: and r13,#0x1
c0cd5a: mov r12,r13
c0cd5c: bclr 0xfd00.0x6
c0cd5e: bset 0xff10.0xb
c0cd60: mov r13,r12
c0cd62: mov r13,0xfd02
c0cd66: bmov r13.0xe,r12.0x0
c0cd6a: mov 0xfd02,r13
c0cd6e: mov r12,0xfd02
c0cd72: jnb r12.0xe,0xc0cd78
c0cd76: bset 0xfd02.0xf
c0cd78: bclr 0xff10.0xb
c0cd7a: mov r13,0xfd00
c0cd7e: shr r13,#0xb
c0cd80: and r13,#0x1
c0cd82: mov r12,r13
c0cd84: bclr 0xfd00.0xb
c0cd86: bset 0xff10.0xb
c0cd88: mov r13,r12
c0cd8a: mov r13,0xfd02
c0cd8e: bmov r13.0xd,r12.0x0
c0cd92: mov 0xfd02,r13
c0cd96: bclr 0xff10.0xb
c0cd98: mov r13,0xfd00
c0cd9c: shr r13,#0x9
c0cd9e: and r13,#0x1
c0cda0: mov r12,r13
c0cda2: bclr 0xfd00.0x9
c0cda4: bset 0xff10.0xb
c0cda6: mov r13,r12
c0cda8: mov r13,0xfd02
c0cdac: bmov r13.0xc,r12.0x0
c0cdb0: mov 0xfd02,r13
c0cdb4: mov r12,0xfd02
c0cdb8: jnb r12.0xc,0xc0cdc0
c0cdbc: bfldh 0xfd02,#0xc,#0xc
c0cdc0: bset 0xff10.0xb
c0cdc2: mov r12,#0x7000
c0cdc6: mov r13,0xc9d0
c0cdca: calls 0xc2850e
c0cdce: mov 0xc254,r4
c0cdd2: mov r12,#0x504c
c0cdd6: mov r13,#0xc0
c0cdda: mov r14,r4
c0cddc: calls 0xc27ca4
c0cde0: mov 0xc274,r4
c0cde4: mov r12,#0x5038
c0cde8: mov r13,#0xc0
c0cdec: mov r14,0xc254
c0cdf0: calls 0xc27ca4
c0cdf4: mov 0xc26e,r4
c0cdf8: rets


; ----------------------------------------------------------------------------
; angle_init
; Address: 0xC0D562
; Area:    application/04-engine-control/speed
; Size:    104 bytes
; --------------------------------------------------------------------------
c0d562: bclr 0xff10.0xb
c0d564: mov r12,#0xd076
c0d568: mov r13,#0xc0
c0d56c: mov 0xc224,r12
c0d570: mov 0xc226,r13
c0d574: movb RL1,#0x0
c0d576: mov r12,#0x5032
c0d57a: mov r13,#0xc0
c0d57e: movbz r14,RL1
c0d580: shl r14,#0x1
c0d582: mov r15,#0x0
c0d584: add r12,r14
c0d586: addc r13,r15
c0d588: exts r13, #0x1
c0d58a: mov r3,[r12]
c0d58c: shr r3,#0x6
c0d58e: mov r12,#0xf
c0d590: mov 0xfe0e,r3
c0d594: divu r12
c0d596: movbz r12,RL1
c0d598: addb RL1,#0x1
c0d59a: mov r3,0xfe0e
c0d59e: movb RL2,RL3
c0d5a0: addb RL2,#0x4
c0d5a2: mov r4,r2
c0d5a4: movb RL2,RL4
c0d5a6: cmpb RL2,#0x18
c0d5aa: jmpr cc_ULE,0xc0d5be
c0d5ac: movbz r4,RL2
c0d5ae: mov r13,#0x18
c0d5b2: mov 0xfe0e,r4
c0d5b6: divu r13
c0d5b8: mov r4,0xfe0c
c0d5bc: movb RL2,RL4
c0d5be: movb [r12+#0xc382],RL2
c0d5c2: cmpb RL1,#0x2
c0d5c4: jmpr cc_C,0xc0d576
c0d5c6: bset 0xff10.0xb
c0d5c8: rets


; ============================== Engine control / load ==============================

; ----------------------------------------------------------------------------
; calc_load
; Address: 0xC1FD9C
; Area:    application/04-engine-control/load
; Size:    322 bytes
; --------------------------------------------------------------------------
c1fd9c: mov [-r0],r8
c1fd9e: extp 0x380, #0x1
c1fda2: movb RL1,0x89e
c1fda6: cmpb RL1,#0x2
c1fda8: jmpr cc_EQ,0xc1fdb0
c1fdaa: movb RL2,0xca37
c1fdae: jmpr cc_EQ,0xc1fdbc
c1fdb0: extp 0x380, #0x1
c1fdb4: mov 0x8a8,0xff1c
c1fdb8: jmpa cc_UC,0xc1feda
c1fdbc: extp 0x380, #0x1
c1fdc0: movb RL1,0x81b
c1fdc4: jmpr cc_EQ,0xc1fdd0
c1fdc6: extp 0x380, #0x1
c1fdca: mov 0x8b2,0xff1c
c1fdce: jmpr cc_UC,0xc1fe2c
c1fdd0: mov r12,#0x7564
c1fdd4: mov r13,0xc9d0
c1fdd8: calls 0xc2850e
c1fddc: mov r8,r4
c1fdde: mov r12,#0x755e
c1fde2: mov r13,0xca2a
c1fde6: calls 0xc2850e
c1fdea: mov r14,r4
c1fdec: mov r12,#0x794a
c1fdf0: mov r13,#0xc0
c1fdf4: mov r15,r14
c1fdf6: mov r14,r8
c1fdf8: calls 0xc2826e
c1fdfc: mov r8,r4
c1fdfe: mov r12,#0x79b6
c1fe02: mov r13,#0xc0
c1fe06: mov r14,0xc97c
c1fe0a: calls 0xc27fca
c1fe0e: mov r12,r4
c1fe10: mulu r8,r12
c1fe12: mov r13,0xfe0c
c1fe16: mov r12,r13
c1fe18: mov r8,0xfe0e
c1fe1c: shr r8,#0xf
c1fe1e: shr r13,#0xf
c1fe20: shl r12,#0x1
c1fe22: or r8,r12
c1fe24: extp 0x380, #0x1
c1fe28: mov 0x8b2,r8
c1fe2c: extp 0x380, #0x1
c1fe30: mov r8,0x8a8
c1fe34: extp 0x380, #0x1
c1fe38: cmp r8,0x8b2
c1fe3c: jmpr cc_NC,0xc1fe7a
c1fe3e: mov r12,#0x755e
c1fe42: mov r13,0xca2a
c1fe46: calls 0xc2850e
c1fe4a: mov r14,r4
c1fe4c: mov r12,#0x79aa
c1fe50: mov r13,#0xc0
c1fe54: calls 0xc27fca
c1fe58: mov r8,r4
c1fe5a: extp 0x380, #0x1
c1fe5e: mov r12,0x8a8
c1fe62: extp 0x380, #0x1
c1fe66: mov r13,0x8b2
c1fe6a: mov r14,r8
c1fe6c: calls 0xc1596e
c1fe70: extp 0x380, #0x1
c1fe74: mov 0x8a8,r4
c1fe78: jmpr cc_UC,0xc1feb2
c1fe7a: movb RL1,0xc604
c1fe7e: jmpr cc_NE,0xc1fe96
c1fe80: extp 0x301, #0x1
c1fe84: movb RL2,0x107a
c1fe88: cmpb RL2,#0x1
c1fe8a: jmpr cc_NE,0xc1fe96
c1fe8c: extp 0x301, #0x1
c1fe90: mov r8,0x39ca
c1fe94: jmpr cc_UC,0xc1feb2
c1fe96: mov r12,#0x7564
c1fe9a: mov r13,0xc9d0
c1fe9e: calls 0xc2850e
c1fea2: mov r14,r4
c1fea4: mov r12,#0x799e
c1fea8: mov r13,#0xc0
c1feac: calls 0xc27fca
c1feb0: mov r8,r4
c1feb2: extp 0x380, #0x1
c1feb6: mov r12,0x8a8
c1feba: extp 0x380, #0x1
c1febe: cmp r12,0x8b2
c1fec2: jmpr cc_C,0xc1feda
c1fec4: extp 0x380, #0x1
c1fec8: mov r13,0x8b2
c1fecc: mov r14,r8
c1fece: calls 0xc1596e
c1fed2: extp 0x380, #0x1
c1fed6: mov 0x8a8,r4
c1feda: mov r8,[r0+]
c1fedc: rets


; ============================== Engine control / limits ==============================

; ----------------------------------------------------------------------------
; rate_limit
; Address: 0xC1596E
; Area:    application/04-engine-control/limits
; Size:    78 bytes
; --------------------------------------------------------------------------
c1596e: mov r15,r12
c15970: cmp r13,r12
c15972: jmpr cc_EQ,0xc159b8
c15974: cmp r14,#0x0
c15976: jmpr cc_EQ,0xc159b8
c15978: cmp r13,r12
c1597a: jmpr cc_ULE,0xc15994
c1597c: mov r1,r13
c1597e: sub r1,r12
c15980: mulu r1,r14
c15982: mov r2,#0x0
c15984: mov r14,r12
c15986: mov r3,#0x0
c15988: mov r1,0xfe0c
c1598c: add r14,r1
c1598e: addc r3,r2
c15990: mov r15,r14
c15992: jmpr cc_UC,0xc159aa
c15994: mov r1,r12
c15996: sub r1,r13
c15998: mulu r1,r14
c1599a: mov r2,#0x0
c1599c: mov r14,r12
c1599e: mov r3,#0x0
c159a0: mov r1,0xfe0c
c159a4: sub r14,r1
c159a6: subc r3,r2
c159a8: mov r15,r14
c159aa: cmp r15,r12
c159ac: jmpr cc_NE,0xc159b8
c159ae: cmp r13,r12
c159b0: jmpr cc_ULE,0xc159b6
c159b2: add r15,#0x1
c159b4: jmpr cc_UC,0xc159b8
c159b6: sub r15,#0x1
c159b8: mov r4,r15
c159ba: rets


; ----------------------------------------------------------------------------
; calc_limit1
; Address: 0xC200AA
; Area:    application/04-engine-control/limits
; Size:    260 bytes
; --------------------------------------------------------------------------
c200aa: movb RL1,0xc93c
c200ae: cmpb RL1,#0x4
c200b0: jmpr cc_EQ,0xc200b6
c200b2: cmpb RL1,#0x1
c200b4: jmpr cc_NE,0xc200bc
c200b6: calls 0xc202ee
c200ba: jmpr cc_UC,0xc20192
c200bc: extp 0x380, #0x1
c200c0: movb RL1,0x85b
c200c4: jmpr cc_EQ,0xc200d4
c200c6: mov r12,#0x8000
c200ca: extp 0x380, #0x1
c200ce: mov 0x8ac,r12
c200d2: jmpr cc_UC,0xc20192
c200d4: movb RL1,0xc93c
c200d8: cmpb RL1,#0x3
c200da: jmpr cc_NE,0xc20192
c200dc: movb RL2,#0x1
c200de: movb 0xc886,RL2
c200e2: mov r12,0xc86e
c200e6: extp 0x380, #0x1
c200ea: cmp r12,0x8a6
c200ee: jmpr cc_C,0xc20192
c200f0: extp 0x380, #0x1
c200f4: mov r13,0x8a0
c200f8: cmp r13,#0x80
c200fc: jmpr cc_UGT,0xc2010c
c200fe: extp 0x380, #0x1
c20102: mov r14,0x8ac
c20106: cmp r14,#0x80
c2010a: jmpr cc_ULE,0xc20192
c2010c: movb 0xc886,0xff1c
c20110: mov 0xc86e,0xff1c
c20114: extp 0x380, #0x1
c20118: mov r12,0x8a0
c2011c: extp 0x301, #0x1
c20120: mov r14,0x38e0
c20124: mulu r12,r14
c20126: mov r13,#0x0
c20128: mov r12,0xfe0c
c2012c: extp 0x380, #0x1
c20130: mov 0x8a0,r12
c20134: cmp r12,#0x80
c20138: jmpr cc_UGT,0xc20142
c2013a: extp 0x380, #0x1
c2013e: mov 0x8a0,0xff1c
c20142: extp 0x380, #0x1
c20146: movb RL1,0x822
c2014a: jmpr cc_EQ,0xc2017a
c2014c: extp 0x380, #0x1
c20150: mov r12,0x8ac
c20154: extp 0x380, #0x1
c20158: mov r14,0x8a4
c2015c: mulu r12,r14
c2015e: mov r13,#0x0
c20160: mov r12,0xfe0c
c20164: extp 0x380, #0x1
c20168: mov 0x8ac,r12
c2016c: cmp r12,#0x80
c20170: jmpr cc_UGT,0xc2017a
c20172: extp 0x380, #0x1
c20176: mov 0x8ac,0xff1c
c2017a: mov r12,#0x7912
c2017e: mov r13,#0xc0
c20182: mov r14,0xc97c
c20186: calls 0xc27ca4
c2018a: extp 0x380, #0x1
c2018e: mov 0x8a6,r4
c20192: extp 0x380, #0x1
c20196: mov r12,0x8a0
c2019a: extp 0x380, #0x1
c2019e: cmp r12,0x8ac
c201a2: jmpr cc_NC,0xc201ac
c201a4: extp 0x380, #0x1
c201a8: mov 0x8ac,r12
c201ac: rets


; ----------------------------------------------------------------------------
; calc_limit2
; Address: 0xC201AE
; Area:    application/04-engine-control/limits
; Size:    320 bytes
; --------------------------------------------------------------------------
c201ae: extp 0x380, #0x1
c201b2: movb RL1,0x85b
c201b6: jmpr cc_EQ,0xc201ca
c201b8: extp 0x380, #0x1
c201bc: mov 0x8b0,0xff1c
c201c0: extp 0x380, #0x1
c201c4: mov 0x8aa,0xff1c
c201c8: rets
c201ca: movb RL1,0xc93c
c201ce: cmpb RL1,#0x3
c201d0: jmpr cc_EQ,0xc201f4
c201d2: movb 0xc885,0xff1c
c201d6: mov 0xc86c,0xff1c
c201da: mov r12,#0x7860
c201de: mov r13,#0xc0
c201e2: mov r14,0xc97c
c201e6: calls 0xc27fca
c201ea: extp 0x380, #0x1
c201ee: mov 0x8aa,r4
c201f2: jmpr cc_UC,0xc2024c
c201f4: movb RL1,0xc93c
c201f8: cmpb RL1,#0x3
c201fa: jmpr cc_NE,0xc2024c
c201fc: movb RL2,#0x1
c201fe: movb 0xc885,RL2
c20202: extp 0x380, #0x1
c20206: mov r12,0x8aa
c2020a: cmp r12,#0x80
c2020e: jmpr cc_ULE,0xc2024c
c20210: mov r13,0xc86c
c20214: extp 0x301, #0x1
c20218: cmp r13,0x3834
c2021c: jmpr cc_C,0xc2024c
c2021e: movb 0xc885,0xff1c
c20222: mov 0xc86c,0xff1c
c20226: extp 0x301, #0x1
c2022a: mov r14,0x3830
c2022e: mulu r12,r14
c20230: mov r13,#0x0
c20232: mov r12,0xfe0c
c20236: extp 0x380, #0x1
c2023a: mov 0x8aa,r12
c2023e: cmp r12,#0x80
c20242: jmpr cc_UGT,0xc2024c
c20244: extp 0x380, #0x1
c20248: mov 0x8aa,0xff1c
c2024c: movb RL1,0xc93c
c20250: cmpb RL1,#0x3
c20252: jmpr cc_NE,0xc202e0
c20254: mov r12,0xc9d0
c20258: extp 0x301, #0x1
c2025c: cmp r12,0x381e
c20260: jmpr cc_C,0xc20266
c20262: movb RL1,#0x1
c20264: jmpr cc_UC,0xc20268
c20266: movb RL1,#0x0
c20268: mov r12,0xc86a
c2026c: extp 0x301, #0x1
c20270: cmp r12,0x3832
c20274: jmpr cc_C,0xc2027a
c20276: movb RL2,#0x1
c20278: jmpr cc_UC,0xc2027c
c2027a: movb RL2,#0x0
c2027c: cmpb RL1,#0x0
c2027e: jmpr cc_EQ,0xc20286
c20280: movb RL3,#0x1
c20282: movb 0xc884,RL3
c20286: cmpb RL1,#0x0
c20288: jmpr cc_EQ,0xc2029e
c2028a: cmpb RL2,#0x0
c2028c: jmpr cc_EQ,0xc2029e
c2028e: movb 0xc884,0xff1c
c20292: movb RL1,#0x1
c20294: extp 0x380, #0x1
c20298: movb 0x8a2,RL1
c2029c: jmpr cc_UC,0xc202a6
c2029e: extp 0x380, #0x1
c202a2: movb 0x8a2,0xff1c
c202a6: extp 0x380, #0x1
c202aa: movb RL1,0x8a2
c202ae: jmpr cc_EQ,0xc202b6
c202b0: mov r12,0xc958
c202b4: jmpr cc_UC,0xc202be
c202b6: extp 0x301, #0x1
c202ba: mov r12,0x383c
c202be: mov r13,r12
c202c0: mov r12,#0x7510
c202c4: calls 0xc2850e
c202c8: mov r14,r4
c202ca: mov r12,#0x784c
c202ce: mov r13,#0xc0
c202d2: calls 0xc27fca
c202d6: extp 0x380, #0x1
c202da: mov 0x8b0,r4
c202de: rets
c202e0: mov 0xc86a,0xff1c
c202e4: extp 0x380, #0x1
c202e8: mov 0x8b0,0xff1c
c202ec: rets


; ----------------------------------------------------------------------------
; calc_limit3
; Address: 0xC202EE
; Area:    application/04-engine-control/limits
; Size:    170 bytes
; --------------------------------------------------------------------------
c202ee: mov [-r0],r8
c202f0: mov r12,#0x7552
c202f4: mov r13,0xc936
c202f8: calls 0xc284d8
c202fc: mov r8,r4
c202fe: mov r12,#0x7912
c20302: mov r13,#0xc0
c20306: mov r14,r8
c20308: calls 0xc27ca4
c2030c: extp 0x380, #0x1
c20310: mov 0x8a6,r4
c20314: mov r12,#0x78e2
c20318: mov r13,#0xc0
c2031c: mov r14,r8
c2031e: calls 0xc27fca
c20322: extp 0x380, #0x1
c20326: mov 0x8a4,r4
c2032a: mov r12,#0x7874
c2032e: mov r13,#0xc0
c20332: mov r14,r8
c20334: calls 0xc27fca
c20338: mov r8,r4
c2033a: mov r12,#0x750a
c2033e: mov r13,0xc06a
c20342: calls 0xc2850e
c20346: mov r14,r4
c20348: mov r12,#0x78d8
c2034c: mov r13,#0xc0
c20350: calls 0xc27fca
c20354: mov r12,r4
c20356: mulu r8,r12
c20358: mov r13,0xfe0c
c2035c: mov r12,r13
c2035e: mov r8,0xfe0e
c20362: shr r8,#0xd
c20364: shr r13,#0xd
c20366: shl r12,#0x3
c20368: or r8,r12
c2036a: extp 0x380, #0x1
c2036e: mov 0x8ac,r8
c20372: cmp r8,#0x8000
c20376: jmpr cc_ULE,0xc20384
c20378: mov r12,#0x8000
c2037c: extp 0x380, #0x1
c20380: mov 0x8ac,r12
c20384: extp 0x380, #0x1
c20388: mov r8,0x8ac
c2038c: extp 0x380, #0x1
c20390: mov 0x8a0,r8
c20394: mov r8,[r0+]
c20396: rets


; ============================== Engine control / sensor ==============================

; ----------------------------------------------------------------------------
; config_sensor_setup
; Address: 0xC0F628
; Area:    application/04-engine-control/sensor
; Size:    532 bytes
; --------------------------------------------------------------------------
c0f628: bclr 0xff10.0xb
c0f62a: bclr 0xfd0a.0x0
c0f62c: bclr 0xfd0a.0x1
c0f62e: extp 0x301, #0x1
c0f632: movb RL1,0x1036
c0f636: cmpb RL1,#0x3
c0f638: jmpa cc_UGT,0xc0f824
c0f63c: mov r12,#0xd09a
c0f640: mov r13,#0xc0
c0f644: mov 0xc23c,r12
c0f648: mov 0xc23e,r13
c0f64c: mov r12,#0xd07c
c0f650: mov r13,#0xc0
c0f654: mov 0xc22c,r12
c0f658: mov 0xc22e,r13
c0f65c: mov r12,#0xd08e
c0f660: mov r13,#0xc0
c0f664: mov 0xc234,r12
c0f668: mov 0xc236,r13
c0f66c: mov r12,#0xd0b2
c0f670: mov r13,#0xc0
c0f674: mov 0xc220,r12
c0f678: mov 0xc222,r13
c0f67c: mov r14,#0x4
c0f67e: or 0xc28a,r14
c0f682: movb RL2,#0x2
c0f684: movb 0xc45e,RL2
c0f688: mov r12,#0xd0a0
c0f68c: mov r13,#0xc0
c0f690: mov 0xc238,r12
c0f694: mov 0xc23a,r13
c0f698: mov r12,#0xd082
c0f69c: mov r13,#0xc0
c0f6a0: mov 0xc228,r12
c0f6a4: mov 0xc22a,r13
c0f6a8: mov r12,#0xd094
c0f6ac: mov r13,#0xc0
c0f6b0: mov 0xc230,r12
c0f6b4: mov 0xc232,r13
c0f6b8: cmpb RL1,#0x2
c0f6ba: jmpr cc_EQ,0xc0f6c6
c0f6bc: cmpb RL1,#0x3
c0f6be: jmpr cc_EQ,0xc0f6e0
c0f6c0: cmpb RL1,#0x0
c0f6c2: jmpr cc_EQ,0xc0f6fa
c0f6c4: jmpr cc_UC,0xc0f71c
c0f6c6: movb RL1,#0x5a
c0f6ca: mov r12,#0x200
c0f6ce: or 0xc28a,r12
c0f6d2: mov r12,#0x200
c0f6d6: or 0xc290,r12
c0f6da: mov r12,#0x7022
c0f6de: jmpr cc_UC,0xc0f722
c0f6e0: movb RL1,#0x3c
c0f6e4: mov r12,#0x200
c0f6e8: or 0xc2aa,r12
c0f6ec: mov r12,#0x200
c0f6f0: or 0xc28c,r12
c0f6f4: mov r12,#0x7018
c0f6f8: jmpr cc_UC,0xc0f722
c0f6fa: movb RL1,#0xb4
c0f6fe: mov r12,#0x200
c0f702: or 0xc28a,r12
c0f706: mov r12,#0x200
c0f70a: or 0xc296,r12
c0f70e: mov r12,#0x200
c0f712: or 0xc29c,r12
c0f716: mov r12,#0x702c
c0f71a: jmpr cc_UC,0xc0f722
c0f71c: movb RL1,#0x0
c0f71e: mov r12,#0x700e
c0f722: movbz r2,RL1
c0f724: mov r13,#0xf
c0f726: mov 0xfe0e,r2
c0f72a: divu r13
c0f72c: sub r0,#0x8
c0f730: mov r4,#0x7036
c0f734: mov r14,#0x200
c0f738: or 0xc2a2,r14
c0f73c: mov 0xc44c,0xff1c
c0f740: mov r2,0xfe0e
c0f744: movb RL1,RL2
c0f746: mov r14,r1
c0f748: calls 0xc28f6c
c0f74c: mov r11,r10
c0f74e: mov r1,r14
c0f750: movbz r10,RL1
c0f752: add r10,#0x4
c0f754: mov r4,r10
c0f756: calls 0xc28dec
c0f75a: calls 0xc28e50
c0f75e: add r0,#0x10
c0f762: cmp r4,#0xffff
c0f766: jmpr cc_EQ,0xc0f792
c0f768: mov r1,r14
c0f76a: movbz r11,RL1
c0f76c: add r11,#0x4
c0f76e: mov r4,r11
c0f770: calls 0xc28dec
c0f774: mov r11,r10
c0f776: mov r4,#0x703e
c0f77a: calls 0xc28f6c
c0f77e: calls 0xc28cac
c0f782: mov r4,r0
c0f784: add r4,#0x10
c0f788: calls 0xc28f84
c0f78c: add r0,#0x10
c0f790: jmpr cc_UC,0xc0f7ba
c0f792: mov r4,#0x703e
c0f796: calls 0xc28f6c
c0f79a: mov r11,r10
c0f79c: mov r1,r14
c0f79e: movbz r10,RL1
c0f7a0: add r10,#0x4
c0f7a2: mov r4,r10
c0f7a4: calls 0xc28dec
c0f7a8: calls 0xc28ca4
c0f7ac: mov r4,r0
c0f7ae: add r4,#0x10
c0f7b2: calls 0xc28f84
c0f7b6: add r0,#0x10
c0f7ba: mov r10,r0
c0f7bc: calls 0xc28dbe
c0f7c0: movbz r13,RL4
c0f7c2: shl r13,#0x1
c0f7c4: mov r14,#0xc282
c0f7c8: add r14,r13
c0f7ca: movb RL1,#0x0
c0f7cc: add r0,#0x8
c0f7d0: mov r13,[r14]
c0f7d2: bfldl r13,#0x8,#0x8
c0f7d6: mov [r14],r13
c0f7d8: movbz r13,RL1
c0f7da: shl r13,#0x1
c0f7dc: mov r14,r12
c0f7de: add r14,r13
c0f7e0: addb RL1,#0x1
c0f7e2: movb RL2,[r14]
c0f7e4: mov r14,r12
c0f7e6: add r14,#0x1
c0f7e8: add r14,r13
c0f7ea: movb [r13+#0xc468],RL2
c0f7ee: movb RL2,[r14]
c0f7f0: movb [r13+#0xc469],RL2
c0f7f4: movbz r13,RL1
c0f7f6: cmp r13,#0x5
c0f7f8: jmpr cc_C,0xc0f7d8
c0f7fa: movb RL1,#0x0
c0f7fc: jmpr cc_UC,0xc0f816
c0f7fe: movbz r12,RL1
c0f800: mov r13,#0x1a
c0f804: mulu r12,r13
c0f806: movb RL2,#0x0
c0f808: mov r12,0xfe0e
c0f80c: addb RL1,#0x1
c0f80e: movb [r12+#0xc3da],RL2
c0f812: movb [r12+#0xc3d9],RL2
c0f816: cmpb RL1,0xc45e
c0f81a: jmpr cc_C,0xc0f7fe
c0f81c: calls 0xc0bf02
c0f820: calls 0xc0bef0
c0f824: mov r12,#0x4800
c0f828: mov 0xfd08,r12
c0f82c: mov 0xfd06,r12
c0f830: calls 0xc0ebe6
c0f834: movb 0xc456,0xff1c
c0f838: bset 0xff10.0xb
c0f83a: rets


; ============================== Runtime library ==============================

; ----------------------------------------------------------------------------
; memcpy_wdt
; Address: 0xC01D9A
; Area:    application/05-runtime-lib
; Size:    40 bytes
; --------------------------------------------------------------------------
c01d9a: mov [-r0],r8
c01d9c: mov r8,#0x0
c01d9e: jmpr cc_UC,0xc01db6
c01da0: exts r15, #0x1
c01da2: movb RL1,[r14]
c01da4: exts r13, #0x1
c01da6: movb [r12],RL1
c01da8: add r12,#0x1
c01daa: addc r13,#0x0
c01dac: add r14,#0x1
c01dae: addc r15,#0x0
c01db0: srvwdt
c01db4: add r8,#0x1
c01db6: mov r1,[r0+#0x2]
c01dba: cmp r8,r1
c01dbc: jmpr cc_C,0xc01da0
c01dbe: mov r8,[r0+]
c01dc0: rets


; ----------------------------------------------------------------------------
; ret_stub
; Address: 0xC01EC8
; Area:    application/05-runtime-lib
; Size:    6 bytes
; --------------------------------------------------------------------------
c01ec8: push r5
c01eca: push r4
c01ecc: rets


; ----------------------------------------------------------------------------
; mem_read_word
; Address: 0xC01ECE
; Area:    application/05-runtime-lib
; Size:    14 bytes
; --------------------------------------------------------------------------
c01ece: exts r5, #0x1
c01ed0: mov r10,[r4]
c01ed2: add r4,#0x2
c01ed4: addc r5,#0x0
c01ed6: exts r5, #0x1
c01ed8: mov r11,[r4]
c01eda: rets


; ----------------------------------------------------------------------------
; mem_write_word
; Address: 0xC01EDC
; Area:    application/05-runtime-lib
; Size:    14 bytes
; --------------------------------------------------------------------------
c01edc: exts r5, #0x1
c01ede: mov [r4],r10
c01ee0: add r4,#0x2
c01ee2: addc r5,#0x0
c01ee4: exts r5, #0x1
c01ee6: mov [r4],r11
c01ee8: rets


; ----------------------------------------------------------------------------
; seg_to_ptr
; Address: 0xC01EEA
; Area:    application/05-runtime-lib
; Size:    22 bytes
; --------------------------------------------------------------------------
c01eea: mov r5,r4
c01eec: shr r5,#0xe
c01eee: shl r5,#0x1
c01ef0: mov r5,[r5+#0xfe00]
c01ef4: bmov r4.0xe,r5.0x0
c01ef8: bmov r4.0xf,r5.0x1
c01efc: shr r5,#0x2
c01efe: rets


; ----------------------------------------------------------------------------
; empty_stub_1
; Address: 0xC0BFF4
; Area:    application/05-runtime-lib
; Size:    2 bytes
; --------------------------------------------------------------------------
c0bff4: rets


; ----------------------------------------------------------------------------
; empty_stub_2
; Address: 0xC0BFF6
; Area:    application/05-runtime-lib
; Size:    2 bytes
; --------------------------------------------------------------------------
c0bff6: rets


; ----------------------------------------------------------------------------
; empty_stub_3
; Address: 0xC10240
; Area:    application/05-runtime-lib
; Size:    2 bytes
; --------------------------------------------------------------------------
c10240: rets


; ----------------------------------------------------------------------------
; div32_checked
; Address: 0xC1096E
; Area:    application/05-runtime-lib
; Size:    52 bytes
; --------------------------------------------------------------------------
c1096e: mov r15,#0xffff
c10972: mov r1,r15
c10974: cmp r14,#0x0
c10976: jmpr cc_ULE,0xc1099c
c10978: mov r4,r12
c1097a: mov r5,r13
c1097c: mov r10,r14
c1097e: mov r11,#0x0
c10980: calls 0xc28bb2
c10984: mov r15,r4
c10986: mov r1,r5
c10988: mov r12,r15
c1098a: mov r13,r1
c1098c: sub r12,#0xffff
c10990: subc r13,#0xffff
c10994: jmpr cc_C,0xc1099c
c10996: mov r15,#0xffff
c1099a: mov r1,r15
c1099c: mov r4,r15
c1099e: mov r5,r1
c109a0: rets


; ----------------------------------------------------------------------------
; mul_div32
; Address: 0xC109A2
; Area:    application/05-runtime-lib
; Size:    24 bytes
; --------------------------------------------------------------------------
c109a2: mov r4,r12
c109a4: mov r5,r13
c109a6: mov r10,r14
c109a8: mov r11,#0x0
c109aa: calls 0xc28b64
c109ae: mov r10,#0x64
c109b2: mov r11,#0x0
c109b4: calls 0xc28bb2
c109b8: rets


; ----------------------------------------------------------------------------
; mul32
; Address: 0xC28B64
; Area:    application/05-runtime-lib
; Size:    36 bytes
; --------------------------------------------------------------------------
c28b64: atomic #0x2
c28b66: mulu r5,r10
c28b68: nop
c28b6a: mov r5,0xfe0e
c28b6e: atomic #0x2
c28b70: mulu r4,r11
c28b72: nop
c28b74: add r5,0xfe0e
c28b78: atomic #0x2
c28b7a: mulu r4,r10
c28b7c: nop
c28b7e: add r5,0xfe0c
c28b82: mov r4,0xfe0e
c28b86: rets


; ----------------------------------------------------------------------------
; div32u
; Address: 0xC28BB2
; Area:    application/05-runtime-lib
; Size:    148 bytes
; --------------------------------------------------------------------------
c28bb2: mov [-r0],r2
c28bb4: prior r2,r11
c28bb6: jmpr cc_NE,0xc28be0
c28bb8: mov 0xfe0e,r5
c28bbc: mov 0xfe0c,r2
c28bc0: atomic #0x4
c28bc2: divlu r10
c28bc4: mov r2,0xfe0c
c28bc8: mov r5,0xfe0e
c28bcc: mov 0xfe0c,r2
c28bd0: mov 0xfe0e,r4
c28bd4: atomic #0x4
c28bd6: divlu r10
c28bd8: mov r4,0xfe0e
c28bdc: mov r2,[r0+]
c28bde: rets
c28be0: mov [-r0],r5
c28be2: mov [-r0],r4
c28be4: mov [-r0],r10
c28be6: mov [-r0],r11
c28be8: cmp r2,#0x0
c28bea: jmpr cc_NE,0xc28bf2
c28bec: mov r4,r5
c28bee: mov r5,#0x0
c28bf0: jmpr cc_UC,0xc28c06
c28bf2: shl r11,r2
c28bf4: neg r2
c28bf6: shr r10,r2
c28bf8: or r11,r10
c28bfa: mov r10,r5
c28bfc: shr r5,r2
c28bfe: shr r4,r2
c28c00: neg r2
c28c02: shl r10,r2
c28c04: or r4,r10
c28c06: mov 0xfe0c,r5
c28c0a: mov 0xfe0e,r4
c28c0e: atomic #0x4
c28c10: divlu r11
c28c12: mov r4,0xfe0e
c28c16: mov r11,[r0+]
c28c18: mov r10,[r0+]
c28c1a: atomic #0x2
c28c1c: mulu r4,r11
c28c1e: nop
c28c20: mov r5,0xfe0e
c28c24: atomic #0x2
c28c26: mulu r4,r10
c28c28: nop
c28c2a: add r5,0xfe0c
c28c2e: mov r11,0xfe0e
c28c32: jmpr cc_NC,0xc28c38
c28c34: add r0,#0x4
c28c36: jmpr cc_UC,0xc28c3e
c28c38: sub r11,[r0+]
c28c3a: subc r5,[r0+]
c28c3c: jmpr cc_ULE,0xc28c40
c28c3e: sub r4,#0x1
c28c40: mov r5,#0x0
c28c42: mov r2,[r0+]
c28c44: rets


; ----------------------------------------------------------------------------
; empty_stub_0
; Address: 0xC28C4E
; Area:    application/05-runtime-lib
; Size:    6 bytes
; --------------------------------------------------------------------------
c28c4e: push r5
c28c50: push r4
c28c52: rets


; ----------------------------------------------------------------------------
; store32
; Address: 0xC28C62
; Area:    application/05-runtime-lib
; Size:    14 bytes
; --------------------------------------------------------------------------
c28c62: exts r5, #0x1
c28c64: mov [r4],r10
c28c66: add r4,#0x2
c28c68: addc r5,#0x0
c28c6a: exts r5, #0x1
c28c6c: mov [r4],r11
c28c6e: rets


; ----------------------------------------------------------------------------
; fp_div_signed
; Address: 0xC28CA4
; Area:    application/05-runtime-lib
; Size:    28 bytes
; --------------------------------------------------------------------------
c28c86: mov r1,r2
c28c88: shr r4,#0x1
c28c8a: mov r7,r6
c28c8c: mov r8,r12
c28c8e: mov r9,r13
c28c90: mov r5,r14
c28c92: jmps 0xc28f1e
c28c96: jmps 0xc28f5e
c28ca4: mov r2,[r11]
c28ca6: bmovn r2.0xf,r2.0xf
c28caa: mov [r11],r2


; ----------------------------------------------------------------------------
; fp_div_unsigned
; Address: 0xC28CAC
; Area:    application/05-runtime-lib
; Size:    274 bytes
; --------------------------------------------------------------------------
c28cac: calls 0xc28e94
c28cb0: cmp r2,#0x0
c28cb2: jmpr cc_EQ,0xc28c92
c28cb4: cmp r1,#0x0
c28cb6: jmpr cc_EQ,0xc28c86
c28cb8: cmp r1,r2
c28cba: jmpr cc_NC,0xc28ce0
c28cbc: xor r7,r6
c28cbe: xor r6,r7
c28cc0: xor r7,r6
c28cc2: xor r8,r12
c28cc4: xor r12,r8
c28cc6: xor r8,r12
c28cc8: xor r9,r13
c28cca: xor r13,r9
c28ccc: xor r9,r13
c28cce: xor r5,r14
c28cd0: xor r14,r5
c28cd2: xor r5,r14
c28cd4: xor r1,r2
c28cd6: xor r2,r1
c28cd8: xor r1,r2
c28cda: bmov r4.0x2,r4.0x0
c28cde: shr r4,#0x1
c28ce0: mov r3,#0x0
c28ce2: sub r2,r1
c28ce4: jmpr cc_EQ,0xc28d38
c28ce6: neg r2
c28ce8: cmp r2,#0x35
c28cec: jmpr cc_UGT,0xc28c92
c28cee: sub r2,#0x10
c28cf2: jmpr cc_SLT,0xc28d00
c28cf4: mov r3,r14
c28cf6: mov r14,r13
c28cf8: mov r13,r12
c28cfa: mov r12,r6
c28cfc: mov r6,#0x0
c28cfe: jmpr cc_UC,0xc28cee
c28d00: add r2,#0x10
c28d04: jmpr cc_EQ,0xc28d38
c28d06: mov [-r0],r4
c28d08: mov [-r0],r7
c28d0a: mov r7,r14
c28d0c: shr r3,r2
c28d0e: neg r2
c28d10: shl r7,r2
c28d12: or r3,r7
c28d14: mov r7,r13
c28d16: shl r7,r2
c28d18: neg r2
c28d1a: shr r14,r2
c28d1c: or r14,r7
c28d1e: mov r7,r12
c28d20: shr r13,r2
c28d22: neg r2
c28d24: shl r7,r2
c28d26: or r13,r7
c28d28: mov r7,r6
c28d2a: shl r7,r2
c28d2c: neg r2
c28d2e: shr r12,r2
c28d30: or r12,r7
c28d32: shr r6,r2
c28d34: mov r7,[r0+]
c28d36: mov r4,[r0+]
c28d38: bcmp r4.0x1,r4.0x0
c28d3c: jmpr cc_N,0xc28d6c
c28d3e: add r5,r14
c28d40: addc r9,r13
c28d42: addc r8,r12
c28d44: addc r7,r6
c28d46: jb r7.0x5,0xc28d4e
c28d4a: jmps 0xc28f0e
c28d4e: shr r3,#0x1
c28d50: bmov r3.0xf,r5.0x0
c28d54: shr r5,#0x1
c28d56: bmov r5.0xf,r9.0x0
c28d5a: shr r9,#0x1
c28d5c: bmov r9.0xf,r8.0x0
c28d60: shr r8,#0x1
c28d62: bmov r8.0xf,r7.0x0
c28d66: shr r7,#0x1
c28d68: add r1,#0x1
c28d6a: jmpr cc_UC,0xc28d4a
c28d6c: neg r3
c28d6e: subc r5,r14
c28d70: subc r9,r13
c28d72: subc r8,r12
c28d74: subc r7,r6
c28d76: jmpr cc_EQ,0xc28c96
c28d78: jmpr cc_UGT,0xc28d90
c28d7a: cpl r4
c28d7c: cpl r3
c28d7e: cpl r5
c28d80: cpl r9
c28d82: cpl r8
c28d84: cpl r7
c28d86: add r3,#0x1
c28d88: addc r5,#0x0
c28d8a: addc r9,#0x0
c28d8c: addc r8,#0x0
c28d8e: addc r7,#0x0
c28d90: mov r6,r7
c28d92: or r6,r8
c28d94: jmpr cc_EQ,0xc28dac
c28d96: jnb r7.0x4,0xc28d9e
c28d9a: jmps 0xc28f0e
c28d9e: sub r1,#0x1
c28da0: add r3,r3
c28da2: addc r5,r5
c28da4: addc r9,r9
c28da6: addc r8,r8
c28da8: addc r7,r7
c28daa: jmpr cc_UC,0xc28d90
c28dac: mov r8,r9
c28dae: mov r9,r5
c28db0: mov r5,r3
c28db2: mov r3,#0x0
c28db4: sub r1,#0x10
c28db8: jmpr cc_UC,0xc28d90
c28f0a: add r1,#0x1
c28f0c: jmpr cc_UC,0xc28f1e


; ----------------------------------------------------------------------------
; fp_to_int
; Address: 0xC28DBE
; Area:    application/05-runtime-lib
; Size:    50 bytes
; --------------------------------------------------------------------------
c28dba: mov r4,#0x0
c28dbc: jmpr cc_UC,0xc28de4
c28dbe: mov [-r0],r7
c28dc0: mov [-r0],r8
c28dc2: mov [-r0],r9
c28dc4: calls 0xc28ed2
c28dc8: jb r4.0x0,0xc28dba
c28dcc: cmp r1,#0x3ff
c28dd0: jmpr cc_C,0xc28dba
c28dd2: shl r7,#0xb
c28dd4: shr r8,#0x5
c28dd6: or r7,r8
c28dd8: sub r1,#0x40e
c28ddc: jmpr cc_UGT,0xc28dbc
c28dde: neg r1
c28de0: shr r7,r1
c28de2: mov r4,r7
c28de4: mov r9,[r0+]
c28de6: mov r8,[r0+]
c28de8: mov r7,[r0+]
c28dea: rets


; ----------------------------------------------------------------------------
; fp_neg
; Address: 0xC28DEC
; Area:    application/05-runtime-lib
; Size:    82 bytes
; --------------------------------------------------------------------------
c28dec: sub r0,#0x8
c28df0: mov r10,r0
c28df2: mov [-r0],r7
c28df4: mov [-r0],r8
c28df6: mov [-r0],r9
c28df8: mov r7,r4
c28dfa: shr r7,#0xf
c28dfc: mov [r10+#0x6],r7
c28e00: jmpr cc_EQ,0xc28e18
c28e02: neg r4
c28e04: jmpr cc_UC,0xc28e18
c28e18: prior r1,r4
c28e1a: jmpr cc_NE,0xc28e28
c28e1c: mov r1,#0x0
c28e1e: mov [r10+#0x6],r1
c28e22: calls 0xc28f5e
c28e26: jmpr cc_UC,0xc28e48
c28e28: mov r7,r4
c28e2a: mov r4,[r10+#0x6]
c28e2e: shl r7,r1
c28e30: sub r1,#0x40e
c28e34: neg r1
c28e36: mov r8,r7
c28e38: shr r7,#0xb
c28e3a: shl r8,#0x5
c28e3c: mov r9,#0x0
c28e3e: mov r5,#0x0
c28e40: mov [r10+#0x6],r5
c28e44: calls 0xc28f1e
c28e48: mov r9,[r0+]
c28e4a: mov r8,[r0+]
c28e4c: mov r7,[r0+]
c28e4e: rets


; ----------------------------------------------------------------------------
; fp_compare
; Address: 0xC28E50
; Area:    application/05-runtime-lib
; Size:    68 bytes
; --------------------------------------------------------------------------
c28e50: mov r1,r10
c28e52: mov r2,r11
c28e54: mov r3,[r1+]
c28e56: mov r5,[r2+]
c28e58: mov r4,r3
c28e5a: or r3,r5
c28e5c: and r3,#0x7ff0
c28e60: jmpr cc_EQ,0xc28e8c
c28e62: mov r3,r4
c28e64: ashr r4,#0xf
c28e66: or r4,#0x1
c28e68: bcmp r3.0xf,r5.0xf
c28e6c: jmpr cc_N,0xc28e92
c28e6e: cmp r3,r5
c28e70: jmpr cc_UGT,0xc28e92
c28e72: jmpr cc_C,0xc28e90
c28e74: mov r3,[r1+]
c28e76: cmp r3,[r2+]
c28e78: jmpr cc_UGT,0xc28e92
c28e7a: jmpr cc_C,0xc28e90
c28e7c: mov r3,[r1+]
c28e7e: cmp r3,[r2+]
c28e80: jmpr cc_UGT,0xc28e92
c28e82: jmpr cc_C,0xc28e90
c28e84: mov r3,[r1]
c28e86: cmp r3,[r2]
c28e88: jmpr cc_UGT,0xc28e92
c28e8a: jmpr cc_C,0xc28e90
c28e8c: mov r4,#0x0
c28e8e: rets
c28e90: neg r4
c28e92: rets


; ----------------------------------------------------------------------------
; fp_pack
; Address: 0xC28E94
; Area:    application/05-runtime-lib
; Size:    62 bytes
; --------------------------------------------------------------------------
c28e94: mov r3,r14
c28e96: mov r14,[r11+#0x6]
c28e9a: mov [r11+#0x6],r3
c28e9e: mov r3,r13
c28ea0: mov r13,[r11+#0x4]
c28ea4: mov [r11+#0x4],r3
c28ea8: mov r3,r12
c28eaa: mov r12,[r11+#0x2]
c28eae: mov [r11+#0x2],r3
c28eb2: mov r3,r6
c28eb4: mov r2,[r11]
c28eb6: mov [r11],r3
c28eb8: bmov r4.0x1,r2.0xf
c28ebc: mov r6,r2
c28ebe: and r6,#0xf
c28ec2: shl r2,#0x1
c28ec4: shr r2,#0x5
c28ec6: bmovn r6.0x4,0xff10.0x3
c28eca: mov r5,[r10+#0x6]
c28ece: mov r3,#0x1
c28ed0: jmpr cc_UC,0xc28ed8


; ----------------------------------------------------------------------------
; fp_pack_zero
; Address: 0xC28ED2
; Area:    application/05-runtime-lib
; Size:    56 bytes
; --------------------------------------------------------------------------
c28ed2: mov r5,[r10+#0x6]
c28ed6: mov r3,#0x0
c28ed8: mov [r10+#0x6],r3
c28edc: mov r3,r9
c28ede: mov r9,[r10+#0x4]
c28ee2: mov [r10+#0x4],r3
c28ee6: mov r3,r8
c28ee8: mov r8,[r10+#0x2]
c28eec: mov [r10+#0x2],r3
c28ef0: mov r3,r7
c28ef2: mov r1,[r10]
c28ef4: mov [r10],r3
c28ef6: bmov r4.0x0,r1.0xf
c28efa: mov r7,r1
c28efc: and r7,#0xf
c28f00: shl r1,#0x1
c28f02: shr r1,#0x5
c28f04: bmovn r7.0x4,0xff10.0x3
c28f08: rets


; ----------------------------------------------------------------------------
; fp_round
; Address: 0xC28F0E
; Area:    application/05-runtime-lib
; Size:    16 bytes
; --------------------------------------------------------------------------
c28f0e: jnb r3.0xf,0xc28f1e
c28f12: add r5,#0x1
c28f14: addc r9,#0x0
c28f16: addc r8,#0x0
c28f18: addc r7,#0x0
c28f1a: jb r7.0x5,0xc28f0a


; ----------------------------------------------------------------------------
; fp_store
; Address: 0xC28F1E
; Area:    application/05-runtime-lib
; Size:    64 bytes
; --------------------------------------------------------------------------
c28f1e: mov r3,[r10+#0x6]
c28f22: jmpr cc_EQ,0xc28f32
c28f24: mov r14,[r11+#0x6]
c28f28: mov r13,[r11+#0x4]
c28f2c: mov r12,[r11+#0x2]
c28f30: mov r6,[r11]
c28f32: mov [r10+#0x6],r5
c28f36: mov r3,[r10+#0x4]
c28f3a: mov [r10+#0x4],r9
c28f3e: mov r9,r3
c28f40: mov r3,[r10+#0x2]
c28f44: mov [r10+#0x2],r8
c28f48: mov r8,r3
c28f4a: mov r3,[r10]
c28f4c: shl r1,#0x4
c28f4e: and r7,#0xf
c28f52: or r7,r1
c28f54: bmov r7.0xf,r4.0x0
c28f58: mov [r10],r7
c28f5a: mov r7,r3
c28f5c: rets


; ----------------------------------------------------------------------------
; fp_store_zero
; Address: 0xC28F5E
; Area:    application/05-runtime-lib
; Size:    14 bytes
; --------------------------------------------------------------------------
c28f5e: mov r4,#0x0
c28f60: mov r1,#0x0
c28f62: mov r7,#0x0
c28f64: mov r8,#0x0
c28f66: mov r9,#0x0
c28f68: mov r5,#0x0
c28f6a: jmpr cc_UC,0xc28f1e


; ----------------------------------------------------------------------------
; fp_load
; Address: 0xC28F6C
; Area:    application/05-runtime-lib
; Size:    24 bytes
; --------------------------------------------------------------------------
c28f6c: sub r0,#0x8
c28f70: mov r10,r0
c28f72: mov [r10+],[r4]
c28f74: add r4,#0x2
c28f76: mov [r10+],[r4]
c28f78: add r4,#0x2
c28f7a: mov [r10+],[r4]
c28f7c: add r4,#0x2
c28f7e: mov [r10],[r4]
c28f80: sub r10,#0x6
c28f82: rets


; ----------------------------------------------------------------------------
; fp_copy
; Address: 0xC28F84
; Area:    application/05-runtime-lib
; Size:    16 bytes
; --------------------------------------------------------------------------
c28f84: mov [r4],[r10+]
c28f86: add r4,#0x2
c28f88: mov [r4],[r10+]
c28f8a: add r4,#0x2
c28f8c: mov [r4],[r10+]
c28f8e: add r4,#0x2
c28f90: mov [r4],[r10]
c28f92: rets

