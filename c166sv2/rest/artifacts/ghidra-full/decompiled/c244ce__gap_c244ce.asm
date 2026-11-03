; c244ce gap_c244ce size=34
c244ce  shl r12,#0x1
c244d0  mov r13,[r12+#0x7286]
c244d4  mov r12,r13
c244d6  cmp r12,#0xffff
c244da  jmpr cc_EQ,0xc244ea
c244dc  shl r12,#0x1
c244de  mov r13,[r12+#0xc168]
c244e2  shr r13,#0x2
c244e4  and r13,#0x1
c244e6  mov r1,r13
c244e8  jmpr cc_UC,0xc244ec
c244ea  movb RL1,#0x0
c244ec  movb RL4,RL1
c244ee  rets
