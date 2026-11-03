; c12c0a gap_c12c0a size=40
c12c0a  movb 0xc594,[r0]
c12c0e  movb RL1,0xc594
c12c12  cmpb RL1,#0xf0
c12c16  jmpr cc_EQ,0xc12c24
c12c18  cmpb RL1,#0xf1
c12c1c  jmpr cc_EQ,0xc12c24
c12c1e  cmpb RL1,#0xc1
c12c22  jmpr cc_NE,0xc12c9e
c12c24  movb RL1,0xc578
c12c28  jmpr cc_NE,0xc12c40
c12c2a  mov r12,#0x3
c12c2c  mov 0xc574,r12
c12c30  jmpr cc_UC,0xc12cb0
