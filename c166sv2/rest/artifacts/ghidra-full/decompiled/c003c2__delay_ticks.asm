; c003c2 delay_ticks size=28
c003c2  mov r14,#0x0
c003c4  jmpa cc_UC,0xc003d6
c003c8  srvwdt
c003cc  mov r13,#0x0
c003ce  cmpi1 r13,#0x7bbf
c003d2  jmpr cc_SLT,0xc003ce
c003d4  add r14,#0x1
c003d6  cmp r14,r12
c003d8  jmpa cc_SLT,0xc003c8
c003dc  rets
