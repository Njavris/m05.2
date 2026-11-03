; c12910 gap_c12910 size=44
c12910  mov r1,r12
c12912  cmpb RL1,#0x0
c12914  jmpr cc_EQ,0xc12934
c12916  movbz r12,0xc5c4
c1291a  movb RL2,[r12+#0xf63d]
c1291e  movbz r12,0xc5c7
c12922  mov r1,r1
c12924  addb RL2,#0x40
c12928  movb [r12+#0xf63d],RL2
c1292c  movbz r12,RL1
c1292e  calls 0xc12856
c12932  rets
c12934  mov r12,#0x0
c12936  calls 0xc126da
c1293a  rets
