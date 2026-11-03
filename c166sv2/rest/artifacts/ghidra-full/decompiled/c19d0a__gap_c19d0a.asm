; c19d0a gap_c19d0a size=36
c19d0a  movb RL1,0xc93c
c19d0e  cmpb RL1,#0x3
c19d10  jmpr cc_NE,0xc19d18
c19d12  movb RL2,#0x1
c19d14  movb 0xc8a2,RL2
c19d18  movb RL1,0xc8a2
c19d1c  jmpr cc_EQ,0xc19d2c
c19d1e  mov r12,0xc8a0
c19d22  cmp r12,#0xffff
c19d26  jmpr cc_NC,0xc19d2c
c19d28  sub 0xc8a0,0xff1e
c19d2c  rets
