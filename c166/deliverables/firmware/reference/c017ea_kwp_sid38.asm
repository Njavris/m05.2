c017ea: movb RL1,0xc09a
c017ee: cmpb RL1,#0x1
c017f0: jmpr cc_NE,0xc01820
c017f2: movb RL2,#0x1
c017f4: movb 0xc09b,RL2
c017f8: movb RL3,#0x4
c017fa: movb 0xc0b5,RL3
c017fe: movb RL4,#0x78
c01802: movb 0xc0b6,RL4
c01806: movb RL5,0xc149
c0180a: movb 0xc0b7,RL5
c0180e: movb RL1,0xc14a
c01812: movb 0xc0b8,RL1
c01816: movb RL1,0xc14b
c0181a: movb 0xc0b9,RL1
c0181e: rets
c01820: movb RL1,#0x3
c01822: movb 0xc0b5,RL1
c01826: movb RL2,#0x7f
c0182a: movb 0xc0b6,RL2
c0182e: movb RL3,#0x31
c01832: movb 0xc0b7,RL3
c01836: movb RL4,#0xbd
c0183a: movb 0xc0b8,RL4
c0183e: rets
