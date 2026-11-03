; c1c0b4 gap_c1c0b4 size=54
c1c0b4  mov r12,0xc9d0
c1c0b8  extp 0x301, #0x1
c1c0bc  cmp r12,0x3cd8
c1c0c0  jmpr cc_UGT,0xc1c0d0
c1c0c2  calls 0xc1c09e
c1c0c6  calls 0xc15ecc
c1c0ca  calls 0xc17cbc
c1c0ce  rets
c1c0d0  mov 0xcb02,0xff1c
c1c0d4  mov 0xcb04,0xff1c
c1c0d8  mov r12,#0x0
c1c0da  mov r13,#0x0
c1c0dc  calls 0xc1c3ee
c1c0e0  mov r12,#0x0
c1c0e2  mov r13,#0x1
c1c0e4  calls 0xc1c3ee
c1c0e8  rets
