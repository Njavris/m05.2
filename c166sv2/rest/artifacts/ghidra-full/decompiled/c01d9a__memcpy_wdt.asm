; c01d9a memcpy_wdt size=40
c01d9a  mov [-r0],r8
c01d9c  mov r8,#0x0
c01d9e  jmpr cc_UC,0xc01db6
c01da0  exts r15, #0x1
c01da2  movb RL1,[r14]
c01da4  exts r13, #0x1
c01da6  movb [r12],RL1
c01da8  add r12,#0x1
c01daa  addc r13,#0x0
c01dac  add r14,#0x1
c01dae  addc r15,#0x0
c01db0  srvwdt
c01db4  add r8,#0x1
c01db6  mov r1,[r0+#0x2]
c01dba  cmp r8,r1
c01dbc  jmpr cc_C,0xc01da0
c01dbe  mov r8,[r0+]
c01dc0  rets
