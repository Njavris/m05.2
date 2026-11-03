; c14a1c gap_c14a1c size=32
c14a1c  mov [-r0],r6
c14a1e  movb RL6,#0x0
c14a20  mov r13,#0x1
c14a22  calls 0xc117d8
c14a26  mov r12,r4
c14a28  cmp r12,#0x2
c14a2a  jmpr cc_EQ,0xc14a34
c14a2c  cmp r12,#0x1
c14a2e  jmpr cc_NE,0xc14a36
c14a30  movb RL6,#0x1
c14a32  jmpr cc_UC,0xc14a36
c14a34  movb RL6,#0x2
c14a36  movb RL4,RL6
c14a38  mov r6,[r0+]
c14a3a  rets
