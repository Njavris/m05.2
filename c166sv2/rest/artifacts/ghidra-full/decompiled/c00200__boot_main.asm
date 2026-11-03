; c00200 boot_main size=220
c00200  mov r12,#0x7fc
c00204  mov r13,#0xe0
c00208  mov r14,0xf1e4
c0020c  jnb r14.0x1,0xc00240
c00210  mov r4,r12
c00212  mov r5,r13
c00214  calls 0xc01ece
c00218  sub r10,#0x8625
c0021c  subc r11,#0x6450
c00220  jmpr cc_NE,0xc00228
c00222  movb RL1,#0x1
c00224  movb 0xc020,RL1
c00228  mov r4,r12
c0022a  mov r5,r13
c0022c  calls 0xc01ece
c00230  sub r10,#0x6450
c00234  subc r11,#0x8633
c00238  jmpr cc_NE,0xc00240
c0023a  movb RL1,#0x2
c0023c  movb 0xc020,RL1
c00240  mov r10,#0x0
c00242  mov r11,#0x0
c00244  mov r4,r12
c00246  mov r5,r13
c00248  calls 0xc01edc
c0024c  calls 0xc002dc
c00250  extp 0x304, #0x1
c00254  mov r12,0x0
c00258  jmpr cc_NE,0xc0025e
c0025a  calls 0xc003f0
c0025e  mov r12,0xf1e4
c00262  jnb r12.0xa,0xc0026a
c00266  calls 0xc003f0
c0026a  movb RL1,0xc020
c0026e  cmpb RL1,#0x1
c00270  jmpr cc_EQ,0xc00276
c00272  cmpb RL1,#0x2
c00274  jmpr cc_NE,0xc00282
c00276  movbz r12,0xc020
c0027a  calls 0xc01218
c0027e  calls 0xc003f0
c00282  extp 0x30f, #0x1
c00286  mov r12,0x3ffc
c0028a  cmp r12,#0xaa00
c0028e  jmpr cc_EQ,0xc002d2
c00290  mov r12,#0x0
c00292  mov r13,#0xc0
c00296  mov r14,#0x1ffd
c0029a  mov r15,#0xc0
c0029e  calls 0xc0037e
c002a2  extp 0x300, #0x1
c002a6  mov r12,0x1ffe
c002aa  cmp r4,r12
c002ac  jmpa cc_NE,0xc002d6
c002b0  mov r12,#0xb000
c002b4  mov r13,#0xc0
c002b8  mov r14,#0xfffb
c002bc  mov r15,#0xc3
c002c0  calls 0xc0037e
c002c4  extp 0x30f, #0x1
c002c8  mov r12,0x3ffe
c002cc  cmp r4,r12
c002ce  jmpa cc_NE,0xc002d6
c002d2  jmps 0xc10000
c002d6  calls 0xc003f0
c002da  rets
