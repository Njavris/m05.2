; c15a12 gap_c15a12 size=40
c15a12  mov r15,#0x0
c15a14  jmpr cc_UC,0xc15a34
c15a16  mov r1,r13
c15a18  add r1,r15
c15a1a  movb RL1,[r1]
c15a1c  jmpr cc_EQ,0xc15a32
c15a1e  mov r1,r12
c15a20  add r1,r15
c15a22  movb RL2,[r1]
c15a24  movbz r2,RL2
c15a26  cmp r2,#0xff
c15a2a  jmpr cc_SGE,0xc15a32
c15a2c  movb RL2,[r1]
c15a2e  addb RL2,#0x1
c15a30  movb [r1],RL2
c15a32  add r15,#0x1
c15a34  cmp r15,r14
c15a36  jmpr cc_C,0xc15a16
c15a38  rets
