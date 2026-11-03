; c269f6 gap_c269f6 size=68
c269f6  movb RL1,0xcc7e
c269fa  jmpr cc_NE,0xc26a2c
c269fc  calls 0xc2699e
c26a00  cmpb RL4,#0x1
c26a02  jmpr cc_NE,0xc26a2c
c26a04  movb RL1,0xcc80
c26a08  jmpr cc_NE,0xc26a2c
c26a0a  mov r12,0xcc78
c26a0e  extp 0x301, #0x1
c26a12  cmp r12,0x3e24
c26a16  jmpr cc_C,0xc26a24
c26a18  movb 0xcc84,0xff1c
c26a1c  movb RL2,#0x1
c26a1e  movb 0xcc83,RL2
c26a22  rets
c26a24  movb RL1,#0x1
c26a26  movb 0xcc84,RL1
c26a2a  jmpr cc_UC,0xc26a34
c26a2c  movb 0xcc84,0xff1c
c26a30  mov 0xcc78,0xff1c
c26a34  movb 0xcc83,0xff1c
c26a38  rets
