; c25732 gap_c25732 size=46
c25732  mov [-r0],r8
c25734  calls 0xc25414
c25738  mov r8,#0x0
c2573a  mov r12,r8
c2573c  calls 0xc24286
c25740  cmpb RL4,#0x0
c25742  jmpr cc_EQ,0xc25754
c25744  mov r12,r8
c25746  calls 0xc2465c
c2574a  cmpb RL4,#0x1
c2574c  jmpr cc_NE,0xc25754
c2574e  mov r12,r8
c25750  calls 0xc246de
c25754  add r8,#0x1
c25756  cmp r8,#0x27
c2575a  jmpr cc_C,0xc2573a
c2575c  mov r8,[r0+]
c2575e  rets
