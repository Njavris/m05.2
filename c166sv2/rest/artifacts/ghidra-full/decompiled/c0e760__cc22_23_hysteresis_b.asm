; c0e760 cc22_23_hysteresis_b size=106
c0e760  mov r13,0xc454
c0e764  jmpr cc_EQ,0xc0e774
c0e766  cmp r13,#0x1
c0e768  jmpr cc_EQ,0xc0e77c
c0e76a  cmp r13,#0x2
c0e76c  jmpr cc_EQ,0xc0e794
c0e76e  cmp r13,#0x3
c0e770  jmpr cc_EQ,0xc0e7b4
c0e772  jmpr cc_UC,0xc0e7c8
c0e774  cmp r12,#0x1c00
c0e778  jmpr cc_ULE,0xc0e7c8
c0e77a  jmpr cc_UC,0xc0e7c2
c0e77c  cmp r12,#0x1800
c0e780  jmpr cc_NC,0xc0e786
c0e782  mov 0xc454,0xff1c
c0e786  cmp r12,#0x5f00
c0e78a  jmpr cc_UGT,0xc0e7ba
c0e78c  mov r12,0xc450
c0e790  jmpr cc_EQ,0xc0e7c8
c0e792  jmpr cc_UC,0xc0e7ba
c0e794  cmp r12,#0x5a00
c0e798  jmpr cc_NC,0xc0e7a6
c0e79a  mov r13,0xc450
c0e79e  jmpr cc_NE,0xc0e7a6
c0e7a0  mov r14,#0x1
c0e7a2  mov 0xc454,r14
c0e7a6  cmp r12,#0x8400
c0e7aa  jmpr cc_ULE,0xc0e7c8
c0e7ac  mov r12,#0x3
c0e7ae  mov 0xc454,r12
c0e7b2  rets
c0e7b4  cmp r12,#0x8000
c0e7b8  jmpr cc_NC,0xc0e7c8
c0e7ba  mov r12,#0x2
c0e7bc  mov 0xc454,r12
c0e7c0  rets
c0e7c2  mov r12,#0x1
c0e7c4  mov 0xc454,r12
c0e7c8  rets
