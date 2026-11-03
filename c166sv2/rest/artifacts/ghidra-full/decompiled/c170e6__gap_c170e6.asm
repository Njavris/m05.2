; c170e6 gap_c170e6 size=140
c170e6  movb RL1,0xc93c
c170ea  cmpb RL1,#0x3
c170ec  jmpr cc_NE,0xc1716c
c170ee  movb RL2,0xc77e
c170f2  jmpr cc_NE,0xc17134
c170f4  movb RL3,0xc81c
c170f8  jmpr cc_EQ,0xc1712c
c170fa  mov r12,0xc936
c170fe  extp 0x301, #0x1
c17102  cmp r12,0x219e
c17106  jmpr cc_SLE,0xc1712c
c17108  movb RL4,#0x1
c1710a  movb 0xc7f8,RL4
c1710e  mov 0xc7cc,0xff1c
c17112  mov r13,0xc7ca
c17116  extp 0x301, #0x1
c1711a  cmp r13,0x21a0
c1711e  jmpr cc_ULE,0xc17126
c17120  movb 0xc77e,RL4
c17124  jmpr cc_UC,0xc17130
c17126  movb 0xc77e,0xff1c
c1712a  jmpr cc_UC,0xc17134
c1712c  mov 0xc7ca,0xff1c
c17130  movb 0xc7f8,0xff1c
c17134  movb RL1,0xc77e
c17138  jmpr cc_EQ,0xc17162
c1713a  movb RL2,0xc81c
c1713e  jmpr cc_NE,0xc17162
c17140  movb RL3,#0x1
c17142  movb 0xc7f9,RL3
c17146  mov r12,0xc7cc
c1714a  extp 0x301, #0x1
c1714e  cmp r12,0x21a2
c17152  jmpr cc_ULE,0xc17170
c17154  movb 0xc77e,0xff1c
c17158  movb 0xc7f9,0xff1c
c1715c  mov 0xc7ca,0xff1c
c17160  rets
c17162  mov 0xc7cc,0xff1c
c17166  movb 0xc7f9,0xff1c
c1716a  rets
c1716c  movb 0xc77e,0xff1c
c17170  rets
