; c26ac6 gap_c26ac6 size=62
c26ac6  mov r12,0xcc7a
c26aca  extp 0x301, #0x1
c26ace  cmp r12,0x3e2a
c26ad2  jmpr cc_C,0xc26ae0
c26ad4  movb RL1,#0x1
c26ad6  extp 0x380, #0x1
c26ada  movb 0x8e8,RL1
c26ade  jmpr cc_UC,0xc26af6
c26ae0  mov r12,0xcc7c
c26ae4  extp 0x301, #0x1
c26ae8  cmp r12,0x3e2c
c26aec  jmpr cc_C,0xc26afe
c26aee  extp 0x380, #0x1
c26af2  movb 0x8e8,0xff1c
c26af6  movb RL1,#0x1
c26af8  movb 0xcc82,RL1
c26afc  rets
c26afe  movb 0xcc82,0xff1c
c26b02  rets
