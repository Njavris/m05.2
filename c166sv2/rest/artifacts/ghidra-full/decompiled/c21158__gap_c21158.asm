; c21158 gap_c21158 size=194
c21158  calls 0xc18ed0
c2115c  movb 0xca95,0xff1c
c21160  movb RL1,#0x23
c21164  movb 0xca9e,0xff1c
c21168  jmpr cc_UC,0xc211ee
c2116a  movb RL2,0xc702
c2116e  cmpb RL2,#0x1
c21170  jmpr cc_NE,0xc21182
c21172  movbs r13,0xca9e
c21176  shl r13,#0x1
c21178  mov r12,#0x8000
c2117c  mov [r13+#0xc0c0],r12
c21180  jmpr cc_UC,0xc211ea
c21182  mov r12,0xc936
c21186  extp 0x301, #0x1
c2118a  cmp r12,0x1b8a
c2118e  jmpr cc_SGE,0xc211be
c21190  mov r14,#0xc0c0
c21194  movbs r15,0xca9e
c21198  shl r15,#0x1
c2119a  add r14,r15
c2119c  mov r12,#0x5bd4
c211a0  add r12,r15
c211a2  mov r13,[r14]
c211a4  mov r2,r13
c211a6  mov r13,#0xc0
c211aa  mov r3,#0x0
c211ac  addc r13,r3
c211ae  exts r13, #0x1
c211b0  mov r15,[r12]
c211b2  cmp r2,r15
c211b4  jmpr cc_NC,0xc211ea
c211b6  exts r13, #0x1
c211b8  mov r12,[r12]
c211ba  mov [r14],r12
c211bc  jmpr cc_UC,0xc211ea
c211be  mov r12,#0xc0c0
c211c2  movbs r15,0xca9e
c211c6  shl r15,#0x1
c211c8  add r12,r15
c211ca  mov r14,#0xc0
c211ce  mov r3,#0x0
c211d0  mov r13,[r12]
c211d2  mov r2,r13
c211d4  mov r13,#0x5b8c
c211d8  add r13,r15
c211da  addc r14,r3
c211dc  exts r14, #0x1
c211de  mov r15,[r13]
c211e0  cmp r2,r15
c211e2  jmpr cc_NC,0xc211ea
c211e4  exts r14, #0x1
c211e6  mov r13,[r13]
c211e8  mov [r12],r13
c211ea  subb 0xca9e,0xff1e
c211ee  cmpb RL1,0xca9e
c211f2  jmpr cc_SGE,0xc2116a
c211f4  movb 0xca99,0xff1c
c211f8  movb 0xc801,0xff1c
c211fc  movb 0xc802,0xff1c
c21200  mov 0xc7d4,0xff1c
c21204  mov 0xc7d6,0xff1c
c21208  movb 0xca8d,0xff1c
c2120c  movb 0xca9b,0xff1c
c21210  mov r12,#0x20
c21214  mov 0xc862,r12
c21218  rets
