; c1b5fe gap_c1b5fe size=96
c1b5fe  movb RL1,0xc954
c1b602  jmpr cc_NE,0xc1b61a
c1b604  mov r12,0xc946
c1b608  extp 0x301, #0x1
c1b60c  cmp r12,0x2c40
c1b610  jmpr cc_NC,0xc1b61a
c1b612  movb RL2,#0x1
c1b614  movb 0xc941,RL2
c1b618  jmpr cc_UC,0xc1b646
c1b61a  movb RL1,0xc954
c1b61e  jmpr cc_NE,0xc1b63a
c1b620  mov r12,0xc946
c1b624  extp 0x301, #0x1
c1b628  cmp r12,0x2c40
c1b62c  jmpr cc_C,0xc1b63a
c1b62e  movb RL2,#0x1
c1b630  movb 0xc940,RL2
c1b634  movb 0xc941,0xff1c
c1b638  jmpr cc_UC,0xc1b646
c1b63a  movb 0xc940,0xff1c
c1b63e  movb 0xc941,0xff1c
c1b642  mov 0xc946,0xff1c
c1b646  movb RL1,0xc940
c1b64a  jmpr cc_EQ,0xc1b65c
c1b64c  movb RL2,0xc9e6
c1b650  jmpr cc_EQ,0xc1b65c
c1b652  calls 0xc1c410
c1b656  movb RL1,#0x1
c1b658  movb 0xc94a,RL1
c1b65c  rets
