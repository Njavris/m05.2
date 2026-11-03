; c01218 asc0_state2_init size=58
c01218  mov [-r0],r12
c0121a  calls 0xc01182
c0121e  mov r12,[r0+]
c01220  mov r1,r12
c01222  cmpb RL1,#0x2
c01224  jmpr cc_NE,0xc0123e
c01226  movb RL1,#0x5e
c0122a  movb 0xc09e,RL1
c0122e  mov r12,#0x49fb
c01232  mov 0xc0a0,r12
c01236  movb RL2,#0x79
c0123a  movb 0xc0a2,RL2
c0123e  movb RL1,#0x3
c01240  movb 0xc0af,RL1
c01244  movb 0xc1d0,0xff1c
c01248  movb RL2,#0x1
c0124a  movb 0xc09a,RL2
c0124e  bset 0xffb0.0x4
c01250  rets
