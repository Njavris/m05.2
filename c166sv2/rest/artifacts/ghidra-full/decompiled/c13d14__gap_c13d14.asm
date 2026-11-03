; c13d14 gap_c13d14 size=54
c13d14  movb RL1,0xc578
c13d18  cmpb RL1,#0x1
c13d1a  jmpr cc_EQ,0xc13d2c
c13d1c  cmpb RL1,#0x2
c13d1e  jmpr cc_NE,0xc13d46
c13d20  movbz r12,0xc5c4
c13d24  movb RL2,[r12+#0xf63e]
c13d28  cmpb RL2,#0x1
c13d2a  jmpr cc_NE,0xc13d34
c13d2c  mov r12,#0x1
c13d2e  calls 0xc12910
c13d32  rets
c13d34  movbz r12,0xc5c4
c13d38  movb RL1,[r12+#0xf63e]
c13d3c  cmpb RL1,#0x2
c13d3e  jmpr cc_NE,0xc13d46
c13d40  mov 0xc59e,0xff1c
c13d44  rets
c13d46  mov r12,#0x12
