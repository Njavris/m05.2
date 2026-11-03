; c26a6a gap_c26a6a size=52
c26a6a  movb RL1,0xcc83
c26a6e  cmpb RL1,#0x1
c26a70  jmpr cc_NE,0xc26a94
c26a72  extp 0x380, #0x1
c26a76  mov r12,0x8ea
c26a7a  mov r13,0xc890
c26a7e  extp 0x301, #0x1
c26a82  mov r14,0x3e1c
c26a86  calls 0xc1596e
c26a8a  extp 0x380, #0x1
c26a8e  mov 0x8ea,r4
c26a92  rets
c26a94  extp 0x380, #0x1
c26a98  mov 0x8ea,0xff1c
c26a9c  rets
