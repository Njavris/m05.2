; c020c4 boot_hidden_copy size=70
c020c4  mov r12,#0x10
c020c8  mov r13,#0xe0
c020cc  mov [r0],r12
c020ce  mov [r0+#0x2],r13
c020d2  mov r14,#0x4
c020d4  mov [-r0],r14
c020d6  mov r15,#0x6
c020d8  add r15,r0
c020da  mov r4,r15
c020dc  calls 0xc03de2
c020e0  mov r12,r4
c020e2  mov r13,r5
c020e4  mov r15,#0x2
c020e6  add r15,r0
c020e8  mov r4,r15
c020ea  calls 0xc03de2
c020ee  mov r14,r4
c020f0  mov r15,r5
c020f2  calls 0xc0210a
c020f6  add r0,#0x2
c020f8  mov r4,[r0+#0x4]
c020fc  mov r5,[r0+#0x6]
c02100  calls 0xc03ddc
c02104  add r0,#0x8
c02108  rets
