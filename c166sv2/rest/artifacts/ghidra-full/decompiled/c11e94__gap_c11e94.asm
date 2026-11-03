; c11e94 gap_c11e94 size=28
c11e94  mov r6,0xc5a2
c11e98  cmp r6,#0x1
c11e9a  jmpr cc_NE,0xc11ea0
c11e9c  mov 0xc5ac,0xff1c
c11ea0  mov r6,0xc5a2
c11ea4  jmpr cc_NE,0xc11eb0
c11ea6  mov 0xc59a,0xff1c
c11eaa  jmpr cc_UC,0xc11eb0
c11eb0  calls 0xc1482c
