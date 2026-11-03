; c0ece6 gap_c0ece6 size=60
c0ece6  mov r12,#0x0
c0ece8  mov r13,0xc44e
c0ecec  cmp r13,#0x1
c0ecee  jmpr cc_NE,0xc0ed1e
c0ecf0  mov r14,0xc072
c0ecf4  extp 0x301, #0x1
c0ecf8  cmp r14,0x108c
c0ecfc  jmpr cc_UGT,0xc0ed0e
c0ecfe  mov r15,0xc266
c0ed02  extp 0x301, #0x1
c0ed06  cmp r15,0x1088
c0ed0a  jmpr cc_ULE,0xc0ed1e
c0ed0c  jmpr cc_UC,0xc0ed1c
c0ed0e  mov r13,0xc266
c0ed12  extp 0x301, #0x1
c0ed16  cmp r13,0x108a
c0ed1a  jmpr cc_ULE,0xc0ed1e
c0ed1c  mov r12,#0x1
c0ed1e  mov r4,r12
c0ed20  rets
