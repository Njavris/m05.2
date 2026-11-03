; c11d98 gap_c11d98 size=34
c11d98  calls 0xc11f60
c11d9c  cmpb RL4,0xc5b3
c11da0  jmpr cc_EQ,0xc11da8
c11da2  mov r6,0xc5a2
c11da6  jmpr cc_NE,0xc11e80
c11da8  mov r6,0xc57a
c11dac  cmp r6,#0x6
c11dae  jmpr cc_UGT,0xc11e78
c11db0  shl r6,#0x1
c11db2  add r6,#0x7076
c11db6  mov r6,[r6]
c11db8  jmpi cc_UC,[r6]
