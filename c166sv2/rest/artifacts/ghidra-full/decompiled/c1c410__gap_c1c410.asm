; c1c410 gap_c1c410 size=22
c1c410  movb RL1,0xc9b0
c1c414  jmpr cc_EQ,0xc1c424
c1c416  mov r12,0xc06e
c1c41a  cmp r12,#0xffff
c1c41e  jmpr cc_NC,0xc1c424
c1c420  sub 0xc06e,0xff1e
c1c424  rets
