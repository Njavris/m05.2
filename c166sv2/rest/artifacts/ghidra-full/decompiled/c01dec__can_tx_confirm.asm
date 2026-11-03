; c01dec can_tx_confirm size=212
c01dec  mov r12,#0x430
c01df0  mov r13,#0x80
c01df4  extp r13, #0x1
c01df6  mov r14,[r12]
c01df8  bfldl r14,#0x40,#0xc0
c01dfc  extp r13, #0x1
c01dfe  mov [r12],r14
c01e00  mov r12,#0x420
c01e04  add r12,#0x10
c01e08  mov r13,#0x80
c01e0c  extp r13, #0x1
c01e0e  mov r14,[r12]
c01e10  bclr r14.0x1
c01e12  extp r13, #0x1
c01e14  mov [r12],r14
c01e16  mov r12,#0x430
c01e1a  mov r13,#0x80
c01e1e  extp r13, #0x1
c01e20  mov r14,[r12]
c01e22  bfldh r14,#0xc0,#0x40
c01e26  extp r13, #0x1
c01e28  mov [r12],r14
c01e2a  mov r12,#0x430
c01e2e  mov r13,#0x80
c01e32  extp r13, #0x1
c01e34  mov r14,[r12]
c01e36  bfldh r14,#0x30,#0x10
c01e3a  extp r13, #0x1
c01e3c  mov [r12],r14
c01e3e  mov r12,#0x430
c01e42  mov r13,#0x80
c01e46  extp r13, #0x1
c01e48  mov r14,[r12]
c01e4a  bfldh r14,#0x3,#0x1
c01e4e  extp r13, #0x1
c01e50  mov [r12],r14
c01e52  movb RL1,0xc1d6
c01e56  jmpr cc_EQ,0xc01e82
c01e58  mov r12,#0x434
c01e5c  mov r13,#0x80
c01e60  extp r13, #0x1
c01e62  mov r14,[r12]
c01e64  and r14,#0xfff7
c01e68  extp r13, #0x1
c01e6a  mov [r12],r14
c01e6c  mov r12,#0x430
c01e70  mov r13,#0x80
c01e74  extp r13, #0x1
c01e76  mov r14,[r12]
c01e78  bfldh r14,#0xc,#0x4
c01e7c  extp r13, #0x1
c01e7e  mov [r12],r14
c01e80  jmpr cc_UC,0xc01eaa
c01e82  mov r12,#0x434
c01e86  mov r13,#0x80
c01e8a  extp r13, #0x1
c01e8c  mov r14,[r12]
c01e8e  bfldl r14,#0x8,#0x8
c01e92  extp r13, #0x1
c01e94  mov [r12],r14
c01e96  mov r12,#0x430
c01e9a  mov r13,#0x80
c01e9e  extp r13, #0x1
c01ea0  mov r14,[r12]
c01ea2  bfldh r14,#0xc,#0x8
c01ea6  extp r13, #0x1
c01ea8  mov [r12],r14
c01eaa  mov r12,#0x430
c01eae  mov r13,#0x80
c01eb2  extp r13, #0x1
c01eb4  mov r14,[r12]
c01eb6  bfldl r14,#0x80,#0xc0
c01eba  extp r13, #0x1
c01ebc  mov [r12],r14
c01ebe  rets
