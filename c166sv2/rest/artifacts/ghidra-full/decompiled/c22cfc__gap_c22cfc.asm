; c22cfc gap_c22cfc size=166
c22cfc  extp 0x301, #0x1
c22d00  movb RL1,0x106c
c22d04  cmpb RL1,#0x2
c22d06  jmpr cc_NE,0xc22da0
c22d08  mov r12,#0x6
c22d0a  calls 0xc14cec
c22d0e  mov r12,0xc9d0
c22d12  extp 0x301, #0x1
c22d16  cmp r12,0x3cf2
c22d1a  jmpr cc_UGT,0xc22d26
c22d1c  extp 0x380, #0x1
c22d20  movb 0x8c8,0xff1c
c22d24  jmpr cc_UC,0xc22d3e
c22d26  mov r12,0xc9d0
c22d2a  extp 0x301, #0x1
c22d2e  cmp r12,0x3cf0
c22d32  jmpr cc_ULE,0xc22d3e
c22d34  movb RL1,#0x1
c22d36  extp 0x380, #0x1
c22d3a  movb 0x8c8,RL1
c22d3e  extp 0x380, #0x1
c22d42  movb RL1,0x8c8
c22d46  jmpr cc_EQ,0xc22d56
c22d48  extp 0x301, #0x1
c22d4c  movb RL2,0x3cf4
c22d50  cmpb RL2,#0x1
c22d52  jmpr cc_NE,0xc22d72
c22d54  jmpr cc_UC,0xc22d60
c22d56  extp 0x301, #0x1
c22d5a  movb RL1,0x3cf4
c22d5e  jmpr cc_NE,0xc22d72
c22d60  mov r12,#0x0
c22d62  mov r13,#0x8000
c22d66  mov r14,#0xf
c22d68  calls 0xc27b86
c22d6c  mov 0xc98c,r4
c22d70  jmpr cc_UC,0xc22d84
c22d72  mov r12,#0xffff
c22d76  mov r13,#0x8000
c22d7a  mov r14,#0xf
c22d7c  calls 0xc27b86
c22d80  mov 0xc98c,r4
c22d84  mov r12,#0x8000
c22d88  mov r13,0xc98c
c22d8c  calls 0xc28852
c22d90  mov 0xc98c,r4
c22d94  mov r12,#0x6
c22d96  mov r13,#0x40
c22d9a  mov r14,r4
c22d9c  calls 0xc14c70
c22da0  rets
