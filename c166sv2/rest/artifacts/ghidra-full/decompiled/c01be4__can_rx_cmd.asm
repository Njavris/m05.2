; c01be4 can_rx_cmd size=138
c01be4  mov [-r0],r8
c01be6  extp 0x3, #0x1
c01bea  movb RL1,0x3746
c01bee  cmpb RL1,#0xff
c01bf2  jmpr cc_NE,0xc01c4e
c01bf4  calls 0xc01dec
c01bf8  jmpr cc_UC,0xc01c44
c01bfa  mov r12,0xc1d4
c01bfe  cmp r12,#0x8
c01c02  jmpr cc_ULE,0xc01c08
c01c04  mov r12,#0x8
c01c06  jmpr cc_UC,0xc01c0c
c01c08  mov r12,0xc1d4
c01c0c  mov r8,r12
c01c0e  mov [-r0],r8
c01c10  mov r12,#0xf750
c01c14  mov r4,r12
c01c16  calls 0xc01eea
c01c1a  mov r12,r4
c01c1c  mov r13,r5
c01c1e  mov r14,0xc1dc
c01c22  mov r15,0xc1de
c01c26  calls 0xc01d9a
c01c2a  add r0,#0x2
c01c2c  mov r12,r8
c01c2e  calls 0xc01cc8
c01c32  sub 0xc1d4,r8
c01c36  mov r12,#0x0
c01c38  add 0xc1dc,r8
c01c3c  addc 0xc1de,r12
c01c40  srvwdt
c01c44  mov r8,0xc1d4
c01c48  cmp r8,#0x0
c01c4a  jmpr cc_UGT,0xc01bfa
c01c4c  jmpr cc_UC,0xc01c6a
c01c4e  extp 0x3, #0x1
c01c52  movb RL1,0x3746
c01c56  jmpr cc_NE,0xc01c6a
c01c58  mov r8,0xc1d4
c01c5c  cmp r8,#0x0
c01c5e  jmpr cc_ULE,0xc01c6a
c01c60  movb RL2,#0x1
c01c62  movb 0xc1d6,RL2
c01c66  calls 0xc01dec
c01c6a  mov r8,[r0+]
c01c6c  rets
