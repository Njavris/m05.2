; c10cb4 farcall_50 size=62
c10cb4  mov 0xfca0,r0
c10cb8  scxt 0xfe10,#0xfca0
c10cbc  scxt 0xff0e,#0x10
c10cc0  push 0xfe00
c10cc2  mov 0xfe00,#0x301
c10cc6  push 0xfe04
c10cc8  mov 0xfe04,#0x303
c10ccc  push 0xfe0c
c10cce  push 0xfe0e
c10cd0  mov r12,#0xc4de
c10cd4  mov r13,#0xfe64
c10cd8  mov r14,#0xff04
c10cdc  mov r15,#0x20
c10ce0  calls 0xc10b3e
c10ce4  pop 0xfe0e
c10ce6  pop 0xfe0c
c10ce8  pop 0xfe04
c10cea  pop 0xfe00
c10cec  pop 0xff0e
c10cee  pop 0xfe10
c10cf0  reti
