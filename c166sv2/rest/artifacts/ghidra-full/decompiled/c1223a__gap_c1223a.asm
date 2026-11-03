; c1223a gap_c1223a size=40
c1223a  mov r12,0xc5c2
c1223e  jmpr cc_NE,0xc12244
c12240  movb RL1,#0x1
c12242  jmpr cc_UC,0xc12246
c12244  movb RL1,#0x0
c12246  cmpb RL1,#0x0
c12248  jmpr cc_EQ,0xc12258
c1224a  movb RL1,0xc578
c1224e  cmpb RL1,#0x1
c12250  jmpr cc_NE,0xc12258
c12252  calls 0xc12262
c12256  rets
c12258  mov r12,#0x12
c1225c  calls 0xc128ec
c12260  rets
