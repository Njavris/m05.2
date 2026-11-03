; c12f10 gap_c12f10 size=48
c12f10  mov r12,0xc5ac
c12f14  cmp r12,0xc5a6
c12f18  jmpr cc_NC,0xc12f1e
c12f1a  sub 0xc5ac,0xff1e
c12f1e  mov r12,0xc5ac
c12f22  cmp r12,0xc5a6
c12f26  jmpr cc_C,0xc12f6e
c12f28  movb RL1,0xc58a
c12f2c  jmpr cc_EQ,0xc12f3a
c12f2e  movbz r12,RL1
c12f30  calls 0xc128c6
c12f34  movb 0xc58a,0xff1c
c12f38  jmpr cc_UC,0xc12f6e
c12f3a  calls 0xc127fe
c12f3e  jmpr cc_UC,0xc12f6e
