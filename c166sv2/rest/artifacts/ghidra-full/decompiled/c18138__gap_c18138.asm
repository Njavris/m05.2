; c18138 gap_c18138 size=62
c18138  movb 0xc816,0xff1c
c1813c  mov r12,#0x0
c1813e  calls 0xc1c2d6
c18142  movb 0xc81a,0xff1c
c18146  movb 0xc9a5,0xff1c
c1814a  movb RL1,#0x0
c1814c  movbz r13,RL1
c1814e  shl r13,#0x1
c18150  movb RL2,#0x0
c18152  mov r12,#0x0
c18154  mov [r13+#0xc808],r12
c18158  movbz r13,RL1
c1815a  addb RL1,#0x1
c1815c  cmpb RL1,#0x2
c1815e  movb [r13+#0xc806],RL2
c18162  jmpr cc_C,0xc1814c
c18164  mov r12,#0xc808
c18168  calls 0xc1c296
c1816c  mov r12,#0xc806
c18170  calls 0xc1c312
c18174  rets
