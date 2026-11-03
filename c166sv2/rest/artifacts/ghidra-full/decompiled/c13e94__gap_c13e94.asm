; c13e94 gap_c13e94 size=156
c13e94  mov r12,#0x3
c13e96  calls 0xc10398
c13e9a  mov 0xc5ec,r4
c13e9e  mov r12,#0x2
c13ea0  calls 0xc10398
c13ea4  mov 0xc5ee,r4
c13ea8  mov r12,#0x4
c13eaa  calls 0xc10398
c13eae  mov 0xc5f0,r4
c13eb2  mov r12,#0x6
c13eb4  calls 0xc10398
c13eb8  mov 0xc5f2,r4
c13ebc  mov r12,#0x0
c13ebe  calls 0xc10398
c13ec2  mov 0xc5f6,r4
c13ec6  mov r12,#0x5
c13ec8  calls 0xc10398
c13ecc  mov 0xc5f4,r4
c13ed0  extp 0x301, #0x1
c13ed4  mov r12,0x1066
c13ed8  jmpr cc_NE,0xc13eea
c13eda  mov r12,#0x1
c13edc  calls 0xc10398
c13ee0  mov 0xc5fc,r4
c13ee4  mov 0xc5f8,0xff1c
c13ee8  jmpr cc_UC,0xc13ef8
c13eea  mov 0xc5fc,0xff1c
c13eee  mov r12,#0x1
c13ef0  calls 0xc10398
c13ef4  mov 0xc5f8,r4
c13ef8  extp 0x301, #0x1
c13efc  mov r12,0x1068
c13f00  cmp r12,#0x1
c13f02  jmpr cc_NE,0xc13f14
c13f04  mov r12,#0xf
c13f06  calls 0xc10398
c13f0a  mov 0xc5fc,r4
c13f0e  mov 0xc5fa,0xff1c
c13f12  rets
c13f14  extp 0x301, #0x1
c13f18  mov r12,0x1068
c13f1c  cmp r12,#0x2
c13f1e  jmpr cc_NE,0xc13f2e
c13f20  mov 0xc5fc,0xff1c
c13f24  mov r12,#0xf
c13f26  calls 0xc10398
c13f2a  mov 0xc5fa,r4
c13f2e  rets
