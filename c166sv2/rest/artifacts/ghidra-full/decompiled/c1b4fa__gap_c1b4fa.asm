; c1b4fa gap_c1b4fa size=260
c1b4fa  movb RL1,0xc93c
c1b4fe  cmpb RL1,#0x3
c1b500  jmpr cc_EQ,0xc1b546
c1b502  mov r12,0xc936
c1b506  extp 0x301, #0x1
c1b50a  cmp r12,0x2c3c
c1b50e  jmpr cc_SGE,0xc1b51e
c1b510  extp 0x301, #0x1
c1b514  movb RL2,0x2c42
c1b518  movb 0xc93f,RL2
c1b51c  jmpr cc_UC,0xc1b546
c1b51e  mov r12,0xc936
c1b522  extp 0x301, #0x1
c1b526  cmp r12,0x2c3e
c1b52a  jmpr cc_SGE,0xc1b53a
c1b52c  extp 0x301, #0x1
c1b530  movb RL1,0x2c43
c1b534  movb 0xc93f,RL1
c1b538  jmpr cc_UC,0xc1b546
c1b53a  extp 0x301, #0x1
c1b53e  movb RL1,0x2c3a
c1b542  movb 0xc93f,RL1
c1b546  movb RL1,0xc93c
c1b54a  cmpb RL1,#0x2
c1b54c  jmpr cc_NE,0xc1b578
c1b54e  mov r12,0xc9d0
c1b552  extp 0x301, #0x1
c1b556  cmp r12,0x2c34
c1b55a  jmpr cc_C,0xc1b578
c1b55c  movb RL2,#0x2
c1b55e  movb 0xc93b,RL2
c1b562  movb RL3,0xc938
c1b566  cmpb RL3,0xc93f
c1b56a  jmpr cc_C,0xc1b580
c1b56c  movb RL4,#0x1
c1b56e  movb 0xc943,RL4
c1b572  movb 0xc93b,RL4
c1b576  jmpr cc_UC,0xc1b580
c1b578  movb 0xc943,0xff1c
c1b57c  movb 0xc93b,0xff1c
c1b580  movb RL1,0xc93c
c1b584  cmpb RL1,#0x2
c1b586  jmpr cc_NE,0xc1b59a
c1b588  mov r12,0xc9d0
c1b58c  cmp r12,#0xf0
c1b590  jmpr cc_UGT,0xc1b59a
c1b592  movb RL2,#0x1
c1b594  movb 0xc944,RL2
c1b598  jmpr cc_UC,0xc1b59e
c1b59a  movb 0xc944,0xff1c
c1b59e  movb RL1,0xc93c
c1b5a2  cmpb RL1,#0x3
c1b5a4  jmpr cc_NE,0xc1b5bc
c1b5a6  mov r12,0xc9d0
c1b5aa  extp 0x301, #0x1
c1b5ae  cmp r12,0x2c36
c1b5b2  jmpr cc_UGT,0xc1b5bc
c1b5b4  movb RL2,#0x1
c1b5b6  movb 0xc948,RL2
c1b5ba  jmpr cc_UC,0xc1b5c0
c1b5bc  movb 0xc948,0xff1c
c1b5c0  movb RL1,0xc93c
c1b5c4  cmpb RL1,#0x4
c1b5c6  jmpr cc_NE,0xc1b5da
c1b5c8  mov r12,0xc9d0
c1b5cc  cmp r12,#0xf0
c1b5d0  jmpr cc_ULE,0xc1b5da
c1b5d2  movb RL2,#0x1
c1b5d4  movb 0xc93e,RL2
c1b5d8  jmpr cc_UC,0xc1b5de
c1b5da  movb 0xc93e,0xff1c
c1b5de  movb RL1,0xc93c
c1b5e2  cmpb RL1,#0x1
c1b5e4  jmpr cc_NE,0xc1b5f8
c1b5e6  mov r12,0xc9d0
c1b5ea  cmp r12,#0xf0
c1b5ee  jmpr cc_ULE,0xc1b5f8
c1b5f0  movb RL2,#0x1
c1b5f2  movb 0xc939,RL2
c1b5f6  rets
c1b5f8  movb 0xc939,0xff1c
c1b5fc  rets
