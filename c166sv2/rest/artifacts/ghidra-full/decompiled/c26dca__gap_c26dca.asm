; c26dca gap_c26dca size=268
c26dca  mov [-r0],r8
c26dcc  calls 0xc1aeac
c26dd0  mov r13,r4
c26dd2  mov r12,0xc06a
c26dd6  calls 0xc28852
c26dda  mov r8,r4
c26ddc  extp 0x380, #0x1
c26de0  mov r12,0x8ee
c26de4  mov r13,0xc962
c26de8  calls 0xc28852
c26dec  mov r12,r4
c26dee  extp 0x380, #0x1
c26df2  movb RL1,0x8f4
c26df6  jmpr cc_EQ,0xc26e30
c26df8  movb RL2,0xc93c
c26dfc  cmpb RL2,#0x4
c26dfe  jmpr cc_EQ,0xc26e04
c26e00  cmpb RL2,#0x1
c26e02  jmpr cc_NE,0xc26e30
c26e04  movb RL1,0xcc32
c26e08  jmpr cc_NE,0xc26e30
c26e0a  movb RL2,0xca18
c26e0e  jmpr cc_NE,0xc26e30
c26e10  jb 0xfd00.0xd,0xc26e30
c26e14  extp 0x301, #0x1
c26e18  cmp r8,0x3e3c
c26e1c  jmpr cc_C,0xc26e30
c26e1e  extp 0x301, #0x1
c26e22  cmp r12,0x3e40
c26e26  jmpr cc_C,0xc26e30
c26e28  movb RL3,#0x1
c26e2a  movb 0xcc8f,RL3
c26e2e  jmpr cc_UC,0xc26e34
c26e30  movb 0xcc8f,0xff1c
c26e34  extp 0x380, #0x1
c26e38  movb RL1,0x8f0
c26e3c  jmpr cc_EQ,0xc26e46
c26e3e  extp 0x380, #0x1
c26e42  movb 0x8f0,0xff1c
c26e46  extp 0x380, #0x1
c26e4a  movb RL1,0x8f4
c26e4e  jmpr cc_EQ,0xc26e92
c26e50  movb 0xcc8e,0xff1c
c26e54  mov 0xcc92,0xff1c
c26e58  movb RL2,0xcc8f
c26e5c  jmpr cc_EQ,0xc26e8c
c26e5e  mov r8,0xcc90
c26e62  extp 0x301, #0x1
c26e66  cmp r8,0x3e3e
c26e6a  jmpr cc_C,0xc26e84
c26e6c  movb RL3,#0x1
c26e6e  extp 0x380, #0x1
c26e72  movb 0x8ec,RL3
c26e76  extp 0x380, #0x1
c26e7a  movb 0x8f0,RL3
c26e7e  movb 0xcc8d,0xff1c
c26e82  jmpr cc_UC,0xc26ec6
c26e84  movb RL1,#0x1
c26e86  movb 0xcc8d,RL1
c26e8a  jmpr cc_UC,0xc26ed2
c26e8c  movb 0xcc8d,0xff1c
c26e90  jmpr cc_UC,0xc26ed2
c26e92  movb 0xcc8d,0xff1c
c26e96  movb RL1,0xc93c
c26e9a  cmpb RL1,#0x3
c26e9c  jmpr cc_EQ,0xc26eac
c26e9e  mov r8,0xcc92
c26ea2  extp 0x301, #0x1
c26ea6  cmp r8,0x3e42
c26eaa  jmpr cc_C,0xc26ecc
c26eac  extp 0x380, #0x1
c26eb0  movb 0x8ec,0xff1c
c26eb4  movb RL1,#0x1
c26eb6  extp 0x380, #0x1
c26eba  movb 0x8f0,RL1
c26ebe  movb 0xcc8e,0xff1c
c26ec2  mov 0xcc92,0xff1c
c26ec6  mov 0xcc90,0xff1c
c26eca  jmpr cc_UC,0xc26ed2
c26ecc  movb RL1,#0x1
c26ece  movb 0xcc8e,RL1
c26ed2  mov r8,[r0+]
c26ed4  rets
