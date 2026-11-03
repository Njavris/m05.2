c01cc8: extp 0x80, #0x1
c01ccc: mov r13,0x430
c01cd0: shr r13,#0xc
c01cd2: and r13,#0x3
c01cd4: mov r1,r13
c01cd6: cmpb RL1,#0x2
c01cd8: jmpr cc_EQ,0xc01cc8
c01cda: mov r13,#0x430
c01cde: mov r14,#0x80
c01ce2: extp r14, #0x1
c01ce4: mov r15,[r13]
c01ce6: bfldh r15,#0xc,#0x8
c01cea: extp r14, #0x1
c01cec: mov [r13],r15
c01cee: mov r13,#0x430
c01cf2: mov r14,#0x80
c01cf6: extp r14, #0x1
c01cf8: mov r15,[r13]
c01cfa: bfldh r15,#0x3,#0x2
c01cfe: extp r14, #0x1
c01d00: mov [r13],r15
c01d02: cmp r12,#0x8
c01d06: jmpr cc_NC,0xc01d26
c01d08: mov r13,#0x434
c01d0c: mov r14,#0x80
c01d10: and r12,#0xf
c01d14: shl r12,#0x4
c01d16: extp r14, #0x1
c01d18: mov r15,[r13]
c01d1a: and r15,#0xff0f
c01d1e: or r15,r12
c01d20: extp r14, #0x1
c01d22: mov [r13],r15
c01d24: jmpr cc_UC,0xc01d3a
c01d26: mov r12,#0x434
c01d2a: mov r13,#0x80
c01d2e: extp r13, #0x1
c01d30: mov r14,[r12]
c01d32: bfldl r14,#0x80,#0xf0
c01d36: extp r13, #0x1
c01d38: mov [r12],r14
c01d3a: mov r12,#0x0
c01d3c: mov r13,#0x3750
c01d40: add r13,r12
c01d42: mov r14,#0x3
c01d44: extp r14, #0x1
c01d46: movb RL1,[r13]
c01d48: mov r13,#0x420
c01d4c: add r13,r12
c01d4e: mov r14,#0x80
c01d52: extp r14, #0x1
c01d54: movb [r13],RL1
c01d56: add r12,#0x1
c01d58: cmp r12,#0x8
c01d5c: jmpr cc_C,0xc01d3c
c01d5e: mov r12,#0x430
c01d62: mov r13,#0x80
c01d66: extp r13, #0x1
c01d68: mov r14,[r12]
c01d6a: bfldh r14,#0xc,#0x4
c01d6e: extp r13, #0x1
c01d70: mov [r12],r14
c01d72: mov r12,#0x430
c01d76: mov r13,#0x80
c01d7a: extp r13, #0x1
c01d7c: mov r14,[r12]
c01d7e: bfldh r14,#0x30,#0x20
c01d82: extp r13, #0x1
c01d84: mov [r12],r14
c01d86: extp 0x80, #0x1
c01d8a: mov r12,0x430
c01d8e: shr r12,#0xc
c01d90: and r12,#0x3
c01d92: mov r1,r12
c01d94: cmpb RL1,#0x2
c01d96: jmpr cc_EQ,0xc01d86
c01d98: rets
