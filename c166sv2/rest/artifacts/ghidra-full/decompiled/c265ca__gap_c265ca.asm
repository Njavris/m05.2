; c265ca gap_c265ca size=36
c265ca  mov r12,#0x21
c265ce  calls 0xc243a8
c265d2  cmpb RL4,#0x0
c265d4  jmpr cc_NE,0xc265e2
c265d6  mov r12,#0x22
c265da  calls 0xc243a8
c265de  cmpb RL4,#0x0
c265e0  jmpr cc_EQ,0xc265e6
c265e2  movb RL1,#0x1
c265e4  jmpr cc_UC,0xc265e8
c265e6  movb RL1,#0x0
c265e8  movb 0xcc58,RL1
c265ec  rets
