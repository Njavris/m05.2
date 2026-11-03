; ============================================================================
; Delphi MT05.2 semantic reconstruction: bootloader firmware part
; Generated from Ghidra decompiler output; not compilable source.
; Functions are grouped by area and sorted by address.
; ============================================================================

; ============================== Bootloader ==============================

; ----------------------------------------------------------------------------
; boot_main
; Address: 0xC00200
; Area:    bootloader
; Size:    220 bytes
; --------------------------------------------------------------------------
c00200: mov r12,#0x7fc
c00204: mov r13,#0xe0
c00208: mov r14,0xf1e4
c0020c: jnb r14.0x1,0xc00240
c00210: mov r4,r12
c00212: mov r5,r13
c00214: calls 0xc01ece
c00218: sub r10,#0x8625
c0021c: subc r11,#0x6450
c00220: jmpr cc_NE,0xc00228
c00222: movb RL1,#0x1
c00224: movb 0xc020,RL1
c00228: mov r4,r12
c0022a: mov r5,r13
c0022c: calls 0xc01ece
c00230: sub r10,#0x6450
c00234: subc r11,#0x8633
c00238: jmpr cc_NE,0xc00240
c0023a: movb RL1,#0x2
c0023c: movb 0xc020,RL1
c00240: mov r10,#0x0
c00242: mov r11,#0x0
c00244: mov r4,r12
c00246: mov r5,r13
c00248: calls 0xc01edc
c0024c: calls 0xc002dc
c00250: extp 0x304, #0x1
c00254: mov r12,0x0
c00258: jmpr cc_NE,0xc0025e
c0025a: calls 0xc003f0
c0025e: mov r12,0xf1e4
c00262: jnb r12.0xa,0xc0026a
c00266: calls 0xc003f0
c0026a: movb RL1,0xc020
c0026e: cmpb RL1,#0x1
c00270: jmpr cc_EQ,0xc00276
c00272: cmpb RL1,#0x2
c00274: jmpr cc_NE,0xc00282
c00276: movbz r12,0xc020
c0027a: calls 0xc01218
c0027e: calls 0xc003f0
c00282: extp 0x30f, #0x1
c00286: mov r12,0x3ffc
c0028a: cmp r12,#0xaa00
c0028e: jmpr cc_EQ,0xc002d2
c00290: mov r12,#0x0
c00292: mov r13,#0xc0
c00296: mov r14,#0x1ffd
c0029a: mov r15,#0xc0
c0029e: calls 0xc0037e
c002a2: extp 0x300, #0x1
c002a6: mov r12,0x1ffe
c002aa: cmp r4,r12
c002ac: jmpa cc_NE,0xc002d6
c002b0: mov r12,#0xb000
c002b4: mov r13,#0xc0
c002b8: mov r14,#0xfffb
c002bc: mov r15,#0xc3
c002c0: calls 0xc0037e
c002c4: extp 0x30f, #0x1
c002c8: mov r12,0x3ffe
c002cc: cmp r4,r12
c002ce: jmpa cc_NE,0xc002d6
c002d2: jmps 0xc10000
c002d6: calls 0xc003f0
c002da: rets


; ----------------------------------------------------------------------------
; boot_periph_init
; Address: 0xC002DC
; Area:    bootloader
; Size:    50 bytes
; --------------------------------------------------------------------------
c002dc: calls 0xc0030e
c002e0: extr #0x1
c002e2: mov 0xffd0,#0x7f13
c002e6: calls 0xc01080
c002ea: movbz r12,0xc020
c002ee: calls 0xc00c36
c002f2: movbz r12,0xc020
c002f6: calls 0xc00ca2
c002fa: calls 0xc00ee8
c002fe: calls 0xc00ddc
c00302: calls 0xc00dae
c00306: calls 0xc00434
c0030a: bset 0xff10.0xb
c0030c: rets


; ----------------------------------------------------------------------------
; boot_bus_mode
; Address: 0xC0030E
; Area:    bootloader
; Size:    112 bytes
; --------------------------------------------------------------------------
c0030e: mov r12,0xf0c2
c00312: and r12,#0x1800
c00316: cmp r12,#0x800
c0031a: jmpr cc_NE,0xc00332
c0031c: mov r12,0xf0c2
c00320: and r12,#0xff
c00324: mov r1,r12
c00326: cplb RL1
c00328: movbz r12,RL1
c0032a: or r12,#0x8e00
c0032e: mov 0xf0c0,r12
c00332: mov r12,0xf0c2
c00336: and r12,#0x1800
c0033a: cmp r12,#0x1800
c0033e: jmpr cc_NE,0xc0037c
c00340: extr #0x2
c00342: mov 0xf0c0,#0xaaaa
c00346: mov 0xfec0,#0x5554
c0034a: mov r12,0xf0c2
c0034e: and r12,#0xff
c00352: mov r1,r12
c00354: cplb RL1
c00356: movbz r12,RL1
c00358: or r12,#0x9600
c0035c: mov 0xf0c0,r12
c00360: extr #0x1
c00362: mov 0xfec0,#0x800
c00366: mov r12,0xf0c2
c0036a: and r12,#0xff
c0036e: mov r1,r12
c00370: cplb RL1
c00372: movbz r12,RL1
c00374: or r12,#0x8e00
c00378: mov 0xf0c0,r12
c0037c: rets


; ----------------------------------------------------------------------------
; checksum16_be
; Address: 0xC0037E
; Area:    bootloader
; Size:    50 bytes
; --------------------------------------------------------------------------
c0037e: mov r1,r12
c00380: mov r2,r13
c00382: mov r1,#0x0
c00384: diswdt
c00388: jmpr cc_UC,0xc003a6
c0038a: exts r13, #0x1
c0038c: mov r2,[r12]
c0038e: and r2,#0xff
c00392: shl r2,#0x8
c00394: add r1,r2
c00396: exts r13, #0x1
c00398: mov r2,[r12]
c0039a: and r2,#0xff00
c0039e: shr r2,#0x8
c003a0: add r1,r2
c003a2: add r12,#0x2
c003a4: addc r13,#0x0
c003a6: mov r2,r12
c003a8: mov r3,r13
c003aa: sub r2,r14
c003ac: subc r3,r15
c003ae: jmpr cc_C,0xc0038a


; ----------------------------------------------------------------------------
; delay_loop
; Address: 0xC003B8
; Area:    bootloader
; Size:    10 bytes
; --------------------------------------------------------------------------
c003b8: mov r12,#0x0
c003ba: cmpi1 r12,#0x62f
c003be: jmpr cc_SLT,0xc003ba
c003c0: rets


; ----------------------------------------------------------------------------
; delay_ticks
; Address: 0xC003C2
; Area:    bootloader
; Size:    28 bytes
; --------------------------------------------------------------------------
c003c2: mov r14,#0x0
c003c4: jmpa cc_UC,0xc003d6
c003c8: srvwdt
c003cc: mov r13,#0x0
c003ce: cmpi1 r13,#0x7bbf
c003d2: jmpr cc_SLT,0xc003ce
c003d4: add r14,#0x1
c003d6: cmp r14,r12
c003d8: jmpa cc_SLT,0xc003c8
c003dc: rets


; ----------------------------------------------------------------------------
; boot_minimal_main
; Address: 0xC003DE
; Area:    bootloader
; Size:    18 bytes
; --------------------------------------------------------------------------
c003de: mov r12,#0x0
c003e0: calls 0xc00c36
c003e4: mov r12,#0x0
c003e6: calls 0xc00ca2
c003ea: calls 0xc01ad4
c003ee: rets


; ----------------------------------------------------------------------------
; bootloader_entry
; Address: 0xC003F0
; Area:    bootloader
; Size:    56 bytes
; --------------------------------------------------------------------------
c003f0: bclr 0xff04.0x5
c003f2: bclr 0xff16.0x4
c003f4: bclr 0xff04.0x6
c003f6: mov r12,#0x1
c003f8: calls 0xc003c2
c003fc: calls 0xc00eca
c00400: mov r12,#0x1
c00402: calls 0xc003c2
c00406: calls 0xc00eca
c0040a: extr #0x1
c0040c: bclr 0xff04.0x6
c0040e: mov r12,#0x1f4
c00412: calls 0xc003c2
c00416: mov r12,0xc078
c0041a: jb r12.0x4,0xc0040e
c0041e: extr #0x1
c00420: bset 0xff04.0x6
c00422: bmovn 0xff04.0x6,0xff04.0x6
c00426: jmpr cc_UC,0xc0040e


; ----------------------------------------------------------------------------
; boot_cinit
; Address: 0xC00904
; Area:    bootloader
; Size:    372 bytes
; --------------------------------------------------------------------------
c00904: mov r1,#0xfdfe
c00908: cmp r1,#0xfc22
c0090c: jmpr cc_EQ,0xc00918
c0090e: cmp r1,#0xfc20
c00912: jmpr cc_EQ,0xc00918
c00914: mov [r1],0xff1c
c00918: cmpd2 r1,#0xfd00
c0091c: jmpr cc_NE,0xc00908
c0091e: mov r4,#0x8ba
c00922: mov 0xfe00,#0x300
c00926: nop
c00928: mov r5,[r4+]
c0092a: cmp r5,#0x1
c0092c: jmpr cc_EQ,0xc009e6
c0092e: cmp r5,#0x5
c00930: jmpr cc_EQ,0xc009d2
c00932: cmp r5,#0x6
c00934: jmpr cc_EQ,0xc00998
c00936: cmp r5,#0x7
c00938: jmpr cc_NE,0xc009ec
c0093a: mov r1,[r4+]
c0093c: mov r3,[r4+]
c0093e: movb RH3,RH1
c00940: rol r3,#0x2
c00942: and r3,#0x3ff
c00946: mov 0xfe02,r3
c0094a: bclr r1.0xf
c0094c: bset r1.0xe
c0094e: mov r2,[r4+]
c00950: mov r3,[r4+]
c00952: movb RH3,RH2
c00954: rol r3,#0x2
c00956: and r3,#0x3ff
c0095a: mov 0xfe04,r3
c0095e: bset r2.0xf
c00960: bclr r2.0xe
c00962: mov r5,[r4+]
c00964: mov r6,[r4+]
c00966: cmpd1 r5,#0x0
c00968: jmpr cc_NE,0xc0096e
c0096a: cmpd1 r6,#0x0
c0096c: jmpr cc_EQ,0xc0098e
c0096e: movb [r1],[r2]
c00970: cmpi1 r1,#0x7fff
c00974: jmpr cc_NE,0xc0097e
c00976: mov r1,#0x4000
c0097a: add 0xfe02,#0x1
c0097e: cmpi1 r2,#0xbfff
c00982: jmpr cc_NE,0xc00966
c00984: mov r2,#0x8000
c00988: add 0xfe04,#0x1
c0098c: jmpr cc_UC,0xc00966
c0098e: mov 0xfe02,#0x301
c00992: mov 0xfe04,#0x302
c00996: jmpr cc_UC,0xc00928
c00998: mov r1,[r4+]
c0099a: bclr r1.0xf
c0099c: bset r1.0xe
c0099e: mov 0xfe02,[r4]
c009a2: add r4,#0x2
c009a4: mov r2,[r4+]
c009a6: bset r2.0xf
c009a8: bclr r2.0xe
c009aa: mov 0xfe04,[r4]
c009ae: add r4,#0x2
c009b0: mov r5,[r4+]
c009b2: cmpd1 r5,#0x0
c009b4: jmpr cc_EQ,0xc009c8
c009b6: movb [r1],[r2+]
c009b8: cmpi1 r1,#0x7fff
c009bc: jmpr cc_NE,0xc009b2
c009be: mov r1,#0x4000
c009c2: add 0xfe02,#0x1
c009c6: jmpr cc_UC,0xc009b2
c009c8: mov 0xfe02,#0x301
c009cc: mov 0xfe04,#0x302
c009d0: jmpr cc_UC,0xc00928
c009d2: mov r1,[r4+]
c009d4: mov r2,[r4+]
c009d6: mov r5,[r4+]
c009d8: mov 0xfe00,#0x300
c009dc: cmpd1 r5,#0x0
c009de: jmpr cc_EQ,0xc00922
c009e0: movb [r1],[r2+]
c009e2: add r1,#0x1
c009e4: jmpr cc_UC,0xc009dc
c009e6: add r4,#0xc
c009ea: jmpr cc_UC,0xc00928
c009ec: mov r4,#0x898
c009f0: mov 0xfe00,#0x300
c009f4: nop
c009f6: mov r5,[r4+]
c009f8: cmp r5,#0x5
c009fa: jmpr cc_EQ,0xc00a5e
c009fc: cmp r5,#0x6
c009fe: jmpr cc_EQ,0xc00a3e
c00a00: cmp r5,#0x7
c00a02: jmpr cc_NE,0xc00a72
c00a04: mov r1,[r4+]
c00a06: mov r3,[r4+]
c00a08: movb RH3,RH1
c00a0a: rol r3,#0x2
c00a0c: and r3,#0x3ff
c00a10: mov 0xfe02,r3
c00a14: bclr r1.0xf
c00a16: bset r1.0xe
c00a18: mov r5,[r4+]
c00a1a: mov r6,[r4+]
c00a1c: cmpd1 r5,#0x0
c00a1e: jmpr cc_NE,0xc00a24
c00a20: cmpd1 r6,#0x0
c00a22: jmpr cc_EQ,0xc00a38
c00a24: movb [r1],0xff1c
c00a28: cmpi1 r1,#0x7fff
c00a2c: jmpr cc_NE,0xc00a1c
c00a2e: mov r1,#0x4000
c00a32: add 0xfe02,#0x1
c00a36: jmpr cc_UC,0xc00a1c
c00a38: mov 0xfe02,#0x301
c00a3c: jmpr cc_UC,0xc009f6
c00a3e: mov r1,[r4+]
c00a40: bclr r1.0xf
c00a42: bset r1.0xe
c00a44: mov 0xfe02,[r4]
c00a48: add r4,#0x2
c00a4a: mov r5,[r4+]
c00a4c: cmpd1 r5,#0x0
c00a4e: jmpr cc_EQ,0xc00a58
c00a50: movb [r1],0xff1c
c00a54: add r1,#0x1
c00a56: jmpr cc_UC,0xc00a4c
c00a58: mov 0xfe02,#0x301
c00a5c: jmpr cc_UC,0xc009f6
c00a5e: mov r1,[r4+]
c00a60: mov r5,[r4+]
c00a62: mov 0xfe00,#0x300
c00a66: cmpd1 r5,#0x0
c00a68: jmpr cc_EQ,0xc009f0
c00a6a: movb [r1],0xff1c
c00a6e: add r1,#0x1
c00a70: jmpr cc_UC,0xc00a66
c00a72: mov 0xfe00,#0x300
c00a76: rets


; ----------------------------------------------------------------------------
; boot_reset
; Address: 0xC00A78
; Area:    bootloader
; Size:    440 bytes
; --------------------------------------------------------------------------
c00a78: mov 0xffae,#0xcf01
c00a7c: mov 0xfe18,#0x17
c00a80: mov 0xfe1a,#0x8fbb
c00a84: extr #0x1
c00a86: mov 0xffdc,#0x0
c00a8a: extr #0x1
c00a8c: mov 0xffd4,#0x0
c00a90: mov 0xffaa,#0x0
c00a94: bset 0xffc6.0xf
c00a96: bset 0xffc4.0xf
c00a98: extr #0x1
c00a9a: mov 0xfefa,#0x8000
c00a9e: mov 0xff12,#0xc0
c00aa2: atomic #0x3
c00aa4: mov 0xfe12,#0xfc00
c00aa8: mov 0xfe14,#0xfa0c
c00aac: mov 0xfe16,#0xfc00
c00ab0: mov 0xfe10,#0xfc20
c00ab4: nop
c00ab6: mov 0xfe00,#0x300
c00aba: mov 0xfe02,#0x301
c00abe: mov 0xfe04,#0x302
c00ac2: mov r0,#0xc06e
c00ac6: bfldh 0xff10,#0x3,#0x2
c00aca: mov r0,#0xc000
c00ace: bfldh 0xff10,#0x3,#0x3
c00ad2: mov r0,#0xc000
c00ad6: bfldh 0xff10,#0x3,#0x0
c00ada: einit
c00ade: calls 0xc00904
c00ae2: calls 0xc003b8
c00ae6: mov 0xffbe,#0x9000
c00aea: mov r15,#0x0
c00aec: mov 0xf09c,r15
c00af0: mov 0xffa4,#0x59
c00af4: bset 0xffbe.0x7
c00af6: jnb 0xff98.0x7,0xc00af6
c00afa: bclr 0xff98.0x7
c00afc: bclr 0xff9a.0x7
c00afe: mov r12,0xfea0
c00b02: and r12,#0xfff
c00b06: shr r12,#0x2
c00b08: cmp r12,#0x396
c00b0c: jmpr cc_ULE,0xc00b98
c00b0e: mov 0xffbe,#0x9003
c00b12: mov r15,#0x0
c00b14: mov 0xf09c,r15
c00b18: mov 0xffa4,#0x59
c00b1c: bset 0xffbe.0x7
c00b1e: jnb 0xff98.0x7,0xc00b1e
c00b22: bclr 0xff98.0x7
c00b24: bclr 0xff9a.0x7
c00b26: mov r12,0xfea0
c00b2a: and r12,#0xfff
c00b2e: shr r12,#0x2
c00b30: cmp r12,#0x396
c00b34: jmpr cc_ULE,0xc00b98
c00b36: mov 0xffbe,#0x9004
c00b3a: mov r15,#0x0
c00b3c: mov 0xf09c,r15
c00b40: mov 0xffa4,#0x59
c00b44: bset 0xffbe.0x7
c00b46: jnb 0xff98.0x7,0xc00b46
c00b4a: bclr 0xff98.0x7
c00b4c: bclr 0xff9a.0x7
c00b4e: mov r12,0xfea0
c00b52: and r12,#0xfff
c00b56: shr r12,#0x2
c00b58: cmp r12,#0x66
c00b5c: jmpr cc_UGT,0xc00b98
c00b5e: mov 0xffbe,#0x9006
c00b62: mov r15,#0x0
c00b64: mov 0xf09c,r15
c00b68: mov 0xffa4,#0x59
c00b6c: bset 0xffbe.0x7
c00b6e: jnb 0xff98.0x7,0xc00b6e
c00b72: bclr 0xff98.0x7
c00b74: bclr 0xff9a.0x7
c00b76: mov r12,0xfea0
c00b7a: and r12,#0xfff
c00b7e: shr r12,#0x2
c00b80: cmp r12,#0x66
c00b84: jmpr cc_UGT,0xc00b98
c00b86: mov r12,#0x0
c00b88: mov r13,#0x0
c00b8a: mov r14,#0x0
c00b8c: einit
c00b90: calls 0xc002dc
c00b94: jmps 0xc003de
c00b98: mov 0xffbe,#0x9006
c00b9c: mov r15,#0x0
c00b9e: mov 0xf09c,r15
c00ba2: mov 0xffa4,#0x59
c00ba6: bset 0xffbe.0x7
c00ba8: jnb 0xff98.0x7,0xc00ba8
c00bac: bclr 0xff98.0x7
c00bae: bclr 0xff9a.0x7
c00bb0: mov r12,0xfea0
c00bb4: and r12,#0xfff
c00bb8: shr r12,#0x2
c00bba: cmp r12,#0x396
c00bbe: jmpr cc_ULE,0xc00c22
c00bc0: mov 0xffbe,#0x9004
c00bc4: mov r15,#0x0
c00bc6: mov 0xf09c,r15
c00bca: mov 0xffa4,#0x59
c00bce: bset 0xffbe.0x7
c00bd0: jnb 0xff98.0x7,0xc00bd0
c00bd4: bclr 0xff98.0x7
c00bd6: bclr 0xff9a.0x7
c00bd8: mov r12,0xfea0
c00bdc: and r12,#0xfff
c00be0: shr r12,#0x2
c00be2: cmp r12,#0x396
c00be6: jmpr cc_ULE,0xc00c22
c00be8: mov 0xffbe,#0x9005
c00bec: mov r15,#0x0
c00bee: mov 0xf09c,r15
c00bf2: mov 0xffa4,#0x59
c00bf6: bset 0xffbe.0x7
c00bf8: jnb 0xff98.0x7,0xc00bf8
c00bfc: bclr 0xff98.0x7
c00bfe: bclr 0xff9a.0x7
c00c00: mov r12,0xfea0
c00c04: and r12,#0xfff
c00c08: shr r12,#0x2
c00c0a: cmp r12,#0x14
c00c0e: jmpr cc_UGT,0xc00c22
c00c10: mov r12,#0x0
c00c12: mov r13,#0x0
c00c14: mov r14,#0x0
c00c16: einit
c00c1a: calls 0xc002dc
c00c1e: jmps 0xc003f0
c00c22: mov r12,#0x0
c00c24: mov r13,#0x0
c00c26: mov r14,#0x0
c00c28: einit
c00c2c: jmps 0xc00200


; ----------------------------------------------------------------------------
; boot_port_adc_init
; Address: 0xC00DAE
; Area:    bootloader
; Size:    44 bytes
; --------------------------------------------------------------------------
c00dae: mov 0xc080,0xff1e
c00db2: movb RL1,#0x2
c00db4: movb 0xc092,RL1
c00db8: movb 0xc091,0xff1c
c00dbc: movb 0xc090,0xff1c
c00dc0: movb RL2,#0x1f
c00dc4: movb 0xc08f,RL2
c00dc8: movb 0xc08e,0xff1c
c00dcc: movb 0xc08d,0xff1c
c00dd0: movb 0xc08c,0xff1c
c00dd4: calls 0xc00eca
c00dd8: rets


; ----------------------------------------------------------------------------
; boot_extint_init
; Address: 0xC00EE8
; Area:    bootloader
; Size:    36 bytes
; --------------------------------------------------------------------------
c00ee8: calls 0xc0030e
c00eec: extr #0x1
c00eee: mov 0xffda,#0x0
c00ef2: calls 0xc0030e
c00ef6: extr #0x1
c00ef8: mov 0xffd8,#0x0
c00efc: calls 0xc0030e
c00f00: extr #0x2
c00f02: mov 0xf1c0,#0x0
c00f06: mov 0xff9e,#0x44
c00f0a: rets


; ----------------------------------------------------------------------------
; trap_stack_overflow
; Address: 0xC00F0C
; Area:    bootloader
; Size:    94 bytes
; --------------------------------------------------------------------------
c00f0c: mov 0xfc80,r0
c00f10: scxt 0xfe10,#0xfc80
c00f14: push 0xfe00
c00f16: mov 0xfe00,#0x300
c00f1a: push 0xfe04
c00f1c: mov 0xfe04,#0x302
c00f20: push 0xffde
c00f22: push 0xfe5c
c00f24: push 0xfe5e
c00f26: push 0xffdc
c00f28: scxt 0xffda,#0x0
c00f2c: push 0xff08
c00f2e: push 0xff0a
c00f30: extr #0x4
c00f32: push 0xf000
c00f34: push 0xf002
c00f36: push 0xf004
c00f38: push 0xfe06
c00f3a: bclr 0xff10.0xb
c00f3c: mov r12,0xffac
c00f40: or 0xfdfe,r12
c00f44: bclr 0xffac.0xe
c00f46: srst
c00f4a: extr #0x4
c00f4c: pop 0xf006
c00f4e: pop 0xf004
c00f50: pop 0xf002
c00f52: pop 0xfe00
c00f54: pop 0xff0a
c00f56: pop 0xff08
c00f58: pop 0xffda
c00f5a: pop 0xffdc
c00f5c: pop 0xfe5e
c00f5e: pop 0xfe5c
c00f60: pop 0xffde
c00f62: pop 0xfe04
c00f64: pop 0xfe00
c00f66: pop 0xfe10
c00f68: reti


; ----------------------------------------------------------------------------
; trap_stack_underflow
; Address: 0xC00F6A
; Area:    bootloader
; Size:    94 bytes
; --------------------------------------------------------------------------
c00f6a: mov 0xfc80,r0
c00f6e: scxt 0xfe10,#0xfc80
c00f72: push 0xfe00
c00f74: mov 0xfe00,#0x300
c00f78: push 0xfe04
c00f7a: mov 0xfe04,#0x302
c00f7e: push 0xffde
c00f80: push 0xfe5c
c00f82: push 0xfe5e
c00f84: push 0xffdc
c00f86: scxt 0xffda,#0x0
c00f8a: push 0xff08
c00f8c: push 0xff0a
c00f8e: extr #0x4
c00f90: push 0xf000
c00f92: push 0xf002
c00f94: push 0xf004
c00f96: push 0xfe06
c00f98: bclr 0xff10.0xb
c00f9a: mov r12,0xffac
c00f9e: or 0xfdfe,r12
c00fa2: bclr 0xffac.0xd
c00fa4: srst
c00fa8: extr #0x4
c00faa: pop 0xf006
c00fac: pop 0xf004
c00fae: pop 0xf002
c00fb0: pop 0xfe00
c00fb2: pop 0xff0a
c00fb4: pop 0xff08
c00fb6: pop 0xffda
c00fb8: pop 0xffdc
c00fba: pop 0xfe5e
c00fbc: pop 0xfe5c
c00fbe: pop 0xffde
c00fc0: pop 0xfe04
c00fc2: pop 0xfe00
c00fc4: pop 0xfe10
c00fc6: reti


; ----------------------------------------------------------------------------
; trap_bootstrap
; Address: 0xC00FC8
; Area:    bootloader
; Size:    128 bytes
; --------------------------------------------------------------------------
c00fc8: mov 0xfc80,r0
c00fcc: scxt 0xfe10,#0xfc80
c00fd0: push 0xfe00
c00fd2: mov 0xfe00,#0x300
c00fd6: push 0xfe04
c00fd8: mov 0xfe04,#0x302
c00fdc: push 0xffde
c00fde: push 0xfe5c
c00fe0: push 0xfe5e
c00fe2: push 0xffdc
c00fe4: scxt 0xffda,#0x0
c00fe8: push 0xff08
c00fea: push 0xff0a
c00fec: extr #0x4
c00fee: push 0xf000
c00ff0: push 0xf002
c00ff2: push 0xf004
c00ff4: push 0xfe06
c00ff6: bclr 0xff10.0xb
c00ff8: mov r12,0xffac
c00ffc: or 0xfdfe,r12
c01000: jnb 0xffac.0x7,0xc01006
c01004: bclr 0xffac.0x7
c01006: jnb 0xffac.0x4,0xc01018
c0100a: bclr 0xffac.0x4
c0100c: extp 0x3ff, #0x1
c01010: mov r12,0x3000
c01014: or 0xfdfc,r12
c01018: jnb 0xffac.0x3,0xc0101e
c0101c: bclr 0xffac.0x3
c0101e: jnb 0xffac.0x2,0xc01024
c01022: bclr 0xffac.0x2
c01024: srst
c01028: extr #0x4
c0102a: pop 0xf006
c0102c: pop 0xf004
c0102e: pop 0xf002
c01030: pop 0xfe00
c01032: pop 0xff0a
c01034: pop 0xff08
c01036: pop 0xffda
c01038: pop 0xffdc
c0103a: pop 0xfe5e
c0103c: pop 0xfe5c
c0103e: pop 0xffde
c01040: pop 0xfe04
c01042: pop 0xfe00
c01044: pop 0xfe10
c01046: reti


; ----------------------------------------------------------------------------
; can_bootloader_wait
; Address: 0xC01AD4
; Area:    bootloader
; Size:    78 bytes
; --------------------------------------------------------------------------
c01ad4: sub r0,#0x8
c01ad8: calls 0xc019d6
c01adc: mov r12,#0x2000
c01ae0: mov r13,#0xc0
c01ae4: mov [r0],r12
c01ae6: mov [r0+#0x2],r13
c01aea: mov r14,#0x4
c01aec: mov [-r0],r14
c01aee: mov r15,#0x6
c01af0: add r15,r0
c01af2: mov r4,r15
c01af4: calls 0xc01eea
c01af8: mov r12,r4
c01afa: mov r13,r5
c01afc: mov r15,#0x2
c01afe: add r15,r0
c01b00: mov r4,r15
c01b02: calls 0xc01eea
c01b06: mov r14,r4
c01b08: mov r15,r5
c01b0a: calls 0xc01d9a
c01b0e: add r0,#0x2
c01b10: srvwdt
c01b14: mov r4,[r0+#0x4]
c01b18: mov r5,[r0+#0x6]
c01b1c: calls 0xc01ec8
c01b20: jmpr cc_UC,0xc01b20

