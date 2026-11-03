; c27738 gap_c27738 size=28
c27738  add r12,r14
c2773a  addc r13,r15
c2773c  mov r1,r12
c2773e  mov r2,r13
c27740  sub r1,r14
c27742  subc r2,r15
c27744  jmpr cc_NC,0xc2774e
c27746  mov r4,#0xffff
c2774a  mov r5,r4
c2774c  jmpr cc_UC,0xc27752
c2774e  mov r4,r12
c27750  mov r5,r13
c27752  rets
