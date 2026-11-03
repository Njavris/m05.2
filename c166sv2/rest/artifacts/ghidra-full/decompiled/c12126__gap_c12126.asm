; c12126 gap_c12126 size=40
c12126  mov r12,0xc5c2
c1212a  jmpr cc_NE,0xc12130
c1212c  movb RL1,#0x1
c1212e  jmpr cc_UC,0xc12132
c12130  movb RL1,#0x0
c12132  cmpb RL1,#0x0
c12134  jmpr cc_EQ,0xc12144
c12136  movb RL1,0xc578
c1213a  cmpb RL1,#0x1
c1213c  jmpr cc_NE,0xc12144
c1213e  calls 0xc1214e
c12142  rets
c12144  mov r12,#0x12
c12148  calls 0xc128ec
c1214c  rets
