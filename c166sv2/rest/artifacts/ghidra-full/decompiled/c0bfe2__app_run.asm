; c0bfe2 app_run size=16
c0bfe2  cmp r12,#0x0
c0bfe4  jmpr cc_EQ,0xc0bfec
c0bfe6  cmp r12,#0x1
c0bfe8  jmpr cc_EQ,0xc0bfec
c0bfea  jmpr cc_UC,0xc0bfea
c0bfec  calls 0xc11c62
c0bff0  rets
