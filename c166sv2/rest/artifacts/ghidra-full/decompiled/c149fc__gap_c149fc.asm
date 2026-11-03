; c149fc gap_c149fc size=32
c149fc  mov [-r0],r6
c149fe  movb RL6,#0x0
c14a00  mov r13,#0x0
c14a02  calls 0xc117d8
c14a06  mov r12,r4
c14a08  cmp r12,#0x2
c14a0a  jmpr cc_EQ,0xc14a14
c14a0c  cmp r12,#0x1
c14a0e  jmpr cc_NE,0xc14a16
c14a10  movb RL6,#0x1
c14a12  jmpr cc_UC,0xc14a16
c14a14  movb RL6,#0x2
c14a16  movb RL4,RL6
c14a18  mov r6,[r0+]
c14a1a  rets
