; c10ed0 gap_c10ed0 size=54
c10ed0  mov [-r0],r9
c10ed2  mov [-r0],r8
c10ed4  mov r8,#0xaa55
c10ed8  mov r9,#0x0
c10eda  mov r15,#0x0
c10edc  jmpr cc_UC,0xc10ef8
c10ede  mov r1,r15
c10ee0  mov r2,#0x0
c10ee2  mov r3,r12
c10ee4  mov r4,r13
c10ee6  add r3,r1
c10ee8  addc r4,r2
c10eea  exts r4, #0x1
c10eec  movb RL1,[r3]
c10eee  movbz r1,RL1
c10ef0  mov r3,#0x0
c10ef2  add r8,r1
c10ef4  addc r9,r3
c10ef6  add r15,#0x1
c10ef8  cmp r15,r14
c10efa  jmpr cc_C,0xc10ede
c10efc  mov r4,r8
c10efe  mov r5,r9
c10f00  mov r8,[r0+]
c10f02  mov r9,[r0+]
c10f04  rets
