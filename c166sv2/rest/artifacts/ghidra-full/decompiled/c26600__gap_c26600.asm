; c26600 gap_c26600 size=58
c26600  movb RL1,[r0]
c26602  cmp r14,0xc072
c26606  jmpr cc_NC,0xc26634
c26608  mov r2,r12
c2660a  cmpb RL2,#0x0
c2660c  jmpr cc_EQ,0xc26634
c2660e  cmp r15,0xc936
c26612  jmpr cc_SGE,0xc26634
c26614  cmpb RL1,#0x0
c26616  jmpr cc_EQ,0xc26622
c26618  cmpb RL1,#0x1
c2661a  jmpr cc_NE,0xc26634
c2661c  movb RL2,[r0+#0x2]
c26620  jmpr cc_NE,0xc26634
c26622  movb RL1,0xc784
c26626  jmpr cc_NE,0xc26634
c26628  movb RL2,0xc81c
c2662c  jmpr cc_NE,0xc26634
c2662e  movb RL3,#0x1
c26630  movb [r13],RL3
c26632  rets
c26634  movb RL1,#0x0
c26636  movb [r13],RL1
c26638  rets
