; c1acd6 gap_c1acd6 size=470
c1acd6  mov [-r0],r8
c1acd8  movb RL1,0xcc32
c1acdc  jmpa cc_NE,0xc1ae3a
c1ace0  movb RL2,0xca18
c1ace4  jmpa cc_NE,0xc1ae3a
c1ace8  movb 0xc926,0xff1c
c1acec  jb 0xfd02.0xb,0xc1acfc
c1acf0  mov r12,0xc9d0
c1acf4  cmp r12,#0x0
c1acf6  jmpr cc_UGT,0xc1acfc
c1acf8  jnb 0xfd02.0x9,0xc1ada2
c1acfc  calls 0xc1d39c
c1ad00  movb RL1,0xc93c
c1ad04  cmpb RL1,#0x3
c1ad06  jmpr cc_NE,0xc1ad72
c1ad08  movb RL2,0xc934
c1ad0c  jmpr cc_EQ,0xc1ad72
c1ad0e  mov r8,0xc9d0
c1ad12  extp 0x301, #0x1
c1ad16  cmp r8,0x2c52
c1ad1a  jmpr cc_UGT,0xc1ad72
c1ad1c  movb RL3,0xc9ea
c1ad20  jmpr cc_EQ,0xc1ad72
c1ad22  mov r12,0xc9ca
c1ad26  extp 0x301, #0x1
c1ad2a  cmp r12,0x2ccc
c1ad2e  jmpr cc_NC,0xc1ad72
c1ad30  extp 0x301, #0x1
c1ad34  movb RL4,0x107b
c1ad38  jmpr cc_NE,0xc1ad72
c1ad3a  movb RL5,#0x1
c1ad3c  movb 0xc91c,RL5
c1ad40  movb RL1,0xc920
c1ad44  jmpr cc_EQ,0xc1ad7a
c1ad46  movb 0xc920,0xff1c
c1ad4a  mov r12,0xc91e
c1ad4e  mov r13,0xc924
c1ad52  calls 0xc276a4
c1ad56  mov r12,r4
c1ad58  mov r8,r12
c1ad5a  mov r12,0xc06a
c1ad5e  mov r13,r8
c1ad60  extp 0x301, #0x1
c1ad64  mov r14,0x2c56
c1ad68  calls 0xc1596e
c1ad6c  mov 0xc06a,r4
c1ad70  jmpr cc_UC,0xc1ad7a
c1ad72  movb 0xc920,0xff1c
c1ad76  movb 0xc91c,0xff1c
c1ad7a  mov r12,#0x50dc
c1ad7e  mov r13,#0xc0
c1ad82  mov r14,0xc9d0
c1ad86  calls 0xc28544
c1ad8a  mov r12,r4
c1ad8c  mov r8,r12
c1ad8e  mov r12,#0x6ca4
c1ad92  mov r13,#0xc0
c1ad96  mov r14,r8
c1ad98  calls 0xc27fca
c1ad9c  mov 0xc922,r4
c1ada0  jmpr cc_UC,0xc1ae66
c1ada2  movb RL1,0xcc2c
c1ada6  jmpr cc_NE,0xc1ae26
c1ada8  calls 0xc1aeac
c1adac  mov r13,r4
c1adae  extp 0x380, #0x1
c1adb2  mov r12,0x824
c1adb6  calls 0xc27b10
c1adba  mov r8,r4
c1adbc  extp 0x380, #0x1
c1adc0  mov r12,0x828
c1adc4  jmpr cc_EQ,0xc1adda
c1adc6  extp 0x301, #0x1
c1adca  cmp r8,0x2cc2
c1adce  jmpr cc_ULE,0xc1ade6
c1add0  extp 0x380, #0x1
c1add4  mov 0x828,0xff1c
c1add8  jmpr cc_UC,0xc1adee
c1adda  calls 0xc1aeac
c1adde  extp 0x380, #0x1
c1ade2  mov 0x824,r4
c1ade6  extp 0x380, #0x1
c1adea  sub 0x828,0xff1e
c1adee  extp 0x380, #0x1
c1adf2  mov r8,0x828
c1adf6  extp 0x301, #0x1
c1adfa  cmp r8,0x2cd6
c1adfe  jmpr cc_ULE,0xc1ae66
c1ae00  mov r12,0xc06a
c1ae04  extp 0x380, #0x1
c1ae08  mov r13,0x824
c1ae0c  extp 0x301, #0x1
c1ae10  mov r14,0x2c54
c1ae14  calls 0xc1596e
c1ae18  mov 0xc06a,r4
c1ae1c  extp 0x380, #0x1
c1ae20  mov 0x828,0xff1c
c1ae24  jmpr cc_UC,0xc1ae66
c1ae26  extp 0x301, #0x1
c1ae2a  mov r8,0x2c50
c1ae2e  mov 0xc06a,r8
c1ae32  movb RL1,#0x1
c1ae34  movb 0xc926,RL1
c1ae38  jmpr cc_UC,0xc1ae66
c1ae3a  movb RL1,#0x1
c1ae3c  movb 0xc926,RL1
c1ae40  movb 0xc91c,0xff1c
c1ae44  movb RL2,0xc93c
c1ae48  cmpb RL2,#0x1
c1ae4a  jmpr cc_EQ,0xc1ae5a
c1ae4c  extp 0x380, #0x1
c1ae50  mov r8,0x826
c1ae54  mov 0xc06a,r8
c1ae58  jmpr cc_UC,0xc1ae66
c1ae5a  extp 0x301, #0x1
c1ae5e  mov r8,0x2c50
c1ae62  mov 0xc06a,r8
c1ae66  mov r8,0xc06a
c1ae6a  extp 0x301, #0x1
c1ae6e  cmp r8,0x2c5a
c1ae72  jmpr cc_ULE,0xc1ae78
c1ae74  mov r12,r8
c1ae76  jmpr cc_UC,0xc1ae80
c1ae78  extp 0x301, #0x1
c1ae7c  mov r12,0x2c5a
c1ae80  extp 0x301, #0x1
c1ae84  cmp r12,0x2c58
c1ae88  jmpr cc_ULE,0xc1ae98
c1ae8a  extp 0x301, #0x1
c1ae8e  mov r8,0x2c58
c1ae92  mov 0xc06a,r8
c1ae96  jmpr cc_UC,0xc1ae9c
c1ae98  mov 0xc06a,r12
c1ae9c  mov r8,0xc06a
c1aea0  extp 0x380, #0x1
c1aea4  mov 0x826,r8
c1aea8  mov r8,[r0+]
c1aeaa  rets
