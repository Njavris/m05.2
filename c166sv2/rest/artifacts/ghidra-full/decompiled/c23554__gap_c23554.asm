; c23554 gap_c23554 size=104
c23554  mov r1,r12
c23556  mov r2,r13
c23558  cmpb RL1,#0x0
c2355a  jmpr cc_NE,0xc23564
c2355c  movbz r12,RL2
c2355e  movb RL4,[r12+#0x76c8]
c23562  rets
c23564  cmpb RL1,#0x1
c23566  jmpr cc_NE,0xc23570
c23568  movbz r12,RL2
c2356a  movb RL4,[r12+#0x76cc]
c2356e  rets
c23570  cmpb RL1,#0x2
c23572  jmpr cc_NE,0xc2357c
c23574  movbz r12,RL2
c23576  movb RL4,[r12+#0x76d0]
c2357a  rets
c2357c  cmpb RL1,#0x3
c2357e  jmpr cc_NE,0xc23588
c23580  movbz r12,RL2
c23582  movb RL4,[r12+#0x76d4]
c23586  rets
c23588  cmpb RL1,#0x4
c2358a  jmpr cc_NE,0xc23594
c2358c  movbz r12,RL2
c2358e  movb RL4,[r12+#0x76d8]
c23592  rets
c23594  cmpb RL1,#0x5
c23596  jmpr cc_NE,0xc235a0
c23598  movbz r12,RL2
c2359a  movb RL4,[r12+#0x76dc]
c2359e  rets
c235a0  cmpb RL1,#0x6
c235a2  jmpr cc_NE,0xc235ac
c235a4  movbz r12,RL2
c235a6  movb RL4,[r12+#0x76e4]
c235aa  rets
c235ac  cmpb RL1,#0x7
c235ae  jmpr cc_NE,0xc235b8
c235b0  movbz r12,RL2
c235b2  movb RL4,[r12+#0x76e0]
c235b6  rets
c235b8  movb RL4,#0x0
c235ba  rets
