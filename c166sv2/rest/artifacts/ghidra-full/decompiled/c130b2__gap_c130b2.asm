; c130b2 gap_c130b2 size=82
c130b2  mov r1,r12
c130b4  cmpb RL1,#0x0
c130b6  jmpr cc_EQ,0xc130ca
c130b8  cmpb RL1,#0x7
c130ba  jmpr cc_EQ,0xc130d0
c130bc  cmpb RL1,#0x80
c130c0  jmpr cc_EQ,0xc130d6
c130c2  cmpb RL1,#0x81
c130c6  jmpr cc_EQ,0xc130dc
c130c8  jmpr cc_UC,0xc130fc
c130ca  movb RL1,#0x0
c130cc  movb [r13],RL1
c130ce  rets
c130d0  movb RL1,#0x1
c130d2  movb [r13],RL1
c130d4  jmpr cc_UC,0xc130e2
c130d6  movb RL1,#0x2
c130d8  movb [r13],RL1
c130da  jmpr cc_UC,0xc130e2
c130dc  movb RL1,#0x82
c130e0  movb [r13],RL1
c130e2  mov [-r0],r15
c130e4  mov [-r0],r14
c130e6  calls 0xc13a84
c130ea  mov r15,[r0+#0x2]
c130ee  mulu r4,r15
c130f0  mov r14,[r0+]
c130f2  add r0,#0x2
c130f4  mov r12,0xfe0e
c130f8  mov [r14],r12
c130fa  rets
c130fc  mov r12,#0x1
c130fe  calls 0xc13a92
c13102  rets
