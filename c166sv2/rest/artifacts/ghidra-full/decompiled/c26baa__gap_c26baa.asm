; c26baa gap_c26baa size=64
c26baa  mov [-r0],r9
c26bac  mov [-r0],r8
c26bae  mov r9,#0xcc7e
c26bb2  mov r8,#0x7a9c
c26bb6  jmpr cc_UC,0xc26bd4
c26bb8  mov r12,[r8]
c26bba  calls 0xc24530
c26bbe  cmpb RL4,#0x0
c26bc0  jmpr cc_EQ,0xc26bd2
c26bc2  mov r12,[r8]
c26bc4  calls 0xc24e0a
c26bc8  cmpb RL4,#0x0
c26bca  jmpr cc_NE,0xc26bd2
c26bcc  movb RL1,#0x1
c26bce  movb [r9],RL1
c26bd0  jmpr cc_UC,0xc26be0
c26bd2  add r8,#0x2
c26bd4  mov r12,[r8]
c26bd6  cmp r12,#0x27
c26bda  jmpr cc_SLT,0xc26bb8
c26bdc  movb RL1,#0x0
c26bde  movb [r9],RL1
c26be0  calls 0xc26a3a
c26be4  mov r8,[r0+]
c26be6  mov r9,[r0+]
c26be8  rets
