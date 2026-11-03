; c28e50 fp_compare size=68
c28e50  mov r1,r10
c28e52  mov r2,r11
c28e54  mov r3,[r1+]
c28e56  mov r5,[r2+]
c28e58  mov r4,r3
c28e5a  or r3,r5
c28e5c  and r3,#0x7ff0
c28e60  jmpr cc_EQ,0xc28e8c
c28e62  mov r3,r4
c28e64  ashr r4,#0xf
c28e66  or r4,#0x1
c28e68  bcmp r3.0xf,r5.0xf
c28e6c  jmpr cc_N,0xc28e92
c28e6e  cmp r3,r5
c28e70  jmpr cc_UGT,0xc28e92
c28e72  jmpr cc_C,0xc28e90
c28e74  mov r3,[r1+]
c28e76  cmp r3,[r2+]
c28e78  jmpr cc_UGT,0xc28e92
c28e7a  jmpr cc_C,0xc28e90
c28e7c  mov r3,[r1+]
c28e7e  cmp r3,[r2+]
c28e80  jmpr cc_UGT,0xc28e92
c28e82  jmpr cc_C,0xc28e90
c28e84  mov r3,[r1]
c28e86  cmp r3,[r2]
c28e88  jmpr cc_UGT,0xc28e92
c28e8a  jmpr cc_C,0xc28e90
c28e8c  mov r4,#0x0
c28e8e  rets
c28e90  neg r4
c28e92  rets
