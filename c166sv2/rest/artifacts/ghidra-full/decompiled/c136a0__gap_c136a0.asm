; c136a0 gap_c136a0 size=86
c136a0  movb RL1,#0x1
c136a2  movbz r15,0xc5c4
c136a6  mov r3,r1
c136a8  movb RL1,#0x2
c136aa  movb RL2,[r15+#0xf63e]
c136ae  mov r15,r1
c136b0  mov r1,r3
c136b2  movbz r3,RL1
c136b4  movbz r1,0xc5c7
c136b8  add r1,r3
c136ba  movb [r1+#0xf63d],RL2
c136be  mov r1,r15
c136c0  movb RL2,#0x0
c136c2  jmpr cc_UC,0xc136e6
c136c4  movbz r15,RL2
c136c6  mov r3,#0x0
c136c8  mov r4,r12
c136ca  mov r5,r13
c136cc  add r4,r15
c136ce  addc r5,r3
c136d0  exts r5, #0x1
c136d2  movb RL4,[r4]
c136d4  movb RL5,RL1
c136d6  movbz r15,RL5
c136d8  movbz r5,0xc5c7
c136dc  add r5,r15
c136de  addb RL2,#0x1
c136e0  addb RL1,#0x1
c136e2  movb [r5+#0xf63d],RL4
c136e6  mov r3,r14
c136e8  cmpb RL2,RL3
c136ea  jmpr cc_C,0xc136c4
c136ec  mov r1,r1
c136ee  movbz r12,RL1
c136f0  calls 0xc12910
c136f4  rets
