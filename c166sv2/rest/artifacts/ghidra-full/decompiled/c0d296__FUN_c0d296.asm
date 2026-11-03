; c0d296 FUN_c0d296 size=78
c0d296  mov r12,#0x1f16
c0d29a  mov r13,#0xc1
c0d29e  mov 0xc20c,r12
c0d2a2  mov 0xc20e,r13
c0d2a6  movb RL1,0xc92f
c0d2aa  jmpr cc_EQ,0xc0d2c8
c0d2ac  mov r14,#0xc282
c0d2b0  extp 0x301, #0x1
c0d2b4  movb RL2,0x1084
c0d2b8  movbz r15,RL2
c0d2ba  shl r15,#0x1
c0d2bc  add r14,r15
c0d2be  mov r15,[r14]
c0d2c0  bfldh r15,#0x40,#0x40
c0d2c4  mov [r14],r15
c0d2c6  rets
c0d2c8  mov r12,#0xc282
c0d2cc  extp 0x301, #0x1
c0d2d0  movb RL1,0x1085
c0d2d4  movbz r13,RL1
c0d2d6  shl r13,#0x1
c0d2d8  add r12,r13
c0d2da  mov r13,[r12]
c0d2dc  bfldh r13,#0x40,#0x40
c0d2e0  mov [r12],r13
c0d2e2  rets
