; c0166a kwp_sid83 size=88
c0166a  movb RL1,0xc149
c0166e  jmpr cc_EQ,0xc01692
c01670  cmpb RL1,#0x3
c01672  jmpr cc_NE,0xc016c0
c01674  movb RL1,#0x82
c01678  movb 0xc0b2,RL1
c0167c  movb RL2,#0x2
c0167e  movb 0xc0b5,RL2
c01682  movb RL3,#0xc3
c01686  movb 0xc0b6,RL3
c0168a  movb RL4,#0x3
c0168c  movb 0xc0b7,RL4
c01690  rets
c01692  movb RL1,#0x87
c01696  movb 0xc0b2,RL1
c0169a  movb RL2,#0x7
c0169c  movb 0xc0b5,RL2
c016a0  movb RL3,#0xc3
c016a4  movb 0xc0b6,RL3
c016a8  movb 0xc0b7,0xff1c
c016ac  movb 0xc0b8,0xff1c
c016b0  movb 0xc0b9,0xff1e
c016b4  movb 0xc0ba,0xff1c
c016b8  movb 0xc0bb,0xff1e
c016bc  movb 0xc0bc,0xff1c
c016c0  rets
