; c24802 gap_c24802 size=28
c24802  mov [-r0],r12
c24804  calls 0xc24724
c24808  mov r12,[r0+]
c2480a  cmpb RL4,#0x0
c2480c  jmpr cc_EQ,0xc2481c
c2480e  movb RL1,#0x0
c24810  mov [-r0],r1
c24812  calls 0xc2473a
c24816  mov r1,[r0+]
c24818  movb [r4+#0xcb6c],RL1
c2481c  rets
