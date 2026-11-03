; c0f0e6 FUN_c0f0e6 size=76
c0f0e6  mov r1,r13
c0f0e8  cmp r12,#0x0
c0f0ea  jmpr cc_NE,0xc0f0f8
c0f0ec  movbz r13,RL1
c0f0ee  shl r13,#0x1
c0f0f0  movb RL2,[r13+#0x700e]
c0f0f4  movb RL1,RL2
c0f0f6  jmpr cc_UC,0xc0f102
c0f0f8  movbz r13,RL1
c0f0fa  shl r13,#0x1
c0f0fc  movb RL2,[r13+#0xc468]
c0f100  movb RL1,RL2
c0f102  mov r14,#0x1a
c0f106  mulu r12,r14
c0f108  mov r13,#0xc3da
c0f10c  mov r12,0xfe0e
c0f110  add r13,r12
c0f112  movb RL2,#0x0
c0f114  movb [r13],RL2
c0f116  cmpb RL1,#0x0
c0f118  jmpr cc_ULE,0xc0f130
c0f11a  cmpb RL1,#0x3
c0f11c  jmpr cc_NC,0xc0f124
c0f11e  addb RL1,#0x3
c0f120  movb [r13],RL1
c0f122  rets
c0f124  cmpb RL1,#0x14
c0f128  jmpr cc_ULE,0xc0f130
c0f12a  subb RL1,#0x14
c0f12e  movb [r13],RL1
c0f130  rets
