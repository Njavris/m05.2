; c24592 gap_c24592 size=32
c24592  shl r12,#0x1
c24594  mov r13,[r12+#0x7286]
c24598  mov r12,r13
c2459a  cmp r12,#0xffff
c2459e  jmpr cc_EQ,0xc245ac
c245a0  shl r12,#0x1
c245a2  mov r13,[r12+#0xc168]
c245a6  and r13,#0x1
c245a8  mov r1,r13
c245aa  jmpr cc_UC,0xc245ae
c245ac  movb RL1,#0x0
c245ae  movb RL4,RL1
c245b0  rets
