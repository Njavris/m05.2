; c20e96 gap_c20e96 size=198
c20e96  calls 0xc18ed0
c20e9a  movb 0xca94,0xff1c
c20e9e  movb RL1,#0x23
c20ea2  movb 0xca9c,0xff1c
c20ea6  jmpr cc_UC,0xc20f2c
c20ea8  movb RL2,0xc702
c20eac  cmpb RL2,#0x1
c20eae  jmpr cc_NE,0xc20ec0
c20eb0  movbs r13,0xca9c
c20eb4  shl r13,#0x1
c20eb6  mov r12,#0x8000
c20eba  mov [r13+#0xc016],r12
c20ebe  jmpr cc_UC,0xc20f28
c20ec0  mov r12,0xc936
c20ec4  extp 0x301, #0x1
c20ec8  cmp r12,0x1b8a
c20ecc  jmpr cc_SGE,0xc20efc
c20ece  mov r14,#0xc016
c20ed2  movbs r15,0xca9c
c20ed6  shl r15,#0x1
c20ed8  add r14,r15
c20eda  mov r12,#0x5bd4
c20ede  add r12,r15
c20ee0  mov r13,[r14]
c20ee2  mov r2,r13
c20ee4  mov r13,#0xc0
c20ee8  mov r3,#0x0
c20eea  addc r13,r3
c20eec  exts r13, #0x1
c20eee  mov r15,[r12]
c20ef0  cmp r2,r15
c20ef2  jmpr cc_NC,0xc20f28
c20ef4  exts r13, #0x1
c20ef6  mov r12,[r12]
c20ef8  mov [r14],r12
c20efa  jmpr cc_UC,0xc20f28
c20efc  mov r12,#0xc016
c20f00  movbs r15,0xca9c
c20f04  shl r15,#0x1
c20f06  add r12,r15
c20f08  mov r14,#0xc0
c20f0c  mov r3,#0x0
c20f0e  mov r13,[r12]
c20f10  mov r2,r13
c20f12  mov r13,#0x5b8c
c20f16  add r13,r15
c20f18  addc r14,r3
c20f1a  exts r14, #0x1
c20f1c  mov r15,[r13]
c20f1e  cmp r2,r15
c20f20  jmpr cc_NC,0xc20f28
c20f22  exts r14, #0x1
c20f24  mov r13,[r13]
c20f26  mov [r12],r13
c20f28  subb 0xca9c,0xff1e
c20f2c  cmpb RL1,0xca9c
c20f30  jmpr cc_SGE,0xc20ea8
c20f32  movb 0xca98,0xff1c
c20f36  movb 0xc7ff,0xff1c
c20f3a  movb 0xc800,0xff1c
c20f3e  mov 0xc7d0,0xff1c
c20f42  mov 0xc7d2,0xff1c
c20f46  movb 0xca8c,0xff1c
c20f4a  movb 0xca9b,0xff1c
c20f4e  movb 0xca9a,0xff1c
c20f52  mov r12,#0x20
c20f56  mov 0xc862,r12
c20f5a  rets
