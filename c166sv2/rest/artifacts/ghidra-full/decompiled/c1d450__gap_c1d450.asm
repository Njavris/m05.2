; c1d450 gap_c1d450 size=30
c1d450  movb RL1,0xc702
c1d454  jmpr cc_EQ,0xc1d46c
c1d456  movb RL1,#0x0
c1d458  mov r12,#0x8000
c1d45c  movbz r13,RL1
c1d45e  shl r13,#0x1
c1d460  addb RL1,#0x1
c1d462  cmpb RL1,#0x10
c1d466  mov [r13+#0xc07a],r12
c1d46a  jmpr cc_C,0xc1d458
c1d46c  rets
