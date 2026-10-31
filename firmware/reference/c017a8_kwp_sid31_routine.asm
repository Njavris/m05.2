c017a8: movb RL1,0xc09a
c017ac: cmpb RL1,#0x1
c017ae: jmpr cc_NE,0xc017ca
c017b0: movb RL2,#0x1
c017b2: movb 0xc09b,RL2
c017b6: movb RL3,#0x2
c017b8: movb 0xc0b5,RL3
c017bc: movb RL4,#0x71
c017c0: movb 0xc0b6,RL4
c017c4: movb 0xc0b7,RL3
c017c8: rets
c017ca: movb RL1,#0x3
c017cc: movb 0xc0b5,RL1
c017d0: movb RL2,#0x7f
c017d4: movb 0xc0b6,RL2
c017d8: movb RL3,#0x31
c017dc: movb 0xc0b7,RL3
c017e0: movb RL4,#0xbd
c017e4: movb 0xc0b8,RL4
c017e8: rets
