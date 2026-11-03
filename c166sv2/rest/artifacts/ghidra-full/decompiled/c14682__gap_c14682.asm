; c14682 gap_c14682 size=92
c14682  mov r14,#0x0
c14684  extp 0x301, #0x1
c14688  mov r15,0x1068
c1468c  jmpr cc_EQ,0xc14692
c1468e  cmp r15,#0x4
c14690  jmpr cc_NE,0xc146da
c14692  mov r1,r12
c14694  cmpb RL1,#0x0
c14696  jmpr cc_EQ,0xc1469c
c14698  cmpb RL1,#0x1
c1469a  jmpr cc_NE,0xc146da
c1469c  mov r12,#0x0
c1469e  extp 0x301, #0x1
c146a2  mov r14,0x1068
c146a6  jmpr cc_EQ,0xc146ac
c146a8  cmp r14,#0x4
c146aa  jmpr cc_NE,0xc146d8
c146ac  mov r14,0xc4d4
c146b0  or r14,0xc4d2
c146b4  jmpr cc_EQ,0xc146d8
c146b6  mov r1,r13
c146b8  movbz r13,RL1
c146ba  mov r4,#0x4240
c146be  mov r5,#0xf
c146c0  jmpr cc_UC,0xc146c6
c146c2  add r4,r4
c146c4  addc r5,r5
c146c6  cmpd1 r13,#0x0
c146c8  jmpr cc_NE,0xc146c2
c146ca  mov r10,0xc4d2
c146ce  mov r11,0xc4d4
c146d2  calls 0xc28bb2
c146d6  mov r12,r4
c146d8  mov r14,r12
c146da  mov r4,r14
c146dc  rets
