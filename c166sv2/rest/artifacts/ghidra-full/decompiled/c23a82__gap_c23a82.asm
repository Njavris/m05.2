; c23a82 gap_c23a82 size=20
c23a82  movb RL1,0xcb2d
c23a86  cmpb RL1,#0x10
c23a8a  jmpr cc_NE,0xc23a94
c23a8c  mov r12,0xc074
c23a90  mov 0xcb38,r12
c23a94  rets
