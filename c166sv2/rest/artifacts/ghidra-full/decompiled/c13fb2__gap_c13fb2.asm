; c13fb2 gap_c13fb2 size=48
c13fb2  mov r13,#0x0
c13fb4  mov r1,r12
c13fb6  cmpb RL1,#0x0
c13fb8  jmpr cc_NE,0xc13fcc
c13fba  mov r12,0xfd10
c13fbe  jnb r12.0x2,0xc13fde
c13fc2  mov r12,0xfd10
c13fc6  jnb r12.0x1,0xc13fde
c13fca  jmpr cc_UC,0xc13fdc
c13fcc  mov r12,0xfd0c
c13fd0  jnb r12.0x2,0xc13fde
c13fd4  mov r12,0xfd0c
c13fd8  jnb r12.0x1,0xc13fde
c13fdc  mov r13,#0x1
c13fde  mov r4,r13
c13fe0  rets
