; c14300 gap_c14300 size=62
c14300  extp 0x301, #0x1
c14304  mov r12,0x106a
c14308  cmp r12,#0x1
c1430a  jmpr cc_NE,0xc1432e
c1430c  mov r12,#0xe
c1430e  calls 0xc10398
c14312  shr r4,#0x6
c14314  mov r12,r4
c14316  cmp r12,#0x266
c1431a  jmpr cc_C,0xc14322
c1431c  mov r13,#0x1
c1431e  mov 0xc600,r13
c14322  cmp r12,#0x1ff
c14326  jmpr cc_UGT,0xc14338
c14328  mov 0xc600,0xff1c
c1432c  jmpr cc_UC,0xc14338
c1432e  mov r12,#0x0
c14330  bmov r12.0x0,0xffa2.0xe
c14334  mov 0xc600,r12
c14338  mov r12,0xc600
c1433c  jmpr cc_UC,0xc1435c
