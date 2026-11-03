; c127a2 gap_c127a2 size=92
c127a2  bclr 0xffb0.0x4
c127a4  mov r12,0xc57a
c127a8  jmpr cc_NE,0xc127d4
c127aa  extr #0x1
c127ac  jb 0xf19c.0x7,0xc127d4
c127b0  mov r13,0xc5a2
c127b4  cmp r13,#0x1
c127b6  jmpr cc_NE,0xc127c2
c127b8  mov 0xc5ac,0xff1c
c127bc  mov r14,#0xa
c127be  mov 0xc584,r14
c127c2  mov r12,0xc5a2
c127c6  jmpr cc_NE,0xc127fc
c127c8  mov 0xc59a,0xff1c
c127cc  mov r13,#0xb
c127ce  mov 0xc584,r13
c127d2  rets
c127d4  mov r12,0xc5be
c127d8  cmp r12,0xc586
c127dc  jmpr cc_NC,0xc127ec
c127de  mov r13,0xc5a2
c127e2  jmpr cc_NE,0xc127ec
c127e4  mov r14,#0xc
c127e6  mov 0xc584,r14
c127ea  rets
c127ec  movbz r12,0xc5b3
c127f0  calls 0xc11f5a
c127f4  movb RL1,0xc5b3
c127f8  addb 0xc5a4,RL1
c127fc  rets
