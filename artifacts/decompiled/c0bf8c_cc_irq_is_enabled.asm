c0bf8c: mov r14,0xc3c4
c0bf90: shr r12,#0x1
c0bf92: and r12,#0xf
c0bf96: mov r13,#0x1
c0bf98: shl r13,r12
c0bf9a: mov r15,[r14]
c0bf9c: and r15,r13
c0bf9e: mov r12,r15
c0bfa0: jmpr cc_EQ,0xc0bfaa
c0bfa2: cmp r13,#0x0
c0bfa4: jmpr cc_EQ,0xc0bfaa
c0bfa6: mov r12,#0x1
c0bfa8: jmpr cc_UC,0xc0bfac
c0bfaa: mov r12,#0x0
c0bfac: mov r4,r12
c0bfae: rets
