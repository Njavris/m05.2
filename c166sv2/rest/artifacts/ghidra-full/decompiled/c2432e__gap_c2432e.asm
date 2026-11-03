; c2432e gap_c2432e size=34
c2432e  shl r12,#0x1
c24330  mov r13,[r12+#0x7286]
c24334  mov r12,r13
c24336  cmp r12,#0xffff
c2433a  jmpr cc_EQ,0xc2434a
c2433c  shl r12,#0x1
c2433e  mov r13,[r12+#0xc168]
c24342  shr r13,#0x6
c24344  and r13,#0x3
c24346  mov r1,r13
c24348  jmpr cc_UC,0xc2434c
c2434a  movb RL1,#0x0
c2434c  movb RL4,RL1
c2434e  rets
