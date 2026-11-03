; c284d8 axis16_signed size=54
c284d8  mov r14,[r12+#0x2]
c284dc  mov r15,[r12+#0x4]
c284e0  mov r1,[r12]
c284e2  sub r1,#0x1
c284e4  shl r1,#0x8
c284e6  mov r12,r1
c284e8  cmp r13,r14
c284ea  jmpr cc_SGT,0xc284f0
c284ec  mov r4,#0x0
c284ee  jmpr cc_UC,0xc2850c
c284f0  cmp r13,r15
c284f2  jmpr cc_SLT,0xc284f8
c284f4  mov r4,r12
c284f6  jmpr cc_UC,0xc2850c
c284f8  sub r13,r14
c284fa  mulu r13,r12
c284fc  sub r15,r14
c284fe  mov r1,0xfe0c
c28502  mov r13,0xfe0e
c28506  divlu r15
c28508  mov r4,0xfe0e
c2850c  rets
