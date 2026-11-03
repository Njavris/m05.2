; c11662 gap_c11662 size=40
c11662  movb RL1,#0x0
c11664  jmpr cc_UC,0xc11680
c11666  movb RL2,#0x0
c11668  mov r12,#0x0
c1166c  mov r13,#0xe0
c11670  movb RL3,RL1
c11672  addb RL1,#0x1
c11674  movbz r3,RL3
c11676  mov r14,#0x0
c11678  add r12,r3
c1167a  addc r13,r14
c1167c  exts r13, #0x1
c1167e  movb [r12],RL2
c11680  movbz r12,RL1
c11682  cmp r12,#0x80
c11686  jmpr cc_SLT,0xc11666
c11688  rets
