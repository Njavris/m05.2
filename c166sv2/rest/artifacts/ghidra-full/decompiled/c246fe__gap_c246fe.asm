; c246fe gap_c246fe size=34
c246fe  shl r12,#0x1
c24700  mov r13,[r12+#0x7286]
c24704  mov r12,r13
c24706  cmp r12,#0xffff
c2470a  jmpr cc_EQ,0xc2471a
c2470c  shl r12,#0x1
c2470e  mov r13,[r12+#0xc168]
c24712  shr r13,#0xc
c24714  and r13,#0x1
c24716  mov r1,r13
c24718  jmpr cc_UC,0xc2471c
c2471a  movb RL1,#0x0
c2471c  movb RL4,RL1
c2471e  rets
