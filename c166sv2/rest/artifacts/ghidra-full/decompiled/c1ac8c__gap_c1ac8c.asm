; c1ac8c gap_c1ac8c size=74
c1ac8c  movb RL1,0xc702
c1ac90  jmpr cc_EQ,0xc1ac9e
c1ac92  extp 0x301, #0x1
c1ac96  mov r12,0x2c50
c1ac9a  mov 0xc06a,r12
c1ac9e  movb 0xc926,0xff1c
c1aca2  mov r12,0xc06a
c1aca6  extp 0x301, #0x1
c1acaa  cmp r12,0x2c5a
c1acae  jmpr cc_UGT,0xc1acb8
c1acb0  extp 0x301, #0x1
c1acb4  mov r12,0x2c5a
c1acb8  extp 0x301, #0x1
c1acbc  cmp r12,0x2c58
c1acc0  jmpr cc_ULE,0xc1acd0
c1acc2  extp 0x301, #0x1
c1acc6  mov r12,0x2c58
c1acca  mov 0xc06a,r12
c1acce  rets
c1acd0  mov 0xc06a,r12
c1acd4  rets
