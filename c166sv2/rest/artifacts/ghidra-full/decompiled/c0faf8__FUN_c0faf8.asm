; c0faf8 FUN_c0faf8 size=62
c0faf8  mov r13,#0x0
c0fafa  movb RL1,0xc456
c0fafe  cmpb RL1,#0x3
c0fb00  jmpr cc_EQ,0xc0fb08
c0fb02  cmpb RL1,#0x4
c0fb04  jmpa cc_NE,0xc0fb26
c0fb08  cmp r12,#0x0
c0fb0a  jmpa cc_NE,0xc0fb16
c0fb0e  extr #0x1
c0fb10  bset 0xf16e.0x6
c0fb12  jmpa cc_UC,0xc0fb20
c0fb16  cmp r12,#0x1
c0fb18  jmpa cc_NE,0xc0fb20
c0fb1c  extr #0x1
c0fb1e  bset 0xf16c.0x6
c0fb20  mov r13,#0x1
c0fb22  subb 0xc456,0xff1e
c0fb26  movb RL1,0xc456
c0fb2a  cmpb RL1,#0x5
c0fb2c  jmpr cc_NE,0xc0fb32
c0fb2e  movb 0xc456,0xff1c
c0fb32  mov r4,r13
c0fb34  rets
