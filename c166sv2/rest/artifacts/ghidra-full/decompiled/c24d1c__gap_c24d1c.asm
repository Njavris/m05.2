; c24d1c gap_c24d1c size=36
c24d1c  mov r1,[r0+#0x2]
c24d20  mov r2,[r0]
c24d22  cmp r12,r14
c24d24  jmpr cc_C,0xc24d2c
c24d26  movb RL3,#0x1
c24d28  movb [r1],RL3
c24d2a  jmpr cc_UC,0xc24d34
c24d2c  cmp r13,r15
c24d2e  jmpr cc_C,0xc24d3a
c24d30  movb RL3,#0x0
c24d32  movb [r1],RL3
c24d34  movb RL1,#0x1
c24d36  movb [r2],RL1
c24d38  rets
c24d3a  movb RL1,#0x0
c24d3c  movb [r2],RL1
c24d3e  rets
