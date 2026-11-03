; c14346 gap_c14346 size=20
c14346  mov r12,#0x0
c14348  bmov r12.0x0,0xffc4.0x6
c1434c  jmpr cc_UC,0xc1435c
c1435c  cmp r12,#0x0
c1435e  jmpr cc_EQ,0xc14364
c14360  mov r4,#0x1
c14362  jmpr cc_UC,0xc14366
c14364  mov r4,#0x0
c14366  rets
