; c0db90 cc_irq_enable_bit size=22
c0db90  mov r1,r12
c0db92  cmpb RL1,#0x10
c0db96  jmpa cc_NE,0xc0dba0
c0db9a  or 0xfe2a,#0x1
c0db9e  rets
c0dba0  or 0xfe2a,#0x2
c0dba4  rets
