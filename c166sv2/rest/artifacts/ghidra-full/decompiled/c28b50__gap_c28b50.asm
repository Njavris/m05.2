; c28b50 gap_c28b50 size=20
c28b50  mov r3,r14
c28b52  jmpr cc_NE,0xc28b56
c28b54  rets
c28b56  mov r4,r13
c28b58  mov r10,r12
c28b5a  mov [r10],[r4+]
c28b5c  add r10,#0x2
c28b5e  sub r3,#0x1
c28b60  jmpr cc_NE,0xc28b5a
c28b62  rets
