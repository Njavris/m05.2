; c26586 gap_c26586 size=36
c26586  mov r12,#0x10
c2658a  calls 0xc243a8
c2658e  cmpb RL4,#0x0
c26590  jmpr cc_NE,0xc2659e
c26592  mov r12,#0x11
c26596  calls 0xc243a8
c2659a  cmpb RL4,#0x0
c2659c  jmpr cc_EQ,0xc265a2
c2659e  movb RL1,#0x1
c265a0  jmpr cc_UC,0xc265a4
c265a2  movb RL1,#0x0
c265a4  movb 0xcc54,RL1
c265a8  rets
