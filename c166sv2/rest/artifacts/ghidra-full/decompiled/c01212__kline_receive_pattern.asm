; c01212 kline_receive_pattern size=64
c011d8  calls 0xc00c8a
c011dc  mov r13,#0xc144
c011e0  movbz r12,0xc0ae
c011e4  add r13,r12
c011e6  movb [r13],RL4
c011e8  movb RL1,[r13]
c011ea  movb RL2,[r12+#0xc0a3]
c011ee  cmpb RL1,RL2
c011f0  jmpr cc_EQ,0xc011fa
c011f2  movb RL1,#0x1
c011f4  movb 0xc0af,RL1
c011f8  jmpr cc_UC,0xc01212
c011fa  movb RL1,0xc0ae
c011fe  cmpb RL1,#0x4
c01200  jmpr cc_NE,0xc0120e
c01202  subb 0xc0af,0xff1e
c01206  movb RL2,#0x1
c01208  movb 0xc1d1,RL2
c0120c  jmpr cc_UC,0xc01212
c0120e  subb 0xc0ae,0xff1e
c01212  jb 0xff6e.0x7,0xc011d8
c01216  rets
