; c243a8 FUN_c243a8 size=34
c243a8  shl r12,#0x1
c243aa  mov r13,[r12+#0x7286]
c243ae  mov r12,r13
c243b0  cmp r12,#0xffff
c243b4  jmpr cc_EQ,0xc243c4
c243b6  shl r12,#0x1
c243b8  mov r13,[r12+#0xc168]
c243bc  shr r13,#0x5
c243be  and r13,#0x1
c243c0  mov r1,r13
c243c2  jmpr cc_UC,0xc243c6
c243c4  movb RL1,#0x0
c243c6  movb RL4,RL1
c243c8  rets
