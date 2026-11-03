; c26a9e gap_c26a9e size=40
c26a9e  movb RL1,0xcc83
c26aa2  cmpb RL1,#0x1
c26aa4  jmpr cc_NE,0xc26ac0
c26aa6  extp 0x380, #0x1
c26aaa  mov r12,0x8ea
c26aae  extp 0x301, #0x1
c26ab2  cmp r12,0x3e1e
c26ab6  jmpr cc_UGT,0xc26ac0
c26ab8  movb RL2,#0x1
c26aba  movb 0xcc81,RL2
c26abe  rets
c26ac0  movb 0xcc81,0xff1c
c26ac4  rets
