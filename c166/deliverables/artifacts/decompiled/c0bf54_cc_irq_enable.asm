c0bf54: cmp r13,#0x0
c0bf56: jmpr cc_EQ,0xc0bf74
c0bf58: mov r14,0xc3c4
c0bf5c: shr r12,#0x1
c0bf5e: and r12,#0xf
c0bf62: mov r13,#0x1
c0bf64: shl r13,r12
c0bf66: mov r12,r13
c0bf68: cpl r12
c0bf6a: mov r15,[r14]
c0bf6c: and r15,r12
c0bf6e: or r15,r13
c0bf70: mov [r14],r15
c0bf72: rets
c0bf74: mov r13,0xc3c4
c0bf78: shr r12,#0x1
c0bf7a: and r12,#0xf
c0bf7e: mov r15,#0x1
c0bf80: shl r15,r12
c0bf82: cpl r15
c0bf84: mov r14,[r13]
c0bf86: and r14,r15
c0bf88: mov [r13],r14
c0bf8a: rets
