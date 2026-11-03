; c26a3a gap_c26a3a size=48
c26a3a  extp 0x301, #0x1
c26a3e  movb RL1,0x3e1a
c26a42  jmpr cc_NE,0xc26a64
c26a44  movb RL2,0xc848
c26a48  jmpr cc_NE,0xc26a5c
c26a4a  movb RL3,0xc912
c26a4e  jmpr cc_NE,0xc26a5c
c26a50  movb RL4,0xc90a
c26a54  jmpr cc_NE,0xc26a5c
c26a56  movb RL5,0xc90e
c26a5a  jmpr cc_EQ,0xc26a64
c26a5c  movb RL1,#0x1
c26a5e  movb 0xcc80,RL1
c26a62  rets
c26a64  movb 0xcc80,0xff1c
c26a68  rets
