; c102dc gap_c102dc size=102
c102dc  subb 0xc4aa,0xff1e
c102e0  movb RL1,0xc4aa
c102e4  andb RL1,#0xf
c102e8  cmpb RL1,#0x1
c102ea  jmpr cc_NE,0xc102f4
c102ec  bclr 0xff04.0x6
c102ee  movb RL2,#0x1
c102f0  movb 0xc4b4,RL2
c102f4  cmpb RL1,#0x5
c102f6  jmpr cc_NE,0xc10316
c102f8  mov r12,0xc4a4
c102fc  jnb r12.0xb,0xc10306
c10300  subb 0xc49e,0xff1e
c10304  jmpr cc_UC,0xc10316
c10306  mov r12,#0xf7ff
c1030a  and 0xc4a4,r12
c1030e  mov r12,#0x200
c10312  or 0xc4ba,r12
c10316  movb RL1,0xc4aa
c1031a  cmpb RL1,#0x7f
c1031e  jmpr cc_NE,0xc10340
c10320  movb 0xc4aa,0xff1e
c10324  movbz r12,0xc49e
c10328  cmp r12,#0x6
c1032a  jmpr cc_SLE,0xc1033c
c1032c  extr #0x1
c1032e  bclr 0xf104.0x6
c10330  bset 0xff04.0x6
c10332  movb RL1,#0x55
c10336  movb 0xc4b4,RL1
c1033a  rets
c1033c  movb 0xc4b4,0xff1c
c10340  rets
