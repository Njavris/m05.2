; c02ac8 gap_c02ac8 size=174
c02ac8  movb RL1,#0x0
c02aca  extp 0x380, #0x2
c02ace  movb 0x20,RL1
c02ad2  movb RL2,0x1
c02ad6  extp 0x380, #0x1
c02ada  movb RL3,0x2
c02ade  movbz r13,RL3
c02ae0  mov r12,#0x0
c02ae2  extp 0x380, #0x1
c02ae6  movbz r4,0x3
c02aea  mov r14,#0x0
c02aec  mov r15,r4
c02aee  shl r4,#0x8
c02af0  shl r14,#0x8
c02af2  shr r15,#0x8
c02af4  or r14,r15
c02af6  or r12,r4
c02af8  or r13,r14
c02afa  extp 0x380, #0x1
c02afe  movbz r4,0x4
c02b02  mov r14,#0x0
c02b04  or r12,r4
c02b06  or r13,r14
c02b08  and r13,#0xff
c02b0c  mov r3,r12
c02b0e  mov r10,r13
c02b10  mov r14,#0x5
c02b12  mov r15,#0xe0
c02b16  jmpr cc_UC,0xc02b32
c02b18  mov r4,r14
c02b1a  mov r5,r15
c02b1c  add r14,#0x1
c02b1e  addc r15,#0x0
c02b20  exts r5, #0x1
c02b22  movb RL4,[r4]
c02b24  mov r5,r12
c02b26  mov r11,r13
c02b28  add r12,#0x1
c02b2a  addc r13,#0x0
c02b2c  exts r11, #0x1
c02b2e  movb [r5],RL4
c02b30  addb RL1,#0x1
c02b32  cmpb RL1,RL2
c02b34  jmpr cc_C,0xc02b18
c02b36  mov r12,r3
c02b38  mov r13,r10
c02b3a  mov r14,#0x5
c02b3c  mov r15,#0xe0
c02b40  movb RL1,#0x0
c02b42  jmpr cc_UC,0xc02b70
c02b44  mov r3,r12
c02b46  mov r4,r13
c02b48  add r12,#0x1
c02b4a  addc r13,#0x0
c02b4c  exts r4, #0x1
c02b4e  movb RL3,[r3]
c02b50  mov r4,r14
c02b52  mov r5,r15
c02b54  add r14,#0x1
c02b56  addc r15,#0x0
c02b58  exts r5, #0x1
c02b5a  movb RL4,[r4]
c02b5c  cmpb RL3,RL4
c02b5e  jmpr cc_EQ,0xc02b6e
c02b60  movb RL1,#0xff
c02b64  extp 0x380, #0x1
c02b68  movb 0x20,RL1
c02b6c  rets
c02b6e  addb RL1,#0x1
c02b70  cmpb RL1,RL2
c02b72  jmpr cc_C,0xc02b44
c02b74  rets
