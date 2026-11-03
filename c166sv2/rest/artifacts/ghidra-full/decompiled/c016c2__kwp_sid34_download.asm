; c016c2 kwp_sid34_download size=72
c016c2  movb RL1,0xc09a
c016c6  cmpb RL1,#0x1
c016c8  jmpr cc_NE,0xc016ea
c016ca  movb RL2,#0x82
c016ce  movb 0xc0b2,RL2
c016d2  movb RL3,#0x2
c016d4  movb 0xc0b5,RL3
c016d8  movb RL4,#0x74
c016dc  movb 0xc0b6,RL4
c016e0  movb RL5,#0xfb
c016e4  movb 0xc0b7,RL5
c016e8  rets
c016ea  movb RL1,#0x3
c016ec  movb 0xc0b5,RL1
c016f0  movb RL2,#0x7f
c016f4  movb 0xc0b6,RL2
c016f8  movb RL3,#0x10
c016fc  movb 0xc0b7,RL3
c01700  movb RL4,#0x33
c01704  movb 0xc0b8,RL4
c01708  rets
