; c0e722 cc22_23_hysteresis_a size=62
c0e722  mov r13,0xc450
c0e726  jmpr cc_EQ,0xc0e732
c0e728  cmp r13,#0x1
c0e72a  jmpr cc_EQ,0xc0e73a
c0e72c  cmp r13,#0x2
c0e72e  jmpr cc_EQ,0xc0e752
c0e730  jmpr cc_UC,0xc0e75e
c0e732  cmp r12,#0x6900
c0e736  jmpr cc_ULE,0xc0e75e
c0e738  jmpr cc_UC,0xc0e758
c0e73a  cmp r12,#0x6400
c0e73e  jmpr cc_NC,0xc0e744
c0e740  mov 0xc450,0xff1c
c0e744  cmp r12,#0xa400
c0e748  jmpr cc_ULE,0xc0e75e
c0e74a  mov r12,#0x2
c0e74c  mov 0xc450,r12
c0e750  rets
c0e752  cmp r12,#0xa000
c0e756  jmpr cc_NC,0xc0e75e
c0e758  mov r12,#0x1
c0e75a  mov 0xc450,r12
c0e75e  rets
