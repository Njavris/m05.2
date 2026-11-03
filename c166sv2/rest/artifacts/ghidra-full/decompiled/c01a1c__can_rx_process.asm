; c01a1c can_rx_process size=184
c01a1c  extp 0x80, #0x1
c01a20  mov r12,0x284
c01a24  jnb r12.0xa,0xc01a4e
c01a28  extp 0x80, #0x1
c01a2c  mov r13,0x450
c01a30  jnb r13.0x1,0xc01a84
c01a34  extp 0x80, #0x1
c01a38  mov r14,0x450
c01a3c  shr r14,#0x8
c01a3e  and r14,#0x3
c01a40  mov r1,r14
c01a42  cmpb RL1,#0x2
c01a44  jmpr cc_NE,0xc01a84
c01a46  mov r14,#0xa
c01a48  mov 0xc1d2,r14
c01a4c  jmpr cc_UC,0xc01a84
c01a4e  extp 0x80, #0x1
c01a52  mov r12,0x284
c01a56  jnb r12.0x9,0xc01a80
c01a5a  extp 0x80, #0x1
c01a5e  mov r13,0x430
c01a62  jnb r13.0x1,0xc01a84
c01a66  extp 0x80, #0x1
c01a6a  mov r14,0x430
c01a6e  shr r14,#0x8
c01a70  and r14,#0x3
c01a72  mov r1,r14
c01a74  cmpb RL1,#0x2
c01a76  jmpr cc_NE,0xc01a84
c01a78  mov r14,#0x9
c01a7a  mov 0xc1d2,r14
c01a7e  jmpr cc_UC,0xc01a84
c01a80  mov 0xc1d2,0xff1c
c01a84  srvwdt
c01a88  mov r12,0xc1d2
c01a8c  jmpr cc_EQ,0xc01ad2
c01a8e  movb RL1,#0x0
c01a90  mov r12,0xc1d2
c01a94  shl r12,#0x5
c01a96  movbz r13,RL1
c01a98  add r13,r12
c01a9a  mov r12,#0x300
c01a9e  add r12,r13
c01aa0  mov r14,#0x80
c01aa4  extp r14, #0x1
c01aa6  movb RL2,[r12]
c01aa8  movbz r12,RL1
c01aaa  mov r13,#0x3740
c01aae  add r13,r12
c01ab0  mov r14,#0x3
c01ab2  extp r14, #0x1
c01ab4  movb [r13],RL2
c01ab6  addb RL1,#0x1
c01ab8  cmpb RL1,#0x8
c01abc  jmpr cc_C,0xc01a90
c01abe  calls 0xc01b22
c01ac2  mov r12,#0x5599
c01ac6  extp 0x80, #0x2
c01aca  mov 0x450,r12
c01ace  mov 0x430,r12
c01ad2  rets
