; c24fd8 gap_c24fd8 size=32
c24fd8  mov r15,#0x0
c24fda  jmpr cc_UC,0xc24fe4
c24fdc  mov r1,[r12+]
c24fde  cmp r1,r14
c24fe0  jmpr cc_EQ,0xc24ff4
c24fe2  add r15,#0x1
c24fe4  mov r1,[r12]
c24fe6  cmp r1,#0xb
c24fea  jmpr cc_EQ,0xc24ff0
c24fec  cmp r15,r13
c24fee  jmpr cc_C,0xc24fdc
c24ff0  mov r15,#0xffff
c24ff4  mov r4,r15
c24ff6  rets
