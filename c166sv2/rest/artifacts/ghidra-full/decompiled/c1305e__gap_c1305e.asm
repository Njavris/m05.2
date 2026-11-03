; c1305e gap_c1305e size=84
c1305e  mov r1,r12
c13060  cmpb RL1,#0x0
c13062  jmpr cc_EQ,0xc13076
c13064  cmpb RL1,#0x7
c13066  jmpr cc_EQ,0xc1307c
c13068  cmpb RL1,#0x80
c1306c  jmpr cc_EQ,0xc13082
c1306e  cmpb RL1,#0x81
c13072  jmpr cc_EQ,0xc13088
c13074  jmpr cc_UC,0xc130aa
c13076  movb RL1,#0x0
c13078  movb [r13],RL1
c1307a  rets
c1307c  movb RL1,#0x1
c1307e  movb [r13],RL1
c13080  jmpr cc_UC,0xc1308e
c13082  movb RL1,#0x2
c13084  movb [r13],RL1
c13086  jmpr cc_UC,0xc1308e
c13088  movb RL1,#0x82
c1308c  movb [r13],RL1
c1308e  mov [-r0],r15
c13090  mov [-r0],r14
c13092  calls 0xc13a84
c13096  mov r15,[r0+#0x2]
c1309a  mulu r4,r15
c1309c  mov r14,[r0+]
c1309e  add r0,#0x2
c130a0  mov r12,0xfe0e
c130a4  mov r1,r12
c130a6  movb [r14],RL1
c130a8  rets
c130aa  mov r12,#0x1
c130ac  calls 0xc13a92
c130b0  rets
