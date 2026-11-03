; c1064c t7_timestamp size=40
c1064c  mov r12,0xf050
c10650  cmp r12,#0x8000
c10654  jmpr cc_UGT,0xc1066a
c10656  mov r13,0xf17a
c1065a  jnb r13.0x7,0xc1066a
c1065e  shr r12,#0x3
c10660  add r12,0xc4c8
c10664  add r12,#0x2000
c10668  jmpr cc_UC,0xc10670
c1066a  shr r12,#0x3
c1066c  add r12,0xc4c8
c10670  mov r4,r12
c10672  rets
