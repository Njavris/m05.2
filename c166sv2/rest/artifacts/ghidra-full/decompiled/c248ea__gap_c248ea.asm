; c248ea gap_c248ea size=58
c248ea  movb RL1,0xc898
c248ee  cmpb RL1,#0x7
c248f0  jmpr cc_EQ,0xc24908
c248f2  cmpb RL1,#0x5
c248f4  jmpr cc_NE,0xc24900
c248f6  mov r12,#0x7a2a
c248fa  calls 0xc24764
c248fe  jmpr cc_UC,0xc2491a
c24900  movb RL1,0xc898
c24904  cmpb RL1,#0x3
c24906  jmpr cc_NE,0xc24912
c24908  mov r12,#0x7a24
c2490c  calls 0xc24764
c24910  jmpr cc_UC,0xc2491a
c24912  movb RL1,0xc898
c24916  cmpb RL1,#0x1
c24918  jmpr cc_NE,0xc2492c
c2491a  mov r12,#0x7a1e
c2491e  calls 0xc24764
c24922  rets
