; c12ede gap_c12ede size=50
c12ede  mov r12,0xc5ac
c12ee2  cmp r12,0xc5a6
c12ee6  jmpr cc_NC,0xc12eec
c12ee8  sub 0xc5ac,0xff1e
c12eec  mov r12,0xc59c
c12ef0  cmp r12,#0xffff
c12ef4  jmpr cc_NE,0xc12ef8
c12ef6  sub r12,#0x1
c12ef8  cmp r12,0xc5ba
c12efc  jmpr cc_ULE,0xc12f02
c12efe  sub 0xc5ba,0xff1e
c12f02  cmp r12,0xc5ba
c12f06  jmpr cc_UGT,0xc12f6e
c12f08  mov r12,#0x0
c12f0a  calls 0xc126da
c12f0e  jmpr cc_UC,0xc12f6e
