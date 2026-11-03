; c0210a boot_hidden_memcpy size=40
c0210a  mov [-r0],r6
c0210c  movb RL6,#0x0
c0210e  jmpr cc_UC,0xc02126
c02110  exts r15, #0x1
c02112  movb RL1,[r14]
c02114  exts r13, #0x1
c02116  movb [r12],RL1
c02118  add r12,#0x1
c0211a  addc r13,#0x0
c0211c  add r14,#0x1
c0211e  addc r15,#0x0
c02120  srvwdt
c02124  addb RL6,#0x1
c02126  movb RL1,[r0+#0x2]
c0212a  cmpb RL6,RL1
c0212c  jmpr cc_C,0xc02110
c0212e  mov r6,[r0+]
c02130  rets
