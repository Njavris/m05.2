; c267f4 gap_c267f4 size=46
c267f4  mov r12,#0x1f
c267f8  mov r13,#0x20
c267fc  mov r14,#0x14
c26800  calls 0xc24c46
c26804  mov r12,0xcafa
c26808  extp 0x380, #0x1
c2680c  mov 0x8e6,r12
c26810  extp 0x301, #0x1
c26814  cmp r12,0x3e0a
c26818  jmpr cc_ULE,0xc26820
c2681a  movb RL1,#0x1
c2681c  movb 0xcc68,RL1
c26820  rets
