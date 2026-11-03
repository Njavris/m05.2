; c15a3a gap_c15a3a size=36
c15a3a  mov r15,#0x0
c15a3c  jmpr cc_UC,0xc15a58
c15a3e  mov r1,r13
c15a40  add r1,r15
c15a42  movb RL1,[r1]
c15a44  jmpr cc_EQ,0xc15a56
c15a46  mov r1,r12
c15a48  add r1,r15
c15a4a  movb RL2,[r1]
c15a4c  cmpb RL2,#0x0
c15a4e  jmpr cc_ULE,0xc15a56
c15a50  movb RL2,[r1]
c15a52  subb RL2,#0x1
c15a54  movb [r1],RL2
c15a56  add r15,#0x1
c15a58  cmp r15,r14
c15a5a  jmpr cc_C,0xc15a3e
c15a5c  rets
