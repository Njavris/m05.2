; c26b04 gap_c26b04 size=106
c26b04  movb RL1,0xcc81
c26b08  jmpr cc_NE,0xc26b3e
c26b0a  movb RL2,0xcc82
c26b0e  jmpr cc_NE,0xc26b3e
c26b10  extp 0x380, #0x1
c26b14  mov r12,0x8ac
c26b18  jmpr cc_NE,0xc26b3e
c26b1a  extp 0x380, #0x1
c26b1e  movb RL3,0x89e
c26b22  jmpr cc_NE,0xc26b3e
c26b24  extp 0x380, #0x1
c26b28  movb RL4,0x846
c26b2c  jmpr cc_NE,0xc26b3e
c26b2e  movb RL5,0xcc83
c26b32  cmpb RL5,#0x1
c26b34  jmpr cc_NE,0xc26b3e
c26b36  movb RL1,#0x1
c26b38  movb 0xcc85,RL1
c26b3c  jmpr cc_UC,0xc26b46
c26b3e  movb 0xcc85,0xff1c
c26b42  mov 0xcc7a,0xff1c
c26b46  movb RL1,0xcc81
c26b4a  cmpb RL1,#0x1
c26b4c  jmpr cc_NE,0xc26b64
c26b4e  movb RL2,0xcc83
c26b52  cmpb RL2,#0x1
c26b54  jmpr cc_NE,0xc26b64
c26b56  movb RL3,0xcc82
c26b5a  jmpr cc_NE,0xc26b64
c26b5c  movb RL4,#0x1
c26b5e  movb 0xcc86,RL4
c26b62  rets
c26b64  movb 0xcc86,0xff1c
c26b68  mov 0xcc7c,0xff1c
c26b6c  rets
