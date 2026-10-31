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
