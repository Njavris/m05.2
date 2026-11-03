; c24cb4 gap_c24cb4 size=40
c24cb4  mov r1,[r0]
c24cb6  mov r2,r12
c24cb8  cmpb RL2,#0x0
c24cba  jmpr cc_EQ,0xc24cc2
c24cbc  mov r12,#0x0
c24cbe  mov [r15],r12
c24cc0  mov [r1],r12
c24cc2  mov r2,r13
c24cc4  cmpb RL2,#0x0
c24cc6  jmpr cc_EQ,0xc24cda
c24cc8  mov r12,[r1]
c24cca  add r12,#0x1
c24ccc  mov [r1],r12
c24cce  mov r1,r14
c24cd0  cmpb RL1,#0x0
c24cd2  jmpr cc_EQ,0xc24cda
c24cd4  mov r12,[r15]
c24cd6  add r12,#0x1
c24cd8  mov [r15],r12
c24cda  rets
