; c25a7c gap_c25a7c size=28
c25a7c  shl r12,#0x2
c25a7e  mov r13,[r12+#0x71ea]
c25a82  mov r14,[r12+#0x71ec]
c25a86  exts r14, #0x1
c25a88  mov r12,[r13]
c25a8a  jnb r12.0x4,0xc25a92
c25a8e  movb RL1,#0x1
c25a90  jmpr cc_UC,0xc25a94
c25a92  movb RL1,#0x0
c25a94  movb RL4,RL1
c25a96  rets
