; c270da gap_c270da size=94
c270da  movb RL1,0xc81c
c270de  jmpr cc_EQ,0xc27128
c270e0  movb RL2,0xcad6
c270e4  jmpr cc_EQ,0xc27128
c270e6  mov r12,#0xe
c270e8  calls 0xc243a8
c270ec  cmpb RL4,#0x0
c270ee  jmpr cc_NE,0xc27128
c270f0  mov r12,#0xf
c270f2  calls 0xc243a8
c270f6  cmpb RL4,#0x0
c270f8  jmpr cc_NE,0xc27128
c270fa  mov r12,0xc99a
c270fe  extp 0x301, #0x1
c27102  cmp r12,0x3e4e
c27106  jmpr cc_NC,0xc27128
c27108  mov r13,0xcc9e
c2710c  extp 0x301, #0x1
c27110  cmp r13,0x3e54
c27114  jmpr cc_C,0xc2711e
c27116  movb RL1,#0x1
c27118  movb 0xcca2,0xff1c
c2711c  jmpr cc_UC,0xc2712e
c2711e  movb RL1,#0x0
c27120  movb RL2,#0x1
c27122  movb 0xcca2,RL2
c27126  jmpr cc_UC,0xc2712e
c27128  movb RL1,#0x0
c2712a  mov 0xcc9e,0xff1c
c2712e  extp 0x380, #0x1
c27132  movb 0x8f6,RL1
c27136  rets
