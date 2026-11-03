; c265aa gap_c265aa size=32
c265aa  mov r12,#0xe
c265ac  calls 0xc243a8
c265b0  cmpb RL4,#0x0
c265b2  jmpr cc_NE,0xc265be
c265b4  mov r12,#0xf
c265b6  calls 0xc243a8
c265ba  cmpb RL4,#0x0
c265bc  jmpr cc_EQ,0xc265c2
c265be  movb RL1,#0x1
c265c0  jmpr cc_UC,0xc265c4
c265c2  movb RL1,#0x0
c265c4  movb 0xcc56,RL1
c265c8  rets
