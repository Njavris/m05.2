; c125d2 gap_c125d2 size=20
c125d2  jb 0xfd02.0xb,0xc125de
c125d6  mov r12,0xc9d0
c125da  cmp r12,#0x0
c125dc  jmpr cc_ULE,0xc125e2
c125de  movb RL4,#0x1
c125e0  jmpr cc_UC,0xc125e4
c125e2  movb RL4,#0x0
c125e4  rets
